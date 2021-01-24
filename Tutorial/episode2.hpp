//
//  episode2.hpp
//  SDL_Tutorial
//
//  Created by Rongqing Ye on 4/25/20.
//  Copyright © 2020 Rongqing Ye. All rights reserved.
//

#ifndef episode2_hpp
#define episode2_hpp

#include "engine.hpp"

class Episode2: public GameEngine {
public:
    virtual void render() override;
    
    virtual void draw();
};

#endif /* episode2_hpp */
