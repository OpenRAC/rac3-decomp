#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 38E518.c's earlier functions */
extern s32 func_0038E488(u8 *p, s32 off, s32 *out);
extern s32 *D_001D55C4[];
extern u8 D_001D5B42;

typedef struct { s16 h0, h2, h4, h6, h8, hA, hC, hE, h10; u16 fl; s16 h14, h16, h18, h1A; } O_0038B1E8;
typedef struct { s16 key; s8 val; u8 end; } K_0038B1E8;
extern s32 D_001D5B94;
extern u8 D_001D5B41, D_001D5B42, D_001D5B40;
extern s32 D_001D5B68;
extern s32 D_001D5B48[2];
extern s32 D_001D9C80;
extern u16 D_001D9C88[4], D_001D9CA0[4], D_001D9CB8[4], D_001D9CD0[4];
extern s32 D_001D55C4_0038FD40;
extern s32 D_001D55C8_0038FD40;
extern s32 D_001D4BC0_0038FD40, D_001D4BC4_0038FD40;
extern void func_003A98B8(s32, s32, s32, s32);
extern s32 func_0038E928_0038FD40(u8 *, s32, f32);
extern void func_0038EBC8_0038FD40(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
typedef struct { s16 h0, h2, h4, h6, h8, hA, hC, hE, h10; u16 h12; s16 h14, h16; } B_38BB50;
typedef struct { u32 w0, w1; } G_38BB50;
extern s32 D_001D5B94;
extern u8 D_001D5B41;
extern s32 D_001D5B48[2];
extern s32 D_001D5B5C[];
extern s32 D_001D4BC0[];
extern s32 D_001D4BC4[];
extern void func_003A98B8(s32, s32, s32, s32);
extern s32 func_0038E928_00390768(u8 *, s32, f32);
extern void func_0038EBC8_00390768(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00390768);
