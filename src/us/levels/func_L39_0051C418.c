#include "common.h"

/* NTSC-U counterpart of func_L39_0051C768 (src/levels/shared/L39_0051C768.c) */
/* localdecomp:start func_L39_0051C418 */
#include "vu0.h"
typedef int Q_0051C768 __attribute__((mode(TI)));
typedef struct { s32 a; f32 b; s32 c; } T_0051C768;
typedef struct {
    f32 x, y, z, w;
    void *f10;
    s32 f14;
    u8 f18;
    u8 f19;
    u16 f1A;
    f32 f1C;
    s32 f20;
    s32 pad24;
    s32 f28;
    s32 pad2C;
} __attribute__((aligned(16))) C_0051C768;
extern T_0051C768 D_L39_0024A960_0051C418;
extern f32 D_L39_0024A958;
__asm__(".extern D_L39_0024A958, 4");
extern u8 *D_L39_0024CF1C;
extern Q_0051C768 D_L39_0025F860;
extern u8 D_L39_0024DF40[];
extern void func_00388880(void *, void *, f32);
extern s32 func_00388398(void *);
extern void func_L39_005FD658(s32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern void func_L39_005FD6D8(void);
extern s32 func_003D00C0(void);
extern void func_003CF790(void *, s32, void *, void *, f32);
extern s32 func_L01_0032FE90_0051C418(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L39_0051C918(u8 *, s32);
extern void func_003BD360(void *);
extern f32 func_00389380(f32, f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_L39_005B2568(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_L39_005B2498(s32);
extern void func_00388758(void *, void *, void *);
extern void func_00389158(void *, void *, void *, f32);
extern f32 func_00388770(void *);
extern f32 func_L39_005B2510(f32, f32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_L39_005C7680(void *, void *, s32, s32, f32);

/* from rac2-decomp's func_PAL_L04_003FD8F0 */
void func_L39_0051C418(u8 *m) {
    vu0_v4 old;
    T_0051C768 t;
    C_0051C768 c;
    vu0_v4 diff;
    vu0_v4 cur;
    vu0_v4 v1;
    vu0_v4 v2;
    u8 *pos;
    vu0_v4 *po;
    u8 *s;
    u8 *o;
    s32 r;
    s32 i;
    void *owner;
    s32 d;
    f32 f;
    f32 len;

    pos = m + 0x10;
    po = &old;
    s = *(u8 **)(m + 0x68);
    t = D_L39_0024A960_0051C418;
    *(Q_0051C768 *)po = *(Q_0051C768 *)pos;
    vec_add_ab(pos, pos, s);
    if (*(f32 *)(pos) < 0.0f || *(f32 *)(m + 0x14) < 0.0f || *(f32 *)(m + 0x18) < 0.0f) {
        func_L39_0051C918(m, 0);
        func_003BD360(m);
        return;
    }
    c.f10 = *(void **)(s + 0x18);
    c.f1C = D_L39_0024A958;
    c.f14 = 0x10001;
    c.f20 = 1;
    *(Q_0051C768 *)&c = *(Q_0051C768 *)s;
    func_00388880(&c, &c, 1.0f);
    c.z = 1.0f;
    c.w = 5627.9248f;
    c.f18 = 1;
    c.f19 = 1;
    c.f1A = *(u16 *)(m + 0xAA);
    c.f28 = *(s32 *)(s + 0x60);
    if (func_00388398(s + 0x10)) {
        func_L39_0051C918(m, 0);
        func_003BD360(m);
        return;
    }
    owner = *(void **)(s + 0x18);
    func_L39_005FD658(D_L39_0024CF1C ? *(s32 *)(D_L39_0024CF1C + 0x2548) : -1);
    r = func_003CE740(po, pos, 0, owner, &c);
    func_L39_005FD6D8();
    if (r != 0) {
        if (func_003D00C0()) {
            *(Q_0051C768 *)(pos) = D_L39_0025F860;
            c.f1C = D_L39_0024A958 * 0.5f;
            func_003CF790(pos, 0, *(void **)(s + 0x18), &c, 2.0f);
            func_L01_0032FE90_0051C418(pos, 0, 2, 3, 2, 4, 0, 0, 0.4f, 0.0f, 0.0f, 2.0f,
                0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L39_0051C918(m, 0);
            func_003BD360(m);
            return;
        }
        if (*(s32 *)(s + 0x10) > 3) {
            *(s32 *)(s + 0x10) = 3;
        }
    }
    *(f32 *)(m + 0xF4) = func_00389380(*(f32 *)(m + 0xF4), t.b);
    d = *(s32 *)(s + 0x14) - *(s32 *)(s + 0x10);
    if (d < 13) {
        f = (f32)d / 13.0f * 0.15f;
    } else {
        f = 0.15f;
    }
    vec_sub_ab(&diff, &old, m + 0x10);
    func_00388830(&diff, &diff, f);
    *(Q_0051C768 *)&cur = *(Q_0051C768 *)(m + 0x10);
    if (*(u8 **)(s + 0x1C)) {
        *(Q_0051C768 *)(*(u8 **)(s + 0x1C) + 0x10) = *(Q_0051C768 *)&cur;
    }
    for (i = 0; i < 16; i++) {
        o = ((u8 **)(s + 0x20))[i];
        if (o) {
            vec_add_ab(o + 0x10, &cur, &diff);
            *(Q_0051C768 *)&cur = *(Q_0051C768 *)(o + 0x10);
            *(f32 *)(o + 0x10) += func_L39_005B2568(0.0f, 0.125f);
            *(f32 *)(o + 0x14) += func_L39_005B2568(0.0f, 0.125f);
            *(f32 *)(o + 0x18) += func_L39_005B2568(0.0f, 0.125f);
            func_003886E8(&diff, &diff, 1.05f);
        }
    }
    if (func_L39_005B2498(5) == 0) {
        func_00388758(&v1, &diff, D_L39_0024DF40);
        func_00389158(&v1, &v1, &diff, func_L39_005B2568(0.0f, 3.1415927f));
        len = func_00388770(&v1);
        if (len != 0.0f) {
            func_003886E8(&v2, &v1, func_L39_005B2510(0.008333334f, 0.033333335f) / len);
            func_L39_005C7680(m + 0x10, &v2, 0x7F2F4F6F, func_L39_005B24C8(10, 15), 70000.0f);
        }
    }
}
/* localdecomp:end func_L39_0051C418 */
