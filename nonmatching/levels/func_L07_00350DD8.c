/* NTSC-U draft (2026-11-14, Claude worker): C of func_L07_00350120, the NTSC-U twin of func_L07_00350DD8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L07_0034FC78.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* localdecomp:start func_L07_00350120 */
/* Needs @ps2as (float immediates) beyond the PAL file's flags. */
typedef int u128_00350120 __attribute__((mode(TI)));
extern s32 D_001D545C;
extern u8 D_L07_001E1EC0[];

extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L07_00350490(void *);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern void func_0039FE80(s32, s32, void *);
extern void func_L01_004412D0(void *, s32, s32);
extern void func_003BD360(void *);
extern s32 func_L01_0044FCD0(void *, void *, s32, s32, s32);
extern void func_L07_003507A0(void *);
extern s32 func_L01_004539A8(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L07_00350120(void *self) {
    u8 *a0 = self;
    u8 *st;
    f32 f;

    st = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 0) {
        f = *(f32 *)(st + 0x440);
        *(s32 *)(st + 0x74) = 0;
        *(s32 *)(st + 0x9C) = 0;
        st[0x170] = 6;
        st[0x1A8] = 3;
        *(f32 *)(st + 0x19C) = 0.15f;
        *(f32 *)(st + 0x70) = 1.868f;
        *(f32 *)(st + 0x7C) = 0.5f;
        *(f32 *)(st + 0x80) = 3.1415927f;
        *(f32 *)(st + 0xA0) = 0.5235988f;
        *(f32 *)(st + 0x190) = 0.5f;
        *(f32 *)(st + 0x194) = 0.5f;
        *(f32 *)(st + 0x78) = 0.5f;
        func_L01_00458A70(a0, (f + f) * 0.00027777778f, f * 0.016666668f, 0.00043633234f, 0.034906588f);
        *(s32 *)(st + 0xA8) |= 2;
        if (*(s16 *)(st + 0x34) == 0) {
            *(s16 *)(st + 0x34) = 1;
            *(f32 *)(st + 0x30) = 1.0f;
        }
        st[0x3F] = 0;
        st[0x3E] = 1;
        st[0x64] = 0;
        *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * 1.3f;
        st[0x58] = 0x12;
        st[0x5A] = 0x10;
        *(f32 *)(st + 0x3B8) = *(f32 *)(a0 + 0x18);
        *(u128_00350120 *)(st + 0x260) = *(u128_00350120 *)(a0 + 0x10);
        *(u128_00350120 *)(st + 0x270) = *(u128_00350120 *)(a0 + 0xF0);
        if (D_001D545C != 0x10) {
            func_L07_00350490(a0);
        } else {
            func_L01_00441FB8(a0, 1, 0);
        }
    }
    if (a0[0x31] != 0) {
        if (func_L01_0040C018(D_L07_001E1EC0, a0 + 0x10) < 1024.0f) {
            func_L01_00444188(a0);
            a0[0x6F] = 0x1E;
        }
    }
    if (st[0x3E] == 2) {
        func_0039FE80(4, 0, a0);
        func_L01_004412D0(a0, 0, 3);
        func_003BD360(a0);
        return;
    }
    if (func_L01_0044FCD0(a0, st + 0x160, 0, 0, 0) != 0) {
        func_L07_003507A0(a0);
    }
    *(s32 *)(st + 0x2A0) = func_L01_004539A8(a0, *(s32 *)(st + 0x290), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x294), 10.0f, 1.0f);
    *(s32 *)(st + 0x3B4) = func_L01_004539A8(a0, *(s32 *)(st + 0x3B0), 0, 0, 0, 0, 1, 0, 0, 0, 0.0f, 10.0f, 1.0f);
    *(f32 *)(a0 + 0x18) = *(f32 *)(st + 0x3B8);
}
/* localdecomp:end func_L07_00350120 */
