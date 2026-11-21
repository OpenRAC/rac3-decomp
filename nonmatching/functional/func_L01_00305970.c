/* functional: high. Same calls, reads and writes as retail; the stack copy of the 8-byte table is two s32 moves. */
#include "common.h"
#include "vu0.h"

extern u8 D_001425D1;
extern u8 D_L01_002C5600[];
extern s32 D_L01_001DC5D0[2];
__asm__(".extern D_L01_001DC5D0, 8");
extern s32 D_L01_001DC5DC;
__asm__(".extern D_L01_001DC5DC, 4");
extern void func_L01_00472F58(void *, void *, s32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);

void func_L01_00305970(u8 *obj, u8 *p, vu0_v4 *q) {
    vu0_v4 v;
    s32 tbl[2];
    u8 *st;
    f32 r;

    st = *(u8 **)(obj + 0x68);
    v = *q;
    func_0038CF68(&v, &v, 0.05f);
    tbl[0] = D_L01_001DC5D0[0];
    tbl[1] = D_L01_001DC5D0[1];
    if (D_L01_002C5600[D_001425D1 * 240 + 1] < 4) {
        r = func_003824E0(0.05f, 0.1f);
        func_L01_00472F58(p, &v, 0x48, r * *(f32 *)(st + 0x50) * 0.1f);
    } else {
        r = func_003824E0(0.05f, 0.1f);
        func_L01_00472F58(p, &v, tbl[D_L01_001DC5DC % 2], r * *(f32 *)(st + 0x50) * 0.1f);
    }
    D_L01_001DC5DC = D_L01_001DC5DC + 1;
}
