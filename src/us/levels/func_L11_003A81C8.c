#include "common.h"

/* NTSC-U counterpart of func_L11_003A9E60 (src/levels/11_obani_moons/L11_003A9E60.c) */
#include "vu0.h"

/* localdecomp:start func_L11_003A81C8 */
#include "vu0.h"

extern s32 D_001A71A4[];
extern u8 *D_L11_0021CB80_003A81C8[];
extern u8 *D_L11_001DEA4C_003A81C8;
extern u8 *D_L11_001DEF00_003A81C8;
extern u8 D_L11_001E84C0_003A81C8[];
extern u8 *D_L11_0021E6C8_003A81C8[];
extern u8 D_L11_001D66B0_003A81C8[8];

extern s32 func_L11_003A93A8(u8 *);
extern void func_003BD360(u8 *);
extern void func_L01_004A6DF8(u8 *, s32);
extern s32 func_L01_00452EF0(u8 *);
extern s32 func_0037E208(s32, s32);
extern s32 func_L01_00442998(s32, s32, s32);
extern s32 func_003883C8(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L02_00350598(void *);
extern s32 func_L01_00451078(u8 *, void *);
extern void func_L01_003154D8(u8 *, s32, s32);
extern f32 func_00388800(void *, void *);
extern void func_L01_00458E48(u8 *, void *, s32, s32);
extern s32 func_L01_00452EC8(u8 *);
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L01_00440A88(void *, f32, f32);
extern s32 func_L01_00453210(void *, s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00459BC8(u8 *, void *);
extern f32 func_003887C8(void *, void *);
extern s32 func_00388398(void *);
extern s32 func_L11_0042FDC8(u8 *, void *);
extern f32 func_L01_0044E4B8(u8 *, void *, s32);
extern s32 func_L01_00459BF8(u8 *, void *, void *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_003BD9A0(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_003BF5E0(s32);
extern void func_0037E2F0(void *, f32, f32);
extern void func_L01_0046FE70(void *, void *, s32, f32);
extern s32 func_0037E1D8(s32);
extern f32 func_L01_00440918(f32, f32);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern f32 func_L01_00436500(u8 *);
extern void func_003BDA38(u8 *, s32, void *);
extern s32 func_L01_0044AF40(u8 *, f32);
extern void func_L01_0044DE28(u8 *, void *, void *, s32, f32);
extern void func_L11_003ACE38(void *, u8 *, void *);
extern void func_L11_003A98B8(u8 *);

typedef struct { s16 f0; s16 f2; u8 pad4[0xC]; u8 *f10; u8 pad14[0x1C]; } E_3A9E60;
typedef struct { u8 hdr[0x30]; E_3A9E60 e[1]; } H_3A9E60;

void func_L11_003A81C8(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 d;
    vu0_v4 m[4];
    vu0_v4 d2;
    vu0_v4 d3;
    vu0_v4 d4;
    f32 f20;
    f32 f21;
    f32 f22;
    u8 *ret;

    if (func_L11_003A93A8(a0) != 0) {
        func_003BD360(a0);
        return;
    }
    if (D_001A71A4[0] == 0x31) {
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004A6DF8(a0, 1);
        return;
    }
    {
        u8 *ent = *(u8 **)(a0 + 0x24);

        *(u16 *)(a0 + 0x34) &= 0xFFBE;
        *(u16 *)(a0 + 0x34) |= *(u16 *)(ent + 0x44) & 0x1000;
        *(s32 *)(a0 + 0x98) = *(s32 *)(ent + 0x10);
    }

    switch (a0[0x95]) {
    case 0:
        if (func_L01_00452EF0(a0) != 0) {
            *(s16 *)(v + 0x2D6) = func_0037E208(0, 0x1E);
        }
        {
            s32 one = 1;
            s32 t;

            if (*(s32 *)(v + 0x2E4) != -1) {
                t = (func_L01_00442998(*(s32 *)(v + 0x2E4), -1, 1) == 0) ? one : 0;
            } else {
                t = 0;
            }
            if ((*(s16 *)(v + 0x234) == 1 || t != 0) && func_003883C8(v + 0x2D6) != 0) {
                if (a0[0x43] != 3) {
                    func_003BE4F0(a0, 3, 0, 10);
                }
                func_L01_00441FB8(a0, 4, 2);
                {
                    s32 n = -1;

                    if (*(s32 *)(v + 0x2E0) != n) {
                        func_L01_00441FB8(a0, 8, -1);
                    }
                    if (*(s32 *)(v + 0x2DC) != n) {
                        u8 *p = (u8 *)D_L11_001DEA4C_003A81C8 + *(s32 *)(v + 0x2DC) * 0x30;

                        if (*(s16 *)(p + 0x32) != 0) {
                            func_L01_00441FB8(a0, 7, -1);
                        }
                    }
                }
            } else if (*(s32 *)(v + 0x2D8) != 0) {
                if (func_003883C8(v + 0x2D6) != 0) {
                    func_L01_00441FB8(a0, 3, 1);
                    *(s32 *)(v + 0x2D8) = 0;
                    if (*(s32 *)(v + 0x2D0) < 300) {
                        *(s32 *)(v + 0x2D0) = func_0037E208(0x1E0, 0x258);
                    }
                }
            }
        }
        break;
    case 1:
        if (*(s16 *)(v + 0x234) == 1) {
            if (a0[0x43] != 3) {
                func_003BE4F0(a0, 3, 0, 10);
            }
            func_L01_00441FB8(a0, 4, 2);
            if (*(s32 *)(v + 0x2DC) != -1) {
                u8 *p = (u8 *)D_L11_001DEA4C_003A81C8 + *(s32 *)(v + 0x2DC) * 0x30;

                if (*(s16 *)(p + 0x32) != 0) {
                    func_L01_00441FB8(a0, 7, -1);
                }
            }
        } else if (*(s32 *)(v + 0x2D0) == 0) {
            func_L01_00441FB8(a0, 2, 0);
        }
        break;
    case 2:
        if (*(s16 *)(v + 0x234) != 1) {
            if (func_L01_00452EF0(a0) == 0) {
                func_L01_00441FB8(a0, 3, 1);
                *(s32 *)(v + 0x2D0) = func_0037E208(0x244, 0x258);
            }
        }
        break;
    case 3:
        if (*(f32 *)(v + 0x30) <= 0.0f) {
            *(f32 *)(v + 0x190) = 1.25f;
            *(f32 *)(v + 0x194) = 1.25f;
        }
        {
        s32 r = func_L01_00451078(a0, v + 0x160);

        if (r & 1) {
            func_L02_00350598(a0);
            func_L01_003154D8(a0, 0, 0);
            return;
        }
        if (r & 2) {
            if (*(s16 *)(v + 0x234) == 1) {
                if (a0[0x43] != 3) {
                    func_003BE4F0(a0, 3, 0, 10);
                }
                func_L01_00441FB8(a0, 4, 2);
                if (*(s32 *)(v + 0x2DC) != -1) {
                    u8 *p = (u8 *)D_L11_001DEA4C_003A81C8 + *(s32 *)(v + 0x2DC) * 0x30;

                    if (*(s16 *)(p + 0x32) != 0) {
                        func_L01_00441FB8(a0, 7, -1);
                    }
                }
            } else {
                func_L01_00441FB8(a0, 3, 1);
                *(s32 *)(v + 0x2D0) = func_0037E208(0x244, 0x258);
            }
        }
        }
        break;
    }

    switch (a0[0x20]) {
    case 1:
        if ((a0[0x60] & 2) != 0) {
            if (a0[0x43] != 2) {
                func_003BE4F0(a0, 2, 0, 10);
            }
            if (*(s32 *)(v + 0x2E8) != -1) {
                u8 *e = D_L11_0021CB80_003A81C8[*(s32 *)(v + 0x2E8)];

                f20 = func_00388800(a0 + 0x10, e + 0x10);
                if (func_00388800(a0 + 0x10, e + *(s32 *)e * 0x10) < f20) {
                    func_L01_00458E48(a0, e, 0, *(s32 *)e - 1);
                } else {
                    func_L01_00458E48(a0, e, *(s32 *)e - 1, 0);
                }
                func_L01_00441FB8(a0, 9, -1);
            } else {
                func_L01_00441FB8(a0, 10, -1);
            }
        }
        break;
    case 10:
        if (func_L01_00452EC8(a0) != 0) {
            f20 = func_0037E2A8();
            f21 = func_0037E250(6.0f, 9.0f);
            qzero(v + 0x310);
            *(f32 *)(v + 0x310) = func_00388960(f20) * f21;
            *(f32 *)(v + 0x314) = func_00388978(f20) * f21;
            func_L01_00440A88(v + 0x310, 5.0f, 8.0f);
            vec_add_ab(v + 0x310, v + 0x310, v + 0x300);
            if (*(s32 *)(v + 0x320) != -1) {
                if (func_L01_00453210(v + 0x310, *(s32 *)(v + 0x320)) == 0) {
                    *(vu0_q *)(v + 0x310) = *(vu0_q *)(v + 0x300);
                }
            }
            *(s32 *)(v + 0x324) = func_0037E208(0x190, 0x212);
            func_L01_00458A70(a0, 0.002222222276f, 0.03333333507f, 0.00698131742f, 0.139626354f);
        }
        func_L01_00459BC8(a0, v + 0x310);
        if (func_003887C8(a0 + 0x10, v + 0x310) < 2.0f) {
            f20 = func_0037E2A8();
            f21 = func_0037E250(6.0f, 9.0f);
            qzero(v + 0x310);
            *(f32 *)(v + 0x310) = func_00388960(f20) * f21;
            *(f32 *)(v + 0x314) = func_00388978(f20) * f21;
            vec_add_ab(v + 0x310, v + 0x310, v + 0x300);
            if (*(s32 *)(v + 0x320) != -1 && func_L01_00453210(v + 0x310, *(s32 *)(v + 0x320)) == 0) {
                *(vu0_q *)(v + 0x310) = *(vu0_q *)(v + 0x300);
            }
        }
        if (func_00388398(v + 0x324) != 0) {
            if (a0[0x43] != 1) {
                func_003BE4F0(a0, 1, 0, 0xF);
            }
            func_L01_00441FB8(a0, 1, -1);
        }
        break;
    case 9:
        if (func_L01_00452EC8(a0) != 0) {
            func_L01_00458A70(a0, 0.002222222276f, 0.03333333507f, 0.007757019252f, 0.2617993951f);
        }
        if (func_L11_0042FDC8(a0, D_L11_0021CB80_003A81C8[*(s32 *)(v + 0x2E8)]) != 0) {
            func_L01_00441FB8(a0, 1, -1);
            if (a0[0x43] != 1) {
                func_003BE4F0(a0, 1, 0, 10);
            }
        }
        break;
    case 8:
        if (func_L01_00452EC8(a0) != 0) {
            func_L01_00458A70(a0, 0.004444444552f, 0.1000000089f, 0.007757019252f, 0.2617993951f);
        }
        if (func_L11_0042FDC8(a0, D_L11_0021CB80_003A81C8[*(s32 *)(v + 0x2E0)]) != 0) {
            func_L01_00441FB8(a0, 4, -1);
            if (*(s32 *)(v + 0x2DC) != -1) {
                u8 *p = (u8 *)D_L11_001DEA4C_003A81C8 + *(s32 *)(v + 0x2DC) * 0x30;

                if (*(s16 *)(p + 0x32) != 0) {
                    func_L01_00441FB8(a0, 7, -1);
                }
            }
        }
        break;
    case 4:
        if (func_L01_00452EC8(a0) != 0) {
            func_L01_00458A70(a0, 0.004444444552f, 0.1000000089f, 0.007757019252f, 0.2617993951f);
        }
        func_L01_00459BC8(a0, v + 0x220);
        vec_sub_ba(&d, v + 0x220, a0 + 0x10);
        f20 = func_L01_0044E4B8(a0, &d, 0);
        if (func_00388800(a0 + 0x10, v + 0x220) < 8.0f) {
            if (f20 < 0.43633232f) {
                if (a0[0x43] != 0x17) {
                    func_003BE4F0(a0, 0x17, 0, 10);
                }
                func_L01_00441FB8(a0, 5, -1);
            }
        }
        break;
    case 7:
        if (func_L01_00452EC8(a0) != 0) {
            func_L01_00458A70(a0, 0.004444444552f, 0.1000000089f, 0.007757019252f, 0.2617993951f);
            {
                u8 *entry = (u8 *)D_L11_001DEA4C_003A81C8 + *(s32 *)(v + 0x2DC) * 0x30;
                u8 *arr = *(u8 **)(entry + 0x40);
                u8 *q = (u8 *)D_L11_001DEF00_003A81C8 + *(s32 *)arr * 0x80;
                *(vu0_q *)(v + 0x2F0) = *(vu0_q *)(q + 0x30);
            }
            {
            s32 i;
            for (i = 0; i < ((H_3A9E60 *)D_L11_001DEA4C_003A81C8)->e[*(s32 *)(v + 0x2DC)].f2; i++) {
                u8 *arr = *(u8 **)((u8 *)D_L11_001DEA4C_003A81C8 + *(s32 *)(v + 0x2DC) * 0x30 + 0x40);
                u8 *q = (u8 *)D_L11_001DEF00_003A81C8 + ((s32 *)arr)[i] * 0x80;
                f20 = func_003887C8(q + 0x30, v + 0x220);
                if (func_003887C8(v + 0x2F0, v + 0x220) < f20 ||
                    func_003887C8(a0 + 0x10, v + 0x2F0) < 2.0f) {
                    if (func_003887C8(a0 + 0x10, q + 0x30) > 2.0f) {
                        *(vu0_q *)(v + 0x2F0) = *(vu0_q *)(q + 0x30);
                    }
                }
            }
            }
        }
        if (func_003887C8(a0 + 0x10, v + 0x2F0) < 1.0f) {
            vec_sub_ba(&d, v + 0x220, a0 + 0x10);
            func_L01_00459BF8(a0, a0 + 0x10, &d);
            if (func_L01_0044E4B8(a0, &d, 0) < 0.17453292f) {
                func_L01_00441FB8(a0, 5, -1);
                if (a0[0x43] != 0x17) {
                    func_003BE4F0(a0, 0x17, 0, func_0037E208(10, 15));
                }
            }
        } else {
            func_L01_00459BC8(a0, v + 0x2F0);
        }
        break;
    case 5:
        if (func_L01_00452EC8(a0) != 0) {
            func_0039FE80(0, 0, a0);
            *(s32 *)(v + 0x330) = 0;
        }
        func_003BD9A0(a0, 0, m);
        func_00388830(&d, &m[1], -0.5f);
        vec_add_ba(&d, &m[3], &d);
        vec_sub_ba(&d2, v + 0x220, a0 + 0x10);
        func_L01_00459BF8(a0, a0 + 0x10, &d2);
        if (*(u16 *)(a0 + 0x96) >= 0x3C) {
            s32 flag = 0;
            if (func_003CE740(&d, v + 0x220, 2, a0, 0) == 0) {
                flag = 1;
            } else {
                u8 *q = D_L11_001E84C0_003A81C8;

                if (*(s32 *)(q + 0x18) != 0) {
                    if (func_003BF5E0(*(s32 *)(q + 0x18)) != 0) {
                        flag = 1;
                    } else {
                        s32 x = *(s32 *)(v + 0x230);

                        *(s32 *)(q + 0x18) = x;
                        flag = x != 0;
                    }
                }
            }
            if (flag != 0) {
                if (a0[0x43] != 0x18) {
                    func_003BE4F0(a0, 0x18, 0, 10);
                }
                func_L01_00441FB8(a0, 6, -1);
            }
        }
        func_0037E2F0(&d3, 0.0250000004f, 0.150000006f);
        vec_add_ba(&d3, &d3, &d);
        vec_sub_ab(&d4, &d, &d3);
        func_00388830(&d4, &d4, *(f32 *)(v + 0x330) * 0.01250000112f);
        func_L01_0046FE70(&d3, &d4, 0xF, 1.0f);
        f22 = *(f32 *)(v + 0x330) * 157500.0f;
        if (func_0037E1D8(2) != 0) {
            ret = func_L01_00466F98(&d, D_L11_001D66B0_003A81C8, 0xF, 6, 0x904020,
                                    (s32)func_L01_00440918(1.0f, -1.0f),
                                    f22 * 3.0f, 500.0f, 1.0f, 0.0f, 0.0f);
            if (ret != 0) {
                ret[2] = *((u8 *)D_L11_0021E6C8_003A81C8[0] + 1);
            }
        }
        f21 = 0.0f;
        f20 = 0.039999999f;
        *(f32 *)((u8 *)&d + 0x00) = *(f32 *)((u8 *)&d + 0x00) + func_L01_00440918(f21, f20);
        *(f32 *)((u8 *)&d + 0x04) = *(f32 *)((u8 *)&d + 0x04) + func_L01_00440918(f21, f20);
        *(f32 *)((u8 *)&d + 0x08) = *(f32 *)((u8 *)&d + 0x08) + func_L01_00440918(f21, f20);
        if (func_0037E1D8(2) != 0) {
            f20 = 1.0f;
            ret = func_L01_00466F98(&d, D_L11_001D66B0_003A81C8, 0xF, 0x5F, 0x804020,
                                    (s32)func_L01_00440918(1.0f, -1.0f),
                                    f22 * 2.4000001f, 500.0f, 1.0f, 0.0f, 0.0f);
            if (ret != 0) {
                ret[3] = func_0037E1D8(2) != 0 ? 0x48 : 0x44;
                ret[2] = *(u8 *)D_L11_0021E6C8_003A81C8[0];
            }
        }
        *(f32 *)(v + 0x330) = *(f32 *)(v + 0x330) + 0.01666666754f;
        if (*(f32 *)(v + 0x330) > 1.0f) {
            *(f32 *)(v + 0x330) = 1.0f;
        }
        break;
    case 6:
        if (func_L01_00436500(a0) < 3.0f || a0[0x42] != 0x18) {
            *(f32 *)(v + 0x330) = *(f32 *)(v + 0x330) + 0.03333333507f;
            func_003BDA38(a0, 0, &d);
            func_0037E2F0(&m[0], 0.0250000004f, 0.150000006f);
            vec_add_ba(&m[0], &m[0], &d);
            vec_sub_ab(&m[1], &d, &m[0]);
            func_00388830(&m[1], &m[1], *(f32 *)(v + 0x330) * 0.01250000112f);
            func_L01_0046FE70(&m[0], &m[1], 0xF, 1.0f);
            f22 = *(f32 *)(v + 0x330) * 157500.0f;
            if (func_0037E1D8(2) != 0) {
                ret = func_L01_00466F98(&d, D_L11_001D66B0_003A81C8, 0xF, 6, 0x904020,
                                        (s32)func_L01_00440918(1.0f, -1.0f),
                                        f22 * 3.0f, 500.0f, 1.0f, 0.0f, 0.0f);
                if (ret != 0) {
                    ret[2] = *((u8 *)D_L11_0021E6C8_003A81C8[0] + 1);
                }
            }
            f21 = 0.0f;
            f20 = 0.039999999f;
            *(f32 *)((u8 *)&d + 0x00) = *(f32 *)((u8 *)&d + 0x00) + func_L01_00440918(f21, f20);
            *(f32 *)((u8 *)&d + 0x04) = *(f32 *)((u8 *)&d + 0x04) + func_L01_00440918(f21, f20);
            *(f32 *)((u8 *)&d + 0x08) = *(f32 *)((u8 *)&d + 0x08) + func_L01_00440918(f21, f20);
            if (func_0037E1D8(2) != 0) {
                f20 = 1.0f;
                ret = func_L01_00466F98(&d, D_L11_001D66B0_003A81C8, 0xF, 0x5F, 0x804020,
                                        (s32)func_L01_00440918(1.0f, -1.0f),
                                        f22 * 2.4000001f, 500.0f, 1.0f, 0.0f, 0.0f);
                if (ret != 0) {
                    ret[3] = func_0037E1D8(2) != 0 ? 0x48 : 0x44;
                    ret[2] = *(u8 *)D_L11_0021E6C8_003A81C8[0];
                }
            }
        }
        if (func_L01_0044AF40(a0, 3.0f) != 0) {
            if (a0[0x42] == 0x18) {
                func_003BDA38(a0, 0, &d);
                vec_sub_ba(&m[0], v + 0x220, &d);
                func_L01_0044DE28(a0, &m[0], &m[0], 0, 0.0f);
                func_00388830(&m[0], &m[0], 0.2833333611f);
                func_L11_003ACE38(&d, a0, &m[0]);
            }
        }
        if ((a0[0x60] & 2) != 0) {
            *(s32 *)(v + 0x32C) = 0;
            func_L01_00441FB8(a0, 4, -1);
            if (a0[0x43] != 3) {
                func_003BE4F0(a0, 3, 0, 10);
            }
            if (*(s32 *)(v + 0x2DC) != -1) {
                u8 *p = (u8 *)D_L11_001DEA4C_003A81C8 + *(s32 *)(v + 0x2DC) * 0x30;

                if (*(s16 *)(p + 0x32) != 0) {
                    func_L01_00441FB8(a0, 7, -1);
                }
            }
        }
        break;
    case 2:
    case 3:
        break;
    }

    func_L11_003A98B8(a0);
}
/* localdecomp:end func_L11_003A81C8 */
