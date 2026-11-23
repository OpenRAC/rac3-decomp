#include "common.h"

typedef struct {
    s32 pad[3];
    s32 val;
} S_48DA70;
typedef struct { u8 b[16]; } V16_48DCD8;
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6EC0 - 0x4958];
    u8 fX[1];
} S_func_0048E5D8;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} E_002EB338;
typedef struct {
    s32 w0;
    u8 b4;
    u8 pad5[3];
    void (*fn)(void);
    s32 wC;
} S_48F880e;
typedef struct {
    u8 pad0[0x1C4];
    s32 w1C4;
} S_48F880;

/* declared by functions of L01_00491A30.c, which this file was cut from */
extern void *func_003B42F8(s32);
extern s32 func_L01_00516D60(s32, s32);
extern s32 func_00381FF0(s32);
extern void func_L01_004928C8();

/* localdecomp:start func_L01_004928C8 */
extern s32 D_L01_001D8E6C;
__asm__(".extern D_L01_001D8E6C, 4");
extern s32 D_L01_001D8E78;
extern f32 D_L01_001DC0E8;
extern u8 D_L01_002EB4E8[];
extern void func_L01_00492FE0(void);
extern void func_0038E150(s32);
extern s32 func_00381FF0(s32);
extern s32 func_0038E548(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern void func_003E7F20(s32, s32);
extern void func_003E8630(s32, s32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_L01_00492D00(void *);
extern void func_003E8348(s32, s32);
extern void func_003E8710(s32, void *);
extern s32 func_L01_00516D60(s32, s32);
extern void func_003E87B8(s32, s32, s32);
extern void func_L01_004931E0(void);

/* same shape as func_L01_0049D5E8 in L01_0049D5E8.c */
void func_L01_004928C8(void) {
    s32 scale = 0;
    f32 width;
    f32 ratio;
    f32 maxWidth = 0.49f;
    f32 low = 6.0f;
    f32 high = 11.0f;
    f32 zoom = 0.0f;
    f32 zero = 0.0f;
    D_L01_001D8E6C = -1;
    D_L01_001D8E78 = 0;
    func_L01_00492FE0();
    func_0038E150(0);
    ratio = (f32)func_0038E548(func_00381FF0(0x162), -1, 1.2f) / D_L01_001DC0E8;
    if (ratio > maxWidth) {
        scale = 1;
        zoom = 0.58800006f / ratio;
        ratio = maxWidth;
    }
    width = func_003C4088(low, high, (ratio - zero) / maxWidth);
    if (width > high) width = high;
    else if (width < low) width = low;
    func_003B9298(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005,
        0xD0008, func_00381FF0(0x162), 0xD0006, 0x124, 0xD0007, 0xCD5, width);
    func_003E8FE8(0xD0009, func_00381FF0(0x1B80), 0x8066CCFF, 0.035f, 0.5f, 1.0f, 1.0f);
    func_003E7F20(0xD0009, 1);
    func_003E8630(0xD000B, 0xD0009);
    if (scale) func_L01_00517538(0xD0005, zoom, zoom);
    func_L01_00492D00(D_L01_002EB4E8);
    func_003E8348(0x11, 0x1C0000);
    func_003E8710(0x1C0003, func_003B42F8(0));
    func_L01_00516D60(0x1C0003, 0);
    func_003E87B8(0x1C0003, 1, 8);
    func_L01_004931E0();
}
/* localdecomp:end func_L01_004928C8 */
