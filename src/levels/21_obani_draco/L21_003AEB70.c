#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L21_003AEB70);

INCLUDE_ASM("asm/levels", func_L21_003AF758);

INCLUDE_ASM("asm/levels", func_L21_003AF988);

INCLUDE_ASM("asm/levels", func_L21_003AFBA8);

INCLUDE_ASM("asm/levels", func_L21_003AFCF0);

/* localdecomp:start func_L21_003AFED0 */
extern u8 D_L21_002C4408[];

/* from rac4-decomp's func_L01_003CC6B0 */
s32 func_L21_003AFED0(s32 arg0, s32 arg1, u32 *arg2) {
    if (arg1 == 0) {
        *arg2 = 68;
        return (u32)D_L21_002C4408;
    }
    return 0;
}
/* localdecomp:end func_L21_003AFED0 */

/* localdecomp:start func_L21_003AFEF0 */
void func_L01_004450F0(s32, s32, s32);

s32 func_L21_003AFEF0(void *arg0, s32 arg1) {
    u8 *s = *(u8 **)((u8 *)arg0 + 0x68);
    if (*(u8 *)((u8 *)arg0 + 0x20) == 9) {
        return 0;
    }
    if (*(u8 *)((u8 *)arg0 + 0x95) == 2) {
        return 1;
    }
    *(s8 *)(s + 0x303) = arg1;
    func_L01_004450F0((s32)arg0, 4, 2);
    return 1;
}
/* localdecomp:end func_L21_003AFEF0 */

/* localdecomp:start func_L21_003AFF40 */
void func_L01_004450F0(s32, s32, s32);
s32 func_L21_003AFF40(void *arg0) {
    if (((*(u8 *)((u8 *)arg0 + 0x95)) != 1) && ((*(u8 *)((u8 *)arg0 + 0x20)) != 9)) {
        func_L01_004450F0((s32) arg0, 3, 1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L21_003AFF40 */

/* localdecomp:start func_L21_003AFF88 */
void func_L01_004450F0(s32, s32, s32);
s32 func_L21_003AFF88(void *arg0, s8 arg1) {
    u8 *obj = (u8 *)arg0;
    *(s8 *)(*(u8 **)(obj + 0x68) + 0x301) = arg1;
    if (obj[0x20] == 9) {
        return 0;
    }
    if (obj[0x95] != 3) {
        func_L01_004450F0((s32)obj, 7, 3);
    }
    return 1;
}
/* localdecomp:end func_L21_003AFF88 */

/* localdecomp:start func_L21_003AFFE0 */
s32 func_L21_003AFFE0(u8 *obj, u8 flag, u8 *a, u8 *b) {
    *(u8 *)(*(u8 **)(obj + 0x68) + 0x301) = flag;
    if (obj[0x20] == 9) {
        return 0;
    }
    if (obj[0x95] != 3) {
        func_L01_004450F0(obj, 8, 3);
        *(u128_t *)(obj + 0x10) = *(u128_t *)a;
        *(u128_t *)(obj + 0xF0) = *(u128_t *)b;
    }
    return 1;
}
/* localdecomp:end func_L21_003AFFE0 */

/* localdecomp:start func_L21_003B0068 */
void func_L21_003B0068(void *arg0, s32 arg1) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    if (arg1 != 0) {
        *(f32 *)(p + 0xEC) = 0.3f;
        *(f32 *)(p + 0xF0) = 0.0200000014f;
    } else {
        *(s32 *)(p + 0xEC) = 0;
        *(s32 *)(p + 0xF0) = 0;
    }
}
/* localdecomp:end func_L21_003B0068 */

/* localdecomp:start func_L21_003B00A0 */
void func_L21_003B00A0(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x300) = arg1;
}
/* localdecomp:end func_L21_003B00A0 */

/* localdecomp:start func_L21_003B00B0 */
s8 func_L21_003B00B0(void *arg0) {
    return (*(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x300));
}
/* localdecomp:end func_L21_003B00B0 */

/* localdecomp:start func_L21_003B00C0 */
void func_L21_003B00C0(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x301) = arg1;
}
/* localdecomp:end func_L21_003B00C0 */

/* localdecomp:start func_L21_003B00D0 */
s8 func_L21_003B00D0(void *arg0) {
    return (*(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x301));
}
/* localdecomp:end func_L21_003B00D0 */

/* localdecomp:start func_L21_003B00E0 */
void func_L21_003B00E0(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x302) = arg1;
}
/* localdecomp:end func_L21_003B00E0 */

/* localdecomp:start func_L21_003B00F0 */
s8 func_L21_003B00F0(void *arg0) {
    return (*(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x302));
}
/* localdecomp:end func_L21_003B00F0 */

/* localdecomp:start func_L21_003B0100 */
void func_L01_004450F0(s32, s32, s32);
s32 func_L21_003B0100(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x95)) == 4) {
        if ((*(u8 *)((u8 *)arg0 + 0x20)) == 9) {
            func_L01_004450F0((s32) arg0, 1, -1);
        }
    }
    return (*(u8 *)((u8 *)arg0 + 0x95)) == 4;
}
/* localdecomp:end func_L21_003B0100 */

/* localdecomp:start func_L21_003B0158 */
s32 func_L21_003B0158(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x95)) == 3;
}
/* localdecomp:end func_L21_003B0158 */

/* localdecomp:start func_L21_003B0168 */
s32 func_L21_003B0168(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x95)) == 1;
}
/* localdecomp:end func_L21_003B0168 */

/* localdecomp:start func_L21_003B0178 */
s32 func_L21_003B0178(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x95)) == 2;
}
/* localdecomp:end func_L21_003B0178 */

/* localdecomp:start func_L21_003B0188 */
s32 func_L21_003B0188(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x95)) == 0;
}
/* localdecomp:end func_L21_003B0188 */
