//
//  engine.hpp
//  SDL_Tutorial
//
//  Created by Rongqing Ye on 4/25/20.
//  Copyright © 2020 Rongqing Ye. All rights reserved.
//

#ifndef engine_hpp
#define engine_hpp

#include <string>
#include "sdl.hpp"

class GameEngine {
public:
    GameEngine();
    virtual ~GameEngine();
    
    /** Initialize all required members for the engine.
     
     @returns
     True if the initialization goes smoothly, false otherwise.
     */
    virtual bool init(const std::string title="Tutorial", int width=800, int height=600);
    
    /** Clean up all memory claimed by the engine.
     */
    virtual void clear();
    
    /** The game loop where we handle events, rendering and update.
     */
    virtual void loop();
    
    /** Handle events in game loop.
     */
    virtual void handleEvent(SDL_Event &event);
    
    /** Render in game loop.
     */
    virtual void render() {}
    
    /** Update in game loop.
     */
    virtual void update() {}

private:
    /** Change directory to Contents/Resources.
     */
    void changeWorkingDirectory();
    
public:
    bool success;
    bool quit;
    char errMsg[1024];
    
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    int width, height;
    
    /** Number of frames per second.
     */
    int fps;
};

#endif /* engine_hpp */
