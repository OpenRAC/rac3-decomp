#include "common.h"

typedef struct { u8 pad[0x2D8]; s32 x2D8; s32 x2DC; u8 pad2E0[0x2F8 - 0x2E0]; s32 x2F8; } X_006683F8;
typedef struct { u8 pad[0x2528]; X_006683F8 *x2528; u8 pad2[0x254C - 0x252C]; s32 x254C; } P_006683F8;

/* localdecomp:start func_L39_006673E8 */
#include "vu0.h"

typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    u8 padC[0x10];
} R_006673E8;

typedef struct {
    u8 pad0[0x34];
    void (*fn34)(void *, s32, s32, s32, s32);
} V_006673E8;

extern R_006673E8 D_L39_004840A0[];
extern vu0_v4 D_L39_00243F20 __attribute__((section(".sdata")));
extern void func_0038CF68(void *, void *, f32);

void func_L39_006673E8(void *a0, void *a1, s32 c) {
    u8 *a = a0;
    u8 *b = a1;
    u8 save;
    u8 *t;
    vu0_v4 v;

    save = b[0x1A0A];
    *(s32 *)(a + 0x2DC) = 0;
    if (b != 0) {
        *(s32 *)(b + 0x2578) = *(s32 *)(a + 0x2D0);
        *(s32 *)(b + 0x360) = 0x32;
        *(s32 *)(b + 0x2528) = 0;
        *(s32 *)(b + 0x254C) = 0;
        (*(V_006673E8 **)(b + 0x14))->fn34(b, 0, 1, 0, 1);
        D_L39_004840A0[*(s32 *)(b + 0x2544)].x0 = 5;
        D_L39_004840A0[*(s32 *)(b + 0x2544)].x8 = 10;
        if (c != 0) {
            b[0x1A0A] = 0;
        } else {
            b[0x1A0A] = save;
        }
        if (++*(s16 *)(a + 0x306) >= 4) {
            *(s16 *)(a + 0x306) = 0;
        }
        if (b[0x1A14] != 0) {
            func_0038CF68(&v, &D_L39_00243F20, *(f32 *)(b + 0x132C));
            vec_add_ab(b + 0x1180, b + 0xA0, &v);
        }
    }
    t = *(u8 **)(a + 0x2D8);
    if (t != 0) {
        *(s32 *)(*(u8 **)(a + 0x2D0) + 0xB8) = *(s32 *)(t + 0x2524);
    } else {
        *(*(u8 **)(a + 0x2D0) + 0xBE) &= 0xF7;
        *(*(u8 **)(a + 0x2D0) + 0xBE) &= 0xEF;
        *(s32 *)(*(u8 **)(a + 0x2D0) + 0xB8) = 0;
    }
}
/* localdecomp:end func_L39_006673E8 */
