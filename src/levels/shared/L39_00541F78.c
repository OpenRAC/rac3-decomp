#include "common.h"

/* localdecomp:start func_L39_00541F78 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00541F78;
typedef struct { u8 p0[0x14]; s32 x14; u8 x18; u8 x19; u16 x1A; u8 p1C[0xC]; s32 x28; u8 p2C[0x4]; } S_00541F78;
typedef struct { V_00541F78 v; s32 x10; f32 x14; u8 p18[0xC]; s32 x24; s32 x28; s32 x2C; s32 x30; u8 p34[4]; f32 x38; f32 x3C; } M_00541F78;
typedef struct { u8 p0[0x10]; V_00541F78 pos; u8 b20; u8 p21[0x89]; u16 xAA; u8 pAC[0x14]; u8 xC0[0x10]; u8 xD0[0x10]; u8 xE0[0x10]; } O_00541F78;
typedef struct { u8 p0[0x18]; s32 x18; u8 p1C[4]; u8 x20[0x10]; } G_00541F78;
extern u8 *D_L39_0024CE1C;
extern G_00541F78 D_L39_0025F740;
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L39_005FFDF8(s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_L39_005FFE78(void);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2880(void *);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_L01_00404A10(void *, void *);
extern void func_L04_00354AE8(f32, void *, u32, u32, u32, u32, u32);
extern void func_L04_00355678(void);

void func_L39_00541F78(O_00541F78 *o) {
    M_00541F78 *m = *(M_00541F78 **)((u8 *)o + 0x68);
    u8 *tgt = (u8 *)o;
    V_00541F78 v0; S_00541F78 s; V_00541F78 v40; S_00541F78 s2;
    s32 hit, a;
    void *p;

    if ((u32)m->x30 != 0xFFFFFFFF) {
        tgt = (u8 *)m->x10;
    }
    m->x24 = m->x24 + 1;
    if (m->x24 >= 0x3A) {
        func_003C2880(o);
        return;
    }
    switch (o->b20) {
    case 0:
        m->x38 = m->x38 + m->x3C;
        vec_add_ba(&v0, &o->pos, m);
        func_L01_00446760(&s, o, m->x2C, m, m->x14);
        s.x1A = o->xAA;
        s.x28 = m->x30;
        s.x18 = 0;
        s.x19 = 1;
        a = -1; if (D_L39_0024CE1C != 0) { a = *(s32 *)(D_L39_0024CE1C + 0x2548); }
        func_L39_005FFDF8(a);
        hit = func_003D3CB0(&o->pos, &v0, 0, tgt, &s);
        func_L39_005FFE78();
        if (hit != 0) {
            if (D_L39_0025F740.x18 != 0) {
                if (D_L39_0025F740.x18 != m->x10) {
                    v40 = m->v;
                    func_0038CE20(&v40, &v40, 2.0f);
                    tgt = D_L39_0025F740.x20;
                    v40.w = 5627.9248f;
                    func_L01_00446760(&s2, o, m->x2C, &v40, m->x14);
                    s2.x19 = 1;
                    s2.x1A = o->xAA;
                    s2.x14 = 0x10001;
                    s2.x18 = 0;
                    s2.x28 = m->x30;
                    a = -1; if (D_L39_0024CE1C != 0) { a = *(s32 *)(D_L39_0024CE1C + 0x2548); }
                    func_L39_005FFDF8(a);
                    func_003D4D00(tgt, 0, o, &s2, 1.0f);
                    func_L39_005FFE78();
                    func_L01_004450F0(o, 1, -1);
                    return;
                }
            } else {
                v40 = m->v;
                func_0038CE20(&v40, &v40, 3.0f);
                p = D_L39_0025F740.x20;
                v40.w = 5627.9248f;
                func_L01_00446760(&s2, o, m->x2C, &v40, m->x14);
                s2.x19 = 1;
                s2.x1A = o->xAA;
                s2.x18 = 0;
                s2.x28 = m->x30;
                a = -1; if (D_L39_0024CE1C != 0) { a = *(s32 *)(D_L39_0024CE1C + 0x2548); }
                func_L39_005FFDF8(a);
                func_003D4D00(p, 0, tgt, &s2, 2.0f);
                func_L39_005FFE78();
                func_L01_004450F0(o, 1, -1);
                return;
            }
        }
        o->pos = v0;
        func_0038CE20(&v40, m, -0.5f);
        qzero(&s2);
        break;
    case 1:
        func_L04_00354AE8(5.85f, (u8 *)o + 0x10, 0x803B0612, 0x80DA5615, 0x64FFFFFF, 0x507030FF, 0x320000FF);
        func_003C2880(o);
        return;
    default:
        break;
    }
    func_0038D890(o->xE0, o->xE0, o->xD0, 0.0f);
    func_0038D890(o->xC0, o->xC0, o->xD0, 0.0f);
    func_L01_00404A10(func_L04_00355678, o);
}
/* localdecomp:end func_L39_00541F78 */

