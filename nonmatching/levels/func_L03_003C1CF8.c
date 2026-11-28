/* func_L03_003C1CF8 (Claude wave 14 r63, 2026-11-28). Replaces the earlier draft of this function (NTSC-U draft of `func_L03_003BFEF0` (Claude wave K)). */
/* PAL near miss, wave 14 r63 (2026-11-28): func_L03_003C1CF8 (1188 B, levels 03 and 19).
 * func_L03_003C0DD8's b39-w10 draft ported to this sibling (flag byte D_00142792, D_001DEC70_sda, callees
 * func_L03_003C17F8 / 003C1528 / 003C1AF0 / 003C21A0, sound 0x12A9, D_L03_001E9220[2] + 0.5f), with the
 * family's dead third test at the end of chain 2 and func_0039EC28 returning s32.
 * Needs @ps2as: retail's float constants are Ps2EeAs lui/ori/mtc1 (0.0418879, 0.0139626, 0.0069813,
 * 0.0314159, 0.0279253, 1.5707964, 0.35). The file holds only this function, so its line can become the
 * existing "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (no VU0 code here, -mvu0-use-vf0-vf2 not needed).
 * tools/check.py --as ps2as: 7 diff at level 03; under the file's current line 213 (p10/check.py).
 * Still differs: only the registers of the first zero-extension of o[0x20] and its raw copy (ours $v1/$a0,
 * retail $a0/$a1) and the two andi that read the copy. Tried without effect (7): the dead test reading
 * D_001D545C_sda in its second or third conjunct; worse: D_001D545C_sda as its first conjunct (184),
 * as a fourth conjunct (186). */
#include "common.h"

