#include "common.h"

/* NTSC-U counterpart of func_L39_0069E950 (src/levels/39_multiplayer_menu/L39_0069E1A8.c) */
/* localdecomp:start func_L39_0069C140 */
__asm__(".extern D_L39_00247A74, 16");
extern u8 *D_L39_00247A74;
extern s32 D_001A4568[];
extern f32 D_001DCCAC_sda_0069C140;
extern f32 D_001DCC88_sda;
void func_L39_006B5488(s32 a, s32 b, s32 c, s32 d, s32 e);
s32 func_L39_00685798(s32, s32, s32);
s32 func_L39_00688350(void *, s32);
void func_L39_00687728(void *, s32, s32, s32, f32, f32);

typedef struct V_0069E950 V_0069E950;
typedef struct O_0069E950 {
    u8 pad[0x60];
    V_0069E950 *vt;
} O_0069E950;
struct V_0069E950 {
    u8 pad[0x30];
    void (*get)(O_0069E950 *, s32 *, f32 *);
};

typedef struct P_0069E950 {
    u8 pad0[0x110];
    O_0069E950 *objs[0x60];
    s32 x290;
    u8 pad294[0x14];
    s32 x2A8;
    u8 x2AC;
} P_0069E950;

s32 func_L39_0069C140(P_0069E950 *p, s32 arg1) {
    s32 a;
    f32 b;
    s32 idx;
    s32 sel;

    func_L39_006B5488(1, 0, 0x190, 0, 0x82);
    if (arg1 == 7) {
        p->x2A8 = p->x290;
        *(s32 *)(D_L39_00247A74 + 0x284) = 0x2C;
        return 1;
    }
    if ((u32)(arg1 - 3) < 2) {
        func_L39_00685798(3, 0, 0);
    }
    if (func_L39_00688350(p, arg1)) {
        return 1;
    }
    if (p->x2AC && D_001A4568[0] != 2) {
        p->x2A8 = 3;
        *(s32 *)(D_L39_00247A74 + 0x284) = 0x2C;
        return 1;
    }
    idx = p->x290;
    if (idx >= 0) {
        O_0069E950 *o = p->objs[idx];
        o->vt->get(o, &a, &b);
        sel = p->x290 == 0 ? 2 : 0;
        if (p->x290 == 1) {
            sel |= 1;
        }
        func_L39_00687728(p, sel, 3, 3, D_001DCC88_sda, b + D_001DCCAC_sda_0069C140);
    }
    return 0;
}
/* localdecomp:end func_L39_0069C140 */
