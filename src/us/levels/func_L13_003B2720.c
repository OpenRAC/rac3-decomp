#include "common.h"

/* NTSC-U counterpart of func_L13_003B4618 (src/levels/shared/L13_003B3938.c) */
/* localdecomp:start func_L13_003B2720 */
typedef int Quad_3B4618 __attribute__((mode(TI)));
extern f32 D_001DE90C_sda;
__asm__(".extern D_001DE90C_sda, 4");
extern f32 D_L13_001D66B0[2];
__asm__(".extern D_L13_001D66B0, 16");
extern u8 *func_003BCFB0(s32, s32);
extern void func_L01_004475D0(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_003887A0(void *);
extern void func_L01_004A6DF8(void *, s32);
extern void func_003C26C8(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00467DA8(f32 *, s32, s32, s32, s32, f32 *, f32, f32, f32, s32);

u8 *func_L13_003B2720(void *owner, void *pos, f32 *dir, u8 type, s32 extra) {
    u8 *m;
    u8 *vars;
    Quad_3B4618 q;
    s32 ff;

    m = func_003BCFB0(0x1BF4, 0x40);
    if (m != 0) {
        *(void **)(m + 0xB8) = owner;
        vars = *(u8 **)(m + 0x68);
        ff = 0xFF;
        *(s16 *)(m + 0x32) = ff;
        m[0x30] = ff;
        m[0x31] = 1;
        func_L01_004475D0(m);
        q = *(Quad_3B4618 *)pos;
        *(Quad_3B4618 *)(m + 0x10) = q;
        *(Quad_3B4618 *)(vars + 0x10) = q;
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * D_001DE90C_sda;
        *(Quad_3B4618 *)vars = *(Quad_3B4618 *)dir;
        *(f32 *)(m + 0xF8) = func_00388A28(dir[0], dir[1]);
        *(f32 *)(m + 0xF4) = -func_00388A28(func_003887A0(dir), dir[2]);
        *(f32 *)(vars + 0x2C) = 1.0f;
        vars[0x24] = type;
        *(s32 *)(vars + 0x20) = extra;
        vars[0x25] = 0x50;
        *(f32 *)(vars + 0x30) = 0.0f;
        *(s32 *)(vars + 0x34) = 0;
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L01_004A6DF8(m, 1);
        func_003C26C8(m);
        func_L01_00441FB8(m, 1, -1);
        func_L01_00467DA8((f32 *)(vars + 0x10), 0x28, 0xAF076007, 0, 2, D_L13_001D66B0, 10.0f, 15.0f, 0.0f, 0);
        func_L01_00467DA8((f32 *)(vars + 0x10), 0x28, 0x7F7F7F7F, 0, 2, D_L13_001D66B0, 8.0f, 12.0f, 0.0f, 0);
    }
    return m;
}
/* localdecomp:end func_L13_003B2720 */
