#include "common.h"

/* NTSC-U counterpart of func_L23_003A7908 (src/levels/23_holostar_studios_clank/L23_003A6688.c) */
typedef int u128_t __attribute__((mode(TI)));
#include "vu0.h"
extern f32 func_00388770(void *);
#include "vu0.h"
extern f32 func_00388770(void *);

/* localdecomp:start func_L23_003A6150 */
#include "vu0.h"
extern s16 D_L23_002362B0[];
extern s32 D_L23_001DE160;
__asm__(".extern D_L23_001DE160, 4");
extern s32 D_L23_001DE164;
__asm__(".extern D_L23_001DE164, 4");
extern s32 D_L23_001DE168;
__asm__(".extern D_L23_001DE168, 4");
extern u8 *func_003BCFB0(s32, s32);
extern void func_L01_00452E70(void *, void *);
extern void func_L01_0044B598(void *, s32);
extern f32 func_00388770(void *);
extern void func_00388BD0(void *, void *);
extern void func_003C2868(void *);
extern f32 func_00388978(f32);
extern void func_L01_00440A88(f32 *, f32, f32);
extern void func_L01_003F5B38(u8 *, s32, s32, s32, f32 *, s32, s32, f32);
extern void func_L01_002FFEA8(u8 *);

u8 *func_L23_003A6150(u8 *src, u8 *pos, s32 arg)
{
    s32 cls = -1;
    s16 id = D_L23_002362B0[src[0x1A]];
    u8 *m;
    f32 s;
    f32 q[4];

    if (id == D_L23_001DE164) {
        cls = 0x1BD6;
    }
    if (id == D_L23_001DE168) {
        cls = 0x1BD7;
    }
    if (cls < 0) {
        return 0;
    }
    m = func_003BCFB0(cls, 0x80);
    if (m != 0) {
        func_L01_00452E70(m, 0);
        func_L01_0044B598(m, D_L23_001DE160);
        *(f32 *)(m + 0x2C) *= func_00388770(pos + 0x20);
        *(u128_t *)(m + 0x10) = *(u128_t *)(pos + 0x30);
        func_00388BD0(m + 0xC0, m + 0xF0);
        func_003C2868(m);
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x100) & ~0x30;
        *(void (**)(u8 *))(m + 0x64) = func_L01_002FFEA8;
        *(s32 *)(m + 0x98) = 0;
        *(s32 *)(*(u8 **)(m + 0x68) + 0x54) = 0;
        s = func_00388978(0.0058177644f);
        func_L01_00440A88(q, s, s);
        q[3] = sqrt_asm(1.0f - s * s);
        func_L01_003F5B38(m, 2, 0, arg, q, 0xFF, 0xB4, 15.0f);
        *(u16 *)(m + 0x34) &= ~2;
    }
    return m;
}
/* localdecomp:end func_L23_003A6150 */
