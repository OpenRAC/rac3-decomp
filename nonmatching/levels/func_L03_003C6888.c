/* PAL port of the NTSC-U draft (Sonnet worker b15-z4, 2026-11-18): PAL names, constants and gp slots done; needs @ps2as and -mvu0-use-vf0-vf2 on the file line. */
/* NM-R7 (2026-11-22): 213 differences (tools/check.py, level 03, the file's line), 68 with -mvu0-use-vf0-vf2 @ps2as. Why the `== 2` andi is missing (combine's nonzero_bits on the gcse copy of o[0x20]): nonmatching/README.md. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003C6888 */
typedef struct {
    u8 pad0[0x80];
    vu0_v4 f80;
    vu0_v4 f90;
    u8 padA0[0x1DC - 0xA0];
    s16 f1DC;
    u8 pad1DE[0xC08 - 0x1DE];
    u32 fC08;
} Hero_3C4A08;

extern Hero_3C4A08 D_001A4BE0;
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern f32 D_001DEE00_sda;
__asm__(".extern D_001DEE00_sda, 4");
extern s32 D_001DF2DC_sda;
__asm__(".extern D_001DF2DC_sda, 4");
extern u8 D_00142797[];
__asm__(".extern D_00142797, 16");
extern f32 D_L03_001E9228[];
__asm__(".extern D_L03_001E9228, 16");
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
} S_001CCFD0;
extern S_001CCFD0 D_001CCFD0;
extern u16 D_001A7E18[];

extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern f32 func_00382538(void);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_L03_003C6388(u8 *);
extern f32 func_0038DAB8(f32, f32);
extern void func_L03_003C60B8(u8 *);
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);
extern void func_003A1798(void);
extern void func_L03_003C6680(u8 *);
extern s32 func_00382468(s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern s32 func_0038CAD0(void *);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_003EB5E0(s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L03_003C6D28(void *, s32);
extern void func_L01_00451F60(s32, s32, s32);
extern void func_0039EF28(void);
extern void func_0039EC28(s32, s32);
extern void func_L01_0041A5B0(s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C2880(void *);

void func_L03_003C6888(u8 *o) {
    u8 *st;
    u8 *sv;
    vu0_v4 v0;
    vu0_v4 v10;
    f32 k;
    s32 i;
    s32 one;

    st = *(u8 **)(o + 0x68);
    if (st != 0) {
        if (D_001D545C_sda != 3) {
            if (o[0x20] == 0) {
                if (D_00142797[0] != 0) {
                    goto kill;
                }
                k = 1.0f;
                *(vu0_v4 *)(st + 0x20) = *(vu0_v4 *)(o + 0x10);
                *(f32 *)(st + 0x2C) = *(f32 *)(o + 0xF8);
                v0 = *(vu0_v4 *)(o + 0x10);
                v10 = *(vu0_v4 *)(o + 0x10);
                v10.z += k;
                v0.z -= k;
                if (func_003D3CB0(&v10, &v0, 2, o, 0) != 0) {
                    *(f32 *)(o + 0x18) = D_L03_001E9228[0] + k;
                }
                *(f32 *)(o + 0xF0) = func_00382538();
                *(f32 *)(o + 0xF4) = func_00382538();
                *(f32 *)(o + 0xF8) = func_00382538();
                *(f32 *)(o + 0xFC) = func_00382538();
                *(f32 *)(st + 8) = *(f32 *)(o + 0x18);
                func_L01_004450F0(o, 1, -1);
            } else if (o[0x20] == 1) {
                if (func_0038CF00(D_001A4C60, o + 0x10) <= D_001DEE00_sda) {
                    func_L03_003C6388(o);
                }
            }
            if (o[0x20] == 1) {
                *(f32 *)(o + 0xF0) = func_0038DAB8(*(f32 *)(o + 0xF0), 0.041887905f);
                *(f32 *)(o + 0xF4) = func_0038DAB8(*(f32 *)(o + 0xF4), 0.013962635f);
                *(f32 *)(o + 0xF8) = func_0038DAB8(*(f32 *)(o + 0xF8), 0.0069813174f);
                *(f32 *)(o + 0xFC) = func_0038DAB8(*(f32 *)(o + 0xFC), 0.03141593f);
                func_L03_003C60B8(o);
                func_L01_0044EAE0(o, st, st + 4, 0.25f, 0.02792527f, *(f32 *)(st + 8));
                *(u16 *)(o + 0x96) = 0;
            } else if (o[0x20] == 2) {
                if (D_001CCFD0.f76 == 0 && D_001CCFD0.f9E == 3 && D_001CCFD0.f98 < 0x1B58) {
                    func_003A1798();
                }
                one = 1;
                D_L03_001DF6B8 = one;
                D_001A4BE0.f1DC = 3;
                func_L03_003C6680(o);
                *(vu0_v4 *)(o + 0x10) = D_001A4BE0.f80;
                *(vu0_v4 *)(o + 0xF0) = D_001A4BE0.f90;
                if (o[0x42] == one) {
                    if (func_00382468(10) == 0) {
                        func_L03_003C60B8(o);
                    }
                    if (o[0x60] & 2) {
                        if (o[0x43] != 0) {
                            func_003C3A10(o, 0, 0, 0);
                        }
                        o[0x31] = 0;
                        *(u16 *)(o + 0x34) |= 1;
                        for (i = 3; i >= 0; i--) {
                            func_L03_003C60B8(o);
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
                        func_L03_003C6D28(o + 0x10, 10);
                        func_L01_00451F60(0x12AE, 417, 0);
                        D_00142797[0] = 1;
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
            }
        } else if (o[0x20] == 0) {
            o[0x20] = 1;
            if (D_00142797[0] == 0) {
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
/* localdecomp:end func_L03_003C6888 */
