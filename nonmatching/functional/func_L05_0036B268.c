/* functional: high. Rebuilt from PAL asm with NTSC draft as guide; 199 diffs are register/schedule only. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_0036B268 */
typedef struct {
    u8 pad00[1];
    u8 b1;
    u8 pad02[0x6A];
    f32 f6C;
    u8 pad70[0x80];
} R_0036B268;
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
} P_0036B268;
typedef struct {
    u8 pad00[0x25C0];
    u8 *w25C0;
} H_0036B268;
typedef struct {
    vu0_v4 v0;
    u8 pad10[0x8];
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad1C[4];
    s32 w20;
    u8 pad24[0xC];
} C_0036B268;
extern H_0036B268 D_001A4BE0;
extern u8 D_001425C0[];
extern R_0036B268 D_L05_002C7FC0[];
extern u8 *D_L05_001EE740[];
extern vu0_v4 D_L05_001EA6E0;
extern u8 D_L05_0028DE00[];
extern s32 func_0038CAD0(void *);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern u8 *func_00382348(void *);
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0034C9F0(void *, s32, s32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446978(void *, void *);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_00404A10();
extern void func_003C2880(void *);
extern void func_L05_0036B5E0();
extern void func_L05_0036BC98();
extern void func_L05_0036BF28();
extern void func_L05_0036B870();

void func_L05_0036B268(u8 *o) {
    P_0036B268 *p;
    u8 *pos;
    vu0_v4 a;
    vu0_v4 c;
    vu0_v4 b;
    C_0036B268 cc;
    s32 n;
    s32 i;
    u8 **ps;
    u8 *t;
    f32 r1;
    f32 r2;

    p = *(P_0036B268 **)(o + 0x68);
    if (func_0038CAD0(p) == 0) {
        func_L05_0036B5E0(o);
        pos = o + 0x10;
        n = func_003D4D00(pos, 1, o, 0, 10.0f);
        if (n != 0 && D_L05_002C7FC0[D_001425C0[0x3F]].b1 != 0 && n > 0) {
            ps = D_L05_001EE740;
            for (i = n; i != 0; i--, ps++) {
                t = func_00382348(*ps);
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
                if (p->w8 != 0) {
                    func_L01_00446760(&cc, o, 0x110000, &b, D_L05_002C7FC0[D_001425C0[0x3F]].f6C * 0.001f);
                } else {
                    func_L01_00446760(&cc, o, 0x210000, &b, D_L05_002C7FC0[D_001425C0[0x3F]].f6C * 0.001f);
                }
                cc.v0 = b;
                cc.v0.w = 5627.925f;
                cc.b18 = 5;
                cc.b19 = 3;
                cc.h1A = *(u16 *)(*ps + 0xAA);
                cc.w20 = 1;
                func_L01_00446978(*ps, &cc);
            }
        }
        r1 = func_00382538();
        r2 = func_00382538();
        func_00382760(&a, 7.0f, r1, r2);
        vec_add_ab(&a, &a, o + 0x10);
        if (func_003D3CB0(pos, &a, 0, o, 0) != 0) {
            *(vu0_q *)&a = *(vu0_q *)&D_L05_001EA6E0;
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
