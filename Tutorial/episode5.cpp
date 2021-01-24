//
//  episode5.cpp
//  SDL_Tutorial
//
//  Created by Rongqing Ye on 5/2/20.
//  Copyright © 2020 Rongqing Ye. All rights reserved.
//

#include "episode5.hpp"

bool Episode5::init(const std::string title, int width, int height) {
    GameEngine::init(title, width, height);
    
    mTexture.load(this, "assets/dino/Idle (1).png");
    
    return success;
}

void Episode5::render() {
    // white background
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    
    // render texture
    /* Uncomment this part to experiment
    SDL_Rect rect = {200, 100, 0, 0};
    mTexture.getSize(&rect.w, &rect.h);
    rect.w /= 2;
    rect.h /= 2;
    
    SDL_Rect origin = {100, 100, 0, 0};
    origin.w = 200;
    origin.h = 200;
     */
    SDL_RenderCopy(renderer, mTexture.getSDLTexture(), nullptr, nullptr);
    
    SDL_RenderPresent(renderer);
}
