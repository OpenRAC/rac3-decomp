#include "common.h"

/* NTSC-U counterpart of func_L21_003AEB70 (src/levels/21_obani_draco/L21_003AEB70.c) */
/* localdecomp:start func_L21_003AD028 */
#include "vu0.h"

extern s32 D_L21_001D6694_003AD028;
extern u8 *D_L21_001EC540[];
extern u8 D_001A4BE0[];
extern u8 D_L21_001D66B0_003AD028;
extern s32 func_L21_003ADC08(u8 *);
extern void func_L21_003ADE38(u8 *);
extern void func_L21_003AE058(void *);
extern void func_L21_003AE1A0(void *);
extern void func_L01_004A6DF8(void *, s32);
extern s32 func_L01_004B6C68(void);
extern s32 func_L01_00452EC8(void *);
extern s32 func_0037E208(s32, s32);
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern s32 func_L01_00443790(void *, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_004574A0(void *, void *, f32);
extern s32 func_003883C8(void *);
extern void func_L01_004026A0(void *, void *);
extern f32 func_L01_00436500(void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00457728(void *, void *);
extern s32 func_L01_00444F38_003AD028(s32, s32, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_0037E1D8(s32);
extern void func_L01_00468DC0(void *, void *, s32, f32, s32, u8, s32, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_L01_00451078(void *, void *);
extern s32 func_L03_0043C598(void *, s32, void *, s32, s32, f32, f32, f32, f32, s32, f32, f32, s32, s32, f32);
extern s32 func_L01_0032FE90_003AD028(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L21_003388A0(s32, s32, s32);
extern void func_L01_003154D8(void *, s32, void *);
extern void func_L21_003387D8(void *, void *, s32);
void func_L01_00441FB8(s32, s32, s32);

static __inline__ void syncvis_003AEB70(u8 *m)
{
    u8 *c = *(u8 **)(m + 0x24);
    *(u16 *)(m + 0x34) &= ~0x41;
    *(u16 *)(m + 0x34) |= *(u16 *)(c + 0x44) & 0x1000;
    *(s32 *)(m + 0x98) = *(s32 *)(c + 0x10);
}

void func_L21_003AD028(u8 *m)
{
    u8 *p;
    vu0_v4 pos;
    vu0_v4 a;
    vu0_v4 v;
    s32 n;
    s32 r;
    f32 f;

    if (func_L21_003ADC08(m) != 0) {
        return;
    }
    if (m[0x95] != 4) {
        if (D_L21_001D6694_003AD028 == 2) {
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & ~0x1000;
            func_L01_004A6DF8(m, 1);
            return;
        }
        if (func_L01_004B6C68() == 0) {
            syncvis_003AEB70(m);
        }
    }
    func_L21_003ADE38(m);
    pos = *(vu0_v4 *)(m + 0x10);
    p = *(u8 **)(m + 0x68);
    switch (m[0x20]) {
    case 2:
    case 3:
        if (func_L01_00452EC8(m) != 0 || (m[0x60] & 2)) {
            func_003BE4F0(m, func_0037E208(1, 2), 0, 10);
        }
        break;
    case 4:
        if (func_L01_00452EC8(m) != 0) {
            *(s32 *)(p + 0x1C8) &= ~0x10;
            func_L01_00458A70(m, 0.0033333334f, 0.06666667f, 0.0034906587f, 0.41887906f);
            *(f32 *)(p + 0x30C) = func_L01_00440918(25.0f, 50.0f) * 0.017453292f;
            n = func_0037E208(2, 8);
            *(s16 *)(p + 0x304) = 0;
            *(s16 *)(p + 0x306) = (f32)n * 60.0f;
            func_003BE4F0(m, 4, 0, 5);
        }
        if (m[0x43] == 4 && (m[0x60] & 2)) {
            func_003BE4F0(m, 5, 0, 0);
        } else if (m[0x43] == 5) {
            n = func_L01_00443790(m, 0, p[0x5F] ? 0x10000 : 1, 0, 1, 0, 0.3f, (f32)p[0x44], 1.0f);
            if (p[0x5F] != 0) {
                s32 j;
                for (j = 0; j < n; j++) {
                    if (*(s16 *)(D_L21_001EC540[j] + 0xAA) == *(s16 *)(m + 0xAA)) {
                        *(s16 *)(p + 0x304) = 1;
                    }
                }
            } else {
                s32 j;
                for (j = 0; j < n; j++) {
                    u8 *e = D_L21_001EC540[j];
                    u8 *g = D_001A4BE0;
                    if (e == *(u8 **)(g + 0x25C0)) {
                        *(s16 *)(p + 0x304) = 1;
                    }
                }
            }
            func_L01_004574A0(m, p + 0xB0, *(f32 *)(p + 0x30C));
            if (func_003883C8(p + 0x306) != 0) {
                *(f32 *)(p + 0x30C) = func_L01_00440918(25.0f, 50.0f) * 0.017453292f;
                *(s16 *)(p + 0x306) = (f32)func_0037E208(2, 8) * 60.0f;
            }
            func_L01_004026A0(func_L21_003AE1A0, m);
            if (*(s16 *)(p + 0x304) != 0 && (m[0x60] & 2)) {
                func_003BE4F0(m, 6, 0, 0);
            }
        } else if (m[0x43] == 6) {
            if (m[0x60] & 2) {
                *(s16 *)(p + 0x304) = 0;
                func_L01_00441FB8((s32)m, 5, -1);
            }
        }
        break;
    case 5:
        if (func_L01_00452EC8(m) != 0) {
            *(s32 *)(p + 0x1C8) &= ~0x10;
            func_003BE4F0(m, 8, 0, 0);
        }
        f = func_L01_00436500(m);
        if (8.0f < f && f < 18.0f) {

            func_00388830(&a, m + 0xC0, 0.16f);
            vec_neg(&a, &a);
            func_L01_00457728(m, &a);
            break;
        }
        if (m[0x60] & 2) {
            func_L01_00441FB8((s32)m, 4, -1);
        }
        break;
    case 6:
        if (func_L01_00452EC8(m) != 0) {
            *(s16 *)(p + 0x306) = 120;
            *(s32 *)(p + 0x1C8) &= ~0x10;
            func_003BE4F0(m, 0, 0, 0);
        }
        if (func_003883C8(p + 0x306) != 0) {
            if (m[0x95] == 0) {
                func_L01_00441FB8((s32)m, 2, -1);
            } else if (m[0x95] == 1) {
                func_L01_00441FB8((s32)m, 3, -1);
            } else if (m[0x95] == 2) {
                func_L01_00441FB8((s32)m, 4, -1);
            }
        }
        break;
    case 8:
        if (func_L01_00452EC8(m) != 0) {
            *(s16 *)(p + 0x306) = 30;
            *(f32 *)(p + 0x308) = 0.033333335f;
            *(u16 *)(m + 0x34) |= 0x808;
            p[0xE2] = p[0xE1] = 0xFF;
            func_003BE4F0(m, 3, 0, 0);
        }
        syncvis_003AEB70(m);
        if (func_003883C8(p + 0x306) != 0) {
            m[0x23] = 0x80;
            p[0xE1] = 7;
            p[0xE2] = 9;
            {
                s8 t = p[0x301];
                if (t == 2) {
                    p[0x300] = t;
                } else if (t == 3) {
                    p[0x300] = t;
                }
            }
            func_L01_00441FB8((s32)m, 2, 0);
            break;
        }
        m[0x23] = func_L01_00444F38_003AD028(0x80, 0, (f32)*(s16 *)(p + 0x306) * *(f32 *)(p + 0x308));
        {
        s32 i;
        for (i = 0; i < 5; i++) {
            f32 ang, r, sc;
            s32 col, k;

            qzero(&v);
            col = 0xFFE01FC8;
            v.z = func_0037E250(3.0f, 4.0f) * 0.0166666675f;
            ang = func_0037E2A8();
            r = func_0037E250(0.25f, 0.5f);
            a.x = func_00388960(ang) * r;
            a.y = func_00388978(ang) * r;
            a.z = 0.0f;
            vec_add_ba(&a, &a, m + 0x10);
            k = func_0037E208(0x1E, 0x3C);
            sc = func_0037E250(0.1f, 0.3f);
            if (func_0037E1D8(2) != 0) {
                col = 0xFFDE5CED;
            }
            func_L01_00468DC0(&a, &v, col, sc, k, func_0037E1D8(0xFF), 0, 0x40, 0);
        }
        }
        break;
    case 7:
        if (func_L01_00452EC8(m) != 0) {
            *(s16 *)(p + 0x306) = 30;
            *(f32 *)(p + 0x308) = 0.033333335f;
            *(u16 *)(m + 0x34) |= 0x808;
            p[0xE2] = p[0xE1] = 0xFF;
            func_003BE4F0(m, 3, 0, 10);
        }
        if (func_003883C8(p + 0x306) != 0) {
            m[0x23] = 0;
            p[0xE1] = 7;
            p[0xE2] = 9;
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & ~0x1000;
            func_L01_004A6DF8(m, 1);
            {
                s8 t = p[0x301];
                if (t == 0) {
                    p[0x300] = t;
                } else if (t == 1) {
                    p[0x300] = t;
                }
            }
            func_L01_00441FB8((s32)m, 1, 4);
            break;
        }
        m[0x23] = func_L01_00444F38_003AD028(0, 0x80, (f32)*(s16 *)(p + 0x306) * *(f32 *)(p + 0x308));
        {
        s32 i;
        for (i = 0; i < 5; i++) {
            f32 ang, r, sc;
            s32 col, k;

            qzero(&v);
            col = 0xFFE01FC8;
            v.z = func_0037E250(3.0f, 4.0f) * 0.0166666675f;
            ang = func_0037E2A8();
            r = func_0037E250(0.25f, 0.5f);
            a.x = func_00388960(ang) * r;
            a.y = func_00388978(ang) * r;
            a.z = 0.0f;
            vec_add_ba(&a, &a, m + 0x10);
            k = func_0037E208(0x1E, 0x3C);
            sc = func_0037E250(0.1f, 0.3f);
            if (func_0037E1D8(2) != 0) {
                col = 0xFFDE5CED;
            }
            func_L01_00468DC0(&a, &v, col, sc, k, func_0037E1D8(0xFF), 0, 0x40, 0);
        }
        }
        break;
    case 9:
        if (func_L01_00452EC8(m) != 0) {
            func_0039FE80(1, 0, m);
        }
        r = func_L01_00451078(m, p + 0xD0);
        if ((r & 1) || *(f32 *)(p + 0x30) <= 0.0f) {
            func_L03_0043C598(m, 0x7F, &D_L21_001D66B0_003AD028, 4, 2, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0.5f);
            func_L01_0032FE90_003AD028(m + 0x10, 0, 0xA, 0, 0, 0, 0xF, 2, 1.0f, 0.0f, 0.0f, 0.0f,
                0, 1, 0, 0, 1, 0, 0, 0, 0xF7388E, 0xF70063, 0xFF407F, 0xFF0020, 0xFF008F, 0xFF3064,
                0x7FFF60A0, 0x28FF0000, 0xFF3064, 0);
            if (func_0037E1D8(5) == 0) {
                func_L21_003388A0(*(s32 *)(m + 0xB8), 3, 0);
            }
            *(u16 *)(m + 0x34) &= ~0x808;
            func_L01_003154D8(m, 6, func_L21_003AE058);
            break;
        }
        if (r & 2) {
            func_003BE4F0(m, 0, 0, 0);
            if (m[0x95] == 0) {
                func_L01_00441FB8((s32)m, 2, -1);
            } else if (m[0x95] == 1) {
                func_L01_00441FB8((s32)m, 3, -1);
            } else if (m[0x95] == 2) {
                func_L01_00441FB8((s32)m, 4, -1);
            }
        }
        break;
    }
    if (m[0x95] == 2) {
        func_L21_003387D8(m, &pos, m[0x20] == 9);
    }
}
/* localdecomp:end func_L21_003AD028 */
