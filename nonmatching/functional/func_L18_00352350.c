/* functional: medium. Fixed: a, d and m are 3-row matrices (0x30 bytes) the callees fill, previously 16-byte locals that overflowed. Hand-written from PAL assembly (no draft existed). Notes: func_L18_00351908's return value (s32) is passed back out, called through a cast because the unit declares it void; f24/f25 limits (30, 25) are overwritten with (35, -7) only when v+0x3BC is 0, as in retail; the dead repeat of the +0x3BC test before the func_0038D028 call is folded. Needs -mvu0-use-vf0-vf2 only if the vec helpers are used (they are not here). */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L18_00352350 */
typedef int u128_00352350 __attribute__((mode(TI)));
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) V_00352350;

/* the matrices are 3 rows of 16 bytes: the callees write all 0x30 bytes. Retail's frame has the
   row-vector d at sp+0x60 and the rotation matrix m at sp+0x70; d also serves as a matrix early on. */
typedef struct {
    f32 r[12];
} __attribute__((aligned(16))) M_00352350;
typedef struct {
    V_00352350 d;
    M_00352350 m;
} DM_00352350;
typedef union {
    M_00352350 dm;
    DM_00352350 s;
} U_00352350;

extern void func_0038D5B0(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C4840(void *, f32, void *);
extern void func_0038D850(void *, void *, void *);
extern void func_0038D328(void *, void *);
extern f32 func_0038CED8(void *);
extern void func_L01_00448728(void *, void *, s32, f32, f32, f32, f32);
extern u8 *D_001D52FC_sda;
extern u8 D_001439F4;
extern s32 D_00143A10[][8];
extern s32 D_00143A70[][8];
__asm__(".extern D_001D52FC_sda, 4");

s32 func_L18_00352350(u8 *self) {
    u8 *v;
    u8 *pad;
    u8 *g;
    u8 *vp;
    M_00352350 a;
    V_00352350 b;
    V_00352350 c;
    U_00352350 u;
    V_00352350 e;
    V_00352350 h;
    f32 f24;
    f32 f25;
    f32 f1;
    f32 f5;
    f32 f7;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;
    f32 lim;
    f32 r;
    f32 sc;
    u32 flags;
    s32 idx;
    s32 ret;

    v = *(u8 **)(self + 0x68);
    f24 = 30.0f;
    f25 = 25.0f;
    pad = D_001D52FC_sda;
    if (*(s32 *)(v + 0x3BC) != 0) {
        func_0038D5B0(&a, self + 0xC0);
        vp = v + 0x290;
        func_0038D028(&b, vp, &a);
    } else {
        vp = v + 0x290;
        *(u128_00352350 *)&b = *(u128_00352350 *)(v + 0x290);
    }
    f1 = *(f32 *)(v + 0x2A8) * 0.9f;
    f20 = *(f32 *)(v + 0x298) * 0.95f;
    *(f32 *)(v + 0x2A8) = f1;
    func_0038CE20(vp, vp, 0.98f);
    *(f32 *)(v + 0x298) = f20;

    g = (u8 *)&D_001A4BE0;
    idx = D_001439F4;
    f7 = *(f32 *)(g + 0x2260);
    if (*(s32 *)(v + 0x3BC) != 0) {
        f7 = -f7;
    }
    f23 = -1.0f;
    if (D_00143A10[idx][0] != 0) {
        f23 = 1.0f;
    }
    f1 = 1.0f;
    if (D_00143A70[idx][0] != 0) {
        f1 = -1.0f;
    }
    *(s32 *)(g + 0x360) = 0;
    if (idx == 0) {
        f1 = 1.0f;
    }
    f21 = *(f32 *)(g + 0x2264);
    flags = *(u32 *)(pad + 0x1A0);
    f5 = -*(f32 *)(pad + 0x100) * f1;
    f20 = 0.0f;
    if (flags & 4) {
        f20 = 1.0f;
    }
    if (flags & 1) {
        f20 = f20 - 1.0f;
    }
    if (flags & 0x40) {
        f20 = f20 + 1.0f;
    }
    if (flags & 0x80) {
        f20 = f20 - 1.0f;
    }
    if (1.0f < f20) {
        f20 = 1.0f;
    }
    if (f20 < -1.0f) {
        f20 = -1.0f;
    }
    lim = *(f32 *)(v + 0x390);
    r = (f20 + 1.0f) * 0.5f * 0.087266475f + 0.05235988f - lim;
    if (0.0034906587f < r) {
        r = 0.0034906587f;
    } else if (r < -0.0034906587f) {
        r = -0.0034906587f;
    }
    r = lim + r;
    f22 = f7 * 0.024f;
    *(f32 *)(v + 0x390) = r;
    f5 = f5 * 0.0034906587f;
    f21 = f21 * 0.014f;
    f20 = f20 * 0.024f;
    r = func_0038DAB8(*(f32 *)(v + 0x2A8), f5);
    *(f32 *)(v + 0x2A8) = r;
    if (0.2792527f < r) {
        *(f32 *)(v + 0x2A8) = 0.2792527f;
    } else if (r < -0.2792527f) {
        *(f32 *)(v + 0x2A8) = -0.2792527f;
    }
    if (*(s32 *)(v + 0x3BC) != 0) {
        r = func_0038DAB8(*(f32 *)(self + 0xF8), *(f32 *)(v + 0x2A8));
        *(f32 *)(self + 0xF8) = r;
    } else {
        func_003C4840(&u.dm, *(f32 *)(v + 0x2A8), v + 0x2F0);
        f24 = 35.0f;
        f25 = -7.0f;
        func_0038D850(v + 0x2D0, v + 0x2D0, &u.dm);
        func_0038D850(v + 0x2E0, v + 0x2E0, &u.dm);
    }
    *(u128_00352350 *)&e = 0;
    u.s.d.v[0] = f21;
    u.s.d.v[2] = f20;
    u.s.d.v[1] = f22;
    e.v[2] = *(f32 *)(self + 0xF8);
    func_0038D328(&u.s.m, &e);
    func_0038D028(&u.s.d, &u.s.d, &u.s.m);
    f20 = 0.48000002f;
    {
        /* vec_add of +0x290 and d, kept as an xyz add (w untouched) */
        f32 *q = (f32 *)vp;
        q[0] = q[0] + u.s.d.v[0];
        q[1] = q[1] + u.s.d.v[1];
        q[2] = q[2] + u.s.d.v[2];
        h = *(V_00352350 *)vp;
    }
    f21 = func_0038CED8(vp);
    if (f20 < f21) {
        f20 = f20 / f21;
        *(f32 *)(v + 0x290) = *(f32 *)(v + 0x290) * f20;
        *(f32 *)(v + 0x294) = *(f32 *)(v + 0x294) * f20;
    }
    r = *(f32 *)(v + 0x298);
    if (0.28000003f < r) {
        *(f32 *)(v + 0x298) = 0.28000003f;
    } else if (r < -0.28000003f) {
        *(f32 *)(v + 0x298) = -0.28000003f;
    }
    ret = ((s32 (*)(void *))func_L18_00351908)(self);
    if (*(s32 *)(v + 0x3BC) == 0) {
        r = *(f32 *)(v + 0x39C);
        f1 = *(f32 *)(v + 0x394);
    } else {
        r = *(f32 *)(v + 0x394);
        f1 = *(f32 *)(v + 0x39C);
    }
    f5 = (r - f1) * -0.8f;
    func_L01_00448728(v + 0x2B0, v + 0x2A0, 0, f5, 0.01008f, 0.28800002f, 0.024434611f);
    if (0.3f < *(f32 *)(v + 0x2B0)) {
        *(f32 *)(v + 0x2B0) = 0.3f;
    }
    if (*(f32 *)(v + 0x2B0) < -0.3f) {
        *(f32 *)(v + 0x2B0) = -0.3f;
    }
    if (*(s32 *)(v + 0x3BC) != 0) {
        *(f32 *)(self + 0xF0) = *(f32 *)(v + 0x2B0);
    } else {
        func_003C4840(&u.s.m, *(f32 *)(v + 0x2B0), self + 0xC0);
        func_0038D850(self + 0xD0, self + 0xD0, &u.s.m);
        func_0038D850(self + 0xE0, self + 0xE0, &u.s.m);
    }
    f1 = *(f32 *)(v + 0x350) + *(f32 *)(pad + 0x104) * -0.012f * f23;
    *(f32 *)(v + 0x350) = f1;
    lim = f24 * 0.017453292f;
    if (lim < f1) {
        *(f32 *)(v + 0x350) = lim;
    }
    lim = -f25 * 0.017453292f;
    if (*(f32 *)(v + 0x350) < lim) {
        *(f32 *)(v + 0x350) = lim;
    }
    if (*(s32 *)(v + 0x3BC) == 0) {
        *(u128_00352350 *)&c = *(u128_00352350 *)(v + 0x290);
    } else {
        *(f32 *)(self + 0xF4) = *(f32 *)(v + 0x350);
        func_0038D028(&c, vp, &a);
    }
    f5 = (c.v[0] - b.v[0]) * 45.0f;
    f21 = 0.008f;
    if (fabs_asm(f5) <= 0.001f) {
        f21 = 0.00080000004f;
    }
    func_L01_00448728(v + 0x2B4, v + 0x2A4, 0, f5, f21 * 1.44f, 0.28800002f, 0.03490659f);
    if (0.55f < *(f32 *)(v + 0x2B4)) {
        *(f32 *)(v + 0x2B4) = 0.55f;
    }
    if (*(f32 *)(v + 0x2B4) < -0.5f) {
        *(f32 *)(v + 0x2B4) = -0.5f;
    }
    if (*(s32 *)(v + 0x3BC) != 0) {
        r = func_0038DAB8(*(f32 *)(self + 0xF4), *(f32 *)(v + 0x2B4));
        *(f32 *)(self + 0xF4) = r;
    } else {
        func_003C4840(&u.s.m, -*(f32 *)(v + 0x350), self + 0xD0);
        func_0038D850(self + 0xC0, self + 0xC0, &u.s.m);
        func_0038D850(self + 0xE0, self + 0xE0, &u.s.m);
        func_003C4840(&u.s.m, *(f32 *)(v + 0x2B4), self + 0xD0);
        func_0038D850(self + 0xC0, self + 0xC0, &u.s.m);
        func_0038D850(self + 0xE0, self + 0xE0, &u.s.m);
    }
    return ret;
}
/* localdecomp:end func_L18_00352350 */
