/* 
 * File:   SysMenu.cpp
 * Author: cecco
 * 
 * Created on 25 aprile 2015, 13.05
 */

#include <cmath>
#include <string>

#include "Primitives.h"
#include "SysMenu.h"


SysMenu::SysMenu(float l) {
    this->l = l;
    MarginCredits = 10*l;
    Xcredits = -MarginCredits;

    Title = new char [100];
    strcpy(Title, "  Cetris!!!  ");
    TitleL = strlen(Title);
}

SysMenu::~SysMenu() {
    delete [] Title;
}


void SysMenu::update(float dt) {

    float delta = fabs(MenuRot - MenuRotAnim);
    if(delta > dt*VelRot) {
        MenuRotAnim < MenuRot? 
            MenuRotAnim += VelRot*dt : MenuRotAnim -= VelRot*dt;
    } else {
        MenuRotAnim = MenuRot;
    }

    static float tmp =0;
    tmp += TitleVel*dt;
    TitleRot -= TitleVel*dt;
    if(tmp >=90) {
        NTurn++;
        tmp=tmp-90;
    }

    Xcredits -= 2*dt;
    if(Xcredits <= -MarginCredits)
        Xcredits = MarginCredits;

    alphaC = 1 - fabs(Xcredits)/ MarginCredits;
}


void SysMenu::draw() {


    glPushMatrix();
    drawTitle();
    glPopMatrix();


    glTranslatef(0,-4*l,-20);  //allontana
    glPushMatrix();             //push per il messaggio

    glRotatef(MenuRotAnim, 1,0,0);

    glPushMatrix();
    COLOR Cubecol = {0,0,1.0,0.2};
    SDL_Color Textcol = {0,255,0,0};


    glTranslatef(-l*2-l,0,0);
    drawColoredCharCube(l, Cubecol, Textcol," P ", Font);
    glTranslatef(2*l,0,0);
    drawColoredCharCube(l, Cubecol, Textcol," l ", Font);
    glTranslatef(2*l,0,0);
    drawColoredCharCube(l, Cubecol, Textcol," a ", Font);
    glTranslatef(2*l,0,0);
    drawColoredCharCube(l, Cubecol, Textcol," y ", Font);

    glPopMatrix();
    glPushMatrix();
    
    glTranslatef(-l*2-l,0,0);
    glRotatef(180,1,0,0);
    
    Textcol = {255,0,0,0};
    drawCharQuad(l+0.01, Textcol, " E ", Font);
    glTranslatef(2*l,0,0);
    drawCharQuad(l+0.01, Textcol, " x ", Font);
    glTranslatef(2*l,0,0);
    drawCharQuad(l+0.01, Textcol, " i ", Font);
    glTranslatef(2*l,0,0);
    drawCharQuad(l+0.01, Textcol, " t ", Font);
    glPopMatrix();

    //messaggio
    glPopMatrix();
    glPushMatrix();
    glTranslatef(Xcredits - LCredits/2,-4*l,0);
    drawText(0.5,0.5, {0,0,255,0}, "Programming:", Font, alphaC);
    glTranslatef(4.15/2,0,0);
    drawText(0.5,0.5, {200,0,100,0}, "Francesco Gatti", Font, alphaC);
    glTranslatef(4.6/2,0,0);
    drawText(0.5,0.5, {0,0,255,0}, "- Music:", Font, alphaC);
    glTranslatef(2.5/2,0,0);
    drawText(0.5,0.5, {200,0,100,0}, "Bruno Ghion", Font, alphaC);


    glPopMatrix();
}

void SysMenu::drawTitle() {
    
    glTranslatef(0,2*l,-20);
    glRotatef(TitleRot,0,1,0);
    
    COLOR Cubecol = {0,0,1.0,0.2};
    SDL_Color Textcol = {255,255,0,0};
    
    drawColoredCube(2*l, Cubecol);
    
    
    static int pos[] = {0,1,2,3};

    if(NTurn !=0)
    	pos[(NTurn-1)%4] = (NTurn+3)%TitleL;

    char s[4] = " # ";
    s[1] = Title[pos[0]];    drawCharQuad(2*l, Textcol, s, Font);
    
    glRotatef(90,0,1,0);
    s[1] = Title[pos[1]];    drawCharQuad(2*l, Textcol, s, Font);
    
    glRotatef(90,0,1,0);
    s[1] = Title[pos[2]];    drawCharQuad(2*l, Textcol, s, Font);
    
    glRotatef(90,0,1,0);
    s[1] = Title[pos[3]];    drawCharQuad(2*l, Textcol, s, Font);
}


void SysMenu::switchEntry() {
    if(currentEntry == PLAY_e) currentEntry = EXIT_e;
    else                       currentEntry = PLAY_e;
}

void SysMenu::keypressed(SDL_Event& ev) {

    if(MenuRotAnim == MenuRot) {
        if (ev.key.keysym.sym == SDLK_UP) {
            MenuRot += 180;
            switchEntry();
        }
        if (ev.key.keysym.sym == SDLK_DOWN) {
            MenuRot -= 180;
            switchEntry();
        }


        if (ev.key.keysym.sym == SDLK_RETURN) {
            if (currentEntry == PLAY_e)
                setStat(PLAY);
            if (currentEntry == EXIT_e)
                setStat(EXIT);
        }
    }
}




void SysMenu::keyrelased(SDL_Event& ev) {

}



