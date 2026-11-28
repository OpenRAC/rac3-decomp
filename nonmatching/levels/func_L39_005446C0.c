/* First draft (wave 13, r25), 6 diff at level 39 (and level 53) with the file's flags; fresh entry.
 * Everything else matches: struct-typed accesses (retail hoists the 0x2F8 load above the global store),
 * the float locals f20-f23/f5 reused the way retail's registers are (separate temporaries elsewhere),
 * duplicated arms that retail cross-jumped (the 0 < z scale, the 0x2B0 target), the 20/15 degree
 * limits as variables, qzero for the q80 clear, the gp slot D_001D5A54_sda.
 * Still differs: (1) the vector add. This file's line has no -mvu0-use-vf0-vf2, so the vu0.h helpers
 * cannot compile here; retail's sequence has the call's daddu a0, s3 between vadd and the first sqc2
 * and the second sqc2 (a compiler spill of the sum to 0xC0(sp)) in the jal delay slot, which only a
 * register-allocated VU0 value can give; one asm block (the allowed form) leaves 3 words different.
 * (2) the lv60 stores: retail x, y, (a1), z; here y, (a1), x (3 words), unchanged by five orders.
 */#include "common.h"

/* localdecomp:start func_L39_005446C0 */
#include "vu0.h"

typedef int u128_005446C0 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x100];
    f32 f100;
    f32 f104;
    u8 pad108[0x1A0 - 0x108];
    s32 f1A0;
} Pad_005446C0;
typedef struct {
    u8 pad0[0x110];
    f32 f110;
    f32 f114;
    u8 pad118[0x2D0 - 0x118];
    s32 f2D0;
    u8 pad2D4[0x320 - 0x2D4];
    s16 f320;
    u8 pad322[0x1A14 - 0x322];
    u8 f1A14;
    u8 pad1A15[0x2534 - 0x1A15];
    Pad_005446C0 *f2534;
    u8 pad2538[0x2544 - 0x2538];
    s32 f2544;
} P_005446C0;
typedef struct {
    u8 pad0[0x270];
    u128_005446C0 q270;
    u8 pad280[0x2D8 - 0x280];
    P_005446C0 *f2D8;
    u8 pad2DC[0x2F8 - 0x2DC];
    s32 f2F8;
    u8 pad2FC[0x310 - 0x2FC];
    f32 f310;
} T_005446C0;
typedef struct {
    u8 pad0[0x290];
    vu0_v4 v290;
    f32 f2A0;
    f32 f2A4;
    f32 f2A8;
    u8 pad2AC[4];
    f32 f2B0;
    f32 f2B4;
    u8 pad2B8[0x350 - 0x2B8];
    f32 f350;
    u8 pad354[0x384 - 0x354];
    T_005446C0 *f384;
    u8 pad388[0x390 - 0x388];
    f32 f390;
    f32 f394;
    f32 f398;
    f32 f39C;
    u8 pad3A0[0x3BC - 0x3A0];
    s32 f3BC;
} O_005446C0;
typedef struct {
    u8 pad0[0x68];
    O_005446C0 *f68;
    u8 pad6C[0xC0 - 0x6C];
    u8 mC0[0x30];
    f32 fF0;
    f32 fF4;
    f32 fF8;
} A_005446C0;
typedef struct {
    u8 pad[0xA4];
    u8 fA4[4];
} G_005446C0;

extern Pad_005446C0 *D_001D5A54_sda;
__asm__(".extern D_001D5A54_sda, 4");
extern s32 D_L39_0024BB90;
extern G_005446C0 D_001A5810_005446C0;
extern s32 D_001A58D0[][8];
extern s32 D_001A5930[][8];

