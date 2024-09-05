#include "utils/hook.h"
#include "sc2/patch.h"
#include "lib.h"
#include "controller.h"
#include "cheats.h"

#define HOOK_DEF(rettype, name, params)     \
    typedef rettype(*tp_##name##_t) params; \
    tp_##name##_t name##Trampoline;

HOOK_DEF(void, cDyl_InitAsync, (void*, void*, void*));
HOOK_DEF(void, fapGm_Execute, (void));
HOOK_DEF(void, sc2_Execute, (void));
HOOK_DEF(void, draw, (void*));
HOOK_DEF(void, pad, (void*));
HOOK_DEF(uint32_t, checkHookshotStickBG, (void*, void*));
HOOK_DEF(void, setSpecialGravity, (float, float, int));
HOOK_DEF(uint32_t, checkCastleTownUseItem, (uint16_t));
HOOK_DEF(uint32_t, query042, (void*, void*, int));
HOOK_DEF(void*, cc_at_check, (void*, int*));

struct {
    uint32_t a[2];
} trampolines[HOOK_AMNT];

namespace Hook {
    using namespace mod::patch;

    void initHook(void* p1, void* p2, void* p3) {
        cDyl_InitAsyncTrampoline(p1, p2, p3);
        init();
    }

    void gameLoopHook(void) {
        game_loop();
        sc2_ExecuteTrampoline();
    }

    void drawHook(void* p1) {
        drawTrampoline(p1);
        draw();
    }

    void padHook(void* p1) {
        padTrampoline(p1);
        pad();
    }

//FUN_800adc2c
    void apply_hooks() {
#define APPLY_HOOK(name, addr, idx, func) name##Trampoline = hookFunction((tp_##name##_t)addr, trampolines[idx].a, func)
        //APPLY_HOOK(cDyl_InitAsync, 0x80018764, HK_LIB_INIT_INDEX, initHook);
        APPLY_HOOK(sc2_Execute, 0x8007aef8, HK_LIB_GAME_LOOP_INDEX, gameLoopHook);
        APPLY_HOOK(draw, 0x800adc2c, HK_LIB_DRAW_INDEX, drawHook);
        APPLY_HOOK(pad, 0x80011c80, HK_LIB_READ_CONTROLLER_INDEX, padHook);
        //APPLY_HOOK(checkHookshotStickBG, 0x801087b0, HK_SUPER_CLAWSHOT_INDEX, superClawshotHook);
        //APPLY_HOOK(setSpecialGravity, 0x800bb770, HK_DISABLE_GRAV_INDEX, disableGravityHook);
        //APPLY_HOOK(checkCastleTownUseItem, 0x800c0678, HK_UNRESTRICTED_ITEMS_INDEX, unrestrictedItemsHook);
        //APPLY_HOOK(query042, 0x8024bfec, HK_TRANSFORM_ANYWHERE_INDEX, transformAnywhereHook);
        //APPLY_HOOK(cc_at_check, 0x80087c04, HK_INVINCIBLE_ENEMIES_INDEX, invincibleEnemiesHook);
#undef APPLY_HOOK
    }
}  // namespace Hook