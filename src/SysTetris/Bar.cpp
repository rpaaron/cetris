/* 
 * File:   Bar.cpp
 * Author: cecco
 * 
 * Created on 24 marzo 2015, 18.23
 */

#include "Bar.h"

Bar::Bar(int x) : Brick(x) {
    id = 2;   
    maxRotation = 2;
    
    Brick::init3dCubes();
}


Bar::~Bar() {
}

int Bar::getBodyValue(int r, int c) { 
    if(r>=0 && r<4 && c>=0 && c<=4)
        return body[rotation][r][c]; 
    return 0;
}

    

