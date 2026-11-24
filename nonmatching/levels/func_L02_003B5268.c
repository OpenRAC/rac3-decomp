/* b39-w10 (2026-11-24): 7 raw differences (was 184) with --mode S --as ps2as: a dead third test at the end of chain 2,
 * `else if (o[0x20] == 0 && A && B) { return; } else { return; }` (three conjuncts, the state compare first, compared
 * with 0, both arms identical). It leaves the zero_extend of the second `== 2` test with two uses at combine time, so its
 * `andi` survives, and jump2 deletes the test afterwards (sonnet-b29-nm3's mechanism). Left: only the registers of the
 * first extension and the raw copy (ours $v1/$a0, retail $a0/$a1) and the slot/join andi that read them. */
/* PAL near miss. Port of the closest func_L03_003C77A0 draft using the
 * data and callee names of the level 02 retail code. Compile in the
 * L02_003B4A98.c context for its declarations and function types.
 * check.py --mode S --as ps2as reports 184 raw differences in both
 * placements (02 and 03); 11/17 aligned with branch displacements ignored.
 * The older level 03 functional draft reported 282 raw. The compiler
 * still folds the state-2 mask into the compare. State locals, masks,
 * signedness and typed accesses did not recover the missing andi.
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L02_003B5268 */
typedef struct {
    u8 pad0[0x80];
    vu0_v4 f80;
    vu0_v4 f90;
    u8 padA0[0x1DC - 0xA0];
    s16 f1DC;
    u8 pad1DE[0xC08 - 0x1DE];
    u32 fC08;
} Hero_3C4A08;

extern u8 D_001A4BE0[];
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern f32 D_L02_001DDF10;
__asm__(".extern D_L02_001DDF10, 4");
extern s32 D_L02_001DE2DC;
__asm__(".extern D_L02_001DE2DC, 4");
extern u8 D_00142790[];
__asm__(".extern D_00142790, 16");
extern f32 D_L02_001E8060[];
__asm__(".extern D_L02_001E8060, 16");
extern s32 D_L02_001DE6B8;
__asm__(".extern D_L02_001DE6B8, 16");
extern u8 D_001A4C60[];
extern u16 D_001A7E18[];

extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern f32 func_00382538(void);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_L02_003B4D68(u8 *);
extern f32 func_0038DAB8(f32, f32);
extern void func_L02_003B4A98(S_003BE830 *);
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);
extern void func_003A1798(void);
extern void func_L02_003B5060(O_003B5060 *);
extern s32 func_00382468(s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern s32 func_0038CAD0(void *);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_003EB5E0(s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L02_003B5710(f32 *, s32);
extern void func_L01_00451F60(s32, s32, s32);
extern void func_0039EF28(void);
extern s32 func_0039EC28(s32, s32);
extern void func_L01_0041A5B0(s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C2880(void *);

void func_L02_003B5268(u8 *o) {
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
                if (D_00142790[0] != 0) {
                    goto kill;
                }
                *(vu0_v4 *)(st + 0x20) = *(vu0_v4 *)(o + 0x10);
                *(f32 *)(st + 0x2C) = *(f32 *)(o + 0xF8);
                v0 = *(vu0_v4 *)(o + 0x10);
                v10 = *(vu0_v4 *)(o + 0x10);
                v10.z += 1.0f;
                v0.z -= 1.0f;
                if (func_003D3CB0(&v10, &v0, 2, o, 0) != 0) {
                    *(f32 *)(o + 0x18) = D_L02_001E8060[2] + 0.5f;
                }
                *(f32 *)(o + 0xF0) = func_00382538();
                *(f32 *)(o + 0xF4) = func_00382538();
                *(f32 *)(o + 0xF8) = func_00382538();
                *(f32 *)(o + 0xFC) = func_00382538();
                *(f32 *)(st + 8) = *(f32 *)(o + 0x18);
                func_L01_004450F0(o, 1, -1);
            } else if (o[0x20] == 1) {
                if (func_0038CF00(D_001A4C60, o + 0x10) <= D_L02_001DDF10) {
                    func_L02_003B4D68(o);
                }
            }
            if (o[0x20] == 1) {
                *(f32 *)(o + 0xF0) = func_0038DAB8(*(f32 *)(o + 0xF0), 0.041887905f);
                *(f32 *)(o + 0xF4) = func_0038DAB8(*(f32 *)(o + 0xF4), 0.013962635f);
                *(f32 *)(o + 0xF8) = func_0038DAB8(*(f32 *)(o + 0xF8), 0.0069813174f);
                *(f32 *)(o + 0xFC) = func_0038DAB8(*(f32 *)(o + 0xFC), 0.03141593f);
                func_L02_003B4A98((S_003BE830 *)o);
                func_L01_0044EAE0(o, st, st + 4, 0.25f, 0.02792527f, *(f32 *)(st + 8));
                *(u16 *)(o + 0x96) = 0;
            } else if (o[0x20] == 2) {
                if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58) {
                    func_003A1798();
                }
                one = 1;
                D_L02_001DE6B8 = one;
                ((Hero_3C4A08 *)D_001A4BE0)->f1DC = 3;
                func_L02_003B5060((O_003B5060 *)o);
                *(vu0_v4 *)(o + 0x10) = ((Hero_3C4A08 *)D_001A4BE0)->f80;
                *(vu0_v4 *)(o + 0xF0) = ((Hero_3C4A08 *)D_001A4BE0)->f90;
                if (o[0x42] == one) {
                    if (func_00382468(10) == 0) {
                        func_L02_003B4A98((S_003BE830 *)o);
                    }
                    if (o[0x60] & 2) {
                        if (o[0x43] != 0) {
                            func_003C3A10(o, 0, 0, 0);
                        }
                        o[0x31] = 0;
                        *(u16 *)(o + 0x34) |= 1;
                        for (i = 3; i >= 0; i--) {
                            func_L02_003B4A98((S_003BE830 *)o);
                        }
                    }
                }
                if (((Hero_3C4A08 *)D_001A4BE0)->fC08 & 2) {
                    func_L01_0050FB40(0, 0, 25.0f);
                }
                if (o[0x42] == 0) {
                    if (func_0038CAD0(st + 0x7C) != 0) {
                        D_L02_001DE2DC = 0;
                        func_L01_004F50C8(&((Hero_3C4A08 *)D_001A4BE0)->f80, &((Hero_3C4A08 *)D_001A4BE0)->f90, 0, 0);
                        func_L01_003EB5E0(0, 0);
                        func_003A52A0(0, 0, o);
                        func_L02_003B5710((f32 *)(o + 0x10), 10);
                        func_L01_00451F60(0x12A7, 417, 0);
                        D_00142790[0] = 1;
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
            if (D_00142790[0] == 0) {
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
/* localdecomp:end func_L02_003B5268 */
