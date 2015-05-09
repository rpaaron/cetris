/* 
 * File:   SystemGL.cpp
 * Author: cecco
 * 
 * Created on 23 marzo 2015, 22.14
 */
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_opengl.h>

#include "SystemSDL.h"


SystemSDL::SystemSDL(int width, int height, int bpp) {

    this->height = height;
    this->width = width;
    this->bpp = bpp;
}


SystemSDL::~SystemSDL() {
}

bool SystemSDL::init() {
   
      //Initialize SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
      { return false; } //Create Window


    //Set caption
    SDL_WM_SetCaption( "Tetris3d", NULL );
    
    SDL_Surface *icon = SDL_LoadBMP("data/icon.bmp");
    if(icon == NULL) {
         printf("Icon load error: %s\n", SDL_GetError());
    } else {
        SDL_SetColorKey ( icon , SDL_SRCCOLORKEY, 
                SDL_MapRGB( icon->format, 255, 0, 255) );
    } 
    
    SDL_WM_SetIcon(icon, NULL);
    

    if( SDL_SetVideoMode( width, height, bpp, SDL_OPENGL | SDL_RESIZABLE) == NULL )
      { return false; } //Initialize OpenGL

	glClearColor(0, 0, 0, 0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, ((float)width/(float)height), 0.1, 1000.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
    glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0f);
        
	glDepthFunc(GL_LEQUAL);
	//orion spec:
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glEnable(GL_BLEND);
        
	glEnable(GL_LIGHTING);
	GLfloat OrionEnv [] = { 0.2, 0.2, 0.2, 1};
	GLfloat OrionLight[] = { 0.8, 0.8, 0.8, 1 };
	GLfloat OrionPos[] =  { 0, 0, 0, 1.0f }; 
	glLightfv(GL_LIGHT1, GL_AMBIENT, OrionEnv);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, OrionLight);
	glLightfv(GL_LIGHT1, GL_POSITION, OrionPos);
	glEnable(GL_LIGHT1);

    glEnable(GL_COLOR_MATERIAL);
        
    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR ) {
      printf("Error initializing OpenGL! %s\n", gluErrorString(error));
      return false;
    }
    
    
    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
        return false;    
    
    Game = new SysGame();
    
    return true;
}

void SystemSDL::loop() {
    Game->load();
    
    quitLoop = false;
    Uint32 timer;
    dt =0;   
    
    while(!quitLoop) {
        timer = SDL_GetTicks();

        eventUpdate();

        Game->update(dt);

        //Clear color buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        Game->render();

        //Update screen
        SDL_GL_SwapBuffers();
        
        timer = SDL_GetTicks() - timer;
        dt = (float)(timer) /1000;
    }
}

void SystemSDL::eventUpdate() {
    //While there are events to handle
    while( SDL_PollEvent( &event ) ) {
        if( event.type == SDL_QUIT ) {
            quitLoop = true;
        } else if( event.type == SDL_KEYDOWN ) {
            Game->keypressed(event);
        } else if(event.type == SDL_KEYUP) {
            Game->keyrelased(event);
        }

        if(event.type == SDL_VIDEORESIZE) {
            width = event.resize.w;
            height = event.resize.h;
            SDL_SetVideoMode( width, height, bpp, SDL_OPENGL | SDL_RESIZABLE );
            glViewport(0,0,width,height);

            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluPerspective(45.0, ((float)width/(float)height), 0.1, 1000.0);

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
        }
    }
    
    if(Game->toQuit())
        quitLoop = true;
}

