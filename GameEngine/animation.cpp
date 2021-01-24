//
//  animation.cpp
//  SDL_Tutorial
//
//  Created by Rongqing Ye on 5/2/20.
//  Copyright © 2020 Rongqing Ye. All rights reserved.
//

#include "animation.hpp"
#include "texture.hpp"

Animation::Animation() {
    init();
}

Animation::Animation(Texture *texture, LoopType type) {
    init(texture);
    mType = type;
}

Animation::~Animation() {}

void Animation::update(int dx, int dy) {
    if (mDead) return;

    mPosX += dx;
    mPosY += dy;
    
    mFrame ++;
    if (mFrame == mDuration) {
        mFrame = 0;
    }
    
    if (mType == LOOPTYPE_LIFESPAN) {
        mLifespan --;
        if (!mLifespan)
            mDead = true;
    }
}

void Animation::render(SDL_Renderer *renderer) {
    if (mDead) return;
    
    // compute index
    int cnt = mTexture->count();
    int index = mFrame * cnt / mDuration;
    SDL_Texture *origin = mTexture->getSDLTexture(index);
    
    int w = static_cast<int>(mScale * mCrop.w);
    int h = static_cast<int>(mScale * mCrop.h);
    SDL_Rect rect = {mPosX, mPosY, w, h};
    
    SDL_RenderCopy(renderer, origin, &mCrop, &rect);
}

void Animation::init(Texture *texture) {
    mTexture = texture;
    mType = LOOPTYPE_INFINITY;
    mDuration = 0;
    mFrame = 0;
    mScale = 1.0;
    mPosX = mPosY = 0;
    mCrop = SDL_Rect{0, 0, 0, 0};
    mDead = false;
    if (texture) {
        mDuration = 3 * texture->count();
        texture->getSize(&mCrop.w, &mCrop.h);
    }
}

void Animation::init(Texture *texture, LoopType type, int duration) {
    init(texture);
    mType = type;
    mDuration = duration;
    if (type == LOOPTYPE_LIFESPAN)
        mLifespan = mDuration;
}
