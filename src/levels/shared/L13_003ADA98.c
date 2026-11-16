#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3AC810;

/* localdecomp:start func_L13_003ADA98 */
extern void func_L13_003AE698(u8 *a);

void func_L13_003ADA98(u8 *a, u8 *b) {
    if (b[939] != 0) {
        a[149] = 0;
    } else {
        a[149] = 1;
    }
    b[943] = 0;
    func_L13_003AE698(a);
}
/* localdecomp:end func_L13_003ADA98 */

INCLUDE_ASM("asm/levels", func_L13_003ADAD0);

INCLUDE_ASM("asm/levels", func_L13_003ADE00);

INCLUDE_ASM("asm/levels", func_L13_003AE508);

/* localdecomp:start func_L13_003AE5F8 */

extern S_3AC810 *func_L01_0043B548(s32, s32);
extern void func_003C2880(void *);

void func_L13_003AE5F8(u8 *m, s32 b) {
    if (*(s32 *)(*(u8 **)(m + 0x68) + 0x260) != 0) {
        S_3AC810 *v = func_L01_0043B548(6625, 108);
        v->f0(m);
        if (b) {
            v->f4(m);
        }
    } else {
        func_003C2880(m);
    }
}
/* localdecomp:end func_L13_003AE5F8 */

/* localdecomp:start func_L13_003AE678 */
extern void func_L13_003AE5F8_003AE678(u8 *, s32);

/* from rac2-decomp's func_0012B3C0, renamed (constants adapted) */
void func_L13_003AE678(u8 *m)
{
    func_L13_003AE5F8_003AE678(m, 1);
}
/* localdecomp:end func_L13_003AE678 */

INCLUDE_ASM("asm/levels", func_L13_003AE698);

/* localdecomp:start func_L13_003AE880 */
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L13_003AE8C8(u8 *);
void func_L13_003AE880(u8 *a0) {
    if (*(s32 *)(*(u8 **)(a0 + 104) + 896) != -1) {
        func_L01_004450F0(a0, 8, -1);
    } else {
        func_L13_003AE8C8(a0);
    }
}
/* localdecomp:end func_L13_003AE880 */

/* localdecomp:start func_L13_003AE8C8 */
/* PAL port of the NTSC-U match src/us/levels/func_L13_003ACAE0.c */
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L13_003AE8C8(u8 *object) {
    u8 *child = *(u8 **)(object + 0x68);
    if (child[0x3AE] != 0) {
        if (object[0x43] != 0) {
            func_003C3A10(object, 0, 0, 3);
        }
        func_L01_004450F0(object, 0x10, -1);
    } else {
        s32 state = *(s32 *)(child + 0x390);
        if (state != -1) {
            if (object[0x43] != 0x18) {
                func_003C3A10(object, 0x18, 0, 3);
            }
            func_L01_004450F0(object, 0xA, -1);
        } else {
            if (object[0x43] != 0x1A) {
                func_003C3A10(object, 0x1A, 0, 7);
            }
            func_L01_004450F0(object, 0xD, -1);
        }
    }
}
/* localdecomp:end func_L13_003AE8C8 */

/* localdecomp:start func_L13_003AE990 */
extern void func_L13_003AEA10(u8 *arg0);
extern void func_L13_003AEB48(void *);
extern void func_L13_003AEBC8(void *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L13_003AE990(u8 *obj) {
    u8 *d = *(u8 **)(obj + 0x68);

    if (d[0x3AB] == 0 && *(s32 *)(d + 0x380) != -1) {
        if (d[0x3AA] != 0) {
            func_L13_003AEB48(obj);
        } else {
            func_L13_003AEBC8(obj);
        }
        func_L01_004450F0(obj, 0x13, -1);
    } else {
        func_L13_003AEA10(obj);
    }
}
/* localdecomp:end func_L13_003AE990 */

/* localdecomp:start func_L13_003AEA10 */
extern void func_L13_003AEB48(void *);
extern void func_L13_003AEBC8(void *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L13_003AEA10(u8 *arg0)
{
    u8 *v = *(u8 **)(arg0 + 104);

    if (*(s32 *)(v + 908) != -1) {
        ((void (*)(u8 *))func_L13_003AEBC8)(arg0);
        func_L01_004450F0(arg0, 23, -1);
    } else if (*(s32 *)(v + 916) != -1) {
        ((void (*)(u8 *))func_L13_003AEBC8)(arg0);
        func_L01_004450F0(arg0, 21, -1);
    } else {
        ((void (*)(u8 *))func_L13_003AEB48)(arg0);
        func_L01_004450F0(arg0, 22, -1);
    }
}
/* localdecomp:end func_L13_003AEA10 */

/* localdecomp:start func_L13_003AEA98 */
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern f32 func_L01_0040E570(u8 *, u8 *);
extern f32 D_L13_001DE6B4;

void func_L13_003AEA98(u8 *arg0) {
    f32 r = func_L01_0040E570(arg0 + 0x10, *(u8 **)(arg0 + 0x68) + 0x130);

    if (r < D_L13_001DE6B4 * D_L13_001DE6B4) {
        if (arg0[0x43] != 13) {
            func_003C3A10(arg0, 13, 0, 3);
        }
        func_L01_004450F0(arg0, 33, -1);
    } else {
        if (arg0[0x43] != 9) {
            func_003C3A10(arg0, 9, 3, 13);
        }
        func_L01_004450F0(arg0, 28, -1);
    }
}
/* localdecomp:end func_L13_003AEA98 */
