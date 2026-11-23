/* PAL port of the NTSC-U draft (Claude wave K, func_L03_003C3B00; the two versions' code differs): 22 aligned rows with the file's flags (-mvu0-use-vf0-vf2 @ps2as), the earlier NTSC-U-named draft was 285 words off on NTSC-U and about 160 rows on PAL after a name mapping.
 * What the port needed: callee names through config/us/map.tsv; PAL's 50 Hz values (25.0f for the fade, 417 for the 500-frame wait, the four rotation-smoothing constants pi/75, pi/225, pi/450 and pi/100, 0.02792527f); PAL-only `func_003C2880(self)` after the case-2 `func_L01_004AA7E8(self, 1)` (the early `D_00142796` return jumps to that shared tail); data at PAL addresses (D_001DEDB0_sda, D_L03_001DF2DC, D_L03_001DF6B8, D_L03_001E9228) with .extern size hints for the scalars retail reaches through `lui $at`/$gp; the hero base read as `D_001A4BE0 + off` through two pointers (one before the 3-pass loop, one after: retail rematerialises it from the shared `lui` in $s4 and reuses $s0 as the loop counter; a single pointer held across the loop was the 127-row cascade); t0/t1 as `u128_t tt[2]` (stack layout).
 * Round 14 (Sonnet b24-u1): 20 aligned rows (check.py's raw count is 184: everything after the first extra `andi` is shifted). The t quads written the other way round (`tt[0] = ...; tt[1] = tt[0];`) give retail's store order, z loads and add/sub order.
 * Left: (1) the `self[0x20]` compares: retail has `lbu $v0; andi $a0,$v0,0xff; bnez $a0; move $a1,$v0` and compares $a0 again for `== 1` (here $v1/$a0); in the second chain it compares the raw byte (`bne $v0,$v1`, `move $a1,$v0`) and then `andi $v1,$a1,0xff` before the `== 2` test (here the copy is compared without the `andi`: gcc knows it is zero-extended). The extra `andi` also moves the loop-padding nop and every later branch offset. A local `u8`/`s32` for the state loses the `andi` altogether (115 raw). (2) the D_001A7E18 halfword read's registers ($v0/$v1 swapped; `*(u16 *)((u8 *)D_001A7E18 + 0xC540)` and `!D_001A7E18[0x6270]` give the same or worse). */
/* NM-R7 (2026-11-22): file-ready; compiles in L03_003C5460.c's context with the file's u128_t, D_001CCFD0 and func_003A52A0 declarations: 184 differences (tools/check.py) at level 03, 185 at level 05. */
/* FAM-2 (2026-11-23, upstream bbf261a1): still 184 at level 03, 185 at level 05 (the file's flags); a u8 state local following retail's dataflow gives 115 with no andi at all. */
#include "common.h"

