#include "common.h"

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x7058 - 0x4958];
    u8 fX[1];
} S_func_00498868;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 x14;
    u8 pad[3];
} E_498978;
typedef struct { u8 pad0[0x1C4]; s32 w1C4; } S_0049C950;
extern S_0049C950 *D_001D52FC[] __attribute__((section(".sdata")));

/* declared by functions of L01_0049BE80.c, which this file was cut from */
extern void *func_003B42F8(s32);
extern s32 *func_003B9BD0(s32);
extern s32 func_00381FF0(s32);
extern s32 func_L01_00516D60(s32, s32);
extern s32 func_L01_00517190(s32, s32);
extern void func_L01_0049C688();

/* localdecomp:start func_L01_0049C688 */
typedef struct MenuRow_0049C688 {
    s32 text;
    u8 pad[16];
    u8 enabled;
    u8 tail[3];
} MenuRow_0049C688;
extern s32 D_L01_001D9468, D_L01_001D9470, D_L01_001D9474, D_L01_001D9478;
__asm__(".extern D_L01_001D9468, 4");
__asm__(".extern D_L01_001D9470, 4");
__asm__(".extern D_L01_001D9474, 4");
__asm__(".extern D_L01_001D9478, 4");
extern f32 D_L01_001DC0E8;
extern MenuRow_0049C688 D_L01_002EC368[];
extern u8 D_L01_002EC5D8[];
extern void func_L01_0049D0F8(void);
extern s32 func_0038E548(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_L01_0049CA28(void *);
extern void func_003E8348(s32, s32);
extern void func_003E8710(s32, void *);
extern void func_L01_0049CD08(void);
extern void func_L01_0049D2E8(void);
extern void func_L01_004986A8(s32 *, s32);
extern void func_003E87B8(s32, s32, s32);

void func_L01_0049C688(void) {
    s32 i = 0;
    s32 scale = 0;
    f32 width;
    f32 ratio;
    f32 maxWidth = 0.49f;
    f32 low = 6.0f;
    f32 high = 11.0f;
    f32 zoom = 0.0f;
    f32 zero = 0.0f;
    s32 selected;
    MenuRow_0049C688 *row;
    MenuRow_0049C688 *first;
    func_L01_0049D0F8();
    ratio = (f32)func_0038E548(func_00381FF0(0x1C3), -1, 1.2f) / D_L01_001DC0E8;
    if (ratio > maxWidth) {
        scale = 1;
        zoom = 0.58800006f / ratio;
        ratio = maxWidth;
    }
    width = func_003C4088(low, high, (ratio - zero) / maxWidth);
    if (width > high) width = high;
    else if (width < low) width = low;
    func_003B9298(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005,
        0xD0008, func_00381FF0(0x1C3), 0xD0006, 0x124, 0xD0007, 0xCD5, width);
    if (scale) func_L01_00517538(0xD0005, zoom, zoom);
    func_L01_0049CA28(D_L01_002EC5D8);
    func_003E8348(0x11, 0x4E0000);
    func_003E8710(0x4E0003, func_003B42F8(1));
    func_L01_00517190(0x4E0003, 0);
    func_L01_0049CD08();
    func_L01_0049D2E8();
    D_L01_001D9478 = -1;
    first = &D_L01_002EC368[i];
    if (first->text) {
        row = first;
        selected = -1;
        while (row->text && selected < 0) {
            if (row->enabled) selected = i;
            row++;
            i++;
        }
        D_L01_001D9478 = selected;
    }
    if (D_L01_001D9478 < 0 && D_L01_001D9470 != 0) D_L01_001D9478 = 0;
    if (D_L01_001D9474 >= 0) func_L01_004986A8(func_003B9BD0(0), D_L01_001D9474);
    D_L01_001D9474 = -1;
    D_L01_001D9468 = -1;
    func_L01_00516D60(0x4E0003, 0);
    func_003E87B8(0x4E0003, 1, 8);
}
/* localdecomp:end func_L01_0049C688 */
