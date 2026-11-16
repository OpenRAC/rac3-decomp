/*
 * P03 wave-2 deferral, PAL, base 1118a8b8 (2026-11-16).
 * Owner: src/levels/07_annihilation_nation/L07_003AF398.c.
 * Exact owning flags: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
 * -mno-check-zero-division @ps2as. Stock snippet checker printed MATCH.
 * Full PAL level-07 build failed section .rodata relocation agreement:
 * AF398 requires base 0x002C06A0; B0B08 and unchanged B0E08 require
 * 0x002C06C0; B37D0 requires 0x002C06F0; B64D0 requires 0x002C0760.
 * Intervening INCLUDE_ASM jump tables (including AFD10's table) leave holes
 * absent from the combined C object's section. Deferred by owner decision,
 * not exhausted C matching. No full match or US carry claimed.
 * The removed source block, including its markers, is preserved verbatim.
 */
#include "common.h"

/* localdecomp:start func_L07_003B37D0 */
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_00456230(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
void func_L07_003B37D0(u8 *self, s32 state) {
    u8 *p = *(u8 **)(self + 0x68);
    switch (state) {
    case 1:
    case 3:
        break;
    case 2:
        if (self[0x43] != 1) func_003C3A10(self, 1, 0, 0);
        break;
    case 4:
        *(f32 *)(p + 0xC8) = 0.20000002f;
        *(u16 *)(self + 0x34) |= 0x5000;
        break;
    case 5:
        *(s16 *)(p + 0x664) = ((func_00382468(10) + 20) * 5 + 2) / 6;
        if (self[0x95] >= 2) {
            if (self[0x43] != 3) func_003C3A10(self, 3, 0, 2);
        } else if (self[0x43] != 1) func_003C3A10(self, 1, 0, 2);
        *(f32 *)(p + 0xC8) = 0.20000002f;
        *(s32 *)(p + 0xD8) |= 0x10;
        break;
    case 6:
        *(s16 *)(p + 0x660) = ((func_00382468(30) + 60) * 5 + 2) / 6;
        break;
    case 7:
        func_L01_00456230(self, 0);
        p[0x66A] = 0;
        *(f32 *)(p + 0xC8) = (func_003824E0(0.0f, 1.0f) + 3.0f) * 0.020000001f;
        *(f32 *)(p + 0x658) = func_003824E0(0.0f, 2.0f);
        *(f32 *)(p + 0x65C) = func_003824E0(0.0f, 2.0f);
        if (self[0x43] != 0) func_003C3A10(self, 0, 0, 3);
        break;
    case 8:
        *(s16 *)(p + 0x660) = 42;
        break;
    case 9:
        p[0x667] = 1 << func_00382498(0, 1);
        *(s16 *)(p + 0x660) = ((func_00382468(30) + 60) * 5 + 2) / 6;
        break;
    case 10:
        func_L01_00456230(self, 0);
        if (self[0x43] != 4) func_003C3A10(self, 4, 0, 0);
        break;
    case 11:
        if (self[0x43] != 6) func_003C3A10(self, 6, 0, 0);
        break;
    case 12:
        p[0x66A] = 0;
        p[0x667] = 3;
        if (self[0x43] != 2) func_003C3A10(self, 2, 0, 2);
        break;
    }
    func_L01_004450F0(self, state, -1);
}
/* localdecomp:end func_L07_003B37D0 */