/* localdecomp:start func_L03_003C5968 */
extern s32 D_001D545C_sda;
extern f32 D_001DEDB0_sda;
__asm__(".extern D_001DEDB0_sda, 4");
extern s32 D_L03_001DF2DC;
extern s32 D_L03_001DF6B8;
__asm__(".extern D_L03_001DF6B8, 16");
extern f32 D_L03_001E9228[];
extern u8 D_00142796[];
extern u8 D_001A4C60[];
extern u8 D_001A4BE0[];
extern u16 D_001A7E18[];
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_00382538(void);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_L03_003C5460(void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_L03_003C5190(void *);
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);
extern void func_003A1798(void);
extern void func_L03_003C5760(void *);
extern s32 func_00382468(s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern s32 func_0038CAD0(void *);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_003EB5E0(s32, s32);
extern void func_L03_003C5E10(void *, s32);
extern void func_L01_00451F60(s32, s32, s32);
extern void func_0039EF28(void);
extern void func_0039EC28(s32, s32);
extern void func_L01_0041A5B0(s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C2880(void *);

void func_L03_003C5968(u8 *self) {
    u8 *s3 = *(u8 **)(self + 0x68);
    u128_t tt[2];
    s32 one;
    s32 i;
    u16 fl;

    if (s3 == 0) {
        return;
    }
    if (D_001D545C_sda != 3) {
        if (self[0x20] == 0) {
            if (D_00142796[0] != 0) {
                func_003C2880(self);
                return;
            }
            *(u128_t *)(s3 + 0x20) = *(u128_t *)(self + 0x10);
            *(f32 *)(s3 + 0x2C) = *(f32 *)(self + 0xF8);
            tt[0] = *(u128_t *)(self + 0x10);
            tt[1] = tt[0];
            ((f32 *)&tt[1])[2] = ((f32 *)&tt[1])[2] + 1.0f;
            ((f32 *)&tt[0])[2] = ((f32 *)&tt[0])[2] - 1.0f;
            if (func_003D3CB0(&tt[1], &tt[0], 2, self, 0) != 0) {
                *(f32 *)(self + 0x18) = D_L03_001E9228[0] + 0.5f;
            }
            *(f32 *)(self + 0xF0) = func_00382538();
            *(f32 *)(self + 0xF4) = func_00382538();
            *(f32 *)(self + 0xF8) = func_00382538();
            *(f32 *)(self + 0xFC) = func_00382538();
            *(f32 *)(s3 + 8) = *(f32 *)(self + 0x18);
            func_L01_004450F0(self, 1, -1);
        } else if (self[0x20] == 1) {
            if (func_0038CF00(D_001A4C60, self + 0x10) <= D_001DEDB0_sda) {
                func_L03_003C5460(self);
            }
        }
        if (self[0x20] == 1) {
            *(f32 *)(self + 0xF0) = func_0038DAB8(*(f32 *)(self + 0xF0), 0.041887905f);
            *(f32 *)(self + 0xF4) = func_0038DAB8(*(f32 *)(self + 0xF4), 0.013962635f);
            *(f32 *)(self + 0xF8) = func_0038DAB8(*(f32 *)(self + 0xF8), 0.0069813174f);
            *(f32 *)(self + 0xFC) = func_0038DAB8(*(f32 *)(self + 0xFC), 0.03141593f);
            func_L03_003C5190(self);
            func_L01_0044EAE0(self, s3, s3 + 4, 0.25f, 0.02792527f, *(f32 *)(s3 + 8));
            *(s16 *)(self + 0x96) = 0;
        } else if (self[0x20] == 2) {
            u8 *a = (u8 *)&D_001CCFD0;
            u8 *h1;
            u8 *h2;
            if (*(s16 *)(a + 0x76) == 0) {
                if (*(s16 *)(a + 0x9E) == 3 && *(s16 *)(a + 0x98) < 0x1B58) {
                    func_003A1798();
                }
            }
            one = 1;
            D_L03_001DF6B8 = one;
            h1 = D_001A4BE0;
            *(s16 *)(h1 + 0x1DC) = 3;
            func_L03_003C5760(self);
            *(u128_t *)(self + 0x10) = *(u128_t *)(h1 + 0x80);
            *(u128_t *)(self + 0xF0) = *(u128_t *)(h1 + 0x90);
            if (self[0x42] == one) {
                if (func_00382468(10) == 0) {
                    func_L03_003C5190(self);
                }
                if (self[0x60] & 2) {
                    if (self[0x43] != 0) {
                        func_003C3A10(self, 0, 0, 0);
                    }
                    self[0x31] = 0;
                    *(u16 *)(self + 0x34) |= 1;
                    for (i = 3; i >= 0; i--) {
                        func_L03_003C5190(self);
                    }
                }
            }
            h2 = D_001A4BE0;
            if (*(s32 *)(h2 + 0xC08) & 2) {
                func_L01_0050FB40(0, 0, 25.0f);
            }
            if (self[0x42] == 0) {
                if (func_0038CAD0(s3 + 0x7C) != 0) {
                    D_L03_001DF2DC = 0;
                    func_L01_004F50C8(h2 + 0x80, h2 + 0x90, 0, 0);
                    func_L01_003EB5E0(0, 0);
                    func_003A52A0(0, 0, self);
                    func_L03_003C5E10(self + 0x10, 10);
                    func_L01_00451F60(0x12AD, 0x1A1, 0);
                    D_00142796[0] = 1;
                    func_0039EF28();
                    func_0039EC28(0, -1);
                    if (D_001A7E18[(0x8000 + 0x4540) / 2] == 0) {
                        func_L01_0041A5B0(0x1070, 0xDF);
                    }
                    *(s32 *)(self + 0x98) = 0;
                    *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
                    func_L01_004AA7E8(self, 1);
                    func_003C2880(self);
                }
            }
        }
    } else {
        if (self[0x20] == 0) {
        self[0x20] = 1;
        if (D_00142796[0] == 0) {
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
            *(s32 *)(self + 0x98) = 0;
            func_L01_004AA7E8(self, 1);
        } else {
            u8 *o;
            *(f32 *)(self + 0xF4) = func_0038DAB8(*(f32 *)(self + 0xF4), 1.5707964f);
            *(f32 *)(self + 0x18) = *(f32 *)(self + 0x18) + 0.35f;
            fl = *(u16 *)(self + 0x34) & 0xFFBE;
            o = *(u8 **)(self + 0x24);
            *(u16 *)(self + 0x34) = fl;
            *(u16 *)(self + 0x34) = fl | (*(u16 *)(o + 0x44) & 0x1000);
            *(s32 *)(self + 0x98) = *(s32 *)(o + 0x10);
        }
        }
    }
}
/* localdecomp:end func_L03_003C5968 */
