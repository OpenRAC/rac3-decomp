#include "common.h"

/* localdecomp:start func_L07_003AA9C0 */
void func_L07_00334740(void *);
void func_L07_003AAA50(void *, s32);

void func_L07_003AA9C0(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    *(s32 *)(p + 0x188) &= -0x11;
    *(s32 *)(p + 0x53C) = 0;
    func_L07_00334740(arg0);
    func_L07_003AAA50(arg0, 1);
}
/* localdecomp:end func_L07_003AA9C0 */

/* localdecomp:start func_L07_003AAA08 */
void func_L07_00334800();
void func_L07_003AAA50(void *, s32);

void func_L07_003AAA08(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0x2C) = (f32) ((*(f32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x24))) + 0x24)) * 0.75f);
    func_L07_00334800();
    func_L07_003AAA50(arg0, 2);
}
/* localdecomp:end func_L07_003AAA08 */

INCLUDE_ASM("asm/levels", func_L07_003AAA50);

INCLUDE_ASM("asm/levels", func_L07_003AADB0);

INCLUDE_ASM("asm/levels", func_L07_003AAF98);

/* localdecomp:start func_L07_003AB200 */
extern void func_003C2F58(u8 *a, s32 b, f32 *out);
extern f32 func_0038CF38(void *a, void *b);
extern f32 func_0038D160(f32 x, f32 y);
extern f32 func_0038DB48(f32 a);

void func_L07_003AB200(u8 *arg0) {
    u8 *p;
    u8 *q;
    f32 v[3];
    f32 d;

    p = *(u8 **)(arg0 + 0x68);
    func_003C2F58(arg0, p[0x533] + 3, v);
    d = func_0038D160(*(f32 *)(p + 0x520) - v[0], *(f32 *)(p + 0x524) - v[1]);
    d = func_0038DB48((d - *(f32 *)(p + 0x2A8)) - *(f32 *)(arg0 + 0xF8));
    q = p + p[0x533] * 128;
    *(f32 *)(q + 0x3C8) = d;
    d = func_0038CF38(v, p + 0x520);
    d = func_0038D160(d, *(f32 *)(p + 0x528) - v[2]);
    p = p + p[0x533] * 128;
    *(f32 *)(p + 0x3C4) = -d;
}
/* localdecomp:end func_L07_003AB200 */

INCLUDE_ASM("asm/levels", func_L07_003AB2B0);

INCLUDE_ASM("asm/levels", func_L07_003AB4B8);

INCLUDE_ASM("asm/levels", func_L07_003AB678);

INCLUDE_ASM("asm/levels", func_L07_003AB918);

