#include "common.h"

/* NTSC-U counterpart of func_L30_00352208 (src/levels/shared/L30_00352050.c) */
extern s32 D_L30_001DF2C0_003512E0;
#include "vu0.h"
extern s32 D_L30_001DF2C0_003512E0;
extern u8 D_L30_001E2120_003512E0[];
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_0037E208(s32, s32);

/* localdecomp:start func_L30_003512E0 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00352208;
typedef struct { u8 pad[0x18]; f32 x18; s32 x1C; } T_00352208;
typedef struct { u8 pad[0x10]; V4_00352208 pos; u8 pad20[0x68 - 0x20]; T_00352208 *x68; } O_00352208;
typedef struct { u8 pad[0xAA]; s16 xAA; } M_00352208;
typedef struct { u8 pad[0xE0]; V4_00352208 xE0; } H_00352208;
typedef struct {
    u8 pad[0x88]; f32 x88;
    u8 pad8C[0x110 - 0x8C]; V4_00352208 x110;
    u8 pad120[0x1B24 - 0x120]; M_00352208 *x1B24;
    u8 pad1B28[0x25C0 - 0x1B28]; H_00352208 *x25C0;
} G_00352208;

extern G_00352208 D_001A4BE0;
__asm__(".extern D_L30_001DD8A8_003512E0, 4");
__asm__(".extern D_L30_001DD8A4_003512E0, 4");
__asm__(".extern D_L30_001DD8A0_003512E0, 4");
__asm__(".extern D_L30_001DD8E0_003512E0, 4");
__asm__(".extern D_L30_001DD8E4_003512E0, 4");
__asm__(".extern D_L30_001DDA74, 4");
__asm__(".extern D_L30_001DDA70, 4");
__asm__(".extern D_L30_001DDA20_003512E0, 4");
__asm__(".extern D_L30_001DDA24_003512E0, 4");
__asm__(".extern D_L30_001DDA60, 4");
__asm__(".extern D_L30_001DD9B4_003512E0, 1");
__asm__(".extern D_L30_001DD9B5, 1");
__asm__(".extern D_L30_001DD9B6, 1");
__asm__(".extern D_L30_001DD9B7, 1");
__asm__(".extern D_L30_001DD9B9, 1");
__asm__(".extern D_L30_001DD9C4_003512E0, 4");
__asm__(".extern D_L30_001DD9D8_003512E0, 4");
__asm__(".extern D_L30_001DD9DC_003512E0, 4");
__asm__(".extern D_L30_001DDA30_003512E0, 4");
__asm__(".extern D_L30_001DD9D4_003512E0, 4");
__asm__(".extern D_L30_001DD9BC_003512E0, 4");
__asm__(".extern D_L30_001DD9C0_003512E0, 4");
__asm__(".extern D_L30_001DD9CC_003512E0, 4");
__asm__(".extern D_L30_001DD9D0_003512E0, 4");
__asm__(".extern D_L30_001DD9C8_003512E0, 4");
__asm__(".extern D_L30_001DDA34_003512E0, 4");
__asm__(".extern D_L30_001DDA10_003512E0, 4");
__asm__(".extern D_L30_001DDA04_003512E0, 4");
__asm__(".extern D_L30_001DDA0C_003512E0, 4");
__asm__(".extern D_L30_001DDA14_003512E0, 4");
__asm__(".extern D_L30_001DDA18_003512E0, 4");
__asm__(".extern D_L30_001DDA08_003512E0, 4");
__asm__(".extern D_L30_001DDA38, 4");
__asm__(".extern D_L30_001DDA28_003512E0, 4");
__asm__(".extern D_L30_001DD9E8_003512E0, 4");
__asm__(".extern D_L30_001DD9E0_003512E0, 4");
__asm__(".extern D_L30_001DD9E4_003512E0, 4");
__asm__(".extern D_L30_001DDA2C_003512E0, 4");
__asm__(".extern D_L30_001DD9F8_003512E0, 4");
__asm__(".extern D_L30_001DD9F4_003512E0, 4");
__asm__(".extern D_L30_001DDA3C, 4");
__asm__(".extern D_L30_001DD9FC_003512E0, 4");
__asm__(".extern D_L30_001DD9EC_003512E0, 4");
__asm__(".extern D_L30_001DD9F0_003512E0, 4");
__asm__(".extern D_L30_001DDA6C, 4");
__asm__(".extern D_L30_001DDA00_003512E0, 4");
__asm__(".extern D_L30_001DDA64_003512E0, 4");
__asm__(".extern D_L30_001DDA68, 4");
extern s32 D_L30_001DD8A8_003512E0;
extern f32 D_L30_001DD8A4_003512E0;
extern f32 D_L30_001DD8A0_003512E0;
extern f32 D_L30_001DD8E0_003512E0;
extern f32 D_L30_001DD8E4_003512E0;
extern f32 D_L30_001DDA74;
extern f32 D_L30_001DDA70;
extern f32 D_L30_001DDA20_003512E0;
extern f32 D_L30_001DDA24_003512E0;
extern s32 D_L30_001DDA60;
extern u8 D_L30_001DD9B4_003512E0;
extern u8 D_L30_001DD9B5;
extern u8 D_L30_001DD9B6;
extern u8 D_L30_001DD9B7;
extern u8 D_L30_001DD9B9;
extern f32 D_L30_001DD9C4_003512E0;
extern f32 D_L30_001DD9D8_003512E0;
extern f32 D_L30_001DD9DC_003512E0;
extern s32 D_L30_001DDA30_003512E0;
extern s32 D_L30_001DD9D4_003512E0;
extern f32 D_L30_001DD9BC_003512E0;
extern f32 D_L30_001DD9C0_003512E0;
extern s32 D_L30_001DD9CC_003512E0;
extern s32 D_L30_001DD9D0_003512E0;
extern f32 D_L30_001DD9C8_003512E0;
extern s32 D_L30_001DDA34_003512E0;
extern s32 D_L30_001DDA10_003512E0;
extern f32 D_L30_001DDA04_003512E0;
extern f32 D_L30_001DDA0C_003512E0;
extern s32 D_L30_001DDA14_003512E0;
extern s32 D_L30_001DDA18_003512E0;
extern f32 D_L30_001DDA08_003512E0;
extern s32 D_L30_001DDA38;
extern f32 D_L30_001DDA28_003512E0;
extern s32 D_L30_001DD9E8_003512E0;
extern f32 D_L30_001DD9E0_003512E0;
extern f32 D_L30_001DD9E4_003512E0;
extern f32 D_L30_001DDA2C_003512E0;
extern f32 D_L30_001DD9F8_003512E0;
extern f32 D_L30_001DD9F4_003512E0;
extern s32 D_L30_001DDA3C;
extern s32 D_L30_001DD9FC_003512E0;
extern f32 D_L30_001DD9EC_003512E0;
extern f32 D_L30_001DD9F0_003512E0;
extern s32 D_L30_001DDA6C;
extern s32 D_L30_001DDA00_003512E0;
extern s32 D_L30_001DDA64_003512E0;
extern s32 D_L30_001DDA68;
extern f32 D_L30_001E2240_003512E0[];
extern V4_00352208 D_L30_001E2110_003512E0;
extern V4_00352208 D_L30_001E9020_003512E0[];
extern u8 D_L30_001D66B0_003512E0[] __attribute__((section(".sdata")));
extern u8 *D_L30_0021F098_003512E0[];

extern f32 func_L30_004E2A88(void);
extern void func_003BDA38(void *, s32, void *);
extern f32 func_0037E250(f32, f32);
extern f32 func_00389410(f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_00388830(void *, void *, f32);
extern void func_L30_003B7390(void *, void *);
extern void func_L30_0034BC88(u8 *, void *, s32, s32, s32, s32, f32, f32);
extern s32 func_L01_003F9498(void *, s32, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_0046D1D0(void *, void *, s32, s32, f32, f32, s32, s32, s32, s32, s32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_0037E1D8(s32);
extern f32 func_L01_00440918(f32, f32);
extern void func_00389158(void *, void *, void *, f32);
extern void func_L30_00350E00(void *, void *, void *);

void func_L30_003512E0(O_00352208 *self) {
    T_00352208 *t = self->x68;
    f32 frac;
    f32 ang;
    f32 rad;
    f32 r;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    V4_00352208 dir;
    V4_00352208 pos;
    V4_00352208 v30;
    V4_00352208 v40;
    V4_00352208 v50;
    V4_00352208 v60;
    V4_00352208 v70;
    V4_00352208 v80;
    V4_00352208 v90;
    V4_00352208 vA0;
    V4_00352208 vB0;
    V4_00352208 vC0;
    V4_00352208 vD0;
    V4_00352208 vE0;
    V4_00352208 vF0;
    V4_00352208 v100;
    V4_00352208 v110;

    frac = (f32)t->x1C / (f32)D_L30_001DD8A8_003512E0;
    if (frac > 1.0f) {
        frac = 1.0f;
    }
    if (D_001A4BE0.x1B24 == 0 || D_001A4BE0.x1B24->xAA != 0x1C7E) {
        return;
    }
    t->x18 = func_L30_004E2A88();
    func_003BDA38(D_001A4BE0.x1B24, 1, &self->pos);
    ang = func_00389380(func_00389410(func_0037E250(-D_L30_001DD8A4_003512E0, D_L30_001DD8A4_003512E0)), t->x18);
    rad = func_0037E250(D_L30_001DD8E4_003512E0, D_L30_001DD8E0_003512E0);
    dir.x = func_00388960(ang) * rad;
    dir.z = func_00388978(ang) * rad;
    pos = self->pos;
    pos.y = 100.0f;
    dir.y = 0.0f;
    if (D_001A4BE0.x88 < D_L30_001E2240_003512E0[2] - 1.0f) {
        pos.z += D_L30_001DDA74;
    }
    func_00388830(&v30, &dir, frac * 7.0f);
    v40 = pos;
    v40.z -= D_L30_001DDA70;
    func_00388830(&v50, &dir, func_0037E250(D_L30_001DDA20_003512E0, D_L30_001DDA24_003512E0) * 0.0166666675f);
    v60 = D_001A4BE0.x110;
    v60.z = 0.0f;
    vec_add_ab(&v50, &v50, &v60);
    if (D_L30_001DF2C0_003512E0 % D_L30_001DDA60 == 0 || t->x1C == 1) {
        func_L30_003B7390(&self->pos, &v50);
        func_L30_0034BC88((u8 *)self, &dir, 0, -1, (s32)&v40, 0, D_L30_001DD8A0_003512E0, 2.0f);
    }
    if (D_L30_001DD9B9 && func_L01_003F9498(&v30, 0, D_001A4BE0.x25C0, 1.25f)) {
        u8 *p;
        func_003886E8(&v80, &D_L30_001E2110_003512E0, 0.05f);
        func_00388830(&v70, &D_L30_001E9020_003512E0[2], 0.05f);
        vec_add_ba(&v70, &v70, &D_L30_001E9020_003512E0[0]);
        p = func_L01_0046D1D0(&v70, D_L30_001D66B0_003512E0, 0x4F5050FF, 0x102434EE,
                              func_0037E250(0.4f, 0.7f) * 210000.0f, 1.5f, func_0037E208(10, 20), 1, -1, -1, 1);
        if (p) {
            p[2] = D_L30_0021F098_003512E0[91][0];
        }
    }
    v90 = D_001A4BE0.x25C0->xE0;
    func_003886E8(&v90, &v90, D_L30_001DD9C4_003512E0);
    v70 = pos;
    func_00388830(&v80, &dir, func_0037E250(D_L30_001DD9D8_003512E0, D_L30_001DD9DC_003512E0) * 0.0166666675f);
    vec_sub_ab(&v80, &v80, &v90);
    vec_add_ab(&v80, &v80, &v60);
    for (i = 0; i < D_L30_001DDA30_003512E0; i++) {
        if (D_L30_001DD9B4_003512E0) {
            func_L01_0046C468(&v70, &v80, D_L30_001DD9D4_003512E0, 0x808080, 0x1E,
                              D_L30_001DD9CC_003512E0, D_L30_001DD9D0_003512E0, 0,
                              D_L30_001DD9BC_003512E0 * 210000.0f, D_L30_001DD9C0_003512E0 * 210000.0f, D_L30_001DD9C8_003512E0);
        }
    }
    vA0 = pos;
    vB0 = v80;
    for (j = 0; j < D_L30_001DDA34_003512E0; j++) {
        if (D_L30_001DD9B5) {
            u8 *p;
            p = func_L01_0046C468(&vA0, &vB0, D_L30_001DDA10_003512E0, 0x800000, 0x1E,
                                  D_L30_001DDA14_003512E0, D_L30_001DDA18_003512E0, 0,
                                  D_L30_001DDA04_003512E0 * 210000.0f, D_L30_001DDA0C_003512E0 * 210000.0f, D_L30_001DDA08_003512E0);
            if (p) {
                p[2] = D_L30_0021F098_003512E0[23][0];
                p[3] = func_0037E1D8(2) ? 0x44 : 0x48;
            }
        }
    }
    vC0 = dir;
    vD0 = v50;
    for (k = 0; k < D_L30_001DDA38; k++) {
        vC0.x = func_00388960(t->x18) * rad;
        vC0.z = func_00388978(t->x18) * rad;
        vC0.y = 0.0f;
        func_00388830(&vD0, &vC0, func_0037E250(D_L30_001DDA20_003512E0 * D_L30_001DDA28_003512E0, D_L30_001DDA24_003512E0 * D_L30_001DDA28_003512E0) * 0.0166666675f);
        func_00389158(&vD0, &vD0, D_L30_001E2120_003512E0, func_0037E250(-0.14835298f, 0.04363323f));
        if (D_L30_001DD9B6) {
            s32 life = func_0037E1D8(0x1E);
            f32 a = D_L30_001DD9E0_003512E0 * 210000.0f;
            f32 b = D_L30_001DD9E4_003512E0 * 210000.0f;
            u8 *p = func_L01_0046C468(&pos, &vD0, D_L30_001DD9E8_003512E0, 0x808080, life, 0x7F, 0, 0, a, b,
                                  func_L01_00440918(-0.0013888889f, 0.0f));
            if (p) {
                if (func_0037E1D8(4)) {
                    p[2] = D_L30_0021F098_003512E0[91][4];
                    p[3] = func_0037E1D8(4) ? 0x44 : 0x48;
                } else {
                    p[2] = D_L30_0021F098_003512E0[91][0];
                    p[3] = 0x48;
                }
            }
        }
    }
    vF0 = dir;
    v100 = v50;
    vF0.x = func_00388960(t->x18) * rad;
    vF0.z = func_00388978(t->x18) * rad;
    vF0.y = 0.0f;
    func_00388830(&v100, &vF0, func_0037E250(D_L30_001DDA20_003512E0 * D_L30_001DDA2C_003512E0, D_L30_001DDA24_003512E0 * D_L30_001DDA2C_003512E0) * 0.0166666675f);
    func_003886E8(&v110, D_L30_001E2120_003512E0, D_L30_001DD9F8_003512E0);
    vec_add_ba(&v100, &v110, &v100);
    func_003886E8(&v110, D_L30_001E2120_003512E0, D_L30_001DD9F4_003512E0);
    vec_add_ab(&vE0, &v110, &pos);
    for (m = 0; m < D_L30_001DDA3C; m++) {
        if (D_L30_001DD9B7) {
            u8 *p = func_L01_0046C468(&vE0, &v100, D_L30_001DD9FC_003512E0, D_L30_001DDA6C, 0x1E, D_L30_001DDA00_003512E0, D_L30_001DDA18_003512E0, 0,
                                  D_L30_001DD9EC_003512E0 * 210000.0f, D_L30_001DD9F0_003512E0 * 210000.0f, func_L01_00440918(-0.0013888889f, 0.0f));
            if (p) {
                p[3] = func_0037E1D8(8) ? 0x48 : 0x44;
                p[2] = D_L30_0021F098_003512E0[D_L30_001DDA64_003512E0][D_L30_001DDA68];
            }
        }
    }
    func_L30_00350E00(self, &pos, &vD0);
    func_L30_00351128((s32)self, &pos, &vD0);
}
/* localdecomp:end func_L30_003512E0 */
