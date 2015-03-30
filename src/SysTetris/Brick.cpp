/* 
 * File:   Brick.cpp
 * Author: cecco
 * 
 * Created on 24 marzo 2015, 18.16
 */

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#include "Brick.h"

Brick::Brick() {

}


Brick::Brick(int x) {
    this->x = x;
    this->y = 0;
    this->id = 0;
    this->rotation =0;

}

Brick::~Brick() {
}

bool Brick::checkPos(int x, int y, int field[FIELD_H][FIELD_W]) {

    for(int i=y; i<y+4; i++) {
        for(int j=x; j<x+4; j++) {
            if(i<0 || i>=FIELD_H || j<0 || j>=FIELD_W)
               if(this->getBodyValue(i-y,j-x) != 0)
                   return false;
            
            if(field[i][j] > 0 && this->getBodyValue(i-y,j-x) != 0)
                return false;
        }
    }
    return true;
}

void Brick::saveOnField(int field[FIELD_H][FIELD_W]) {
    
    for(int i=y; i<y+4; i++) {
        for(int j=x; j<x+4; j++) {            
            if(this->getBodyValue(i-y,j-x) != 0)
                field[i][j] = id;
        }
    }
}

void Brick::rotate() {
    rotation = (rotation+1)% maxRotation;
}

void Brick::rotatedCheckPos(int field[FIELD_H][FIELD_W]) {
    int r = rotation;
    rotation = (rotation+1)% maxRotation;
    
    if(checkPos(this->x, this->y, field)) {
        return;
    } else {
        rotation = r;
    }
}
