#include <stdio.h>
#include "utils/practice.hpp"
#include "sc2/sc2.h"
#include "sc2/system.h"
#include "sc2/mot.h"
#include "sc2/controller.h"
#include "menus/practice_menu.h"
#include "draw.h"
#include "system.h"

bool record_init = false;
int currentFrame = 0;
int maxFrames = 0;
bool recording = false;
bool playback = false;
bool play_loop = false;

Controller::InputBuffer inputBuf;

namespace Practice {
    char inputString[3][10] = {
        "",
        "RECORDING",
        "PLAYING"
    };

    int paused_prev = 0;

    bool playback_init = false;

    void input_record_draw() {
        uint32_t textColor = COLOR_BLUE;
        uint32_t valColor = COLOR_WHITE;
        int i = 0;

        if (recording) {
            i = 1;
        } else if (playback) {
            i = 2;
        }

        drawText(48.0f, (4 * 16) + 30.0f, MenuDraw::textFloat, menuString, textColor, 
                        inputString[i]);
        drawText(48.0f, (5 * 16) + 30.0f, MenuDraw::textFloat, menuString3, valColor, 
                        currentFrame);
        drawText(96.0f, (5 * 16) + 30.0f, MenuDraw::textFloat, menuString3, valColor, 
                        maxFrames);
    }

    void input_record_init() {
        inputBuf.frames = 0;
        currentFrame = 0;
    }

    void input_write_to_buffer(Controller::PadButton2 input) {
        input.button_held = sc2_mPad1.button_held;
    }

    void input_record() {
        if (currentFrame < 419) {
            currentFrame++;
            //input_write_to_buffer(inputBuf.input[currentFrame]);
            inputBuf.input[currentFrame] = sc2_mPad1;
            inputBuf.frames = currentFrame;
        }
    }

    void input_play() {
        if (currentFrame < maxFrames) {
            sc2_mPad1 = inputBuf.input[currentFrame];    
            sc2_mPad12 = inputBuf.input[currentFrame];            
            currentFrame++;
        }
    }

    void input_main() {

        /*if (paused_prev == 1) {
            currentFrame = 0;
            record_init = false;
            playback_init = false;
        }*/
        /*
        if (menu_input == PracticeMenu::Input::RECORD){
            recording = true;
            playback = false;
        } else if (menu_input == PracticeMenu::Input::PLAY){
            recording = false;
            playback = true;
        } else {
            recording = false;
            playback = false;
        }
        */

        if ((sc2_gameScreen  == System::GameScreen::IN_GAME) && recording) {
            if (!record_init) {
                input_record_init();
                record_init = true;
                sc2_player1.controller = 01;
                sc2_player2.controller = 00;
            } else {
                //input_record();
            }
        } else if (playback)  {
            if (!record_init) {
                currentFrame = 0;
                record_init = true;
                sc2_player1.controller = 00;
                sc2_player2.controller = 01;
            } else {
                //input_play();
            }
        }
    }
}