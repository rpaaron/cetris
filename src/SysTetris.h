/* 
 * File:   Tetris.h
 * Author: cecco
 *
 * Created on 24 marzo 2015, 17.36
 */

#define FIELD_H 20
#define FIELD_W 10

#include <list>

#ifndef SYSTETRIS_H
#define	SYSTETRIS_H

#include "SysTetris/Brick.h"
#include "Brick3dCube.h"
#include "SysTetris/Eliminated3dCube.h"


class SysTetris {
public:
    SysTetris();
    virtual ~SysTetris();
    
    void update(float dt);
    void draw();
    
    void drawFieldLimits();
    void updateBackColor(float dt);
    
    void setXYZField(float x, float y, float z) { XField=x; YField=y; ZField=z;}
    void setXYZFieldRot(float x, float y, float z)
        { XFieldRot=x; YFieldRot=y; ZFieldRot=z; }
    void setCubel (float l) { this->l = l; }
    
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
    std::list <Eliminated3dCube*> freeBrick3dCube;
    
    //bool for control movement
    bool Left=0, Right=0;
    
    int score=0;
    
    //control move animation
    float MinTimeMove =0;
    const float MoveSpeed = 100;
    
    //3d position of the field
    float XField=0, YField=0, ZField=0;
    float XFieldRot=0, YFieldRot=0, ZFieldRot=0;
    
    //lenght of half a cube
    float l = 1;
    
    //control fall animation
    float FallTime = 0;
    const float FallSpeed = 10;
    float AdditionFallSpeed = 0;
    float MaxFallSpeed = 100;
    
    Brick *currentBrick = NULL;
    Brick *nextBrick = NULL;
    
    //control animation of next brick
    float nextBrickRotation=0;

    COLOR backColor;
};

#endif	/* TETRIS_H */

