#include "common.h"
#include "vu0.h"


/* localdecomp:start func_L01_0032C6B8 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x48];
    s32 w48;
} S_32C6B8m;
typedef struct {
    u8 pad0[0x68];
    S_32C6B8m *p68;
} S_32C6B8;
extern u8 *func_L01_004C80D0(s32 a0);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_003C47E8(void *, void *);
extern void func_003C2F58(void *, s32, void *);

void func_L01_0032C6B8(S_32C6B8 *a0, vu0_q *a1) {
    struct { vu0_q a, b, c, d, e, f, g; } L;
    u8 *r;

    r = func_L01_004C80D0(a0->p68->w48);
    L.a = L.d = *a1;
    L.e = 0;
    ((f32 *)&L.e)[2] = 1.0f;
    func_0038CE90(&L.b, &L.a, &L.e);
    func_0038CF68(&L.b, &L.b, 1.0f);
    func_0038CE90(&L.c, &L.b, &L.a);
    func_003C47E8(r + 0x10, &L.a);
    func_003C2F58(a0, 0, &L.f);
    func_0038D000(&L.d, a1, (u8 *)a0 + 0xC0);
    vec_add_ab(&L.g, &L.d, &L.f);
}
/* localdecomp:end func_L01_0032C6B8 */

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

/* localdecomp:start func_L01_0032CB38 */
typedef struct {
    vu0_q pos;
    vu0_q step;
    f32 timer;
    s32 owner;
    u8 pad28[8];
} Entry_32CB38;
typedef struct {
    u8 pad0[1];
    u8 tier;
    u8 pad2[0x6A];
    f32 damage;
    u8 pad70[0x80];
} Weapon_32CB38;
typedef struct {
    u8 pad0[0x18];
    u8 *hit;
    u8 pad1C[4];
    u8 point[16];
} Hit_32CB38;
typedef struct {
    vu0_q direction;
    u8 pad10[8];
    u8 type;
    u8 mode;
    u16 source;
    u8 pad1C[0x14];
} Damage_32CB38;

