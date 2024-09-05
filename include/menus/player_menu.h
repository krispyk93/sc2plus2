#include "menu.h"
#include "audio.h"

enum PlayerIndex {
};

extern int menu_disp_pos;
extern int menu_disp_animation;
extern int menu_disp_frames;

class PlayerMenu : public Menu {
public:
    PlayerMenu() : Menu() {}
    static void update();
    static void draw();
    static void render();
};