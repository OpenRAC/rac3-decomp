#include "common.h"

/* localdecomp:start func_L35_003A2C40 */
extern u8 D_001A4BE0[];
extern f32 D_L35_001DE9CC;
extern s32 D_L35_001DE9E0;
extern s32 D_L35_001DE9C8;
extern s32 D_L35_001DE9E4;
extern void func_L35_003A29A8(u8 *, u8 *, s32, s32, f32, f32);
extern void func_0038CE20(s32, s32, f32);
__asm__(".extern D_L35_001DE9E0, 4");
__asm__(".extern D_L35_001DE9C8, 4");
__asm__(".extern D_L35_001DE9E4, 4");

void func_L35_003A2C40(u8 *a0, u8 *a1) {
    u8 *s1 = D_001A4BE0;
    u8 *s8 = *(u8 **)(s1 + 0x25C0);
    u8 *s6 = *(u8 **)(a1 + 0x20);
    f32 f20 = D_L35_001DE9CC;
    f32 tmp[4];

    if (*(s16 *)(s6 + 0xAA) != *(s16 *)(s8 + 0xAA)) {
        f20 = f20 * 0.3f;
    }
    func_L35_003A29A8(a0 + 0x10, s8 + ((D_L35_001DE9E0 << 4) + 0xC0), D_L35_001DE9C8, D_L35_001DE9E4, f20, 1.0f);
    func_0038CE20((s32)tmp, (s32)(*(u8 **)(s1 + 0x25C0) + ((D_L35_001DE9E0 << 4) + 0xC0)), -1.0f);
    func_L35_003A29A8(a0 + 0x10, (u8 *)tmp, (s32)((f32)D_L35_001DE9C8 * 0.5f), D_L35_001DE9E4, f20 * 0.5f, 0.6f);
}
/* localdecomp:end func_L35_003A2C40 */
