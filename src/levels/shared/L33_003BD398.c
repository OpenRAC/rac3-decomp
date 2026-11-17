#include "common.h"

/* declared by functions of L33_003BD2E8.c, which this file was cut from */
extern void func_L33_003BD5F8(u8 *);

/* localdecomp:start func_L33_003BD398 */
__asm__(".extern D_L33_001DF140, 4");
__asm__(".extern D_L33_001DF130, 4");
__asm__(".extern D_L33_001DF154, 4");
__asm__(".extern D_L33_001DF128, 4");
__asm__(".extern D_L33_001DF12C, 4");
__asm__(".extern D_L33_001DF144, 4");
__asm__(".extern D_L33_001DF148, 4");
extern f32 D_L33_001DF140;
extern f32 D_L33_001DF130;
extern s32 D_L33_001DF154;
extern s32 D_L33_001DF128;
extern s32 D_L33_001DF12C;
extern u8 D_L33_001DF144;
extern f32 D_L33_001DF148;
extern u8 D_L33_002A3FF0[];
extern u8 D_001A4BE0[];
extern void func_L02_003BAFA0(void *, void *, void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern s32 func_0038CB00(void *);
extern f32 func_003C4088(f32, f32, f32);

typedef struct {
    u8 *obj;
    s32 f4;
    s16 f8;
    u16 fA;
    s16 fC;
    u8 pE[2];
    f32 f10, f14, f18, f1C;
} P_003BD398;

typedef struct {
    u8 p0[4];
    u32 f4;
    u8 f8;
    u8 p9;
    s16 fA;
    f32 fC;
    f32 f10, f14, f18;
} O_003BD398;

void func_L33_003BD398(u8 *a0, u8 *a1) {
    O_003BD398 *o = (O_003BD398 *)a0;
    P_003BD398 *p = (P_003BD398 *)a1;
    f32 zero, half, x, r;
    u8 *obj;
    s32 f4;
    if (p == 0) {
        return;
    }
    obj = p->obj;
    f4 = p->f4;
    if (obj == 0 || f4 == 0 || *(s32 *)(obj + 0x68) == 0) {
        return;
    }
    if (p->fA & 1) {
        zero = 0.0f;
        func_L02_003BAFA0(*(void **)(D_001A4BE0 + 0x25C0), D_L33_002A3FF0, &o->f10, &p->f10, zero);
        half = 0.5f;
        o->f14 += D_L33_001DF140;
        p->f14 = zero;
        p->f18 = func_003824E0(half, 1.5f) * D_L33_001DF130;
        if (p->f10 > 0.66f) {
            p->fC = (s32)(D_L33_001DF154 * 0.83f);
        } else if (p->f10 > 0.33f) {
            p->fC = (s32)(D_L33_001DF154 * half);
        } else {
            p->fC = (s32)(D_L33_001DF154 * 0.17f);
        }
        o->f4 = func_0038DBD8(D_L33_001DF128, D_L33_001DF12C, p->f10);
        o->f8 = D_L33_001DF144;
        x = D_L33_001DF148 * func_003824E0(0.5f, 1.5f);
        o->fC = x;
        p->f1C = x;
    }
    r = func_L03_0034B440(1, 0, 0, (f32)o->fA, (f32)(p->f8 + 1), 1.0f);
    if (func_0038CB00(&p->fC)) {
        p->f14 += p->f18;
        o->f18 += p->f14;
    } else {
        o->fA++;
    }
    o->f4 = (o->f4 & 0xFFFFFF) | ((s32)((1.0f - r) * 128.0f) << 24);
    o->fC = func_003C4088(p->f1C, p->f1C + p->f1C, r);
}
/* localdecomp:end func_L33_003BD398 */

/* localdecomp:start func_L33_003BD5F8 */
typedef struct { u8 r, g, b, a; } C_003BD5F8;
__asm__(".extern D_L33_001DF160, 4");
__asm__(".extern D_L33_001DF138, 4");
__asm__(".extern D_L33_001DF13C, 4");
__asm__(".extern D_L33_001DF14C, 4");
__asm__(".extern D_L33_001DF150, 4");
__asm__(".extern D_L33_001DF134, 4");
__asm__(".extern D_L33_001DF16C, 4");
__asm__(".extern D_L33_001DF164, 4");
extern s32 D_L33_001DF160;
extern s32 D_L33_001DF138;
extern s32 D_L33_001DF13C;
extern f32 D_L33_001DF14C;
extern s32 D_L33_001DF150;
extern s32 D_L33_001DF134;
extern f32 D_L33_001DF16C;
extern C_003BD5F8 D_L33_001DF164;
extern u8 D_L33_001E2288;
extern s32 D_L33_001E2298;
extern void func_L33_003BD398(u8 *, u8 *);
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern f32 func_003C3D30(void *, s32, void *, f32);

void func_L33_003BD5F8(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    if (D_L33_001DF160 == 0) {
        D_L33_001DF160 = 1;
        func_L03_0034B218(&D_L33_001E2288, D_L33_001DF138, D_L33_001DF13C, D_L33_001DF14C, D_L33_001DF150, func_L33_003BD398);
        D_L33_001E2298 = D_L33_001DF134;
    }
    *(s32 *)(a0 + 0x48) = 0;
    *(f32 *)(a0 + 0x2C) = D_L33_001DF16C * *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
    func_L01_0043B9E8(a0, D_L33_001DF164.r, D_L33_001DF164.g, D_L33_001DF164.b);
    *(f32 *)(v + 4) = func_003C3D30(a0 + 0x10, 0, 0, 0.5f);
    *(s32 *)(v + 8) = -1;
    *(s32 *)(v + 0xC) = 0;
    *(s32 *)(v + 0x10) = 0;
    *(s32 *)(v + 0x14) = 0;
}
/* localdecomp:end func_L33_003BD5F8 */
