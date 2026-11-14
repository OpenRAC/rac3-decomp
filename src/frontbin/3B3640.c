#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);


/* localdecomp:start func_003B3640 */
extern s32 D_001D545C_003B3640;
extern u8 D_001D5571_003B3640;
__asm__(".extern D_001D545C_003B3640, 16");
__asm__(".extern D_001D5571_003B3640, 16");
extern s32 D_001D545C;
extern u8 D_001D5571;
/* PAL candidate for func_003B3640 (frontbin).
   Retail reaches D_001D545C / D_001D5571 with the "lui + lo, destination
   reused" form (the assembler's expansion), so they are read through
   an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did); the $gp access to D_001D545C keeps its own sized name. */

extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s32 D_001D545C_gp_003B3640;
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
extern void func_003A3FE0(void);
extern s32 func_003A2750(s32);
extern void func_0013BFE0(s32);
extern void func_003A8F50(void);

void func_003B3640(void) {
    D_001425AC[0] = 1;
    func_003A3FE0();
    func_003A2750(1);
    func_0013BFE0(D_00143958[0] == 0);
    {
    s32 v = D_001D545C_gp_003B3640;
    if (D_001D545C_003B3640 < 2 && D_001D5571_003B3640 == 0) {
        func_003A8F50();
        return;
    }
    func_003A0EC0(6, 2, 5, v, 0);
    }
}
/* localdecomp:end func_003B3640 */

extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s32 D_001D545C_gp_003B36C8;
extern s32 D_001D545C;
extern u8 D_001D5571;
extern s32 D_001D5B74;
extern s32 D_001D9D04;
extern void func_003A3FE0(void);
extern s32 func_003A2750(s32);
extern void func_0013BFE0(s32);
extern void func_003A8F50(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003B36C8);
