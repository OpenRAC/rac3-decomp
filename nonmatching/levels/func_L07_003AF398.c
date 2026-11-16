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

/* localdecomp:start func_L07_003AF398 */
extern void func_L07_003AF600(void *);
extern void func_L07_003AF678(u8 *);
extern s32 func_L07_003AF758(u8 *);
extern void func_L07_003AF7F8(u8 *);
extern void func_L07_003AF7B8();
extern void func_L07_003AF920(u8 *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_004AA760(s32, void *);
void func_L07_003AF398(u8 *self) {
    u8 *p;
    func_L07_003AF600(self);
    func_L07_003AF678(self);
    p = *(u8 **)(self + 0x68);
    switch (self[0x20]) {
    case 1:
        if (func_L07_003AF758(self)) {
            func_003A52A0(1, 4, self);
            func_L01_004450F0(self, 2, -1);
        }
        break;
    case 2:
        *(f32 *)(p + 0xD4) += 0.010053097f;
        if (*(f32 *)(p + 0xD4) > 0.25132743f) {
            *(f32 *)(p + 0xD4) = 0.25132743f;
            func_L01_004450F0(self, 3, -1);
        }
        func_L07_003AF7F8(self);
        ((void (*)(void *, f32))func_L07_003AF7B8)(self, *(f32 *)(p + 0xD4));
        if (!func_L07_003AF758(self)) func_L01_004450F0(self, 4, -1);
        break;
    case 3:
        if (func_L01_004561B8(self)) *(s16 *)(p + 0xE8) = 250;
        if (++*(u16 *)(self + 0x96) >= 6) {
            func_003A52A0(0, 0, self);
            func_L07_003AF920(self);
            *(u16 *)(self + 0x96) = 0;
        }
        func_L07_003AF7F8(self);
        ((void (*)(void *, f32))func_L07_003AF7B8)(self, *(f32 *)(p + 0xD4));
        if (func_0038CB00(p + 0xE8) || !func_L07_003AF758(self))
            func_L01_004450F0(self, 4, -1);
        break;
    case 4:
        *(f32 *)(p + 0xD4) -= 0.010053097f;
        if (*(f32 *)(p + 0xD4) <= 0.0f) {
            *(f32 *)(p + 0xD4) = 0.0f;
            if (func_L07_003AF758(self)) func_L01_004450F0(self, 5, -1);
            else {
                func_L01_004AA760(1, self);
                func_L01_004450F0(self, 1, -1);
            }
        }
        ((void (*)(void *, f32))func_L07_003AF7B8)(self, *(f32 *)(p + 0xD4));
        break;
    case 5:
        if (func_L01_004561B8(self)) *(s16 *)(p + 0xE8) = 100;
        if (!func_L07_003AF758(self)) {
            func_L01_004AA760(1, self);
            func_L01_004450F0(self, 1, -1);
        } else if (func_0038CB00(p + 0xE8)) func_L01_004450F0(self, 2, -1);
        break;
    }
}
/* localdecomp:end func_L07_003AF398 */
