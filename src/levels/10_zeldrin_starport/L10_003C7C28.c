#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L10_003C7C28 */
__asm__(".extern D_L10_001DE91C, 4");
extern f32 D_L10_001DE91C;
extern u8 D_001A30B0[];
extern u8 D_L10_001D66B0[8];
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern f32 func_0038DB48(f32);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern u8 *func_L01_00452460(void *, s32, s32);
extern void func_003C2880(void *);

void func_L10_003C7C28(u8 *m) {
    s32 *v = *(s32 **)(m + 0x68);
    s32 h;
    u8 *e;

    {
        s32 k = v[0];
        if (k == -1 || *(u8 **)((e = D_001A30B0 + (k << 7)) + 0xDC) != m || e[0xD0] == 0) {
            v[0] = func_003A52A0(1, 4, m);
        }
    }
    *(f32 *)(m + 0xF4) = func_0038DB48(*(f32 *)(m + 0xF4) + D_L10_001DE91C);
    if (func_L01_00447490(m, -1, 0) != 0) {
        h = v[0];
        if (h != -1) {
            e = D_001A30B0 + (h << 7);
            if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                func_003A4F28(h);
            }
        }
        v[0] = -1;
        func_003A52A0(0, 0, m);
        func_L01_00451FE0(m, 0x1F, D_L10_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f,
                          3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        *(s32 *)(m + 0xF0) = 0;
        *(s32 *)(m + 0xF8) = 0;
        func_L01_00452460(m, 0x1EC9, 0);
        func_003C2880(m);
    }
}
/* localdecomp:end func_L10_003C7C28 */

/* localdecomp:start func_L10_003C7DA0 */
__asm__(".extern D_L10_001DE920, 4");
extern f32 D_L10_001DE920;

void func_L10_003C7DA0(u8 *m) {
    s32 *v = *(s32 **)(m + 0x68);
    s32 h;
    u8 *e;

    {
        s32 k = v[0];
        if (k == -1 || *(u8 **)((e = D_001A30B0 + (k << 7)) + 0xDC) != m || e[0xD0] == 0) {
            v[0] = func_003A52A0(1, 4, m);
        }
    }
    *(f32 *)(m + 0xF4) = func_0038DB48(*(f32 *)(m + 0xF4) - D_L10_001DE920);
    if (func_L01_00447490(m, -1, 0) != 0) {
        h = v[0];
        if (h != -1) {
            e = D_001A30B0 + (h << 7);
            if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                func_003A4F28(h);
            }
        }
        v[0] = -1;
        func_003A52A0(0, 0, m);
        func_L01_00451FE0(m, 0x1F, D_L10_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f,
                          3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        *(s32 *)(m + 0xF0) = 0;
        *(s32 *)(m + 0xF8) = 0;
        func_L01_00452460(m, 0x1ECA, 0);
        func_003C2880(m);
    }
}
/* localdecomp:end func_L10_003C7DA0 */

/* localdecomp:start func_L10_003C7F18 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C7F18;
__asm__(".extern D_L10_001DE924, 4");
__asm__(".extern D_L10_001DE928, 4");
__asm__(".extern D_L10_001DE92C, 4");
extern f32 D_L10_001DE924;
extern f32 D_L10_001DE928;
extern f32 D_L10_001DE92C;
extern f32 func_003824E0(f32, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_00382580(void *, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00470668(void *, void *, s32, f32);

void func_L10_003C7F18(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    V4_3C7F18 a;
    V4_3C7F18 p;
    V4_3C7F18 t;
    s32 i;
    f32 f;

    f = func_003824E0(0.7853982f, -0.7853982f);
    func_0038D890(&a, v, m + 0xD0, f);
    p = *(V4_3C7F18 *)(m + 0x10);
    for (i = 0; i < 2; i++) {
        func_00382580(&t, D_L10_001DE924, D_L10_001DE924);
        vec_add_ab(&t, &t, &a);
        func_0038CE20(&t, &t, func_003824E0(D_L10_001DE928 * 0.75f, D_L10_001DE928 * 1.25f) * 0.020000001f);
        func_L01_00470668(&p, &t, 0x32, D_L10_001DE92C * 0.00040000002f);
    }
}
/* localdecomp:end func_L10_003C7F18 */

