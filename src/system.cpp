#include "sc2/sc2.h"
#include "sc2/controller.h"
#include "system.h"
#include "audio.h"
#include "draw.h"
#include "menu.h"
#include "menus/main_menu.h"
#include "menus/settings_menu.h"
#include "menus/player_menu.h"
#include "menus/practice_menu.h"
#include "utils/player.hpp"
#include "utils/practice.hpp"



namespace System {
    bool camera_run_once;
    bool hud_run_once;
    bool def_language = true;
    bool def_language2 = true;
    bool def_bgm = true;

    bool hit1 = false;
    bool rec1 = false;
    bool act1 = false;

    bool hit2 = false;
    bool rec2 = false;
    bool act2 = false;

    int language;
    int language2;
    int bgm;

    int hitStart1;
    int recoveryStart1;
    int actStart1;

    int hitFrames;
    int hitFrames2;

    int hitStart2;
    int recoveryStart2;
    int actStart2;

    char wordString[] = "$s$P1#X#Y#Z#C %s";
    char wordString2[] = "$s$P1#X#Y#Z#C %04X";

    int hitColor1 = COLOR_WHITE;
    int hitColor2 = COLOR_WHITE;

    void MainUpdate()  {
        switch (sc2_gameScreen) {
            case GameScreen::IN_GAME:
                GameUpdate();
                break;
            case GameScreen::CHR_SELECT:
                ChrSelectUpdate();
                break;
            default: 
                break;
        }
    }

    void MainDraw(){
        switch (sc2_gameScreen){
            case GameScreen::IN_GAME:
                GameDraw();
                break;
            case GameScreen::CHR_SELECT:
                ChrSelectDraw();
                break;
            default: 
                break;
        }
    }

    void setHitTextColor() {
        if (sc2_player1.unk352 == 1) {hit1 = false; rec1 = false; act1 = false; hitStart1 = recoveryStart1 = actStart1 = 0;}
        if (sc2_player2.unk352 == 1) {hit2 = false; rec2 = false; act2 = false; hitStart2 = recoveryStart2 = actStart2 = 0;}

        if (sc2_player1.move_active == true){
                hitColor1 = COLOR_YELLOW;
                if (sc2_player1.hitbox_active == true){
                    hitColor1 = COLOR_RED;
                    if (!hit1) { hit1 = true;  hitStart1 = sc2_player1.unk352;}
                } else if (sc2_player1.recovery_active == true){
                    hitColor1 = COLOR_GREEN;
                    if (!rec1) { rec1 = true;  recoveryStart1 = sc2_player1.unk352;}
                }
            } else {
                hitColor1 = COLOR_WHITE;
                if (!act1) { act1 = true;  actStart1 = sc2_player1.unk352; hitFrames2 = actStart1 - (actStart2 - hitStart2);}
            }

            if (sc2_player2.move_active == true){
                hitColor2 = COLOR_YELLOW;
                if (sc2_player2.hitbox_active == true){
                    hitColor2 = COLOR_RED;
                    if (!hit2) { hit2 = true;  hitStart2 = sc2_player2.unk352;}
                } else if (sc2_player2.recovery_active == true){
                    hitColor2 = COLOR_GREEN;
                    recoveryStart2 = sc2_player1.unk352;
                    if (!rec2) { rec2 = true;  recoveryStart2 = sc2_player2.unk352;}
                }
            } else {
                hitColor2 = COLOR_WHITE;
                if (!act2) { act2 = true;  actStart2 = sc2_player2.unk352;;}
            }
            if (act1 && act2) {
                (hitFrames = actStart2 - (actStart1 - hitStart1));
                (hitFrames2 = actStart1 - (actStart2 - hitStart2));
            }
    }

    void GameUpdate()  {
        if (sc2_paused) {
            MenuProcess::to_menu_update();
            //if ((sc2_mPad1.button_press0 & Controller::Pad2::START)) {
            //    record_init = false;
            //}
        } else {
            switch(sc2_gameMode) {
                case GameMode::PRACTICE:
                    if (recording) {
                        if ((sc2_mPad1.button_press0 & Controller::Pad2::START)) {
                            maxFrames = currentFrame;
                            recording = false;
                            sc2_player1.controller = 00;
                            sc2_player2.controller = 01;
                        }
                    }
                    switch (menu_input) {
                        case PracticeMenu::Input::RECORD:
                        case PracticeMenu::Input::PLAY:
                            Practice::input_main();
                        default:
                            break;
                    }
                default:
                    break;
            }
            setHitTextColor();
        }
    }