/* localdecomp:start func_L39_005422E8 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D308(void *, void *);
extern f32 func_L39_005B4410(f32, f32);
extern u8 *func_L01_0046B458(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind, s32 spin, void *velocity, f32 unk, s32 delay);
extern void func_L39_005F33E0(s32, s32, s32);
extern u8 D_L39_00242930[8];
__asm__(".extern D_L39_0024AE8C, 4");
__asm__(".extern D_L39_0024AE90, 4");
__asm__(".extern D_L39_0024AE94, 4");
__asm__(".extern D_L39_0024AE98, 4");
extern s32 D_L39_0024AE8C;
extern s32 D_L39_0024AE90;
extern s32 D_L39_0024AE94;
extern s32 D_L39_0024AE98;

u8 *func_L39_005422E8(u8 *a0, f32 f, f32 *v, u128_t *a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    u8 *o;
    u8 *r;
    f32 g;
    f32 h;
    s32 n;
    f32 z;
    unsigned long t;

    n = 10;
    o = func_003C24B0(0xEA7, 0x80);
    if (o != 0) {
        o[0x30] = 0xFF;
        *(s16 *)(o + 0x32) = 0xFF;
        o[0x31] = 1;
        o[0x20] = 0;
        r = *(u8 **)(o + 0x68);
        t = *(unsigned long *)(a0 + 0x38);
        *(unsigned long *)(o + 0x38) = t;
        *(u128_t *)(o + 0x10) = *a2;
        *(u128_t *)r = *(u128_t *)v;
        *(u8 **)(r + 0x10) = a0;
        *(f32 *)(r + 0x14) = f;
        *(f32 *)(r + 0x20) = 0.15f;
        *(u16 *)(o + 0x34) |= 0x208;
        *(s32 *)(r + 0x2C) = a3;
        *(s32 *)(r + 0x30) = a4;
        r[0x34] = a5;
        h = func_0038CEA8(v) * 0.8f;
        *(f32 *)(r + 0x3C) = h;
        *(f32 *)(r + 0x38) = -h;
        *(f32 *)(o + 0xF8) = func_0038DAB8(func_0038D160(v[0], v[1]), 1.5707964f);
        *(f32 *)(o + 0xF0) = -func_0038D160(func_0038CED8(v), v[2]);
        func_0038D308(o + 0xC0, o + 0xF0);
        *(u16 *)(o + 0x34) |= 0x100;
        o[0x23] = 0x80;
        *(f32 *)(o + 0x2C) = 0.0725f;
        *(s32 *)(r + 0x24) = 0;
        g = func_L39_005B4410(1.5f, 3.0f);
        switch (a6) {
        case 1: {
            s32 x = D_L39_0024AE94;
            s32 y = D_L39_0024AE98;
            *(s32 *)(r + 0x40) = x;
            *(s32 *)(r + 0x44) = y;
            *(s32 *)(r + 0x48) = x;
            break;
        }
        case 0:
        default: {
            s32 c0 = D_L39_0024AE8C;
            s32 c1 = D_L39_0024AE90;
            *(s32 *)(r + 0x40) = c0;
            *(s32 *)(r + 0x44) = c1;
            *(s32 *)(r + 0x48) = 0x80803010;
            break;
        }
        }
        *(s32 *)(r + 0x4C) = a6;
        z = 0.0f;
        func_L01_0046B458(o + 0x10, 12, g * 0.3f, g, *(s32 *)(r + 0x48), 0, n, D_L39_00242930, z, 0);
        func_L01_0046B458(o + 0x10, 12, g * 0.04f, g * 0.4f, -1, 1, -n, D_L39_00242930, z, 0);
        func_L39_005F33E0(0, 0, (s32)o);
    }
    return o;
}
/* localdecomp:end func_L39_005422E8 */
