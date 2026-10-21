#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003E7188();
extern void func_003E71E0(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003E7188 */
extern f32 D_00225900[];
extern f32 D_001DA940;
extern s32 D_001DA944;
extern s32 D_001D55E8;
extern void func_003873C0();
extern void func_003A9440(s32, unsigned long);
void func_003E7188(void) {
    D_001DA940 = D_00225900[0xB0/4];
    D_00225900[0xB0/4] = 0.62f;
    func_003873C0();
    func_003A9440(0x47, 0x33001);
    D_001DA944 = D_001D55E8;
}
/* localdecomp:end func_003E7188 */

/* localdecomp:start func_003E71E0 */
extern s32 D_001DA944;
extern f32 D_001DA940;
extern f32 D_002259B0[];
extern void func_0038E150();
extern void func_003873C0();
void func_003E71E0(void) {
    func_0038E150(D_001DA944);
    D_002259B0[0] = D_001DA940;
    func_003873C0();
}
/* localdecomp:end func_003E71E0 */

extern void func_00389240();
/* localdecomp:start func_003E7218 */
void func_003E7218(void) {
    func_00389240(0);
}
/* localdecomp:end func_003E7218 */

extern void func_00389370();
/* localdecomp:start func_003E7238 */
void func_003E7238(void) {
    func_00389370();
}
/* localdecomp:end func_003E7238 */

LINKER_REMNANT("asm/remnants", func_003E7258);

extern f32 D_001D9698;
extern f32 D_001D969C;
extern f32 D_001D96A0;
extern f32 D_001D96A4;
extern f32 D_001D96A8;
extern f32 D_001D96AC;
INCLUDE_ASM("asm/nonmatchings/text", func_003E7268);

/* PAL candidate for func_003E72A0 (US draft of rac3-uya-decomp func_003E1D50).

   Retail reaches D_001D96A8/D_001D96AC through $gp (lwc1 $f0, -0x3208($gp)),
   which is SN's assembler (Ps2EeAs) using $gp for a global it knows to be
   small. Ps2EeAs is single pass, so the size has to be known before the use:
   gcc's own .extern hints come at the end of the file, too late. The size
   hints below (the project's documented Option A pattern) tell Ps2EeAs the
   two globals are 4-byte objects before the function is assembled. */

/* localdecomp:start func_003E72A0 */
__asm__(".extern D_001D96A8, 4");
__asm__(".extern D_001D96AC, 4");
extern f32 D_001D96A8;
extern f32 D_001D96AC;
void func_003E72A0(f32 *a, f32 *b) { *a = D_001D96A8; *b = D_001D96AC; }
/* localdecomp:end func_003E72A0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E72B8);
