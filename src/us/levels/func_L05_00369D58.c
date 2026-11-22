#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L05_0036B268 (src/levels/shared/L05_0036B268.c) */
/* localdecomp:start func_L05_00369D58 */
typedef int u128_00369D58 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00369D58;
typedef struct { V_00369D58 v0; u8 pad10[0x20]; } C_00369D58;
typedef struct { s32 w0; s32 w4; s32 w8; } P_00369D58;
typedef struct { u8 pad00[1]; u8 b1; u8 pad02[0x6A]; f32 f6C; u8 pad70[0x80]; } R_00369D58;
typedef struct { u8 pad00[0x25C0]; u8 *w25C0; } H_00369D58;

extern H_00369D58 D_001A4BE0;
extern u8 D_001425C0[];
extern R_00369D58 D_L05_002C8000[];
extern u8 *D_L05_001EE7C0[];
extern u128_00369D58 D_L05_001EA760;
extern u8 D_L05_0028DE80[];
extern void func_L05_0036A360(u8 *);
extern s32 func_00388398(void *);
extern void func_L05_0036A0D0(u8 *);
extern s32 func_003CF790(void *, s32, void *, s32, f32);
extern u8 *func_0037E0B8(void *);
extern void func_L01_004C41E8(void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L05_0036A788(u8 *, u8 *, s32);
extern void func_L01_0034BF98(void *, s32, s32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_00443840(void *, void *);
extern f32 func_0037E2A8(void);
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L05_0036AA18();
extern void func_L01_004026A0_00369D58(void *, void *);
extern void func_003BD360(void *);

void func_L05_00369D58(u8 *o) {
    P_00369D58 *p;
    V_00369D58 a;
    V_00369D58 c;
    V_00369D58 b;
    C_00369D58 cc;
    s32 n;
    s32 i;
    u8 **ps;
    f32 r1;
    f32 sc;

    p = *(P_00369D58 **)(o + 0x68);
    if (func_00388398(p) == 0) {
        func_L05_0036A0D0(o);
        n = func_003CF790(o + 0x10, 1, o, 0, 10.0f);
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
                func_L01_004C41E8(o + 0x10, &c);
                func_00388830(&c, &c, *(f32 *)(t + 0x10));
                vec_add_ba(&a, *ps + 0x10, &c);
                func_L05_0036A788(o, (u8 *)&a, 5);
                if (p->w0 == 0x1D) {
                    if (D_L05_002C8000[D_001425C0[0x3F]].b1 >= 2) {
                        func_L01_0034BF98(*ps, 0x3F, p->w4);
                    }
                }
                vec_sub_ba(&b, *ps + 0x10, o + 0x10);
                func_00388830(&b, &b, 1.5f);
                func_00388830(&cc, &cc, 2.0f);
                {
                    R_00369D58 *r = &D_L05_002C8000[D_001425C0[0x3F]];
                    sc = r->f6C * 0.001f;
                }
                if (p->w8 != 0) {
                    func_L01_00443628(&cc, o, 0x110000, &b, sc);
                } else {
                    func_L01_00443628(&cc, o, 0x210000, &b, sc);
                }
                cc.v0 = b;
                *(s32 *)((u8 *)&cc + 0x20) = 1;
                cc.v0.w = 5627.925f;
                *((u8 *)&cc + 0x18) = 5;
                *((u8 *)&cc + 0x19) = 3;
                *(u16 *)((u8 *)&cc + 0x1A) = *(u16 *)(*ps + 0xAA);
                func_L01_00443840(*ps, &cc);
            }
        }
        r1 = func_0037E2A8();
        func_0037E4B8(&a, 7.0f, r1, func_0037E2A8());
        vec_add_ab(&a, &a, o + 0x10);
        if (func_003CE740(o + 0x10, &a, 0, o, 0) != 0) {
            *(u128_00369D58 *)&a = D_L05_001EA760;
        }
        func_L05_0036A788(o, (u8 *)&a, 5);
        func_L05_0036AA18(o);
        func_L01_004026A0_00369D58(func_L05_0036A360, o);
    } else {
        s32 j;
        for (j = 15; j >= 0; j--) {
            u8 *e = D_L05_0028DE80 + j * 0xB0;
            *(s32 *)(e + 0x9C) = 0;
        }
        func_003BD360(o);
    }
}
/* localdecomp:end func_L05_00369D58 */
