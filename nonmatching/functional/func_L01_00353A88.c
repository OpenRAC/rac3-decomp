/* functional: high. Compiles in context, not exact (quad scheduling/registers only). Variant of func_L01_00353970 with arg ignored, state+0x348 = 0 and a random offset: 0.0 plus 0.03 into func_L01_00443A18 added to D_L01_001DD4BC. gp floats 4B8/4BC/4C8 checked. */
#include "vu0.h"
__asm__(".extern D_L01_001DD4B8, 4");
extern f32 D_L01_001DD4B8;
__asm__(".extern D_L01_001DD4BC, 4");
extern f32 D_L01_001DD4BC;
__asm__(".extern D_L01_001DD4C8, 4");
extern f32 D_L01_001DD4C8;
extern void func_0038D308(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C3938(void *, s32, s32);
void func_L01_00353A88(u8 *obj, vu0_q *src, s32 unused, f32 f) {
    vu0_q q __attribute__((aligned(16)));
    u8 *v;
    u8 *p24;
    f32 k;
    f32 r;
    u16 h;
    q = 0;
    *(f32 *)((u8 *)&q + 8) = f;
    v = *(u8 **)(obj + 0x68);
    *(vu0_q *)(obj + 0x10) = *src;
    *(vu0_q *)(obj + 0xF0) = q;
    func_0038D308(obj + 0xC0, &q);
    h = *(u16 *)(obj + 0x34) & 0xFFBE;
    k = D_L01_001DD4C8;
    p24 = *(u8 **)(obj + 0x24);
    *(u16 *)(obj + 0x34) = h;
    h |= *(u16 *)(p24 + 0x44) & 0x1000;
    *(u16 *)(obj + 0x34) = h;
    *(s32 *)(obj + 0x98) = *(s32 *)(p24 + 0x10);
    *(f32 *)(v + 0x34C) = k;
    *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * k * *(f32 *)(v + 0x5D4);
    *(s32 *)(v + 0x348) = 0;
    func_0038CE20(v + 0x110, obj + 0xC0, D_L01_001DD4B8);
    r = func_L01_00443A18(0.0f, 0.03f);
    *(f32 *)(v + 0x100) = 0.0f;
    *(s32 *)(v + 0xF8) = 0;
    *(s32 *)(v + 0xFC) = 0;
    *(vu0_q *)(v + 0xC0) = 0;
    *(s32 *)(v + 0x148) = -1;
    *(f32 *)(v + 0x118) = D_L01_001DD4BC + r;
    func_L01_004450F0(obj, 0x13, 6);
    func_003C3938(obj, 9, 0);
}
