#include "common.h"

INCLUDE_ASM("asm/levels", func_L10_003C7C28);

INCLUDE_ASM("asm/levels", func_L10_003C7DA0);

INCLUDE_ASM("asm/levels", func_L10_003C7F18);

INCLUDE_ASM("asm/levels", func_L10_003C8048);

INCLUDE_ASM("asm/levels", func_L10_003C8238);

INCLUDE_ASM("asm/levels", func_L10_003C8428);

/* localdecomp:start func_L10_003C8698 */
typedef struct { u8 pad[0x30]; s32 f30; s32 f34; } S_3C8698;
extern s32 D_L10_001D6694;
extern S_3C8698 D_L10_001E5F00;
extern f32 func_0038DAB8(f32, f32);

void func_L10_003C8698(u8 *m) {
    s32 v = D_L10_001D6694;
    u8 *p;

    if (v == 2) {
        if (D_L10_001E5F00.f30 == v && (u32)(D_L10_001E5F00.f34 - 0x114) < 0x19) {
            *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(m + 0xF8), 0.12566371f);
        }
    } else {
        p = *(u8 **)(m + 0x24);
        *(u16 *)(m + 0x34) &= 0xFFBE;
        *(u16 *)(m + 0x34) |= *(u16 *)(p + 0x44) & 0x1000;
        *(s32 *)(m + 0x98) = *(s32 *)(p + 0x10);
    }
}
/* localdecomp:end func_L10_003C8698 */
