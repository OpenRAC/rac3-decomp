#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L33_003AA940 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3AA940;
typedef struct {
    u8 pad_00[4];
    f32 f_04;
    f32 f_08;
    f32 f_0C;
    s32 f_10;
    s32 f_14;
    s32 f_18;
} C_3AA940;

__asm__(".extern D_L33_001DFC80, 4");
__asm__(".extern D_L33_001DEE2C, 4");
__asm__(".extern D_L33_001DEE30, 4");
__asm__(".extern D_L33_001DF740, 16");
extern s32 D_L33_001DF740;
extern u8 D_001A4BE0[];
extern V_3AA940 D_001A4C60;
extern u8 D_L33_001E7480[];
extern u8 *D_L33_001DFC80;
extern f32 D_L33_001DEE2C;
extern f32 D_L33_001DEE30;
extern void func_L30_0034BEE0(f32 *, f32 *, f32 *, f32 *, f32);
extern void func_L30_0034BDF0(u8 *, f32 *, f32 *, f32 *, f32 *);
extern f32 func_L30_003A8020(f32, f32, f32);
extern f32 func_L30_003A7DE8(V_3AA940 *, f32);
void func_L33_003AA940(C_3AA940 *a0, V_3AA940 *a1, V_3AA940 *a2) {
    V_3AA940 b;
    V_3AA940 c;
    u8 *e;
    u8 *cam;
    u8 *hstate;
    u8 *hpos;
    f32 h;
    f32 x;
    f32 m;
    s32 state;

    func_L30_0034BEE0(&b.x, &b.y, &b.z, &b.w, 1.0f);
    h = 0.0f;
    if (D_L33_001DF740 < 5) {
        h = 15.0f;
    }
    x = a0->f_04 * 15.0f;
    m = (x < h) ? h : x;
    h = m;
    if (a0->f_10 == 0) {
        a1->x = a0->f_08;
    } else if (a0->f_10 == 1) {
        u8 *hero = D_001A4BE0;
        a1->x = func_L30_003A8020(*(f32 *)(hero + 0x80), a0->f_08, b.y - b.x);
    } else {
        a1->x = a2->x;
    }
    hstate = D_001A4BE0;
    state = *(s32 *)(hstate + 0x25C4);
    if (state == 0x9F || (a0->f_14 != 3 && ((state == 0x9C && *(s16 *)(hstate + 0x1B3E) == 0) || state == 0xA2 || state == 0xAA))) {
        a1->z = a2->z;
    } else if (a0->f_14 == 0) {
        a1->z = a0->f_0C;
    } else if (a0->f_14 == 1 || a0->f_14 == 3) {
        u8 *hero = D_001A4BE0;
        a1->z = func_L30_003A8020(*(f32 *)(hero + 0x88), a0->f_0C, b.w - b.z);
    } else if (a0->f_14 == 2) {
        a1->z = func_L30_003A8020(func_L30_003A7DE8(&D_001A4C60, D_001A4C60.z - b.z), a0->f_0C, b.w - b.z);
    } else {
        a1->z = a2->z;
    }
    if (a0->f_18 != -1) {
        e = D_L33_001DFC80 + a0->f_18 * 128;
        func_L30_0034BDF0(e, &c.x, &c.y, &c.z, &c.w);
        if (a0->f_10 == 0) {
            a1->x = *(f32 *)(e + 0x30);
        }
        cam = D_L33_001E7480;
        if (*(f32 *)(cam + 0xB0) != 0.0f && a0->f_14 != 4) {
            f32 d;
            d = (c.y - c.x) / (*(f32 *)(cam + 0xB0) + *(f32 *)(cam + 0xB0));
            if (d < m) {
                d = m;
            }
            h = d;
        }
        if (a0->f_14 == 0) {
            a1->z = *(f32 *)(e + 0x38);
        }
        if (a0->f_14 == 4) {
            u8 *hero = D_001A4BE0;
            a1->z = c.z + a0->f_0C * fabs_asm((*(f32 *)(hero + 0x80) - c.x) / (c.y - c.x));
        }
        cam = D_L33_001E7480;
        if (*(f32 *)(cam + 0xB4) != 0.0f) {
            f32 d;
            d = (c.w - c.z) / (*(f32 *)(cam + 0xB4) + *(f32 *)(cam + 0xB4));
            if (d < h) {
                d = h;
            }
            h = d;
        }
    }
    hpos = D_001A4BE0;
    a1->y = *(f32 *)(hpos + 0x84) - h;
    if (fabs_asm(a1->x - a2->x) < D_L33_001DEE2C) {
        a1->x = a2->x;
    } else {
        f32 lim;
        f32 dx;
        lim = fabs_asm(a2->x - a1->x) - D_L33_001DEE2C;
        dx = a1->x - a2->x;
        if (lim < dx) {
            dx = lim;
        } else if (dx < -lim) {
            dx = -lim;
        }
        a1->x = a2->x + dx;
    }
    if (fabs_asm(a1->z - a2->z) < D_L33_001DEE30) {
        a1->z = a2->z;
    }
    *a2 = *a1;
}
/* localdecomp:end func_L33_003AA940 */
