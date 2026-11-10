#include "common.h"

/* localdecomp:start func_L03_003B8570 */
typedef struct S_003B8570 {
    char p0[0x20]; u8 mode; char p1[0x10]; u8 f31; char p2[2]; u16 flags; char p3[0xD]; u8 f43;
    char p4[0x1C]; u8 f60; char p5[7]; struct T_003B8570 *t;
} S_003B8570;
typedef struct T_003B8570 { char p[0x11C]; s32 a; char b[1]; } T_003B8570;
extern s32 D_00142C5C[];
extern s32 D_L03_001D6694;
__asm__(".extern D_L03_001D6694, 16");
__asm__(".extern D_00142C5C, 16");
extern s32 D_001D6694_sda;
__asm__(".extern D_001D6694_sda, 4");
extern void func_003C3A10(S_003B8570 *, s32, s32, s32);
extern void func_L01_004450F0(S_003B8570 *, s32, s32);
extern void func_003C2880(S_003B8570 *);
extern s32 func_L01_004BA800();
extern s32 func_0038CAD0(s32 *);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_L03_003B8770(S_003B8570 *);
extern void func_L01_00451DB8(f32, S_003B8570 *, char *, s32, s32);

void func_L03_003B8570(S_003B8570 *s) {
    T_003B8570 *t = s->t;
    s32 v;
    if (s->mode == 0) {
        if (D_00142C5C[0] & 0x40000000) {
            if (s->f43 != 1) func_003C3A10(s, 1, 0, 8);
            func_L01_004450F0(s, 1, -1);
            v = D_001D6694_sda;
        } else {
            func_003C2880(s);
            return;
        }
    } else {
        v = D_L03_001D6694;
    }
    if (v == 2) {
        s->f31 = 0;
        s->flags |= 1;
        return;
    }
    if (func_L01_004BA800() == 0) {
        s->f31 = 1;
        s->flags &= 0xFFFE;
    }
    switch (s->mode) {
    case 1:
        if (func_0038CAD0(&t->a)) {
            s32 k;
            t->a = (s32)((func_003824E0(600.0f, 1200.0f) * 5.0f + 2.0f) / 6.0f);
            k = func_00382468(3) ? 2 : 3;
            if (s->f43 != k) func_003C3A10(s, k, 0, 8);
            func_L01_004450F0(s, 2, -1);
        }
        break;
    case 2:
        if (s->f60 & 2) {
            if (s->f43 != 1) func_003C3A10(s, 1, 0, 8);
            func_L01_004450F0(s, 1, -1);
        }
        break;
    }
    func_L03_003B8770(s);
    func_L01_00451DB8(0.06283186f, s, t->b, 0x80A0A0A0, 0x80404040);
}
/* localdecomp:end func_L03_003B8570 */

INCLUDE_ASM("asm/levels", func_L03_003B8770);
