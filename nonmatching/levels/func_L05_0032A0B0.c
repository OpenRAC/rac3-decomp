/* func_L05_0032A0B0: near miss (file L05_00328BF8.c). 21 differences with the file's flags: the node-row address operand order (retail adds the row offset first for the two quadword loads, the base first for the call arguments) and the schedule of the last-point store; typed indexing, offset locals and operand orders tried */
#include "common.h"
#include "vu0.h"

extern s32 *D_L05_0021ED80[];
extern u8 *D_L05_001DFC80;
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
__asm__(".extern D_L05_001DC8BC, 4");
extern f32 D_L05_001DC8BC;

void func_L05_0032A0B0(u8 *a0, u8 *a1, s32 a2, s32 a3) {
    s32 *tab;
    f32 d;
    s32 off;

    *(s32 *)(a1 + 0x168) = 0;
    qzero(a1 + 0x170);
    *(s32 *)(a1 + 0x160) = a2;
    tab = D_L05_0021ED80[a2];
    if (func_0038CF00(a0 + 0x10, tab + 4) < 0.01f) {
        *(s32 *)(a1 + 0x164) = 0;
        d = -1.0f;
        *(vu0_q *)(a1 + 0x180) = *(vu0_q *)(tab + 4);
    } else {
        *(f32 *)(a1 + 0x164) = -1.0f;
        *(vu0_q *)(a1 + 0x180) = *(vu0_q *)(a0 + 0x10);
        d = func_0038CF00(a0 + 0x10, tab + 4);
    }
    *(f32 *)(a1 + 0x18C) = d;
    off = a3 << 7;
    *(vu0_q *)(a1 + 0x190) = *(vu0_q *)(D_L05_001DFC80 + off + 0x30);
    *(f32 *)((u8 *)tab + ((tab[0] - 1) << 4) + 0x1C) = func_0038CF00(D_L05_001DFC80 + off + 0x30, (u8 *)tab + tab[0] * 16);
    func_0038CF68(a1 + 0x1A0, D_L05_001DFC80 + off, D_L05_001DC8BC);
    vec_add_ab(a1 + 0x1A0, a1 + 0x1A0, D_L05_001DFC80 + off + 0x30);
    *(f32 *)(a1 + 0x19C) = func_0038CF00(a1 + 0x1A0, D_L05_001DFC80 + off + 0x30);
    *(f32 *)(a1 + 0x1AC) = D_L05_001DC8BC;
}
