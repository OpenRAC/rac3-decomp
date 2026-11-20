#include "common.h"
#include "vu0.h"


INCLUDE_ASM("asm/levels", func_L01_0032C6B8);

/* localdecomp:start func_L01_0032C7A0 */
#include "vu0.h"

typedef int s128_0032C7A0 __attribute__((mode(TI)));

extern s32 D_001A71A0[];
extern u8 D_001425C0[];
typedef struct { u8 pad0[0x54]; u16 x54; u8 pad56[0xF0 - 0x56]; } T_2C5600_0032C7A0;
extern T_2C5600_0032C7A0 D_L01_002C5600_0032C7A0[];
extern s32 D_L01_001DCE48_0032C7A0;
__asm__(".extern D_L01_001DCE48_0032C7A0, 4");
extern u8 *func_003C24B0(s32, s32);
extern void func_0038D308(void *, void *);
extern void func_L01_004C7D98_0032C7A0(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D098(f32);
extern void func_0038D810(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern s32 func_L01_004C80F8_0032C7A0(s32, s32);
extern void func_003C2880(void *);
extern s32 func_L01_004C85C8_0032C7A0(u8 *, s32, f32, f32, f32);
extern void func_003C7C38(void *);

u8 *func_L01_0032C7A0(s128_0032C7A0 *pos, s128_0032C7A0 *rot) {
    f32 tmp[4];
    f32 a[4];
    f32 c[4];
    f32 b[4];
    f32 d[12];
    f32 h;
    u16 n;
    s32 cnt;
    u8 *v;
    u8 *p;
    u8 *m = func_003C24B0(0x1366, 0x80);
    if (m != 0) {
        *(f32 *)(m + 0x2C) *= 0.75f;
        m[0x30] = *(s16 *)(m + 0x32) = 0xFF;
        *(u16 *)(m + 0x34) |= 0x100;
        m[0x20] = 0;
        p = m + 0x10;
        v = *(u8 **)(m + 0x68);
        *(s128_0032C7A0 *)(m + 0x10) = *pos;
        *(s128_0032C7A0 *)v = *rot;
        func_0038D308(m + 0xC0, D_001A71A0[0] + 0xF0);
        func_L01_004C7D98_0032C7A0(p, tmp);
        func_0038CF68(a, m + 0xE0, 1.0f);
        func_0038CE90(b, a, tmp);
        h = func_0038CE68(a, tmp) * 0.5f;
        func_0038CE20(c, b, func_0038D0B0(h));
        c[3] = func_0038D098(h);
        func_0038D810(c, d);
        func_0038D5F0(m + 0xC0, d, m + 0xC0);
        cnt = (D_L01_001DCE48_0032C7A0 * 5 + 2) / 6;
        *(s32 *)(v + 0x68) = 0;
        n = (D_L01_002C5600_0032C7A0 + D_001425C0[0x15])->x54;
        qzero(v + 0x10);
        *(s16 *)(v + 0x66) = 0;
        *(f32 *)(v + 0x10) = 1.0f;
        *(s32 *)(v + 0x50) = 0;
        *(s128_0032C7A0 *)(v + 0x30) = *(s128_0032C7A0 *)(v + 0x10);
        *(s32 *)(v + 0x44) = 0;
        *(u16 *)(v + 0x64) = n;
        *(s16 *)(v + 0x4C) = 1;
        *(s128_0032C7A0 *)(v + 0x20) = *(s128_0032C7A0 *)(v + 0x10);
        *(f32 *)(v + 0x58) = 0.031415928f;
        *(s32 *)(v + 0x40) = cnt;
        *(s32 *)(v + 0x48) = func_L01_004C80F8_0032C7A0((s32)m, 0);
        if (*(s32 *)(v + 0x48) == -1) {
            func_003C2880(m);
            return 0;
        }
        *(s8 *)(v + 0x4F) = func_L01_004C85C8_0032C7A0(m, 0, 1.0f, 1.0f, 1.0f);
        *(s8 *)(v + 0x4E) = -1;
        *(s32 *)(v + 0x70) = 0;
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L01_0032C7A0 */

/* localdecomp:start func_L01_0032C9F0 */
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    s128 q0;
    s128 q10;
    f32 f20;
    s32 w24;
    u8 pad28[0x30 - 0x28];
} S_277090;
typedef struct {
    s32 a[0x40];
    s32 b[0x40];
    s32 c[8];
    s32 w220;
    s32 w224;
    s32 w228;
} S_276E60;
extern S_277090 D_L01_00277090[];
extern S_276E60 D_L01_00276E60[];

void func_L01_0032C9F0(void) {
    s32 i;
    S_276E60 *p;

    for (i = 99; i >= 0; i--) {
        D_L01_00277090[i].w24 = 0;
    }
    p = D_L01_00276E60;
    p->w228 = 5;
    p->w224 = 0;
    p->w220 = 0;
    for (i = 0; i < 64; i++) {
        p->a[i] = 0;
        p->b[i] = 0;
    }
    for (i = 7; i >= 0; i--) {
        D_L01_00276E60->c[i] = 0;
    }
}
/* localdecomp:end func_L01_0032C9F0 */

/* localdecomp:start func_L01_0032CA80 */
extern void func_L01_004CAE90(void *a0);

void func_L01_0032CA80(void) {
    func_L01_004CAE90(D_L01_00276E60);
}
/* localdecomp:end func_L01_0032CA80 */

/* localdecomp:start func_L01_0032CAA0 */
typedef struct {
    u8 pad0[0x66];
    u16 h66;
} S_32CAA0m;
typedef struct {
    u8 pad0[0x68];
    S_32CAA0m *p68;
} S_32CAA0;
extern void func_003C2F58(void *, s32, void *);

void func_L01_0032CAA0(S_32CAA0 *a0, s128 *a1) {
    s128 v;
    S_32CAA0m *m;
    S_277090 *e;
    s32 i;

    m = a0->p68;
    func_003C2F58(a0, 1, &v);
    for (i = 0; i < 100; i++) {
        if (D_L01_00277090[i].w24 == 0) {
            e = &D_L01_00277090[i];
            m->h66++;
            e->w24 = (s32)a0;
            e->f20 = 100.0f;
            e->q10 = *a1;
            e->q0 = v;
            break;
        }
    }
}
/* localdecomp:end func_L01_0032CAA0 */

INCLUDE_ASM("asm/levels", func_L01_0032CB38);

/* localdecomp:start func_L01_0032CE18 */
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0032DB08(void *, void *, void *);

void func_L01_0032CE18(void *a0) {
    u8 v[16];
    S_277090 *e;
    s32 i;

    for (i = 0; i < 100; i++) {
        e = &D_L01_00277090[i];
        if (e->w24 == (s32)a0) {
            func_0038CF68(v, &e->q10, 2.1f);
            vec_sub_ba(v, e, v);
            func_L01_0032DB08(a0, e, v);
        }
    }
}
/* localdecomp:end func_L01_0032CE18 */

/* localdecomp:start func_L01_0032CEB8 */
void func_L01_0032CEB8(char *p)
{
    *(long *)(p + 112) = 0L;
    *(int *)(p + 80) = 0;
    *(int *)(p + 84) = 0;
    *(float *)(p + 88) = 1.0f;
    *(int *)(p + 92) = 0;
    *(int *)(p + 96) = 0;
    *(float *)(p + 100) = 1.0f;
    *(float *)(p + 104) = 1.0f;
    *(float *)(p + 108) = 1.0f;
    *(float *)(p + 8) = -2.0f;
    *(float *)(p + 24) = 2.0f;
    *(float *)(p + 40) = -2.0f;
    *(float *)(p + 56) = 2.0f;
    *(float *)(p + 4) = -2.0f;
    *(float *)(p + 36) = 2.0f;
    *(int *)(p + 0) = 0;
    *(int *)(p + 16) = 0;
    *(int *)(p + 32) = 0;
    *(int *)(p + 48) = 0;
    *(float *)(p + 12) = 1.0f;
    *(float *)(p + 28) = 1.0f;
    *(float *)(p + 44) = 1.0f;
    *(long *)(p + 128) = 0x0000FF9000000260L;
    *(float *)(p + 20) = -2.0f;
    *(float *)(p + 52) = 2.0f;
    *(float *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_0032CEB8 */

/* localdecomp:start func_L01_0032CF48 */
typedef struct { u8 p0[0x68]; u8 *w68; } M_32CAB0;
extern s32 func_0038CAD0(u8 *);
extern void func_L01_0032D348(M_32CAB0 *);
extern void func_L01_0032CE18(void *);

void func_L01_0032CF48(M_32CAB0 *m) {
    if (func_0038CAD0(m->w68 + 68) == 0) {
        func_L01_0032D348(m);
    }
    func_L01_0032CE18(m);
}
/* localdecomp:end func_L01_0032CF48 */

/* localdecomp:start func_L01_0032CF90 */
typedef struct {
    vu0_v4 m[4];
    u32 col[4];
    u8 pad50[0x20];
    long l70;
    long l78;
    long l80;
    long l88;
} A_0032CF90;
typedef struct {
    vu0_v4 m[4];
    vu0_v4 rot;
    vu0_v4 dir;
} B_0032CF90;

extern u8 D_001425C0[];
extern u8 D_L01_002C5600_0032CF90[];
extern u8 D_L01_001E2880_0032CF90[];
extern long func_00389598(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_00382538(void);
extern void func_0038D328(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);

void func_L01_0032CF90(void *m, vu0_v4 *pos) {
    A_0032CF90 a;
    B_0032CF90 b;
    f32 s;
    u8 *d;
    u8 *r;
    u8 *q;
    long v;
    s32 alpha;

    func_L01_0032CEB8_0032CF90((char *)&a);
    v = func_00389598(0x2C);
    a.l70 = 0;
    a.l78 = v;
    a.l80 = 0x0000FF9000000260L;
    a.l88 = 0x0000008000000048L;
    alpha = func_00382498(0x30, 0x40);
    q = D_L01_002C5600_0032CF90 + D_001425C0[0x15] * 0xF0;
    if (q[1] >= 2) {
        a.col[0] = a.col[1] = a.col[2] = a.col[3] = (alpha << 24) + 0x4F1808;
    } else {
        a.col[0] = a.col[1] = a.col[2] = a.col[3] = (alpha << 24) + 0x8183F;
    }
    d = D_L01_001E2880_0032CF90;
    b.rot.w = 0.0f;
    b.rot.z = func_0038D160(((vu0_v4 *)(d + 0x140))->x - pos->x, ((vu0_v4 *)(d + 0x140))->y - pos->y);
    b.rot.y = -func_0038D160(func_0038CF38(pos, d + 0x140), ((vu0_v4 *)(d + 0x140))->z - pos->z);
    b.rot.x = func_00382538();
    func_0038D328(&b, &b.rot);
    vec_sub_ba(&b.dir, d + 0x140, pos);
    func_0038CF68(&b.dir, &b.dir, 0.25f);
    b.m[3].x = pos->x + b.dir.x;
    b.m[3].y = pos->y + b.dir.y;
    b.m[3].z = pos->z + b.dir.z;
    b.m[3].w = 1.0f;
    s = func_003824E0(0.3f, 0.4f);
    func_0038CE20(&a.m[0], &a.m[0], s);
    func_0038CE20(&a.m[1], &a.m[1], s);
    func_0038CE20(&a.m[2], &a.m[2], s);
    func_0038CE20(&a.m[3], &a.m[3], s);
    func_003D2DA0(&a, &b, 0);
    func_0038CE20(&a.m[0], &a.m[0], 0.5f);
    func_0038CE20(&a.m[1], &a.m[1], 0.5f);
    func_0038CE20(&a.m[2], &a.m[2], 0.5f);
    func_0038CE20(&a.m[3], &a.m[3], 0.5f);
    alpha = func_00382498(0x40, 0x7F);
    r = D_L01_002C5600_0032CF90 + D_001425C0[0x15] * 0xF0;
    if (r[1] >= 2) {
        a.col[0] = a.col[1] = a.col[2] = a.col[3] = (alpha << 24) + 0x803010;
    } else {
        a.col[0] = a.col[1] = a.col[2] = a.col[3] = (alpha << 24) + 0x103080;
    }
    func_003D2DA0(&a, &b, 0);
    func_0038CE20(&a.m[0], &a.m[0], 0.5f);
    func_0038CE20(&a.m[1], &a.m[1], 0.5f);
    func_0038CE20(&a.m[2], &a.m[2], 0.5f);
    func_0038CE20(&a.m[3], &a.m[3], 0.5f);
    a.col[0] = a.col[1] = a.col[2] = a.col[3] = (func_00382498(0x40, 0x7F) << 24) + 0x7F7F7F;
    func_003D2DA0(&a, &b, 0);
}
/* localdecomp:end func_L01_0032CF90 */

INCLUDE_ASM("asm/levels", func_L01_0032D348);

/* localdecomp:start func_L01_0032D7E8 */
#include "vu0.h"

typedef struct {
    vu0_v4 m[4];
    u32 col[4];
    u8 pad50[0x20];
    long l70;
    long l78;
    long l80;
    long l88;
} A_0032D7E8;
typedef struct {
    vu0_v4 m[4];
    vu0_v4 rot;
    vu0_v4 dir;
} B_0032D7E8;

extern u8 D_001425C0[];
extern u8 D_L01_002C5600_0032D7E8[];
extern u8 D_L01_001E2880_0032D7E8[];
extern void func_L01_0032CEB8_0032D7E8(char *);
extern long func_00389598(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_00382538(void);
extern void func_0038D328(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);

void func_L01_0032D7E8(void *m, vu0_v4 *pos) {
    A_0032D7E8 a;
    B_0032D7E8 b;
    f32 s;
    u8 *d;
    u8 *r;
    long v;
    s32 alpha;

    func_L01_0032CEB8_0032D7E8((char *)&a);
    v = func_00389598(0xB);
    a.l70 = 0;
    a.l78 = v;
    a.l80 = 0x0000FF9000000260L;
    a.l88 = 0x0000008000000048L;
    alpha = func_00382498(0x30, 0x40);
    r = D_L01_002C5600_0032D7E8 + D_001425C0[0x15] * 0xF0;
    if (r[1] >= 2) {
        a.col[0] = a.col[1] = a.col[2] = a.col[3] = (alpha << 24) + 0x806060;
    } else {
        a.col[0] = a.col[1] = a.col[2] = a.col[3] = (alpha << 24) + 0x80;
    }
    d = D_L01_001E2880_0032D7E8;
    b.rot.w = 0.0f;
    b.rot.z = func_0038D160(((vu0_v4 *)(d + 0x140))->x - pos->x, ((vu0_v4 *)(d + 0x140))->y - pos->y);
    b.rot.y = -func_0038D160(func_0038CF38(pos, d + 0x140), ((vu0_v4 *)(d + 0x140))->z - pos->z);
    b.rot.x = func_00382538();
    func_0038D328(&b, &b.rot);
    vec_sub_ba(&b.dir, d + 0x140, pos);
    func_0038CF68(&b.dir, &b.dir, 0.25f);
    b.m[3].x = pos->x;
    b.m[3].y = pos->y;
    b.m[3].z = pos->z;
    b.m[3].w = 1.0f;
    s = func_003824E0(0.03f, 0.0625f);
    func_0038CE20(&a.m[0], &a.m[0], s);
    func_0038CE20(&a.m[1], &a.m[1], s);
    func_0038CE20(&a.m[2], &a.m[2], s);
    func_0038CE20(&a.m[3], &a.m[3], s);
    func_003D2DA0(&a, &b, 0);
    func_0038CE20(&a.m[0], &a.m[0], 0.5f);
    func_0038CE20(&a.m[1], &a.m[1], 0.5f);
    func_0038CE20(&a.m[2], &a.m[2], 0.5f);
    func_0038CE20(&a.m[3], &a.m[3], 0.5f);
    a.col[0] = a.col[1] = a.col[2] = a.col[3] = (func_00382498(0x40, 0x7F) << 24) + 0x1F1F1F;
    func_003D2DA0(&a, &b, 0);
    func_0038CE20(&a.m[0], &a.m[0], 0.5f);
    func_0038CE20(&a.m[1], &a.m[1], 0.5f);
    func_0038CE20(&a.m[2], &a.m[2], 0.5f);
    func_0038CE20(&a.m[3], &a.m[3], 0.5f);
    a.col[0] = a.col[1] = a.col[2] = a.col[3] = (func_00382498(0x40, 0x7F) << 24) + 0x7F7F7F;
    func_003D2DA0(&a, &b, 0);
}
/* localdecomp:end func_L01_0032D7E8 */

INCLUDE_ASM("asm/levels", func_L01_0032DB08);

/* localdecomp:start func_L01_0032DED0 */
extern vu0_v4 D_L01_001E29C0;
extern f32 D_L01_001DCE90;
__asm__(".extern D_L01_001DCE90, 4");
extern f32 D_L01_001DCE94;
__asm__(".extern D_L01_001DCE94, 4");
extern f32 D_L01_001DCE98;
__asm__(".extern D_L01_001DCE98, 4");
extern f32 D_L01_001DCE9C;
__asm__(".extern D_L01_001DCE9C, 4");
extern f32 D_L01_001DCEA0;
__asm__(".extern D_L01_001DCEA0, 4");
extern f32 D_L01_001DCEA4;
__asm__(".extern D_L01_001DCEA4, 4");
extern f32 D_L01_001DCEA8;
__asm__(".extern D_L01_001DCEA8, 4");
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
extern void func_L01_004C7D98(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_0013D3E0(void);
extern u8 *func_L01_0046B458(void *, s32, f32, f32, u32, s32, s32, void *, f32, s32);

void func_L01_0032DED0(u8 *pos, s32 count) {
    vu0_v4 velocity, at, delta, axis, base, t50;
    f32 size, speed;
    s32 spin, i;
    u32 colour;
    u8 *p;
    u8 *r;

    vec_sub_ab(&delta, &D_L01_001E29C0, pos);
    func_L01_004C7D98(pos, &axis);
    speed = func_0038CE68(&axis, &delta);
    func_0038CE20(&base, &axis, speed);
    vec_sub_ab(&delta, &delta, &base);
    for (i = 0; i < count; i++) {
            colour = 0x7F000080;
            size = func_003824E0(D_L01_001DCEA4, D_L01_001DCEA8);
            spin = func_00382468(2);
            if (spin == 0) spin--;
            func_0038D890(&velocity, &delta, &axis, func_003824E0(-1.0471976f, 1.0471976f));
            speed = func_003824E0(D_L01_001DCE90, D_L01_001DCE94) * 0.020000001f;
            func_0038CF68(&velocity, &velocity, speed);
            velocity.z = func_003824E0(D_L01_001DCE98, D_L01_001DCE9C) * 0.020000001f;
            *(vu0_q *)&at = *(vu0_q *)pos;
            at.x += func_L01_00443A18(0.0f, 0.15f);
            at.y += func_L01_00443A18(0.0f, 0.15f);
            at.z += func_L01_00443A18(0.0f, 0.15f);
            r = D_L01_002C5600 + D_001425C0[0x15] * 0xF0;
            if (r[1] >= 2) colour = 0x7F806060;
            if ((func_0013D3E0() & 1) == 0) {
                func_0038CE20(&velocity, &velocity, 1.5f);
                p = func_L01_0046B458(&at, 0x32, size * 0.1f * 3.5f, size, colour, 0, spin, &velocity, D_L01_001DCEA0 * 1.44f, 1);
                if (p) p[9] = 0x74;
                p = func_L01_0046B458(&at, 0x32, size * 0.07f * 3.5f, size * 0.7f, 0x7F7F7F7F, 1, -spin, &velocity, D_L01_001DCEA0 * 1.44f, 1);
                if (p) p[9] = 0x74;
            } else {
                vec_sub_ba(&t50, &D_L01_001E29C0, &at);
                func_0038CF68(&t50, &t50, speed);
                vec_add_ab(&velocity, &velocity, &t50);
                p = func_L01_0046B458(&at, 0x21, size * 0.1f * 20.5f, size, colour, 0, spin, &velocity, D_L01_001DCEA0 * 1.44f, 1);
                if (p) p[9] = 0x74;
                p = func_L01_0046B458(&at, 0x21, size * 0.07f * 20.5f, size * 0.7f, 0x7F7F7F7F, 1, -spin, &velocity, D_L01_001DCEA0 * 1.44f, 1);
                if (p) p[9] = 0x74;
            }
        }
}
/* localdecomp:end func_L01_0032DED0 */

/* localdecomp:start func_L01_0032E2B0 */
void func_L01_0032E2B0(void *arg0) {
    if ((u8) (*(u8 *)((u8 *)arg0 + 0x20)) < 8U) {
        *(u8 *)((u8 *)arg0 + 0x20) = 8U;
    }
}
/* localdecomp:end func_L01_0032E2B0 */

INCLUDE_ASM("asm/levels", func_L01_0032E2D0);

/* localdecomp:start func_L01_0032EE48 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x18];
    s32 m18;
    u8 pad1c[0x20 - 0x1C];
    vu0_q m20;
} G_32EE48_0032EE48;
extern G_32EE48_0032EE48 D_L01_001EAA00_0032EE48;
extern s32 D_001A71A0[];
extern void func_L01_004C7D98_0032EE48(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D5630(void);
extern s32 func_L01_003FB640_0032EE48(f32 *, s32, u8 *, f32);

s32 func_L01_0032EE48(vu0_q *out, f32 *pos, u8 *obj, f32 dist) {
    vu0_v4 v;
    vu0_v4 w;
    u32 r;
    u8 *t;
    s32 p;
    s32 m;
    vu0_q *q;

    func_L01_004C7D98_0032EE48(obj + 0x10, &v);
    func_0038CE20(&v, &v, -dist);
    vec_add_ba(&w, pos, &v);
    if (func_003D3CB0(pos, &w, 0x10, obj, 0) != 0) {
        r = func_003D5630();
        if (r >= 2) {
            if (r != 11 && r != 7 && r != 13 && r != 14) {
                t = *(u8 **)(obj + 0x68);
                q = &D_L01_001EAA00_0032EE48.m20;
                *out = *q;
                p = D_001A71A0[0];
                if (D_L01_001EAA00_0032EE48.m18 != p) {
                    if (func_L01_003FB640_0032EE48(pos, 2, (u8 *)p, 0.9f) != 0) {
                        return 0;
                    }
                    m = D_L01_001EAA00_0032EE48.m18;
                    if (m != 0 && t != 0) {
                        *(s32 *)(t + 0x70) = m;
                    } else {
                        *(s32 *)(t + 0x70) = 0;
                    }
                    return 1;
                }
            }
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0032EE48 */

INCLUDE_ASM("asm/levels", func_L01_0032EF88);

INCLUDE_ASM("asm/levels", func_L01_0032F020);

/* localdecomp:start func_L01_0032F0D8 */
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_003FB640(f32 *, s32, u8 *, f32);
extern s32 D_L01_001EAA1C[];

void func_L01_0032F0D8(u8 *a0) {
    f32 v[4];

    func_003C2F58(a0, 0, v);
    if (func_L01_003FB640(v, 2, a0, 0.25f) && D_L01_001EAA1C[0] > 0) {
        a0[32] = 8;
    }
}
/* localdecomp:end func_L01_0032F0D8 */

INCLUDE_ASM("asm/levels", func_L01_0032F138);

INCLUDE_ASM("asm/levels", func_L01_0032F1B8);

/* localdecomp:start func_L01_0032F3E0 */
#include "vu0.h"

extern u8 *func_00382348(void *);
extern void func_L01_004C7D98_0032F3E0(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_0040EE50_0032F3E0(void *, void *);
extern void func_0038D000(void *, void *, void *);

void func_L01_0032F3E0(u8 *a0) {
    vu0_v4 pos, axis, at, d;
    vu0_v4 m[3];
    u8 *s;
    u8 *t;
    u8 *p;

    s = *(u8 **)(a0 + 0x68);
    t = func_00382348(*(void **)(s + 0x64));
    func_L01_004C7D98_0032F3E0(a0 + 0x10, &axis);
    *(vu0_q *)&pos = *(vu0_q *)(*(u8 **)(s + 0x64) + 0x10);
    if (t != 0) {
        func_0038CE20(&d, *(u8 **)(s + 0x64) + 0xE0, *(f32 *)(t + 0x10));
        vec_add_ab(&pos, &pos, &d);
    }
    p = *(u8 **)(s + 0x64);
    if (p == 0 || p[0x20] == 0xFE || p[0x20] == 0xFD || !(*(u16 *)(p + 0x34) & 0x1000)) {
        a0[0x20] = 3;
        *(u8 **)(s + 0x64) = 0;
    } else {
        func_003C2F58(a0, 0, &at);
        vec_sub_ab(&d, &pos, &at);
        func_L01_0040EE50_0032F3E0(m, a0 + 0xC0);
        func_0038D000(s + 0x20, &d, m);
    }
}
/* localdecomp:end func_L01_0032F3E0 */

/* localdecomp:start func_L01_0032F4E0 */
#include "vu0.h"

extern s32 D_L01_001DFB40_0032F4E0;
extern s32 D_L01_001DCEC8_0032F4E0;
__asm__(".extern D_L01_001DCEC8_0032F4E0, 4");
extern u8 D_001425C0[];
extern u8 D_L01_002C5600_0032F4E0[];
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_004C7D98_0032F4E0(void *, void *);
extern u8 *func_00382348(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_004AAC98_0032F4E0(s32, s32, void *, s32);
extern u8 *func_L01_00344A88_0032F4E0(void *, void *, u8, u8, u8, u8, u16, f32, f32, f32, f32, void *, s32, s32);

void func_L01_0032F4E0(u8 *a0) {
    vu0_v4 axis, pos, dir, base, off;
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 *t;
    u8 *m;
    u8 *r;

    if (D_L01_001DFB40_0032F4E0 & 1) {
        func_003C2F58(a0, 1, &base);
    } else {
        func_003C2F58(a0, 2, &base);
    }
    func_L01_004C7D98_0032F4E0(a0 + 0x10, &axis);
    if (*(f32 *)(v + 0x5C) == 0.0f && *(s32 *)(v + 0x50) != 0 && *(void **)(v + 0x64) != 0) {
        t = func_00382348(*(void **)(v + 0x64));
        *(vu0_q *)&pos = *(vu0_q *)(*(u8 **)(v + 0x64) + 0x10);
        if (t != 0) {
            func_0038CE20(&off, *(u8 **)(v + 0x64) + 0xE0, *(f32 *)(t + 0x10));
            vec_add_ab(&pos, &pos, &off);
        }
        vec_sub_ab(&dir, &pos, &base);
        r = D_L01_002C5600_0032F4E0 + D_001425C0[0x15] * 0xF0;
        func_0038CF68(&dir, &dir, *(f32 *)(r + 0x4C) * 0.020000001f);
        func_L01_004AAC98_0032F4E0(0, 0, a0, 0x1367);
        m = func_L01_00344A88_0032F4E0(&base, &dir, 0x50, 0xC8, 1, 0, 0x10E, 2.0f, 15.0f, 0.5f,
                              *(f32 *)(D_L01_002C5600_0032F4E0 + D_001425C0[0x15] * 0xF0 + 0x6C), *(void **)(v + 0x64), 0, 0);
        if (m != 0) {
            *(s32 *)(m + 0xB8) = *(s32 *)(v + 0x68);
        }
        *(s32 *)(v + 0x40) = (D_L01_001DCEC8_0032F4E0 * 5 + 2) / 6;
        *(s32 *)(v + 0x44) = 5;
        if (--*(s32 *)(v + 0x60) <= 0) {
            a0[0x20] = 8;
        }
        *(f32 *)(v + 0x5C) = 0.41666669f;
    }
}
/* localdecomp:end func_L01_0032F4E0 */
