#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0050DE78);

INCLUDE_ASM("asm/levels", func_L39_0050DEC0);

/* localdecomp:start func_L39_0050DF38 */
typedef struct {
    u8 *data;
    u32 remaining;
} Cursor;
typedef struct {
    u8 prefix[12];
    Cursor cursor;
} Input;

/* from rac4-decomp's func_0040BAB8, renamed */
s32 func_L39_0050DF38(const Input *input, Cursor *output)
{
    u32 remaining;
    u8 *nextData;
    *output = input->cursor;
    remaining = output->remaining;
    if (!remaining || (output->data[0] & 0x80))
        return 0x801;
    goto test;
next:
    {
        u32 nextRemaining = remaining - 1;
        output->data = nextData;
        output->remaining = nextRemaining;
        remaining = nextRemaining;
    }
test:
    if (remaining) {
        u8 *data = output->data;
        nextData = data + 1;
        if (!*data)
            goto next;
    }
    return 0;
}
/* localdecomp:end func_L39_0050DF38 */

INCLUDE_ASM("asm/levels", func_L39_0050DFA0);

LINKER_REMNANT("asm/levels", func_L39_0050E080);

INCLUDE_ASM("asm/levels", func_L39_0050E0C8);

INCLUDE_ASM("asm/levels", func_L39_0050E330);

INCLUDE_ASM("asm/levels", func_L39_0050E948);

INCLUDE_ASM("asm/levels", func_L39_0050EC58);

INCLUDE_ASM("asm/levels", func_L39_0050F1C0);

INCLUDE_ASM("asm/levels", func_L39_0050F358);
