#include "common.h"

typedef struct {
    u8 pad00[0x7C];
    u16 x7C;
} Obj_003B2B90;

INCLUDE_ASM("asm/levels", func_L19_003B1A80);

INCLUDE_ASM("asm/levels", func_L19_003B1E08);

INCLUDE_ASM("asm/levels", func_L19_003B2190);

INCLUDE_ASM("asm/levels", func_L19_003B2290);

INCLUDE_ASM("asm/levels", func_L19_003B2370);

INCLUDE_ASM("asm/levels", func_L19_003B2538);

INCLUDE_ASM("asm/levels", func_L19_003B2748);

INCLUDE_ASM("asm/levels", func_L19_003B2880);

INCLUDE_ASM("asm/levels", func_L19_003B2968);

/* localdecomp:start func_L19_003B2AC8 */
extern void func_L19_003B2968(u8 *a0, s32 a1);

void func_L19_003B2AC8(u8 *a0)
{
    s32 i;
    u16 flags;

    flags = *(u16 *)(a0 + 0x7C);
    if (flags & 2) {
        *(u16 *)(a0 + 0x7C) = flags | 0x100;
    }
    for (i = 0; i < 16; i++) {
        func_L19_003B2968(a0, i);
    }
}
/* localdecomp:end func_L19_003B2AC8 */

INCLUDE_ASM("asm/levels", func_L19_003B2B28);

INCLUDE_ASM("asm/levels", func_L19_003B2B90);

/* localdecomp:start func_L19_003B2C48 */
extern s32 func_L19_003B2B90(u8 *, s32);

s32 func_L19_003B2C48(u8 *self, f32 a, f32 b, f32 c)
{
    s32 i;
    f32 k;
    f32 lo;

    if (self[0x95] == 5) {
        return 0;
    }
    k = c * 0.13333300f;
    lo = c - k;
    i = 6;
    do {
        if (lo <= a) {
            if (b < lo) {
                func_L19_003B2B90(self, i);
            }
        }
        i--;
        lo -= k;
    } while (i != 0);
    return 1;
}
/* localdecomp:end func_L19_003B2C48 */

INCLUDE_ASM("asm/levels", func_L19_003B2D00);

/* localdecomp:start func_L19_003B2EA8 */
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern void func_003D9508(void *p, s32 a, u32 color, s32 b, f32 f0, f32 f1, f32 f2);

void func_L19_003B2EA8(u8 *a0) {
    u8 buf[0x10];
    func_003C2F58(a0, 1, buf);
    func_003D9508(buf, 0x2E, 0x8080FFFF, 1, 0.45f, 0.0f, 0.0f);
    func_003D9508(buf, 0xC, 0x8020F020, 1, 0.45f, 0.0f, 0.0f);
}
/* localdecomp:end func_L19_003B2EA8 */
