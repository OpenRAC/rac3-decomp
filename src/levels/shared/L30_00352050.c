#include "common.h"

/* declared by functions of L30_0034EB98.c, which this file was cut from */
extern s32 D_L30_001DF2C0;

/* localdecomp:start func_L30_00352050 */
#include "vu0.h"
__asm__(".extern D_L30_001DF2C0, 16");
__asm__(".extern D_L30_001DDA18, 4");
__asm__(".extern D_L30_001DDA1C, 4");
extern s32 D_L30_001DF2C0;
extern f32 D_L30_001DDA18;
extern f32 D_L30_001DDA1C;
extern u8 D_L30_001E2120[];
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_0038CE20(void *, void *, f32);
extern void func_00382760(void *, f32, f32, f32);
extern u32 func_L01_00448D88(u32, s32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_00465738(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);

void func_L30_00352050(s32 a0, void *a1, void *a2) {
    vu0_v4 pos;
    vu0_v4 v;
    f32 s;
    f32 a;
    f32 b;
    u32 c1;
    u32 c2;

    if (D_L30_001DF2C0 % 10 != 0) {
        return;
    }
    s = D_L30_001DDA18;
    a = func_003824E0(0.261799395f, 1.04719758f);
    b = func_00382538();
    func_0038CE20(&v, D_L30_001E2120, D_L30_001DDA1C);
    vec_add_ab(&pos, &v, &pos);
    func_00382760(&pos, func_003824E0(7.0f, 10.5f) * 0.0200000014f * 0.7f, b, a);
    func_0038CE20(&v, D_L30_001E2120, D_L30_001DDA1C);
    vec_add_ba(&pos, &v, &pos);
    vec_add_ba(&pos, &pos, a2);
    c1 = func_L01_00448D88(0x4F007FFF, 0);
    c2 = func_L01_00448D88(0x1F00007F, 0);
    func_L01_00465738(a1, &pos, c1, c2, func_00382498(0x21, 0x36), 1, -1, -1, 0, s * 40000.0f);
}
/* localdecomp:end func_L30_00352050 */

/* localdecomp:start func_L30_00352208 */
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
__asm__(".extern D_L30_001DD868, 4");
__asm__(".extern D_L30_001DD864, 4");
__asm__(".extern D_L30_001DD860, 4");
__asm__(".extern D_L30_001DD8A0, 4");
__asm__(".extern D_L30_001DD8A4, 4");
__asm__(".extern D_L30_001DDA34, 4");
__asm__(".extern D_L30_001DDA30, 4");
__asm__(".extern D_L30_001DD9E0, 4");
__asm__(".extern D_L30_001DD9E4, 4");
__asm__(".extern D_L30_001DDA20, 4");
__asm__(".extern D_L30_001DD974, 1");
__asm__(".extern D_L30_001DD975, 1");
__asm__(".extern D_L30_001DD976, 1");
__asm__(".extern D_L30_001DD977, 1");
__asm__(".extern D_L30_001DD979, 1");
__asm__(".extern D_L30_001DD984, 4");
__asm__(".extern D_L30_001DD998, 4");
__asm__(".extern D_L30_001DD99C, 4");
__asm__(".extern D_L30_001DD9F0, 4");
__asm__(".extern D_L30_001DD994, 4");
__asm__(".extern D_L30_001DD97C, 4");
__asm__(".extern D_L30_001DD980, 4");
__asm__(".extern D_L30_001DD98C, 4");
__asm__(".extern D_L30_001DD990, 4");
__asm__(".extern D_L30_001DD988, 4");
__asm__(".extern D_L30_001DD9F4, 4");
__asm__(".extern D_L30_001DD9D0, 4");
__asm__(".extern D_L30_001DD9C4, 4");
__asm__(".extern D_L30_001DD9CC, 4");
__asm__(".extern D_L30_001DD9D4, 4");
__asm__(".extern D_L30_001DD9D8, 4");
__asm__(".extern D_L30_001DD9C8, 4");
__asm__(".extern D_L30_001DD9F8, 4");
__asm__(".extern D_L30_001DD9E8, 4");
__asm__(".extern D_L30_001DD9A8, 4");
__asm__(".extern D_L30_001DD9A0, 4");
__asm__(".extern D_L30_001DD9A4, 4");
__asm__(".extern D_L30_001DD9EC, 4");
__asm__(".extern D_L30_001DD9B8, 4");
__asm__(".extern D_L30_001DD9B4, 4");
__asm__(".extern D_L30_001DD9FC, 4");
__asm__(".extern D_L30_001DD9BC, 4");
__asm__(".extern D_L30_001DD9AC, 4");
__asm__(".extern D_L30_001DD9B0, 4");
__asm__(".extern D_L30_001DDA2C, 4");
__asm__(".extern D_L30_001DD9C0, 4");
__asm__(".extern D_L30_001DDA24, 4");
__asm__(".extern D_L30_001DDA28, 4");
extern s32 D_L30_001DD868;
extern f32 D_L30_001DD864;
extern f32 D_L30_001DD860;
extern f32 D_L30_001DD8A0;
extern f32 D_L30_001DD8A4;
extern f32 D_L30_001DDA34;
extern f32 D_L30_001DDA30;
extern f32 D_L30_001DD9E0;
extern f32 D_L30_001DD9E4;
extern s32 D_L30_001DDA20;
extern u8 D_L30_001DD974;
extern u8 D_L30_001DD975;
extern u8 D_L30_001DD976;
extern u8 D_L30_001DD977;
extern u8 D_L30_001DD979;
extern f32 D_L30_001DD984;
extern f32 D_L30_001DD998;
extern f32 D_L30_001DD99C;
extern s32 D_L30_001DD9F0;
extern s32 D_L30_001DD994;
extern f32 D_L30_001DD97C;
extern f32 D_L30_001DD980;
extern s32 D_L30_001DD98C;
extern s32 D_L30_001DD990;
extern f32 D_L30_001DD988;
extern s32 D_L30_001DD9F4;
extern s32 D_L30_001DD9D0;
extern f32 D_L30_001DD9C4;
extern f32 D_L30_001DD9CC;
extern s32 D_L30_001DD9D4;
extern s32 D_L30_001DD9D8;
extern f32 D_L30_001DD9C8;
extern s32 D_L30_001DD9F8;
extern f32 D_L30_001DD9E8;
extern s32 D_L30_001DD9A8;
extern f32 D_L30_001DD9A0;
extern f32 D_L30_001DD9A4;
extern f32 D_L30_001DD9EC;
extern f32 D_L30_001DD9B8;
extern f32 D_L30_001DD9B4;
extern s32 D_L30_001DD9FC;
extern s32 D_L30_001DD9BC;
extern f32 D_L30_001DD9AC;
extern f32 D_L30_001DD9B0;
extern s32 D_L30_001DDA2C;
extern s32 D_L30_001DD9C0;
extern s32 D_L30_001DDA24;
extern s32 D_L30_001DDA28;
extern f32 D_L30_001E2240[];
extern V4_00352208 D_L30_001E2110;
extern V4_00352208 D_L30_001E9020[];
extern u8 D_L30_001D66B0[] __attribute__((section(".sdata")));
extern u8 *D_L30_0021F098[];

extern f32 func_L30_004E6988(void);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L30_003B92B0(void *, void *);
extern void func_L30_0034CB68(u8 *, void *, s32, s32, s32, s32, f32, f32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004708C8(void *, void *, s32, s32, f32, f32, s32, s32, s32, s32, s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_00382468(s32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_L30_00351D10(void *, void *, void *);

void func_L30_00352208(O_00352208 *self) {
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

    frac = (f32)t->x1C / (f32)D_L30_001DD868;
    if (frac > 1.0f) {
        frac = 1.0f;
    }
    if (D_001A4BE0.x1B24 == 0 || D_001A4BE0.x1B24->xAA != 0x1C7E) {
        return;
    }
    t->x18 = func_L30_004E6988();
    func_003C2F58(D_001A4BE0.x1B24, 1, &self->pos);
    ang = func_0038DAB8(func_0038DB48(func_003824E0(-D_L30_001DD864, D_L30_001DD864)), t->x18);
    rad = func_003824E0(D_L30_001DD8A4, D_L30_001DD8A0);
    dir.x = func_0038D098(ang) * rad;
    dir.z = func_0038D0B0(ang) * rad;
    pos = self->pos;
    pos.y = 100.0f;
    dir.y = 0.0f;
    if (D_001A4BE0.x88 < D_L30_001E2240[2] - 1.0f) {
        pos.z += D_L30_001DDA34;
    }
    func_0038CF68(&v30, &dir, frac * 7.0f);
    v40 = pos;
    v40.z -= D_L30_001DDA30;
    func_0038CF68(&v50, &dir, func_003824E0(D_L30_001DD9E0, D_L30_001DD9E4) * 0.0200000014f);
    v60 = D_001A4BE0.x110;
    v60.z = 0.0f;
    vec_add_ab(&v50, &v50, &v60);
    if (D_L30_001DF2C0 % D_L30_001DDA20 == 0 || t->x1C == 1) {
        func_L30_003B92B0(&self->pos, &v50);
        func_L30_0034CB68((u8 *)self, &dir, 0, -1, (s32)&v40, 0, D_L30_001DD860, 2.0f);
    }
    if (D_L30_001DD979 && func_L01_003FB640(&v30, 0, D_001A4BE0.x25C0, 1.25f)) {
        u8 *p;
        func_0038CE20(&v80, &D_L30_001E2110, 0.05f);
        func_0038CF68(&v70, &D_L30_001E9020[2], 0.05f);
        vec_add_ba(&v70, &v70, &D_L30_001E9020[0]);
        p = func_L01_004708C8(&v70, D_L30_001D66B0, 0x4F5050FF, 0x102434EE,
                              func_003824E0(0.4f, 0.7f) * 210000.0f, 1.5f, func_00382498(8, 0x11), 1, -1, -1, 1);
        if (p) {
            p[2] = D_L30_0021F098[91][0];
        }
    }
    v90 = D_001A4BE0.x25C0->xE0;
    func_0038CE20(&v90, &v90, D_L30_001DD984);
    v70 = pos;
    func_0038CF68(&v80, &dir, func_003824E0(D_L30_001DD998, D_L30_001DD99C) * 0.0200000014f);
    vec_sub_ab(&v80, &v80, &v90);
    vec_add_ab(&v80, &v80, &v60);
    for (i = 0; i < D_L30_001DD9F0; i++) {
        if (D_L30_001DD974) {
            func_L01_0046FB40(&v70, &v80, (D_L30_001DD994 * 5 + 2) / 6, 0x808080, 0x1E,
                              D_L30_001DD98C, D_L30_001DD990, 0,
                              D_L30_001DD97C * 210000.0f, D_L30_001DD980 * 210000.0f, D_L30_001DD988);
        }
    }
    vA0 = pos;
    vB0 = v80;
    for (j = 0; j < D_L30_001DD9F4; j++) {
        if (D_L30_001DD975) {
            u8 *p;
            p = func_L01_0046FB40(&vA0, &vB0, (D_L30_001DD9D0 * 5 + 2) / 6, 0x800000, 0x1E,
                                  D_L30_001DD9D4, D_L30_001DD9D8, 0,
                                  D_L30_001DD9C4 * 210000.0f, D_L30_001DD9CC * 210000.0f, D_L30_001DD9C8);
            if (p) {
                p[2] = D_L30_0021F098[23][0];
                p[3] = func_00382468(2) ? 0x44 : 0x48;
            }
        }
    }
    vC0 = dir;
    vD0 = v50;
    for (k = 0; k < D_L30_001DD9F8; k++) {
        vC0.x = func_0038D098(t->x18) * rad;
        vC0.z = func_0038D0B0(t->x18) * rad;
        vC0.y = 0.0f;
        func_0038CF68(&vD0, &vC0, func_003824E0(D_L30_001DD9E0 * D_L30_001DD9E8, D_L30_001DD9E4 * D_L30_001DD9E8) * 0.0200000014f);
        func_0038D890(&vD0, &vD0, D_L30_001E2120, func_003824E0(-0.14835298f, 0.04363323f));
        if (D_L30_001DD976) {
            s32 n = (D_L30_001DD9A8 * 5 + 2) / 6;
            s32 life = func_00382468(0x1E);
            f32 a = D_L30_001DD9A0 * 210000.0f;
            f32 b = D_L30_001DD9A4 * 210000.0f;
            u8 *p = func_L01_0046FB40(&pos, &vD0, n, 0x808080, life, 0x7F, 0, 0, a, b,
                                  func_L01_00443A18(-0.002f, 0.0f));
            if (p) {
                if (func_00382468(4)) {
                    p[2] = D_L30_0021F098[91][4];
                    p[3] = func_00382468(4) ? 0x44 : 0x48;
                } else {
                    p[2] = D_L30_0021F098[91][0];
                    p[3] = 0x48;
                }
            }
        }
    }
    vF0 = dir;
    v100 = v50;
    vF0.x = func_0038D098(t->x18) * rad;
    vF0.z = func_0038D0B0(t->x18) * rad;
    vF0.y = 0.0f;
    func_0038CF68(&v100, &vF0, func_003824E0(D_L30_001DD9E0 * D_L30_001DD9EC, D_L30_001DD9E4 * D_L30_001DD9EC) * 0.0200000014f);
    func_0038CE20(&v110, D_L30_001E2120, D_L30_001DD9B8);
    vec_add_ba(&v100, &v110, &v100);
    func_0038CE20(&v110, D_L30_001E2120, D_L30_001DD9B4);
    vec_add_ab(&vE0, &v110, &pos);
    for (m = 0; m < D_L30_001DD9FC; m++) {
        if (D_L30_001DD977) {
            u8 *p = func_L01_0046FB40(&vE0, &v100, (D_L30_001DD9BC * 5 + 2) / 6, D_L30_001DDA2C, 0x1E, D_L30_001DD9C0, D_L30_001DD9D8, 0,
                                  D_L30_001DD9AC * 210000.0f, D_L30_001DD9B0 * 210000.0f, func_L01_00443A18(-0.002f, 0.0f));
            if (p) {
                p[3] = func_00382468(8) ? 0x48 : 0x44;
                p[2] = D_L30_0021F098[D_L30_001DDA24][D_L30_001DDA28];
            }
        }
    }
    func_L30_00351D10(self, &pos, &vD0);
    func_L30_00352050((s32)self, &pos, &vD0);
}
/* localdecomp:end func_L30_00352208 */