/* localdecomp:start func_L10_003C8048 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C8048;
__asm__(".extern D_L10_001DE930, 4");
__asm__(".extern D_L10_001DE934, 4");
__asm__(".extern D_L10_001DE938, 4");
extern f32 D_L10_001DE930;
extern s32 D_L10_001DE934;
extern s32 D_L10_001DE938;
extern u8 D_001A4C60[];
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_L01_00451E78(void *, s32, f32);
extern s32 func_00382468(s32);
extern void func_L10_003C7F18(u8 *);
extern f32 func_0038DB48(f32);

void func_L10_003C8048(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    V4_3C8048 d;
    s32 t;
    f32 r;

    switch (m[0x20]) {
    case 0:
        vec_sub_ba(&d, D_001A4C60, m + 0x10);
        if (func_0038CE68(&d, m + 0xE0) > 0.0f) {
            *(V4_3C8048 *)v = *(V4_3C8048 *)(m + 0xE0);
        } else {
            func_0038CE20(v, m + 0xE0, -1.0f);
        }
        t = func_00382498(200, 400);
        *(s32 *)(v + 0x14) = 0;
        *(s32 *)(v + 0x1C) = t;
        *(s32 *)(v + 0x10) = (t * 5 + 2) / 6;
        *(f32 *)(v + 0x18) = func_003824E0(0.68f, 0.72000003f);
        func_L01_004450F0(m, 1, -1);
        break;
    case 1:
        if (func_0038CAD0(v + 0x10) != 0) {
            func_L01_00451E78(m, 1, 0.0f);
            func_L01_004450F0(m, 2, -1);
        }
        if (func_0038CAD0(v + 0x14) != 0) {
            r = (f32)*(s32 *)(v + 0x10) / (f32)((*(s32 *)(v + 0x1C) * 5 + 2) / 6);
            if (*(f32 *)(v + 0x18) < r && func_00382468(D_L10_001DE938) == 0) {
                *(s32 *)(v + 0x14) = (D_L10_001DE934 * 5 + 2) / 6;
                func_L10_003C7F18(m);
            }
            *(f32 *)(m + 0xF4) = func_0038DB48(*(f32 *)(m + 0xF4) + D_L10_001DE930 * r);
        }
        break;
    }
    m[0xA8] = 0xFF;
}
/* localdecomp:end func_L10_003C8048 */

/* localdecomp:start func_L10_003C8238 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C8238;
__asm__(".extern D_L10_001DE93C, 4");
__asm__(".extern D_L10_001DE940, 4");
__asm__(".extern D_L10_001DE944, 4");
extern f32 D_L10_001DE93C;
extern s32 D_L10_001DE940;
extern s32 D_L10_001DE944;

void func_L10_003C8238(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    V4_3C8238 d;
    s32 t;
    f32 r;

    switch (m[0x20]) {
    case 0:
        vec_sub_ba(&d, D_001A4C60, m + 0x10);
        if (func_0038CE68(&d, m + 0xE0) > 0.0f) {
            *(V4_3C8238 *)v = *(V4_3C8238 *)(m + 0xE0);
        } else {
            func_0038CE20(v, m + 0xE0, -1.0f);
        }
        t = func_00382498(200, 400);
        *(s32 *)(v + 0x14) = 0;
        *(s32 *)(v + 0x1C) = t;
        *(s32 *)(v + 0x10) = (t * 5 + 2) / 6;
        *(f32 *)(v + 0x18) = func_003824E0(0.68f, 0.72000003f);
        func_L01_004450F0(m, 1, -1);
        break;
    case 1:
        if (func_0038CAD0(v + 0x10) != 0) {
            func_L01_00451E78(m, 1, 0.0f);
            func_L01_004450F0(m, 2, -1);
        }
        if (func_0038CAD0(v + 0x14) != 0) {
            r = (f32)*(s32 *)(v + 0x10) / (f32)((*(s32 *)(v + 0x1C) * 5 + 2) / 6);
            if (*(f32 *)(v + 0x18) < r && func_00382468(D_L10_001DE944) == 0) {
                *(s32 *)(v + 0x14) = (D_L10_001DE940 * 5 + 2) / 6;
                func_L10_003C7F18(m);
            }
            *(f32 *)(m + 0xF4) = func_0038DB48(*(f32 *)(m + 0xF4) - D_L10_001DE93C * r);
        }
        break;
    }
    m[0xA8] = 0xFF;
}
/* localdecomp:end func_L10_003C8238 */

