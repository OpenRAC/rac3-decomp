#include "common.h"

/* NTSC-U counterpart of func_L16_003CC1A8 (src/levels/16_kerwan/L16_003CC0A8.c) */
#include "vu0.h"

/* localdecomp:start func_L16_003CA820 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003CC1A8;

extern s32 D_L16_001DE9B4; __asm__(".extern D_L16_001DE9B4, 4");
extern f32 D_L16_001DE9B8; __asm__(".extern D_L16_001DE9B8, 4");
extern f32 D_L16_001DE9BC; __asm__(".extern D_L16_001DE9BC, 4");
extern f32 D_L16_001DE9C0; __asm__(".extern D_L16_001DE9C0, 4");
extern f32 D_L16_001DE9C4; __asm__(".extern D_L16_001DE9C4, 4");
extern f32 D_L16_001DE9C8; __asm__(".extern D_L16_001DE9C8, 4");
extern f32 D_L16_001DE9CC; __asm__(".extern D_L16_001DE9CC, 4");
extern f32 D_L16_001DE9D0; __asm__(".extern D_L16_001DE9D0, 4");
extern f32 D_L16_001DE9D4; __asm__(".extern D_L16_001DE9D4, 4");
extern s32 D_L16_001DE9D8; __asm__(".extern D_L16_001DE9D8, 4");
extern s32 D_L16_001DE9DC; __asm__(".extern D_L16_001DE9DC, 4");
extern s32 D_L16_001DE9E0; __asm__(".extern D_L16_001DE9E0, 4");
extern s32 D_L16_001DE9E8[3] __attribute__((section(".sdata"))); __asm__(".extern D_L16_001DE9E8, 4");
extern s32 D_L16_001DE9F8[3] __attribute__((section(".sdata"))); __asm__(".extern D_L16_001DE9F8, 4");
extern s32 D_L16_001DEA04; __asm__(".extern D_L16_001DEA04, 4");
extern s32 D_L16_001DEA08; __asm__(".extern D_L16_001DEA08, 4");
extern s32 D_L16_001DEA0C; __asm__(".extern D_L16_001DEA0C, 4");
extern f32 D_L16_001DEA10; __asm__(".extern D_L16_001DEA10, 4");
extern f32 D_L16_001DEA14; __asm__(".extern D_L16_001DEA14, 4");
extern f32 D_L16_001DEA18; __asm__(".extern D_L16_001DEA18, 4");
extern f32 D_L16_001DEA1C; __asm__(".extern D_L16_001DEA1C, 4");
extern f32 D_L16_001DEA20; __asm__(".extern D_L16_001DEA20, 4");
extern f32 D_L16_001DEA24; __asm__(".extern D_L16_001DEA24, 4");
extern f32 D_L16_001DEA28; __asm__(".extern D_L16_001DEA28, 4");
extern f32 D_L16_001DEA2C; __asm__(".extern D_L16_001DEA2C, 4");
extern s32 D_L16_001DEA30; __asm__(".extern D_L16_001DEA30, 4");
extern s32 D_L16_001DEA34; __asm__(".extern D_L16_001DEA34, 4");
extern s32 D_L16_001DEA38[3] __attribute__((section(".sdata"))); __asm__(".extern D_L16_001DEA38, 4");
extern s32 D_L16_001DEA48[3] __attribute__((section(".sdata"))); __asm__(".extern D_L16_001DEA48, 4");
extern s32 D_L16_001DEA54; __asm__(".extern D_L16_001DEA54, 4");

extern void func_003BDA38(void *, s32, void *);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_00444F38_003CA820(s32, s32, f32);
extern f32 func_003BEB48(f32, f32, f32);

/* from an angle and a radius: the point on the circle round the origin, z cleared */
static __inline__ void polar_003CC1A8(V4_003CC1A8 *v, f32 ang, f32 r) {
    v->x = func_00388960(ang) * r;
    v->y = func_00388978(ang) * r;
    v->z = 0.0f;
}

