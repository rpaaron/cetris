/* 
 * File:   Primitives.h
 * Author: cecco
 *
 * Created on 24 marzo 2015, 17.31
 */
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#ifndef PRIMITIVES_H
#define	PRIMITIVES_H

struct COLOR {
  GLfloat r,g,b,a;
};
    
void drawCube(float l);
void drawColoredCube(float l, COLOR col);
void drawColoredCharCube(float l, COLOR col, SDL_Color charcol, const char* text);
void drawCharQuad(float l, SDL_Color charcol, const char* text);

#endif	/* PRIMITIVES_H */

