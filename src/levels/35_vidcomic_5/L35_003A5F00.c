#include "common.h"

INCLUDE_ASM("asm/levels", func_L35_003A5F00);

/* localdecomp:start func_L35_003A5FD8 */
extern u8 D_001A4C60[];
extern s32 func_L01_00456500(void *, s32);

s32 func_L35_003A5FD8(u8 *a0, f32 *a1, f32 *a2, s32 *a3) {
    u8 *base;
    u8 *s;
    s32 s4 = 0;
    s32 s5 = 0;
    s32 key;

    base = *(u8 **)(a0 + 0x68);
    if (a1 != 0) {
        *(s32 *)a1 = 0;
    }
    s = base;
    do {
        key = *(s32 *)s;
        if (key != -1 && func_L01_00456500(D_001A4C60, key) != 0) {
            s5 = 1;
            s4++;
            if (a1 != 0) {
                *a1 = *(f32 *)(s + 0x10);
            }
            if (a2 != 0) {
                *a2 = *(f32 *)(s + 0x20);
            }
            if (a3 != 0) {
                *a3 = *(s32 *)(s + 0x30);
            }
        }
        s += 4;
    } while ((s32)s < (s32)(base + 0x10));
    if (s5 != 0 && a1 != 0) {
        *a1 = *a1 / (f32)s4;
    }
    return s5;
}
/* localdecomp:end func_L35_003A5FD8 */

/* localdecomp:start func_L35_003A60F0 */
extern u8 D_001A4BE0[];
extern s32 func_L01_00456250(void *);
extern void func_L01_004561B8(void *);
extern void func_003C4138(void *, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
__asm__(".extern D_L35_001DEAA0, 4");
extern f32 D_L35_001DEAA0;
__asm__(".extern D_L35_001E1E3C, 16");
extern f32 D_L35_001E1E3C;
extern f32 D_L35_001DEAAC;
__asm__(".extern D_L35_001DD920, 16");
extern f32 D_L35_001DD920;
extern f32 D_L35_001E2500[];

static __inline__ s32 heroState_003A60F0(void) {
    u8 *hero = D_001A4BE0;
    return *(s32 *)(hero + 0x25C4);
}

void func_L35_003A60F0(void *a0) {
    u8 *obj = *(u8 **)((u8 *)a0 + 0x68);
    f32 a;
    f32 b;
    s32 c;
    f32 v;
    f32 t;
    f32 w;
    s32 st;

    func_L01_004561B8(a0);
    if (func_L35_003A5FD8(a0, &a, &b, &c) != 0 && func_L01_00456250(a0) != 0) {
        func_003C4138(obj + 0x58, a, D_L35_001DEAAC);
        v = *(f32 *)(obj + 0x58);
        w = *(f32 *)(obj + 0x48) + v;
        D_L35_001DD920 = v + 2.0f;
        *(f32 *)(obj + 0x48) = w;
        if ((*(u8 *)&c ^ 1) & 1 || (st = heroState_003A60F0(), st != 0xA2 && st != 0xA7 && st != 0x9C)) {
            t = D_L35_001E2500[2] - b;
            if (w < t) {
                *(f32 *)(obj + 0x48) = t;
            }
        }
        if (*(f32 *)(obj + 0x48) > *(f32 *)(obj + 0x50)) {
            *(f32 *)(obj + 0x48) = *(f32 *)(obj + 0x50);
        }
    } else {
        func_L01_004450F0(a0, 1, -1);
    }
    st = heroState_003A60F0();
    if (st != 0x74 && st != 0x9F && st != 0xA0) {
        D_L35_001E1E3C = *(f32 *)(obj + 0x48) + D_L35_001DEAA0;
    }
}
/* localdecomp:end func_L35_003A60F0 */

/* localdecomp:start func_L35_003A6240 */
extern s32 func_L35_003A5FD8(u8 *, f32 *, f32 *, s32 *);
extern s32 func_L01_00456250(void *);
extern void func_L01_004450F0(void *, s32, s32);
__asm__(".extern D_L35_001DEAA0, 4");
extern f32 D_L35_001DEAA0;
__asm__(".extern D_L35_001E1E3C, 16");
extern f32 D_L35_001E1E3C;

void func_L35_003A6240(u8 *a0) {
    u8 *obj = *(u8 **)(a0 + 0x68);
    f32 f;

    if (func_L35_003A5FD8(a0, 0, 0, 0) != 0) {
        if (func_L01_00456250(a0) != 0) {
            func_L01_004450F0(a0, 2, -1);
        }
    }
    f = *(f32 *)(obj + 0x48);
    D_L35_001E1E3C = f + D_L35_001DEAA0;
}
/* localdecomp:end func_L35_003A6240 */
