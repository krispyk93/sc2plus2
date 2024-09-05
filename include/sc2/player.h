#include <stdint.h>



namespace Player {

    struct Player1 {
        /* 0x0000 */ uint8_t  pad0[2];        // 0x8034D4C0
        /* 0x0002 */ uint8_t  controller; // controller // 00 = controller 1, 01 = controller 2
        /* 0x0003 */ uint8_t  pad00[0x55];        // 0x8034D4C0
        /* 0x0006 */ //uint8_t is_cpu;
        /* 0x0008 */ //uint32_t opponent player pointer;
        /* 0x0024 */ // buttons
        /* 0x0034 */ // enum direction pressed2
        /* 0x0038 */ // enum direction pressed
        /* 0x003C */ // enum direction held
        /* 0x0038 */ // 
        /* 0x004C */ // enum direction pressed2
        /* 0x0050 */ // int player_control       // 8034D510
        /* 0x0058 */ uint16_t id_0;              // 8034D518
        /* 0x005A */ uint16_t moveset_id_1;      // 8034D51A
        /* 0x005C */ uint16_t moveset_id_2;      // 8034D51C
        /* 0x005E */ uint16_t id_3;              // 8034D51E
        /* 0x0060 */ uint16_t unk4;          // 8034D520
        /* 0x0062 */ uint16_t unk5;          // 8034D522
        /* 0x0064 */ uint16_t costume;          // 8034D524
        /* 0x0066 */ uint8_t pad1[0x3A];       // 8034D526
        /* 0x00A0 */ uint8_t move_active;  // 8034D560
        /* 0x00A1 */ uint8_t unk99a;  // 8034D560
        /* 0x00A2 */ uint8_t pad1e[0x1E];       // 8034D526
        /* 0x00C0 */ uint16_t hitbox_active;  // 8034D580
        /* 0x00C2 */ uint16_t recovery_active;  // 8034D580
        /* 0x00C4 */ uint8_t pad1a[0x1AC];       // 8034D582
        /* 0x0270 */ uint16_t soul_charge;       // 8034D730
		/* 0x0272 */ uint16_t unk0;       // 8034D732
		/* 0x0274 */ uint8_t pad2[0x12D8];       // 8034D734
		/* 0x154C */ uint16_t rounds_won; 		//8034EA0C
        /* 0x154E */ uint16_t unk2; 		    //8034EA0CE
		/* 0x1550 */ uint8_t pad3[0xC];			// 8034EA10
        /* 0x155C */ float health_bar; 			 // 8034EA1C
        /* 0x1560 */ float healthRegenRate;		// 8034EA1C
        /* 0x1564 */ uint8_t pad4[0x8];			// 8034EA20
        /* 0x156C */ float health; 				  // 8034EA2C
        /* 0x1570 */ // float dmg_taken;
        /* 0x15BC */ // float dmg_taken_multiplier;
        /* 0x1570 */ uint8_t pad5[0x290];       // 8034EA30
        /* 0x1800 */ Vec3 pos0;                 // 8034ECC0
        /* 0x180C */ uint8_t pad6[0x41C];       // 8034ECCC
        /* 0x18D0 */ // 
        /* 0x18F8 */ // atbCombo;
        /* 0x191C */ // atkPower;
        /* 0x1920 */ // atkRange;
        /* 0x1924 */ // speed
        /* 0x1C28 */ uint8_t pad7[0x380]; // 8034F0E8 // move set struct? size 0x380
        /* 0x1C58 */// command_no;
        /* 0x1FA8 */ uint16_t s_8034F9B0_unk0; // 8034F468 move set struct
        /* 0x1FAA */ uint16_t s_8034F9B0_unk1; //
        /* 0x1FAC */ int32_t unk352; // pointer? attack frame?
        /* 0x1FB0 */ float   unkFloat2;   // 8034F470 compares with moveset info addr + 0x36 // attack frame?
        /* 0x1FB4 */ uint8_t pad8[0x46]; // 
        /* 0x1FFA */ uint16_t action_id2; // 8034F4BA
        /* 0x1FFC */ uint8_t pad9[0x8]; // 
        /* 0x2004 */ float unkFloat; // FUN_800948a0 param 1
        /* 0x2008 */ uint8_t padA[0x28];
        /* 0x2030 */ uint32_t* s_8034F9B0; // current move set data?
        /* 0x2034 */ uint8_t padB[0x2F4];
        /* 0x21C4 */ //uint8_t padA[0x32E]; // 8034F684
        /* 0x2328 */ uint8_t padC[0x140]; // 8034F684
        /* 0x2468 */ uint8_t padD[0x88]; // 
        /* 0x24F0 */ uint16_t unk1;      // 8034F9B0 struct
        /* 0x24F2 */ uint16_t action_id;		// 8034F9B2
        /* 0x24F4 */ uint8_t padE[0x42C];     // 8034F9B4
        /* 0x0000 */ // 8034FC90
        /* 0x2920 */ Vec3 pos1;                // 8034FDE0
        /* 0x292C */ uint8_t padF[0x24];       // 8034FDEC
        /* 0x2950 */ Vec3 pos2;                // 8034FE10
        /* 0x295C */ uint8_t pad10[0x24];       // 8034FE1C
        /* 0x2980 */ // 8034FE40
    }; // struct Player1

    static_assert(sizeof(Player1) == 0x2980); 

    struct Filename {
        uint8_t player_file_name[0x10];             // 80406374
    }; // struct Filename

    static_assert(sizeof(Filename) == 0x10);
}; // namespace Player

#define sc2_player1 (*(Player::Player1 *)Player1_addr)
#define sc2_player2 (*(Player::Player1 *)Player2_addr)

//#endif // LIB_SC2_PLAYER