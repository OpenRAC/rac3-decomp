#include "common.h"

/* NTSC-U counterpart of func_L24_00359650 (src/levels/24_insomniac_museum/L24_00359248.c) */
#include "vu0.h"
extern u8 D_001A4C60[];
extern f32 func_00388800(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);

/* localdecomp:start func_L24_00358600 */
typedef int Q_00359650 __attribute__((mode(TI)));
typedef struct { u8 pad0[0x160]; f32 x160; f32 x164; } S_00359650;
extern f32 D_L24_001DD630_00358600;
extern f32 D_L24_001DD62C_00358600;
extern f32 D_L24_001DD64C_00358600;
extern f32 D_L24_001DD648_00358600;
extern f32 D_L24_001DD5FC_00358600;
extern f32 D_L24_001DD614_00358600;
extern f32 D_L24_001DD678;
extern s32 D_L24_001DD67C;
extern s32 D_L24_001DD680;
extern s32 D_L24_001DD684;
extern s32 D_L24_001DD688;
extern s32 D_L24_001DD68C;
__asm__(".extern D_L24_001DD630_00358600, 4");
__asm__(".extern D_L24_001DD62C_00358600, 4");
__asm__(".extern D_L24_001DD64C_00358600, 4");
__asm__(".extern D_L24_001DD648_00358600, 4");
__asm__(".extern D_L24_001DD5FC_00358600, 4");
__asm__(".extern D_L24_001DD614_00358600, 4");
__asm__(".extern D_L24_001DD678, 4");
__asm__(".extern D_L24_001DD67C, 4");
__asm__(".extern D_L24_001DD680, 4");
__asm__(".extern D_L24_001DD684, 4");
__asm__(".extern D_L24_001DD688, 4");
__asm__(".extern D_L24_001DD68C, 4");
extern u8 D_L24_001D9A60[] __attribute__((section(".sdata")));
extern void func_L24_003597D8(void *, s32);
extern void func_L24_00359A28(void *);
extern void func_L24_00358F08(u8 *);
extern s32 func_L24_00359380(u8 *);
extern s32 func_003883C8(void *);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_L01_00452EF0(void *);
extern s32 func_L01_00451078(void *, void *);
extern void func_L02_003A30F0(s32);
extern void func_L01_003154D8(void *, s32, s32);
extern s32 func_L01_0044AF40(void *, f32);
extern f32 func_L01_00436500(void *);
extern s32 func_L24_003A3290(void *, void *, void *, f32);
extern void func_L24_003A3790(void *, void *);
extern void func_L24_00359AA0(void *, s32);
extern s32 func_L24_00359FA0(void *);
extern s32 func_L24_00359B80(void *, s32, s32);
extern void func_L24_00359840(void *, s32);
extern s32 func_L24_00359490(void *);
extern f32 func_00388730(void *, void *);
extern f32 func_00388990(f32);
extern void func_L24_0035A0C8(void *, f32);
extern void func_00388830(void *, void *, f32);

