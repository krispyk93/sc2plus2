#include "menu.h"
#include "audio.h"

#define UNLOCK_AMT 0x51

extern int menu_input;
extern bool menu_input_init;

class PracticeMenu : public Menu {
public:
    PracticeMenu() : Menu() {}
    static void update();
    static void draw();
    static void render();

    enum PRACTICE_ENTRY {
        PRACTICE_PLAYER2,
        PRACTICE_LOOP,
        PRACTICE_MAX
    };

    enum Input {
        NOTHING,
        RECORD,
        PLAY
    };

    struct sc2HumanUnlockable {
        uint8_t unlockable[6];
    };
    static_assert(sizeof(sc2HumanUnlockable) == 0x6);

    struct sc2Unlockable {
        uint8_t entry[UNLOCK_AMT];
    };
    static_assert(sizeof(sc2Unlockable) == UNLOCK_AMT);

    /* TODO: move somewhere else */
    struct CSSEntry{
	/* 0x0000 */ uint16_t		char_id;
	/* 0x0002 */ uint16_t		unk0;
	/* 0x0004 */ uint32_t       unk1;
	/* 0x0008 */ uint8_t        costumeIcon[4];
	/* 0x000C */ uint8_t        pad[0x18];
	/* 0x0024 */
    }; // Character Select Entries
    static_assert(sizeof(CSSEntry) == 0x24);
};

#define sc2_heihachi_unlock_addr 0x8027952C
#define sc2_spawn_unlock_addr  0x80279532

#define sc2_css_link_addr 0x80250544

#define sc2_unlock_addr 0x80402160
#define sc2_unlock (*(PracticeMenu::sc2Unlockable *)sc2_unlock_addr)

#define sc2_heihachi_unlock (*(PracticeMenu::sc2HumanUnlockable *)sc2_heihachi_unlock_addr)
#define sc2_spawn_unlock (*(PracticeMenu::sc2HumanUnlockable *)sc2_spawn_unlock_addr)

#define sc2_css_link (*(PracticeMenu::CSSEntry *)sc2_css_link_addr)


