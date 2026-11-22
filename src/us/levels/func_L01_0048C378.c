#include "common.h"

/* NTSC-U counterpart of func_L01_0048FBF0 (src/levels/shared/L01_0048FBF0.c): 8 -> 10 */
extern void func_L01_005131A0(s32 id, s32 v);
extern void func_L01_00512D70(s32 id, s32 v);
extern s32 func_L01_005130C8(s32, s32);
extern s32 func_L01_00513548(s32, f32, f32);

/* localdecomp:start func_L01_0048C378 */
__asm__(".extern D_L01_001D8D98, 4");
__asm__(".extern D_L01_001D8DAC, 4");
__asm__(".extern D_L01_001D8DB4, 4");
__asm__(".extern D_L01_001D8DB8, 4");
__asm__(".extern D_L01_001D8DBC, 4");
__asm__(".extern D_L01_001D8DC0, 4");
__asm__(".extern D_L01_001D8DC4, 4");
extern s32 D_L01_001D8D98;
extern f32 D_L01_001D8DAC;
extern f32 D_L01_001D8DB4;
extern f32 D_L01_001D8DB8;
extern f32 D_L01_001D8DBC;
extern f32 D_L01_001D8DC0;
extern f32 D_L01_001D8DC4;
extern u8 D_L01_002EB0E8[];
extern void func_L01_0048D030(void);
extern s32 func_L01_0048CB78(void *);
extern void func_L01_004962E0(s32, s32, s32);
extern s32 func_0037DF98(s32);
extern s32 func_003B3DB8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 func_L01_00513548(s32, f32, f32);
extern s32 func_003E2DE0(s32, s32);
extern s32 func_L01_0048CE58(void);
extern void func_L01_00514D50_0048C378(s32);
extern s32 func_003E3D08(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E3BD0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00512BA0(s32, s32, s32);
extern s32 func_L01_005130C8(s32, s32);
extern s32 func_003E3630(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E34A0(s32, s32, s32);
extern void func_L01_0048D720(void);
extern s32 func_003AED40(s32);
extern s32 func_003E31A8(s32, s32);
extern s32 func_003E3250(s32, s32, s32);

void func_L01_0048C378(void) {
    f32 scale;
    f32 val;

    scale = 1.0f;
    val = 0.0f;
    D_L01_001D8D98 = -1;
    func_L01_0048D030();
    func_L01_0048CB78(D_L01_002EB0E8);
    func_L01_004962E0(0xCBD, (s32)&scale, (s32)&val);
    func_003B3DB8(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008,
                      func_0037DF98(0xCBD), 0xD0006, 0xFF, 0xD0007, 0xCD5, val);
    func_L01_00513548(0xD0005, scale, scale);
    func_003E2DE0(0x11, 0x1E0000);
    func_L01_0048CE58();
    func_L01_00514D50_0048C378(0x1E0006);

    func_003E3D08(0x1E0009, 0x706EC8FF, D_L01_001D8DB8 + D_L01_001D8DC0,
                      D_L01_001D8DAC + D_L01_001D8DB4 * 2.0f, 0.01953f, 0.040868f, 0.004f, 0.005f);
    func_003E3D08(0x1E0008, 0x332299DE,
                      (D_L01_001D8DB8 + D_L01_001D8DC0 + D_L01_001D8DBC) * 0.5f,
                      D_L01_001D8DAC + D_L01_001D8DB4 * 2.0f,
                      D_L01_001D8DBC - (D_L01_001D8DB8 + D_L01_001D8DC0), D_L01_001D8DC4, 0.004f, 0.005f);
    func_003E3BD0(0x1E0007, 0x332299DE, 0, D_L01_001D8DB8 + D_L01_001D8DC0 + 0.004f,
                      D_L01_001D8DAC + D_L01_001D8DB4 * 2.0f,
                      D_L01_001D8DBC - (D_L01_001D8DB8 + D_L01_001D8DC0) - 0.008f, D_L01_001D8DC4 - 0.01f);
    func_L01_00512BA0(0x1E0007, 1, 3);

    func_003E3D08(0x1E000C, 0x706EC8FF, D_L01_001D8DB8 + D_L01_001D8DC0,
                      D_L01_001D8DAC + D_L01_001D8DB4 * 3.0f, 0.01953f, 0.040868f, 0.004f, 0.005f);
    func_003E3D08(0x1E000B, 0x332299DE,
                      (D_L01_001D8DB8 + D_L01_001D8DC0 + D_L01_001D8DBC) * 0.5f,
                      D_L01_001D8DAC + D_L01_001D8DB4 * 3.0f,
                      D_L01_001D8DBC - (D_L01_001D8DB8 + D_L01_001D8DC0), D_L01_001D8DC4, 0.004f, 0.005f);
    func_003E3BD0(0x1E000A, 0x332299DE, 0, D_L01_001D8DB8 + D_L01_001D8DC0 + 0.004f,
                      D_L01_001D8DAC + D_L01_001D8DB4 * 3.0f,
                      D_L01_001D8DBC - (D_L01_001D8DB8 + D_L01_001D8DC0) - 0.008f, D_L01_001D8DC4 - 0.01f);

    func_L01_005130C8(0x1E0008, 0x331465B7);
    func_L01_005130C8(0x1E0007, 0x60000000);
    func_L01_005130C8(0x1E000B, 0x331465B7);
    func_L01_005130C8(0x1E000A, 0x60000000);
    func_L01_00512BA0(0x1E000A, 1, 3);
    func_003E3630(0x1E0006, 0x1E0007, 0x1E0008, 0x1E000A, 0x1E0009, 0x1E000B, 0x1E000C);
    func_003E34A0(0x1E0000, 0x1E0006, 0x1E000D);
    func_L01_0048D720();
    func_003E31A8(0x1E0003, func_003AED40(1));
    func_L01_005131A0(0x1E0003, 0);
    func_L01_00512D70(0x1E0003, 0);
    func_003E3250(0x1E0003, 1, 10);
}
/* localdecomp:end func_L01_0048C378 */
