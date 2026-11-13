#include "common.h"

/* The game's HUD rounding: a screen coordinate times the screen scale, rounded, with the dead
 * compare of the video mode that retail keeps (docs/wiki/Matching-Patterns.md, "Dead compare
 * loads before a rounding expression"). */
extern s32 D_L10_001E0420;
extern f32 D_L10_001E0424;

static __inline__ s32 scale_3B5690(f32 v) {
    f32 z0 = 0.0f, z1 = 0.0f;
    return (s32)((f32)(s32)v * D_L10_001E0424 + 0.5f + (D_L10_001E0420 == 1 ? z0 : z1));
}

/* localdecomp:start func_L10_003B4350 */
extern s32 D_L10_001DEC48;
extern u32 *D_L10_001E02E8;
extern u8 D_00141990[];
extern void func_003A92F0(s32);
extern s32 func_0012C908(s32);
extern void func_003A9108(void);
extern void func_003A91D0(void);
extern void func_003A9150(void);
extern void func_003922B8(void);
extern void func_00392350(s32);
extern void func_003923D0(void);
extern void func_003A9440(s32, unsigned long);
extern void func_L01_004AADE8(s32, s32, void *, s32);
extern void func_003A4288(void);

void func_L10_003B4350(s32 n, s32 k) {
    s32 i;
    s32 c;
    s32 t;

    c = 0;
    func_003A92F0(1);
    i = n - 1;
    func_0012C908(0);
    D_L10_001DEC48 = D_L10_001DEC48 + 1;
    func_003A9108();
    while (i >= 0) {
        c++;
        func_003922B8();
        func_00392350(1);
        func_003923D0();
        func_003A9440(0x42, 0x8000000044UL);
        t = (i << 7) / (i + 1);
        func_003A9440(1, ((long)(0x80 - t) << 24) | 0xFFFFFF);
        D_L10_001E02E8[0] = 0x30000014;
        D_L10_001E02E8[1] = (u32)D_00141990;
        D_L10_001E02E8[2] = 0;
        D_L10_001E02E8[3] = 0x50000014;
        D_L10_001E02E8 = D_L10_001E02E8 + 4;
        func_003A92F0(1);
        func_0012C908(0);
        D_L10_001DEC48 = D_L10_001DEC48 + 1;
        func_003A91D0();
        func_003A9150();
        if (c == 2) {
            func_L01_004AADE8(0x17, 0x110, 0, 0);
        }
        func_003A4288();
        i--;
    }
    i = k - 1;
    while (i >= 0) {
        i--;
        func_003922B8();
        func_00392350(1);
        func_003923D0();
        func_003A9440(0x42, 0x8000000044UL);
        func_003A9440(1, 0x80FFFFFFUL);
        D_L10_001E02E8[0] = 0x30000014;
        D_L10_001E02E8[1] = (u32)D_00141990;
        D_L10_001E02E8[2] = 0;
        D_L10_001E02E8[3] = 0x50000014;
        D_L10_001E02E8 = D_L10_001E02E8 + 4;
        func_003A92F0(1);
        func_0012C908(0);
        D_L10_001DEC48 = D_L10_001DEC48 + 1;
        func_003A91D0();
        func_003A9150();
    }
    func_003A92F0(1);
    func_0012C908(0);
    D_L10_001DEC48 = D_L10_001DEC48 + 1;
    func_003A9108();
    func_003922B8();
    func_00392350(1);
}
/* localdecomp:end func_L10_003B4350 */

/* localdecomp:start func_L10_003B4600 */
extern void func_0038A238(s32);
extern void func_L01_0042B068(s32, s32);
extern void func_003864C0(s32);
extern f32 D_L10_001DEC50;
extern u8 D_L10_001DECE4;
extern u8 D_L10_001DECE5;
extern u8 D_L10_001DECE6;
extern f32 D_L10_001DECE8;
extern f32 D_L10_001DECEC;
extern f32 D_L10_001DECF0;
extern f32 D_L10_001DECF4;

