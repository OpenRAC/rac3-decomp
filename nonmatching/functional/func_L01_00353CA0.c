/* functional: high. Compiles in context, not exact (stack frame size and scheduling only; retail also spills the source quad to sp+0x10, dead). 10-argument call to func_L01_00409598 with the two literals 0x80FF40 and 0x108F10 on the stack, as retail. */
#include "vu0.h"
extern void func_L01_00409598(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00446278(void *, s32, s32, f32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_00382498(s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
void func_L01_00353CA0(u8 *obj, vu0_q *src) {
    vu0_q q __attribute__((aligned(16)));
    u8 *p24;
    u16 h;
    s32 r;
    q = *src;
    *(vu0_q *)(obj + 0x10) = q;
    h = *(u16 *)(obj + 0x34) & 0xFFBC;
    *(u16 *)(obj + 0x34) = h;
    p24 = *(u8 **)(obj + 0x24);
    h |= *(u16 *)(p24 + 0x44) & 0x1000;
    *(u16 *)(obj + 0x34) = h;
    *(s32 *)(obj + 0x98) = *(s32 *)(p24 + 0x10);
    if (obj[0x43] != 0) {
        r = func_00382498(0, 10);
        func_003C3A10(obj, 0, r, 0);
    }
    *(f32 *)(obj + 0x18) = func_003C3D30(obj + 0x10, 0, 0, 0.5f);
    if (obj[0x95] == 9) func_L01_004450F0(obj, 0x18, -1);
    else func_L01_004450F0(obj, 2, 1);
    obj[0x31] = 0;
    *(u16 *)(obj + 0x34) |= 1;
    func_L01_00409598(obj, obj + 0x10, obj + 0xF0, 0, 2, 3, 0x25, 0x25, 0x80FF40, 0x108F10);
}
