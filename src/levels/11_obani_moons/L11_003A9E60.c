#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L11_003A9E60 */
#include "vu0.h"

extern s32 D_001A71A4[];
extern u8 *D_L11_0021CB80[];
extern u8 *D_L11_001DEA4C;
extern u8 *D_L11_001DEF00;
extern u8 D_L11_001E84C0[];
extern u8 *D_L11_0021E6C8[];
extern u8 D_L11_001D66B0[8];

extern s32 func_L11_003AB080(u8 *);
extern void func_003C2880(u8 *);
extern void func_L01_004AA7E8(u8 *, s32);
extern s32 func_L01_004561E0(u8 *);
extern s32 func_00382498(s32, s32);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern s32 func_0038CB00(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L02_003516A8(void *);
extern s32 func_L01_00454370(u8 *, void *);
extern void func_L01_00315900(u8 *, s32, s32);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_0045C150(u8 *, void *, s32, s32);
extern s32 func_L01_004561B8(u8 *);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_00443B88(void *, f32, f32);
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_0045CED0(u8 *, void *);
extern f32 func_0038CF00(void *, void *);
extern s32 func_0038CAD0(void *);
extern s32 func_L11_00433210(u8 *, void *);
extern f32 func_L01_00451738(u8 *, void *, s32);
extern s32 func_L01_0045CF00(u8 *, void *, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003C4B50(s32);
extern void func_00382580(void *, f32, f32);
extern void func_L01_004735F0(void *, void *, s32, f32);
extern s32 func_00382468(s32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern f32 func_L01_004395E0(u8 *);
extern void func_003C2F58(u8 *, s32, void *);
extern s32 func_L01_0044E1B8(u8 *, f32);
extern void func_L01_004510A8(u8 *, void *, void *, s32, f32);
extern void func_L11_003AEBE8(void *, u8 *, void *);
extern void func_L11_003AB590(u8 *);

typedef struct { s16 f0; s16 f2; u8 pad4[0xC]; u8 *f10; u8 pad14[0x1C]; } E_3A9E60;
typedef struct { u8 hdr[0x30]; E_3A9E60 e[1]; } H_3A9E60;

void func_L11_003A9E60(u8 *a0)
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

    if (func_L11_003AB080(a0) != 0) {
        func_003C2880(a0);
        return;
    }
    if (D_001A71A4[0] == 0x31) {
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004AA7E8(a0, 1);
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
        if (func_L01_004561E0(a0) != 0) {
            *(s16 *)(v + 0x2D6) = (func_00382498(0, 0x1E) * 5 + 2) / 6;
        }
        {
            s32 one = 1;
            s32 t;

            if (*(s32 *)(v + 0x2E4) != -1) {
                t = (func_L01_00445AD0(*(s32 *)(v + 0x2E4), -1, 1) == 0) ? one : 0;
            } else {
                t = 0;
            }
            if ((*(s16 *)(v + 0x234) == 1 || t != 0) && func_0038CB00(v + 0x2D6) != 0) {
                if (a0[0x43] != 3) {
                    func_003C3A10(a0, 3, 0, 8);
                }
                func_L01_004450F0(a0, 4, 2);
                {
                    s32 n = -1;

                    if (*(s32 *)(v + 0x2E0) != n) {
                        func_L01_004450F0(a0, 8, -1);
                    }
                    if (*(s32 *)(v + 0x2DC) != n) {
                        u8 *p = (u8 *)D_L11_001DEA4C + *(s32 *)(v + 0x2DC) * 0x30;

                        if (*(s16 *)(p + 0x32) != 0) {
                            func_L01_004450F0(a0, 7, -1);
                        }
                    }
                }
            } else if (*(s32 *)(v + 0x2D8) != 0) {
                if (func_0038CB00(v + 0x2D6) != 0) {
                    func_L01_004450F0(a0, 3, 1);
                    *(s32 *)(v + 0x2D8) = 0;
                    if (*(s32 *)(v + 0x2D0) < 250) {
                        *(s32 *)(v + 0x2D0) = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
                    }
                }
            }
        }
        break;
    case 1:
        if (*(s16 *)(v + 0x234) == 1) {
            if (a0[0x43] != 3) {
                func_003C3A10(a0, 3, 0, 8);
            }
            func_L01_004450F0(a0, 4, 2);
            if (*(s32 *)(v + 0x2DC) != -1) {
                u8 *p = (u8 *)D_L11_001DEA4C + *(s32 *)(v + 0x2DC) * 0x30;

                if (*(s16 *)(p + 0x32) != 0) {
                    func_L01_004450F0(a0, 7, -1);
                }
            }
        } else if (*(s32 *)(v + 0x2D0) == 0) {
            func_L01_004450F0(a0, 2, 0);
        }
        break;
    case 2:
        if (*(s16 *)(v + 0x234) != 1) {
            if (func_L01_004561E0(a0) == 0) {
                func_L01_004450F0(a0, 3, 1);
                *(s32 *)(v + 0x2D0) = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    case 3:
        if (*(f32 *)(v + 0x30) <= 0.0f) {
            *(f32 *)(v + 0x190) = 1.25f;
            *(f32 *)(v + 0x194) = 1.25f;
        }
        {
        s32 r = func_L01_00454370(a0, v + 0x160);

        if (r & 1) {
            func_L02_003516A8(a0);
            func_L01_00315900(a0, 0, 0);
            return;
        }
        if (r & 2) {
            if (*(s16 *)(v + 0x234) == 1) {
                if (a0[0x43] != 3) {
                    func_003C3A10(a0, 3, 0, 8);
                }
                func_L01_004450F0(a0, 4, 2);
                if (*(s32 *)(v + 0x2DC) != -1) {
                    u8 *p = (u8 *)D_L11_001DEA4C + *(s32 *)(v + 0x2DC) * 0x30;

                    if (*(s16 *)(p + 0x32) != 0) {
                        func_L01_004450F0(a0, 7, -1);
                    }
                }
            } else {
                func_L01_004450F0(a0, 3, 1);
                *(s32 *)(v + 0x2D0) = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
            }
        }
        }
        break;
    }

    switch (a0[0x20]) {
    case 1:
        if ((a0[0x60] & 2) != 0) {
            if (a0[0x43] != 2) {
                func_003C3A10(a0, 2, 0, 8);
            }
            if (*(s32 *)(v + 0x2E8) != -1) {
                u8 *e = D_L11_0021CB80[*(s32 *)(v + 0x2E8)];

                f20 = func_0038CF38(a0 + 0x10, e + 0x10);
                if (func_0038CF38(a0 + 0x10, e + *(s32 *)e * 0x10) < f20) {
                    func_L01_0045C150(a0, e, 0, *(s32 *)e - 1);
                } else {
                    func_L01_0045C150(a0, e, *(s32 *)e - 1, 0);
                }
                func_L01_004450F0(a0, 9, -1);
            } else {
                func_L01_004450F0(a0, 10, -1);
            }
        }
        break;
    case 10:
        if (func_L01_004561B8(a0) != 0) {
            f20 = func_00382538();
            f21 = func_003824E0(6.0f, 9.0f);
            qzero(v + 0x310);
            *(f32 *)(v + 0x310) = func_0038D098(f20) * f21;
            *(f32 *)(v + 0x314) = func_0038D0B0(f20) * f21;
            func_L01_00443B88(v + 0x310, 5.0f, 8.0f);
            vec_add_ab(v + 0x310, v + 0x310, v + 0x300);
            if (*(s32 *)(v + 0x320) != -1) {
                if (func_L01_00456500(v + 0x310, *(s32 *)(v + 0x320)) == 0) {
                    *(vu0_q *)(v + 0x310) = *(vu0_q *)(v + 0x300);
                }
            }
            *(s32 *)(v + 0x324) = func_00382498(0x190, 0x212);
            func_L01_0045BD78(a0, 0.0032000002f, 0.040000003f, 0.010053097f, 0.16755162f);
        }
        func_L01_0045CED0(a0, v + 0x310);
        if (func_0038CF00(a0 + 0x10, v + 0x310) < 2.0f) {
            f20 = func_00382538();
            f21 = func_003824E0(6.0f, 9.0f);
            qzero(v + 0x310);
            *(f32 *)(v + 0x310) = func_0038D098(f20) * f21;
            *(f32 *)(v + 0x314) = func_0038D0B0(f20) * f21;
            vec_add_ab(v + 0x310, v + 0x310, v + 0x300);
            if (*(s32 *)(v + 0x320) != -1 && func_L01_00456500(v + 0x310, *(s32 *)(v + 0x320)) == 0) {
                *(vu0_q *)(v + 0x310) = *(vu0_q *)(v + 0x300);
            }
        }
        if (func_0038CAD0(v + 0x324) != 0) {
            if (a0[0x43] != 1) {
                func_003C3A10(a0, 1, 0, 0xC);
            }
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    case 9:
        if (func_L01_004561B8(a0) != 0) {
            func_L01_0045BD78(a0, 0.0032000002f, 0.040000003f, 0.011170108f, 0.31415927f);
        }
        if (func_L11_00433210(a0, D_L11_0021CB80[*(s32 *)(v + 0x2E8)]) != 0) {
            func_L01_004450F0(a0, 1, -1);
            if (a0[0x43] != 1) {
                func_003C3A10(a0, 1, 0, 8);
            }
        }
        break;
    case 8:
        if (func_L01_004561B8(a0) != 0) {
            func_L01_0045BD78(a0, 0.0064000003f, 0.120000005f, 0.011170108f, 0.31415927f);
        }
        if (func_L11_00433210(a0, D_L11_0021CB80[*(s32 *)(v + 0x2E0)]) != 0) {
            func_L01_004450F0(a0, 4, -1);
            if (*(s32 *)(v + 0x2DC) != -1) {
                u8 *p = (u8 *)D_L11_001DEA4C + *(s32 *)(v + 0x2DC) * 0x30;

                if (*(s16 *)(p + 0x32) != 0) {
                    func_L01_004450F0(a0, 7, -1);
                }
            }
        }
        break;
    case 4:
        if (func_L01_004561B8(a0) != 0) {
            func_L01_0045BD78(a0, 0.0064000003f, 0.120000005f, 0.011170108f, 0.31415927f);
        }
        func_L01_0045CED0(a0, v + 0x220);
        vec_sub_ba(&d, v + 0x220, a0 + 0x10);
        f20 = func_L01_00451738(a0, &d, 0);
        if (func_0038CF38(a0 + 0x10, v + 0x220) < 8.0f) {
            if (f20 < 0.43633232f) {
                if (a0[0x43] != 0x17) {
                    func_003C3A10(a0, 0x17, 0, 8);
                }
                func_L01_004450F0(a0, 5, -1);
            }
        }
        break;
    case 7:
        if (func_L01_004561B8(a0) != 0) {
            func_L01_0045BD78(a0, 0.0064000003f, 0.120000005f, 0.011170108f, 0.31415927f);
            {
                u8 *entry = (u8 *)D_L11_001DEA4C + *(s32 *)(v + 0x2DC) * 0x30;
                u8 *arr = *(u8 **)(entry + 0x40);
                u8 *q = (u8 *)D_L11_001DEF00 + *(s32 *)arr * 0x80;
                *(vu0_q *)(v + 0x2F0) = *(vu0_q *)(q + 0x30);
            }
            {
            s32 i;
            for (i = 0; i < ((H_3A9E60 *)D_L11_001DEA4C)->e[*(s32 *)(v + 0x2DC)].f2; i++) {
                u8 *arr = *(u8 **)((u8 *)D_L11_001DEA4C + *(s32 *)(v + 0x2DC) * 0x30 + 0x40);
                u8 *q = (u8 *)D_L11_001DEF00 + ((s32 *)arr)[i] * 0x80;
                f20 = func_0038CF00(q + 0x30, v + 0x220);
                if (func_0038CF00(v + 0x2F0, v + 0x220) < f20 ||
                    func_0038CF00(a0 + 0x10, v + 0x2F0) < 2.0f) {
                    if (func_0038CF00(a0 + 0x10, q + 0x30) > 2.0f) {
                        *(vu0_q *)(v + 0x2F0) = *(vu0_q *)(q + 0x30);
                    }
                }
            }
            }
        }
        if (func_0038CF00(a0 + 0x10, v + 0x2F0) < 1.0f) {
            vec_sub_ba(&d, v + 0x220, a0 + 0x10);
            func_L01_0045CF00(a0, a0 + 0x10, &d);
            if (func_L01_00451738(a0, &d, 0) < 0.17453292f) {
                func_L01_004450F0(a0, 5, -1);
                if (a0[0x43] != 0x17) {
                    func_003C3A10(a0, 0x17, 0, (func_00382498(10, 15) * 5 + 2) / 6);
                }
            }
        } else {
            func_L01_0045CED0(a0, v + 0x2F0);
        }
        break;
    case 5:
        if (func_L01_004561B8(a0) != 0) {
            func_003A52A0(0, 0, a0);
            *(s32 *)(v + 0x330) = 0;
        }
        func_003C2EC0(a0, 0, m);
        func_0038CF68(&d, &m[1], -0.5f);
        vec_add_ba(&d, &m[3], &d);
        vec_sub_ba(&d2, v + 0x220, a0 + 0x10);
        func_L01_0045CF00(a0, a0 + 0x10, &d2);
        if (*(u16 *)(a0 + 0x96) >= 0x32) {
            s32 flag = 0;
            if (func_003D3CB0(&d, v + 0x220, 2, a0, 0) == 0) {
                flag = 1;
            } else {
                u8 *q = D_L11_001E84C0;

                if (*(s32 *)(q + 0x18) != 0) {
                    if (func_003C4B50(*(s32 *)(q + 0x18)) != 0) {
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
                    func_003C3A10(a0, 0x18, 0, 8);
                }
                func_L01_004450F0(a0, 6, -1);
            }
        }
        func_00382580(&d3, 0.0250000004f, 0.150000006f);
        vec_add_ba(&d3, &d3, &d);
        vec_sub_ab(&d4, &d, &d3);
        func_0038CF68(&d4, &d4, *(f32 *)(v + 0x330) * 0.0150000006f);
        func_L01_004735F0(&d3, &d4, 0xC, 1.0f);
        f22 = *(f32 *)(v + 0x330) * 157500.0f;
        if (func_00382468(2) != 0) {
            ret = func_L01_0046A610(&d, D_L11_001D66B0, 0xC, 6, 0x904020,
                                    (s32)func_L01_00443A18(1.0f, -1.0f),
                                    f22 * 3.0f, 500.0f, 1.0f, 0.0f, 0.0f);
            if (ret != 0) {
                ret[2] = *((u8 *)D_L11_0021E6C8[0] + 1);
            }
        }
        f21 = 0.0f;
        f20 = 0.039999999f;
        *(f32 *)((u8 *)&d + 0x00) = *(f32 *)((u8 *)&d + 0x00) + func_L01_00443A18(f21, f20);
        *(f32 *)((u8 *)&d + 0x04) = *(f32 *)((u8 *)&d + 0x04) + func_L01_00443A18(f21, f20);
        *(f32 *)((u8 *)&d + 0x08) = *(f32 *)((u8 *)&d + 0x08) + func_L01_00443A18(f21, f20);
        if (func_00382468(2) != 0) {
            f20 = 1.0f;
            ret = func_L01_0046A610(&d, D_L11_001D66B0, 0xC, 0x5F, 0x804020,
                                    (s32)func_L01_00443A18(1.0f, -1.0f),
                                    f22 * 2.4000001f, 500.0f, 1.0f, 0.0f, 0.0f);
            if (ret != 0) {
                ret[3] = func_00382468(2) != 0 ? 0x48 : 0x44;
                ret[2] = *(u8 *)D_L11_0021E6C8[0];
            }
        }
        *(f32 *)(v + 0x330) = *(f32 *)(v + 0x330) + 0.020000001f;
        if (*(f32 *)(v + 0x330) > 1.0f) {
            *(f32 *)(v + 0x330) = 1.0f;
        }
        break;
    case 6:
        if (func_L01_004395E0(a0) < 3.0f || a0[0x42] != 0x18) {
            *(f32 *)(v + 0x330) = *(f32 *)(v + 0x330) + 0.040000003f;
            func_003C2F58(a0, 0, &d);
            func_00382580(&m[0], 0.0250000004f, 0.150000006f);
            vec_add_ba(&m[0], &m[0], &d);
            vec_sub_ab(&m[1], &d, &m[0]);
            func_0038CF68(&m[1], &m[1], *(f32 *)(v + 0x330) * 0.0150000006f);
            func_L01_004735F0(&m[0], &m[1], 0xC, 1.0f);
            f22 = *(f32 *)(v + 0x330) * 157500.0f;
            if (func_00382468(2) != 0) {
                ret = func_L01_0046A610(&d, D_L11_001D66B0, 0xC, 6, 0x904020,
                                        (s32)func_L01_00443A18(1.0f, -1.0f),
                                        f22 * 3.0f, 500.0f, 1.0f, 0.0f, 0.0f);
                if (ret != 0) {
                    ret[2] = *((u8 *)D_L11_0021E6C8[0] + 1);
                }
            }
            f21 = 0.0f;
            f20 = 0.039999999f;
            *(f32 *)((u8 *)&d + 0x00) = *(f32 *)((u8 *)&d + 0x00) + func_L01_00443A18(f21, f20);
            *(f32 *)((u8 *)&d + 0x04) = *(f32 *)((u8 *)&d + 0x04) + func_L01_00443A18(f21, f20);
            *(f32 *)((u8 *)&d + 0x08) = *(f32 *)((u8 *)&d + 0x08) + func_L01_00443A18(f21, f20);
            if (func_00382468(2) != 0) {
                f20 = 1.0f;
                ret = func_L01_0046A610(&d, D_L11_001D66B0, 0xC, 0x5F, 0x804020,
                                        (s32)func_L01_00443A18(1.0f, -1.0f),
                                        f22 * 2.4000001f, 500.0f, 1.0f, 0.0f, 0.0f);
                if (ret != 0) {
                    ret[3] = func_00382468(2) != 0 ? 0x48 : 0x44;
                    ret[2] = *(u8 *)D_L11_0021E6C8[0];
                }
            }
        }
        if (func_L01_0044E1B8(a0, 3.0f) != 0) {
            if (a0[0x42] == 0x18) {
                func_003C2F58(a0, 0, &d);
                vec_sub_ba(&m[0], v + 0x220, &d);
                func_L01_004510A8(a0, &m[0], &m[0], 0, 0.0f);
                func_0038CF68(&m[0], &m[0], 0.34000003f);
                func_L11_003AEBE8(&d, a0, &m[0]);
            }
        }
        if ((a0[0x60] & 2) != 0) {
            *(s32 *)(v + 0x32C) = 0;
            func_L01_004450F0(a0, 4, -1);
            if (a0[0x43] != 3) {
                func_003C3A10(a0, 3, 0, 8);
            }
            if (*(s32 *)(v + 0x2DC) != -1) {
                u8 *p = (u8 *)D_L11_001DEA4C + *(s32 *)(v + 0x2DC) * 0x30;

                if (*(s16 *)(p + 0x32) != 0) {
                    func_L01_004450F0(a0, 7, -1);
                }
            }
        }
        break;
    case 2:
    case 3:
        break;
    }

    func_L11_003AB590(a0);
}
/* localdecomp:end func_L11_003A9E60 */

/* localdecomp:start func_L11_003AB080 */
extern s32 func_L11_003AB258(u8 *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L02_00351780(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L02_003516A8(void *);
extern void func_L01_00404A10(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L11_003AB080(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);

    if (a0[0x20] == 0 && func_L11_003AB258(a0) != 0) {
        return 1;
    }
    if (v[0x3E] == 2) {
        goto die;
    }
    if (func_L01_00452FB0(a0, v + 0x160, 0, 0, 0) != 0) {
        func_003A52A0(3, 0, a0);
        func_L02_00351780(a0);
    }
    func_L01_00452860(a0, v + 0x30, 0);
    if (v[0x5E] != 0) {
die:
        func_L02_003516A8(a0);
        return 1;
    }
    if (v[0x5F] != 0) {
        func_L01_00404A10(a0, 5);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(v + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(v + 0x2CC), 10.0f, 1.0f);
        }
    } else {
        func_L01_00404A10(a0, 3);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(v + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(v + 0x2CC), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L11_003AB080 */

/* localdecomp:start func_L11_003AB258 */
extern vu0_v4 D_L11_001E84E0;
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

s32 func_L11_003AB258(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 m[4];
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 m2[4];
    vu0_q qp, qa, qb;

    func_003C5180(a0 + 0x10, m, 0);
    func_L01_004515D8(a0 + 0xC0, &m[0], &m[1]);
    *(s16 *)(a0 + 0x7C) = 0xFF;
    func_0038CF68(&a, a0 + 0xE0, 0.5f);
    func_0038CF68(&b, a0 + 0xE0, -4.0f);
    /* a + pos and b + pos with one load of the position (VU0) */
    __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)(a0 + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qp));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(qa));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qb) : "j"(qb), "j"(qp));
    __asm__("sqc2 %1, %0" : "=m"(b) : "j"(qb));
    if (func_003D3CB0(&a, &b, 2, a0, 0) != 0) {
        *(vu0_v4 *)(a0 + 0x10) = D_L11_001E84E0;
        func_003C5180(a0 + 0x10, m2, 0);
        func_L01_004515D8(a0 + 0xC0, &m2[0], &m2[1]);
    }
    *(vu0_v4 *)(v + 0x300) = *(vu0_v4 *)(a0 + 0x10);
    v[0x170] = 0xB;
    v[0x1DB] = 0xFF;
    *(f32 *)(v + 0x190) = 0.5f;
    *(f32 *)(v + 0x194) = 0.1f;
    v[0x1D7] = 1;
    v[0x1D8] = 0;
    v[0x1D9] = 0;
    *(f32 *)(v + 0x19C) = 0.15f;
    v[0x1DA] = 0;
    v[0x1A8] = 3;
    *(u16 *)(a0 + 0x34) |= 0x100;
    *(f32 *)(v + 0x70) = 0.5f;
    *(f32 *)(v + 0x74) = 0.1f;
    *(f32 *)(v + 0x78) = 0.75f;
    *(f32 *)(v + 0x7C) = 1.25f;
    *(f32 *)(v + 0x80) = 1.553343f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(f32 *)(v + 0x9C) = 0.00392f;
    func_L01_0045BD78(a0, 0.0064000003f, 0.120000005f, 0.010053097f, 0.25132743f);
    v[0x58] = 0x14;
    v[0x5A] = 0xE;
    if (*(s16 *)(v + 0x34) == 0) {
        *(s16 *)(v + 0x34) = 10;
        *(f32 *)(v + 0x30) = 10.0f;
    }
    v[0x39] = 1;
    v[0x3E] = 1;
    v[0x3F] = 0;
    *(f32 *)(v + 0x40) = 1.0f;
    func_L01_004450F0(a0, 2, 0);
    if (a0[0x43] != 0) {
        func_003C3A10(a0, 0, 0, 0);
    }
    if (*(s32 *)(v + 0x2E8) != -1) {
        func_L01_004450F0(a0, 9, -1);
        if (a0[0x43] != 2) {
            func_003C3A10(a0, 2, 0, 8);
        }
    } else if (*(s32 *)(v + 0x2EC) == 0) {
        func_L01_004450F0(a0, 10, -1);
        if (a0[0x43] != 2) {
            func_003C3A10(a0, 2, 0, 8);
        }
    }
    return 0;
}
/* localdecomp:end func_L11_003AB258 */
