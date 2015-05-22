//
// Created by cecco on 22/05/15.
//

#include "utils.h"
#include "SysMusic.h"


SysMusic::SysMusic() {
    for(int i=0; i<nChunks; i++)
        Music[i] = NULL;

    for(int i=0; i<nChunks; i++) {
        Music[i] = Mix_LoadWAV(data(MusicPaths[i]).c_str());
        if (Music[i] == NULL) {
            printf("Failed to load %s sound! SDL_mixer Error: %s\n", MusicPaths[i], Mix_GetError());
            exit(1);
        }
    }

    ActualRoutine =NONE;
    RoutineToSet =NONE;
}

SysMusic::~SysMusic() {

    for(int i=0; i<nChunks; i++) {
        if(Music[i] != NULL)
            Mix_FreeChunk(Music[i]);
    }

}

int SysMusic::playChannel(int channel, TYPE t, int loop) {
    return Mix_PlayChannel(channel, Music[t],loop);
}

void SysMusic::update(int score) {


    switch (RoutineToSet) {
        case MENU:
            menuRoutine();
            break;

        case PLAY:
            playRoutine(score);
            break;

        case END:
            endRoutine();
            break;

        case PAUSE:
            pauseRoutine();
            break;

        case NONE:
            break;
    }
}

void SysMusic::menuRoutine() {
    if(ActualRoutine != RoutineToSet) {
        ActualRoutine = RoutineToSet;
        Mix_FadeInChannel(0, Music[BASS_INTRO],0,1000);
        return;
    }

    if(!Mix_Playing(0)) {
        Mix_PlayChannel(0, Music[BASS_INTRO], 0);
        Mix_PlayChannel(1, Music[BATT_INTRO1], 0);
    }
}

void SysMusic::playRoutine(int score) {
    if(ActualRoutine != RoutineToSet && PlayStatus==0) {
        ActualRoutine = RoutineToSet;
    }

    if(!Mix_Playing(0)) {
        printf("Status %d\n", PlayStatus);
        if(PlayStatus ==0) {
            Mix_PlayChannel(0, Music[BASS_INTRO], 0);
            Mix_PlayChannel(1, Music[BATT_INTRO1], 0);
            PlayStatus++;
        } else if(PlayStatus ==1) {
            Mix_PlayChannel(0, Music[BASS_INTRO], 0);
            Mix_PlayChannel(1, Music[BATT_INTRO2], 0);
            PlayStatus = rand()%6;

        } else if(PlayStatus==2) {
            Mix_PlayChannel(0, Music[BASS1], 0);
            Mix_PlayChannel(1, Music[BATT1], 0);
            Mix_PlayChannel(2, Music[LEAD1], 0);
            PlayStatus = 3;

        } else if(PlayStatus ==3) {
            Mix_PlayChannel(0, Music[BASS2], 0);
            Mix_PlayChannel(1, Music[BATT1], 0);
            Mix_PlayChannel(2, Music[LEAD2], 0);
            PlayStatus = 0;

        } else if(PlayStatus ==4) {
            Mix_PlayChannel(0, Music[BASS3], 0);
            Mix_PlayChannel(1, Music[BATT2], 0);
            Mix_PlayChannel(2, Music[LEAD3], 0);
            PlayStatus = 2;

        } else if(PlayStatus ==5) {
            Mix_PlayChannel(0, Music[BASS4], 0);
            Mix_PlayChannel(1, Music[BATT2], 0);
            Mix_PlayChannel(2, Music[LEAD4], 0);
            PlayStatus = 0;
        } else {
            PlayStatus=0;
        }
    }

}

void SysMusic::pauseRoutine() {

}

void SysMusic::endRoutine() {

}
