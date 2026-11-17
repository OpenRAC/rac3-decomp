#include "common.h"

/* NTSC-U counterpart of func_L07_003B5CC8 (src/levels/07_annihilation_nation/L07_003AF398.c) */
#include "structs/moby.h"
#include "vu0.h"
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern s32 func_L01_0044B550(void *);

/* localdecomp:start func_L07_003B43D8 */
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern s32 func_L01_0044B550(void *);
extern void func_L07_003B4A30(u8 *);
extern void func_L07_003B49D8(u8 *);

void func_L07_003B43D8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u16 t;

    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    *(f32 *)(p + 0x40) = 1.0f;
    p[0x3E] = 3;
    *(u16 *)(p + 0x32C) = *(u16 *)(p + 0x34);
    p[0x3F] = 0;
    p[0x64] = 0;
    t = *(u16 *)(a0 + 0xB6);
    p[0x39] = 0;
    *(f32 *)(p + 0xA0) = 3.0f;
    *(f32 *)(p + 0xA4) = 1.2f;
    *(f32 *)(p + 0xA8) = 1.2f;
    *(f32 *)(p + 0xAC) = 1.2f;
    *(f32 *)(p + 0xB0) = 3.1415927f;
    *(f32 *)(p + 0xD0) = 0.7853982f;
    *(f32 *)(p + 0xCC) = 0.0027222223579883575f;
    *(f32 *)(p + 0xD4) = 0.2f;
    *(u16 *)(p + 0x32E) = t;
    func_L01_00458A70(a0, 0.05000000074505806f, 0.3333333432674408f, 0.0008726646774448454f, 0.05235988274216652f);
    *(void **)(p + 0x194) = func_L07_003B4A30;
    *(void **)(p + 0x198) = func_L07_003B49D8;
    *(u8 *)(p + 0x1AD) = 0xFF;
    *(s16 *)(p + 0x19C) = -1;
    *(s32 *)(p + 0x33C) = func_L01_0044B550(a0);
    func_L07_003B49D8(a0);
}
/* localdecomp:end func_L07_003B43D8 */
