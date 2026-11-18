#include "common.h"

/* types of func_L35_003A45A0, from upstream's L35_003A29A8.c */
typedef struct { u8 pad[0x1C]; s32 mode; } Row;
typedef struct { u8 pad[0x100]; Row rows[4]; } State;

/* types of func_L35_003A42F8, from upstream's L35_003A29A8.c */
typedef struct { u8 pad[0x1C]; s32 kind; } Entry_003A42F8;
typedef struct { u8 pad[0x100]; Entry_003A42F8 entries[4]; } State_003A42F8;

/* declared by functions of L35_003A29A8.c, which this file was cut from */
extern void func_L01_004450F0(u8 *moby, s32 a, s32 b);
extern s32 func_0038CAD0(void *);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_L01_004561B8(u8 *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_L35_003A48F0(u8 *a0);
extern void func_L35_003A4A88(u8 *a0);
extern void func_L35_003A3D10(u8 *);
extern void func_L35_003A4BD8(u8 *a0);
extern void func_L35_003A4180(u8 *a0, s32 a1);
extern void func_L35_003A42F8(u8 *self);
extern void func_L35_003A45A0(u8 *obj);
extern void func_L35_003A4D00(u8 *m);

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
extern void func_L35_003A4180(u8 *a0, s32 a1);
extern s32 func_L01_004561B8(u8 *);
extern f32 func_L01_004395E0(u8 *);
extern s32 func_0038CAD0(void *);
extern f32 func_0038DB00(f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_003A52A0(s32, s32, void *);
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

extern void func_L35_003A4180(u8 *a0, s32 a1);
extern s32 func_L01_004561B8(u8 *);
extern f32 func_L01_004395E0(u8 *);
extern s32 func_0038CAD0(void *);
extern f32 func_0038DB00(f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L35_003A5780(f32 *, f32);
extern void func_L35_003A3D10(u8 *);
extern s32 func_L31_00346798(u8 *, f32, f32, f32);
extern s32 func_L01_00456500(void *, s32);
extern s32 func_L01_0044E1B8(u8 *, f32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);


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
extern s32 func_L31_00346798(u8 *, f32, f32, f32);
extern f32 func_L01_004395E0(u8 *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038DB00(f32, f32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L35_003A4180(u8 *a0, s32 a1);
extern f32 D_L35_001DE9E8;
extern f32 D_L35_001DE9EC;
extern f32 D_L35_001DE9F8;
extern f32 D_L35_001DEA08;
extern f32 D_L35_001DEA24;
extern f32 D_L35_001DEA28_003A48F0;
extern f32 D_L35_001DEA40;
extern f32 D_L35_001DEA4C_003A48F0;
__asm__(".extern D_L35_001DE9E8, 4");
__asm__(".extern D_L35_001DE9EC, 4");
__asm__(".extern D_L35_001DE9F8, 4");
__asm__(".extern D_L35_001DEA08, 4");
__asm__(".extern D_L35_001DEA24, 4");
__asm__(".extern D_L35_001DEA28_003A48F0, 4");
__asm__(".extern D_L35_001DEA40, 4");
__asm__(".extern D_L35_001DEA4C_003A48F0, 4");

void func_L35_003A48F0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    f32 f;

    if (func_L01_004561B8(a0) != 0) {
        func_L30_0034D1E8(a0, a0 + 0x10, v + 0xE0, ((u8 *)&D_L35_001E1D80), D_L35_001DEA40, D_L35_001DEA40, D_L35_001DEA4C_003A48F0,
                          0.0f, 0.0f, D_L35_001DEA28_003A48F0, 1, 1, 1, 0);
    }
    func_L30_0034D1E8(a0, a0 + 0x10, v + 0xE0, ((u8 *)&D_L35_001E1D80), D_L35_001DEA40, D_L35_001DEA40, D_L35_001DEA4C_003A48F0,
                      0.0f, 0.0f, D_L35_001DEA28_003A48F0, 1, 1, 1, 0);
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
extern s32 func_L31_00346798(u8 *, f32, f32, f32);
extern s32 func_0038CAD0(void *);
extern s32 func_L30_0034D8D8(void *, f32);
extern s32 func_L01_00456500(void *, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L35_003A4180(u8 *a0, s32 a1);
typedef int Q_003A4A88 __attribute__((mode(TI)));
extern f32 D_L35_001DE9E8;
extern f32 D_L35_001DE9EC;
extern f32 D_L35_001DEA08;
extern f32 D_L35_001DEA50_003A4A88;
extern s32 D_L35_001DE9F0;
extern f32 D_L35_001DEA40;
extern f32 D_L35_001DEA4C_003A4A88;
extern f32 D_L35_001DEA58_003A4A88;
__asm__(".extern D_L35_001DE9E8, 4");
__asm__(".extern D_L35_001DE9EC, 4");
__asm__(".extern D_L35_001DEA08, 4");
__asm__(".extern D_L35_001DEA50_003A4A88, 4");
__asm__(".extern D_L35_001DE9F0, 4");
__asm__(".extern D_L35_001DEA40, 4");
__asm__(".extern D_L35_001DEA4C_003A4A88, 4");
__asm__(".extern D_L35_001DEA58_003A4A88, 4");

void func_L35_003A4A88(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);

    func_L01_004561B8(a0);
    if (func_L31_00346798(a0, D_L35_001DE9E8, D_L35_001DE9EC, D_L35_001DEA08) == 0) {
        func_L35_003A4180(a0, 8);
        return;
    }
    if (func_0038CAD0(v + 0x198) != 0 && func_L30_0034D8D8(a0 + 0x10, D_L35_001DEA50_003A4A88) != 0) {
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
    func_L30_0034D1E8(a0, a0 + 0x10, v + 0xE0, ((u8 *)&D_L35_001E1D80), D_L35_001DEA40, D_L35_001DEA40, D_L35_001DEA4C_003A4A88,
                      0.0f, 0.0f, D_L35_001DEA58_003A4A88, 1, 1, 1, 0);
}
/* localdecomp:end func_L35_003A4A88 */

/* localdecomp:start func_L35_003A4BD8 */
/* log: first draft 10 diff (la split); D_L35_001E1D80 as .sdata + .extern 16 -> MATCH with divs row 2. */
#include "vu0.h"
extern s32 func_L01_004561B8(u8 *);
extern void func_L31_00346B10(void *, void *, f32, f32, f32, f32, f32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern f32 func_0038CEA8(void *);
extern void func_L35_003A4180(u8 *a0, s32 a1);
extern f32 D_L35_001DEA44;
extern f32 D_L35_001DE9F8;
extern f32 D_L35_001DEA48_003A4BD8;
extern f32 D_L35_001DEA40;
extern f32 D_L35_001DEA58_003A4BD8;
extern f32 D_L35_001DEA4C_003A4BD8;
extern f32 D_L35_001DEA3C;
__asm__(".extern D_L35_001DEA44, 4");
__asm__(".extern D_L35_001DE9F8, 4");
__asm__(".extern D_L35_001DEA48_003A4BD8, 4");
__asm__(".extern D_L35_001DEA40, 4");
__asm__(".extern D_L35_001DEA58_003A4BD8, 4");
__asm__(".extern D_L35_001DEA4C_003A4BD8, 4");
__asm__(".extern D_L35_001DEA3C, 4");

void func_L35_003A4BD8(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 *p;
    f32 s;

    func_L01_004561B8(a0);
    p = v + 0xE0;
    func_L31_00346B10(a0, p, *(f32 *)(v + 0xD0), D_L35_001DE9F8, D_L35_001DEA48_003A4BD8, D_L35_001DEA44, D_L35_001DEA44);
    func_L30_0034D1E8(a0, a0 + 0x10, p, ((u8 *)&D_L35_001E1D80), D_L35_001DEA40, D_L35_001DEA40, D_L35_001DEA4C_003A4BD8,
                      D_L35_001DEA48_003A4BD8, 0.0f, D_L35_001DEA58_003A4BD8, 1, 1, 1, 0);
    s = D_L35_001DEA3C * func_0038CEA8(p) / D_L35_001DEA48_003A4BD8;
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
extern f32 D_L35_001DEA48_003A4D00;
extern f32 D_L35_001DEA5C;
extern f32 D_L35_001DEA60;
extern f32 D_L35_001DEA64;
extern f32 D_L35_001DEA68;
__asm__(".extern D_L35_001DE9E8, 4");
__asm__(".extern D_L35_001DE9EC, 4");
__asm__(".extern D_L35_001DE9F8, 4");
__asm__(".extern D_L35_001DEA08, 4");
__asm__(".extern D_L35_001DEA3C, 4");
__asm__(".extern D_L35_001DEA48_003A4D00, 4");
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
extern void func_L35_003A4180(u8 *a0, s32 a1);

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
        t.q = (*(Q_003A4D00 *)&D_001A4C60);
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
    *(f32 *)(m + 0x48) = func_003C4088(D_L35_001DEA3C * func_0038CEA8(vars + 0xE0) / D_L35_001DEA48_003A4D00, D_L35_001DEA60, fabs_asm(d) / D_L35_001DEA68);
    func_0038D098(func_0038DB48(d));
}
/* localdecomp:end func_L35_003A4D00 */
