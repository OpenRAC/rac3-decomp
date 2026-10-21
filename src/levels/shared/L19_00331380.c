#include "common.h"

INCLUDE_ASM("asm/levels", func_L19_00331380);

INCLUDE_ASM("asm/levels", func_L19_00332948);

INCLUDE_ASM("asm/levels", func_L19_00332D38);

INCLUDE_ASM("asm/levels", func_L19_00333160);

INCLUDE_ASM("asm/levels", func_L19_00333468);

/* localdecomp:start func_L19_00333580 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_00332BA8;

extern s32 func_00382380(void *, s32, s32);
extern u16 *D_L19_0021C260[];
extern u8 *D_L19_001DF71C;
extern u8 *D_L19_001DF800;
extern s32 D_L19_001DF758 __attribute__((section(".sdata")));

void func_L19_00333580(u8 *arg0, Vec4_00332BA8 v) {
    u8 *s2;
    u16 *s1;
    s32 idx;
    s32 start;
    u8 *ent;
    u8 *s0;
    u8 *m;

    s2 = *(u8 **)(arg0 + 104);
    *(Vec4_00332BA8 *)(s2 + 960) = v;
    start = *(s32 *)(s2 + 912);
    if (start < 0) {
        return;
    }
    for (s1 = D_L19_0021C260[start];
         (idx = *(s32 *)(s2 + 912), (idx & 0xFF) != 255) && D_L19_001DF758 >= idx && s1 != 0 &&
         ((s16)s1[-1] >= 0 || s1 == D_L19_0021C260[idx]);
         s1++) {
        ent = D_L19_001DF71C + ((*s1 & 0x7FFF) << 8);
        if (ent == 0) {
            return;
        }
        s0 = *(u8 **)(ent + 104);
        if (func_00382380(s2 + 960, *(s32 *)s0, 0) != 0) {
            if (*(s32 *)(s0 + 8) < 0 || func_00382380(arg0 + 16, *(s32 *)(s0 + 8), 0) != 0) {
                m = (u8 *)((*(s32 *)(s0 + 4) << 7) + (s32)D_L19_001DF800);
                if (__builtin_fabsf(*(f32 *)(m + 56) - *(f32 *)(arg0 + 24)) < 2.5f) {
                    *(u128_t *)(s2 + 960) = *(u128_t *)(m + 48);
                    return;
                }
            }
        }
    }
}
/* localdecomp:end func_L19_00333580 */

INCLUDE_ASM("asm/levels", func_L19_003336E0);

INCLUDE_ASM("asm/levels", func_L19_003337D8);

INCLUDE_ASM("asm/levels", func_L19_00333A80);

INCLUDE_ASM("asm/levels", func_L19_00333C60);

INCLUDE_ASM("asm/levels", func_L19_00333DC0);

INCLUDE_ASM("asm/levels", func_L19_00333FC0);

INCLUDE_ASM("asm/levels", func_L19_003340A0);

INCLUDE_ASM("asm/levels", func_L19_003343A8);

INCLUDE_ASM("asm/levels", func_L19_003345D0);

INCLUDE_ASM("asm/levels", func_L19_003347B0);

INCLUDE_ASM("asm/levels", func_L19_00334958);

INCLUDE_ASM("asm/levels", func_L19_00334B10);

INCLUDE_ASM("asm/levels", func_L19_00334CF0);

INCLUDE_ASM("asm/levels", func_L19_00334F80);

INCLUDE_ASM("asm/levels", func_L19_00335130);

INCLUDE_ASM("asm/levels", func_L19_00335210);

INCLUDE_ASM("asm/levels", func_L19_00335330);
