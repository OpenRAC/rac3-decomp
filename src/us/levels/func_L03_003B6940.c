#include "common.h"

/* NTSC-U counterpart of func_L03_003B8570 (src/levels/03_starship_phoenix/L03_003B8570.c) */
/* localdecomp:start func_L03_003B6940 */
typedef struct S_003B8570 {
    char p0[0x20]; u8 mode; char p1[0x10]; u8 f31; char p2[2]; u16 flags; char p3[0xD]; u8 f43;
    char p4[0x1C]; u8 f60; char p5[7]; struct T_003B8570 *t;
} S_003B8570;
typedef struct T_003B8570 { char p[0x11C]; s32 a; char b[1]; } T_003B8570;
extern s32 D_00142C5C[];
extern s32 D_L03_001D6694_003B6940;
__asm__(".extern D_L03_001D6694_003B6940, 16");
__asm__(".extern D_00142C5C, 16");
extern s32 D_001D6694_sda_003B6940;
__asm__(".extern D_001D6694_sda_003B6940, 4");
extern void func_003BE4F0(S_003B8570 *, s32, s32, s32);
extern void func_L01_00441FB8(S_003B8570 *, s32, s32);
extern void func_003BD360(S_003B8570 *);
extern s32 func_L01_004B6C68();
extern s32 func_00388398(s32 *);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_L03_003B6B20(S_003B8570 *);
extern void func_L01_0044EB38(f32, S_003B8570 *, char *, s32, s32);

void func_L03_003B6940(S_003B8570 *s) {
    T_003B8570 *t = s->t;
    s32 v;
    if (s->mode == 0) {
        if (D_00142C5C[0] & 0x40000000) {
            if (s->f43 != 1) func_003BE4F0(s, 1, 0, 10);
            func_L01_00441FB8(s, 1, -1);
            v = D_001D6694_sda_003B6940;
        } else {
            func_003BD360(s);
            return;
        }
    } else {
        v = D_L03_001D6694_003B6940;
    }
    if (v == 2) {
        s->f31 = 0;
        s->flags |= 1;
        return;
    }
    if (func_L01_004B6C68() == 0) {
        s->f31 = 1;
        s->flags &= 0xFFFE;
    }
    switch (s->mode) {
    case 1:
        if (func_00388398(&t->a)) {
            s32 k;
            t->a = (s32)func_0037E250(600.0f, 1200.0f);
            k = func_0037E1D8(3) ? 2 : 3;
            if (s->f43 != k) func_003BE4F0(s, k, 0, 10);
            func_L01_00441FB8(s, 2, -1);
        }
        break;
    case 2:
        if (s->f60 & 2) {
            if (s->f43 != 1) func_003BE4F0(s, 1, 0, 10);
            func_L01_00441FB8(s, 1, -1);
        }
        break;
    }
    func_L03_003B6B20(s);
    func_L01_0044EB38(0.052359883f, s, t->b, 0x80A0A0A0, 0x80404040);
}
/* localdecomp:end func_L03_003B6940 */
