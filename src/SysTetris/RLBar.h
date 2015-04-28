/* 
 * File:   TBar.h
 * Author: cecco
 *
 * Created on 24 marzo 2015, 18.23
 */

#ifndef RLBAR_H
#define	RLBAR_H

#include "Brick.h"

class RLBar : public Brick {
public:
    RLBar(int x);
    virtual ~RLBar();
    

    int getBodyValue(int r, int c);
    

private:
    const int body [4][4][4] { 
        {   { 1, 1, 1, 0 },
            { 0, 0, 1, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 }, },
            
        {   { 0, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 1, 1, 0, 0 },
            { 0, 0, 0, 0 }, },
        
        {   { 1, 0, 0, 0 },
            { 1, 1, 1, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 }, },
            
        {   { 0, 1, 1, 0 },
            { 0, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 }, },
    };
};

#endif	/* BAR_H */

