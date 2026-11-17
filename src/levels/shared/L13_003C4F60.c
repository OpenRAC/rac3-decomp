#include "common.h"

INCLUDE_ASM("asm/levels", func_L13_003C4F60);

/* localdecomp:start func_L13_003C5430 */
__asm__(".extern D_L13_001DEB58, 4");
extern f32 D_L13_001DEB58;
extern f32 D_L13_001E1B20[];
extern s32 D_L13_001E1B18[];
extern f32 func_003824E0(f32, f32);
extern void func_003C6FB0(s32, u32 *, u32 *, u32 *);

void func_L13_003C5430(u8 *self) {
    u32 r;
    u32 g;
    u32 b;
    u8 *o;
    f32 *s;
    s32 i;

    o = *(u8 **)(self + 0x68);
    s = &D_L13_001DEB58;
    for (i = 0; i < 5; i++) {
        D_L13_001E1B20[i] = s[i];
    }
    *(f32 *)(o + 0x25C) = func_003824E0(0.0628318564f, 0.1675516218f);
    func_003C6FB0((s32)self, &r, &g, &b);
    *(u8 *)(o + 0x264) = *(u8 *)&r;
    *(u8 *)(o + 0x265) = *(u8 *)&g;
    *(u8 *)(o + 0x266) = *(u8 *)&b;
    D_L13_001E1B18[0] = 0;
}
/* localdecomp:end func_L13_003C5430 */

INCLUDE_ASM("asm/levels", func_L13_003C54F8);

/* localdecomp:start func_L13_003C56A0 */
typedef struct {
    u8 pad0[0x200];
    f32 f200[4];
    f32 f210[4];
    s32 f220[4];
    u8 pad230[0x10];
    s32 f240;
    s32 f244[3];
} S_003C56A0;
extern s32 func_00382468(s32);
extern f32 func_0038DB48(f32);
extern s32 func_00382498(s32, s32);

void func_L13_003C56A0(u8 *self)
{
    S_003C56A0 *p = *(S_003C56A0 **)(self + 0x68);
    s32 i;

    for (i = 0; i < 3; i++) {
        p->f244[i] = p->f240 - 1;
        if (p->f240 == 0) {
            p->f244[i] += func_00382468(4);
        }
    }
    if (p->f240 == 0 && p->f244[0] == p->f244[1] && p->f244[0] == p->f244[2]) {
        p->f244[2] += func_00382468(3) + 1;
    }
    for (i = 0; i < 3; i++) {
        p->f200[i] = func_0038DB48(p->f200[i]);
        if (i != 1) {
            p->f220[i] = func_00382498(4, 6) * 4 + p->f244[i];
        } else {
            s32 r = func_00382498(4, 6) * 4;
            s32 t = p->f244[1] - 4;
            p->f220[1] = r - t;
        }
        p->f210[i] = (f32)p->f220[i] * 6.2831855f * 0.25f;
    }
}
/* localdecomp:end func_L13_003C56A0 */

INCLUDE_ASM("asm/levels", func_L13_003C5838);

/* localdecomp:start func_L13_003C59E8 */
extern s32 func_003A52A0(s32, s32, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L01_00450DE8(void *, void *, f32, f32, f32);
extern void func_L01_00446748(void *, void *, s32, f32);
extern s32 func_003D4D00(void *, s32, f32, void *, void *);
extern void func_L04_00325460(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32, s32);
extern void func_L01_00452460(void *, s32, s32);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003C59E8;
typedef struct {
    u8 pad[0x18];
    u8 a;
    u8 b;
    u16 c;
    s32 d[5];
} Hit_003C59E8;

void func_L13_003C59E8(u8 *self) {
    u8 *p;
    V4_003C59E8 v;
    V4_003C59E8 pos;
    Hit_003C59E8 h;

    p = *(u8 **)(self + 0x68);
    func_003A52A0(4, 0, self);
    func_0038CE20(&v, self + 0xE0, 0.120000005f);
    func_L01_00451FE0(self, 0x7FF, &v, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
    if (*(s32 *)(p + 0x250)) {
        func_L01_00450DE8(self, &pos, 0.0f, 0.0f, 1.5f);
        func_L01_00446748(&h, self, 0x1010001, *(s32 *)(p + 0x254) ? 2.0f : 10.0f);
        h.a = 2;
        h.b = 1;
        h.c = *(u16 *)(self + 0xAA);
        func_003D4D00(&pos, 0x10, 3.0f, self, &h);
        func_L04_00325460(self + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 1.0f, 20.0f, 1, 1, 0, 0);
    }
    func_L01_00452460(self, 0x1EF5, 0x20);
}
/* localdecomp:end func_L13_003C59E8 */
