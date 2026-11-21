/* functional: high. Draft from the PAL near miss, every constant and field checked against the PAL asm; only bytes differ (func_0013D3E0 is called through an s32-returning pointer cast because the unit prototypes it as u8 and retail uses its full int result). */
#include "vu0.h"
extern u8 *D_L01_002210C8[];
u8 *func_L01_00469210(vu0_q *position, vu0_q *velocity, u8 type, s32 value, u8 size, s32 render) {
    extern u8 *func_L01_004618E0(s32);
    extern u32 func_L01_00448CC0(f32, f32, f32, f32);
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32, f32);
    u8 *p = func_L01_004618E0(0x28);
    u8 *vars;
    if (p) {
        *(vu0_q *)(p + 0x10) = *position;
        vars = p + 0x20;
        *(vu0_q *)(p + 0x20) = *velocity;
        *(u32 *)(p + 4) = func_L01_00448CC0(0.7f, 0.7f, 0.7f, 0.08f);
        p[1] = 0;
        p[9] = ((render >> 5) << 4) + 4;
        p[3] = 0x44;
        *(f32 *)(vars + 0x10) = func_00382538();
        p[8] = (s32)(*(f32 *)(vars + 0x10) * 256.0f);
        p[2] = D_L01_002210C8[0][func_0013D3E0() & 7];
        vars[0x19] = size;
        vars[0x18] = type;
        *(s16 *)(vars + 0x14) = 0;
        *(s16 *)(vars + 0x16) = 0;
        if (type < 5) {
            *(f32 *)(p + 0xC) = func_003824E0(((u8)size * 0.03125f) * 21000.0f, ((u8)size * 0.03125f) * 30000.0f);
            *(s16 *)(p + 0xA) = 15 - ((s32 (*)(void))func_0013D3E0)() % 12;
        } else {
            *(f32 *)(p + 0xC) = (vars[0x19] * 0.03125f) * 30000.0f;
            *(s16 *)(p + 0xA) = 15;
        }
        *(s32 *)(vars + 0x1C) = value;
    }
    return p;
}
