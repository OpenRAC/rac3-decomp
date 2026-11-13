#include "common.h"

/* NTSC-U counterpart of func_L04_00504520 (src/levels/04_marcadia/L04_00504520.c) */
/* localdecomp:start func_L04_005003D0 */
/* func_L04_005003D0: Marcadia's per-frame hero state machine (family A1 member, docs/prep/FAMILIES.md),
   a 178-way switch on the state at D_001A4BE0+0x25C4 (Opus family A, 2026-11-08): the root
   func_L08_004D6580 (src/levels/08_aquatos/L08_004D6580.c) ported by alignment, plus the states
   Marcadia has and Aquatos lacks, written from retail (0x8F/0x90, 0x23, 0x24, 0x25, 0x2B, 0xB0,
   0x6A, 0x7D, 0x37 and the 0x2C block of case 0x6/0x2C); without the root's case 0 0x25EA call
   and case 0x2 0x1476 flag block, which Marcadia lacks.
   Build needs: "-mvu0-use-vf0-vf2 ... @ps2as" on this file, its config/levels/divs_nops.txt row
   and include/vu0.h (vadd/vsub.xyz, qzero(), fabs_asm() at every abs.s, sqrt_asm() at both sqrt.s
   of case 0x2B). The level's hero tunables are one small-data array (docs/GLOBALS.md). v40 is one
   0x40-byte local (retail's frame is 0x1B0; 0x2B passes it to func_00388BF0 as a matrix).
   Beyond the root's fixes (its header lists them):
   - 0x6/0x2C and 0xB0 name their velocity vector the same way, D_001A4BE0 + 0xF0. Retail
     cross-jumps 0x6's tail into 0xB0's from the c.lt.s: jump2 merges two argument moves whose
     REG_EQUAL constants are equal and rewrites both into the constant (the `la`), so the two cases'
     constants must be written alike; with D_001A4CD0 in one of them only the jal merges.
   - case 0x24's angle as a local, 0x6A's compare operands, 0x14's stack slots and 0x2B's limit read
     through a struct (in-struct MEMs do not alias the stack scalar, so sched2 moves its store into
     the bc1f delay slot as retail does). */
