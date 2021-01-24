//
//  episode4.hpp
//  SDL_Tutorial
//
//  Created by Rongqing Ye on 4/29/20.
//  Copyright © 2020 Rongqing Ye. All rights reserved.
//

#ifndef episode4_hpp
#define episode4_hpp

#include "engine.hpp"

class Episode4: public GameEngine {
public:
    virtual bool init(const std::string title="Tutorial", int width=800, int height=600) override;
    virtual void render() override;
    virtual void handleEvent(SDL_Event &event) override;
    
private:
    int x, y;
    int rad;
    int step;
};

#endif /* episode4_hpp */
