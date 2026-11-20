#include "common.h"

/* localdecomp:start func_L03_00395808 */
#include "vu0.h"
typedef struct {
    vu0_v4 v0;
    vu0_v4 v10;
    s32 i20;
    s32 i24;
    f32 f28;
    s32 i2C;
    f32 f30;
    f32 f34;
    u8 pad38[0x48 - 0x38];
    f32 f48;
    f32 f4C;
    u8 pad50[0x54 - 0x50];
    f32 f54;
    f32 f58;
    s32 i5C;
    u8 b60;
    u8 pad61;
    u8 b62;
    u8 b63;
    u8 b64;
    u8 pad65[0x70 - 0x65];
    s32 i70;
} S_00395808;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 b20; u8 pad21[0x47]; S_00395808 *p68; u8 pad6C[0xF0 - 0x6C]; f32 fF0; f32 fF4; f32 fF8; } A_00395808;
typedef struct { u8 pad0[0x48]; f32 f48; } P_00395808;
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern u8 D_001A30B0[];
extern s16 D_001A4DBC[];
extern u8 D_L03_001E9220[];
extern s32 *D_L03_0021D8C0[];
__asm__(".extern D_L03_0021D8C0, 16");
extern void func_L03_00395BF0(void *);
extern void func_L03_00395CA8(void *);
extern void func_L03_003965E8(void *);
extern void func_L03_00396320(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L03_00433C70(void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern void func_L01_00404808(void *, void *);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern void func_L03_004657D0(s32, s32, void *, void *, s32, f32);
extern void func_0038CE20(void *, void *, f32);

void func_L03_00395808(void *arg) {
    A_00395808 *a = arg;
    S_00395808 *s = a->p68;
    vu0_v4 d;
    int flag;
    f32 x;
    func_L03_00395BF0(a);
    if (a->b20 != 1) return;
    if (s->i20 != -1) {
        u8 *t;
        int idx = s->i70;
        u8 *e;
        if (idx == -1 || (e = D_001A30B0 + (idx << 7), *(void **)(e + 0xDC) != a) || e[0xD0] == 0) {
            s->i70 = func_003A52A0(0, 4, a);
        }
        t = D_L03_001DF99C + (s->i20 << 8);
        if (t != 0) {
            vec_sub_ba(&d, t + 0x10, &a->pos);
            a->fF8 = func_0038D160(*(f32 *)(t + 0x10) - a->pos.x, *(f32 *)(t + 0x14) - a->pos.y);
            a->fF4 = -func_0038D160(func_0038CF38(&a->pos, t + 0x10), *(f32 *)(t + 0x18) - a->pos.z);
            if (s->b63 == 0) {
                if (s->b62 != 0) {
                    s->f30 = func_0038DAB8(s->f30, s->f34 * 0.017453292f * 0.020000001f);
                    s->f58 = s->f58 + 0.11f;
                    if (s->f58 >= 1.0f) s->f58 = s->f58 - 1.0f;
                    if (func_L03_00433C70(a, &a->pos, t + 0x10, 1, s->f54, 1.0f, 0, 1, 0) != 0 && D_001A4DBC[0] == 0) {
                        func_L03_00396320(D_L03_001E9220);
                    }
                    func_L01_00404808(func_L03_00395CA8, a);
                }
            } else if (s->b63 == 1) {
                s->f58 = s->f58 + 0.1f;
                if (s->f58 >= 1.0f) s->f58 = s->f58 - 1.0f;
                if (s->b62 != 0) func_L01_00404808(func_L03_003965E8, a);
            }
        }
    }
    flag = 0;
    if (s->i24 != -1) {
        u8 *m = D_L03_001DF99C + (s->i24 << 8);
        if (m != 0 && *(s16 *)(m + 0xAA) == 0x18C0) {
            flag = 1;
            s->f48 = (*(P_00395808 **)(m + 0x68))->f48 + s->f28;
        }
    }
    if (flag == 0) s->f48 = s->f48 + s->f4C * 1.2f;
    if (s->b60 != 0) {
        if (s->f48 > 1.0f) s->f48 = s->f48 - 1.0f;
        x = s->f48;
    } else {
        if (s->f48 > 2.0f) s->f48 = s->f48 - 2.0f;
        x = (1.0f - func_0038D098(func_0038DB48(s->f48 * 3.1415927f))) * 0.5f;
    }
    if (s->i5C != -1) {
        if (s->b64 != 0) x = 1.0f - x;
        func_L03_004657D0(s->i5C, s->b60, &a->pos, &a->fF0, 1, x * (f32)*D_L03_0021D8C0[s->i5C]);
    } else if (s->i2C != -1) {
        func_0038CE20(&d, &s->v10, x);
        vec_add_ab(&a->pos, &s->v0, &d);
    }
}
/* localdecomp:end func_L03_00395808 */

/* localdecomp:start func_L03_00395BF0 */
#include "vu0.h"
typedef struct { u8 pad0[0x10]; vu0_v4 v10; u8 pad20[0x48]; u8 *p68; } A_00395BF0;
typedef struct { vu0_v4 v0; vu0_v4 v10; u8 pad20[0xC]; s32 i2C; u8 pad30[8]; f32 f38; u8 pad3C[4]; s32 i40; f32 f44; u8 pad48[4]; f32 f4C; s32 i50; u8 pad54[4]; s32 f58; } P_00395BF0;
typedef struct { u8 b[0x80]; } E_00395BF0;
extern E_00395BF0 *D_L03_001DFA80;
extern void func_L01_004450F0(void *, s32, s32);
void func_L03_00395BF0(void *arg) {
    A_00395BF0 *a = arg;
    P_00395BF0 *p;
    if (*(u8 *)((u8 *)arg + 0x20) == 0) {
        p = (P_00395BF0 *)a->p68;
        p->f58 = 0;
        p->v0 = *(vu0_v4 *)&a->v10;
        if (p->i2C != -1) {
            vec_sub_ba(&p->v10, D_L03_001DFA80[p->i2C].b + 0x30, &a->v10);
        }
        p->f44 = p->f38 / (f32)p->i40 * 0.017453292f;
        p->f4C = 1.0f / (f32)p->i50;
        func_L01_004450F0(arg, 1, -1);
    }
}
/* localdecomp:end func_L03_00395BF0 */

/* localdecomp:start func_L03_00395CA8 */
typedef struct { u8 pad0[0x30]; f32 f30; u8 pad34[8]; s32 i3C; } P_00395CA8;
extern void func_L03_00396190(void *, f32);
extern void func_L03_00395D60(void *, f32);
void func_L03_00395CA8(void *a) {
    P_00395CA8 *p;
    s32 i;
    f32 f20;
    f32 f21;
    p = *(P_00395CA8 **)((u8 *)a + 0x68);
    i = 0;
    func_L03_00396190(a, 0.15f);
    f21 = 6.2831855f / (f32)p->i3C;
    f20 = p->f30;
    for (; i < p->i3C; i++) {
        func_L03_00395D60(a, f20);
        f20 = func_0038DAB8(f20, f21);
    }
}
/* localdecomp:end func_L03_00395CA8 */

/* localdecomp:start func_L03_00395D60 */
/* localdecomp:start func_L03_00395D60 */
#include "vu0.h"
typedef struct {
    vu0_v4 v[4];
    s32 color[4];
    f32 uv[4][2];
    long x70, x78, x80, x88;
} Q_00395D60;
typedef struct { u8 pad0[0x20]; s32 i20; u8 pad24[0x40 - 0x24]; s32 i40; f32 f44; } S_00395D60;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; S_00395D60 *p68; u8 pad6C[0xC0 - 0x6C]; u8 mtx[0x40]; } A_00395D60;
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern u8 D_L03_001E2840[];
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, s32, s32);
extern f32 func_0038DAB8(f32, f32);

