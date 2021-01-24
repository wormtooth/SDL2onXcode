//
//  engine.cpp
//  SDL_Tutorial
//
//  Created by Rongqing Ye on 4/25/20.
//  Copyright © 2020 Rongqing Ye. All rights reserved.
//

#include "engine.hpp"

#include "CoreFoundation/CoreFoundation.h"
#include <cstdio>

GameEngine::GameEngine() {
    success = true;
    quit = false;
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        sprintf(errMsg, "Error while initializing SDL2: %s", SDL_GetError());
        success = false;
        return;
    }
    
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        sprintf(errMsg, "Error while initializing SDL2_image: %s", IMG_GetError());
        success = false;
        return;
    }
    
    changeWorkingDirectory();
}

GameEngine::~GameEngine() {
    IMG_Quit();
    SDL_Quit();
}

bool GameEngine::init(const std::string title, int width, int height) {
    if (!success) return false;
    
    fps = 60;
    
    // create window
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        sprintf(errMsg, "Error while creating window: %s", SDL_GetError());
        success = false;
    }
    if (!success) return false;
    this->width = width;
    this->height = height;
    
    // create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        sprintf(errMsg, "Error while creating renderer: %s", SDL_GetError());
        success = false;
    }

    return success;
}

void GameEngine::clear() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void GameEngine::loop() {
    Uint32 frameTime = 1000 / fps;
    SDL_Event event;
    while (!quit) {
        Uint32 frameStart = SDL_GetTicks();
        
        while (SDL_PollEvent(&event)) {
            handleEvent(event);
        }
        render();
        update();
        
        Uint32 frameRunTime = SDL_GetTicks() - frameStart;
        if (frameRunTime < frameTime) {
            SDL_Delay(frameTime - frameRunTime);
        }
    }
}

void GameEngine::handleEvent(SDL_Event &event) {
    if (event.type == SDL_QUIT) {
        quit = true;
    }
}

/* Change working directory to Contents/Resources within the application bundle.
 *
 * Note: We need to link against Cocoa.framework, but no need to embed and sign the
 * framework as it is already included in the Mac OS.
 */
void GameEngine::changeWorkingDirectory() {
    CFBundleRef mainBundle = CFBundleGetMainBundle();
    CFURLRef resourcesURL = CFBundleCopyResourcesDirectoryURL(mainBundle);
    char path[PATH_MAX];
    if (!CFURLGetFileSystemRepresentation(resourcesURL, true, (UInt8 *)path, PATH_MAX)) {
        success = false;
        sprintf(errMsg, "Fail to change directory to Contents/Resources");
        return;
    }
    CFRelease(resourcesURL);
    chdir(path);
}
