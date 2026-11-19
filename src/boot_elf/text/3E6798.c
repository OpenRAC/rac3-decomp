#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3E5C60.c's earlier functions */
extern void *func_003E5D80(s32 idx);

typedef struct { u32 key; void *val; } HE_3E0E90;
typedef struct { s32 f0; s32 n; HE_3E0E90 e[0x400]; } HT_3E0E90;
typedef struct { s32 f0; s32 f4; struct { s32 pad[2]; void (*fn)(void *, s32); } *vt; } O_3E0E90;
typedef struct { struct { s32 pad[3]; void (*fn)(void *, void *); } *vt; } M_3E0E90;
typedef struct { s32 f0; s32 x4; } G_3E0E90;
extern s32 D_001DAA08[2];
extern G_3E0E90 D_001DA938[];
extern void *func_003E6BB0();
extern void *func_003E6FC0();
extern s32 func_003E7078();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E6798);
