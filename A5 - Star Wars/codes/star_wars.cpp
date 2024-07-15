#include "star_wars.hpp"
using namespace std;

StarWars::StarWars(string filename, Window* _win) : musicPlayer(_win), mySpaceShip(_win) {
    win = _win;
    musicPlayer.play_theme();
    mySpaceShip.set_music_player(&musicPlayer);

    level = 1;
    gameMode = RUNNING;
    read_file(filename);
}

int StarWars::read_sizes_of_map(ifstream& fileStream) {
    int numOfMaps;
    fileStream >> numOfMaps;
    int numOfBlocksHeight, numOfBlocksWidth;
    fileStream >> numOfBlocksHeight >> numOfBlocksWidth;
    blockWidth = BACKGROUND_WIDTH / numOfBlocksHeight;
    blockHeight = BACKGROUND_HEIGHT / numOfBlocksWidth;

    mySpaceShip.set_block_size(blockWidth, blockHeight);
    return numOfMaps;
}

void StarWars::read_file(string filename) {
    ifstream fileStream (filename);
    int numOfMaps = read_sizes_of_map(fileStream);

    vector<singleMap> _maps;
    singleMap currentMap;
    while (numOfMaps--) {
        currentMap.clear();
        string line;
        do {
            fileStream >> line;
            currentMap.push_back(line);
        } while (line != MAP_SPLITTER);
        currentMap.pop_back(); //to get rid of the extra line which is splitter

        _maps.push_back(currentMap);
    }
    maps = _maps;   //this line and the whole local maps is to avoid stack overflow
    fileStream.close();
}

void StarWars::initialise() {
    bullets.clear();
    hostages.clear();
    enemies.initialise();
    mySpaceShip.initialise();
    singleMap currentMap = maps[level - 1];
    convert_map_to_positions(currentMap);
    gameMode = RUNNING;
}

void StarWars::convert_map_to_positions(singleMap currentMap) {
    for (int i = 0; i < currentMap.size(); i++) {
        for (int j = 0; j < currentMap[0].size(); j++) {
            if (currentMap[i][j] == EMPTY_SYMBOL)
                continue;
            if (currentMap[i][j] == STATIONARY_ENEMY_SYMBOL)
                enemies.add_member(new StationaryEnemy(Point(j * blockWidth, i * blockHeight), win, blockWidth, blockHeight, &musicPlayer));
            else if (currentMap[i][j] == MOVING_ENEMY_SYMBOL)
                enemies.add_member(new MovingEnemy(Point(j * blockWidth, i * blockHeight), win, blockWidth, blockHeight, &musicPlayer));
            else if (currentMap[i][j] == HOSTAGE_SYMBOL)
                hostages.push_back(Hostage(Point(j * blockWidth, i * blockHeight), win, blockWidth, blockHeight, &musicPlayer));  
        }
    }
}

void StarWars::run() {
    for (; level <= maps.size() && gameMode != LOST; level++) {
        initialise();
        string welcome = " welcome to level " + to_string(level);
        win->show_text(welcome, Point(BACKGROUND_WIDTH / 10, BACKGROUND_HEIGHT / 5), WHITE, FONT_ADDRESS_FOR_LEVELS, 54);
        musicPlayer.play_sound_effect(LEVEL);
        win->update_screen();
        delay(2000);
        while (gameMode == RUNNING) {
            process_events();
            update_frame();
            check_for_end_round();
        }
        check_for_end_game();
    }
}

void StarWars::process_events() {
    while (win->has_pending_event()) {
        Event event = win->poll_for_event();
        if (event.get_type() == Event::KEY_PRESS) {
            if (event.get_pressed_key() == MOVE_SYMBOLS[SHOOT])
                space_ship_shoot(); 
            else
                mySpaceShip.set_move(event.get_pressed_key());
        }
        else if (event.get_type() == Event::KEY_RELEASE)
            mySpaceShip.stop_moving(event.get_pressed_key());
        else if (event.get_type() == Event::QUIT)
            exit(EXIT_SUCCESS);
    }
}

void StarWars::update_frame() {
    win->clear();
    draw_background();
    update_bullets();
    mySpaceShip.update();
    enemies.update(mySpaceShip, bullets);
    enemies_shoot();
    update_hostages();
    win->update_screen();
    delay(80);
}

void StarWars::update_hostages() {
    for (auto& hostage : hostages) {
        hostage.update();
    
        for (auto& bullet : bullets) {
            if (hostage.is_shot_by(bullet)) {
                bullet.extinct();
                hostage.get_shot();
            }
        }

        if (hostage.is_hit_by(mySpaceShip)) {
            hostage.get_shot();
            mySpaceShip.die();
        }
    }
}

void StarWars::update_bullets() {
    for (auto& bullet : bullets) {
        bullet.update(win);
        
        if (mySpaceShip.is_shot_by(bullet)) {
            bullet.extinct();
            mySpaceShip.get_shot();
        }
    }
    erase_extra_bullets();
}


void StarWars::erase_extra_bullets() {
    auto i = bullets.begin();
    while (i != bullets.end()) {
        if (i->does_exist())
            i++;
        else
            i = bullets.erase(i);
    }
}


void StarWars::check_for_end_round() {
    if (mySpaceShip.is_dead())
        gameMode = LOST;
    
    for (auto& hostage : hostages) {
        if (gameMode == LOST)
            break;

        if (hostage.is_dead()) 
            gameMode = LOST;
    }

    if (enemies.count_alive() == 0 && gameMode != LOST) 
        gameMode = WON;
}

void StarWars::check_for_end_game() {
    if (gameMode == LOST) {
        delay(100);
        win->clear();
        win->show_text("you lost!", Point(BACKGROUND_WIDTH / 3, BACKGROUND_HEIGHT / 3), RED, FONT_ADDRESS_END_MATCHES, 80);
        win->update_screen();
        delay(2000);
        exit(EXIT_SUCCESS);
    }
    else if (gameMode == WON && level < maps.size()) {
        delay(100);
        win->clear();
        win->show_text("you won! now prepare yourself for next level", Point(30, BACKGROUND_HEIGHT / 3), GREEN, FONT_ADDRESS_END_MATCHES, 70);
        win->update_screen();
        delay(2000);
        win->clear();
    }
    else {
        delay(100);
        win->clear();
        win->show_text("you won!", Point(BACKGROUND_WIDTH / 3, BACKGROUND_HEIGHT / 3), GREEN, FONT_ADDRESS_END_MATCHES, 80);
        win->update_screen();
        delay(2000);
        exit(EXIT_SUCCESS);
    }
}


void StarWars::space_ship_shoot() { 
    bullets.push_back(Bullet(mySpaceShip.get_center() - Point(0, blockHeight / 2), MY_SPACESHIP)); 
    mySpaceShip.play_shooting_sound();
}

void StarWars::enemies_shoot() {
    vector<int> enemyShooters = enemies.choose_shooter(level, mySpaceShip);
    for (auto i : enemyShooters) {
        bullets.push_back(Bullet(enemies.get_center_of_enemy_in_index(i) + Point(0, blockHeight / 2), ENEMY));
    }
}

void StarWars::draw_background() { win->draw_img(BACKGROUND_ADDRESS); }
StarWars::~StarWars() { delete win; }