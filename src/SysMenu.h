/* 
 * File:   SysMenu.h
 * Author: cecco
 *
 * Created on 25 aprile 2015, 13.05
 */

#ifndef SYSMENU_H
#define	SYSMENU_H

#include "KeyEvent.h"


class SysMenu : KeyEvent {
public:
    SysMenu(float l);
    virtual ~SysMenu();
    

    void draw();
    void update(float dt);
    
    virtual void keypressed(SDL_Event& ev);
    virtual void keyrelased(SDL_Event& ev);

    void drawTitle();
    
    enum stat { MENU, PLAY, EXIT};
    enum entry { PLAY_e, EXIT_e};
    
    stat getStat() { return Stat; };
    void setStat(stat s) { Stat=s; };
    
    void switchEntry();
    
private:
    stat Stat= MENU;
    
    entry currentEntry = PLAY_e;
    
    
    float l;
    float MenuRot = 0;
    float MenuRotAnim =0;
    float VelRot = 400;
    
    float TitleRot=0;
    float TitleVel=40;
    
    char *Title;
    int TitleL;
    int NTurn=0;


};

#endif	/* SYSMENU_H */

