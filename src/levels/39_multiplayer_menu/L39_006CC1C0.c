#include "common.h"

typedef struct S_006CC458 {
    u8 pad_000[0x164];
    s32 f164;
    s32 f168;
    s32 f16C;
    s32 f170;
    s32 f174;
    s32 f178;
    s32 f17C;
    s32 f180;
} S_006CC458;
typedef struct E_0047F0C0 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} E_0047F0C0;

INCLUDE_ASM("asm/levels", func_L39_006CC1C0);

/* localdecomp:start func_L39_006CC238 */
/* from rac2-decomp's func_002B0A18, renamed */
void func_L39_006CC238(int first, int second)
{
    extern int func_L01_004DFE80(int);
    extern void func_L39_006CC268(int, int);
    func_L39_006CC268(func_L01_004DFE80(first), second);
}
/* localdecomp:end func_L39_006CC238 */

INCLUDE_ASM("asm/levels", func_L39_006CC268);

INCLUDE_ASM("asm/levels", func_L39_006CC2A8);

INCLUDE_ASM("asm/levels", func_L39_006CC2E8);

INCLUDE_ASM("asm/levels", func_L39_006CC340);

INCLUDE_ASM("asm/levels", func_L39_006CC350);

INCLUDE_ASM("asm/levels", func_L39_006CC360);

INCLUDE_ASM("asm/levels", func_L39_006CC458);

INCLUDE_ASM("asm/levels", func_L39_006CC4F8);

INCLUDE_ASM("asm/levels", func_L39_006CC648);

INCLUDE_ASM("asm/levels", func_L39_006CC798);
