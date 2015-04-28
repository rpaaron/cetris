/* 
 * File:   Brick.h
 * Author: cecco
 *
 * Created on 24 marzo 2015, 18.16
 */

#ifndef BRICK_H
#define	BRICK_H

#ifndef SYSTETRIS_H
#include "../SysTetris.h"
#endif

#include "../Brick3dCube.h"

class Brick {
public:
    Brick();
    Brick(int x);
    virtual ~Brick();
    
    void init3dCubes();
    void delete3dCubes();
    
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    
    int getX() { return x; }
    int getY() { return y; }
    int getID(){ return id;}
    
    
    bool checkPos(int x, int y, Brick3dCube* field[FIELD_H][FIELD_W]);
    void saveOnField(Brick3dCube* field[FIELD_H][FIELD_W]);

    void rotate();
    void rotatedCheckPos(Brick3dCube* field[FIELD_H][FIELD_W]);
    
    
    virtual int getBodyValue(int r, int c) = 0;
    
    
    void update(float dt);
    Brick3dCube** get3Dcubes() { return bodyBricks; }
    
    
    enum SPEEDS { LATERAL , VERTICAL , ROTATE, ROWFALL };
    void setBodyCubesSpeed(SPEEDS s);
    
    bool toDraw() { return drawIt; }
    void setToDraw(bool s) { drawIt = s; } 
    
    float getAngle() { return angle; };
    void setAngle(float a) { angle = a; };
    float getH() { return h; }
    void setH(float h) { this->h = h; } 
private:
    
protected:
    int x, y;
    int id;
    int rotation;
    int maxRotation;
    
    bool drawIt = true;
    
    Brick3dCube* bodyBricks[4];
    
    float angle=0;
    float h=0;
};

#include "Bar.h"
#include "LBar.h"
#include "RLBar.h"
#include "ZBar.h"
#include "RZBar.h"
#include "TBar.h"
#include "Quad.h"

#endif	/* BRICK_H */

