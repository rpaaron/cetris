/* 
 * File:   Tetris.h
 * Author: cecco
 *
 * Created on 24 marzo 2015, 17.36
 */

#define FIELD_H 20
#define FIELD_W 10

#ifndef SYSTETRIS_H
#define	SYSTETRIS_H

#include "SysTetris/Brick.h"
#include "Brick3dCube.h"

class SysTetris {
public:
    SysTetris();
    virtual ~SysTetris();
    
    void update(float dt);
    void draw();
    
    Brick3dCube* getField(int r, int c);
    
    Brick* newBrick();
    void createBrick();
    
    COLOR colorFromId(int id);

    void moveLeft(bool s)  { Left  = s; MinTimeMove=0; }
    void moveRight(bool s) { Right = s; MinTimeMove=0; }
    void fallBrick();
    void rotateBrick();
    
    void addFallSpeed(bool s);
    
    bool gameOver=false;
    
private:
    void checkFullLines();
    void removeLine(int n);
    bool copyLine(int s, int d);
    
    Brick3dCube* field[FIELD_H][FIELD_W];
    
    bool Left=0, Right=0;
    
    int score=0;
    
    float MinTimeMove =0;
    const float MoveSpeed = 100;
    
    float FallTime = 0;
    const float FallSpeed = 10;
    float AdditionFallSpeed = 0;
    float MaxFallSpeed = 100;
    
    Brick *currentBrick = NULL;
    Brick *nextBrick = NULL;
    
    float nextBrickRotation=0;

};

#endif	/* TETRIS_H */

