#include "common.h"

typedef struct {
    u8 pad[0x25C0];
    u8 *p25C0;
    s32 w25C4;
} S_1A4BE0_0034CE78;

INCLUDE_ASM("asm/levels", func_L30_0034CF28);

LINKER_REMNANT("asm/levels", func_L30_0034D068);

INCLUDE_ASM("asm/levels", func_L30_0034D088);
