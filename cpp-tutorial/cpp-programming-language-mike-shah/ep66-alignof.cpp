#include <iostream>
#include <string>

struct GameStateWrong{
    bool checkpoint;
    float score;
    short numberOfPlayers;
};

struct GameStateGood{
    float score;
    short numberOfPlayers;
    bool checkpoint;
};

struct GameState{
    double score;
    short numberOfPlayers;
    bool checkpoint1;
    bool checkpoint2;
    bool checkpoint3;
    bool checkpoint4;
};

struct ShortGameState{
    short score;
    short numberOfPlayers;
    bool checkpoint1;
};

int main() {
    std::cout << sizeof(GameStateWrong) << std::endl;
    std::cout << sizeof(GameStateGood) << std::endl;
    std::cout << alignof(GameStateWrong) << std::endl;
    std::cout << alignof(GameState) << std::endl;
    std::cout << sizeof(GameState) << std::endl;
    std::cout << alignof(ShortGameState) << std::endl;
    std::cout << sizeof(ShortGameState) << std::endl;
    
    return 0;
}
