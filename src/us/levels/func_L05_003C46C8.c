#include "common.h"

/* NTSC-U counterpart of the PAL function at the same position (L05 shared, @ps2as) */
/* localdecomp:start func_L05_003C46C8 */
extern void func_00388398(void *);
extern s32 func_003883C8(void *);
extern void func_L01_0044EB78(void *, void *, s32, s32, f32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
extern u8 D_L05_001E2780[];

void func_L05_003C46C8(u8 *obj) {
    u8 *sub = *(u8 **)(obj + 0x68);
    u16 t;
    f32 r;

    func_00388398(sub + 0x2F0);
    func_003883C8(sub + 0x2F4);
    t = *(u16 *)(obj + 0x96);
    if (t <= 0xFFFE) {
        *(u16 *)(obj + 0x96) = t + 1;
    }
    func_L01_0044EB78(obj, sub + 0x260, 4, 1, 2.5f);
    if (obj[0x31] != 0) {
        if (func_L01_0040C018(D_L05_001E2780, obj + 0x10) < 1024.0f) {
            func_L01_00444188(obj);
            obj[0x6F] = 0x1E;
        }
    }
    r = func_00389380(*(f32 *)(sub + 0x42C), 3.4906585f * 0.016666668f);
    *(f32 *)(sub + 0x42C) = r;
    *(s32 *)(obj + 0x78) = func_003894A0(0x80A0A0A0, 0x60101010, (func_00388978(r) + 1.0f) * 0.5f);
    func_L01_0044B5C8(obj, sub + 0x300, 0, 0.03f, 0.3f);
    func_L01_0044B5C8(obj, sub + 0x380, 1, 0.03f, 0.3f);
}
/* localdecomp:end func_L05_003C46C8 */