void func_L10_003B4600(void) {
    func_0038A238(5);
    func_L01_0042B068(2, 0);
    D_L10_001DEC50 = 1.5f;
    D_L10_001DECE4 = 1;
    D_L10_001DECE5 = 1;
    D_L10_001DECE6 = 1;
    D_L10_001DECE8 = 262144.0f;
    D_L10_001DECEC = 524288.0f;
    D_L10_001DECF0 = 255.0f;
    D_L10_001DECF4 = 249.0f;
    func_003864C0(0);
}
/* localdecomp:end func_L10_003B4600 */

INCLUDE_ASM("asm/levels", func_L10_003B4698);

/* localdecomp:start func_L10_003B5690 */
extern s32 func_00396968(void *, s32);
extern void func_00396E50(s32, s32, s32, s32, s32, s32 *);

void func_L10_003B5690(u8 *a0, s32 color, f32 x0, f32 x1, f32 y0, f32 y1) {
    s32 c[4];
    f32 w = x1 - x0;
    f32 h = y1 - y0;

    c[0] = color;
    c[1] = color;
    c[2] = color;
    c[3] = color;
    func_00396E50(func_00396968(a0 + 0xED1C, 0), (s32)y0, scale_3B5690(x0), (s32)h,
                  scale_3B5690(w), c);
}
/* localdecomp:end func_L10_003B5690 */

/* localdecomp:start func_L10_003B57A8 */
__asm__(".extern D_L10_001DE748, 4");
extern s32 D_L10_001DE748;
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern void func_L01_00436020(s32, s32, f32, f32, f32, f32);
extern void func_L10_003B5690(u8 *, s32, f32, f32, f32, f32);

void func_L10_003B57A8(void) {
    s32 t = D_L10_001DE748;
    s32 m;
    s32 fr;
    f32 f;
    f32 x0;
    f32 x1;
    f32 y0;
    f32 y1;
    f32 w;
    f32 g;
    s32 d0;
    s32 d1;
    s32 d2;
    s32 d3;

    m = t / 50;
    fr = (t - m * 50) * 100;
    fr = fr / 50;
    if (m >= 100) {
        m = 99;
    }
    f = 0.0f;
    if (fr > 80) {
        f = (f32)(fr - 80) / 20.0f;
    }
    d0 = m % 10;
    d1 = m / 10 % 10;
    d2 = fr / 10 % 10;
    d3 = fr % 10;
    func_0038C3B0(scale_3B5690(71.0f), scale_3B5690(105.0f), 200, 307, 30, 0);
    func_L01_00436020(0x60, 0x462299DE, (f32)scale_3B5690(71.0f), (f32)scale_3B5690(105.0f), 200.0f, 307.0f);
    y0 = 251.0f;
    y1 = 255.0f;
    func_L10_003B5690((u8 *)0, 0x802020D0, 82.0f, 86.0f, y0, y1);
    func_L10_003B5690((u8 *)0, 0x802020D0, 92.0f, 96.0f, y0, y1);
    g = f + f;
    y1 = 250.0f - f;
    x0 = 75.0f - f * 3.0f;
    x1 = f * 3.0f + 103.0f;
    y0 = (y1 - 22.0f) - g;
    func_L10_003B5690((u8 *)d0, 0x802020D0, x0, x1, y0, y1);
    y1 = (y0 - 2.0f) - f;
    func_L10_003B5690((u8 *)d1, 0x802020D0, x0, x1, (y1 - 22.0f) - g, y1);
    y0 = f + 258.0f;
    y1 = (y0 + 22.0f) + g;
    func_L10_003B5690((u8 *)d2, 0x802020D0, x0, x1, y0, y1);
    y0 = (y1 + 2.0f) + f;
    func_L10_003B5690((u8 *)d3, 0x802020D0, x0, x1, y0, (y0 + 22.0f) + g);
}
/* localdecomp:end func_L10_003B57A8 */
