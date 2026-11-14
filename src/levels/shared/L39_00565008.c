#include "common.h"

/* localdecomp:start func_L39_00565008 */
typedef union Buf_00565008 {
    u8 b[8];
    u32 w[2];
    f32 f[2];
} Buf_00565008;
typedef struct Inner_00565008 {
    u8 pad0[0x40];
    u8 *p40;
} Inner_00565008;
typedef struct Self_00565008 {
    u8 pad0[0x68];
    Inner_00565008 *p68;
} Self_00565008;
extern u8 D_L39_004997E0[];

s32 func_L39_00565008(u8 *self, f32 arg) {
    Self_00565008 *s = (Self_00565008 *)self;
    Inner_00565008 *o;
    u8 *q1;
    u8 *q2;
    u8 *q3;
    u32 r;
    f32 v;
    u8 t;
    s32 x;
    f32 zero;
    Buf_00565008 buf;

    o = s->p68;
    if (arg <= 0.0f) {
        goto fail;
    }
    q1 = o->p40 + 0x19E4;
    if (*q1 == 0) {
        r = 0;
    } else {
        u32 a;
        u32 b;
        s32 n;
        s32 k;
        s32 m;
        s32 i;
        u8 *d;
        n = *q1;
        k = ((u32)q1 - n) & 7;
        m = n + 1;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q1;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = b;
        r = b;
    }
    if ((r ^ 0x31) == 0) {
        goto fail;
    }
    q2 = o->p40 + 0x19E6;
    if (*q2 == 0) {
        r = 0;
    } else {
        u32 a;
        u32 b;
        s32 n;
        s32 k;
        s32 m;
        s32 i;
        u8 *d;
        n = *q2;
        k = ((u32)q2 - n) & 7;
        m = n + 1;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q2;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = b;
        r = b;
    }
    if ((r ^ 0x14) == 0) {
        goto fail;
    }
    zero = 0.0f;
    q3 = o->p40 + 0x2476;
    if (*q3 == 0) {
        v = zero;
    } else {
        u32 a;
        u32 b;
        s32 n;
        s32 k;
        s32 m;
        s32 i;
        u8 *d;
        n = *q3;
        k = ((u32)q3 - n) & 7;
        m = n + 1;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q3;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = b;
        v = buf.f[1];
    }
    x = v <= zero;
    t = x;
    if (t != 0) {
fail:
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L39_00565008 */

/* localdecomp:start func_L39_005651F0 */
#include "vu0.h"

typedef struct {
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    u8 pad30[4];
    f32 f34;
    f32 f38;
    f32 f3C;
    u8 pad40[4];
    s32 f44;
    s32 f48;
    f32 f4C;
} P_005651F0;

typedef struct {
    u8 pad0[0x1A];
    u16 f1A;
    u8 pad1C[0x14];
    vu0_v4 v30;
} H_005651F0;

typedef struct {
    u8 pad0[0x18];
    u8 *f18;
    u8 pad1C[4];
    vu0_v4 v20;
} G_005651F0;

typedef struct {
    u8 pad0[0x2548];
    s32 team;
} T_005651F0;

extern f32 D_L39_0024B554;
__asm__(".extern D_L39_0024B554, 4");
extern u8 D_L39_00242930;
extern T_005651F0 *D_L39_0024CE1C;
extern G_005651F0 D_L39_0025F740;

extern s32 func_L39_005BE900(void *, s32, f32);
extern f32 func_L39_005B44C8(void);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L39_005FFDF8(s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_L39_005FFE78(void);
extern s32 func_L01_00456250(void *);
extern void func_L39_00565D30(void *, s32, s32, f32);
extern void func_L01_00456230(void *, s32);
extern void func_L01_00446780(s32, f32, s32, s32, f32, f32, s32, s32, s32);
extern void func_L01_0031BC78(u8 *);
extern void func_L01_00404A10(void *, void *);
/* level 39 calls func_L01_003500C0's place, level 45 another empty function */
extern void func_L01_003500C0_005651F0(void *);
extern void func_003C2880(void *);

void func_L39_005651F0(u8 *obj) {
    P_005651F0 *p = *(P_005651F0 **)(obj + 0x68);
    vu0_q seg[2];
    vu0_v4 dir;
    H_005651F0 hit;
    vu0_v4 back;
    f32 t;
    f32 s;
    f32 scale;
    s32 r;
    s32 last;
    f32 step;
    s32 team;
    G_005651F0 *g;
    vu0_v4 *pos;

    t = p->f38 + 1.0f;
    s = p->f3C;
    p->f38 = t;
    if (t > 32.0f) {
        s *= 1.0f - (t - 32.0f) / 6.0f;
    }
    scale = (s > 1.0f) ? s : 1.0f;
    if (t > 2.0f) {
        seg[0] = *(vu0_q *)&p->v10;
    } else {
        seg[0] = *(vu0_q *)&p->v0;
    }
    seg[1] = *(vu0_q *)&p->v10;
    ((f32 *)&seg[1])[3] = 0.5f;
    if (func_L39_005BE900(&seg[1], 0, D_L39_0024B554) != -1) {
        func_L01_0046A610(&p->v10, &D_L39_00242930, 3, 0x60, p->f44, (s32)func_L39_005B44C8(),
                          *(f32 *)(obj + 0x2C) * 210000.0f, 200.0f, 0.95f, 0.0f, 0.0f);
    }
    if (p->f38 < 15.0f) {
        p->f34 += p->f4C * 0.020000001f;
        func_0038CF68(&p->v10, &p->v20, p->f34);
        func_0038CF68(&dir, &p->v20, 0.080000006f);
        func_L01_00446760(&hit, obj, 0x10001, &dir, scale);
        hit.f1A = *(u16 *)(obj + 0xAA);
        vec_add_ba(&p->v10, &p->v0, &p->v10);
        func_0038CF68(&hit.v30, &p->v20, -(p->f4C * 0.020000001f));
        vec_add_ab(&hit.v30, &hit.v30, &p->v10);
        team = -1;
        if (D_L39_0024CE1C != 0) {
            team = D_L39_0024CE1C->team;
        }
        func_L39_005FFDF8(team);
        r = func_003D3CB0(&p->v10, seg, 0x10, obj, &hit);
        func_L39_005FFE78();
        if (r != 0 && (g = &D_L39_0025F740)->f18 != *(u8 **)(obj + 0xB8)) {
            last = g->f18 == 0;
            pos = &g->v20;
            *(vu0_q *)&p->v10 = *(vu0_q *)pos;
            if (func_L01_00456250(obj) == 0) {
                func_L39_00565D30(pos, 0x14, p->f48, *(f32 *)(obj + 0x2C));
                func_L01_00456230(obj, 1);
                if (last) {
                    func_L01_00446780((s32)obj, 0.75f, (s32)pos, 0x10001, scale, 1.0f, 0, 1, 0);
                }
            }
            func_003C2880(obj);
            return;
        }
        func_L01_00404A10(func_L01_0031BC78, obj);
    } else if (p->f38 < 38.0f) {
        f32 d = func_0038CF38(p, &p->v10);
        step = p->f4C * 0.020000001f;
        if (step < d) {
            p->f34 += step;
            func_0038CF68(&p->v10, &p->v20, p->f34);
            func_0038CF68(&dir, &p->v20, 0.080000006f);
            func_L01_00446760(&hit, obj, 0x10001, &dir, scale);
            hit.f1A = *(u16 *)(obj + 0xAA);
            vec_add_ba(&p->v10, &p->v0, &p->v10);
            func_0038CF68(&hit.v30, &p->v20, -(p->f4C * 0.020000001f));
            vec_add_ab(&hit.v30, &hit.v30, &p->v10);
            team = -1;
            if (D_L39_0024CE1C != 0) {
                team = D_L39_0024CE1C->team;
            }
            func_L39_005FFDF8(team);
            r = func_003D3CB0(&p->v10, seg, 0x10, obj, &hit);
            func_L39_005FFE78();
            if (r != 0 && (g = &D_L39_0025F740)->f18 != *(u8 **)(obj + 0xB8)) {
                last = g->f18 == 0;
                if (g->f18 == 0 || *(s16 *)(g->f18 + 0xAA) != 0x1625) {
                    pos = &g->v20;
                    *(vu0_q *)&p->v10 = *(vu0_q *)pos;
                    if (func_L01_00456250(obj) == 0) {
                        func_L39_00565D30(pos, 0x14, p->f48, *(f32 *)(obj + 0x2C));
                        func_L01_00456230(obj, 1);
                        if (last) {
                            func_L01_00446780((s32)obj, 0.75f, (s32)pos, 0x10001, scale, 1.0f, 0, 1, 0);
                        }
                    }
                    func_003C2880(obj);
                    return;
                }
            }
            func_0038CF68(&back, &p->v20, p->f4C * 2.0f * 0.020000001f);
            vec_add_ab(&p->v0, &p->v0, &back);
            func_L01_00404A10(func_L01_0031BC78, obj);
        }
    } else {
        func_L01_003500C0_005651F0(&p->v10);
        func_003C2880(obj);
        return;
    }
    *(vu0_q *)(obj + 0x10) = *(vu0_q *)&p->v0;
}
/* localdecomp:end func_L39_005651F0 */
