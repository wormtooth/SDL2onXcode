//
//  episode2.cpp
//  SDL_Tutorial
//
//  Created by Rongqing Ye on 4/25/20.
//  Copyright © 2020 Rongqing Ye. All rights reserved.
//

#include "episode2.hpp"

void Episode2::render() {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
    SDL_RenderSetViewport(renderer, nullptr);
    SDL_RenderClear(renderer);
    
    draw();
    
    SDL_RenderPresent(renderer);
}

void Episode2::draw() {
    // draw vertical green lines
    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, SDL_ALPHA_OPAQUE);
    for (int w = 200; w < width; w += 200) {
        SDL_RenderDrawLine(renderer, w, 0, w, height);
    }
    
    // draw red rectangle
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, SDL_ALPHA_OPAQUE);
    SDL_Rect rect = {50, 50, 100, 100}; // {x, y, w, h}
    SDL_RenderDrawRect(renderer, &rect);
    
    // draw blue filled rectangle
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, SDL_ALPHA_OPAQUE);
    rect = {250, 50, 100, 100};
    SDL_RenderFillRect(renderer, &rect);
    
    // draw black points
    SDL_Point points[4] = {
        {150, 50}, {25, 75}, {120, 150}, {150, 125}
    };
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
    rect = {400, 0, 200, 200};
    SDL_RenderSetViewport(renderer, &rect);
    SDL_RenderDrawPoints(renderer, points, 4);
    
    // draw black lines
    rect = {600, 0, 200, 200};
    SDL_RenderSetViewport(renderer, &rect);
    SDL_RenderDrawLines(renderer, points, 4);
}
