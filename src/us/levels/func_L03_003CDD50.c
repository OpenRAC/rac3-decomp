#include "common.h"

/* NTSC-U counterpart of func_L03_003CFD80 (src/levels/shared/L03_003CFCA0.c) */
#include "vu0.h"

/* localdecomp:start func_L03_003CDD50 */
extern void func_0039FB08(s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_0037E1D8(s32);
extern void func_00388830(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern void func_L01_00460318(void *, void *, u32, u32, s32, s32, s32, s32);
extern u8 D_001A30B0[];

void func_L03_003CDD50(u8 *a0) {
    vu0_v4 vel;
    vu0_v4 pos;
    vu0_v4 off;
    s32 *pv = *(s32 **)(a0 + 0x68);
    s32 r;
    u8 *e;
    if (a0[0x20] != 0) {
        return;
    }
    (*(u16 *)(a0 + 0x96))++;
    if (*(u16 *)(a0 + 0x96) >= 0x12D) {
        if (*pv != -1) {
            e = D_001A30B0 + (*pv << 7);
            if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
                func_0039FB08(*pv);
            }
        }
        *pv = -1;
        func_L01_00441FB8(a0, 1, -1);
        return;
    }
    if (*pv == -1 || (e = D_001A30B0 + (*pv << 7), *(u8 **)(e + 0xDC) != a0) || e[0xD0] == 0) {
        *pv = func_0039FE80(0, 4, a0);
    }
    r = func_0037E1D8(30);
    *(vu0_q *)&pos = *(vu0_q *)(a0 + 0x10);
    func_00388830(&off, a0 + 0xC0, -0.3f);
    vec_add_ab(&pos, &pos, &off);
    pos.z += 0.9f;
    qzero(&vel);
    func_00388830(&vel, a0 + 0xC0, -0.025000002f);
    func_003BF6A8(&vel, 0.011666667f);
    vel.z += 0.033333335f;
    func_L01_00460318(&pos, &vel, 0x80808080, 0x202020, 0x32, r + 0x1E, r + 0x5A, 1);
}
/* localdecomp:end func_L03_003CDD50 */
