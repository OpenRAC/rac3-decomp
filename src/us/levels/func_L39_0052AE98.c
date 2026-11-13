#include "common.h"

/* localdecomp:start func_L39_0052AE98 */
typedef int Quad_52AE98 __attribute__((mode(TI)));
extern u8 *func_003BCFB0(s32, s32);
extern void func_L01_00438908(u8 *, s32, s32, s32);
extern void func_003BDA38(u8 *, s32, u8 *);
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern void func_003C26C8(u8 *);

u8 *func_L39_0052AE98(u8 *a0, f32 f) {
    u8 *m = func_003BCFB0(0x18E1, 0x80);
    u8 *p;
    if (m != 0) {
        p = *(u8 **)(m + 0x68);
        *(f32 *)(p + 4) = f;
        *(u8 **)p = a0;
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        func_L01_00438908(m, 0x80, 0x80, 0x80);
        func_003BDA38(a0, 0, m + 0x10);
        *(Quad_52AE98 *)(m + 0xC0) = *(Quad_52AE98 *)(a0 + 0xC0);
        *(Quad_52AE98 *)(m + 0xD0) = *(Quad_52AE98 *)(a0 + 0xD0);
        *(Quad_52AE98 *)(m + 0xE0) = *(Quad_52AE98 *)(a0 + 0xE0);
        if (m[0x43] != 0) {
            func_003BE4F0(m, 0, 0, 10);
        }
        func_003C26C8(m);
        m[0x20] = 0;
        *(u16 *)(m + 0x34) |= 5;
    }
    return m;
}
/* localdecomp:end func_L39_0052AE98 */
