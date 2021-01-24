//
//  episode6.hpp
//  SDL_Tutorial
//
//  Created by Rongqing Ye on 5/3/20.
//  Copyright © 2020 Rongqing Ye. All rights reserved.
//

#ifndef episode6_hpp
#define episode6_hpp

#include "engine.hpp"
#include "texture.hpp"
#include "animation.hpp"

class Episode6: public GameEngine {
public:
    virtual bool init(const std::string title="Tutorial", int width=800, int height=600) override;
    virtual void render() override;
    virtual void update() override;

private:
    Texture mDinoTexture;
    Texture mFireworkTexture;
    Animation mDinoAnimation;
    Animation mFireworkAnimation;
};

#endif /* episode6_hpp */
