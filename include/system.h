#pragma once

#include <stdint.h>
#include <string.h>

namespace System {
    void MainUpdate();
    void MainDraw();

    void GameUpdate();
    void GameDraw();

    void ChrSelectUpdate();
    void ChrSelectDraw();

    void lock_camera();
    void unlock_camera();
    void hide_hud();
    void show_hud();

    enum GameMode  : uint16_t {
        UNK00,
        ARCADE,
        TIME_ATTACK,
        VS,
        TEAM_BATTLE,
        VS_TEAM_BATTLE,
        SURVIVAL,
        PRACTICE
    };

    enum GameScreen : uint32_t {
        BOOT,
        NAMCO,
        UNK02,
        UNK03,
        UNK04,
        TITLE,
        MENU,
        IN_GAME,
        UNK08,
        RANK,
        CHR_SELECT,
        INTRO_TITLE,
        INTRO_ARCADE,
        UNK0D,
        UNK0E,
        UNK0F,
        SAVE,
        WEAPON_MASTER = 0x1C,
        ART_GALLERY = 0x1E,
        BOOT2 = 0x21, // ?
        MEMORY_CARD = 0x22,
        NINTENDO = 0x25,
    };

    enum Language {
        ENG,
        JPN
    };

    struct sc2StageName {
        uint32_t name[31];
    };
    static_assert(sizeof(sc2StageName) == 0x7C);
}

#define sc2_paused (*(uint32_t *)sc2_paused_addr)
#define sc2_gameMode (*(uint16_t *)sc2_gameMode_addr)
#define sc2_inGame (*(uint16_t *)sc2_inGame_addr)
#define sc2_gameScreen (*(uint32_t *)sc2_gameScreen_addr)
#define sc2_language (*(uint32_t *)sc2_language_addr)
#define sc2_stageName (*(System::sc2StageName *)sc2_stageName_addr)