#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3AD328.c's earlier functions */
typedef struct { u8 p0[0x18]; f32 f18; s32 f1C; s32 f20; f32 f24; s8 b28; u8 p29[3]; s32 f2C; u8 p30[0x50]; s32 f80; s32 f84; } S_3A7E80;
typedef struct { u8 pad[0x30]; f32 m[4][4]; f32 v[4]; } S_3A7F90;
typedef struct { f32 a[3]; f32 b[3]; } V_7FC8;
extern void func_003AD428(S_3A7E80 *o);
extern void func_003AD4E8(void *p, s32 value);
extern void func_003AD520(void *p, s32 value);
extern u8 func_003AD528(void *p, u8 value);
extern void func_003AD538(S_3A7F90 *p, s32 i, f32 a, f32 b, f32 c, f32 d, f32 e);
extern void func_003AD570(V_7FC8 *s, s32 i, f32 x, f32 y);
extern void func_003AD588(void *p, s32 value);
extern void func_003AD590(u8 *p, s32 a);
extern void func_003AD5D0(void *p, s32 value);
extern void func_003AD5D8(void *p, f32 value);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD7D8);
