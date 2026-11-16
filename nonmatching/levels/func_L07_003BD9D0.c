/* PAL near miss (Codex wave 10): near miss: 14 words differ with the file's flags.
 * Worker's note: 14 word diffs of 142, same size; 0.5/1.0 float register assignment and three constant byte-store order; six compiles including inline initializer and chained-store forms. Best log build/codex/w501/003BD9D0-02.log
 */
#include "common.h"
/* localdecomp:start func_L07_003BD9D0 */
typedef int Quad_003BD9D0 __attribute__((mode(TI)));
void func_L07_003BD9D0(u8 *obj) {
    extern void func_L01_00445F40(void *, s32);
    extern s32 func_L07_003C1AF8(void);
    extern f32 func_L07_003C1B40(s32);
    extern void func_L01_00446058(void *, s32, s32);
    extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
    extern void func_L07_003BE368(char *);
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *p;
    u8 *q;
    s32 type;
    f32 scale;
    func_L01_00445F40(obj, 0x19BE);
    p = s + 0x30;
    type = func_L07_003C1AF8();
    scale = func_L07_003C1B40(type);
    *(s16 *)(p + 4) = (s32)((f32)*(s16 *)(s + 0x34) * scale);
    *(f32 *)p = (f32)*(s16 *)(p + 4);
    p[0x14] = (s32)((f32)s[0x44] * scale);
    p[0x15] = (s32)((f32)s[0x45] * scale);
    p[0x16] = (s32)((f32)s[0x46] * scale);
    if (type == 1 || type == 3) func_L01_00446058(obj, 0x1D89, 0x19BE);
    { f32 half = 0.5f; f32 one = 1.0f;
    p[0x28] = 20;
    p[0x2A] = 14;
    *(f32 *)(p + 0x10) = one;
    p[0xF] = 0;
    p[9] = 0;
    q = s + 0x70;
    q[0x48] = 255;
    q[0x10] = 8;
    q[0x77] = 1;
    *(f32 *)(q + 0x3C) = 0.15f;
    *(f32 *)(q + 0x58) = 0.35f;
    *(f32 *)(q + 0x30) = one;
    *(f32 *)(q + 0x34) = half;
    *(f32 *)(q + 0xB0) = one;
    *(f32 *)(q + 0x5C) = half;
    *(s32 *)(q + 0xA8) = 0;
    *(f32 *)(s + 0x150) = one;
    *(f32 *)(s + 0x154) = 0.3f;
    *(f32 *)(s + 0x160) = 1.5707963705062866f;
    *(f32 *)(s + 0x180) = 0.24434609711170197f;
    *(f32 *)(s + 0x17C) = 0.003920000046491623f;
    *(f32 *)(s + 0x158) = half;
    *(f32 *)(s + 0x15C) = half;
    *(f32 *)(s + 0x184) = half;
    *(s32 *)(s + 0x23C) = 0;
    *(s16 *)(s + 0x4F6) = 0;
    }
    *(Quad_003BD9D0 *)(s + 0x340) = *(Quad_003BD9D0 *)(obj + 0x10);
    *(Quad_003BD9D0 *)(s + 0x350) = *(Quad_003BD9D0 *)(obj + 0xF0);
    func_L01_0045BD78(obj, 0.0020000000949949026f, 0.10000000894069672f, 0.005026548635214567f, 0.12566371262073517f);
    func_L07_003BE368((char *)obj);
}
/* localdecomp:end func_L07_003BD9D0 */
