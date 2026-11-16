/* PAL near miss (Claude wave S2/pal): flags: byte-exact only with "@ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 * Worker's note: re-verified wave S draft: MATCH only with @ps2as added to line 1269 of config/levels/text_parts.txt (src/levels/shared/L13_003ADA98.c); without it the float constants are gp literals (36 diff). No vu0 flag needed (qzero only). The file declares none of its ...
 */
#include "common.h"

/* localdecomp:start func_L13_003AEC48 */
#include "vu0.h"
extern f32 D_001DE6DC_sda, D_001DE6E0_sda, D_001DE6EC_sda;
__asm__(".extern D_001DE6DC_sda, 4");
__asm__(".extern D_001DE6E0_sda, 4");
__asm__(".extern D_001DE6EC_sda, 4");
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);

void func_L13_003AEC48(u8 *obj) {
    f32 *o = (f32 *)obj;
    u8 *d = *(u8 **)(obj + 0x68);
    f32 k;

    func_L01_0044EAE0(obj, d + 0x3B0, d + 0x3B4, D_001DE6DC_sda, D_001DE6E0_sda * 0.017453292f * 0.020000001f, -1.0f);
    qzero(d + 0x1F0);
    k = 1.0f - D_001DE6EC_sda;
    *(s32 *)(d + 0x204) = 0;
    o[0xF0 / 4] *= k;
    o[0xF4 / 4] *= k;
}
/* localdecomp:end func_L13_003AEC48 */
