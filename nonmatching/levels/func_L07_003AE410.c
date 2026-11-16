/* PAL near miss (Codex wave 10): near miss: 108 words differ with the file's flags.
 * Worker's note: 99 positional diff; build/codex/w520/func_L07_003AE410.02.log; fixed default assembler inserts mfc1-store hazard nops and emits 9 float pool loads where retail uses lui/ori/mtc1; no alternate flags attempted
 */
#include "common.h"
/* localdecomp:start func_L07_003AE410 */
void func_L07_003AE410(u8 *m) {
    extern s32 func_L07_003C1AF8(u8 *);
    extern f32 func_L07_003C1B40(s32);
    extern void func_L01_00446058(u8 *, s32, s32);
    extern void func_L01_0045BD78(u8 *, f32, f32, f32, f32);
    extern void func_L07_003AECD8(int *);
    extern void func_L07_003AECA8(s32);
    u8 *p = *(u8 **)(m + 0x68);
    s32 kind = func_L07_003C1AF8(m);
    u8 *q = p + 0x120;
    f32 scale = func_L07_003C1B40(kind);
    *(s16 *)(q + 4) = *(s16 *)(p + 0x124) * scale;
    *(f32 *)(p + 0x120) = *(s16 *)(q + 4);
    q[0x14] = p[0x134] * scale;
    q[0x15] = p[0x135] * scale;
    q[0x16] = p[0x136] * scale;
    if (kind == 1 || kind == 3) func_L01_00446058(m, 0x1D88, 0x19D2);
    q[0x28] = 20;
    *(f32 *)(q + 0x10) = 0.25f;
    q[0x2A] = 14;
    q[9] = 0;
    *(s32 *)(p + 0x11C) = 0;
    p[0x170] = 5;
    p[0x172] = 255;
    *(f32 *)(p + 0x30) = 0.8f;
    *(f32 *)(p + 0x34) = -0.3f;
    *(f32 *)(p + 0x40) = 3.1415927f;
    *(f32 *)(p + 0x60) = 0.7853982f;
    *(f32 *)(p + 0x5C) = 0.00392f;
    p[0x1A8] = 255;
    p[0x171] = 255;
    func_L01_0045BD78(m, 0.0048f, 0.24f, 0.0025132743f, 0.12566371f);
    *(void (**)(int *))(p + 0x244) = func_L07_003AECD8;
    p[0x25F] = 7;
    *(void (**)(s32))(p + 0x248) = func_L07_003AECA8;
    p[0x25D] = 6;
    *(s16 *)(p + 0x24C) = -1;
    func_L07_003AECA8((s32)m);
}
/* localdecomp:end func_L07_003AE410 */
