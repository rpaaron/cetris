/* 
 * File:   TBar.h
 * Author: cecco
 *
 * Created on 24 marzo 2015, 18.23
 */

#ifndef TBAR_H
#define	TBAR_H

#include "Brick.h"

class TBar : public Brick {
public:
    TBar(int x);
    virtual ~TBar();
    

    int getBodyValue(int r, int c);
    

private:
    const int body [4][4][4] { 
        {   { 0, 1, 0, 0 },
            { 1, 1, 1, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 }, },
            
        {   { 0, 1, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 }, },
        
        {   { 0, 0, 0, 0 },
            { 1, 1, 1, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 }, },
            
        {   { 0, 1, 0, 0 },
            { 1, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 }, },
    };
};

#endif	/* BAR_H */