/* localdecomp:start func_L10_003C8428 */
#include "vu0.h"
typedef int u128_t_3C8428 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C8428;
__asm__(".extern D_L10_001DE948, 4");
__asm__(".extern D_L10_001DE94C, 4");
__asm__(".extern D_L10_001DE950, 4");
__asm__(".extern D_L10_001DE954, 4");
extern f32 D_L10_001DE948;
extern f32 D_L10_001DE94C;
extern f32 D_L10_001DE950;
extern f32 D_L10_001DE954;
extern void func_0038D000(void *, void *, void *);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L10_003C8428(u8 *m) {
    V4_3C8428 p;
    V4_3C8428 a;
    u128_t_3C8428 z;

    if (func_L01_00447490(m, -1, 0) != 0) {
        func_003A52A0(0, 0, m);
        func_L01_00451FE0(m, 7, D_L10_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f,
                          3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        z = 0;
        *(u128_t_3C8428 *)&a = z;
        a.x = D_L10_001DE948;
        a.y = D_L10_001DE94C;
        a.z = D_L10_001DE950;
        p = a;
        func_0038CE20(&p, &p, 6.016847f);
        *(u128_t_3C8428 *)&a = z;
        a.z = -0.14000002f;
        func_L02_003E2E38(m, &p, 0.1f, &a, 0x14, 0, 0, 0.18000001f, *(f32 *)(m + 0x2C) * 9.02527f, 20.0f, 1.0f);
        func_0038CE20(&p, &p, *(f32 *)(m + 0x2C));
        func_0038D000(&p, &p, m + 0xC0);
        vec_add_ab(&p, &p, m + 0x10);
        func_L01_003303B8(&p, 0, 0, 0, 0, 2, 5, 0, D_L10_001DE954 * 6.016847f * *(f32 *)(m + 0x2C), 0.0f, 0.0f, 0.0f, 0, 1, 0, 0, 0, 0, 0x1000000, 0, 0xFFA939, 0xFFD092, 0, 0, 0, 0, 0x7FFFA939, 0x28FFD092, 0, 0);
        func_L01_00451E78(m, 1, 0.0f);
        func_003C2880(m);
    }
}
/* localdecomp:end func_L10_003C8428 */

/* localdecomp:start func_L10_003C8698 */
typedef struct { u8 pad[0x30]; s32 f30; s32 f34; } S_3C8698;
extern s32 D_L10_001D6694;
extern S_3C8698 D_L10_001E5F00;
extern f32 func_0038DAB8(f32, f32);

void func_L10_003C8698(u8 *m) {
    s32 v = D_L10_001D6694;
    u8 *p;

    if (v == 2) {
        if (D_L10_001E5F00.f30 == v && (u32)(D_L10_001E5F00.f34 - 0x114) < 0x19) {
            *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(m + 0xF8), 0.12566371f);
        }
    } else {
        p = *(u8 **)(m + 0x24);
        *(u16 *)(m + 0x34) &= 0xFFBE;
        *(u16 *)(m + 0x34) |= *(u16 *)(p + 0x44) & 0x1000;
        *(s32 *)(m + 0x98) = *(s32 *)(p + 0x10);
    }
}
/* localdecomp:end func_L10_003C8698 */
