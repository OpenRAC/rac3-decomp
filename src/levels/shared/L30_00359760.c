#include "common.h"

/* localdecomp:start func_L30_00359760 */
typedef struct {
    u8 pad[0x10BE4];
    u16 done;
} Big_00358658;
typedef struct {
    u8 pad[64];
    s32 a;
    s32 b;
} Vars_00358658;
typedef struct {
    u8 pad[104];
    Vars_00358658 *vars;
} Moby_00358658;
extern u8 D_001A4C60[];
extern Big_00358658 D_001A7E18;
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_0041A5B0(s32, s32);
extern void func_L01_0041BE28(s32, s32);
void func_L30_00359760(Moby_00358658 *m) {
    Vars_00358658 *v = m->vars;
    func_00382380(D_001A4C60, v->a, 0);
    if (func_00382380(D_001A4C60, v->b, 0) == 0) return;
    if (D_001A7E18.done != 0) return;
    if (func_L01_0041A5B0(5715, 315) == 0) func_L01_0041BE28(5715, 315);
    if (D_001A7E18.done == 0) D_001A7E18.done = 1;
}
/* localdecomp:end func_L30_00359760 */

INCLUDE_ASM("asm/levels", func_L30_00359808);
