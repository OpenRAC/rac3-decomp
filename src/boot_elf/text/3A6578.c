#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3A56A8.c's earlier functions (tools/port_from_us.py) */
extern u8 D_001A30B0[];
#define QZERO(p) __asm__ __volatile__("sq $0,0x0(%0)" : : "r"(p))
extern s32 D_001D6E1C;
extern u8 D_1A3100[];
extern void func_13CA28(void);
extern s32 func_13B620(void);
extern void func_13C170(void);
extern s32 func_12C908(s32);
extern void func_003A5A20(void);
typedef struct { u8 x0; s8 x1; s8 x2; s8 x3; u16 x4; u16 x6; s32 x8; s32 xC; u32 x10; s32 x14; s32 x18; u8 pad[0x60-0x1C]; } S_3A0200;
extern S_3A0200 D_0022D430[];
extern s32 D_0022D8B0[];
extern void func_003C2C38(s32 p);
typedef struct O2_3A02D8 { u8 pad[8]; void *f8; } O2_3A02D8;
typedef struct { u8 pad[0x30]; u8 f30; u8 pad31; s16 f32; u16 f34; u8 pad36[0x63 - 0x36]; u8 f63; u8 pad64[4]; O2_3A02D8 *f68; } O_3A02D8;
typedef struct { O_3A02D8 *f0; u8 pad[0x40]; } S_16C580_3A02D8;
extern S_16C580_3A02D8 D_0016C580_003A5AF8;
extern u32 D_001D54D0;
extern s16 D_001D5BB0[4];
extern s16 D_001D5BB6;
extern s16 D_001D5BB8;
extern s16 D_001D5BBA;
extern s16 D_001D5BBC;
extern O_3A02D8 *func_003C2868_003A5AF8(s32, s32);
extern void func_003A5AA0(void);

typedef struct { u8 p0[0x20]; s16 f20; } S_16C580_3A0D58;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A0D58;
extern S_16C580_3A0D58 D_16C580_003A6578;
extern f32 func_00382918(void);
extern void func_003C4FD0(f32 *v, f32 r);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A6578);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A66D0);
