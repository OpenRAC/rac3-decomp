#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_00351C58);

INCLUDE_ASM("asm/levels", func_L07_00352510);

INCLUDE_ASM("asm/levels", func_L07_00352758);

/* localdecomp:start func_L07_00352A58 */
void func_L07_00334740();
void func_L07_00352AC8(s32, s32);

void func_L07_00352A58(s32 arg0) {
    func_L07_00334740();
    func_L07_00352AC8(arg0, 1);
}
/* localdecomp:end func_L07_00352A58 */

/* localdecomp:start func_L07_00352A88 */
void func_L07_00352AC8(s32, s32);
void func_L07_00334800();

void func_L07_00352A88(s32 arg0) {
    *(f32 *)(arg0 + 0x2C) = *(f32 *)(*(s32 *)(arg0 + 0x24) + 0x24);
    func_L07_00334800();
    func_L07_00352AC8(arg0, 2);
}
/* localdecomp:end func_L07_00352A88 */

INCLUDE_ASM("asm/levels", func_L07_00352AC8);

/* localdecomp:start func_L07_00352E88 */
extern f32 func_L07_00353D60(u8 *);
extern void func_L07_00352AC8(s32, s32);
extern void func_L07_00352F30(u8 *, f32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0045AA10(u8 *);
extern u8 D_L07_001DD604[];

void func_L07_00352E88(u8 *self) {
    u8 *o;
    f32 r;
    f32 t;
    f32 *p;

    o = *(u8 **)(self + 0x68);
    t = func_L07_00353D60(self);
    p = (f32 *)(D_L07_001DD604 + (s32)o[0x464] * 8);
    r = *p - 0.5f;
    if (r > t) {
        f32 d;
        func_L07_00352AC8((s32)self, 8);
        d = func_0038D160(*(f32 *)(o + 0x130) - *(f32 *)(self + 0x10),
                          *(f32 *)(o + 0x134) - *(f32 *)(self + 0x14));
        ((void (*)(u8 *, f32))func_L01_0045AA10)(self, d);
    } else {
        func_L07_00352F30(self, r);
    }
}
/* localdecomp:end func_L07_00352E88 */

INCLUDE_ASM("asm/levels", func_L07_00352F30);

INCLUDE_ASM("asm/levels", func_L07_00352FF0);

INCLUDE_ASM("asm/levels", func_L07_00353178);

/* localdecomp:start func_L07_003532D0 */
extern f32 func_L07_00353D60(u8 *);
void func_L07_00352AC8(s32, s32);

void func_L07_003532D0(u8 *arg0) {
    u8 *p;
    f32 t;

    p = *(u8 **)(arg0 + 0x68);
    t = func_L07_00353D60(arg0) - *(f32 *)(D_L07_001DD604 + p[0x464] * 8);
    if (t < 4.0f) {
        func_L07_00352AC8((s32)arg0, 8);
    } else if (t < 8.0f) {
        func_L07_00352AC8((s32)arg0, 9);
    } else {
        func_L07_00352AC8((s32)arg0, 10);
    }
}
/* localdecomp:end func_L07_003532D0 */

INCLUDE_ASM("asm/levels", func_L07_00353378);

INCLUDE_ASM("asm/levels", func_L07_00353498);

/* localdecomp:start func_L07_003535B0 */
extern s32 func_00382498(s32, s32);
extern void func_L07_00352AC8(s32, s32);

void func_L07_003535B0(s32 arg0) {
    func_L07_00352AC8(arg0, func_00382498(0, 1) + 0x15);
}
/* localdecomp:end func_L07_003535B0 */

INCLUDE_ASM("asm/levels", func_L07_003535E8);

/* localdecomp:start func_L07_00353730 */
s32 func_L07_00331008(s32, s32);
void func_L07_003535B0(s32);
void func_L07_00352AC8(s32, s32);

void func_L07_00353730(s32 arg0) {
    u8 *handle = *(u8 **)(arg0 + 0x68);

    if (*(u8 *)(arg0 + 0x60) & 2) {
        if (handle[0x466] != 0) {
            func_L07_003535B0(arg0);
            handle[0x466] = 0;
        } else {
            if (func_L07_00331008(*(s32 *)(handle + 0x240), arg0) == 0) {
                func_L07_00352AC8(arg0, 6);
            } else {
                func_L07_00352AC8(arg0, 7);
            }
        }
    }
}
/* localdecomp:end func_L07_00353730 */

/* localdecomp:start func_L07_003537B0 */
extern s32 func_L01_0045A9F0(void *);
extern s32 func_L07_00331008(s32, s32);
extern void func_L07_00352AC8(s32, s32);

void func_L07_003537B0(s32 arg0) {
    u8 *handle = *(u8 **)(arg0 + 0x68);

    func_L01_0045A9F0((void *)arg0);
    if (*(u8 *)(arg0 + 0x60) & 2) {
        handle[0x467] = 0;
        if (func_L07_00331008(*(s32 *)(handle + 0x240), arg0) == 0) {
            func_L07_00352AC8(arg0, 6);
        } else {
            func_L07_00352AC8(arg0, 7);
        }
    }
}
/* localdecomp:end func_L07_003537B0 */

INCLUDE_ASM("asm/levels", func_L07_00353820);

INCLUDE_ASM("asm/levels", func_L07_003538A0);

INCLUDE_ASM("asm/levels", func_L07_00353980);

INCLUDE_ASM("asm/levels", func_L07_00353AB0);

INCLUDE_ASM("asm/levels", func_L07_00353D20);

/* localdecomp:start func_L07_00353D60 */
void func_0038CF38(void *, s32);

void func_L07_00353D60_00353D60(void *arg0) __asm__("func_L07_00353D60");
void func_L07_00353D60_00353D60(void *arg0) {
    func_0038CF38(arg0 + 0x10, (*(s32 *)((u8 *)arg0 + 0x68)) + 0x130);
}
/* localdecomp:end func_L07_00353D60 */

/* localdecomp:start func_L07_00353D88 */
typedef struct {
    u8 pad[0x68];
    u8 *p68;
} S_353D88;

void func_L07_00353D88(S_353D88 *a0) {
    u8 *p = a0->p68;

    p[0x468] = 0;
    p[0x469] = 0;
}
/* localdecomp:end func_L07_00353D88 */

INCLUDE_ASM("asm/levels", func_L07_00353D98);

INCLUDE_ASM("asm/levels", func_L07_00353E10);

INCLUDE_ASM("asm/levels", func_L07_00353FF0);
