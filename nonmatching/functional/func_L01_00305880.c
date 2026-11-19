/* functional: high. Same calls and reads as retail; the 8-byte table copy to the stack is done with two s32 loads/stores. */
#include "common.h"
#include "vu0.h"

extern u8 D_001425D1;
extern u8 D_L01_002C5600[];
extern s32 D_L01_001DC5D0[2];
__asm__(".extern D_L01_001DC5D0, 8");
extern s32 D_L01_001DC5D8;
__asm__(".extern D_L01_001DC5D8, 4");
extern void func_L01_00472F58(void *, void *, s32, f32);

void func_L01_00305880(u8 *obj, u8 *p) {
    vu0_v4 zero;
    s32 tbl[2];
    u8 *st;
    s32 n;

    st = *(u8 **)(obj + 0x68);
    qzero(&zero);
    tbl[0] = D_L01_001DC5D0[0];
    tbl[1] = D_L01_001DC5D0[1];
    if (D_L01_002C5600[D_001425D1 * 240 + 1] < 4) {
        func_L01_00472F58(p, &zero, 0x48, *(f32 *)(st + 0x50) * 0.25f * 0.1f);
    } else {
        func_L01_00472F58(p, &zero, tbl[D_L01_001DC5D8 % 2], *(f32 *)(st + 0x50) * 0.25f * 0.1f);
    }
    D_L01_001DC5D8 = D_L01_001DC5D8 + 1;
}
