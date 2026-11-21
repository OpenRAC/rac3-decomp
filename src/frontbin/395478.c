#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 394F48.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u8 pad[0x58]; s32 w; s32 h; union { s32 flags; u8 c; } u; } S_38EDE8;
extern void func_00393808(void *);
extern s32 func_00393620(S_38EDE8 *p, s32 *x, s32 *y);
extern void func_00393808(void *arg);

INCLUDE_ASM("asm/nonmatchings/text", func_00395478);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C0C0);

LINKER_REMNANT("asm/remnants", func_00396240);

typedef struct { u8 p0[8]; s32 w8; u8 pC[0x44]; s32 w50; s32 w54; s32 w58; s32 w5C; u8 p60[0xC]; s32 w6C; u8 p70[4]; s32 w74; } O_91A18;
extern void func_00396C60();
extern void func_003970D8();
extern void func_00393690();
extern s16 D_001A666A[];
INCLUDE_ASM("asm/nonmatchings/text", func_00396278);

/* PAL candidate for func_00396390 (frontbin).
   Same shape as the US draft; the constant stored at offset 0x7C is 0x82 in PAL
   retail (0x96 in the US build). */

/* localdecomp:start func_00396390 */
extern void func_00393808(void *);
 
void func_00396390(void *p) {
    *(s32 *)((u8 *)p + 0x7C) = 0x82;
    *(s32 *)((u8 *)p + 0x58) = 0x20;
    *(s32 *)((u8 *)p + 0x5C) = 0x20;
    func_00393808(p);
}
/* localdecomp:end func_00396390 */

/* localdecomp:start func_003963C0 */
s32 func_003963C0(void) {
    return 0;
}
/* localdecomp:end func_003963C0 */

LINKER_REMNANT("asm/remnants", func_003963C8);
