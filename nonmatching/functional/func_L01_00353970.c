/* functional: high. Compiles in context, not exact (quad zero/copy scheduling and register order only). All offsets, gp floats (D_L01_001DD4B0/4B4/4C0) and callees re-read against retail. Stores before calls kept in retail order. */
#include "vu0.h"
__asm__(".extern D_L01_001DD4B0, 4");
extern f32 D_L01_001DD4B0;
__asm__(".extern D_L01_001DD4B4, 4");
extern f32 D_L01_001DD4B4;
__asm__(".extern D_L01_001DD4C0, 4");
extern f32 D_L01_001DD4C0;
extern void func_0038D308(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C3938(void *, s32, s32);
void func_L01_00353970(u8 *obj, vu0_q *src, s32 arg, f32 f) {
    vu0_q q __attribute__((aligned(16)));
    u8 *v;
    u8 *p24;
    f32 k;
    u16 h;
    q = 0;
    *(f32 *)((u8 *)&q + 8) = f;
    v = *(u8 **)(obj + 0x68);
    *(vu0_q *)(obj + 0x10) = *src;
    *(vu0_q *)(obj + 0xF0) = q;
    func_0038D308(obj + 0xC0, &q);
    k = D_L01_001DD4C0;
    h = *(u16 *)(obj + 0x34) & 0xFFBE;
    *(u16 *)(obj + 0x34) = h;
    p24 = *(u8 **)(obj + 0x24);
    h |= *(u16 *)(p24 + 0x44) & 0x1000;
    *(u16 *)(obj + 0x34) = h;
    *(s32 *)(obj + 0x98) = *(s32 *)(p24 + 0x10);
    *(f32 *)(v + 0x34C) = k;
    *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * k * *(f32 *)(v + 0x5D4);
    *(s32 *)(v + 0x348) = arg;
    func_0038CE20(v + 0x110, obj + 0xC0, D_L01_001DD4B0);
    *(s32 *)(v + 0x100) = 0;
    *(s32 *)(v + 0xF8) = 0;
    *(vu0_q *)(v + 0xC0) = 0;
    *(s32 *)(v + 0xFC) = 0;
    *(f32 *)(v + 0x118) = D_L01_001DD4B4;
    *(s32 *)(v + 0x148) = -1;
    func_L01_004450F0(obj, 0x13, 6);
    func_003C3938(obj, 9, 0);
}
