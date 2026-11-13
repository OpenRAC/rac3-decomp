#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L36_00353598);

/* localdecomp:start func_L36_00353F58 */
__asm__(".extern D_L36_001DD908, 4");
extern f32 D_L36_001DD908;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_0038D308(u8 *, u8 *);
extern void func_003C7DD8(u8 *);
extern void func_003C29B0(u8 *);
extern void func_003C6FE0(u8 *);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(u8 *, u8 *, f32);
extern void func_L36_00354B28(u8 *);
extern void func_L36_003540D8(u8 *);
u8 *func_L36_00353F58(u8 *a0, void *a1, s32 a2, f32 a3) {
    u8 *o;
    u8 *p;
    u8 *q;
    u16 h;
    s32 m;
    o = func_003C24B0(*(s16 *)(a0 + 0xAA), 0x80);
    if (o == 0 || a0 == 0) {
        return 0;
    }
    func_L01_00456160(o, a0);
    func_0038D308(o + 0xC0, o + 0xF0);
    *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * (*(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24));
    func_003C7DD8(o);
    h = *(u16 *)(o + 0x34);
    m = 1 << a2;
    *(s32 *)(o + 0x98) = 0;
    h |= 0x100;
    m |= 0x8000;
    h &= 0xFFDF;
    *(u8 *)(o + 0x43) = 0;
    *(u8 *)(o + 0x42) = 0;
    *(u16 *)(o + 0x34) = h;
    *(u16 *)(o + 0x7C) = m;
    func_003C29B0(o);
    *(s32 *)(o + 0x48) = 0;
    *(s32 *)(o + 0x44) = 0;
    func_003C6FE0(o);
    *(u128_t *)(o + 0x10) = *(u128_t *)(a0 + 0x10);
    q = *(u8 **)(a0 + 0x68);
    func_L01_0043B9E8(o, *(u8 *)(q + 0x44), *(u8 *)(q + 0x45), *(u8 *)(q + 0x46));
    p = *(u8 **)(o + 0x68);
    *(u128_t *)(p + 0x20) = *(u128_t *)a1;
    func_0038CE20(a1, a1, func_003824E0(1.0f - D_L36_001DD908, D_L36_001DD908 + 1.0f));
    *(u128_t *)(p + 0x30) = *(u128_t *)a1;
    *(s32 *)(p + 0x4C) = a2;
    *(f32 *)(p + 0x58) = a3;
    *(s32 *)(p + 0x40) = 0;
    *(u16 *)(p + 0x44) = 0;
    *(s32 *)(p + 0x54) = 0;
    *(s32 *)(p + 0x5C) = 0;
    func_L36_00354B28(o);
    *(void **)(o + 0x64) = func_L36_003540D8;
    return o;
}
/* localdecomp:end func_L36_00353F58 */

INCLUDE_ASM("asm/levels", func_L36_003540D8);

