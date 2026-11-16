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

/* localdecomp:start func_L07_003B0B08 */
extern void func_L07_003B0CF8(u8 *);
extern void func_L07_003B0F20(u8 *);
extern void func_L07_003B0FE0(void *);
extern void func_L07_003B13E8(u8 *);
extern void func_L07_003B0E08(void *, s32);
extern s32 func_L07_003B12D8(u8 *);
extern void func_L01_004AA760(s32, void *);
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_003C7C38(void *);
void func_L07_003B0B08(u8 *self) {
    u8 *p;
    func_L07_003B0CF8(self);
    p = *(u8 **)(self + 0x68);
    switch (self[0x20]) {
    case 1:
        break;
    case 3:
        if (self[0x60] & 2) {
            func_L01_004AA760(0, self);
            func_L07_003B0FE0(self);
            func_L07_003B0E08(self, 4);
        } else func_L07_003B0F20(self);
        break;
    case 4:
        *(f32 *)(p + 0x48) += 0.012f;
        if (*(f32 *)(p + 0x48) >= 1.0f) {
            *(f32 *)(p + 0x48) = 1.0f;
            func_L01_004AA760(1, self);
            func_L07_003B0E08(self, 2);
        }
        *(f32 *)(*(u8 **)(p + 0x44) + 0xF0) = func_003C3BE8(0.0f, -1.5707964f, *(f32 *)(p + 0x48));
        func_003C7C38(*(void **)(p + 0x44));
        break;
    case 2:
        if (func_L07_003B12D8(self)) func_L07_003B0E08(self, 5);
        break;
    case 5:
        if (!func_L07_003B12D8(self)) {
            func_L07_003B0E08(self, 4);
            break;
        }
        *(f32 *)(p + 0x48) -= 0.012f;
        if (*(f32 *)(p + 0x48) <= 0.0f) {
            *(f32 *)(p + 0x48) = 0.0f;
            func_L01_004AA760(1, self);
            func_L07_003B0E08(self, 6);
        }
        *(f32 *)(*(u8 **)(p + 0x44) + 0xF0) = func_003C3BE8(0.0f, -1.5707964f, *(f32 *)(p + 0x48));
        func_003C7C38(*(void **)(p + 0x44));
        break;
    case 6:
        if (self[0x60] & 2) {
            func_L01_004AA760(0, self);
            func_L07_003B13E8(self);
            func_L07_003B0E08(self, 1);
        } else func_L07_003B0F20(self);
        break;
    }
}
/* localdecomp:end func_L07_003B0B08 */
