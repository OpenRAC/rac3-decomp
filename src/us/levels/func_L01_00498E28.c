#include "common.h"

/* NTSC-U counterpart of func_L01_0049C688 (src/levels/shared/L01_0049C688.c): 8 -> 10 */
extern void *func_003AED40(s32);
extern s32 *func_003B46F0(s32);
extern s32 func_0037DF98(s32);
extern s32 func_L01_00512D70(s32, s32);
extern s32 func_L01_005131A0(s32, s32);
extern void func_L01_00498E28();

/* localdecomp:start func_L01_00498E28 */
typedef struct MenuRow_0049C688 {
    s32 text;
    u8 pad[16];
    u8 enabled;
    u8 tail[3];
} MenuRow_0049C688;
extern s32 D_L01_001D9498, D_L01_001D94A0, D_L01_001D94A4, D_L01_001D94A8;
__asm__(".extern D_L01_001D9498, 4");
__asm__(".extern D_L01_001D94A0, 4");
__asm__(".extern D_L01_001D94A4, 4");
__asm__(".extern D_L01_001D94A8, 4");
extern f32 D_L01_001DC128;
extern MenuRow_0049C688 D_L01_002EC3B8[];
extern u8 D_L01_002EC628[];
extern void func_L01_00499898(void);
extern s32 func_00389D18(s32, s32, f32);
extern f32 func_003BEB48(f32, f32, f32);
extern void func_003B3DB8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_L01_00513548(s32, f32, f32);
extern void func_L01_004991C8(void *);
extern void func_003E2DE0(s32, s32);
extern void func_003E31A8(s32, void *);
extern void func_L01_004994A8(void);
extern void func_L01_00499A88(void);
extern void func_L01_00494E68(s32 *, s32);
extern void func_003E3250(s32, s32, s32);

void func_L01_00498E28(void) {
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
    func_L01_00499898();
    ratio = (f32)func_00389D18(func_0037DF98(0x1C3), -1, 1.2f) / D_L01_001DC128;
    if (ratio > maxWidth) {
        scale = 1;
        zoom = 0.58800006f / ratio;
        ratio = maxWidth;
    }
    width = func_003BEB48(low, high, (ratio - zero) / maxWidth);
    if (width > high) width = high;
    else if (width < low) width = low;
    func_003B3DB8(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005,
        0xD0008, func_0037DF98(0x1C3), 0xD0006, 0x124, 0xD0007, 0xCD5, width);
    if (scale) func_L01_00513548(0xD0005, zoom, zoom);
    func_L01_004991C8(D_L01_002EC628);
    func_003E2DE0(0x11, 0x4E0000);
    func_003E31A8(0x4E0003, func_003AED40(1));
    func_L01_005131A0(0x4E0003, 0);
    func_L01_004994A8();
    func_L01_00499A88();
    D_L01_001D94A8 = -1;
    first = &D_L01_002EC3B8[i];
    if (first->text) {
        row = first;
        selected = -1;
        while (row->text && selected < 0) {
            if (row->enabled) selected = i;
            row++;
            i++;
        }
        D_L01_001D94A8 = selected;
    }
    if (D_L01_001D94A8 < 0 && D_L01_001D94A0 != 0) D_L01_001D94A8 = 0;
    if (D_L01_001D94A4 >= 0) func_L01_00494E68(func_003B46F0(0), D_L01_001D94A4);
    D_L01_001D94A4 = -1;
    D_L01_001D9498 = -1;
    func_L01_00512D70(0x4E0003, 0);
    func_003E3250(0x4E0003, 1, 10);
}
/* localdecomp:end func_L01_00498E28 */
