#include "common.h"

/* NTSC-U counterpart of func_L24_0034D5D8 (src/levels/shared/L24_0034D5D8.c) */
/* localdecomp:start func_L24_0034C788 */
#include "vu0.h"

typedef struct S_0034D5D8 {
    f32 vel[4];
    u8 pad10[4];
    u8 timer[4];
    s32 sound;
} S_0034D5D8;

extern u8 D_001A30B0[];
extern s32 D_L24_001E8F58_0034C788 __attribute__((section(".data")));
__asm__(".extern D_L24_001DD408, 4");
extern f32 D_L24_001DD408 __attribute__((section(".sdata")));

extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern void func_003BF6A8(void *, f32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_00462FD0(void *, void *, s32, s32, s32, s32, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_L01_003F9498(void *, s32, u8 *, f32);
extern s32 func_00388398(void *);
extern void func_003BD360(void *);
extern s32 func_L01_0032FE90_0034C788(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L24_0034C788(u8 *moby) {
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
    if (pv->sound == -1 || (e = D_001A30B0 + (pv->sound << 7), *(u8 **)(e + 0xDC) != moby) ||
        e[0xD0] == 0) {
        pv->sound = func_0039FE80(0, 4, moby);
    }
    *(vu0_q *)a = *(vu0_q *)old;
    vec_sub_ab(step, moby + 0x10, old);
    func_003886E8(step, step, 0.25f);
    g = -0.0018f;
    t = 1.0f;
    for (i = 3; i >= 0; i--) {
        sz = func_0037E250(0.3f, 0.5f) * 210000.0f;
        col = func_0037E1D8(8);
        if (func_0037E1D8(2) != 0) {
            col = -col;
        }
        *(vu0_q *)c = *(vu0_q *)a;
        func_003BF6A8(c, 0.075f);
        func_003886E8(d, pv->vel, func_0037E250(0.05f, 0.1f));
        d[2] += func_0037E250(-0.02f, 0.02f) - g * t;
        func_L01_0046C468(c, d, 15, 0x808080, col, 0x18, 0, sz, sz * 0.4f, -0.0018f, 0);
        vec_add_ab(a, a, step);
        if (func_0037E1D8(4) == 0) {
            d[2] -= g * func_0037E250(1.5f, 2.5f);
            func_L01_00462FD0(c, d, 0x4F007FFF, 0x1FFFFFFF, func_0037E208(5, 12), 1, 30000.0f);
        }
        t -= 0.25f;
    }
    if (*(f32 *)(moby + 0x10) < 0.0f || *(f32 *)(moby + 0x14) < 0.0f || *(f32 *)(moby + 0x18) < 0.0f) {
        func_003BD360(moby);
        return;
    }
    if (moby[0xBC] == 0 &&
        (func_003CE740(old, moby + 0x10, 0x10, moby, 0) != 0 ||
         func_L01_003F9498(moby + 0x10, 0x10, moby, D_L24_001DD408) != 0)) {
        if (D_L24_001E8F58_0034C788 == 0 || D_L24_001E8F58_0034C788 != *(s32 *)(moby + 0xB8)) {
            moby[0xBC] = 1;
        }
    } else if (func_00388398(pv->timer) != 0) {
        func_003BD360(moby);
        return;
    }
    if (moby[0xBC] != 0) {
        if (pv->sound != -1) {
            e = D_001A30B0 + (pv->sound << 7);
            if (*(u8 **)(e + 0xDC) == moby && e[0xD0] != 0) {
                func_0039FB08(pv->sound);
            }
        }
        pv->sound = -1;
        func_0039FE80(1, 0, moby);
        func_L01_0032FE90_0034C788(moby + 0x10, 1, 25, 20, 20, 20, 45, 0, 0.5f, 0.0f, 20.0f, 1.0f,
                          1, 1, 0, 0, 0, 1, 0x30001, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003BD360(moby);
    }
}
/* localdecomp:end func_L24_0034C788 */
