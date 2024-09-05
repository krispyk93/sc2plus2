#include "sc2/sc2.h"
#include "sc2/controller.h"
#include "menus/main_menu.h"
#include "controller.h"
#include "utils/cursor.hpp"
#include "utils/lines.hpp"
#include <stdio.h>
#include "draw.h"

#define LINES 11
#define LINES2 5


int cursor = 0;
int menu = 0;
int count = LINES2;

char menuName[] = "MAIN MENU";

Line lines[LINES] = {
    {"cheats", PRACTICE_INDEX, "Turn cheats on/off", false},
    {"flags", FLAGS_INDEX, "Turn in-game flags on/off", false},
    {"inventory", INVENTORY_INDEX, "Set Link's items and equipment", false},
    {"memory", MEMORY_INDEX, "View/edit memory and add watches", false},
    {"practice", PRACTICE_INDEX, "Load practice files", false},
    {"scene", SCENE_INDEX, "Adjust the scene's state", false},
    {"settings", SETTINGS_INDEX, "Configure settings", false},
    {"tools", TOOLS_INDEX, "Use various tools for practice and testing", false},
    {"warping", WARPING_INDEX, "Warp to dungeons, towns, grottos, etc.", false},
    {"actor", ACTOR_SPAWN_INDEX, "Spawn an Actor", false},
    {"audio", AUDIO_INDEX, "Audio Debug", false}
};

char menuLines[LINES2][16] = {
    "PRACTICE",
    "PLAYER",
    "GAME",
    "AUDIO",
    "MISC"
};

void MainMenu::update() {

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

    if (sc2_mPad1.button_press0 & Controller::Pad2::Y) {
        int nextMenu = cursor + 1;
        MenuProcess::set_menu(nextMenu);
    } else if (sc2_mPad1.button_press0 & Controller::Pad2::X) {
        MenuProcess::set_menu(MENU_MAIN);
    }
}

void MainMenu::draw() {
    drawText(48.0f, 24.0f, MenuDraw::textFloat, menuString, 0xFF0000FF, menuName);

    for (int i = 0; i < LINES2; i++) {
        if (cursor == i) {
            MenuDraw::cursorColor = 0xFFFF00FF; // yellow
        } else {
            MenuDraw::cursorColor = 0xFFFFFFFF; // white
        }
        drawText(48.0f, (i * 16) + 40.0f, MenuDraw::textFloat, menuString, MenuDraw::cursorColor, menuLines[i]);
    }
}

void MainMenu::render() {
    /*
    if (button_is_pressed(Controller::B)) {
        MenuRendering::set_menu(MN_NONE_INDEX);
        fifo_visible = true;
        return;
    };

    Utilities::move_cursor(cursor, LINES);

    if (current_input == 256 && !a_held) {
        switch (cursor.y) {
            case MEMORY_INDEX: {
                MenuRendering::set_menu(MN_MEMORY_INDEX);
                return;
            }
            case INVENTORY_INDEX: {
                MenuRendering::set_menu(MN_INVENTORY_INDEX);
                return;
            }
            case CHEAT_INDEX: {
                MenuRendering::set_menu(MN_CHEAT_INDEX);
                return;
            }
            case TOOLS_INDEX: {
                MenuRendering::set_menu(MN_TOOLS_INDEX);
                return;
            }
            case SETTINGS_INDEX: {
                MenuRendering::set_menu(MN_SETTINGS_INDEX);
                return;
            }
            case WARPING_INDEX: {
                MenuRendering::set_menu(MN_WARPING_INDEX);
                return;
            }
            case PRACTICE_INDEX: {
                MenuRendering::set_menu(MN_PRACTICE_INDEX);
                return;
            }
            case SCENE_INDEX: {
                MenuRendering::set_menu(MN_SCENE_INDEX);
                return;
            }
            case FLAGS_INDEX: {
                MenuRendering::set_menu(MN_FLAGS_INDEX);
                return;
            }
            case ACTOR_SPAWN_INDEX: {
                MenuRendering::set_menu(MN_ACTOR_SPAWN_INDEX);
                return;
            }
            case AUDIO_INDEX: {
                MenuRendering::set_menu(MN_AUDIO_INDEX);
                return;
            }
        }
    }

    Utilities::render_lines(lines, cursor.y, LINES);*/
};
