#include "common.h"

/* NTSC-U counterpart of func_L07_003AAA50 (src/levels/07_annihilation_nation/L07_003AA9C0.c) */
#include "vu0.h"
void func_L07_003A9210(void *, s32);
void func_L07_003A9210(void *, s32);

/* localdecomp:start func_L07_003A9210 */
typedef struct {
    u8 pad_000[0x170];
    f32 f170;
    f32 f174;
    f32 f178;
    u8 pad_17C[0xC];
    s32 w188;
    u8 pad_18C[0x3A4];
    s16 h530;
    u8 b532;
    u8 b533;
    s32 w534;
    s32 w538;
} Sub_003AAA50;

void func_L07_003A9210(void *arg0, s32 state) {
    extern void func_003BE4F0(void *, s32, s32, s32);
    extern s32 func_0037E1D8(s32);
    extern void func_L01_004A72A8(s32, s32, void *, s32);
    extern void func_L07_003A9758(u8 *);
    extern void func_L01_00441FB8(void *, s32, s32);
    u8 *obj = arg0;
    Sub_003AAA50 *s = *(Sub_003AAA50 **)(obj + 0x68);

    switch (state) {
    case 1:
        break;
    case 2:
        if (obj[0x43] != 0) {
            func_003BE4F0(obj, 0, 0, 0);
        }
        break;
    case 4:
        if (obj[0x43] != 4) {
            func_003BE4F0(obj, 4, 0, 5);
        }
        s->f170 = 6.5f / 60.0f / 60.0f;
        s->f178 = 6.5f * 0.016666668f;
        s->f174 = 6.5f / 60.0f / 60.0f;
        *(u16 *)(obj + 0x34) |= 0x5000;
        break;
    case 6:
        s->w188 &= ~0x10;
        if (obj[0x43] != 3) {
            func_003BE4F0(obj, 3, 0, 5);
        }
        break;
    case 7:
        s->w188 &= ~0x10;
        s->f170 = 6.5f / 60.0f / 60.0f;
        s->f174 = 6.5f / 60.0f / 60.0f;
        s->f178 = 6.5f * 0.016666668f;
        if (obj[0x43] != 4) {
            func_003BE4F0(obj, 4, 0, 5);
        }
        break;
    case 8:
        s->w188 |= 0x10;
        s->f170 = 3.5f / 60.0f / 60.0f;
        s->f174 = 3.5f / 60.0f / 60.0f;
        s->f178 = 3.5f * 0.016666668f;
        if (obj[0x43] != 3) {
            func_003BE4F0(obj, 3, 0, 5);
        }
        break;
    case 9:
        s->b532 = 0;
        s->w538 = 0;
        s->w534 = 0;
        if (func_0037E1D8(2) != 0) {
            s->b533 = 0;
            if (obj[0x43] != 5) {
                func_003BE4F0(obj, 5, 0, 3);
            }
        } else {
            s->b533 = 1;
            if (obj[0x43] != 9) {
                func_003BE4F0(obj, 9, 0, 3);
            }
        }
        break;
    case 10:
        func_L01_004A72A8(2, 0, obj, 0x19BD);
        s->h530 = 0x2D;
        if (s->b533 == 0) {
            if (obj[0x43] != 6) {
                func_003BE4F0(obj, 6, 0, 3);
            }
        } else {
            if (obj[0x43] != 0xA) {
                func_003BE4F0(obj, 0xA, 0, 3);
            }
        }
        break;
    case 11:
        func_L07_003A9758(obj);
        s->h530 = 0x2D;
        if (s->b533 == 0) {
            if (obj[0x43] != 7) {
                func_003BE4F0(obj, 7, 0, 3);
            }
        } else {
            if (obj[0x43] != 0xB) {
                func_003BE4F0(obj, 0xB, 0, 3);
            }
        }
        break;
    case 12:
        s->w188 |= 0x10;
        if (s->b533 == 0) {
            if (obj[0x43] != 8) {
                func_003BE4F0(obj, 8, 0, 3);
            }
        } else {
            if (obj[0x43] != 0xC) {
                func_003BE4F0(obj, 0xC, 0, 3);
            }
        }
        break;
    case 13:
        if (obj[0x43] != 0xE) {
            func_003BE4F0(obj, 0xE, 0, 3);
        }
        break;
    case 14:
        s->w188 |= 0x10;
        s->f170 = 3.5f / 60.0f / 60.0f;
        s->f174 = 3.5f / 60.0f / 60.0f;
        s->f178 = 3.5f * 0.016666668f;
        if (obj[0x43] != 3) {
            func_003BE4F0(obj, 3, 0, 5);
        }
        break;
    }
    func_L01_00441FB8(obj, state, -1);
}
/* localdecomp:end func_L07_003A9210 */
