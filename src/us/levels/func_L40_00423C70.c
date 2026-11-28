#include "common.h"
/* localdecomp:start func_L40_00423C70 */
#include "vu0.h"

extern s32 D_L40_002412AC;
extern s32 D_L40_002499C8;
extern s32 D_L40_002499CC;
extern s32 D_L40_00248500_00423C70;
extern s32 D_L40_00247890;
__asm__(".extern D_L40_00247890, 4");
extern s32 D_L40_00247894;
__asm__(".extern D_L40_00247894, 4");

struct L40_00424540_obj {
    u8 pad[0xAA];
    s16 type;
};

void func_L40_00423C70(u8 *obj, s32 unused, u8 *src) {
    extern s32 func_L39_005F0CE0(s32, s32, void *);
    extern u8 *func_L01_00461E08(void *, s32, s32, f32, f32, f32, f32, f32);
    extern f32 func_L01_00445110(s32 *, s32, s32);
    extern void func_L01_0044ED60(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
    extern void func_L01_00441FB8(void *, s32, s32);
    vu0_v4 pos;
    vu0_v4 dir;
    vu0_v4 zero;
    s32 i;
    s32 c;
    s32 mask;
    s32 d;
    s32 r;

    if (abs_asm(D_L40_002412AC - D_L40_002499C8) >= 2) {
        r = func_L39_005F0CE0(0, 0, obj);
        *(vu0_q *)&dir = 0;
        dir.z = 0.5f;
        func_L39_005F1018(r, &dir);
        D_L40_002499C8 = D_L40_002412AC;
    }
    if (abs_asm(D_L40_002412AC - D_L40_002499CC) >= 2) {
        D_L40_002499CC = D_L40_002412AC;
    }
    *(vu0_q *)&pos = *(vu0_q *)(obj + 0x10);
    pos.z = pos.z + 0.3f;
    func_L01_00461E08(&pos, 1, 0x40808080, 0.3f, 1.01f, 1.075f, 0.05f, 50000.0f);
    for (i = 0; i < 5; i++) {
        func_L01_00461E08(&pos, 1, 0x40808080, 0.3f, 1.01f, 1.07f, 0.05f, 50000.0f);
    }
    if (src != 0) {
        *(vu0_q *)&dir = *(vu0_q *)(src + 0x10);
    } else {
        qzero(&dir);
        dir.z = 1.0f;
    }
    d = abs_asm(D_L40_002412AC - D_L40_00247890);
    if (d >= 0xF1) {
        D_L40_00247890 = D_L40_002412AC;
        D_L40_00247894 = 0;
    } else if (D_L40_002412AC != D_L40_00247890) {
        func_L01_00445110(&D_L40_00247894, 0, d >> 2);
        D_L40_00247890 = D_L40_002412AC;
    }
    if (D_L40_00248500_00423C70 >= 0xFB && D_L40_00247894 < 5) {
        c = 4;
    } else if (D_L40_00248500_00423C70 >= 0xC9 && D_L40_00247894 < 10) {
        c = 3;
    } else if (D_L40_00248500_00423C70 >= 0x97 && D_L40_00247894 < 15) {
        c = 2;
    } else {
        c = 0;
        if (D_L40_00248500_00423C70 >= 0x65) {
            c = D_L40_00247894 < 20;
        }
    }
    if (c != 0) {
        mask = 0;
        D_L40_00247894 = D_L40_00247894 + c;
        switch (((struct L40_00424540_obj *)obj)->type) {
        case 0x1FF:
        case 0x1ABA:
        case 0x1ABB:
        case 0x1ABC:
        case 0x1ABD:
        case 0x1ABE:
        case 0x1ABF:
        case 0x1AC0:
        case 0x1AC1:
        case 0x1AF2:
        case 0x1B09:
        case 0x1B0A:
        case 0x1B0B:
        case 0x1B4B:
            switch (c) {
            case 1:
                mask = 1;
                break;
            case 2:
                mask = 5;
                break;
            case 3:
            default:
                mask = 0x25;
                break;
            }
            break;
        case 0x1F5:
        case 0x200:
            mask = (1 << (c - 1)) - 1;
            if (!(mask < 0x10)) {
                mask = 0xF;
            }
            break;
        }
        if (mask != 0) {
            qzero(&zero);
            func_L01_0044ED60(obj, mask, (u8 *)&zero, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        }
    }
    *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 1;
    func_L01_00441FB8(obj, 3, -1);
    *(s32 *)(obj + 0x98) = 0;
    obj[0xBC] = 0xF;
}
/* localdecomp:end func_L40_00423C70 */
