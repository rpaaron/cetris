//
// Created by cecco on 22/05/15.
//

#include "utils.h"
#include "SysMusic.h"
#include "SysTetris.h"


void readSound(int chan, void *stream, int len, void *udata) {
    BackgroundField *B = (BackgroundField*) udata;
    short* p = (short*) stream;

    static int i=0;
    i = (i++)%(len/2);

    float alpha = 0.2+float(abs(p[i]))/1000/2;
    if(alpha >1)
        alpha=1;
    B->setAlpha(alpha);
}

SysMusic::SysMusic(BackgroundField *BField) {
    this->BField = BField;

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

void SysMusic::update(SysTetris *Tetris) {

    //Leggo dati audio
    void* arg = BField;
    Mix_RegisterEffect(1, readSound, NULL, arg);

    switch (RoutineToSet) {
        case MENU:
            menuRoutine();
            break;

        case PLAY:
            playRoutine(Tetris);
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
        Mix_FadeOutChannel(1,1000);
        Mix_FadeOutChannel(2,1000);
        Mix_FadeOutChannel(3,0);
        return;
    }

    if(!Mix_Playing(0)) {
        Mix_PlayChannel(0, Music[BASS_INTRO], 0);
        Mix_PlayChannel(1, Music[BATT_INTRO1], 0);
    }
}

void SysMusic::playRoutine(SysTetris *Tetris) {
    static int count=0;
    static int count2=0;
    if(Tetris->getScore()==0) {
        count = 0;
        count2= 0;
    }

    if(ActualRoutine != RoutineToSet) {
        if(Tetris->getScore()>0) {
            Mix_Resume(0);
            Mix_Resume(1);
            Mix_Resume(2);
            Mix_FadeOutChannel(3,0);
        }
        ActualRoutine = RoutineToSet;
    }

    if(!Mix_Playing(0)) {
        int s600 =Tetris->getScore();
        int i=0;
        while(s600 >=600) {
            s600 -= 600;
            i++;
        }

        int s2000 =Tetris->getScore();
        int j=0;
        while(s2000 >=2000) {
            s2000 -= 2000;
            j++;
        }

        //Muro alto o ogni 2000 musica calzante
        if( ( Tetris->getScore()>1000 && Tetris->getFieldCount()>FIELD_W*(FIELD_H/2) ) || j>count2) {
            if(PlayStatus==0 || PlayStatus ==4)
                PlayStatus=5;
            else
                PlayStatus=4;

            if(j>count2) count2=j;

        //Musichetta ogni 800 punti
        } else if(i>count && PlayStatus <4) {
                if(PlayStatus==0 || PlayStatus==2)
                    PlayStatus=3;
                else
                    PlayStatus=2;
                count=i;

        //Musica standard
        } else {
            PlayStatus= rand()%2;
        }

        if(PlayStatus ==0) {
            Mix_PlayChannel(0, Music[BASS_INTRO], 0);
            Mix_PlayChannel(1, Music[BATT_INTRO1], 0);
        } else if(PlayStatus ==1) {
            Mix_PlayChannel(0, Music[BASS_INTRO], 0);
            Mix_PlayChannel(1, Music[BATT_INTRO2], 0);
        } else if(PlayStatus==2) {
            Mix_PlayChannel(0, Music[BASS1], 0);
            Mix_PlayChannel(1, Music[BATT1], 0);
            Mix_PlayChannel(2, Music[LEAD1], 0);
        } else if(PlayStatus ==3) {
            Mix_PlayChannel(0, Music[BASS2], 0);
            Mix_PlayChannel(1, Music[BATT1], 0);
            Mix_PlayChannel(2, Music[LEAD2], 0);
        } else if(PlayStatus ==4) {
            Mix_PlayChannel(0, Music[BASS3], 0);
            Mix_PlayChannel(1, Music[BATT2], 0);
            Mix_PlayChannel(2, Music[LEAD3], 0);
        } else if(PlayStatus ==5) {
            Mix_PlayChannel(0, Music[BASS4], 0);
            Mix_PlayChannel(1, Music[BATT2], 0);
            Mix_PlayChannel(2, Music[LEAD4], 0);
        } else {
            PlayStatus=0;
        }

    }

}

void SysMusic::pauseRoutine() {
    if(ActualRoutine != RoutineToSet) {
        Mix_Pause(0);
        Mix_Pause(1);
        Mix_Pause(2);

        ActualRoutine = RoutineToSet;
        return;
    }

    if(!Mix_Playing(3)) {
        Mix_PlayChannel(3, Music[BASS_INTRO], 0);
    }
}

void SysMusic::endRoutine() {
    if(ActualRoutine != RoutineToSet) {
        ActualRoutine = RoutineToSet;
        Mix_FadeOutChannel(0,100);
        Mix_FadeOutChannel(1,100);
        Mix_FadeOutChannel(2,100);
        Mix_FadeOutChannel(3,0);

        Mix_PlayChannel(2, Music[LEAD2], 0);
        return;
    }
}


