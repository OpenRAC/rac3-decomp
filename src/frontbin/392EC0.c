#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00392EF0(void);
/* --- end of declarations from other files --- */

/* declarations of 392A18.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);

LINKER_REMNANT("asm/remnants", func_00392EC0);

/* localdecomp:start func_00392EF0 */
extern u8 D_001D551C;
void func_00392EF0(void) {
    D_001D551C = 0;
}
/* localdecomp:end func_00392EF0 */

LINKER_REMNANT("asm/remnants", func_00392EF8);

extern u8 D_001D5BDC;
extern s32 D_001D5C90;
extern s32 D_0022758C;
extern s32 D_001DA058;
/* localdecomp:start func_00392F08 */
__asm__(".extern D_001DA058, 16");
extern s32 D_0022758C_00392F08 __attribute__((section(".data")));
s32 func_00392F08(u32 value, s32 *result) {
    if (value > 0x40000) {
        *result = 0;
        return -1;
    }
    if (D_001D5BDC != 0 || D_001D5C90 == 0) {
        *result = D_0022758C_00392F08 + D_001DA058 - value;
    } else {
        *result = D_001D5C90;
    }
    return 0;
}
/* localdecomp:end func_00392F08 */

/* localdecomp:start func_00392F60 */
extern s32 D_001D5C90;
void func_00392F60(s32 a) {
    D_001D5C90 = a;
}
/* localdecomp:end func_00392F60 */
