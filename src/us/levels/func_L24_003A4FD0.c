#include "common.h"

/* NTSC-U counterpart of func_L24_003A6BA8 (src/levels/24_insomniac_museum/L24_003A6BA8.c) */
/* localdecomp:start func_L24_003A4FD0 */
typedef int u128_003A6BA8 __attribute__((mode(TI)));

__asm__(".extern D_L24_001DE340, 4");
extern s32 D_L24_001DE340;
extern u8 D_001CD0C0[];
extern s32 D_L24_001DF0C0_003A4FD0;
extern s32 D_L24_002CF570[];
extern s32 D_L24_001DD5B4_003A4FD0;

extern void func_L24_003A6DA0(u8 *);
extern void func_L24_003A5A18(u8 *, u8 *);
extern s32 func_L24_003A6CA0(u8 *);
extern void func_L24_003A6110(u8 *, u8 *);
extern void func_L24_003A5980(s32 *, s32 *);
extern void func_L24_003A69F8(void);
extern void func_L24_003A6A70(u8 *);
extern void func_L24_003A6530(void);
extern void func_L24_003A63F0(u8 *, u8 *);
extern void func_L24_003A5AE0(u8 *, u8 *, s32, s32);
extern void func_L24_003A5B78(u8 *, u8 *);
extern void func_L24_003A5ED0(u8 *, u8 *);
extern void func_L24_003A5E18(u8 *, u8 *);
extern void func_L24_003A6CF0(u8 *);
extern void func_L24_003A5C98(u8 *, u8 *, s32);
extern void func_L01_003D31A0(void);
extern void func_L01_004100D8(void);
extern void func_L01_00479140(s32 a0, s32 idx, u8 flag, f32 f);
extern void func_003BD360(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_00388440(void *, s32, s32);
extern f32 func_L01_00445758(void *, f32, void *, f32, f32, f32, s32);
extern s32 func_L01_00451078(void *, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00402498(void *, void *);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_L01_0044AF40(void *, f32);
extern f32 func_L01_00436500(void *);

void func_L24_003A4FD0(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    s32 x;
    s32 y;
    s32 r;
    s32 res;
    s32 i;
    u32 btn;

    if (*(s32 *)(v + 0x950) == 1) {
        func_L24_003A6DA0(o);
        return;
    }
    if (D_L24_001DF0C0_003A4FD0 < 10) {
        func_L24_003A5A18(o, v);
    }
    if (D_L24_002CF570[0] != 5) {
        return;
    }
    func_L01_00479140(0, 1, 0, *(f32 *)(v + 0x30) / (f32)*(s16 *)(v + 0x34));
    if (D_L24_001DD5B4_003A4FD0 > 80) {
        D_L24_001DD5B4_003A4FD0 = 0;
    }
    if (D_L24_001DD5B4_003A4FD0 != 0) {
        D_L24_001DD5B4_003A4FD0 = D_L24_001DD5B4_003A4FD0 + 1;
        ((void (*)(u8 *))func_L01_003D31A0)(o);
        *(u128_003A6BA8 *)(o + 0x10) = *(u128_003A6BA8 *)(v + 0x910);
        func_L01_00441FB8(o, 0, 1);
        if (o[0x43] != 0) {
            func_003BE4F0(o, 0, 0, 4);
        }
        *(f32 *)(v + 0x30) = *(s16 *)(v + 0x34);
        *(s32 *)(o + 0x98) = *(s32 *)(*(u8 **)(o + 0x24) + 0x10);
        *(s16 *)(v + 0x198) = 0;
        return;
    }
    x = 0;
    r = 1;
    y = 0;
    if (func_L24_003A6CA0(o)) {
        func_003BD360(o);
        return;
    }
    func_L24_003A6110(o, v);
    if (*(f32 *)(o + 0x10) < 273.0f) {
        *(f32 *)(o + 0x10) = 273.0f;
    }
    if (284.0f < *(f32 *)(o + 0x10)) {
        *(f32 *)(o + 0x10) = 284.0f;
    }
    switch (o[0x95]) {
    case 0:
        *(u128_003A6BA8 *)(v + 0x910) = *(u128_003A6BA8 *)(o + 0x10);
        for (i = 1; i < 8; i++) {
            if (D_001CD0C0[i * 0x5C0 + 0x558] != 0) {
                D_L24_001DE340 = i;
                break;
            }
        }
        if (D_L24_001DE340 == 0) {
            return;
        }
        func_L01_00441FB8(o, 0, 1);
        func_00388440(v + 0x990, 0, 0x80);
        break;
    case 1:
        func_L24_003A5980(&x, &y);
        if (x > 0) {
            *(f32 *)(v + 0x948) = 0.0f;
        } else {
            *(f32 *)(v + 0x948) = 3.1415927f;
        }
        func_L01_00445758(o + 0xF8, *(f32 *)(v + 0x948), v + 0x944, 0.2617994f, 0.2617994f, 0.29088822f, 0);
        break;
    case 4:
        if (x > 0) {
            *(f32 *)(v + 0x948) = 1.5707964f;
        } else {
            *(f32 *)(v + 0x948) = 4.712389f;
        }
        func_L01_00445758(o + 0xF8, *(f32 *)(v + 0x948), v + 0x944, 0.2617994f, 0.2617994f, 0.29088822f, 0);
        break;
    case 3:
        if (x > 0) {
            *(f32 *)(v + 0x948) = 0.0f;
        } else {
            *(f32 *)(v + 0x948) = 3.1415927f;
        }
        func_L01_00445758(o + 0xF8, *(f32 *)(v + 0x948), v + 0x944, 0.2617994f, 0.2617994f, 0.29088822f, 0);
        break;
    case 5:
        res = func_L01_00451078(o, v + 0x160);
        if (res & 1) {
            D_L24_001DD5B4_003A4FD0++;
            ((void (*)(u8 *))func_L01_003D31A0)(o);
            *(u128_003A6BA8 *)(o + 0x10) = *(u128_003A6BA8 *)(v + 0x910);
            func_L01_00441FB8(o, 0, 1);
            if (o[0x43] != 0) {
                func_003BE4F0(o, 0, 0, 4);
            }
            *(f32 *)(v + 0x30) = *(s16 *)(v + 0x34);
            *(s32 *)(o + 0x98) = *(s32 *)(*(u8 **)(o + 0x24) + 0x10);
            *(s16 *)(v + 0x198) = 0;
            return;
        }
        if (res & 2) {
            func_L01_00441FB8(o, 0, 1);
        }
        break;
    }

    switch (o[0x20]) {
    case 11:
        *(u16 *)(o + 0x96) += 7;
        func_L01_00402498(func_L24_003A69F8, o);
        if ((f32)*(u16 *)(o + 0x96) >= 180.0f) {
            func_L24_003A6A70(o);
            if ((f32)*(u16 *)(o + 0x96) >= 220.0f) {
                func_L01_00441FB8(o, 12, -1);
            }
        }
        break;
    case 10:
        {
            u8 *p = D_001CD0C0 + D_L24_001DE340 * 0x5C0;
            if (*(u32 *)(p + 0x1A4) & 0x20) {
                func_L01_00441FB8(o, 11, -1);
                break;
            }
        }
    case 0:
    case 12:
        if (y == 1) {
            *(u16 *)(o + 0x96) += 5;
            if (*(u16 *)(o + 0x96) >= 360) {
                *(u16 *)(o + 0x96) = 0;
            }
            r = 0;
            if (o[0x43] != 1) {
                func_003BE4F0(o, 1, 0, 6);
            }
            if (o[0x20] == 10) {
                func_L01_00402498(func_L01_004100D8, o);
            } else if (o[0x20] != 12) {
                func_L01_00441FB8(o, 10, -1);
            }
        } else {
            if (o[0x20] != 0) {
                func_L01_00441FB8(o, 0, -1);
                *(u16 *)(o + 0x96) = 0;
            }
            if (x != 0) {
                if (o[0x43] != 5) {
                    func_003BE4F0(o, 5, 0, 6);
                }
                *(f32 *)(o + 0x10) += (f32)x * 0.06666667f;
            } else if (o[0x43] != 0) {
                func_003BE4F0(o, 0, 0, 6);
            }
        }
        {
            u8 *p = D_001CD0C0 + D_L24_001DE340 * 0x5C0;
            btn = *(u32 *)(p + 0x1A4);
        }
        if (btn & 0x40) {
            *(s32 *)(v + 0x930) = x;
            if (o[0x43] != 3) {
                func_003BE4F0(o, 3, 0, 3);
            }
            func_L01_00441FB8(o, 9, 3);
        } else if (btn & 0x80) {
            *(s32 *)(v + 0x930) = x;
            if (o[0x43] != 4) {
                func_003BE4F0(o, 4, 0, 3);
            }
            func_L01_00441FB8(o, 5, 3);
            *(f32 *)(v + 0x98C) = 0.75f;
        } else if (btn & 0x20) {
            *(s32 *)(v + 0x930) = x;
            if (o[0x43] != 7) {
                func_003BE4F0(o, 7, 0, 3);
            }
            func_L01_00441FB8(o, 3, 3);
        } else if (btn & 0x10) {
            *(s32 *)(v + 0x930) = x;
            if (o[0x43] != 8) {
                func_003BE4F0(o, 8, 0, 0);
            }
            func_L01_00441FB8(o, 6, 4);
        }
        break;
    case 6:
        func_003BDA38(o, 0, v + 0x970);
        if (o[0x60] & 2) {
            *(s16 *)(v + 0x94E) = 0;
            *(s32 *)(v + 0x95C) = 1;
            *(s16 *)(v + 0x94C) = 0;
            if (o[0x43] != 9) {
                func_003BE4F0(o, 9, 0, 0);
            }
            func_L01_00441FB8(o, 7, -1);
        }
        break;
    case 7:
        func_L24_003A5980(&x, &y);
        if ((*(s16 *)(v + 0x94E) == 0 && x < 0) || (*(s16 *)(v + 0x94E) == 1 && y < 0) ||
            (*(s16 *)(v + 0x94E) == 2 && x > 0) || (*(s16 *)(v + 0x94E) == 3 && y > 0)) {
            if (++*(s16 *)(v + 0x94E) == 4) {
                *(s16 *)(v + 0x94E) = 0;
            }
            if (*(s16 *)(v + 0x94E) & 1) {
                (*(s32 *)(v + 0x95C))++;
            }
            *(s16 *)(v + 0x94C) = 10;
        }
        func_L01_00402498(func_L24_003A6530, o);
        func_L24_003A63F0(o, v);
        if (o[0x60] & 2) {
            if (o[0x43] != 10) {
                func_003BE4F0(o, 10, 0, 0);
            }
            func_L01_00441FB8(o, 8, -1);
        }
        break;
    case 9:
        if (func_L01_0044AF40(o, 43.0f)) {
            if (*(s32 *)(v + 0x980) < 4) {
                (*(s32 *)(v + 0x980))++;
            }
            *(s32 *)(v + 0x984) = 0;
        }
        if (o[0x60] & 2) {
            if (o[0x43] != 0) {
                func_003BE4F0(o, 0, 0, 10);
            }
            func_L01_00441FB8(o, 0, 1);
        }
        break;
    case 5: {
        f32 d;
        func_L24_003A5980(&x, &y);
        func_L24_003A5AE0(o, v, x, y);
        d = func_L01_00436500(o);
        if (d >= 20.0f && d <= 60.0f) {
            if (*(u16 *)(o + 0x96) == 0) {
                func_L24_003A5B78(o, v);
                *(u16 *)(o + 0x96) = 30;
            }
            (*(u16 *)(o + 0x96))--;
        }
    }
    case 8:
        if (o[0x60] & 2) {
            if (o[0x43] != 0) {
                func_003BE4F0(o, 0, 0, 10);
            }
            func_L01_00441FB8(o, 0, 1);
        }
        break;
    case 3: {
        f32 d = func_L01_00436500(o);
        if (d == 17.0f || d == 40.0f) {
            func_L24_003A5ED0(o, v);
        }
        if (*(s32 *)(v + 0x980) != 0) {
            if (func_L01_0044AF40(o, 17.0f)) {
                func_L24_003A5E18(o, v);
            } else if (func_L01_0044AF40(o, 38.0f)) {
                func_L24_003A5E18(o, v);
            }
        }
        if (o[0x60] & 2) {
            if (o[0x43] != 0) {
                func_003BE4F0(o, 0, 0, 10);
            }
            func_L01_00441FB8(o, 0, 1);
        }
        break;
    }
    }
    func_L24_003A6CF0(o);
    func_L24_003A5C98(o, v, r);
}
/* localdecomp:end func_L24_003A4FD0 */
