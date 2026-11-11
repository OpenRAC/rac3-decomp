#include "common.h"
typedef struct { s32 id; s32 x4[4]; } Rec14;

INCLUDE_ASM("asm/levels", func_L23_003A6688);

INCLUDE_ASM("asm/levels", func_L23_003A6838);

INCLUDE_ASM("asm/levels", func_L23_003A6970);

INCLUDE_ASM("asm/levels", func_L23_003A6A60);

INCLUDE_ASM("asm/levels", func_L23_003A6B98);

INCLUDE_ASM("asm/levels", func_L23_003A6D18);

INCLUDE_ASM("asm/levels", func_L23_003A6D70);

INCLUDE_ASM("asm/levels", func_L23_003A6E68);

INCLUDE_ASM("asm/levels", func_L23_003A6F50);

INCLUDE_ASM("asm/levels", func_L23_003A7048);

INCLUDE_ASM("asm/levels", func_L23_003A77F0);

INCLUDE_ASM("asm/levels", func_L23_003A7908);

INCLUDE_ASM("asm/levels", func_L23_003A7A90);

INCLUDE_ASM("asm/levels", func_L23_003A8028);

INCLUDE_ASM("asm/levels", func_L23_003A97B8);

/* localdecomp:start func_L23_003A9C40 */
extern u16 **D_L23_001D6764;
__asm__(".extern D_L23_001D6764, 16");
extern u8 *D_L23_001E0014;
__asm__(".extern D_L23_001E0014, 16");
extern s16 D_L23_0023A3C0[];
extern Rec14 D_L23_002BC7F8[];

s32 func_L23_003A9C40(s32 idx)
{
    u16 *p = D_L23_001D6764[idx];
    u8 *e;
    s32 id;
    s32 i;

    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[idx])) {
        e = D_L23_001E0014 + ((*p & 0x7FFF) << 5);
        if (e == 0)
            break;
        id = D_L23_0023A3C0[e[0x1D]];
        for (i = 0; D_L23_002BC7F8[i].id >= 0; i++) {
            if (id == D_L23_002BC7F8[i].id)
                return 1;
        }
        p++;
    }
    return 0;
}
/* localdecomp:end func_L23_003A9C40 */

INCLUDE_ASM("asm/levels", func_L23_003A9D00);
