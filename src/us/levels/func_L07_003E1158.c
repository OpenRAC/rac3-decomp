#include "common.h"

/* NTSC-U-only function (flags of its neighbours: @ps2as) */
/* localdecomp:start func_L07_003E1158 */
typedef struct {
    u8 pad_00[0x80];
    f32 f80;
    f32 f84;
    f32 f88;
} Core_3E1158;

extern Core_3E1158 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
extern void func_L01_00457590(f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern f32 func_00388A28(f32, f32);
extern void func_L01_00445758(void *, void *, s32, f32, f32, f32, f32);
extern f32 func_00388800(void *, void *);

void func_L07_003E1158(u8 *obj) {
    u8 *sub = *(u8 **)(obj + 0x68);
    u8 *ang = obj + 0xF8;
    f32 r;

    *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) - *(f32 *)(sub + 0x274);
    func_L01_00457590(*(f32 *)(obj + 0xF8));
    r = func_00389380(*(f32 *)(sub + 0x270), *(f32 *)(sub + 0x278));
    *(f32 *)(sub + 0x270) = r;
    *(f32 *)(sub + 0x274) = func_00388978(r) * *(f32 *)(sub + 0x27C);
    *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) + *(f32 *)(sub + 0x274);
    r = func_00388A28(D_001A4BE0.f80 - *(f32 *)(obj + 0x10), D_001A4BE0.f84 - *(f32 *)(obj + 0x14));
    func_L01_00445758(ang, sub + 0xE4, 0, r, 3.1415927f / 1800.0f, 3.1415927f / 1800.0f, 3.1415927f * 0.033333335f);
    r = func_00388800(obj + 0x10, &D_001A4BE0.f80);
    *(f32 *)(sub + 0x184) = -func_00388A28(r, D_001A4BE0.f88 - *(f32 *)(obj + 0x18));
}
/* localdecomp:end func_L07_003E1158 */
