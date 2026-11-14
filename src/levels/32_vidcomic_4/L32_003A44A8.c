#include "common.h"
#include "vu0.h"

/* declared by functions of L32_003A0BB8.c, which this file was cut from */
void func_L01_004450F0(s32, s32, s32);
s32 func_L01_004561B8(void *);
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern u8 *D_L32_001DFE1C;

/* localdecomp:start func_L32_003A44A8 */
extern u8 *D_L32_002A3E50[];
extern s32 D_L32_001DED30;
extern s32 D_L32_001DED34;
__asm__(".extern D_L32_001DED30, 16");
__asm__(".extern D_L32_001DED34, 16");
extern long func_00389598(s32);
extern void func_003A9440(s32, unsigned long);
extern void func_0038C750(void);
extern void func_L32_003B3A20(u8 *);
extern void func_L32_003B3D88(u8 *);

void func_L32_003A44A8(void) {
    s32 i;
    s32 j;
    u8 **p;

    for (i = 31, p = D_L32_002A3E50; i >= 0; i--, p++) {
        if (*p != 0 && (*p)[0x20] >= 0xFD) {
            *p = 0;
        }
    }
    func_003A9440(6, func_00389598(D_L32_001DED30));
    func_003A9440(8, 0);
    func_003A9440(0x42, 0x8000000044UL);
    func_0038C750();
    for (j = 0; j < 32; j++) {
        if (D_L32_002A3E50[j] != 0) {
            func_L32_003B3A20(D_L32_002A3E50[j]);
        }
    }
    func_003A9440(6, func_00389598(D_L32_001DED34));
    func_003A9440(0x42, 0x8000000048UL);
    for (j = 0; j < 32; j++) {
        if (D_L32_002A3E50[j] != 0) {
            func_L32_003B3D88(D_L32_002A3E50[j]);
        }
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L32_003A44A8 */

INCLUDE_ASM("asm/levels", func_L32_003A45D8);

INCLUDE_ASM("asm/levels", func_L32_003A4F18);

INCLUDE_ASM("asm/levels", func_L32_003A52A8);

INCLUDE_ASM("asm/levels", func_L32_003A5720);

INCLUDE_ASM("asm/levels", func_L32_003A5850);

/* localdecomp:start func_L32_003A5B20 */
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DEA88;
extern f32 D_L32_001DEA50;
extern s32 func_L01_004561B8(void *);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A52A8(void *, s32);

void func_L32_003A5B20(u8 *a0, s32 a1) {
    u8 *s = *(u8 **)(a0 + 0x68);

    if (func_L01_004561B8(a0) != 0) {
        *(s32 *)(s + 0x90) = 0;
    }
    *(s32 *)(s + 0x110) = func_L30_0034D1E8(a0, a0 + 0x10, s + 0x90, s + 0x140, D_L32_001DE9D4, D_L32_001DE9D4, D_L32_001DEA88, 0.0f, 0.0f, D_L32_001DEA50, 1, 1, 1, 0);
    if (a0[0x60] & 2) {
        func_L32_003A52A8(a0, a1);
    }
}
/* localdecomp:end func_L32_003A5B20 */

/* localdecomp:start func_L32_003A5BC0 */
extern s32 D_L32_001DEA58;
extern s32 D_L32_001DE9BC;
extern u8 D_L32_001DEB30[2];
__asm__(".extern D_L32_001DEB30, 2");
extern f32 D_L32_001DEAB0;
__asm__(".extern D_L32_001DEA58, 4");
__asm__(".extern D_L32_001DE9BC, 4");
__asm__(".extern D_L32_001DEAB0, 4");
extern s32 func_L01_004561B8(void *);
extern u8 *func_L32_003C4F70(vu0_q *);
extern s32 func_0038CAD0(void *);
extern void func_L32_003A5850(void *);

void func_L32_003A5BC0(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    vu0_v4 v;
    s32 t;

    if (func_L01_004561B8(arg0) != 0) {
        t = D_L32_001DEA58;
        *(s32 *)(p + 0x128) = D_L32_001DE9BC;
        *(s32 *)(p + 0xA8) = t;
        D_L32_001DEB30[*(s32 *)(p + 0xF8) != 1] = 1;
        v = *(vu0_v4 *)((u8 *)arg0 + 0x10);
        v.x = (*(f32 *)((u8 *)arg0 + 0x10) + *(f32 *)(p + 0x17C)) * 0.5f;
        v.z = *(f32 *)(p + 0x174) + D_L32_001DEAB0;
        *(u8 **)(p + 0x168) = func_L32_003C4F70((vu0_q *)&v);
    }
    if (func_0038CAD0(p + 0xA8) != 0) {
        func_L32_003A5850(arg0);
    }
}
/* localdecomp:end func_L32_003A5BC0 */

/* localdecomp:start func_L32_003A5C78 */
extern f32 D_001DE9D4_sda, D_001DEA88_sda, D_001DEA50_sda;
__asm__(".extern D_001DE9D4_sda, 4");
__asm__(".extern D_001DEA88_sda, 4");
__asm__(".extern D_001DEA50_sda, 4");
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A5850(void *);

void func_L32_003A5C78(u8 *obj) {
    u8 *d = *(u8 **)(obj + 0x68);

    *(s32 *)(d + 0x110) = func_L30_0034D1E8(obj, obj + 0x10, d + 0x90, d + 0x140, D_001DE9D4_sda, D_001DE9D4_sda, D_001DEA88_sda, 0.0f, 0.0f, D_001DEA50_sda, 1, 1, 1, 0);
    if (obj[0x60] & 2) {
        func_L32_003A5850(obj);
    }
}
/* localdecomp:end func_L32_003A5C78 */

INCLUDE_ASM("asm/levels", func_L32_003A5CF8);

INCLUDE_ASM("asm/levels", func_L32_003A5E48);

INCLUDE_ASM("asm/levels", func_L32_003A6168);

INCLUDE_ASM("asm/levels", func_L32_003A6308);

INCLUDE_ASM("asm/levels", func_L32_003A63E0);

/* localdecomp:start func_L32_003A6608 */
extern f32 D_L32_001DE950;
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DEA88;
extern f32 D_L32_001DEA80;
extern f32 D_L32_001DEA50;
__asm__(".extern D_L32_001DE950, 4");
__asm__(".extern D_L32_001DE9D4, 4");
__asm__(".extern D_L32_001DEA88, 4");
__asm__(".extern D_L32_001DEA80, 4");
__asm__(".extern D_L32_001DEA50, 4");
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A52A8(void *, s32);

void func_L32_003A6608(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    f32 v[4] __attribute__((aligned(16)));
    s32 r;

    qzero(v);
    v[2] = D_L32_001DE950;
    r = func_L30_0034D1E8(arg0, (u8 *)arg0 + 0x10, p + 0x90, v, D_L32_001DE9D4, D_L32_001DE9D4,
                          D_L32_001DEA88, D_L32_001DEA80, 0.0f, D_L32_001DEA50, 1, 1, 1, 0);
    *(s32 *)(p + 0x110) = r;
    if (*(f32 *)(p + 0x98) <= 0.0f || r != 0) {
        func_L32_003A52A8(arg0, 9);
    }
}
/* localdecomp:end func_L32_003A6608 */

INCLUDE_ASM("asm/levels", func_L32_003A66B0);

INCLUDE_ASM("asm/levels", func_L32_003A6920);

INCLUDE_ASM("asm/levels", func_L32_003A6D70);

/* localdecomp:start func_L32_003A70A0 */
__asm__(".extern D_L32_001DE8DC, 4");
__asm__(".extern D_L32_001DE8F4, 4");
__asm__(".extern D_L32_001DEA84, 4");
__asm__(".extern D_L32_001DE9D4, 4");
__asm__(".extern D_L32_001DEA88, 4");
__asm__(".extern D_L32_001DEA50, 4");
__asm__(".extern D_L32_001DE8EC, 4");
__asm__(".extern D_L32_001DE93C, 4");
extern f32 D_L32_001DE8DC;
extern f32 D_L32_001DE8F4;
extern f32 D_L32_001DEA84;
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DEA88;
extern f32 D_L32_001DEA50;
extern f32 D_L32_001DE8EC;
extern s32 D_L32_001DE93C;
extern u8 D_001A4C60[];
extern void func_L31_00346B10(void *, void *, f32, f32, f32, f32, f32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A52A8(void *, s32);

void func_L32_003A70A0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 f;
    s32 r;

    func_L31_00346B10(a0, p + 0x90, *(f32 *)D_001A4C60, D_L32_001DE8F4, D_L32_001DEA84, D_L32_001DE8DC, D_L32_001DE8DC);
    r = func_L30_0034D1E8(a0, a0 + 0x10, p + 0x90, p + 0x140, D_L32_001DE9D4, D_L32_001DE9D4,
                                            D_L32_001DEA88, D_L32_001DEA84, 0.0f, D_L32_001DEA50, 1, 1, 1, 0);
    f = D_L32_001DE8EC * fabs_asm(*(f32 *)(p + 0x90)) / D_L32_001DEA84;
    *(s32 *)(p + 0x110) = r;
    *(f32 *)(a0 + 0x48) = f;
    if (f > 5.0f) {
        *(f32 *)(a0 + 0x48) = 5.0f;
    } else if (f < 0.5f) {
        *(f32 *)(a0 + 0x48) = 0.5f;
    }
    if (*(s32 *)(p + 0xFC) == 0 || *(s32 *)(p + 0x12C) == 0) {
        func_L32_003A52A8(a0, 0x12);
    } else if (*(s32 *)(p + 0x134) != 0 && *(s32 *)(p + 0x138) != 0 && *(s32 *)(p + 0xF0) != 0) {
        s32 lim = D_L32_001DE93C;
        if (lim < ++*(s32 *)(p + 0x108)) {
            func_L32_003A52A8(a0, *(s32 *)(p + 0x100) != 0 ? 0x10 : 0xF);
        }
    }
}
/* localdecomp:end func_L32_003A70A0 */

INCLUDE_ASM("asm/levels", func_L32_003A7210);

/* localdecomp:start func_L32_003A77D8 */
__asm__(".extern D_L32_001DE9D4, 4");
__asm__(".extern D_L32_001DEA88, 4");
__asm__(".extern D_L32_001DEA50, 4");
__asm__(".extern D_L32_001DEB3C, 4");
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DEA88;
extern f32 D_L32_001DEA50;
extern f32 D_L32_001DEB3C;
extern s32 D_001A4BE0[];
extern u8 D_00142660[];
extern s32 func_L01_004561B8(void *);
extern void func_L32_003C3F98(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A52A8(void *, s32);
extern void func_L32_003A5850(void *);

void func_L32_003A77D8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 st;

    if (func_L01_004561B8(a0) != 0) {
        st = *(s32 *)(p + 0xF4);
        if (st == -3 && !(D_001A4BE0[0x6CE] & 4)) {
            D_001A4BE0[0x6CE] |= 4; /* byte 0x1B38 */
            D_00142660[0x77] |= 4;
            func_L32_003C3F98(*(s32 *)(p + 0x184), 1);
            func_L32_003C3F98(*(s32 *)(p + 0x184), 6);
        } else if (st == 0 || st == 2) {
            if (func_003824E0(0.0f, 1.0f) < D_L32_001DEB3C) {
                func_L32_003C3F98(*(s32 *)(p + 0x184), func_00382498(0, 1) ? 0 : 2);
            }
        }
    }
    *(s32 *)(p + 0x110) = func_L30_0034D1E8(a0, a0 + 0x10, p + 0x90, p + 0x140, D_L32_001DE9D4, D_L32_001DE9D4,
                                            D_L32_001DEA88, 0.0f, 0.0f, D_L32_001DEA50, 1, 1, 1, 0);
    if (*(s32 *)(p + 0x134) != 0 && *(s32 *)(p + 0x138) != 0 && *(s32 *)(p + 0xF0) != 0) {
        func_L32_003A52A8(a0, *(s32 *)(p + 0x100) != 0 ? 0x10 : 0xF);
    }
    if (a0[0x60] & 2) {
        func_L32_003A5850(a0);
    }
}
/* localdecomp:end func_L32_003A77D8 */

INCLUDE_ASM("asm/levels", func_L32_003A7948);

/* localdecomp:start func_L32_003A7C88 */
__asm__(".extern D_L32_001DEC54, 4");
__asm__(".extern D_L32_001DE980, 4");
__asm__(".extern D_L32_001DE8E0, 4");
extern s32 D_L32_001DEC54;
extern s32 D_L32_001DE980;
extern s32 D_L32_001DE984;
extern s32 D_L32_001DE988;
extern s32 D_L32_001DE8E0;
extern f32 D_L32_001E1AF0;
extern f32 D_L32_001E1AF4;
extern f32 D_L32_001E1AF8;
extern f32 D_L32_001E1AFC;
extern f32 D_L32_001E1B00;
extern f32 D_L32_001E1B04;
extern s32 func_L01_004561B8(void *);
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern void func_L30_004CF4B0(s32, s32);
extern void func_L01_0045F1E8(s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_L32_003A52A8(void *, s32);
extern u8 D_001A4C60[];
extern u8 *D_L32_001DFE1C;

void func_L32_003A7C88(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *e;
    u8 *m;
    f32 a, b, c;
    s32 h;

    if (func_L01_004561B8(a0) != 0) {
        *(s32 *)(p + 0x120) = -1;
    }
    if (func_00382380(D_001A4C60, *(s32 *)(p + 0xD8), 0) != 0) {
        m = *(u8 **)(p + 0x160);
        if (m != 0) {
            m = *(u8 **)(m + 0x68);
            if (m != 0 && *(s32 *)(p + 0xD4) != 0 && *(s32 *)(p + 0xC0) != -1 && *(s32 *)(p + 0xD0) != -1
                && *(s32 *)(p + 0x120) == -1) {
                e = m + 0x4C;
                *(f32 *)(e + (*(s32 *)(p + 0xC0) << 5)) = 1.0f;
                *(s32 *)(e + (*(s32 *)(p + 0xD0) << 5)) = 0;
                D_L32_001DEC54 = 0;
                func_L30_004CF4B0(0x74, 1);
                *(s32 *)(p + 0x11C) = 0;
                if (*(s32 *)(p + 0xC4) != -1) {
                    func_L01_00456230(D_L32_001DFE1C + (*(s32 *)(p + 0xC4) << 8), 1);
                }
                h = *(s32 *)(p + 0x194);
                a = D_L32_001DE980;
                b = D_L32_001DE984;
                c = D_L32_001DE988;
                D_L32_001E1AF4 = a;
                D_L32_001E1AFC = b;
                D_L32_001E1B04 = c;
                D_L32_001E1AF0 = a;
                D_L32_001E1AF8 = b;
                D_L32_001E1B00 = c;
                *(s32 *)(p + 0x120) = D_L32_001DE8E0;
                func_L01_0045F1E8(h, -1);
            }
        }
    }
    if (*(s32 *)(p + 0x120) >= 0) {
        if (func_0038CAD0(p + 0x120) != 0) {
            func_L32_003A52A8(a0, 9);
        }
    }
}
/* localdecomp:end func_L32_003A7C88 */

INCLUDE_ASM("asm/levels", func_L32_003A7E18);

INCLUDE_ASM("asm/levels", func_L32_003A7F48);
