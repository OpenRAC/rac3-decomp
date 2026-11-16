/* PAL near miss (Codex wave 6): near miss: 129 words differ with "-O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 * Worker's note: 128 diff; build/codex/w301/logs/func_L07_003CE3A8-05-wrapper.log; fixed default assembler pools 0.08f and 0.025f instead of inline lui/ori/mtc1; color packing order and first draw setup also differ; full PAL control flow and both endpoint pairs reconstructed; ...
 */
#include "common.h"
/* localdecomp:start func_L07_003CE3A8 */
void func_L07_003CE3A8(u8 *moby)
{
    extern void func_003C2F58(u8 *, s32, f32 *);
    extern void func_L01_0040A8C0(f32 *, f32 *, s32, s32, f32, f32, f32, u32, u32, u32, u32);
    extern void func_L07_003CE330(u8 *, f32 *, f32 *);
    extern s32 func_L07_003CECD0(s32, s32);
    extern void func_L07_003CE618(void *, void *, s32, s32, s32, u32, u32);
    f32 start[4] __attribute__((aligned(16)));
    f32 end[4] __attribute__((aligned(16)));
    u8 *state = *(u8 **)(moby + 0x68);
    u32 color;
    if (*(u16 *)(moby + 0x34) & 1)
        return;
    func_003C2F58(moby, 0, start);
    func_003C2F58(moby, 1, end);
    color = ((state[0x41F] << 16) | ((state[0x41F] << 8) | 0x7F000000)) | state[0x41D];
    func_L01_0040A8C0(start, end, 14, 1, 0.08f, 0.75f, *(f32 *)(state + 0x400), color, color, color, color);
    func_L01_0040A8C0(start, end, 14, 1, 0.025f, 0.75f, *(f32 *)(state + 0x400), 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF);
    if (state[0x407] != 0) {
        u32 flash;
        s32 red, green, blue;
        u32 random_color;
        func_L07_003CE330(moby, start, end);
        flash = ((state[0x41F] << 16) | ((state[0x41F] << 8) | 0x40000000)) | state[0x41D];
        red = func_L07_003CECD0(state[0x41D], 128);
        green = func_L07_003CECD0(state[0x41E], 128);
        blue = func_L07_003CECD0(state[0x41F], 128);
        random_color = (blue << 16) | (green << 8) | red;
        func_L07_003CE618(state + 0x2C0, state + 0x360, state[0x409], state[0x408], state[0x40A] + 100, flash, random_color);
    }
    func_003C2F58(moby, 2, start);
    func_003C2F58(moby, 3, end);
    func_L01_0040A8C0(start, end, 14, 1, 0.08f, 0.75f, *(f32 *)(state + 0x400), color, color, color, color);
    func_L01_0040A8C0(start, end, 14, 1, 0.025f, 0.75f, *(f32 *)(state + 0x400), 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF);
}
/* localdecomp:end func_L07_003CE3A8 */
