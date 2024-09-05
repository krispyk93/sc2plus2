#include "sc2/controller.h"
#include "menus/audio_menu.h"
#include "controller.h"
#include "utils/cursor.hpp"
#include "utils/lines.hpp"
#include "sc2/sc2.h"
#include <stdio.h>
#include "sc2/system.h"
#include "draw.h"

#define LINES 6
#define LINES2 2
#define SPAWN_OFFSET 4
#define SPAWN_READ_LENGTH 32
#define ROOM_READ_LENGTH 64
#define STAGE_READ_LENGTH 64
#define STAGE_OFFSET 64
#define ROOM_OFFSET 64
#define DEFAULT_LAYER 0xFF

//static Cursor cursor = {0, 0};
static int cursor = 0;
uint8_t layer = 0xFF;
bool init_once = false;
bool file;

int32_t menu_sound_id = 0;
int32_t bgm_id = 0;

int bgm_counter = 0;
int bgmwave_counter = 0;
int sfx_counter = 0;

char file_path[89];

char menuName[] = "AUDIO MENU";

char toggleString[2][5] = {
    "OFF",
    "ON"
};

char menuLines[LINES2][24] = {
    "Menu SFX",
    "BGM"
};

enum AudioLines {
    AUDIO_SFX,
    AUDIO_BGM
};

char menuLine[] = "$s$P1#X#Y#Z#C%s %02X";

enum {
    DUNGEON,
    OVERWORLD,
    INTERIOR,
    CAVE,
    SPECIAL
};

char stage_types[5][10] = {
    "dungeon",
    "overworld",
    "interior",
    "cave",
    "special"
};

Line lines[LINES] = {
    {"bgm:", AUDIO_BGM_INDEX, "Background music ID", false},
    {"play bgm", AUDIO_BGM_BUTTON_INDEX, "Play BGM", false},
    {"bgmwave:", AUDIO_BGMWAVE_INDEX, "Instrument Bank, X to set to currently loaded", false},
    {"load bgmwave", AUDIO_BGMWAVE_BUTTON_INDEX, "Load BGMWave", false},
    {"sfx:", AUDIO_SFX_INDEX, "Sound effect ID", false},
    {"play sfx", AUDIO_SFX_BUTTON_INDEX, "Play SFX", false}
};

Line2 menuLines2[LINES2] = {
    {"Menu SFX", &menu_sound_id},
    {"BGM", &bgm_id}
};

void AudioMenu::update() {

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
            case AUDIO_SFX:
                menu_sound_id++;
                if (menu_sound_id > 0x21) {
                    menu_sound_id = 0x21;
                }
                break;
            case AUDIO_BGM:
                bgm_id++;
                if (bgm_id > 0x4E) {
                    bgm_id = 0x4E;
                }
                break;
        }
    } else if (sc2_mPad1.button_press0 & Controller::Pad2::LEFT) {
        switch (cursor) {
            case AUDIO_SFX:
                menu_sound_id--;
                if (menu_sound_id < 0) {
                    menu_sound_id = 0;
                }
                break;
            case AUDIO_BGM:
                bgm_id--;
                if (bgm_id < 0) {
                    bgm_id = 0;
                }
                break;
        }
    }

    if (sc2_mPad1.button_press0 & Controller::Pad2::Y) {
        switch (cursor) {
            case AUDIO_SFX:
                playSound(0.0f, *menuLines2[AUDIO_SFX].value);
                break;
            case AUDIO_BGM:
                playBgm(*menuLines2[AUDIO_BGM].value);
                break;
        }
    } else if (sc2_mPad1.button_press0 & Controller::Pad2::X) {
        MenuProcess::set_menu(MENU_MAIN);
    }
}

void AudioMenu::draw() {
    drawText(48.0f, 24.0f, MenuDraw::textFloat, menuString, 0xFF0000FF, menuName);

    for (int i = 0; i < LINES2; i++) {
        if (cursor == i) {
            MenuDraw::cursorColor = 0xFFFF00FF; // yellow
        } else {
            MenuDraw::cursorColor = 0xFFFFFFFF; // white
        }

        switch (i) {
            default:
                drawText(48.0f, (i * 16) + 40.0f, MenuDraw::textFloat, menuLine, MenuDraw::cursorColor, 
                    menuLines2[i].line, *menuLines2[i].value);
                break;
        }
    }
}

void AudioMenu::render() {
}