/* functional: high. Draft verified against PAL asm word by word; only scheduling differs. */
#include "common.h"
/* localdecomp:start func_L07_003C7E70 */
typedef int Q_003C7E70 __attribute__((mode(TI)));
void func_L07_003C7E70(u8 *obj) {
    extern void func_L01_00445F40(void *, s32);
    extern s32 func_L07_003C1AF8(void);
    extern f32 func_L07_003C1B40(s32);
    extern void func_L01_00446058(void *, s32, s32);
    extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
    extern void func_L07_003C86D0(char *);
    u8 *state = *(u8 **)(obj + 0x68);
    u8 *stats;
    u8 *move;
    u8 *tune;
    s32 kind;
    f32 scale;
    func_L01_00445F40(obj, 0x19BD);
    stats = state + 0x30;
    kind = func_L07_003C1AF8();
    scale = func_L07_003C1B40(kind);
    *(s16 *)(stats + 4) = (s32)(*(s16 *)(state + 0x34) * scale);
    *(f32 *)(state + 0x30) = *(s16 *)(stats + 4);
    stats[0x14] = (s32)(state[0x44] * scale);
    stats[0x15] = (s32)(state[0x45] * scale);
    stats[0x16] = (s32)(state[0x46] * scale);
    if (kind == 1 || kind == 3) func_L01_00446058(obj, 0x1D8A, 0x19BD);
    stats[0x28] = 20;
    stats[0x2A] = 14;
    *(f32 *)(stats + 0x10) = 1.0f;
    stats[0xF] = 0;
    stats[9] = 0;
    move = state + 0x70;
    *(f32 *)(move + 0x3C) = 0.15f;
    *(f32 *)(move + 0x30) = 1.0f;
    *(f32 *)(move + 0xB0) = 1.0f;
    *(f32 *)(move + 0x58) = 0.35f;
    move[0x48] = 255;
    move[0x10] = 8;
    move[0x77] = 1;
    *(f32 *)(move + 0x5C) = *(f32 *)(move + 0x34) = 0.5f;
    tune = state + 0x150;
    *(f32 *)tune = 0.6f;
    *(f32 *)(tune + 4) = 0.3f;
    *(f32 *)(tune + 0xC) = *(f32 *)(tune + 8) = 0.5f;
    *(f32 *)(tune + 0x10) = 1.5707963705062866f;
    *(f32 *)(tune + 0x30) = 0.24434609711170197f;
    *(f32 *)(tune + 0x2C) = 0.19600002467632294f;
    *(f32 *)(tune + 0x34) = 0.2f;
    *(s32 *)(tune + 0xEC) = 0;
    *(Q_003C7E70 *)(state + 0x440) = *(Q_003C7E70 *)(obj + 0x10);
    *(Q_003C7E70 *)(state + 0x450) = *(Q_003C7E70 *)(obj + 0xF0);
    func_L01_0045BD78(obj, 0.002400000113993883f, 0.12000000476837158f, 0.005026548635214567f, 0.12566371262073517f);
    func_L07_003C86D0((char *)obj);
}
/* localdecomp:end func_L07_003C7E70 */
