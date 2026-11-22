#include "common.h"

/* NTSC-U counterpart of func_L06_0034A7A8 (src/levels/shared/L06_0034A2B8.c) */
#include "vu0.h"
extern s32 D_L06_001DD2D8_00349B48;
extern void func_003BDA38(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00449008(void *, void *, void *, s32, f32);
extern s32 D_L06_001DD2D8_00349B48;
extern void func_003BDA38(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);

/* localdecomp:start func_L06_00349B48 */
typedef int u128_0034A7A8 __attribute__((mode(TI)));
typedef union Mo_0034A7A8_ { u8 b[0x100]; s8 c[0x100]; s16 h[0x80]; u16 uh[0x80]; s32 i[0x40]; u32 u[0x40]; f32 f[0x40]; void *p[0x40]; long d[0x20]; u128_0034A7A8 q[0x10]; } Mo_0034A7A8;
typedef union Pv_0034A7A8_ { u8 b[0x1000]; s8 c[0x1000]; s16 h[0x800]; u16 uh[0x800]; s32 i[0x400]; u32 u[0x400]; f32 f[0x400]; void *p[0x400]; long d[0x200]; u128_0034A7A8 q[0x100]; } Pv_0034A7A8;
typedef union G_0034A7A8_ { u8 b[0x4000]; s8 c[0x4000]; s16 h[0x2000]; u16 uh[0x2000]; s32 i[0x1000]; u32 u[0x1000]; f32 f[0x1000]; void *p[0x1000]; long d[0x800]; u128_0034A7A8 q[0x400]; } G_0034A7A8;
typedef union { f32 f[4]; s32 i[4]; s8 c[16]; u8 b[16]; s16 h[8]; u16 uh[8]; u128_0034A7A8 q; } __attribute__((aligned(16))) U16_0034A7A8;
extern char D_001A4BE0[];
typedef struct { u8 pad0[2]; s16 cnt; u8 pad4[0xC]; s32 *list; u8 pad14[0x1C]; } E30_0034A7A8;
typedef struct { u8 hdr[0x30]; E30_0034A7A8 e[1]; } H30_0034A7A8;
extern H30_0034A7A8 *D_L06_001DEA4C_00349B48;
typedef struct { u8 pad0[0x30]; u128_0034A7A8 pos; u8 pad40[0x40]; } E80_0034A7A8;
extern E80_0034A7A8 *D_L06_001DEE80_00349B48;
extern s32 D_L06_001E8458_00349B48 __attribute__((section(".data")));
extern u128_0034A7A8 D_L06_001E8460_00349B48;
extern void *D_L06_0021CB00_00349B48[];
extern s32 D_L06_001DD2D8_00349B48;
extern f32 D_L06_001DD2D0_00349B48;
__asm__(".extern D_L06_001DD2D8_00349B48, 4");
__asm__(".extern D_L06_001DD2D0_00349B48, 4");
extern void func_L06_0034F0B8_00349B48(void *);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_003883C8(void *);
extern f32 func_00388800(void *, void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00389468(f32, f32);
extern void func_003BD360(void *);
extern f32 func_L01_00436500(void *);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00442998(s32, s32, s32);
extern void func_L01_00442AA8(s32, s32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_L01_00443628(void *, void *, s32, f32, void *);
extern f32 func_003BEBF8(void *, f32, f32);
extern void func_003BEC60(void *, f32, void *, f32, f32, f32);
extern s32 func_L01_00448E90(void *);
extern s32 func_L01_00451078(void *, void *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_L01_00452EF0(void *);
extern void func_L01_00455E98(void *, void *, void *);
extern void func_L01_00457440(void *, void *);
extern s32 func_L01_00457728(void *, void *);
extern s32 func_L01_00458A08(void *, f32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern s32 func_L01_00458AE0(void *, s32);
extern void func_L01_00458E48(void *, void *, s32, s32);
extern void func_L01_00459F10(void *, void *);
extern void func_L01_0032FE90_00349B48(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L06_00349A68(u8 *);
extern s32 func_L06_0034E980(u8 *);
extern void func_L06_0034EFD8(u8 *, s32);
extern void func_L06_003577D0(void *, void *, void *, void *, s32, s32, f32);
extern s32 func_L01_00443790(void *, s32, f32, f32, s32, f32, s32, s32, s32);
extern s32 func_L06_00428768(void *, void *, f32);
extern void func_L01_00449008(void *, void *, void *, s32, f32);
extern s32 func_L01_0044AF40(void *, f32);
extern s32 func_L01_00455C88(void *, void *, s32, s32);
#include "vu0.h"

void func_L06_00349B48(Mo_0034A7A8 *m) {
    U16_0034A7A8 sp90;
    U16_0034A7A8 spA0;
    U16_0034A7A8 spB0;
    U16_0034A7A8 spC0;
    U16_0034A7A8 spD0;
    U16_0034A7A8 spE0;
    U16_0034A7A8 spF0;
    U16_0034A7A8 sp100;
    U16_0034A7A8 sp110;
    f32 temp_f0;
    f32 temp_f0_10;
    f32 temp_f0_11;
    f32 temp_f0_12;
    f32 temp_f0_13;
    f32 temp_f0_14;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f0_9;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f14_3;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f21;
    f32 var_f0;
    f32 var_f22;
    s32 *temp_s1;
    s32 temp_a0_10;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a0_5;
    s32 temp_a0_6;
    s32 temp_a0_7;
    s32 temp_a0_8;
    s32 temp_a0_9;
    s32 temp_a1;
    s32 temp_a1_4;
    s32 temp_a1_5;
    s32 temp_a3;
    s32 temp_s0_2;
    s32 temp_s0_6;
    s32 temp_s2;
    s32 temp_s7;
    s32 temp_v0;
    s32 temp_v0_10;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_a1;
    s32 var_a1_10;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_a1_4;
    s32 var_a1_5;
    s32 var_a1_6;
    s32 var_a1_7;
    s32 var_a1_8;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_a2_3;
    s32 var_condition_bit;
    s32 var_condition_bit_2;
    s32 var_condition_bit_3;
    s32 var_condition_bit_4;
    s32 var_condition_bit_5;
    s32 var_condition_bit_6;
    s32 var_condition_bit_7;
    s32 var_condition_bit_8;
    s32 var_condition_bit_9;
    s32 var_s2;
    u8 temp_a0;
    u8 temp_v0_2;
    u8 temp_v1;
    u8 temp_v1_3;
    u8 temp_v1_4;
    u8 temp_v1_5;
    u8 temp_v1_7;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_s0;
    void *temp_s0_10;
    void *temp_s0_11;
    void *temp_s0_12;
    void *temp_s0_13;
    void *temp_s0_14;
    void *temp_s0_3;
    void *temp_s0_4;
    void *temp_s0_5;
    void *temp_s0_7;
    void *temp_s0_8;
    void *temp_s0_9;
    void *temp_s1_2;
    void *temp_s1_3;
    void *temp_s1_4;
    void *temp_s1_5;
    void *temp_s1_6;
    void *temp_s1_7;
    void *temp_s3;
    void *temp_s4;
    Pv_0034A7A8 *pv;
    void *temp_s7_2;
    void *temp_v0_7;
    void *temp_v0_8;
    void *temp_v0_9;
    void *temp_v1_6;
    void *var_a0_2;
    void *var_a0_3;
    void *var_a1_9;
    void *var_s0;
    void *var_s1;

    pv = m->p[0x68/4];
    if (func_L01_00448E90((u8 *)m + 0x10) == 0) {
        return;
    }
    if ((pv->i[0x958/4] != 0) && (m->b[0x20] == 0x25)) {
        return;
    }
    if ((func_L06_0034E980((u8 *)m) != 0) || (pv->d[0x908/8] != 0)) {
        func_003BD360(m);
        return;
    }
    if ((pv->f[0x30/4] > 0.0f) && (((G_0034A7A8 *)D_001A4BE0)->i[0x2850/4] <= 0) && (m->b[0x60] & 2) && (m->b[0x95] != 4)) {
        if (m->b[0x43] != 0x12) {
            func_003BE4F0(m, 0x12, 0, 10);
        }
        func_L01_00441FB8(m, 0x18, 4);
        if (((G_0034A7A8 *)D_001A4BE0)->p[0x2808/4] == m) {
            if (m->b[0x43] != 2) {
                func_003BE4F0(m, 2, 0, 10);
            }
            func_L01_00441FB8(m, 0x19, -1);
        }
    }
    if ((pv->b[0x176] == 0xFF) && (pv->f[0x30/4] <= 0.0f)) {
        if ((m->b[0x21] != 0xFF) && (m->b[0xBC] == 0)) {
            func_L01_00442AA8(m->b[0x21], 0);
            m->b[0xBC] = 0;
        }
        func_L06_0034EFD8(m->b, 0);
        func_L01_0032FE90_00349B48((u8 *)m + 0x10, 0, 0xA, 0xA, 0xA, 0xA, 0xF, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                          0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003BD360(m);
        return;
    }
    temp_s7 = (pv->b[0x5F] != 0) ? 0x10001 : 1;
    switch (m->b[0x95]) {
    case 0:
        if ((pv->i[0x948/4] != -1) && (func_L01_00442998(pv->i[0x948/4], -1, 1) != 0)) {
            break;
        }
        if ((pv->h[0x234/2] == 1) && (((s32 (*)(void *))func_003883C8)(pv->b + 0x8D6) != 0)) {
            func_L01_00441FB8(m, 0xB, 2);
            if (m->b[0x43] != 0xB) {
                func_003BE4F0(m, 0xB, 0, (s32)func_0037E250(6.0f, 12.0f));
            }
            if ((pv->i[0x930/4] != 0) && (pv->i[0x944/4] == -1)) {
                func_L01_00441FB8(m, 0xA, 2);
                if (m->b[0x43] != 0xE) {
                    func_003BE4F0(m, 0xE, 0, 10);
                }
            }
            if (pv->i[0x908/4] != 0) {
                s32 r = func_L06_00349A68((u8 *)m);
                if (r == 1) {
                    if (m->b[0x43] != 4) {
                        func_003BE4F0(m, 4, 0, 10);
                    }
                    func_L01_00441FB8(m, 0x1D, 2);
                    pv->i[0x908/4] = 2;
                } else if (r == 2) {
                    if (m->b[0x43] != 3) {
                        func_003BE4F0(m, 3, 0, 10);
                    }
                    func_L01_00441FB8(m, 0x1E, 2);
                    pv->i[0x908/4] = 1;
                }
            }
            if (pv->i[0x95C/4] != -1) {
                func_L01_00441FB8(m, 0x11, 2);
                if (m->b[0x43] != 7) {
                    func_003BE4F0(m, 7, 0, 10);
                }
            }
            {
            s32 n = pv->i[0x974/4];
            if ((n != -1) && (D_L06_001DEA4C_00349B48->e[n].cnt != 0)) {
                func_L01_00441FB8(m, 0xB, 2);
                if (m->b[0x43] != 0xB) {
                    func_003BE4F0(m, 0xB, 0, (s32)func_0037E250(6.0f, 12.0f));
                }
            }
            }
            if (pv->i[0x90C/4] != 0) {
                if (m->b[0x43] != 5) {
                    func_003BE4F0(m, 5, 0, 10);
                }
                func_L01_00441FB8(m, 0x1F, 2);
            }
            if (pv->i[0x94C/4] != 0) {
                if (m->b[0x43] != 5) {
                    func_003BE4F0(m, 5, 0, 10);
                }
                func_L01_00441FB8(m, 0x20, 2);
            }
        } else if ((pv->i[0x8D8/4] != 0) && (((s32 (*)(void *))func_003883C8)(pv->b + 0x8D6) != 0)) {
            if (m->b[0x20] == 2) {
                if (m->b[0x43] != 5) {
                    func_003BE4F0(m, 5, 0, 10);
                }
                func_L01_00441FB8(m, 0x20, 2);
            } else {
                func_L01_00441FB8(m, 8, 1);
            }
            pv->i[0x8D8/4] = 0;
            if (pv->i[0x8D0/4] < 0x12C) {
                pv->i[0x8D0/4] = func_0037E208(0x1E0, 0x258);
            }
        }
        break;
    case 1:
        if (pv->h[0x234/2] == 1) {
            func_L01_00441FB8(m, 0xB, 2);
            if (m->b[0x43] != 0xB) {
                func_003BE4F0(m, 0xB, 0, 10);
            }
            if (m->b[0x20] == 2) {
                if (m->b[0x43] != 5) {
                    func_003BE4F0(m, 5, 0, 10);
                }
                func_L01_00441FB8(m, 0x20, 2);
            }
        }
        break;
    case 2:
        if ((pv->h[0x234/2] != 1) && (func_L01_00452EF0(m) == 0) && (m->b[0x20] != 0x20)) {
            if (m->b[0x43] != 0x11) {
                func_003BE4F0(m, 0x11, 0, 10);
            }
            func_L01_00441FB8(m, 8, 1);
            pv->i[0x8D0/4] = func_0037E208(0x244, 0x258);
        }
        break;
    case 3:
        {
        s32 r = func_L01_00451078(m, pv->b + 0x160);
        if (r & 1) {
            if ((m->b[0x21] != 0xFF) && (m->b[0xBC] == 0)) {
                func_L01_00442AA8(m->b[0x21], 0);
                m->b[0xBC] = 0;
            }
            func_L06_0034EFD8(m->b, 0);
            func_L01_0032FE90_00349B48((u8 *)m + 0x10, 0, 0xA, 0xA, 0xA, 0xA, 0xF, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_003BD360(m);
            return;
        }
        if (r & 2) {
            if (pv->h[0x234/2] == 1) {
                if (pv->i[0x95C/4] != -1) {
                    func_L01_00441FB8(m, 0x11, 2);
                    if (m->b[0x43] != 7) {
                        func_003BE4F0(m, 7, 0, 8);
                    }
                } else {
                    func_L01_00441FB8(m, 0xE, 2);
                    if (m->b[0x43] != 6) {
                        func_003BE4F0(m, 6, 0, 8);
                    }
                }
            } else {
                if (m->b[0x43] != 0x11) {
                    func_003BE4F0(m, 0x11, 0, 10);
                }
                func_L01_00441FB8(m, 8, 1);
                pv->i[0x8D0/4] = func_0037E208(0x244, 0x258);
            }
        }
        if ((pv->b[0x176] == 0xFF) && (pv->f[0x30/4] <= 0.0f)) {
            if ((m->b[0x21] != 0xFF) && (m->b[0xBC] == 0)) {
                func_L01_00442AA8(m->b[0x21], 0);
                m->b[0xBC] = 0;
            }
            func_L06_0034EFD8(m->b, 0);
            func_L01_0032FE90_00349B48((u8 *)m + 0x10, 0, 0xA, 0xA, 0xA, 0xA, 0xF, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_003BD360(m);
            return;
        }
        }
        break;
    }
    switch (m->b[0x20]) {
                        case 1:
                        case 2:
                            break;
                        case 3:                     /* switch 2 */
                            if (m->b[0x60] & 2) {
                                if (m->b[0x43] != 9) {
                                    func_003BE4F0(m, 9, 0, 0);
                                }
                                func_L01_00441FB8(m, 4, -1);
                            }
                            break;
                        case 4:                     /* switch 2 */
                            if (func_L01_00452EC8(m) != 0) {
                                func_L01_00458A70(m, 0.0022222223f, 0.033333335f, 0.0069813174f, 0.20943953f);
                                temp_f20 = func_0037E2A8();
                                temp_f21 = func_0037E250(7.0f, 8.0f);
                                qzero(pv->b + 0x960);
                                pv->f[0x960/4] = func_00388960(temp_f20) * temp_f21;
                                pv->f[0x964/4] = func_00388978(temp_f20) * temp_f21;
                                vec_add_ab(pv->b + 0x960, pv->b + 0x910, pv->b + 0x960);
                            }
                            func_00388830(&sp90, (u8 *)m + 0xC0, 3.0f);
                            vec_add_ab(&sp90, &sp90, m->b + 0x10);
                            func_L01_00457440(m, &sp90);
                            func_L01_00458A08(m, func_00388A28(pv->f[0x960/4] - m->f[0x10/4], pv->f[0x964/4] - m->f[0x14/4]));
                            if (func_00388800((u8 *)m + 0x10, (u8 *)pv + 0x960) < 0.5f) {
                                func_L01_00441FB8(m, 7, -1);
                                if (m->b[0x43] != 1) {
                                    func_003BE4F0(m, 1, 1, 0xC);
                                }
                            }
                            break;
                        case 5:                     /* switch 2 */
                            if (func_L01_00452EC8(m) != 0) {
                                temp_s0 = (u8 *)m + 0x10;
                                func_L01_00458A70(m, 0.0022222223f, 0.033333335f, 0.0034906587f, 0.20943953f);
                                temp_s1 = D_L06_0021CB00_00349B48[pv->i[0x950/4]];
                                temp_f20_2 = func_00388800(temp_s0, (u8 *)temp_s1 + 0x10);
                                if (func_00388800(temp_s0, (u8 *)temp_s1 + (*temp_s1 * 0x10)) < temp_f20_2) {
                                    func_L01_00458E48(m, temp_s1, 0, *temp_s1 - 1);
                                } else {
                                    func_L01_00458E48(m, temp_s1, *temp_s1 - 1, 0);
                                }
                            }
                            if (func_L01_00458AE0(m, pv->i[0x950/4]) != 0) {
                                func_L01_00441FB8(m, 7, -1);
                                if (m->b[0x43] != 1) {
                                    func_003BE4F0(m, 1, 6, 4);
                                }
                            }
                            break;
                        case 6:                     /* switch 2 */
                            func_L01_00452EC8(m);
                            if ((func_L01_0044AF40(m, 8.0f) != 0) && (m->b[0x42] == 0xA)) {
                                if (m->b[0x43] != 1) {
                                    func_003BE4F0(m, 1, 6, 4);
                                }
                                func_L01_00441FB8(m, 7, -1);
                                break;
                            }
                            break;
                        case 7:                     /* switch 2 */
                            if ((func_L01_0044AF40(m, 61.0f) != 0) && (m->b[0x42] == 1)) {
                                if (m->b[0x43] != 6) {
                                    func_003BE4F0(m, 6, 0, 0xC);
                                }
                                func_L01_00441FB8(m, 4, -1);
                                if (pv->i[0x950/4] != -1) {
                                    func_L01_00441FB8(m, 5, -1);
                                    if (m->b[0x43] != 6) {
                                        func_003BE4F0(m, 6, 0, 0xC);
                                    }
                                }
                            }
                            break;
                        case 8:                     /* switch 2 */
                            if (m->b[0x60] & 2) {
                                if (m->b[0x43] != 6) {
                                    func_003BE4F0(m, 6, 0, 6);
                                }
                                func_L01_00441FB8(m, 4, -1);
                                break;
                            }
                            break;
                        case 36:                    /* switch 2 */
                            if (m->b[0x42] == 0x1B) {
                                temp_f0 = func_L01_00436500(m);
                                if ((temp_f0 > 8.0f) && (temp_f0 < 24.0f)) {
                                    f32 d = func_00388800((u8 *)m + 0x10, (u8 *)pv + 0x220);
                                    func_00388830(&spB0, (u8 *)m + 0xC0, (d - 1.25f) * 0.0625f);
                                    vec_add_ba(&sp90, m->b + 0x10, &spB0);
                                    if (temp_f0 < 20.0f) {
                                        func_L01_00458A08(m, func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]));
                                    }
                                }
                                if (temp_f0 > 16.0f) {
                                    func_003BDA38(m, 0, &spB0);
                                    func_003BDA38(m, 1, &spC0);
                                    temp_a1 = D_L06_001DD2D8_00349B48;
                                    temp_s0_2 = ((pv->i[0x8DC/4] - 2 + temp_a1) % temp_a1) * 0x10;
                                    vec_sub_ab(&spD0, pv->b + 0x2C0 + pv->i[0x8DC/4] * 0x10, pv->b + 0x2C0 + temp_s0_2);
                                    func_00388830(&spD0, &spD0, 1.1f);
                                    spD0.f[2] = 1.0f;
                                    spD0.f[3] = 5627.925f;
                                    func_L01_00443628(&spE0, m, temp_s7, (f32) pv->b[0x44], &spD0);
                                    spF0.c[9] = 1;
                                    spF0.uh[5] = m->uh[0xAA/2];
                                    spF0.c[8] = 0;
                                    ((s32 (*)(void *, void *, s32, void *, void *))func_003CE740)(&spB0, &spC0, 9, m, &spE0);
                                    ((s32 (*)(void *, void *, s32, void *, void *))func_003CE740)(&spB0, pv->b + 0x2C0 + temp_s0_2, 9, m, &spE0);
                                }
                                if ((temp_f0 > 8.0f) && (temp_f0 < 16.0f)) {
                                    func_003BEC60(&sp90.f[2], func_003BE7F0((u8 *)m + 0x10, 0, 0, 0.5f) + 3.5f, (u8 *)pv + 0x8E0, 1.09375f, 0.175f, 0.74375004f);
                                }
                                if (temp_f0 == 16.0f) {
                                    pv->i[0x8E0/4] = 0;
                                }
                                if ((temp_f0 > 16.0f) && (temp_f0 < 24.0f)) {
                                    func_003BEC60(&sp90.f[2], func_003BE7F0((u8 *)m + 0x10, 0, 0, 0.5f), (u8 *)pv + 0x8E0, 0.036458332f, 0.21875f, 0.65625f);
                                }
                                if ((temp_f0 > 8.0f) && (temp_f0 < 24.0f)) {
                                    vec_sub_ab(&spA0, &sp90, m->b + 0x10);
                                    func_L01_00457728(m, &spA0);
                                }
                                if ((func_L01_0044AF40(m, 28.0f) != 0) && (((G_0034A7A8 *)D_001A4BE0)->i[0x2850/4] > 0)) {
                                    if ((m->b[0x21] != 0xFF) && (pv->b[0x5F] == 0)) {
                                        func_L01_00442AA8((s32) m->b[0x21], 0);
                                        m->b[0xBC] = 0U;
                                    }
                                    if (func_0037E1D8(2) != 0) {
                                        if (m->b[0x43] != 4) {
                                            func_003BE4F0(m, 4, 0, 7);
                                        }
                                        func_L01_00441FB8(m, 0x1B, -1);
                                    } else {
                                        if (m->b[0x43] != 3) {
                                            func_003BE4F0(m, 3, 0, 7);
                                        }
                                        func_L01_00441FB8(m, 0x1C, -1);
                                    }
                                    break;
                                }
                            }
                            break;
                        case 26:                    /* switch 2 */
                            if (m->b[0x42] == 5) {
                                f32 t = func_L01_00436500(m);
                                if ((t > 8.0f) && (t < 24.0f)) {
                                    func_00388830(&spB0, m->b + 0xC0, -0.09375f);
                                    vec_add_ba(&sp90, m->b + 0x10, &spB0);
                                    func_L01_00458A08(m, func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]));
                                }
                                if ((t > 8.0f) && (t < 16.0f)) {
                                    func_003BEC60(&sp90.f[2], func_003BE7F0(m->b + 0x10, 0, 0, 0.5f) + D_L06_001DD2D0_00349B48, pv->b + 0x8E0, (D_L06_001DD2D0_00349B48 * 0.125f) / 1.05f, (D_L06_001DD2D0_00349B48 * 0.125f) / 2.1f, D_L06_001DD2D0_00349B48 * 0.125f);
                                }
                                if (t == 16.0f) {
                                    pv->i[0x8E0/4] = 0;
                                }
                                if ((t > 16.0f) && (t < 24.0f)) {
                                    f32 h = 0.5f;
                                    func_003BEC60(&sp90.f[2], func_003BE7F0(m->b + 0x10, 0, 0, h), pv->b + 0x8E0, (D_L06_001DD2D0_00349B48 * 0.125f) / 12.0f, (D_L06_001DD2D0_00349B48 * 0.125f) * h, D_L06_001DD2D0_00349B48 * 0.125f);
                                }
                                if ((t > 8.0f) && (t < 24.0f)) {
                                    vec_sub_ab(&spA0, &sp90, m->b + 0x10);
                                    func_L01_00457728(m, &spA0);
                                }
                                if (func_L01_0044AF40(m, 34.0f) != 0) {
                                    if (m->b[0x43] != 0x1B) {
                                        func_003BE4F0(m, 0x1B, 6, 5);
                                    }
                                    func_L01_00441FB8(m, 0x24, -1);
                                }
                            }
                            break;
                        case 27:                    /* switch 2 */
                            if (m->b[0x42] == 4) {
                                f32 t = func_L01_00436500(m);
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    func_00388830(&spB0, m->b + 0xD0, 0.1125f);
                                    vec_add_ba(&sp90, m->b + 0x10, &spB0);
                                    func_L01_00458A08(m, func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]));
                                }
                                if ((t > 7.0f) && (t < 16.0f)) {
                                    func_003BEC60(&sp90.f[2], func_003BE7F0(m->b + 0x10, 0, 0, 0.5f) + 2.0f, pv->b + 0x8E0, 0.22222222f, 0.22222222f, 0.22222222f);
                                }
                                if (t == 16.0f) {
                                    pv->i[0x8E0/4] = 0;
                                }
                                if ((t > 16.0f) && (t < 23.0f)) {
                                    func_003BEC60(&sp90.f[2], func_003BE7F0(m->b + 0x10, 0, 0, 0.5f), pv->b + 0x8E0, 0.023809524f, 0.14285715f, 0.2857143f);
                                }
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    vec_sub_ab(&spA0, &sp90, m->b + 0x10);
                                    func_L01_00457728(m, &spA0);
                                }
                                if (func_L01_0044AF40(m, 36.0f) != 0) {
                                    if (m->b[0x43] != 0x10) {
                                        func_003BE4F0(m, 0x10, 0, 7);
                                    }
                                    func_L01_00441FB8(m, 0x17, -1);
                                    if ((func_00388800(m->b + 0x10, pv->b + 0x220) <= 4.2f) && (func_00389468(m->f[0xF8/4], func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f)) {
                                        if (m->b[0x43] != 0xF) {
                                            func_003BE4F0(m, 0xF, 0xA, 6);
                                        }
                                        func_L01_00441FB8(m, 0x12, -1);
                                    }
                                }
                            }
                            break;
                        case 28:                    /* switch 2 */
                            if (m->b[0x42] == 3) {
                                f32 t = func_L01_00436500(m);
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    func_00388830(&spB0, m->b + 0xD0, -0.1125f);
                                    vec_add_ba(&sp90, m->b + 0x10, &spB0);
                                    func_L01_00458A08(m, func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]));
                                }
                                if ((t > 7.0f) && (t < 16.0f)) {
                                    func_003BEC60(&sp90.f[2], func_003BE7F0(m->b + 0x10, 0, 0, 0.5f) + 2.0f, pv->b + 0x8E0, 0.22222222f, 0.22222222f, 0.22222222f);
                                }
                                if (t == 16.0f) {
                                    pv->i[0x8E0/4] = 0;
                                }
                                if ((t > 16.0f) && (t < 23.0f)) {
                                    func_003BEC60(&sp90.f[2], func_003BE7F0(m->b + 0x10, 0, 0, 0.5f), pv->b + 0x8E0, 0.023809524f, 0.14285715f, 0.2857143f);
                                }
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    vec_sub_ab(&spA0, &sp90, m->b + 0x10);
                                    func_L01_00457728(m, &spA0);
                                }
                                if (func_L01_0044AF40(m, 36.0f) != 0) {
                                    if (m->b[0x43] != 0x10) {
                                        func_003BE4F0(m, 0x10, 0, 7);
                                    }
                                    func_L01_00441FB8(m, 0x17, -1);
                                    if ((func_00388800(m->b + 0x10, pv->b + 0x220) <= 4.2f) && (func_00389468(m->f[0xF8/4], func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f)) {
                                        if (m->b[0x43] != 0xF) {
                                            func_003BE4F0(m, 0xF, 0xA, 6);
                                        }
                                        func_L01_00441FB8(m, 0x12, -1);
                                    }
                                }
                            }
                            break;
                        case 31:                    /* switch 2 */
                            if (func_L01_00452EC8(m) != 0) {
                                pv->f[0x92C/4] = (f32) m->f[0xF8/4];
                                pv->f[0x918/4] = (f32) m->f[0x18/4];
                            }
                            if (m->b[0x42] == 5) {
                                sp90.q = m->q[0x10/16];
                                spA0.q = m->q[0x10/16];
                                spA0.f[2] -= 1.0f;
                                sp90.f[2] += 15.0f;
                                if (func_003CE740(&spA0, &sp90, 0, m, 0) != 0) {
                                    sp90.q = D_L06_001E8460_00349B48;
                                }
                                temp_f0_5 = func_L01_00436500(m);
                                if ((temp_f0_5 > 8.0f) && (temp_f0_5 < 24.0f)) {
                                    spB0.q = m->q[0x10/16];
                                }
                                if ((temp_f0_5 > 8.0f) && (temp_f0_5 < 16.0f)) {
                                    temp_f0_6 = D_L06_001DD2D0_00349B48 * 0.125f;
                                    func_003BEC60(&spB0.f[2], sp90.f[2], (u8 *)pv + 0x8E0, temp_f0_6 / 1.05f, temp_f0_6 / 2.1f, temp_f0_6 * 1.3f);
                                }
                                if (temp_f0_5 == 16.0f) {
                                    pv->i[0x8E0/4] = 0;
                                    m->f[0xF8/4] = func_00389380(m->f[0xF8/4], 3.1415927f);
                                }
                                if ((temp_f0_5 > 16.0f) && (temp_f0_5 < 24.0f)) {
                                    temp_f0_7 = D_L06_001DD2D0_00349B48 * 0.125f;
                                    func_003BEC60(&spB0.f[2], sp90.f[2], (u8 *)pv + 0x8E0, temp_f0_7 / 1.05f, temp_f0_7 / 2.1f, temp_f0_7 * 1.3f);
                                }
                                if (temp_f0_5 > 8.0f) {
                                    if (temp_f0_5 < 24.0f) {
                                        func_003BEBF8((u8 *)m + 0xF4, 3.1415927f, 0.13962635f);
                                    }
                                }
                                if ((temp_f0_5 > 24.0f) && (pv->i[0x930/4] == 0)) {
                                    pv->i[0x8E8/4] = (s32) (pv->i[0x8E8/4] + 1);
                                }
                                if ((temp_f0_5 > 8.0f) && (temp_f0_5 < 24.0f)) {
                                    vec_sub_ba(&spC0, &spB0, m->b + 0x10);
                                    vec_add_ab(m->b + 0x10, m->b + 0x10, &spC0);
                                }
                                if (func_L01_0044AF40(m, 35.0f) != 0) {
                                    if (m->b[0x43] != 8) {
                                        func_003BE4F0(m, 8, 3, 7);
                                    }
                                    func_L01_00441FB8(m, 0x26, -1);
                                    if ((pv->i[0x94C/4] != 0) && (pv->h[0x234/2] != 1)) {
                                        func_L01_00441FB8(m, 2, 0);
                                        if (m->b[0x43] != 0) {
                                            func_003BE4F0(m, 0, 0, 10);
                                        }
                                    }
                                }
                            }
                            break;
                        case 32:                    /* switch 2 */
                            if (func_L01_00452EC8(m) != 0) {
                                pv->f[0x92C/4] = (f32) m->f[0xF8/4];
                                pv->f[0x918/4] = (f32) m->f[0x18/4];
                            }
                            if (m->b[0x42] == 5) {
                                var_f22 = D_L06_001DD2D0_00349B48;
                                                                if (fabs_asm(pv->f[0x918/4] - func_003BE7F0(((u8 *)m + 0x10), 0, 0, 0.1f)) > 16.0f) {
                                    var_f22 = 6.0f;
                                }
                                sp90.q = m->q[0x10/16];
                                spA0.q = m->q[0x10/16];
                                spA0.f[2] += 1.0f;
                                sp90.f[2] -= 5.0f;
                                if (func_003CE740(&spA0, &sp90, 2, m, 0) != 0) {
                                    sp90.q = D_L06_001E8460_00349B48;
                                }
                                temp_f0_8 = func_L01_00436500(m);
                                if ((temp_f0_8 > 8.0f) && (temp_f0_8 < 24.0f)) {
                                    spB0.q = m->q[0x10/16];
                                }
                                if ((temp_f0_8 > 8.0f) && (temp_f0_8 < 16.0f)) {
                                    temp_f0_9 = var_f22 * 0.125f;
                                    func_003BEC60(&spB0.f[2], sp90.f[2], (u8 *)pv + 0x8E0, temp_f0_9 / 1.05f, temp_f0_9 / 2.1f, temp_f0_9 * 1.4f);
                                }
                                if (temp_f0_8 == 16.0f) {
                                    pv->i[0x8E0/4] = 0;
                                    m->f[0xF8/4] = func_00389380(m->f[0xF8/4], 3.1415927f);
                                }
                                if ((temp_f0_8 > 16.0f) && (temp_f0_8 < 24.0f)) {
                                    func_L01_00458A08(m, func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]));
                                    temp_f0_10 = var_f22 * 0.125f;
                                    func_003BEC60(&spB0.f[2], sp90.f[2], (u8 *)pv + 0x8E0, temp_f0_10 / 1.05f, temp_f0_10 / 2.1f, temp_f0_10 * 1.4f);
                                }
                                if (temp_f0_8 > 8.0f) {
                                    if (temp_f0_8 < 24.0f) {
                                        func_003BEBF8((u8 *)m + 0xF4, 0.0f, 0.13962635f);
                                    }
                                }
                                if ((temp_f0_8 > 24.0f) && (pv->i[0x930/4] == 0)) {
                                    pv->i[0x8E8/4] = (s32) (pv->i[0x8E8/4] + 1);
                                }
                                if ((temp_f0_8 > 8.0f) && (temp_f0_8 < 24.0f)) {
                                    vec_sub_ab(&spC0, &spB0, m->b + 0x10);
                                    func_L01_00457728(m, &spC0);
                                }
                                if (func_L01_0044AF40(m, 35.0f) != 0) {
                                    if (m->b[0x43] != 0xF) {
                                        func_003BE4F0(m, 0xF, 0xA, 8);
                                    }
                                    func_L01_00441FB8(m, 0x12, -1);
                                    if (func_00388800(((u8 *)m + 0x10), ((u8 *)pv + 0x220)) > 3.0f) {
                                        if (m->b[0x43] != 0x1B) {
                                            func_003BE4F0(m, 0x1B, 6, 5);
                                        }
                                        func_L01_00441FB8(m, 0x24, -1);
                                    }
                                    if (func_00388800(((u8 *)m + 0x10), ((u8 *)pv + 0x220)) > 6.0f) {
                                        func_L01_00441FB8(m, 0xB, 2);
                                        if (m->b[0x43] != 0xB) {
                                            func_003BE4F0(m, 0xB, 0, 10);
                                        }
                                    }
                                }
                            }
                            break;
                        case 29:                    /* switch 2 */
                            if (func_L01_00452EC8(m) != 0) {
                                pv->q[0x920/16] = m->q[0xD0/16];
                            }
                            if (m->b[0x42] == 4) {
                                f32 t = func_L01_00436500(m);
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    f32 k = 0.1125f;
                                    spA0.q = m->q[0x10/16];
                                    func_00388830(&spB0, pv->b + 0x920, 3.0f);
                                    vec_add_ba(&spB0, m->b + 0x10, &spB0);
                                    if (func_003CE740(m->b + 0x10, &spB0, 0, m, 0) != 0) {
                                        spB0.q = D_L06_001E8460_00349B48;
                                    } else {
                                        spB0.q = m->q[0x10/16];
                                    }
                                    func_L06_00428768(&spA0, &spB0, k + k);
                                }
                                if ((t > 7.0f) && (t < 16.0f)) {
                                    func_003BEC60(&spA0.f[2], pv->f[0x918/4] + 2.0f + 2.0f, pv->b + 0x8E0, 0.22222222f, 0.22222222f, 0.22222222f);
                                }
                                if (t == 16.0f) {
                                    pv->i[0x8E0/4] = 0;
                                }
                                if ((t > 16.0f) && (t < 23.0f)) {
                                    func_003BEC60(&spA0.f[2], pv->f[0x918/4] + 2.0f + 2.0f, pv->b + 0x8E0, 0.22222222f, 0.22222222f, 0.22222222f);
                                }
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    func_003BEBF8(m->b + 0xF0, 1.5707964f, 0.06981318f);
                                }
                                if ((t > 23.0f) && (pv->i[0x930/4] == 0)) {
                                    pv->i[0x8E8/4]++;
                                }
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    vec_sub_ba(&sp90, &spA0, m->b + 0x10);
                                    vec_add_ab(m->b + 0x10, m->b + 0x10, &sp90);
                                }
                                if (func_L01_0044AF40(m, 35.0f) != 0) {
                                    if (m->b[0x43] != 8) {
                                        func_003BE4F0(m, 8, 3, 7);
                                    }
                                    func_L01_00441FB8(m, 0x26, -1);
                                }
                            }
                            break;
                        case 33:                    /* switch 2 */
                            if (func_L01_00452EC8(m) != 0) {
                                pv->q[0x920/16] = m->q[0xE0/16];
                            }
                            if (m->b[0x42] == 4) {
                                f32 t = func_L01_00436500(m);
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    U16_0034A7A8 *a = &sp90;
                                    U16_0034A7A8 *b = &spB0;
                                    u8 *p = m->b + 0x10;
                                    a->q = *(u128_0034A7A8 *)p;
                                    func_00388830(b, pv->b + 0x920, 3.0f);
                                    vec_add_ba(b, p, b);
                                    if (func_003CE740(p, b, 0, m, 0) != 0) {
                                        b->q = D_L06_001E8460_00349B48;
                                    }
                                    func_L06_00428768(a, b, 0.225f);
                                }
                                if ((t > 7.0f) && (t < 16.0f)) {
                                    func_003BEC60(&sp90.f[2], pv->f[0x918/4] + 2.0f, pv->b + 0x8E0, 0.22222222f, 0.22222222f, 0.22222222f);
                                }
                                if (t == 16.0f) {
                                    pv->i[0x8E0/4] = 0;
                                }
                                if ((t > 16.0f) && (t < 23.0f)) {
                                    func_003BEC60(&sp90.f[2], pv->f[0x918/4], pv->b + 0x8E0, 0.22222222f, 0.22222222f, 0.22222222f);
                                }
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    func_003BEBF8(m->b + 0xF0, 0.0f, 0.06981318f);
                                }
                                if ((t > 23.0f) && (pv->i[0x930/4] == 0)) {
                                    pv->i[0x8E8/4]++;
                                }
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    vec_sub_ab(&spA0, &sp90, m->b + 0x10);
                                    func_L01_00457728(m, &spA0);
                                }
                                if (func_L01_0044AF40(m, 35.0f) != 0) {
                                    func_L01_00441FB8(m, 0xB, 2);
                                    if (m->b[0x43] != 0xB) {
                                        func_003BE4F0(m, 0xB, 0, 10);
                                    }
                                    if (pv->i[0x930/4] != 0) {
                                        func_L01_00441FB8(m, 0xA, -1);
                                        if (m->b[0x43] != 0xE) {
                                            func_003BE4F0(m, 0xE, 0, 10);
                                        }
                                    }
                                }
                            }
                            break;
                        case 30:                    /* switch 2 */
                            if (func_L01_00452EC8(m) != 0) {
                                pv->q[0x920/16] = m->q[0xD0/16];
                            }
                            if (m->b[0x42] == 3) {
                                f32 t = func_L01_00436500(m);
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    f32 k = 0.1125f;
                                    sp90.q = m->q[0x10/16];
                                    func_00388830(&spB0, pv->b + 0x920, -3.0f);
                                    vec_add_ba(&spB0, m->b + 0x10, &spB0);
                                    if (func_003CE740(m->b + 0x10, &spB0, 0, m, 0) != 0) {
                                        spB0.q = D_L06_001E8460_00349B48;
                                    } else {
                                        spB0.q = m->q[0x10/16];
                                    }
                                    func_L06_00428768(&sp90, &spB0, k + k);
                                }
                                if ((t > 7.0f) && (t < 16.0f)) {
                                    func_003BEC60(&sp90.f[2], pv->f[0x918/4] + 2.0f + 2.0f, pv->b + 0x8E0, 0.22222222f, 0.22222222f, 0.22222222f);
                                }
                                if (t == 16.0f) {
                                    pv->i[0x8E0/4] = 0;
                                }
                                if ((t > 16.0f) && (t < 23.0f)) {
                                    func_003BEC60(&sp90.f[2], pv->f[0x918/4] + 2.0f + 2.0f, pv->b + 0x8E0, 0.22222222f, 0.22222222f, 0.22222222f);
                                }
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    func_003BEBF8(m->b + 0xF0, -1.5707964f, 0.06981318f);
                                }
                                if ((t > 23.0f) && (pv->i[0x930/4] == 0)) {
                                    pv->i[0x8E8/4]++;
                                }
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    vu0_q a, b, c, d, e, f, g;
                                    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(vu0_v4 *)(m->b + 0x10)));
                                    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(vu0_v4 *)&sp90));
                                    __asm__("vsub.xyz %0, %1, %2" : "=j"(c) : "j"(b), "j"(a));
                                    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)&spA0) : "j"(c));
                                    __asm__("lqc2 %0, %1" : "=j"(d) : "m"(*(vu0_v4 *)(m->b + 0x10)));
                                    __asm__("lqc2 %0, %1" : "=j"(e) : "m"(*(vu0_v4 *)&spA0));
                                    __asm__("vadd.xyz %0, %1, %2" : "=j"(g) : "j"(e), "j"(d));
                                    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(m->b + 0x10)) : "j"(g));
                                }
                                if (func_L01_0044AF40(m, 35.0f) != 0) {
                                    if (m->b[0x43] != 8) {
                                        func_003BE4F0(m, 8, 3, 7);
                                    }
                                    func_L01_00441FB8(m, 0x26, -1);
                                }
                            }
                            break;
                        case 34:                    /* switch 2 */
                            if (func_L01_00452EC8(m) != 0) {
                                pv->q[0x920/16] = m->q[0xE0/16];
                            }
                            if (m->b[0x42] == 3) {
                                f32 t = func_L01_00436500(m);
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    U16_0034A7A8 *a = &sp90;
                                    U16_0034A7A8 *b = &spB0;
                                    u8 *p = m->b + 0x10;
                                    a->q = *(u128_0034A7A8 *)p;
                                    func_00388830(b, pv->b + 0x920, 3.0f);
                                    vec_add_ba(b, p, b);
                                    if (func_003CE740(p, b, 0, m, 0) != 0) {
                                        b->q = D_L06_001E8460_00349B48;
                                    }
                                    func_L06_00428768(a, b, 0.225f);
                                }
                                if ((t > 7.0f) && (t < 16.0f)) {
                                    func_003BEC60(&sp90.f[2], pv->f[0x918/4] + 2.0f, pv->b + 0x8E0, 0.22222222f, 0.22222222f, 0.22222222f);
                                }
                                if (t == 16.0f) {
                                    pv->i[0x8E0/4] = 0;
                                }
                                if ((t > 16.0f) && (t < 23.0f)) {
                                    func_003BEC60(&sp90.f[2], pv->f[0x918/4], pv->b + 0x8E0, 0.22222222f, 0.22222222f, 0.22222222f);
                                }
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    func_003BEBF8(m->b + 0xF0, 0.0f, 0.06981318f);
                                }
                                if ((t > 23.0f) && (pv->i[0x930/4] == 0)) {
                                    pv->i[0x8E8/4]++;
                                }
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    vec_sub_ab(&spA0, &sp90, m->b + 0x10);
                                    func_L01_00457728(m, &spA0);
                                }
                                if (func_L01_0044AF40(m, 35.0f) != 0) {
                                    func_L01_00441FB8(m, 0xB, 2);
                                    if (m->b[0x43] != 0xB) {
                                        func_003BE4F0(m, 0xB, 0, 10);
                                    }
                                    if (pv->i[0x930/4] != 0) {
                                        func_L01_00441FB8(m, 0xA, -1);
                                        if (m->b[0x43] != 0xE) {
                                            func_003BE4F0(m, 0xE, 0, 10);
                                        }
                                    }
                                }
                            }
                            break;
                        case 38:                    /* switch 2 */
                            if (m->b[0x60] & 2) {
                                if (m->b[0x43] != 9) {
                                    func_003BE4F0(m, 9, 0, 6);
                                }
                                func_L01_00441FB8(m, 0x27, -1);
                                break;
                            }
                            break;
                        case 39:                    /* switch 2 */
                            if (func_L01_00452EC8(m) != 0) {
                                func_L01_00458A70(m, 0.0033333334f, 0.06666667f, 0.0069813174f, 0.20943953f);
                                pv->i[0xA8/4] = (s32) (pv->i[0xA8/4] | 4);
                                pv->f[0x78/4] = 0.7f;
                                pv->f[0x7C/4] = 0.7f;
                                m->uh[0x34/2] = (u16) (m->uh[0x34/2] | 0x100);
                                pv->f[0x80/4] = 12.566371f;
                                pv->i[0xA8/4] = (s32) (pv->i[0xA8/4] | 1);
                            }
                            func_00388830(&sp90, (u8 *)m + 0xC0, 7.0f);
                            vec_add_ba(&sp90, m->b + 0x10, &sp90);
                            func_L01_00459F10(m, (u8 *)pv + 0x220);
                            if ((func_00388800(m->b + 0x10, pv->b + 0x220) < 13.0f) && (pv->i[0x90C/4] == 0)) {
                                if (m->b[0x43] != 0xA) {
                                    func_003BE4F0(m, 0xA, 2, 3);
                                }
                                func_L01_00441FB8(m, 0x28, -1);
                            }
                            if (pv->i[0x90C/4] != 0) {
                                if (func_00388800(m->b + 0x10, pv->b + 0x220) < 2.5f) {
                                    if (m->b[0x43] != 0xA) {
                                        func_003BE4F0(m, 0xA, 2, 3);
                                    }
                                    func_L01_00441FB8(m, 0x28, -1);
                                    break;
                                }
                            }
                            break;
                        case 40:                    /* switch 2 */
                            if (func_L01_00452EC8(m) != 0) {
                                m->uh[0x34/2] = (u16) (m->uh[0x34/2] & 0xFEFF);
                                pv->f[0x74/4] = 0.5f;
                                pv->f[0x70/4] = 0.7f;
                                pv->f[0x78/4] = 0.5f;
                                pv->f[0x7C/4] = 1.0f;
                                pv->f[0x80/4] = 0.7853982f;
                                pv->f[0xA0/4] = 0.34906584f;
                                pv->f[0x9C/4] = 0.0027222224f;
                                pv->i[0xA8/4] &= ~4;
                                pv->i[0xA8/4] &= ~1;
                            }
                            if ((func_L01_0044AF40(m, 8.0f) != 0) && (m->b[0x42] == 0xA)) {
                                if (m->b[0x43] != 0) {
                                    func_003BE4F0(m, 0, 0, 10);
                                }
                                func_L01_00441FB8(m, 0x23, -1);
                                if (pv->i[0x90C/4] != 0) {
                                    sp90.q = m->q[0x10/16];
                                    spA0.q = m->q[0x10/16];
                                    spA0.f[2] += 1.0f;
                                    sp90.f[2] -= 5.0f;
                                    if (func_003CE740(&spA0, &sp90, 0, m, 0) != 0) {
                                        if (D_L06_001E8458_00349B48 == 0) {
                                            func_L01_00441FB8(m, 0x20, -1);
                                            if (m->b[0x43] != 5) {
                                                func_003BE4F0(m, 5, 5, 4);
                                            }
                                        }
                                    } else {
                                        func_L01_00441FB8(m, 0x20, -1);
                                        if (m->b[0x43] != 5) {
                                            func_003BE4F0(m, 5, 5, 4);
                                        }
                                    }
                                }
                                temp_a0_4 = pv->i[0x908/4];
                                if (temp_a0_4 == 1) {
                                    func_L01_00441FB8(m, 0x21, -1);
                                    if (m->b[0x43] != 4) {
                                        func_003BE4F0(m, 4, 0, 6);
                                    }
                                } else if (temp_a0_4 == 2) {
                                    func_L01_00441FB8(m, 0x22, -1);
                                    if (m->b[0x43] != 3) {
                                        func_003BE4F0(m, 3, 0, 6);
                                    }
                                }
                            }
                            break;
                        case 35:                    /* switch 2 */
                            sp90.q = m->q[0x10/16];
                            spA0.q = m->q[0x10/16];
                            spA0.f[2] += 1.0f;
                            sp90.f[2] -= 5.0f;
                            if (func_003CE740(&spA0, &sp90, 0, m, 0) != 0) {
                                if (D_L06_001E8458_00349B48 == 0) {
                                    func_L01_00441FB8(m, 0x20, -1);
                                    if (m->b[0x43] != 5) {
                                        func_003BE4F0(m, 5, 5, 4);
                                    }
                                }
                            } else {
                                func_L01_00441FB8(m, 0x20, -1);
                                if (m->b[0x43] != 5) {
                                    func_003BE4F0(m, 5, 5, 4);
                                }
                            }
                            break;
                        case 10:                    /* switch 2 */
                            if ((func_L01_00436500(m) > 12.0f) && (m->b[0x42] == 0xE)) {
                                pv->i[0x8E8/4] = (s32) (pv->i[0x8E8/4] + 1);
                            }
                            if ((func_L01_0044AF40(m, 25.0f) != 0) && (m->b[0x42] == 0xE)) {
                                pv->i[0x8E8/4] = (s32) (pv->i[0x8E8/4] + 1);
                                func_L01_00441FB8(m, 0xB, -1);
                                if (m->b[0x43] != 0xB) {
                                    func_003BE4F0(m, 0xB, 0, 6);
                                }
                            }
                            break;
                        case 11:                    /* switch 2 */
                            if (func_L01_00452EC8(m) != 0) {
                                func_L01_00458A70(m, 0.005f, 0.13333334f, 0.0069813174f, 0.20943953f);
                                pv->f[0xA4/4] = 2.5f;
                            }
                            if (m->b[0x60] & 2) {
                                func_L01_00441FB8(m, 0xC, -1);
                                if (m->b[0x43] != 0xC) {
                                    temp_s0_6 = func_0037E1D8(3);
                                    func_003BE4F0(m, 0xC, temp_s0_6, func_0037E1D8(4));
                                }
                                temp_v1_2 = pv->i[0x944/4];
                                if (temp_v1_2 != -1) {
                                    func_L01_00441FB8(m, 0x10, -1);
                                    break;
                                }
                                temp_a0_5 = pv->i[0x974/4];
                                if ((temp_a0_5 != temp_v1_2) && (D_L06_001DEA4C_00349B48->e[temp_a0_5].cnt != 0)) {
                                    func_L01_00441FB8(m, 0x16, -1);
                                    break;
                                }
                            }
                            break;
                        case 12:                    /* switch 2 */
                            if (func_L01_00452EC8(m) != 0) {
                                if ((m->b[0x21] != 0xFF) && (pv->b[0x5F] == 0)) {
                                    func_L01_00442AA8(m->b[0x21], 1);
                                    m->b[0xBC] = 0;
                                }
                                func_L01_00455E98(m, pv->p[0x230/4], pv->b + 0x9A0);
                            }
                            func_L01_00455C88(m, pv->b + 0x9A0, 0, 0);
                            func_L01_00457440(m, pv->b + 0x9A0);
                            if (pv->p[0x230/4] != pv->p[0x9F0/4]) {
                                func_L01_00455E98(m, pv->p[0x230/4], pv->b + 0x9A0);
                            }
                            if (func_00388800(pv->b + 0x9A0, pv->b + 0x220) < 1.0f) {
                                pv->f[0xA4/4] = 2.5f;
                            } else {
                                pv->f[0xA4/4] = 0.5f;
                            }
                            if (((func_00388800(m->b + 0x10, pv->b + 0x220) < 3.5f) && (func_L01_0044AF40(m, 14.0f) != 0)) || (m->b[0xBC] != 0)) {
                                pv->f[0xA4/4] = 1.5f;
                                func_L01_00441FB8(m, 0xD, -1);
                                if (m->b[0x43] != 0xD) {
                                    func_003BE4F0(m, 0xD, 0, 5);
                                }
                            }
                            break;
                        case 13:                    /* switch 2 */
                            if (pv->i[0x930/4] == 0) {
                                pv->i[0x8E8/4] = (s32) (pv->i[0x8E8/4] + 1);
                            }
                            if ((func_L01_0044AF40(m, 3.0f) != 0) && (m->b[0x42] == 0xD)) {
                                if (m->b[0x43] != 0x1C) {
                                    func_003BE4F0(m, 0x1C, 0, 6);
                                }
                                func_L01_00441FB8(m, 0x14, -1);
                                if ((pv->i[0x930/4] != 0) && (pv->i[0x8E8/4] == 0)) {
                                    func_L01_00441FB8(m, 0xA, 2);
                                    if (m->b[0x43] != 0xE) {
                                        func_003BE4F0(m, 0xE, 0, 10);
                                    }
                                }
                                if (m->b[0xBC] != 0) {
                                    if (m->b[0x43] != 0) {
                                        func_003BE4F0(m, 0, 0, 8);
                                    }
                                    func_L01_00441FB8(m, 9, -1);
                                }
                                temp_a0_6 = pv->i[0x974/4];
                                if ((temp_a0_6 != -1) && (D_L06_001DEA4C_00349B48->e[temp_a0_6].cnt != 0)) {
                                    func_L01_00441FB8(m, 0x15, -1);
                                    if (m->b[0x43] != 0x14) {
                                        func_003BE4F0(m, 0x14, 0, 0xF);
                                    }
                                }
                            }
                            break;
                        case 9:                     /* switch 2 */
                            if (m->b[0xBC] == 0) {
                                func_L01_00441FB8(m, 0xB, -1);
                                if (m->b[0x43] != 0xB) {
                                    func_003BE4F0(m, 0xB, 0, 6);
                                }
                            }
                            if (m->b[0x42] == 0) {
                                if (func_0037E1D8(3) == 0) {
                                    if (m->b[0x43] != 0x10) {
                                        func_003BE4F0(m, 0x10, 0, 8);
                                    }
                                } else if (func_0037E1D8(2) != 0) {
                                    if (m->b[0x43] != 0x11) {
                                        func_003BE4F0(m, 0x11, 0, 8);
                                    }
                                } else if (m->b[0x43] != 0xE) {
                                    func_003BE4F0(m, 0xE, 0, 10);
                                }
                            }
                            if ((m->b[0x42] == 0xE) && (m->b[0x60] & 2)) {
                                if (func_0037E1D8(2) == 0) {
                                    if (m->b[0x43] != 0x10) {
                                        func_003BE4F0(m, 0x10, 0, 8);
                                    }
                                } else if (m->b[0x43] != 0x11) {
                                    func_003BE4F0(m, 0x11, 0, 8);
                                }
                            }
                            if ((m->b[0x42] == 0x10) && (m->b[0x60] & 2)) {
                                if (func_0037E1D8(2) == 0) {
                                    if (m->b[0x43] != 0xE) {
                                        func_003BE4F0(m, 0xE, 0, 8);
                                    }
                                } else if (m->b[0x43] != 0x11) {
                                    func_003BE4F0(m, 0x11, 0, 8);
                                }
                            }
                            if ((m->b[0x42] == 0x11) && (m->b[0x60] & 2)) {
                                func_0037E1D8(2);
                                if (m->b[0x43] != 0x10) {
                                    func_003BE4F0(m, 0x10, 0, 8);
                                }
                            }
                            break;
                        case 14:                    /* switch 2 */
                            if (func_L01_00452EC8(m) != 0) {
                                func_L01_00458A70(m, 0.0022222223f, 0.033333335f, 0.0069813174f, 0.20943953f);
                                pv->f[0xA4/4] = 2.5f;
                            }
                            func_L01_00457440(m, (u8 *)pv + 0x220);
                            if (func_00388800(((u8 *)m + 0x10), ((u8 *)pv + 0x220)) <= 2.5f) {
                                if (func_00389468(m->f[0xF8/4], func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f) {
                                    if (m->b[0x43] != 0x1C) {
                                        func_003BE4F0(m, 0x1C, 4, 6);
                                    }
                                    func_L01_00441FB8(m, 0x14, -1);
                                }
                            }
                            if ((func_00388800(((u8 *)m + 0x10), ((u8 *)pv + 0x220)) > 6.0f) || ((u16) m->uh[0x96/2] >= 0x12DU)) {
                                func_L01_00441FB8(m, 0xB, 2);
                                if (m->b[0x43] != 0xB) {
                                    func_003BE4F0(m, 0xB, 0, 10);
                                }
                            }
                            if (m->b[0xBC] != 0) {
                                func_L01_00441FB8(m, 9, -1);
                                if (m->b[0x43] != 0) {
                                    func_003BE4F0(m, 0, 0, 10);
                                }
                            }
                            break;
                        case 16:                    /* switch 2 */
                            if (pv->i[0x970/4] != 0) {
                                if (func_L01_00452EC8(m) != 0) {
                                    if (m->b[0x43] != 6) {
                                        func_003BE4F0(m, 6, 0, 8);
                                    }
                                    func_L01_00458A70(m, 0.0022222223f, 0.033333335f, 0.0069813174f, 0.20943953f);
                                    pv->f[0xA4/4] = 2.5f;
                                }
                                if (func_L01_00458AE0(m, pv->i[0x944/4]) == 0) {
                                    break;
                                }
                                if (pv->i[0x930/4] == 0) {
                                    pv->i[0x944/4] = -1;
                                    func_L01_00441FB8(m, 0xE, -1);
                                    if (m->b[0x43] != 6) {
                                        func_003BE4F0(m, 6, 0, 8);
                                    }
                                }
                                if (pv->i[0x930/4] != 0) {
                                    pv->i[0x944/4] = -1;
                                    func_L01_00441FB8(m, 0xA, 2);
                                    if (m->b[0x43] != 0xE) {
                                        func_003BE4F0(m, 0xE, 0, 10);
                                    }
                                }
                                if (func_00388800(m->b + 0x10, pv->b + 0x220) < 3.5f) {
                                    pv->i[0x944/4] = -1;
                                    pv->f[0xA4/4] = 1.5f;
                                    if (m->b[0x43] != 0x1C) {
                                        func_003BE4F0(m, 0x1C, 0, 6);
                                    }
                                    func_L01_00441FB8(m, 0x14, -1);
                                    break;
                                }
                                {
                                s32 n = pv->i[0x974/4];
                                if ((n != -1) && (D_L06_001DEA4C_00349B48->e[n].cnt != 0)) {
                                    func_L01_00441FB8(m, 0x16, -1);
                                }
                                }
                            } else {
                                if (func_L01_00458AE0(m, pv->i[0x944/4]) != 0) {
                                    if (pv->i[0x930/4] == 0) {
                                        pv->i[0x944/4] = -1;
                                        func_L01_00441FB8(m, 0xC, -1);
                                    }
                                    if ((pv->i[0x930/4] != 0) && (func_L01_0044AF40(m, 14.0f) != 0)) {
                                        pv->i[0x944/4] = -1;
                                        func_L01_00441FB8(m, 0xD, -1);
                                        if (m->b[0x43] != 0xD) {
                                            func_003BE4F0(m, 0xD, 0, 5);
                                        }
                                    }
                                    {
                                    s32 n = pv->i[0x974/4];
                                    if ((n != -1) && (D_L06_001DEA4C_00349B48->e[n].cnt != 0)) {
                                        func_L01_00441FB8(m, 0x16, -1);
                                    }
                                    }
                                }
                                if ((func_00388800(m->b + 0x10, pv->b + 0x220) < 3.5f) && (func_L01_0044AF40(m, 14.0f) != 0)) {
                                    pv->i[0x944/4] = -1;
                                    pv->f[0xA4/4] = 1.5f;
                                    func_L01_00441FB8(m, 0xD, -1);
                                    if (m->b[0x43] != 0xD) {
                                        func_003BE4F0(m, 0xD, 0, 5);
                                    }
                                }
                            }
                            break;
                        case 15:                    /* switch 2 */
                            if (func_L01_00452EC8(m) != 0) {
                                func_L01_00458A70(m, 0.0033333334f, 0.06666667f, 0.0069813174f, 0.20943953f);
                                pv->f[0xA4/4] = 2.5f;
                                func_L01_00455E98(m, pv->p[0x230/4], ((u8 *)pv + 0x9A0));
                            }
                            func_L01_00455C88(m, ((u8 *)pv + 0x9A0), 0, 0);
                            func_L01_00457440(m, ((u8 *)pv + 0x9A0));
                            temp_a1_3 = pv->p[0x230/4];
                            if (temp_a1_3 != pv->i[0x9F0/4]) {
                                func_L01_00455E98(m, temp_a1_3, ((u8 *)pv + 0x9A0));
                            }
                            temp_s1_3 = (u8 *)pv + 0x220;
                            if ((func_00388800(((u8 *)m + 0x10), temp_s1_3) <= 2.5f) && (func_00389468(m->f[0xF8/4], func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f)) {
                                if (m->b[0x43] != 0xF) {
                                    func_003BE4F0(m, 0xF, 0, 6);
                                }
                                func_L01_00441FB8(m, 0x12, -1);
                            }
                            if (func_00388800(((u8 *)m + 0x10), temp_s1_3) > 8.0f) {
                                func_L01_00441FB8(m, 0xB, 2);
                                if (m->b[0x43] != 0xB) {
                                    func_003BE4F0(m, 0xB, 0, 10);
                                }
                            }
                            if (m->b[0xBC] != 0) {
                                func_L01_00441FB8(m, 9, -1);
                                if (m->b[0x43] != 0) {
                                    func_003BE4F0(m, 0, 0, 10);
                                }
                            }
                            break;
                        case 17:                    /* switch 2 */
                            if (func_L01_00452EC8(m) != 0) {
                                func_L01_00458A70(m, 0.0033333334f, 0.06666667f, 0.0069813174f, 0.20943953f);
                            }
                            temp_s0_10 = (u8 *)&D_L06_001DEE80_00349B48[pv->i[0x95C/4]].pos;
                            var_a1_9 = temp_s0_10;
                            if (func_00388800((u8 *)m + 0x10, temp_s0_10) <= 1.0f) {
                                if (!(func_00389468(m->f[0xF8/4], func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f)) {
                                    temp_v0_8 = pv->p[0x230/4];
                                    func_L01_00458A08(m, func_00388A28(((G_0034A7A8 *)(temp_v0_8))->f[0x10/4] - m->f[0x10/4], ((G_0034A7A8 *)(temp_v0_8))->f[0x14/4] - m->f[0x14/4]));
                                } else {
                                    func_L01_00441FB8(m, 0x15, -1);
                                    if (m->b[0x43] != 0x14) {
                                        func_003BE4F0(m, 0x14, 0, 0xF);
                                    }
                                }
                            } else {
                                func_L01_00457440(m, var_a1_9);
                            }
                            break;
                        case 22:                    /* switch 2 */
                            if (func_L01_00452EC8(m) != 0) {
                                s32 n;
                                func_L01_00458A70(m, 0.005f, 0.13333334f, 0.0069813174f, 0.20943953f);
                                n = pv->i[0x974/4];
                                if ((n != -1) && (D_L06_001DEA4C_00349B48->e[n].cnt != 0)) {
                                    s32 k;
                                    *(u128_0034A7A8 *)(pv->b + 0x980) = *(u128_0034A7A8 *)((u8 *)D_L06_001DEE80_00349B48 + (**(s32 **)((u8 *)D_L06_001DEA4C_00349B48 + n * 0x30 + 0x40) << 7) + 0x30);
                                    for (k = 0; k < D_L06_001DEA4C_00349B48->e[pv->i[0x974/4]].cnt; k++) {
                                        E80_0034A7A8 *e = &D_L06_001DEE80_00349B48[D_L06_001DEA4C_00349B48->e[pv->i[0x974/4]].list[k]];
                                        f32 d = func_00388800(&e->pos, pv->b + 0x220);
                                        if (((func_00388800(pv->b + 0x980, pv->b + 0x220) < d) || (func_00388800(m->b + 0x10, pv->b + 0x980) < 2.0f)) && (func_00388800(m->b + 0x10, &e->pos) > 2.0f)) {
                                            pv->q[0x980/16] = e->pos;
                                        }
                                    }
                                }
                                pv->f[0xA4/4] = 0.5f;
                            }
                            if (func_00388800(m->b + 0x10, pv->b + 0x980) < 1.0f) {
                                func_L01_00458A08(m, func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]));
                                if (func_00389468(m->f[0xF8/4], func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.27925268f) {
                                    func_L01_00441FB8(m, 0xD, -1);
                                    if (m->b[0x43] != 0xD) {
                                        func_003BE4F0(m, 0xD, 0, 5);
                                    }
                                }
                            } else {
                                func_L01_00457440(m, pv->b + 0x980);
                            }
                            break;
                        case 18:                    /* switch 2 */
                            func_003BDA38(m, 0, &sp90);
                            func_003BDA38(m, 1, &spA0);
                            temp_a1_5 = D_L06_001DD2D8_00349B48;
                            temp_s2 = ((pv->i[0x8DC/4] - 2 + temp_a1_5) % temp_a1_5) * 0x10;
                            vec_sub_ab(&spB0, pv->b + 0x2C0 + pv->i[0x8DC/4] * 0x10, pv->b + 0x2C0 + temp_s2);
                            func_00388830(&spB0, &spB0, 2.5f);
                            spB0.f[2] = 1.0f;
                            spB0.f[3] = 5627.925f;
                            func_L01_00443628(&spC0, m, temp_s7, (f32) pv->b[0x44], &spB0);
                            spD0.c[9] = 1;
                            spD0.uh[5] = m->uh[0xAA/2];
                            spD0.c[8] = 0;
                            ((s32 (*)(void *, void *, s32, void *, void *))func_003CE740)(&sp90, &spA0, 9, m, &spC0);
                            {
                            vu0_q a, b, c, d, e;
                            __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(vu0_v4 *)(m->b + 0x10)));
                            __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(vu0_v4 *)(pv->b + 0x2C0 + temp_s2)));
                            __asm__("lqc2 %0, %1" : "=j"(c) : "m"(*(vu0_v4 *)(m->b + 0x10)));
                            __asm__("vsub.xyz %0, %1, %2" : "=j"(d) : "j"(b), "j"(a));
                            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(&sp110)) : "j"(d));
                            __asm__("lqc2 %0, %1" : "=j"(e) : "m"(*(vu0_v4 *)(&spA0)));
                            __asm__("vsub.xyz %0, %1, %2" : "=j"(e) : "j"(e), "j"(c));
                            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(&spF0)) : "j"(e));
                            }
                            func_L01_00449008(&sp100, &sp110, &spF0, 0, 0.2f);
                            vec_add_ab(&sp100, &sp100, m->b + 0x10);
                            ((s32 (*)(void *, void *, s32, void *, void *))func_003CE740)(&sp90, &sp100, 9, m, &spC0);
                            func_L01_00449008(&sp100, &sp110, &spF0, 0, 0.4f);
                            vec_add_ab(&sp100, &sp100, m->b + 0x10);
                            ((s32 (*)(void *, void *, s32, void *, void *))func_003CE740)(&sp90, &sp100, 9, m, &spC0);
                            func_L01_00449008(&sp100, &sp110, &spF0, 0, 0.6f);
                            vec_add_ab(&sp100, &sp100, m->b + 0x10);
                            ((s32 (*)(void *, void *, s32, void *, void *))func_003CE740)(&sp90, &sp100, 9, m, &spC0);
                            func_L01_00449008(&sp100, &sp110, &spF0, 0, 0.8f);
                            vec_add_ab(&sp100, &sp100, m->b + 0x10);
                            ((s32 (*)(void *, void *, s32, void *, void *))func_003CE740)(&sp90, &sp100, 9, m, &spC0);
                            ((s32 (*)(void *, void *, s32, void *, void *))func_003CE740)(&sp90, pv->b + (temp_s2 + 0x2C0), 9, m, &spC0);
                            if ((func_L01_0044AF40(m, 30.0f) != 0) && (m->b[0x42] == 0xF) && (((G_0034A7A8 *)D_001A4BE0)->i[0x2850/4] > 0)) {
                                if (func_0037E1D8(4) == 0) {
                                    if (func_0037E1D8(2) != 0) {
                                        if (m->b[0x43] != 0x11) {
                                            func_003BE4F0(m, 0x11, 0xD, 8);
                                        }
                                    } else if (m->b[0x43] != 0x10) {
                                        func_003BE4F0(m, 0x10, 0xA, 10);
                                    }
                                    func_L01_00441FB8(m, 0x17, -1);
                                    if (((G_0034A7A8 *)D_001A4BE0)->p[0x2808/4] == m) {
                                        if (func_00389468(m->f[0xF8/4], func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.61086524f) {
                                            func_L01_00441FB8(m, 0x15, -1);
                                            if (m->b[0x43] != 0x14) {
                                                func_003BE4F0(m, 0x14, 0, 0xF);
                                            }
                                        }
                                    }
                                }
                                if (((G_0034A7A8 *)D_001A4BE0)->p[0x2808/4] != m) {
                                    if ((func_00388800(m->b + 0x10, (u8 *)pv + 0x220) <= 2.5f) && (func_00389468(m->f[0xF8/4], func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f)) {
                                        if (m->b[0x43] != 0x13) {
                                            func_003BE4F0(m, 0x13, 0xA, 6);
                                        }
                                        func_L01_00441FB8(m, 0x13, -1);
                                        break;
                                    }
                                }
                            } else if (m->b[0x60] & 2) {
                                if ((func_00388800((u8 *)m + 0x10, (u8 *)pv + 0x220) <= 2.5f) && (func_00389468(m->f[0xF8/4], func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f)) {
                                    if (m->b[0x43] != 0x13) {
                                        func_003BE4F0(m, 0x13, 8, 8);
                                    }
                                    func_L01_00441FB8(m, 0x13, -1);
                                    break;
                                }
                                if (m->b[0x43] != 6) {
                                    func_003BE4F0(m, 6, 0, 10);
                                }
                                func_L01_00441FB8(m, 0xE, -1);
                                if (func_0037E1D8(5) == 0) {
                                    if (m->b[0x43] != 0x1B) {
                                        func_003BE4F0(m, 0x1B, 6, 5);
                                    }
                                    func_L01_00441FB8(m, 0x24, -1);
                                }
                                if ((((G_0034A7A8 *)D_001A4BE0)->p[0x2808/4] == m) && (func_00389468(m->f[0xF8/4], func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.61086524f)) {
                                    func_L01_00441FB8(m, 0x15, -1);
                                    if (m->b[0x43] != 0x14) {
                                        func_003BE4F0(m, 0x14, 0, 0xF);
                                    }
                                }
                            }
                            break;
                        case 20:                    /* switch 2 */
                            if ((func_L01_0044AF40(m, 30.0f) != 0) && (m->b[0x42] == 0x1C) && (((G_0034A7A8 *)D_001A4BE0)->i[0x2850/4] > 0)) {
                                if ((((G_0034A7A8 *)D_001A4BE0)->p[0x2808/4] != m) && (func_00388800((u8 *)m + 0x10, (u8 *)pv + 0x220) <= 2.5f) && (func_00389468(m->f[0xF8/4], func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f)) {
                                    func_L01_00441FB8(m, 0x13, -1);
                                    if (m->b[0x43] != 0x13) {
                                        func_003BE4F0(m, 0x13, 8, 6);
                                    }
                                } else {
                                    if (m->b[0x43] != 0x1B) {
                                        func_003BE4F0(m, 0x1B, 0, 0xF);
                                    }
                                    func_L01_00441FB8(m, 0x24, -1);
                                }
                            }
                            if ((func_L01_00436500(m) > 12.0f) && (m->b[0x42] == 0x1C)) {
                                func_L01_00443790(m, 8, 0.25f, (f32) pv->b[0x45], temp_s7, 2.5f, 0, 1, 0);
                                func_L01_00443790(m, 9, 0.45f, (f32) pv->b[0x45], temp_s7, 2.5f, 0, 1, 0);
                                func_L01_00443790(m, 7, 0.75f, (f32) pv->b[0x45], temp_s7, 2.5f, 0, 1, 0);
                            }
                            break;
                        case 19:                    /* switch 2 */
                            if (m->b[0x42] != m->b[0x43]) {
                                temp_v0_9 = pv->p[0x230/4];
                                func_L01_00458A08(m, func_00388A28(((G_0034A7A8 *)(temp_v0_9))->f[0x10/4] - m->f[0x10/4], ((G_0034A7A8 *)(temp_v0_9))->f[0x14/4] - m->f[0x14/4]));
                            }
                            if (func_L01_00436500(m) < 20.0f) {
                                func_L01_00443790(m, 4, 0.3f, (f32) pv->b[0x46], temp_s7, 2.0f, 0, 1, 0);
                            }
                            if ((func_L01_0044AF40(m, 25.0f) != 0) && (m->b[0x42] == 0x13) && (((G_0034A7A8 *)D_001A4BE0)->i[0x2850/4] > 0)) {
                                if (((G_0034A7A8 *)D_001A4BE0)->p[0x2808/4] != m) {
                                    func_L01_00441FB8(m, 0x1A, -1);
                                    if (m->b[0x43] != 5) {
                                        func_003BE4F0(m, 5, 5, 4);
                                    }
                                    break;
                                }
                                if (m->b[0x43] != 0x1B) {
                                    func_003BE4F0(m, 0x1B, 0, 0xF);
                                }
                                func_L01_00441FB8(m, 0x24, -1);
                                break;
                            }
                            break;
                        case 21:                    /* switch 2 */
                            if ((func_L01_0044AF40(m, 15.5f) != 0) && (m->b[0x42] == 0x14)) {
                                func_003BDA38(m, 4, &spA0);
                                vec_sub_ab(&sp90, pv->b + 0x220, &spA0);
                                func_00388830(&sp90, &sp90, 0.4166667f);
                                if (pv->b[0x5F] != 0) {
                                    func_00388830(&sp90, &sp90, 0.8333334f);
                                }
                                func_L06_003577D0(m, &sp90, &spA0, (u8 *)m + 0xF0, 1, 0, (f32) pv->b[0x46]);
                            }
                            if (func_L01_0044AF40(m, 26.0f) != 0) {
                                if (m->b[0x42] == 0x14) {
                                    temp_s1_5 = (u8 *)pv + 0x220;
                                    if (func_00388800(((u8 *)m + 0x10), temp_s1_5) > 6.0f) {
                                        func_L01_00441FB8(m, 0xB, 2);
                                        if (m->b[0x43] != 0xB) {
                                            func_003BE4F0(m, 0xB, 0, 6);
                                        }
                                    } else {
                                        if (m->b[0x43] != 6) {
                                            func_003BE4F0(m, 6, 0, 10);
                                        }
                                        func_L01_00441FB8(m, 0xE, -1);
                                    }
                                    if (func_00388800(((u8 *)m + 0x10), temp_s1_5) < 8.0f) {
                                        if (m->b[0x43] != 0x1B) {
                                            func_003BE4F0(m, 0x1B, 0, 0xF);
                                        }
                                        func_L01_00441FB8(m, 0x24, -1);
                                    }
                                    if (pv->i[0x95C/4] != -1) {
                                        func_L01_00441FB8(m, 0x11, -1);
                                        if (m->b[0x43] != 7) {
                                            func_003BE4F0(m, 7, 0, 6);
                                        }
                                    }
                                    temp_a0_10 = pv->i[0x974/4];
                                    if ((temp_a0_10 != -1) && (D_L06_001DEA4C_00349B48->e[temp_a0_10].cnt != 0)) {
                                        func_L01_00441FB8(m, 0xB, 2);
                                        if (m->b[0x43] != 0xB) {
                                            func_003BE4F0(m, 0xB, 0, (s32)func_0037E250(6.0f, 12.0f));
                                        }
                                    }
                                }
                            }
                            break;
                        case 23:                    /* switch 2 */
                            temp_v1_7 = m->b[0x42];
                            if (temp_v1_7 == 0x10) {
                                if (m->b[0x60] & 2) {
                                    if (m->b[0x43] != 6) {
                                        func_003BE4F0(m, 6, 0, 8);
                                    }
                                    func_L01_00441FB8(m, 0xE, -1);
                                    if ((func_00388800(((u8 *)m + 0x10), ((u8 *)pv + 0x220)) <= 2.5f) && (func_00389468(m->f[0xF8/4], func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f)) {
                                        if (m->b[0x43] != 0x13) {
                                            func_003BE4F0(m, 0x13, 8, 8);
                                        }
                                        func_L01_00441FB8(m, 0x13, -1);
                                    }
                                    if (func_00388800(((u8 *)m + 0x10), ((u8 *)pv + 0x220)) > 6.0f) {
                                        if (m->b[0x43] != 7) {
                                            func_003BE4F0(m, 7, 0, 8);
                                        }
                                        func_L01_00441FB8(m, 0xF, -1);
                                        break;
                                    }
                                }
                            } else if (temp_v1_7 == 0x11) {
                                if (func_L01_0044AF40(m, 38.0f) != 0) {
                                    if (m->b[0x43] != 6) {
                                        func_003BE4F0(m, 6, 0, 8);
                                    }
                                    func_L01_00441FB8(m, 0xE, -1);
                                    if ((func_00388800(((u8 *)m + 0x10), ((u8 *)pv + 0x220)) <= 2.5f) && (func_00389468(m->f[0xF8/4], func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f)) {
                                        if (m->b[0x43] != 0xF) {
                                            func_003BE4F0(m, 0xF, 0xA, 6);
                                        }
                                        func_L01_00441FB8(m, 0x12, -1);
                                    }
                                    if (func_00388800(((u8 *)m + 0x10), ((u8 *)pv + 0x220)) > 6.0f) {
                                        if (m->b[0x43] != 7) {
                                            func_003BE4F0(m, 7, 0, 8);
                                        }
                                        func_L01_00441FB8(m, 0xF, -1);
                                        break;
                                    }
                                }
                            } else {
                                if (m->b[0x60] & 2) {
                                    if (m->b[0x43] != 6) {
                                        func_003BE4F0(m, 6, 0, 8);
                                    }
                                    func_L01_00441FB8(m, 0xE, -1);
                                    if ((func_00388800((u8 *)m + 0x10, (u8 *)pv + 0x220) <= 2.5f) && (func_00389468(m->f[0xF8/4], func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f)) {
                                        if (m->b[0x43] != 0xF) {
                                            func_003BE4F0(m, 0xF, 0xA, 6);
                                        }
                                        func_L01_00441FB8(m, 0x12, -1);
                                        break;
                                    }
                                }
                            }
                            break;
                        case 24:                    /* switch 2 */
                            if ((func_L01_0044AF40(m, 27.0f) != 0) && (m->b[0x42] == 0x12)) {
                                pv->i[0x8E8/4] = 0;
                                if (m->b[0x43] != 0) {
                                    func_003BE4F0(m, 0, 0, 8);
                                }
                                func_L01_00441FB8(m, 0x19, -1);
                                break;
                            }
                            break;
                        case 25:                    /* switch 2 */
                            func_L01_00458A08(m, func_00388A28(((G_0034A7A8 *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((G_0034A7A8 *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
                            break;
    }
    func_L06_0034F0B8_00349B48(m);
}
/* localdecomp:end func_L06_00349B48 */