void func_L03_00395D60(void *arg, f32 angle) {
    A_00395D60 *a = arg;
    S_00395D60 *s = a->p68;
    u8 *e = D_L03_001DF99C + (s->i20 << 8);
    if (e != 0) {
        f32 ang = angle;
        vu0_v4 seg[4];
        vu0_v4 d;
        vu0_v4 p;
        vu0_v4 w;
        vu0_v4 x;
        vu0_v4 y;
        Q_00395D60 q;
        f32 step = 1.0f / (f32)s->i40;
        f32 t = 0.0f;
        f32 r1 = func_003824E0(0.0f, 1.0f);
        f32 r2 = func_003824E0(0.0f, 1.0f);
        int i;
        vec_sub_ab(&d, e + 0x10, &a->pos);
        for (i = 0; i <= s->i40; i++) {
            int k;
            if (t == 0.0f) {
                p = a->pos;
            } else if (t == 1.0f) {
                p = *(vu0_v4 *)(e + 0x10);
            } else {
                func_0038CE20(&p, &d, t);
                vec_add_ba(&p, &a->pos, &p);
            }
            {
                f32 sy = func_0038D098(ang);
                f32 cz = func_0038D0B0(ang);
                *(vu0_q *)&w = 0;
                w.y = sy * 0.3f;
                w.z = cz * 0.3f;
            }
            func_0038D000(&w, &w, a->mtx);
            func_0038CE90(&x, &d, D_L03_001E2840);
            func_0038CF68(&x, &x, 0.1f);
            vec_add_ab(&p, &p, &w);
            vec_add_ba(&seg[0], &p, &x);
            vec_sub_ab(&seg[1], &p, &x);
            func_0038CF68(&y, &x, func_003824E0(-0.1f, 0.1f));
            vec_add_ba(&seg[0], &seg[0], &y);
            vec_add_ab(&seg[1], &seg[1], &y);
            if (i != 0) {
                f32 u;
                q.x78 = func_00389598(0x17);
                q.x80 = 0xFF9000000260L;
                q.x88 = 0x8000000048L;
                q.v[0] = seg[2];
                q.v[1] = seg[3];
                q.v[2] = seg[0];
                q.v[3] = seg[1];
                q.x70 = 0;
                q.color[3] = 0x7FFFFFFF;
                q.color[2] = 0x7FFFFFFF;
                q.color[1] = 0x7FFFFFFF;
                q.color[0] = 0x7FFFFFFF;
                q.uv[0][0] = r1;
                q.uv[1][0] = r1;
                q.uv[0][1] = 0.0f;
                q.uv[1][1] = 1.0f;
                q.uv[2][0] = r1 + 1.0f;
                q.uv[3][0] = r1 + 1.0f;
                q.uv[2][1] = 0.0f;
                q.uv[3][1] = 1.0f;
                func_003D2DA0(&q, 0, 0);
                func_0038CE20(&x, &x, 4.0f);
                vec_add_ba(&q.v[0], &q.v[0], &x);
                vec_sub_ba(&q.v[1], &q.v[1], &x);
                vec_add_ab(&q.v[2], &q.v[2], &x);
                vec_sub_ab(&q.v[3], &q.v[3], &x);
                u = r2 + 0.3f;
                q.uv[1][0] = r2;
                q.uv[0][0] = r2;
                q.color[3] = 0x4010FF10;
                q.color[2] = 0x4010FF10;
                q.color[1] = 0x4010FF10;
                q.color[0] = 0x4010FF10;
                q.uv[2][0] = u;
                q.uv[3][0] = u;
                r2 = u;
                if (u >= 1.0f) r2 = u - 1.0f;
                func_003D2DA0(&q, 0, 0);
            }
            ang = func_0038DAB8(ang, s->f44);
            t += step;
            for (k = 2; k < 4; k++) seg[k] = seg[k - 2];
        }
    }
}
/* localdecomp:end func_L03_00395D60 */
/* localdecomp:end func_L03_00395D60 */

