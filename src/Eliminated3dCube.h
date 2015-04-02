/* 
 * File:   FreeBrick3dCube.h
 * Author: cecco
 *
 * Created on 31 marzo 2015, 18.25
 */

#ifndef ELIMINATED3DCUBE_H
#define	ELIMINATED3DCUBE_H

#include "Brick3dCube.h"


class Eliminated3dCube : public Brick3dCube {
public:
    Eliminated3dCube(int id, float x, float y, float z, float l);
    virtual ~Eliminated3dCube();
    
    float getZreal() { return Zreal; }
    bool updatePosition(float dt);
    float getRotation() { return rotation; }
private:  
    float Zreal;
    float l;
    float rotation=0;

};

#endif	/* FREEBRICK3DCUBE_H */

