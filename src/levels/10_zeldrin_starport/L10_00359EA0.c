#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L10_00359EA0);

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
