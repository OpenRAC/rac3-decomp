#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3A53E8.c's earlier functions */
typedef struct O2_3A02D8 { u8 pad[8]; void *f8; } O2_3A02D8;
typedef struct { u8 pad[0x30]; u8 f30; u8 pad31; s16 f32; u16 f34; u8 pad36[0x63 - 0x36]; u8 f63; u8 pad64[4]; O2_3A02D8 *f68; } O_3A02D8;
extern void func_003A56F8(O_3A02D8 *obj);

INCLUDE_ASM("asm/nonmatchings/text", func_003A58C0);

LINKER_REMNANT("asm/remnants", func_003A6140);
