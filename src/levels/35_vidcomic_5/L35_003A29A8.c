#include "common.h"
#include "vu0.h"

typedef struct { u8 pad[0x1C]; s32 kind; } Entry_003A42F8;
typedef struct { u8 pad[0x100]; Entry_003A42F8 entries[4]; } State_003A42F8;

typedef struct { u8 pad[0x1C]; s32 mode; } Row;
typedef struct { u8 pad[0x100]; Row rows[4]; } State;

INCLUDE_ASM("asm/levels", func_L35_003A29A8);

/* localdecomp:start func_L35_003A2C40 */
extern u8 D_001A4BE0[];
extern f32 D_L35_001DE9CC;
extern s32 D_L35_001DE9E0;
extern s32 D_L35_001DE9C8;
extern s32 D_L35_001DE9E4;
extern void func_L35_003A29A8(u8 *, u8 *, s32, s32, f32, f32);
extern void func_0038CE20(s32, s32, f32);
__asm__(".extern D_L35_001DE9E0, 4");
__asm__(".extern D_L35_001DE9C8, 4");
__asm__(".extern D_L35_001DE9E4, 4");

void func_L35_003A2C40(u8 *a0, u8 *a1) {
    u8 *s1 = D_001A4BE0;
    u8 *s8 = *(u8 **)(s1 + 0x25C0);
    u8 *s6 = *(u8 **)(a1 + 0x20);
    f32 f20 = D_L35_001DE9CC;
    f32 tmp[4];

    if (*(s16 *)(s6 + 0xAA) != *(s16 *)(s8 + 0xAA)) {
        f20 = f20 * 0.3f;
    }
    func_L35_003A29A8(a0 + 0x10, s8 + ((D_L35_001DE9E0 << 4) + 0xC0), D_L35_001DE9C8, D_L35_001DE9E4, f20, 1.0f);
    func_0038CE20((s32)tmp, (s32)(*(u8 **)(s1 + 0x25C0) + ((D_L35_001DE9E0 << 4) + 0xC0)), -1.0f);
    func_L35_003A29A8(a0 + 0x10, (u8 *)tmp, (s32)((f32)D_L35_001DE9C8 * 0.5f), D_L35_001DE9E4, f20 * 0.5f, 0.6f);
}
/* localdecomp:end func_L35_003A2C40 */

INCLUDE_ASM("asm/levels", func_L35_003A2D30);

INCLUDE_ASM("asm/levels", func_L35_003A3240);

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

INCLUDE_ASM("asm/levels", func_L35_003A3D10);

INCLUDE_ASM("asm/levels", func_L35_003A3E40);

INCLUDE_ASM("asm/levels", func_L35_003A3FC8);

/* localdecomp:start func_L35_003A4180 */
extern void func_L01_004450F0(u8 *moby, s32 a, s32 b);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern f32 D_L35_001DEA30;
extern s32 D_L35_001DEA34;
extern f32 D_L35_001DEA20;
extern s32 D_L35_001DE9F0;
extern f32 D_L35_001DEA14;
extern f32 D_L35_001DEA0C;
__asm__(".extern D_L35_001DEA30, 4");
__asm__(".extern D_L35_001DEA34, 4");
__asm__(".extern D_L35_001DEA20, 4");
__asm__(".extern D_L35_001DE9F0, 4");
__asm__(".extern D_L35_001DEA14, 4");
__asm__(".extern D_L35_001DEA0C, 4");

void func_L35_003A4180(u8 *a0, s32 a1) {
    func_L01_004450F0(a0, a1, -1);
    switch (a0[0x20]) {
    case 1:
        func_003C3A10(a0, 7, (s32)D_L35_001DEA30, D_L35_001DEA34);
        *(f32 *)(a0 + 0x48) = D_L35_001DEA20;
        *(f32 *)(a0 + 0x44) = *(f32 *)(a0 + 0x44) + *(f32 *)(a0 + 0x4C);
        break;
    case 3:
        if (a0[0x43] != 2) {
            func_003C3A10(a0, 2, 0, D_L35_001DE9F0);
        }
        break;
    case 4:
        if (a0[0x43] != 3) {
            func_003C3A10(a0, 3, 0, D_L35_001DE9F0);
        }
        *(f32 *)(a0 + 0x48) = 1.0f;
        break;
    case 5:
        if (a0[0x43] != 6) {
            func_003C3A10(a0, 6, 0, D_L35_001DE9F0);
        }
        *(f32 *)(a0 + 0x48) = 1.0f;
        break;
    case 6:
        if (a0[0x94] != 6) {
            if (a0[0x43] != 5) {
                func_003C3A10(a0, 5, (s32)D_L35_001DEA14, D_L35_001DE9F0);
            }
            *(f32 *)(a0 + 0x48) = D_L35_001DEA0C;
        }
        break;
    case 2:
    case 7:
        if (a0[0x43] != 0) {
            func_003C3A10(a0, 0, 0, D_L35_001DE9F0);
        }
        *(f32 *)(a0 + 0x48) = 1.0f;
        break;
    case 8:
        if (a0[0x43] != 1) {
            func_003C3A10(a0, 1, 0, D_L35_001DE9F0);
        }
        break;
    case 0:
    case 0x42:
        break;
    }
}
/* localdecomp:end func_L35_003A4180 */

