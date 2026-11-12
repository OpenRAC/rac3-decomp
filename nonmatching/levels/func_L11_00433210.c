/* near miss (level 11, Obani Moons): 35 differences, one cause: retail computes p->f38 & 0x400 into $v1 before the distance call and never uses it (a dead lw/andi pair, 2 instructions), which shifts everything after it; with them every other instruction matches. The C here folds the test away; tried a ternary of two equal locals before and inside the compare, if/else, equal float/double constants, a separate flag local (about 12 compiles) */
#include "common.h"

/* localdecomp:start func_L11_00433210 */
typedef struct {
    u8 pad0[0x38];
    s32 f38;
    u8 pad3C[0xC4 - 0x3C];
    u8 *fC4;
    s16 fC8;
    s16 fCA;
} P_433210;
extern P_433210 *func_L01_0045B958(void *);
extern void func_L01_0045C150(void *, void *, s32, s32);
extern void func_L01_0045CED0(void *, void *);
extern f32 func_0038CF00(void *, void *);

s32 func_L11_00433210(u8 *a0, u8 *path)
{
    P_433210 *p;
    f32 near0 = 0.5f;
    f32 near1 = 0.5f;
    f32 thr;

    p = func_L01_0045B958(a0);
    if (p == 0) {
        return 0;
    }
    if (path != p->fC4) {
        func_L01_0045C150(a0, path, -1, 0);
    }
    func_L01_0045CED0(a0, path + (p->fC8 * 16 + 0x10));
    thr = (p->f38 & 0x400) ? near0 : near1;
    if (func_0038CF00(a0 + 0x10, path + (p->fC8 * 16 + 0x10)) <= thr) {
        if (p->fCA == p->fC8) {
            return 1;
        }
        if (p->fCA < p->fC8) {
            p->fC8--;
        } else {
            p->fC8++;
        }
    }
    return 0;
}
/* localdecomp:end func_L11_00433210 */
