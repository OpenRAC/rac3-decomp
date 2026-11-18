/* PAL port (round 7, Sonnet Y4) of the NTSC-U draft of func_L01_004CAA98: callees func_0011BB58 / func_L01_004CDC38, default 0x96, 135.0f.
 * near miss: 33 words differ with the file's flags. Retail computes v (nor + movn) BEFORE the first call, re-multiplies i * 0x230 after
 * the first call and keeps the constant 0x230 in $s2 (o, i, 0x230, v in $s3, $s1, $s2, $s0); ours CSEs the product in the first cse pass
 * (-da dump: two mult after jump, one after cse), and keeps it in a saved register. v first, ternary, array types, a u32 cast and
 * o + (i * 0x230 + 0x4610) all give 33-35.
 */
#include "common.h"

/* localdecomp:start func_L01_004CE758 */
extern s32 func_0011BB58(void *, s32, s32);
extern void func_L01_004CDC38(void *, s32, s32, f32, f32);

void func_L01_004CE758(u8 *o, s32 i, s32 a, s32 b)
{
    s32 v = 0x96;
    if (b != -1) {
        v = b;
    }
    func_0011BB58(o + i * 0x230 + 0x4698, a, 0xFE);
    func_L01_004CDC38(o + (i * 0x230 + 0x4610), 1, v, 255.0f, 135.0f);
}
/* localdecomp:end func_L01_004CE758 */
