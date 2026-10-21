#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3B6CD8.c's earlier functions (tools/port_from_us.py) */
extern void func_00393340(s32);
extern void func_0039E9C0(s32);
extern void func_003BB5A8(s32);
extern s32 func_003BB760(s32);
extern s32 D_001D8AA0;
extern s32 D_001D8A9C;
extern s32 D_001D8AAC;
extern s32 D_001D8AB0;
extern s32 D_001D8AA4;
extern s32 D_001D8AA8;
extern u8 D_001D5BDC[];
extern u8 D_001D5BDC_003B6DB0[];
extern void func_003A5748(s32, s32, s32);
typedef struct { u8 on; u8 pad[7]; } F;
typedef struct { void (*fn)(); s32 pad; } T;
extern s32 D_001D8A18_003B6E78;
extern F D_001D8A48_003B6E78[1];
extern T D_001D8A4C[1];
typedef struct { s32 a[7]; } R;
extern R D_142430[];
extern void func_003B6C00();
extern void func_003B6CC8();
extern void func_003B6D28();
extern void func_003B6D68();
extern void func_003B6E50();
extern f32 D_001D8A68;
extern f32 D_001D8A6C;
extern f32 D_001D8A70;
extern f32 D_001D8A74;
extern f32 D_001D8A78;
extern f32 D_001D8A7C;
extern f32 D_001D8A80;
extern f32 D_001D8A84;
extern f32 D_001D8A88;
extern f32 D_001D8A8C;
extern f32 D_001D8A90;
extern f32 D_001D8A94;
extern f32 D_001D8A98;
extern f32 D_001D8AD0;
extern f32 D_001D8AD4;
extern f32 D_001D8AD8;
extern f32 D_001D8ADC;
extern f32 D_001D8AE0;
extern s32 D_001D8AC0[2];
extern void func_003BB538(void);
extern void func_003E9808();
extern s32 func_003BB4D0(u32);
extern s32 func_003E93A0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E82D8(s32, s32);
extern s32 func_003E7E80(s32, s32);
extern s32 func_003E7CE0(s32, s32, s32);
extern s32 func_003E94F0_003B6F48(s32, s32, f32, f32, f32, f32, s32);
extern s32 func_003E7BF0(s32, s32, s32);
extern s32 func_003E9628(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8200(s32, s32);
extern s32 func_003E9020(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E8E10(s32, s32, s32, s32, s32);
extern s32 func_003E89E8(s32, s32);
extern s32 func_003E8AC8(s32, s32);
extern s32 func_003E8700(s32, s32);
extern s32 D_001D8A18_003B7640;
extern s32 func_003823D0();
extern s32 func_003B9650(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B7748);
