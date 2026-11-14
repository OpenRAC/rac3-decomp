#include "common.h"

/* NTSC-U counterpart of func_L40_00421C08 (src/levels/shared/L40_00421920.c) */
extern s32 func_L39_005F0CE0(s32, s32, u8 *);

/* localdecomp:start func_L40_00421350 */
#include "vu0.h"

extern u8 *D_L40_003575EC __attribute__((section(".data")));
extern s32 *D_L40_0028FF00[];
extern u8 D_L40_001FE1A0[];
extern s32 D_L40_00247810;
__asm__(".extern D_L40_00247810, 4");
extern s32 D_L40_00247884;
__asm__(".extern D_L40_00247884, 4");
extern f32 D_L40_00247880;
__asm__(".extern D_L40_00247880, 4");
extern f32 D_L40_0024787C;
__asm__(".extern D_L40_0024787C, 4");
extern void func_L39_00669B68(s32);
extern void func_L40_0053CE30(void *);
extern void func_L39_005F08F8(void *, s32);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_L40_00421068(u8 *, u8 *, s32);
extern s32 func_L01_00452EC8(u8 *);
extern void func_003BDA38(void *, s32, void *);
extern void func_L40_00421710(void *, void *, void *, void *, void *, void *, s32, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_00388A28(f32, f32);
extern void func_L01_004424B0(void *, void *, f32, f32, f32, f32);
extern f32 func_L39_005B25C8_00421350(void);
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);
extern s32 func_L39_005F0CE0(s32, s32, u8 *);
extern void func_L01_00457440(void *, void *);
extern s32 func_L01_00451078(void *, void *);

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00421C08;

typedef struct {
    u8 p0[0x88];
    s32 f88[1];
} S2_00421C08;

void func_L40_00421350(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    u8 *n = *(u8 **)(m + 0x90);
    s32 t = *(s32 *)n;
    u8 *e;
    f32 s, a, z;
    V_00421C08 pos;
    V_00421C08 zero;

    *(s32 *)(n + 0x18) = ((S2_00421C08 *)D_L40_003575EC)->f88[*(s32 *)(v + 0x290)];
    if (v[0x3E] == 2) {
        func_L39_00669B68(t);
        func_L40_0053CE30(m);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & ~0x1000;
        func_L39_005F08F8(m, 1);
        func_L01_00441FB8(m, 0x25, -1);
        return;
    }
    func_L40_00421068(m, v, t);
    switch (m[0x20]) {
    case 2:
        if (func_L01_00452EC8(m) != 0) {
            func_003BDA38(m, D_L40_00247810, &pos);
            qzero(&zero);
            func_L40_00421710(m, &pos, &zero, v + 0x2D0, &zero, m + 0xF0, D_L40_00247884, 0, 0);
        }
        if (m[0x43] != 2) {
            func_003BE4F0(m, 2, 0, 10);
        }
        a = func_00388A28(*(f32 *)(v + 0x2D0) - *(f32 *)(m + 0x10), *(f32 *)(v + 0x2D4) - *(f32 *)(m + 0x14));
        func_L01_004424B0(m, v + 0x458, a, 0.0017453293548896909f, 0.0017453293548896909f, 0.10471976548433304f);
        s = (f32)*(s32 *)(v + 0x460) / 100.0f;
        *(f32 *)(v + 0x2FC) = s / 3.0f;
        *(f32 *)(v + 0x30C) = (s + s) / 3.0f;
        a = func_L39_005B25C8_00421350();
        *(f32 *)(v + 0x2F4) = func_00388978(a) * 0.25f * s;
        *(f32 *)(v + 0x2F8) = func_00388960(a) * 0.25f * s;
        *(f32 *)(v + 0x304) = func_00388978(a) * 0.25f * s;
        *(f32 *)(v + 0x308) = func_00388960(a) * 0.25f * s;
        if ((*(s32 *)(v + 0x460))++ >= 101) {
            func_L01_00441FB8(m, 1, -1);
        }
        break;
    case 1:
        func_L01_00452EC8(m);
        if (*(s32 *)(v + 0x2AC) == -1
            || *(u8 **)((e = D_L40_001FE1A0 + *(s32 *)(v + 0x2AC) * 0x80) + 0xDC) != m
            || e[0xD0] == 0) {
            *(s32 *)(v + 0x2AC) = func_L39_005F0CE0(3, 4, m);
        }
        if (m[0x43] != 1) {
            func_003BE4F0(m, 1, 0, 10);
        }
        func_L01_00457440(m, &((V_00421C08 *)D_L40_0028FF00[*(s32 *)(v + 0x454)])[*(s32 *)(v + 0x450) + 1]);
        s = func_00388978(*(f32 *)(v + 0x348) * 0.017453292f);
        z = *(f32 *)(v + 0x230) + 0.6f + D_L40_0024787C * s;
        *(f32 *)(v + 0x348) += D_L40_00247880;
        if (*(f32 *)(v + 0x348) >= 360.0f) {
            *(f32 *)(v + 0x348) = 0.0f;
        }
        *(f32 *)(m + 0x18) = z;
        *(s32 *)(v + 0x460) = 0;
        break;
    case 3:
        func_L01_00452EC8(m);
        if (func_L01_00451078(m, v + 0xE0) & 2) {
            func_L01_00441FB8(m, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L40_00421350 */
