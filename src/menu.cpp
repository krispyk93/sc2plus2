#include "menu.h"
#include "menus/practice_menu.h"
#include "menus/main_menu.h"
#include "menus/player_menu.h"
#include "menus/audio_menu.h"


typedef void (*menu_render_t)();

menu_render_t MenuRenderList[MAX_MENU_RENDER_FLAGS] = {
    MainMenu::render,
    PracticeMenu::render,
    AudioMenu::render
};

menu_render_t currentMenu = nullptr;

typedef void (*menu_update_t)();

menu_update_t MenuUpdateList[MAX_MENU_UPDATE_FLAGS] = {
    MainMenu::update,
    PracticeMenu::update,
    PlayerMenu::update,
    MainMenu::update,
    AudioMenu::update,
    MainMenu::update
};

menu_update_t menu_update = nullptr;

typedef void (*menu_draw_t)();

menu_draw_t MenuDrawList[MAX_MENU_UPDATE_FLAGS] = {
    MainMenu::draw,
    PracticeMenu::draw,
    PlayerMenu::draw,
    MainMenu::draw,
    AudioMenu::draw,
    MainMenu::draw
};

menu_draw_t menu_draw = nullptr;

namespace MenuProcess {
    void to_menu_update() {
        if (menu_update) {
            menu_update();
        }
    }

    void to_menu_draw() {
        if (menu_draw) {
            menu_draw();
        }
    }

    void set_menu(int idx) {
        if (idx > MENU_NONE) {
            menu_update = MenuUpdateList[idx];
            menu_draw = MenuDrawList[idx];
        } else {
            menu_update = nullptr;
            menu_draw = nullptr;
        }
    }
    
} // namespace MenuProcess

namespace MenuRendering {
    void render_active_menus() {
        if (currentMenu) {
            currentMenu();
        }
    }

    void set_menu(MenuIndex idx) {
        if (idx > MN_NONE_INDEX) {
            currentMenu = MenuRenderList[idx];
        } else {
            currentMenu = nullptr;
        }
    }


    void close_active_menus() {
        if (currentMenu) {
            currentMenu = nullptr;
        }
    }

    bool is_menu_open() {
        return currentMenu != nullptr;
    }
}  // namespace MenuRendering