void func_L24_00358600(u8 *obj)
{
    u8 *v = *(u8 **)(obj + 0x68);
    S_00359650 *sv = (S_00359650 *)v;
    s32 st;
    s32 r;
    f32 d[4] __attribute__((aligned(16)));
    f32 *o;

    func_L24_00358F08(obj);
    st = obj[0x95];
    switch (st) {
    case 1:
        if (v[0x199] != 0 && v[0x198] != 2) {
            v[0x198] = 2;
            r = func_0037E208(0, D_L24_001DD680);
            v[0x199] = 0;
            *(s16 *)(v + 0x194) = r;
        }
        if (func_L24_00359380(obj) != 0 && func_003883C8(v + 0x222) != 0 && v[0x198] != 2) {
            v[0x198] = 2;
            r = func_0037E208(0, D_L24_001DD680);
            *(s16 *)(v + 0x194) = r;
        }
        break;
    case 2:
        if (func_L01_00452EF0(obj) != 0) {
            v[0x198] = 1;
            r = func_0037E208(0, D_L24_001DD680);
            *(s16 *)(v + 0x194) = D_L24_001DD684 + r;
        }
        if (func_L24_00359380(obj) != 0 && func_003883C8(v + 0x226) != 0 && v[0x198] != 3) {
            v[0x198] = 3;
            r = func_0037E208(0, D_L24_001DD680);
            *(s16 *)(v + 0x194) = r;
        }
        break;
    case 3:
        if (func_L24_00359380(obj) == 0 && v[0x198] != 2) {
            func_L24_003597D8(obj, 0);
            v[0x198] = 2;
            r = func_0037E208(0, D_L24_001DD680);
            *(s16 *)(v + 0x194) = r;
        }
        break;
    case 4:
        if (func_L01_00452EF0(obj) != 0) {
            v[0x198] = st;
        }
        r = func_L01_00451078(obj, v + 0x70);
        if (r & 1) {
            func_L02_003A30F0((s32)obj);
            func_L01_003154D8(obj, 0, 0);
            return;
        }
        if (r & 2) {
            if (*(s16 *)(v + 0x144) == 1 && func_L24_00359380(obj) != 0) {
                v[0x198] = 3;
            } else {
                v[0x198] = 2;
            }
            r = func_0037E208(0, D_L24_001DD67C);
            *(s16 *)(v + 0x194) = r;
        }
        break;
    }
    func_L24_00359A28(obj);
    switch (obj[0x20]) {
    case 1:
        if (func_L01_0044AF40(obj, 29.0f) != 0) {
            func_L24_00359AA0(obj, 1);
            return;
        }
        break;
    case 2:
        if (func_L01_0044AF40(obj, 89.0f) != 0) {
            func_L24_00359AA0(obj, 1);
            return;
        }
        break;
    case 3:
        if ((func_L24_003A3290(v + 0x1C0, obj, v + 0x160, -9999999827968.0f) & 0xA) != 0) {
            *(Q_00359650 *)(v + 0x160) = *(Q_00359650 *)(v + 0x150);
            sv->x160 += func_0037E250(-D_L24_001DD630_00358600, D_L24_001DD630_00358600);
            sv->x164 += func_0037E250(-D_L24_001DD630_00358600, D_L24_001DD630_00358600);
        }
        if (func_00388800(obj + 0x10, v + 0x160) < D_L24_001DD62C_00358600) {
            func_L24_00359AA0(obj, 1);
            return;
        }
        break;
    case 4:
        if ((func_L24_003A3290(v + 0x1C0, obj, v + 0x160, -9999999827968.0f) & 0xA) != 0) {
            *(Q_00359650 *)(v + 0x160) = *(Q_00359650 *)(v + 0x150);
            sv->x160 += func_0037E250(-D_L24_001DD64C_00358600, D_L24_001DD64C_00358600);
            sv->x164 += func_0037E250(-D_L24_001DD64C_00358600, D_L24_001DD64C_00358600);
        }
        if (func_00388800(obj + 0x10, v + 0x160) < D_L24_001DD648_00358600) {
            func_L24_00359AA0(obj, 1);
            return;
        }
        break;
    case 5:
        if (func_L01_0044AF40(obj, 89.0f) != 0) {
            func_L24_00359AA0(obj, 2);
            return;
        }
        break;
    case 6:
        if (func_L01_0044AF40(obj, 23.0f) != 0) {
            func_L24_003A3790(v + 0x1C0, obj);
            if (func_003883C8(v + 0x196) == 0) {
                return;
            }
            if (func_0037E1D8(2) != 0) {
                if (func_L24_00359FA0(obj) == 0) {
                    func_L24_00359B80(obj, 4, 2);
                    return;
                }
                r = func_0037E208(0, D_L24_001DD680);
                *(s16 *)(v + 0x196) = D_L24_001DD688 + r;
                break;
            }
            func_L24_00359AA0(obj, 2);
            return;
        }
        func_L24_00359840(obj, (s32)(v + 0x160));
        return;
    case 7:
        if (func_L01_00436500(obj) < 8.0f || 23.0f <= func_L01_00436500(obj)) {
            *(Q_00359650 *)(v + 0x160) = *(Q_00359650 *)(v + 0x130);
            if (func_00388800(D_001A4C60, obj + 0x10) < D_L24_001DD5FC_00358600) {
                func_L24_00359B80(obj, 8, 3);
            }
        }
        func_L24_00359840(obj, (s32)(v + 0x160));
        return;
    case 8:
        if (func_L01_0044AF40(obj, 25.0f) != 0) {
            vec_sub_ba(d, D_001A4C60, obj + 0x10);
            d[2] = 0.0f;
            func_00388830(d, d, D_L24_001DD614_00358600);
            o = (f32 *)(v + 0x1B0);
            o[0] = d[0];
            o[1] = d[1];
            o[2] = d[2];
            vec_add_ab(v + 0x160, obj + 0x10, d);
            *(s16 *)(v + 0x196) = D_L24_001DD68C;
            func_L24_00359B80(obj, 9, 3);
        }
        func_L24_003A3290(v + 0x1C0, obj, v + 0x130, -9999999827968.0f);
        return;
    case 9:
        if (func_003883C8(v + 0x196) == 0) {
            f32 q;
            f32 lim;
            if (func_L24_00359490(obj) != 0) {
                return;
            }
            q = func_00388990(func_00388730(obj + 0xE0, D_L24_001D9A60));
            lim = 1.0f / D_L24_001DD678;
            if (1.5707964f - q < lim) {
                func_L24_0035A0C8(obj, 1.5707964f - q);
                func_L24_00359B80(obj, 0xB, 3);
                return;
            }
            func_L24_0035A0C8(obj, 1.5707964f - q);
            func_L24_00359B80(obj, 0xB, 3);
            qzero(v + 0x1C0);
            return;
        }
        func_L24_0035A0C8(obj, 1.5707964f - func_00388990(func_00388730(obj + 0xE0, D_L24_001D9A60)));
        func_L24_00359B80(obj, 0xB, 3);
        func_L24_003A3790(v + 0x1C0, obj);
        return;
    case 10:
    case 11: {
        s32 f = 0;
        if (*(s16 *)(v + 0x196) != 0) {
            f = 1;
            if (obj[0x42] == obj[0x43]) {
                if (6.5f < func_L01_00436500(obj)) {
                    func_L24_00359490(obj);
                    if (func_003883C8(v + 0x196) != 0) {
                        *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) & 0xFEFF;
                    }
                }
            }
        }
        if (func_L01_0044AF40(obj, 29.0f) != 0) {
            func_L24_00359B80(obj, 7, 3);
        }
        if (f != 0) {
            return;
        }
        func_L24_003A3290(v + 0x1C0, obj, v + 0x130, -9999999827968.0f);
        return;
    }
    case 12:
        if (obj[0x60] & 2) {
            *(f32 *)(obj + 0x48) = 1.0f;
            if (obj[0x43] != 5) {
                func_003BE4F0(obj, 5, 0, 3);
            }
            func_L01_00441FB8(obj, 0xD, -1);
        }
        break;
    case 13:
    case 14:
        break;
    }
}
/* localdecomp:end func_L24_00358600 */
