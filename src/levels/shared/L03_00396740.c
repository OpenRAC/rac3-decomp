#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_00396740 */
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C4DA8(void *, void *, void *, void *);

void func_L03_00396740(u8 *a0) {
    u8 *m = *(u8 **)(a0 + 0x68);
    vu0_v4 d;
    if (a0[0x20] == 0) {
        *(vu0_q *)(m + 0x70) = *(vu0_q *)(a0 + 0x10);
        *(vu0_q *)(m + 0x80) = *(vu0_q *)(a0 + 0xF0);
        func_L01_004450F0(a0, 1, -1);
    }
    vec_sub_ba(&d, a0 + 0x10, m + 0x70);
    func_003C4DA8(m + 0x30, &d, m + 0x80, a0 + 0xF0);
    *(vu0_q *)(m + 0x70) = *(vu0_q *)(a0 + 0x10);
    *(vu0_q *)(m + 0x80) = *(vu0_q *)(a0 + 0xF0);
}
/* localdecomp:end func_L03_00396740 */
