/* 
 * File:   FreeBrick3dCube.cpp
 * Author: cecco
 * 
 * Created on 31 marzo 2015, 18.25
 */
#include <iostream>
#include "../SysTetris.h"

Eliminated3dCube::Eliminated3dCube(int id, float x, float y, float z, float l) : 
    Brick3dCube(id) {
    
    this->Xreal = x;
    this->Yreal = y;
    this->Zreal = z;
    this->l = l;
}


Eliminated3dCube::~Eliminated3dCube() {
}

bool Eliminated3dCube::updatePosition(float dt) {
    if(Zreal < l && rotation <90) {
        Zreal +=speed*dt;
        rotation += 90*speed*dt;
    } else {
        Xreal += (Xreal-FIELD_W*l)/4*speed*dt;
        Yreal -= 4*speed*dt;
        Zreal += speed/12*dt;
        rotation += 90*speed*dt;
    }
    
    if(abs(Xreal) >1000 || abs(Yreal) >1000 || abs(Zreal) >1000)
        return false;
    
    return true;
}
