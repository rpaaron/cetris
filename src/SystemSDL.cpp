/* 
 * File:   SystemGL.cpp
 * Author: cecco
 * 
 * Created on 23 marzo 2015, 22.14
 */


#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_mixer.h>

#include <GLFW/glfw3.h>
#include "SystemSDL.h"
#include "utils.h"


void cetPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar) {
    static const GLdouble pi = 3.1415926535897932384626433832795;
    auto fH = tan( (fovy / 2) / 180 * pi ) * zNear;
    auto fW = fH * aspect;
    glFrustum(-fW, fW, -fH, fH, zNear, zFar);
}


SystemSDL::SystemSDL(int width, int height, int bpp) {

    this->height = height;
    this->width = width;
    this->bpp = bpp;
}


SystemSDL::~SystemSDL() {

    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
}

bool SystemSDL::init() {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* xxx = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
      //Initialize SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
        printf( "SDL could not initialize! SDL Error: %s\n", Mix_GetError() );
        return false;
    }
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); //SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 3); //OpenGL 3+
    SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 2); //OpenGL 3.3

    //Set caption
    //SDL_WM_SetCaption( "Cetris", NULL );
    SDL_Surface *icon = SDL_LoadBMP(data("data/icon.bmp").c_str());
    if(icon == NULL) {
         printf("Icon load error: %s\n", SDL_GetError());
    } else {
        SDL_SetColorKey ( icon , SDL_TRUE, 
                SDL_MapRGB( icon->format, 255, 0, 255) );
    } 
    
    

    //if( SDL_SetVideoMode( width, height, bpp, SDL_OPENGL | SDL_RESIZABLE) == NULL )
    screen = SDL_CreateWindow("Cetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    if (screen == nullptr)
      { return false; }

    //SDL_WM_SetIcon(icon, NULL);
    SDL_SetWindowIcon(screen, icon);
    SDL_Renderer *renderer = SDL_CreateRenderer(screen, -1, 0);

    //Initialize OpenGL
    SDL_GLContext glcontext = SDL_GL_CreateContext(screen);
	printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));
	printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VENDOR));
	printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_RENDERER));
	printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_EXTENSIONS));
	GLint maj, min;
	glGetIntegerv(GL_MAJOR_VERSION, &maj);
	glGetIntegerv(GL_MINOR_VERSION, &min);
	std::cout << "Versin " << maj << " " << min << "\n";

	int maj2, min2;
	SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &maj2);
	SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &min2);
	std::cout << "Versin " << maj2 << " " << min2 << "\n";
	glClearColor(0, 0, 0, 0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	cetPerspective(45.0, ((float)width/(float)height), 0.1, 1000.0);

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
      std::cout << "EEEEEEEEEERRRRRRRRRRRRRRRRRRRRRRRRROOOOOOOOOOOOOOOOOORRRRRRRRRRRRRRRRRRRR\n";
      //printf("Error initializing OpenGL! %s\n", gluErrorString(error)); // FIXME
      return false;
    }
    
    
    //Initialize SDL_ttf
    if( TTF_Init() == -1 ) {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", Mix_GetError() );
        return false;
    }

    //Initialize SDL_mixer
    if( Mix_OpenAudio( 44100, AUDIO_S16SYS, 6, 2048 ) < 0 ) {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }

    Game = new SysGame();

    if(!Game->load())
        return false;

    return true;
}


void SystemSDL::loop() {

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
        SDL_GL_SwapWindow(screen);
        
        timer = SDL_GetTicks() - timer;
        dt = (float)(timer) /1000;
    }
}

void SystemSDL::eventUpdate() {
    //While there are events to handle
    while( SDL_PollEvent( &event ) ) {

        //std::cout << "Event type " << (uint32_t) event.type << "\n";
        //std::cout << "Event window " << (uint32_t) event.window.event << "\n";
        if( event.type == SDL_QUIT ) {
            quitLoop = true;
        } else if( event.type == SDL_KEYDOWN ) {
            Game->keypressed(event);
        } else if(event.type == SDL_KEYUP) {
            Game->keyrelased(event);
        }

        if(event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED) {
            std::cout << "Get resize\n";
            width = event.window.data1;
            height = event.window.data2;
            //SDL_SetVideoMode( width, height, bpp, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE ); //FIXME
            glViewport(0,0,width,height);

            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            cetPerspective(45.0, ((float)width/(float)height), 0.1, 1000.0);

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
        }
    }
    
    if(Game->toQuit())
        quitLoop = true;
}

