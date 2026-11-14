#include "common.h"

typedef struct {
    u8 pad0[8128];
    f32 hist[224];
    s32 head;
    s32 count;
} S_0062F240;
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct {
    u8 pad0[0x20];
    f32 m0[4][4];
    f32 m1[4][4];
    u8 pad[0x1A06 - 0xA0];
    u8 mode;
} Obj62FA50;
typedef struct {
    u8 pad[32];
    u8 m20[64];
    u8 m60[6662 - 96];
    u8 mode;
} S_62FD10;

/* declared by functions of L39_0062D7C8.c, which this file was cut from */
extern u8 D_L39_004997E0[];
extern s32 func_L39_005C42E8(s32, s32);

/* localdecomp:start func_L39_0062E930 */
#include "vu0.h"

typedef union Buf_0062E930 {
    u8 b[8];
    u32 w[2];
    u128_t q;
} Buf_0062E930;

typedef struct Ent_0062E930 {
    f32 f0;
    f32 f4;
    s32 n;
    s32 pad;
} Ent_0062E930;

typedef struct Seq_0062E930 {
    s32 start;
    s32 end;
    u8 pad8[0xC];
    Ent_0062E930 *arr;
    s32 idx;
    s32 cnt;
    f32 val;
} Seq_0062E930;

typedef struct Aux_0062E930 {
    u8 pad0[0x1A0];
    u32 w1A0;
} Aux_0062E930;

typedef struct S_0062E930 {
    u8 pad0[0xA0];
    Vec4 vA0;
    u8 padB0[0x120 - 0xB0];
    Vec4 v120;
    u8 pad130[0x2F0 - 0x130];
    s32 t2F0;
    u8 pad2F4[0x1440 - 0x2F4];
    Seq_0062E930 seq;
    u8 pad1464[0x1470 - 0x1464];
    Vec4 v1470;
    u8 pad1480[0x14AC - 0x1480];
    u8 b14AC;
    u8 b14AD;
    u8 pad14AE[2];
    f32 f14B0;
    u8 pad14B4[4];
    f32 f14B8;
    s16 h14BC;
    u8 pad14BE[2];
    f32 f14C0;
    f32 f14C4;
    u8 pad14C8[0x1518 - 0x14C8];
    f32 f1518;
    f32 f151C;
    u8 pad1520[0x1528 - 0x1520];
    s16 h1528;
    u8 pad152A[0x1530 - 0x152A];
    f32 f1530;
    u8 pad1534[0x19E4 - 0x1534];
    u8 b19E4;
    u8 pad19E5[0x2534 - 0x19E5];
    Aux_0062E930 *p2534;
    u8 pad2538[0x2544 - 0x2538];
    s32 s2544;
} S_0062E930;

extern u8 D_L39_004997E0[];
extern s32 func_L39_005C42E8(s32, s32);
extern void func_L39_00632558(S_62FD10 *, Vec4 *, Vec4 *, f32);
extern void func_L39_00632A20(void *, Vec4 *, Vec4 *, f32);
extern f32 func_L39_00632678(u8 *, f32 *);
extern void func_L39_00632988(void *, Vec4 *, Vec4 *, f32);
extern void func_003C4138(f32 *, f32, f32);

