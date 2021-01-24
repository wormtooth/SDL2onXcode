//
//  texture.hpp
//  SDL_Tutorial
//
//  Created by Rongqing Ye on 5/1/20.
//  Copyright © 2020 Rongqing Ye. All rights reserved.
//

#ifndef texture_hpp
#define texture_hpp

#include "sdl.hpp"
#include <vector>
#include <string>

class GameEngine;

/**
 @class Texture
 A simple wrapper around SDL_Texture. However, it contains not just one SDL_Texture, but a list of them to represent a sprite sheet ready for animation.
 
 @discussion
 The class represents a sprite sheet instead of a single SDL_Texture, so it contains multiple frames. For example, for a walking character, it has different walking poses which compose a walking animation.
 
 @warning
 We assume that all SDL_Texture within one Texture instance has the same width and height.
 */
class Texture {
public:
    /** Constructor.
     */
    Texture(): mWidth(0), mHeight(0) {}
    
    /** Destructor.
     */
    ~Texture() {clear();}
    
    // Loading functions

    /** Load one texture from an image.
     */
    void load(GameEngine *engine, std::string imagePath);
    
    /** Load multiple textures from a list of images.
     */
    void load(GameEngine *engine, std::vector<std::string>& imagePaths);
    
    /** Load multiple textures from a sprite sheet and a list of given regions.
     */
    void load(GameEngine *engine, std::string imagePath, std::vector<SDL_Rect>& rects);
    
    // Properties access
    
    /** Get the count of SDL_texture in this texture.
     */
    int count() const;
    
    /** Query the width and height of the texture.
     */
    void getSize(int *width, int *height) const;
    
    /** Get a SDL_Texture by index.
     
     @discussion
     It allows negative index, meaning to get the texture counting from the back.
     */
    SDL_Texture * getSDLTexture(int index=0) const;

private:
    /** Clear claimed memory.
     */
    void clear();
    
    /** Load an image to a SDL_Texture
     
     @discussion
     After the image is sucessfully loaded, mWidth and mHeight will be set according to the image's size.
     */
    SDL_Texture * loadImage(GameEngine *engine, std::string imagePath);

private:
    /** The list of SDL_Texture within this sprite sheet.
     */
    std::vector<SDL_Texture *> mSpriteSheet;
    
    /** The size of each SDL_Texture.
     */
    int mWidth, mHeight;
};

#endif /* texture_hpp */
