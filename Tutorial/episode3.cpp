//
//  episode3.cpp
//  SDL_Tutorial
//
//  Created by Rongqing Ye on 4/26/20.
//  Copyright © 2020 Rongqing Ye. All rights reserved.
//

#include "episode3.hpp"

void Episode3::draw() {
    Episode2::draw();
    
    SDL_RenderSetViewport(renderer, nullptr);
    
    // draw the horizontal green line
    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, 0, height / 2, width, height / 2);
    
    int cellWidth = width / 4;
    int cellHeight = height / 2;
    
    // draw green thick line
    SDL_Rect rect = {0, height / 2, cellWidth, cellHeight};
    SDL_RenderSetViewport(renderer, &rect);
    thickLineRGBA(renderer, 50, 50, 150, 150, 10, 0x00, 0xFF, 0x00, SDL_ALPHA_OPAQUE);
    
    // draw pink circle
    rect.x += cellWidth;
    SDL_RenderSetViewport(renderer, &rect);
    circleRGBA(renderer, 100, 100, 50, 0xFF, 0x00, 0xFF, SDL_ALPHA_OPAQUE);
    
    // draw pink filled ellipse
    rect.x += cellWidth;
    SDL_RenderSetViewport(renderer, &rect);
    filledEllipseRGBA(renderer, 100, 100, 50, 75, 0xFF, 0x00, 0xFF, SDL_ALPHA_OPAQUE);
    
    // draw blue rounded rectangle
    rect.x += cellWidth;
    SDL_RenderSetViewport(renderer, &rect);
    roundedRectangleRGBA(renderer, 50, 50, 150, 175, 10, 0x00, 0x00, 0xFF, SDL_ALPHA_OPAQUE);
}
