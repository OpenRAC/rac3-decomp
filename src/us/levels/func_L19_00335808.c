#include "common.h"

/* NTSC-U counterpart of func_L19_003361E0 (src/levels/shared/L19_003361E0.c) */
/* localdecomp:start func_L19_00335808 */
typedef int u128_003361E0 __attribute__((mode(TI)));

extern s32 D_L19_001DCD60;
__asm__(".extern D_L19_001DCD60, 4");

void func_L19_00335808(u8 *obj)
{
    u8 *p = *(u8 **)(obj + 0x68);

    *(s32 *)(p + 0x94) = 0;
    if (*(s32 *)(p + 0x9C) < 0) {
        *(s32 *)(p + 0x9C) = 0xE;
    }
    if (*(s32 *)(p + 0x80) < 0) {
        *(s32 *)(p + 0x80) = 0x10;
    }
    *(s32 *)(p + 0xA8) = 0;
    *(s32 *)(p + 0xBC) = 0x80402080;
    *(s32 *)(p + 0xC0) = 0x80004880;
    *(f32 *)(p + 0xA4) = 1.0f;
    *(f32 *)(p + 0xA0) = 0.25f;
    *(s32 *)(p + 0x60) = 0x807F0000;
    *(s32 *)(p + 0x64) = 0x8000007F;
    *(s32 *)(p + 0x68) = 0x807F0000;
    *(s32 *)(p + 0x6C) = 0x8000007F;
    *(u128_003361E0 *)(p + 0xE0) = *(u128_003361E0 *)(obj + 0x10);
    *(s32 *)(p + 0xD8) = -1;
    *(s32 *)(p + 0xDC) = *(s32 *)(p + 0xDC) << 3;
    *(f32 *)(p + 0xE8) = *(f32 *)(p + 0xE8) + 1.1f;
    D_L19_001DCD60 = 0;
}
/* localdecomp:end func_L19_00335808 */
