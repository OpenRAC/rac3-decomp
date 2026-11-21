/* functional: high. Same calls with the same arguments in the same order; only scheduling/regalloc may differ. */
#include "common.h"

extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
extern void func_003A9440(s32, unsigned long);
extern void func_L01_00305F00(u8 *, s32, s32, f32);
extern void func_L01_00305D30(f32, u8 *, u8 *, s32);
extern void func_L01_00306A98(u8 *);

void func_L01_00305AB8(u8 *obj) {
    u8 *st;
    u8 *pos;

    st = *(u8 **)(obj + 0x68);
    func_003A9440(0x47, 0x53001);
    if (D_L01_002C5600[D_001425C0[0x11] * 240 + 1] >= 4) {
        func_L01_00305F00(obj, 0x7F7F7F7F, 0x4B, 0.1f);
    } else {
        func_L01_00305F00(obj, 0x7F7F7F7F, 0x4B, 0.05f);
    }
    if (*(f32 *)(st + 0x50) != 0.0f) {
        pos = st + 0x10;
        if (D_L01_002C5600[D_001425C0[0x11] * 240 + 1] >= 4) {
            func_L01_00305D30(0.25f, obj, pos, 0x7F7F3010);
            func_L01_00305D30(0.5f, obj, pos, 0x3F3F1808);
        } else {
            func_L01_00305D30(0.25f, obj, pos, 0x7F10307F);
            func_L01_00305D30(0.5f, obj, pos, 0x3F08183F);
        }
    }
    func_L01_00306A98(obj);
    func_003A9440(0x47, 0x5360B);
}
