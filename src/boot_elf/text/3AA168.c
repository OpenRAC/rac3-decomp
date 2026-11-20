#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

typedef struct { u8 p0[0x16]; s16 h16; } F_3A4860;
typedef struct { u8 p0[4]; s16 n; u8 p6[2]; s16 nframes; s16 stride; u8 pC[0x14]; u8 *data; } A_3A4860;
typedef struct { f32 m[16]; } M_3A4860;
extern void func_0038DDF0();
extern void func_0038DE48(void *, void *, void *, f32);
extern void func_0038DD58();
extern void func_0038DA20();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003AA168);

extern int D_001DA050[];

/* localdecomp:start func_003AA328 */
extern int D_001DA050[];
extern u32 *D_001DA050_g;
extern u8 D_001D8030;
void func_003AA328(void) {
    ((u32 *)D_001DA050[0])[0] = 0x30000003;
    ((u32 *)D_001DA050[0])[1] = (u32)&D_001D8030;
    ((u32 *)D_001DA050[0])[2] = 0;
    ((u32 *)D_001DA050[0])[3] = 0x50000003;
    D_001DA050_g = (u32 *)D_001DA050[0] + 4;
}
/* localdecomp:end func_003AA328 */
