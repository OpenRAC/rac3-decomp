#include "common.h"

typedef struct S_005A5238 {
    u8 pad_000[0x164];
    s32 f164;
    s32 f168;
} S_005A5238;

typedef struct S_005A57F8 {
    u8 pad0[0x18];
    u16 f18;
    u8 pad1[0x148 - 0x1A];
    s32 f148;
    u8 pad2[0x15C - 0x14C];
    s32 f15C;
    u8 pad3[0x164 - 0x160];
    s32 f164;
    u8 pad4[0x16C - 0x168];
    s32 f16C;
} S_005A57F8;

/* localdecomp:start func_L39_005A5238 */
extern S_005A5238 D_001A43E0;

void func_L39_005A5238(void) {
    D_001A43E0.f164 = -1;
    *(s32 *)0x2403F8 = 6;
    D_001A43E0.f168 = -1;
}
/* localdecomp:end func_L39_005A5238 */

INCLUDE_ASM("asm/levels", func_L39_005A5260);

INCLUDE_ASM("asm/levels", func_L39_005A5288);

INCLUDE_ASM("asm/levels", func_L39_005A52F0);

INCLUDE_ASM("asm/levels", func_L39_005A5340);

INCLUDE_ASM("asm/levels", func_L39_005A53D0);

INCLUDE_ASM("asm/levels", func_L39_005A5400);

INCLUDE_ASM("asm/levels", func_L39_005A5460);

INCLUDE_ASM("asm/levels", func_L39_005A54A0);

INCLUDE_ASM("asm/levels", func_L39_005A54F8);

INCLUDE_ASM("asm/levels", func_L39_005A5590);

INCLUDE_ASM("asm/levels", func_L39_005A55E8);

INCLUDE_ASM("asm/levels", func_L39_005A56E8);

INCLUDE_ASM("asm/levels", func_L39_005A5728);

INCLUDE_ASM("asm/levels", func_L39_005A5798);

/* localdecomp:start func_L39_005A57F8 */
extern S_005A57F8 D_1A43E0;
extern s32 D_001D4CEC;

void func_L39_005A57F8(void)
{
    S_005A57F8 *s = &D_1A43E0;

    if (s->f15C != 2 || s->f164 >= 0)
        return;
    if (s->f16C != 0) {
        D_001D4CEC = *(s32 *)0x2403FC | 0x40;
        *(s32 *)0x2403F8 = 0x14;
    } else {
        s->f148 = 0;
        *(s32 *)0x2403F8 = 0x1F;
        s->f18 = 0;
    }
}
/* localdecomp:end func_L39_005A57F8 */

INCLUDE_ASM("asm/levels", func_L39_005A5860);

INCLUDE_ASM("asm/levels", func_L39_005A5920);

INCLUDE_ASM("asm/levels", func_L39_005A5990);

INCLUDE_ASM("asm/levels", func_L39_005A5A0C);
