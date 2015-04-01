/* 
 * File:   Brick3dCube.cpp
 * Author: cecco
 * 
 * Created on 30 marzo 2015, 22.47
 */
#include <cmath>
#include "Brick3dCube.h"

Brick3dCube::Brick3dCube(int id) {
    this->id = id;
    this->x = 0;
    this->y = 0;
    Xreal=0;
    Yreal=0;
}


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
    
    float dx = fabs(Xreal - float(x));
    float dy = fabs(Yreal - float(y));
    
    if(dx > delta)
        Xreal > x ? Xreal -= dx*speed*dt : Xreal += dx*speed*dt;
    else
        Xreal = x;
    
    if(dy > delta)
        Yreal > y ? Yreal -= dy*speed*dt : Yreal += dy*speed*dt;
    else
        Yreal = y;
}


