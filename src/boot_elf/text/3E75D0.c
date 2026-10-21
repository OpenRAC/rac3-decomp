#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
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

extern f32 D_001D9698;
extern f32 D_001D969C;
extern f32 D_001D96A0;
extern f32 D_001D96A4;
extern f32 D_001D96A8;
extern f32 D_001D96AC;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E7620);

/* localdecomp:start func_003E7658 */
extern f32 D_001D96A8;
extern f32 D_001D96AC;
void func_003E7658(f32 *a, f32 *b) { *a = D_001D96A8; *b = D_001D96AC; }
/* localdecomp:end func_003E7658 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E7670);