/* localdecomp:start func_L03_00396190 */
typedef struct {
    vu0_v4 v[4];
    s32 color[4];
    f32 uv[4][2];
    long x70, x78, x80, x88;
} Q_00396190;
typedef struct { u8 pad0[0x20]; s32 i20; u8 pad24[0x58 - 0x24]; f32 f58; u8 pad5C[0x61 - 0x5C]; u8 b61; } S_00396190;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; S_00396190 *p68; } A_00396190;
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern u8 D_L03_001E2840[];
extern f32 D_001DE2E0_sda;
__asm__(".extern D_001DE2E0_sda, 4");
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, s32, s32);

void func_L03_00396190(void *arg, f32 r) {
    A_00396190 *a = arg;
    S_00396190 *s = a->p68;
    u8 *e = D_L03_001DF99C + (s->i20 << 8);
    vu0_v4 dir;
    vu0_v4 d;
    Q_00396190 q;
    vu0_q c;
    if (e != 0) {
        vec_sub_ba(&dir, e + 0x10, &a->pos);
        func_0038CE90(&d, &dir, D_L03_001E2840);
        func_0038CF68(&d, &d, r);
        q.x78 = func_00389598(s->b61 + 0x64);
        q.x80 = 0xFF9000000260L;
        q.x88 = 0x6000000062L;
        q.x70 = 0;
        q.color[3] = 0x60408040;
        q.color[2] = 0x60408040;
        q.color[1] = 0x60408040;
        q.color[0] = 0x60408040;
        __asm__("lqc2 %0, %1" : "=j"(c) : "m"(a->pos));
        vec_add_ab(&q.v[0], &a->pos, &d);
        {
            vu0_q qd, qr;
            __asm__("lqc2 %0, %1" : "=j"(qd) : "m"(d));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(qr) : "j"(c), "j"(qd));
            __asm__("sqc2 %1, %0" : "=m"(q.v[1]) : "j"(qr));
        }
        vec_add_ba(&q.v[2], e + 0x10, &d);
        vec_sub_ab(&q.v[3], e + 0x10, &d);
        q.uv[0][0] = -D_001DE2E0_sda + s->f58;
        q.uv[0][1] = 0.0f;
        q.uv[1][0] = -D_001DE2E0_sda + s->f58;
        q.uv[1][1] = 1.0f;
        q.uv[2][0] = s->f58 + D_001DE2E0_sda;
        q.uv[2][1] = 0.0f;
        q.uv[3][0] = s->f58 + D_001DE2E0_sda;
        q.uv[3][1] = 1.0f;
        func_003D2DA0(&q, 0, 0);
    }
}
/* localdecomp:end func_L03_00396190 */

