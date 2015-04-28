/* 
 * File:   Bar.h
 * Author: cecco
 *
 * Created on 24 marzo 2015, 18.23
 */

#ifndef BAR_H
#define	BAR_H

#include "Brick.h"

class Bar : public Brick {
public:
    Bar(int x);
    virtual ~Bar();
    

    int getBodyValue(int r, int c);
    

private:
    const int body [2][4][4] { 
        {   { 0, 0, 0, 0 },
            { 1, 1, 1, 1 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 }, },
            
        {   { 0, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 1, 0, 0 }, }
    };
};

#endif	/* BAR_H */

