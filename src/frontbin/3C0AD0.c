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


extern s32 func_0038CAD0();
extern s32 func_003BDF18();
extern void func_003BB968();
INCLUDE_ASM("asm/nonmatchings/text", func_003C0AD0);

extern s32 D_001D4BC0;
extern u8 D_002D1FC0_003C0C40[];
extern void func_00389240();
extern void func_00390F50(s32, s32, unsigned long, u8 *, s32, f32);
extern void func_00389370();
/* localdecomp:start func_003C0C40 */
extern s32 D_001D4BC0_003C0C40;
extern u8 D_002D1FC0_003C0C40_003C0C40[];
extern void func_00389240_003C0C40();
extern void func_00390F50_003C0C40(s32, s32, unsigned long, u8 *, s32, f32);
extern void func_00389370_003C0C40();
void func_003C0C40(void) {
    func_00389240_003C0C40(1);
    func_00390F50_003C0C40(D_001D4BC0_003C0C40 >> 1, 0xA0, 0x80FFFFFF, D_002D1FC0_003C0C40_003C0C40, -1, 1.2f);
    func_00389370_003C0C40();
}
/* localdecomp:end func_003C0C40 */