s32 func_L39_005446C0(A_005446C0 *a) {
    extern void func_0038D5B0(void *, void *);
    extern void func_0038D028(void *, void *, void *);
    extern void func_0038D328(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038DAB8(f32, f32);
    extern s32 func_L39_00543AA8(void *);
    extern f32 func_L01_00448728(f32 *pos, f32 target, f32 *vel, f32 a, f32 b, f32 c, s32 mode);
    O_005446C0 *o = a->f68;
    Pad_005446C0 *pad = D_001D5A54_sda;
    T_005446C0 *g;
    T_005446C0 *g2;
    P_005446C0 *pl;
    P_005446C0 *p2;
    P_005446C0 *p3;
    vu0_v4 *vec;
    vu0_v4 m0[4];
    vu0_v4 lv40;
    vu0_v4 lv50;
    vu0_v4 lv60;
    vu0_v4 m70[4];
    vu0_v4 q80;
    vu0_v4 tmp;
    s32 res;
    s32 idx;
    s32 b;
    s32 btn;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;
    f32 f5;
    f32 t1;
    f32 t0;
    f32 sgn;
    f32 cur;
    f32 x;
    f32 x2;
    f32 p0;
    f32 p1;
    f32 pitch;
    f32 d;
    f32 hi = 20.0f;
    f32 lo = 15.0f;

    g = o->f384;
    if (g != 0) {
        pl = g->f2D8;
        if (pl != 0) {
            if (pl->f1A14 != 0) {
                D_L39_0024BB90 = 2;
                g->f2F8 |= 0x800;
            }
            pad = o->f384->f2D8->f2534;
        }
    }
    vec = &o->v290;
    if (o->f3BC != 0) {
        func_0038D5B0(m0, a->mC0);
        func_0038D028(&lv40, vec, m0);
    }

    t1 = o->f2A8 * 0.9f;
    f20 = o->v290.z;
    f20 *= 0.95f;
    o->f2A8 = t1;
    func_0038CE20(vec, vec, 0.98f);
    o->v290.z = f20;

    p2 = o->f384->f2D8;
    idx = p2->f2544;
    t0 = p2->f110;
    b = D_001A5810_005446C0.fA4[idx];
    if (o->f3BC != 0) {
        t0 = -t0;
    }
    f22 = t0;
    f23 = -1.0f;
    if (D_001A58D0[b][idx] != 0) {
        f23 = 1.0f;
    }
    sgn = 1.0f;
    if (D_001A5930[b][idx] != 0) {
        sgn = -1.0f;
    }
    p2->f2D0 = 0;
    if (b == 0) {
        sgn = 1.0f;
    }
    btn = pad->f1A0;
    p3 = o->f384->f2D8;
    f5 = -pad->f100 * sgn;
    f21 = p3->f114;
    f20 = 0.0f;
    if (btn & 4) {
        f20 = 1.0f;
    }
    if (btn & 1) {
        f20 -= 1.0f;
    }
    if (btn & 0x40) {
        f20 += 1.0f;
    }
    if (btn & 0x80) {
        f20 -= 1.0f;
    }
    if (1.0f < f20) {
        f20 = 1.0f;
    }
    if (f20 < -1.0f) {
        f20 = -1.0f;
    }
    if (o->f384 != 0 && p3 != 0 && p3->f320 > 0) {
        f5 = 0.0f;
        f20 = 0.0f;
        f21 = 0.0f;
        f22 = 0.0f;
    }

    d = (f20 + 1.0f) * 0.5f * 0.087266475f + 0.052359879f - o->f390;
    if (0.0034906587f < d) {
        d = 0.0034906587f;
    } else if (d < -0.0034906587f) {
        d = -0.0034906587f;
    }
    o->f390 = o->f390 + d;
    f22 *= 0.008f;
    f5 *= 0.0029321532f;
    f21 *= 0.014f;
    if (0.0f < f20) {
        f20 *= 0.014f;
    } else {
        f20 *= 0.014f;
    }
    x = func_0038DAB8(o->f2A8, f5);
    o->f2A8 = x;
    if (0.20943952f < x) {
        o->f2A8 = 0.20943952f;
    } else if (x < -0.20943952f) {
        o->f2A8 = -0.20943952f;
    }
    if (o->f3BC != 0) {
        a->fF8 = func_0038DAB8(a->fF8, o->f2A8);
    }
    lv60.x = f21;
    lv60.y = f22;
    lv60.z = f20;
    qzero(&q80);
    q80.z = a->fF8;
    func_0038D328(m70, &q80);
    f22 = 0.48000002f;
    func_0038D028(&lv60, &lv60, m70);
    __asm__ __volatile__(
        "lqc2 $vf1, %2\n"
        "lqc2 $vf2, %3\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %0\n"
        "sqc2 $vf1, %1\n"
        : "=m"(o->v290), "=m"(tmp)
        : "m"(o->v290), "m"(lv60)
        : "vf1", "vf2");
    f21 = func_0038CED8(vec);
    if (f22 < f21) {
        f20 = f22 / f21;
        o->v290.x *= f20;
        o->v290.y *= f20;
        f21 = f22;
    }
    o->f384->f310 = f21;
    x2 = o->v290.z;
    if (0.28000003f < x2) {
        o->v290.z = 0.28000003f;
    } else if (x2 < -0.28000003f) {
        o->v290.z = -0.28000003f;
    }
    o->f384->q270 = *(u128_005446C0 *)&o->v290;
    res = func_L39_00543AA8(a);

    if (o->f3BC != 0) {
        f5 = (o->f394 - o->f39C) * -0.8f;
    } else {
        f5 = (o->f39C - o->f394) * -0.8f;
    }
    func_L01_00448728(&o->f2B0, f5, &o->f2A0, 0.01008f, 0.28800002f, 0.024434611f, 0);
    if (0.3f < o->f2B0) {
        o->f2B0 = 0.3f;
    }
    if (o->f2B0 < -0.3f) {
        o->f2B0 = -0.3f;
    }
    if (o->f3BC != 0) {
        a->fF0 = o->f2B0;
    }

    pitch = pad->f104;
    g2 = o->f384;
    if (g2 != 0 && g2->f2D8 != 0 && g2->f2D8->f320 > 0) {
        pitch = 0.0f;
    }
    o->f350 = o->f350 + pitch * -0.012f * f23;
    if (hi * 0.017453292f < o->f350) {
        o->f350 = hi * 0.017453292f;
    }
    if (o->f350 < -lo * 0.017453292f) {
        o->f350 = -lo * 0.017453292f;
    }
    if (o->f3BC != 0) {
        a->fF4 = o->f350;
        if (o->f3BC != 0) {
            func_0038D028(&lv50, vec, m0);
        }
    }
    f5 = (lv50.x - lv40.x) * 45.0f;
    f21 = 0.008f;
    if (fabs_asm(f5) <= 0.001f) {
        f21 = 0.000800000038f;
    }
    func_L01_00448728(&o->f2B4, f5, &o->f2A4, f21 * 1.44f, 0.28800002f, 0.034906588f, 0);
    if (0.55f < o->f2B4) {
        o->f2B4 = 0.55f;
    }
    if (o->f2B4 < -0.5f) {
        o->f2B4 = -0.5f;
    }
    if (o->f3BC != 0) {
        a->fF4 = func_0038DAB8(a->fF4, o->f2B4);
    }
    return res;
}
/* localdecomp:end func_L39_005446C0 */
