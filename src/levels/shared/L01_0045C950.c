#include "common.h"

/* localdecomp:start func_L01_0045C950 */
extern void func_L01_0045CDA0(u8 *, u8 *);
extern u8 D_L01_001DFC50[];
extern f32 func_0038CF00(void *, void *);
extern f32 func_L01_00450F60(u8 *, u8 *, s32);
extern u8 *func_L01_00448FF0(u8 *);
extern void func_L01_0045B8F0(u8 *, u8 *);
extern void func_003C50E8(u8 *, u8 *, s32);
extern void func_L01_00450E48(u8 *, f32 *, f32, f32, f32);
extern s32 func_L01_0045D158(u8 *, u8 *);
extern void func_L01_00446BC8(u8 *, s32, s32, u8 *, f32);

static __inline__ f32 d_01(u8 *p) {
    return func_0038CF00(p, D_L01_001DFC50);
}

void func_L01_0045C950(u8 *a, u8 *b, u8 *c, s32 d) {
    s32 hit = 0;
    f32 dist;
    f32 t;
    u8 *p;
    u8 *pos;

    func_L01_0045CDA0(a, b);
    dist = d_01(a + 16);
    if (dist < *(f32 *)(b + 144) - *(f32 *)(b + 8)) {
        hit = 1;
        *(s32 *)(b + 148) |= 2;
    }
    if (((*(u8 *)(b + 56) ^ 1) & 1) && *(s16 *)(b + 194) < 5) {
        if (*(f32 *)(b + 144) + *(f32 *)(b + 12) < dist) {
            hit = 1;
            *(s32 *)(b + 148) |= 1;
        }
    }
    if (*(s16 *)(b + 192) != 0) {
        if (func_L01_00450F60(a, b + 80, 0) > *(f32 *)(b + 16)) {
            hit = 1;
            *(s32 *)(b + 148) |= 4;
        }
    }
    if (*(s32 *)(b + 216) != -1 && *(s16 *)(b + 192) != 0) {
        p = func_L01_00448FF0(a);
        if (p != 0 && *(u8 *)(p + 73) != 0 && *(u16 *)(p + 74) != 0 &&
            ((*(u16 *)(p + 74) >> *(s32 *)(b + 216)) & 1)) {
            hit = 1;
            *(s32 *)(b + 148) |= 0x200;
        }
    }
    pos = a + 16;
    if (hit) {
        func_L01_0045B8F0(a, b);
        func_L01_0045CDA0(a, b);
        dist = func_0038CF00(pos, D_L01_001DFC50);
    }
    if (dist <= *(f32 *)(b + 144) + 0.005f) {
        func_003C50E8(a, b + 160, 0);
        if (d != 0) {
            func_L01_00450E48(a, (f32 *)pos, 0.0f, 0.0f, *(f32 *)(b + 144) - dist);
        }
        *(u16 *)(b + 192) += 1;
        *(u16 *)(b + 194) = 0;
    } else if (*(f32 *)(b + 144) + *(f32 *)(b + 12) <= dist) {
        *(u16 *)(b + 192) = 0;
        *(u16 *)(b + 194) += 1;
    }
    t = func_0038CF00(pos, c);
    *(f32 *)(b + 204) = t;
    if (t <= *(f32 *)(b + 52)) {
        *(s32 *)(b + 148) |= 0x80;
    }
    if (*(s32 *)(b + 56) & 0x200) {
        if (func_L01_0045D158(a, b)) {
            func_L01_00446BC8(a, 0, 0x10000, pos, 255.0f);
        }
    }
}
/* localdecomp:end func_L01_0045C950 */

/* localdecomp:start func_L01_0045CC18 */
#include "vu0.h"
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) V_0045CC18;
extern f32 func_L01_00451700(s32, void *, s32);
extern f32 func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);

