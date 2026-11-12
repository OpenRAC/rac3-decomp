#include "common.h"

INCLUDE_ASM("asm/levels", func_L20_003F1A78);

INCLUDE_ASM("asm/levels", func_L20_003F21A8);

INCLUDE_ASM("asm/levels", func_L20_003F22C0);

INCLUDE_ASM("asm/levels", func_L20_003F27E8);

INCLUDE_ASM("asm/levels", func_L20_003F2918);

INCLUDE_ASM("asm/levels", func_L20_003F32D0);

INCLUDE_ASM("asm/levels", func_L20_003F3528);

/* localdecomp:start func_L20_003F3F28 */
extern f32 func_0038CF38(f32 *, f32 *);
extern f32 D_L20_001E2E80[];
__asm__(".extern D_L20_001E2E80, 16");
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 D_L20_001DF408;
__asm__(".extern D_L20_001DF408, 4");

void func_L20_003F3F28(u8 *p) {
    f32 len = func_0038CF38((f32 *)(p + 0x10), D_L20_001E2E80);

    if (len <= 2.0f && 1.0f < len) {
        func_003C4138(&D_L20_001DF408, 0.5f, 0.2f);
    } else if (len <= 1.0f) {
        func_003C4138(&D_L20_001DF408, 0.0f, 0.2f);
    } else {
        func_003C4138(&D_L20_001DF408, 2.0f, 0.1f);
    }
}
/* localdecomp:end func_L20_003F3F28 */

INCLUDE_ASM("asm/levels", func_L20_003F3FF8);

INCLUDE_ASM("asm/levels", func_L20_003F4320);

INCLUDE_ASM("asm/levels", func_L20_003F43D0);
