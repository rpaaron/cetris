/* 
 * File:   Brick.h
 * Author: cecco
 *
 * Created on 24 marzo 2015, 18.16
 */

#ifndef BAR_H
#include "Bar.h"
#endif

#ifndef QUAD_H
#include "Quad.h"
#endif

#ifndef TBAR_H
#include "TBar.h"
#endif

#ifndef LBAR_H
#include "LBar.h"
#endif

#ifndef ZBAR_H
#include "ZBar.h"
#endif

#ifndef RZBAR_H
#include "RZBar.h"
#endif

#ifndef RLBAR_H
#include "RLBar.h"
#endif

#ifndef SYSTETRIS_H
#include "../SysTetris.h"
#endif

#include "../Primitives.h"
#include "../Brick3dCube.h"

#ifndef BRICK_H
#define	BRICK_H

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
private:
    
protected:
    int x, y;
    int id;
    int rotation;
    int maxRotation;
    
    Brick3dCube* bodyBricks[4];
};

#endif	/* BRICK_H */

