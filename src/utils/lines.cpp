#include "utils/lines.hpp"
#include "sc2/system.h"
#include "menus/settings_menu.h"
#include "utils/draw.h"

int cursor_rgba;

namespace Utilities {

    void change_cursor_color() {
		switch (g_cursor_color) {
            case CURSOR_GREEN: {
                cursor_rgba = 0x00CC00FF;
                break;
			}
            case CURSOR_BLUE: {
                cursor_rgba = 0x0080FFFF;
                break;
            }
            case CURSOR_RED: {
                cursor_rgba = 0xCC0000FF;
                break;
            }
            case CURSOR_ORANGE: {
                cursor_rgba = 0xEE8000FF;
                break;
            }
            case CURSOR_YELLOW: {
                cursor_rgba = 0xFFCC00FF;
                break;
            }
            case CURSOR_PURPLE: {
                cursor_rgba = 0x6600CCFF;
                break;
            }
		}
    }

}  // namespace Utilities
