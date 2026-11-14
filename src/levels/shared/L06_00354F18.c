#include "common.h"

/* localdecomp:start func_L06_00354F18 */
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
extern void func_L06_00351930(u8 *a0, u8 *a1, s32 a2, s32 a3, s32 t0);
extern s32 func_L01_004561E0(void *);
extern f32 func_003C3D30(void *, s32, void *, f32);
s32 func_L06_00354F18(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    f32 f;
    if (*(s32 *)(v + 0x26C) == 2 && (a0[0x43] == 2 || a0[0x43] == 0x11)) {
        if ((a0[0x60] & 2) || a0[0x43] == 2) {
            if (*(s32 *)(v + 0x33C) != 0) {
                func_L06_00351930(a0, v, 0x11, 0, 10);
                *(s32 *)(v + 0x33C) = 0;
            } else if (0.0f < *(f32 *)(v + 0x338)) {
                func_L01_004450F0(a0, 1, 3);
                func_L06_00351930(a0, v, 2, 0, 10);
            } else {
                func_L01_004450F0(a0, 1, 5);
                func_L06_00351930(a0, v, 2, 0, 10);
            }
        }
        return 1;
    }
    if (func_L01_004561E0(a0)) {
        func_L06_00351930(a0, v, 1, 0, 10);
    } else if (a0[0x43] == 1 && (a0[0x60] & 2)) {
        func_L06_00351930(a0, v, 2, 0, 10);
    }
    f = func_003C3D30(a0 + 0x10, 0, a0, 1.0f);
    if (0.0f < f) {
        *(f32 *)(a0 + 0x18) = f;
    }
    return 0;
}
/* localdecomp:end func_L06_00354F18 */

/* localdecomp:start func_L06_003550B0 */
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
extern void func_L06_00351930(u8 *a0, u8 *a1, s32 a2, s32 a3, s32 t0);
s32 func_L06_003550B0(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    f32 f;
    if (a0[96] & 2) {
        func_L01_004450F0(a0, 1, 0);
        func_L06_00351930(a0, s1, 0, 0, 0);
        f = (*(f32 *)(s1 + 788) + *(f32 *)(s1 + 796)) * 0.5f;
        if (*(f32 *)(s1 + 616) < f) {
            *(f32 *)(s1 + 616) = f;
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_003550B0 */

/* localdecomp:start func_L06_00355148 */
extern void func_L06_00351930(u8 *a0, u8 *a1, s32 a2, s32 a3, s32 t0);
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
extern int func_L01_004561E0(void *a0);
extern void func_L06_00353208(float f, void *a0, void *a1);

int func_L06_00355148(void *moby)
{
    char *pv = *(char **)((char *)moby + 104);

    if (func_L01_004561E0(moby)) {
        func_L06_00353208(*(float *)(pv + 824), moby, pv);
        *(int *)(pv + 824) = 0;
        ((void (*)(void *a0, int a1, int a2))func_L01_004450F0)(moby, 3, -1);
        return 1;
    }
    if (*(unsigned char *)((char *)moby + 32) == 15) {
        ((void (*)(void *a0, int a1, int a2))func_L01_004450F0)(moby, 1, 5);
        ((void (*)(void *a0, void *a1, int a2, int a3, int t0))func_L06_00351930)(moby, pv, 2, 0, 10);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00355148 */

INCLUDE_ASM("asm/levels", func_L06_003551E8);

INCLUDE_ASM("asm/levels", func_L06_003552F8);

INCLUDE_ASM("asm/levels", func_L06_00355610);

INCLUDE_ASM("asm/levels", func_L06_003558D0);

INCLUDE_ASM("asm/levels", func_L06_00355C20);

/* localdecomp:start func_L06_00355F90 */
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern f32 func_L06_00353160(u8 *, s32);
s32 func_L06_00355F90(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    if (func_L01_004561B8(a0)) {
        *(s32 *)(v + 0x350) = 1;
        *(f32 *)(v + 0x354) = func_L06_00353160(v, *(s32 *)(v + 0x344));
        *(f32 *)(v + 0xA4) = 0.15f;
        func_L01_0045BD78(a0, 0.004f, 0.20000002f, 0.010053097f, 0.25132743f);
        func_L06_00351930(a0, v, 6, 0, 10);
    }
    func_L06_00351220(a0, v);
    if (a0[0x60] & 2) {
        func_L01_004450F0(a0, 6, -1);
        func_L06_00351930(a0, v, 7, 0, 5);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00355F90 */

INCLUDE_ASM("asm/levels", func_L06_00356088);

INCLUDE_ASM("asm/levels", func_L06_003564A0);

/* localdecomp:start func_L06_003565B8 */
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
s32 func_L06_003565B8(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    if (func_L01_004561B8(a0)) {
        *(s32 *)(v + 0x384) = 0;
        *(s32 *)(v + 0x350) = 1;
        *(f32 *)(v + 0x354) = 2.0f;
        *(f32 *)(v + 0xA4) = 0.15f;
        func_L01_0045BD78(a0, 0.004f, 0.20000002f, 0.010053097f, 0.25132743f);
        func_L06_00351930(a0, v, 6, 0, 10);
    }
    func_L06_00351220(a0, v);
    if (a0[0x60] & 2) {
        func_L01_004450F0(a0, 9, -1);
        func_L06_00351930(a0, v, 7, 0, 5);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_003565B8 */

INCLUDE_ASM("asm/levels", func_L06_003566B0);
