/* func_L05_0036B268 (PAL): 143 differences with its file's flags. PAL port (Promises, 2026-11-20) of the
 * NTSC-U draft of func_L05_00369D58 (Claude wave K), which this file held before: PAL names and addresses
 * (func_L05_0036BC98 with 4, the 0xF0-stride table D_L05_002C7FC0, D_L05_001EE740, D_L05_001EA6E0, the 16
 * entries of D_L05_0028DE00 cleared at +0x9C), the 0x30-byte struct at sp+0x30, and the scale of
 * func_L01_00446760 computed once through a row pointer (retail multiplies in the beqz delay slot; 200 -> 143).
 * Still differs: retail computes o + 0x10 into $s0 and copies it to $s7 (two pseudos) before the first
 * func_003D4D00 call, and gives the loop's pointers $s3/$s4/$s5/$s6 where this C has $s4/$s5/$s6/$s2, so almost
 * every remaining difference is that register cascade; also the lui $a2 of the 0x210000 call is scheduled
 * outside the jal delay slot. Tried: pos assigned before or after the first call, o + 0x10 passed directly. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_0036B268 */
typedef int u128_0036B268 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0036B268;
typedef struct { V_0036B268 v0; u8 pad10[0xC]; f32 f1C; u8 pad20[0x10]; } C_0036B268;
typedef struct { s32 w0; s32 w4; s32 w8; } P_0036B268;
typedef struct { u8 pad00[1]; u8 b1; u8 pad02[0x6A]; f32 f6C; u8 pad70[0x80]; } R_0036B268;
typedef struct { u8 pad00[0x25C0]; u8 *w25C0; } H_0036B268;

extern H_0036B268 D_001A4BE0;
extern u8 D_001425C0[];
extern R_0036B268 D_L05_002C7FC0[];
extern u8 *D_L05_001EE740[];
extern u128_0036B268 D_L05_001EA6E0;
extern u8 D_L05_0028DE00[];
extern void func_L05_0036B870(void);
extern s32 func_0038CAD0(void *);
extern void func_L05_0036B5E0(u8 *);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern u8 *func_00382348(void *);
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L05_0036BC98(void *, void *, s32);
extern void func_L01_0034C9F0(void *, s32, s32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446978(void *, void *);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L05_0036BF28(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_003C2880(void *);

void func_L05_0036B268(u8 *o) {
    P_0036B268 *p;
    u8 *pos;
    V_0036B268 a;
    V_0036B268 c;
    V_0036B268 b;
    C_0036B268 cc;
    s32 n;
    s32 i;
    u8 **ps;
    f32 r1;
    f32 sc;

    p = *(P_0036B268 **)(o + 0x68);
    if (func_0038CAD0(p) == 0) {
        func_L05_0036B5E0(o);
        n = func_003D4D00(o + 0x10, 1, o, 0, 10.0f);
        pos = o + 0x10;
        if (n != 0 && D_L05_002C7FC0[D_001425C0[0x3F]].b1 != 0 && n > 0) {
            ps = D_L05_001EE740;
            for (i = n; i != 0; i--, ps++) {
                u8 *t = func_00382348(*ps);
                if (t == 0) {
                    continue;
                }
                if ((*(u16 *)(*ps + 0x34) & 0x4000) == 0) {
                    continue;
                }
                if (*ps == D_001A4BE0.w25C0) {
                    continue;
                }
                func_L01_004C7D98(pos, &c);
                func_0038CF68(&c, &c, *(f32 *)(t + 0x10));
                vec_add_ba(&a, *ps + 0x10, &c);
                func_L05_0036BC98(o, &a, 4);
                if (p->w0 == 0x1D) {
                    if (D_L05_002C7FC0[D_001425C0[0x3F]].b1 >= 2) {
                        func_L01_0034C9F0(*ps, 0x3F, p->w4);
                    }
                }
                vec_sub_ba(&b, *ps + 0x10, o + 0x10);
                func_0038CF68(&b, &b, 1.5f);
                func_0038CF68(&cc, &cc, 2.0f);
                { R_0036B268 *r = &D_L05_002C7FC0[D_001425C0[0x3F]]; sc = r->f6C * 0.001f; }
                if (p->w8 != 0) {
                    func_L01_00446760(&cc, o, 0x110000, &b, sc);
                    cc.v0 = b;
                } else {
                    func_L01_00446760(&cc, o, 0x210000, &b, sc);
                    cc.v0 = b;
                }
                cc.f1C = 5627.925f;
                *((u8 *)&cc + 0x18) = 5;
                *((u8 *)&cc + 0x19) = 3;
                *(u16 *)((u8 *)&cc + 0x1A) = *(u16 *)(*ps + 0xAA);
                *(s32 *)((u8 *)&cc + 0x20) = 1;
                func_L01_00446978(*ps, &cc);
            }
        }
        r1 = func_00382538();
        func_00382760(&a, 7.0f, r1, func_00382538());
        vec_add_ab(&a, &a, o + 0x10);
        if (func_003D3CB0(pos, &a, 0, o, 0) != 0) {
            *(u128_0036B268 *)&a = D_L05_001EA6E0;
        }
        func_L05_0036BC98(o, &a, 4);
        func_L05_0036BF28(o);
        func_L01_00404A10(func_L05_0036B870, o);
    } else {
        for (i = 15; i >= 0; i--) {
            *(s32 *)(D_L05_0028DE00 + 0x9C + i * 0xB0) = 0;
        }
        func_003C2880(o);
    }
}
/* localdecomp:end func_L05_0036B268 */
