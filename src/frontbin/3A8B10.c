#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void func_003A8B10(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);


INCLUDE_ASM("asm/nonmatchings/text", func_003A8B10);

/* localdecomp:start func_003A8F50 */
extern s32 D_001425AC[];
extern s16 D_0016C5A8[];
extern s32 D_001D4D40;
extern void func_00392DF0(s32, s32);
void func_003A8F50(void) {
    D_001D4D40 = 1;
    D_0016C5A8[0] = 1;
    D_001425AC[0] = 1;
    func_00392DF0(1, 1);
}
/* localdecomp:end func_003A8F50 */
TEXT_PADDING(2);

/* localdecomp:start func_003A8F90 */
extern void func_0038CB50();
void func_003A8F90(u32 a) {
    while (*(volatile u32 *)0x10008000 & 0x100) {
        func_0038CB50(0x10);
    }
    *(volatile u32 *)0x10008020 = 0;
    *(volatile u32 *)0x10008030 = a & 0xFFFFFFF;
    *(volatile u32 *)0x10008000 = 0x145;
    while (*(volatile u32 *)0x10008000 & 0x100) {
        func_0038CB50(0x10);
    }
}
/* localdecomp:end func_003A8F90 */
