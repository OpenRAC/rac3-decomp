#include "common.h"

/* localdecomp:start func_L39_0068AEF8 */
typedef struct {
    s32 pad0[0x18];
    s32 (**vt)(void *, s32);
} S1_68AEF8;
typedef struct {
    u8 pad0[0x110];
    S1_68AEF8 *unk110[(0x290 - 0x110) / 4];
    s32 unk290;
} S0_68AEF8;
/* defined later in this file with an S0_68B3C0 * parameter; no prototype here so the types agree */
s32 func_L39_0068B3C0();
extern void func_L39_00689A90(void);

s32 func_L39_0068AEF8(S0_68AEF8 *a, s32 b) {
    func_L39_0068B3C0(a);
    func_L39_00689A90();
    if (a->unk290 >= 0) {
        S1_68AEF8 *o = a->unk110[a->unk290];
        if (o->vt[5](o, b) == 1) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_0068AEF8 */
