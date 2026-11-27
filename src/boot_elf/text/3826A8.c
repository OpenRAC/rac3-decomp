#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_003826A8 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern unsigned long D_001D4D38_003826A8;
__asm__(".extern D_001D4D38_003826A8, 16");
typedef struct { u8 p0[0x64C]; s32 f64C; s32 f650; s32 f654; } S_160C40_3826C8;
extern S_160C40_3826C8 D_160C40_003826A8;
extern u8 D_2D2100[];
extern s32 D_1A1F0C[];
extern s32 func_003A2AF0(s32, s32, s32);
extern void func_003824D0_003826A8(void *, unsigned long *, s32, s32);
void func_003826A8(void) {
    unsigned long out[4];
    S_160C40_3826C8 *g = &D_160C40_003826A8;
    func_003A2AF0((s32)D_2D2100, g->f650 + g->f64C, g->f654);
    func_003824D0_003826A8(D_2D2100, out, D_1A1F0C[0], 0x3FFC00);
    D_001D4D38_003826A8 = out[0];
}
/* localdecomp:end func_003826A8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00382714);

/* localdecomp:start func_00382728 */
s32 func_00382728(u8 *p) {
    s32 *q;
    if (p == 0 || (q = *(s32 **)(p + 0x68)) == 0 || !(*(u16 *)(p + 0x34) & 0x20)) {
        return 0;
    }
    return *q;
}
/* localdecomp:end func_00382728 */
