#include "star_wars.hpp"
using namespace std;

StarWars::StarWars(string filename, Window* _win) : 
    musicPlayer(_win), enemies(_win), spaceship(_win) {
    enemies.set_space_ship(&spaceship);
    enemies.set_music_player(&musicPlayer);
    win = _win;
    totalHeight = _win->get_height();
    totalWidth = _win->get_width();
    level = 1;
    gameMode = RUNNING;
    musicPlayer.play_theme();
    read_file(filename);
}

int StarWars::read_sizes_of_map(ifstream& fileStream) {
    int numOfMaps;
    fileStream >> numOfMaps;
    int numOfBlocksHeight, numOfBlocksWidth;
    fileStream >> numOfBlocksHeight >> numOfBlocksWidth;
    blockWidth = totalHeight / numOfBlocksHeight;
    blockHeight = totalWidth / numOfBlocksWidth;
    enemies.set_block_size(blockWidth, blockHeight);
    spaceship.set_block_size(blockWidth, blockHeight);
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
    enemies.initialise();
    spaceship.initialise();
    singleMap currentMap = maps[level - 1];
    convert_map_to_positions(currentMap);
}

void StarWars::convert_map_to_positions(singleMap currentMap) {
    for (int i = 0; i < currentMap.size(); i++) {
        for (int j = 0; j < currentMap[0].size(); j++) {
            if (currentMap[i][j] == EMPRY_SYMBOL)
                continue;
            if (currentMap[i][j] == STATIONARY_ENEMY_SYMBOL)
                enemies.add_member(StationaryEnemy(Point(j * blockWidth, i * blockHeight), blockWidth, blockHeight));
            else if (currentMap[i][j] == MOVING_ENEMY_SYMBOL)
                enemies.add_member(MovingEnemy(Point(j * blockWidth, i * blockHeight), blockWidth, blockHeight));
            else if (currentMap[i][j] == HOSTAGE_SYMBOL)
                hostage.set_top_left(Point(j * blockWidth, i * blockHeight));
        }
    }
}

void StarWars::run() {
    for (; level <= maps.size() && gameMode != LOST; level++) {
        initialise();
        string welcome = "welcome to level " + level;
        win->show_text(welcome, Point(totalWidth / 10, totalHeight / 5), WHITE, FONT_ADDRESS, 36);
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
        if (event.get_type() == Event::KEY_PRESS)
            spaceship.set_move(event.get_type());
        if (event.get_type() == Event::KEY_RELEASE)
            spaceship.stop_moving(event.get_type());
        if (event.get_type() == Event::QUIT)
            exit(EXIT_SUCCESS);
    }
}

void StarWars::update_frame() {
    win->clear();
    draw_background();

    spaceship.update();
    enemies.update();
    
    spaceship.draw();
    enemies.draw();
    win->update_screen();

    delay(100);
}

void StarWars::check_for_end_round() {
    if (hostage.is_dead() || spaceship.is_dead())
        gameMode = LOST;
    else if (enemies.count_alive() == 0) 
        gameMode = WON;
}

void StarWars::check_for_end_game() {
    if (gameMode == LOST) {
        win->clear();
        win->show_text("YOU LOST!\n", Point(totalWidth / 2, totalHeight / 4), RED, FONT_ADDRESS, 48);
        win->update_screen();
        delay(2000);
        exit(EXIT_SUCCESS);
    }
    else if (gameMode == WON && level == maps.size()) {
        win->clear();
        win->show_text("YOU WON!\n", Point(totalWidth / 2, totalHeight / 4), GREEN, FONT_ADDRESS, 48);
        win->update_screen();
        delay(2000);
        exit(EXIT_SUCCESS);
    }
}

void StarWars::draw_background() { win->draw_img(BACKGROUND_ADDRESS); }
StarWars::~StarWars() { delete win; }