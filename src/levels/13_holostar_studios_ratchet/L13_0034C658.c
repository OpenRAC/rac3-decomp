#include "common.h"

INCLUDE_ASM("asm/levels", func_L13_0034C658);

/* localdecomp:start func_L13_0034C730 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_34C730;
typedef struct {
    char _p0[0x10];
    s32 f10;
    char _p14[0x44 - 0x14];
    u16 f44;
} C_34C730;
typedef struct {
    char _p0[0x30];
    f32 f30;
    s16 s34;
    char _p36[0x5F - 0x36];
    u8 f5F;
    char _p60[0x198 - 0x60];
    s16 s198;
    char _p19A[0x2F0 - 0x19A];
    V4_34C730 v2F0;
    char _p300[0x320 - 0x300];
    V4_34C730 v320;
} X_34C730;
typedef struct {
    char _p0[0x10];
    V4_34C730 v10;
    char _p20[0x24 - 0x20];
    C_34C730 *f24;
    char _p28[0x32 - 0x28];
    s16 s32;
    u16 u34;
    char _p36[0x68 - 0x36];
    X_34C730 *f68;
    char _p6C[0x98 - 0x6C];
    s32 f98;
    char _p9C[0xF8 - 0x9C];
    f32 fF8;
} M_34C730;

extern f32 func_0038D160(f32, f32);
extern void func_L01_004450F0(M_34C730 *, s32, s32);

void func_L13_0034C730(M_34C730 *self, V4_34C730 *a, V4_34C730 *b) {
    V4_34C730 t0 = *a;
    V4_34C730 t1 = *b;
    X_34C730 *x = self->f68;

    self->s32 = 0x50;
    x->s198 = 0;
    x->f30 = x->s34;
    self->u34 &= 0xFFBE;
    self->u34 |= self->f24->f44 & 0x1000;
    self->f98 = self->f24->f10;
    x->v320 = t1;
    self->v10 = t0;
    x->v2F0 = t0;
    x->f5F = 0;
    self->fF8 = func_0038D160(t1.x - t0.x, t1.y - t0.y);
    func_L01_004450F0(self, 0x18, 9);
}
/* localdecomp:end func_L13_0034C730 */
