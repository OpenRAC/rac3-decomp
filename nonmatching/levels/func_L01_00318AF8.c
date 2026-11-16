/* PAL near miss (Codex wave 10): near miss: 14 words differ with the file's flags.
 * Worker's note: Best 14 diff: w517/func_L01_00318AF8.v7.log; color alternate constant sinks into branch, opposite branch-likely and one extra instruction; no metadata
 */
#include "common.h"
/* localdecomp:start func_L01_00318AF8 */
#include "vu0.h"
extern E_L01_00272780_00318408 D_L01_00272780[];

void func_L01_00318AF8(u8 *obj, vu0_q *position, s32 value) {
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_00382538(void);
    extern f32 func_L01_00443A18(f32, f32);
    u8 *p = (u8 *)D_L01_00272780;
    s32 end = (s32)(D_L01_00272780 + 64);
    s32 color = 0x204060, alternate = 0x800000;
    s32 *state = *(s32 **)(obj + 0x68);
search:
    if (*(s32 *)(p + 0x44) != 0) goto next;
    {
            *(u8 **)(p + 0x44) = obj;
            *(s32 *)(p + 0x30) = value;
            *(vu0_q *)p = *position;
            qzero(p + 0x10);
            if (state[6] == 0) *(s32 *)(p + 0x38) = alternate;
            else *(s32 *)(p + 0x38) = color;
            *(f32 *)(p + 0x20) = func_003824E0(0.1f, 0.3f);
            *(f32 *)(p + 0x24) = func_003824E0(0.4f, 0.5f);
            *(s32 *)(p + 0x40) = *(s32 *)(p + 0x3C) = (func_00382498(25, 40) * 5 + 2) / 6;
            *(f32 *)(p + 0x2C) = func_00382538();
            *(f32 *)(p + 0x28) = func_L01_00443A18(180.0f, 360.0f) * 0.01745329238474369f * 0.020000001415610313f;
            state[0]++;
            return;
        }
next:
    p += 0x50;
    if ((s32)p < end) goto search;
}
/* localdecomp:end func_L01_00318AF8 */
