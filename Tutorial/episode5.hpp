//
//  episode5.hpp
//  SDL_Tutorial
//
//  Created by Rongqing Ye on 5/2/20.
//  Copyright © 2020 Rongqing Ye. All rights reserved.
//

#ifndef episode5_hpp
#define episode5_hpp

#include "engine.hpp"
#include "texture.hpp"

class Episode5: public GameEngine {
public:
    virtual bool init(const std::string title="Tutorial", int width=800, int height=600) override;
    virtual void render() override;
    
private:
    Texture mTexture;
};

#endif /* episode5_hpp */
