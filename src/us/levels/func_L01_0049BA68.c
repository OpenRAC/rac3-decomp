#include "common.h"

/* NTSC-U counterpart of func_L01_0049F2C8 (src/levels/shared/L01_0049E9F0.c): 8 -> 10 */
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} S_2ED730_0049F2C8;
extern void func_L01_0049BA68(void);

/* localdecomp:start func_L01_0049BA68 */
extern u8 D_00143950[];
extern s32 D_L01_001E0D50[2];
__asm__(".extern D_L01_001E0D50_0049BA68, 4");
extern s32 D_L01_001E0D50_0049BA68;
extern s32 D_L01_001E0D40[2];
extern S_2ED730_0049F2C8 D_L01_002ED780_0049BA68[];
extern u8 D_L01_002ECD00[];
extern void func_L01_0049CF28(void);
extern void func_L01_0049CAA0(void);
extern void func_L01_0049CA58(void);
extern void func_L01_0049C590(void);
extern void func_L01_0049CC58(void);
extern void func_L01_0049D220(void);
extern s32 func_0037DF98(s32);
extern void func_003B3DB8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_L01_0049C088(void *);
extern s32 func_003E2DE0(s32, s32);
extern s32 func_L01_00512650(s32, f32, f32);
extern s32 func_003E29B8(s32, s32);
extern s32 func_003AED40(s32);
extern s32 func_003E31A8(s32, s32);
extern void func_L01_00512D70(s32, s32);
extern void func_L01_005131A0(s32, s32);
extern s32 func_003E3250(s32, s32, s32);
extern void func_L01_00514D50_0049BA68(s32);
extern s32 func_003E3D08(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E3BD0(s32, s32, f32, f32, f32, f32, s32);
extern void func_L01_00512BA0(s32, s32, s32);
extern s32 func_L01_00514120(s32, s32, s32, s32);
extern s32 func_003E30C8(s32, s32);
extern s32 func_L01_005130C8(s32, s32);
__asm__(".extern D_L01_001D95A8_0049BA68, 4");
extern f32 D_L01_001D95A8_0049BA68;
__asm__(".extern D_L01_001D95AC_0049BA68, 4");
extern f32 D_L01_001D95AC_0049BA68;
__asm__(".extern D_L01_001D95B0_0049BA68, 4");
extern f32 D_L01_001D95B0_0049BA68;
__asm__(".extern D_L01_001D95B4_0049BA68, 4");
extern f32 D_L01_001D95B4_0049BA68;
__asm__(".extern D_L01_001D95B8_0049BA68, 4");
extern f32 D_L01_001D95B8_0049BA68;
__asm__(".extern D_L01_001D95BC, 4");
extern f32 D_L01_001D95BC;

void func_L01_0049BA68(void) {
    s32 i = 0;
    f32 k1 = 0.0035000001f;
    f32 k2 = 0.006f;
    s32 n3 = 3;
    u8 t = D_00143950[0xA4];
    if (t == 2) {
        D_L01_001E0D50[0] = t;
    } else if (t == 1) {
        D_L01_001E0D50[0] = t;
    } else {
        D_L01_001E0D50_0049BA68 = 0;
    }
    D_L01_001E0D40[i] = D_L01_001E0D50[i];
    func_L01_0049CF28();
    func_L01_0049CAA0();
    func_L01_0049CA58();
    func_003B3DB8(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008, func_0037DF98(0x112), 0xD0006, 0xFF, 0xD0007, 0xCD5, 0.0f);
    func_L01_0049C088(D_L01_002ECD00);
    func_003E2DE0(0x11, 0x540000);
    func_L01_00512650(0x540002, 0.0035000001f, 0.006f);
    func_003E29B8(0x54000A, 1);
    func_003E29B8(0x54000E, 1);
    func_003E29B8(0x540012, 1);
    func_003E29B8(0x540016, 1);
    func_003E29B8(0x54001A, 1);
    func_003E29B8(0x54001E, 1);
    func_003E29B8(0x540022, 1);
    func_003E29B8(0x540026, 1);
    func_003E29B8(0x54002A, 1);
    func_003E29B8(0x54002E, 1);
    func_003E29B8(0x540032, 1);
    func_003E29B8(0x540036, 1);
    func_003E31A8(0x540003, func_003AED40(0));
    func_L01_00512D70(0x540003, 0);
    func_L01_005131A0(0x540003, 0);
    func_003E3250(0x540003, 1, 10);
    func_L01_0049C590();
    func_L01_00514D50_0049BA68(0x54003A);
    func_003E3D08(0x54003D, 0x706EC8FF, D_L01_001D95B0_0049BA68 + D_L01_001D95B8_0049BA68, D_L01_001D95A8_0049BA68 + D_L01_001D95AC_0049BA68 * n3, 0.01953f, 0.040868f, 0.0035000001f, 0.006f);
    func_003E3D08(0x54003C, 0x332299DE, ((D_L01_001D95B0_0049BA68 + D_L01_001D95B8_0049BA68) + D_L01_001D95B4_0049BA68) * 0.5f, D_L01_001D95A8_0049BA68 + D_L01_001D95AC_0049BA68 * n3, D_L01_001D95B4_0049BA68 - (D_L01_001D95B0_0049BA68 + D_L01_001D95B8_0049BA68), D_L01_001D95BC, 0.0035000001f, 0.006f);
    func_003E3BD0(0x54003B, 0x332299DE, (D_L01_001D95B0_0049BA68 + D_L01_001D95B8_0049BA68) + k1, D_L01_001D95A8_0049BA68 + D_L01_001D95AC_0049BA68 * n3, (D_L01_001D95B4_0049BA68 - (D_L01_001D95B0_0049BA68 + D_L01_001D95B8_0049BA68)) - (k1 + k1), D_L01_001D95BC - (k2 + k2), 0);
    func_L01_00512BA0(0x54003B, 1, 3);
    func_L01_00514120(0x54003A, 0x54003B, 0x54003C, 0x54003D);
    func_003E30C8(0x540000, 0x54003A);
    func_L01_005130C8(0x54003C, 0x331465B7);
    func_L01_005130C8(0x54003B, 0x60000000);
    t = D_00143950[0xA4];
    switch (t) {
    case 0:
        D_L01_001E0D50[i] = 0;
        D_L01_002ED780_0049BA68[i].a = 0;
        break;
    case 1:
        D_L01_001E0D50[i] = 1;
        D_L01_002ED780_0049BA68[i].a = 2;
        break;
    case 2:
        D_L01_001E0D50[i] = 2;
        D_L01_002ED780_0049BA68[i].a = 1;
        break;
    }
    func_L01_0049CC58();
    func_L01_0049D220();
}
/* localdecomp:end func_L01_0049BA68 */
