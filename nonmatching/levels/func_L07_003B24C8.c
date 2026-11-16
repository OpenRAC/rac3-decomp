/*
 * P03 PAL retail reconstruction, wave 2, base 1118a8b8 (2026-11-16).
 * Owner: src/levels/07_annihilation_nation/L07_003AF398.c.
 * Flags: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
 *        -mno-check-zero-division @ps2as.
 * Stock checker: 16 positional differences; preserves checked iteration 04.
 * Attempts: 16, 16, compile error (missing struct tag), 16 differences.
 * Pointer arithmetic, commuted operands and typed indexing give identical
 * output (01/02/04). Remaining: moby-index/base/flag register allocation.
 * No full build or US carry; marker retained.
 */
#include "common.h"
#include "structs/moby.h"
extern void func_0038D308(void *, void *);
extern void func_L07_003B2870(void *);
extern void func_L07_003B2738(u8 *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_L01_004AAC98(s32, s32, void *, s32);
extern void func_L01_004AA760(s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern u8 D_001A4C60[];
extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 4");
void func_L07_003B24C8(u8 *self) {
    u8 *p = *(u8 **)(self + 0x68);
    u8 *other;
    s32 index;
    if (self[0x20] == 0) {
        func_0038D308(self + 0xC0, self + 0xF0);
        func_L07_003B2870(self);
    }
    switch (self[0x20]) {
    case 1:
        if (*(s32 *)(p + 0xC) != -1 && func_00382380(D_001A4C60, *(s32 *)(p + 0xC), 0))
            self[0xBE] |= 4;
        if (self[0xBE] & 4) func_L01_004450F0(self, 2, -1);
        break;
    case 2:
        if (func_L01_004561B8(self)) {
            func_L01_004AAC98(0, 4, self, 0x1D79);
            index = *(s32 *)(p + 0x10);
            if (index != -1) {
                other = (u8 *)&((struct Moby *)D_L07_001DF41C)[index];
                other[0xBE] |= 4;
            }
        }
        if (!(self[0xBE] & 4)) {
            func_L01_004AA760(0, self);
            func_L01_004450F0(self, 4, -1);
        } else {
            *(f32 *)(p + 0x14) += 0.012f;
            if (*(f32 *)(p + 0x14) >= 1.0f) {
                *(f32 *)(p + 0x14) = 1.0f;
                func_L01_004AA760(0, self);
                func_L01_004450F0(self, 3, -1);
            }
            func_L07_003B2738(self);
        }
        break;
    case 3:
        if (!(self[0xBE] & 4)) func_L01_004450F0(self, 4, -1);
        break;
    case 4:
        if (func_L01_004561B8(self)) {
            func_L01_004AAC98(0, 4, self, 0x1D79);
            index = *(s32 *)(p + 0x10);
            if (index != -1) {
                other = (u8 *)&((struct Moby *)D_L07_001DF41C)[index];
                other[0xBE] &= ~4;
            }
        }
        if (self[0xBE] & 4) {
            func_L01_004AA760(0, self);
            func_L01_004450F0(self, 2, -1);
        } else {
            *(f32 *)(p + 0x14) -= 0.012f;
            if (*(f32 *)(p + 0x14) <= 0.0f) {
                *(f32 *)(p + 0x14) = 0.0f;
                func_L01_004AA760(0, self);
                func_L01_004450F0(self, 1, -1);
            }
            func_L07_003B2738(self);
        }
        break;
    }
}
