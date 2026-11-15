#include "common.h"

/* localdecomp:start func_L39_005665D0 */
#include "vu0.h"

typedef struct {
    f32 pos[3]; f32 f0C;
    f32 vel[3]; f32 f1C;
    f32 acc[3]; f32 f2C;
    f32 f30[3]; f32 f3C;
    f32 pad40; f32 f44; f32 f48; f32 f4C;
    s32 timer; u8 state; u8 b55; u8 pad56[2];
    f32 f58; f32 f5C;
} P_005665D0;

typedef struct {
    P_005665D0 p[10];
    u8 pad[0x3D2 - 0x3C0];
    u8 count; u8 pad3D3;
    f32 f3D4; f32 f3D8;
} S_005665D0;

typedef struct {
    u8 p0[0x10]; vu0_v4 pos;
    u8 b20; u8 pad21[0x68 - 0x21];
    S_005665D0 *s;
} O_005665D0;

extern u8 D_L39_00242960[8];
extern void func_L01_003D5F28(void *);
extern void func_L01_00404808(void *, void *);
extern void func_003C2880(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_L01_0044AE78(f32);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_0038CE20(void *, void *, f32);

void func_L39_005665D0(O_005665D0 *o) {
    vu0_v4 w;
    vu0_v4 t;
    S_005665D0 *s;
    s32 i;
    s32 done;
    f32 a, b, c, ang, sn, sn2, r, e, f, g;

    s = o->s;
    w = o->pos;
    w.w = s->f3D8 * 3.0f;
    done = 0;
    for (i = 0; i < s->count && i < 10; i++) {
        P_005665D0 *h = &s->p[i];
        a = h->f0C;
        b = h->f4C;
        c = h->f1C;
        switch (h->state) {
        case 0: {
            P_005665D0 *q = &s->p[i];
            q->f48 = func_0038D160(q->vel[0], q->vel[1]);
            q->f44 = 3.1415927f;
            q->state = 1;
            q->timer = (func_L39_005B43C8(10, 20) * 5 + 2) / 6;
            break;
        }
        case 1: {
            P_005665D0 *q;
            vec_add_ab(s->p[i].pos, s->p[i].pos, s->p[i].vel);
            q = &s->p[i];
            func_0038CE20(q->vel, q->vel, 0.90400004f);
            if (func_0038CAD0(&q->timer)) {
                func_0038CE20(&t, q->f30, -b);
                vec_add_ab(q->acc, &t, q->pos);
                q->f58 = 1.5707964f;
                q->acc[2] -= b * 0.5f;
                q->f5C = 3.1415927f / (a + a);
                q->state = 2;
                q->timer = 1000;
            }
            break;
        }
        case 2: {
            P_005665D0 *q;
            P_005665D0 *u = &s->p[i];
            f32 k;
            u->acc[2] -= c;
            ang = func_L01_0044AE78(u->f5C * a);
            sn = func_0038D0B0(ang);
            g = sn * 3.0f;
            if (sn >= 0.0f) {
                e = b * (sqrt_asm(sn) + g) * 0.25f;
            } else {
                e = b * (-sqrt_asm(-sn) + g) * 0.25f;
            }
            k = 1.5707964f;
            f = b * sn;
            f = f * sn;
            q = &s->p[i];
            q->f44 = -(q->f58 * sn + k);
            f = f * (q->f58 / k);
            f = f * 0.5f;
            sn2 = func_0038D0B0(func_L01_0044AE78(2.0f * (q->f5C * a)));
            q->f48 = -(q->f58 * sn2 + k);
            func_0038CE20(&t, D_L39_00242960, f);
            vec_add_ab(q->pos, &t, q->acc);
            func_0038CE20(&t, q->f30, e);
            vec_add_ab(q->pos, &t, q->pos);
            if (fabs_asm(ang) < 0.1f) {
                q->f58 = func_L39_005B4410(30.0f, 60.0f) * 0.017453292f;
            }
            if (q->pos[2] < s->f3D4 || func_0038CAD0(&q->timer)) {
                q->state = 3;
                q->timer = 50;
            }
            break;
        }
        case 3: {
            P_005665D0 *q = &s->p[i];
            q->f44 = (q->f44 + 1.5707964f) * 0.94f - 1.5707964f;
            q->b55 = (s32)((f32)q->timer / 50.0f * 127.0f);
            if (func_0038CAD0(&q->timer)) {
                q->timer = 0;
                q->state = 4;
            }
            break;
        }
        case 4:
            done++;
            break;
        }
        {
            P_005665D0 *z = &s->p[i];
            z->f0C = a;
            z->f4C = b;
            z->f1C = c;
            z->f5C += 1.0f;
        }
    }
    func_L01_004450F0(o, 1, -1);
    if (done == s->count) {
        func_L01_004450F0(o, 4, -1);
        func_003C2880(o);
    } else if (o->b20 != 0 && o->b20 != 4) {
        func_L01_00404808(func_L01_003D5F28, o);
    }
}
/* localdecomp:end func_L39_005665D0 */
