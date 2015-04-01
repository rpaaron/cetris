/* 
 * File:   Quad.cpp
 * Author: cecco
 * 
 * Created on 24 marzo 2015, 18.23
 */
#include<stdio.h>

#include "Quad.h"

Quad::Quad(int x) : Brick(x) {
    id = 1;
    maxRotation = 1;
    
    Brick::init3dCubes();
    printf("create quad\n");
}

Quad::~Quad() {
    printf("deleting quad\n");

}


int Quad::getBodyValue(int r, int c) { 
    if(r>=0 && r<4 && c>=0 && c<=4)
        return body[rotation][r][c]; 
    return 0;
}