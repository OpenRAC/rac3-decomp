#include "common.h"

/* NTSC-U counterpart of func_L35_003A45A0 (src/levels/35_vidcomic_5/L35_003A29A8.c) */
/* localdecomp:start func_L35_003A2CA0 */
#include "vu0.h"
extern f32 D_L35_001DEA28;
__asm__(".extern D_L35_001DEA28, 4");
extern f32 D_L35_001DEA2C;
__asm__(".extern D_L35_001DEA2C, 4");
extern s32 D_L35_001DEA30_003A2CA0;
__asm__(".extern D_L35_001DEA30_003A2CA0, 4");
extern s32 D_L35_001DEA34_003A2CA0;
__asm__(".extern D_L35_001DEA34_003A2CA0, 4");
extern f32 D_L35_001DEA48;
__asm__(".extern D_L35_001DEA48, 4");
extern f32 D_L35_001DEA4C;
__asm__(".extern D_L35_001DEA4C, 4");
extern f32 D_L35_001DEA50;
__asm__(".extern D_L35_001DEA50, 4");
extern f32 D_L35_001DEA80;
__asm__(".extern D_L35_001DEA80, 4");
extern f32 D_L35_001DEA8C;
__asm__(".extern D_L35_001DEA8C, 4");
extern f32 D_L35_001DEA98;
__asm__(".extern D_L35_001DEA98, 4");
extern u8 D_001A4C60[];
extern s32 D_L35_001E1E00;
__asm__(".extern D_L35_001E1E00, 16");

extern void func_L35_003A28B8(u8 *, s32);
extern s32 func_L01_00452EC8(u8 *);
extern f32 func_L01_00436500(u8 *);
extern s32 func_00388398(void *);
extern f32 func_003893C8(f32, f32);
extern void func_003BDA38(u8 *, s32, void *);
extern void func_0039FE80(s32, s32, u8 *);
extern s32 func_L35_003A3E68(f32 *, f32);
extern void func_L35_003A2460(u8 *);
extern s32 func_L31_00345C88(u8 *, f32, f32, f32);
extern s32 func_L01_00453210(void *, s32);
extern s32 func_L01_0044AF40(u8 *, f32);
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern void func_L30_0034C308(u8 *, u8 *, u8 *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
typedef struct { u8 pad[0x1C]; s32 mode; } Row;
typedef struct { u8 pad[0x100]; Row rows[4]; } State;

void func_L35_003A2CA0(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *row;
    s32 closer = 1;
    f32 a, b;
    f32 vec[4];

    a = fabs_asm(func_003893C8(D_L35_001DEA28, *(f32 *)(obj + 0xF8)));
    b = fabs_asm(func_003893C8(D_L35_001DEA2C, *(f32 *)(obj + 0xF8)));
    closer = a < b;
    if (func_L01_00452EC8(obj)) {
        *(s32 *)(s + 0xF8) = 0;
    }
    if (*(s32 *)(s + 0x180) < 0 || *(s32 *)(s + 0x180) >= *(s32 *)(s + 0x188)) {
        func_L35_003A28B8(obj, 5);
        return;
    }
    row = s + 0x100 + *(s32 *)(s + 0x180) * 32;
    if (func_00388398(s + 0x198) && !func_00388398(s + 0x19C)) {
        if (func_00388398(s + 0xF8)) {
            f32 d = func_L01_00436500(obj);
            *(s32 *)(s + 0xF8) = *(s32 *)(row + 0x10);
            if ((*(long *)(obj + 0x40) & 0xFFFF0000) == 0x4040000 && d < D_L35_001DEA50) {
                func_003BDA38(obj, 0, vec);
                vec[1] = *(f32 *)(D_001A4C60 + 4);
                func_0039FE80(0, 0, obj);
                func_L35_003A3E68(vec, closer ? 3.14159274f : 0.0f);
            }
            func_003BE4F0(obj, 4, 0, D_L35_001DEA34_003A2CA0);
            *(f32 *)(obj + 0x48) = D_L35_001DEA4C;
        }
        if ((*(long *)(obj + 0x40) & 0xFFFF0000) == 0x4040000) {
            if (func_L01_0044AF40(obj, D_L35_001DEA50)) {
                func_003BDA38(obj, 0, vec);
                vec[1] = *(f32 *)(D_001A4C60 + 4);
                func_0039FE80(0, 0, obj);
                func_L35_003A3E68(vec, closer ? 3.14159274f : 0.0f);
            }
        }
    } else if (*(long *)(s + 0x198) == 0) {
        *(s32 *)(s + 0x198) = *(s32 *)(row + 0x14);
        func_L35_003A2460(obj);
        if (!func_L31_00345C88(obj, D_L35_001DEA28, D_L35_001DEA2C, D_L35_001DEA48)) {
            func_L35_003A28B8(obj, 8);
        } else if (*(s32 *)(s + 0x18C) != -1 && !func_L01_00453210(D_001A4C60, *(s32 *)(s + 0x18C))) {
            func_L35_003A28B8(obj, 2);
        } else if (((State *)s)->rows[*(s32 *)(s + 0x180)].mode == 2) {
            func_L35_003A28B8(obj, 7);
        } else {
            func_L35_003A28B8(obj, 6);
        }
    }
    if (obj[0x60] & 2) {
        if (obj[0x43] != 0) {
            func_003BE4F0(obj, 0, 0, D_L35_001DEA30_003A2CA0);
        }
        *(f32 *)(obj + 0x48) = D_L35_001DEA4C;
    }
    func_L30_0034C308(obj, obj + 0x10, s + 0xE0, &D_L35_001E1E00, D_L35_001DEA80, D_L35_001DEA80, D_L35_001DEA8C, 0.0f, 0.0f,
                      D_L35_001DEA98, 1, 1, 1, 0);
}
/* localdecomp:end func_L35_003A2CA0 */
