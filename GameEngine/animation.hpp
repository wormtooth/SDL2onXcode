//
//  animation.hpp
//  SDL_Tutorial
//
//  Created by Rongqing Ye on 5/2/20.
//  Copyright © 2020 Rongqing Ye. All rights reserved.
//

#ifndef animation_hpp
#define animation_hpp

#include "sdl.hpp"

class Texture;

/** Loop type of animations.
 */
enum LoopType {
    LOOPTYPE_INFINITY,
    LOOPTYPE_LIFESPAN
};

class Animation {
public:
    /** Constructor.
     */
    Animation();
    
    Animation(Texture *texture, LoopType type);
    
    /** Destructor.
     */
    ~Animation();
    
    /** Initialize the animation with given information.
     */
    void init(Texture *texture, LoopType type, int duration);
    
    /** Update of the animation for next frame.
     */
    void update(int dx=0, int dy=0);
    
    /** Render of the animation.
     */
    void render(SDL_Renderer *renderer);
    
    /** Setter.
     */
    void setTexture(Texture *texture) {mTexture = texture;}
    void setType(LoopType type) {mType = type;}
    void setDuration(int duration) {mDuration = duration;}
    void setLifepan(int lifespan) {mLifespan = lifespan;}
    void setCrop(const SDL_Rect crop) {mCrop = crop;}
    void setScale(double scale) {mScale = scale;}
    void setDead(bool dead=true) {mDead = dead;}
    void setPos(int x, int y) {mPosX = x; mPosY = y;}

private:
    /** Common settings.
     */
    void init(Texture *texture = nullptr);

private:
    /** Reference to the underlying texture.
     */
    Texture *mTexture;
    
    /** Loop type. It can either be LOOPTYPE_INFINITY or LOOPTYPE_LIFESPAN
     */
    LoopType mType;
    
    /** Duration of the animation, in terms of number of frames.
     */
    int mDuration;
    
    /** Lifespan of the animation, in terms of number of frames.
     
     @discussion
     The animation will be marked dead if lifespan drops to zero and the loop type is LOOPTYPE_LIFESPAN
     */
    int mLifespan;
    
    /** Frame counter of the animation. It will be reset to zero once it reaches mDuration.
     */
    int mFrame;
    
    /** Position of the animation.
     */
    int mPosX, mPosY;
    
    /** Crop of the underlying texture.
     
     @discussion
     By default, the whole underlying texture is used.
     */
    SDL_Rect mCrop;
    
    /** Scaling factor of the underlying texture.
     */
    double mScale;
    
    /** Whether the animation is dead.
     */
    bool mDead;
};

#endif /* animation_hpp */
