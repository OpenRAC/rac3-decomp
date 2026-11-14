#include "common.h"

/* NTSC-U counterpart of func_L24_0034BA30 (src/levels/24_insomniac_museum/L24_0034A2C8.c): 0.002 -> 0.00138889; 0.0048 -> 0.00333333; 0.12 -> 0.1; 0.00698132 -> 0.00484814; 0.47473 -> 0.395608 */
extern s32 func_L24_0034ABE0(void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);

/* localdecomp:start func_L24_0034ABE0 */
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L24_0034ADF8(void *);
extern void func_L24_0034B0E8(u8 *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
__asm__(".extern D_L24_001DD3DC, 4");
__asm__(".extern D_L24_001DD3E0, 4");
extern s32 D_L24_001DD3DC;
extern s32 D_L24_001DD3E0;

s32 func_L24_0034ABE0(void *arg) {
    u8 *obj = arg;
    u8 *s = *(u8 **)(obj + 0x68);
    f32 y;

    *(s32 *)(s + 0x580) = 0;
    D_L24_001DD3DC = 0;
    y = *(f32 *)(obj + 0x18);
    D_L24_001DD3E0 = 0;
    *(f32 *)(s + 0x58C) = y;
    if (*(s16 *)(obj + 0xB2) == 0x34) {
        *(u16 *)(obj + 0x34) |= 0x8000;
    }
    s[0x1A8] = 3;
    *(f32 *)(s + 0x190) = 0.5f;
    s[0x170] = 0xE;
    s[0x176] = 3;
    *(f32 *)(s + 0x194) = 0.5f;
    *(f32 *)(s + 0x19C) = 0.15f;
    s[0x1D7] = 1;
    if (*(s16 *)(s + 0x34) == 0) {
        *(s16 *)(s + 0x34) = 100;
        *(f32 *)(s + 0x30) = 100.0f;
    }
    *(f32 *)(s + 0x40) = 2.0f;
    *(f32 *)(s + 0x80) = 0.9599311f;
    *(f32 *)(s + 0xA0) = 1.4835298f;
    *(f32 *)(s + 0x9C) = 0.00138888892f;
    *(f32 *)(s + 0xA4) = 1.5f;
    *(f32 *)(s + 0x74) = 4.5f;
    *(f32 *)(s + 0x70) = 6.0f;
    func_L01_00458A70(obj, 0.00333333341f, 0.100000009f, 0.00484813703f, 0.395607978f);
    *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * 0.75f;
    *(s32 *)(s + 0x584) = 0;
    func_L24_0034ADF8(obj);
    func_L24_0034B0E8(obj);
    func_L01_00441FB8(obj, 1, 0);
    if (obj[0x43] != 0) {
        func_003BE4F0(obj, 0, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L24_0034ABE0 */
