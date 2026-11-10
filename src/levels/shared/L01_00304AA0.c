#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128 __attribute__((mode(TI)));


INCLUDE_ASM("asm/levels", func_L01_00304AA0);

INCLUDE_ASM("asm/levels", func_L01_00304C48);

/* localdecomp:start func_L01_003057A0 */

extern u8 *D_L01_001DC5C4;
extern void func_L01_004C8668(s32);
extern s32 func_L01_004C85C8(u8 *, u8 *, f32, f32, f32);

void func_L01_003057A0(u8 *a0, s128 *a1, s128 *a2, s32 a3) {
    s32 *v = *(s32 **)(a0 + 104);
    s32 n;
    if (D_L01_001DC5C4 != 0) {
        u8 *e = D_L01_001DC5C4 + (v[15] << 6);
        *(s128 *)e = *a1;
        *(s128 *)(e + 16) = *a2;
        if (*(s32 *)(e + 56) >= 0) {
            func_L01_004C8668(*(s32 *)(e + 56));
        }
        *(s32 *)(e + 56) = func_L01_004C85C8(a0, e, 1.0f, 1.0f, 1.0f);
        *(s32 *)(e + 48) = a3;
        *(s32 *)(e + 52) = 0;
    }
    n = v[15];
    v[18] = n;
    v[15] = n + 1;
    if (n + 1 >= 35) {
        v[15] = 0;
        v[16] = 1;
    } else if (v[16] != 1) {
        v[17]++;
    }
}
/* localdecomp:end func_L01_003057A0 */

INCLUDE_ASM("asm/levels", func_L01_00305880);

INCLUDE_ASM("asm/levels", func_L01_00305970);

INCLUDE_ASM("asm/levels", func_L01_00305AB8);

INCLUDE_ASM("asm/levels", func_L01_00305C50);

INCLUDE_ASM("asm/levels", func_L01_00305CB8);

LINKER_REMNANT("asm/levels", func_L01_00305D28);

INCLUDE_ASM("asm/levels", func_L01_00305D30);

INCLUDE_ASM("asm/levels", func_L01_00305F00);

INCLUDE_ASM("asm/levels", func_L01_00306628);
