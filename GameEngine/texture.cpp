//
//  texture.cpp
//  SDL_Tutorial
//
//  Created by Rongqing Ye on 5/1/20.
//  Copyright © 2020 Rongqing Ye. All rights reserved.
//

#include "texture.hpp"
#include "engine.hpp"

void Texture::load(GameEngine *engine, std::string imagePath) {
    clear();
    SDL_Texture *texture = loadImage(engine, imagePath);
    mSpriteSheet.push_back(texture);
}

void Texture::load(GameEngine *engine, std::vector<std::string>& imagePaths) {
    clear();
    for (auto& path: imagePaths) {
        SDL_Texture *texture = loadImage(engine, path);
        mSpriteSheet.push_back(texture);
    }
}

void Texture::load(GameEngine *engine,
                   std::string imagePath, std::vector<SDL_Rect>& rects) {
    clear();
    
    SDL_Texture *origin = loadImage(engine, imagePath);
    if (!origin) return;
    
    auto renderer = engine->renderer;
    for (auto &rect: rects) {
        SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rect.w, rect.h);
        SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
        SDL_SetRenderTarget(renderer, texture);
        SDL_RenderCopy(renderer, origin, &rect, nullptr);
        
        mSpriteSheet.push_back(texture);
        mWidth = rect.w;
        mHeight = rect.h;
    }
    
    // reset render target
    SDL_SetRenderTarget(renderer, nullptr);
    
    SDL_DestroyTexture(origin);
}

int Texture::count() const {
    return static_cast<int>(mSpriteSheet.size());
}

void Texture::getSize(int *width, int *height) const {
    if (width) *width = mWidth;
    if (height) *height = mHeight;
}

SDL_Texture * Texture::getSDLTexture(int index) const {
    int cnt = count();
    if (index < 0) {
        index += cnt;
    }
    if (index < 0 || index >= cnt) {
        throw "index out of range";
    }
    
    return mSpriteSheet[index];
}

void Texture::clear() {
    for (auto texture: mSpriteSheet) {
        SDL_DestroyTexture(texture);
    }
    mSpriteSheet.clear();
    mWidth = mHeight = 0;
}

SDL_Texture * Texture::loadImage(GameEngine *engine, std::string imagePath) {
    const char *img_path = imagePath.c_str();
    SDL_Surface *surface = IMG_Load(img_path);
    if (!surface) {
        engine->success = false;
        sprintf(engine->errMsg, "Error while loading %s: %s", img_path, IMG_GetError());
        return nullptr;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(engine->renderer, surface);
    if (!texture) {
        SDL_FreeSurface(surface);
        engine->success = false;
        sprintf(engine->errMsg, "Error while creating texture for %s: %s", img_path, SDL_GetError());
        return nullptr;
    }
    
    mWidth = surface->w;
    mHeight = surface->h;
    SDL_FreeSurface(surface);
    return texture;
}
