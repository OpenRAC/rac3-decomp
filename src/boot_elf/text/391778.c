#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_00391778 */
extern s32 D_001D4D08[];
extern s32 D_001D4D0C[];
extern s32 D_001D4D10[];
extern s32 D_001D4D14[];
extern s32 D_001D4D18[];
extern s32 D_001D4D1C[];
extern s32 D_001D4CF8[];
void func_00391778(void) {
    *(unsigned long *)((u8 *)D_001D4CF8[0] + 0x18) = (long)D_001D4D08[0] | ((long)D_001D4D0C[0] << 12) | ((long)D_001D4D10[0] << 23) | ((long)D_001D4D14[0] << 27) | ((long)D_001D4D18[0] << 32) | ((long)D_001D4D1C[0] << 44);
}
/* localdecomp:end func_00391778 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003917E0);

extern s32 D_001D4D08_003917E8;
extern s32 D_001D4D0C_003917E8;
/* localdecomp:start func_003917E8 */
__asm__(".extern D_001D4D08_003917E8, 16");
void func_003917E8(s32 dx, s32 dy, s32 clamp) {
    extern void func_00391778(void);
    s32 x = D_001D4D08_003917E8 + dx;
    s32 y = (&D_001D4D08_003917E8)[1] + dy;
    D_001D4D08_003917E8 = x;
    D_001D4D0C_003917E8 = y;
    if (clamp) {
        dx = x > -1 ? x : 0;
        dy = y > -1 ? y : 0;
        x = dx < 3001 ? dx : 3000;
        y = dy < 451 ? dy : 450;
        D_001D4D08_003917E8 = x;
        (&D_001D4D08_003917E8)[1] = y;
    }
    func_00391778();
}
/* localdecomp:end func_003917E8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00391870);
