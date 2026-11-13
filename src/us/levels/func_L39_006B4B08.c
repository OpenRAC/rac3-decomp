#include "common.h"

/* NTSC-U counterpart of func_L39_006B7520 (src/levels/39_multiplayer_menu/L39_006B6A80.c) */
/* localdecomp:start func_L39_006B4B08 */
typedef struct P_006B7520 {
    char _p0[0x8];
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
} P_006B7520;
typedef struct V_006B7520 {
    char _p0[0x30];
    void (*f30)(void *, f32 *, f32 *);
} V_006B7520;
typedef struct O_006B7520 {
    char _p0[0x60];
    V_006B7520 *f60;
} O_006B7520;
typedef struct S_006B7520 {
    char _p0[0x110];
    O_006B7520 *f110[0x60];
    s32 f290;
} S_006B7520;

extern P_006B7520 D_L39_004B1498;
extern P_006B7520 D_L39_004B14D0;
void func_L39_00687358(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);

s32 func_L39_006B4B08(void *arg) {
    S_006B7520 *arg0 = arg;
    f32 x = 0.0f;
    f32 y = 0.0f;
    f32 a = 0.0f, b = 0.0f, f = 0.0f, e = 0.0f, c = 0.0f, d = 0.0f;
    P_006B7520 *p;
    O_006B7520 *o;

    switch (arg0->f290) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        p = &D_L39_004B1498;
        a = p->f8;
        b = p->fC;
        c = p->f10;
        d = p->f14;
        e = p->f18;
        f = p->f1C;
        break;
    case 7:
        p = &D_L39_004B14D0;
        a = p->f8;
        b = p->fC;
        c = p->f10;
        d = p->f14;
        e = p->f18;
        f = p->f1C;
        break;
    }
    o = arg0->f110[arg0->f290];
    o->f60->f30(o, &x, &y);
    func_L39_00687358(arg0, 3, 3, 3, x + c, y + d, a, b, e, f);
    return 0;
}
/* localdecomp:end func_L39_006B4B08 */
