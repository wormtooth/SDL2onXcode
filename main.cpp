//
//  main.cpp
//  SDL_Tutorial
//
//  Created by Rongqing Ye on 4/24/20.
//  Copyright © 2020 Rongqing Ye. All rights reserved.
//

#include <iostream>

#include "episode6.hpp"

int main(int argc, const char *argv[]) {
    GameEngine *game = new Episode6();

    if (!game->init("Episode 6", 800, 600)) {
        std::cout << game->errMsg << std::endl;
        game->clear();
        delete game;
        return 1;
    }
    
    game->loop();
    game->clear();
    
    delete game;
    return 0;
}
