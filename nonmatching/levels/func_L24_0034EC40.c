/* func_L24_0034EC40: 6 differences (level 24, file L24_0034DAB8.c, @ps2as). Registers now match retail (the byte/half
   constants written in the order 1, 0x1E, 0x20, 100 get $v0, $v1, $a0, $a1 as retail has them); what differs is the
   scheduling: retail loads 100 first and stores +0x3E before the second qzero and +0x34 after it, this C stores +0x34
   first. All 24 orders of the four constant stores (with the qzero stores after them), and a hill climb over the whole
   group, leave 6 or more. */
#include "common.h"
#include "vu0.h"
extern void func_L01_0043A430(void *, s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
__asm__(".extern D_L24_001DD3D0, 4");
extern f32 D_L24_001DD3D0;

void func_L24_0034EC40(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    func_L01_0043A430(obj, 0, s + 0x80);
    func_L01_0043A430(obj, 1, s + 0xC0);
    s[0x3E] = 1;
    s[0x58] = 0x1E;
    s[0x5A] = 0x20;
    *(s16 *)(s + 0x34) = 100;
    qzero(s + 0x100);
    qzero(s + 0x110);
    qzero(s + 0x120);
    *(f32 *)(s + 0x30) = 100.0f;
    *(s32 *)(s + 0x144) = 0;
    *(s32 *)(s + 0x14C) = 0;
    *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * 0.1f * D_L24_001DD3D0;
    *(s32 *)(s + 0x140) = 0;
    *(s32 *)(s + 0x148) = 0;
    *(f32 *)(s + 0x150) = *(f32 *)(obj + 0x18);
    *(s16 *)(s + 0x166) = 0;
    *(s16 *)(s + 0x168) = 0;
    *(s16 *)(s + 0x16A) = 0;
    *(s32 *)(s + 0x15C) = 0;
    *(s32 *)(s + 0x160) = 0;
    *(s16 *)(s + 0x164) = 0;
    func_L01_004450F0(obj, 0, 1);
}
