//
//  episode4.cpp
//  SDL_Tutorial
//
//  Created by Rongqing Ye on 4/29/20.
//  Copyright © 2020 Rongqing Ye. All rights reserved.
//

#include "episode4.hpp"

bool Episode4::init(const std::string title, int width, int height) {
    GameEngine::init(title, width, height);
    
    x = width / 2;
    y = height / 2;
    rad = 20;
    step = 5;
    
    return success;
}

void Episode4::render() {
    // white background
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    
    // black filled circle
    filledCircleRGBA(renderer, x, y, rad, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
    
    SDL_RenderPresent(renderer);
}

void Episode4::handleEvent(SDL_Event &event) {
    GameEngine::handleEvent(event);
    
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
                quit = true;
                break;
                
            case SDLK_LEFT:
                if (x - step >= 0) {
                    x -= step;
                }
                break;
                
            case SDLK_RIGHT:
                if (x + step < width) {
                    x += step;
                }
                break;
                
            case SDLK_UP:
                if (y - step >= 0) {
                    y -= step;
                }
                break;
                
            case SDLK_DOWN:
                if (y + step < height) {
                    y += step;
                }
                break;
                
            case SDLK_p:
                if (rad < 50) {
                    rad += step;
                }
                break;
                
            case SDLK_m:
                if (rad > 10) {
                    rad -= step;
                }
                break;
                
            default:
                break;
        }
    } else if (event.type == SDL_MOUSEBUTTONDOWN) {
        SDL_GetMouseState(&x, &y);
        auto button = event.button;
        if (button.button == SDL_BUTTON_LEFT) {
            printf("Left button clicked!\n");
        } else if (button.button == SDL_BUTTON_RIGHT) {
            printf("Right button clicked!\n");
        }
    }
}
