#include "common.h"

/* localdecomp:start func_L24_0034D5D8 */
#include "vu0.h"

typedef struct S_0034D5D8 {
    f32 vel[4];
    u8 pad10[4];
    u8 timer[4];
    s32 sound;
} S_0034D5D8;

extern u8 D_1A30B0[];
extern s32 D_L24_001E8F58 __attribute__((section(".data")));
__asm__(".extern D_L24_001DD3C8, 4");
extern f32 D_L24_001DD3C8 __attribute__((section(".sdata")));

extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_003C4C18(void *, f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_00466588(void *, void *, s32, s32, s32, s32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L24_0034D5D8(u8 *moby) {
    f32 old[4] __attribute__((aligned(16)));
    f32 a[4] __attribute__((aligned(16)));
    f32 step[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    S_0034D5D8 *pv;
    u8 *e;
    s32 i;
    s32 col;
    f32 sz;
    f32 t;
    f32 g;

    *(u16 *)(moby + 0x34) &= 0xFFBE;
    pv = *(S_0034D5D8 **)(moby + 0x68);
    *(vu0_q *)old = *(vu0_q *)(moby + 0x10);
    vec_add_ab(moby + 0x10, moby + 0x10, pv->vel);
    if (pv->sound == -1 || (e = D_1A30B0 + (pv->sound << 7), *(u8 **)(e + 0xDC) != moby) ||
        e[0xD0] == 0) {
        pv->sound = func_003A52A0(0, 4, moby);
    }
    *(vu0_q *)a = *(vu0_q *)old;
    vec_sub_ab(step, moby + 0x10, old);
    func_0038CE20(step, step, 0.25f);
    g = -0.0018f;
    t = 1.0f;
    for (i = 3; i >= 0; i--) {
        sz = func_003824E0(0.3f, 0.5f) * 210000.0f;
        col = func_00382468(8);
        if (func_00382468(2) != 0) {
            col = -col;
        }
        *(vu0_q *)c = *(vu0_q *)a;
        func_003C4C18(c, 0.075f);
        func_0038CE20(d, pv->vel, func_003824E0(0.05f, 0.1f));
        d[2] += func_003824E0(-0.02f, 0.02f) - g * t;
        func_L01_0046FB40(c, d, 12, 0x808080, col, 0x18, 0, sz, sz * 0.4f, -0.0018f, 0);
        vec_add_ab(a, a, step);
        if (func_00382468(4) == 0) {
            d[2] -= g * func_003824E0(1.5f, 2.5f);
            func_L01_00466588(c, d, 0x4F007FFF, 0x1FFFFFFF, func_00382498(4, 10), 1, 30000.0f);
        }
        t -= 0.25f;
    }
    if (*(f32 *)(moby + 0x10) < 0.0f || *(f32 *)(moby + 0x14) < 0.0f || *(f32 *)(moby + 0x18) < 0.0f) {
        func_003C2880(moby);
        return;
    }
    if (moby[0xBC] == 0 &&
        (func_003D3CB0(old, moby + 0x10, 0x10, moby, 0) != 0 ||
         func_L01_003FB640(moby + 0x10, 0x10, moby, D_L24_001DD3C8) != 0)) {
        if (D_L24_001E8F58 == 0 || D_L24_001E8F58 != *(s32 *)(moby + 0xB8)) {
            moby[0xBC] = 1;
        }
    } else if (func_0038CAD0(pv->timer) != 0) {
        func_003C2880(moby);
        return;
    }
    if (moby[0xBC] != 0) {
        if (pv->sound != -1) {
            e = D_1A30B0 + (pv->sound << 7);
            if (*(u8 **)(e + 0xDC) == moby && e[0xD0] != 0) {
                func_003A4F28(pv->sound);
            }
        }
        pv->sound = -1;
        func_003A52A0(1, 0, moby);
        func_L01_003303B8(moby + 0x10, 1, 25, 20, 20, 20, 45, 0, 0.5f, 0.0f, 20.0f, 1.0f,
                          1, 1, 0, 0, 0, 1, 0x30001, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003C2880(moby);
    }
}
/* localdecomp:end func_L24_0034D5D8 */
