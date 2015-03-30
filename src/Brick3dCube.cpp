/* 
 * File:   Brick3dCube.cpp
 * Author: cecco
 * 
 * Created on 30 marzo 2015, 22.47
 */

#include "Brick3dCube.h"

Brick3dCube::Brick3dCube(int id, int x, int y) {
    this->id = id;
    this->x = x;
    this->y = y;
    Xreal=x;
    Yreal=y;
}


Brick3dCube::~Brick3dCube() {
}

void Brick3dCube::updatePosition(float dt) {
    
    if(Xreal > (float) x+delta)
        Xreal -= speed*dt;
    if(Xreal < (float) x-delta)
        Xreal += speed*dt;
    
    if(Yreal > (float) y+delta)
        Yreal -= speed*dt;
    if(Yreal < (float) y-delta)
        Yreal += speed*dt;
}


