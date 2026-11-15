#include "common.h"

/* declared by functions of L35_003A29A8.c, which this file was cut from */
extern u8 D_001A4BE0[];

/* localdecomp:start func_L35_003A3498 */
extern u8 D_001A4BE0[];
extern void func_003C2880(u8 *a);
extern void func_L01_004450F0(u8 *moby, s32 a, s32 b);

void func_L35_003A3498(u8 *a0) {
    u8 *a3 = *(u8 **)(a0 + 0x68);
    u8 *g = D_001A4BE0;
    s32 n;
    n = 3;
    if (*(u8 **)(g + 0x538) == a0) {
        *(u8 **)(g + 0x538) = 0;
    }
    if (*(u8 **)(g + 0x3C0) == a0) {
        *(u8 **)(g + 0x3C0) = 0;
    }
    if (*(u8 **)(g + 0x35C) == a0) {
        *(u8 **)(g + 0x35C) = 0;
    }
    if (*(s32 *)(a3 + 0x98) == 0) {
        func_003C2880(a0);
    } else {
        func_L01_004450F0(a0, n, -1);
    }
    n = 0;
}
/* localdecomp:end func_L35_003A3498 */

/* localdecomp:start func_L35_003A3500 */
extern s32 func_0038CAD0(void *);
extern s32 func_L05_00328FF8(void *);
extern s32 func_L01_004AAC98(s32, s32, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L30_0034C8A8(void *, void *);
extern void func_L01_0044ABD0(void *, void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003C4A40(void *, void *);
extern void func_L01_00445F40(void *, s32);
extern void func_L35_003A2C40(u8 *, u8 *);
extern s32 D_001A4F40 __attribute__((section(".data")));
extern u8 D_L35_001E1D60[] __attribute__((section(".sdata")));
__asm__(".extern D_L35_001E1D60, 16");
extern f32 D_L35_001DE98C;
extern f32 D_L35_001DE994;
extern f32 D_L35_001DE998;
extern s32 D_L35_001DE9A0;
__asm__(".extern D_L35_001DE98C, 4");
__asm__(".extern D_L35_001DE994, 4");
__asm__(".extern D_L35_001DE998, 4");
__asm__(".extern D_L35_001DE9A0, 4");

void func_L35_003A3500(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 *t;
    u8 *p;
    u8 *g;

    func_0038CAD0(v + 0x9C);
    func_0038CAD0(v + 0xA8);
    if (*(s32 *)(v + 0x98) != 0 && func_L05_00328FF8(a0) != 0) {
        if (D_001A4F40 < 2) {
            func_L01_004AAC98(0, 0, (s32)a0, 0x1D67);
        }
        *(f32 *)(D_L35_001E1D60 + 4) =
            func_003C4088(D_L35_001DE994, D_L35_001DE998, (f32)*(s32 *)(v + 0x90) / (f32)D_L35_001DE9A0);
        func_L30_0034C8A8(D_L35_001E1D60, a0);
        if (func_0038CAD0(v + 0x90) != 0) {
            func_L01_004450F0(a0, 2, -1);
        }
    }
    if (a0[0x20] != 4) {
        func_L01_0044ABD0(a0, v + 0x70);
    }
    t = (u8 *)func_L01_00447490(a0, 0x10000, 0);
    if (t == 0) {
        return;
    }
    a0[0xA8] = 0xFF;
    if (!(0.0f < *(f32 *)(t + 0x2C))) {
        return;
    }
    if (*(s32 *)(v + 0x9C) > 0) {
        return;
    }
    p = *(u8 **)(t + 0x20);
    if (p != 0) {
        g = D_001A4BE0;
        if (*(s16 *)(p + 0xAA) == *(s16 *)(*(u8 **)(g + 0x25C0) + 0xAA)) {
            if (*(u8 **)(g + 0x35C) == a0) {
                return;
            }
            if (!(*(f32 *)(g + 0x88) < *(f32 *)(a0 + 0x18))) {
                return;
            }
        }
    }
    v[0x77] = 0xFF;
    func_003C4A40(a0, v + 0x70);
    *(f32 *)(D_L35_001E1D60 + 4) = D_L35_001DE98C;
    func_L35_003A2C40(a0, t);
    *(s32 *)(v + 0x9C) = 12;
    *(f32 *)(v + 0x94) -= *(f32 *)(t + 0x2C);
    if (*(f32 *)(v + 0x94) <= 0.0f) {
        func_L01_004450F0(a0, 2, -1);
        return;
    }
    if (*(s32 *)(v + 0x98) != 0) {
        return;
    }
    func_L01_004AAC98(0, 0, (s32)a0, 0x1D64);
    if (*(f32 *)(v + 0x94) == 2.0f) {
        func_L01_00445F40(a0, 0x1D65);
    } else if (*(f32 *)(v + 0x94) == 1.0f) {
        func_L01_00445F40(a0, 0x1D66);
    }
}
/* localdecomp:end func_L35_003A3500 */

/* localdecomp:start func_L35_003A3758 */
extern s32 D_L35_001DE9A0;
extern f32 D_L35_001DE9BC;
extern f32 D_L35_001DE9B4;
extern u8 *D_L35_001DF89C;
extern s32 D_L35_001DE9B0;
extern s32 D_L35_001DE978;
extern s32 D_L35_001DE97C;
extern f32 D_L35_001DE998;
extern s32 D_L35_001DE99C;
extern u8 D_L35_001E1D60[] __attribute__((section(".sdata")));
__asm__(".extern D_L35_001DE9A0, 4");
__asm__(".extern D_L35_001DE9BC, 4");
__asm__(".extern D_L35_001DE9B4, 4");
__asm__(".extern D_L35_001DE9B0, 4");
__asm__(".extern D_L35_001DE978, 4");
__asm__(".extern D_L35_001DE97C, 4");
__asm__(".extern D_L35_001DE998, 4");
__asm__(".extern D_L35_001DE99C, 4");

extern void func_L01_00445F40(void *, s32);
extern s32 func_00382498(s32, s32);
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern void func_L35_003A3240();

void func_L35_003A3758(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 idx;

    *(s32 *)(v + 0x90) = D_L35_001DE9A0;
    if (*(s32 *)(v + 0x98) == 0) {
        *(f32 *)(v + 0x94) = D_L35_001DE9BC;
        func_L01_00445F40(a0, 0x1D64);
    } else {
        *(f32 *)(v + 0x94) = D_L35_001DE9B4;
        func_L01_00445F40(a0, func_00382498(0x1D67, 0x1D68));
    }
    idx = *(s32 *)(v + 0xA0);
    if (idx != -1) {
        *(u8 **)(v + 0xA4) = D_L35_001DF89C + idx * 0x100;
    } else {
        *(u8 **)(v + 0xA4) = 0;
    }
    if (D_L35_001DE9B0 == 0) {
        D_L35_001DE9B0 = 1;
        func_L03_0034B218(D_L35_001E1D60, D_L35_001DE978, D_L35_001DE97C, D_L35_001DE998, D_L35_001DE99C, func_L35_003A3240);
    }
}
/* localdecomp:end func_L35_003A3758 */

/* localdecomp:start func_L35_003A3828 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003A3828;
typedef struct {
    u8 pad0[0x10];
    V_003A3828 pos;
    u8 b20;
    u8 pad21[0x89];
    u16 hAA;
} M_003A3828;
extern f32 D_L35_001DE9A4;
__asm__(".extern D_L35_001DE9A4, 4");
extern M_003A3828 *D_L35_001E92D8 __attribute__((section(".data")));
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

void func_L35_003A3828(M_003A3828 *m) {
    V_003A3828 v;
    M_003A3828 *t;

    v = m->pos;
    v.x += D_L35_001DE9A4 + D_L35_001DE9A4;
    if (func_003D3CB0(&m->pos, &v, 2, m, 0) != 0) {
        t = D_L35_001E92D8;
        if (t != 0 && (u16)(t->hAA - 0x1D64) < 3 && t->b20 == 1) {
            func_L01_004450F0((u8 *)t, 2, -1);
        }
    }
    v = m->pos;
    v.x -= D_L35_001DE9A4 + D_L35_001DE9A4;
    if (func_003D3CB0(&m->pos, &v, 2, m, 0) != 0) {
        t = D_L35_001E92D8;
        if (t != 0 && (u16)(t->hAA - 0x1D64) < 3 && t->b20 == 1) {
            func_L01_004450F0((u8 *)t, 2, -1);
        }
    }
    v = m->pos;
    v.z += D_L35_001DE9A4 + D_L35_001DE9A4;
    if (func_003D3CB0(&m->pos, &v, 2, m, 0) != 0) {
        t = D_L35_001E92D8;
        if (t != 0 && (u16)(t->hAA - 0x1D64) < 3 && t->b20 == 1) {
            func_L01_004450F0((u8 *)t, 2, -1);
        }
    }
    v = m->pos;
    v.z -= D_L35_001DE9A4 + D_L35_001DE9A4;
    if (func_003D3CB0(&m->pos, &v, 2, m, 0) != 0) {
        t = D_L35_001E92D8;
        if (t != 0 && (u16)(t->hAA - 0x1D64) < 3 && t->b20 == 1) {
            func_L01_004450F0((u8 *)t, 2, -1);
        }
    }
}
/* localdecomp:end func_L35_003A3828 */

/* localdecomp:start func_L35_003A3A28 */
extern f32 D_L35_001DEA00;
extern f32 D_L35_001DE9FC;
extern f32 D_L35_001DEA70;
extern f32 D_L35_001DEA6C;
__asm__(".extern D_L35_001DEA00, 4");
__asm__(".extern D_L35_001DE9FC, 4");
__asm__(".extern D_L35_001DEA70, 4");
__asm__(".extern D_L35_001DEA6C, 4");
extern u8 D_L35_001D66B0[8];
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern void func_L35_003A48F0(u8 *);
extern void func_L35_003A4A88(u8 *);
extern void func_L35_003A3FC8(u8 *);
extern void func_L35_003A3D10(u8 *);
extern void func_L35_003A4BD8(u8 *);
extern void func_L35_003A4180(u8 *, s32);
extern void func_L35_003A42F8(u8 *);
extern void func_L35_003A45A0(u8 *);
extern void func_L35_003A4D00(u8 *);
extern void func_L35_003A3E40(u8 *);

void func_L35_003A3A28(u8 *a0) {
    u8 *s2 = *(u8 **)(a0 + 0x68);
    f32 tmp[4] __attribute__((aligned(16)));
    f32 pos[4] __attribute__((aligned(16)));
    s32 i;

    switch (a0[0x20]) {
    case 0x42:
        if (func_L01_004561B8(a0) == 0) {
            break;
        }
        *(s32 *)(a0 + 0x98) = 0;
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(a0, 1);
        func_003A52A0(1, 0, a0);
        func_003C2F58(a0, 1, pos);
        func_L01_003303B8((u8 *)pos, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, D_L35_001DEA00, 0.0f, 0.0f, 2.0f,
                          1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                          0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_0038CF68(tmp, s2 + 0xE0, D_L35_001DE9FC);
        func_L01_00451FE0(a0, 0xFF, D_L35_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        break;
    case 1:
        func_L35_003A48F0(a0);
        break;
    case 2:
        func_L35_003A4A88(a0);
        break;
    case 0:
        func_L35_003A3FC8(a0);
        func_L35_003A3D10(a0);
        func_L35_003A4180(a0, 2);
        break;
    case 3:
        func_L35_003A4BD8(a0);
        break;
    case 4:
        if (a0[0x60] & 2) {
            i = *(s32 *)(s2 + 0x180);
            if (i >= 0 && *(s32 *)(s2 + (i << 5) + 0x11C) != 2) {
                func_L35_003A4180(a0, 6);
            } else {
                func_L35_003A4180(a0, 7);
            }
        }
        break;
    case 5:
        if (a0[0x60] & 2) {
            func_L35_003A4180(a0, 2);
        }
        break;
    case 6:
        func_L35_003A42F8(a0);
        break;
    case 7:
        func_L35_003A45A0(a0);
        break;
    case 8:
        func_L35_003A4D00(a0);
        break;
    }
    func_L35_003A3E40(a0);
    func_L01_0044E850(a0, s2 + 0x50, 2, D_L35_001DEA70, D_L35_001DEA6C);
}
/* localdecomp:end func_L35_003A3A28 */
