#include "common.h"

/* NTSC-U counterpart of func_L07_003A9DB0. */
/* localdecomp:start func_U_L07_003A8570 */
extern void func_U_003A89E8(u8 *);
extern void func_U_003A8C18(u8 *);
extern s32 func_U_00456650(void *);
extern s32 func_U_0040C3D0(void *);
extern void func_U_003A9210(void *, s32);
extern void func_U_004563A8(void *, void *);
extern f32 func_U_0040C950(void *, void *);
extern s32 func_U_00451638(void *, void *);
extern s32 func_U_003308C8(void *, void *);
extern void func_U_003A9570(void *, f32);
extern f32 func_U_0040C8F8(void *, void *);
extern s16 func_U_00333CC8(void *);
extern s32 func_U_00333F98(void *);
extern void func_U_00333E48(void *);
extern void func_U_003A9758(void *);
extern void func_U_003A99C0(void *);
extern void func_U_003A9C78(void *);
extern void func_U_003A9A70(void *);
extern void func_U_003A9E38(void *);
extern void func_U_003AA0C0(void);
extern void func_U_004039F8(void *, void *);

void func_U_L07_003A8570(u8 *obj) {
    u8 *s;
    f32 d;

    if (obj[0x20] == 0) {
        func_U_003A89E8(obj);
    }
    func_U_003A8C18(obj);
    s = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 1:
        break;
    case 2:
        func_U_00456650(obj);
        if (func_U_0040C3D0(s + 0x24E) != 0) {
            func_U_003A9210(obj, 3);
        }
        break;
    case 3:
        func_U_00456650(obj);
        func_U_003A9210(obj, 4);
        break;
    case 4:
        func_U_004563A8(obj, *(u8 **)(s + 0x240) + 0x10);
        if (func_U_0040C950(*(u8 **)(s + 0x240) + 0x10, obj + 0x10) < 484.0f) {
            s[0x25E] = 1;
            func_U_003A9210(obj, 6);
        }
        break;
    case 5:
        func_U_00456650(obj);
        if (func_U_00451638(obj, s + 0x70) & 2) {
            if (s[0x25E] != 0) {
                func_U_003A9210(obj, 6);
            } else {
                func_U_003A9210(obj, 4);
            }
        }
        break;
    case 6:
        func_U_00456650(obj);
        if (func_U_003308C8(*(u8 **)(s + 0x240), obj) != 0) {
            if (func_U_0040C950(obj + 0x10, s + 0x130) < 196.0f) {
                func_U_003A9210(obj, 8);
            } else {
                func_U_003A9210(obj, 7);
            }
        } else {
            func_U_003A9210(obj, 0xE);
        }
        break;
    case 7:
        func_U_003A9570(obj, 5.0f);
        if (func_U_003308C8(*(u8 **)(s + 0x240), obj) != 0) {
            if (func_U_0040C950(obj + 0x10, s + 0x130) < 100.0f) {
                func_U_003A9210(obj, 8);
            }
        } else {
            func_U_003A9210(obj, 6);
        }
        break;
    case 8:
        func_U_003A9570(obj, 8.0f);
        if (func_U_003308C8(*(u8 **)(s + 0x240), obj) != 0) {
            d = func_U_0040C8F8(obj + 0x10, s + 0x130);
            if (14.0f < d) {
                func_U_003A9210(obj, 7);
            } else if (func_U_0040C3D0(s + 0x530) != 0) {
                if (d < 10.0f) {
                    *(s16 *)(s + 0x24C) = func_U_00333CC8(obj);
                    if (func_U_00333F98(obj) != 0) {
                        func_U_003A9210(obj, 9);
                    }
                }
            }
        } else {
            func_U_00333E48(obj);
            func_U_003A9210(obj, 6);
        }
        break;
    case 9:
        func_U_00456650(obj);
        if (obj[0x60] & 2) {
            func_U_003A9210(obj, 0xA);
        }
        break;
    case 10:
        func_U_00456650(obj);
        func_U_003A9758(obj);
        func_U_003A99C0(obj);
        func_U_003A9C78(obj);
        if (func_U_0040C3D0(s + 0x530) != 0) {
            func_U_003A9210(obj, 0xB);
        }
        break;
    case 11:
        func_U_00456650(obj);
        func_U_003A99C0(obj);
        *(f32 *)(s + 0x538) += 0.1f;
        if (*(f32 *)(s + 0x538) > 1.0f) {
            *(f32 *)(s + 0x538) = 1.0f;
        }
        *(f32 *)(s + 0x534) += 0.16f;
        if (*(f32 *)(s + 0x534) > 1.0f) {
            *(f32 *)(s + 0x534) -= 1.0f;
        }
        func_U_003A9A70(obj);
        func_U_003A9E38(obj);
        func_U_004039F8((void *)func_U_003AA0C0, obj);
        if (func_U_0040C3D0(s + 0x530) != 0) {
            func_U_003A9210(obj, 0xC);
        }
        break;
    case 12:
        func_U_003A9570(obj, 8.0f);
        if (obj[0x60] & 2) {
            func_U_00333E48(obj);
            if (s[0x532] != 0) {
                func_U_003A9210(obj, 0xD);
            } else {
                *(s16 *)(s + 0x530) = 60;
                func_U_003A9210(obj, 6);
            }
        }
        break;
    case 13:
        func_U_003A9570(obj, 8.0f);
        if (obj[0x60] & 2) {
            func_U_003A9210(obj, 6);
        }
        break;
    case 14:
        func_U_003A9570(obj, 12.0f);
        if (func_U_003308C8(*(u8 **)(s + 0x240), obj) != 0) {
            func_U_003A9210(obj, 6);
        }
        break;
    }
}
/* localdecomp:end func_U_L07_003A8570 */
