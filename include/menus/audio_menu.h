#include "menu.h"
#include "audio.h"

enum AudioIndex {
    AUDIO_BGM_INDEX,
    AUDIO_BGM_BUTTON_INDEX,
    AUDIO_BGMWAVE_INDEX,
    AUDIO_BGMWAVE_BUTTON_INDEX,
    AUDIO_SFX_INDEX,
    AUDIO_SFX_BUTTON_INDEX
};

class AudioMenu : public Menu {
public:
    AudioMenu() : Menu() {}
    static void update();
    static void draw();
    static void render();
};