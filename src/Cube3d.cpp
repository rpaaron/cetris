//
// Created by cecco on 05/05/15.
//
#include <math.h>

#include "Cube3d.h"




Cube3d::Cube3d(float x, float y, float z, float l) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->l = l;

    gx=x;       gy=y;       gz=z;
    gax=ax=0;   gay=ay=0;   gaz=az=0;
}

Cube3d::~Cube3d() {

}

void Cube3d::update(float dt) {
    if(!move)
        return;
    
    float delta;

    float dx = fabs(gx - x);
    delta = dx*speed*dt;
    if(dx > delta)
        x > gx ? x -= dx*speed*dt : x += dx*speed*dt;
    else
        x = gx;


    float dy = fabs(gy - y);
    delta = dy*speed*dt;
    if(dy > delta)
        y > gy ? y -= dy*speed*dt : y += dy*speed*dt;
    else
        y = gy;


    float dz = fabs(gz - z);
    delta = dz*speed*dt;
    if(dz > delta)
        z > gz ? z -= dz*speed*dt : z += dz*speed*dt;
    else
        z = gz;


    float dl = fabs(gl -l);
    delta = dl*speed*dt;
    if(dl > delta)
        l > gl ? l -= dl*speed*dt : l += dl*speed*dt;
    else
        l = gl;

}

void Cube3d::draw() {
    glPushMatrix();

    glTranslatef(x,y,z);
    glRotatef(ax, 1,0,0);
    glRotatef(ay, 0,1,0);
    glRotatef(az, 0,0,1);

    drawColoredCube(l,col);

    glPopMatrix();
}

