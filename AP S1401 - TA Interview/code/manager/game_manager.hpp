#ifndef __GAME_MANAGER_HPP__
#define __GAME_MANAGER_HPP__

typedef void (GameManager::*game_manager_func)(std::map<std::string, std::string>);


class GameManager {
public:
    GameManager();
    ~GameManager();
    void init();
    void run();
    void shutdown();

    class Node {
    public:
        Node();
        ~Node();
    };

    class Player {
    public:
        Player();
        ~Player();
    };

};

#endif