    char myString5[] = "#CSC2 PLUS 0.9.6.1";
    char myString1[] = "#C%04X";
    char frameString[] = "$s$P1#X#Y#Z#CF: %03d ";
    char hitFrameString[] = "$s$P1#X#Y#Z#CH: %03d ";
    char recFrameString[] = "$s$P1#X#Y#Z#CR: %03d ";
    char actFrameString[] = "$s$P1#X#Y#Z#CA: %03d ";

    char plsFrameString[] = "$s$P1#X#Y#Z#C+%03d ";
    char negFrameString[] = "$s$P1#X#Y#Z#C-%03d ";

    void GameDraw(){
        if (sc2_paused) {
            /* Print text test */
            drawText2(320.0f, 440.0f, myString5, COLOR_GREEN);
            MenuProcess::to_menu_draw();
        } else {
            if (menu_disp_pos) {
                Utilities::show_player_info();
            }
            if (menu_disp_animation) {
                Utilities::show_player_action();
            }
            if ((sc2_gameMode == GameMode::PRACTICE) && 
                (recording || playback)) {
                Practice::input_record_draw();
            }

            if (menu_disp_frames) {
                drawText(10.0f, 360.0f, MenuDraw::textFloat, frameString, hitColor1,  sc2_player1.unk352);
                drawText(70.0f, 360.0f, MenuDraw::textFloat, hitFrameString, COLOR_RED,  hitStart1);
                drawText(130.0f, 360.0f, MenuDraw::textFloat, recFrameString, COLOR_GREEN,  recoveryStart1);
                drawText(190.0f, 360.0f, MenuDraw::textFloat, actFrameString, COLOR_WHITE,  actStart1);
    
                if (hitFrames < 0) {
                    int hf = hitFrames * -1;
                    drawText(10.0f, 340.0f, MenuDraw::textFloat, negFrameString, COLOR_RED,  hf);
                } else {
                    drawText(10.0f, 340.0f, MenuDraw::textFloat, plsFrameString, COLOR_GREEN,  hitFrames);
                }
    
                drawText(360.0f, 360.0f, MenuDraw::textFloat, frameString, hitColor2,  sc2_player2.unk352);
                drawText(420.0f, 360.0f, MenuDraw::textFloat, hitFrameString, COLOR_RED,  hitStart2);
                drawText(480.0f, 360.0f, MenuDraw::textFloat, recFrameString, COLOR_GREEN,  recoveryStart2);
                drawText(540.0f, 360.0f, MenuDraw::textFloat, actFrameString, COLOR_WHITE,  actStart2);
            }
            
        }
    }

    void ChrSelectUpdate() {
        /*
        if (sc2_mPad1.button_press0 & Controller::Pad2::X) {
            playSound(0.0f, 0x0D);
            def_language ^= 1;
            language = sc2_language ^ 1;
        }

        if (sc2_mPad2.button_press0 & Controller::Pad2::X) {
            playSound(0.0f, 0x0D);
            def_language2 ^= 1;
            language2 = sc2_language ^ 1;
        }
        */
        /*
        if (sc2_mPad1.button_press0 & Controller::Pad2::L) {
            playSound(0.0f, 0x0D);
            bgm--;
            if (bgm < 0) bgm = 31;
        } else if (sc2_mPad1.button_press0 & Controller::Pad2::R) {
            playSound(0.0f, 0x0D);
            bgm++;
            if (bgm > 31) bgm = 0;
        }
        */

    }

    char languageStr[2][4] = {"ENG", "JPN"};

    void ChrSelectDraw() {
        /*
        int a;
        if (bgm == 31) {
            a = 0x80274F5D;
        } else {
            a = sc2_stageName.name[bgm];
        }

        drawText(10.0f, 20.0f, MenuDraw::textFloat, wordString, COLOR_GREEN, a);
        */
        /*
        if (def_language){
            drawText(10.0f, 420.0f, MenuDraw::textFloat, wordString, COLOR_YELLOW,  languageStr[sc2_language]);
        } else {
            drawText(10.0f, 420.0f, MenuDraw::textFloat, wordString, COLOR_YELLOW,  languageStr[language]);
        }

        if (def_language2){
            drawText(412.0f, 420.0f, MenuDraw::textFloat, wordString, COLOR_YELLOW,  languageStr[sc2_language]);
        } else {
            drawText(412.0f, 420.0f, MenuDraw::textFloat, wordString, COLOR_YELLOW,  languageStr[language2]);
        }
        */
    }

}