//
//  episode6.cpp
//  SDL_Tutorial
//
//  Created by Rongqing Ye on 5/3/20.
//  Copyright © 2020 Rongqing Ye. All rights reserved.
//

#include "episode6.hpp"

bool Episode6::init(const std::string title, int width, int height) {
    GameEngine::init(title, width, height);
    
    std::vector<std::string> paths;
    char buffer[128];
    for (int i = 1; i <= 10; i ++) {
        sprintf(buffer, "assets/dino/Walk (%d).png", i);
        paths.push_back(std::string(buffer));
    }
    mDinoTexture.load(this, paths);
    mDinoAnimation.init(&mDinoTexture, LOOPTYPE_INFINITY, 60);
    
    std::vector<SDL_Rect> rects;
    for (int h = 0; h < 5; h ++) {
        for (int w = 0; w < 6; w ++) {
            rects.push_back(SDL_Rect{w * 256, h * 256, 256, 256});
        }
    }
    mFireworkTexture.load(this, "assets/Firework.png", rects);
    mFireworkAnimation.init(&mFireworkTexture, LOOPTYPE_LIFESPAN, 90);
    mFireworkAnimation.setPos(width / 2, height / 2);
    
    return success;
}

void Episode6::render() {
    // white background
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    
    mDinoAnimation.render(renderer);
    mFireworkAnimation.render(renderer);
    
    SDL_RenderPresent(renderer);
}

void Episode6::update() {
    mDinoAnimation.update();
    mFireworkAnimation.update();
}
