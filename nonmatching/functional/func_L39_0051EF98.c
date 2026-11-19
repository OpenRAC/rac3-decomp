/* functional: medium. Every block read against asm; counts/constants taken from asm; needs vu0 flag line. */
#include "vu0.h"
typedef struct { s32 v[6]; } Arr6_0051EF98;
extern u8 D_L39_0024DE80[];
extern f32 D_001DF170_sda, D_001DF174_sda, D_001DF178_sda, D_001DF17C_sda;
extern f32 D_001DF1C8_sda, D_001DF1CC_sda, D_001DF1D0_sda;
extern s32 D_001DF1D4_sda;
extern f32 D_001DF190_sda, D_001DF194_sda, D_001DF198_sda;
extern s32 D_001DF188_sda, D_001DF18C_sda;
extern s32 *D_L39_00241120;
extern Arr6_0051EF98 D_L39_0024A8E8;
extern Arr6_0051EF98 D_L39_0024A900;
extern f32 D_L39_0046F580[];
extern f32 func_0038CEA8(void *);
extern s32 func_L39_005BE900(void *, void *, f32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B44C8(void);
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040E6B8(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_002FB660(void *, void *, s32, s32, s32, s32);
extern void func_L39_0051EB38(void *, void *);
extern void func_L39_0051ED58(void *, void *);
extern void func_L39_005C6E90(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32);
extern void func_00382580(void *, f32, f32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_00448D88(u32, s32);
extern u8 *func_L01_00470668(void *, void *, s32, f32);
extern void func_0038CE20(void *, void *, f32);

/* Multiplayer-menu level: the impact effect of a projectile at `hit` (m = the projectile). Picks how
 * strong the effect is from the distance between the hit point and the reference position (nearest
 * player), then sprays dust puffs, debris and smoke/sparks around the hit point. */
void func_L39_0051EF98(u8 *m, vu0_v4 *hit) {
    vu0_v4 d, q10, q20, q30, q40;
    Arr6_0051EF98 A, B;
    f32 out[2];
    f32 dist, f20, f21;
    s32 cntDust, cntDebris, cntSpark, i, k, r;
    u8 *p = *(u8 **)(*(u8 **)(m + 0x68) + 0x30);
    u8 *ref;
    u8 *e;

    if (p != 0) {
        ref = D_L39_0024DE80 + p[0x24C9] * 0x460;
    } else {
        ref = D_L39_0024DE80;
    }
    vec_sub_ba(&d, ref, hit);
    cntDust = 5;
    dist = func_0038CEA8(&d);
    q10 = *(vu0_v4 *)(m + 0x10);
    q10.w = 0.5f;
    if (func_L39_005BE900(&q10, out, D_001DF17C_sda) > 0) {
        if (out[0] < D_001DF170_sda * D_001DF170_sda) {
            cntDebris = 3;
            r = 150;
        } else if (out[0] < D_001DF174_sda * D_001DF174_sda) {
            cntDust = 2;
            cntDebris = 5;
            r = 25;
        } else if (out[0] < D_001DF178_sda * D_001DF178_sda) {
            cntDust = 0;
            cntDebris = 5;
            r = 10;
        } else {
            cntDust = 0;
            cntDebris = 3;
            r = 0;
        }
    } else {
        r = 0;
        cntDust = 0;
        cntDebris = 0;
    }
    cntSpark = r;
    if (!(*D_L39_00241120 < 3)) {
        cntDust = 0;
    }
    cntDust--;
    if (cntDust + 1 != 0) {
        q30.x = func_L39_005B4410(-1.0f, 1.0f);
        q30.y = func_L39_005B4410(-1.0f, 1.0f);
        q30.z = func_L39_005B4410(-1.0f, 1.0f);
        q30.w = 0.0f;
        d.z = d.z + dist * 0.5f;
        q20 = q30;
        func_0038CF68(&q20, &q20, dist / 5.0f * 0.020000001415610313f);
        func_0038CF68(&d, &d, (dist + dist) * 0.020000001415610313f);
        vec_add_ab(&q20, &q20, &d);
        func_L01_0040E6B8(&q20, &q20, 0.20000001788139343f);
        func_0038D000(&q20, &q20, m + 0xC0);
        func_L01_002FB660(hit, &q20, func_L39_005B43C8(50, 75), 0, 0, 0);
        for (k = cntDust; k > 0; k--) {
            func_L39_0051EB38(m, hit);
        }
    }
    qzero(&q20);
    if (cntDebris != 0) {
        k = cntDebris;
        do {
            Arr6_0051EF98 *pa;
            s32 n17, n42;
            f20 = func_L39_005B4410(8.0f, 10.0f);
            k--;
            A = D_L39_0024A8E8;
            B = D_L39_0024A900;
            f20 = f20 * 0.020000001415610313f;
            i = func_L39_005B4398(6);
            r = func_L39_005B4398(6);
            n17 = func_L39_005B43C8(17, 33);
            n42 = func_L39_005B43C8(42, 58);
            func_L39_005C6E90(hit, &q20, A.v[i], B.v[r], n17, n42, 0, 0, 600000.0f, f20 * 1.5f);
            func_L39_0051ED58(m, hit);
        } while (k != 0);
    }
    D_L39_0046F580[8] = 13.0f;
    D_L39_0046F580[9] = 13.0f;
    D_L39_0046F580[10] = 13.0f;
    k = 19;
    do {
        s32 n, c;
        f21 = 0.5f;
        qzero(&q40);
        q40.z = func_L39_005B4410(D_001DF1C8_sda * f21, D_001DF1C8_sda) * 0.020000001415610313f;
        q30 = q40;
        func_0038D000(&q30, &q30, m + 0xC0);
        func_00382580(&q40, 0.0f, D_001DF1CC_sda);
        n = (D_001DF1D4_sda * 5 + 2) / 6;
        vec_add_ba(&q40, hit, &q40);
        c = func_L39_005B43C8(-2, 2);
        e = func_L01_00475C60(&q40, &q30, n, c, 0x7F407FFF, 0x407FFF, 420000.0f, 252000.015625f,
                              func_L39_005B4410(D_001DF1D0_sda * 0.6000000238418579f, D_001DF1D0_sda), 0);
        if (e != 0) {
            e[2] = (*(u8 **)(D_L39_00296818 + 0x184))[3];
        }
        k--;
    } while (k >= 0);
    if (cntSpark != 0) {
        for (i = 0; i < cntSpark; i++) {
            f21 = func_L39_005B4410(0.13962633907794952f, 0.6108652353286743f);
            f20 = func_L39_005B44C8();
            func_L01_00448D88(0x4F007FFF, 0);
            func_L01_00448D88(0x1F00007F, 0);
            func_0038D000(&q30, &q30, m + 0xC0);
            if (i < 40) {
                func_L01_00470668(hit, &q30, (func_L39_005B43C8(25, 40) * 5 + 2) / 6, D_001DF198_sda * 0.0004000000189989805f);
            }
            func_0038CE20(&q30, &q30, func_L39_005B4410(0.10000000149011612f, 1.2000000476837158f));
            r = func_L39_005B43C8(50, 100);
            e = func_L01_00475C60(hit, &q30, r - 10, -2, 0x7F404040, 0x404040, D_001DF190_sda * 210000.0f,
                                  D_001DF190_sda * 210000.0f, D_001DF194_sda, 0);
            if (e != 0) {
                e[2] = (*(u8 **)(D_L39_00296818 + D_001DF188_sda * 4))[D_001DF18C_sda];
            }
        }
    }
}
