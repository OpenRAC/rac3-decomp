#include "common.h"

/* NTSC-U counterpart of func_L24_00352060 (src/levels/24_insomniac_museum/L24_00352060.c) */
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_L24_001E8F58_003510A0[];

/* localdecomp:start func_L24_003510A0 */
typedef union Mo_t_00352060 { u8 b[0x100]; s8 c[0x100]; s16 h[0x80]; u16 uh[0x80]; s32 i[0x40]; u32 u[0x40]; f32 f[0x40]; void *p[0x40]; long d[0x20]; u128_t q[0x10]; } Mo_00352060;
typedef union Pv_t_00352060 { u8 b[0x1000]; s8 c[0x1000]; s16 h[0x800]; u16 uh[0x800]; s32 i[0x400]; u32 u[0x400]; f32 f[0x400]; void *p[0x400]; long d[0x200]; u128_t q[0x100]; } Pv_00352060;
typedef union G_t_00352060 { u8 b[0x4000]; s8 c[0x4000]; s16 h[0x2000]; u16 uh[0x2000]; s32 i[0x1000]; u32 u[0x1000]; f32 f[0x1000]; void *p[0x1000]; long d[0x800]; u128_t q[0x400]; } G_00352060;
typedef union { f32 f[4]; s32 i[4]; s8 c[16]; u8 b[16]; s16 h[8]; u16 uh[8]; u128_t q; } __attribute__((aligned(16))) U16_00352060;
extern s32 D_L24_001DF0C0_003510A0;
extern u8 *D_L24_001DF51C_003510A0;
typedef struct { u8 pad0[0x80]; } E80_00352060;
extern E80_00352060 *D_L24_001DF600_003510A0;
extern void *D_L24_0021D600_003510A0[];
extern f32 D_L24_001DD558_003510A0;
__asm__(".extern D_L24_001DD558_003510A0, 4");
extern f32 D_L24_001DD55C_003510A0;
__asm__(".extern D_L24_001DD55C_003510A0, 4");
extern f32 D_L24_001DD560_003510A0;
__asm__(".extern D_L24_001DD560_003510A0, 4");
extern f32 D_L24_001DD564_003510A0;
__asm__(".extern D_L24_001DD564_003510A0, 4");
extern f32 D_L24_001DD568_003510A0;
__asm__(".extern D_L24_001DD568_003510A0, 4");
extern f32 D_L24_001DD56C;
__asm__(".extern D_L24_001DD56C, 4");
extern f32 D_L24_001DD570_003510A0;
__asm__(".extern D_L24_001DD570_003510A0, 4");
extern f32 D_L24_001DD574_003510A0;
__asm__(".extern D_L24_001DD574_003510A0, 4");
extern f32 D_L24_001DD578_003510A0;
__asm__(".extern D_L24_001DD578_003510A0, 4");
extern f32 D_L24_001DD57C_003510A0;
__asm__(".extern D_L24_001DD57C_003510A0, 4");
extern f32 D_L24_001DD580_003510A0;
__asm__(".extern D_L24_001DD580_003510A0, 4");
extern f32 D_L24_001DD584_003510A0;
__asm__(".extern D_L24_001DD584_003510A0, 4");
extern f32 D_L24_001DD590_003510A0;
__asm__(".extern D_L24_001DD590_003510A0, 4");
extern f32 D_L24_001DD594_003510A0;
__asm__(".extern D_L24_001DD594_003510A0, 4");
extern f32 D_L24_001DD598_003510A0;
__asm__(".extern D_L24_001DD598_003510A0, 4");
extern f32 D_L24_001DD59C_003510A0;
__asm__(".extern D_L24_001DD59C_003510A0, 4");
extern f32 D_L24_001DD5A0_003510A0;
__asm__(".extern D_L24_001DD5A0_003510A0, 4");
extern f32 D_L24_001DD5A4_003510A0;
__asm__(".extern D_L24_001DD5A4_003510A0, 4");
extern f32 D_L24_001DD5A8_003510A0;
__asm__(".extern D_L24_001DD5A8_003510A0, 4");
extern f32 *func_0037E0B8(void *);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern s32 func_00388398(void *);
extern s32 func_003883C8(void *);
extern f32 func_003887A0(void *);
extern f32 func_00388800(void *, void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern void func_003BD360(void *);
extern void func_003BDA38(void *, s32, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern f32 func_003BEBF8(void *, f32, f32);
extern void func_003BEC60(void *, f32, void *, f32, f32, f32);
extern s32 func_003D00C0();
extern void func_L01_00301508(void *, s32, f32, f32);
extern void func_L01_003154D8(void *, s32, s32);
extern s32 func_L01_003F9498(void *, s32, void *, f32);
extern f32 func_L01_00436500(void *);
extern f32 func_L01_00440918(f32, f32);
extern void func_L01_00440A88(void *, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00443790(void *, s32, f32, f32, s32, f32, s32, s32, s32);
extern f32 func_L01_00444740(void *, void *, s32, f32, f32);
extern s32 func_L01_0044AF40(void *, f32);
extern f32 func_L01_0044E128(void *, s32, s32);
extern s32 func_L01_00451078(void *, void *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_L01_00452EF0(void *);
extern void func_L01_00452F40(void *, s32);
extern s32 func_L01_00455C88(void *, void *, s32, s32);
extern void func_L01_00455E98(void *, void *, void *);
extern void func_L01_00457440(void *, void *);
extern void func_L01_004574A0(void *, void *, f32);
extern void func_L01_004576E8(void *);
extern s32 func_L01_00457708(void *, f32);
extern s32 func_L01_00457728(void *, void *);
extern s32 func_L01_00458A08(void *, f32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern s32 func_L01_00458B30(void *, void *);
extern void func_L01_00458E48(void *, void *, s32, s32);
extern void func_L01_00465410(void *, void *, s32, s32);
extern void func_L01_00467288(void *, void *, s32, f32, f32);
extern void func_L02_00350598(void *);
extern void func_L24_0034D3C8(void *, void *, void *, void *, s32, f32, f32);
extern s32 func_L24_00353910(void);
extern void func_L24_003542C0(void *);
extern s32 func_L24_00354470();
extern s32 func_L24_00354670(void *);
#include "vu0.h"
void func_L24_003510A0(Mo_00352060 *m) {
    U16_00352060 sp00;
    U16_00352060 sp10;
    U16_00352060 sp20;
    u8 *posz;
    U16_00352060 sp30;
    U16_00352060 sp40;
    s32 var_4;
    s32 var_5;
    s32 var_5_2;
    s32 var_5_3;
    s32 var_5_4;
    s32 var_5_5;
    s32 var_5_6;
    s32 var_5_7;
    s32 var_5_9;
    s32 var_f13;
    s32 var_f14;
    s32 var_f15;
    f32 *temp_4_8;
    f32 temp_4_2;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f21;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f12;
    f32 var_f20;
    s32 *temp_18;
    s32 temp_16_9;
    s32 temp_2_7;
    s32 temp_4_3;
    s32 var_16_2;
    s32 var_18;
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_condition_bit;
    u16 temp_3_3;
    u16 temp_3_4;
    u32 var_3;
    u8 temp_3;
    u8 temp_3_2;
    u8 temp_3_5;
    u8 temp_3_6;
    u8 temp_3_7;
    u8 temp_3_8;
    u8 temp_4;
    void *temp_16;
    void *temp_16_2;
    void *temp_16_3;
    void *temp_16_4;
    void *temp_16_5;
    void *temp_16_6;
    void *temp_16_7;
    void *temp_16_8;
    void *temp_18_2;
    Pv_00352060 *pv;
    void *temp_2;
    void *temp_2_2;
    void *temp_2_3;
    void *temp_2_4;
    void *temp_2_5;
    void *temp_2_6;
    void *temp_4_4;
    void *temp_4_5;
    void *temp_4_6;
    void *temp_4_7;
    void *temp_5;
    void *temp_5_2;
    void *temp_5_3;
    void *temp_5_4;
    void *temp_5_5;
    void *temp_5_6;
    void *temp_6;
    void *var_5_8;

    pv = m->p[0x68/4];
    if (func_L24_00353910() != 0) {
        return;
    }
    sp00.q = m->q[0x10/16];
    switch (m->b[0x95]) {
    case 0:
        if ((func_L01_00452EF0(m) != 0) && (pv->h[0x2D6/2] == 0)) {
            pv->h[0x2D6/2] = func_0037E208(0, 0x28);
        }
        if ((pv->h[0x234/2] == 1) && (func_003883C8(pv->b + 0x2D6) != 0)) {
            pv->f[0xA0/4] = 0.06981317f;
            func_L01_00441FB8(m, 0xD, 2);
            if (m->b[0x43] != 6) {
                func_003BE4F0(m, 6, 0, 10);
            }
            if (pv->i[0x2E4/4] != 0) {
                func_L01_00441FB8(m, 0x14, 2);
                if (m->b[0x43] != 3) {
                    func_003BE4F0(m, 3, 0, 10);
                }
                if (pv->i[0x2E4/4] == 2) {
                    func_L01_00441FB8(m, 0x15, -1);
                }
            }
            if (pv->i[0x32C/4] != -1) {
                func_L01_00441FB8(m, 8, -1);
                if (m->b[0x43] != 7) {
                    func_003BE4F0(m, 7, 0, 6);
                }
            }
        } else if ((pv->i[0x2D8/4] != 0) && (func_003883C8(pv->b + 0x2D6) != 0) && (pv->i[0x2E4/4] == 0)) {
            m->b[0x95] = 1;
            m->b[0xBE] &= 0xFD;
            pv->i[0x2D8/4] = 0;
            if (pv->i[0x2D0/4] < 0x12C) {
                pv->i[0x2D0/4] = func_0037E208(0x1E0, 0x258);
            }
        }
        break;
    case 1:
        if (pv->h[0x234/2] == 1) {
            pv->f[0xA0/4] = 0.06981317f;
            func_L01_00441FB8(m, 0xD, 2);
            if (m->b[0x43] != 6) {
                func_003BE4F0(m, 6, 0, 10);
            }
        }
        break;
    case 2:
        if ((pv->h[0x234/2] != 1) && (m->b[0x20] != 0x14) && (m->b[0x20] != 0xE) && (m->b[0x20] != 0x10)) {
            if (m->b[0x43] != 7) {
                func_003BE4F0(m, 7, 0, 10);
            }
            func_L01_00441FB8(m, 9, 1);
            pv->q[0x340/16] = pv->q[0x220/16];
            pv->i[0x2D0/4] = func_0037E208(0x244, 0x258);
        }
        break;
    case 3:
        {
            s32 r;
            pv->c[0x1A9] = 1;
            r = func_L01_00451078(m, pv->b + 0x160);
            if (r & 1) {
                func_L02_00350598(m);
                func_L01_003154D8(m, 0, 0);
                return;
            }
            if (r & 2) {
                if (pv->h[0x234/2] == 1) {
                    if (func_L24_00354470(m) != 0) {
                        func_L01_00441FB8(m, 0xD, 2);
                        if (m->b[0x43] != 6) {
                            func_003BE4F0(m, 6, 0, 10);
                        }
                    } else {
                        func_L01_00441FB8(m, 0xC, 2);
                        if (m->b[0x43] != 7) {
                            func_003BE4F0(m, 7, 0, 10);
                        }
                    }
                } else {
                    if (m->b[0x43] != 7) {
                        func_003BE4F0(m, 7, 0, 10);
                    }
                    func_L01_00441FB8(m, 9, 1);
                    pv->q[0x340/16] = pv->q[0x220/16];
                    pv->i[0x2D0/4] = func_0037E208(0x244, 0x258);
                }
            }
        }
        break;
    case 4:
        m->f[0x18/4] -= 0.200000018f;
        break;
    }
                switch (m->b[0x20]) {                    /* switch 2 */
                case 1:
                case 26:
                    break;
                case 2:                             /* switch 2 */
                    pv->f[0xA0/4] = 0.61086524f;
                    func_L01_00458A70(m, D_L24_001DD56C * 0.000277777785f, D_L24_001DD568_003510A0 * 0.0166666675f, D_L24_001DD574_003510A0 * 0.017453292f * 0.000277777785f, D_L24_001DD570_003510A0 * 0.017453292f * 0.0166666675f);
                    if (func_L01_00458B30(m, D_L24_0021D600_003510A0[pv->i[0x2F4/4]]) != 0) {
                        func_L01_00441FB8(m, 4, -1);
                        if (m->b[0x43] != 2) {
                            func_003BE4F0(m, 2, 0, 20);
                        }
                    }
                    break;
                case 4:                             /* switch 2 */
                    if (m->b[0x60] & 2) {
                        temp_4_3 = pv->i[0x2F4/4];
                        if (temp_4_3 != -1) {
                            temp_16 = m->b + 0x10;
                            temp_18 = D_L24_0021D600_003510A0[temp_4_3];
                            temp_f20 = func_00388800(temp_16, (u8 *)temp_18 + 0x10);
                            if (func_00388800(temp_16, (u8 *)temp_18 + (*temp_18 * 0x10)) < temp_f20) {
                                func_L01_00458E48(m, D_L24_0021D600_003510A0[pv->i[0x2F4/4]], 0, *temp_18 - 1);
                            } else {
                                func_L01_00458E48(m, D_L24_0021D600_003510A0[pv->i[0x2F4/4]], *temp_18 - 1, 0);
                            }
                            func_L01_00441FB8(m, 2, -1);
                            if (m->b[0x43] != 4) {
                                func_003BE4F0(m, 4, 0, 20);
                            }
                        } else {
                            func_L01_00441FB8(m, 6, -1);
                            if (m->b[0x43] != 4) {
                                func_003BE4F0(m, 4, 0, 20);
                            }
                        }
                    }
                    func_L01_00457708(m, m->f[0xF8/4]);
                    break;
                case 6:                             /* switch 2 */
                    if (func_L01_00452EC8(m) != 0) {
                        func_L01_00458A70(m, D_L24_001DD56C * 0.000277777785f, D_L24_001DD568_003510A0 * 0.0166666675f, D_L24_001DD574_003510A0 * 0.017453292f * 0.000277777785f, D_L24_001DD570_003510A0 * 0.017453292f * 0.0166666675f);
                        func_L01_00440A88(&sp10, 4.0f, 6.0f);
                        vec_add_ab(pv->b + 0x300, &sp10, m->b + 0x10);
                    }
                    temp_16_2 = pv->b + 0x300;
                    func_L01_00457440(m, temp_16_2);
                    if (func_00388800(m->b + 0x10, temp_16_2) < 2.0f) {
                        func_L01_00441FB8(m, 4, -1);
                        if (m->b[0x43] != 2) {
                            func_003BE4F0(m, 2, 0, 20);
                        }
                    }
                    break;
                case 9:                             /* switch 2 */
                    if (func_L01_00452EC8(m) != 0) {
                        func_L01_00458A70(m, D_L24_001DD55C_003510A0 * 0.000277777785f, D_L24_001DD558_003510A0 * 0.0166666675f, D_L24_001DD564_003510A0 * 0.017453292f * 0.000277777785f, D_L24_001DD560_003510A0 * 0.017453292f * 0.0166666675f);
                    }
                    func_L01_00457440(m, (pv->b + 0x340));
                    if (func_L24_00354670(m) == 1) {
                        func_L01_00441FB8(m, 0x18, -1);
                        if (m->b[0x43] != 3) {
                            func_003BE4F0(m, 3, 0, 15);
                        }
                    }
                    if ((func_00388800(m->b + 0x10, (pv->b + 0x340)) < 6.0f) || (pv->i[0x330/4] >= 0x10)) {
                        func_L01_00441FB8(m, 0xA, -1);
                        if (m->b[0x43] != 0xB) {
                            func_003BE4F0(m, 0xB, 0, 8);
                        }
                    }
                    break;
                case 10:                             /* switch 2 */
                    if (m->b[0x60] & 2) {
                        func_L01_00441FB8(m, 4, -1);
                        if (m->b[0x43] != 1) {
                            func_003BE4F0(m, 1, 0, 8);
                        }
                    }
                    break;
                case 8:                             /* switch 2 */
                    if (func_L01_00452EC8(m) != 0) {
                        func_L01_00458A70(m, D_L24_001DD55C_003510A0 * 0.000277777785f, D_L24_001DD558_003510A0 * 0.0166666675f, D_L24_001DD564_003510A0 * 0.017453292f * 0.000277777785f, D_L24_001DD560_003510A0 * 0.017453292f * 0.0166666675f);
                    }
                    temp_16_3 = (u8 *)&D_L24_001DF600_003510A0[pv->i[0x32C/4]];
                    temp_18_2 = temp_16_3 + 0x30;
                    if (func_00388800((m->b + 0x10), temp_18_2) < 0.5f) {
                        func_L01_00458A08(m, ((G_00352060 *)temp_16_3)->f[0x78/4]);
                    } else {
                        func_L01_00457440(m, temp_18_2);
                    }
                    if ((func_00388800((m->b + 0x10), temp_16_3 + 0x30) < 0.5f) && (func_00389468(m->f[0xF8/4], ((G_00352060 *)temp_16_3)->f[0x78/4]) < 0.17453292f)) {
                        if (m->b[0x43] != 3) {
                            func_003BE4F0(m, 3, 0, 10);
                        }
                        func_L01_00441FB8(m, 0x18, -1);
                    }
                    break;
                case 12:                            /* switch 2 */
                    if (func_L01_00452EC8(m) != 0) {
                        if (m->b[0x43] == 7) {
                            func_L01_00458A70(m, D_L24_001DD55C_003510A0 * 0.000277777785f, D_L24_001DD558_003510A0 * 0.0166666675f, D_L24_001DD564_003510A0 * 0.017453292f * 0.000277777785f, D_L24_001DD560_003510A0 * 0.017453292f * 0.0166666675f);
                        } else {
                            func_L01_00458A70(m, D_L24_001DD56C * 0.000277777785f, D_L24_001DD568_003510A0 * 0.0166666675f, D_L24_001DD574_003510A0 * 0.017453292f * 0.000277777785f, D_L24_001DD570_003510A0 * 0.017453292f * 0.0166666675f);
                        }
                        func_L01_00455E98(m, pv->p[0x230/4], (pv->b + 0x360));
                        pv->f[0x354/4] = (f32) (func_L01_00440918(D_L24_001DD5A4_003510A0, D_L24_001DD5A8_003510A0) * 0.017453292f);
                    }
                    if (func_L24_00354670(m) == 1) {
                        func_L01_00441FB8(m, 0x18, -1);
                        if (m->b[0x43] != 3) {
                            func_003BE4F0(m, 3, 0, 15);
                        }
                    }
                    if ((pv->i[0x330/4] >= 4) && (func_L24_00354670(m) == 1)) {
                        func_L01_00441FB8(m, 0x18, -1);
                        if (m->b[0x43] != 3) {
                            func_003BE4F0(m, 3, 0, 5);
                        }
                    }
                    temp_5_2 = pv->p[0x230/4];
                    if (temp_5_2 != pv->p[0x3B0/4]) {
                        func_L01_00455E98(m, temp_5_2, (pv->b + 0x360));
                    }
                    func_L01_00455C88(m, (pv->b + 0x360), 0, 0);
                    func_L01_004574A0(m, (pv->b + 0x360), pv->f[0x354/4]);
                    if ((func_00388800(m->b + 0x10, pv->b + 0x220) < D_L24_001DD57C_003510A0) && (func_00389468(m->f[0xF8/4], func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < (D_L24_001DD578_003510A0 * 0.017453292f))) {
                        if (func_0037E1D8(2) != 0) {
                            if (m->b[0x43] != 0xF) {
                                func_003BE4F0(m, 0xF, 0, 10);
                            }
                            func_L01_00441FB8(m, 0x12, -1);
                        } else {
                            if (m->b[0x43] != 0x10) {
                                func_003BE4F0(m, 0x10, 0, 10);
                            }
                            func_L01_00441FB8(m, 0x12, -1);
                        }
                    }
                    break;
                case 14:                            /* switch 2 */
                    if (((u32) (m->b[0x42] - 8) < 2U) && (pv->p[0x2DC/4] == 0) && (func_L01_00436500(m) > 9.0f) && (func_003BDA38(m, 0, &sp10), (func_L01_003F9498(&sp10, 1, m, D_L24_001DD580_003510A0) != 0))) {
                        G_00352060 *e = (G_00352060 *) D_L24_001E8F58_003510A0[0];
                        if ((e != 0) && (e == pv->p[0x2E0/4])) {
                            pv->p[0x2DC/4] = e;
                            e->i[0x98/4] = 0;
                            temp_4_5 = pv->p[0x2E0/4];
                            if (((G_00352060 *)temp_4_5)->h[0xAA/2] == 0x1663) {
                                ((G_00352060 *)temp_4_5)->c[0xBC] = 1;
                            }
                        }
                    }
                    if (pv->p[0x2E0/4] != 0) {
                        func_L01_00457708(m, func_00388A28(((G_00352060 *)(pv->p[0x2E0/4]))->f[0x10/4] - m->f[0x10/4], ((G_00352060 *)(pv->p[0x2E0/4]))->f[0x14/4] - m->f[0x14/4]));
                    } else {
                        func_L01_004576E8(m);
                    }
                    if (func_L01_0044AF40(m, 18.0f) != 0) {
                        if (pv->p[0x2DC/4] != 0) {
                            func_L01_00441FB8(m, 0x10, -1);
                            if (m->b[0x43] != 0xA) {
                                func_003BE4F0(m, 0xA, 0, (s32) func_0037E250(6.0f, 10.0f));
                            }
                        } else if (func_L24_00354470(m) != 0) {
                            func_L01_00441FB8(m, 0xD, -1);
                            if (func_00388800(m->b + 0x10, pv->p[0x2E0/4] + 0x10) < 6.0f) {
                                if (m->b[0x43] != 4) {
                                    func_003BE4F0(m, 4, 0, 10);
                                }
                            } else if (m->b[0x43] != 6) {
                                func_003BE4F0(m, 6, 0, 10);
                            }
                        }
                    }
                    temp_2 = pv->p[0x2E0/4];
                    if ((temp_2 == 0) || (temp_3 = ((G_00352060 *)temp_2)->b[0x20], (temp_3 == 0xFE)) || (temp_3 == 0xFD)) {
                        if (func_L24_00354470(m) != 0) {
                            func_L01_00441FB8(m, 0xD, -1);
                            if (func_00388800(m->b + 0x10, pv->p[0x2E0/4] + 0x10) < 6.0f) {
                                if (m->b[0x43] != 4) {
                                    func_003BE4F0(m, 4, 0, 10);
                                }
                            } else if (m->b[0x43] != 6) {
                                func_003BE4F0(m, 6, 0, 10);
                            }
                        } else {
                            func_L01_00441FB8(m, 0xC, -1);
                            if ((pv->b[0x5F] == 0) && (func_00388800(m->b + 0x10, pv->p[0x230/4] + 0x10) < 6.0f)) {
                                if (m->b[0x43] != 4) {
                                    func_003BE4F0(m, 4, 0, 10);
                                }
                            } else if (m->b[0x43] != 7) {
                                func_003BE4F0(m, 7, 0, 10);
                            }
                        }
                        if (pv->i[0x33C/4] != 0) {
                            func_L01_00441FB8(m, 0xB, -1);
                            if (m->b[0x43] != 4) {
                                func_003BE4F0(m, 4, 0, 15);
                            }
                            pv->i[0x33C/4] = 0;
                        }
                    }
                    if (pv->i[0x2F0/4] != 0) {
                        func_L01_00441FB8(m, 0xC, -1);
                        if ((pv->b[0x5F] == 0) && (func_00388800(m->b + 0x10, pv->p[0x230/4] + 0x10) < 6.0f)) {
                            if (m->b[0x43] != 4) {
                                func_003BE4F0(m, 4, 0, 10);
                            }
                        } else if (m->b[0x43] != 7) {
                            func_003BE4F0(m, 7, 0, 10);
                        }
                    }
                    break;
                case 15:                            /* switch 2 */
                    if (func_L24_00351018(m->b) != 0) {
                        if (m->b[0x43] != 0xA) {
                            func_003BE4F0(m, 0xA, 0, (s32) func_0037E250(6.0f, 10.0f));
                        }
                        func_L01_00441FB8(m, 0x10, -1);
                    } else {
                        func_L01_00441FB8(m, 0x11, -1);
                        if (m->b[0x43] != 5) {
                            func_003BE4F0(m, 5, 0, 6);
                        }
                    }
                    break;
                case 17:                            /* switch 2 */
                    if (func_L01_00452EC8(m) != 0) {
                        func_L01_00458A70(m, D_L24_001DD56C * 0.000277777785f, D_L24_001DD568_003510A0 * 0.0166666675f, D_L24_001DD574_003510A0 * 0.017453292f * 0.000277777785f, D_L24_001DD570_003510A0 * 0.017453292f * 0.0166666675f);
                    }
                    func_L01_004574A0(m, pv->b + 0x220, 0.43633232f);
                    if (func_L24_00351018(m->b) != 0) {
                        if (m->b[0x43] != 0xA) {
                            func_003BE4F0(m, 0xA, 0, (s32) func_0037E250(6.0f, 10.0f));
                        }
                        func_L01_00441FB8(m, 0x10, -1);
                    }
                    break;
                case 16:                            /* switch 2 */
                    temp_2_2 = pv->p[0x230/4];
                    func_L01_00458A08(m, func_00388A28(((G_00352060 *)temp_2_2)->f[0x10/4] - m->f[0x10/4], ((G_00352060 *)temp_2_2)->f[0x14/4] - m->f[0x14/4]));
                    if ((m->b[0x42] == 0xA) && (func_L01_0044AF40(m, 16.5f) != 0)) {
                        vec_sub_ab(&sp10, pv->b + 0x220, ((G_00352060 *)pv->p[0x2DC/4])->b + 0x10);
                        func_00388830(&sp10, &sp10, D_L24_001DD59C_003510A0 * 0.0166666675f);
                        sp10.f[2] = func_L01_00444740(pv->p[0x2DC/4] + 0x10, pv->b + 0x220, 0, D_L24_001DD59C_003510A0 * 0.0166666675f, -(D_L24_001DD5A0_003510A0 * 0.000277777785f));
                        temp_6 = pv->p[0x2DC/4];
                        func_L24_0034D3C8(m, &sp10, temp_6 + 0x10, temp_6 + 0xF0, ((G_00352060 *)(pv->p[0x2E0/4]))->h[0xAA/2], D_L24_001DD5A0_003510A0 * 0.000277777785f, (f32) pv->b[0x45]);
                        func_003BD360(pv->p[0x2DC/4]);
                        pv->p[0x2DC/4] = 0;
                    }
                    if (m->b[0x60] & 2) {
                        if (func_0037E1D8(2) != 0) {
                            if (m->b[0x43] != 0xB) {
                                func_003BE4F0(m, 0xB, 0, 10);
                            }
                            func_L01_00441FB8(m, 0x13, -1);
                            break;
                        }
                        if (func_L24_00354470(m) != 0) {
                            func_L01_00441FB8(m, 0xD, -1);
                            if (m->b[0x43] != 6) {
                                func_003BE4F0(m, 6, 0, 10);
                            }
                            if ((func_00388800(m->b + 0x10, pv->p[0x2E0/4] + 0x10) < 6.0f) && (m->b[0x43] != 4)) {
                                func_003BE4F0(m, 4, 0, 10);
                            }
                        } else {
                            func_L01_00441FB8(m, 0xC, -1);
                            if ((pv->b[0x5F] == 0) && (func_00388800(m->b + 0x10, pv->p[0x230/4] + 0x10) < 6.0f)) {
                                if (m->b[0x43] != 4) {
                                    func_003BE4F0(m, 4, 0, 10);
                                }
                            } else if (m->b[0x43] != 7) {
                                func_003BE4F0(m, 7, 0, 10);
                            }
                            if (pv->i[0x33C/4] != 0) {
                                func_L01_00441FB8(m, 0xB, -1);
                                if (m->b[0x43] != 4) {
                                    func_003BE4F0(m, 4, 0, 15);
                                }
                                pv->i[0x33C/4] = 0;
                            }
                        }
                    }
                    break;
                case 19:                            /* switch 2 */
                    if (m->b[0x60] & 2) {
                        if (func_L24_00354470(m) != 0) {
                            func_L01_00441FB8(m, 0xD, -1);
                            if (m->b[0x43] != 6) {
                                func_003BE4F0(m, 6, 0, 10);
                            }
                            if ((func_00388800(m->b + 0x10, pv->p[0x2E0/4] + 0x10) < 6.0f) && (m->b[0x43] != 4)) {
                                func_003BE4F0(m, 4, 0, 10);
                            }
                        } else {
                            func_L01_00441FB8(m, 0xC, -1);
                            if ((pv->b[0x5F] == 0) && (func_00388800(m->b + 0x10, pv->p[0x230/4] + 0x10) < 6.0f)) {
                                if (m->b[0x43] != 4) {
                                    func_003BE4F0(m, 4, 0, 10);
                                }
                            } else if (m->b[0x43] != 7) {
                                func_003BE4F0(m, 7, 0, 10);
                            }
                            if (pv->i[0x33C/4] != 0) {
                                func_L01_00441FB8(m, 0xB, -1);
                                if (m->b[0x43] != 4) {
                                    func_003BE4F0(m, 4, 0, 15);
                                }
                                pv->i[0x33C/4] = 0;
                            }
                        }
                    }
                    break;
                case 13:                            /* switch 2 */
                    if (func_L01_00452EC8(m) != 0) {
                        if (m->b[0x43] == 7) {
                            func_L01_00458A70(m, D_L24_001DD55C_003510A0 * 0.000277777785f, D_L24_001DD558_003510A0 * 0.0166666675f, D_L24_001DD564_003510A0 * 0.017453292f * 0.000277777785f, D_L24_001DD560_003510A0 * 0.017453292f * 0.0166666675f);
                        } else {
                            func_L01_00458A70(m, D_L24_001DD56C * 0.000277777785f, D_L24_001DD568_003510A0 * 0.0166666675f, D_L24_001DD574_003510A0 * 0.017453292f * 0.000277777785f, D_L24_001DD570_003510A0 * 0.017453292f * 0.0166666675f);
                        }
                        if (pv->p[0x2E0/4] != 0) {
                            func_L01_00455E98(m, pv->p[0x2E0/4], pv->b + 0x360);
                        }
                    }
                    if (pv->i[0x2F0/4] != 0) {
                        func_L01_00441FB8(m, 0xC, -1);
                        if ((pv->b[0x5F] == 0) && (func_00388800(m->b + 0x10, ((G_00352060 *)pv->p[0x230/4])->b + 0x10) < 6.0f)) {
                            if (m->b[0x43] != 4) {
                                func_003BE4F0(m, 4, 0, 10);
                            }
                        } else if (m->b[0x43] != 7) {
                            func_003BE4F0(m, 7, 0, 10);
                        }
                    } else {
                        G_00352060 *t = pv->p[0x2E0/4];
                        if ((t == 0) || (t->b[0x20] == 0xFE) || (t->b[0x20] == 0xFD)) {
                            if (func_L24_00354470(m) != 0) {
                                func_L01_00441FB8(m, 0xD, -1);
                                if (m->b[0x43] != 6) {
                                    func_003BE4F0(m, 6, 0, 10);
                                }
                                if ((func_00388800(m->b + 0x10, ((G_00352060 *)pv->p[0x2E0/4])->b + 0x10) < 6.0f) && (m->b[0x43] != 4)) {
                                    func_003BE4F0(m, 4, 0, 10);
                                }
                            } else {
                                func_L01_00441FB8(m, 0xC, -1);
                                if ((pv->b[0x5F] == 0) && (func_00388800(m->b + 0x10, ((G_00352060 *)pv->p[0x230/4])->b + 0x10) < 6.0f)) {
                                    if (m->b[0x43] != 4) {
                                        func_003BE4F0(m, 4, 0, 10);
                                    }
                                } else if (m->b[0x43] != 7) {
                                    func_003BE4F0(m, 7, 0, 10);
                                }
                                if (pv->i[0x33C/4] != 0) {
                                    func_L01_00441FB8(m, 0xB, -1);
                                    if (m->b[0x43] != 4) {
                                        func_003BE4F0(m, 4, 0, 15);
                                    }
                                    pv->i[0x33C/4] = 0;
                                }
                            }
                        } else {
                            if (t != pv->p[0x3B0/4]) {
                                func_L01_00455E98(m, t, pv->b + 0x360);
                            }
                            func_L01_00455C88(m, pv->b + 0x360, 0, 0);
                            func_L01_00457440(m, pv->b + 0x360);
                            if (((G_00352060 *)pv->p[0x2E0/4])->h[0xAA/2] == 0x1663) {
                                if ((func_00388800(m->b + 0x10, ((G_00352060 *)pv->p[0x2E0/4])->b + 0x10) < D_L24_001DD594_003510A0) && (func_00389468(m->f[0xF8/4], func_00388A28(((G_00352060 *)pv->p[0x2E0/4])->f[0x10/4] - m->f[0x10/4], ((G_00352060 *)pv->p[0x2E0/4])->f[0x14/4] - m->f[0x14/4])) < (D_L24_001DD590_003510A0 * 0.017453292f))) {
                                    if (fabs_asm(m->f[0x18/4] - ((G_00352060 *)pv->p[0x2E0/4])->f[0x18/4]) < D_L24_001DD598_003510A0) {
                                        if (m->b[0x43] != 8) {
                                            func_003BE4F0(m, 8, 0, 10);
                                        }
                                        func_L01_00441FB8(m, 0xE, -1);
                                    } else {
                                        if (m->b[0x43] != 9) {
                                            func_003BE4F0(m, 9, 0, 10);
                                        }
                                        func_L01_00441FB8(m, 0xE, -1);
                                    }
                                }
                            } else if ((func_00388800(m->b + 0x10, ((G_00352060 *)pv->p[0x2E0/4])->b + 0x10) < D_L24_001DD594_003510A0) && (func_00389468(m->f[0xF8/4], func_00388A28(((G_00352060 *)pv->p[0x2E0/4])->f[0x10/4] - m->f[0x10/4], ((G_00352060 *)pv->p[0x2E0/4])->f[0x14/4] - m->f[0x14/4])) < (D_L24_001DD590_003510A0 * 0.017453292f))) {
                                if ((fabs_asm(m->f[0x18/4] - ((G_00352060 *)pv->p[0x2E0/4])->f[0x18/4]) < D_L24_001DD598_003510A0) || (((G_00352060 *)pv->p[0x2E0/4])->h[0xAA/2] == 0x1663)) {
                                    if (m->b[0x43] != 8) {
                                        func_003BE4F0(m, 8, 0, 10);
                                    }
                                    func_L01_00441FB8(m, 0xE, -1);
                                } else {
                                    if (m->b[0x43] != 9) {
                                        func_003BE4F0(m, 9, 0, 10);
                                    }
                                    func_L01_00441FB8(m, 0xE, -1);
                                }
                            } else if (*(u8 *)&D_L24_001DF0C0_003510A0 == (u8)((s32)m >> 8)) {
                                func_L01_00452F40(pv->p[0x2E0/4], 0);
                                func_L24_00354470(m);
                            }
                            if (func_L24_00354670(m) == 1) {
                                func_L01_00441FB8(m, 0x18, -1);
                                if (m->b[0x43] != 3) {
                                    func_003BE4F0(m, 3, 0, 15);
                                }
                            }
                        }
                    }
                    break;
                case 18:                            /* switch 2 */
                    temp_2_6 = pv->p[0x230/4];
                    func_L01_00457708(m, func_00388A28(((G_00352060 *)temp_2_6)->f[0x10/4] - m->f[0x10/4], ((G_00352060 *)temp_2_6)->f[0x14/4] - m->f[0x14/4]));
                    if (m->b[0x60] & 2) {
                        if ((func_00388800((m->b + 0x10), pv->b + 0x220) > D_L24_001DD57C_003510A0) || (func_00389468(m->f[0xF8/4], func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) > (D_L24_001DD578_003510A0 * 0.017453292f))) {
                            if ((pv->b[0x5F] == 0) && (func_00388800((m->b + 0x10), pv->p[0x230/4] + 0x10) < 6.0f)) {
                                if (m->b[0x43] != 4) {
                                    func_003BE4F0(m, 4, 0, 10);
                                }
                            } else if (m->b[0x43] != 7) {
                                func_003BE4F0(m, 7, 0, 10);
                            }
                            func_L01_00441FB8(m, 0xC, -1);
                        } else if (func_0037E1D8(2) != 0) {
                            if (m->b[0x43] != 0xF) {
                                func_003BE4F0(m, 0xF, 0, 10);
                            }
                            func_L01_00441FB8(m, 0x12, -1);
                        } else {
                            if (m->b[0x43] != 0x10) {
                                func_003BE4F0(m, 0x10, 0, 10);
                            }
                            func_L01_00441FB8(m, 0x12, -1);
                        }
                    }
                    if ((func_L01_00436500(m) > 10.0f) && (m->b[0x42] == 0xF)) {
                        func_L01_00443790(m, 0, D_L24_001DD580_003510A0, (f32) pv->b[0x44], (pv->b[0x5F] != 0) ? 0x08010001 : 0x08000001, D_L24_001DD584_003510A0, 0, 1, 0);
                    } else if ((func_L01_00436500(m) > 10.0f) && (m->b[0x42] == 0x10)) {
                        func_L01_00443790(m, 1, D_L24_001DD580_003510A0, (f32) pv->b[0x44], (pv->b[0x5F] != 0) ? 0x08010001 : 0x08000001, D_L24_001DD584_003510A0, 0, 1, 0);
                    }
                    break;
                case 24:                            /* switch 2 */
                    if (func_L01_00452EC8(m) != 0) {
                        sp10.f[0] = func_00388960(m->f[0xF8/4]) * 7.5f;
                        temp_f0 = func_00388978(m->f[0xF8/4]) * 7.5f;
                        sp10.f[2] = 0.0f;
                        sp10.f[1] = temp_f0;
                        vec_add_ab(&sp10, m->b + 0x10, &sp10);
                        pv->f[0x308/4] = func_003BE7F0(&sp10, 0, 0, 0.5f);
                        pv->f[0x30C/4] = (f32) m->f[0x18/4];
                    }
                    if (m->b[0x42] == 3) {
                        f32 t;
                        m->f[0x48/4] = 1.0f;
                        t = func_L01_00436500(m);
                        if ((t > 11.0f) && (t < 22.0f)) {
                            func_00388830(&sp30, m->b + 0xC0, 0.3409091f);
                            vec_add_ba(&sp10, m->b + 0x10, &sp30);
                        }
                        if ((t > 11.0f) && (t < 17.0f)) {
                            func_003BEC60(&sp10.f[2], pv->f[0x308/4] + 1.5f, pv->b + 0x320, 0.016666668f, 0.11904763f, 0.25f);
                        }
                        if (t == 17.0f) {
                            pv->i[0x320/4] = 0;
                        }
                        if ((t > 17.0f) && (t < 22.0f)) {
                            if (fabs_asm(pv->f[0x308/4] - pv->f[0x30C/4]) > 6.0f) {
                                m->f[0x48/4] = 0.35f;
                            } else {
                                m->f[0x48/4] = 0.8f;
                            }
                            func_003BEC60(&sp10.f[2], pv->f[0x308/4], pv->b + 0x320, 0.021428572f, 0.15f, 0.3f);
                        }
                        if ((t > 11.0f) && (t < 22.0f)) {
                            vec_sub_ab(&sp20, &sp10, m->b + 0x10);
                            func_L01_00457728(m, &sp20);
                        }
                        if (m->b[0x60] & 2) {
                            pv->f[0xA0/4] = 0.06981317f;
                            func_L01_00441FB8(m, 0xD, 2);
                            if (m->b[0x43] != 6) {
                                func_003BE4F0(m, 6, 0, 10);
                            }
                        }
                    }
                    break;
                case 20:                            /* switch 2 */
                    if (func_L01_00452EC8(m) != 0) {
                        temp_4_6 = m->p[0x24/4];
                        temp_3_3 = m->uh[0x34/2] & 0xFFBE;
                        m->uh[0x34/2] = temp_3_3;
                        m->uh[0x34/2] = (u16) (temp_3_3 | (((G_00352060 *)temp_4_6)->uh[0x44/2] & 0x1000));
                        m->i[0x98/4] = (s32) ((G_00352060 *)temp_4_6)->i[0x10/4];
                    }
                    if (m->b[0x42] == 3) {
                        f32 t = func_L01_00436500(m);
                        temp_16_6 = (u8 *)&D_L24_001DF600_003510A0[(t < 17.0f) ? pv->i[0x324/4] : pv->i[0x328/4]];
                        if ((t > 11.0f) && (t < 22.0f)) {
                            func_00388830(&sp30, m->b + 0xC0, 0.18181819f);
                            vec_add_ba(&sp10, m->b + 0x10, &sp30);
                        } else {
                            m->f[0x48/4] = 1.0f;
                        }
                        if (t > 11.0f) {
                            if (t < 17.0f) {
                                m->f[0x48/4] = 0.5f;
                                func_003BEC60(&sp10.f[2], ((G_00352060 *)temp_16_6)->f[0x38/4] + 1.5f, pv->b + 0x320, 0.25f, 0.03125f, 0.375f);
                            }
                        }
                        if (t == 17.0f) {
                            pv->i[0x320/4] = 0;
                        }
                        if ((t > 17.0f) && (t < 22.0f)) {
                            func_003BEBF8(m->b + 0x48, 0.75f, 0.2f);
                            func_003BEC60(&sp10.f[2], ((G_00352060 *)temp_16_6)->f[0x38/4], pv->b + 0x320, 0.3f, 0.3f, 0.48000002f);
                        }
                        if ((t > 11.0f) && (t < 22.0f)) {
                            vec_sub_ab(&sp20, &sp10, m->b + 0x10);
                            func_L01_00457728(m, &sp20);
                        }
                        if (func_L01_0044AF40(m, 31.0f) != 0) {
                            m->f[0x48/4] = 1.0f;
                            pv->f[0xA0/4] = 0.06981317f;
                            if (m->b[0x43] != 8) {
                                func_003BE4F0(m, 8, 0, 10);
                            }
                            func_L01_00441FB8(m, 0xE, 2);
                            pv->c[0x1A9] = 1;
                        }
                    }
                    break;
                case 11:                            /* switch 2 */
                    sp10.f[0] = 443.82f;
                    sp10.f[2] = 21.11f;
                    sp10.f[1] = 137.81f;
                    func_L01_00458A08(m, func_00388A28(443.82f - m->f[0x10/4], 137.81f - m->f[0x14/4]));
                    if (func_00389468(m->f[0xF8/4], func_00388A28(sp10.f[0] - m->f[0x10/4], sp10.f[1] - m->f[0x14/4])) < 0.10471976f) {
                        func_L01_00441FB8(m, 0x18, -1);
                        if (m->b[0x43] != 3) {
                            func_003BE4F0(m, 3, 0, 15);
                        }
                        pv->i[0x33C/4] = 0;
                    }
                    break;
                case 21:                            /* switch 2 */
                    if (func_L01_00452EC8(m) != 0) {
                        temp_4_7 = m->p[0x24/4];
                        temp_3_4 = m->uh[0x34/2] & 0xFFBE;
                        m->uh[0x34/2] = temp_3_4;
                        m->uh[0x34/2] = (u16) (temp_3_4 | (((G_00352060 *)temp_4_7)->uh[0x44/2] & 0x1000));
                        m->i[0x98/4] = (s32) ((G_00352060 *)temp_4_7)->i[0x10/4];
                    }
                    if (m->b[0x42] == 3) {
                        f32 t = func_L01_00436500(m);
                        temp_16_7 = (u8 *)&D_L24_001DF600_003510A0[(t < 17.0f) ? pv->i[0x324/4] : pv->i[0x328/4]];
                        if ((t > 11.0f) && (t < 22.0f)) {
                            func_00388830(&sp30, m->b + 0xC0, 0.18181819f);
                            vec_add_ba(&sp10, m->b + 0x10, &sp30);
                        } else {
                            m->f[0x48/4] = 1.0f;
                        }
                        if (t > 11.0f) {
                            if (t <= 17.0f) {
                                m->f[0x48/4] = 0.75f;
                                func_003BEC60(&sp10.f[2], ((G_00352060 *)temp_16_7)->f[0x38/4] + 1.5f, pv->b + 0x320, 0.25f, 0.013888889f, 0.275f);
                            }
                        }
                        if (t == 17.0f) {
                            pv->i[0x320/4] = 0;
                        }
                        if ((t > 17.0f) && (t < 22.0f)) {
                            func_003BEBF8(m->b + 0x48, 1.0f, 0.075f);
                            func_003BEC60(&sp10.f[2], ((G_00352060 *)temp_16_7)->f[0x38/4], pv->b + 0x320, 0.060000002f, 0.90000004f, 0.96000004f);
                        }
                        if ((t > 11.0f) && (t < 22.0f)) {
                            vec_sub_ab(&sp20, &sp10, m->b + 0x10);
                            func_L01_00457728(m, &sp20);
                        }
                        if (func_L01_0044AF40(m, 31.0f) != 0) {
                            m->f[0x48/4] = 1.0f;
                            pv->f[0xA0/4] = 0.06981317f;
                            if (m->b[0x43] != 8) {
                                func_003BE4F0(m, 8, 0, 10);
                            }
                            func_L01_00441FB8(m, 0xE, 2);
                            pv->c[0x1A9] = 1;
                        }
                    }
                    break;
                case 7:                             /* switch 2 */
                    if (((s32) D_L24_001DF0C0_003510A0 >= 3) && ((temp_16_8 = D_L24_001DF51C_003510A0 + (pv->i[0x2EC/4] << 8), temp_4_8 = func_0037E0B8(temp_16_8), (temp_16_8 == 0)) || (temp_3_5 = ((G_00352060 *)temp_16_8)->b[0x20], (temp_3_5 == 0xFE)) || (temp_3_5 == 0xFD) || (*temp_4_8 <= 0.0f)) && (pv->h[0x234/2] == 1)) {
                        func_L01_00441FB8(m, 0x14, 2);
                        if (m->b[0x43] != 3) {
                            func_003BE4F0(m, 3, 0, 10);
                        }
                    }
                    break;
                }
            vec_sub_ba(&sp10, m->b + 0x10, &sp00);
            if ((func_003887A0(&sp10) < 0.0500000045f) && ((temp_3_6 = m->b[0x20], (temp_3_6 == 0xC)) || (temp_3_6 == 9) || (temp_3_6 == 0xD))) {
                pv->i[0x330/4] = (s32) (pv->i[0x330/4] + 1);
            } else {
                func_00388398(pv->b + 0x330);
            }
            if (((u32) (m->b[0x20] - 0x14) >= 2U) && (func_L01_0044E128(m->b + 0x10, 0, 0) < 0.1f)) {
                temp_3_7 = m->b[0x95];
                if (temp_3_7 != 4) {
                if ((temp_3_7 != 3) && ((func_003D00C0() == 0) || (func_003D00C0() == 1))) {
                    func_L01_00441FB8(m, 0x17, 4);
                    if (m->b[0x43] != 0xE) {
                        func_003BE4F0(m, 0xE, 6, 6);
                    }
                    posz = m->b + 0x18;
                    sp20.q = m->q[0x10/16];
                    func_L01_00301508(&sp20, 3, 3.25f, 1.025f);
                    for (var_16_2 = 2; var_16_2 >= 0; var_16_2--) {
                        sp30.f[0] = m->f[0x10/4] + func_0037E250(-0.3f, 0.3f);
                        temp_f1 = m->f[0x14/4] + func_0037E250(-0.3f, 0.3f);
                        sp30.f[2] = m->f[0x18/4];
                        sp30.f[1] = temp_f1;
                        func_L01_00467288(&sp30, posz, -1, func_0037E250(0.5f, 0.75f), 5250.0f);
                    }
                    var_18 = 0xF;
                    do {
                        var_18 -= 1;
                        temp_f21 = func_0037E2A8();
                        temp_f20_2 = func_0037E250(0, 0.0500000045f);
                        sp30.f[0] = func_00388960(temp_f21) * temp_f20_2;
                        sp30.f[1] = func_00388978(temp_f21) * temp_f20_2;
                        sp30.f[2] = func_0037E250(0.0500000045f, 0.13333334f);
                        sp40.f[0] = m->f[0x10/4] + (sp30.f[0] * 8.0f);
                        sp40.f[1] = m->f[0x14/4] + (sp30.f[0] * 8.0f);
                        sp40.f[2] = m->f[0x18/4] - func_0037E250(0, 0.2f);
                        temp_16_9 = func_0037E1D8(2);
                        func_L01_00465410(&sp40, &sp30, temp_16_9, func_0037E208(0x5A, 0x78));
                    } while (var_18 >= 0);
                }
                }
            }
            func_L24_003542C0(m);
}
/* localdecomp:end func_L24_003510A0 */
