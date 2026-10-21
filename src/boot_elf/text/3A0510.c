#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/boot_elf/remnants", func_003A0510);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A0518);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A0540);
TEXT_PADDING(8);