/* localdecomp:start func_L36_00354288 */
__asm__(".extern D_L36_001DD918, 4");
__asm__(".extern D_L36_001DD830, 4");
__asm__(".extern D_L36_001DD924, 4");
__asm__(".extern D_L36_001DD8B0, 4");
__asm__(".extern D_L36_001DD874, 4");
__asm__(".extern D_L36_001DD928, 4");
__asm__(".extern D_L36_001DD91C, 4");
__asm__(".extern D_L36_001DD828, 4");
__asm__(".extern D_L36_001DD920, 4");
typedef struct {
    vu0_v4 pos;
    u8 pad10[0x10];
    vu0_v4 vel;
    u8 pad30[0x20];
    f32 f50;
    f32 f54;
    f32 f58;
    s32 i5C;
} S_354288;
extern f32 D_L36_001DD918;
extern f32 D_L36_001DD830;
extern f32 D_L36_001DD924;
extern f32 D_L36_001DD8B0;
extern f32 D_L36_001DD874;
extern f32 D_L36_001DD928;
extern f32 D_L36_001DD91C;
extern f32 D_L36_001DD828;
extern f32 D_L36_001DD920;
extern vu0_v4 D_L36_001E9560;
extern vu0_v4 D_L36_001E2660;
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L36_00348BB8(u8 *, f32 *, f32, f32, f32);
void func_L36_00354288(u8 *a0) {
    S_354288 *s = *(S_354288 **)(a0 + 0x68);
    vu0_v4 to;
    vu0_v4 proj;
    vu0_v4 rest;
    vu0_v4 side;
    vu0_v4 axis;
    vu0_v4 old;
    vu0_v4 dd;
    f32 v;
    f32 w;
    f32 x;
    s32 r;

    func_L36_00354B28(a0);
    r = func_L01_003FB640(s, 2, a0, s->f50);
    vec_sub_ab(&to, &D_L36_001E9560, &s->pos);
    to.y = 0.0f;
    if (r == 0 || func_0038CE68(&to, &s->vel) < D_L36_001DD918) {
        if (s->i5C != 2) {
            s->vel.z = s->vel.z + D_L36_001DD8B0;
        }
        vec_add_ab(a0 + 0x10, a0 + 0x10, &s->vel);
        func_L36_00354B28(a0);
        old = s->pos;
        func_L36_00348BB8(a0, (f32 *)s, 0.0f, s->f58, 0.0f);
        func_L36_00354B28(a0);
        vec_sub_ab(&dd, &old, &s->pos);
        vec_add_ab(a0 + 0x10, a0 + 0x10, &dd);
        return;
    }
    s->i5C = 0;
    if (func_0038CEA8(&s->vel) < D_L36_001DD830) {
        if (0.0f < to.x * s->f58 && fabs_asm(to.z) < D_L36_001DD924 * fabs_asm(to.x)) {
            s->f58 = -s->f58;
            return;
        }
        old = s->pos;
        func_L36_00348BB8(a0, (f32 *)s, 0.0f, s->f58, 0.0f);
        func_L36_00354B28(a0);
        vec_sub_ab(&dd, &old, &s->pos);
        vec_add_ab(a0 + 0x10, a0 + 0x10, &dd);
        *(f32 *)(a0 + 0x10) = *(f32 *)(a0 + 0x10) + s->f58 * s->f50;
        v = s->f58;
        if (0.0f < v) {
            w = v - D_L36_001DD874;
            x = (w < 0.0f) ? 0.0f : w;
        } else {
            w = v + D_L36_001DD874;
            x = (0.0f < w) ? 0.0f : w;
        }
        s->f58 = x;
        s->f54 = s->f54 + 1.0f;
        if (fabs_asm(to.x) > fabs_asm(to.z) || 0.0f < to.x) {
            s->vel.z = s->vel.z + D_L36_001DD8B0;
        }
        return;
    }
    func_0038CE20((u8 *)&proj, (u8 *)&to, func_0038CE68(&to, &s->vel) / func_0038CE68(&to, &to));
    vec_sub_ab(&rest, &s->vel, &proj);
    func_0038CE90(&side, &D_L36_001E2660, &proj);
    func_0038CF68(&side, &side, 1.0f);
    axis = side;
    func_0038CE20((u8 *)&side, (u8 *)&side, D_L36_001DD928 * s->f58 * s->f50);
    vec_add_ab(&rest, &side, &rest);
    func_0038CE20((u8 *)&rest, (u8 *)&rest, 0.5f);
    s->f58 = D_L36_001DD91C * 0.5f * (s->f58 + D_L36_001DD928 * func_0038CE68(&axis, &rest) / s->f50);
    func_0038CE20((u8 *)&proj, (u8 *)&proj, -D_L36_001DD828);
    func_0038CE20((u8 *)&rest, (u8 *)&rest, D_L36_001DD920);
    vec_add_ab(&s->vel, &proj, &rest);
    s->vel.y = 0.0f;
}
/* localdecomp:end func_L36_00354288 */

