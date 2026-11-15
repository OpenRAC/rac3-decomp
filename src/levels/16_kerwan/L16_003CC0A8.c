#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L16_003CC0A8 */
typedef struct V_003CC0A8 {
    u8 pad00[0x1F0];
    s32 a1F0[3];
    s32 a1FC[4];
    u8 pad20C[0x214 - 0x20C];
    s16 h214;
    s16 h216;
    u8 pad218[0x228 - 0x218];
    s32 w228;
    u8 *w22C;
    u8 x230[0x10];
} V_003CC0A8;

extern void func_003C5060(void *, void *, void *, s32);
extern u8 *D_L16_001E015C;
__asm__(".extern D_L16_001E015C, 16");
extern s32 D_L16_001DFC40;
extern u8 D_001A4C60[];

void func_L16_003CC0A8(u8 *self) {
    V_003CC0A8 *s = *(V_003CC0A8 **)(self + 0x68);
    vu0_v4 tmp;
    u8 *obj;

    if (s->h214 != 0) {
        obj = D_L16_001E015C + (s->a1FC[s->h216] << 8);
    } else {
        obj = D_L16_001E015C + (s->a1F0[s->h216] << 8);
    }
    s->w22C = obj;
    vec_sub_ba(&tmp, D_001A4C60, obj + 0x10);
    tmp.z = 1.618f;
    func_003C5060(s->w22C, s->x230, &tmp, 0);
    s->w228 = D_L16_001DFC40;
}
/* localdecomp:end func_L16_003CC0A8 */

/* localdecomp:start func_L16_003CC150 */
extern void func_0038D000(float *, float *, float *);

void func_L16_003CC150(void *arg0, void *arg1) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    func_0038D000(arg1, (float *)((u8 *)temp_s0 + 0x230),
                  (float *)((u8 *)*(void **)((u8 *)temp_s0 + 0x22C) + 0xC0));
    vec_add_ab(arg1, arg1, (u8 *)*(void **)((u8 *)temp_s0 + 0x22C) + 0x10);
}
/* localdecomp:end func_L16_003CC150 */

/* localdecomp:start func_L16_003CC1A8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003CC1A8;

extern s32 D_001DE974; __asm__(".extern D_001DE974, 4");
extern f32 D_001DE978; __asm__(".extern D_001DE978, 4");
extern f32 D_001DE97C; __asm__(".extern D_001DE97C, 4");
extern f32 D_001DE980; __asm__(".extern D_001DE980, 4");
extern f32 D_001DE984; __asm__(".extern D_001DE984, 4");
extern f32 D_001DE988; __asm__(".extern D_001DE988, 4");
extern f32 D_001DE98C; __asm__(".extern D_001DE98C, 4");
extern f32 D_001DE990; __asm__(".extern D_001DE990, 4");
extern f32 D_001DE994; __asm__(".extern D_001DE994, 4");
extern s32 D_001DE998; __asm__(".extern D_001DE998, 4");
extern s32 D_001DE99C; __asm__(".extern D_001DE99C, 4");
extern s32 D_001DE9A0; __asm__(".extern D_001DE9A0, 4");
extern s32 D_001DE9A8[3] __attribute__((section(".sdata"))); __asm__(".extern D_001DE9A8, 4");
extern s32 D_001DE9B8[3] __attribute__((section(".sdata"))); __asm__(".extern D_001DE9B8, 4");
extern s32 D_001DE9C4; __asm__(".extern D_001DE9C4, 4");
extern s32 D_001DE9C8; __asm__(".extern D_001DE9C8, 4");
extern s32 D_001DE9CC; __asm__(".extern D_001DE9CC, 4");
extern f32 D_001DE9D0; __asm__(".extern D_001DE9D0, 4");
extern f32 D_001DE9D4; __asm__(".extern D_001DE9D4, 4");
extern f32 D_001DE9D8; __asm__(".extern D_001DE9D8, 4");
extern f32 D_001DE9DC; __asm__(".extern D_001DE9DC, 4");
extern f32 D_001DE9E0; __asm__(".extern D_001DE9E0, 4");
extern f32 D_001DE9E4; __asm__(".extern D_001DE9E4, 4");
extern f32 D_001DE9E8; __asm__(".extern D_001DE9E8, 4");
extern f32 D_001DE9EC; __asm__(".extern D_001DE9EC, 4");
extern s32 D_001DE9F0; __asm__(".extern D_001DE9F0, 4");
extern s32 D_001DE9F4; __asm__(".extern D_001DE9F4, 4");
extern s32 D_001DE9F8[3] __attribute__((section(".sdata"))); __asm__(".extern D_001DE9F8, 4");
extern s32 D_001DEA08[3] __attribute__((section(".sdata"))); __asm__(".extern D_001DEA08, 4");
extern s32 D_001DEA14; __asm__(".extern D_001DEA14, 4");

extern void func_003C2F58(void *, s32, void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_00382468(s32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_00448070(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);

/* from an angle and a radius: the point on the circle round the origin, z cleared */
static __inline__ void polar_003CC1A8(V4_003CC1A8 *v, f32 ang, f32 r) {
    v->x = func_0038D098(ang) * r;
    v->y = func_0038D0B0(ang) * r;
    v->z = 0.0f;
}