/* localdecomp:start func_L03_00396320 */
typedef struct { u8 pad0[2]; u8 b2; u8 pad1[5]; u8 b8; } S_00396320;
typedef struct { u8 pad[0x164]; u8 *p; } G_00396320;
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
__asm__(".extern D_L03_001D66B0, 16");
extern u8 D_L03_001D66B0;
extern G_00396320 D_L03_0021F298;
static __inline__ f32 size_00396320(f32 x)
{
    return x * 210000.0f;
}
void func_L03_00396320(void *arg) {
    f32 v[4];
    f32 t;
    s32 c = 0;
    s32 i;
    S_00396320 *s;
    s = (S_00396320 *)func_L01_0046FB40(arg, &D_L03_001D66B0, 15, 0xFFFFFF, 1, 127, 127, size_00396320(4.0f), size_00396320(2.0f), 0.0f, 0);
    if (s) {
        s->b2 = *D_L03_0021F298.p;
        c = s->b8 + 0x20;
    }
    s = (S_00396320 *)func_L01_0046FB40(arg, &D_L03_001D66B0, 15, 0x40FF40, 1, 64, 32, size_00396320(6.0f), size_00396320(6.0f), 0.0f, 0);
    if (s) {
        s->b2 = *D_L03_0021F298.p;
        s->b8 = c;
    }
    for (i = 0; i < 20; i++) {
        s32 n;
        f32 a, b, u;
        u = (func_003824E0(-1.0f, 1.0f) + 4.0f) * 0.020000001f;
        a = func_00382538();
        b = func_00382538();
        func_00382760(v, u, a, b);
        n = func_00382498(-10, 10) + 30;
        t = func_003824E0(-0.4f, 0.4f) + 0.8f;
        s = (S_00396320 *)func_L01_0046FB40(arg, v, n, 0x40FF40, func_00382468(2) ? -1 : 1, 64, 32, size_00396320(t), size_00396320(t), 0.00392f, 0);
        if (s) {
            s->b2 = *D_L03_0021F298.p;
            c = s->b8 + 0x20;
        }
        s = (S_00396320 *)func_L01_0046FB40(arg, v, n, 0xF7F7F7, func_00382468(2) ? -1 : 1, 48, 48, size_00396320(t * 0.6f), size_00396320(t * 0.6f), 0.00392f, 0);
        if (s) {
            s->b2 = *D_L03_0021F298.p;
            s->b8 = c;
        }
    }
}
/* localdecomp:end func_L03_00396320 */

/* localdecomp:start func_L03_003965E8 */
#include "vu0.h"
typedef struct { u8 pad0[0x20]; s32 i20; u8 pad24[0x58 - 0x24]; f32 f58; } S_003965E8;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; S_003965E8 *p68; } A_003965E8;
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4C18(f32 *v, f32 r);
extern void func_L01_00409658(void *, f32, f32, f32, s32, s32, s32, s32, s32, s32);

void func_L03_003965E8(void *arg) {
    A_003965E8 *a = arg;
    S_003965E8 *s = a->p68;
    vu0_v4 cur;
    vu0_v4 step;
    f32 pts[24][4];
    int i;
    vec_sub_ba(&step, D_L03_001DF99C + (s->i20 << 8) + 0x10, &a->pos);
    func_0038CE20(&step, &step, 0.14285715f);
    cur = a->pos;
    for (i = 0; i < 8; i++) {
        *(vu0_v4 *)pts[i] = cur;
        if (i != 0 && i != 7) {
            func_003C4C18(pts[i], 0.5f);
        }
        pts[i][3] = 0.15f;
        vec_add_ab(&cur, &cur, &step);
    }
    func_L01_00409658(pts, 0.15f, 8.0f, s->f58, 0x17, 0x17, 9, -1, 0x60600000, 0);
}
/* localdecomp:end func_L03_003965E8 */