typedef int u128_t __attribute__((mode(TI)));
typedef union { u8 b[0x2600]; s8 c[0x2600]; s16 h[0x1300]; u16 uh[0x1300]; s32 i[0x980]; u32 u[0x980]; f32 f[0x980]; void *ptr[0x980]; long d[0x4C0]; u128_t q[0x260]; } Hero;
typedef struct { s32 x0[7]; s32 x1C; u8 x20[0xC0]; } LevelInfo;
typedef struct { s32 w[11]; } Rec2C;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
extern void func_L01_00443648(s32, f32, s32, s32, f32, f32, s32, s32, s32);
extern void func_L04_004FCBA8(void);
extern Hero *D_001D52FC;
extern u8 D_001A30B0[];
extern char D_001A4BE0[];
extern char D_001A4CD0[];
extern char D_001A7C10[];
extern u8 D_001A7F08[];
extern u32 D_001D4C38;
extern s32 D_001D545C;
extern u8 D_00142CAD[];
extern u8 D_001439F4[];
extern u8 D_00142CBA[];
extern s32 D_L04_001D673C_005003D0;
extern s32 D_L04_001DF9C0;
extern s32 D_L04_001E0E90;
extern s32 D_L04_001E0E98;
extern u8 D_L04_001E28C0[];
extern u8 D_L04_001E28D8[];
extern u8 D_L04_001ED680[];
extern u8 D_L04_002F4E00[];
extern Rec2C D_L04_002F6B90[];
extern u8 D_L04_002F6EB0[];
extern s32 func_003CE740(s32, s32, s32, s32, s32);
extern s32 func_003CF790(s32, s32, f32, s32, s32);
extern s32 func_00388398(s32);
extern s32 func_003883C8(s32);
extern void func_L01_004F0928(f32);
extern void func_003888C8(s32, s32, s32);
extern void func_003886E8(s32, s32, f32);
extern void func_00388758(s32, s32, s32);
extern f32 func_00388770(s32);
extern f32 func_003887A0(s32);
extern f32 func_00388800(s32, s32);
extern f32 func_003887C8(s32, s32);
extern void func_00388830(s32, s32, f32);
extern void func_00388880(s32, s32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388A28(f32, f32);
extern void func_00388BF0(s32, s32);
extern void func_00388E78(s32, s32);
extern void func_003888F0(s32, s32, s32);
extern s32 func_L01_00443080(f32 *, f32 *, f32, f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389468(f32, f32);
extern void func_003BDA38(s32, s32, s32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00443628(s32, s32, s32, f32, s32);
extern void func_L01_00443938(s32, s32, s32, s32, s32, f32);
extern f32 func_003BEBF8(s32, f32, f32);
extern f32 func_L01_00445168(s32, s32, f32, f32, f32, f32);
extern f32 func_L01_00445208_005003D0(s32, s32, s32, f32, f32, f32);
extern f32 func_L01_004454A8(s32, f32, f32);
extern void func_L01_00445558(s32, s32, f32, f32);
extern f32 func_L01_004455F0(s32, f32, s32, f32, f32, f32, s32);
extern s32 func_003BF5E0(s32);
extern void func_003BF640(s32, f32);
extern void func_0037E4B8(s32, f32, f32, f32);
extern s32 func_L01_00465020(s32, s32, f32, f32, s32);
extern void func_0039FB08(s32);
extern void func_L01_004C2BF8(s32, s32, void *, f32, f32, f32, f32);
extern void func_L01_004E1168(s32, s32, f32);
extern void func_L01_004E1268(f32, f32, f32, f32);
extern f32 func_L01_004E1368(s32, s32);
extern void func_L01_004E14C8(f32, f32, f32);
extern void func_L01_004E1980(s32, s32);
extern void func_L01_004E1A78(s32, s32);
extern void func_L01_004E1C58(s32, s32);
extern void func_L01_004E1E40(s32, s32, s32);
extern void func_L01_004E20F0(s32, s32, s32);
extern void func_L01_004E25C8(f32, f32);
extern void func_L01_004E25E0(f32, f32);
extern void func_L01_004E25F8(f32, f32);
extern void func_L01_004E2610(f32, f32);
extern void func_L01_004E39B8(void);
extern s32 func_L01_004E5470(s32);
extern s32 func_L01_0045D358(s32, s32, s32, s32);
extern void func_L04_00508950(s32, s32);
extern void func_L01_004F1CE0(void);
extern void func_L01_004F1A08(void);

extern void func_L01_004EA628(void);
extern s32 func_L01_004EAA20(f32);
extern void func_L01_004EAA78(f32, s32);
extern void func_L04_004F9C78(void);
extern void func_L01_004EAEC0(f32, f32, f32);
extern void func_L01_004EAFF8(s32, f32, f32, f32);
extern void func_L01_004EB0E8(void);
extern void func_L01_004EB350(f32, f32);
extern void func_L01_004EB3A0(f32);
extern void func_L01_004EB460(s32);
extern void func_L01_004EB490(void);
extern void func_L01_004EC780(f32, f32);
extern f32 func_L01_004EC818(s32);
extern void func_L04_004FC178(f32);
extern void func_L01_004ED860(void);
extern void func_L01_004EEA78(f32, f32, f32);
extern void func_L01_004EF060(void);
extern void func_L01_004EFDD8(void);
extern void func_L01_004F0138(void);
extern f32 func_L01_004F1018(s32, s32);
extern s32 func_L01_004F1068(s32, s32);
extern void func_L01_004F1110(s32, s32, s32);
extern s32 func_L01_004F14D8(f32, f32, f32);
extern s32 func_L01_0050DA08(s32);
extern void func_L01_00501458(void);
extern s32 func_L01_00503310(void);
extern void func_L01_0050BB98(s32, s32, f32);
extern void func_L01_0050CF30(s32, s32, f32);
extern void func_L01_0050D110(s32, s32, f32, f32, f32);
extern void func_L01_0050D180(s32, s32, f32);
extern void func_L01_0050D1A0(s32, s32, f32);
extern void func_L01_0050D2A8(s32, s32, f32);
extern void func_L01_0050D348(s32, s32);
extern f32 func_L01_0050D430(s32);
extern f32 func_L01_0050D4D8(s32);
extern void func_L01_0050D530(s32, s32, f32);
extern void func_L01_0050D5B0(s32, s32, f32);
extern s32 func_L01_003EFFE0(s32, s32);
extern s32 func_L01_0040C1F8(s32, s32, f32);
extern void func_L01_0044B1E0(s32, s32);
extern void func_L01_0044C900(s32, s32, f32, f32, f32);
extern f32 func_L01_0045D488(s32, s32);
extern s32 func_L01_004E4550(s32, s32, s32);
extern f32 D_L04_002F0400[];
extern f32 D_L04_001DBCC4[] __attribute__((section(".sdata")));
extern s32 D_L04_001D66B0_005003D0[2];
extern f32 func_00388730(s32, s32);
extern void func_L01_004EF060(void);
extern void func_L01_004EFDD8(void);

extern f32 D_L04_001DA480[];
extern s32 func_L04_004EBEA0(s32);
extern void func_L01_004EB5D0(s32);

#include "vu0.h"


void func_L04_005003D0(void) {
    f32 v0[4] __attribute__((aligned(16)));
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));
    f32 v30[4] __attribute__((aligned(16)));
    f32 v40[16] __attribute__((aligned(16)));
    s32 lim;
    s32 lim2;

    s32 sp114;
    s32 sp118;
    f32 temp_f0;
    f32 var_f12;
    f32 var_f12_4;
    f32 var_f1;
    f32 var_f20;
    s32 temp_a0_3;
    s32 var_a0_2;
    u32 temp_v1;
    u32 temp_v1_3;
    u8 temp_a0_2;
    void* temp_a0_4;
    void* temp_fp;

    sp114 = ((Hero *)D_001A4BE0)->i[0x25C8/4];
    temp_fp = ((Hero *)D_001A4BE0)->ptr[0x25C0/4];
    sp118 = (s32) (*(u8 *)((u8 *)(temp_fp) + 0x43));
    switch (((Hero *)D_001A4BE0)->u[0x25C4/4]) {                              /* switch 1 */
    case 0x0:
    case 0x1:
    case 0x3:
    case 0x4:
    case 0x1C:
    case 0x1D:
    case 0x1E:
    case 0x39:
    case 0x72:
    case 0x74:
    case 0x82:
        func_L01_004EC780(0.5f, 0.033333335f);
        func_L01_004F14D8(3.7f, 0.0f, 0.35f);
        func_L01_004EAA78(1.0f, 0);
        temp_v1 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
        if ((temp_v1 == 1) || (temp_v1 == 0x1D)) {
            if (((Hero *)D_001A4BE0)->b[0x25E5] != 0) {
                (*(u128_t*)v0) = 0;
                v0[0] = 1.0f;
                func_003888C8((s32) (((void*)D_001A4BE0) + 0x190), (s32)((u128_t*)v0), (s32)&D_L04_001E28D8[0x368]);
                ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_L04_001E28D8)->f[0];
                func_L01_004EAFF8(0, 1.0f, 0.0f, 2.9088824f);
                if ((((Hero *)D_001A4BE0)->b[0x25EC] != 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] == 120)) {
                    if (((Hero *)D_001A7C10)->uh[0xD8/2] < 0xFFFF) {
                        ((Hero *)D_001A7C10)->uh[0xD8/2]++;
                    }
                    lim = (s32)D_001D4C38;
                    if (((Hero *)D_001A7C10)->u[0xDC/4] < lim) {
                        ((Hero *)D_001A7C10)->u[0xDC/4] = lim;
                    }
                    ((Hero *)D_001A7C10)->u[0xE0/4] = ((Hero *)D_001A7C10)->u[0xE0/4] | (1 << D_001D545C) | 0x80000000;
                }
            }
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 3) {
            if (func_L01_00503310() != 0) {
                break;
            }
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 4) {
            if ((((Hero *)D_001A4BE0)->f[0x2838/4] > 0.2f) || (temp_a0_2 = (*(u8 *)((u8 *)(((Hero *)D_001A4BE0)->ptr[0x25C0/4]) + 0x43)), (temp_a0_2 == 0xE)) || (temp_a0_2 == 0xF)) {
                if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 4) {
                    func_L01_004EAFF8(0, 0.002f, 0.07f, 0.1658063f);
                }
                if (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A4/4]) > 0.0058177644f) {
                    temp_a0_3 = ((Hero *)D_001A4BE0)->f[0x1A4/4] < 0.0f;
                    temp_a0_3 += 0xE;
                    if ((*(u8 *)((u8 *)(((Hero *)D_001A4BE0)->ptr[0x25C0/4]) + 0x43)) != temp_a0_3) {
                        func_L01_0050BB98(temp_a0_3, 0, 5.0f);
                    }
                    temp_f0 = fabs_asm(((Hero *)D_001A4BE0)->f[0x1A4/4]) / 0.055268764f;
                    ((Hero *)D_001A4BE0)->f[0xC00/4] = temp_f0;
                    if (temp_f0 < 0.55f) {
                        ((Hero *)D_001A4BE0)->f[0xC00/4] = 0.55f;
                    }
                    if (((Hero *)D_001A4BE0)->f[0xC00/4] > 2.5f) {
                        ((Hero *)D_001A4BE0)->f[0xC00/4] = 2.5f;
                    }
                } else if (((Hero *)D_001A4BE0)->f[0x1A4/4] == 0.0f) {
                    if ((*(u8 *)((u8 *)(((Hero *)D_001A4BE0)->ptr[0x25C0/4]) + 0x43)) != 0xD) {
                        func_L01_0050BB98(0xD, 0, 7.0f);
                    }
                }
            }
        }
            temp_v1_3 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
            if (temp_v1_3 == 3) {
                var_f12 = ((Hero *)D_001A4BE0)->f[0x17C/4] + 1.0f;
                if (var_f12 > 1.0f) {
                    var_f12 = 1.0f;
                }
                temp_a0_4 = ((Hero *)D_001A4BE0)->ptr[0x25C0/4];
                var_f20 = var_f12 * 0.0075000003f;
                ((Hero *)D_001A4BE0)->f[0x282C/4] = var_f20;
                if ((*(u8 *)((u8 *)(temp_a0_4) + 0x42)) == (*(u8 *)((u8 *)(temp_a0_4) + 0x43))) {
                    var_f1 = ((Hero *)D_001A4BE0)->f[0x174/4] / var_f20;
                    if ((var_f1 > 5.0f) && ((f32) (*(u8 *)((u8 *)(temp_a0_4) + 0x41)) < 5.5f)) {
                        func_L01_004E1268(13.0f, var_f1, 0.5f, -1.0f);
                        if (((Hero *)D_001A4BE0)->f[0xC00/4] > 1.1f) {
                            ((Hero *)D_001A4BE0)->f[0xC00/4] = 1.1f;
                        }
                    } else if ((f32) (*(u8 *)((u8 *)(((Hero *)D_001A4BE0)->ptr[0x25C0/4]) + 0x41)) > 6.5f) {
                        ((Hero *)D_001A4BE0)->f[0xC00/4] = 1.0f;
                    }
                }
            } else {
                var_f20 = (temp_v1_3 == 4) ? 0.0075000003f : 0.004916667f;
            }
            func_L01_004EB350(0.0f, var_f20);
            qzero((V4 *)(D_001A4BE0 + 0xF0));
            func_L01_004F0928(var_f20);
            if ((((Hero *)D_001A4BE0)->b[0x1479] != 0) && (D_00142CAD[0] != 0)) {
                var_a0_2 = (s32)(D_001A4BE0 + 0xF0);
                if (((Hero *)D_001A4BE0)->f[0x33C/4] > 0.2f) {
                    func_L01_0050CF30(var_a0_2, var_a0_2 + 0x30, 0.0061111115f);
                } else {
                    func_L01_0050CF30((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.015000001f);
                    if (((Hero *)D_001A4BE0)->i[0x35C/4] != 0) {
                        *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x80/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x2F0/16]);
                        ((Hero *)D_001A4BE0)->f[0x33C/4] = 0.0f;
                        ((Hero *)D_001A4BE0)->h[0x36E/2] = 0;
                    }
                }
            } else {
                func_L01_004EB5D0(0);
                if (((Hero *)D_001A4BE0)->h[0x36E/2] == 0) {
                    func_L01_0050CF30((s32) ((void*)D_001A4BE0) + 0xF0, (s32) ((void*)D_001A4BE0) + 0xF0, 0.015000001f);
                } else {
                    func_L01_0050CF30((s32) ((void*)D_001A4BE0) + 0xF0, (s32) ((void*)D_001A4BE0) + 0x130, 0.0069444445f);
                    func_L01_004EB490();
                }
            }
        break;
    case 0x32:
    case 0x33:
    case 0x34:
        {
        f32 turn;
        s32 st32;
        f32 spE0;
        f32 m;
        f32 sp;
        f32 h94;
        f32 dh;
        f32 yaw;
        f32 roll;
        s32 a;
        s32 b;
        s32 tA2;
        void *obj;
        s32 i;
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x34) {
            if (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 0x47) {
                (*(u16*)&D_001A7F08) = 0xFFFF;
            }
            func_L01_004F1110(5, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0xF);
            func_L01_003EFFE0(0x16, 0);
        } else {
            {
            s32 t27A0 = ((Hero *)D_001A4BE0)->i[0x27A0/4];
            if (t27A0 != -1) {
                u8 *o = (u8 *)D_001A30B0 + (t27A0 << 7);
                if (*(void **)(o + 0xDC) == ((Hero *)D_001A4BE0)->ptr[0x25C0/4]) {
                    if (*(u8 *)(o + 0xD0) != 0) {
                        func_0039FB08(t27A0);
                    }
                }
            }
            }
            ((Hero *)D_001A4BE0)->i[0x27A0/4] = -1;
        }
        if (((Hero *)D_001A4BE0)->h[0x9CA/2] != 0) {
            s32 t9CA;
            func_003883C8((s32) (((void*)D_001A4BE0) + 0x9CA));
            t9CA = (s32) ((u16) ((Hero *)D_001A4BE0)->h[0x9CA/2] << 0x10) >> 0x12;
            func_L01_004E1E40((t9CA >= 9) ? 8 : t9CA, 0, 0);
        }
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x32) && (((Hero *)D_001A4BE0)->i[0xC0C/4] == 0)) {
            f32 tC18 = ((Hero *)D_001A4BE0)->f[0xC18/4];
            if (tC18 > 0.0f) {
                if (tC18 < 10.0f) {
                    func_L01_004E1E40(4, 1, 0);
                }
            }
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x33) {
            if (((Hero *)D_001A4BE0)->i[0x25D0/4] == 0x34) {
                s32 t1B8 = ((Hero *)D_001A4BE0)->i[0x1B8/4];
                if (t1B8 < 0xF) {
                    func_L01_004E1E40(((s32) (0x14 - t1B8) / 3) + 1, 1, 0);
                }
            }
        }
        {
        s32 t25C8 = ((Hero *)D_001A4BE0)->i[0x25C8/4];
        if (t25C8 == 1) {
            s32 t9A0;
            if (((Hero *)D_001A4BE0)->i[0x1B8/4] == t25C8) {
                func_L01_004E20F0(3, 0x10, 0);
                if (D_L04_001E0E90 != 0) {
                    func_L01_004C2BF8(D_L04_001E0E90, D_L04_001E0E98, 0, ((Hero *)D_001A4BE0)->f[0x80/4], ((Hero *)D_001A4BE0)->f[0x84/4], 0.4f, -0.3f);
                }
                ((Hero *)D_001A4BE0)->h[0x9CA/2] = 0x46;
            }
            t9A0 = ((Hero *)D_001A4BE0)->i[0x9A0/4] + 1;
            ((Hero *)D_001A4BE0)->i[0x9A0/4] = t9A0;
            if (t9A0 >= 0x29) {
                ((Hero *)D_001A4BE0)->i[0x25C8/4] = 0;
            }
        }
        }
        {
        f32 x128;
        f32 x12C;
        f32 lo;
        var_f12_4 = 0.0f;
        turn = 0.011635529f;
        if (D_001D52FC->f[0x128/4] < D_001D52FC->f[0x12C/4]) {
            m = D_001D52FC->f[0x12C/4];
        } else {
            m = D_001D52FC->f[0x128/4];
        }
        turn += m * 0.008726647f;
        lo = 0.2f;
        if (((D_001D52FC->d[0x1A0/8] & 0xC0) == 0x80) || (((Hero *)D_001A4BE0)->i[0x25C8/4] == 1)) {
            var_f12_4 = D_001D52FC->f[0x12C/4] * 1.5f;
            if (var_f12_4 > 1.0f) {
                var_f12_4 = 1.0f;
            }
            if (var_f12_4 < lo) {
                var_f12_4 = lo;
            }
            if (D_001D52FC->i[0x1DC/4] != 0x79) {
                s32 c9C2 = ((Hero *)D_001A4BE0)->uh[0x9C2/2] + 1;
                ((Hero *)D_001A4BE0)->uh[0x9C0/2] = 0;
                var_f12_4 = (f32) (s16) c9C2 * 0.5f / 20.0f + 0.5f;
                ((Hero *)D_001A4BE0)->uh[0x9C2/2] = c9C2;
                if (var_f12_4 > 1.0f) {
                    var_f12_4 = 1.0f;
                }
            }
            if ((((Hero *)D_001A4BE0)->i[0x25C8/4] == 1) && (var_f12_4 < 0.35f)) {
                var_f12_4 = 0.35f;
            }
            var_f12_4 = var_f12_4 * 1.3613569f;
        } else if (D_001D52FC->i[0x1A0/4] & 0x40) {
            var_f12_4 = D_001D52FC->f[0x128/4] * 1.5f;
            if (var_f12_4 > 1.0f) {
                var_f12_4 = 1.0f;
            }
            if (var_f12_4 < lo) {
                var_f12_4 = lo;
            }
            if (D_001D52FC->i[0x1DC/4] != 0x79) {
                s32 c9C0 = ((Hero *)D_001A4BE0)->uh[0x9C0/2] + 1;
                ((Hero *)D_001A4BE0)->uh[0x9C2/2] = 0;
                ((Hero *)D_001A4BE0)->uh[0x9C0/2] = c9C0;
                var_f12_4 = (f32) (s16) c9C0 * 0.5f / 20.0f + 0.5f;
                if (var_f12_4 > 1.0f) {
                    var_f12_4 = 1.0f;
                }
            }
            var_f12_4 = var_f12_4 * -1.3613569f;
        } else {
            ((Hero *)D_001A4BE0)->uh[0x9C0/2] = 0;
            ((Hero *)D_001A4BE0)->uh[0x9C2/2] = 0;
        }
        }
        if (D_001D52FC->i[0x1A0/4] & 0x40) {
            ((Hero *)D_001A4BE0)->uh[0x9CE/2]++;
            if (D_001D52FC->f[0x128/4] > 0.75f) {
                s32 c9CC = ((Hero *)D_001A4BE0)->uh[0x9CC/2] + 1;
                ((Hero *)D_001A4BE0)->uh[0x9CC/2] = c9CC;
                if ((s16) c9CC >= 0x5B) {
                    if (((Hero *)D_001A7C10)->uh[0x84/2] < 0xFFFF) {
                        ((Hero *)D_001A7C10)->uh[0x84/2]++;
                    }
                }
                lim = (s32)D_001D4C38;
                if (((Hero *)D_001A7C10)->u[0x88/4] < lim) {
                    ((Hero *)D_001A7C10)->u[0x88/4] = lim;
                }
                ((Hero *)D_001A7C10)->u[0x8C/4] = ((Hero *)D_001A7C10)->u[0x8C/4] | (1 << D_001D545C) | 0x80000000;
            } else {
                ((Hero *)D_001A4BE0)->uh[0x9CC/2] = 0;
            }
        } else {
            ((Hero *)D_001A4BE0)->uh[0x9CE/2] = 0;
            ((Hero *)D_001A4BE0)->uh[0x9CC/2] = 0;
        }
        if (D_001D52FC->i[0x1A4/4] & 0x40) {
            if ((D_L04_001DF9C0 - ((Hero *)D_001A4BE0)->i[0x9D4/4]) < 0x46) {
                ((Hero *)D_001A4BE0)->i[0x9D0/4]++;
            }
            ((Hero *)D_001A4BE0)->i[0x9D4/4] = D_L04_001DF9C0;
        }
        if (((Hero *)D_001A4BE0)->h[0x9CE/2] >= 0x47) {
            ((Hero *)D_001A4BE0)->i[0x9D0/4] = 0;
        }
        if (D_001D52FC->i[0x1A0/4] & 0x80) {
            ((Hero *)D_001A4BE0)->i[0x9D0/4] = 0;
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x33) {
            var_f12_4 = 0.0f;
        }
        h94 = ((Hero *)D_001A4BE0)->f[0x94/4];
        func_L01_004455F0((s32) (D_001A4BE0 + 0x94), var_f12_4, (s32) (D_001A4BE0 + 0x9A8), 0.015f, 0.2f, turn, 0);
        dh = func_003893C8(((Hero *)D_001A4BE0)->f[0x94/4], h94);
        func_L01_004EAA78(1.0f, 0);
        func_L01_004EAFF8(0, 0.007f, 0.08f, 0.08726647f);
        ((Hero *)D_001A4BE0)->f[0x9AC/4] = ((Hero *)D_001A4BE0)->f[0x1A4/4];
        func_00388398((s32) (D_001A4BE0 + 0x9B4));
        if (((Hero *)D_001A4BE0)->i[0x25C8/4] == 1) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.10000001f;
        } else if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x34) {
            if (D_001D52FC->i[0x1A0/4] & 0xA) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.116666675f;
            } else {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.04666667f;
            }
        } else {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.050000004f;
        }
        {
        f32 sc;
        f32 lo;
        sc = ((Hero *)D_001A4BE0)->f[0x2838/4];
        if ((D_001D52FC->i[0x1A0/4] & 0xC0) || (((Hero *)D_001A4BE0)->i[0x25C8/4] == 1)) {
            if (sc < 1.0f) {
                sc = 1.0f;
            }
        }
        if (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.15f) {
            lo = 0.35f;
            if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x34) {
                lo = 0.4f;
            }
            if (sc < lo) {
                sc = lo;
            }
        }
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] != 0x34) || !(D_001D52FC->i[0x1A0/4] & 0xA)) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0x1B0/4] * sc;
        }
        }
        if (func_00388398((s32)(D_001A4BE0 + 0x9B0)) != 0) {
            Hero *h9 = (Hero *)D_001A4BE0;
            func_003BDA38((s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 4, (s32)v0);
            (*(u128_t*)v20) = 0;
            v20[0] = 0.4f;
            func_003888C8((s32)v20, (s32)v20, (s32) (((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0xC0));
            vec_add_ba((V4 *)v0, (V4 *)v0, (V4 *)v20);
            *(u128_t *)(v10) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x110/16]);
            func_00388830((s32)v20, (s32)v20, 0.025000002f);
            vec_add_ab((V4 *)v10, (V4 *)v10, (V4 *)v20);
            v10[2] += 0.033333335f;
            func_L01_00465020((s32)v0, (s32)v10, 25200.0f, -1.0f, 0x88A0A0A0);
            if ((f32) func_0037E1D8(100) < 40.0f) {
                a = 4;
                b = 11;
            } else {
                a = 0x28;
                b = 0x5A;
            }
            h9->i[0x9B0/4] = func_0037E208(a, b);
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x34) {
            if (func_003883C8((s32) (D_001A4BE0 + 0x9B8)) != 0) {
                obj = ((Hero *)D_001A4BE0)->ptr[0x12F0/4];
                if (obj != 0) {
                    if (*(s16 *)((u8 *)obj + 0xAA) == 0x261) {
                        for (i = 0; i < 4; i++) {
                            func_003BDA38((s32) obj, i % 2, (s32)v0);
                            (*(u128_t*)v20) = 0;
                            v20[0] = -0.15f;
                            func_003888C8((s32)v20, (s32)v20, (s32) (((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0xC0));
                            vec_add_ab((V4 *)v0, (V4 *)v0, (V4 *)v20);
                            v0[0] += func_0037E250(0.0f, 0.03f);
                            v0[1] += func_0037E250(0.0f, 0.03f);
                            v0[2] += func_0037E250(0.0f, 0.03f);
                            *(u128_t *)(v10) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x110/16]);
                            func_L01_0044C900((s32)v10, (s32)v10, -0.012500001f, ((Hero *)D_001A4BE0)->f[0x98/4], ((Hero *)D_001A4BE0)->f[0x94/4]);
                            ((Hero *)D_001A4BE0)->h[0x9B8/2] = (0.116666675f - ((Hero *)D_001A4BE0)->f[0x1B4/4]) / 0.116666675f * 5.0f;
                            func_L01_00465020((s32)v0, (s32)v10, func_0037E250(6300.0f, 9450.0f), -1.0f, 0x88A0A0A0);
                        }
                    }
                }
            }
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x34) {
            func_L01_004EB350(0.003611111f, 0.0022222223f);
        } else {
            func_L01_004EB350(0.0019444445f, 0.0011111111f);
        }
        yaw = func_00389380(-((Hero *)D_001A4BE0)->f[0x94/4], 0.0f);
        st32 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
        if (st32 == 0x34) {
            func_0037E4B8((s32)D_001A4BE0 + 0xF0, ((Hero *)D_001A4BE0)->f[0x1B4/4], ((Hero *)D_001A4BE0)->f[0x98/4], yaw);
        } else if (st32 == 0x32) {
            sp = ((Hero *)D_001A4BE0)->f[0x1B4/4] * func_L01_004E1368((s32)D_L04_002F6EB0, 0x1E) * 5.0f;
            if ((((Hero *)D_001A4BE0)->i[0x25D0/4] == 0x34) && (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0xF) && (sp < 0.075f)) {
                sp = 0.075f;
            }
            func_0037E4B8((s32)(D_001A4BE0 + 0xF0), sp, ((Hero *)D_001A4BE0)->f[0x98/4], yaw);
        } else if (st32 == 0x33) {
            spE0 = func_00388770((s32) (D_001A4BE0 + 0x160));
            if (((Hero *)D_001A4BE0)->i[0x25D0/4] == 0x34) {
                func_003BEBF8((s32) &spE0, 0.0f, 0.0022222223f);
            } else {
                func_003BEBF8((s32) &spE0, 0.0f, 0.0011111111f);
            }
            func_00388830((s32)(D_001A4BE0 + 0x160), (s32)(D_001A4BE0 + 0x160), spE0);
            *(u128_t *)(&((Hero *)D_001A4BE0)->q[0xF0/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x160/16]);
        }
        func_L01_004EB5D0(0);
        roll = ((Hero *)D_001A4BE0)->f[0x9AC/4] * func_00388960(yaw) * -7.0f;
        func_L01_004455F0((s32) (D_001A4BE0 + 0x90), roll, (s32) (D_001A4BE0 + 0x9A4), 0.007f, 0.17f, 0.020362176f, 0);
        func_L01_004E25E0(0.009f, 0.22f);
        func_L01_004E25F8(0.04f, 0.2f);
        func_L01_004E2610(0.02f, 0.2f);
        {
        f32 pit = dh * 47.0f;
        f32 yw;
        f32 rl;
        ((Hero *)D_L04_002F4E00)->f[0x114/4] = pit;
        ((Hero *)D_L04_002F4E00)->f[0x118/4] = roll * 1.5f;
        ((Hero *)D_L04_002F4E00)->f[0x110/4] = roll * 1.4f;
        if (pit > 0.87266463f) {
            ((Hero *)D_L04_002F4E00)->f[0x114/4] = 0.87266463f;
        } else if (pit < -0.87266463f) {
            ((Hero *)D_L04_002F4E00)->f[0x114/4] = -0.87266463f;
        }
        yw = dh * 40.0f;
        rl = roll * 1.1f;
        ((Hero *)D_L04_002F4E00)->f[0x364/4] = 0.03f;
        ((Hero *)D_L04_002F4E00)->f[0x368/4] = 0.22f;
        ((Hero *)D_L04_002F4E00)->f[0x324/4] = yw;
        ((Hero *)D_L04_002F4E00)->f[0x328/4] = rl;
        ((Hero *)D_L04_002F4E00)->f[0x414/4] = 0.03f;
        ((Hero *)D_L04_002F4E00)->f[0x418/4] = 0.22f;
        ((Hero *)D_L04_002F4E00)->f[0x3D4/4] = yw;
        ((Hero *)D_L04_002F4E00)->f[0x3D8/4] = rl;
        }
        }
        break;
    case 0x78:
        {
        s32 t78;
        t78 = 0xA - (((Hero *)D_001A4BE0)->i[0x1B8/4] / 3);
        func_L01_004E1E40((t78 >= 9) ? 8 : t78, 0, 0);
        ((Hero *)D_001A4BE0)->f[0xF8/4] = 0.0f;
        func_L01_0040C1F8((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, func_003887A0((s32)D_001A4BE0 + 0xF0) * 0.92f);
        func_L01_004EB5D0(0);
        }
        break;
    case 0x77:
        func_L01_004E1980(0xF, 0x1E);
        ((Hero *)D_001A4BE0)->f[0xF8/4] = 0.0f;
        func_L01_0040C1F8((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, func_003887A0((s32)D_001A4BE0 + 0xF0) * 0.92f);
        func_L01_004EB5D0(0);
        func_L01_00501458();
        break;
    case 0x6C:
    case 0x84:
        {
        f32 sp6C;
        s32 t6C;
        sp6C = func_00388770((s32)(D_001A4BE0 + 0x160));
        func_003BEBF8((s32)&sp6C, 0.0f, 0.0011111111f);
        func_00388830((s32)(D_001A4BE0 + 0x160), (s32)(D_001A4BE0 + 0x160), sp6C);
        *(u128_t *)(&((Hero *)D_001A4BE0)->q[0xF0/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x160/16]);
        if (func_00388398((s32)(D_001A4BE0 + 0x9B0)) == 2) {
            func_003BDA38((s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 4, (s32)v0);
            (*(u128_t*)v20) = 0;
            v20[0] = 0.4f;
            func_003888C8((s32)v20, (s32)v20, (s32) (((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0xC0));
            vec_add_ba((V4 *)v0, (V4 *)v0, (V4 *)v20);
            *(u128_t *)(v10) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x110/16]);
            func_00388830((s32)v20, (s32)v20, 0.025000002f);
            vec_add_ab((V4 *)v10, (V4 *)v10, (V4 *)v20);
            v10[2] += 0.033333335f;
            func_L01_00465020((s32)v0, (s32)v10, 25200.0f, -1.0f, 0x88A0A0A0);
            t6C = ((Hero *)D_001A4BE0)->i[0x1B8/4];
            if (t6C < 0x28) {
                ((Hero *)D_001A4BE0)->i[0x9B0/4] = func_0037E208(2, 5) + (((Hero *)D_001A4BE0)->i[0x1B8/4] / 5);
            } else if (t6C >= 0x47) {
                ((Hero *)D_001A4BE0)->i[0x9B0/4] = func_0037E208(10, 0x14);
            }
        }
        if (((Hero *)D_001A4BE0)->f[0x9BC/4] > 0.0f) {
            ((Hero *)D_001A4BE0)->f[0x9BC/4] = 0.0f;
        }
        func_003BEBF8((s32)D_001A4BE0 + 0x9BC, -0.025000002f, 0.00041666668f);
        ((Hero *)D_001A4BE0)->f[0xF8/4] = ((Hero *)D_001A4BE0)->f[0x9BC/4];
        }
        break;
    case 0x35:
    case 0x36:
        {
        s32 t35;
        f32 sp35;
        f32 v35;
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x36) {
            func_L01_004E1980(0xF, 0x1E);
        }
        if (((Hero *)D_001A4BE0)->f[0x174/4] > 0.025000002f) {
            func_L01_004E1C58(4, 0xC);
        }
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x35) && (((Hero *)D_001A4BE0)->f[0x174/4] > 0.016666668f)) {
            func_L01_004E1A78(0, 1);
        }
        if (((Hero *)D_001A4BE0)->h[0x9CA/2] != 0) {
            ((Hero *)D_001A4BE0)->h[0x9CA/2] -= 1;
            t35 = ((Hero *)D_001A4BE0)->h[0x9CA/2] >> 3;
            func_L01_004E1E40((t35 >= 7) ? 6 : t35, 0, 0);
        }
        ((Hero *)D_001A4BE0)->f[0xC00/4] = 0.6f;
        func_L01_004EAA78(0.050000004f, 0);
        if ((D_001D52FC->i[0x1D4/4] == 0) && (((Hero *)D_001A4BE0)->f[0x1B0/4] < 0.025000002f)) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.025000002f;
        }
        func_L01_004EAFF8(0, 0.007f, 0.08f, 0.08726647f);
        func_00388398((s32)(D_001A4BE0 + 0x728));
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x35) {
            if ((D_001D52FC->i[0x1D4/4] != 0) && (((Hero *)D_001A4BE0)->i[0x728/4] != 0)) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.050000004f;
            }
            if (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) > 0.7853982f) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
            }
            func_L01_004EB350(0.0011111111f, 0.0013888889f);
            sp35 = ((Hero *)D_001A4BE0)->f[0x1B4/4] * func_L01_004E1368((s32)D_L04_002F6EB0, 0x1E) * 5.5f;
            ((Hero *)D_001A4BE0)->f[0xF0/4] = func_00388960(((Hero *)D_001A4BE0)->f[0x98/4]) * sp35;
            {
            f32 w35 = func_00388978(((Hero *)D_001A4BE0)->f[0x98/4]) * sp35;
            ((Hero *)D_001A4BE0)->f[0xF8/4] = 0.0f;
            ((Hero *)D_001A4BE0)->f[0xF4/4] = w35;
            }
        } else {
            ((Hero *)D_001A4BE0)->f[0x1B4/4] = 0.0f;
            qzero((V4 *)(D_001A4BE0 + 0xF0));
        }
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x35) && (((Hero *)D_001A4BE0)->i[0xC0C/4] == 0)) {
            v35 = ((Hero *)D_001A4BE0)->f[0xC18/4];
            if ((v35 > 0.0f) && (v35 < 10.0f)) {
                func_L01_004E1E40(4, 1, 0);
            }
        }
        func_L01_004F0928(0.0011666666f);
        func_L01_004EB5D0(0);
        func_L01_00501458();
        }
        break;
    case 0x2F:
        {
        s32 anim;
        s32 blend;
        anim = -1;
        blend = 0;
        if (((Hero *)D_001A4BE0)->b[0x1474] != 0) {
            func_L01_004EC780(0.7f, 0.0f);
        } else {
            func_L01_004EC780(0.5f, 0.033333335f);
        }
        func_L01_004F14D8(3.7f, 0.0f, 0.35f);
        func_L01_004EAA78(1.0f, 0);
        func_L01_004EB350(0.004916667f, 0.004916667f);
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_L01_004F0928(0.004916667f);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_0050CF30((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0) + 0x20, 0.0069444445f);
            func_L01_004EB490();
        } else {
            func_L01_0050CF30((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.015000001f);
        }
        if ((anim != -1) && (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x42) != 0x31)) {
            func_L01_0050BB98(anim, 0, (f32) blend);
        } else if ((*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x60) & 2) && (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x42) == 0x31)) {
            func_L01_0050BB98(func_L04_004EBEA0(0), 0, 5.0f);
        }
        }
        break;
    case 0x8F:
    case 0x90:
        func_L01_004F14D8(3.7f, 0.0f, 0.35f);
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        func_L01_004EB350(0.004916667f, 0.004916667f);
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_L01_004F0928(0.004916667f);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_0050CF30((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0x120), 0.0061111115f);
            func_L01_004EB490();
        } else {
            func_L01_0050CF30((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.015000001f);
        }
        if (((Hero *)D_001A4BE0)->ptr[0xA90/4] != 0) {
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_00388A28(*(f32 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA90/4] + 0x10) - *(f32 *)((u8 *)temp_fp + 0x10), *(f32 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA90/4] + 0x14) - *(f32 *)((u8 *)temp_fp + 0x14));
            func_L01_004EAFF8(0, 0.02f, 0.15f, 0.104719765f);
        }
        break;
    case 0x23:
        func_L01_004F14D8(3.7f, 0.0f, 0.35f);
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        func_L01_004EB350(0.004916667f, 0.004916667f);
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_L01_004F0928(0.004916667f);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_0050CF30((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0x120), 0.0061111115f);
            func_L01_004EB490();
        } else {
            func_L01_0050CF30((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.015000001f);
        }
        if (((Hero *)D_001A4BE0)->ptr[0xA24/4] != 0) {
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_00388A28(*(f32 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA24/4] + 0x10) - *(f32 *)((u8 *)temp_fp + 0x10), *(f32 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA24/4] + 0x14) - *(f32 *)((u8 *)temp_fp + 0x14));
            func_L01_004EAFF8(0, 0.02f, 0.15f, 0.104719765f);
        }
        break;
    case 0x24:
        {
        f32 dist24;
        f32 yaw24;
        f32 hitE8;
        f32 hitEC;
        s32 st24;
        *(u128_t *)v0 = *(u128_t *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA24/4] + 0x10);
        dist24 = func_003887C8((s32)(D_001A4BE0 + 0x80), (s32)v0);
        ((Hero *)D_001A4BE0)->f[0xA30/4] = dist24;
        ((Hero *)D_001A4BE0)->f[0xA2C/4] = 60.0f;
        if (((Hero *)D_001A4BE0)->f[0xA20/4] > 0.0f) {
            ((Hero *)D_001A4BE0)->f[0xA2C/4] = dist24 / ((Hero *)D_001A4BE0)->f[0x170/4];
        }
        st24 = ((Hero *)D_001A4BE0)->i[0x25C8/4];
        if (st24 == 0) {
            func_003BEBF8((s32)(D_001A4BE0 + 0xA20), 0.45000002f, 0.022222223f);
            yaw24 = func_00388A28(*(f32 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA24/4] + 0x10) - *(f32 *)((u8 *)temp_fp + 0x10), *(f32 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA24/4] + 0x14) - *(f32 *)((u8 *)temp_fp + 0x14));
            if (((Hero *)D_001A4BE0)->i[0x3C0/4] != 0) {
                if (func_00389468(((Hero *)D_001A4BE0)->f[0x98/4], yaw24) > 1.5707964f) {
                    yaw24 = func_00389380(yaw24, 3.1415927f);
                }
            }
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = yaw24;
            func_L01_004EAFF8(0, 0.03f, 0.15f, 0.122173056f);
        } else if (st24 == 1) {
            func_003BEBF8((s32)(D_001A4BE0 + 0xA20), 0.0f, 0.011666667f);
        }
        if ((func_L01_00443080(&hitE8, &hitEC, -0.0058333334f, ((Hero *)D_001A4BE0)->f[0xA20/4], -(((Hero *)D_001A4BE0)->f[0xA30/4] - 1.9f)) > 0) && (hitE8 > 0.0f)) {
            ((Hero *)D_001A4BE0)->f[0xA2C/4] = hitE8;
            ((Hero *)D_001A4BE0)->i[0x25C8/4] = 1;
        }
        ((Hero *)D_001A4BE0)->h[0x226/2] = 3;
        if (((Hero *)D_001A4BE0)->f[0xA2C/4] < 20.0f) {
            ((Hero *)D_001A4BE0)->i[0xA34/4] = 1;
        }
        if (((Hero *)D_001A4BE0)->i[0xA34/4] != 0) {
            func_L01_00445558((s32)(D_001A4BE0 + 0x94), 0, 0.0f, 0.063995406f);
        } else {
            f32 a24 = func_00389380(-func_00388A28(func_00388800((s32)(D_001A4BE0 + 0x80), (s32)v0), v0[2] - ((Hero *)D_001A4BE0)->f[0x88/4]), 1.5707964f);
            func_L01_00445558((s32)(D_001A4BE0 + 0x94), 0, a24, 0.10762864f);
        }
        v20[0] = func_00388960(func_00389380(((Hero *)D_001A4BE0)->f[0x98/4], -1.5707964f)) * -0.57f;
        v20[1] = func_00388978(func_00389380(((Hero *)D_001A4BE0)->f[0x98/4], -1.5707964f)) * -0.57f;
        *(s32 *)&v20[2] = 0;
        vec_add_ba((V4 *)v20, (V4 *)v20, (V4 *)(D_001A4BE0 + 0x80));
        vec_sub_ab((V4 *)v10, (V4 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA24/4] + 0x10), (V4 *)v20);
        func_00388830((s32)(D_001A4BE0 + 0xF0), (s32)v10, ((Hero *)D_001A4BE0)->f[0xA20/4]);
        if (((Hero *)D_001A4BE0)->f[0xA2C/4] < 30.0f) {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = ((Hero *)D_001A4BE0)->f[0xF8/4] - (30.0f - ((Hero *)D_001A4BE0)->f[0xA2C/4]) * 0.008055556f;
        }
        }
        break;
    case 0x25:
        func_003BEBF8((s32)(D_001A4BE0 + 0xA3C), ((Hero *)D_001A4BE0)->f[0xA40/4], 0.16666667f);
        *(u128_t *)(D_001A4BE0 + 0xF0) = *(u128_t *)(D_001A4BE0 + 0x110);
        func_003886E8((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.9f);
        ((Hero *)D_001A4BE0)->f[0xF8/4] = ((Hero *)D_001A4BE0)->f[0xF8/4] - 0.004166667f;
        *(u128_t *)v0 = *(u128_t *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA24/4] + 0x10);
        ((Hero *)D_001A4BE0)->f[0xA30/4] = func_003887C8((s32)(D_001A4BE0 + 0x80), (s32)v0);
        vec_add_ba((V4 *)v10, (V4 *)(D_001A4BE0 + 0x80), (V4 *)(D_001A4BE0 + 0xF0));
        vec_sub_ba((V4 *)v30, (V4 *)v10, (V4 *)v0);
        func_00388830((s32)v30, (s32)v30, ((Hero *)D_001A4BE0)->f[0xA3C/4]);
        vec_add_ba((V4 *)v20, (V4 *)v0, (V4 *)v30);
        vec_sub_ab((V4 *)(D_001A4BE0 + 0xF0), (V4 *)v20, (V4 *)(D_001A4BE0 + 0x80));
        break;
    case 0x2B:
        {
        f32 vz2B;
        f32 ang2B;
        f32 rate2B;
        f32 old2B;
        f32 lenF0;
        f32 lenF4;
        s32 below2B;
        s32 up2B;
        s32 a7c;
        void *obj2B;
        void *lim2B;
        f32 min2B;
        f32 side2B;
        f32 m80[16] __attribute__((aligned(16)));
        f32 vC0[4] __attribute__((aligned(16)));
        f32 vD0[4] __attribute__((aligned(16)));
        if ((((Hero *)D_001A4BE0)->i[0xC08/4] & 2) && ((*(u8 *)((u8 *)temp_fp + 0x43)) == 0x2F)) {
            func_L01_0050BB98(0x30, 0xA, 12.0f);
            ((Hero *)D_001A4BE0)->f[0xC00/4] = 0.3f;
        }
        obj2B = ((Hero *)D_001A4BE0)->ptr[0xA54/4];
        vz2B = ((Hero *)D_001A4BE0)->f[0xF8/4];
        if (obj2B != 0) {
            if ((*(void **)((u8 *)obj2B + 0x68) != 0) && (*(s32 *)((u8 *)*(void **)((u8 *)obj2B + 0x68) + 0x34) != 0)) {
                ang2B = *(f32 *)((u8 *)obj2B + 0xF8);
                if (func_00389468(ang2B, ((Hero *)D_001A4BE0)->f[0x98/4]) > 90.0f) {
                    ang2B = func_00389380(ang2B, 3.1415927f);
                }
                func_L01_004455F0((s32)(D_001A4BE0 + 0xA6C), ang2B, (s32)(D_001A4BE0 + 0xA78), 0.02f, 0.3f, 0.0f, 0);
            }
        }
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0xA6C/4];
        func_L01_004EAFF8(0, 0.02f, 0.3f, 0.07853982f);
        vec_sub_ba((V4 *)v0, (V4 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA54/4] + 0x10), (V4 *)(D_001A4BE0 + 0x80));
        func_00388830((s32)v0, (s32)v0, 1.0f);
        if (v0[2] < 0.23f) {
            v0[2] = 0.23f;
        }
        qzero((V4 *)v20);
        v20[2] = ((Hero *)D_001A4BE0)->f[0x98/4];
        func_00388BF0((s32)v40, (s32)v20);
        func_00388E78((s32)m80, (s32)v40);
        func_003888F0((s32)v0, (s32)v0, (s32)m80);
        v10[0] = -func_00388A28(sqrt_asm(v0[0] * v0[0] + v0[2] * v0[2]), v0[1]);
        v10[1] = func_00388A28(v0[2], v0[0]);
        func_L01_004455F0((s32)(D_001A4BE0 + 0x94), v10[1], (s32)(D_001A4BE0 + 0xA4), 0.04f, 0.2f, 0.15998852f, 0);
        func_L01_004455F0((s32)(D_001A4BE0 + 0x90), v10[0], (s32)(D_001A4BE0 + 0xA0), 0.04f, 0.2f, 0.15998852f, 0);
        below2B = ((Hero *)D_001A4BE0)->f[0x88/4] < *(f32 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA54/4] + 0x18);
        if (((Hero *)D_001A4BE0)->h[0xA5C/2] != 0) {
            if ((below2B != 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 0x29) && (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.25f)) {
                func_L01_004EAA78(1.0f, 0);
                rate2B = ((Hero *)D_001A4BE0)->f[0x2838/4] * 0.0035f;
                if (rate2B > 0.083333336f) {
                    rate2B = 0.083333336f;
                }
                v30[0] = func_00388960(((Hero *)D_001A4BE0)->f[0x1A0/4]) * rate2B;
                v30[1] = func_00388978(((Hero *)D_001A4BE0)->f[0x1A0/4]) * rate2B;
                *(s32 *)&v30[2] = 0;
                vec_add_ab((V4 *)(D_001A4BE0 + 0xF0), (V4 *)(D_001A4BE0 + 0xF0), (V4 *)v30);
            }
            if (((Hero *)D_001A4BE0)->h[0xA5C/2] != 0) {
                if ((func_00388800((s32)(D_001A4BE0 + 0x80), (s32)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA54/4] + 0x10)) < (((Hero *)D_001A4BE0)->f[0xA60/4] * 1.57f)) || (((Hero *)D_001A4BE0)->f[0x33C/4] > 1.5f)) {
                    func_L01_0050CF30((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0x110), 0.011111111f);
                    if ((((Hero *)D_001A4BE0)->h[0xA7E/2] != 0) && (func_L01_0050D4D8((s32)(D_001A4BE0 + 0xF0)) > 0.0f)) {
                        vec_sub_ab((V4 *)v30, (V4 *)(D_001A4BE0 + 0x80), (V4 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA54/4] + 0x10));
                        func_L01_0050CF30((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.015833333f);
                    }
                }
                rate2B = func_00388770((s32)D_001A4CD0) * 0.00025f;
                func_003886E8((s32)v30, (s32)D_001A4CD0, -1.0f);
                func_00388830((s32)v30, (s32)v30, rate2B);
                vec_add_ab((V4 *)D_001A4CD0, (V4 *)D_001A4CD0, (V4 *)v30);
            }
        }
        if (((Hero *)D_001A4BE0)->ptr[0xA54/4] != 0) {
            lim2B = *(void **)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA54/4] + 0x68);
            if (lim2B != 0) {
                lenF0 = func_00388770((s32)(D_001A4BE0 + 0xF0));
                if (((Hero *)lim2B)->f[0xC/4] < lenF0) {
                    func_003BEBF8((s32)&lenF0, ((Hero *)lim2B)->f[0xC/4], 0.004166667f);
                    func_00388830((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), lenF0);
                }
            }
        }
        side2B = func_00389380(((Hero *)D_001A4BE0)->f[0x98/4], -1.5707964f);
        vD0[0] = func_00388960(side2B) * 0.15f;
        vD0[1] = func_00388978(side2B) * 0.15f;
        *(s32 *)&vD0[2] = 0;
        vec_add_ba((V4 *)vD0, (V4 *)vD0, (V4 *)(D_001A4BE0 + 0x80));
        vec_add_ba((V4 *)v30, (V4 *)vD0, (V4 *)(D_001A4BE0 + 0xF0));
        vec_sub_ba((V4 *)vC0, (V4 *)v30, (V4 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA54/4] + 0x10));
        func_00388830((s32)vC0, (s32)vC0, ((Hero *)D_001A4BE0)->f[0xA64/4]);
        vec_add_ba((V4 *)v30, (V4 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA54/4] + 0x10), (V4 *)vC0);
        vec_sub_ab((V4 *)(D_001A4BE0 + 0xF0), (V4 *)v30, (V4 *)vD0);
        old2B = ((Hero *)D_001A4BE0)->f[0xA64/4];
        func_L01_00445168((s32)(D_001A4BE0 + 0xA64), (s32)(D_001A4BE0 + 0xA68), ((Hero *)D_001A4BE0)->f[0xA60/4], ((Hero *)D_001A4BE0)->f[0xA84/4], ((Hero *)D_001A4BE0)->f[0xA88/4], ((Hero *)D_001A4BE0)->f[0xA8C/4]);
        old2B = ((Hero *)D_001A4BE0)->f[0xA64/4] - old2B;
        if (((Hero *)D_001A4BE0)->f[0xA64/4] < func_00388770((s32)vC0)) {
            func_00388830((s32)vC0, (s32)vC0, old2B);
            vec_add_ab((V4 *)(D_001A4BE0 + 0x80), (V4 *)(D_001A4BE0 + 0x80), (V4 *)vC0);
        }
        if ((((Hero *)D_001A4BE0)->h[0xA7E/2] != 0) && (below2B != 0)) {
            min2B = 0.23333335f;
            lenF4 = func_003887A0((s32)(D_001A4BE0 + 0xF0));
            if (lenF4 < min2B) {
                func_L01_00445168((s32)&lenF4, (s32)(D_001A4BE0 + 0xA74), min2B, 0.047f, 0.3f, 0.0f);
                v30[0] = func_00388960(((Hero *)D_001A4BE0)->f[0xA6C/4]) * ((Hero *)D_001A4BE0)->f[0xA74/4];
                v30[1] = func_00388978(((Hero *)D_001A4BE0)->f[0xA6C/4]) * ((Hero *)D_001A4BE0)->f[0xA74/4];
                v30[2] = 0.0f;
                vec_add_ab((V4 *)(D_001A4BE0 + 0xF0), (V4 *)(D_001A4BE0 + 0xF0), (V4 *)v30);
            }
        }
        if ((((Hero *)D_001A4BE0)->h[0xA5C/2] != 0) && (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) && (((vz2B < 0.0f) && (((Hero *)D_001A4BE0)->f[0xF8/4] > 0.0f)) || (((Hero *)D_001A4BE0)->h[0xA7C/2] != 0))) {
            ((Hero *)D_001A4BE0)->h[0xA7E/2] = 0;
            ang2B = sqrt_asm(((Hero *)D_001A4BE0)->f[0xA60/4] / ((Hero *)D_001A4BE0)->f[0xA70/4]) * 3.1415927f;
            a7c = ((Hero *)D_001A4BE0)->h[0xA7C/2];
            if (a7c != 0) {
                up2B = a7c == 1;
            } else {
                *(u128_t *)v30 = ((Hero *)D_001A4BE0)->q[0x110/16];
                up2B = func_L01_004EC818((s32)v30) > 0.0f;
            }
            if (up2B != 0) {
                if ((*(u8 *)((u8 *)temp_fp + 0x43)) != 0x30) {
                    func_L01_0050BB98(0x30, 6, 17.0f);
                    ((Hero *)D_001A4BE0)->h[0xA7C/2] = 1;
                } else if (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x42) == *(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x43)) {
                    func_L01_004E1268(42.0f, ang2B, 0.5f, -1.0f);
                    ((Hero *)D_001A4BE0)->h[0xA7C/2] = 0;
                }
            } else if ((*(u8 *)((u8 *)temp_fp + 0x43)) != 0x30) {
                func_L01_0050BB98(0x30, 0x15, 9.0f);
                ((Hero *)D_001A4BE0)->h[0xA7C/2] = 2;
            } else if (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x42) == *(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x43)) {
                func_L01_004E1268(12.0f, ang2B, 0.5f, -1.0f);
                ((Hero *)D_001A4BE0)->h[0xA7C/2] = 0;
            }
        }
        }
        break;
    case 0x14:
        {
        s32 hit;
        s32 lim14;
        s32 t14;
        f32 spF8;
        f32 d14;
        f32 rise;
        f32 vy;
        f32 cap;
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] != 0) || (((Hero *)D_001A4BE0)->f[0xC18/4] < (f32) D_L04_002F6B90[((Hero *)D_001A4BE0)->h[0xBDC/2]].w[0x18/4])) {
            ((Hero *)D_001A4BE0)->c[0x1219] = 2;
        }
        hit = 0;
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        if ((((Hero *)D_001A4BE0)->b[0x1478] != 0) || (((Hero *)D_001A4BE0)->b[0x1477] != 0) || (((Hero *)D_001A4BE0)->b[0x147D] != 0) || (((Hero *)D_001A4BE0)->f[0x33C/4] > 4.0f)) {
            hit = 1;
        }
        if (((Hero *)D_001A4BE0)->i[0xBC4/4] != 0) {
            vec_sub_ab((V4 *)v0, (V4 *)(((Hero *)D_001A4BE0)->i[0xBC4/4] + 0x10), (V4 *)(D_001A4BE0 + 0x80));
            d14 = func_L01_0050D430((s32)v0);
            if (((d14 > 2.0f) && (d14 < 5.0f)) || (hit != 0)) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.075f;
            }
            func_L01_004EB350(0.0069444445f, 0.0069444445f);
            func_00388830((s32)v10, (s32)D_001A4BE0, ((Hero *)D_001A4BE0)->f[0x1B4/4]);
            func_L01_0050D5B0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.0f);
            vec_add_ab((V4 *)(D_001A4BE0 + 0xF0), (V4 *)(D_001A4BE0 + 0xF0), (V4 *)v10);
        } else {
            if ((hit != 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0x46)) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.075f;
            }
            func_L01_004EB350(0.004166667f, 0.004166667f);
            func_L01_0050D5B0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), ((Hero *)D_001A4BE0)->f[0x1B4/4]);
        }
        if ((((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) || (((Hero *)D_001A4BE0)->i[0xBC4/4] != 0)) {
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0xBCC/4];
            *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x190/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0xBA0/16]);
            func_L01_004EAFF8(0, 0.05f, 0.2f, 0.28216156f);
        } else if (((Hero *)D_001A4BE0)->f[0xC18/4] < 25.0f) {
            func_L01_004EEA78(8.0f, 1.0471976f, 1.0471976f);
        }
        rise = 0.12833333f;
        if (((Hero *)D_001A4BE0)->f[0x33C/4] > 2.25f) {
            rise = 0.064166665f;
        } else if (((Hero *)D_001A4BE0)->f[0x33C/4] > 1.8f) {
            rise = 0.08983333f;
        }
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] == 0) && (((Hero *)D_001A4BE0)->f[0xC18/4] > 23.5f) && (((Hero *)D_001A4BE0)->f[0x118/4] < 0.0f) && (((Hero *)D_001A4BE0)->h[0x36E/2] != 0)) {
            *(u128_t *)(v0) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x80/16]);
            func_L01_0050D180((s32)v0, (s32)v0, -0.5f);
            func_00388830((s32)v40, (s32)D_001A4BE0, 2.0f);
            func_L01_00443628((s32)v10, (s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0x10000, 2.0f, (s32)v40);
            v10[3] = 5627.925f;
            (*(u8*)((u8*)v20+9)) = 1;
            (*(u16*)((u8*)v20+10)) = 0x47;
            (*(u8*)((u8*)v20+8)) = 0;
            func_003CF790((s32)v0, 0x10, 0.4f, (s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], (s32)v10);
        }
        if (func_L01_004EAA20(25.7f) != 0) {
            func_L01_003EFFE0(0x19, 0);
            ((Hero *)D_001A4BE0)->h[0x1FA/2] = 0x32;
            if (D_00142CBA[0] != 0) {
                ((Hero *)D_L04_001E28C0)->i[0x2C/4] = 0;
                ((Hero *)D_L04_001E28C0)->i[0x48/4] = 0x1E;
                ((Hero *)D_001A4BE0)->h[0x224/2] = 0x23;
                ((Hero *)D_L04_001E28C0)->f[0x40/4] = 0.1f;
            }
        }
        lim14 = 0xE;
        t14 = ((Hero *)D_001A4BE0)->i[0x1B8/4];
        if (t14 < 9) {
            vy = func_L01_0050D4D8((s32)(D_001A4BE0 + 0xF0));
            spF8 = vy;
            func_003BEBF8((s32)&spF8, rise, 0.041666668f);
            func_L01_0050D530((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), spF8);
        } else if (t14 > lim14) {
            func_L01_0050CF30((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.036111113f);
            if (func_L01_0050D4D8((s32)(D_001A4BE0 + 0xF0)) < 0.0f) {
                ((Hero *)D_001A4BE0)->f[0xBE0/4] = 1.0f;
            }
            cap = -0.6166667f;
            if (D_L04_001D673C_005003D0 != 0) {
                cap = -1.1666667f;
            }
            if (func_L01_0050D4D8((s32)(D_001A4BE0 + 0xF0)) < cap) {
                func_L01_0050D530((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), cap);
            }
        }
        }
        break;
    case 0x15:
    case 0x88:
        {
        s32 near;
        s32 go;
        f32 dyaw;
        f32 dist;
        s32 lane;
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] != 0) || (((Hero *)D_001A4BE0)->f[0xC18/4] < (f32) D_L04_002F6B90[((Hero *)D_001A4BE0)->h[0xBDC/2]].w[0x18/4])) {
            ((Hero *)D_001A4BE0)->c[0x1219] = 2;
        }
        go = (((Hero *)D_001A4BE0)->i[0x25D0/4] == 1) && (((Hero *)D_001A4BE0)->i[0x25D8/4] >= 0x15);
        if (go == 0) {
            if ((((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) || (((Hero *)D_001A4BE0)->i[0xBC4/4] != 0)) {
                near = 0;
                if (((Hero *)D_001A4BE0)->b[0x25F4] != 0) {
                    dyaw = func_L01_004F1018((s32)(D_001A4BE0 + 0xBA0), 0);
                    dist = func_L01_004F1018((s32)(D_001A4BE0 + 0xBA0), 1);
                } else {
                    dyaw = func_003893C8(((Hero *)D_001A4BE0)->f[0xBCC/4], ((Hero *)D_001A4BE0)->f[0x98/4]);
                    dist = func_L01_004454A8(1, ((Hero *)D_001A4BE0)->f[0xBCC/4], ((Hero *)D_001A4BE0)->f[0x98/4]);
                }
                if (dist < 4.363323f) {
                    near = 1;
                }
                if (dyaw > 0.0f) {
                    ((Hero *)D_001A4BE0)->f[0xC00/4] = 1.0f / (dist + 1.0f);
                }
                ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0xBCC/4];
                *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x190/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0xBA0/16]);
                if (near != 0) {
                    func_L01_004EAFF8(1, 0.057f, 0.2f, 0.28216156f);
                } else {
                    func_L01_004EAFF8(0, 0.057f, 0.2f, 0.28216156f);
                }
            } else {
                go = 1;
                if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x88) && (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 0xC)) {
                    go = 0;
                } else if ((((Hero *)D_001A4BE0)->i[0xC0C/4] == 0) && (((Hero *)D_001A4BE0)->f[0xC18/4] > 6.0f)) {
                    go = 0;
                }
                if (go != 0) {
                    if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x15) {
                        func_L01_004EEA78(14.0f, 0.5235988f, 0.7853982f);
                    }
                }
            }
        }
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] == 0) && (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x43) == 0x1A) && (func_L01_004EAA20(33.0f) != 0) && (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x15)) {
            lane = ((Hero *)D_001A4BE0)->i[0x1228/4];
            if ((lane == 0x7F) && (func_L01_0050DA08(-1) != 0)) {
                func_L01_004F1CE0();
            } else if ((lane == 0x7F) && (((Hero *)D_001A4BE0)->i[0x1228/4] == lane) && (func_L01_0050DA08(-1) == 0)) {
                func_L04_00508950(0, 1);
            } else {
                func_L01_004F1A08();
            }
        }
        func_L01_004EB350(0.010277778f, 0.007777778f);
        func_L01_004EB3A0(99999.0f);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_0050CF30((s32)(D_001A4BE0 + 0xF0), (s32)D_001A4BE0 + 0x130, 0.0069444445f);
        } else {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.015000001f);
        }
        }
        break;
    case 0x13:
        {
        Rec2C *rec13;
        s32 tgt13;
        f32 d13;
        f32 lo13;
        f32 off13;
        f32 hi13;
        f32 r13;
        f32 dy13;
        f32 e13;
        s32 go13;
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] != 0) || (((Hero *)D_001A4BE0)->f[0xC18/4] < (f32) D_L04_002F6B90[((Hero *)D_001A4BE0)->h[0xBDC/2]].w[0x20/4])) {
            ((Hero *)D_001A4BE0)->c[0x1219] = 2;
        }
        tgt13 = ((Hero *)D_001A4BE0)->i[0xBC4/4];
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        rec13 = &D_L04_002F6B90[((Hero *)D_001A4BE0)->h[0xBDC/2]];
        if ((tgt13 != 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] < 4)) {
            d13 = func_00388800(tgt13 + 0x10, (s32)D_001A4BE0 + 0x80);
            if (D_L04_001D673C_005003D0 != 0) {
                d13 = func_003887C8(((Hero *)D_001A4BE0)->i[0xBC4/4] + 0x10, (s32)D_001A4BE0 + 0x80);
            }
            d13 = d13 - 0.5f;
            if (d13 < 0.0f) {
                d13 = 0.0f;
            }
            if (rec13->w[1] == 0) {
                off13 = 0.75f;
                lo13 = 0.8f;
                hi13 = 4.0f;
            } else if (rec13->w[1] == 1) {
                off13 = 0.6f;
                lo13 = 1.7f;
                hi13 = 4.0f;
            } else {
                off13 = 1.3f;
                lo13 = 1.7f;
                hi13 = 1.9f;
            }
            if (((Hero *)D_001A4BE0)->i[0x234/4] != 0) {
                lo13 *= 3.0f;
            }
            e13 = d13 - off13;
            if (fabs_asm(e13) < lo13 + 3.0f) {
                r13 = e13 / 0.9f;
                if (r13 > hi13) {
                    r13 = hi13;
                }
                if (((Hero *)D_001A4BE0)->i[0x234/4] != 0) {
                    r13 *= 2.5f;
                }
                if (r13 > 1.0f) {
                    ((Hero *)D_001A4BE0)->f[0xBD4/4] = r13;
                }
            }
        }
        switch (rec13->w[1]) {
        case 0:
            if (((Hero *)D_001A4BE0)->f[0xC18/4] < 18.0f) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0xBD4/4] * 0.07333334f;
            }
            break;
        case 1:
            if ((((Hero *)D_001A4BE0)->i[0xC0C/4] != 0) || (((Hero *)D_001A4BE0)->f[0xC18/4] < 9.0f)) {
                if (((Hero *)D_001A4BE0)->f[0xC18/4] > 8.0f) {
                    ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0xBD4/4] * 0.050000004f;
                } else if (((Hero *)D_001A4BE0)->f[0xC18/4] > 7.0f) {
                    ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0xBD4/4] * 0.075f;
                } else {
                    ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0xBD4/4] * 0.095f;
                }
            }
            break;
        case 2:
            if ((((Hero *)D_001A4BE0)->i[0xC0C/4] != 0) || (((Hero *)D_001A4BE0)->f[0xC18/4] < 12.0f)) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0xBD4/4] * 0.06166667f;
            }
            break;
        }
        func_003BEBF8((s32)D_001A4BE0 + 0xC00, 1.0f, 0.2f);
        if ((((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) || (((Hero *)D_001A4BE0)->i[0xBC4/4] != 0)) {
            if (((Hero *)D_001A4BE0)->b[0x25F4] != 0) {
                dy13 = func_L01_004F1018((s32)D_001A4BE0 + 0xBA0, 0);
            } else {
                dy13 = func_003893C8(((Hero *)D_001A4BE0)->f[0xBCC/4], ((Hero *)D_001A4BE0)->f[0x98/4]);
            }
            r13 = fabs_asm(dy13);
            if ((rec13->w[1] == 1) && (dy13 > 0.0f)) {
                ((Hero *)D_001A4BE0)->f[0xC00/4] = 1.0f / (r13 + 1.0f);
            }
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0xBCC/4];
            *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x190/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0xBA0/16]);
            func_L01_004EAFF8(0, 0.05f, 0.2f, 0.28216156f);
        } else {
            go13 = 1;
            if ((rec13->w[1] == 1) && (((Hero *)D_001A4BE0)->i[0xC0C/4] == 0) && (((Hero *)D_001A4BE0)->f[0xC18/4] > 7.0f)) {
                go13 = 0;
            }
            if (go13 != 0) {
                func_L01_004EEA78(5.0f, 0.7853982f, 0.7853982f);
            }
        }
        func_L01_004EB350(0.010277778f, 0.007777778f);
        if (((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) {
            if (((Hero *)D_001A4BE0)->b[0x25F4] != 0) {
                func_L01_004EB460((s32)D_001A4BE0 + 0xBA0);
            } else {
                func_L01_004EB3A0(((Hero *)D_001A4BE0)->f[0xBCC/4]);
            }
        } else {
            func_L01_004EB3A0(99999.0f);
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.0069444445f);
        } else {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.015000001f);
        }
        func_L01_004F14D8(3.7f, 0.0f, 0.35f);
        }
        break;
    case 0x7C:
        func_003BEBF8((s32)(D_001A4BE0 + 0x1B4), 0.0f, 0.006666667f);
        if (D_L04_001D673C_005003D0 != 0) {
            func_00388830((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xBB0), ((Hero *)D_001A4BE0)->f[0x1B4/4]);
            if (((Hero *)D_001A4BE0)->f[0x33C/4] > 0.0f) {
                func_L01_0050CF30((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0x130), 0.0069444445f);
            } else {
                func_L01_0050D530((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.0f);
            }
            func_003886E8((s32)(D_001A4BE0 + 0x190), (s32)(D_001A4BE0 + 0x190) + 0xA20, -1.0f);
        } else {
            ((Hero *)D_001A4BE0)->f[0xF0/4] = func_00388960(((Hero *)D_001A4BE0)->f[0xBD0/4]) * ((Hero *)D_001A4BE0)->f[0x1B4/4];
            ((Hero *)D_001A4BE0)->f[0xF4/4] = func_00388978(((Hero *)D_001A4BE0)->f[0xBD0/4]) * ((Hero *)D_001A4BE0)->f[0x1B4/4];
            if (((Hero *)D_001A4BE0)->f[0x33C/4] > 0.0f) {
                ((Hero *)D_001A4BE0)->f[0xF8/4] = ((Hero *)D_001A4BE0)->f[0x128/4] - 0.0069444445f;
            } else {
                ((Hero *)D_001A4BE0)->f[0xF8/4] = 0.0f;
            }
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_00389380(((Hero *)D_001A4BE0)->f[0xBD0/4], 3.1415927f);
        }
        func_L01_004EAFF8(0, 0.05f, 0.2f, 0.28216156f);
        break;
    case 0x22:
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        if (((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) {
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0xBCC/4];
            *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x190/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0xBA0/16]);
            func_L01_004EAFF8(0, 0.04f, 0.2f, 0.28216156f);
        } else {
            func_L01_004EEA78(11.0f, 0.87266463f, -1.0f);
        }
        func_L01_004EB350(0.008333334f, 0.009722223f);
        func_L01_004EB3A0(99999.0f);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x110, 0.015000001f);
            func_L01_004EB490();
        } else {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.015000001f);
        }
        break;
    case 0x2:
    case 0x75:
        {
        f32 f1a;
        f32 f1b;
        f32 scale;
        f32 lim2;
        f32 k13;
        f32 ab;
        f32 ab2;
        f32 lim2b;
        f32 lim2c;
        f32 spd;
        if (!((((Hero *)D_001A4BE0)->h[0x1434/2] != 0) || ((((Hero *)D_001A4BE0)->i[0x16B0/4] == 1) && (func_L01_0045D358(0x28, 2, 0, 0) != 0)))) {
            if (((Hero *)D_001A4BE0)->f[0x174/4] < 0.028333336f) {
                ((Hero *)D_001A4BE0)->b[0x3EC] = 1;
                if (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) > 2.0943952f) {
                    if (((Hero *)D_001A4BE0)->f[0x2838/4] == 1.0f) {
                        ((Hero *)D_001A4BE0)->b[0x3EF] = 1;
                    }
                }
            }
            f1b = func_L01_0045D488(1, 0);
            if (func_00389468(f1b, func_L01_0045D488(7, 0)) > 1.9198622f) {
                if (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) > 1.2217305f) {
                    if (((Hero *)D_001A4BE0)->f[0x2838/4] == 1.0f) {
                        ((Hero *)D_001A4BE0)->b[0x3EF] = 1;
                        ((Hero *)D_001A4BE0)->b[0x3EC] = 1;
                    }
                }
            }
            if (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) < 0.08726646f) {
                ((Hero *)D_001A4BE0)->b[0x3EC] = 0;
            }
        }
        if ((((Hero *)D_001A4BE0)->i[0x1E8/4] < 3) && (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) > 1.5707964f) && (((Hero *)D_001A4BE0)->b[0x1436] != 0)) {
            ((Hero *)D_001A4BE0)->b[0x3EF] = 1;
            ((Hero *)D_001A4BE0)->b[0x3EC] = 1;
        }
        if ((((Hero *)D_001A4BE0)->b[0x3EF] != 0) && (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) < 0.06981317f)) {
            ((Hero *)D_001A4BE0)->b[0x3EF] = 0;
        }
        if (((Hero *)D_001A4BE0)->f[0x2838/4] < 0.2f) {
            if (((Hero *)D_001A4BE0)->i[0x3F0/4] != 0) {
                ((Hero *)D_001A4BE0)->b[0x3EF] = 1;
            }
            *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x190/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x3D0/16]);
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0x3E8/4];
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        } else {
            func_L04_004F9C78();
            if ((func_L01_004E5470(0) == 9) && ((((Hero *)D_001A4BE0)->f[0x283C/4] == 1.0f) || (((Hero *)D_001A4BE0)->i[0x3F0/4] != 0)) && (((Hero *)D_001A4BE0)->b[0x25EB] == 0)) {
                *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x3D0/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x190/16]);
                ((Hero *)D_001A4BE0)->f[0x3E8/4] = ((Hero *)D_001A4BE0)->f[0x1A0/4];
                ((Hero *)D_001A4BE0)->i[0x3F0/4] = 1;
            } else {
                *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x3D0/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x0/16]);
                ((Hero *)D_001A4BE0)->f[0x3E8/4] = ((Hero *)D_001A4BE0)->f[0x98/4];
            }
        }
        if (((Hero *)D_001A4BE0)->f[0x9F0/4] > 0.0f) {
            func_L01_004EC780(0.7f, 0.0f);
            (*(u128_t*)v0) = ((Hero *)D_001A4BE0)->q[0x9E0/16];
            f1a = ((Hero *)D_001A4BE0)->f[0x1B0/4] + func_L01_004EC818((s32)v0);
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = f1a;
            if (f1a < 0.011666667f) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.011666667f;
            }
            qzero((V4 *)(D_001A4BE0 + 0x9E0));
        }
        scale = 1.0f;
        if ((((Hero *)D_001A4BE0)->h[0x1434/2] != 0) || ((((Hero *)D_001A4BE0)->i[0x16B0/4] == 1) && (func_L01_0045D358(0x28, 2, 0, 0) != 0))) {
            func_L01_004EA628();
        } else {
            ((Hero *)D_001A4BE0)->f[0x1438/4] = ((Hero *)D_001A4BE0)->f[0x98/4];
            *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x1420/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x0/16]);
            if ((((Hero *)D_001A4BE0)->i[0x25C8/4] == 1) && (((Hero *)D_001A4BE0)->b[0x3EF] == 0) && (((Hero *)D_001A4BE0)->b[0x25EB] == 0)) {
                func_L01_004EAFF8(0, 0.037f, 0.13f, 0.20362175f);
            } else {
                ab = fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]);
                if (((((Hero *)D_001A4BE0)->f[0x2838/4] < 0.9f) || ((((Hero *)D_001A4BE0)->b[0x25EB] != 0) && (((Hero *)D_001A4BE0)->b[0x3EF] == 0))) && (ab > 0.7853982f)) {
                    scale = 0.0f;
                }
                func_L01_004EB0E8();
            }
        }
        func_L01_004EF060();
        func_L01_004F0138();
        if (((Hero *)D_001A4BE0)->b[0x3EF] != 0) {
            lim2 = 0.10283334f - fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) * 0.09166667f / 3.1415927f;
            if (lim2 < 0.0f) {
                lim2 = 0.0f;
            }
            if (lim2 < ((Hero *)D_001A4BE0)->f[0x1B0/4]) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = lim2;
            }
        }
        spd = scale * 0.010277778f;
        k13 = 0.008333334f;
        if (((Hero *)D_001A4BE0)->b[0x3EF] != 0) {
            lim2b = 2.6179938f - ((Hero *)D_001A4BE0)->f[0x1A8/4];
            if (lim2b > 1.0f) {
                lim2b = 1.0f;
            }
            if (lim2b < 0.2f) {
                lim2b = 0.2f;
            }
            k13 = 0.004722222f;
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0x1B0/4] * lim2b;
        }
        ab2 = fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]);
        if ((((Hero *)D_001A4BE0)->f[0x2838/4] < 0.75f) && (ab2 > 0.61086524f)) {
            lim2c = 1.0f - ab2 * 0.4f;
            if (lim2c < 0.0f) {
                lim2c = 0.0f;
            }
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0x1B0/4] * lim2c;
        }
        func_L01_004EB350(spd, k13);
        if ((((Hero *)D_001A4BE0)->b[0x3EC] != 0) || (((Hero *)D_001A4BE0)->h[0x1434/2] != 0) || ((((Hero *)D_001A4BE0)->i[0x16B0/4] == 1) && (func_L01_0045D358(0x28, 2, 0, 0) != 0))) {
            if (((Hero *)D_001A4BE0)->b[0x25F4] == 0) {
                if ((((Hero *)D_001A4BE0)->h[0x1434/2] != 0) || ((((Hero *)D_001A4BE0)->i[0x16B0/4] == 1) && (func_L01_0045D358(0x28, 2, 0, 0) != 0))) {
                    func_L01_004EB3A0(((Hero *)D_001A4BE0)->f[0x1438/4]);
                } else {
                    func_L01_004EB3A0(((Hero *)D_001A4BE0)->f[0x1A0/4]);
                }
            } else if ((((Hero *)D_001A4BE0)->h[0x1434/2] != 0) || ((((Hero *)D_001A4BE0)->i[0x16B0/4] == 1) && (func_L01_0045D358(0x28, 2, 0, 0) != 0))) {
                func_L01_004EB460((s32) (D_001A4BE0 + 0x1420));
            } else {
                func_L01_004EB460((s32) (D_001A4BE0 + 0x190));
            }
        } else {
            func_L01_004EB3A0(99999.0f);
        }
        func_L01_004EB5D0(0);
        if (((Hero *)D_001A4BE0)->h[0x214/2] != 0) {
            func_L01_004F14D8(5.0f, 0.2f, 0.35f);
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.0069444445f);
            func_L01_004EB490();
        } else {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.015000001f);
        }
        }
        break;
    case 0x80:
        {
        f32 tilt;
        s32 n80;
        s32 lim80;
        s32 cnt80;
        s32 i80;
        f32 cl80;
        func_L01_004F1110(4, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0xD);
        func_L01_003EFFE0(0x16, 0);
        func_L01_004EAA78(1.0f, 0);
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.19166668f;
        func_L01_004E1168((s32)v0, (s32) (D_001A4BE0 + 0x970), 0.17f);
        tilt = ((Hero *)D_001A4BE0)->f[0x2838/4] * 0.020362176f * v0[0];
        if ((D_L04_001D673C_005003D0 == 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0x3C)) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.5f;
        }
        n80 = ((Hero *)D_001A4BE0)->i[0x1B8/4];
        lim80 = 0x32;
        if (n80 < lim80) {
            tilt *= (f32)n80 / (f32)lim80;
        }
        if ((n80 >= 0x15) && (func_L01_004F14D8(2.5f, 0.0f, 1.5f) != 0)) {
            ((Hero *)D_001A4BE0)->i[0x984/4] = 1;
        }
        if (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.2f) {
            func_L01_004EAEC0(0.0f, 0.0f, tilt);
        }
        func_L01_004EB350(0.027777778f, 0.004166667f);
        func_L01_004EB3A0(99999.0f);
        if (D_L04_001D673C_005003D0 != 0) {
            *(u128_t *)(v10) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x2F0/16]);
            func_L01_0050D180((s32)v10, (s32)v10, 0.17f);
            func_L01_00445208_005003D0((s32) (D_001A4BE0 + 0x80), (s32)v10, (s32) (D_001A4BE0 + 0x980), 0.04f, 0.3f, 0.125f);
        } else {
            func_L01_00445168((s32) (D_001A4BE0 + 0x88), (s32) (D_001A4BE0 + 0x980), ((Hero *)D_001A4BE0)->f[0x338/4] + 0.17f, 0.04f, 0.3f, 0.125f);
        }
        func_003886E8((s32)v10, (s32)(D_001A4BE0 + 0x110), 3.0f);
        vec_add_ab((V4 *)v10, (V4 *)v10, (V4 *)(D_001A4BE0 + 0xE0));
        cnt80 = func_003CF790((s32)v10, 0, 0.57f, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0);
        if (cnt80 != 0) {
            func_003886E8((s32)v20, (s32)(D_001A4BE0 + 0x110), 7.0f);
            for (i80 = 0; i80 < cnt80; i80++) {
                if (func_003BF5E0(((s32 *)D_L04_001ED680)[i80]) != 0) {
                    func_L01_00443938(((s32 *)D_L04_001ED680)[i80], (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0x10000, (s32) (D_001A4BE0 + 0x80), (s32)v20, 1.0f);
                }
            }
        }
        func_L01_004E25C8(0.017f, 0.3f);
        func_L01_004E25F8(0.025f, 0.3f);
        func_L01_004E2610(0.03f, 0.27f);
        cl80 = tilt * 27.0f;
        if (cl80 > 1.7f) {
            cl80 = 1.7f;
        } else if (cl80 < -1.7f) {
            cl80 = -1.7f;
        }
        ((Hero *)D_L04_002F4E00)->f[0x60/4] = -cl80;
        ((Hero *)D_L04_002F4E00)->f[0x278/4] = cl80 * 0.5f;
        ((Hero *)D_L04_002F4E00)->f[0x1C8/4] = cl80 * 0.5f;
        }
        break;
    case 0x17:
    case 0x18:
        {
        vec_sub_ba((V4 *)(D_001A4BE0 + 0x190), (V4 *)(D_001A4BE0 + 0x510), (V4 *)(D_001A4BE0 + 0x500));
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_00388A28(((Hero *)D_001A4BE0)->f[0x190/4], ((Hero *)D_001A4BE0)->f[0x194/4]);
        func_L01_004EAFF8(0, 0.04f, 0.2f, 0.104719765f);
        if (((Hero *)D_001A4BE0)->b[0x25F4] != 2) {
            func_L01_00445558((s32)(D_001A4BE0 + 0x94), 0, 0.0f, 0.07853982f);
        }
        vec_sub_ab((V4 *)(D_001A4BE0 + 0xF0), (V4 *)(D_001A4BE0 + 0x500), (V4 *)(D_001A4BE0 + 0x80));
        func_003BF640((s32)(D_001A4BE0 + 0xF0), 0.06666667f);
        func_003BEBF8((s32)(D_001A4BE0 + 0x530), ((Hero *)D_001A4BE0)->f[0x88/4], 0.050000004f);
        }
        break;
    case 0x46:
    case 0x47:
        {
        vec_sub_ba((V4 *)(D_001A4BE0 + 0x190), (V4 *)(D_001A4BE0 + 0x510), (V4 *)(D_001A4BE0 + 0x500));
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_00388A28(((Hero *)D_001A4BE0)->f[0x190/4], ((Hero *)D_001A4BE0)->f[0x194/4]);
        func_L01_004EAFF8(0, 0.02f, 0.2f, 0.07853982f);
        vec_sub_ab((V4 *)(D_001A4BE0 + 0xF0), (V4 *)(D_001A4BE0 + 0x500), (V4 *)(D_001A4BE0 + 0x80));
        func_003BF640((s32)(D_001A4BE0 + 0xF0), 0.028333336f);
        func_003BEBF8((s32)(D_001A4BE0 + 0x530), ((Hero *)D_001A4BE0)->f[0x88/4], 0.050000004f);
        }
        break;
    case 0x19:
    case 0x1A:
        {
        vec_sub_ba((V4 *)(D_001A4BE0 + 0x190), (V4 *)(D_001A4BE0 + 0x510), (V4 *)(D_001A4BE0 + 0x500));
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_00388A28(((Hero *)D_001A4BE0)->f[0x190/4], ((Hero *)D_001A4BE0)->f[0x194/4]);
        func_L01_004EAFF8(0, 0.02f, 0.2f, 0.07853982f);
        vec_sub_ab((V4 *)(&v40[8]), (V4 *)(D_001A4BE0 + 0x510), (V4 *)(D_001A4BE0 + 0x500));
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x19) {
            func_00388758((s32)v40, (s32)D_001A4BE0 + 0x2E0, (s32)(&v40[8]));
        } else {
            func_00388758((s32)v40, (s32)(&v40[8]), (s32)D_001A4BE0 + 0x2E0);
        }
        func_00388830((s32)v40, (s32)v40, 0.2f);
        vec_add_ba((V4 *)(&v40[4]), (V4 *)(D_001A4BE0 + 0x80), (V4 *)v40);
        if (func_L01_004E4550((s32)D_001A4BE0 + 0x80, (s32)D_001A4BE0 + 0x90, 0) == 0) {
            break;
        }
        if (func_L01_004E4550((s32)(&v40[4]), (s32)D_001A4BE0 + 0x90, (s32)v0) != 0) {
            vec_sub_ba((V4 *)(D_001A4BE0 + 0xF0), (V4 *)v0, (V4 *)(D_001A4BE0 + 0x80));
            func_00388830((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, D_L04_001DA480[(s32)((Hero *)D_001A4BE0)->f[0xC18/4]] * 0.5f);
        }
        }
        break;
    case 0x6:
    case 0x2C:
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x2C) {
            f32 p2C;
            p2C = 0.0f;
            if (((Hero *)D_001A4BE0)->f[0x33C/4] > 4.0f) {
                p2C = 0.43633232f;
            }
            *(u128_t *)v0 = ((Hero *)D_001A4BE0)->q[0x90/16];
            func_L01_004455F0((s32)&v0[1], p2C, (s32)(D_001A4BE0 + 0xA4), 0.02f, 0.3f, 0.043633234f, 0);
            func_L01_004455F0((s32)v0, 0.0f, (s32)(D_001A4BE0 + 0xA0), 0.02f, 0.3f, 0.043633234f, 0);
            func_L01_004E14C8(((Hero *)D_001A4BE0)->f[0xA0/4], ((Hero *)D_001A4BE0)->f[0xA4/4], 0.0f);
            if (((Hero *)D_001A4BE0)->f[0x33C/4] > 1.0f) {
                ((Hero *)D_001A4BE0)->i[0x25C8/4] = 1;
            }
        }
        func_L04_004F9C78();
        if (((Hero *)D_001A4BE0)->h[0x1E0/2] == 0) {
            func_L04_004FCBA8();
        }
        func_L01_004EF060();
        func_L01_004EC780(0.7f, 0.0f);
        func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, ((Hero *)D_001A4BE0)->f[0xA00/4]);
        if (func_L01_0050D4D8((s32)D_001A4BE0 + 0xF0) < -0.8333334f) {
            func_L01_0050D530((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, -0.8333334f);
        }
        break;
    case 0x79:
        ((Hero *)D_001A4BE0)->c[0x25ED] = 1;
        func_003BEBF8((s32)D_001A4BE0 + 0xA08, ((Hero *)D_001A4BE0)->f[0xA10/4], 0.0024240685f);
        func_003BEBF8((s32)D_001A4BE0 + 0xA0C, ((Hero *)D_001A4BE0)->f[0xA14/4], 0.0024240685f);
        func_L01_004E14C8(((Hero *)D_001A4BE0)->f[0xA08/4], ((Hero *)D_001A4BE0)->f[0xA0C/4], 0.0f);
        func_L01_0040C1F8((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, func_003887A0((s32)D_001A4BE0 + 0xF0) * 0.9f);
        func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, ((Hero *)D_001A4BE0)->f[0xA00/4]);
        if (func_L01_0050D4D8((s32)D_001A4BE0 + 0xF0) < -0.8333334f) {
            func_L01_0050D530((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, -0.8333334f);
        }
        break;
    case 0xB0:
        {
        f32 dB0;
        f32 sB0;
        f32 tB0;
        f32 yB0;
        f32 kB0;
        f32 qB0;
        f32 oB0;
        f32 jB0;
        qB0 = 0.008f;
        func_L01_004EAA78(0.13333334f, 0);
        kB0 = 0.25f;
        oB0 = ((Hero *)D_001A4BE0)->f[0x1A0/4];
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_L04_001E28D8)->f[0];
        func_L01_004EAFF8(0, qB0, 0.3f, 0.072722055f);
        jB0 = 0.015f;
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = oB0;
        func_L04_004FC178(0.004166667f);
        func_L01_004E25C8(0.017f, 0.33f);
        func_L01_004E25E0(jB0, kB0);
        func_L01_004E25F8(jB0, kB0);
        func_L01_004E2610(qB0, kB0);
        dB0 = ((Hero *)D_001A4BE0)->f[0x1A8/4] * 0.7f;
        if (dB0 > 1.2f) {
            dB0 = 1.2f;
        } else if (dB0 < -1.2f) {
            dB0 = -1.2f;
        }
        ((Hero *)D_L04_002F4E00)->f[0x60/4] = -dB0 * 0.52f;
        if (((Hero *)D_L04_002F4E00)->f[0x60/4] > 0.28f) {
            ((Hero *)D_L04_002F4E00)->f[0x60/4] = 0.28f;
        } else if (((Hero *)D_L04_002F4E00)->f[0x60/4] < -0.28f) {
            ((Hero *)D_L04_002F4E00)->f[0x60/4] = -0.28f;
        }
        ((Hero *)D_L04_002F4E00)->f[0x278/4] = dB0 * 1.2f;
        ((Hero *)D_L04_002F4E00)->f[0x118/4] = dB0 * 0.58f;
        ((Hero *)D_L04_002F4E00)->f[0x1C0/4] = dB0 * -0.28f;
        if (((Hero *)D_L04_002F4E00)->f[0x278/4] > 0.6f) {
            ((Hero *)D_L04_002F4E00)->f[0x278/4] = 0.6f;
        } else if (((Hero *)D_L04_002F4E00)->f[0x278/4] < -0.6f) {
            ((Hero *)D_L04_002F4E00)->f[0x278/4] = -0.6f;
        }
        ((Hero *)D_L04_002F4E00)->f[0x270/4] = fabs_asm(dB0) * 0.16f;
        ((Hero *)D_L04_002F4E00)->f[0x64/4] = func_00389380(((Hero *)D_L04_002F4E00)->f[0x64/4], -0.12217305f);
        if (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.1f) {
            yB0 = func_003893C8(((Hero *)D_001A4BE0)->f[0x1A0/4], ((Hero *)D_001A4BE0)->f[0x98/4]);
            sB0 = ((Hero *)D_001A4BE0)->f[0x2838/4] * 0.61086524f;
            ((Hero *)D_L04_002F4E00)->f[0x60/4] = -func_00388978(yB0) * sB0;
            ((Hero *)D_L04_002F4E00)->f[0x64/4] = func_00389380(((Hero *)D_L04_002F4E00)->f[0x64/4], func_00388960(yB0) * sB0);
            if (((Hero *)D_L04_002F4E00)->f[0x60/4] > 0.47123888f) {
                ((Hero *)D_L04_002F4E00)->f[0x60/4] = 0.47123888f;
            } else if (((Hero *)D_L04_002F4E00)->f[0x60/4] < -0.47123888f) {
                ((Hero *)D_L04_002F4E00)->f[0x60/4] = -0.47123888f;
            }
            if (((Hero *)D_L04_002F4E00)->f[0x64/4] > 0.47123888f) {
                ((Hero *)D_L04_002F4E00)->f[0x64/4] = 0.47123888f;
            } else if (((Hero *)D_L04_002F4E00)->f[0x64/4] < -0.47123888f) {
                ((Hero *)D_L04_002F4E00)->f[0x64/4] = -0.47123888f;
            }
        }
        func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.019444445f);
        if (func_L01_0050D4D8((s32)D_001A4BE0 + 0xF0) < -0.18333334f) {
            func_L01_0050D530((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, -0.18333334f);
        }
        }
        break;
    case 0x8:
        {
        f32 g8;
        f32 m8;
        f32 h8;
        f32 sp8;
        if (func_L01_004E5470(3) == 2) {
            s32 t279C = ((Hero *)D_001A4BE0)->i[0x279C/4];
            if (t279C != -1) {
                u8 *o = (u8 *)D_001A30B0 + (t279C << 7);
                if ((*(void **)(o + 0xDC) == ((Hero *)D_001A4BE0)->ptr[0x25C0/4]) && (*(u8 *)(o + 0xD0) != 0)) {
                    func_0039FB08(t279C);
                }
            }
            ((Hero *)D_001A4BE0)->i[0x279C/4] = -1;
            func_L01_004F1110(3, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 2);
        } else {
            s32 t2798 = ((Hero *)D_001A4BE0)->i[0x2798/4];
            if (t2798 != -1) {
                u8 *o = (u8 *)D_001A30B0 + (t2798 << 7);
                if ((*(void **)(o + 0xDC) == ((Hero *)D_001A4BE0)->ptr[0x25C0/4]) && (*(u8 *)(o + 0xD0) != 0)) {
                    func_0039FB08(t2798);
                }
            }
            ((Hero *)D_001A4BE0)->i[0x2798/4] = -1;
            func_L01_004F1110(4, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0xD);
        }
        g8 = 0.050000004f;
        if (((Hero *)D_001A4BE0)->i[0x1318/4] == 3) {
            g8 = 0.083333336f;
        }
        h8 = ((Hero *)D_001A4BE0)->f[0x284C/4];
        m8 = 0.72f;
        if (h8 != 0.0f) {
            m8 = h8;
        }
        sp8 = func_L01_0050D4D8((s32)D_001A4BE0 + 0xF0);
        func_L01_004EAA78(g8, 0);
        func_L01_004EAFF8(0, 0.025f, 0.3f, 0.20943953f);
        func_L01_004EB350(0.004166667f, 0.0019444445f);
        func_L01_004EB3A0(99999.0f);
        func_L01_004EF060();
        func_L01_0050D348((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0);
        func_L01_00445168((s32)&sp8, (s32)D_001A4BE0 + 0xA18, -g8 * m8, 0.025f, 0.3f, 0.28333336f);
        func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, -sp8);
        if (((Hero *)D_001A4BE0)->f[0x88/4] < ((Hero *)D_001A4BE0)->f[0x460/4]) {
            func_003BEBF8((s32)D_001A4BE0 + 0x460, ((Hero *)D_001A4BE0)->f[0x88/4], 0.06666667f);
        }
        func_L01_004E39B8();
        }
        break;
    case 0x7:
    case 0x9:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
    case 0xF:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x1B:
    case 0x38:
    case 0x45:
    case 0x48:
    case 0x54:
    case 0x5F:
    case 0x69:
    case 0x6B:
    case 0x73:
    case 0x86:
    case 0xA2:
    case 0xA7:
    case 0xAC:
        {
        s32 end7;
        s32 t7;
        s32 st7;
        f32 keep7;
        f32 v7;
        f32 cap7;
        s32 n7;
        s32 i7;
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x1B) && (((Hero *)D_001A4BE0)->h[0x2884/2] == 0) && (((Hero *)D_001A4BE0)->i[0x1318/4] == 3)) {
            if (func_L01_004EAA20(10.0f) != 0) {
                func_L01_004F1068(4, 0);
            }
        }
        if ((((Hero *)D_001A4BE0)->h[0x4F8/2] != 0) && (((Hero *)D_001A4BE0)->b[0x1474] != 0)) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0x1B4/4];
        } else if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x69) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0x1B4/4];
            if ((((Hero *)D_001A4BE0)->b[0x46C] != 0) && (((Hero *)D_001A4BE0)->f[0x1B4/4] > 0.10283334f)) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.10283334f;
            }
        } else {
            if (((Hero *)D_001A4BE0)->b[0x46C] != 0) {
                func_L01_004EAA78(0.10283334f, 0);
            }
            func_L01_004EAA78(((Hero *)D_001A4BE0)->f[0x474/4], 0);
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x12) {
            if (((Hero *)D_001A4BE0)->i[0x1B8/4] == 0x14) {
                func_L01_004E20F0(3, 0x10, 1);
                if (D_L04_001E0E90 != 0) {
                    func_L01_004C2BF8(D_L04_001E0E90, D_L04_001E0E98, 0, ((Hero *)D_001A4BE0)->f[0x80/4], ((Hero *)D_001A4BE0)->f[0x84/4], 0.4f, 0.35f);
                }
            }
            v7 = ((Hero *)D_001A4BE0)->f[0xC18/4];
            if ((v7 >= 4.0f) && (v7 <= 7.0f)) {
                func_L01_004E1E40(7, 0, 0);
            }
        }
        end7 = ((Hero *)D_001A4BE0)->h[0x47C/2];
        t7 = ((Hero *)D_001A4BE0)->i[0x1B8/4];
        if (t7 == end7) {
            *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x430/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x80/16]);
        }
        if ((((Hero *)D_001A4BE0)->b[0x46C] != 0) || ((t7 < end7) && (st7 = ((Hero *)D_001A4BE0)->u[0x25C4/4], (st7 != 0xB)) && (st7 != 0x10) && (st7 != 0xC) && (st7 != 0x11) && (st7 != 0x1B) && (st7 != 0x48))) {
            if (((Hero *)D_001A4BE0)->b[0x25E4] != 5) {
                func_L01_004EAFF8(0, 0.015f, 0.2f, 0.25016388f);
            }
            keep7 = ((Hero *)D_001A4BE0)->f[0x1B4/4];
            if (((Hero *)D_001A4BE0)->b[0x46C] >= 2) {
                ((Hero *)D_001A4BE0)->f[0x1B4/4] = keep7 * 0.4f;
            }
            if ((((Hero *)D_001A4BE0)->h[0x1434/2] != 0) || ((((Hero *)D_001A4BE0)->i[0x16B0/4] == 1) && (func_L01_0045D358(0x28, 2, 0, 0) != 0))) {
                func_L01_004EB3A0(((Hero *)D_001A4BE0)->f[0x1438/4]);
            } else {
                func_L01_004EB3A0(99999.0f);
            }
            ((Hero *)D_001A4BE0)->f[0x1B4/4] = keep7;
            if (((Hero *)D_001A4BE0)->b[0x46C] != 1) {
                func_L01_004EB350(((Hero *)D_001A4BE0)->f[0x4D0/4], ((Hero *)D_001A4BE0)->f[0x4D4/4]);
            }
            if (((Hero *)D_001A4BE0)->b[0x46C] != 0) {
                if (D_001D52FC->i[0x1D4/4] != 0) {
                    if (((Hero *)D_001A4BE0)->h[0x36A/2] != 0) {
                        ((Hero *)D_001A4BE0)->f[0x1B4/4] = 0.0f;
                    }
                }
                if (((Hero *)D_001A4BE0)->b[0x46C] != 0) {
                    func_L01_004F0928(((Hero *)D_001A4BE0)->f[0x4D4/4]);
                }
            }
            func_L01_004EC780(0.5f, 0.033333335f);
            if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 9) {
                s32 c9 = ((Hero *)D_001A4BE0)->i[0x1B8/4];
                if (c9 < (((Hero *)D_001A4BE0)->h[0x47C/2] + 4)) {
                    func_L01_0050D1A0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), (f32) c9 * 0.0044444446f);
                }
            }
            if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0xA) {
                s32 cA = ((Hero *)D_001A4BE0)->i[0x1B8/4];
                if (cA < 0x22) {
                    func_L01_0050D1A0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), (f32) cA * 0.014722222f);
                }
            }
            if ((((Hero *)D_001A4BE0)->i[0x1B8/4] < 10) && (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.2f)) {
                *(u128_t *)(v0) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x80/16]);
                func_L01_0050D2A8((s32)v0, (s32)v0, 0.5f);
                func_L01_0050D1A0((s32)v10, (s32)v0, 0.95f);
                if (func_003CE740((s32)v0, (s32)v10, 4, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0) != 0) {
                    ((Hero *)D_001A4BE0)->h[0x4F4/2] = 1;
                }
            }
        } else {
            func_L04_004FCBA8();
            if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x12) {
                cap7 = func_003887A0((s32)(D_001A4BE0 + 0xF0));
                if (cap7 > 0.06166667f) {
                    cap7 = 0.06166667f;
                }
                func_00388880((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), cap7);
            }
        }
        {
        f32 a338 = ((Hero *)D_001A4BE0)->f[0x338/4];
        f32 a460 = ((Hero *)D_001A4BE0)->f[0x460/4];
        if (a460 < a338) {
            f32 n460 = a460 + 0.10000001f;
            ((Hero *)D_001A4BE0)->f[0x460/4] = n460;
            if (a338 < n460) {
                ((Hero *)D_001A4BE0)->f[0x460/4] = a338;
            }
        }
        }
        {
        f32 a88 = ((Hero *)D_001A4BE0)->f[0x88/4];
        if (a88 < ((Hero *)D_001A4BE0)->f[0x460/4]) {
            ((Hero *)D_001A4BE0)->f[0x460/4] = a88;
        }
        }
        if ((((Hero *)D_001A4BE0)->h[0x47C/2] < ((Hero *)D_001A4BE0)->i[0x1B8/4]) && (func_L01_0050D4D8((s32)(D_001A4BE0 + 0xF0)) < 0.001f) && ((((Hero *)D_001A4BE0)->b[0x46D] == 0) || (((Hero *)D_001A4BE0)->i[0x1B8/4] > ((Hero *)D_001A4BE0)->i[0x404/4])) && ((((Hero *)D_001A4BE0)->u[0x25C4/4] != 0xE) || (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 0x12))) {
            f32 a428 = ((Hero *)D_001A4BE0)->f[0x428/4];
            ((Hero *)D_001A4BE0)->b[0x46E] = 1;
            if (a428 != 0.0f) {
                ((Hero *)D_001A4BE0)->f[0x4F0/4] = a428;
            }
        }
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 0) {
            func_L01_004EF060();
        }
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 1) {
            func_L01_004EFDD8();
        }
        st7 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
        if ((st7 == 0x10) || (st7 == 0xD)) {
            if (D_001439F4[0] != 2) {
                func_L01_0044B1E0((s32)(D_001A4BE0 + 0x1B90), (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0xD) ? 0 : 2);
            }
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x86) {
            func_L01_0044B1E0((s32)(D_001A4BE0 + 0x1B90), (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0xE) ? 0 : 2);
        }
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x10) && (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 9) && (((Hero *)D_001A4BE0)->f[0xC18/4] < 28.0f)) {
            func_L01_0050D110((s32)v0, 1, 0.8f, 0.0f, 0.3f);
            n7 = func_003CF790((s32)v0, 0, 0.9f, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0);
            if (n7 != 0) {
                func_003886E8((s32)v10, (s32)D_001A4BE0 + 0x110, 7.0f);
                for (i7 = 0; i7 < n7; i7++) {
                    if (func_003BF5E0(((s32 *)D_L04_001ED680)[i7]) != 0) {
                        func_L01_00443938(((s32 *)D_L04_001ED680)[i7], (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0x10000, (s32)D_001A4BE0 + 0x80, (s32)v10, 1.0f);
                    }
                }
            }
        }
        func_L01_004ED860();
        func_L01_004E39B8();
        }
        break;
    case 0x16:
    case 0xB1:
        {
        f32 sp16;
        f32 dec16;
        sp16 = func_L01_0050D430((s32)(D_001A4BE0 + 0xF0));
        dec16 = 0.0011111111f;
        if ((((Hero *)D_001A4BE0)->h[0x36E/2] == 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 11)) {
            dec16 = 0.0027777778f;
        }
        sp16 = sp16 - dec16;
        if (sp16 < 0.0f) {
            sp16 = 0.0f;
        }
        if (((Hero *)D_001A4BE0)->b[0x1479] != 0) {
            func_L01_004F14D8(3.7f, 0.0f, 0.35f);
        }
        func_L01_0050D5B0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, sp16);
        func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.004f);
        }
        break;
    case 0x91:
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = -0.38333336f;
        }
        break;
    case 0x66:
        {
        f32 len66;
        f32 sc66;
        s32 n66;
        s32 i66;
        void *o66;
        vec_sub_ab((V4 *)v0, (V4 *)(D_001A4BE0 + 0x1B40), (V4 *)(D_001A4BE0 + 0x80));
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_00388A28(v0[0], v0[1]);
        if (D_L04_001D673C_005003D0 != 0) {
            len66 = func_00388770((s32)v0);
        } else {
            len66 = func_003887A0((s32)v0);
        }
        if (len66 > 0.3f) {
            if (D_L04_001D673C_005003D0 != 0) {
                Hero *g66 = (Hero *)D_001A4BE0;
                g66->f[0x2838/4] = 1.0f;
                *(u128_t *)(&g66->q[0x190/16]) = *(u128_t *)(&g66->q[0x1B60/16]);
                g66->f[0x1B0/4] = len66;
                if (len66 < D_L04_001DBCC4[2]) {
                    g66->f[0x1B0/4] = D_L04_001DBCC4[1] * 0.016666668f;
                } else {
                    g66->f[0x1B0/4] = D_L04_001DBCC4[5] * 0.016666668f;
                }
            } else {
                Hero *h66 = (Hero *)D_001A4BE0;
                h66->f[0x2838/4] = 1.0f;
                h66->f[0x1A0/4] = func_00388A28(v0[0], v0[1]);
                h66->f[0x1B0/4] = len66;
                if (len66 < D_L04_001DBCC4[2]) {
                    h66->f[0x1B0/4] = D_L04_001DBCC4[1] * 0.016666668f;
                } else {
                    h66->f[0x1B0/4] = D_L04_001DBCC4[5] * 0.016666668f;
                }
            }
            if (((Hero *)D_001A4BE0)->b[0x25E4] == 1) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.015000001f;
            }
        } else {
            if (D_L04_001D673C_005003D0 != 0) {
                ((Hero *)D_001A4BE0)->f[0x2838/4] = 1.0f;
                *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x190/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x1B60/16]);
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
            } else {
                ((Hero *)D_001A4BE0)->f[0x2838/4] = 1.0f;
                ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0x1B4C/4];
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
            }
        }
        sc66 = 1.0f;
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 3) {
            func_L01_004EAFF8(0, 0.03f, 0.3f, 0.13671747f);
        } else if (((Hero *)D_001A4BE0)->b[0x25E4] == 1) {
            func_L01_004EAFF8(0, 0.03f, 0.3f, 0.1308997f);
        } else if (((Hero *)D_001A4BE0)->b[0x25E4] == 0) {
            func_L01_004EAFF8(0, 0.03f, 0.3f, 0.1308997f);
        }
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 0) {
            func_L01_004EF060();
        }
        func_L01_004EB350(sc66 * 0.010277778f, 0.008333334f);
        if (D_L04_001D673C_005003D0 != 0) {
            func_L01_004EB460((s32)(D_001A4BE0 + 0x190));
        } else {
            func_L01_004EB3A0(99999.0f);
        }
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 0) {
            func_L01_004EB5D0(0);
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x110, 0.0069444445f);
            func_L01_004EB490();
        } else {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.015000001f);
        }
        *(u128_t *)v10 = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0xE0/16]);
        n66 = func_003CF790((s32)v10, 0, ((Hero *)D_001A4BE0)->f[0x284/4] + 0.2f, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0);
        for (i66 = 0; i66 < n66; i66++) {
            o66 = ((void **)D_L04_001ED680)[i66];
            if ((o66 != 0) && (*(s16 *)((u8 *)o66 + 0xAA) == 0xCB)) {
                func_L01_00443938((s32)o66, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0x10000, (s32)D_001A4BE0 + 0xE0, (s32)D_L04_001D66B0_005003D0, 100.0f);
            }
        }
        }
        break;
    case 0x67:
        vec_sub_ab((V4 *)v0, (V4 *)(D_001A4BE0 + 0x1B40), (V4 *)(D_001A4BE0 + 0x80));
        if (func_00388730((s32)v0, (s32)(D_001A4BE0 + 0x160)) < 0.0f) {
            qzero((V4 *)(D_001A4BE0 + 0x160));
        }
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_L01_004F0928(0.0075000003f);
        func_L01_004EB5D0(0);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x110, 0.0069444445f);
            func_L01_004EB490();
        } else {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.015000001f);
        }
        break;
    case 0x68:
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        ((Hero *)D_001A4BE0)->i[0x1B4/4] = 0;
        func_L01_004EB3A0(99999.0f);
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 0) {
            func_L01_004EB5D0(0);
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x110, 0.0069444445f);
            func_L01_004EB490();
        } else {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.015000001f);
        }
        break;
    case 0x6A:
        qzero((V4 *)D_001A4CD0);
        if (((Hero *)(D_001A4CD0 - 0xF0))->f[0x354/4] - ((Hero *)(D_001A4CD0 - 0xF0))->f[0x88/4] > (f32)((Hero *)(D_001A4CD0 - 0xF0))->i[0x1B70/4] * 0.5f) {
            func_L01_0050D348((s32)D_001A4CD0, (s32)D_001A4CD0);
            func_L01_0050CF30((s32)D_001A4CD0, (s32)D_001A4CD0, 0.004166667f);
        } else {
            func_L01_0050D348((s32)D_001A4CD0, (s32)D_001A4CD0);
            func_L01_0050CF30((s32)D_001A4CD0, (s32)D_001A4CD0, 0.016666668f);
        }
        break;
    case 0x7D:
        qzero((V4 *)D_001A4CD0);
        func_L01_0050D348((s32)D_001A4CD0, (s32)D_001A4CD0);
        func_L01_0050CF30((s32)D_001A4CD0, (s32)D_001A4CD0, 0.016666668f);
        break;
    case 0x3F:
    case 0x43:
        func_L01_004F14D8(3.7f, 0.0f, 0.35f);
        func_L01_004EAA78(1.0f, 0);
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        func_L01_004EB350(0.0f, 0.0035f);
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_L01_004EB5D0(0);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.0069444445f);
            func_L01_004EB490();
        } else {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.015000001f);
        }
        break;
    case 0x4D:
        {
        Rec2C *rec;
        s32 tgt;
        f32 d;
        s32 side;
        f32 sp4D;
        tgt = ((Hero *)D_001A4BE0)->i[0xBC4/4];
        rec = &D_L04_002F6B90[((Hero *)D_001A4BE0)->h[0xBDC/2]];
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        sp4D = 0.075f;
        if (tgt != 0) {
            d = func_00388800((s32)D_001A4BE0 + 0x80, tgt + 0x10);
            if (d > 1.1f) {
                sp4D = 0.125f;
            }
            if (d > 0.7f) {
                sp4D = 0.095f;
            }
        }
        if (rec->w[1] == 0) {
            if (((Hero *)D_001A4BE0)->f[0xC18/4] < 7.5f) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = sp4D;
            }
        } else if (rec->w[1] == 1) {
            if (((Hero *)D_001A4BE0)->f[0xC18/4] < 7.5f) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = sp4D;
            }
        }
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] == 0) && ((f32)rec->w[7] <= ((Hero *)D_001A4BE0)->f[0xC18/4]) && (((Hero *)D_001A4BE0)->f[0xC18/4] <= (f32)rec->w[8])) {
            side = 2;
            if (rec->w[1] == 1) {
                side = 0;
            }
            func_003BDA38((s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], side, (s32)v10);
            func_003BDA38((s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], side | 1, (s32)v20);
            vec_add_ab((V4 *)v0, (V4 *)v10, (V4 *)v20);
            func_003886E8((s32)v0, (s32)v0, 0.5f);
            func_L01_00443648((s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0.25f, (s32)v0, 0x10000, 1.0f, 1.0f, 0, 1, 0);
        }
        func_003BEBF8((s32)D_001A4BE0 + 0xC00, 1.0f, 0.2f);
        if ((((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) || (((Hero *)D_001A4BE0)->i[0xBC4/4] != 0)) {
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0xBCC/4];
            func_L01_004EAFF8(0, 0.05f, 0.2f, 0.28216156f);
        } else {
            func_L01_004EEA78(3.0f, 0.7853982f, 0.7853982f);
        }
        func_L01_004EB350(0.010277778f, 0.007777778f);
        if (((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) {
            if (((Hero *)D_001A4BE0)->b[0x25F4] == 2) {
                func_L01_004EB460((s32)D_001A4BE0 + 0xBA0);
            } else {
                func_L01_004EB3A0(((Hero *)D_001A4BE0)->f[0xBCC/4]);
            }
        } else {
            func_L01_004EB3A0(99999.0f);
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = ((Hero *)D_001A4BE0)->f[0x118/4] - 0.0069444445f;
            func_L01_004EB490();
        } else {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = ((Hero *)D_001A4BE0)->f[0xF8/4] - 0.015000001f;
        }
        func_L01_004F14D8(0.7f, 0.0f, 0.3f);
        }
        break;
    case 0x4B:
        func_L01_004EAA78(0.033333335f, 0);
        func_L01_004EAFF8(0, 0.04f, 0.2f, 0.1658063f);
        func_L01_004EB350(0.004166667f, 0.0019444445f);
        func_L01_004EB3A0(99999.0f);
        func_L01_0050D348((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0));
        func_L01_0050CF30((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.024000002f);
        break;
    case 0x4E:
    case 0x7B:
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0x34C/4];
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.09166667f;
        func_L04_004FC178(0.0069444445f);
        func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.005f);
        break;
    case 0x4F:
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_L01_0050CF30((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.0033333334f);
        break;
    case 0x41:
        func_L01_004EAA78(0.055000003f, 0);
        if (((Hero *)D_001A4BE0)->h[0x1E0/2] == 0) {
            func_L04_004FCBA8();
        }
        func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0033333334f);
        if (((Hero *)D_001A4BE0)->f[0xF8/4] < -0.16666667f) {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = -0.16666667f;
        }
        break;
    case 0x44:
        if (((Hero *)D_001A4BE0)->f[0xF8/4] > 0.0f) {
            func_L01_004E14C8(0.0f, 0.20943953f, 0.0f);
        }
        func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0055555557f);
        break;
    case 0x40:
    case 0x4C:
        {
        f32 a40;
        f32 c40;
        f32 m40;
        f32 b40;
        func_L01_004EAA78(0.055000003f, 0);
        c40 = 0.1658063f;
        a40 = 0.033f;
        if (((Hero *)D_001A4BE0)->b[0x3EF] != 0) {
            c40 = 0.1948951f;
            a40 = 0.037f;
        }
        func_L01_004EAFF8(0, a40, 0.15f, c40);
        func_L01_004EB350(0.010277778f, 0.008333334f);
        if (((Hero *)D_001A4BE0)->f[0x174/4] < 0.011666667f) {
            ((Hero *)D_001A4BE0)->b[0x3EC] = 1;
            if ((fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) > 1.7453293f) && (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.8f)) {
                ((Hero *)D_001A4BE0)->b[0x3EF] = 1;
            }
        }
        m40 = func_L01_0045D488(0, 0);
        if (func_00389468(m40, func_L01_0045D488(2, 0)) > 2.6179938f) {
            if ((fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) > 1.2217305f) && (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.8f)) {
                ((Hero *)D_001A4BE0)->b[0x3EF] = 1;
                ((Hero *)D_001A4BE0)->b[0x3EC] = 1;
            }
        }
        if (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) < 0.08726646f) {
            ((Hero *)D_001A4BE0)->b[0x3EC] = 0;
        }
        if (((Hero *)D_001A4BE0)->b[0x3EF] != 0) {
            if (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) < 0.06981317f) {
                ((Hero *)D_001A4BE0)->b[0x3EF] = 0;
            }
            if (((Hero *)D_001A4BE0)->b[0x3EF] != 0) {
                b40 = 0.055000003f - fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) * 0.06666667f / 3.1415927f;
                if (b40 < 0.0f) {
                    b40 = 0.0f;
                }
                if (b40 < ((Hero *)D_001A4BE0)->f[0x1B0/4]) {
                    ((Hero *)D_001A4BE0)->f[0x1B0/4] = b40;
                }
            }
        }
        if (((Hero *)D_001A4BE0)->b[0x3EC] != 0) {
            func_L01_004EB3A0(((Hero *)D_001A4BE0)->f[0x1A0/4]);
        } else {
            func_L01_004EB3A0(99999.0f);
        }
        func_L01_004EB5D0(0);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.0069444445f);
            func_L01_004EB490();
        } else {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.015000001f);
        }
        }
        break;
    case 0x42:
        {
        f32 var_f12_r4;
        var_f12_r4 = func_003887A0((s32)(D_001A4BE0 + 0xF0));
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            var_f12_r4 *= 0.95f;
        } else {
            var_f12_r4 *= 0.8f;
        }
        func_L01_0040C1F8((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), var_f12_r4);
        ((Hero *)D_001A4BE0)->i[0xF8/4] = 0;
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_0050CF30((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0) + 0x30, 0.0061111115f);
        } else {
            func_L01_0050CF30((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.004f);
        }
        }
        break;
    case 0x49:
    case 0x4A:
        {
        ((Hero *)D_001A4BE0)->f[0xC00/4] = 1.3f;
        vec_sub_ba((V4 *)(D_001A4BE0 + 0x190), (V4 *)(D_001A4BE0 + 0x510), (V4 *)(D_001A4BE0 + 0x500));
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_00388A28(((Hero *)D_001A4BE0)->f[0x190/4], ((Hero *)D_001A4BE0)->f[0x194/4]);
        func_L01_004EAFF8(0, 0.02f, 0.2f, 0.07853982f);
        vec_sub_ab((V4 *)(&v40[8]), (V4 *)(D_001A4BE0 + 0x510), (V4 *)(D_001A4BE0 + 0x500));
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x49) {
            func_00388758((s32)v40, (s32)D_001A4BE0 + 0x2E0, (s32)(&v40[8]));
        } else {
            func_00388758((s32)v40, (s32)(&v40[8]), (s32)D_001A4BE0 + 0x2E0);
        }
        func_00388830((s32)v40, (s32)v40, 0.2f);
        vec_add_ba((V4 *)(&v40[4]), (V4 *)(D_001A4BE0 + 0x80), (V4 *)v40);
        if (func_L01_004E4550((s32)D_001A4BE0 + 0x80, (s32)D_001A4BE0 + 0x90, 0) == 0) {
            break;
        }
        if (func_L01_004E4550((s32)(&v40[4]), (s32)D_001A4BE0 + 0x90, (s32)v0) != 0) {
            vec_sub_ba((V4 *)(D_001A4BE0 + 0xF0), (V4 *)v0, (V4 *)(D_001A4BE0 + 0x80));
            func_00388830((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, D_L04_002F0400[(s32)((Hero *)D_001A4BE0)->f[0xC18/4]] * 0.5f);
        }
        }
        break;
    case 0x51:
    case 0x56:
    case 0x59:
        func_L01_004F14D8(3.7f, 0.0f, 0.35f);
        func_L01_004EAA78(1.0f, 0);
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        func_L01_004EB350(0.0f, 0.004916667f);
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_L01_004F0928(0.004916667f);
        func_L01_004EB5D0(0);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.0069444445f);
            func_L01_004EB490();
        } else {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.015000001f);
        }
        break;
    case 0x57:
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0x34C/4];
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.09166667f;
        func_L04_004FC178(0.0069444445f);
        func_L01_0050CF30((s32)(D_001A4BE0 + 0xF0), (s32)D_001A4BE0 + 0x130, 0.005f);
        break;
    case 0x58:
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        break;
    case 0x53:
        func_L01_004EAA78(0.083333336f, 0);
        if (((Hero *)D_001A4BE0)->h[0x1E0/2] == 0) {
            func_L04_004FCBA8();
        }
        if (((Hero *)D_001A4BE0)->h[0x202/2] >= 0x15) {
            func_L01_00443648((s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], 1.0f, (s32)D_001A4BE0 + 0x80, 0xA, 1.0f, 1.0f, 0, 1, 0);
        }
        func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0058333334f);
        if (((Hero *)D_001A4BE0)->f[0xF8/4] < -0.25f) {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = -0.25f;
        }
        break;
    case 0x52:
        {
        f32 var_f21_r3;
        f32 var_f20_r3;
        f32 var_f2_r3;
        var_f21_r3 = func_00389468(((Hero *)D_001A4BE0)->f[0x98/4], ((Hero *)D_001A4BE0)->f[0x1A0/4]);
        func_L01_004EAA78(0.083333336f, 0);
        if (((Hero *)D_001A4BE0)->f[0x1B0/4] < 0.045833334f) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.045833334f;
        }
        var_f20_r3 = 1.0f;
        var_f20_r3 -= var_f21_r3 * 0.3f;
        var_f2_r3 = ((Hero *)D_001A4BE0)->f[0x2838/4] + 0.35f;
        if (var_f20_r3 < 0.0f) {
            var_f20_r3 = 0.0f;
        }
        func_L01_004EAFF8(0, var_f2_r3 * 0.035f, 0.1f, var_f2_r3 * 0.13671747f);
        func_L01_004EB350(var_f20_r3 * 0.010277778f, 0.008333334f);
        if ((((Hero *)D_001A4BE0)->b[0x3EC] != 0) && (((Hero *)D_001A4BE0)->h[0x368/2] == 0)) {
            func_L01_004EB3A0(((Hero *)D_001A4BE0)->f[0x1A0/4]);
        } else {
            func_L01_004EB3A0(99999.0f);
        }
        func_L01_004EB5D0(0);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.0069444445f);
            func_L01_004EB490();
        } else {
            func_L01_0050CF30((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.015000001f);
        }
        }
        break;
    case 0x55:
        {
        f32 var_f12_r3;
        var_f12_r3 = func_003887A0((s32)(D_001A4BE0 + 0xF0));
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            var_f12_r3 *= 0.99f;
        } else {
            var_f12_r3 *= 0.92f;
        }
        func_L01_0040C1F8((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), var_f12_r3);
        ((Hero *)D_001A4BE0)->i[0xF8/4] = 0;
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_0050CF30((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0) + 0x30, 0.0061111115f);
        } else {
            func_L01_0050CF30((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.004f);
        }
        }
        break;
    case 0x37:
        if (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x43) == 0x3F) {
            func_L01_004EAFF8(0, 0.137f, 0.25f, 0.20362175f);
        } else {
            func_L01_004EAFF8(0, 1.0f, 0.1f, 0.4072435f);
        }
        break;
    case 0x3C:
    case 0x64:
    case 0x65:
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        break;
    }
    if (sp114 != ((Hero *)D_001A4BE0)->i[0x25C8/4]) {
        ((Hero *)D_001A4BE0)->i[0x1C0/4] = 0;
    }
    if (sp118 != (*(u8 *)((u8 *)(temp_fp) + 0x43))) {
        ((Hero *)D_001A4BE0)->i[0x1C4/4] = 0;
    }
}

/* localdecomp:end func_L04_005003D0 */
