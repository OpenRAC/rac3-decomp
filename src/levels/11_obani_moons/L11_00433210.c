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
extern s32 func_L01_0045CED0(void *, void *);
extern f32 func_0038CF00(void *, void *);

s32 func_L11_00433210(u8 *a0, u8 *path)
{
    P_433210 *p;
    f32 d;

    p = func_L01_0045B958(a0);
    if (p == 0) {
        return 0;
    }
    if (path != p->fC4) {
        func_L01_0045C150(a0, path, -1, 0);
    }
    func_L01_0045CED0(a0, path + (p->fC8 * 16 + 0x10));
    if (p->f38 & 0x400) {
        d = func_0038CF00(a0 + 0x10, path + (p->fC8 * 16 + 0x10));
    } else {
        d = func_0038CF00(a0 + 0x10, path + (p->fC8 * 16 + 0x10));
    }
    if (d <= 0.5f) {
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
