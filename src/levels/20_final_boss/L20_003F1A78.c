#include "common.h"
#include "vu0.h"

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

/* localdecomp:start func_L20_003F4320 */
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

u8 *func_L20_003F4320(u8 *a0, f32 x, f32 y) {
    u8 *o;
    u8 *p;

    o = func_003C24B0(0x1D91, 0xB0);
    if (o == 0) {
        return 0;
    }
    o[0x20] = 0;
    o[0x30] = 0xFF;
    *(s16 *)(o + 0x32) = 0xFF;
    p = *(u8 **)(o + 0x68);
    *(vu0_q *)(o + 0x10) = *(vu0_q *)a0;
    *(f32 *)(p + 0x90) = 10.0f;
    qzero(p);
    *(f32 *)(p + 0x94) = 10.0f;
    *(f32 *)(p + 0x98) = x;
    *(f32 *)(p + 0x9C) = y;
    func_L01_004450F0(o, 0, -1);
    return o;
}
/* localdecomp:end func_L20_003F4320 */

INCLUDE_ASM("asm/levels", func_L20_003F43D0);
