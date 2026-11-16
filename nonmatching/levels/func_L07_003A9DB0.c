/* NTSC-U draft (Claude wave C4): C of func_L07_003A8570, the NTSC-U twin of func_L07_003A9DB0, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L07_003A8570", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (0 diff) only with @ps2as added (inline lui/ori/mtc1 for 0.1f and 0.16f; its PAL file has none; no div row needed). Enemy/boss AI state machine: switch (obj[0x20]) with 14 jump-table entries (case 1 empty so the table starts at 1), each ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L07_003A9DB0 (src/levels/07_annihilation_nation/L07_003A9D80.c) */
/* localdecomp:start func_L07_003A8570 */
extern u8 D_L07_003AA0C0[];
extern void func_L07_003A89E8(void);
extern void func_L07_003A8C18(void *);
extern s32 func_L01_004576E8(void *);
extern s32 func_003883C8(void *);
extern void func_L07_003A9210(void *, s32);
extern void func_L01_00457440(void *, void *);
extern f32 func_L01_0040C040(void *, void *);
extern s32 func_L01_00451078(void *, void *);
extern s32 func_L07_003308C8(void *, void *);
extern void func_L07_003A9570(void *, f32);
extern f32 func_00388800(void *, void *);
extern s32 func_L07_00333CC8(void *);
extern s32 func_L07_00333F98(void *);
extern void func_L03_0032D348(void *);
extern void func_L07_003A9758(void *);
extern void func_L07_003A99C0(void *);
extern void func_L07_003A9C78(void *);
extern void func_L07_003A9A70(void *);
extern void func_L07_003A9E38(void *);
extern void func_L01_00402498(void *, void *);

void func_L07_003A8570(u8 *obj) {
    u8 *s;
    f32 d;

    if (obj[0x20] == 0) {
        func_L07_003A89E8();
    }
    func_L07_003A8C18(obj);
    s = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 1:
        break;
    case 2:
        func_L01_004576E8(obj);
        if (func_003883C8(s + 0x24E) != 0) {
            func_L07_003A9210(obj, 3);
        }
        break;
    case 3:
        func_L01_004576E8(obj);
        func_L07_003A9210(obj, 4);
        break;
    case 4:
        func_L01_00457440(obj, *(u8 **)(s + 0x240) + 0x10);
        if (func_L01_0040C040(*(u8 **)(s + 0x240) + 0x10, obj + 0x10) < 484.0f) {
            s[0x25E] = 1;
            func_L07_003A9210(obj, 6);
        }
        break;
    case 5:
        func_L01_004576E8(obj);
        if (func_L01_00451078(obj, s + 0x70) & 2) {
            if (s[0x25E] != 0) {
                func_L07_003A9210(obj, 6);
            } else {
                func_L07_003A9210(obj, 4);
            }
        }
        break;
    case 6:
        func_L01_004576E8(obj);
        if (func_L07_003308C8(*(u8 **)(s + 0x240), obj) != 0) {
            if (func_L01_0040C040(obj + 0x10, s + 0x130) < 196.0f) {
                func_L07_003A9210(obj, 8);
            } else {
                func_L07_003A9210(obj, 7);
            }
        } else {
            func_L07_003A9210(obj, 0xE);
        }
        break;
    case 7:
        func_L07_003A9570(obj, 5.0f);
        if (func_L07_003308C8(*(u8 **)(s + 0x240), obj) != 0) {
            if (func_L01_0040C040(obj + 0x10, s + 0x130) < 100.0f) {
                func_L07_003A9210(obj, 8);
            }
        } else {
            func_L07_003A9210(obj, 6);
        }
        break;
    case 8:
        func_L07_003A9570(obj, 8.0f);
        if (func_L07_003308C8(*(u8 **)(s + 0x240), obj) != 0) {
            d = func_00388800(obj + 0x10, s + 0x130);
            if (14.0f < d) {
                func_L07_003A9210(obj, 7);
            } else if (func_003883C8(s + 0x530) != 0) {
                if (d < 10.0f) {
                    *(s16 *)(s + 0x24C) = func_L07_00333CC8(obj);
                    if (func_L07_00333F98(obj) != 0) {
                        func_L07_003A9210(obj, 9);
                    }
                }
            }
        } else {
            func_L03_0032D348(obj);
            func_L07_003A9210(obj, 6);
        }
        break;
    case 9:
        func_L01_004576E8(obj);
        if (obj[0x60] & 2) {
            func_L07_003A9210(obj, 0xA);
        }
        break;
    case 10:
        func_L01_004576E8(obj);
        func_L07_003A9758(obj);
        func_L07_003A99C0(obj);
        func_L07_003A9C78(obj);
        if (func_003883C8(s + 0x530) != 0) {
            func_L07_003A9210(obj, 0xB);
        }
        break;
    case 11:
        func_L01_004576E8(obj);
        func_L07_003A99C0(obj);
        *(f32 *)(s + 0x538) += 0.1f;
        if (*(f32 *)(s + 0x538) > 1.0f) {
            *(f32 *)(s + 0x538) = 1.0f;
        }
        *(f32 *)(s + 0x534) += 0.16f;
        if (*(f32 *)(s + 0x534) > 1.0f) {
            *(f32 *)(s + 0x534) -= 1.0f;
        }
        func_L07_003A9A70(obj);
        func_L07_003A9E38(obj);
        func_L01_00402498(D_L07_003AA0C0, obj);
        if (func_003883C8(s + 0x530) != 0) {
            func_L07_003A9210(obj, 0xC);
        }
        break;
    case 12:
        func_L07_003A9570(obj, 8.0f);
        if (obj[0x60] & 2) {
            func_L03_0032D348(obj);
            if (s[0x532] != 0) {
                func_L07_003A9210(obj, 0xD);
            } else {
                *(s16 *)(s + 0x530) = 0x3C;
                func_L07_003A9210(obj, 6);
            }
        }
        break;
    case 13:
        func_L07_003A9570(obj, 8.0f);
        if (obj[0x60] & 2) {
            func_L07_003A9210(obj, 6);
        }
        break;
    case 14:
        func_L07_003A9570(obj, 12.0f);
        if (func_L07_003308C8(*(u8 **)(s + 0x240), obj) != 0) {
            func_L07_003A9210(obj, 6);
        }
        break;
    }
}
/* localdecomp:end func_L07_003A8570 */