void func_L16_003CC1A8(u8 *m) {
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
        func_003C2F58(m, i, &pos);
        top = pos;
        pp = &pos;
        top.z = func_003C3D30(pp, 0, 0, 0.5f);
        for (j = 0; j < D_001DE974; j++) {
            s32 k1, k2, k3, col, fl;
            f32 ang, r;

            k1 = (func_00382498(D_001DE9A8[0], D_001DE9B8[0]) * 5 + 2) / 6;
            k2 = (func_00382498(D_001DE9A8[1], D_001DE9B8[1]) * 5 + 2) / 6;
            k3 = (func_00382498(D_001DE9A8[2], D_001DE9B8[2]) * 5 + 2) / 6;
            ang = func_00382538();
            r = func_003824E0(0.0f, D_001DE978);
            polar_003CC1A8(&a, ang, r);
            vec_add_ba(&a, &a, &pos);
            ang = func_00382538();
            r = func_003824E0(0.0f, D_001DE97C);
            polar_003CC1A8(&b, ang, r);
            b.z = -func_003824E0(D_001DE980, D_001DE984);
            b.w = D_001DE98C + func_003824E0(0.0f, D_001DE994);
            vec_add_ab(&b, &b, s + 0x240);
            func_0038CE20(&c, &b, D_001DE988);
            c.w = D_001DE990 + func_003824E0(0.0f, D_001DE994);
            vec_add_ab(&c, &c, s + 0x240);
            col = func_0038DBD8(D_001DE998, D_001DE99C, func_003824E0(0.0f, 1.0f));
            if (func_00382468(D_001DE9C8))
                fl = D_001DE9C4;
            else
                fl = D_001DE9C4 | 0x10000;
            func_L01_00463378(&a, &b, &c, col, D_001DE9A0, k1, k2, k3, fl);
        }
        f = 1.0f - fabs_asm(pos.z - top.z) / D_001DE9D0;
        n = func_L01_00448070(0, D_001DE9CC, f);
        for (k = 0; k < n; k++) {
            s32 k1, k2, k3;
            f32 ang, r;

            k1 = (func_00382498(D_001DE9F8[0], D_001DEA08[0]) * 5 + 2) / 6;
            k2 = (s32)((func_003824E0((f32)D_001DE9F8[1], (f32)D_001DEA08[1]) * 5.0f + 2.0f) / 6.0f * f) + 1;
            k3 = (func_00382498(D_001DE9F8[2], D_001DEA08[2]) * 5 + 2) / 6;
            a = top;
            ang = func_00382538();
            r = func_003C4088(D_001DE9D4, D_001DE9D8, f + func_003824E0(-0.1f, 0.1f));
            polar_003CC1A8(&b, ang, r);
            b.w = func_003C4088(0.0f, D_001DE9E4, f) + func_003824E0(0.0f, D_001DE9EC);
            vec_add_ba(&b, &b, s + 0x240);
            func_0038CE20(&c, &b, D_001DE9DC);
            c.z += D_001DE9E0 * (f32)(k1 + k2 + k3);
            c.w = func_003C4088(0.0f, D_001DE9E8, f) + func_003824E0(0.0f, D_001DE9EC);
            vec_add_ba(&c, &c, s + 0x240);
            func_L01_00463378(&a, &b, &c, D_001DE9F0, D_001DE9F4, k1, k2, k3, D_001DEA14);
        }
    }
}
/* localdecomp:end func_L16_003CC1A8 */
