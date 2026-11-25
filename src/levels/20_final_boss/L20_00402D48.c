#include "common.h"

/* localdecomp:start func_L20_00402D48 */
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00480098(void *);
extern void func_L20_00402AD0(u8 *a0, u8 *a1);

void func_L20_00402D48(u8 *arg0) {
    u8 *m = *(u8 **)(arg0 + 0x68);
    s32 done;

    switch (arg0[0x20]) {
    case 1:
        if (*(u16 *)(arg0 + 0x96) == 0) {
            func_L01_004450F0(arg0, 2, -1);
        } else {
            *(u16 *)(arg0 + 0x96) -= 1;
        }
        break;
    case 2:
        done = 0;
        *(u16 *)(arg0 + 0x96) += 1;
        if (*(u16 *)(arg0 + 0x96) < 120) {
            func_L20_00402AD0(arg0, m);
            *(f32 *)(m + 0x1C) += *(f32 *)(m + 0x20);
            if (*(f32 *)(m + 0x24) <= *(f32 *)(m + 0x1C)) {
                done = 1;
            }
        } else {
            done = 1;
        }
        if (done) {
            func_L01_004450F0(arg0, 3, -1);
        }
        break;
    case 3:
        func_L01_00480098(arg0);
        break;
    }
}
/* localdecomp:end func_L20_00402D48 */
