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

/* localdecomp:start func_L39_0062EF58 */
#include "vu0.h"

typedef int q_0062EF58 __attribute__((mode(TI)));

typedef union Buf_0062EF58 {
    q_0062EF58 q;
    u8 b[8];
    u32 w[2];
    f32 f[4];
} Buf_0062EF58;

typedef union V_0062EF58 {
    q_0062EF58 q;
    f32 f[4];
} V_0062EF58;

typedef struct S_0062EF58 {
    u8 pad0[0x20];
    u8 m20[0x20];
    u8 m40[0x78];
    f32 fB8;
    u8 padBC[0x120 - 0xBC];
    Vec4 v120;
    u8 pad130[0x190 - 0x130];
    q_0062EF58 q190;
    u8 pad1A0[4];
    f32 f1A4;
    u8 pad1A8[0x2D8 - 0x1A8];
    s16 h2D8;
    s16 h2DA;
    u8 pad2DC[0x2F0 - 0x2DC];
    s32 t2F0;
    u8 pad2F4[0x3D0 - 0x2F4];
    q_0062EF58 q3D0;
    u8 pad3E0[4];
    s16 h3E4;
    u8 pad3E6[2];
    f32 f3E8;
    u8 pad3EC[0x628 - 0x3EC];
    f32 f628;
    u8 pad62C[0xFB0 - 0x62C];
    f32 fFB0;
    f32 fFB4;
    u8 padFB8[0xFC0 - 0xFB8];
    V_0062EF58 vFC0;
    f32 fFD0;
    u8 mFD4[4];
    f32 fFD8;
    u8 padFDC[0x1310 - 0xFDC];
    s32 w1310;
    u8 pad1314[0x1464 - 0x1314];
    f32 f1464;
    u8 pad1468[0x1480 - 0x1468];
    Vec4 v1480;
    q_0062EF58 q1490;
    u8 pad14A0[4];
    f32 f14A4;
    u8 pad14A8[0x14AE - 0x14A8];
    u8 b14AE;
    u8 pad14AF[0x14BE - 0x14AF];
    s16 h14BE;
    u8 pad14C0[0x14CC - 0x14C0];
    f32 f14CC;
    f32 f14D0;
    f32 f14D4;
    u8 pad14D8[0x14E4 - 0x14D8];
    s32 w14E4;
    f32 f14E8;
    f32 f14EC;
    u8 pad14F0[0x1500 - 0x14F0];
    V_0062EF58 v1500;
    u8 pad1510[0x1530 - 0x1510];
    f32 f1530;
    s16 h1534;
    u8 pad1536[0x153D - 0x1536];
    u8 b153D;
    u8 pad153E[0x15A0 - 0x153E];
    q_0062EF58 q15A0;
    u8 pad15B0[0x15C4 - 0x15B0];
    f32 f15C4;
    u8 pad15C8[0x19E4 - 0x15C8];
    u8 b19E4;
    u8 pad19E5;
    u8 b19E6;
    u8 pad19E7[0x1A06 - 0x19E7];
    u8 b1A06;
    u8 pad1A07[0x23B8 - 0x1A07];
    f32 f23B8;
    u8 pad23BC[4];
    q_0062EF58 q23C0;
    u8 pad23D0[0x2468 - 0x23D0];
    f32 f2468;
    u8 pad246C[0x2534 - 0x246C];
    s32 w2534;
} S_0062EF58;

