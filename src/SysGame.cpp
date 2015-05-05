/* 
 * File:   Game.cpp
 * Author: cecco
 * 
 * Created on 24 marzo 2015, 17.57
 */

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include "SysGame.h"

SysGame::SysGame() {
    Menu = new SysMenu(CubeL);
}


SysGame::~SysGame() {
}

bool SysGame::load() {  
    Tetris = new SysTetris();
    Tetris->setL(CubeL);
    Tetris->setXYZField(0,-2,-60);
    Tetris->setXYZFieldRot(0,0,0);
    Tetris->updateLastFieldRot();
   
    BackField = new BackgroundField(10);
    
    return true;
}



void SysGame::update(float dt) {
    
    float delta = abs(RotMenuPlayAnim - RotMenuPlay);
    if (delta >2*dt*RotVel) {
        RotMenuPlayAnim<RotMenuPlay?
            RotMenuPlayAnim += RotVel*dt : RotMenuPlayAnim -= RotVel*dt;
    } else {
        RotMenuPlayAnim = RotMenuPlay;
    }
    
    if(Tetris->isGameOver() && !Tetris->isPaused()) {
        Menu->setStat(Menu->MENU);
        
        if(RotMenuPlayAnim == 0) {
            Tetris->switchPause();
            delete Tetris;
            load();
        }
    }
        
    BackField->update(dt);
    
    if(Menu->getStat() == Menu->PLAY) {
        RotMenuPlay = 90;
        Tetris->update(dt);
    } else if(Menu->getStat() == Menu->MENU) {
        RotMenuPlay = 0;
        Menu->update(dt);
    } else if(Menu->getStat() == Menu->EXIT) {
        RotMenuPlay =-90;
        if(RotMenuPlayAnim == -90)
            quit = true;
    }

}

void SysGame::render() {  
        
    glLoadIdentity();
    BackField->draw();
    
    glLoadIdentity();

    glRotatef(RotMenuPlayAnim,0,1,0);
    glPushMatrix();
    if(RotMenuPlayAnim <= 80)
        Menu->draw();
    glPopMatrix();
    
    glRotatef(-90,0,1,0);
    if(RotMenuPlayAnim >= 20)
    Tetris->draw();


}

void SysGame::keypressed(SDL_Event& ev) {
    if(Menu->getStat() == Menu->PLAY) {
        if(ev.key.keysym.sym == SDLK_ESCAPE) {
            Menu->setStat(Menu->MENU);
        }
        
        Tetris->keypressed(ev);
    } else if(Menu->getStat() == Menu->MENU) {
        Menu->keypressed(ev);
    }
}

void SysGame::keyrelased(SDL_Event& ev) {
    if(Menu->getStat() == Menu->PLAY) {
        Tetris->keyrelased(ev);
    } if(Menu->getStat() == Menu->MENU) {
        Menu->keyrelased(ev);
    }
}