extern Entry_32CB38 D_L01_00277090_0032CB38[];
extern Weapon_32CB38 D_L01_002C5600_0032CB38[];
extern Hit_32CB38 D_L01_001EAA00_0032CB38;
extern u8 D_L01_001EAA20_0032CB38[];
extern u8 D_001425C0[];
extern struct { u8 pad[0x25C0]; u8 *moby; } D_001A4BE0;
extern s32 func_L01_0040E050(void *);
extern s32 func_L01_004CB2D8(void);
extern void func_L01_004CAB30(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446978(void *, void *);
extern void func_L01_0034C9F0(void *, s32, void *);
extern void func_L01_0032DED0(u8 *, s32);

void func_L01_0032CB38(u8 *moby) {
    struct { vu0_q previous, direction; Damage_32CB38 damage; } frame;
    s32 i;
    u8 *vars = *(u8 **)(moby + 0x68);

    for (i = 0; i < 100; i++) {
        Entry_32CB38 *e;
        f32 *pos;
        u8 *hit;
        Weapon_32CB38 *weapon;
        f32 dmg;

        if (D_L01_00277090_0032CB38[i].owner != (s32)moby)
            continue;
        e = &D_L01_00277090_0032CB38[i];
        pos = (f32 *)&e->pos;
        if (func_L01_0040E050(&e->timer) ||
            pos[0] < 2.0f || pos[0] > 1021.0f ||
            pos[1] < 2.0f || pos[1] > 1021.0f ||
            pos[2] < 2.0f || pos[2] > 1021.0f) {
            e->owner = 0;
            (*(u16 *)(vars + 0x66))--;
            continue;
        }
        frame.previous = e->pos;
        vec_add_ab(&e->pos, &e->pos, &e->step);
        if (func_L01_004CB2D8())
            func_L01_004CAB30(e, e);
        if (!func_003D3CB0(&frame.previous, e, 0, moby, 0))
            continue;
        hit = D_L01_001EAA00_0032CB38.hit;
        if (hit != 0) {
        if ((*(u16 *)(hit + 0x34) & 0x1000) ||
            (*(u8 **)(hit + 0x24))[0x46] == 5) {
            if (hit != D_001A4BE0.moby && *(s16 *)(hit + 0xAA) != 0x1366) {
                func_0038CF68(&frame.direction, &e->step, 1.0f);
                weapon = &D_L01_002C5600_0032CB38[D_001425C0[0x15]];
                dmg = weapon->damage;
                if (weapon->tier >= 2)
                    func_L01_00446760(&frame.damage, moby, 0x10010000, &frame.direction, dmg);
                else
                    func_L01_00446760(&frame.damage, moby, 0x10000, &frame.direction, dmg);
                frame.damage.type = 1;
                frame.damage.mode = 3;
                frame.damage.source = *(u16 *)(moby + 0xAA);
                func_L01_00446978(hit, &frame.damage);
                func_L01_0034C9F0(hit, 0x15, *(void **)(moby + 0xB8));
                e->owner = 0;
                (*(u16 *)(vars + 0x66))--;
                func_L01_0032DED0(D_L01_001EAA20_0032CB38, 6);
                continue;
            }
        }
        e->owner = 0;
        (*(u16 *)(vars + 0x66))--;
        func_L01_0032DED0(D_L01_001EAA20_0032CB38, 3);
        } else {
            e->owner = 0;
            (*(u16 *)(vars + 0x66))--;
            func_L01_0032DED0(D_L01_001EAA00_0032CB38.point, 3);
        }
    }
}
/* localdecomp:end func_L01_0032CB38 */

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

/* localdecomp:start func_L01_0032D348 */
typedef struct {
    vu0_v4 m[4];
    u32 col[4];
    f32 uv[8];
    long l70;
    long l78;
    long l80;
    long l88;
} A_0032D348;

extern u8 D_001425C0[];
extern u8 D_L01_002C5600_0032D348[];
extern vu0_v4 D_L01_001E29C0;
extern void func_L01_0032CEB8_0032D348(char *);
extern void func_L01_0032CF90_0032D348(void *, void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_0013D3E0(void);
extern long func_00389598(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);

void func_L01_0032D348(M_32CAB0 *m) {
    A_0032D348 a;
    A_0032D348 b;
    vu0_v4 mat[4];
    vu0_v4 p160;
    vu0_v4 p170;
    vu0_v4 t180;
    vu0_v4 v190;
    vu0_v4 v1a0;
    u8 *q;
    u8 *r;
    u8 *vars;

    vars = m->w68;
    func_003C2F58(m, 1, &t180);
    p160 = t180;
    func_0038CF68(&p170, vars + 0x30, func_003824E0(2.0f, 4.0f));
    func_0038D000(&p170, &p170, (u8 *)m + 0xC0);
    vec_add_ab(&p170, &p170, &t180);
    func_L01_0032CF90_0032D348(m, &p160);
    a.l78 = func_00389598(0x17);
    a.l70 = 0;
    a.l80 = 0x0000FF9000000260L;
    a.l88 = 0x0000008000000048L;
    q = D_L01_002C5600_0032D348 + D_001425C0[0x15] * 0xF0;
    if (q[1] >= 2) {
        a.col[2] = a.col[3] = 0x803010;
        a.col[0] = a.col[1] = 0x7F803010;
    } else {
        a.col[2] = a.col[3] = 0x103080;
        a.col[0] = a.col[1] = 0x7F103080;
    }
    b.l78 = func_00389598(0x17);
    b.l80 = 0x0000FF9000000260L;
    b.l88 = 0x0000008000000048L;
    b.l70 = 0;
    r = D_L01_002C5600_0032D348 + D_001425C0[0x15] * 0xF0;
    if (r[1] >= 2) {
        b.col[2] = b.col[3] = 0x803010;
        b.col[0] = b.col[1] = 0x3F803010;
    } else {
        b.col[2] = b.col[3] = 0x103080;
        b.col[0] = b.col[1] = 0x3F103080;
    }
    *(vu0_q *)&v190 = 0;
    *(vu0_q *)&v1a0 = 0;
    v190.w = 1.0f;
    v1a0.w = 1.0f;
    v190.z = func_003824E0(0.1f, 0.3f);
    v1a0.z = v190.z + v190.z;
    func_L01_0032CEB8_0032D348((char *)&a);
    func_L01_0032CEB8_0032D348((char *)&b);
    if ((func_0013D3E0() & 1) == 0) {
        a.uv[0] = 0.0f;
        a.uv[1] = 0.0f;
        a.uv[2] = 0.0f;
        a.uv[3] = 1.0f;
        a.uv[4] = 1.0f;
        a.uv[5] = 0.0f;
        a.uv[6] = 1.0f;
        a.uv[7] = 1.0f;
        b.uv[0] = 0.0f;
        b.uv[1] = 0.0f;
        b.uv[2] = 0.0f;
        b.uv[3] = 1.0f;
        b.uv[4] = 1.0f;
        b.uv[5] = 0.0f;
        b.uv[6] = 1.0f;
        b.uv[7] = 1.0f;
    } else {
        a.uv[0] = 0.0f;
        a.uv[1] = 1.0f;
        a.uv[2] = 0.0f;
        a.uv[3] = 0.0f;
        a.uv[4] = 1.0f;
        a.uv[5] = 1.0f;
        a.uv[6] = 1.0f;
        a.uv[7] = 0.0f;
        b.uv[0] = 0.0f;
        b.uv[1] = 1.0f;
        b.uv[2] = 0.0f;
        b.uv[3] = 0.0f;
        b.uv[4] = 1.0f;
        b.uv[5] = 1.0f;
        b.uv[6] = 1.0f;
        b.uv[7] = 0.0f;
    }
    vec_sub_ba(&mat[0], &p170, &p160);
    func_0038CF68(&mat[0], &mat[0], 1.0f);
    vec_sub_ba(&mat[1], &D_L01_001E29C0, &p160);
    func_0038CE90(&mat[2], &mat[1], &mat[0]);
    func_0038CF68(&mat[2], &mat[2], 1.0f);
    func_0038CE90(&mat[1], &mat[0], &mat[2]);
    mat[3] = p160;
    a.m[0] = v190;
    b.m[0] = v1a0;
    func_0038CE20(&a.m[1], &a.m[0], -1.0f);
    func_0038CE20(&b.m[1], &b.m[0], -1.0f);
    func_0038D028(&a.m[0], &a.m[0], mat);
    func_0038D028(&a.m[1], &a.m[1], mat);
    func_0038D028(&b.m[0], &b.m[0], mat);
    func_0038D028(&b.m[1], &b.m[1], mat);
    v190.z = v190.z * 0.15f;
    mat[3] = p170;
    v1a0.z = v190.z + v190.z;
    a.m[2] = v190;
    b.m[2] = v1a0;
    func_0038CE20(&a.m[3], &a.m[2], -1.0f);
    func_0038CE20(&b.m[3], &b.m[2], -1.0f);
    func_0038D028(&a.m[2], &a.m[2], mat);
    func_0038D028(&a.m[3], &a.m[3], mat);
    func_0038D028(&b.m[2], &b.m[2], mat);
    func_0038D028(&b.m[3], &b.m[3], mat);
    func_003D2DA0(&a, 0, 0);
    func_003D2DA0(&b, 0, 0);
}
/* localdecomp:end func_L01_0032D348 */

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

/* localdecomp:start func_L01_0032DB08 */
typedef struct {
    vu0_v4 m[4];
    u32 col[4];
    f32 uv[8];
    long l70;
    long l78;
    long l80;
    long l88;
} A_0032DB08;

extern u8 D_001425C0[];
extern u8 D_L01_002C5600_0032DB08[];
extern vu0_v4 D_L01_001E29C0;
extern void func_L01_0032CEB8_0032DB08(char *);
extern void func_L01_0032D7E8_0032DB08(void *, void *);
extern long func_00389598(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);

void func_L01_0032DB08(void *m, void *arg1, void *arg2) {
    vu0_v4 *pos = arg1;
    vu0_v4 *v = arg2;
    A_0032DB08 a;
    A_0032DB08 b;
    vu0_v4 mat[4];
    vu0_v4 v160;
    vu0_v4 v170;
    u8 *q;
    u8 *r;

    a.l78 = func_00389598(0xE);
    a.col[0] = a.col[1] = 0x7F7F7F7F;
    a.l80 = 0x0000FF9000000260L;
    a.l70 = 0;
    a.l88 = 0x0000008000000048L;
    b.l78 = func_00389598(0xE);
    b.l80 = 0x0000FF9000000260L;
    b.l88 = 0x0000008000000048L;
    b.l70 = 0;
    q = D_L01_002C5600_0032DB08 + D_001425C0[0x15] * 0xF0;
    if (q[1] >= 2) {
        b.col[0] = b.col[1] = 0x7F806060;
    } else {
        b.col[0] = b.col[1] = 0x7F000080;
    }
    *(vu0_q *)&v160 = 0;
    *(vu0_q *)&v170 = 0;
    v160.z = 0.015f;
    v170.z = 0.0824999958f;
    v160.w = 1.0f;
    v170.w = 1.0f;
    func_L01_0032CEB8_0032DB08((char *)&a);
    func_L01_0032CEB8_0032DB08((char *)&b);
    func_L01_0032D7E8_0032DB08(m, pos);
    a.uv[0] = 0.0f;
    a.uv[1] = 0.0f;
    a.uv[2] = 0.0f;
    a.uv[3] = 1.0f;
    a.uv[4] = 1.0f;
    a.uv[5] = 0.0f;
    a.uv[6] = 1.0f;
    a.uv[7] = 1.0f;
    b.uv[0] = 0.0f;
    b.uv[1] = 0.0f;
    b.uv[2] = 0.0f;
    b.uv[3] = 1.0f;
    b.uv[4] = 1.0f;
    b.uv[5] = 0.0f;
    b.uv[6] = 1.0f;
    b.uv[7] = 1.0f;
    vec_sub_ba(&mat[0], v, pos);
    func_0038CF68(&mat[0], &mat[0], 1.0f);
    vec_sub_ba(&mat[1], &D_L01_001E29C0, pos);
    func_0038CE90(&mat[2], &mat[1], &mat[0]);
    func_0038CF68(&mat[2], &mat[2], 1.0f);
    func_0038CE90(&mat[1], &mat[0], &mat[2]);
    mat[3] = *pos;
    a.m[0] = v160;
    b.m[0] = v170;
    func_0038CE20(&a.m[1], &a.m[0], -1.0f);
    func_0038CE20(&b.m[1], &b.m[0], -1.0f);
    func_0038D028(&a.m[0], &a.m[0], mat);
    func_0038D028(&a.m[1], &a.m[1], mat);
    func_0038D028(&b.m[0], &b.m[0], mat);
    func_0038D028(&b.m[1], &b.m[1], mat);
    mat[3] = *v;
    r = D_L01_002C5600_0032DB08 + D_001425C0[0x15] * 0xF0;
    if (r[1] >= 2) {
        b.col[2] = b.col[3] = 0x806060;
    } else {
        b.col[2] = b.col[3] = 0x80;
    }
    v160.z = v160.z * 0.25f;
    v170.z = v160.z * 5.5f;
    a.m[2] = v160;
    b.m[2] = v170;
    func_0038CE20(&a.m[3], &a.m[2], -1.0f);
    func_0038CE20(&b.m[3], &b.m[2], -1.0f);
    func_0038D028(&a.m[2], &a.m[2], mat);
    func_0038D028(&a.m[3], &a.m[3], mat);
    func_0038D028(&b.m[2], &b.m[2], mat);
    func_0038D028(&b.m[3], &b.m[3], mat);
    func_003D2DA0(&a, 0, 0);
    func_003D2DA0(&b, 0, 0);
}
/* localdecomp:end func_L01_0032DB08 */

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

/* localdecomp:start func_L01_0032E2D0 */
typedef struct {
    vu0_v4 from, to, velocity;
    u8 *hit;
    s32 *info;
    s32 kind;
    f32 radius, step, scale;
    s32 zero48, zero4c, enabled;
    u8 *surface;
    s32 enabled58;
    f32 skin;
} Query_0032E2D0;

extern s32 D_L01_001DCE4C;
__asm__(".extern D_L01_001DCE4C, 16");
extern f32 D_L01_001DCEB0;
__asm__(".extern D_L01_001DCEB0, 4");
extern f32 D_L01_001DCEB8;
__asm__(".extern D_L01_001DCEB8, 4");
extern void *D_L01_001E1090;
__asm__(".extern D_L01_001E1090, 4");
extern void *D_L01_001E1098_0032E2D0;
__asm__(".extern D_L01_001E1098_0032E2D0, 16");
extern u8 D_L01_00278990[];
extern u8 *D_L01_00278350[];
extern f32 D_L01_002784E0[][3];
extern u8 *D_L01_001DAFEC;
extern s32 D_L01_001D673C_0032E2D0, D_L01_001D6740_0032E2D0;
__asm__(".extern D_L01_001D673C_0032E2D0, 16");
__asm__(".extern D_L01_001D6740_0032E2D0, 16");
extern u8 *D_L01_001EEA80[];
extern vu0_v4 D_001A4C60;
extern s32 D_001A71A4[];

extern void func_L01_004C7D98(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D810(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_L01_004C8688(s32, void *, s32);
extern void func_L01_004C7D40(void *, void *, f32);
extern s32 func_L01_004C7E70(Query_0032E2D0 *, s32);
extern s32 func_L01_004CB2D8(void);
extern void func_L01_004CAB30(void *, void *);
extern s32 func_L01_004CB018(void *);
extern void func_L01_004C67A0(void *, void *, s32, f32, f32, f32, f32);
extern u8 *func_L01_003016B0(void *, s32, f32, f32);
extern s32 func_L01_004CADE8(void *, void *);
extern void func_L01_0032FB80(void);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern void func_L01_00444F38(void *, s32, s32, s32, s32);
extern void func_L01_004C8668(s32);
extern void func_0038D5B0(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_L01_004395E0(void *);
extern void func_L01_0032F1B8_0032E2D0(void *);
extern s32 func_L01_004C85C8(void *, s32, f32, f32, f32);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_0038CB00(void *);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0032F4E0_0032E2D0(void *);
extern void func_L01_0032F3E0_0032E2D0(void *);
extern s32 func_L01_004C80F8(void *, s32);
extern void func_L01_0032EF88_0032E2D0(void *);
extern void func_L01_0032F020_0032E2D0(void *);
extern void func_L01_0044BB30(void *, void *, s32, f32, f32);
extern void func_L01_004C81A8(s32);
extern void func_L01_004CAE60(void *, s32);
extern void func_003C2880(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00409428(void *, void *, void *, void *, void *, s32, s32, s32, u32, u32);
extern void func_00382580(void *, f32, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern s32 func_L01_0032EE48_0032E2D0(void *, void *, void *, f32);
extern void func_L01_0032F718(void *);
extern s32 func_0038CAD0(u8 *);
extern void func_L01_0032F0D8_0032E2D0(void *);
extern void func_L01_0032F138_0032E2D0(void *);
extern void func_L01_00404A10(void (*)(void *), void *);
extern void func_L01_0032FBA0(void *);

typedef struct { u8 pad[0x100]; s32 slot[16]; } Tbl_0032E2D0;
extern Tbl_0032E2D0 D_L01_00278990_0032E2D0;
typedef struct { u8 pad0[0x80]; vu0_v4 pos; u8 pad90[0x368 - 0x90]; s16 h368; u8 pad36a[0x25C0 - 0x36A]; u8 *moby; } Hero_0032E2D0;
extern Hero_0032E2D0 D_001A4BE0_0032E2D0;
static __inline__ void copy3_0032E2D0(f32 *d, f32 *s) {
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
}
void func_L01_0032E2D0(u8 *m) {
    u8 *p = *(u8 **)(m + 0x68);
    vu0_v4 old_position;
    s32 info[2];
    vu0_v4 direction, forward, quaternion, axis, rotation[3];
    Query_0032E2D0 query;
    vu0_v4 delta, inverse[4];
    s32 collision, c, idx, n, found;
    f32 angle;
    u8 *o;
    u8 **it;

    switch (m[0x20]) {
    case 0:
        m[0x20] = 1;
        {
            s32 id = D_L01_001DCE4C;
            *(s32 *)(p + 0x6C) = id;
            D_L01_001DCE4C = (id + 1) % 100;
        }
        *(s16 *)(p + 0x90) = 150;
        *(s32 *)(m + 0x98) = 0;
    case 1:
        func_L01_004C7D98(m + 0x10, &direction);
        func_0038CF68(&forward, m + 0xE0, 1.0f);
        func_0038CE90(&axis, &forward, &direction);
        angle = func_0038CE68(&forward, &direction) * 0.5f;
        func_0038CE20(&quaternion, &axis, func_0038D0B0(angle));
        quaternion.w = func_0038D098(angle);
        func_0038D810(&quaternion, rotation);
        func_0038D5F0(m + 0xC0, rotation, m + 0xC0);
        old_position = *(vu0_v4 *)(m + 0x10);
        vec_add_ba(m + 0x10, m + 0x10, p);
        func_L01_004C8688(*(s8 *)(p + 0x4F), p, 0);
        func_L01_004C7D40(m + 0x10, p, D_L01_001DCEB0 * 0.00040000002f);
        info[0] = 0;
        info[1] = 0xC5A;
        query.from = old_position;
        query.to = *(vu0_v4 *)(m + 0x10);
        query.velocity = *(vu0_v4 *)p;
        query.info = info;
        query.radius = 0.13f;
        query.step = D_L01_001DCEB8;
        query.scale = 0.5555556f;
        query.skin = 0.0962f;
        query.hit = m;
        query.kind = 2;
        query.zero48 = 0;
        query.zero4c = 0;
        query.enabled = 1;
        query.enabled58 = 1;
        collision = func_L01_004C7E70(&query, -1);
        *(vu0_v4 *)(m + 0x10) = query.to;
        *(vu0_v4 *)p = query.velocity;
        if (func_L01_004CB2D8() != 0) {
            func_L01_004CAB30(m + 0x10, m + 0x10);
        }
        if (collision != 2) {
            break;
        }
        if (query.hit == 0 || (*(s16 *)(query.hit + 0xAA) != 0xCB && *(s16 *)(query.hit + 0xAA) != 0x1366 &&
                               *(s16 *)(query.hit + 0xAA) != 0x1367)) {
            u8 *hit;
            qzero(p);
            hit = query.hit;
            *(u8 **)(p + 0x70) = hit;
            if (hit != 0) {
                *(f32 *)(p + 0x74) = *(f32 *)(hit + 0x10);
                *(f32 *)(p + 0x78) = *(f32 *)(hit + 0x14);
                *(f32 *)(p + 0x7C) = *(f32 *)(hit + 0x18);
            }
            c = func_L01_004CB018(query.surface);
            if (c == collision) {
                *(f32 *)(p + 8) = -0.030000001f;
                m[0x20] = 7;
                if (query.surface == 0) {
                    u8 *effect;
                    func_L01_004C67A0(D_L01_001E1090, D_L01_001E1098_0032E2D0, 1, *(f32 *)(m + 0x10), *(f32 *)(m + 0x14), 0.5f, -0.35f);
                    effect = func_L01_003016B0(m + 0x10, 3, 2.0f, 1.025f);
                    if (effect != 0) {
                        effect[0x23] = 0x70;
                    }
                }
            } else if (c == 1) {
                m[0x20] = 8;
            } else {
                *(s8 *)(p + 0x4E) = func_L01_004CADE8(&D_L01_00278990_0032E2D0, m);
                func_L01_0032FB80();
                if (D_L01_00278990_0032E2D0.slot[*(s8 *)(p + 0x4E)] != 0) {
                    m[0x20] = 2;
                    func_L01_004AAC98(1, 0, m, 0x1367);
                    func_L01_00444F38(m, 1, 0, 0, 0);
                } else {
                    m[0x20] = 6;
                }
            }
            func_L01_004C8668(*(s8 *)(p + 0x4F));
            D_L01_00278350[*(s32 *)(p + 0x6C)] = D_L01_001DAFEC;
            if (D_L01_001DAFEC != 0) {
                vec_sub_ab(&delta, m + 0x10, D_L01_001DAFEC + 0x10);
                func_0038D5B0(inverse, D_L01_00278350[*(s32 *)(p + 0x6C)] + 0xC0);
                func_0038D028(&delta, &delta, inverse);
                copy3_0032E2D0(D_L01_002784E0[*(s32 *)(p + 0x6C)], (f32 *)&delta);
            }
            *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
        } else {
            func_0038CE20(p, p, 1.1f);
        }
        break;
    case 2:
        if (6.5f <= func_L01_004395E0(m)) {
            func_L01_00444F38(m, 2, 0, 0, 0);
            m[0x20] = 3;
        }
        break;
    case 3:
        func_L01_0032F1B8_0032E2D0(m);
        o = *(u8 **)(p + 0x70);
        if (o != 0) {
            if (o[0x20] == 0xFE) {
                *(s32 *)(m + 0x98) = 0;
                *(s8 *)(p + 0x4F) = func_L01_004C85C8(m, 0, 1.0f, 1.0f, 1.0f);
                m[0x20] = 1;
                *(s32 *)(p + 0x70) = 0;
            } else if (o[0x20] == 0xFD) {
                *(s32 *)(m + 0x98) = 0;
                *(s8 *)(p + 0x4F) = func_L01_004C85C8(m, 0, 1.0f, 1.0f, 1.0f);
                m[0x20] = 1;
                *(s32 *)(p + 0x70) = 0;
            }
        }
        if (D_001A4BE0_0032E2D0.h368 == 0 && D_L01_001D673C_0032E2D0 == 0 && D_L01_001D6740_0032E2D0 == 0) {
            if (400.0f < func_L01_0040E570(&D_001A4BE0_0032E2D0.pos, m + 0x10) && func_0038CB00(p + 0x90) != 0) {
                s32 j;
                found = 0;
                n = func_003D4D00(&D_001A4BE0_0032E2D0.pos, 1, D_001A4BE0_0032E2D0.moby, 0, 20.0f);
                for (j = 0; j < n; j++) {
                    o = D_L01_001EEA80[j];
                    if (o != 0 && *(u8 **)(o + 0x24) != 0 && (*(u8 **)(o + 0x24))[0x46] == 5) {
                        found = 1;
                    }
                }
                if (found != 0) {
                    *(s16 *)(p + 0x90) = (func_00382498(180, 240) * 5 + 2) / 6;
                    func_L01_004450F0(m, 10, -1);
                }
            }
        }
        break;
    case 4:
        func_L01_0032F3E0_0032E2D0(m);
        func_L01_0032F4E0_0032E2D0(m);
        o = *(u8 **)(p + 0x70);
        if (o != 0) {
            if (o[0x20] == 0xFE) {
                *(s32 *)(m + 0x98) = 0;
                *(s8 *)(p + 0x4F) = func_L01_004C85C8(m, 0, 1.0f, 1.0f, 1.0f);
                m[0x20] = 1;
                *(s32 *)(p + 0x70) = 0;
            } else if (o[0x20] == 0xFD) {
                *(s32 *)(m + 0x98) = 0;
                *(s8 *)(p + 0x4F) = func_L01_004C85C8(m, 0, 1.0f, 1.0f, 1.0f);
                m[0x20] = 1;
                *(s32 *)(p + 0x70) = 0;
            }
        }
        break;
    case 5:
        if (func_L01_004395E0(m) <= 1.0f) {
            func_L01_00444F38(m, 0, 0, 0, 0);
            *(f32 *)(m + 0x48) = 1.0f;
            m[0x20] = 6;
        }
        break;
    case 6:
        if (D_L01_00278990_0032E2D0.slot[*(s8 *)(p + 0x4E)] != 0) {
            m[0x20] = 2;
            func_L01_004AAC98(1, 0, m, 0x1367);
            func_L01_00444F38(m, 1, 0, 0, 0);
            *(s32 *)(p + 0x48) = func_L01_004C80F8(m, 0);
        }
        break;
    case 7:
        func_L01_0032EF88_0032E2D0(m);
        func_L01_0032F020_0032E2D0(m);
        break;
    case 8:
        func_L01_004AAC98(3, 0, m, 0x1367);
        func_L01_0044BB30(m, m + 0x10, -1, 0.5f, 13.0f);
        m[0x20] = 9;
        *(u16 *)(m + 0x34) = *(u16 *)(m + 0x34) | 0x41;
        break;
    case 9:
        if (*(s32 *)(p + 0x48) != -1) {
            func_L01_004C81A8(*(s32 *)(p + 0x48));
        }
        if (*(s8 *)(p + 0x4E) != -1) {
            func_L01_004CAE60(&D_L01_00278990_0032E2D0, *(s8 *)(p + 0x4E));
        }
        func_003C2880(m);
        return;
    case 11:
        if (*(s16 *)(p + 0x9E) == 2) {
            func_L01_004450F0(m, 3, -1);
            break;
        }
        if ((*(unsigned long *)(p + 0x98) & 0xFFFFFFFF00000000UL) == 0x0001002100000000UL) {
            func_003A52A0(5, 0, m);
        }
        func_L01_00409428(m, p + 0x9C, p + 0x9E, p + 0x80, m + 0xF0, 2, 3, 0x25, 0xFF8040, 0x8F1010);
        break;
    case 10:
        func_00382580(&delta, 3.0f, 6.5f);
        vec_add_ab(&delta, &delta, &D_001A4C60);
        if (delta.z < D_001A4C60.z) {
            delta.z = D_001A4C60.z;
        }
        delta.z = func_003C3D30(&delta, 0, 0, 0.5f) + 1.0f;
        if (func_L01_0032EE48_0032E2D0(p + 0x80, &delta, m, 10.0f) != 0 &&
            400.0f < func_L01_0040E570(&D_001A4C60, m + 0x10) && func_L01_004CB2D8() == 0) {
            func_L01_004450F0(m, 11, -1);
            func_003A52A0(5, 0, m);
            *(s16 *)(p + 0x9E) = 0;
            *(s16 *)(p + 0x9C) = 0x25;
            break;
        }
        func_L01_004450F0(m, 3, -1);
        break;
    case 12:
        break;
    default:
        break;
    }
    if (m[0x20] >= 2 && D_L01_00278350[*(s32 *)(p + 0x6C)] != 0) {
        copy3_0032E2D0((f32 *)&direction, D_L01_002784E0[*(s32 *)(p + 0x6C)]);
        direction.w = 0.0f;
        func_0038D000(&direction, &direction, D_L01_00278350[*(s32 *)(p + 0x6C)] + 0xC0);
        vec_add_ab(m + 0x10, D_L01_00278350[*(s32 *)(p + 0x6C)] + 0x10, &direction);
    }
    if (m[0x20] == 3 || m[0x20] == 4) {
        func_L01_0032F718(m);
    }
    func_L01_0040E050(p + 0x5C);
    if (func_0038CAD0(p + 0x40) != 0 || D_001A71A4[0] == 0x74) {
        if (m[0x20] != 9) {
            m[0x20] = 8;
        }
    }
    if (m[0x20] == 3 || m[0x20] == 4) {
        func_L01_0032F0D8_0032E2D0(m);
        if (D_L01_00278990_0032E2D0.slot[*(s8 *)(p + 0x4E)] == 0) {
            func_L01_00444F38(m, 1, 9, 0, 0);
            m[0x20] = 5;
            *(f32 *)(m + 0x48) = -1.0f;
            func_L01_004C81A8(*(s32 *)(p + 0x48));
            *(s32 *)(p + 0x48) = -1;
            *(s16 *)(p + 0x4C) = 1;
            *(s32 *)(p + 0x50) = 0;
            *(s32 *)(p + 0x44) = 0;
            *(s32 *)(p + 0x64) = 0;
            *(vu0_v4 *)(p + 0x30) = *(vu0_v4 *)(p + 0x10);
            *(vu0_v4 *)(p + 0x20) = *(vu0_v4 *)(p + 0x10);
        }
    }
    if (m[0x20] < 8 && *(u8 **)(p + 0x70) != 0) {
        if (*(s32 *)(*(u8 **)(p + 0x70) + 0x24) != 0) {
            func_L01_0032F138_0032E2D0(m);
        } else {
            *(s32 *)(p + 0x70) = 0;
        }
    }
    func_L01_00404A10(func_L01_0032FBA0, m);
}
/* localdecomp:end func_L01_0032E2D0 */

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

/* localdecomp:start func_L01_0032EF88 */
#include "vu0.h"
extern float D_L01_001DCEB0;
__asm__(".extern D_L01_001DCEB0, 4");
extern void func_L01_004C7D40(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    vu0_v4 *vel;
} GeObj;
void func_L01_0032EF88(GeObj *p) {
    vu0_v4 old;
    vu0_v4 *v = p->vel;
    old = p->pos;
    vec_add_ab(&p->pos, &p->pos, v);
    func_L01_004C7D40(&p->pos, v, D_L01_001DCEB0 * 0.00040000002f * 0.1f);
    if (func_003D3CB0(&old, &p->pos, 0x10, p, 0) != 0) {
        p->b20 = 8;
    }
}
/* localdecomp:end func_L01_0032EF88 */

/* localdecomp:start func_L01_0032F020 */
extern s32 func_00382468(s32);
extern f32 func_003C3EC8(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_L01_00468678(s32, s32, f32, f32, s32);

void func_L01_0032F020(u8 *a0) {
    f32 v[4];
    f32 h;
    u8 *s = *(u8 **)(a0 + 0x68);

    if (func_00382468(4) != 0) {
        return;
    }
    h = func_003C3EC8(a0 + 0x10, v);
    func_0038CE20(v, s, 0.25f);
    func_L01_00468678((s32)(a0 + 0x10), (s32)v, func_003824E0(0.05f, 0.1f) * 210000.0f, h, 0x88A0A0A0);
}
/* localdecomp:end func_L01_0032F020 */

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

/* localdecomp:start func_L01_0032F138 */
extern s32 func_L01_0044C638(u8 *, s32, u8 *, u8 *, u8 *, u8 *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern void *D_L01_001EAA18[];

void func_L01_0032F138(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);

    func_L01_0044C638(a0, *(s32 *)(v + 0x70), a0 + 0x10, a0 + 0xF0, a0 + 0x10, a0 + 0xF0);
    if (D_001D545C == 7) {
        func_003C3D30(a0 + 0x10, 0, 0, 0.5f);
        if (D_L01_001EAA18[0] == 0) {
            *(s32 *)(v + 0x70) = 0;
        }
    }
}
/* localdecomp:end func_L01_0032F138 */

/* localdecomp:start func_L01_0032F1B8 */
typedef struct { s32 w[3]; } Params_0032F1B8;
typedef struct { f32 x, y, z, w; } Vec_0032F1B8;
typedef struct {
    u8 p0[0x10];
    vu0_q q10;
    Vec_0032F1B8 v20;
    vu0_q q30;
    u8 p40[0xC];
    s16 h4C;
    u8 p4E[6];
    s32 w54;
    u8 p58[4];
    s32 w5C;
    u8 *w60;
    u8 *w64;
    u8 p68[4];
} S_0032F1B8;
extern Params_0032F1B8 D_L01_001DCED8;
extern u8 D_L01_001DAFF0;
__asm__(".extern D_L01_001DAFF0, 16");
extern f32 D_L01_001DCEC4;
__asm__(".extern D_L01_001DCEC4, 4");
extern void func_L01_004C7D98(void *, void *);
extern void func_003C2F58(void *, s32, void *);
extern u8 *func_L01_004501E8(void *, void *, f32, f32, f32, void *, s32, s32, s32, f32, f32, s32, void *, s32, s32, s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C48A8(void *, void *);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_00382760(void *, f32, f32, f32);

void func_L01_0032F1B8(u8 *self) {
    S_0032F1B8 *s = *(S_0032F1B8 **)(self + 0x68);
    vu0_v4 v20;
    vu0_v4 pos;
    Params_0032F1B8 p;
    vu0_v4 quat;
    vu0_v4 m[4];
    vu0_v4 axis;
    Vec_0032F1B8 at;
    f32 a;
    f32 r;

    func_L01_004C7D98(self + 0x10, &v20);
    func_003C2F58(self, 0, &pos);
    if (s->w64 == 0) {
        p = D_L01_001DCED8;
        if (D_L01_001DAFF0 != 0) {
            s->w64 = func_L01_004501E8(&pos, self + 0xC0, 6.2831855f, 6.2831855f, 35.0f, &at, 0, 0, 0, 0.0f, 0.0f, 0, &p, 1, -1, 0);
        } else {
            s->w64 = func_L01_004501E8(&pos, self + 0xC0, 6.2831855f, 6.2831855f, D_L01_001DCEC4, &at, 0, 0, 0, 0.0f, 0.0f, 0, &p, 1, -1, 0);
        }
        if (s->w64 != 0) {
            self[0x20] = 4;
            s->w5C = 0;
        }
    }
    if (s->h4C != 0 || s->w64 != 0) {
        if (s->w64 == 0) {
            *(vu0_q *)&axis = 0;
            axis.z = 1.0f;
            m[0] = *(vu0_v4 *)&s->q30;
            func_0038CE90(&m[1], &m[0], &axis);
            func_0038CF68(&m[1], &m[1], 1.0f);
            func_0038CE90(&m[2], &m[1], &m[0]);
            m[3].x = 0.0f;
            m[3].y = 0.0f;
            m[3].z = 0.0f;
            m[3].w = 1.0f;
            func_003C48A8(&m[0], &quat);
            r = func_L01_00443A18(0.7853982f, 1.5707964f);
            a = func_0038DAB8(quat.z, r);
            r = func_003824E0(-0.1f, 0.45f);
            func_00382760(&s->v20, 1.0f, a, r);
        }
        s->h4C = 0;
        s->w54 = 0;
        s->q10 = s->q30;
    }
}
/* localdecomp:end func_L01_0032F1B8 */

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
