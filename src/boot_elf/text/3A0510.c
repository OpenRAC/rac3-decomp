#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/boot_elf/remnants", func_003A0510);

/* Ten unreachable 0xCDCDCDCD linker-fill words, between the stripped tail and the DMA leaf. */
LINKER_REMNANT("asm/boot_elf/remnants", func_003A0518);

/* Same 32-byte SPR-DMA leaf as frontbin at 003A0140 (ASM_FUNC func_003A0138):
 * $at is held as the MMIO base across four stores, outside the compiler register set. */
ASM_FUNC("asm/boot_elf/handwritten", func_003A0540);