/* localdecomp:start func_L03_003C1CF8 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x80];
    vu0_v4 f80;
    vu0_v4 f90;
    u8 padA0[0x1DC - 0xA0];
    s16 f1DC;
    u8 pad1DE[0xC08 - 0x1DE];
    u32 fC08;
} H_003C1CF8;

extern H_003C1CF8 D_001A4BE0;
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern f32 D_001DEC70_sda;
__asm__(".extern D_001DEC70_sda, 4");
extern s32 D_001DF2DC_sda;
__asm__(".extern D_001DF2DC_sda, 4");
extern u8 D_00142792[];
__asm__(".extern D_00142792, 16");
extern f32 D_L03_001E9220[];
__asm__(".extern D_L03_001E9220, 16");
extern s32 D_L03_001DF6B8;
__asm__(".extern D_L03_001DF6B8, 16");
extern u8 D_001A4C60[];
typedef struct {
    u8 pad0[0x76];
    s16 f76;
    u8 pad78[0x98 - 0x78];
    s16 f98;
    u8 pad9A[0x9E - 0x9A];
    s16 f9E;
} G_003C1CF8;
extern G_003C1CF8 D_001CCFD0;
extern u16 D_001A7E18[];

extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern f32 func_00382538(void);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_L03_003C17F8(u8 *);
extern f32 func_0038DAB8(f32, f32);
extern void func_L03_003C1528(u8 *);
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);
extern void func_003A1798(void);
extern void func_L03_003C1AF0(u8 *);
extern s32 func_00382468(s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern s32 func_0038CAD0(void *);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_003EB5E0(s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L03_003C21A0(void *, s32);
extern void func_L01_00451F60(s32, s32, s32);
extern void func_0039EF28(void);
extern s32 func_0039EC28(s32, s32);
extern void func_L01_0041A5B0(s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C2880(void *);

void func_L03_003C1CF8(u8 *o) {
    u8 *st;
    u8 *sv;
    vu0_v4 v0;
    vu0_v4 v10;
    s32 i;
    s32 one;

    st = *(u8 **)(o + 0x68);
    if (st != 0) {
        if (D_001D545C_sda != 3) {
            if (o[0x20] == 0) {
                if (D_00142792[0] != 0) {
                    goto kill;
                }
                *(vu0_v4 *)(st + 0x20) = *(vu0_v4 *)(o + 0x10);
                *(f32 *)(st + 0x2C) = *(f32 *)(o + 0xF8);
                v0 = *(vu0_v4 *)(o + 0x10);
                v10 = *(vu0_v4 *)(o + 0x10);
                v10.z += 1.0f;
                v0.z -= 1.0f;
                if (func_003D3CB0(&v10, &v0, 2, o, 0) != 0) {
                    *(f32 *)(o + 0x18) = D_L03_001E9220[2] + 0.5f;
                }
                *(f32 *)(o + 0xF0) = func_00382538();
                *(f32 *)(o + 0xF4) = func_00382538();
                *(f32 *)(o + 0xF8) = func_00382538();
                *(f32 *)(o + 0xFC) = func_00382538();
                *(f32 *)(st + 8) = *(f32 *)(o + 0x18);
                func_L01_004450F0(o, 1, -1);
            } else if (o[0x20] == 1) {
                if (func_0038CF00(D_001A4C60, o + 0x10) <= D_001DEC70_sda) {
                    func_L03_003C17F8(o);
                }
            }
            if (o[0x20] == 1) {
                *(f32 *)(o + 0xF0) = func_0038DAB8(*(f32 *)(o + 0xF0), 0.041887905f);
                *(f32 *)(o + 0xF4) = func_0038DAB8(*(f32 *)(o + 0xF4), 0.013962635f);
                *(f32 *)(o + 0xF8) = func_0038DAB8(*(f32 *)(o + 0xF8), 0.0069813174f);
                *(f32 *)(o + 0xFC) = func_0038DAB8(*(f32 *)(o + 0xFC), 0.03141593f);
                func_L03_003C1528(o);
                func_L01_0044EAE0(o, st, st + 4, 0.25f, 0.02792527f, *(f32 *)(st + 8));
                *(u16 *)(o + 0x96) = 0;
            } else if (o[0x20] == 2) {
                if (D_001CCFD0.f76 == 0 && D_001CCFD0.f9E == 3 && D_001CCFD0.f98 < 0x1B58) {
                    func_003A1798();
                }
                one = 1;
                D_L03_001DF6B8 = one;
                D_001A4BE0.f1DC = 3;
                func_L03_003C1AF0(o);
                *(vu0_v4 *)(o + 0x10) = D_001A4BE0.f80;
                *(vu0_v4 *)(o + 0xF0) = D_001A4BE0.f90;
                if (o[0x42] == one) {
                    if (func_00382468(10) == 0) {
                        func_L03_003C1528(o);
                    }
                    if (o[0x60] & 2) {
                        if (o[0x43] != 0) {
                            func_003C3A10(o, 0, 0, 0);
                        }
                        o[0x31] = 0;
                        *(u16 *)(o + 0x34) |= 1;
                        for (i = 3; i >= 0; i--) {
                            func_L03_003C1528(o);
                        }
                    }
                }
                if (D_001A4BE0.fC08 & 2) {
                    func_L01_0050FB40(0, 0, 25.0f);
                }
                if (o[0x42] == 0) {
                    if (func_0038CAD0(st + 0x7C) != 0) {
                        D_001DF2DC_sda = 0;
                        func_L01_004F50C8(&D_001A4BE0.f80, &D_001A4BE0.f90, 0, 0);
                        func_L01_003EB5E0(0, 0);
                        func_003A52A0(0, 0, o);
                        func_L03_003C21A0(o + 0x10, 10);
                        func_L01_00451F60(0x12A9, 417, 0);
                        D_00142792[0] = 1;
                        func_0039EF28();
                        func_0039EC28(0, -1);
                        sv = (u8 *)D_001A7E18;
                        if (*(u16 *)(sv + 0xC540) == 0) {
                            func_L01_0041A5B0(0x1070, 0xDF);
                        }
                        *(s32 *)(o + 0x98) = 0;
                        *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
                        func_L01_004AA7E8(o, 1);
                    kill:
                        func_003C2880(o);
                    }
                }
            } else if (o[0x20] == 0 && o[0x42] == 3 && o[0x43] < 5) {
                return;
            } else {
                return;
            }
        } else if (o[0x20] == 0) {
            o[0x20] = 1;
            if (D_00142792[0] == 0) {
                *(s32 *)(o + 0x98) = 0;
                *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
                func_L01_004AA7E8(o, 1);
            } else {
                *(f32 *)(o + 0xF4) = func_0038DAB8(*(f32 *)(o + 0xF4), 1.5707964f);
                *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) + 0.35f;
                *(u16 *)(o + 0x34) &= 0xFFBE;
                *(u16 *)(o + 0x34) |= *(u16 *)(*(u8 **)(o + 0x24) + 0x44) & 0x1000;
                *(s32 *)(o + 0x98) = *(s32 *)(*(u8 **)(o + 0x24) + 0x10);
            }
        }
    }
}
/* localdecomp:end func_L03_003C1CF8 */
