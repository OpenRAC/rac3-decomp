#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */


typedef struct { u8 p0[0x20]; s16 f20; } S_16C580_3A0D58;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A0D58;
extern S_16C580_3A0D58 D_16C580_003A6178;
extern f32 func_00382538(void);
extern void func_003C4C18(f32 *v, f32 r);
INCLUDE_ASM("asm/nonmatchings/text", func_003A6178);

INCLUDE_ASM("asm/nonmatchings/text", func_003A62D0);
