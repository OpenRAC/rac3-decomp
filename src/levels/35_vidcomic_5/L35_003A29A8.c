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

INCLUDE_ASM("asm/levels", func_L35_003A3500);

INCLUDE_ASM("asm/levels", func_L35_003A3758);

INCLUDE_ASM("asm/levels", func_L35_003A3828);

INCLUDE_ASM("asm/levels", func_L35_003A3A28);

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

INCLUDE_ASM("asm/levels", func_L35_003A48F0);

INCLUDE_ASM("asm/levels", func_L35_003A4A88);

INCLUDE_ASM("asm/levels", func_L35_003A4BD8);

INCLUDE_ASM("asm/levels", func_L35_003A4D00);

INCLUDE_ASM("asm/levels", func_L35_003A4EA8);

INCLUDE_ASM("asm/levels", func_L35_003A5100);

INCLUDE_ASM("asm/levels", func_L35_003A5238);
