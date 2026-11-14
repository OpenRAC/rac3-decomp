#include "common.h"

/* NTSC-U counterpart of func_L28_003A0930 (src/levels/28_aquatos_sewers/L28_0039F2C0.c): 0.0004 -> 0.000277778; 0.02 -> 0.0166667; 0.00392 -> 0.00272222; 0.0100531 -> 0.00698132; 0.251327 -> 0.20944 */
#include "vu0.h"
extern s32 func_L28_0039E8B8(void *);

/* localdecomp:start func_L28_0039E8B8 */
typedef int u128_003A0930 __attribute__((mode(TI)));
extern f32 D_L28_001DE080;
extern f32 D_L28_001DE084;
extern u8 D_L28_001DE0B0;
__asm__(".extern D_L28_001DE080, 4");
__asm__(".extern D_L28_001DE084, 4");
__asm__(".extern D_L28_001DE0B0, 1");
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_004A6DF8(void *, s32);
extern void func_003C2868(void *);
s32 func_L28_0039E8B8(void *self) {
    u8 *a0 = self;
    f32 fa, fb;
    u8 *st = *(u8 **)(a0 + 0x68);
    *(u128_003A0930 *)(st + 0x2D0) = *(u128_003A0930 *)(a0 + 0x10);
    if (*(s16 *)(a0 + 0xB2) == 0) {
        *(s32 *)(st + 0x2F0) = -1;
        *(s32 *)(st + 0x2F8) = -1;
    }
    a0[0x23] = 0x70;
    *(u16 *)(a0 + 0x34) |= 0x2100;
    *(s32 *)(a0 + 0xB8) = 0;
    st[0x170] = 8;
    st[0x1DB] = 0xFF;
    st[0x1A8] = 1;
    st[0x1D7] = 1;
    st[0x1D8] = 0;
    st[0x1D9] = 0;
    st[0x1DA] = 0;
    fa = D_L28_001DE084 * 0.000277777785f;
    fb = D_L28_001DE080 * 0.0166666675f;
    *(s32 *)(st + 0xA8) |= 5;
    *(f32 *)(st + 0x190) = 0.5f;
    *(f32 *)(st + 0x19C) = 0.15000001f;
    *(f32 *)(st + 0x78) = 2.0f;
    *(f32 *)(st + 0x194) = 0.5f;
    *(f32 *)(st + 0x70) = 1.0f;
    *(f32 *)(st + 0x74) = 0.15000001f;
    *(f32 *)(st + 0x7C) = 2.0f;
    *(f32 *)(st + 0x80) = 12.566371f;
    *(f32 *)(st + 0xA0) = 0.34906584f;
    *(f32 *)(st + 0x9C) = 0.00272222236f;
    func_L01_00458A70(a0, fa, fb, 0.00698131742f, 0.209439531f);
    st[0x58] = 0x14;
    st[0x5A] = 0xE;
    if (*(s16 *)(st + 0x34) == 0) {
        *(s16 *)(st + 0x34) = 10;
        *(f32 *)(st + 0x30) = 10.0f;
    }
    *(f32 *)(st + 0x40) = 0.25f;
    st[0x39] = D_L28_001DE0B0;
    st[0x3E] = 1;
    st[0x3F] = 0;
    func_L01_00441FB8(a0, 3, -1);
    if (a0[0x43] != 1) func_003BE4F0(a0, 1, 0, 0);
    if (*(s32 *)(st + 0x2F0) != -1 || *(unsigned long *)(st + 0x2F8) != 0xFFFFFFFFUL) {
        func_L01_00441FB8(a0, 1, -1);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004A6DF8(a0, 1);
    }
    func_003C2868(a0);
    return 0;
}
/* localdecomp:end func_L28_0039E8B8 */
