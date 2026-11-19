#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3B9BD0.c's earlier functions */
extern void func_003B9EC8();
extern s32 func_003B9E30(void *p, s32 x, s32 y);
extern s32 func_003B9E50(void *p, s32 x, s32 y);
extern s32 func_003B9E70(s32 a0, s32 a1);
extern s32 func_003B9E80(s32 a0, s32 a1);
extern s32 func_003B9E90(u8 *p);

typedef struct { u8 p0[0x10]; s32 f10; s32 f14; s32 f18; u8 p1C[4]; f32 a20[4]; f32 a30[4]; f32 a40[4]; f32 f50; f32 f54; u8 p58[4]; f32 f5C; f32 f60; u8 p64[8]; f32 f6C; f32 f70; u8 p74[0x28]; u32 f9C; f32 fA0; f32 fA4; u8 pA8[4]; f32 fAC; } S_3B49E8;
extern void func_003E9450();
extern s32 func_003E81F0(s32, f32, f32);
extern void func_003E8E18_003B9EC8(s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8898(s32, f32, f32);
extern s32 func_003E8958(s32, s32);
extern s32 func_003E7AC8(s32, s32);
extern s32 func_003E9138_003B9EC8(s32, u32, f32, f32, f32, f32, s32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E8A08(s32, s32, s32);
extern s32 func_003E7A18(s32, s32);
extern s32 func_003E8348(s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003B9EC8);
