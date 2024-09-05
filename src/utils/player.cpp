#include "utils/player.hpp"
#include "sc2/sc2.h"
#include "sc2/system.h"
#include "sc2/mot.h"
#include "menus/settings_menu.h"
#include <stdio.h>
#include "draw.h"

uint8_t red;
uint8_t green;
uint8_t blue;

char playerFloatString[4] = "%f";
char playerFloatX[4] = "%f";
char playerFloatY[4] = "%f";
char playerFloatZ[4] = "%f";
char playerAddrString[] = "$s$P1#X#Y#Z#CADDR: %08X";
char playerAddr2String[] = "$s$P1#X#Y#Z#CS: %08X";
char player34String[] = "$s$P1#X#Y#Z#C34: %04X 38: %04X 48: %04X 4C: %04X";
char playerActString[] = "$s$P1#X#Y#Z#CAnim: %04X";
char playerActAddrString[] = "$s$P1#X#Y#Z#CADDR: %08X";
char playerPosString[] = "$s$P1#X#Y#Z#CX:%7.1f Y:%7.1f Z:%7.1f";


namespace Utilities {
    //float p1_x = (sc2_player1.pos0.x * 100); 
    //char test[] = "$s$P1#X#Y#Z#CX:%s Y:%s Z:%s", playerFloatX, playerFloatY, playerFloatZ;

    void show_player_info() {

        //drawText(10.0f, 180.0f, MenuDraw::textFloat, playerActAddrString, COLOR_YELLOW, 
        //            &sc2_player1);

        //drawText(10.0f, 200.0f, MenuDraw::textFloat, playerAddr2String, COLOR_YELLOW, 
        //            &sc2_player1.pos2);

        //drawText(10.0f, 220.0f, MenuDraw::textFloat, player34String, COLOR_YELLOW, 
        //            sc2_player1.pad0[0x37], sc2_player1.pad0[0x3B], sc2_player1.pad0[0x4B], sc2_player1.pad0[0x4F]);

        /* Print Position (?) */
        drawText(10.0f, 420.0f, MenuDraw::textFloat, playerPosString, COLOR_YELLOW, 
                    sc2_player1.pos0.x * 100, sc2_player1.pos0.y * 100, sc2_player1.pos0.z * 100);
        drawText(412.0f, 420.0f, MenuDraw::textFloat, playerPosString, COLOR_YELLOW, 
                    sc2_player2.pos0.x * 100, sc2_player2.pos0.y * 100, sc2_player2.pos0.z * 100);
    }
    void show_player_action(){

        //drawText(10.0f, 380.0f, MenuDraw::textFloat, playerActAddrString, COLOR_YELLOW, 
        //            &sc2_player1.action_id);
        //drawText(500.0f, 380.0f, MenuDraw::textFloat, playerActAddrString, COLOR_YELLOW, 
        //            &sc2_player2.action_id);

        

        /* Print Action */
        drawText(10.0f, 400.0f, MenuDraw::textFloat, playerActString, COLOR_YELLOW, 
                    sc2_player1.action_id);
        drawText(530.0f, 400.0f, MenuDraw::textFloat, playerActString, COLOR_YELLOW, 
                    sc2_player2.action_id);
    }
}  // namespace Utilities