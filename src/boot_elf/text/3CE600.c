#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3CE2E8.c's earlier functions (tools/port_from_us.py) */
typedef struct { u8 pad[0x20]; s16 *arr[1]; } S_3C8B28;
extern S_3C8B28 *D_001DA5F0_003CE450;
extern s32 D_001DA610[2];
extern void func_0038D728(void *, void *);
extern s32 func_003CE450(s32, s32);
s32 func_003CE798_003CE568(s32);
extern s32 D_001D9D00;
extern void *D_001DA5F0_003CE568;
extern s32 D_001DA650;

LINKER_REMNANT("asm/boot_elf/remnants", func_003CE600);
