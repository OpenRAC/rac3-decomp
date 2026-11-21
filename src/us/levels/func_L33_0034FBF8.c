#include "common.h"

/* NTSC-U counterpart of func_L33_00350818 (src/levels/33_vidcomic_2/L33_00350818.c) */
#include "vu0.h"

/* localdecomp:start func_L33_0034FBF8 */
typedef struct {
    u8 pad0[0x14];
    u8 f14;
    u8 pad15[0x3B];
    vu0_v4 v50;
    vu0_v4 v60;
    u8 pad70[8];
    s32 f78;
    u8 pad7C[4];
    vu0_v4 v80;
    f32 f90;
    s32 f94;
    s32 f98;
    s32 f9C;
    s32 fA0;
    u8 padA4[8];
    s32 fAC;
    s32 fB0;
    f32 fB4;
    f32 fB8;
    f32 fBC;
    f32 fC0;
} Vars_00350818;

typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x30];
    u16 f44;
} Ref_00350818;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[2];
    u8 f23;
    Ref_00350818 *f24;
    u8 pad28[0xC];
    u16 f34;
    u8 pad36[0xC];
    u8 f42;
    u8 f43;
    u8 pad44[4];
    f32 f48;
    u8 pad4C[0x14];
    u8 flags;
    u8 pad61[7];
    Vars_00350818 *vars;
    u8 pad6C[0x2A];
    u16 f96;
    s32 f98;
    u8 pad9C[0xE];
    s16 oclass;
    u8 padAC[0x4C];
    f32 fF8;
} Moby_00350818;

typedef struct {
    u8 pad0[0x80];
    vu0_v4 pos;
    u8 pad90[0x25C0 - 0x90];
    Moby_00350818 *p25C0;
} Hero_00350818;

typedef struct {
    vu0_v4 pos;
    u8 pad10[0x2540 - 0x10];
    Moby_00350818 *p2540;
} HeroPos_00350818;

extern Hero_00350818 D_001A4BE0;
extern HeroPos_00350818 D_001A4C60;
extern u8 *D_L33_001DFC80;
extern u8 *D_L33_001DFB9C;
extern u8 *D_L33_001DFC80_2;
__asm__(".extern D_L33_001DFC80_2, 4");
extern u8 *D_L33_001DFB9C_2;
__asm__(".extern D_L33_001DFB9C_2, 4");
extern u8 D_L33_001E18D8[] __attribute__((section(".sdata")));
extern u8 D_L33_001E1918[] __attribute__((section(".sdata")));
extern u8 D_L33_001E1938[] __attribute__((section(".sdata")));
extern vu0_v4 D_L33_001E96A0;

