#ifndef LIB_SC2_CONTROLLER
#define LIB_SC2_CONTROLLER

#include <stdint.h>
#include "addrs.h"
#include "utils.h"

namespace Controller {
    namespace Pad {
        const uint16_t DPAD_LEFT = 0x0001;
        const uint16_t DPAD_RIGHT = 0x0002;
        const uint16_t DPAD_DOWN = 0x0004;
        const uint16_t DPAD_UP = 0x0008;
        const uint16_t Z = 0x0010;
        const uint16_t R = 0x0020;
        const uint16_t L = 0x0040;
        const uint16_t A = 0x0100;
        const uint16_t B = 0x0200;
        const uint16_t X = 0x0400;
        const uint16_t Y = 0x0800;
        const uint16_t START = 0x1000;
    }  // namespace Pad

    namespace Pad2 {
        const uint32_t L = 			0x00000001;
        const uint32_t R = 			0x00000008;
        const uint32_t Z = 			0x00000010;
        const uint32_t X =	 		0x00000020;
        const uint32_t A =			 0x00000040;
        const uint32_t L_ANALOG = 	0x00010004;
        const uint32_t R_ANALOG = 	0x00020080;
        const uint32_t Y =			 0x00000100;
        const uint32_t B =			 0x00000200;
		const uint32_t LSTICK_RIGHT = 0x00040400;
		const uint32_t LSTICK_LEFT = 0x00080800;
		const uint32_t LSTICK_DOWN = 0x00101000;
		const uint32_t LSTICK_UP = 	0x00202000;
		const uint32_t CSTICK_RIGHT = 0x00400000;
		const uint32_t CSTICK_LEFT = 0x00800000;
		const uint32_t CSTICK_DOWN = 0x01000000;
		const uint32_t CSTICK_UP = 	0x02000000;
        const uint32_t DPAD_RIGHT = 0x04000400;
        const uint32_t DPAD_LEFT = 	0x08000800;
        const uint32_t DPAD_DOWN =	 0x10001000;
        const uint32_t DPAD_UP = 	0x20002000;
        const uint32_t START = 		0x00008000;

        const uint32_t RIGHT = 0x00000400;
		const uint32_t LEFT = 0x00000800;
		const uint32_t DOWN = 0x00001000;
		const uint32_t UP = 0x00002000;
    }  // namespace Pad2

    struct PadStatus {
        uint16_t sval;
    };
    static_assert(sizeof(PadStatus) == 0x2);

    struct PadSticks {
        int8_t control_x;
        int8_t control_y;
        int8_t c_x;
        int8_t c_y;
    };
    static_assert(sizeof(PadSticks) == 0x4);

    struct PadTriggers {
        uint8_t trig_L;
        uint8_t trig_R;
    };
    static_assert(sizeof(PadTriggers) == 0x2);
    
    struct ATriggers {
        float l, r;
    };
    static_assert(sizeof(ATriggers) == 0x8);

    struct Sc2PadStatus {
        uint16_t unk0;
        uint16_t buttons; // Pad2 constants
    };
    static_assert(sizeof(Sc2PadStatus) == 0x4);

    struct PadButton {
        uint8_t analog_cardinal;
        uint8_t c_cardinal;
        uint16_t buttons;
        uint8_t _p1[2];
        uint16_t buttons_down;
        uint8_t _p2[18];
        uint16_t sval;
        uint8_t _p3[0xA4];
    };
    static_assert(sizeof(PadButton) == 0xC0);

    struct PadButton2 {
        /* 0x0000 */ uint32_t	button_held;
        /* 0x0004 */ uint32_t	button_press0; // 802b5954
        /* 0x0008 */ uint32_t	button_release; // ?
        /* 0x000C */ uint32_t   button_press2;
        /* 0x0010 */ uint8_t        _p0[0x10]; // c/left analog stick values
        /* 0x0020 */ uint8_t 		_p1[0x48];
        /* 0x0068 */ uint32_t	button_last0;
        /* 0x006C */ uint32_t	button_last1;
        /* 0x0070 */ uint8_t		_p3[0x18];
    };
    static_assert(sizeof(PadButton2) == 0x88);

    struct InputBuffer {
        PadButton2 input[420];
        uint32_t frames;
    };

#define tp_mPadButton (*(Controller::PadButton *)tp_mPadButton_addr)
#define tp_mPadStatus (*(Controller::PadStatus *)tp_mPadStatus_addr)
#define tp_mPadSticks (*(Controller::PadSticks *)tp_mPadSticks_addr)
#define tp_mPadTriggers (*(Controller::PadTriggers *)tp_mPadTriggers_addr)
#define tp_mPadATriggers (*(Controller::ATriggers *)tp_mPadATriggers_addr)
#define tp_mPadAStick (*(Vec2 *)tp_mPadAStick_addr)
#define tp_mPadACStick (*(Vec2 *)tp_mPadACStick_addr)

#define sc2_mPad1 (*(Controller::PadButton2 *)sc2_mPad1_addr)
#define sc2_mPad12 (*(Controller::PadButton2 *)sc2_mPad1_addr2)
#define sc2_mPadStatus (*(Controller::PadStatus *)sc2_mPadStatus_addr)
#define sc2_mPadSticks (*(Controller::PadSticks *)sc2_mPadSticks_addr)
#define sc2_mPadTriggers (*(Controller::PadTriggers *)sc2_mPadTriggers_addr)

#define sc2_mPad2 (*(Controller::PadButton2 *)sc2_mPad2_addr)



    uint16_t buttons_down();
    uint16_t buttons_pressed();
    void set_buttons_down(uint16_t buttons);
    void set_buttons_pressed(uint16_t buttons);
    bool is_down(uint16_t buttons);
    bool is_pressed(uint16_t buttons);
}  // namespace Controller

extern Controller::InputBuffer inputBuf;

#endif  // LIB_SC2_CONTROLLER
