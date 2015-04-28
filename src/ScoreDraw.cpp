/* 
 * File:   ScoreDraw.cpp
 * Author: cecco
 * 
 * Created on 12 aprile 2015, 15.13
 */

#include <iostream>
#include <cmath>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#include "ScoreDraw.h"
#include "SysTetris.h"

ScoreDraw::ScoreDraw(float l) {
    this->l = l;
    //position relative to the center of field
    
    setPlayPosition();
    
    Xreal = Xpos;
    Yreal = Ypos;
    Zreal = Zpos;
    XrealRot = Xrot;
    
    scorel = l;
}

ScoreDraw::~ScoreDraw() {
}

void ScoreDraw::update(int score, float dt) {
    realScore= score;
    
    for(int i=0; i<5; i++) {
        if(toRotate[i])
           RotateAngle += 180*dt; 
        
        if(RotateAngle >= 90) {
            for(int j=0; j<5; j++)
                toRotate[j]=false;
            RotateAngle =0;
            displayScore = realScore;
        }
    }
     
    moveToPos(dt);
}

void ScoreDraw::moveToPos(float dt) {
    float delta= 0.01;
    float dx = fabs(Xreal - Xpos);
    float dy = fabs(Yreal - Ypos);
    float dz = fabs(Zreal - Zpos);
    
     
    if(dx > delta)
        Xreal > Xpos ? Xreal -= dx*speed*dt : Xreal += dx*speed*dt;
    else
        Xreal = Xpos;
    
    if(dy > delta)
        Yreal > Ypos ? Yreal -= dy*speed*dt : Yreal += dy*speed*dt;
    else
        Yreal = Ypos;
    
    if(dz > delta)
        Zreal > Zpos ? Zreal -= dz*speed*dt : Zreal += dz*speed*dt;
    else
        Zreal = Zpos;


    float dxr = fabs(XrealRot - Xrot);
    if(dxr > delta)
        XrealRot > Xrot ? XrealRot -= dxr*speed*dt : XrealRot += dxr*speed*dt;
    else
        XrealRot = Xrot;
}


void ScoreDraw::draw() {
    glTranslatef(Xreal, Yreal, Zreal);
    glRotatef(XrealRot,1,0,0);
    
    drawColoredCharCube(scorel, {0,0,1.0,0.2}, {0,255,255,0}, "S");
    glTranslatef(2*scorel, 0, 0);
    drawColoredCharCube(scorel, {0,0,1.0,0.2}, {0,255,255,0}, "c");
    glTranslatef(2*scorel, 0, 0);
    drawColoredCharCube(scorel, {0,0,1.0,0.2}, {0,255,255,0}, "o");
    glTranslatef(2*scorel, 0, 0);
    drawColoredCharCube(scorel, {0,0,1.0,0.2}, {0,255,255,0}, "r");
    glTranslatef(2*scorel, 0, 0);
    drawColoredCharCube(scorel, {0,0,1.0,0.2}, {0,255,255,0}, "e");
    glTranslatef(2*scorel, 0, 0);
    drawColoredCube(scorel, {0,0,1.0,0.2});
    
    std::string realS = std::to_string(realScore);
    std::string S = std::to_string(displayScore);
    
    for(int i=4; i>=0; i--) {
        char Sc[] = "0";
        
        if(S.size() >i)
            Sc[0] = S[S.size()-1- i];
        
        char realSc[] = "0";
        
        if(realS.size() >i)
            realSc[0] = realS[realS.size()-1- i];
        
        glTranslatef(2*scorel, 0, 0);
        
        glPushMatrix();
        if(toRotate[i])
            glRotatef(RotateAngle, 1,0,0);
        drawColoredCharCube(scorel, {0,0,1.0,0.2}, {0,255,255,0}, Sc);
        
        
        if(realSc[0] != Sc[0]) {
            glRotatef(-90, 1,0,0);
            drawColoredCharCube(scorel, {0,0,1.0,0.2}, {0,255,255,0}, realSc);
            glRotatef(90, 1,0,0);
            toRotate[i] = true;
        }
        glPopMatrix();
    }
    
}

void ScoreDraw::setPausePosition() {
    Zpos = Zpos + l*20;
    Ypos = -l*(FIELD_H/2);
    Xrot = 11120;
}

void ScoreDraw::setPlayPosition() {
    Xpos = -l*(FIELD_W);
    Ypos = l*(FIELD_H)+ l*4;
    Zpos = 0;
    Xrot = 15;
}


