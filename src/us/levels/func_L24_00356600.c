#include "common.h"

/* NTSC-U counterpart of func_L24_00357638 (src/levels/24_insomniac_museum/L24_00356100.c): 0.00392 -> 0.00272222; 0.004 -> 0.00277778; 0.16 -> 0.133333; 0.0100531 -> 0.00698132; 0.251327 -> 0.20944 */
#include "vu0.h"

/* localdecomp:start func_L24_00356600 */
#include "vu0.h"
extern s32 D_L24_001E0FF0_00356600;
extern s32 D_L24_001E0FF4_00356600;
extern s32 D_L24_001E0FF8_00356600;
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L24_003565C8(u8 *);

s32 func_L24_00356600(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);

    *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * 0.9f;
    D_L24_001E0FF0_00356600 = 0;
    D_L24_001E0FF4_00356600 = 0;
    D_L24_001E0FF8_00356600 = 0;
    *(vu0_q *)(s + 0x8A0) = *(vu0_q *)(obj + 0x10);
    *(u8 *)(s + 0x170) = 9;
    *(u8 *)(s + 0x1A8) = 3;
    *(f32 *)(s + 0x1BC) = 0.5f;
    *(f32 *)(s + 0x74) = 0.5f;
    *(f32 *)(s + 0x1B8) = 0.01f;
    *(u8 *)(s + 0x171) = 8;
    *(u8 *)(s + 0x176) = 9;
    *(s32 *)(s + 0x20C) = 0;
    *(f32 *)(s + 0x70) = 0.7f;
    *(f32 *)(s + 0x78) = 0.5f;
    *(f32 *)(s + 0x7C) = 1.0f;
    *(f32 *)(s + 0x80) = 0.7853982f;
    *(f32 *)(s + 0xA0) = 0.34906584f;
    *(f32 *)(s + 0x9C) = 0.00272222236f;
    func_L01_00458A70(obj, 0.00277777785f, 0.13333334f, 0.00698131742f, 0.209439531f);
    if (*(s16 *)(s + 0x34) == 0) {
        *(s16 *)(s + 0x34) = 100;
        *(f32 *)(s + 0x30) = 100.0f;
    }
    *(u8 *)(s + 0x39) = 0;
    *(f32 *)(s + 0x40) = 2.0f;
    func_L24_003565C8(obj);
    *(s32 *)(s + 0x8E4) = -1;
    func_L01_00441FB8(obj, 1, 0);
    if (*(u8 *)(obj + 0x43) != 0) {
        func_003BE4F0(obj, 0, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L24_00356600 */
