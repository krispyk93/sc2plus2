#pragma once
#include "cheats.h"
#include "sc2/utils.h"
#include <string.h>

#define MAX_LIST_MEMBER_LENGTH 40
#define MAX_LIST_ITEMS 20
#define MAX_LINE_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

#define MAX_MENU_RENDER_FLAGS 24
#define MAX_MENU_UPDATE_FLAGS 6

char menuString[] = "$s$P1#X#Y#Z#C%s";
char menuString2[] = "$s$P1#X#Y#Z#C%s %s";
char menuString3[] = "$s$P1#X#Y#Z#C%04X";
char menuString4[] = "$s$P1#X#Y#Z#C%s %03d";
//char lineString[] = "$s$P1#X#Y#Z#C%s %s";

enum MenuIndex {
    MN_NONE_INDEX = -1,
    MN_MAIN_MENU_INDEX = 0,
    MN_PRACTICE_INDEX,
    MN_AUDIO_INDEX
};

enum MenuIndex2 {
    MENU_NONE = -1,
    MENU_MAIN = 0,
    MENU_PRACTICE,
    MENU_PLAYER,
    MENU_GAME,
    MENU_AUDIO,
    MENU_MISC
};

struct ListMember {
    char member[MAX_LIST_MEMBER_LENGTH];
};

struct Line {
    char line[MAX_LINE_LENGTH];
    const int idx;
    char description[MAX_DESCRIPTION_LENGTH];
    bool toggleable = false;
    bool* activation_flag;
    uint8_t max_y_cursor_options;
};

struct Line2 {
    char line[MAX_LINE_LENGTH];
    int32_t* value;
};

struct ItemB {
        uint8_t idx;
        bool active;
    };

class Menu;

namespace MenuProcess {
    void to_menu_update();
    void to_menu_draw();
    void set_menu(int idx);
} // namespace MenuProcess

namespace MenuRendering {
    void render_active_menus();
    void set_menu(MenuIndex idx);
    void close_active_menus();
    bool is_menu_open();
}  // namespace MenuRendering

class Menu {
   public:
    Menu() {}
};