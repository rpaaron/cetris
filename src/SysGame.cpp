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
#include "BackgroundField.h"

SysGame::SysGame() {
}


SysGame::~SysGame() {
}

bool SysGame::load() {    
    Tetris = new SysTetris();
    Tetris->setXYZField(0,-2,-60);
    Tetris->setXYZFieldRot(0,0,0);
    Tetris->updateLastFieldRot();
    
    BackField = new BackgroundField(10);
    
    return true;
}



void SysGame::update(float dt) {
    
    if(Tetris->isGameOver() && !Tetris->isPaused()) {
        Tetris->switchPause();
        delete Tetris;
        load();
    }
    
    BackField->update(dt);
    Tetris->update(dt);

}

void SysGame::render() {
    glLoadIdentity();
    BackField->draw();
    
    glLoadIdentity();
    Tetris->draw();
}

void SysGame::keypressed(SDL_Event& ev) {
    
    Tetris->keypressed(ev);
}

void SysGame::keyrelased(SDL_Event& ev) {
    
    Tetris->keyrelased(ev);
}
