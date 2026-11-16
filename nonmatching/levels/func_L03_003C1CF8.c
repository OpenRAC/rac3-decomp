/* NTSC-U draft (Claude wave K): C of func_L03_003BFEF0, the NTSC-U twin of func_L03_003C1CF8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L03_003BFEF0", whose code is not the PAL one).
 * Worker's note: best TOTAL 28 aligned words (retail 297 words, ours 294), control flow identical; needs @ps2as (float consts lui/ori/mtc1) so best status would be flags. Levers found: put the D_001D545C==3 block as the else arm at the END (retail layout), `goto destroy` ...
 */
#include "common.h"

/* localdecomp:start func_L03_003BFEF0 */
typedef int Q_003BFEF0 __attribute__((mode(TI)));

typedef union V_003BFEF0 {
    Q_003BFEF0 q;
    f32 f[4];
} V_003BFEF0;

typedef struct Ref_003BFEF0 {
    u8 pad00[0x10];
    s32 w10;
    u8 pad14[0x30];
    u16 h44;
} Ref_003BFEF0;

typedef struct S_003BFEF0 {
    u8 pad00[4];
    f32 f4;
    f32 f8;
    u8 padC[0x14];
    V_003BFEF0 p20;
    u8 pad30[0x4C];
    u8 b7C;
} S_003BFEF0;

typedef struct O_003BFEF0 {
    u8 pad00[0x10];
    V_003BFEF0 p;
    u8 b20;
    u8 pad21[3];
    Ref_003BFEF0 *p24;
    u8 pad28[9];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0xC];
    u8 b42;
    u8 b43;
    u8 pad44[0x1C];
    u8 b60;
    u8 pad61[7];
    S_003BFEF0 *p68;
    u8 pad6C[0x2A];
    s16 h96;
    s32 w98;
    u8 pad9C[0x54];
    V_003BFEF0 r;
} O_003BFEF0;

typedef struct K_003BFEF0 {
    u8 pad00[0x76];
    s16 h76;
    u8 pad78[0x20];
    s16 h98;
    u8 pad9A[4];
    s16 h9E;
} K_003BFEF0;

typedef struct H_003BFEF0 {
    u8 pad00[0x80];
    V_003BFEF0 q80;
    V_003BFEF0 q90;
    u8 padA0[0x1DC - 0xA0];
    s16 h1DC;
    u8 pad1DE[0xC08 - 0x1DE];
    s32 wC08;
} H_003BFEF0;

extern s32 D_001D545C;
extern u8 D_00142792[];
extern f32 D_L03_001E92A8[];
extern f32 D_L03_001DECB0;
__asm__(".extern D_L03_001DECB0, 4");
extern s32 D_L03_001DF738;
extern s32 D_L03_001DF35C;
extern K_003BFEF0 D_001CCFD0;
extern H_003BFEF0 D_001A4BE0;
extern u8 D_001A4C60[];
typedef struct {
    u8 pad[0xC540];
    u16 h;
} B_003BFEF0;
extern B_003BFEF0 D_001A7E18;

extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern f32 func_0037E2A8(void);
extern f32 func_00389380(f32, f32);
extern void func_L03_003BF738(void *);
extern void func_L01_0044B860(void *, void *, void *, f32, f32, f32);
extern f32 func_003887C8(void *, void *);
extern void func_L03_003BF9F0(void *);
extern void func_0039C710(void);
extern void func_L03_003BFCE8(void *);
extern s32 func_0037E1D8(s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_0050BB98(s32, s32, f32);
extern s32 func_00388398(void *);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_L01_003E9730(s32, s32);
extern void func_0039FE80(s32, s32, void *);
extern void func_L03_003C0398(void *, s32);
extern void func_L01_0044ECE0(s32, s32, s32);
extern void func_00399F90(void);
extern void func_00399C90(s32, s32);
extern void func_L01_00417F60(s32, s32);
extern void func_L01_004A6DF8(void *, s32);
extern void func_003BD360(void *);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L03_003BFEF0(O_003BFEF0 *o) {
    S_003BFEF0 *s;
    s32 st;
    s32 one;
    s32 i;

    s = o->p68;
    if (s == 0) {
        return;
    }
    if (D_001D545C != 3) {
        st = o->b20;
        if ((u8)st == 0) {
            V_003BFEF0 a;
            V_003BFEF0 b;
            if (D_00142792[0] != 0) {
                goto destroy;
            }
            s->p20.q = o->p.q;
            s->p20.f[3] = o->r.f[2];
            b = o->p;
            a = o->p;
            a.f[2] -= 1.0f;
            b.f[2] += 1.0f;
            if (func_003CE740(&b, &a, 2, o, 0) != 0) {
                o->p.f[2] = D_L03_001E92A8[0] + 0.5f;
            }
            o->r.f[0] = func_0037E2A8();
            o->r.f[1] = func_0037E2A8();
            o->r.f[2] = func_0037E2A8();
            o->r.f[3] = func_0037E2A8();
            s->f8 = o->p.f[2];
            func_L01_00441FB8(o, 1, -1);
            st = o->b20;
        } else if ((u8)st == 1) {
            if (func_003887C8(D_001A4C60, &o->p) <= D_L03_001DECB0) {
                func_L03_003BF9F0(o);
            }
            st = o->b20;
        }
        if (st == 1) {
            o->r.f[0] = func_00389380(o->r.f[0], 0.03490659f);
            o->r.f[1] = func_00389380(o->r.f[1], 0.011635529f);
            o->r.f[2] = func_00389380(o->r.f[2], 0.0058177644f);
            o->r.f[3] = func_00389380(o->r.f[3], 0.026179941f);
            func_L03_003BF738(o);
            func_L01_0044B860(o, s, &s->f4, 0.25f, 0.023271058f, s->f8);
            o->h96 = 0;
            return;
        }
        if ((u8)st == 2) {
            if (D_001CCFD0.h76 != 0 || D_001CCFD0.h9E != 3 || D_001CCFD0.h98 >= 0x1B58) {
            } else {
                func_0039C710();
            }
            one = 1;
            D_L03_001DF738 = one;
            D_001A4BE0.h1DC = 3;
            func_L03_003BFCE8(o);
            o->p.q = D_001A4BE0.q80.q;
            o->r.q = D_001A4BE0.q90.q;
            if (o->b42 == one) {
                if (func_0037E1D8(10) == 0) {
                    func_L03_003BF738(o);
                }
                if (o->b60 & 2) {
                    if (o->b43 != 0) {
                        func_003BE4F0(o, 0, 0, 0);
                    }
                    o->h34 |= 1;
                    o->b31 = 0;
                    for (i = 0; i < 4; i++) {
                        func_L03_003BF738(o);
                    }
                }
            }
            if (D_001A4BE0.wC08 & 2) {
                func_L01_0050BB98(0, 0, 30.0f);
            }
            if (o->b42 != 0) {
                return;
            }
            if (func_00388398((u8 *)s + 0x7C) == 0) {
                return;
            }
            D_L03_001DF35C = 0;
            func_L01_004F12C0(&D_001A4BE0.q80, &D_001A4BE0.q90, 0, 0);
            func_L01_003E9730(0, 0);
            func_0039FE80(0, 0, o);
            func_L03_003C0398(&o->p, 10);
            func_L01_0044ECE0(0x12A9, 0x1F4, 0);
            D_00142792[0] = 1;
            func_00399F90();
            func_00399C90(0, -1);
            if (D_001A7E18.h == 0) {
                func_L01_00417F60(0x1070, 0xDF);
            }
            o->w98 = 0;
            o->h34 = (o->h34 | 0x41) & 0xEFFF;
            func_L01_004A6DF8(o, 1);
        destroy:
            func_003BD360(o);
        }
    } else {
        if (o->b20 == 0) {
                o->b20 = 1;
                if (D_00142792[0] == 0) {
                    o->w98 = 0;
                    o->h34 = (o->h34 | 0x41) & 0xEFFF;
                    func_L01_004A6DF8(o, 1);
                } else {
                    f32 t;
                    o->r.f[1] = func_00389380(o->r.f[1], 1.5707964f);
                    t = o->p.f[2] + 0.35f;
                    o->h34 &= 0xFFBE;
                    o->p.f[2] = t;
                    o->h34 |= o->p24->h44 & 0x1000;
                    o->w98 = o->p24->w10;
                }
            }
    }
}
/* localdecomp:end func_L03_003BFEF0 */
