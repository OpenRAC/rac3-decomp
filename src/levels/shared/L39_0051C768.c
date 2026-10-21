#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0051C768);

INCLUDE_ASM("asm/levels", func_L39_0051CC68);

INCLUDE_ASM("asm/levels", func_L39_0051CEF8);

INCLUDE_ASM("asm/levels", func_L39_0051DB38);

INCLUDE_ASM("asm/levels", func_L39_0051DD30);

INCLUDE_ASM("asm/levels", func_L39_0051E200);

/* localdecomp:start func_L39_0051E230 */
extern s32 D_L39_0024D450[];

s32 func_L39_0051E230(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_L39_0024D450[i] == 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L39_0051E230 */

/* localdecomp:start func_L39_0051E268 */
extern s32 D_L39_0024D490[];
extern s32 D_L39_0024D450[];
extern s32 D_L39_001E1D80;
void func_L39_0051E268(s32 a0) {
    s32 n = D_L39_0024D490[0];
    s32 i = 0;
    s32 *p = D_L39_0024D450;
    do {
        if (*p == a0) {
            *p = 0;
            n--;
            break;
        }
        i++;
        p++;
    } while (i < 16);
    D_L39_001E1D80 = n;
}
/* localdecomp:end func_L39_0051E268 */

INCLUDE_ASM("asm/levels", func_L39_0051E2B0);

INCLUDE_ASM("asm/levels", func_L39_0051E370);

INCLUDE_ASM("asm/levels", func_L39_0051E9A8);

INCLUDE_ASM("asm/levels", func_L39_0051EB38);

INCLUDE_ASM("asm/levels", func_L39_0051ED58);

INCLUDE_ASM("asm/levels", func_L39_0051EF98);

/* localdecomp:start func_L39_0051F6B8 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern s32 func_L01_00457458(s32, s32);
extern void func_003C2880(u8 *);

void func_L39_0051F6B8(u8 *m) {
    Vec4 v;
    u8 *p;

    if (m == 0) {
        return;
    }
    if (m[32] == 254) {
        return;
    }
    if (m[32] == 253) {
        return;
    }
    p = *(u8 **)(m + 104);
    if (p == 0) {
        return;
    }
    if (!func_L01_00457458(*(s16 *)(m + 170), *(s32 *)(p + 40))) {
        func_003C2880(m);
    } else {
        v.q = *(u128_t *)(m + 16);
        v.f[3] = 2.0f;
    }
}
/* localdecomp:end func_L39_0051F6B8 */
