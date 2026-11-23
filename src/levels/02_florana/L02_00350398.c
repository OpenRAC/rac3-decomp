#include "common.h"

/* localdecomp:start func_L02_00350398 */
s32 func_00382468(s32);
void func_003C3A10(void *, s32, s32, s32);

void func_L02_00350398(void *arg0) {
    s32 temp_s0_2;
    s32 temp_s1;
    u8 temp_s0;
    u8 temp_s0_3;

    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        temp_s0 = *(u8 *)((u8 *)arg0 + 0x43);
        if (temp_s0 != func_00382468(4)) {
            temp_s1 = func_00382468(4);
            temp_s0_2 = func_00382468(2);
            func_003C3A10(arg0, temp_s1, temp_s0_2, func_00382468(0xA));
        }
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 1) {
        if ((*(u8 *)((u8 *)arg0 + 0x60)) & 2) {
            temp_s0_3 = *(u8 *)((u8 *)arg0 + 0x43);
            if (temp_s0_3 != func_00382468(4)) {
                func_003C3A10(arg0, func_00382468(4), 0, 0x11);
            }
        }
    }
}
/* localdecomp:end func_L02_00350398 */

INCLUDE_ASM("asm/levels", func_L02_00350478);

/* localdecomp:start func_L02_00351208 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_351208;
extern s32 D_001DE4C0_sda;
__asm__(".extern D_001DE4C0_sda, 4");
extern s32 D_L02_001DE4C0;
__asm__(".extern D_L02_001DE4C0, 16");
extern s32 func_L02_003514D0(u8 *);
extern void func_L02_003516A8(s32);
extern void func_L02_00351780(u8 *);
extern f32 func_003C3D30(void *, s32, void *, f32);
extern void func_L01_0046A938(void *, s32, s32, f32, f32);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_003C4A40(void *, void *);
extern void func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L02_00351208(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *q;
    f32 f20;
    if (a0[0x20] == 0) {
        if (func_L02_003514D0(a0) != 0) return 1;
    }
    if (p[0x3E] == 2) {
        func_L02_003516A8((s32)a0);
        return 1;
    }
    if ((D_001DE4C0_sda & 3) == (((s32)a0 >> 8) & 3)) {
        V4_351208 vec;
        f32 r = func_003C3D30(a0 + 0x10, 0, a0, 2.0f);
        vec = *(V4_351208 *)(a0 + 0x10);
        vec.z = r + 0.2f;
        func_L01_0046A938(&vec, 0, -1, 4.0f, 21000.0f);
    }
    q = p + 0x160;
    f20 = *(f32 *)(p + 0x30);
    if (func_L01_00452FB0(a0, q, 0, 0, 0) != 0) {
        p[0x167] = 0xFF;
        func_003C4A40(a0, q);
        func_L02_00351780(a0);
    }
    if (*(f32 *)(p + 0x30) < f20) {
        p[0x167] = 0xFF;
        func_003C4A40(a0, q);
    }
    func_L01_00452860(a0, p + 0x30, 0);
    if ((*(s16 *)(a0 + 0xB2) + 8) % 8 == D_L02_001DE4C0 % 8) {
        if (p[0x5F] != 0) {
            func_L01_00456BD0(a0, 5);
            if (a0[0x95] == 0) {
                func_L01_00456C98(a0, *(s32 *)(p + 0x2C0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2C4), 10.0f, 1.0f);
            } else {
                func_L01_00456C98(a0, *(s32 *)(p + 0x2C8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2CC), 10.0f, 1.0f);
            }
        } else {
            func_L01_00456BD0(a0, 3);
            if (a0[0x95] == 0) {
                func_L01_00456C98(a0, *(s32 *)(p + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2C4), 10.0f, 1.0f);
            } else {
                func_L01_00456C98(a0, *(s32 *)(p + 0x2C8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2CC), 10.0f, 1.0f);
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L02_00351208 */

/* localdecomp:start func_L02_003514D0 */
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

s32 func_L02_003514D0(u8 *a0)
{
    u8 *p;
    f32 zero = 0.0f;

    *(f32 *)(a0 + 0x18) = *(f32 *)(a0 + 0x18) - zero;
    *(u32 *)(a0 + 0x98) = 0;
    *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
    p = *(u8 **)(a0 + 0x68);
    func_L01_004AA7E8(a0, 1);
    *(f32 *)(p + 0x190) = 0.5f;
    p[0x1A8] = 3;
    p[0x170] = 0xB;
    *(f32 *)(p + 0x194) = 0.5f;
    p[0x1D8] = 1;
    p[0x1D9] = 1;
    p[0x171] = 3;
    *(f32 *)(p + 0x19C) = 0.15f;
    p[0x1DB] = 0x1C;
    p[0x1DA] = 0;
    p[0x176] = 0x10;
    *(f32 *)(p + 0x70) = 0.7f;
    *(f32 *)(p + 0x74) = 3.0f;
    *(f32 *)(p + 0x9C) = zero;
    *(f32 *)(p + 0x78) = 1.0f;
    *(f32 *)(p + 0x7C) = 1.0f;
    *(f32 *)(p + 0x80) = 1.5707964f;
    *(f32 *)(p + 0xA0) = 0.34906584f;
    p[0x172] = 3;
    func_L01_0045BD78(a0, 0.0024f, 0.040000003f, 0.0025132743f, 0.041887905f);
    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    if (*(s16 *)(p + 0x34) == 0) {
        *(s16 *)(p + 0x34) = 5;
        *(f32 *)(p + 0x30) = 5.0f;
    }
    p[0x39] = 1;
    *(f32 *)(p + 0x40) = 2.0f;
    p[0x3F] = 0;
    *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * 1.5f;
    p[0x3E] = 1;
    func_L01_004450F0(a0, 1, 0);
    if (a0[0x43] != 0xE) {
        func_003C3A10(a0, 0xE, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L02_003514D0 */
