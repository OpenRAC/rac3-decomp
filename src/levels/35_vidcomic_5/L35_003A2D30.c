#include "common.h"

/* declared by functions of L35_003A29A8.c, which this file was cut from */
extern u8 D_001A4BE0[];
extern void func_0038CE20(s32, s32, f32);

/* localdecomp:start func_L35_003A2D30 */
#include "vu0.h"

extern u8 D_001A4BE0[];
extern u8 D_L35_001D66B0[8];
extern s32 D_L35_001E1D60;
__asm__(".extern D_L35_001E1D60, 16");
extern f32 D_L35_001E1D64;
__asm__(".extern D_L35_001E1D64, 16");
extern u8 D_L35_0021F258[];
extern s32 D_L35_001DE9A8;
extern const f32 D_L35_001DE990;
extern s32 D_L35_001DE9B8;
extern s32 D_L35_001DE9C4;
extern s32 D_L35_001DE9C0;
extern f32 D_L35_001DE9AC;
extern s32 D_L35_001DE9A0;
__asm__(".extern D_L35_001DE9A8, 4");
__asm__(".extern D_L35_001DE990, 4");
__asm__(".extern D_L35_001DE9B8, 4");
__asm__(".extern D_L35_001DE9C4, 4");
__asm__(".extern D_L35_001DE9C0, 4");
__asm__(".extern D_L35_001DE9AC, 4");
__asm__(".extern D_L35_001DE9A0, 4");
extern void func_L35_003A3758(u8 *);
extern void func_L35_003A3500(u8 *);
extern void func_L35_003A3828(u8 *);
extern void func_L35_003A3498(u8 *);
extern void func_L01_004450F0(u8 *moby, s32 a, s32 b);
extern s32 func_L01_004561B8(u8 *);
extern void func_003C4DA8(void *, void *, void *, void *);
extern s32 func_L01_004AAC98(s32, s32, u8 *, s32);
extern void func_L01_00456230(void *, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern s32 func_L30_0034D8D8(void *, f32);
extern void func_L30_0034C8A8(void *, void *);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0044E820(void *, s32);

void func_L35_003A2D30(u8 *a0) {
    u8 *s2 = *(u8 **)(a0 + 0x68);
    vu0_v4 pos = *(vu0_v4 *)(a0 + 0x10);
    vu0_v4 rot = *(vu0_v4 *)(a0 + 0xF0);
    vu0_v4 d;
    vu0_v4 v;
    vu0_v4 a;
    u8 *p;
    s32 i;
    f32 f;
    u8 *g;
    u8 *tbl;

    switch (a0[0x20]) {
    case 0:
        func_L35_003A3758(a0);
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_L01_004561B8(a0) != 0) {
            a0[0x23] = 0x80;
        }
        if (*(s32 *)(s2 + 0x98) != 0) {
            g = D_001A4BE0;
            if (*(f32 *)(g + 0x88) < *(f32 *)(a0 + 0x18) && *(u8 **)(g + 0x35C) != a0) {
                *(s32 *)(a0 + 0x98) = 0;
            } else {
                *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
            }
        } else {
            *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
        }
        func_L35_003A3500(a0);
        vec_sub_ba(&d, a0 + 0x10, &pos);
        func_003C4DA8(s2 + 0x30, &d, &rot, a0 + 0xF0);
        break;
    case 2:
        if (func_L01_004561B8(a0) != 0) {
            func_L01_004AAC98(1, 0, a0, 0x1D64);
            if (*(void **)(s2 + 0xA4) != 0) {
                func_L01_00456230(*(void **)(s2 + 0xA4), 1);
            }
            *(s32 *)(s2 + 0xB0) = D_L35_001DE9A8;
            D_L35_001E1D64 = D_L35_001DE990;
            *(s32 *)(a0 + 0x98) = 0;
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(a0, 1);
            func_L01_00451FE0(a0, 7, D_L35_001D66B0, 3.0f, 5.0f, 3.0f, 5.0f, 0xFF, 25.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        }
        *(f32 *)(s2 + 0xB4) = func_L03_0034B440(1, 0, 0, (f32)*(s32 *)(s2 + 0xB0), (f32)D_L35_001DE9A8, 1.0f);
        if (func_L30_0034D8D8(a0 + 0x10, 1.2f) != 0) {
            func_L30_0034C8A8(&D_L35_001E1D60, a0);
        }
        tbl = D_L35_0021F258;
        for (i = 0; i < 10; i++) {
            func_00382580(&a, 0.0300000012f, 0.0600000024f);
            func_00382580(&v, 0.0f, 1.5f);
            vec_add_ab(&v, &v, a0 + 0x10);
            p = func_L01_00475C60(&v, &a, 0x19, func_00382498(-3, 3), 0x7FFFF38F, 0x10FFF38F, 63000.004f, 42000.0f, 20.0f, 0);
            if (p != 0) {
                p[2] = func_00382468(3) != 0 ? (*(u8 **)(tbl + 0x1FC))[func_00382498(1, 3)] : **(u8 **)(tbl + 0xD4);
                p[3] = func_00382468(2) != 0 ? 0x44 : 0x48;
            }
        }
        if (*(s32 *)(s2 + 0x98) == 0 && *(s32 *)(s2 + 0xB0) < D_L35_001DE9A8 - D_L35_001DE9B8) {
            func_L35_003A3828(a0);
        }
        if (func_0038CAD0(s2 + 0xB0) != 0) {
            func_L35_003A3498(a0);
        }
        break;
    case 3:
        if (func_L01_004561B8(a0) != 0) {
            *(s32 *)(a0 + 0x98) = 0;
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(a0, 1);
            *(s32 *)(s2 + 0xB0) = D_L35_001DE9C4;
        }
        if (func_0038CAD0(s2 + 0xB0) != 0) {
            func_L01_004450F0(a0, 4, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(a0) != 0) {
            u8 *m = *(u8 **)(a0 + 0x24);
            s32 n = D_L35_001DE9C0 - 1;
            *(u16 *)(a0 + 0x34) &= 0xFFBE;
            *(u16 *)(a0 + 0x34) |= *(u16 *)(m + 0x44) & 0x1000;
            *(s32 *)(a0 + 0x98) = *(s32 *)(m + 0x10);
            *(s32 *)(s2 + 0xB0) = n;
        }
        f = func_L03_0034B440(1, 0, 0, (f32)*(s32 *)(s2 + 0xB0), (f32)D_L35_001DE9C0, 1.0f);
        *(f32 *)(s2 + 0xB4) = f;
        a0[0x23] = (s32)(f * 128.0f);
        func_L01_0044E820(a0, func_0038DBD8(0x8000C4C4, 0x80808080, *(f32 *)(s2 + 0xB4)));
        if (*(f32 *)(s2 + 0xB4) > D_L35_001DE9AC) {
            *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
        } else {
            *(s32 *)(a0 + 0x98) = 0;
        }
        if (func_0038CAD0(s2 + 0xB0) != 0) {
            *(s32 *)(s2 + 0x90) = D_L35_001DE9A0;
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L35_003A2D30 */

/* localdecomp:start func_L35_003A3240 */
#include "vu0.h"

typedef struct {
    u8 *moby;
    s32 tex;
    s16 life;
    u16 flags;
    s16 pad_c;
    u8 alpha;
    u8 pad_f;
    f32 vx;
    f32 vz;
} P_003A3240;

typedef struct {
    s32 pad_0;
    u32 rgba;
    u8 alpha;
    u8 pad_9;
    s16 age;
    f32 size;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} S_003A3240;

extern f32 D_L35_001DE9A4;
__asm__(".extern D_L35_001DE9A4, 4");
extern f32 D_L35_001DE980;
__asm__(".extern D_L35_001DE980, 4");
extern f32 D_L35_001DE970;
__asm__(".extern D_L35_001DE970, 4");
extern s32 D_L35_001DE968;
__asm__(".extern D_L35_001DE968, 4");
extern s32 D_L35_001DE964;
__asm__(".extern D_L35_001DE964, 4");
extern f32 D_L35_001DE988;
__asm__(".extern D_L35_001DE988, 4");
extern f32 D_L35_001DE984;
__asm__(".extern D_L35_001DE984, 4");
extern f32 D_L35_001DE96C;
__asm__(".extern D_L35_001DE96C, 4");
extern f32 D_L35_001DE960;
__asm__(".extern D_L35_001DE960, 4");
extern f32 D_L35_001DE974;
__asm__(".extern D_L35_001DE974, 4");
extern void func_L30_0034C958(vu0_v4 *, f32);
extern void func_L02_003BA9F8(void *, void *, void *, void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_003C4088(f32, f32, f32);

void func_L35_003A3240(u8 *a0, u8 *a1) {
    S_003A3240 *s = (S_003A3240 *)a0;
    P_003A3240 *p = (P_003A3240 *)a1;
    u8 *moby;
    u8 *vars;
    s32 tex;
    f32 t;
    f32 size;
    s16 age;
    vu0_v4 v;
    vu0_v4 r0;
    vu0_v4 r1;
    vu0_v4 d;

    if (p == 0)
        return;
    moby = p->moby;
    vars = *(u8 **)(moby + 0x68);
    tex = p->tex;
    if (moby == 0 || tex == 0)
        return;
    if (p->flags & 1) {
        qzero(&v);
        func_L30_0034C958(&v, D_L35_001DE9A4);
        if (*(s32 *)(vars + 0x98) != 0) {
            func_L02_003BA9F8(&v, vars + 0x80, &r0, &r1);
            func_0038CE20((s32)&r1, (s32)&r1, D_L35_001DE980);
            vec_add_ab(&v, &r0, &r1);
            v.y = func_003824E0(-D_L35_001DE9A4, D_L35_001DE9A4);
        }
        vec_add_ab(&s->x, moby + 0x10, &v);
        if (moby[0x20] == 2) {
            vec_sub_ba(&d, &s->x, moby + 0x10);
            func_0038CF68(&d, &d, (1.0f - *(f32 *)(vars + 0xB4)) * D_L35_001DE970);
            p->vx = d.x;
            p->vz = d.z;
        }
        s->rgba = moby[0x20] == 2 ? D_L35_001DE964 : D_L35_001DE968;
        s->alpha = p->alpha;
        size = func_003824E0(D_L35_001DE988, D_L35_001DE984);
        s->size = size;
        if (moby[0x20] == 2) {
            s->size = size * D_L35_001DE96C;
        }
    }
    t = func_L03_0034B440(1, 0, 0, (f32)s->age, (f32)p->life, 1.0f);
    s->rgba = (s->rgba & 0xFFFFFF) | ((s32)func_003C4088(D_L35_001DE960, 128.0f, t) << 24);
    p->vz += D_L35_001DE974;
    s->x += p->vx;
    age = s->age;
    s->z += p->vz;
    s->size *= (f32)age / (f32)(age + 1);
}
/* localdecomp:end func_L35_003A3240 */
