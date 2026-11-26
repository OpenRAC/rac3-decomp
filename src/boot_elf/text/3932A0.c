#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/boot_elf/remnants", func_003932A0);

/* localdecomp:start func_003932D0 */
extern u8 D_001D551C;
void func_003932D0(void) {
    D_001D551C = 0;
}
/* localdecomp:end func_003932D0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003932D8);

extern u8 D_001D5BDC;
extern s32 D_001D5C90;
extern s32 D_0022758C;
extern s32 D_001DA058;
/* localdecomp:start func_003932E8 */
/* the copy of func_00392F08 */
__asm__(".extern D_001DA058, 16");
extern s32 D_0022758C_003932E8 __asm__("D_0022758C") __attribute__((section(".data")));
s32 func_003932E8(u32 value, s32 *result) {
    if (value > 0x40000) {
        *result = 0;
        return -1;
    }
    if (D_001D5BDC != 0 || D_001D5C90 == 0) {
        *result = D_0022758C_003932E8 + D_001DA058 - value;
    } else {
        *result = D_001D5C90;
    }
    return 0;
}
/* localdecomp:end func_003932E8 */

/* localdecomp:start func_00393340 */
extern s32 D_001D5C90;
void func_00393340(s32 a) {
    D_001D5C90 = a;
}
/* localdecomp:end func_00393340 */
