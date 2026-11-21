#include "common.h"

/* NTSC-U counterpart of func_L10_00359EA0 (src/levels/10_zeldrin_starport/L10_00359EA0.c) */
#include "vu0.h"

/* localdecomp:start func_L10_00358BC0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_359EA0;
typedef struct { u8 pad0[0x10]; u8 *f10; } S_359EA0;
__asm__(".extern D_L10_001DD790, 4");
__asm__(".extern D_L10_001DD798, 4");
__asm__(".extern D_L10_001DD79C, 4");
__asm__(".extern D_L10_001DD7A0, 4");
__asm__(".extern D_L10_001DD7A4, 4");
__asm__(".extern D_L10_001DD7A8, 4");
__asm__(".extern D_L10_001DD7AC, 4");
__asm__(".extern D_L10_001DD7B0, 4");
__asm__(".extern D_L10_001DD7B4, 4");
__asm__(".extern D_L10_001DD7B8, 4");
__asm__(".extern D_L10_001DD7BC, 4");
extern s32 D_L10_001DD790;
extern s32 D_L10_001DD798;
extern s32 D_L10_001DD79C;
extern s32 D_L10_001DD7A0;
extern s32 D_L10_001DD7A4;
extern s32 D_L10_001DD7A8;
extern f32 D_L10_001DD7AC;
extern f32 D_L10_001DD7B0;
extern f32 D_L10_001DD7B4;
extern f32 D_L10_001DD7B8;
extern f32 D_L10_001DD7BC;
extern S_359EA0 D_L10_0021EC18;
extern void func_0037E2F0(void *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_0046CF70(void *, void *, s32, f32);

void func_L10_00358BC0(u8 *m, void *pos, void *c, f32 s) {
    V4_359EA0 p;
    V4_359EA0 q;
    s32 t;
    u8 a;
    s32 i;
    s32 col;
    s32 life;
    s32 r;
    f32 s0;
    f32 s1;
    u8 *e;

    {
        s32 *tp = *(s32 **)(m + 0x68);
        p = *(V4_359EA0 *)pos;
        t = *tp;
    }
    if (t < 50) {
        a = (s32)((f32)t * 127.0f / 50.0f);
    } else {
        a = 0x7F;
    }
    for (i = 0; i < D_L10_001DD790; i++) {
        func_0037E2F0(&q, D_L10_001DD7B4 * s * 0.5f, D_L10_001DD7B4 * s);
        vec_add_ab(&q, &q, c);
        func_00388830(&q, &q, func_0037E250(D_L10_001DD7B8 * 0.5f * s, D_L10_001DD7B8 * s) * 0.016666668f);
        if (func_0037E1D8(4) != 0) {
            col = D_L10_001DD7A8;
        } else {
            col = D_L10_001DD7A0;
        }
        col |= a << 24;
        r = func_0037E208(-2, 2);
        s0 = D_L10_001DD7AC * s * 210000.0f;
        s1 = D_L10_001DD7B0 * s * 210000.0f;
        e = func_L01_00472438(&p, &q, D_L10_001DD798, r, col, D_L10_001DD7A4, 0, s0, s1,
                              func_0037E250(D_L10_001DD7BC * 0.3f, D_L10_001DD7BC));
        if (e != 0) {
            e[2] = *D_L10_0021EC18.f10;
            e[3] = func_0037E1D8(2) ? 0x48 : 0x44;
        }
    }
    if (func_0037E1D8(6) == 0) {
        func_L01_0046CF70(&p, &q, func_0037E208(D_L10_001DD79C - 5, D_L10_001DD79C), func_0037E250(40.0f, 80.0f) * 0.00027777778f);
    }
}
/* localdecomp:end func_L10_00358BC0 */
