#include "menu.h"

enum MainMenuIndex {
    PRACTICE_INDEX,
    FLAGS_INDEX,
    INVENTORY_INDEX,
    MEMORY_INDEX,
    SCENE_INDEX,
    SETTINGS_INDEX,
    TOOLS_INDEX,
    WARPING_INDEX,
    ACTOR_SPAWN_INDEX,
    AUDIO_INDEX
};

class MainMenu : public Menu {
public:
    MainMenu() : Menu() {}
    static void update();
    static void draw();
    static void render();
};