void func_L16_003CA820(u8 *m) {
    u8 *s = *(u8 **)(m + 0x68);
    V4_003CC1A8 pos;
    V4_003CC1A8 top;
    V4_003CC1A8 a;
    V4_003CC1A8 b;
    V4_003CC1A8 c;
    s32 i, j, n, k;
    V4_003CC1A8 *pp;
    f32 f;

    if (*(s32 *)(s + 0x1BC) != 2)
        return;
    for (i = 0; i < 2; i++) {
        func_003BDA38(m, i, &pos);
        top = pos;
        pp = &pos;
        top.z = func_003BE7F0(pp, 0, 0, 0.5f);
        for (j = 0; j < D_L16_001DE9B4; j++) {
            s32 k1, k2, k3, col, fl;
            f32 ang, r;

            k1 = func_0037E208(D_L16_001DE9E8[0], D_L16_001DE9F8[0]);
            k2 = func_0037E208(D_L16_001DE9E8[1], D_L16_001DE9F8[1]);
            k3 = func_0037E208(D_L16_001DE9E8[2], D_L16_001DE9F8[2]);
            ang = func_0037E2A8();
            r = func_0037E250(0.0f, D_L16_001DE9B8);
            polar_003CC1A8(&a, ang, r);
            vec_add_ba(&a, &a, &pos);
            ang = func_0037E2A8();
            r = func_0037E250(0.0f, D_L16_001DE9BC);
            polar_003CC1A8(&b, ang, r);
            b.z = -func_0037E250(D_L16_001DE9C0, D_L16_001DE9C4);
            b.w = D_L16_001DE9CC + func_0037E250(0.0f, D_L16_001DE9D4);
            vec_add_ab(&b, &b, s + 0x240);
            func_003886E8(&c, &b, D_L16_001DE9C8);
            c.w = D_L16_001DE9D0 + func_0037E250(0.0f, D_L16_001DE9D4);
            vec_add_ab(&c, &c, s + 0x240);
            col = func_003894A0(D_L16_001DE9D8, D_L16_001DE9DC, func_0037E250(0.0f, 1.0f));
            if (func_0037E1D8(D_L16_001DEA08))
                fl = D_L16_001DEA04;
            else
                fl = D_L16_001DEA04 | 0x10000;
            func_L01_0045FEC8(&a, &b, &c, col, D_L16_001DE9E0, k1, k2, k3, fl);
        }
        f = 1.0f - fabs_asm(pos.z - top.z) / D_L16_001DEA10;
        n = func_L01_00444F38_003CA820(0, D_L16_001DEA0C, f);
        for (k = 0; k < n; k++) {
            s32 k1, k2, k3;
            f32 ang, r;

            k1 = func_0037E208(D_L16_001DEA38[0], D_L16_001DEA48[0]);
            k2 = (s32)(func_0037E250((f32)D_L16_001DEA38[1], (f32)D_L16_001DEA48[1]) * f) + 1;
            k3 = func_0037E208(D_L16_001DEA38[2], D_L16_001DEA48[2]);
            a = top;
            ang = func_0037E2A8();
            r = func_003BEB48(D_L16_001DEA14, D_L16_001DEA18, f + func_0037E250(-0.1f, 0.1f));
            polar_003CC1A8(&b, ang, r);
            b.w = func_003BEB48(0.0f, D_L16_001DEA24, f) + func_0037E250(0.0f, D_L16_001DEA2C);
            vec_add_ba(&b, &b, s + 0x240);
            func_003886E8(&c, &b, D_L16_001DEA1C);
            c.z += D_L16_001DEA20 * (f32)(k1 + k2 + k3);
            c.w = func_003BEB48(0.0f, D_L16_001DEA28, f) + func_0037E250(0.0f, D_L16_001DEA2C);
            vec_add_ba(&c, &c, s + 0x240);
            func_L01_0045FEC8(&a, &b, &c, D_L16_001DEA30, D_L16_001DEA34, k1, k2, k3, D_L16_001DEA54);
        }
    }
}
/* localdecomp:end func_L16_003CA820 */
