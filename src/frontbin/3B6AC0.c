#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3B69F8.c's earlier functions */
extern void func_003B6A98(void);

typedef struct { u8 on; u8 pad[7]; } F;
typedef struct { void (*fn)(); s32 pad; } T;
extern s32 D_001D8A18_003B6AC0;
extern F D_001D8A48_003B6AC0[1];
extern T D_001D8A4C[1];
typedef struct { s32 a[7]; } R;
extern R D_142430[];
extern void func_003B6848();
extern void func_003B6910();
extern void func_003B6970();
extern void func_003B69B0();
INCLUDE_ASM("asm/nonmatchings/text", func_003B6AC0);