extern f32 D_L39_00246010;
extern void func_L31_004F3CA0_0062EF58(void *, f32, f32);
extern void func_L39_00633620(void *, f32, f32);
extern void func_L39_00632298(void *, void *, void *, f32);
extern void func_L39_00632888(void *, void *, void *, f32);
extern void func_L39_00633308(void *, s32, f32, f32, f32);
extern void func_L39_0062D190(void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L39_006212E8(void *);
extern void func_L39_00637E10(void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_00448728(void *, f32, void *, f32, f32, f32, s32);
extern f32 func_0038DB00(f32, f32);
extern void func_L39_00633980(void *, f32, f32, f32);
extern f32 func_L39_006325D8(void *, void *);

void func_L39_0062EF58(S_0062EF58 *s) {
    Buf_0062EF58 buf;
    Buf_0062EF58 buf2;
    f32 t;
    f32 len;
    f32 r;

    if (((({
            u8 *q = &s->b19E4;
            u32 dec;
        
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
            dec;
        }) ^ 0xA) == 0)) {
        func_L31_004F3CA0_0062EF58(s, 0.7f, 0.0f);
        s->q190 = s->q15A0;
        s->fFB4 = s->f1A4;
    } else if (((({
            u8 *q = &s->b19E4;
            u32 dec;
        
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
            dec;
        }) ^ 0x10) == 0)) {
        if (s->t2F0 >= 0x2E) {
            ((f32 (*)(f32 *, f32, f32))func_003C4138)(&s->f1530, 0.010000001f, 0.0028000001f);
        }
        if (s->t2F0 < 0x2E) {
            s->fFB0 = s->f1464;
        } else {
            s->fFB0 = 0.07000001f;
        }
        func_L39_00633620(s, 0.0176f, 0.018000001f);
        func_L39_00632298(s, &s->v120, &s->v120, 0.0f);
        func_L39_00632888(s, &s->v120, &s->v120, s->fFB4);
    } else if (((({
            u8 *q = &s->b19E4;
            u32 dec;
        
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
            dec;
        }) ^ 0x1B) == 0)) {
        f32 x;

        if (s->t2F0 >= 0x22) {
            func_L39_00633308(s, 0, 0.057600003f, 0.28800002f, 0.30019665f);
            func_L39_0062D190(s, 0.008f);
        }
        x = s->f628;
        if (13.0f <= x && x <= 30.0f) {
            if (27.0f < x) {
                ((f32 (*)(f32 *, f32, f32))func_003C4138)(&s->f14CC, 0.0f, 0.0032000002f);
            } else {
                ((f32 (*)(f32 *, f32, f32))func_003C4138)(&s->f14CC, 0.040000003f, 0.0032000002f);
            }
        }
        buf.f[0] = s->f14CC;
        buf.f[1] = 0.0f;
        buf.f[2] = func_0038CE68(&s->v120, s->m40);
        func_0038D000(&s->v120, &buf, s->m20);
    } else if (((({
            u8 *q = &s->b19E4;
            u32 dec;
        
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
            dec;
        }) ^ 0xB) == 0)) {
        if ((s->h3E4 != 0 ||
             (s->w1310 == 1 && func_L01_004606E8(0x28, 2, 0, s->w2534) != 0 &&
              func_L39_006212E8(s) != 10)) &&
            ((({
                    u8 *q = &s->b19E4;
                    u32 dec;
                
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
                    dec;
                }) ^ 0x10) != 0)) {
            func_L39_00637E10(s);
        } else {
            s->fFD0 = s->f14D4;
            s->vFC0.q = s->q1490;
            func_L39_00633308(s, 0, 0.057600003f, 0.28800002f, 0.13962635f);
        }
        if (s->w14E4 != 3) {
            s->fFB4 = s->f14E8;
        } else {
            s->fFB4 = 0.0f;
        }
        if (s->b153D != 0) {
            f32 r = s->f2468 * 0.10000001f;
            if (r < 0.040000003f) {
                r = 0.040000003f;
            }
            ((f32 (*)(f32 *, f32, f32))func_003C4138)(&s->f14EC, r, 0.014800001f);
            s->fFB4 = s->f1A4;
        } else if (s->b14AE != 0 && s->h14BE < 10) {
            ((f32 (*)(f32 *, f32, f32))func_003C4138)(&s->f14EC, 0.0f, 0.0032000002f);
        } else {
            ((f32 (*)(f32 *, f32, f32))func_003C4138)(&s->f14EC, 0.084f, 0.0032000002f);
        }
        if (s->b1A06 == 0) {
            s->v120.f[0] = func_0038D098(s->f14D0) * s->f14EC;
            s->v120.f[1] = func_0038D0B0(s->f14D0) * s->f14EC;
        } else {
            func_L39_00632298(s, &buf, &s->v1480, s->f14EC);
            func_L39_00632558((S_62FD10 *)s, (Vec4 *)&buf, (Vec4 *)&buf, 0.0f);
            func_L39_00632298(s, &s->v120, &s->v120, 0.0f);
            vec_add_ab(&s->v120, &s->v120, &buf);
        }
        if (s->b1A06 == 0 && s->b153D == 0) {
            f32 k = s->f14E8 * func_0038D0B0(func_0038DBA0(s->f14D4, s->f14D0));
            s->v120.f[0] += func_0038D098(s->f14D4) * k;
            s->v120.f[1] += func_0038D0B0(s->f14D4) * k;
        }
        func_L31_004F3CA0_0062EF58(s, 0.7f, 0.0f);
        s->q190 = s->q15A0;
    } else if (((({
            u8 *q = &s->b19E4;
            u32 dec;
        
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
            dec;
        }) ^ 0x11) == 0)) {
        V_0062EF58 *dir = &s->vFC0;

        s->fFD0 = s->v1500.f[3];
        dir->q = s->v1500.q;
        if (s->t2F0 >= 8) {
            func_L39_00633308(s, -1, 0.060480002f, 0.28800002f, 0.23736478f);
        }
        if (s->t2F0 >= 7) {
            if (s->h2D8 == 0) {
                s->v120.f[0] = func_0038D098(s->fFD0) * 0.09800001f;
                s->v120.f[1] = func_0038D0B0(s->fFD0) * 0.09800001f;
            } else {
                func_L39_00632298(s, &s->v120, &s->v120, 0.0f);
                func_0038CF68(&buf, dir, 0.09800001f);
                vec_add_ab(&s->v120, &s->v120, &buf);
            }
        }
        s->fFB4 = s->f1A4;
    } else if (((({
            u8 *q = &s->b19E4;
            u32 dec;
        
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
            dec;
        }) ^ 0x83) == 0)) {
        if (s->w1310 != 0) {
            s->fFD0 = s->f23B8;
        }
        func_L39_00633308(s, 0, 0.057600003f, 0.28800002f, s->f14A4);
        s->fFB4 = 0.0f;
    } else {
        if (((({
                u8 *q = &s->b19E4;
                u32 dec;
            
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
                dec;
            }) ^ 0x2C) == 0)) {
            f32 yaw;

            t = s->fB8;
            s->fFD8 = func_L01_00448728(&t, s->fFD0, s->mFD4, 0.02592f, 0.28800002f, 0.14660767f, 0);
            yaw = func_0038DB00(t, s->fB8);
            func_L39_00633980(s, 0.0f, 0.0f, yaw);
        } else {
            f32 sf;

            buf.q = s->vFC0.q;
            sf = s->fFD0;
            if ((s->h3E4 != 0 ||
                 (s->w1310 == 1 && func_L01_004606E8(0x28, 2, 0, s->w2534) != 0 &&
                  func_L39_006212E8(s) != 10)) &&
                ((({
                        u8 *q = &s->b19E4;
                        u32 dec;
                    
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
                            d = buf2.b;
                            for (i = 0; i < 40; i += 5) {
                                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                            }
                            a = buf2.w[0] ^ (u32)q;
                            b = buf2.w[1] ^ a;
                            buf2.w[0] = a;
                            buf2.w[1] = b;
                            dec = b;
                        }
                        dec;
                    }) ^ 0x10) != 0)) {
                s->fFD0 = s->f23B8;
                s->vFC0.q = s->q23C0;
            }
            func_L39_00633308(s, 0, 0.057600003f, 0.28800002f, s->f14A4);
            if ((s->h3E4 != 0 ||
                 (s->w1310 == 1 && func_L01_004606E8(0x28, 2, 0, s->w2534) != 0 &&
                  func_L39_006212E8(s) != 10)) &&
                ((({
                        u8 *q = &s->b19E4;
                        u32 dec;
                    
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
                            d = buf2.b;
                            for (i = 0; i < 40; i += 5) {
                                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                            }
                            a = buf2.w[0] ^ (u32)q;
                            b = buf2.w[1] ^ a;
                            buf2.w[0] = a;
                            buf2.w[1] = b;
                            dec = b;
                        }
                        dec;
                    }) ^ 0x10) != 0)) {
                s->f3E8 = sf;
                s->q3D0 = buf.q;
                s->fFD0 = sf;
                s->vFC0.q = buf.q;
            }
        }
        func_L31_004F3CA0_0062EF58(s, 0.7f, 0.0f);
        s->q190 = s->q15A0;
        r = 0.008f;
        if (s->fFB0 < D_L39_00246010 * 0.020000001f * 0.2f) {
            if (((({
                    u8 *q = &s->b19E6;
                    u32 dec;
                
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
                    dec;
                }) ^ 2) == 0)) {
                f32 rate = s->f15C4;

                len = func_L39_006325D8(s, &s->v120);
                ((f32 (*)(f32 *, f32, f32))func_003C4138)(&len, 0.0f, rate);
                func_L39_00632298(s, &s->v120, &s->v120, len);
                return;
            }
            if (s->h2DA != 0) {
                r = 0.0044f;
            } else if (s->h1534 != 0) {
                r = 0.00080000004f;
            } else {
                r = 0.0032000002f;
            }
        }
        func_L39_0062D190(s, r);
    }
}
/* localdecomp:end func_L39_0062EF58 */

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
