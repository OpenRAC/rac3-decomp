#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003B0F90(s32);
extern void func_003B0FE0(void);
extern void func_003B0D60();
extern void func_003B0F50();
/* --- end of declarations from other files --- */

ASM_FUNC("asm/handwritten", func_003B0D60);

ASM_FUNC("asm/handwritten", func_003B0F50);

/* localdecomp:start func_003B0F90 */
extern s32 func_12C908(s32);
extern s32 D_001D5520;
extern volatile s32 D_001DA0D0_003B0F90[];
extern volatile s32 D_001DA0D4[];
void func_003B0F90(s32 a) {
    while (func_12C908(0) == a && D_001D5520 == 0) {
    }
    D_001DA0D0_003B0F90[0] = 1;
    D_001DA0D4[0] = 0;
}
/* localdecomp:end func_003B0F90 */

/* localdecomp:start func_003B0FE0 */
extern s32 D_001DA0D0[];

void func_003B0FE0(void) {
    D_001DA0D0[0] = 0;
}
/* localdecomp:end func_003B0FE0 */
