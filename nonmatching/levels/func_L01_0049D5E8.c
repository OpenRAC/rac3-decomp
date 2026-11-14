/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_00499D88, the NTSC-U twin of func_L01_0049D5E8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/shared/L01_0049CF68.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* localdecomp:start func_L01_00499D88 */
typedef struct MenuRow_499D88 {
    s32 text;
    u8 pad[16];
    u8 enabled;
    u8 tail[3];
} MenuRow_499D88;
extern char D_L01_001D9570[];
extern char D_001D9530_sda[32], D_001D9550_sda[32];
extern s32 D_001D94F0_sda, D_001D94F4_sda, D_001D94F8_sda;
extern s32 D_001D94FC_sda, D_001D9500_sda, D_001D9504_sda;
extern f32 D_L01_001DC128[];
extern MenuRow_499D88 D_L01_002EC7A8[];
extern u8 D_L01_002ECA18[];
extern char *func_0037DF98(s32);
extern s32 func_0011B2E8(char *, char *, char *);
extern void func_L01_0049A930(void);
extern s32 func_00389D18(char *, s32, f32);
extern f32 func_003BEB48(f32, f32, f32);
extern void func_003B3DB8(s32, s32, s32, s32, s32, s32, s32, s32, s32, char *, s32, s32, s32, s32, f32);
extern void func_L01_00512FE8(s32, char *);
extern void func_L01_00513548(s32, f32, f32);
extern void func_L01_0049A2D0(void *);
extern void func_003E3A80(s32, char *, s32, f32, f32, f32, f32);
extern void func_L01_00512738(s32, f32, f32);
extern void func_L01_00512AB0(s32, s32, s32);
extern void func_003E30C8(s32, s32);
extern void func_003E2DE0(s32, s32);
extern char *func_003AED40(s32);
extern void func_003E31A8(s32, char *);
extern void func_L01_0049A5B0(void);
extern void func_L01_00514680(s32, s32, s32);
extern void func_003E29B8(s32, s32);
extern void func_L01_0049AD60(void), func_L01_0049ADE8(void);
extern void func_L01_00512D70(s32, s32), func_L01_005131A0(s32, s32);
extern void func_003E3250(s32, s32, s32);

void func_L01_00499D88(void) {
    s32 i = 0;
    s32 scale = 0;
    f32 width;
    f32 zoom = 0.0f;
    f32 maxWidth = 0.49f;
    f32 low = 6.0f;
    f32 high = 11.0f;
    f32 zero = 0.0f;
    s32 selected;
    MenuRow_499D88 *row;
    func_0011B2E8(D_001D9530_sda, D_L01_001D9570, func_0037DF98(0x1B84));
    func_0011B2E8(D_001D9550_sda, D_L01_001D9570, func_0037DF98(0x1B83));
    D_001D94F0_sda = 0;
    func_L01_0049A930();
    width = (f32)func_00389D18(func_0037DF98(0x1C4), -1, 1.2f) / D_L01_001DC128[0];
    if (width > maxWidth) {
        scale = 1;
        zoom = 0.588f / width;
        width = maxWidth;
    }
    width = func_003BEB48(low, high, (width - zero) / maxWidth);
    if (width > high) width = high;
    else if (width < low) width = low;
    func_003B3DB8(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005,
        0xD0008, func_0037DF98(0x1C4), 0xD0006, 0x124, 0xD0007, 0xCD5, width);
    func_L01_00512FE8(0xD0006, D_001D9530_sda);
    func_L01_00512FE8(0xD0007, D_001D9550_sda);
    if (scale) func_L01_00513548(0xD0005, zoom, zoom);
    func_L01_0049A2D0(D_L01_002ECA18);
    func_003E3A80(0x500009, func_0037DF98(0xCD5), 0x8066CCFF, 0.5f, 0.931999981f, 0.9f, 0.9f);
    func_L01_00512738(0x500009, 0.00449999981f, 0.00449999981f);
    func_L01_00512AB0(0x500009, 0x40, 1);
    func_003E30C8(0x500000, 0x500009);
    func_003E2DE0(0x11, 0x500000);
    func_003E31A8(0x500003, func_003AED40(0));
    func_003E31A8(0x500004, func_003AED40(1));
    func_003E31A8(0x500005, func_003AED40(2));
    func_L01_0049A5B0();
    func_L01_00514680(0x500008, 1, 1);
    func_003E29B8(0x500008, 1);
    D_001D94F8_sda = -1;
    row = &D_L01_002EC7A8[i];
    selected = -1;
    while (row->text && selected < 0) {
        if (row->enabled) selected = i;
        row++;
        i++;
    }
    D_001D94F8_sda = selected;
    if (D_001D94F8_sda < 0 && D_001D94F4_sda == 0) D_001D94F8_sda = 0;
    if (D_001D94F8_sda >= 0) {
        D_001D94FC_sda = 0x500003;
        D_001D9500_sda = 0x500004;
        D_001D9504_sda = 0x500005;
        func_L01_0049AD60();
        func_L01_0049ADE8();
    }
    func_L01_00512D70(D_001D94FC_sda, 0);
    func_L01_005131A0(D_001D94FC_sda, 0);
    func_003E3250(D_001D94FC_sda, 1, 10);
}
/* localdecomp:end func_L01_00499D88 */
