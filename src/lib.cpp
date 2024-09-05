#include "sc2/sc2.h"
#include "sc2/controller.h"
#include "utils/hook.h"
#include "utils/player.hpp"
#include "utils/practice.hpp"
#include "menu.h"
#include "menus/main_menu.h"
#include "menus/settings_menu.h"
#include "menus/player_menu.h"
#include "menus/practice_menu.h"
#include "audio.h"
#include "draw.h"
#include "system.h"

bool card_load = true;

#define COUNTMAIN 5
#define COUNTCHEAT 1
#define COUNTPLAYER 1
#define COUNTGAME 1
#define COUNTAUDIO 1
#define COUNTMISC 1

#define COUNTMENU COUNTMAIN + 1

#define ENTRYMAX 16

extern "C" {

#define main_tampoline ((void(*)(void))0x802977D0)
void apply_lib_hooks() {
    Hook::apply_hooks();
    MenuProcess::set_menu(MENU_MAIN);
    main_tampoline();
}

void init() {
}

int cursor = 0;
int menu = 0;
int count = COUNTMAIN;
int paused_prev = 0;

void game_loop() {

    using namespace Controller::Pad;

    /* Button Combo Tests *//*
    if ((sc2_mPad1.button_held & Controller::Pad2::L) &&
            (sc2_mPad1.button_held & Controller::Pad2::R) ) {
                /*
        if (sc2_mPad1.button_press0 & Controller::Pad2::B) {
            // Player 1 mirrors Player 2's move set
            if (sc2_player1.id_0 && sc2_player2.id_0) {
                if (sc2_player2.id_0 != 0x19) { // if not necrid
                    sc2_player1.moveset_id_1 = sc2_player2.moveset_id_1;
                    sc2_player1.moveset_id_2 = sc2_player2.moveset_id_2;
                }
            }
        } else if (sc2_mPad1.button_press0 & Controller::Pad2::X) {
            playSound(0.0f, 0x1D);
        }
    }*/
    //paused_prev = sc2_paused;
    //if (paused_prev && (paused_prev !=sc2_paused)){
    //    record_init = false;
    //}
    System::MainUpdate();
}


void draw() {

    System::MainDraw();
}

void pad() {
    using GameScreen = System::GameScreen;

    if ((sc2_gameScreen  == GameScreen::IN_GAME) &&recording) {
        if (currentFrame < 419) {
            currentFrame++;
            inputBuf.input[currentFrame] = sc2_mPad1;
            inputBuf.frames = currentFrame;
        }
    }else if (playback) {
        if (currentFrame < maxFrames) {
            sc2_mPad2 = inputBuf.input[currentFrame];    
            //sc2_mPad12 = inputBuf.input[currentFrame];            
            currentFrame++;
        } else if (play_loop) {
            currentFrame = 0;
        }
    }
}

}