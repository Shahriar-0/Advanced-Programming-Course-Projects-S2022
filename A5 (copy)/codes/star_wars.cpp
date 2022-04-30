#include "star_wars.hpp"
using namespace std;

StarWars::StarWars(string filename, Window* _win) : musicPlayer(_win), mySpaceShip(_win) {
    win = _win;
    musicPlayer.play_theme();
    mySpaceShip.set_music_player(&musicPlayer);

    level = 1;
    gameMode = RUNNING;
    //introduction(); //todo
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
    maps = _maps;   //this line ans the whole local maps is to avoid stack overflow
    fileStream.close();
}

void StarWars::initialise() {
    bullets.clear();
    enemies.initialise();
    mySpaceShip.initialise();
    singleMap currentMap = maps[level - 1];
    convert_map_to_positions(currentMap);
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
        win->show_text(welcome, Point(BACKGROUND_WIDTH / 10, BACKGROUND_HEIGHT / 5), WHITE, FONT_ADDRESS, 54);
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
    update_hostages();
    win->update_screen();
    delay(100);
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

void StarWars::update_hostages() {
    for (auto& hostage : hostages)
        hostage.update();
}

void StarWars::update_bullets() {
    for (auto& bullet : bullets)
        bullet.update(win);
    erase_extra_bullets();
}

void StarWars::check_for_end_game() {
    if (gameMode == LOST) {
        win->clear();
        win->show_text("YOU LOST!\n", Point(BACKGROUND_WIDTH / 2, BACKGROUND_HEIGHT / 4), RED, FONT_ADDRESS, 48);
        win->update_screen();
        delay(2000);
        exit(EXIT_SUCCESS);
    }
    else if (gameMode == WON && level < maps.size()) {
        win->clear();
        win->show_text("YOU WON! NOW PREPARE YOURSELF FOR NEXT ROUND\n", Point(BACKGROUND_WIDTH / 5, BACKGROUND_HEIGHT / 4), GREEN, FONT_ADDRESS, 48);
        win->update_screen();
        delay(2000);
        win->clear();
    }
    else {
        win->clear();
        win->show_text("YOU WON!\n", Point(BACKGROUND_WIDTH / 2, BACKGROUND_HEIGHT / 4), GREEN, FONT_ADDRESS, 48);
        win->update_screen();
        delay(2000);
    }
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

void StarWars::space_ship_shoot() { 
    bullets.push_back(Bullet(mySpaceShip.get_center() - Point(0, blockHeight / 2), blockWidth, blockHeight, MY_SPACESHIP)); 
    mySpaceShip.play_shooting_sound();
}

void StarWars::draw_background() { win->draw_img(BACKGROUND_ADDRESS); }
StarWars::~StarWars() { delete win; }