/* localdecomp:start func_L35_003A42F8 */
extern void func_L35_003A4180(u8 *, s32);
extern s32 func_L01_004561B8(u8 *);
extern f32 func_L01_004395E0(u8 *);
extern s32 func_0038CAD0(void *);
extern f32 func_0038DB00(f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_003A52A0(s32, s32, void *);
extern s32 func_L35_003A5780(f32 *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L35_003A3D10(u8 *);
extern s32 func_L31_00346798(u8 *, f32, f32, f32);
extern s32 func_L01_00456500(void *, s32);
extern f32 D_L35_001DEA18;
extern f32 D_L35_001DE9E8;
extern f32 D_L35_001DE9EC;
extern f32 D_L35_001DEA08;
extern u8 D_1A4C60[];

/* Size metadata for the file's single-pass assembler; no instructions. */
__asm__(".extern D_L35_001DEA18, 4");
__asm__(".extern D_L35_001DE9E8, 4");
__asm__(".extern D_L35_001DE9EC, 4");
__asm__(".extern D_L35_001DEA08, 4");

void func_L35_003A42F8(u8 *self) {
    u8 *p = *(u8 **)(self + 0x68);
    u8 *entry;
    f32 angle;
    f32 position[4];
    s32 i = *(s32 *)(p + 0x180);
    if (i < 0 || i >= *(s32 *)(p + 0x188)) {
        func_L35_003A4180(self, 5);
        return;
    }
    entry = p + 0x100 + i * 32;
    if (func_L01_004561B8(self))
        *(s32 *)(p + 0xF8) = *(s32 *)(entry + 0x10);
    if (func_L01_004395E0(self) > D_L35_001DEA18)
        *(s32 *)(self + 0x48) = 0;
    if (!func_0038CAD0(p + 0x198)) return;
    if (!func_0038CAD0(p + 0x19C)) {
        f32 a = __builtin_fabsf(func_0038DB00(D_L35_001DE9E8, *(f32 *)(self + 0xF8)));
        s32 closer = a < __builtin_fabsf(func_0038DB00(D_L35_001DE9EC, *(f32 *)(self + 0xF8)));
        angle = 0.7853981852531433f;
        if (closer) angle = 2.356194496154785f;
        if (*(s32 *)(entry + 0x1C) == 1) {
            *(f32 *)(p + 0x190) = func_003C4088(*(f32 *)(entry + 8), *(f32 *)(entry + 12), 1.0f - (f32)*(s32 *)(p + 0x19C) / (f32)((*(s32 *)(entry + 0x18) * 5 + 2) / 6));
        }
        *(f32 *)(p + 0xB0) = func_0038DB00(*(f32 *)(p + 0x190), angle);
        if (func_0038CAD0(p + 0xF8)) {
            func_003C2F58(self, 0, position);
            position[1] = *(f32 *)(D_1A4C60 + 4);
            *(s32 *)(p + 0xF8) = *(s32 *)(entry + 0x10);
            func_003A52A0(0, 0, self);
            func_L35_003A5780(position, *(f32 *)(p + 0x190));
            if (*(s32 *)(entry + 0x1C) == 0)
                *(f32 *)(p + 0x190) = func_003824E0(*(f32 *)(entry + 8), *(f32 *)(entry + 12));
        }
    } else {
        *(s32 *)(p + 0x198) = (*(s32 *)(entry + 0x14) * 5 + 2) / 6;
        func_L35_003A3D10(self);
        if (!func_L31_00346798(self, D_L35_001DE9E8, D_L35_001DE9EC, D_L35_001DEA08)) {
            func_L35_003A4180(self, 8);
            return;
        }
        if (*(s32 *)(p + 0x18C) != -1 && !func_L01_00456500(D_1A4C60, *(s32 *)(p + 0x18C))) {
            func_L35_003A4180(self, 2);
            return;
        }
        if (((State_003A42F8 *)p)->entries[*(s32 *)(p + 0x180)].kind == 2)
            func_L35_003A4180(self, 7);
        else
            func_L35_003A4180(self, 6);
    }
}
/* localdecomp:end func_L35_003A42F8 */

/* localdecomp:start func_L35_003A45A0 */
/* PAL port of the NTSC-U match src/us/levels/func_L35_003A2CA0.c */
#include "vu0.h"
extern f32 D_L35_001DE9E8;
__asm__(".extern D_L35_001DE9E8, 4");
extern f32 D_L35_001DE9EC;
__asm__(".extern D_L35_001DE9EC, 4");
extern s32 D_L35_001DE9F0;
__asm__(".extern D_L35_001DE9F0, 4");
extern s32 D_L35_001DE9F4;
__asm__(".extern D_L35_001DE9F4, 4");
extern f32 D_L35_001DEA08;
__asm__(".extern D_L35_001DEA08, 4");
extern f32 D_L35_001DEA0C;
__asm__(".extern D_L35_001DEA0C, 4");
extern f32 D_L35_001DEA10;
__asm__(".extern D_L35_001DEA10, 4");
extern f32 D_L35_001DEA40;
__asm__(".extern D_L35_001DEA40, 4");
extern f32 D_L35_001DEA4C;
__asm__(".extern D_L35_001DEA4C, 4");
extern f32 D_L35_001DEA58;
__asm__(".extern D_L35_001DEA58, 4");
extern u8 D_001A4C60[];
extern s32 D_L35_001E1D80;
__asm__(".extern D_L35_001E1D80, 16");

extern void func_L35_003A4180(u8 *, s32);
extern s32 func_L01_004561B8(u8 *);
extern f32 func_L01_004395E0(u8 *);
extern s32 func_0038CAD0(void *);
extern f32 func_0038DB00(f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_003A52A0(s32, s32, void *);
extern s32 func_L35_003A5780(f32 *, f32);
extern void func_L35_003A3D10(u8 *);
extern s32 func_L31_00346798(u8 *, f32, f32, f32);
extern s32 func_L01_00456500(void *, s32);
extern s32 func_L01_0044E1B8(u8 *, f32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L30_0034D1E8(u8 *, u8 *, u8 *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);


void func_L35_003A45A0(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *row;
    s32 closer = 1;
    f32 a, b;
    f32 vec[4];

    a = fabs_asm(func_0038DB00(D_L35_001DE9E8, *(f32 *)(obj + 0xF8)));
    b = fabs_asm(func_0038DB00(D_L35_001DE9EC, *(f32 *)(obj + 0xF8)));
    closer = a < b;
    if (func_L01_004561B8(obj)) {
        *(s32 *)(s + 0xF8) = 0;
    }
    if (*(s32 *)(s + 0x180) < 0 || *(s32 *)(s + 0x180) >= *(s32 *)(s + 0x188)) {
        func_L35_003A4180(obj, 5);
        return;
    }
    row = s + 0x100 + *(s32 *)(s + 0x180) * 32;
    if (func_0038CAD0(s + 0x198) && !func_0038CAD0(s + 0x19C)) {
        if (func_0038CAD0(s + 0xF8)) {
            f32 d = func_L01_004395E0(obj);
            *(s32 *)(s + 0xF8) = *(s32 *)(row + 0x10);
            if ((*(long *)(obj + 0x40) & 0xFFFF0000) == 0x4040000 && d < D_L35_001DEA10) {
                func_003C2F58(obj, 0, vec);
                vec[1] = *(f32 *)(D_001A4C60 + 4);
                func_003A52A0(0, 0, obj);
                func_L35_003A5780(vec, closer ? 3.14159274f : 0.0f);
            }
            func_003C3A10(obj, 4, 0, D_L35_001DE9F4);
            *(f32 *)(obj + 0x48) = D_L35_001DEA0C;
        }
        if ((*(long *)(obj + 0x40) & 0xFFFF0000) == 0x4040000) {
            if (func_L01_0044E1B8(obj, D_L35_001DEA10)) {
                func_003C2F58(obj, 0, vec);
                vec[1] = *(f32 *)(D_001A4C60 + 4);
                func_003A52A0(0, 0, obj);
                func_L35_003A5780(vec, closer ? 3.14159274f : 0.0f);
            }
        }
    } else if (*(long *)(s + 0x198) == 0) {
        *(s32 *)(s + 0x198) = (*(s32 *)(row + 0x14) * 5 + 2) / 6;
        func_L35_003A3D10(obj);
        if (!func_L31_00346798(obj, D_L35_001DE9E8, D_L35_001DE9EC, D_L35_001DEA08)) {
            func_L35_003A4180(obj, 8);
        } else if (*(s32 *)(s + 0x18C) != -1 && !func_L01_00456500(D_001A4C60, *(s32 *)(s + 0x18C))) {
            func_L35_003A4180(obj, 2);
        } else if (((State *)s)->rows[*(s32 *)(s + 0x180)].mode == 2) {
            func_L35_003A4180(obj, 7);
        } else {
            func_L35_003A4180(obj, 6);
        }
    }
    if (obj[0x60] & 2) {
        if (obj[0x43] != 0) {
            func_003C3A10(obj, 0, 0, D_L35_001DE9F0);
        }
        *(f32 *)(obj + 0x48) = D_L35_001DEA0C;
    }
    func_L30_0034D1E8(obj, obj + 0x10, s + 0xE0, &D_L35_001E1D80, D_L35_001DEA40, D_L35_001DEA40, D_L35_001DEA4C, 0.0f, 0.0f,
                      D_L35_001DEA58, 1, 1, 1, 0);
}
/* localdecomp:end func_L35_003A45A0 */

/* localdecomp:start func_L35_003A48F0 */
#include "vu0.h"
extern s32 func_L01_004561B8(u8 *);
extern s32 func_L31_00346798(void *, f32, f32, f32);
extern f32 func_L01_004395E0(void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038DB00(f32, f32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L35_003A4180(u8 *, s32);
extern u8 D_L35_001E1D80[] __attribute__((section(".sdata")));
__asm__(".extern D_L35_001E1D80, 16");
extern f32 D_L35_001DE9E8;
extern f32 D_L35_001DE9EC;
extern f32 D_L35_001DE9F8;
extern f32 D_L35_001DEA08;
extern f32 D_L35_001DEA24;
extern f32 D_L35_001DEA28;
extern f32 D_L35_001DEA40;
extern f32 D_L35_001DEA4C;
__asm__(".extern D_L35_001DE9E8, 4");
__asm__(".extern D_L35_001DE9EC, 4");
__asm__(".extern D_L35_001DE9F8, 4");
__asm__(".extern D_L35_001DEA08, 4");
__asm__(".extern D_L35_001DEA24, 4");
__asm__(".extern D_L35_001DEA28, 4");
__asm__(".extern D_L35_001DEA40, 4");
__asm__(".extern D_L35_001DEA4C, 4");

void func_L35_003A48F0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    f32 f;

    if (func_L01_004561B8(a0) != 0) {
        func_L30_0034D1E8(a0, a0 + 0x10, v + 0xE0, D_L35_001E1D80, D_L35_001DEA40, D_L35_001DEA40, D_L35_001DEA4C,
                          0.0f, 0.0f, D_L35_001DEA28, 1, 1, 1, 0);
    }
    func_L30_0034D1E8(a0, a0 + 0x10, v + 0xE0, D_L35_001E1D80, D_L35_001DEA40, D_L35_001DEA40, D_L35_001DEA4C,
                      0.0f, 0.0f, D_L35_001DEA28, 1, 1, 1, 0);
    f = func_L01_004395E0(a0);
    if (!(a0[0x60] & 2) && !(D_L35_001DEA24 < f)) {
        return;
    }
    if (func_0038CF00(v + 0xD0, a0 + 0x10) < D_L35_001DE9F8) {
        if (func_L31_00346798(a0, D_L35_001DE9E8, D_L35_001DE9EC, D_L35_001DEA08) != 0) {
            func_L35_003A4180(a0, 2);
        } else {
            func_L35_003A4180(a0, 8);
        }
    } else {
        if (fabs_asm(func_0038DB00(*(f32 *)(a0 + 0x10) < *(f32 *)(v + 0xD0) ? D_L35_001DE9EC : D_L35_001DE9E8,
                                   *(f32 *)(a0 + 0xF8))) <= D_L35_001DEA08) {
            func_L35_003A4180(a0, 3);
        } else {
            func_L35_003A4180(a0, 8);
        }
    }
}
/* localdecomp:end func_L35_003A48F0 */

/* localdecomp:start func_L35_003A4A88 */
extern s32 func_L01_004561B8(u8 *);
extern s32 func_L31_00346798(void *, f32, f32, f32);
extern s32 func_0038CAD0(void *);
extern s32 func_L30_0034D8D8(void *, f32);
extern s32 func_L01_00456500(void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L35_003A4180(u8 *, s32);
typedef int Q_003A4A88 __attribute__((mode(TI)));
extern Q_003A4A88 D_001A4C60;
extern u8 D_L35_001E1D80[] __attribute__((section(".sdata")));
__asm__(".extern D_L35_001E1D80, 16");
extern f32 D_L35_001DE9E8;
extern f32 D_L35_001DE9EC;
extern f32 D_L35_001DEA08;
extern f32 D_L35_001DEA50;
extern s32 D_L35_001DE9F0;
extern f32 D_L35_001DEA40;
extern f32 D_L35_001DEA4C;
extern f32 D_L35_001DEA58;
__asm__(".extern D_L35_001DE9E8, 4");
__asm__(".extern D_L35_001DE9EC, 4");
__asm__(".extern D_L35_001DEA08, 4");
__asm__(".extern D_L35_001DEA50, 4");
__asm__(".extern D_L35_001DE9F0, 4");
__asm__(".extern D_L35_001DEA40, 4");
__asm__(".extern D_L35_001DEA4C, 4");
__asm__(".extern D_L35_001DEA58, 4");

void func_L35_003A4A88(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);

    func_L01_004561B8(a0);
    if (func_L31_00346798(a0, D_L35_001DE9E8, D_L35_001DE9EC, D_L35_001DEA08) == 0) {
        func_L35_003A4180(a0, 8);
        return;
    }
    if (func_0038CAD0(v + 0x198) != 0 && func_L30_0034D8D8(a0 + 0x10, D_L35_001DEA50) != 0) {
        if (*(s32 *)(v + 0x18C) == -1 || func_L01_00456500(&D_001A4C60, *(s32 *)(v + 0x18C)) != 0) {
            func_L35_003A4180(a0, 4);
            return;
        }
    }
    if (*(s32 *)(v + 0x194) != 0) {
        *(s32 *)(v + 0x194) = 0;
        if (a0[0x43] != 8) {
            func_003C3A10(a0, 8, 0, D_L35_001DE9F0);
        }
    }
    if ((a0[0x60] & 2) && a0[0x43] != 0) {
        func_003C3A10(a0, 0, 0, D_L35_001DE9F0);
    }
    func_L30_0034D1E8(a0, a0 + 0x10, v + 0xE0, D_L35_001E1D80, D_L35_001DEA40, D_L35_001DEA40, D_L35_001DEA4C,
                      0.0f, 0.0f, D_L35_001DEA58, 1, 1, 1, 0);
}
/* localdecomp:end func_L35_003A4A88 */

/* localdecomp:start func_L35_003A4BD8 */
/* log: first draft 10 diff (la split); D_L35_001E1D80 as .sdata + .extern 16 -> MATCH with divs row 2. */
#include "vu0.h"
extern s32 func_L01_004561B8(u8 *);
extern void func_L31_00346B10(void *, void *, f32, f32, f32, f32, f32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern f32 func_0038CEA8(void *);
extern void func_L35_003A4180(u8 *, s32);
extern u8 D_L35_001E1D80[] __attribute__((section(".sdata")));
__asm__(".extern D_L35_001E1D80, 16");
extern f32 D_L35_001DEA44;
extern f32 D_L35_001DE9F8;
extern f32 D_L35_001DEA48;
extern f32 D_L35_001DEA40;
extern f32 D_L35_001DEA58;
extern f32 D_L35_001DEA4C;
extern f32 D_L35_001DEA3C;
__asm__(".extern D_L35_001DEA44, 4");
__asm__(".extern D_L35_001DE9F8, 4");
__asm__(".extern D_L35_001DEA48, 4");
__asm__(".extern D_L35_001DEA40, 4");
__asm__(".extern D_L35_001DEA58, 4");
__asm__(".extern D_L35_001DEA4C, 4");
__asm__(".extern D_L35_001DEA3C, 4");

void func_L35_003A4BD8(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 *p;
    f32 s;

    func_L01_004561B8(a0);
    p = v + 0xE0;
    func_L31_00346B10(a0, p, *(f32 *)(v + 0xD0), D_L35_001DE9F8, D_L35_001DEA48, D_L35_001DEA44, D_L35_001DEA44);
    func_L30_0034D1E8(a0, a0 + 0x10, p, D_L35_001E1D80, D_L35_001DEA40, D_L35_001DEA40, D_L35_001DEA4C,
                      D_L35_001DEA48, 0.0f, D_L35_001DEA58, 1, 1, 1, 0);
    s = D_L35_001DEA3C * func_0038CEA8(p) / D_L35_001DEA48;
    *(f32 *)(a0 + 0x48) = s;
    if (5.0f < s) {
        *(f32 *)(a0 + 0x48) = 5.0f;
    } else if (s < 0.5f) {
        *(f32 *)(a0 + 0x48) = 0.5f;
    }
    if (fabs_asm(*(f32 *)(v + 0xD0) - *(f32 *)(a0 + 0x10)) < D_L35_001DE9F8) {
        func_L35_003A4180(a0, 2);
    }
}
/* localdecomp:end func_L35_003A4BD8 */

/* localdecomp:start func_L35_003A4D00 */
#include "vu0.h"
typedef int Q_003A4D00 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} V_003A4D00;
extern f32 D_L35_001DE9E8;
extern f32 D_L35_001DE9EC;
extern f32 D_L35_001DE9F8;
extern f32 D_L35_001DEA08;
extern f32 D_L35_001DEA3C;
extern f32 D_L35_001DEA48;
extern f32 D_L35_001DEA5C;
extern f32 D_L35_001DEA60;
extern f32 D_L35_001DEA64;
extern f32 D_L35_001DEA68;
extern Q_003A4D00 D_001A4C60;
__asm__(".extern D_L35_001DE9E8, 4");
__asm__(".extern D_L35_001DE9EC, 4");
__asm__(".extern D_L35_001DE9F8, 4");
__asm__(".extern D_L35_001DEA08, 4");
__asm__(".extern D_L35_001DEA3C, 4");
__asm__(".extern D_L35_001DEA48, 4");
__asm__(".extern D_L35_001DEA5C, 4");
__asm__(".extern D_L35_001DEA60, 4");
__asm__(".extern D_L35_001DEA64, 4");
__asm__(".extern D_L35_001DEA68, 4");

extern s32 func_L01_004561B8(u8 *);
extern f32 func_0038DB00(f32, f32);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern void func_L35_003A4180(u8 *, s32);

void func_L35_003A4D00(u8 *m) {
    u8 *vars = *(u8 **)(m + 0x68);
    s32 near = 1;
    f32 ang;
    f32 d;
    union {
        Q_003A4D00 q;
        V_003A4D00 v;
    } t;

    if (!(fabs_asm(*(f32 *)(vars + 0xD0) - *(f32 *)(m + 0x10)) < D_L35_001DE9F8)) {
        near = 0;
    }
    if (func_L01_004561B8(m)) {
        *(s32 *)(vars + 0xE0) = 0;
        *(s32 *)(vars + 0x1A0) = 0;
    }
    if (near == 0) {
        t.q = *(Q_003A4D00 *)(vars + 0xD0);
    } else {
        t.q = D_001A4C60;
    }
    if (*(f32 *)(m + 0x10) < t.v.x) {
        ang = D_L35_001DE9EC;
    } else {
        ang = D_L35_001DE9E8;
    }
    d = func_0038DB00(ang, *(f32 *)(m + 0xF8));
    if (fabs_asm(d) <= D_L35_001DEA08) {
        if (near) {
            func_L35_003A4180(m, 2);
        } else {
            func_L35_003A4180(m, 3);
        }
        return;
    }
    func_L01_00448890(m + 0xF8, vars + 0x1A0, ang == D_L35_001DE9E8 ? -1 : 1, ang, D_L35_001DEA5C, D_L35_001DEA5C, D_L35_001DEA64);
    if (D_L35_001DEA68 < d) {
        d = D_L35_001DEA68;
    } else if (d < -D_L35_001DEA68) {
        d = -D_L35_001DEA68;
    }
    *(f32 *)(m + 0x48) = func_003C4088(D_L35_001DEA3C * func_0038CEA8(vars + 0xE0) / D_L35_001DEA48, D_L35_001DEA60, fabs_asm(d) / D_L35_001DEA68);
    func_0038D098(func_0038DB48(d));
}
/* localdecomp:end func_L35_003A4D00 */

INCLUDE_ASM("asm/levels", func_L35_003A4EA8);

INCLUDE_ASM("asm/levels", func_L35_003A5100);

INCLUDE_ASM("asm/levels", func_L35_003A5238);
