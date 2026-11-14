#include "common.h"

/* NTSC-U counterpart of func_L32_003B8498 (src/levels/shared/L32_003B8498.c) */
/* localdecomp:start func_L32_003B6A10 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003B8498;

typedef struct {
    V4_003B8498 f0;
    char pad10[0x90];
    f32 fA0;
    f32 fA4;
    f32 fA8;
    s16 fAC;
    s16 fAE;
    char padB0[4];
    s32 fB4;
    f32 fB8;
    u8 fBC;
    u8 fBD;
    u8 fBE;
} P_003B8498;

typedef struct {
    char pad0[0x10];
    V4_003B8498 f10;
    u8 f20;
    char pad21[0xF];
    u8 f30;
    char pad31;
    s16 f32;
    char pad34[0x34];
    P_003B8498 *f68;
} O_003B8498;

extern u8 *func_003BCFB0(s32, s32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);

O_003B8498 *func_L32_003B6A10(V4_003B8498 *pos, s32 a1, u8 a2, u8 a3, s16 a4, s16 a5, void *a6,
                              f32 f0, f32 f1, f32 f2, f32 f3) {
    O_003B8498 *o;
    P_003B8498 *p;
    s32 w = 105;

    o = (O_003B8498 *)func_003BCFB0(0x1C9E, 0xC0);
    if (o == 0) {
        return 0;
    }
    o->f30 = 0xFF;
    o->f32 = 0xFF;
    o->f20 = 0;
    p = o->f68;
    o->f10 = *pos;
    p->fA0 = f0;
    p->fA4 = f1;
    p->fB4 = a1;
    p->fB8 = f2;
    p->fBC = a2;
    p->fBD = a3;
    p->fA8 = f3;
    if (a6 != 0) {
        func_00388830(p, a6, 1.0f);
        p->fBE = 1;
        p->fAE = w;
        p->fAC = 0x64;
        p->fBD = 0;
    } else {
        p->fBE = 0;
        qzero(p);
        p->fAC = a4;
        p->fAE = a5;
    }
    func_L01_00441FB8(o, 0, -1);
    return o;
}
/* localdecomp:end func_L32_003B6A10 */
