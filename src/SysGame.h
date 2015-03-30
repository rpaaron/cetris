/* 
 * File:   Game.h
 * Author: cecco
 *
 * Created on 24 marzo 2015, 17.57
 */


#ifndef GAME_H
#define	GAME_H

#include "SysTetris.h"
#include "Primitives.h"
#include "KeyEvent.h"


class SysGame : KeyEvent {
public:
    SysGame();
    virtual ~SysGame();
    
    bool load();
    void update(float dt);
    void render();
    

    virtual void keypressed(SDL_Event& ev);
    virtual void keyrelased(SDL_Event& ev);


private:
   SysTetris *Tetris;
};

#endif	/* GAME_H */

