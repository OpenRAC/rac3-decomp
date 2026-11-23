#include "common.h"

/* NTSC-U counterpart of func_L11_0033D310 (src/levels/shared/L11_0033CFB0.c) */
#include "vu0.h"
extern f32 func_0037E250(f32, f32);
extern void func_L11_0033C658(void *);
extern f32 func_00388978(f32);
extern f32 D_L11_001DCFD8_0033C658[2], D_L11_001DCFE0_0033C658[2];

/* localdecomp:start func_L11_0033C658 */
#include "vu0.h"
typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 p20[0x48]; u8 *f68; } S_0033D310;
extern s32 func_0037E1D8(s32);
extern void func_003888C8(void *, void *, void *);
extern f32 func_0037E2A8(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00468DC0(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern f32 D_L11_001DCFD8_0033C658[2], D_L11_001DCFE0_0033C658[2], D_L11_001DCFF8_0033C658[2], D_L11_001DD000_0033C658[2], D_L11_001DD018[2];
extern s32 D_L11_001DD010[2];
__asm__(".extern D_L11_001DD010, 8");
__asm__(".extern D_L11_001DD000_0033C658, 8");
extern s32 D_L11_001DD008, D_L11_001DD00C, D_L11_001DD020;

void func_L11_0033C658(void *arg) {
    S_0033D310 *a0 = arg;
    vu0_v4 w;
    vu0_v4 v;
    f32 *p;
    s32 i;
    s32 n;
    s32 tex;
    f32 a;
    f32 r;
    f32 sc;

    p = (f32 *)(a0->f68 + 0x30);
    for (i = 3; i >= 0; i--) {
        p[-4] += p[0];
        if (1.0f <= p[-4]) {
            p[-4] = 0.0f;
            p[0] = func_0037E250(D_L11_001DCFD8_0033C658[0], D_L11_001DCFD8_0033C658[1]) * 0.016666668f;
            p[-8] = func_0037E250(D_L11_001DCFE0_0033C658[0], D_L11_001DCFE0_0033C658[1]);
        }
        p++;
    }
    if (func_0037E1D8(D_L11_001DD020) == 0) {
        return;
    }
    qzero(&v);
    v.z = func_0037E250(D_L11_001DCFF8_0033C658[0], D_L11_001DCFF8_0033C658[1]) * 0.016666668f;
    func_003888C8(&v, &v, (u8 *)a0 + 0xC0);
    a = func_0037E2A8();
    r = func_0037E250(D_L11_001DD018[0], D_L11_001DD018[1]);
    w.x = func_00388960(a) * r;
    w.y = func_00388978(a) * r;
    w.z = 0.0f;
    func_003888C8(&w, &w, (u8 *)a0 + 0xC0);
    vec_add_ba(&w, &w, &a0->pos);
    n = func_0037E208(D_L11_001DD010[0], D_L11_001DD010[1]);
    sc = func_0037E250(D_L11_001DD000_0033C658[0], D_L11_001DD000_0033C658[1]);
    tex = func_0037E1D8(2) ? D_L11_001DD008 : D_L11_001DD00C;
    func_L01_00468DC0(&w, &v, tex, sc, n, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
}
/* localdecomp:end func_L11_0033C658 */
