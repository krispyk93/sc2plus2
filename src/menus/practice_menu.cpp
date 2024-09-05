#include "sc2/controller.h"
#include "sc2/sc2.h"
#include "sc2/system.h"
#include "menus/practice_menu.h"
#include "controller.h"
#include "cheats.h"
#include "utils/practice.hpp"
#include "utils/cursor.hpp"
#include "utils/lines.hpp"
#include <string.h>
#include "draw.h"

#define LINES CHEAT_AMNT
#define LINES2 2

//static Cursor cursor = {0, 0};
static int cursor = 0;
bool init_once = false;
bool chest_collision = false;
using namespace Cheats;
int menu_input = 0;
int menu_loop = 0;
bool menu_input_init = false;
int paused_prev = 0;
bool play_loop = false;

char menuName[] = "PRACTICE";
char toggleString[2][5] = {
    "OFF",
    "ON"
};

char inputString[3][10] = {
    "NOTHING",
    "RECORD",
    "PLAY"
};

char menuLine[] = "$s$P1#X#Y#Z#C%s %04X";
char lineString[] = "$s$P1#X#Y#Z#C%s %s";

Line2 menuLines[LINES2] = {
    {"2P", &menu_input},
    {"LOOP", &menu_loop},
    //{"Set Action", &menu_act_id},
};

namespace Cheats {
    using namespace Controller;

    void apply_cheats() {
    };
}  // namespace Cheats

void PracticeMenu::update() {

    if (sc2_mPad1.button_press0 & Controller::Pad2::DOWN) {
        cursor++;
        if (cursor >= LINES2) {
            cursor = 0;
        }
    } else if (sc2_mPad1.button_press0 & Controller::Pad2::UP) {
        cursor--;
        if (cursor < 0) {
            cursor = LINES2 - 1;
        }
    }

    if (sc2_mPad1.button_press0 & Controller::Pad2::RIGHT) {
        switch (cursor) {
            case PRACTICE_PLAYER2:
                menu_input++;
                if (menu_input > 2) {
                    menu_input = 2;
                }
                break;
            case PRACTICE_LOOP:
                menu_loop = 1;
                play_loop = true;
                break;
        }
    } else if (sc2_mPad1.button_press0 & Controller::Pad2::LEFT) {
        switch (cursor) {
            case PRACTICE_PLAYER2:
                menu_input--;
                if (menu_input < 0) {
                    menu_input = 0;
                }
                break;
            case PRACTICE_LOOP:
                menu_loop = 0;
                play_loop = false;
                break;
        }
    }

    if (sc2_mPad1.button_press0 & Controller::Pad2::Y) {
        /* Toggle cheat */
        switch (cursor) {
            case PracticeMenu::PRACTICE_PLAYER2:
                switch (menu_input){
                    case Input::RECORD:
                        recording = true;
                        playback = false;
                        sc2_player1.controller = 1;
                        sc2_player2.controller = 0;
                        break;
                    case Input::PLAY:
                        recording = false;
                        playback = true;
                        sc2_player1.controller = 0;
                        sc2_player2.controller = 1;
                        break;
                    default:
                        recording = false;
                        playback = false;
                        sc2_player1.controller = 0;
                        sc2_player2.controller = 1;
                }
                record_init = false;
                playSound(0.0f, 0x13);
                break;
            default:
                break;
            
        }
    } else if (sc2_mPad1.button_press0 & Controller::Pad2::X) {
        MenuProcess::set_menu(MENU_MAIN);
    }
}

void PracticeMenu::draw() {
    drawText(48.0f, 24.0f, MenuDraw::textFloat, menuString, 0xFF0000FF, menuName);

    for (int i = 0; i < LINES2; i++) {
        if (cursor == i) {
            MenuDraw::cursorColor = 0xFFFF00FF; // yellow
        } else {
            MenuDraw::cursorColor = 0xFFFFFFFF; // white
        }
        switch (i) {
            case PRACTICE_PLAYER2:
                if (recording) MenuDraw::cursorColor = COLOR_RED;
                else if (playback) MenuDraw::cursorColor = COLOR_GREEN;
                drawText(48.0f, (i * 16) + 40.0f, MenuDraw::textFloat, lineString, MenuDraw::cursorColor, 
                    menuLines[i].line, inputString[*menuLines[i].value]);
                break;
            case PRACTICE_LOOP:
            default:
                drawText(48.0f, (i * 16) + 40.0f, MenuDraw::textFloat, lineString, MenuDraw::cursorColor, 
                    menuLines[i].line, toggleString[*menuLines[i].value]);
                break;
        }
    }

    
}

void PracticeMenu::render() {
};