/* NTSC-U draft (Claude wave K): C of func_L05_00369D58, the NTSC-U twin of func_L05_0036B268, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L05_00369D58", whose code is not the PAL one).
 * Worker's note: best TOTAL 110 aligned words (retail 221, ours 220), 1 draft + 24-order scan of the local vectors; flags: the PAL line has neither -mvu0-use-vf0-vf2 (vec_add_ba/vec_sub_ba/vec_add_ab) nor @ps2as, so best status is flags. Decoded: p=o->p68, if func_00388398(p) ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_00369D58 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct V_00369D58 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00369D58;

typedef struct C_00369D58 {
    V_00369D58 v0;
    u8 pad10[0xC];
    f32 f1C;
    u8 pad20[0x28];
} C_00369D58;

typedef struct P_00369D58 {
    s32 w0;
    s32 w4;
    s32 w8;
} P_00369D58;

typedef struct R_00369D58 {
    u8 pad00[1];
    u8 b1;
    u8 pad02[0x6A];
    f32 f6C;
    u8 pad70[0x80];
} R_00369D58;

typedef struct H_00369D58 {
    u8 pad00[0x25C0];
    u8 *w25C0;
} H_00369D58;

extern H_00369D58 D_001A4BE0;
extern u8 D_001425C0[];
extern R_00369D58 D_L05_002C8000[];
extern u8 *D_L05_001EE7C0[];
extern u128_t D_L05_001EA760;
extern u8 D_L05_0036DE80[];
extern void func_L05_0036A360(void);

extern s32 func_00388398(void *);
extern void func_L05_0036A0D0(void *);
extern s32 func_003CF790(void *, s32, void *, s32, f32);
extern u8 *func_0037E0B8(void *);
extern void func_L01_004C41E8(void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L05_0036A788(void *, void *, s32);
extern void func_L01_0034BF98(void *, s32, s32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_00443840(void *, void *);
extern f32 func_0037E2A8(void);
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L05_0036AA18(void *);
extern void func_L01_004026A0(void *, void *);
extern void func_003BD360(void *);

void func_L05_00369D58(u8 *o) {
    P_00369D58 *p;
    u8 *pos;
    V_00369D58 a;
    V_00369D58 c;
    V_00369D58 b;
    C_00369D58 cc;
    s32 n;
    s32 i;
    u8 **ps;
    f32 r1;

    p = *(P_00369D58 **)(o + 0x68);
    if (func_00388398(p) == 0) {
        func_L05_0036A0D0(o);
        pos = o + 0x10;
        n = func_003CF790(pos, 1, o, 0, 10.0f);
        if (n != 0 && D_L05_002C8000[D_001425C0[0x3F]].b1 != 0 && n > 0) {
            ps = D_L05_001EE7C0;
            for (i = n; i != 0; i--, ps++) {
                u8 *t = func_0037E0B8(*ps);
                if (t == 0) {
                    continue;
                }
                if ((*(u16 *)(*ps + 0x34) & 0x4000) == 0) {
                    continue;
                }
                if (*ps == D_001A4BE0.w25C0) {
                    continue;
                }
                func_L01_004C41E8(pos, &c);
                func_00388830(&c, &c, *(f32 *)(t + 0x10));
                vec_add_ba(&a, *ps + 0x10, &c);
                func_L05_0036A788(o, &a, 5);
                if (p->w0 == 0x1D) {
                    if (D_L05_002C8000[D_001425C0[0x3F]].b1 >= 2) {
                        func_L01_0034BF98(*ps, 0x3F, p->w4);
                    }
                }
                vec_sub_ba(&b, *ps + 0x10, o + 0x10);
                func_00388830(&b, &b, 1.5f);
                func_00388830(&cc, &cc, 2.0f);
                if (p->w8 != 0) {
                    func_L01_00443628(&cc, o, 0x110000, &b, D_L05_002C8000[D_001425C0[0x3F]].f6C * 0.001f);
                    cc.v0 = b;
                } else {
                    func_L01_00443628(&cc, o, 0x210000, &b, D_L05_002C8000[D_001425C0[0x3F]].f6C * 0.001f);
                    cc.v0 = b;
                }
                cc.f1C = 5627.925f;
                *((u8 *)&cc + 0x18) = 5;
                *((u8 *)&cc + 0x19) = 3;
                *(u16 *)((u8 *)&cc + 0x1A) = *(u16 *)(*ps + 0xAA);
                *(s32 *)((u8 *)&cc + 0x20) = 1;
                func_L01_00443840(*ps, &cc);
            }
        }
        r1 = func_0037E2A8();
        func_0037E4B8(&a, 7.0f, r1, func_0037E2A8());
        vec_add_ab(&a, &a, o + 0x10);
        if (func_003CE740(pos, &a, 0, o, 0) != 0) {
            *(u128_t *)&a = D_L05_001EA760;
        }
        func_L05_0036A788(o, &a, 5);
        func_L05_0036AA18(o);
        func_L01_004026A0(func_L05_0036A360, o);
    } else {
        for (i = 15; i >= 0; i--) {
            *(s32 *)(D_L05_0036DE80 + 0x4BC + i * 0xB0) = 0;
        }
        func_003BD360(o);
    }
}
/* localdecomp:end func_L05_00369D58 */
