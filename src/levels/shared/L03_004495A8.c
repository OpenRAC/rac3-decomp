#include "common.h"

/* localdecomp:start func_L03_004495A8 */
extern int D_L03_0021D8C0[];
extern void func_L03_004495E8(int, int);

void func_L03_004495A8(int a0, int a1) {
    int p;
    if (a1 != -1) {
        p = D_L03_0021D8C0[a1];
        if (p != 0)
            func_L03_004495E8(a0, p);
    }
}
/* localdecomp:end func_L03_004495A8 */

INCLUDE_ASM("asm/levels", func_L03_004495E8);

/* localdecomp:start func_L03_004497E8 */
extern s32 D_L03_0021D8C0[];
extern void func_L03_00449838(s32 a0, s32 a1, s16 a2, s16 a3);
void func_L03_004497E8(s32 a0, s32 a1, s16 a2, s16 a3) {
    if (a1 != -1) {
        s32 x = D_L03_0021D8C0[a1];
        if (x) {
            func_L03_00449838(a0, x, a2, a3);
        }
    }
}
/* localdecomp:end func_L03_004497E8 */

/* localdecomp:start func_L03_00449838 */
extern void *func_L01_0045B958(void *);
extern s32 func_L03_004640A8(void *, void *, f32);
typedef struct { u8 pad[0x9C]; s32 w9C; u8 padA0[0x24]; s32 wC4; s16 hC8; s16 hCA; } S_449838;

void func_L03_00449838(s32 a0, s32 a1, s16 a2, s16 a3) {
    S_449838 *m = func_L01_0045B958((void *)a0);
    m->w9C |= 4;
    m->wC4 = a1;
    m->hCA = a2;
    if (a3 == -1) {
        m->hC8 = func_L03_004640A8((u8 *)a0 + 0x10, (void *)a1, 0.0f);
    } else {
        m->hC8 = a3;
    }
}
/* localdecomp:end func_L03_00449838 */
