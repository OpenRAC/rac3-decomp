#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3B3750.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u8 pad0[0x18]; u16 h18; u8 pad1a[0x12E]; s32 f148; u8 pad14c[0x18]; s32 f164; s32 f168; u8 pad16c[8]; s32 f174; } S_003ADCB0;
extern s32 D_001D888C;
extern void func_003B3E60(void);

extern s32 D_001D4CE8_003AE438;
extern u8 D_001D9FA0_003AE438;
extern u8 D_001D5BDC_003AE438;
extern u8 D_001D5BDD_003AE438;
extern u8 D_001D88A0[];
extern u8 D_001D88A8[];
extern s32 func_00381FF0();
extern void func_11B2E8();
extern void func_0038E7E8_003AE438(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, rest:21; } F_003B2F50;
typedef struct { u8 pad[0x1A4]; s32 f1A4; } P_003B2F50;
typedef struct { u8 pad0[8]; s32 f8; u8 pad0c[4]; s32 f10; } S_142430_003AE8A8;
extern s32 D_001D4CE8;
extern F_003B2F50 D_001D4CEC;
extern s32 D_001D888C;
extern u8 D_001D5BDC;
extern u8 D_001D5BDD;
extern u8 D_001D9FA0_003AE438;
extern P_003B2F50 *D_001D52FC;
extern S_003ADCB0 D_00142430;
extern s32 func_0039BC70(s32, s32);
extern void func_0039C300(void);
extern void func_003A8F50(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003B3E60);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C6E0);
