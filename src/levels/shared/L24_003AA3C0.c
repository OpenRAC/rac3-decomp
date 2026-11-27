#include "common.h"

/* localdecomp:start func_L24_003AA3C0 */
extern u8 *func_003C24B0(s32, s32);
extern s32 func_L01_00445F40(void *, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_0038D308(void *, void *);
extern void func_003C7DD8(void *);
extern void func_003C29B0(u8 *);
extern void func_003C6FE0(u8 *);

u8 *func_L24_003AA3C0(u8 *a0) {
    u8 *o;
    u16 h;
    o = func_003C24B0(0x1A94, 0x80);
    if (o == 0) {
        return 0;
    }
    func_L01_00445F40(o, *(s16 *)(a0 + 0xAA));
    func_L01_00456160(o, a0);
    func_0038D308(o + 0xC0, o + 0xF0);
    *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * (*(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24));
    func_003C7DD8(o);
    h = *(u16 *)(o + 0x34);
    *(s32 *)(o + 0x98) = 0;
    h |= 0x100;
    h &= 0xFFDE;
    *(u16 *)(o + 0x34) = h;
    o[0x42] = o[0x43] = a0[0x43];
    o[0x40] = a0[0x40];
    o[0x41] = a0[0x41];
    func_003C29B0(o);
    *(s32 *)(o + 0x48) = 0;
    *(s32 *)(o + 0x44) = 0;
    func_003C6FE0(o);
    *(s32 *)(*(u8 **)(o + 0x68) + 0x44) = 0;
    return o;
}
/* localdecomp:end func_L24_003AA3C0 */
