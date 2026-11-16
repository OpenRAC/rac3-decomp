/* PAL near miss (Codex wave 7): near miss: 97 words differ with the file's flags.
 * Worker's note: Best 96 diff, fixed PAL flags: build/codex/w353/func_003A8440.05.log; outer base/search allocation, immediate float materialization and VU helper scheduling remain; existing vu0.h helpers, no forbidden asm
 */
#include "common.h"
/* localdecomp:start func_003A8440 */
#include "vu0.h"
extern vu0_v4 D_00222400_003A8440[];
typedef struct {
    u8 pad[0x30]; s32 f30; s32 f34; u8 pad38[0xC]; s16 count;
    u8 pad46[0xA]; S2_3A2BC0 *state; u8 pad54[0x14C]; u8 *objects[4];
} Base_003A8440;
extern Base_003A8440 D_00225700_003A8440;
void func_003A8440(void) {
    extern void func_0038D3E0(void *, void *, void *);
    extern void func_0038D348(void *, void *, f32);
    Base_003A8440 *base = &D_00225700_003A8440;
    u8 *m = 0;
    vu0_v4 local;
    s32 lo = -1, hi = 9999, index = 0;
    s32 i;
    if (base->f30 == 0) {
        lo = 150;
        hi = 1800;
        index = 3;
    }
    if (base->f34 > hi) base->state = 0;
    if (base->f34 >= lo && base->f34 <= hi) {
        for (i = 0; i < base->count; i++) {
            if (*(s16 *)(base->objects[i] + 0xAA) == 0xD54) {
                m = base->objects[i];
                break;
            }
        }
        if (m) {
            for (i = 0; i < 4; i++) {
                func_0038D3E0(((vu0_v4 *)base->state->p20) + i, (vu0_v4 *)D_001D7080 + i, (u8 *)m + 0xC0);
                vec_add_ba(((vu0_v4 *)base->state->p20) + i, ((vu0_v4 *)base->state->p20) + i, m + 0x10);
                vec_sub_ab(&local, D_00222400_003A8440, ((vu0_v4 *)base->state->p20) + i);
                func_0038D348(&local, &local, 0.020000001f);
                vec_add_ba(((vu0_v4 *)base->state->p20) + i, ((vu0_v4 *)base->state->p20) + i, &local);
            }
        }
        base->state->p40 = (s32)base->objects[index];
    }
}
/* localdecomp:end func_003A8440 */
