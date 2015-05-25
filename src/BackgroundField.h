/*
 * File:   BackgroundField.h
 * Author: cecco
 *
 * Created on 13 aprile 2015, 21.47
 */

#ifndef BACKGROUNDFIELD_H
#define	BACKGROUNDFIELD_H

#include "SysTetris/Brick.h"

class BackgroundField {
public:
    BackgroundField(int nCubes);
    virtual ~BackgroundField();

    void update(float dt);
    void draw();
    
    void setAlpha(float a) { alpha=a;}
private:
    Brick **Cubelist;
    int nCubes;
    float vel = 10;
    float l = 10;
    float alpha=0.2;
};

#endif	/* BACKGROUNDFIELD_H */

