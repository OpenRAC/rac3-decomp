#include "common.h"

/* localdecomp:start func_L01_0049D5E8 */
typedef struct MenuRow_49D5E8 {
    s32 text;
    u8 pad[16];
    u8 enabled;
    u8 tail[3];
} MenuRow_49D5E8;
extern char D_L01_001D9540[];
extern char D_L01_001D9500[8], D_L01_001D9520[8];
extern s32 D_L01_001D94C0, D_L01_001D94C4, D_L01_001D94C8;
extern s32 D_L01_001D94CC, D_L01_001D94D0, D_L01_001D94D4;
__asm__(".extern D_L01_001D9500, 8");
__asm__(".extern D_L01_001D9520, 8");
__asm__(".extern D_L01_001D94C0, 4");
__asm__(".extern D_L01_001D94C4, 4");
__asm__(".extern D_L01_001D94C8, 4");
__asm__(".extern D_L01_001D94CC, 4");
__asm__(".extern D_L01_001D94D0, 4");
__asm__(".extern D_L01_001D94D4, 4");
extern f32 D_L01_001DC0E8;
extern MenuRow_49D5E8 D_L01_002EC758[];
extern u8 D_L01_002EC9C8[];
extern char *func_00381FF0(s32);
extern s32 func_0011B2E8(char *, char *, char *);
extern void func_L01_0049E190(void);
extern s32 func_0038E548(char *, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, char *, s32, s32, s32, s32, f32);
extern void func_L01_00516FD8(s32, char *);
extern void func_L01_00517538(s32, f32, f32);
extern void func_L01_0049DB30(void *);
extern void func_003E8FE8(s32, char *, s32, f32, f32, f32, f32);
extern void func_L01_00516728(s32, f32, f32);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_003E8630(s32, s32);
extern void func_003E8348(s32, s32);
extern char *func_003B42F8(s32);
extern void func_003E8710(s32, char *);
extern void func_L01_0049DE10(void);
extern void func_L01_00518670(s32, s32, s32);
extern void func_003E7F20(s32, s32);
extern void func_L01_0049E5C0(void), func_L01_0049E648(void);
extern void func_L01_00516D60(s32, s32), func_L01_00517190(s32, s32);
extern void func_003E87B8(s32, s32, s32);

void func_L01_0049D5E8(void) {
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
    MenuRow_49D5E8 *row;
    MenuRow_49D5E8 *first;
    func_0011B2E8(D_L01_001D9500, D_L01_001D9540, func_00381FF0(0x1B84));
    func_0011B2E8(D_L01_001D9520, D_L01_001D9540, func_00381FF0(0x1B83));
    D_L01_001D94C0 = 0;
    func_L01_0049E190();
    ratio = (f32)func_0038E548(func_00381FF0(0x1C4), -1, 1.2f) / D_L01_001DC0E8;
    if (ratio > maxWidth) {
        scale = 1;
        zoom = 0.58800006f / ratio;
        ratio = maxWidth;
    }
    width = func_003C4088(low, high, (ratio - zero) / maxWidth);
    if (width > high) width = high;
    else if (width < low) width = low;
    func_003B9298(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005,
        0xD0008, func_00381FF0(0x1C4), 0xD0006, 0x124, 0xD0007, 0xCD5, width);
    func_L01_00516FD8(0xD0006, D_L01_001D9500);
    func_L01_00516FD8(0xD0007, D_L01_001D9520);
    if (scale) func_L01_00517538(0xD0005, zoom, zoom);
    func_L01_0049DB30(D_L01_002EC9C8);
    func_003E8FE8(0x500009, func_00381FF0(0xCD5), 0x8066CCFF, 0.5f, 0.931999981f, 0.9f, 0.9f);
    func_L01_00516728(0x500009, 0.00449999981f, 0.00449999981f);
    func_L01_00516AA0(0x500009, 0x40, 1);
    func_003E8630(0x500000, 0x500009);
    func_003E8348(0x11, 0x500000);
    func_003E8710(0x500003, func_003B42F8(0));
    func_003E8710(0x500004, func_003B42F8(1));
    func_003E8710(0x500005, func_003B42F8(2));
    func_L01_0049DE10();
    func_L01_00518670(0x500008, 1, 1);
    func_003E7F20(0x500008, 1);
    D_L01_001D94C8 = -1;
    first = &D_L01_002EC758[i];
    if (first->text) {
        row = first;
        selected = -1;
        while (row->text && selected < 0) {
            if (row->enabled) selected = i;
            row++;
            i++;
        }
        D_L01_001D94C8 = selected;
    }
    if (D_L01_001D94C8 < 0 && D_L01_001D94C4 != 0) D_L01_001D94C8 = 0;
    if (D_L01_001D94C8 >= 0) {
        D_L01_001D94CC = 0x500003;
        D_L01_001D94D0 = 0x500004;
        D_L01_001D94D4 = 0x500005;
        func_L01_0049E5C0();
        func_L01_0049E648();
    }
    func_L01_00516D60(D_L01_001D94CC, 0);
    func_L01_00517190(D_L01_001D94CC, 0);
    func_003E87B8(D_L01_001D94CC, 1, 8);
}
/* localdecomp:end func_L01_0049D5E8 */
