#include "common.h"

/* NTSC-U counterpart of func_L10_003C6CB8 (src/levels/10_zeldrin_starport/L10_003C6B68.c) */
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L08_003C50F0(void *, void *, void *);
extern s32 func_00388398(void *);

/* localdecomp:start func_L10_003C4900 */
__asm__(".extern D_L10_001DE90C_003C4900, 4");
__asm__(".extern D_L10_001DE910_003C4900, 4");
extern f32 D_L10_001DE90C_003C4900;
extern s32 D_L10_001DE910_003C4900;
extern f32 func_0037E2A8(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_0039FE80(s32, s32, void *);
extern u8 D_L10_001D66B0_003C4900[8];
extern void func_L01_0044ED60(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);

void func_L10_003C4900(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    f32 a;
    s32 t;
    f32 f;

    switch (m[0x20]) {
    case 0:
        a = func_0037E2A8();
        *(f32 *)(v + 0) = func_00388960(a);
        *(f32 *)(v + 4) = func_00388978(a);
        *(f32 *)(v + 8) = func_0037E250(-0.5f, 0.5f);
        *(f32 *)(v + 0xC) = 0.0f;
        func_00388830(v, v, 1.0f);
        t = D_L10_001DE910_003C4900;
        f = D_L10_001DE90C_003C4900;
        *(s32 *)(v + 0x10) = t;
        *(f32 *)(v + 0x14) = *(f32 *)(m + 0x2C) / f;
        func_L01_00441FB8(m, 1, -1);
        break;
    case 1:
        if (func_L01_00444358(m, -1, 0) != 0) {
            func_0039FE80(0, 0, m);
            func_L01_0044ED60(m, 0xF, D_L10_001D66B0_003C4900, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f,
                              3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
            m[0x31] = 0;
            *(u16 *)(m + 0x34) |= 1;
            func_L01_0044EBF8(m, 1, 0.0f);
            func_L01_00441FB8(m, 2, -1);
        }
        break;
    case 2:
        func_L08_003C50F0(m, m + 0x10, v);
        if (func_00388398(v + 0x10) != 0) {
            func_L01_00441FB8(m, 3, -1);
        }
        break;
    case 3:
        func_003BD360(m);
        return;
    }
    m[0xA8] = 0xFF;
}
/* localdecomp:end func_L10_003C4900 */
