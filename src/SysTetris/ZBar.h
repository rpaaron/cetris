/* 
 * File:   TBar.h
 * Author: cecco
 *
 * Created on 24 marzo 2015, 18.23
 */

#ifndef ZBAR_H
#define	ZBAR_H

#ifndef BRICK_H
    #include "Brick.h"
#endif

class ZBar : public Brick {
public:
    ZBar(int x);
    virtual ~ZBar();
    

    int getBodyValue(int r, int c);
    

private:
    const int body [2][4][4] { 
        {   { 1, 1, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 }, },
            
        {   { 0, 0, 1, 0 },
            { 0, 1, 1, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 }, }
    };
};

#endif	/* BAR_H */

