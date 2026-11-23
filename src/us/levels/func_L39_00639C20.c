#include "common.h"

/* NTSC-U counterpart of func_L39_0063C468 (src/levels/shared/L39_0063BDE0.c) */
extern u8 D_L39_004998A0[];
#include "vu0.h"
extern u8 D_L39_004998A0[];

/* localdecomp:start func_L39_00639C20 */
typedef union Buf_0063C468 {
    u8 b[8];
    u32 w[2];
} Buf_0063C468;

extern u8 D_L39_004998A0[];
extern void func_L39_0061F590(u8 *);
extern void func_L39_00632600(u8 *, f32, f32);
extern void func_L39_006325E0(u8 *, f32, f32);
extern s32 func_L39_005B24C8(s32, s32);
extern s32 func_00388398(void *);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B2568(f32, f32);
extern f32 func_003BEB48(f32, f32, f32);

static __inline__ u32 Dec_0063C468(u8 *q) {
    Buf_0063C468 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

void func_L39_00639C20(u8 *self) {
    s32 flag;
    s32 t;
    u8 *p;
    u8 c;
    f32 r;

    if (*(s32 *)(self + 0x324) < 0x14) {
        return;
    }
    if (self[0x1A07] != 0 || *(s32 *)(self + 0x1078) != 0) {
        func_L39_0061F590(self);
        func_L39_00632600(self, 0.03f, 0.2f);
        func_L39_006325E0(self, 0.03f, 0.2f);
        *(s32 *)(self + 0x10A0) = func_L39_005B24C8(0x5A, 0x78);
        *(s16 *)(self + 0x334) = func_L39_005B24C8(0x5A, 0x78);
        return;
    }
    flag = 1;
    t = -1;
    if (*(s32 *)(self + 0x474) == 2) {
        t = *(s32 *)(self + 0x478);
    }
    if (t == 1) {
        flag = 0;
    }
    if (Dec_0063C468(self + 0x19E4) != 0) {
        return;
    }
    p = *(u8 **)(self + 0x2524);
    c = p[0x43];
    if (c >= 3) {
        return;
    }
    if (*(s32 *)(self + 0x2454) != 0) {
        return;
    }
    if ((u32)(c - 1) < 2) {
        *(s32 *)(self + 0x10A0) = func_L39_005B24C8(0x28, 0x46);
    }
    if (func_00388398(self + 0x10A0)) {
        *(f32 *)(self + 0x1094) = -func_L39_005B2510(-0.15707964f, 0.43633232f);
        if (*(f32 *)(self + 0x208) < 1.5f) {
            *(f32 *)(self + 0x1098) = func_L39_005B2568(0.87266463f, 1.2217305f);
        } else {
            *(f32 *)(self + 0x1098) = func_L39_005B2568(0.34906584f, 0.99483764f);
        }
        r = func_L39_005B2510(0.0f, 1.0f);
        *(f32 *)(self + 0x10A4) = func_003BEB48(0.015f, 0.007f, r);
        *(f32 *)(self + 0x10A8) = func_003BEB48(0.29f, 0.3f, r);
        *(s32 *)(self + 0x10A0) = func_L39_005B24C8(0x5A, 0xC8) + (s32)(r * 80.0f);
    }
    if ((u32)((*(u8 **)(self + 0x2524))[0x43] - 1) < 2) {
        if (0.34906584f < *(f32 *)(self + 0x1098)) {
            *(f32 *)(self + 0x1098) = 0.34906584f;
        } else if (*(f32 *)(self + 0x1098) < -0.34906584f) {
            *(f32 *)(self + 0x1098) = -0.34906584f;
        }
        if (0.2617994f < *(f32 *)(self + 0x1094)) {
            *(f32 *)(self + 0x1094) = 0.2617994f;
        }
        if (*(f32 *)(self + 0x1094) < 0.0f) {
            *(f32 *)(self + 0x1094) = 0.0f;
        }
    }
    func_L39_00632600(self, *(f32 *)(self + 0x10A4), *(f32 *)(self + 0x10A8));
    *(f32 *)(self + 0x9D8) = *(f32 *)(self + 0x1098);
    *(f32 *)(self + 0x9D4) = *(f32 *)(self + 0x1094);
    if (flag) {
        func_L39_006325E0(self, 0.008f, 0.3f);
        *(f32 *)(self + 0x878) = *(f32 *)(self + 0x9D8) * 0.52f;
        *(f32 *)(self + 0x874) = *(f32 *)(self + 0x9D4) * 0.55f;
    }
}
/* localdecomp:end func_L39_00639C20 */
