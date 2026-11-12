#include "common.h"

INCLUDE_ASM("asm/levels", func_L28_0039F2C0);

/* localdecomp:start func_L28_003A0708 */
extern s32 func_L28_003A0930(void *);
extern void func_003C2880(void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L28_003A0EC0(u8 *);
extern s32 func_L01_00452860(void *, void *, s32);
extern s32 func_L28_003A0B60(void *);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
s32 func_L28_003A0708(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    s32 t;
    if (a0[0x20] == 0) {
        if (func_L28_003A0930(a0) != 0) return 1;
    }
    if (*(f32 *)(a0 + 0x18) < *(f32 *)(st + 0x2D8) - 200.0f) {
        func_003C2880(a0);
        return 1;
    }
    if (func_L01_00452FB0(a0, st + 0x160, 0, 0, 0) != 0) func_L28_003A0EC0(a0);
    func_L01_00452860(a0, st + 0x30, 0);
    if (st[0x5E] != 0) {
        func_L28_003A0B60(a0);
        return 1;
    }
    if (st[0x3E] == 2) return 1;
    if (st[0x5F] != 0) {
        func_L01_00456BD0(a0, 5);
        t = a0[0x20];
        if ((u32)(t - 3) < 2 || t == 1) {
            func_L01_00456C98(a0, *(s32 *)(st + 0x2C0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(st + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(st + 0x2C8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(st + 0x2CC), 10.0f, 1.0f);
        }
    } else {
        func_L01_00456BD0(a0, 3);
        t = a0[0x20];
        if ((u32)(t - 3) < 2 || t == 1) {
            func_L01_00456C98(a0, *(s32 *)(st + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(st + 0x2C8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x2CC), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L28_003A0708 */

INCLUDE_ASM("asm/levels", func_L28_003A0930);

INCLUDE_ASM("asm/levels", func_L28_003A0B60);

/* localdecomp:start func_L28_003A0DC0 */
extern u8 D_L28_001E1540[];
extern void func_L01_00404808(void *, void *);
extern void func_L08_003A16C8(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(f32, u32, u32);
void func_L28_003A0DC0(u8 *a0) {
    u8 *d = *(u8 **)(a0 + 0x68);
    f32 t;
    if (*(u16 *)(a0 + 0x96) <= 0xFFFE) *(u16 *)(a0 + 0x96) = *(u16 *)(a0 + 0x96) + 1;
    if (a0[0x20] != 1 && a0[0x31] != 0) func_L01_00404808(func_L08_003A16C8, a0);
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L28_001E1540, a0 + 0x10) < 1024.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x1E;
        }
    }
    t = func_0038DAB8(*(f32 *)(d + 0x30C), 0.15358898f);
    *(f32 *)(d + 0x30C) = t;
    *(s32 *)(a0 + 0x78) = func_0038DBD8((func_0038D0B0(t) + 1.0f) * 0.5f, 0x8000A0A0, 0x80005050);
}
/* localdecomp:end func_L28_003A0DC0 */

/* localdecomp:start func_L28_003A0EC0 */
extern u16 *D_L28_0021B6A0[];
extern u8 *D_L28_001DEC9C;
__asm__(".extern D_L28_001DEC9C, 16");
extern s32 D_L28_001DECD8;

void func_L28_003A0EC0(u8 *a0) {
    u16 *p;
    u8 *e;
    if (a0[0x21] == 0xFF) return;
    p = D_L28_0021B6A0[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L28_001DECD8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L28_0021B6A0[a0[0x21]])) {
        e = D_L28_001DEC9C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        p++;
        if (*(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA)) {
            *(s32 *)(*(u8 **)(e + 0x68) + 0x300) = 1;
        }
    }
}
/* localdecomp:end func_L28_003A0EC0 */