extern f32 D_L33_001DD8C8_0034FBF8[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DD8C8_0034FBF8, 4");
extern f32 D_L33_001DD8E8_0034FBF8[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DD8E8_0034FBF8, 4");
extern f32 D_L33_001DD8F8[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DD8F8, 4");
extern f32 D_L33_001DD908[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DD908, 4");
extern f32 D_L33_001DD918[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DD918, 4");
extern f32 D_L33_001DD940[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DD940, 4");
extern f32 D_L33_001DD978_0034FBF8[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DD978_0034FBF8, 4");
extern f32 D_L33_001DD988_0034FBF8[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DD988_0034FBF8, 4");
extern f32 D_L33_001DD9D8[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DD9D8, 4");
extern f32 D_L33_001DDA20[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DDA20, 4");
extern f32 D_L33_001DDA50_0034FBF8[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DDA50_0034FBF8, 4");
extern f32 D_L33_001DDA90_0034FBF8[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DDA90_0034FBF8, 4");
extern f32 D_L33_001DDB00_0034FBF8[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DDB00_0034FBF8, 4");
extern s32 D_L33_001DDB10[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DDB10, 4");
extern f32 D_L33_001DDB38_0034FBF8[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DDB38_0034FBF8, 4");

extern u8 D_L33_001DD01C;
__asm__(".extern D_L33_001DD01C, 1");
extern s32 D_L33_001DD89C;
__asm__(".extern D_L33_001DD89C, 4");
extern f32 D_L33_001DD924;
__asm__(".extern D_L33_001DD924, 4");
extern f32 D_L33_001DD9A8_0034FBF8;
__asm__(".extern D_L33_001DD9A8_0034FBF8, 4");
extern f32 D_L33_001DD9B0_0034FBF8;
__asm__(".extern D_L33_001DD9B0_0034FBF8, 4");
extern f32 D_L33_001DD9B4;
__asm__(".extern D_L33_001DD9B4, 4");
extern f32 D_L33_001DD9B8;
__asm__(".extern D_L33_001DD9B8, 4");
extern f32 D_L33_001DD9BC;
__asm__(".extern D_L33_001DD9BC, 4");
extern f32 D_L33_001DD9C0_0034FBF8;
__asm__(".extern D_L33_001DD9C0_0034FBF8, 4");
extern f32 D_L33_001DD9E4;
__asm__(".extern D_L33_001DD9E4, 4");
extern s32 D_L33_001DD9E8;
__asm__(".extern D_L33_001DD9E8, 4");
extern f32 D_L33_001DDA7C_0034FBF8;
__asm__(".extern D_L33_001DDA7C_0034FBF8, 4");
extern f32 D_L33_001DDAB4;
__asm__(".extern D_L33_001DDAB4, 4");
extern f32 D_L33_001DDAB8;
__asm__(".extern D_L33_001DDAB8, 4");
extern f32 D_L33_001DDABC;
__asm__(".extern D_L33_001DDABC, 4");
extern f32 D_L33_001DDAC0_0034FBF8;
__asm__(".extern D_L33_001DDAC0_0034FBF8, 4");
extern f32 D_L33_001DDAC8;
__asm__(".extern D_L33_001DDAC8, 4");
extern f32 D_L33_001DDAEC_0034FBF8;
__asm__(".extern D_L33_001DDAEC_0034FBF8, 4");
extern f32 D_L33_001DDB2C;
__asm__(".extern D_L33_001DDB2C, 4");
extern f32 D_L33_001DDB30;
__asm__(".extern D_L33_001DDB30, 4");
extern f32 D_L33_001DDB78_0034FBF8;
__asm__(".extern D_L33_001DDB78_0034FBF8, 4");
extern f32 D_L33_001DDB80;
__asm__(".extern D_L33_001DDB80, 4");
extern s32 D_L33_001DDB88_0034FBF8;
__asm__(".extern D_L33_001DDB88_0034FBF8, 4");
extern f32 D_L33_001DDBB0;
__asm__(".extern D_L33_001DDBB0, 4");
extern f32 D_L33_001DDBB4_0034FBF8;
__asm__(".extern D_L33_001DDBB4_0034FBF8, 4");
extern s32 D_L33_001DDCD0;
__asm__(".extern D_L33_001DDCD0, 4");

extern s32 func_L31_00345C88(void *, f32, f32, f32);
extern void func_L31_00346000(void *, void *, f32, f32, f32, f32, f32);
extern s32 func_L30_0034C308(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L30_0034B9C8(void *, void *);
extern void func_L30_0034BC88(void *, void *, s32, s32, s32, s32, f32, f32);
extern void func_L30_0034BEE0(f32, f32 *, f32 *, f32 *, f32 *);
extern s32 func_L30_0034C9F8_0034FBF8(void *, f32);
extern s32 func_L32_003489D0(void *, void *, f32, f32, f32, f32, f32, f32, f32);
extern void func_L03_0034A688(void *, void *);
extern s32 func_L33_00351B28(s32, s32, s32);
extern f32 func_L33_00351B88(void *);
extern void func_L33_00351CD0(void *);
extern void func_L33_00351DD0(void *);
extern s32 func_L33_003521D0(void *, s32, s32, s32);
extern void func_L33_00352298(void *, s32);
extern void func_L33_003525C0(void *);
s32 func_L33_003527C8(u8 *);
extern void func_L33_00352AE8(void *, void *, s32, s32, s32, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern f32 func_L01_00436500(void *);
extern void func_L01_00445758(void *, void *, s32, f32, f32, f32, f32);
extern void func_L01_00452F40(void *, s32);
extern s32 func_L01_00452F60(void *);
extern void func_L01_004A6DF8(void *, s32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_00388398(void *);
extern f32 func_00388770(void *);
extern f32 func_003887C8(void *, void *);
extern f32 func_00388960(f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389410(f32);
extern void func_003BD360(void *);
extern s32 func_0037E0F0(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_003BEB48(f32, f32, f32);
extern void func_003BEB58(void *, void *, void *, f32);
extern s32 func_0039FE80(s32, s32, void *);

void func_L33_0034FBF8(Moby_00350818 *p) {
    vu0_v4 grav;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    f32 top;
    Vars_00350818 *s = p->vars;
    s32 idx = 0x1761 - p->oclass;
    s32 facing = func_L31_00345C88(p, D_L33_001DD9BC, D_L33_001DD9C0_0034FBF8, D_L33_001DD9B8) != 0;
    s32 inZ;
    s32 inX;
    s32 seen;
    s32 left;
    s32 snd;
    s32 ret;
    s32 n;
    f32 frame;
    f32 a;
    f32 sp;
    f32 m;
    f32 d;
    f32 r;
    f32 q;
    f32 k;
    f32 c;
    f32 z;
    f32 w;
    f32 x;
    f32 y;
    Moby_00350818 *h;

    inZ = 0;
    if (D_001A4BE0.pos.z < D_L33_001DD924 + p->pos.z) {
        if (p->pos.z - D_L33_001DD924 < D_001A4BE0.pos.z) {
            inZ = 1;
        }
    }
    inX = fabs_asm(D_001A4BE0.pos.x - p->pos.x) < D_L33_001DD918[idx];
    seen = 0;
    if (s->fA0 == -1 || func_0037E0F0(&D_001A4BE0.pos, s->fA0, 0) != 0) {
        seen = s->fB0 == 0;
    }
    a = fabs_asm(func_003893C8(D_L33_001DD9BC, p->fF8));
    left = 1;
    if (!(a < fabs_asm(func_003893C8(D_L33_001DD9C0_0034FBF8, p->fF8)))) {
        left = 0;
    }
    frame = func_L01_00436500(p);
    qzero(&grav);
    grav.z = D_L33_001DD9D8[idx];
    snd = p->oclass == 0x175F;

    if (p->state == 0) {
        func_L33_003525C0(p);
        if (s->f9C != -1) {
            func_L33_00352298(p, 15);
        } else {
            func_L33_00352298(p, 5);
        }
    }
    func_L33_00351DD0(p);

    switch (p->state) {
    case 1:
        if (func_L01_00452EC8(p)) {
            s->v80 = D_001A4C60.pos;
            s->v60.x = 0.0f;
            p->f96 = 0;
        }
        ret = func_L30_0034C308(p, &p->pos, &s->v60, &grav, D_L33_001DDB38_0034FBF8[idx], D_L33_001DDB38_0034FBF8[idx], 100.0f,
                                0.0f, 0.0f, D_L33_001DD9A8_0034FBF8, 1, 1, 1, 0);
        if (D_L33_001DD8E8_0034FBF8[idx] <= frame && frame <= D_L33_001DD8F8[idx]) {
            func_L30_0034BC88(p, &s->v60, 1, 1, 0, 0, s->f14, D_L33_001DD908[idx]);
        }
        if (++p->f96 <= 20) {
            break;
        }
        if (!(p->flags & 2) && !(D_L33_001DD8C8_0034FBF8[idx] <= frame)) {
            break;
        }
        if (!ret) {
            func_L33_00352298(p, 3);
        } else if (facing && inX && inZ) {
            func_L33_00352298(p, 1);
        } else if (!func_0037E208(0, 1)) {
            func_L33_00352298(p, 13);
        } else if (seen && inZ) {
            if (facing) {
                func_L33_00352298(p, 12);
            } else {
                s->v80 = D_001A4C60.pos;
                func_L33_00352298(p, 14);
            }
        } else {
            func_L33_00352298(p, 5);
        }
        break;
    case 0x42:
        if (func_L01_00452EC8(p)) {
            s->f78 = D_L33_001DDB10[idx];
            D_L33_001DD89C += 3 - idx;
        }
        if (!func_00388398(&s->f78)) {
            func_L30_0034B9C8(D_L33_001E18D8, p);
            func_L30_0034B9C8(D_L33_001E1918, p);
            p->f23 = (f32)s->f78 * 128.0f / (f32)D_L33_001DDB10[idx];
            func_L30_0034C308(p, &p->pos, &s->v60, &grav, D_L33_001DDB38_0034FBF8[idx], D_L33_001DDB38_0034FBF8[idx], 100.0f, 0.0f,
                              0.0f, D_L33_001DD940[idx], 1, 1, 1, 0);
            break;
        }
        v10.z = D_L33_001DDB78_0034FBF8;
        v10.x = D_L33_001DD9D8[idx] * 5.0f / (2.0f * D_L33_001DDB78_0034FBF8);
        n = p->oclass == 0x1761 ? 1 : 2;
        if (D_001A4BE0.pos.x < p->pos.x) {
            v10.x = -v10.x;
        }
        if (p->oclass != 0x175F) {
            if (p->oclass == 0x1760) {
                func_0039FE80(6, 0, p);
            } else {
                func_0039FE80(7, 0, p);
            }
            v10.x *= func_0037E250(0.8f, 1.2f);
            func_L33_00352AE8(&p->pos, &v10, n, -1, -1, -1, 1);
            v10.x *= func_0037E250(0.4f, 0.6f);
            func_L33_00352AE8(&p->pos, &v10, n, -1, -1, -1, 1);
        }
        qzero(&s->v60);
        func_L33_00351B28(0, p->oclass, 0);
        func_003BD360(p);
        break;
    case 2:
        if (func_L01_00452EC8(p)) {
            s->f78 = D_L33_001DDB10[idx];
            func_0039FE80(snd + 5, 0, p);
            func_L30_0034C308(p, &p->pos, &s->v60, &grav, D_L33_001DDB38_0034FBF8[idx], D_L33_001DDB38_0034FBF8[idx], 100.0f, 0.0f,
                              0.0f, D_L33_001DD940[idx], 1, 1, 1, 1);
        }
        if (p->f42 == p->f43) {
            func_L32_003489D0(p, &p->pos, D_L33_001DDB38_0034FBF8[idx], s->v60.z, D_L33_001DD9D8[idx], D_L33_001DD988_0034FBF8[idx],
                              D_L33_001DD978_0034FBF8[idx], 0.0f, -1.0f);
        } else {
            p->f48 = 1.0f;
        }
        if (!func_00388398(&s->f78)) {
            func_L30_0034B9C8(D_L33_001E18D8, p);
            func_L30_0034B9C8(D_L33_001E1918, p);
        }
        ret = func_L30_0034C308(p, &p->pos, &s->v60, &grav, D_L33_001DDB38_0034FBF8[idx], D_L33_001DDB38_0034FBF8[idx], 100.0f, 0.0f,
                                0.0f, D_L33_001DD940[idx], 1, 1, 1, 1);
        if ((p->flags & 2) || (idx == 2 && s->v60.z <= 0.0f && D_L33_001DD988_0034FBF8[idx] <= frame) ||
            (idx < 2 && s->v60.z <= 0.0f && D_L33_001DD988_0034FBF8[idx] <= frame && ret)) {
            func_L33_00352298(p, 0x42);
        }
        break;
    case 3:
        if (func_L30_0034C308(p, &p->pos, &s->v60, &grav, D_L33_001DDB38_0034FBF8[idx], D_L33_001DDB38_0034FBF8[idx], 100.0f, 100.0f,
                              0.0f, D_L33_001DD9A8_0034FBF8, 1, 1, 1, 0)) {
            func_L33_00352298(p, 11);
        }
        break;
    case 4:
        if (func_L01_00452EC8(p)) {
            s->f78 = D_L33_001DDB10[idx];
            func_0039FE80(snd + 3, 0, p);
            func_0039FE80(snd | 4, 0, p);
            func_L30_0034C308(p, &p->pos, &s->v60, &grav, D_L33_001DDB38_0034FBF8[idx], D_L33_001DDB38_0034FBF8[idx], 100.0f, 0.0f,
                              0.0f, D_L33_001DDA20[idx], 1, 1, 1, 0);
        }
        if (!func_00388398(&s->f78)) {
            func_L30_0034B9C8(D_L33_001E18D8, p);
        }
        ret = func_L30_0034C308(p, &p->pos, &s->v60, &grav, D_L33_001DDB38_0034FBF8[idx], D_L33_001DDB38_0034FBF8[idx], 100.0f, 0.0f,
                                0.0f, D_L33_001DDA20[idx], 1, 1, 1, 0);
        if (!(p->flags & 2) && !(D_L33_001DDA50_0034FBF8[idx] < frame && p->f42 == p->f43)) {
            break;
        }
        if (!ret) {
            func_L33_00352298(p, 3);
        } else if (facing && inX && inZ) {
            func_L33_00352298(p, 1);
        } else if (!seen) {
            func_L33_00352298(p, 5);
        } else if (!inZ) {
            func_L33_00352298(p, 6);
        } else if (facing) {
            func_L33_00352298(p, 12);
        } else {
            s->v80 = D_001A4C60.pos;
            func_L33_00352298(p, 14);
        }
        break;
    case 5:
        if (!func_L30_0034C308(p, &p->pos, &s->v60, &grav, D_L33_001DDB38_0034FBF8[idx], D_L33_001DDB38_0034FBF8[idx], 100.0f, 0.0f,
                               D_L33_001DDB80, s->fB4, 1, 1, 1, 0)) {
            func_L33_00352298(p, 3);
        } else if (facing && inX && inZ) {
            func_L33_00352298(p, 1);
        } else if (seen && inZ) {
            if (facing) {
                func_L33_00352298(p, 12);
            } else {
                s->v80 = D_001A4C60.pos;
                func_L33_00352298(p, 14);
            }
        } else if (p->flags & 2) {
            s->v80 = p->pos;
            s->v80.x += func_L33_003527C8((u8 *)p) ? 4.0f : -4.0f;
            func_L33_00352298(p, 14);
        }
        break;
    case 6:
        if (func_L01_00452EC8(p)) {
            func_L33_00351CD0(p);
            s->f78 = 0;
        }
        v10 = s->v80;
        v10.x = func_L33_00351B88(p);
        func_L31_00346000(p, &s->v60, v10.x, D_L33_001DD9B0_0034FBF8, s->fB8, s->fB4, s->fB4);
        ret = func_L30_0034C308(p, &p->pos, &s->v60, &grav, D_L33_001DDB38_0034FBF8[idx], D_L33_001DDB38_0034FBF8[idx], 100.0f, s->fB8,
                                D_L33_001DDB80, 0.0f, 1, 1, 1, 0);
        {
            f32 spd = D_L33_001DDA7C_0034FBF8 * func_00388770(&s->v60) / D_L33_001DDB00_0034FBF8[idx];
            p->f48 = spd;
            if (spd > 5.0f) {
                p->f48 = 5.0f;
            } else if (spd < 0.5f) {
                p->f48 = 0.5f;
            }
        }
        if (func_00388398(&s->f78)) {
            if (!D_L33_001DD01C) {
                func_L03_0034A688(D_L33_001E1938, p);
            }
            s->f78 = D_L33_001DDCD0;
        }
        if (!ret) {
            func_L33_00352298(p, 3);
        } else if (facing && inX && inZ) {
            func_L33_00352298(p, 1);
        } else if (seen && inZ) {
            if (facing) {
                func_L33_00352298(p, 12);
            } else {
                s->v80 = D_001A4C60.pos;
                func_L33_00352298(p, 14);
            }
        } else if (func_003887C8(&s->v80, &p->pos) < D_L33_001DD9B0_0034FBF8 || func_L33_003521D0(p, left, facing, 0)) {
            func_L33_00352298(p, 5);
        }
        break;
    case 7:
        if (func_L01_00452EC8(p)) {
            qzero(&s->v60);
        }
        if (D_L33_001DDB30 < frame && frame < D_L33_001DDB2C) {
            v10 = s->v50;
            v20 = *(vu0_v4 *)(D_L33_001DFC80_2 + s->f9C * 128 + 0x30);
            func_003BEB58(&p->pos, &v10, &v20, (frame - D_L33_001DDB30) / (D_L33_001DDB2C - D_L33_001DDB30));
            if (D_L33_001DDB30 + D_L33_001DDB2C < 2.0f * frame && s->f98 != -1) {
                func_L01_00452F40(D_L33_001DFB9C_2 + s->f98 * 256, 1);
            }
        } else if (D_L33_001DDB2C < frame) {
            func_L30_0034C308(p, &p->pos, &s->v60, &grav, D_L33_001DDB38_0034FBF8[idx], D_L33_001DDB38_0034FBF8[idx], 100.0f, 0.0f,
                              D_L33_001DDB80, 0.0f, 1, 1, 1, 0);
        }
        if (p->flags & 2) {
            s->v80 = D_001A4C60.pos;
            func_L33_00352298(p, 14);
        }
        break;
    case 8:
        if (func_L01_00452EC8(p)) {
            func_L30_0034BEE0(1.0f, 0, 0, 0, &top);
            v20 = p->pos;
            v30 = p->pos;
            y = D_001A4BE0.pos.y;
            x = *(f32 *)(D_L33_001DFC80 + s->f9C * 128 + 0x30);
            v30.x = x;
            v30.y = y;
            v20.y = y;
            v20.x = x;
            v20.z = top;
            if (!func_003CE740(&v20, &v30, 2, 0, 0)) {
                func_L33_00352298(p, 0x42);
                break;
            }
            top = D_L33_001E96A0.z + D_L33_001DDAC8;
            qzero(&s->v60);
            s->v60.z = sqrt_asm(fabs_asm(2.0f * D_L33_001DD9E4 * (top - p->pos.z)));
            p->f96 = sqrt_asm(fabs_asm((top - p->pos.z) * 2.0f / D_L33_001DD9E4));
            s->f78 = p->f96;
            s->v60.x = (*(f32 *)(D_L33_001DFC80 + s->f9C * 128 + 0x30) - s->v50.x) / p->f96;
            s->f94 = 0;
            p->fF8 = func_00389410(p->pos.x < D_001A4BE0.p25C0->pos.x ? D_L33_001DD9C0_0034FBF8 : D_L33_001DD9BC);
        }
        {
            s32 cnt = p->f96 - 1;
            if (cnt < 0) {
                cnt = 0;
            }
            p->f96 = cnt;
        }
        p->pos.y = func_003BEB48(s->v50.y, D_001A4BE0.pos.y, 1.0f - (f32)p->f96 / (f32)s->f78);
        if (s->v60.z < 0.0f) {
            p->f98 = p->f24->f10;
        }
        func_L32_003489D0(p, &p->pos, D_L33_001DDB38_0034FBF8[idx], s->v60.z, D_L33_001DD9E4, D_L33_001DDAB8, D_L33_001DDABC,
                          0.0f, -1.0f);
        qzero(&v10);
        v10.z = D_L33_001DD9E4;
        if (D_L33_001DDABC <= frame) {
            s->f90 = p->pos.x < D_001A4BE0.pos.x ? D_L33_001DD9C0_0034FBF8 : D_L33_001DD9BC;
            if (D_L33_001DD9B8 < fabs_asm(func_003893C8(s->f90, p->fF8))) {
                {
                    f32 q2 = s->fBC * D_L33_001DDBB0;
                    f32 r2 = s->fC0 * D_L33_001DDBB0;
                    func_L01_00445758(&p->fF8, &s->f94, s->f90 == 0.0f ? -1 : 1, s->f90, q2, q2, r2);
                }
            }
            m = 0.0f;
        } else {
            m = 100.0f;
        }
        func_L30_0034C308(p, &p->pos, &s->v60, &v10, D_L33_001DDB38_0034FBF8[idx], D_L33_001DDB38_0034FBF8[idx], 100.0f, m,
                          D_L33_001DDB80, 0.0f, 1, 1, 1, 0);
        if (D_L33_001DDAC0_0034FBF8 <= frame || (p->flags & 2)) {
            s->v80 = D_001A4C60.pos;
            func_L33_00352298(p, 14);
        }
        break;
    case 9:
        func_L01_00452EC8(p);
        if (func_L30_0034C308(p, &p->pos, &s->v60, &grav, D_L33_001DDB38_0034FBF8[idx], D_L33_001DDB38_0034FBF8[idx], 100.0f, s->fB8,
                              D_L33_001DDB80, 0.0f, 1, 1, 1, 0)) {
            func_L33_00352298(p, 10);
        }
        break;
    case 10:
    case 11:
        if (func_L01_00452EC8(p)) {
            s->f94 = 0;
        }
        ret = func_L30_0034C308(p, &p->pos, &s->v60, &grav, D_L33_001DDB38_0034FBF8[idx], D_L33_001DDB38_0034FBF8[idx], 100.0f, 0.0f,
                                D_L33_001DDB80, 0.0f, 1, 1, 1, 0);
        {
            f32 tgt;
            if (p->pos.x < D_001A4BE0.pos.x) {
                tgt = D_L33_001DD9C0_0034FBF8;
            } else {
                tgt = D_L33_001DD9BC;
            }
            s->f90 = tgt;
        }
        if (D_L33_001DD9B8 < fabs_asm(func_003893C8(s->f90, p->fF8))) {
            {
                f32 q2 = s->fBC * D_L33_001DDBB0;
                f32 r2 = s->fC0 * D_L33_001DDBB0;
                func_L01_00445758(&p->fF8, &s->f94, s->f90 == 0.0f ? -1 : 1, s->f90, q2, q2, r2);
            }
        }
        if (!ret) {
            func_L33_00352298(p, 3);
        }
        if ((p->flags & 2) || (p->state == 11 && D_L33_001DDA90_0034FBF8[idx] <= frame) ||
            (p->state == 10 && D_L33_001DDAB4 <= frame)) {
            if (facing && inX && inZ) {
                func_L33_00352298(p, 1);
            } else if (seen && inZ) {
                if (facing) {
                    func_L33_00352298(p, 12);
                } else {
                    s->v80 = D_001A4C60.pos;
                    func_L33_00352298(p, 14);
                }
            } else {
                func_L33_00352298(p, 5);
            }
        }
        break;
    case 12:
        if (func_L01_00452EC8(p)) {
            s->f78 = 0;
        }
        s->v80 = D_001A4C60.pos;
        v10 = s->v80;
        v10.x = func_L33_00351B88(p);
        h = D_001A4C60.p2540;
        z = s->fB8;
        w = s->fB4;
        if ((h->fF8 < 1.5707964f && p->pos.x < h->pos.x) || (1.5707964f <= h->fF8 && h->pos.x < p->pos.x)) {
            z *= D_L33_001DDAEC_0034FBF8;
            w *= D_L33_001DDAEC_0034FBF8;
        }
        func_L31_00346000(p, &s->v60, v10.x, D_L33_001DD9B0_0034FBF8, z, w, w);
        ret = func_L30_0034C308(p, &p->pos, &s->v60, &grav, D_L33_001DDB38_0034FBF8[idx], D_L33_001DDB38_0034FBF8[idx], 100.0f, z,
                                D_L33_001DDB80, 0.0f, 1, 1, 1, 0);
        if (func_00388770(&s->v60) < D_L33_001DD9B4 && fabs_asm(v10.x - p->pos.x) < D_L33_001DDB38_0034FBF8[idx]) {
            if (!(p->f43 == 1 || p->f43 == 2 || p->f43 == 9) || (p->flags & 2)) {
                if (!func_0037E208(0, 2)) {
                    if (p->f43 != 1) {
                        func_003BE4F0(p, 1, func_0037E250(0.0f, 4.0f), D_L33_001DDB88_0034FBF8);
                    }
                } else if (!func_0037E208(0, 1)) {
                    if (p->f43 != 2) {
                        func_003BE4F0(p, 2, func_0037E250(0.0f, 4.0f), D_L33_001DDB88_0034FBF8);
                    }
                } else {
                    if (p->f43 != 9) {
                        func_003BE4F0(p, 9, func_0037E250(0.0f, 4.0f), D_L33_001DDB88_0034FBF8);
                    }
                }
                p->f48 = 1.0f;
            }
        } else {
            f32 spd;
            if (p->f43 != 3) {
                func_003BE4F0(p, 3, 0, D_L33_001DDB88_0034FBF8);
            }
            spd = D_L33_001DDA7C_0034FBF8 * func_00388770(&s->v60) / D_L33_001DDB00_0034FBF8[idx];
            p->f48 = spd;
            if (spd > 5.0f) {
                p->f48 = 5.0f;
            } else if (spd < 0.5f) {
                p->f48 = 0.5f;
            }
        }
        if (func_00388398(&s->f78)) {
            if (!D_L33_001DD01C) {
                func_L03_0034A688(D_L33_001E1938, p);
            }
            s->f78 = D_L33_001DDCD0;
        }
        if (func_L33_003521D0(p, left, facing, 1)) {
            s->fB0 = D_L33_001DD9E8;
        }
        if (!ret) {
            func_L33_00352298(p, 3);
        } else if (facing && inX && inZ) {
            func_L33_00352298(p, 1);
        } else if (!seen || (inX && !inZ)) {
            func_L33_00352298(p, 5);
        } else if (!facing) {
            func_L33_00352298(p, 14);
        }
        break;
    case 13:
        if (!func_L30_0034C308(p, &p->pos, &s->v60, &grav, D_L33_001DDB38_0034FBF8[idx], D_L33_001DDB38_0034FBF8[idx], 100.0f, 0.0f,
                               D_L33_001DDB80, 0.0f, 1, 1, 1, 0)) {
            func_L33_00352298(p, 3);
        } else if (facing && inX && inZ) {
            func_L33_00352298(p, 1);
        } else if (p->flags & 2) {
            if (seen && inZ) {
                if (facing) {
                    func_L33_00352298(p, 12);
                } else {
                    s->v80 = D_001A4C60.pos;
                    func_L33_00352298(p, 14);
                }
            } else {
                func_L33_00352298(p, 5);
            }
        }
        break;
    case 14:
        if (func_L01_00452EC8(p)) {
            s->f90 = p->pos.x < s->v80.x ? D_L33_001DD9C0_0034FBF8 : D_L33_001DD9BC;
            s->v60.x = 0.0f;
            s->f94 = 0;
        }
        d = func_003893C8(s->f90, p->fF8);
        r = s->fC0;
        if (inX) {
            r *= D_L33_001DDBB0;
        }
        q = s->fBC;
        if (inX) {
            q *= D_L33_001DDBB0;
        }
        if (D_L33_001DD9B8 < fabs_asm(d)) {
            func_L01_00445758(&p->fF8, &s->f94, s->f90 == 0.0f ? -1 : 1, s->f90, q, q, r);
            if (d > 2.0943952f) {
                d = 2.0943952f;
            } else if (d < -2.0943952f) {
                d = -2.0943952f;
            }
            k = func_00388770(&s->v60) / D_L33_001DDB00_0034FBF8[idx];
            c = func_00388960(func_00389410(d));
            if (c < 0.0f) {
                c = 0.0f;
            }
            p->f48 = func_003BEB48(k, D_L33_001DDBB0, fabs_asm(d) / 2.0943952f);
            sp = s->fB8 * fabs_asm(c);
            if (func_L33_003521D0(p, left, facing, 0)) {
                sp = 0.0f;
            }
            v10 = s->v80;
            v10.x = func_L33_00351B88(p);
            func_L31_00346000(p, &s->v60, v10.x, D_L33_001DD918[idx], s->fB8, s->fB4, s->fB4);
            if (sp < s->v60.x) {
                s->v60.x = sp;
            } else if (s->v60.x < -sp) {
                s->v60.x = -sp;
            }
            if (!func_L30_0034C308(p, &p->pos, &s->v60, &grav, D_L33_001DDB38_0034FBF8[idx], D_L33_001DDB38_0034FBF8[idx], 100.0f, sp,
                                   D_L33_001DDB80, s->fB4, 1, 1, 1, 0)) {
                func_L33_00352298(p, 3);
            }
        } else if (facing && inX && inZ) {
            func_L33_00352298(p, 1);
        } else if (func_0037E250(0.0f, 1.0f) < D_L33_001DDBB4_0034FBF8) {
            func_L33_00352298(p, 13);
        } else if (seen && inZ) {
            if (facing) {
                func_L33_00352298(p, 12);
            } else {
                s->v80 = D_001A4C60.pos;
                func_L33_00352298(p, 14);
            }
        } else if (!seen) {
            func_L33_00352298(p, 5);
        } else {
            func_L33_00352298(p, 6);
        }
        break;
    case 15:
        if (!func_L30_0034C308(p, &p->pos, &s->v60, &grav, D_L33_001DDB38_0034FBF8[idx], D_L33_001DDB38_0034FBF8[idx], 100.0f, s->fB8,
                               D_L33_001DDB80, 0.0f, 0, 0, 0, 0)) {
            p->f98 = 0;
            p->f34 = (p->f34 | 0x41) & ~0x1000;
            func_L01_004A6DF8(p, 1);
        }
        if (func_L01_00452F60(p) || (s->fAC != -1 && func_0037E0F0(&D_001A4C60, s->fAC, 0)) ||
            (s->fAC == -1 && s->fA0 != -1 && func_0037E0F0(&D_001A4C60, s->fA0, 0)) ||
            (s->fAC == -1 && s->fA0 == -1 && func_L30_0034C9F8_0034FBF8(&D_001A4C60, 1.5f))) {
            Ref_00350818 *ref;
            p->f34 &= 0xFFBE;
            ref = p->f24;
            p->f34 |= ref->f44 & 0x1000;
            p->f98 = ref->f10;
            if (p->oclass == 0x1761) {
                if (s->f98 != -1) {
                    func_L33_00352298(p, 7);
                } else {
                    func_L33_00352298(p, 3);
                }
            } else if (p->oclass == 0x1760) {
                func_L33_00352298(p, 8);
            } else {
                if (p->pos.x < D_001A4BE0.p25C0->pos.x) {
                    p->fF8 = func_00389410(D_L33_001DD9C0_0034FBF8);
                } else {
                    p->fF8 = func_00389410(D_L33_001DD9BC);
                }
                func_L01_00452F40(D_L33_001DFB9C + s->f98 * 256, 1);
                func_L33_00352298(p, 9);
            }
        }
        break;
    }
}
/* localdecomp:end func_L33_0034FBF8 */
