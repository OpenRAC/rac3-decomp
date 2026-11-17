/* NTSC-U draft (2026-11-14, Claude worker): C of func_L03_003B7158, the NTSC-U twin of func_L03_003B8DF8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L03_003B8B28.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L03_003B8B28 (src/levels/shared/L03_003B8B28.c) */
/* localdecomp:start func_L03_003B7158 */
typedef int u128_3B7158 __attribute__((mode(TI)));
extern u8 *func_003BCFB0(s32, s32);
extern void func_003BDA38(u8 *, s32, u8 *);
extern u8 D_L03_001E1E88[];
extern u8 D_L03_003B7490[];
extern s32 D_001DEAC8_sda;
__asm__(".extern D_001DEAC8_sda, 4");
extern void func_L03_0034A658(u8 *, s32, s32, s32, f32, u8 *);

u8 *func_L03_003B7158(u8 *a0, s32 a1, f32 f) {
    u8 *m = func_003BCFB0(0x1C16, 0x80);
    if (m != 0) {
        u8 *pv = *(u8 **)(m + 0x68);
        u8 *s;
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0x40;
        m[0x31] = 1;
        *(u8 **)(m + 0xB8) = a0;
        *(f32 *)(pv + 0x20) = f * 0.016666668f;
        *(s32 *)(pv + 0x24) = 0;
        *(s32 *)(pv + 0x2C) = a1;
        s = *(u8 **)(a0 + 0x68);
        func_003BDA38(*(u8 **)s, a1, pv + 0x10);
        func_003BDA38(*(u8 **)s, a1 - 0x20, pv);
        *(s32 *)(pv + 0x28) = *(s32 *)s;
        *(u128_3B7158 *)(m + 0x10) = *(u128_3B7158 *)(pv + 0x10);
    }
    if (D_001DEAC8_sda == 0) {
        D_001DEAC8_sda = 1;
        func_L03_0034A658(D_L03_001E1E88, 0x1E, 0x14, 2, 2.1f, D_L03_003B7490);
    }
    return m;
}
/* localdecomp:end func_L03_003B7158 */
