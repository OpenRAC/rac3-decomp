#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 39BCB0.c's earlier functions */
extern s32 D_001D4CE8[];
extern s32 D_001D4CEC[];

/* localdecomp:start func_0039BD48 */
extern void (*D_001D6300)(void);
extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];
void func_0039BD48(void) {
    if (D_001D6300 != 0) {
        D_001D6300();
        D_001D6300 = 0;
    }
    if (!(D_001D4CEC[0] & 0x40)) D_001D4CE8[0] = 4;
}
/* localdecomp:end func_0039BD48 */

typedef struct { u8 pad[0x15C]; s32 f15C; u8 pad2[4]; s32 f164; u8 pad3[4]; s32 f16C; } S_396BC0;
extern S_396BC0 D_142430_0039BD90;
extern s32 D_001D4CEC_0039BD90;
extern s32 D_001D4CE8_0039BD90;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0039BD90);

/* localdecomp:start func_0039BDF0 */
extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];

void func_0039BDF0(void) {
    if (!(D_001D4CEC[0] & 0x40)) D_001D4CE8[0] = 4;
}
/* localdecomp:end func_0039BDF0 */
