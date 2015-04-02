/* 
 * File:   Brick3dCube.h
 * Author: cecco
 *
 * Created on 30 marzo 2015, 22.47
 */

#ifndef BRICK3DCUBE_H
#define	BRICK3DCUBE_H

class Brick3dCube {
public:
    Brick3dCube(int id);
    Brick3dCube(int id, int x, int y);
    virtual ~Brick3dCube();

    float getX() { return x; }
    float getY() { return y; }
    
    float getXreal() { return Xreal; }
    float getYreal() { return Yreal; }
    void setXY(int x, int y) { this->x= x; this->y=y; }
    void setXYreal(int x, int y) { this->Xreal= x; this->Yreal=y; }
    int getID() { return id; }
    
    void setSpeed(float speed) { this->speed = speed; }
    
    
    void updatePosition(float dt);

protected:
    int id;
    int x,y;
    float Xreal, Yreal;
    float speed = 5;
    
    float delta=0.1;
};


#endif	/* BRICK3DCUBE_H */

