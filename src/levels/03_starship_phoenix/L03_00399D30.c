#include "common.h"

/* localdecomp:start func_L03_00399D30 */
#include "vu0.h"
typedef struct { u8 pad0[0x10]; vu0_v4 pos; } A_00399D30;
extern u8 *D_L03_0021F298[];
extern f32 func_00382538(void);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);

/* the unit vector at angle ang in the xy plane */
static __inline__ vu0_v4 angle_dir_00399D30(f32 ang) {
    vu0_v4 t;
    *(vu0_q *)&t = 0;
    t.x = func_0038D0B0(ang);
    t.y = func_0038D098(ang);
    return t;
}

void func_L03_00399D30(void *arg) {
    A_00399D30 *a = arg;
    vu0_v4 vel;
    vu0_v4 pos;
    int i;
    for (i = 0; i >= 0; i--) {
        s32 n;
        u8 *p;
        {
            vu0_v4 dir;
            dir = angle_dir_00399D30(func_00382538());
            {
                f32 sp = func_003824E0(4.0f, 6.0f) * 0.020000001f;
                f32 life = (sp + sp) / 0.002f;
                f32 k = func_003824E0(0.8f, 1.6f);
                n = life;
                func_0038CF68(&vel, &dir, (1.2f - k) / life * 0.5f);
                vel.z = sp;
                func_0038CF68(&dir, &dir, k);
            }
            vec_add_ba(&pos, &a->pos, &dir);
        }
        {
            f32 z = func_003824E0(0.5f, 1.5f);
            s32 sign = func_00382468(2) != 0 ? -2 : 2;
            z *= 210000.0f;
            p = ((u8 *(*)(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32))func_L01_0046FB40)(
                &pos, &vel, n, 0x7FFFFFFF, sign, 0x7F, 0x7F, z, z, 0.002f, 0);
        }
        if (p != 0) {
            p[2] = D_L03_0021F298[23][0];
            p[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L03_00399D30 */

/* localdecomp:start func_L03_00399F38 */
#include "vu0.h"
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; u8 *p68; } A_00399F38;
extern u8 *D_L03_0021F298[];
extern f32 func_00382538(void);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);

void func_L03_00399F38(void *arg) {
    A_00399F38 *a = arg;
    u8 *s = a->p68;
    vu0_v4 vel;
    vu0_v4 pos;
    vu0_v4 dir;
    int i;
    for (i = 2; i >= 0; i--) {
        s32 n;
        f32 z;
        u8 *p;
        {
            f32 ang = func_00382538();
            vu0_v4 t;
            *(vu0_q *)&t = 0;
            t.x = func_0038D0B0(ang);
            t.y = func_0038D098(ang);
            dir = t;
        }
        func_0038CF68(&vel, &dir, func_003824E0(2.0f, 4.0f) * 0.020000001f);
        n = func_00382498(0x3C, 0x78);
        {
            f32 h = a->pos.z - *(f32 *)(s + 0x44);
            if (h > 1.0f) h = 1.0f;
            z = func_003824E0(h * 0.5f, h);
        }
        func_0038CF68(&dir, &dir, 1.7f);
        vec_add_ba(&pos, &a->pos, &dir);
        pos.z = *(f32 *)(s + 0x44) + z * 0.5f;
        {
            s32 sign = func_00382468(2) != 0 ? -2 : 2;
            p = ((u8 *(*)(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32))func_L01_0046FB40)(
                &pos, &vel, n, 0x7FFFFFFF, sign, 0x7F, 0x20, z * 210000.0f, 0.0f, 0.0f, 0);
        }
        if (p != 0) {
            p[2] = D_L03_0021F298[23][0];
            p[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L03_00399F38 */

/* localdecomp:start func_L03_0039A118 */
#include "vu0.h"
extern u8 D_L03_001E24C0[];
extern u8 D_001D66B0;
extern u8 *D_L03_0021F2F4 __attribute__((section(".data")));
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);
void func_L03_0039A118(void *arg) {
    vu0_v4 v;
    vu0_v4 d;
    u8 *r;
    vec_sub_ab(&d, D_L03_001E24C0, (u8 *)arg + 0x10);
    func_0038CF68(&d, &d, 0.8f);
    vec_add_ba(&v, (u8 *)arg + 0x10, &d);
    v.z += 0.625f;
    r = func_L01_0046FB40(&v, &D_001D66B0, 100, 0x7FFFFFFF, func_00382468(2) != 0 ? -1 : 1, 0, 0x7F, 525000.0f, 525000.0f, 0, 0.0f);
    if (r != 0) {
        r[2] = D_L03_0021F2F4[0];
        r[3] = 0x44;
    }
}
/* localdecomp:end func_L03_0039A118 */

/* localdecomp:start func_L03_0039A1F8 */
#include "vu0.h"
typedef struct { f32 ang; f32 spin; f32 h; f32 dh; } E_0039A1F8;
typedef struct { E_0039A1F8 e[4]; u8 pad40[0x7F - 0x40]; u8 b7F; u8 b80; } S_0039A1F8;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; S_0039A1F8 *p68; } A_0039A1F8;
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern void func_L03_0039A5D0(void *, void *);
extern void func_L03_0039A4C8(void *);

void func_L03_0039A1F8(void *arg) {
    A_0039A1F8 *a = arg;
    S_0039A1F8 *s = a->p68;
    vu0_v4 pos;
    int i;
    pos = a->pos;
    pos.z += 1.7f;
    func_003D9508(&pos, 0x29, 0x20404040, 1, 0.8f, 0.0f, 0.0f);
    func_003D9508(&pos, 0x31, 0x80802020, 1, 1.0f, 0.0f, func_00382538());
    func_003D9508(&pos, 0x2C, 0xA0A0A0A0, 1, 0.2f, 0.0f, func_00382538());
    for (i = 0; i < 4; i++) {
        E_0039A1F8 *e = &s->e[i];
        vu0_v4 w;
        vu0_v4 v;
        if (((s->b80 >> i) ^ 1) & 1) {
            if (((s->b7F >> i) & 1) || func_00382468(0x5A) == 0) {
                e->h = func_003824E0(-0.95f, 1.15f);
                e->dh = func_003824E0(-4.0f, 4.0f) * 0.020000001f;
                e->ang = func_00382538();
                e->spin = func_003824E0(-90.0f, 90.0f) * 0.017453292f * 0.020000001f;
                s->b7F &= ~(1 << i);
            }
            e->h = e->h + e->dh;
            if (e->h > 1.15f) {
                e->h = 1.15f;
                e->dh = -e->dh;
            } else if (e->h < -0.95f) {
                e->h = -0.95f;
                e->dh = -e->dh;
            }
            e->ang = func_0038DAB8(e->ang, e->spin);
            *(vu0_q *)&v = 0;
            v.x = func_0038D0B0(e->ang) * 2.2f;
            v.y = func_0038D098(e->ang) * 2.2f;
            v.z = e->h;
            w = v;
            vec_add_ab(&w, &w, &pos);
            func_L03_0039A5D0(&pos, &w);
        }
    }
    if (s->b80 != 0) func_L03_0039A4C8(a);
}
/* localdecomp:end func_L03_0039A1F8 */

/* localdecomp:start func_L03_0039A4C8 */
#include "vu0.h"
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; u8 *p68; } A_0039A4C8;
typedef struct { u8 pad0[0x44]; f32 f44; u8 pad48[0x28]; f32 f70; f32 f74; u8 pad78[8]; u8 b80; u8 b81; } P_0039A4C8;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L03_0039A5D0(void *, void *);
void func_L03_0039A4C8(void *arg) {
    A_0039A4C8 *a = arg;
    P_0039A4C8 *p = (P_0039A4C8 *)a->p68;
    f32 ang = p->f74;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (((p->b80 & ~p->b81) >> i) & 1) {
            vu0_v4 pos;
            vu0_v4 w;
            vu0_v4 u = {0, 0, 0, 0};
            pos = a->pos;
            pos.z += 1.7f;
            u.x = p->f70 * func_0038D0B0(ang);
            u.y = p->f70 * func_0038D098(ang);
            w = u;
            vec_add_ab(&w, &pos, &w);
            w.z = p->f44;
            func_L03_0039A5D0(&pos, &w);
        }
        ang = func_0038DAB8(ang, 1.5707964f);
    }
}
/* localdecomp:end func_L03_0039A4C8 */

/* localdecomp:start func_L03_0039A5D0 */
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4C18(f32 *v, f32 r);
extern void func_L01_00409658(void *, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L03_0039A5D0(void *from, void *to) {
    vu0_v4 cur;
    vu0_v4 step;
    f32 pts[5][4];
    int i;
    vec_sub_ba(&step, to, from);
    func_0038CE20(&step, &step, 0.25f);
    cur = *(vu0_v4 *)from;
    for (i = 0; i < 5; i++) {
        *(vu0_v4 *)pts[i] = cur;
        if (i != 0 && i != 4) {
            func_003C4C18(pts[i], 0.3f);
        }
        pts[i][3] = 0.05f;
        vec_add_ab(&cur, &cur, &step);
    }
    func_L01_00409658(pts, 0.05f, 4.0f, 0.0f, 0x17, 0x17, 6, -1, 0x80802020, 0);
    func_003D9508(to, 0x31, -1, 1, 0.15f, 0.0f, func_00382538());
    func_003D9508(to, 0x31, 0x80802020, 1, 0.6f, 0.0f, func_00382538());
}
/* localdecomp:end func_L03_0039A5D0 */

/* localdecomp:start func_L03_0039A780 */
typedef struct S_0039A780 {
    u8 pad0[2];
    u8 b2;
    u8 pad3[5];
    u8 b8;
} S_0039A780;
typedef S_0039A780 *(*Spawn_0039A780)(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_00382498(s32, s32);

/* -1 or 1 at random */
static __inline__ s32 rsign_0039A780(void) {
    return func_00382468(2) ? -1 : 1;
}

void func_L03_0039A780(void *arg0) {
    S_0039A780 *o;
    s32 col = 0;
    s32 i;

    o = ((Spawn_0039A780)func_L01_0046FB40)(arg0, &D_001D66B0, 15, 0xFFFFFF, 1, 0x7F, 0x7F, 420000.0f, 210000.0f, 0.0f, 0);
    if (o != 0) {
        col = o->b8 + 0x20;
        o->b2 = *D_L03_0021F298[89];
    }
    o = ((Spawn_0039A780)func_L01_0046FB40)(arg0, &D_001D66B0, 15, 0x802020, 1, 0x40, 0x20, 630000.0f, 630000.0f, 0.0f, 0);
    if (o != 0) {
        o->b2 = *D_L03_0021F298[89];
        o->b8 = col;
    }
    for (i = 0; i < 20; i++) {
        f32 vec[4];
        s32 id;
        f32 r;
        S_0039A780 *p;

        {
            f32 s = (func_003824E0(-1.0f, 1.0f) + 4.0f) * 0.0200000014f;
            f32 x = func_00382538();
            f32 y = func_00382538();
            func_00382760(vec, s, x, y);
        }
        id = func_00382498(-10, 10) + 30;
        r = func_003824E0(-0.4f, 0.4f) + 0.8f;
        {
            s32 sign = rsign_0039A780();

            p = ((Spawn_0039A780)func_L01_0046FB40)(arg0, vec, id, 0x802020, sign, 0x40, 0x20, r * 210000.0f, r * 210000.0f, 0.00392f, 0);
            if (p != 0) {
                col = p->b8 + 0x20;
                p->b2 = *D_L03_0021F298[89];
            }
        }
        {
            s32 sign = rsign_0039A780();

            p = ((Spawn_0039A780)func_L01_0046FB40)(arg0, vec, id, 0xF7F7F7, sign, 0x30, 0x30, r * 0.6f * 210000.0f, r * 0.6f * 210000.0f, 0.00392f, 0);
            if (p != 0) {
                p->b2 = *D_L03_0021F298[89];
                p->b8 = col;
            }
        }
    }
}
/* localdecomp:end func_L03_0039A780 */
