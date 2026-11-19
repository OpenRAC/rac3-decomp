#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L20_003F1A78);

/* localdecomp:start func_L20_003F21A8 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003F21A8;

extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_0044A7D0(u8 *);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern s32 func_00382468(s32);

u8 *func_L20_003F21A8(u8 *a0, V_003F21A8 pos, V_003F21A8 dir, u8 *target) {
    V_003F21A8 tmp;
    u8 *q;
    s32 spin;
    u8 *m;
    V_003F21A8 *d = &dir;

    m = func_003C24B0(0x1D85, 0x70);
    if (m != 0) {
        func_L01_00456160(m, a0);
        *(V_003F21A8 *)(m + 0x10) = pos;
        func_L01_0044A7D0(m);
        q = *(u8 **)(m + 0x68);
        *(V_003F21A8 *)q = dir;
        *(V_003F21A8 *)(q + 0x10) = dir;
        *(f32 *)(q + 8) = func_0038DAB8(*(f32 *)(q + 8), func_L01_00443A18(2.0f, 25.0f) * 0.017453292f);
        *(f32 *)(m + 0xF4) = -func_0038D160(func_0038CED8(d), d->z);
        *(f32 *)(m + 0xF8) = func_0038D160(d->x, d->y);
        *(u8 **)(q + 0x2C) = target;
        if (func_00382468(30) == 0) {
            spin = 1;
            *(s32 *)(q + 0x20) = spin;
        } else {
            func_00382468(2);
            spin = -1;
            *(s32 *)(q + 0x20) = spin;
        }
    }
    return m;
}
/* localdecomp:end func_L20_003F21A8 */

