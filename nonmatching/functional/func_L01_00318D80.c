/* exact: high. check.py MATCH at level 01. */
/* PAL near miss (Codex wave 8): near miss: 0 words differ with the file's flags.
 * Worker's note: Canonical MATCH after interleaved float parameter; all log w443/func_L01_00318D80.all.log: 33/34 MATCH, level08 two jal relocations resolve 0x311888 versus retail 0x31C280 (pal_asm names func_L01_00392130). Level08 detail log ...
 */
#include "common.h"

/* localdecomp:start func_L01_00318D80 */
#include "vu0.h"
extern E_L01_00272780_00318408 D_L01_00272780[];
extern G_00318408 D_001A4BE0;
void func_L01_00318D80(s32 owner) {
    extern void func_L01_003190A8(void *, f32, s32, s32, s32, s32, f32, f32);
    vu0_v4 pos;
    E_L01_00272780_00318408 *p;
    s32 i;
    for (i = 0; i < 64; i++) {
        p = &D_L01_00272780[i];
        if (p->active == owner) {
            vec_add_ab(&pos, p, (u8 *)D_001A4BE0.x25C0 + 0x10);
            func_L01_003190A8(&pos, *(f32 *)((u8 *)p + 0x20), 0x7F7F7F, *(s32 *)((u8 *)p + 0x34), 0x31, 2, *(f32 *)((u8 *)p + 0x2C), 0.001f);
            func_L01_003190A8(&pos, *(f32 *)((u8 *)p + 0x24), *(s32 *)((u8 *)p + 0x38), *(s32 *)((u8 *)p + 0x34) >> 1, 0x31, 2, *(f32 *)((u8 *)p + 0x2C), 0.001f);
        }
    }
}
/* localdecomp:end func_L01_00318D80 */
