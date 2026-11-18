#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L10_00359EA0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_359EA0;
typedef struct { u8 pad0[0x10]; u8 *f10; } S_359EA0;
__asm__(".extern D_L10_001DD760, 4");
__asm__(".extern D_L10_001DD768, 4");
__asm__(".extern D_L10_001DD76C, 4");
__asm__(".extern D_L10_001DD770, 4");
__asm__(".extern D_L10_001DD774, 4");
__asm__(".extern D_L10_001DD778, 4");
__asm__(".extern D_L10_001DD77C, 4");
__asm__(".extern D_L10_001DD780, 4");
__asm__(".extern D_L10_001DD784, 4");
__asm__(".extern D_L10_001DD788, 4");
__asm__(".extern D_L10_001DD78C, 4");
extern s32 D_L10_001DD760;
extern s32 D_L10_001DD768;
extern s32 D_L10_001DD76C;
extern s32 D_L10_001DD770;
extern s32 D_L10_001DD774;
extern s32 D_L10_001DD778;
extern f32 D_L10_001DD77C;
extern f32 D_L10_001DD780;
extern f32 D_L10_001DD784;
extern f32 D_L10_001DD788;
extern f32 D_L10_001DD78C;
extern S_359EA0 D_L10_0021EB98;
extern void func_00382580(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00470668(void *, void *, s32, f32);

void func_L10_00359EA0(u8 *m, void *pos, void *c, f32 s) {
    V4_359EA0 p;
    V4_359EA0 q;
    s32 t;
    u8 a;
    s32 i;
    s32 col;
    s32 life;
    s32 r;
    f32 s0;
    f32 s1;
    u8 *e;

    {
        s32 *tp = *(s32 **)(m + 0x68);
        p = *(V4_359EA0 *)pos;
        t = *tp;
    }
    if (t < 50) {
        a = (s32)((f32)t * 127.0f / 50.0f);
    } else {
        a = 0x7F;
    }
    for (i = 0; i < D_L10_001DD760; i++) {
        func_00382580(&q, D_L10_001DD784 * s * 0.5f, D_L10_001DD784 * s);
        vec_add_ab(&q, &q, c);
        func_0038CF68(&q, &q, func_003824E0(D_L10_001DD788 * 0.5f * s, D_L10_001DD788 * s) * 0.020000001f);
        if (func_00382468(4) != 0) {
            col = D_L10_001DD778;
        } else {
            col = D_L10_001DD770;
        }
        life = (D_L10_001DD768 * 5 + 2) / 6;
        col |= a << 24;
        r = func_00382498(-2, 2);
        s0 = D_L10_001DD77C * s * 210000.0f;
        s1 = D_L10_001DD780 * s * 210000.0f;
        e = func_L01_00475C60(&p, &q, life, r, col, D_L10_001DD774, 0, s0, s1,
                              func_003824E0(D_L10_001DD78C * 0.3f, D_L10_001DD78C));
        if (e != 0) {
            e[2] = *D_L10_0021EB98.f10;
            e[3] = func_00382468(2) ? 0x48 : 0x44;
        }
    }
    if (func_00382468(6) == 0) {
        func_L01_00470668(&p, &q, (func_00382498(D_L10_001DD76C - 5, D_L10_001DD76C) * 5 + 2) / 6, func_003824E0(40.0f, 80.0f) * 0.00040000002f);
    }
}
/* localdecomp:end func_L10_00359EA0 */

/* localdecomp:start func_L10_0035A158 */
typedef int u128_t_35A158 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_35A158;
__asm__(".extern D_L10_001DD764, 4");
extern s32 D_L10_001DD764;
extern u8 D_001A30B0[];
extern u8 D_L10_001D66B0[8];
extern void func_L10_00359EA0(u8 *, void *, void *, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, s32, s32, s32, f32, f32, s32, f32, f32, f32, f32, f32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_0038CAD0(void *);

void func_L10_0035A158(u8 *m) {
    s32 *v = *(s32 **)(m + 0x68);
    V4_35A158 a;
    V4_35A158 b;
    V4_35A158 c;
    V4_35A158 d;
    V4_35A158 e;
    u128_t_35A158 z;
    f32 s;
    s32 h;
    u8 *q;

    switch (m[0x20]) {
    case 0: {
        s32 t = (D_L10_001DD764 * 5 + 2) / 6;
        v[2] = -1;
        v[0] = t;
        func_L01_004450F0(m, 1, -1);
        break;
    }
    case 1:
        if (func_L01_00447490(m, -1, 0) != 0) {
            func_003A52A0(0, 0, m);
            func_L01_00451FE0(m, 0x7FF, D_L10_001D66B0, 2.0f, 0xFF, 0xB4, 0, 3.5f, 2.0f, 0, 4.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0x23, 0, 3);
            m[0x31] = 0;
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) |= 1;
            func_L01_00451E78(m, 1, 0.0f);
            func_L01_004450F0(m, 2, -1);
        }
        break;
    case 2:
        {
            s32 k = v[2];
            if (k == -1 || *(u8 **)((q = D_001A30B0 + (k << 7)) + 0xDC) != m || q[0xD0] == 0) {
                v[2] = func_003A52A0(1, 4, m);
            }
        }
        z = 0;
        *(u128_t_35A158 *)&a = z;
        *(u128_t_35A158 *)&b = z;
        *(u128_t_35A158 *)&c = z;
        *(u128_t_35A158 *)&d = z;
        a.z = -1.0f;
        b.z = 1.0f;
        c.z = 3.0f;
        d.z = -4.15f;
        s = *(f32 *)(m + 0x2C) / *(f32 *)(*(u8 **)(m + 0x24) + 0x24);
        func_0038CE20(&e, &c, s);
        vec_add_ab(&c, &e, m + 0x10);
        func_0038CE20(&e, &d, s);
        vec_add_ab(&d, &e, m + 0x10);
        func_L10_00359EA0(m, &c, &a, s);
        func_L10_00359EA0(m, &d, &b, s);
        if (func_0038CAD0(v) != 0) {
            func_L01_004450F0(m, 3, -1);
        }
        break;
    case 3:
        h = v[2];
        if (h != -1) {
            q = D_001A30B0 + (h << 7);
            if (*(u8 **)(q + 0xDC) == m && q[0xD0] != 0) {
                func_003A4F28(h);
            }
        }
        v[2] = -1;
        func_003C2880(m);
        return;
    }
    m[0xA8] = 0xFF;
}
/* localdecomp:end func_L10_0035A158 */