f32 func_L01_0045CC18(u8 *a0, u8 *a1, f32 *a2, s32 a3) {
    V_0045CC18 t;
    V_0045CC18 m[3];
    f32 ang;
    f32 r;

    t = *(V_0045CC18 *)a2;
    r = func_L01_00451700((s32)a0, &t, a3);
    ang = 0.0f;
    func_L01_00448890(&ang, a1 + 0xB4, 0, r, *(f32 *)(a1 + 0x14), *(f32 *)(a1 + 0x18), 3.1415927f);
    qzero(&t);
    t.v[2] = *(f32 *)(a1 + 0xB4);
    func_0038D308(m, &t);
    func_0038D5F0(a0 + 0xC0, a0 + 0xC0, m);
    return fabs_asm(r) - fabs_asm(*(f32 *)(a1 + 0xB4));
}
/* localdecomp:end func_L01_0045CC18 */

INCLUDE_ASM("asm/levels", func_L01_0045CCD8);

INCLUDE_ASM("asm/levels", func_L01_0045CDA0);

INCLUDE_ASM("asm/levels", func_L01_0045CED0);

/* localdecomp:start func_L01_0045CF00 */
#include "vu0.h"
extern s32 D_L01_001DFB40_0045CF00;
extern u8 *func_L01_0045B958_0045CF00(u8 *);
extern void func_L01_0045C1D0_0045CF00(void);
extern void func_0038D5B0(void *, void *);
extern void func_L01_004511C0_0045CF00(u8 *, f32 *, s32);
extern void func_L01_004515D8_0045CF00(void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_0045B908_0045CF00(u8 *, u8 *);
extern void func_L01_0045B8D8_0045CF00(u8 *, u8 *);
extern void func_L01_0045CDA0_0045CF00(u8 *, u8 *);
extern void func_L01_0045C510_0045CF00(u8 *self, u8 *p, void *tgt, s32 a3, s32 t0, s32 t1, s32 t2);
extern void func_L01_0045C7A8_0045CF00(u8 *, u8 *, void *, void *);
extern void func_L01_0045C950_0045CF00(u8 *a, u8 *b, u8 *c, s32 d);

s32 func_L01_0045CF00(u8 *a0, void *a1, void *a2) {
    f32 m[16] __attribute__((aligned(16)));
    f32 v40[4] __attribute__((aligned(16)));
    f32 v50[12] __attribute__((aligned(16)));
    f32 v80[4] __attribute__((aligned(16)));
    f32 v90[4] __attribute__((aligned(16)));
    u8 *o;
    f32 *mp;
    s32 t;

    o = func_L01_0045B958_0045CF00(a0);
    if (o == 0) {
        return 8;
    }
    if (D_L01_001DFB40_0045CF00 == *(s32 *)(o + 0xBC)) {
        return *(s32 *)(o + 0x94);
    }
    func_L01_0045C1D0_0045CF00();
    func_0038D5B0(m, a0 + 0xC0);
    mp = m;
    func_L01_004511C0_0045CF00(a0 + 0x10, v40, 0);
    func_L01_004515D8_0045CF00(a0 + 0xC0, v40, v50);
    func_0038D000(o + 0xA0, o + 0xA0, v50);
    *(s32 *)(o + 0x98) = *(s32 *)(o + 0x94);
    *(s32 *)(o + 0x94) = 0;
    func_L01_0045B908_0045CF00(a0, o);
    func_L01_0045B8D8_0045CF00(a0, o);
    t = *(s32 *)(o + 0xBC);
    if (D_L01_001DFB40_0045CF00 - t >= 2 || t == 0) {
        func_L01_0045CDA0_0045CF00(a0, o);
        *(s32 *)(o + 0x80) = 0;
        *(s32 *)(o + 0x9C) &= ~2;
        o[0xEA] = 0xFF;
        qzero(o + 0xA0);
        *(s32 *)(o + 0xB4) = 0;
    }
    *(s32 *)(o + 0xBC) = D_L01_001DFB40_0045CF00;
    func_L01_0045C510_0045CF00(a0, o, a1, (s32)a2, (s32)v80, (s32)v90, (s32)mp);
    func_L01_0045C7A8_0045CF00(a0, o, v90, mp);
    func_L01_0045C950_0045CF00(a0, o, a1, (s32)mp);
    return *(s32 *)(o + 0x94);
}
/* localdecomp:end func_L01_0045CF00 */

LINKER_REMNANT("asm/levels", func_L01_0045D0A8);