void func_L39_0062E930(S_0062E930 *s) {
    Buf_0062E930 buf;
    u32 dec;
    s32 eq;

    {
    u8 *q = &s->b19E4;
    if (*q == 0) {
        dec = 0;
    } else {
        u32 a;
        u32 b;
        s32 n;
        s32 k;
        s32 m;
        s32 i;
        u8 *d;

        n = *q;
        k = ((u32)q - n) & 7;
        m = n + 1;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = b;
        dec = b;
    }
    }
    eq = dec == 0x1B;
    if (!eq || s->t2F0 >= 8) {
        if (s->t2F0 < s->h14BC) {
            func_L39_00632558((S_62FD10 *)s, &s->v120, &s->v120, 0.0f);
            func_L39_00632A20(s, &s->v120, &s->v120, 0.0192f);
        } else if (s->b14AC != 0) {
            func_L39_00632558((S_62FD10 *)s, &s->v120, &s->v120, 0.0f);
            func_L39_00632A20(s, &s->v120, &s->v120, 0.0216f);
        } else {
            f32 r;
            f32 lim;
            func_L39_00632A20(s, &s->v120, &s->v120, s->f1530);
            r = func_L39_00632678((u8 *)s, (f32 *)&s->v120);
            lim = -s->f14B0;
            if (r < lim) {
                r = lim;
            }
            func_L39_00632558((S_62FD10 *)s, &s->v120, &s->v120, r);
        }
    }

    {
    u8 *q = &s->b19E4;
    if (*q == 0) {
        dec = 0;
    } else {
        u32 a;
        u32 b;
        s32 n;
        s32 k;
        s32 m;
        s32 i;
        u8 *d;

        n = *q;
        k = ((u32)q - n) & 7;
        m = n + 1;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = b;
        dec = b;
    }
    }
    eq = dec == 0xE;
    if (eq) {
        f32 d;
        f32 lim;
        f32 r;
        Vec4 unused[2];

        vec_sub_ab(&buf, &s->vA0, &s->v1470);
        d = func_L39_00632678((u8 *)s, (f32 *)&buf);
        lim = 0.14000001f;
        if (2.1f < d) {
            lim = 0.063000008f;
        } else if (1.7f < d) {
            lim = 0.098000012f;
        }
        if (s->t2F0 < 7) {
            r = func_L39_00632678((u8 *)s, (f32 *)&s->v120);
            if (r < lim) {
                func_003C4138(&r, lim, 0.060000002f);
            }
            func_L39_00632558((S_62FD10 *)s, &s->v120, &s->v120, r);
        }
    } else {
        s32 still = 0;
        if (s->f14C0 == 0.0f && s->f14C4 == 0.0f) {
            still = 1;
        }
        if ((s->p2534->w1A0 & func_L39_005C42E8(0x40, s->s2544)) != 0 || still != 0) {
            goto ramp;
        }
        {
        u8 *q = &s->b19E4;
        if (*q == 0) {
            dec = 0;
        } else {
                    u32 a;
            u32 b;
            s32 n;
            s32 k;
            s32 m;
            s32 i;
            u8 *d;

            n = *q;
            k = ((u32)q - n) & 7;
            m = n + 1;
            d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            b = buf.w[1] ^ a;
            buf.w[0] = a;
            buf.w[1] = b;
            dec = b;
        }
        }
        eq = dec == 0x12;
        if (eq) {
        ramp:
            if (s->f14B8 < s->f151C && s->h1528 >= s->t2F0) {
                f32 hi = s->f151C;
                f32 v = s->f14B8 + (hi - s->f1518) / (f32)s->h1528;
                s->f14B8 = v;
                if (hi < v) {
                    s->f14B8 = hi;
                }
                s->f14C0 = s->f14C0 + (sqrt_asm((s->f14B8 + s->f14B8) * s->f1530) - s->f14C4 - s->f14C0);
            }
        }
        if (s->t2F0 >= s->h14BC) {
            if (0.0f < s->f14C0) {
                func_L39_00632988(s, &s->v120, &s->v120, s->f14C0);
                s->f14C4 = s->f14C4 + s->f14C0;
                s->f14C0 = 0.0f;
            }
        }
        if (s->b14AD != 0 && s->t2F0 >= s->seq.start && s->t2F0 < s->seq.end) {
            Seq_0062E930 *p = &s->seq;
            p->cnt++;
            while (p->idx == -1 || p->cnt >= (p->arr[p->idx].n * 5 + 2) / 6) {
                p->idx++;
                p->cnt = 0;
                if (p->arr[p->idx].f0 != -999999.0f) {
                    p->val = p->arr[p->idx].f0 * 0.00040000002f;
                }
            }
            if (p->cnt > 0) {
                p->val += p->arr[p->idx].f4 * 0.00040000002f;
            }
            func_L39_00632988(s, &s->v120, &s->v120, p->val);
        }
    }
}
/* localdecomp:end func_L39_0062E930 */

INCLUDE_ASM("asm/levels", func_L39_0062EF58);

/* localdecomp:start func_L39_0062FCF0 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0062FCF0;
typedef struct {
    u8 p00[0x10];
    V4_0062FCF0 pos;
} T_0062FCF0;
typedef struct {
    u8 p00[0x20];
    V4_0062FCF0 v20;
    u8 p30[0x70];
    V4_0062FCF0 posA0;
    u8 pB0[8];
    f32 fB8;
    u8 pBC[0xF04];
    V4_0062FCF0 vFC0;
    f32 fFD0;
    u8 pFD4[0x6C];
    V4_0062FCF0 v1040;
    u8 p1050[0x14];
    T_0062FCF0 *f1064;
    s32 f1068;
    f32 f106C;
    u8 p1070[8];
    T_0062FCF0 *f1078;
    u8 p107C[0x998];
    u8 f1A14;
    u8 p1A15[0xA53];
    f32 f2468;
} O_0062FCF0;

extern f32 func_0038D160(f32, f32);
extern void func_L39_00632D78(void *, s32, f32);
extern T_0062FCF0 *func_L39_00639B70(void *, f32, f32, f32, f32, V4_0062FCF0 *, s32, s32);
extern void func_L39_00632558(S_62FD10 *, Vec4 *, Vec4 *, f32);

void func_L39_0062FCF0(O_0062FCF0 *obj, f32 a, f32 b, f32 c) {
    V4_0062FCF0 v;
    T_0062FCF0 *t;
    T_0062FCF0 *u;
    f32 f;

    if (obj->f1068 == 0) {
        v = obj->v20;
        f = obj->fB8;
        if (obj->f2468 > 0.5f) {
            func_L39_00632D78(obj, 0, 1.0f);
            obj->f1068 = 1;
            v = obj->vFC0;
            obj->f1064 = 0;
            f = obj->fFD0;
        }
        if (obj->f1A14 != 0 || (u = obj->f1078) == 0) {
            t = func_L39_00639B70(obj, a, f, b, c, &v, -1, 0);
        } else {
            t = u;
        }
        if (t != 0 && (obj->f1064 == 0 || obj->f1068 != 0)) {
            obj->f106C = func_0038D160(t->pos.x - obj->posA0.x, t->pos.y - obj->posA0.y);
            vec_sub_ab(&obj->v1040, &t->pos, &obj->posA0);
            obj->f1064 = t;
            if (obj->f1A14 != 0) {
                obj->f1078 = t;
            }
        } else {
            obj->f106C = f;
            obj->v1040 = v;
        }
        func_L39_00632558((S_62FD10 *)obj, (Vec4 *)&obj->v1040, (Vec4 *)&obj->v1040, 0.0f);
    }
}
/* localdecomp:end func_L39_0062FCF0 */
