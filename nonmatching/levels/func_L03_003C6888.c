/* NTSC-U draft (Claude wave K): C of func_L03_003C4A08, the NTSC-U twin of func_L03_003C6888, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L03_003C4A08", whose code is not the PAL one).
 * Worker's note: structure and bytes match except 17 of 296 instructions (aligned score; check_native raw count is 100+ only because of one shifted row). Needs @ps2as (ori float literals; PAL line lacks it) so cannot land without a flags change. Blockers: (1) first dispatch: ...
 */
#include "common.h"

#include "vu0.h"

/* localdecomp:start func_L03_003C4A08 */
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
extern f32 D_001DEE40_sda;
__asm__(".extern D_001DEE40_sda, 4");
extern s32 D_001DF35C_sda;
__asm__(".extern D_001DF35C_sda, 4");
extern u8 D_00142797[];
__asm__(".extern D_00142797, 16");
extern f32 D_L03_001E92A8[];
__asm__(".extern D_L03_001E92A8, 16");
extern s32 D_L03_001DF738;
__asm__(".extern D_L03_001DF738, 16");
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

extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern f32 func_0037E2A8(void);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_003887C8(void *, void *);
extern void func_L03_003C4508(u8 *);
extern f32 func_00389380(f32, f32);
extern void func_L03_003C4250(u8 *);
extern void func_L01_0044B860(void *, void *, void *, f32, f32, f32);
extern void func_0039C710(void);
extern void func_L03_003C4800(u8 *);
extern s32 func_0037E1D8(s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_0050BB98(s32, s32, f32);
extern s32 func_00388398(void *);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_L01_003E9730(s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L03_003C4EA8(void *, s32);
extern void func_L01_0044ECE0(s32, s32, s32);
extern void func_00399F90(void);
extern void func_00399C90(s32, s32);
extern void func_L01_00417F60(s32, s32);
extern void func_L01_004A6DF8(void *, s32);
extern void func_003BD360(void *);

void func_L03_003C4A08(u8 *o) {
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
                if (func_003CE740(&v10, &v0, 2, o, 0) != 0) {
                    *(f32 *)(o + 0x18) = D_L03_001E92A8[0] + k;
                }
                *(f32 *)(o + 0xF0) = func_0037E2A8();
                *(f32 *)(o + 0xF4) = func_0037E2A8();
                *(f32 *)(o + 0xF8) = func_0037E2A8();
                *(f32 *)(o + 0xFC) = func_0037E2A8();
                *(f32 *)(st + 8) = *(f32 *)(o + 0x18);
                func_L01_00441FB8(o, 1, -1);
            } else if (o[0x20] == 1) {
                if (func_003887C8(D_001A4C60, o + 0x10) <= D_001DEE40_sda) {
                    func_L03_003C4508(o);
                }
            }
            if (o[0x20] == 1) {
                *(f32 *)(o + 0xF0) = func_00389380(*(f32 *)(o + 0xF0), 0.03490659f);
                *(f32 *)(o + 0xF4) = func_00389380(*(f32 *)(o + 0xF4), 0.011635529f);
                *(f32 *)(o + 0xF8) = func_00389380(*(f32 *)(o + 0xF8), 0.0058177644f);
                *(f32 *)(o + 0xFC) = func_00389380(*(f32 *)(o + 0xFC), 0.026179941f);
                func_L03_003C4250(o);
                func_L01_0044B860(o, st, st + 4, 0.25f, 0.023271058f, *(f32 *)(st + 8));
                *(u16 *)(o + 0x96) = 0;
            } else if (o[0x20] == 2) {
                if (D_001CCFD0.f76 == 0 && D_001CCFD0.f9E == 3 && D_001CCFD0.f98 < 0x1B58) {
                    func_0039C710();
                }
                one = 1;
                D_L03_001DF738 = one;
                D_001A4BE0.f1DC = 3;
                func_L03_003C4800(o);
                *(vu0_v4 *)(o + 0x10) = D_001A4BE0.f80;
                *(vu0_v4 *)(o + 0xF0) = D_001A4BE0.f90;
                if (o[0x42] == one) {
                    if (func_0037E1D8(10) == 0) {
                        func_L03_003C4250(o);
                    }
                    if (o[0x60] & 2) {
                        if (o[0x43] != 0) {
                            func_003BE4F0(o, 0, 0, 0);
                        }
                        o[0x31] = 0;
                        *(u16 *)(o + 0x34) |= 1;
                        for (i = 3; i >= 0; i--) {
                            func_L03_003C4250(o);
                        }
                    }
                }
                if (D_001A4BE0.fC08 & 2) {
                    func_L01_0050BB98(0, 0, 30.0f);
                }
                if (o[0x42] == 0) {
                    if (func_00388398(st + 0x7C) != 0) {
                        D_001DF35C_sda = 0;
                        func_L01_004F12C0(&D_001A4BE0.f80, &D_001A4BE0.f90, 0, 0);
                        func_L01_003E9730(0, 0);
                        func_0039FE80(0, 0, o);
                        func_L03_003C4EA8(o + 0x10, 10);
                        func_L01_0044ECE0(0x12AE, 500, 0);
                        D_00142797[0] = 1;
                        func_00399F90();
                        func_00399C90(0, -1);
                        sv = (u8 *)D_001A7E18;
                        if (*(u16 *)(sv + 0xC540) == 0) {
                            func_L01_00417F60(0x1070, 0xDF);
                        }
                        *(s32 *)(o + 0x98) = 0;
                        *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
                        func_L01_004A6DF8(o, 1);
                    kill:
                        func_003BD360(o);
                    }
                }
            }
        } else if (o[0x20] == 0) {
            o[0x20] = 1;
            if (D_00142797[0] == 0) {
                *(s32 *)(o + 0x98) = 0;
                *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
                func_L01_004A6DF8(o, 1);
            } else {
                *(f32 *)(o + 0xF4) = func_00389380(*(f32 *)(o + 0xF4), 1.5707964f);
                *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) + 0.35f;
                *(u16 *)(o + 0x34) &= 0xFFBE;
                *(u16 *)(o + 0x34) |= *(u16 *)(*(u8 **)(o + 0x24) + 0x44) & 0x1000;
                *(s32 *)(o + 0x98) = *(s32 *)(*(u8 **)(o + 0x24) + 0x10);
            }
        }
    }
}
/* localdecomp:end func_L03_003C4A08 */
