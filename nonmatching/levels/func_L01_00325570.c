/* PAL near miss (Codex wave 6): near miss: 2 words differ with the file's flags.
 * Worker's note: 2 diff; build/codex/w267/func_L01_00325570.03.log; prologue loop-counter and clear-array-base addiu swapped at +0x18/+0x40; for, reversed initialization and do/while unchanged; explicit clear cursor regresses
 */
#include "common.h"
/* localdecomp:start func_L01_00325570 */
typedef struct { u8 pad[0x120]; s32 ids[16]; s32 classes[16]; s32 heads[16]; s32 counts[16]; s32 totals[16]; s32 a260[16]; s32 a2A0[16]; } State_00325570;
extern u8 *D_L01_001E001C;
extern u16 *D_L01_0021DE20[];
extern s32 D_001E0058_sda;
__asm__(".extern D_001E0058_sda, 4");
void func_L01_00325570(void *a, S_324F38 *b) {
    extern s32 func_L01_00325438(void *, S_324F38 *, u8 *);
    State_00325570 *state = (State_00325570 *)b;
    s32 i, j;
    s32 *heads = state->heads;
    s32 *counts = state->counts;
    s32 *totals = state->totals;
    u16 *q;
    u8 *e;
    s32 n;
    for (i = 15, j = 0; i >= 0; i--, j++) {
        state->ids[j] = -1;
        state->classes[j] = 0;
        state->heads[j] = 0;
        state->counts[j] = 0;
        state->totals[j] = 0;
        state->a260[j] = 0;
        state->a2A0[j] = 0;
    }
    if (*(s32 *)((u8 *)b + 0x34) != -1) {
        for (q = D_L01_0021DE20[*(s32 *)((u8 *)b + 0x34)];
             (*(s32 *)((u8 *)b + 0x34) & 0xFF) != 0xFF &&
             *(s32 *)((u8 *)b + 0x34) <= D_001E0058_sda && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L01_0021DE20[*(s32 *)((u8 *)b + 0x34)]); q++) {
            e = D_L01_001E001C + ((*q & 0x7FFF) << 8);
            if (e == 0) break;
            i = func_L01_00325438(a, b, e);
            if (i != -1) {
                n = func_L01_00449050(e);
                *(s32 *)(n + 4) = *(s32 *)((u8 *)heads + (i << 2));
                *(s32 *)((u8 *)heads + (i << 2)) = (s32)e;
                *(s32 *)((u8 *)counts + (i << 2)) += 1;
                *(s32 *)((u8 *)totals + (i << 2)) += 1;
            }
        }
    }
}
/* localdecomp:end func_L01_00325570 */
