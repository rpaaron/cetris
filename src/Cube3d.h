//
// Created by cecco on 05/05/15.
//

#ifndef TETRIS3D_CUBE3D_H
#define TETRIS3D_CUBE3D_H


#include "Primitives.h"

class Cube3d {

public:
    Cube3d(float x, float y, float z, float l);
    virtual ~Cube3d();


    void update(float dt);
    void draw();

    COLOR getCol() {  return col;}
    void setCol(COLOR col) { Cube3d::col = col; }

    void setXYZ(float x, float y, float z) { this->x = x; this->y =y; this->z=z; }
    void goToXYZ(float x, float y, float z) { gx = x; gy =y; gz=z; }
    void goToAngleXYZ(float x, float y, float z) { gax = x; gay =y; gaz=z; }
    void goTol(float l) { gl=l; }

    bool getMove() { return move; }
    void setMove(bool s) {move=s; }

    void setL(float s) { l=s; }

private:
    //Real cor
    float x,y,z;
    float ax,ay,az; //angles
    float l;

    //cor to go
    float gx,gy,gz;
    float gax,gay, gaz;
    float gl;

    float speed =20;

    bool move=true;

    COLOR col = { 1, 1, 1, 0.2};

};
#endif //TETRIS3D_CUBE3D_H
