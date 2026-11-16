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

/* localdecomp:start func_L07_003B64D0 */
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_L07_003B6DC8(u8 *, u8 *);
void func_L07_003B64D0(u8 *self, s32 state) {
    u8 *p = *(u8 **)(self + 0x68);
    switch (state) {
    case 1: case 3: case 16: break;
    case 2:
        if (self[0x43] != 22) func_003C3A10(self, 22, 0, 0);
        break;
    case 4:
        if (self[0x43] != 1) func_003C3A10(self, 1, 0, 7);
        break;
    case 5:
        if (self[0x43] != 0) func_003C3A10(self, 0, 0, 8);
        break;
    case 6:
        if (self[0x43] != 17) func_003C3A10(self, 17, 0, 7);
        break;
    case 7:
        if (self[0x43] != 5) func_003C3A10(self, 5, 0, 3);
        break;
    case 8:
        if (func_L07_003B6DC8(self, p + 0x80) > 0.0f) {
            if (self[0x43] != 7) func_003C3A10(self, 7, 0, 2);
        } else {
            if (self[0x43] != 8) func_003C3A10(self, 8, 0, 2);
        }
        break;
    case 9:
        if (self[0x43] != 9) func_003C3A10(self, 9, 0, 3);
        break;
    case 10:
        if (self[0x43] != 10) func_003C3A10(self, 10, 0, 3);
        break;
    case 11:
        if (self[0x43] != 19) func_003C3A10(self, 19, 0, 3);
        break;
    case 12:
        if (self[0x43] != 11) func_003C3A10(self, 11, 0, 3);
        break;
    case 13:
        if (self[0x43] != 12) func_003C3A10(self, 12, 0, 3);
        break;
    case 14:
        if (self[0x43] != 13) func_003C3A10(self, 13, 0, 3);
        break;
    case 15:
        if (self[0x43] != 18) func_003C3A10(self, 18, 0, 3);
        break;
    case 17:
        if (self[0x43] != 14) func_003C3A10(self, 14, 0, 25);
        break;
    case 18:
        if (self[0x43] != 24) func_003C3A10(self, 24, 0, 3);
        break;
    case 19:
        if (self[0x43] != 2) func_003C3A10(self, 2, 0, 3);
        *(f32 *)(self + 0x48) = 0.5f;
        break;
    case 20:
        if (self[0x43] != 3) func_003C3A10(self, 3, 0, 3);
        break;
    case 21:
        if (self[0x43] != 4) func_003C3A10(self, 4, 0, 3);
        *(f32 *)(self + 0x48) = 0.5f;
        break;
    case 22:
        if (self[0x43] != 22) func_003C3A10(self, 22, 0, 3);
        break;
    case 23:
        if (self[0x43] != 23) func_003C3A10(self, 23, 0, 3);
        break;
    case 24:
        if (self[0x43] != 20) func_003C3A10(self, 20, 0, 3);
        break;
    case 25:
        if (self[0x43] != 25) func_003C3A10(self, 25, 0, 3);
        break;
    }
    func_L01_004450F0(self, state, -1);
}
/* localdecomp:end func_L07_003B64D0 */