/* localdecomp:start func_L07_003ABD18 */
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L07_003AC2D0(void *);
extern void func_L07_003AC500(void *);
void func_L07_003ACA90(void *, s32);
extern void func_L07_003ACD58(void *, f32);
extern void func_L07_003ACF40(u8 *);
extern void func_L07_003AD088(void *);
extern void func_L07_003AD180(void *);
extern void func_L01_0045A9F0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_0045A748(void *, void *);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L07_00331008(u8 *, void *);
extern s32 func_L07_00334408(u8 *);
extern s32 func_L07_003346D8(u8 *);
extern void func_L07_00334588(u8 *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_L01_004395E0(void *);
extern void func_L01_00404808(void *, void *);

void func_L07_003ABD18(u8 *self) {
    u8 *p;
    f32 d;

    if (self[0x20] == 0) func_L07_003AC2D0(self);
    func_L07_003AC500(self);
    p = *(u8 **)(self + 0x68);
    switch (self[0x20]) {
    case 1:
        break;
    case 2:
        func_L01_0045A9F0(self);
        if (func_0038CB00(p + 0x24E)) func_L07_003ACA90(self, 3);
        break;
    case 3:
        func_L01_0045A9F0(self);
        func_L07_003ACA90(self, 4);
        break;
    case 4:
        func_L01_0045A748(self, *(u8 **)(p + 0x240) + 0x10);
        if (func_L01_0040E570(*(u8 **)(p + 0x240) + 0x10, self + 0x10) < 484.0f) {
            p[0x25E] = 1;
            func_L07_003ACA90(self, 6);
        }
        break;
    case 5:
        func_L01_0045A9F0(self);
        if (func_L01_00454370(self, p + 0x70) & 2) {
            if (p[0x25E] == 0) {
                func_L07_003ACA90(self, 4);
            } else {
                func_L07_003ACA90(self, 6);
            }
        }
        break;
    case 6:
        func_L01_0045A9F0(self);
        if (func_L07_00331008(*(u8 **)(p + 0x240), self)) {
            if (func_L01_0040E570(self + 0x10, p + 0x130) < 121.0f) {
                func_L07_003ACA90(self, 8);
            } else {
                func_L07_003ACA90(self, 7);
            }
        } else {
            func_L07_003ACA90(self, 13);
        }
        break;
    case 7:
        func_L07_003ACD58(self, 5.0f);
        if (func_L07_00331008(*(u8 **)(p + 0x240), self)) {
            if (func_L01_0040E570(self + 0x10, p + 0x130) < 64.0f) {
                func_L07_003ACA90(self, 8);
            }
        } else {
            func_L07_003ACA90(self, 6);
        }
        break;
    case 8:
        func_L07_003ACD58(self, 1.5f);
        if (func_L07_00331008(*(u8 **)(p + 0x240), self)) {
            if (121.0f < func_L01_0040E570(self + 0x10, p + 0x130)) {
                *(s32 *)(p + 0x188) &= ~0x10;
                func_L07_003ACA90(self, 7);
            } else if (func_0038CB00(p + 0x564)) {
                if (func_L01_0040E570(self + 0x10, p + 0x130) < 6.25f) {
                    *(s16 *)(p + 0x24C) = func_L07_00334408(self);
                    if (func_L07_003346D8(self)) func_L07_003ACA90(self, 10);
                }
            }
        } else {
            *(s32 *)(p + 0x188) &= ~0x10;
            func_L07_00334588(self);
            func_L07_003ACA90(self, 6);
        }
        break;
    case 9:
        func_L07_003ACD58(self, 1.5f);
        if (func_L07_00331008(*(u8 **)(p + 0x240), self)) {
            f32 dist = func_0038CF38(self + 0x10, p + 0x130);
            if (11.0f < dist) {
                *(s32 *)(p + 0x188) &= ~0x10;
                func_L07_00334588(self);
                func_L07_003ACA90(self, 7);
            } else if (dist < 2.5f) {
                func_L07_003ACA90(self, 10);
            }
        } else {
            *(s32 *)(p + 0x188) &= ~0x10;
            func_L07_00334588(self);
            func_L07_003ACA90(self, 6);
        }
        break;
    case 10:
        d = func_L01_004395E0(self);
        func_L01_0045A9F0(self);
        if (10.0f < d) {
            (*(u16 *)(p + 0x564))++;
            if (!(*(u16 *)(p + 0x564) % 2)) func_L07_003AD088(self);
            func_L01_00404808(func_L07_003AD180, self);
        }
        if (13.0f < d && d < 16.0f) func_L07_003ACF40(self);
        if (self[0x60] & 2) {
            func_L07_00334588(self);
            if (p[0x566] == 0) {
                *(s16 *)(p + 0x564) = 50;
                func_L07_003ACA90(self, 6);
            } else {
                func_L07_003ACA90(self, 12);
            }
        }
        break;
    case 11:
        (*(u16 *)(p + 0x564))++;
        if (!(*(u16 *)(p + 0x564) % 2)) func_L07_003AD088(self);
        func_L01_00404808(func_L07_003AD180, self);
        func_L01_0045A9F0(self);
        func_L07_003ACF40(self);
        if (self[0x60] & 2) {
            func_L07_00334588(self);
            if (p[0x566] != 0) {
                if (self[0x43] != 8) func_003C3A10(self, 8, 0, 10);
                func_L07_003ACA90(self, 12);
            } else {
                *(s16 *)(p + 0x564) = 50;
                if (self[0x43] != 3) func_003C3A10(self, 3, 0, 10);
                func_L01_004450F0(self, 6, -1);
            }
        }
        break;
    case 12:
        func_L07_003ACD58(self, 4.0f);
        if (self[0x60] & 2) {
            *(s32 *)(p + 0x188) &= ~0x10;
            func_L07_003ACA90(self, 6);
        }
        break;
    case 13:
        func_L07_003ACD58(self, 8.0f);
        if (func_L07_00331008(*(u8 **)(p + 0x240), self)) func_L07_003ACA90(self, 6);
        break;
    }
}
/* localdecomp:end func_L07_003ABD18 */
