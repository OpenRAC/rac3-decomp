#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003E7670(s32);
/* --- end of declarations from other files --- */

/* declarations of 3E73F8.c's earlier functions (tools/port_from_us.py) */
extern f32 D_00225900[];
extern f32 D_001DA940;
extern s32 D_001DA944;
extern s32 D_001D55E8;
extern void func_003877A0();
extern void func_003A97F8(s32, unsigned long);
extern s32 D_001DA944;
extern f32 D_001DA940;
extern f32 D_002259B0[];
extern void func_0038E530();
extern void func_003877A0();

/* localdecomp:start func_003E75D0 */
extern void func_00389620();
 
void func_003E75D0(void) {
    func_00389620(0);
}
/* localdecomp:end func_003E75D0 */

/* localdecomp:start func_003E75F0 */
extern void func_00389750();
 
void func_003E75F0(void) {
    func_00389750();
}
/* localdecomp:end func_003E75F0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E7610);

/* Ps2EeAs is one pass: it must know these are 4-byte gp objects before their first use
   (as src/frontbin/3E7188.c tells it). */
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
/* localdecomp:start func_003E7620 */
extern f32 D_001D9698;
extern f32 D_001D969C;
extern f32 D_001D96A0;
extern f32 D_001D96A4;
extern f32 D_001D96A8;
extern f32 D_001D96AC;
/* from rac4-decomp's func_00501988 */
void func_003E7620(void) {
    f32 a = D_001D9698;
    f32 b = D_001D96A0;
    f32 c = D_001D969C;
    f32 d = D_001D96A4;
    D_001D96A8 = a / b;
    D_001D96AC = c / d;
}
/* localdecomp:end func_003E7620 */

/* localdecomp:start func_003E7658 */
extern f32 D_001D96A8;
extern f32 D_001D96AC;
void func_003E7658(f32 *a, f32 *b) { *a = D_001D96A8; *b = D_001D96AC; }
/* localdecomp:end func_003E7658 */

/* localdecomp:start func_003E7670 */
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
extern void func_00391068(f32 *, f32 *, s32);
/* the frontbin copy is func_003E72B8 (src/frontbin/3E7188.c) */
void func_003E7670(s32 mode) {
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
    func_003E7620();
    v[1] = v[0] = 0.0f;
    func_00391068(&v[0], &v[1], 1);
    D_001D96B0 = v[0] * 1.0769231f / D_001D969C;
    D_001D96B4 = (v[1] + v[0] * 0.5f) * 1.0769231f / D_001D969C;
}
/* localdecomp:end func_003E7670 */
