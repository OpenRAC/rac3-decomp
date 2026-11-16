/* NTSC-U draft (Claude wave K): C of func_L01_00312F80, the NTSC-U twin of func_L01_00313270, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 51 words differ on NTSC-U with "-mvu0-use-vf0-vf2 @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses") (NTSC-U twin "func_L01_00312F80", whose code is not the PAL one).
 * Worker's note: first full draft: 51 aligned diff (197 vs 196 words), structure now identical to retail (goto layout: w74!=0 -> w74!=1 skip -> 442068 -> w78==2 goto special; lerp arm then b common; special arm after). Remaining diff is only the callee-saved register ...
 */
#include "common.h"

/* NTSC-U counterpart of the L01 particle-pool update (src/levels/shared) */
#include "vu0.h"

/* localdecomp:start func_L01_00312F80 */
typedef struct T_00312F80 {
    u8 p0[0x14];
    s32 w14;
} T_00312F80;

typedef struct H_00312F80 {
    u8 p0[0x10];
    f32 pos[4];
    u8 b20;
    u8 p21[0x47];
    T_00312F80 *w68;
} H_00312F80;

typedef struct Ow_00312F80 {
    u8 p0[0x30];
    H_00312F80 *w30;
    u8 p34[4];
    s32 w38;
    u8 p3C[4];
    s32 w40;
    s32 w44;
} Ow_00312F80;

typedef struct P_00312F80 {
    f32 v[4];
    f32 pos[4];
    u8 p20[4];
    f32 f24, f28, f2C, f30, f34, f38, f3C, f40, f44, f48, f4C;
    u8 p50[4];
    s32 w54, w58, w5C, w60, w64, w68, w6C;
    u8 p70[4];
    s32 w74, w78;
    Ow_00312F80 *w7C;
} P_00312F80;

extern u8 *D_L01_001E17B4;
extern f32 func_L01_00442068(f32);
extern f32 func_L01_00442070(f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_003BFC18(void *, void *, s32);
extern f32 func_00389380(f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_00388398(void *);

void func_L01_00312F80(Ow_00312F80 *owner) {
    f32 v0[4];
    f32 a[4];
    f32 b[4];
    P_00312F80 *p;
    f32 t;
    f32 r;
    s32 i;
    H_00312F80 *h;
    T_00312F80 *tt;
    s32 n;

    qzero(v0);
    for (i = 0; i < 0x140; i++) {
        p = (P_00312F80 *)(D_L01_001E17B4 + i * 0x80);
        if (p->w7C != owner) {
            continue;
        }
        t = 1.0f - (f32)p->w54 / (f32)p->w58;
        if (p->w74 != 0) {
            if (p->w74 != 1) {
                goto common;
            }
            r = func_L01_00442068(t);
            p->w60 = (s32)((f32)p->w5C - (f32)p->w5C * r);
            if (p->w78 == 2) {
                goto special;
            }
        }
        p->w68 = func_003894A0(p->w64, p->w6C, t);
        p->f2C = p->f28 + (p->f30 - p->f28) * t;
        p->f3C = p->f38 + (p->f40 - p->f38) * t;
        p->f48 = p->f44 + (p->f4C - p->f44) * t;
        func_00388830(v0, p->pos, p->f24 * func_L01_00442070(t));
        goto common;
    special:
        func_00388830(v0, p->pos, p->f24);
    common:
        func_003BFC18(owner->w30->pos, a, 1);
        func_00388830(b, a, p->f3C);
        vec_add_ab(p->v, p->v, b);
        if (p->w78 != 1) {
            vec_add_ab(p->v, v0, p->v);
        }
        h = p->w7C->w30;
        tt = h->w68;
        p->f34 = func_00389380(p->f34, p->f2C);
        if (h->b20 == 2 && tt->w14 < 0x26 && p->w78 != 2) {
            p->w74 = 1;
            n = func_0037E208(0x1E, 0x2D);
            p->w58 = n;
            p->f44 = p->f48;
            p->w64 = p->w68;
            p->f38 = p->f3C;
            p->w5C = p->w60;
            p->f28 = p->f2C;
            p->w54 = n;
        }
        if (func_00388398(&p->w54) != 0) {
            if (p->w74 == 0) {
                p->w74 = 1;
                n = p->w78 == 1 ? 0x1E : 0x37;
                p->w54 = n;
                p->w58 = n;
            } else if (p->w60 > 0) {
                p->w74 = 2;
                p->w60 = p->w60 - 1;
            } else {
                p->w7C->w38--;
                if (p->w78 == 0) {
                    p->w7C->w40--;
                } else if (p->w78 == 1) {
                    p->w7C->w44--;
                }
                p->w7C = 0;
            }
        }
    }
}
/* localdecomp:end func_L01_00312F80 */
