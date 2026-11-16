/* NTSC-U draft (Claude wave C2): C of func_L08_003A81D8, the NTSC-U twin of func_L08_003AA088, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 7 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L08_003A81D8", whose code is not the PAL one).
 * Worker's note: flags: needs '@ps2as' added to the PAL file's flags (float constants -pi/pi/0.35f built with lui/ori/mtc1; PAL flags: 56 diff). With @ps2as 7 diff (about 80 variants of the byte/half store order): only the swap of the first two constant registers (retail ...
 */
#include "common.h"

/* localdecomp:start func_L08_003A81D8 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_003BCFB0(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_003C26C8(u8 *);
extern s32 D_L08_001DE2F0;
__asm__(".extern D_L08_001DE2F0, 4");
extern s32 D_L08_001DE2E8;
__asm__(".extern D_L08_001DE2E8, 4");

u8 *func_L08_003A81D8(u8 *a0, u8 *a1, u8 *a2, f32 f12, f32 f13) {
    u8 *m = func_003BCFB0(0x1A98, 0x80);
    u8 *d;

    if (m != 0) {
        *(u16 *)(m + 0x32) = 0x1FF;
        *(u16 *)(m + 0x34) |= 0x2000;
        m[0x23] = 0x70;
        m[0x31] = 1;
        m[0x30] = 0xFF;
        m[0x20] = 0;
        d = *(u8 **)(m + 0x68);
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 0.35f;
        if (a2 != 0) {
            *(u8 **)(m + 0xB8) = a2;
        }
        *(u128_t *)(m + 0x10) = *(u128_t *)a0;
        *(u128_t *)d = *(u128_t *)a1;
        *(s32 *)(d + 0x10) = D_L08_001DE2F0;
        *(s32 *)(d + 0x18) = D_L08_001DE2E8;
        *(f32 *)(d + 0x28) = f13;
        *(f32 *)(d + 0x20) = f12;
        *(s32 *)(d + 0x14) = 0;
        *(f32 *)(m + 0xF0) = func_0037E250(-3.14159274f, 3.14159274f);
        *(f32 *)(m + 0xF4) = func_0037E250(-3.14159274f, 3.14159274f);
        *(f32 *)(m + 0xF8) = func_0037E250(-3.14159274f, 3.14159274f);
        *(s32 *)(m + 0xFC) = 0;
        func_003C26C8(m);
    }
    return m;
}
/* localdecomp:end func_L08_003A81D8 */
