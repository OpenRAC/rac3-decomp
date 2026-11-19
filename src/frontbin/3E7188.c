#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003E72B8(s32);
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
/* localdecomp:start func_003E7268 */
/* Ported from rac4-decomp/src/game/00501988.c. */
__asm__(".extern D_001D9698, 4");
__asm__(".extern D_001D969C, 4");
__asm__(".extern D_001D96A0, 4");
__asm__(".extern D_001D96A4, 4");
__asm__(".extern D_001D96A8, 4");
__asm__(".extern D_001D96AC, 4");
extern f32 D_001D9698;
extern f32 D_001D969C;
extern f32 D_001D96A0;
extern f32 D_001D96A4;
extern f32 D_001D96A8;
extern f32 D_001D96AC;
void func_003E7268(void) {
    f32 a = D_001D9698;
    f32 b = D_001D96A0;
    f32 c = D_001D969C;
    f32 d = D_001D96A4;
    D_001D96A8 = a / b;
    D_001D96AC = c / d;
}
/* localdecomp:end func_003E7268 */

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

/* localdecomp:start func_003E72B8 */
__asm__(".extern D_001D9688, 4");
__asm__(".extern D_001D968C, 4");
__asm__(".extern D_001D9690, 4");
__asm__(".extern D_001D9694, 4");
__asm__(".extern D_001D96B0, 4");
__asm__(".extern D_001D96B4, 4");
extern f32 D_001D9688;
extern f32 D_001D968C;
extern s32 D_001D9690;
extern s32 D_001D9694;
extern f32 D_001D96B0;
extern f32 D_001D96B4;
extern void func_00390C88(f32 *, f32 *, s32);
void func_003E72B8(s32 mode) {
    f32 v[2];
    D_001D9688 = 1.0f;
    D_001D968C = 1.0f;
    D_001D9690 = 0;
    D_001D9694 = 0;
    D_001D9698 = 512.0f;
    switch (mode) {
    case 0:
        D_001D96A0 = 512.0f;
        D_001D969C = 416.0f;
        D_001D96A4 = 416.0f;
        break;
    case 1:
        D_001D96A0 = 512.0f;
        D_001D969C = 448.0f;
        D_001D96A4 = 448.0f;
        break;
    }
    func_003E7268();
    v[1] = v[0] = 0.0f;
    func_00390C88(&v[0], &v[1], 1);
    D_001D96B0 = v[0] * 1.0769231f / D_001D969C;
    D_001D96B4 = (v[1] + v[0] * 0.5f) * 1.0769231f / D_001D969C;
}
/* localdecomp:end func_003E72B8 */
