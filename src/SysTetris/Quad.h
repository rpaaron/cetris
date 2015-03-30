/* 
 * File:   Quad.h
 * Author: cecco
 *
 * Created on 24 marzo 2015, 18.23
 */

#ifndef QUAD_H
#define	QUAD_H

#ifndef BRICK_H
    #include "Brick.h"
#endif

class Quad : public Brick {
public:
    Quad(int x);
    virtual ~Quad();
    
    int getBodyValue(int r, int c);
    
private:
    const int body [1][4][4] { 
        {   { 0, 0, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 1, 1, 0 },
            { 0, 0, 0, 0 }, }
    };
    
};

#endif	/* QUAD_H */

