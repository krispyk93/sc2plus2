#pragma once

#include <stdint.h>
#include <string.h>

namespace MenuDraw {
    #define COLOR_GREEN 0x00FF00FF
    #define COLOR_YELLOW 0xFFFF00FF
    #define COLOR_WHITE 0xFFFFFFFF
    #define COLOR_BLUE 0x4CF0F0FF
    #define COLOR_RED 0xFF0000FF

    float textFloat = 0.081113495f;
    uint32_t cursorColor = COLOR_WHITE; // white
    //uint32_t infoColor = 0xFFDB1AFF; // Yellow
    uint32_t infoColor = COLOR_YELLOW;
} // namespace MenuDraw

/* Pointers */
//#define tp_mAudioMgrPtr_addr 0x80451368
//#define tp_mAudioMgrPtr (*(tp_mAudioMgrInfo *)tp_mAudioMgrPtr_addr)

/* Functions */
#define drawText_addr 0x80064f14
typedef void (*drawText_t)(float x, float y, float param3, char* string, uint32_t rgba, ...);
#define drawText ((drawText_t)drawText_addr)


#define drawText2_addr 0x800652b4
typedef void (*drawText2_t)(float x, float y, char* string, uint32_t rgba, ...);
#define drawText2 ((drawText2_t)drawText2_addr)

#define func_800f83d8_addr 0x800f83d8
typedef void (*func_800f83d8_t)(void);
#define func_800f83d8 ((func_800f83d8_t)func_800f83d8_addr)