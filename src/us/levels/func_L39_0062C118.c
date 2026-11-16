#include "common.h"

/* NTSC-U counterpart of func_L39_0062E930 (src/levels/shared/L39_0062E930.c) */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct {
    u8 pad[32];
    u8 m20[64];
    u8 m60[6662 - 96];
    u8 mode;
} S_62FD10;
extern u8 D_L39_004998A0[];
extern s32 func_L39_005C2098(s32, s32);

/* localdecomp:start func_L39_0062C118 */
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

extern u8 D_L39_004998A0[];
extern s32 func_L39_005C2098(s32, s32);
extern void func_L39_0062FD10(S_62FD10 *, Vec4 *, Vec4 *, f32);
extern void func_L39_006301D8(void *, Vec4 *, Vec4 *, f32);
extern f32 func_L39_0062FE30(u8 *, f32 *);
extern void func_L39_00630140(void *, Vec4 *, Vec4 *, f32);
extern void func_003BEBF8(f32 *, f32, f32);

void func_L39_0062C118(S_0062E930 *s) {
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
            *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = b;
        dec = b;
    }
    }
    eq = dec == 0x1B;
    if (!eq || s->t2F0 >= 10) {
        if (s->t2F0 < s->h14BC) {
            func_L39_0062FD10((S_62FD10 *)s, &s->v120, &s->v120, 0.0f);
            func_L39_006301D8(s, &s->v120, &s->v120, 0.013333333656191826f);
        } else if (s->b14AC != 0) {
            func_L39_0062FD10((S_62FD10 *)s, &s->v120, &s->v120, 0.0f);
            func_L39_006301D8(s, &s->v120, &s->v120, 0.015000000596046448f);
        } else {
            f32 r;
            f32 lim;
            func_L39_006301D8(s, &s->v120, &s->v120, s->f1530);
            r = func_L39_0062FE30((u8 *)s, (f32 *)&s->v120);
            lim = -s->f14B0;
            if (r < lim) {
                r = lim;
            }
            func_L39_0062FD10((S_62FD10 *)s, &s->v120, &s->v120, r);
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
            *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
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
        d = func_L39_0062FE30((u8 *)s, (f32 *)&buf);
        lim = 0.11666667461395264f;
        if (2.1f < d) {
            lim = 0.05250000208616257f;
        } else if (1.7f < d) {
            lim = 0.08166667073965073f;
        }
        if (s->t2F0 < 8) {
            r = func_L39_0062FE30((u8 *)s, (f32 *)&s->v120);
            if (r < lim) {
                func_003BEBF8(&r, lim, 0.0416666679084301f);
            }
            func_L39_0062FD10((S_62FD10 *)s, &s->v120, &s->v120, r);
        }
    } else {
        s32 still = 0;
        if (s->f14C0 == 0.0f && s->f14C4 == 0.0f) {
            still = 1;
        }
        if ((s->p2534->w1A0 & func_L39_005C2098(0x40, s->s2544)) != 0 || still != 0) {
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
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
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
                func_L39_00630140(s, &s->v120, &s->v120, s->f14C0);
                s->f14C4 = s->f14C4 + s->f14C0;
                s->f14C0 = 0.0f;
            }
        }
        if (s->b14AD != 0 && s->t2F0 >= s->seq.start && s->t2F0 < s->seq.end) {
            Seq_0062E930 *p = &s->seq;
            p->cnt++;
            while (p->idx == -1 || p->cnt >= p->arr[p->idx].n) {
                p->idx++;
                p->cnt = 0;
                if (p->arr[p->idx].f0 != -999999.0f) {
                    p->val = p->arr[p->idx].f0 * 0.00027777778450399637f;
                }
            }
            if (p->cnt > 0) {
                p->val += p->arr[p->idx].f4 * 0.00027777778450399637f;
            }
            func_L39_00630140(s, &s->v120, &s->v120, p->val);
        }
    }
}
/* localdecomp:end func_L39_0062C118 */
