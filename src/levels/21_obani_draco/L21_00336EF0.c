#include "common.h"

INCLUDE_ASM("asm/levels", func_L21_00336EF0);

/* localdecomp:start func_L21_00337BB8 */
void func_L01_004450F0(s32, s32, s32);
s32 func_L21_00337BB8(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) != 0) {
        return 0;
    }
    *(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x7D) = 0;
    func_L01_004450F0((s32) arg0, 1, -1);
    return 1;
}
/* localdecomp:end func_L21_00337BB8 */

INCLUDE_ASM("asm/levels", func_L21_00337BF0);

INCLUDE_ASM("asm/levels", func_L21_00337F08);

/* localdecomp:start func_L21_00338090 */
extern s32 func_L01_0043B568(s32, s32, s32);
extern s32 func_00382468(s32);
extern s32 func_L21_00337F08(void *, s32, s32);
extern s32 D_L21_001DED9C[];

void func_L21_00338090(void *arg0) {
    s32 base;
    s32 k;
    s32 a;
    s32 v;
    u8 *r;

    base = D_L21_001DED9C[0];
    base += *(s32 *)((u8 *)(*(void **)((u8 *)arg0 + 0x68)) + 0x24) << 8;
    r = (u8 *)func_L01_0043B568(0x1BC5, 0, 0x44);
    a = func_00382468(2);
    v = 1;
    if (a == 0) {
        v = -1;
    }
    v += ((s32 (*)(s32))(*(void **)(r + 0x2C)))(base);
    if (v >= 6) {
        v = 0;
    } else {
        if (v <= -1) {
            v = 5;
        }
    }
    func_L21_00337F08(arg0, v, 0);
}
/* localdecomp:end func_L21_00338090 */

/* localdecomp:start func_L21_00338150 */
extern s32 func_L01_0043B568(s32, s32, s32);
extern s32 D_L21_001DED9C[];
void func_L21_00338150(void *arg0) {
    u8 *r;
    s32 base;
    base = D_L21_001DED9C[0] + ((*(s32 *)(*(u8 **)((u8 *)arg0 + 0x68) + 0x24)) << 8);
    r = (u8 *)func_L01_0043B568(0x1BC5, 0, 0x44);
    if (((s32 (*)(s32))(*(void **)(r + 0x30)))(base) != 0) {
        return;
    }
    if (((s32 (*)(s32))(*(void **)(r + 0x34)))(base) != 0) {
        return;
    }
    ((void (*)(s32, s32))(*(void **)(r + 0x8)))(base, 0);
}
/* localdecomp:end func_L21_00338150 */

INCLUDE_ASM("asm/levels", func_L21_003381D8);

INCLUDE_ASM("asm/levels", func_L21_003383A8);

INCLUDE_ASM("asm/levels", func_L21_00338638);

INCLUDE_ASM("asm/levels", func_L21_003387B0);

INCLUDE_ASM("asm/levels", func_L21_00338B00);

INCLUDE_ASM("asm/levels", func_L21_00338C20);

/* localdecomp:start func_L21_00338CC8 */
extern s32 D_L21_001DED9C[];

s32 func_L21_00338CC8(void *arg0, u8 *arg1) {
    s32 base;
    s32 prod;
    s32 r;
    u8 *q;
    f32 lim;
    base = D_L21_001DED9C[0];
    base += *(s32 *)((u8 *)(*(void **)((u8 *)arg0 + 0x68)) + 0x24) << 8;
    q = *(u8 **)(base + 0x68);
    if (arg1 != 0) {
        prod = *(s16 *)(q + 0x34) * *arg1;
        lim = (f32)prod * 0.01f;
        r = 1;
        if (!(*(f32 *)(q + 0x30) < lim)) {
            r = 0;
        }
        return r;
    }
    return 0;
}
/* localdecomp:end func_L21_00338CC8 */

INCLUDE_ASM("asm/levels", func_L21_00338D38);

/* localdecomp:start func_L21_00338D60 */
s32 func_L21_00338D60(void *arg0, u8 *arg1) {
    switch (*(u8 *)((u8 *)arg0 + 0xBC)) {
    case 1:
        return arg1[1];
    case 2:
        return arg1[2];
    case 0:
        return arg1[3];
    case 3:
        return arg1[4];
    default:
        return 0;
    }
}
/* localdecomp:end func_L21_00338D60 */