/* localdecomp:start func_L36_00354648 */
__asm__(".extern D_L36_001DD830, 4");
__asm__(".extern D_L36_001DD828, 4");
__asm__(".extern D_L36_001DD8B0, 4");
typedef struct {
    vu0_v4 pos[2];
    vu0_v4 vel[2];
    u8 pad40[0x10];
    f32 f50;
} S_354648;
extern f32 D_L36_001DD830;
extern f32 D_L36_001DD828;
extern f32 D_L36_001DD8B0;
extern vu0_v4 D_L36_001E9560;
typedef struct { u8 pad[0x20]; f32 x, y, z; } G_354648;
extern G_354648 D_L36_001E9540;
extern f32 D_001A4C64[];
extern void func_0038CE20(u8 *, u8 *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L36_00348BB8(u8 *, f32 *, f32, f32, f32);
void func_L36_00354648(u8 *a0) {
    S_354648 *s = *(S_354648 **)(a0 + 0x68);
    vu0_v4 mid0;
    vu0_v4 mid1;
    vu0_v4 d;
    vu0_v4 to;
    vu0_v4 proj;
    vu0_v4 rest;
    vu0_v4 dir;
    vu0_v4 want;
    f32 ang;
    f32 len;
    f32 t;
    s32 i;
    s32 r;

    func_L36_00354B28(a0);
    vec_add_ab(&mid0, &s->pos[0], &s->pos[1]);
    func_0038CE20((u8 *)&mid0, (u8 *)&mid0, 0.5f);
    ang = func_0038D160(s->pos[1].z - s->pos[0].z, s->pos[1].x - s->pos[0].x);
    len = func_0038CF00(&s->pos[0], &s->pos[1]);
    for (i = 0; i < 2; i++) {
        vec_add_ab(&s->pos[i], &s->pos[i], &s->vel[i]);
        r = func_L01_003FB640(&s->pos[i], 2, a0, s->f50);
        vec_sub_ab(&to, &D_L36_001E9560, &s->pos[i]);
        if (r != 0 && 0.0f < func_0038CE68(&to, &s->vel[i])) {
            if (func_0038CEA8(&s->vel[i]) < D_L36_001DD830
                && fabs_asm(D_L36_001E9540.z - s->pos[i].z) > fabs_asm(D_L36_001E9540.x - s->pos[i].x)) {
                qzero(&s->vel[i]);
                func_0038CE20((u8 *)&s->vel[(i + 1) % 2], (u8 *)&s->vel[(i + 1) % 2], 0.95f);
            } else {
                t = func_0038CE68(&to, &s->vel[i]);
                func_0038CE20((u8 *)&proj, (u8 *)&to, t / func_0038CE68(&to, &to));
                vec_sub_ab(&rest, &s->vel[i], &proj);
                func_0038CE20((u8 *)&proj, (u8 *)&proj, -D_L36_001DD828);
                vec_add_ab(&s->vel[i], &proj, &rest);
            }
        } else {
            s->vel[i].z = s->vel[i].z + D_L36_001DD8B0;
        }
    }
    if (func_0038CF00(&s->pos[0], &s->pos[1]) != len) {
        s->pos[0].y = s->pos[1].y = D_001A4C64[0];
        vec_sub_ab(&dir, &s->pos[1], &s->pos[0]);
        func_0038CF68(&want, &dir, len);
        vec_sub_ab(&d, &want, &dir);
        func_0038CE20((u8 *)&d, (u8 *)&d, 0.5f);
        vec_add_ab(&s->pos[1], &s->pos[1], &d);
        func_0038CE20((u8 *)&d, (u8 *)&d, -0.5f);
        vec_add_ab(&s->pos[0], &s->pos[0], &d);
    }
    vec_add_ab(&mid1, &s->pos[0], &s->pos[1]);
    func_0038CE20((u8 *)&mid1, (u8 *)&mid1, 0.5f);
    t = func_0038D160(s->pos[1].z - s->pos[0].z, s->pos[1].x - s->pos[0].x);
    vec_sub_ab(&d, &mid1, &mid0);
    vec_add_ab(a0 + 0x10, a0 + 0x10, &d);
    func_L36_00348BB8(a0, (f32 *)&mid1, 0.0f, t - ang, 0.0f);
}
/* localdecomp:end func_L36_00354648 */

/* localdecomp:start func_L36_003549F0 */
extern f32 D_L36_001DD87C;
__asm__(".extern D_L36_001DD87C, 4");
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern u8 *func_L36_00353F58(u8 *, void *, s32, f32);
void func_L36_003549F0(u8 *a0, u8 *a1, u8 *a2) {
    u8 *s;
    u8 **q;
    u8 *o;
    u8 *p;
    vu0_v4 v;
    vu0_v4 buf;
    s32 i;
    s32 j;
    s = *(u8 **)(a0 + 0x68);
    *(s32 *)(s + 0x80) = 0;
    q = (u8 **)(s + 0x8C);
    for (i = 6; i < 12; i++) {
        func_0038CF68(&buf, a1, D_L36_001DD87C * 0.5f);
        j = 1;
        o = func_L36_00353F58(a0, &buf, i, func_003824E0(-0.11309733f, 0.11309733f));
        *(u8 **)((s32)q + (i << 2)) = o;
        p = *(u8 **)(o + 0x68);
        do {
            vec_sub_ab(&v, p, a2);
            func_0038CF68(&v, &v, D_L36_001DD87C * 0.5f);
            vec_add_ab(p + 0x20, p + 0x20, &v);
            j--;
            p += 0x10;
        } while (j >= 0);
    }
}
/* localdecomp:end func_L36_003549F0 */

/* localdecomp:start func_L36_00354B28 */
__asm__(".extern D_L36_001DD840, 8");
extern f32 D_L36_001DD840[2];
extern f32 D_001A4C64[];
extern void func_003C2F58(u8 *, s32, u8 *);
extern void func_003C2880(u8 *);
void func_L36_00354B28(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 d;
    switch (*(u32 *)(s + 0x4C)) {
    case 2:
        func_003C2F58(a0, 0x8, s);
        *(s16 *)(s + 0x46) = 0;
        *(f32 *)(s + 0x48) = 0.85f;
        break;
    case 3:
        func_003C2F58(a0, 0xB, s);
        *(s16 *)(s + 0x46) = 0;
        *(f32 *)(s + 0x48) = 0.85f;
        break;
    case 4:
        func_003C2F58(a0, 0xD, s);
        func_003C2F58(a0, 0xE, s + 0x10);
        *(s16 *)(s + 0x46) = 1;
        *(f32 *)(s + 0x48) = 0.75f;
        break;
    case 5:
        func_003C2F58(a0, 0x10, s);
        func_003C2F58(a0, 0x11, s + 0x10);
        *(s16 *)(s + 0x46) = 1;
        *(f32 *)(s + 0x48) = 0.75f;
        break;
    case 6:
        func_003C2F58(a0, 0x3, s);
        *(s16 *)(s + 0x46) = 0;
        *(f32 *)(s + 0x48) = 0.8f;
        break;
    case 0:
    case 1:
    case 7:
        func_003C2F58(a0, 0x4, s);
        *(s16 *)(s + 0x46) = 0;
        *(f32 *)(s + 0x48) = 0.6f;
        break;
    case 8:
        func_003C2F58(a0, 0x5, s);
        func_003C2F58(a0, 0x6, s + 0x10);
        *(s16 *)(s + 0x46) = 1;
        *(f32 *)(s + 0x48) = 0.65f;
        break;
    case 9:
        func_003C2F58(a0, 0x7, s);
        func_003C2F58(a0, 0x9, s + 0x10);
        *(s16 *)(s + 0x46) = 1;
        *(f32 *)(s + 0x48) = 0.5f;
        break;
    case 10:
        func_003C2F58(a0, 0xA, s);
        func_003C2F58(a0, 0xC, s + 0x10);
        *(s16 *)(s + 0x46) = 1;
        *(f32 *)(s + 0x48) = 0.5f;
        break;
    case 11:
        func_003C2F58(a0, 0xD, s);
        func_003C2F58(a0, 0xF, s + 0x10);
        *(s16 *)(s + 0x46) = 1;
        *(f32 *)(s + 0x48) = 0.5f;
        break;
    case 12:
        func_003C2F58(a0, 0x10, s);
        func_003C2F58(a0, 0x12, s + 0x10);
        *(s16 *)(s + 0x46) = 1;
        *(f32 *)(s + 0x48) = 0.5f;
        break;
    case 13:
        func_003C2880(a0);
        break;
    }
    *(f32 *)(s + 0x50) = D_L36_001DD840[*(s32 *)(s + 0x4C)];
    d = D_001A4C64[0] - *(f32 *)(s + 4);
    *(f32 *)(a0 + 0x14) = *(f32 *)(a0 + 0x14) + d;
    *(f32 *)(s + 4) = *(f32 *)(s + 4) + d;
    *(f32 *)(s + 0x14) = *(f32 *)(s + 0x14) + d;
}
/* localdecomp:end func_L36_00354B28 */

/* localdecomp:start func_L36_00354D88 */
__asm__(".extern D_L36_001DD8B8, 4");
__asm__(".extern D_L36_001DD898, 4");
__asm__(".extern D_L36_001DD89C, 4");
__asm__(".extern D_L36_001DD8A8, 4");
__asm__(".extern D_L36_001DD8AC, 4");
__asm__(".extern D_L36_001DD8C0, 4");
__asm__(".extern D_L36_001DD8E0, 4");
__asm__(".extern D_L36_001DD8E4, 4");
__asm__(".extern D_L36_001DD8E8, 4");
__asm__(".extern D_L36_001DD8EC, 4");
__asm__(".extern D_L36_001DD8F0, 4");
__asm__(".extern D_L36_001DD8DC, 4");
__asm__(".extern D_L36_001DD8F4, 4");
__asm__(".extern D_L36_001DD824, 4");
__asm__(".extern D_L36_001DD8BC, 4");
extern s32 D_L36_001DD8B8;
extern f32 D_L36_001DD898;
extern f32 D_L36_001DD89C;
extern f32 D_L36_001DD8A8;
extern f32 D_L36_001DD8AC;
extern s32 D_L36_001DD8C0;
extern f32 D_L36_001DD8E0;
extern f32 D_L36_001DD8E4;
extern f32 D_L36_001DD8E8;
extern f32 D_L36_001DD8EC;
extern f32 D_L36_001DD8F0;
extern f32 D_L36_001DD8DC;
extern f32 D_L36_001DD8F4;
extern f32 D_L36_001DD824;
extern f32 D_L36_001DD8BC;
extern u8 D_L36_001D66B0[8];
extern u8 D_001A4BE0[];
extern s32 func_0038CAD0(void *);
extern void func_L01_0044ABD0(void *, void *);
extern u8 *func_L01_00447490(void *, s32, s32);
extern void func_003C4A40(void *, void *);
extern s32 func_003A52A0(s32, s32, u8 *);
extern void func_L36_003549F0(u8 *, u8 *, u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L36_003553B8(u8 *, u8 *, f32, f32);
extern f32 func_L01_004395E0(u8 *);
extern void func_003C2F58(u8 *, s32, u8 *);
extern void func_L32_00347FE8(u8 *, void *, f32, f32, s32, s32, s32, s32, s32);
void func_L36_00354D88(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *m;
    vu0_v4 v;
    vu0_v4 a;
    vu0_v4 c;
    vu0_v4 b;
    f32 d;
    s32 i;
    u8 *h;

    func_0038CAD0(s + 0x7C);
    func_L01_0044ABD0(a0, s + 0x40);
    m = func_L01_00447490(a0, 0x10000, 0);
    if (m != 0) {
        *(u8 *)(a0 + 0xA8) = 0xFF;
        if (0.0f < *(f32 *)(m + 0x2C) && *(s16 *)(*(u8 **)(m + 0x20) + 0xAA) != 0x167E
            && *(u8 *)(a0 + 0x20) != 0x42 && *(u8 *)(a0 + 0x20) != 0xB && *(s32 *)(s + 0x7C) <= 0) {
            *(s32 *)(s + 0x7C) = D_L36_001DD8B8;
            *(f32 *)s = *(f32 *)s - *(f32 *)(m + 0x2C);
            v = *(vu0_v4 *)(m + 0x10);
            *(u8 *)(s + 0x47) = 0xFF;
            func_003C4A40(a0, s + 0x40);
            if (*(f32 *)s <= 0.0f) {
                func_003A52A0(5, 0, a0);
                func_L36_003549F0(a0, (u8 *)&v, m);
                func_L01_004450F0(a0, 0x42, -1);
            } else if (*(u8 *)(a0 + 0x20) != 2) {
                if (1.0f < *(f32 *)(m + 0x2C)) {
                    func_003A52A0(6, 0, a0);
                    func_0038CF68(&v, &v, D_L36_001DD898);
                    if (*(u8 *)(a0 + 0x20) != 2) {
                        func_L01_004450F0(a0, 9, -1);
                    }
                } else {
                    func_003A52A0(6, 0, a0);
                    func_0038CF68(&v, &v, D_L36_001DD89C);
                    if (*(u8 *)(a0 + 0x20) != 2) {
                        func_L01_004450F0(a0, 8, -1);
                    }
                }
            }
            vec_add_ab(s + 0x60, s + 0x60, &v);
            func_L36_003553B8(a0, (u8 *)&v, *(f32 *)s + *(f32 *)(m + 0x2C), *(f32 *)s);
        } else {
            func_L36_003553B8(a0, D_L36_001D66B0, *(f32 *)s, *(f32 *)s);
        }
    }
    if (*(u8 *)(a0 + 0x20) != 5) {
        for (i = 0; i < 13; i++) {
            if (((u8 **)(s + 0x8C))[i] != 0) {
                func_L36_003540D8(((u8 **)(s + 0x8C))[i]);
            }
        }
    }
    if (*(s32 *)(s + 0x70) != 0) {
        *(f32 *)(a0 + 0xF8) = D_L36_001DD8A8;
    } else {
        *(f32 *)(a0 + 0xF8) = D_L36_001DD8AC;
    }
    h = D_001A4BE0;
    *(f32 *)(a0 + 0x14) = *(f32 *)(h + 0x84);
    if (*(u8 *)(a0 + 0x20) == 0x42 || *(u8 *)(a0 + 0x20) == 9 || *(u8 *)(a0 + 0x20) == 8) {
        return;
    }
    if (*(u8 *)(a0 + 0x94) == 8 && *(u16 *)(a0 + 0x96) < D_L36_001DD8C0) {
        return;
    }
    if (*(u8 *)(a0 + 0x20) == 0xB) {
        return;
    }
    vec_sub_ab(&v, h + 0x80, a0 + 0x10);
    func_0038CF68(&v, &v, 1.0f);
    if ((u32)(*(u8 *)(a0 + 0x20) - 1) < 2) {
        d = func_L01_004395E0(a0);
        if ((D_L36_001DD8E0 <= d && d <= D_L36_001DD8E4) || (D_L36_001DD8E8 <= d && d <= D_L36_001DD8EC)) {
            func_003C2F58(a0, 1, (u8 *)&a);
            func_003C2F58(a0, 0, (u8 *)&b);
            a.z = *(f32 *)(a0 + 0x18) + D_L36_001DD8F0;
            vec_sub_ab(&c, &a, &b);
            func_0038CE20((u8 *)&c, (u8 *)&c, D_L36_001DD8DC);
            vec_add_ab(&a, &c, &b);
            func_L32_00347FE8(a0, &v, (f32)*(u8 *)(s + 0x15), D_L36_001DD8F4, 0, -1, 0, (s32)&a, 0);
        }
    }
    func_L32_00347FE8(a0, &v, (f32)*(u8 *)(s + 0x14), D_L36_001DD824, 5, 4, 0, 0, 0);
    func_L32_00347FE8(a0, &v, (f32)*(u8 *)(s + 0x14), D_L36_001DD8BC, 0xD, 0xF, 0, 0, 0);
    func_L32_00347FE8(a0, &v, (f32)*(u8 *)(s + 0x14), D_L36_001DD8BC, 0x10, 0x12, 0, 0, 0);
}
/* localdecomp:end func_L36_00354D88 */

/* localdecomp:start func_L36_00355210 */
extern u8 D_L36_001D66B0[8];
extern void func_L36_003553B8(u8 *, u8 *, f32, f32);
void func_L36_00355210(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 i;
    s32 *q;
    f32 f = *(f32 *)p;
    *(s32 *)(p + 0x80) = 0x3F;
    func_L36_003553B8(a0, D_L36_001D66B0, f, f);
    for (i = 12, q = (s32 *)(p + 0xBC); i >= 0; i--) {
        *q-- = 0;
    }
    *(s32 *)(p + 0x7C) = 0;
    *(s32 *)(p + 0x70) = 1;
    *(s32 *)(p + 0x74) = 0;
    *(s32 *)(p + 0x78) = 0;
    qzero(p + 0x60);
}
/* localdecomp:end func_L36_00355210 */
