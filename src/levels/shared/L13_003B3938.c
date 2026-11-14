#include "common.h"

typedef int Quad_3B4618 __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L13_003B3938);

INCLUDE_ASM("asm/levels", func_L13_003B3DA8);

INCLUDE_ASM("asm/levels", func_L13_003B3F58);

INCLUDE_ASM("asm/levels", func_L13_003B40A0);

/* localdecomp:start func_L13_003B4618 */
/* PAL port of the NTSC-U match src/us/levels/func_L13_003B2720.c */

extern f32 D_L13_001DE8DC;
__asm__(".extern D_L13_001DE8DC, 4");
extern f32 D_L13_001D66B0[2];
__asm__(".extern D_L13_001D66B0, 16");
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0044A7D0(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C7C38(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0046B458(f32 *, s32, s32, s32, s32, f32 *, f32, f32, f32, s32);

u8 *func_L13_003B4618(void *owner, void *pos, f32 *dir, u8 type, s32 extra) {
    u8 *m;
    u8 *vars;
    Quad_3B4618 q;
    s32 ff;

    m = func_003C24B0(0x1BF4, 0x40);
    if (m != 0) {
        *(void **)(m + 0xB8) = owner;
        vars = *(u8 **)(m + 0x68);
        ff = 0xFF;
        *(s16 *)(m + 0x32) = ff;
        m[0x30] = ff;
        m[0x31] = 1;
        func_L01_0044A7D0(m);
        q = *(Quad_3B4618 *)pos;
        *(Quad_3B4618 *)(m + 0x10) = q;
        *(Quad_3B4618 *)(vars + 0x10) = q;
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * D_L13_001DE8DC;
        *(Quad_3B4618 *)vars = *(Quad_3B4618 *)dir;
        *(f32 *)(m + 0xF8) = func_0038D160(dir[0], dir[1]);
        *(f32 *)(m + 0xF4) = -func_0038D160(func_0038CED8(dir), dir[2]);
        *(f32 *)(vars + 0x2C) = 1.0f;
        vars[0x24] = type;
        *(s32 *)(vars + 0x20) = extra;
        vars[0x25] = 67;
        *(f32 *)(vars + 0x30) = 0.0f;
        *(s32 *)(vars + 0x34) = 0;
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
        func_003C7C38(m);
        func_L01_004450F0(m, 1, -1);
        func_L01_0046B458((f32 *)(vars + 0x10), 33, 0xAF076007, 0, 2, D_L13_001D66B0, 10.0f, 15.0f, 0.0f, 0);
        func_L01_0046B458((f32 *)(vars + 0x10), 33, 0x7F7F7F7F, 0, 2, D_L13_001D66B0, 8.0f, 12.0f, 0.0f, 0);
    }
    return m;
}
/* localdecomp:end func_L13_003B4618 */
