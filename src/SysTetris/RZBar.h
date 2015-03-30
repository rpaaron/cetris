/* 
 * File:   TBar.h
 * Author: cecco
 *
 * Created on 24 marzo 2015, 18.23
 */

#ifndef RZBAR_H
#define	RZBAR_H

#ifndef BRICK_H
    #include "Brick.h"
#endif

class RZBar : public Brick {
public:
    RZBar(int x);
    virtual ~RZBar();
    

    int getBodyValue(int r, int c);
    

private:
    const int body [2][4][4] { 
        {   { 0, 1, 1, 0 },
            { 1, 1, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 }, },
            
        {   { 0, 1, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 0, 1, 0 },
            { 0, 0, 0, 0 }, }
    };
};

#endif	/* BAR_H */

