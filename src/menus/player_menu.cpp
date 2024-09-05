#include "sc2/controller.h"
#include "menus/player_menu.h"
#include "controller.h"
#include "utils/cursor.hpp"
#include "utils/lines.hpp"
#include "sc2/sc2.h"
#include <stdio.h>
#include "sc2/system.h"
#include "draw.h"

#define LINES 6
#define LINES2 4
#define SPAWN_OFFSET 4
#define SPAWN_READ_LENGTH 32
#define ROOM_READ_LENGTH 64
#define STAGE_READ_LENGTH 64
#define STAGE_OFFSET 64
#define ROOM_OFFSET 64
#define DEFAULT_LAYER 0xFF

//static Cursor cursor = {0, 0};
static int  cursor = 0;
uint8_t layer = 0xFF;
bool init_once = false;
bool file;

int menu_disp_pos = 0;
int menu_disp_animation = 0;
int menu_disp_frames = 0;
int menu_act_id = 0;
//int32_t bgm_id = 0;

char file_path[89];

char menuName[] = "PLAYER MENU";

char toggleString[2][5] = {
    "OFF",
    "ON"
};

char menuLines[LINES2][24] = {
    "Menu SFX",
    "BGM"
};

enum PlayerLines {
    PLAYER_DISP_POS,
    PLAYER_DISP_ANIMATION,
    PLAYER_DISP_FRAMES,
    PLAYER_ACT_SET
};

char menuLine[] = "$s$P1#X#Y#Z#C%s %04X";
char lineString[] = "$s$P1#X#Y#Z#C%s %s";


Line2 menuLines2[LINES2] = {
    {"Display Position", &menu_disp_pos},
    {"Display Animation", &menu_disp_animation},
    {"Display Frames", &menu_disp_frames},
    {"Set Action", &menu_act_id},
};

void PlayerMenu::update() {

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
            case PLAYER_DISP_POS:
                menu_disp_pos ^= 1;
                break;
            case PLAYER_DISP_ANIMATION:
                menu_disp_animation ^= 1;
                break;
            case PLAYER_DISP_FRAMES:
                menu_disp_frames ^= 1;
                break;
            case PLAYER_ACT_SET:
                if (sc2_mPad1.button_held & Controller::Pad2::R) {
                    menu_act_id += 0x10;
                } else if (sc2_mPad1.button_held & Controller::Pad2::L){
                    menu_act_id += 0x100;
                } else {
                    menu_act_id++;
                }
                break;
        }
    } else if (sc2_mPad1.button_press0 & Controller::Pad2::LEFT) {
        switch (cursor) {
            case PLAYER_DISP_POS:
                menu_disp_pos ^= 1;
                break;
            case PLAYER_DISP_ANIMATION:
                menu_disp_animation ^= 1;
                break;
            case PLAYER_DISP_FRAMES:
                menu_disp_frames ^= 1;
                break;
            case PLAYER_ACT_SET:
                if (sc2_mPad1.button_held & Controller::Pad2::R) {
                    menu_act_id -= 0x10;
                } else if (sc2_mPad1.button_held & Controller::Pad2::L){
                    menu_act_id -= 0x100;
                } else {
                    menu_act_id--;
                }
                if (menu_act_id < 0) {
                    menu_act_id = 0;
                }
                break;
        }
    }

    if (sc2_mPad1.button_press0 & Controller::Pad2::Y) {
        switch (cursor) {
            case PLAYER_DISP_POS:
                menu_disp_pos ^= 1;
                break;
            case PLAYER_DISP_ANIMATION:
                menu_disp_animation ^= 1;
                break;
            case PLAYER_DISP_FRAMES:
                menu_disp_frames ^= 1;
                break;
            case PLAYER_ACT_SET:
                sc2_player1.action_id2 = menu_act_id;
                break;
        }
    } else if (sc2_mPad1.button_press0 & Controller::Pad2::X) {
        MenuProcess::set_menu(MENU_MAIN);
    }
}

void PlayerMenu::draw() {
    drawText(48.0f, 24.0f, MenuDraw::textFloat, menuString, 0xFF0000FF, menuName);

    for (int i = 0; i < LINES2; i++) {
        if (cursor == i) {
            MenuDraw::cursorColor = 0xFFFF00FF; // yellow
        } else {
            MenuDraw::cursorColor = 0xFFFFFFFF; // white
        }

        switch (i) {
            default:
                drawText(48.0f, (i * 16) + 40.0f, MenuDraw::textFloat, lineString, MenuDraw::cursorColor, 
                    menuLines2[i].line, toggleString[*menuLines2[i].value]);
                break;
            case PLAYER_ACT_SET:
                drawText(48.0f, (i * 16) + 40.0f, MenuDraw::textFloat, menuLine, MenuDraw::cursorColor, 
                    menuLines2[i].line, *menuLines2[i].value);
        }
    }
}

void PlayerMenu::render() {

}