/* localdecomp:start func_L20_003F22C0 */
typedef struct {
    vu0_v4 vel;
    f32 gravity, radius;
    s32 id;
    u8 pad1C[4];
    f32 angle0, angle1;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[4];
    s16 h34, h36, h38, h3A;
    s32 i3C;
    s16 timer, hits;
    u8 pad44[8];
    f32 scale;
    u8 pad50[0xC70-0x50];
    vu0_v4 vectors[12];
    f32 rates[12];
    u8 padD60[0x10];
    vu0_v4 base;
} S_003F22C0;
typedef struct {
    u8 pad0[0x10]; vu0_v4 pos;
    u8 state; u8 pad21[0x47];
    S_003F22C0 *s;
    u8 pad6C[0x29]; u8 phase;
    u8 pad96[0x22]; s32 collision;
    u8 padBC[0x3C]; f32 angle;
} M_003F22C0;
typedef struct { u8 pad0[0xD0]; u8 active; u8 padD1[0xB]; void *owner; } E_003F22C0;
extern vu0_v4 D_L20_001D66B0 __attribute__((section(".sdata")));
extern u8 *D_L20_002202B4 __attribute__((section(".data")));
__asm__(".extern D_L20_002202B4, 16");
extern u8 D_001A30B0[];
extern vu0_v4 D_L20_001E9BE0;
extern vu0_v4 D_001A4CB0;
extern vu0_v4 D_L20_001E2E00;
extern s32 D_L20_001DF404;
__asm__(".extern D_L20_001DF404, 4");
void func_L20_003F22C0(M_003F22C0 *m) {
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern s32 func_003A52A0(s32, s32, void *);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_003A4F28(s32);
    extern s32 func_L04_00325460(void *, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
    extern void func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);
    extern void func_003C2880(void *);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern f32 func_00382538(void);
    extern void func_0038D890(void *, void *, void *, f32);
    extern void func_L20_003F2918(void *);
    extern s32 func_0038CB00(s16 *);
    extern void func_L01_00404A10(void (*)(void *), void *);
    extern void func_L20_003F3F28(void *);
    extern void func_L20_003F3FF8(void *);
    extern void func_L20_003F3528(void *);
    extern void func_L20_003F32D0(void *);
    S_003F22C0 *s = m->s;
    vu0_v4 old, delta;
    vu0_v4 *position = &m->pos;
    u8 *particle;
    s32 random;
    f32 size;
    s32 i;
    E_003F22C0 *entry;
    random = func_00382468(40);
    size = func_003824E0(500.0f, 1500.0f);
    particle = func_L01_0046A610(position, &D_L20_001D66B0, 33, 127, 0x101010, random,
        672000.0f, size, 1.0f, 0.0f, 0.0f);
    if (particle) {
        u8 color = D_L20_002202B4[0];
        particle[3] = 0x44;
        particle[2] = color;
    }
    if (s->id == -1 || (entry = (E_003F22C0 *)(D_001A30B0 + (s->id << 7)))->owner != m || !entry->active) {
        s->id = func_003A52A0(0, 4, m);
    }
    switch (m->state) {
    case 0:
        old = m->pos;
        vec_add_ab(&m->pos, &m->pos, &s->vel);
        s->vel.z -= s->gravity;
        if (func_003D3CB0(&old, &m->pos, 0, m->collision, 0)) {
            m->pos = D_L20_001E9BE0;
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 1:
        if (s->id != -1) {
            entry = (E_003F22C0 *)(D_001A30B0 + (s->id << 7));
            if (entry->owner == m && entry->active) func_003A4F28(s->id);
        }
        s->id = -1;
        func_003A52A0(1, 0, m);
        func_L04_00325460(&m->pos, 1.0f, 0, 25, 20, 20, 20, 45, 1, 1, 0, 0, 0, 20.0f);
        func_L01_00446780(m, &m->pos, 1, 0, 1, 0, 2.0f, s->radius, 1.0f);
        func_003C2880(m);
        return;
    }
    s->angle0 = func_0038DAB8(s->angle0, 0.034906588f);
    s->angle1 = func_0038DAB8(s->angle1, 0.10471976f);
    switch (m->phase) {
    case 0:
        s->base = D_001A4CB0;
        for (i = 0; i < 12; i++) {
            s->rates[i] = func_003824E0(0.017453294f, 0.05235988f);
            s->scale = 2.0f;
            old.x = func_0038D098(m->angle);
            old.y = func_0038D0B0(m->angle);
            old.z = 0.0f;
            vec_sub_ba(&delta, &D_L20_001E2E00, &m->pos);
            func_0038CF68(&delta, &delta, 1.0f);
            func_0038CE90(&s->vectors[i], &old, &delta);
            func_0038CF68(&s->vectors[i], &s->vectors[i], s->scale);
            func_0038D890(&s->vectors[i], &s->vectors[i], &delta, func_00382538());
        }
        func_L20_003F2918(m);
        s->timer = (s->i3C * 5 + 2) / 6;
        m->phase = 2;
        s->f2C = 2.5f;
        s->h38 = 1;
        s->h3A = 1;
        break;
    case 2:
        if (func_0038CB00(&s->timer)) {
            m->phase = 1;
            s->timer = (s->h34 * 5 + 2) / 6;
            func_L20_003F2918(m);
        }
        break;
    case 1:
        if (func_0038CB00(&s->timer)) {
            if (s->h36) {
                m->phase = 2;
                s->timer = 4;
            } else s->timer = 4;
        } else if (s->hits == 0) {
            func_L20_003F2918(m);
        }
        break;
    }
    func_L01_00404A10(func_L20_003F3F28, m);
    func_L01_00404A10(func_L20_003F3FF8, m);
    if (s->hits) {
        func_L20_003F32D0(m);
        if (s->hits > D_L20_001DF404) func_L01_00404A10(func_L20_003F3528, m);
    }
}
/* localdecomp:end func_L20_003F22C0 */

/* localdecomp:start func_L20_003F27E8 */
typedef int q_003F27E8 __attribute__((mode(TI)));

typedef struct P_003F27E8 {
    q_003F27E8 q0;
    f32 f10;
    f32 f14;
} P_003F27E8;

typedef struct M_003F27E8 {
    u8 pad0[0x10];
    q_003F27E8 q10;
    u8 pad20[4];
    u8 *p24;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[4];
    u16 h34;
    u8 pad36[0x32];
    P_003F27E8 *p68;
    u8 pad6C[0x2C];
    s32 i98;
    u8 pad9C[0x24];
    u8 vC0[0x30];
    u8 vF0[0x10];
} M_003F27E8;

extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_0038D308(void *, void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_0044E820(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);

M_003F27E8 *func_L20_003F27E8(u8 *a0, q_003F27E8 *a1, q_003F27E8 *a2, f32 x, f32 y) {
    M_003F27E8 *m = (M_003F27E8 *)func_003C24B0(0x1D8D, 0xD90);
    P_003F27E8 *p;
    if (m != 0) {
        func_L01_00456160((u8 *)m, a0);
        m->q10 = *a1;
        func_L01_00443B88(m->vF0, -3.1415927f, 3.1415927f);
        func_0038D308(m->vC0, m->vF0);
        m->i98 = 0;
        m->h34 = (m->h34 | 0x41) & ~0x1000;
        func_L01_004AA7E8(m, 1);
        m->h34 |= 0x100;
        p = m->p68;
        p->q0 = *a2;
        p->f10 = x;
        p->f14 = y;
        m->f2C = *(f32 *)(m->p24 + 0x24) * 0.6f;
        func_L01_0044E820(m, 0x800000C0);
        func_L01_004450F0(m, 0, -1);
    }
    return m;
}
/* localdecomp:end func_L20_003F27E8 */

/* localdecomp:start func_L20_003F2918 */
/* from func_L20_003CE4F8 (same level) */
typedef struct {
    vu0_v4 p[32];
    vu0_v4 q[32];
    vu0_v4 grid[4][4];
    vu0_v4 gvel[4][4];
    f32 ang[3];
} Rope_003F2918;

typedef struct {
    u8 pad0[0x28];
    s32 total;
    u8 pad2C[0x42 - 0x2C];
    s16 timer;
    u8 pad44[4];
    u8 idx[4];
    u8 pad4C[4];
    Rope_003F2918 r[2];
} V_003F2918;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0x68 - 0x20];
    void *pvar;
    u8 pad6C[0xF0 - 0x6C];
    f32 rot[3];
} M_003F2918;

