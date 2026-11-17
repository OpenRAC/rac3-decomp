/* NTSC-U draft (Claude wave C2): C of func_L07_0030FC78, the NTSC-U twin of func_L07_0030FFE8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 57 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L07_0030FC78", whose code is not the PAL one).
 * Worker's note: flags: working flags '-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (PAL file: '-O2 -G8 -fopt-stack -mno-check-zero-division'). MATCH only with @ps2as added to the PAL flags (float constants lui/ori/mtc1; with the PAL flags 57 diff); same shape as ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_0030FC78 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_003BCFB0(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_004A72A8(s32, s32, u8 *, s32);
extern void func_L07_0030FDF0(u8 *, u8 *);

u8 *func_L07_0030FC78(u8 *a0, void *a1, u8 a2, f32 f12) {
    f32 pos[4];
    u8 *o;
    u8 *s;
    f32 *p;
    s32 i;

    *(u128_t *)pos = *(u128_t *)a1;
    o = func_003BCFB0(0xABE, 0x80);
    if (o != 0) {
        o[0x30] = 0x7F;
        *(s16 *)(o + 0x32) = 0x7F;
        o[0x31] = 1;
        i = 0;
        s = *(u8 **)(o + 0x68);
        p = (f32 *)s;
        *(long *)(o + 0x38) = *(long *)(a0 + 0x38);
        *(u128_t *)(o + 0x10) = *(u128_t *)pos;
        qzero(o + 0xF0);
        *(f32 *)(o + 0xF8) = f12;
        *(f32 *)(o + 0x18) += 0.5f;
        *(f32 *)(s + 0x70) = 0.5f;
        *(u8 **)(o + 0xB8) = a0;
        s[0x7C] = a2;
        *(s32 *)(s + 0x74) = 0;
        *(s32 *)(s + 0x78) = 0;
        for (; i < 0x1C; i++) {
            *p = func_0037E250(-4.0f, 4.0f) * 0.4f / 120.0f;
            if (i == 0 || i == 0x1B) {
                *(s32 *)p = 0;
            }
            p++;
        }
        func_L01_004A72A8(0x10, 4, o, 0x1A1F);
        func_L07_0030FDF0(o, s);
    }
    return o;
}
/* localdecomp:end func_L07_0030FC78 */
