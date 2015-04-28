/* 
 * File:   Bar.cpp
 * Author: cecco
 * 
 * Created on 24 marzo 2015, 18.23
 */
#include "LBar.h"

LBar::LBar(int x) : Brick(x) {
    id = 4;   
    maxRotation = 4;
    
    Brick::init3dCubes();
}


LBar::~LBar() {
}

int LBar::getBodyValue(int r, int c) { 
    if(r>=0 && r<4 && c>=0 && c<=4)
        return body[rotation][r][c]; 
    return 0;
}