extern s32 D_L20_001DF3F8;
extern s32 D_L20_001DF3FC;
extern f32 D_L20_001DF3D0;
extern f32 D_L20_001DF3D4;
extern s32 D_L20_001DF3DC;
extern s32 D_L20_001DF3E0;
extern f32 D_L20_001DF3E8;
extern s32 D_L20_001DF3F0;
extern s32 D_L20_001DF3F4;
__asm__(".extern D_L20_001DF3F8, 4");
__asm__(".extern D_L20_001DF3FC, 4");
__asm__(".extern D_L20_001DF3D0, 4");
__asm__(".extern D_L20_001DF3D4, 4");
__asm__(".extern D_L20_001DF3DC, 4");
__asm__(".extern D_L20_001DF3E0, 4");
__asm__(".extern D_L20_001DF3E8, 4");
__asm__(".extern D_L20_001DF3F0, 4");
__asm__(".extern D_L20_001DF3F4, 4");
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_00382538(void);
extern void func_0038D328(void *, void *);
extern s32 func_00382468(s32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);

static __inline__ void copy_003F2918(vu0_v4 *d, vu0_v4 *s) {
    *d = *s;
}

void func_L20_003F2918(void *arg) {
    u8 *obj = arg;
    vu0_v4 a[32];
    vu0_v4 b[32];
    V_003F2918 *v;
    s32 r;
    f32 spread;

    ((M_003F2918 *)obj)->pos.w = 1.0f;
    v = ((M_003F2918 *)obj)->pvar;
    r = func_00382498((D_L20_001DF3F8 * 5 + 2) / 6, (D_L20_001DF3FC * 5 + 2) / 6);
    v->timer = r;
    v->total = v->timer;
    spread = func_003824E0(4.0f, 5.0f);
    {
        s32 i;

        for (i = 0; i < 32; i++) {
            f32 f = (f32)i / 31.0f;

            f = (0.5f - f) * spread;
            if (i < 3 || i > 28) {
                qzero(&a[i]);
                qzero(&b[i]);
            } else {
                func_L01_00443B88(&a[i], 0.0f, D_L20_001DF3D0);
                func_L01_00443B88(&b[i], 0.0f, D_L20_001DF3D4 * 0.020000001f);
            }
            a[i].w = 1.0f;
            a[i].y += f;
        }
    }
    {
        s32 i;

        for (i = 0; i < 32; i++) {
            if (i == 0 || i == 31) {
                copy_003F2918(&v->r[0].p[i], &a[i]);
                copy_003F2918(&v->r[0].q[i], &b[i]);
            } else {
                vu0_v4 t;
                vec_add_ab(&t, &a[i - 1], &a[i]);
                vec_add_ab(&t, &t, &a[i + 1]);
                func_0038CE20(&v->r[0].p[i], &t, 0.333f);
                vec_add_ab(&t, &b[i - 1], &b[i]);
                vec_add_ab(&t, &t, &b[i + 1]);
                func_0038CE20(&v->r[0].q[i], &t, 0.333f);
            }
        }
    }
    {
        s32 i;

        for (i = 0; i < 32; i++) {
            if (i == 0 || i == 31) {
                copy_003F2918(&v->r[1].p[i], &a[i]);
                copy_003F2918(&v->r[1].q[i], &b[i]);
            } else {
                vu0_v4 t;
                vec_add_ab(&t, &a[i - 1], &a[i]);
                vec_add_ab(&t, &t, &a[i + 1]);
                func_0038CE20(&v->r[1].p[i], &t, 0.333f);
                vec_add_ab(&t, &b[i - 1], &b[i]);
                vec_add_ab(&t, &t, &b[i + 1]);
                func_0038CE20(&v->r[1].q[i], &t, 0.333f);
            }
        }
    }
    {
        s32 k = 0;

        while (k < 4) {
            vu0_v4 t0;
            s32 n;
            s32 j;

            func_L01_00443B88(&t0, D_L20_001DF3D0, D_L20_001DF3D0);
            n = (s32)func_003824E0((f32)k * 6.0f, (f32)(k + 1) * 6.0f) + 4;
            v->idx[k] = n;
            copy_003F2918(&v->r[0].grid[0][k], &v->r[0].p[n]);
            copy_003F2918(&v->r[0].gvel[0][k], &v->r[0].q[n]);
            for (j = 1; j < 4; j++) {
                vu0_v4 t1;
                func_L01_00443B88(&t1, 0.1f, 0.1f);
                func_L01_00443B88(&v->r[0].gvel[j][k], 0.0f, D_L20_001DF3D4 * 0.020000001f);
                vec_add_ab(&v->r[0].grid[j][k], &v->r[0].grid[j - 1][k], &t0);
                vec_add_ab(&v->r[0].grid[j][k], &v->r[0].grid[j][k], &t1);
            }
            k++;
        }
    }
    {
        s32 k = 0;

        while (k < 4) {
            vu0_v4 t0;
            s32 n;
            s32 j;

            func_L01_00443B88(&t0, D_L20_001DF3D0, D_L20_001DF3D0);
            n = (s32)func_003824E0((f32)k * 6.0f, (f32)(k + 1) * 6.0f) + 4;
            v->idx[k] = n;
            copy_003F2918(&v->r[1].grid[0][k], &v->r[1].p[n]);
            copy_003F2918(&v->r[1].gvel[0][k], &v->r[1].q[n]);
            for (j = 1; j < 4; j++) {
                vu0_v4 t1;
                func_L01_00443B88(&t1, 0.1f, 0.1f);
                func_L01_00443B88(&v->r[1].gvel[j][k], 0.0f, D_L20_001DF3D4 * 0.020000001f);
                vec_add_ab(&v->r[1].grid[j][k], &v->r[1].grid[j - 1][k], &t0);
                vec_add_ab(&v->r[1].grid[j][k], &v->r[1].grid[j][k], &t1);
            }
            k++;
        }
    }
    {
        f32 d = func_0038CF38(obj + 0x10, &D_L20_001E2E00);

        if (d >= 4.0f) {
            vu0_v4 m[4];
            vu0_v4 out;
            vu0_v4 vel;

            v->r[0].ang[2] = ((M_003F2918 *)obj)->rot[2];
            v->r[0].ang[1] = ((M_003F2918 *)obj)->rot[1];
            v->r[0].ang[1] += func_L01_00443A18(0.0f, 30.0f) * 0.017453292f;
            v->r[0].ang[0] = func_00382538();
            func_0038D328(m, v->r[0].ang);
            copy_003F2918(&m[3], &((M_003F2918 *)obj)->pos);
            {
                s32 i;

                for (i = 0; i < 32; i += 8) {
                    s32 c;

                    func_0038D028(&out, &v->r[0].p[i], m);
                    copy_003F2918(&vel, &v->r[0].q[i]);
                    vel.w = D_L20_001DF3E8;
                    c = func_00382468(2) ? D_L20_001DF3F0 : D_L20_001DF3F4;
                    func_L01_00463378(&out, &vel, &vel, D_L20_001DF3DC, D_L20_001DF3E0, i >> 1, 0xF,
                        ((func_00382468(10) + 20) * 5 + 2) / 6, c);
                }
            }
            {
                s32 i;

                for (i = 0; i < 2; i++) {
                    s32 c;

                    func_0038D028(&out, &v->r[0].grid[3][i], m);
                    copy_003F2918(&vel, &v->r[0].gvel[3][i]);
                    vel.w = D_L20_001DF3E8;
                    c = func_00382468(2) ? D_L20_001DF3F0 : D_L20_001DF3F4;
                    func_L01_00463378(&out, &vel, &vel, D_L20_001DF3DC, D_L20_001DF3E0, v->idx[i] >> 1, 0xF,
                        ((func_00382468(10) + 20) * 5 + 2) / 6, D_L20_001DF3F4);
                }
            }
        }
    }
    {
        f32 d = func_0038CF38(obj + 0x10, &D_L20_001E2E00);

        if (d >= 4.0f) {
            vu0_v4 m[4];
            vu0_v4 out;
            vu0_v4 vel;

            v->r[1].ang[2] = ((M_003F2918 *)obj)->rot[2];
            v->r[1].ang[1] = ((M_003F2918 *)obj)->rot[1];
            v->r[1].ang[1] += func_L01_00443A18(0.0f, 30.0f) * 0.017453292f;
            v->r[1].ang[0] = func_00382538();
            func_0038D328(m, v->r[1].ang);
            copy_003F2918(&m[3], &((M_003F2918 *)obj)->pos);
            {
                s32 i;

                for (i = 0; i < 32; i += 8) {
                    s32 c;

                    func_0038D028(&out, &v->r[1].p[i], m);
                    copy_003F2918(&vel, &v->r[1].q[i]);
                    vel.w = D_L20_001DF3E8;
                    c = func_00382468(2) ? D_L20_001DF3F0 : D_L20_001DF3F4;
                    func_L01_00463378(&out, &vel, &vel, D_L20_001DF3DC, D_L20_001DF3E0, i >> 1, 0xF,
                        ((func_00382468(10) + 20) * 5 + 2) / 6, c);
                }
            }
            {
                s32 i;

                for (i = 0; i < 2; i++) {
                    s32 c;

                    func_0038D028(&out, &v->r[1].grid[3][i], m);
                    copy_003F2918(&vel, &v->r[1].gvel[3][i]);
                    vel.w = D_L20_001DF3E8;
                    c = func_00382468(2) ? D_L20_001DF3F0 : D_L20_001DF3F4;
                    func_L01_00463378(&out, &vel, &vel, D_L20_001DF3DC, D_L20_001DF3E0, v->idx[i] >> 1, 0xF,
                        ((func_00382468(10) + 20) * 5 + 2) / 6, D_L20_001DF3F4);
                }
            }
        }
    }
}
/* localdecomp:end func_L20_003F2918 */
