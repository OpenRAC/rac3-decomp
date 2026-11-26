#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_00391398 */
extern s32 D_001D4D08[];
extern s32 D_001D4D0C[];
extern s32 D_001D4D10[];
extern s32 D_001D4D14[];
extern s32 D_001D4D18[];
extern s32 D_001D4D1C[];
extern s32 D_001D4CF8[];
void func_00391398(void) {
    *(unsigned long *)((u8 *)D_001D4CF8[0] + 0x18) = (long)D_001D4D08[0] | ((long)D_001D4D0C[0] << 12) | ((long)D_001D4D10[0] << 23) | ((long)D_001D4D14[0] << 27) | ((long)D_001D4D18[0] << 32) | ((long)D_001D4D1C[0] << 44);
}
/* localdecomp:end func_00391398 */

LINKER_REMNANT("asm/remnants", func_00391400);

extern s32 D_001D4D08_00391408;
extern s32 D_001D4D0C_00391408;
/* localdecomp:start func_00391408 */
extern void func_00391398(void);
void func_00391408(s32 dx, s32 dy, s32 clamp) {
    D_001D4D08_00391408 += dx; D_001D4D0C_00391408 += dy; if (clamp) { s32 x = D_001D4D08_00391408 >= 0 ? D_001D4D08_00391408 : 0; s32 y = D_001D4D0C_00391408 >= 0 ? D_001D4D0C_00391408 : 0; D_001D4D08_00391408 = x <= 3000 ? x : 3000; D_001D4D0C_00391408 = y <= 450 ? y : 450; }
    func_00391398();
}
/* localdecomp:end func_00391408 */

LINKER_REMNANT("asm/remnants", func_00391490);
