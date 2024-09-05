#ifndef LIB_SC2_DRAW
#define LIB_SC2_DRAW

#include <stdint.h>
#include "addrs.h"

namespace Draw {
    struct DrawProperty {
        uint8_t _p0[0x18];   // 8042EBC8
        uint16_t hud;        // 8042EBE0
        uint8_t _p1[0xF0E];  // 8042EBE2
    };
    static_assert(sizeof(DrawProperty) == 0xF28);
/*
    extern "C"
	{
        void sc2_drawtext(float param_1, float param_2, float param3, char* string, uint32_t rgba);
    }*/

};  // namespace Draw

#define tp_draw (*(Draw::DrawProperty *)tp_draw_addr)

typedef void (*sc2_drawText_t)(float param_1, float param_2, float param3, char* string, uint32_t rgba);
#define sc2_drawText ((sc2_drawText_t)sc2_drawText_addr)

#endif  // LIB_SC2_DRAW