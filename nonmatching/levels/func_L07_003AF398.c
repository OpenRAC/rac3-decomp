/* PAL near miss (Codex wave 10): near miss: 104 words differ with the file's flags.
 * Worker's note: 106 positional diffs, 604 vs 616 bytes: build/codex/w496/func_L07_003AF398.context.log. Existing func_L07_003AF7B8(u8*) omits retail float f12 at three calls (D4); requires context correction to (u8*,f32) and forwarding into func_0038D750, no incompatible ...
 */
#include "common.h"
/* localdecomp:start func_L07_003AF398 */
void func_L07_003AF398(u8 *m)
{
    extern void func_L07_003AF600(void *);
    extern void func_L07_003AF678(u8 *);
    extern s32 func_L07_003AF758(u8 *);
    extern void func_L07_003AF7B8(u8 *);
    extern void func_L07_003AF7F8(u8 *);
    extern void func_L07_003AF920(u8 *);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_L01_004AA760(s32, void *);
    extern s32 func_L01_004561B8(void *);
    extern void func_003A52A0(s32, s32, void *);
    extern s32 func_0038CB00(void *);
    u8 *p;
    func_L07_003AF600(m);
    func_L07_003AF678(m);
    p = *(u8 **)(m + 0x68);
    switch (m[0x20]) {
    case 1:
        if (func_L07_003AF758(m)) {
            func_003A52A0(1, 4, m);
            func_L01_004450F0(m, 2, -1);
        }
        break;
    case 2:
        *(f32 *)(p + 0xD4) += 0.010053097270429134f;
        if (*(f32 *)(p + 0xD4) > 0.25132742524147034f) {
            *(f32 *)(p + 0xD4) = 0.25132742524147034f;
            func_L01_004450F0(m, 3, -1);
        }
        func_L07_003AF7F8(m);
        /* Existing file prototype omits retail's float argument. */
        func_L07_003AF7B8(m);
        if (!func_L07_003AF758(m)) func_L01_004450F0(m, 4, -1);
        break;
    case 3:
        if (func_L01_004561B8(m)) *(s16 *)(p + 0xE8) = 250;
        if (++*(u16 *)(m + 0x96) > 5) {
            func_003A52A0(0, 0, m);
            func_L07_003AF920(m);
            *(u16 *)(m + 0x96) = 0;
        }
        func_L07_003AF7F8(m);
        func_L07_003AF7B8(m);
        if (func_0038CB00(p + 0xE8) || !func_L07_003AF758(m)) func_L01_004450F0(m, 4, -1);
        break;
    case 4:
        *(f32 *)(p + 0xD4) -= 0.010053097270429134f;
        if (*(f32 *)(p + 0xD4) <= 0.0f) {
            *(f32 *)(p + 0xD4) = 0.0f;
            if (func_L07_003AF758(m)) func_L01_004450F0(m, 5, -1);
            else {
                func_L01_004AA760(1, m);
                func_L01_004450F0(m, 1, -1);
            }
        }
        func_L07_003AF7B8(m);
        break;
    case 5:
        if (func_L01_004561B8(m)) *(s16 *)(p + 0xE8) = 100;
        if (!func_L07_003AF758(m)) {
            func_L01_004AA760(1, m);
            func_L01_004450F0(m, 1, -1);
        } else if (func_0038CB00(p + 0xE8)) func_L01_004450F0(m, 2, -1);
        break;
    }
}
/* localdecomp:end func_L07_003AF398 */
