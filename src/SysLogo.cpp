//
// Created by cecco on 05/05/15.
//

#include "SysLogo.h"

SysLogo::SysLogo() {

    for (int i = 0; i < lmap; i++) {
        for (int j = 0; j < lmap; j++) {
            if(map[i][j]>0) {
                Cube3d *tmp = new Cube3d(-lmap*l+l+ j*2*l, lmap*l - i*2*l, -20.f, 0);
                tmp->setCol({0.6,0.3,0.0,0.2});
                tmp->setMove(false);
                tmp->goTol(l*1.5);
                cubes.push_front(tmp);
            }
        }
    }
}

SysLogo::~SysLogo() {
    for(Cube3d* elem : cubes)
        delete elem;
}

void SysLogo::update(float dt) {
    static float wait=0;
    wait+=10*dt;

    for( std::list<Cube3d*>::iterator elem = cubes.begin() ;
         elem != cubes.end() ; elem++) {
        (*elem)->update(dt);

        if(wait >=15)
            (*elem)->setMove(true);
        if(wait >=16)
            (*elem)->goTol(l);
    }

    if(wait >= 40)
        end=true;
}

void SysLogo::draw() {

    for( std::list<Cube3d*>::iterator elem = cubes.begin() ;
         elem != cubes.end() ; elem++) {
        (*elem)->draw();
    }
}
