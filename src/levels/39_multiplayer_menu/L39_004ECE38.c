#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_004ECE38);

LINKER_REMNANT("asm/levels", func_L39_004ED220);

INCLUDE_ASM("asm/levels", func_L39_004ED228);

INCLUDE_ASM("asm/levels", func_L39_004ED578);

INCLUDE_ASM("asm/levels", func_L39_004ED6A8);

/* localdecomp:start func_L39_004ED810 */
s32 func_L39_004ED810(u8 *ctx, s32 v) {
    *(s32 *)(ctx + 0xBC) = v;
    return 0;
}
/* localdecomp:end func_L39_004ED810 */

/* localdecomp:start func_L39_004ED820 */
extern s32 func_L39_004EDE58();

typedef struct {
    u64 h[5];
    u64 n0;
    u64 n1;
    u8 pad[0xB8 - 0x38];
    s32 num;
    s32 (*block)();
} S_004ED820;

void func_L39_004ED820(S_004ED820 *c) {
    c->h[0] = 0x67452301;
    c->h[1] = 0xEFCDAB89;
    c->h[2] = 0x98BADCFE;
    c->h[3] = 0x10325476;
    c->h[4] = 0xC3D2E1F0;
    c->n0 = 0;
    c->n1 = 0;
    c->num = 0;
    c->block = func_L39_004EDE58;
}
/* localdecomp:end func_L39_004ED820 */

INCLUDE_ASM("asm/levels", func_L39_004ED888);

LINKER_REMNANT("asm/levels", func_L39_004EDE50);

INCLUDE_ASM("asm/levels", func_L39_004EDE58);

INCLUDE_ASM("asm/levels", func_L39_004EE378);

INCLUDE_ASM("asm/levels", func_L39_004EE670);

INCLUDE_ASM("asm/levels", func_L39_004EE958);

INCLUDE_ASM("asm/levels", func_L39_004EEBC0);

INCLUDE_ASM("asm/levels", func_L39_004EED58);

INCLUDE_ASM("asm/levels", func_L39_004EEEF0);

INCLUDE_ASM("asm/levels", func_L39_004EEFF0);

/* localdecomp:start func_L39_004EF078 */
extern s32 func_L01_00494120(s32);
extern void *func_L39_004DF010(void);
extern void func_L39_004DF0E0(void *);
extern s32 func_L39_004DF158(void *, void *);
extern s32 func_L39_004DF260(void *, u8 *, s32, s32);
extern void func_L39_004DF408(void *, void *, s32);
extern s32 func_L39_004DF410(void *, u8 *, s32 *);
extern void func_0011D380(void *, void *, s32);
extern void func_0011D534(void *, s32, s32);

s32 func_L39_004EF078(s32 md, u8 *sec, s32 sec_len, s32 seed, s32 seed_len, u8 *out, s32 olen) {
    s32 chunk;
    s32 j;
    void *ctx;
    void *ctx_tmp;
    u8 A1[0x40];
    s32 A1_len;
    s32 ret = 0;

    chunk = func_L01_00494120(md);
    ctx = func_L39_004DF010();
    ctx_tmp = func_L39_004DF010();
    if (ctx == 0 || ctx_tmp == 0) {
        goto err;
    }
    if (!func_L39_004DF260(ctx, sec, sec_len, md)) {
        goto err;
    }
    func_L39_004DF408(ctx, (void *)seed, seed_len);
    if (!func_L39_004DF410(ctx, A1, &A1_len)) {
        goto err;
    }
    for (;;) {
        if (!func_L39_004DF260(ctx, 0, 0, 0)) {
            goto err;
        }
        func_L39_004DF408(ctx, A1, A1_len);
        if (!func_L39_004DF158(ctx_tmp, ctx)) {
            goto err;
        }
        func_L39_004DF408(ctx, (void *)seed, seed_len);
        if (olen > chunk) {
            if (!func_L39_004DF410(ctx, out, &j)) {
                goto err;
            }
            out += j;
            olen -= j;
            if (!func_L39_004DF410(ctx_tmp, A1, &A1_len)) {
                goto err;
            }
        } else {
            if (!func_L39_004DF410(ctx, A1, &A1_len)) {
                goto err;
            }
            func_0011D380(out, A1, olen);
            break;
        }
    }
    ret = 1;
err:
    if (ctx != 0) {
        func_L39_004DF0E0(ctx);
    }
    if (ctx_tmp != 0) {
        func_L39_004DF0E0(ctx_tmp);
    }
    func_0011D534(A1, 0, 0x40);
    return ret;
}
/* localdecomp:end func_L39_004EF078 */

/* localdecomp:start func_L39_004EF240 */
extern s32 func_L39_004EF078(s32, u8 *, s32, s32, s32, u8 *, s32);

s32 func_L39_004EF240(s32 a0, s32 a1, s32 a2, s32 a3, u8 *a4, s32 a5, u8 *a6, u8 *a7, s32 a8) {
    s32 len = a5 / 2;
    u8 *b = a4 + len;
    s32 i;

    len += a5 & 1;

    if (!func_L39_004EF078(a0, a4, len, a2, a3, a6, a8)) {
        return 0;
    }
    if (!func_L39_004EF078(a1, b, len, a2, a3, a7, a8)) {
        return 0;
    }
    for (i = 0; i < a8; i++) {
        a6[i] ^= a7[i];
    }
    return 1;
}
/* localdecomp:end func_L39_004EF240 */

INCLUDE_ASM("asm/levels", func_L39_004EF350);

INCLUDE_ASM("asm/levels", func_L39_004EF448);

INCLUDE_ASM("asm/levels", func_L39_004EF8F8);

INCLUDE_ASM("asm/levels", func_L39_004EFA50);

/* localdecomp:start func_L39_004EFD20 */
extern s32 func_L39_00505120(void *, void *);
extern void func_L39_004DD7A8(void *, void *, s32 *);

s32 func_L39_004EFD20(u8 *ctx, void *src, void *md) {
    s32 n;

    if (!func_L39_00505120(*(void **)(ctx + 0x128), src)) {
        return 0;
    }
    func_L39_004DD7A8(*(void **)(ctx + 0x128), md, &n);
    return n;
}
/* localdecomp:end func_L39_004EFD20 */

INCLUDE_ASM("asm/levels", func_L39_004EFD78);

INCLUDE_ASM("asm/levels", func_L39_004EFE90);

INCLUDE_ASM("asm/levels", func_L39_004EFFE8);

INCLUDE_ASM("asm/levels", func_L39_004F00E8);

/* localdecomp:start func_L39_004F01D8 */
typedef struct {
    s32 hi;
    u32 lo;
    u32 ns;
} V_004F01D8;

typedef struct {
    s32 f0;
    s32 f4;
    V_004F01D8 t;
} T_004F01D8;

s32 func_L39_004F01D8(T_004F01D8 *a, T_004F01D8 *b, s32 *out) {
    V_004F01D8 zero;
    V_004F01D8 *pa;
    V_004F01D8 *pb;
    s32 r;

    func_0011D534(&zero, 0, sizeof(zero));
    pa = (a == 0) ? &zero : &a->t;
    pb = (b == 0) ? &zero : &b->t;
    if (pa->hi > pb->hi) {
        r = 1;
    } else if (pa->hi < pb->hi) {
        r = -1;
    } else if (pa->lo > pb->lo) {
        r = 1;
    } else if (pa->lo < pb->lo) {
        r = -1;
    } else if (pa->ns > pb->ns) {
        r = 1;
    } else if (pa->ns < pb->ns) {
        r = -1;
    } else {
        r = 0;
    }
    *out = r;
    return 0;
}
/* localdecomp:end func_L39_004F01D8 */

/* localdecomp:start func_L39_004F02A0 */
/* LOG
 */
typedef struct {
    s32 hi;
    u32 lo;
    u32 ns;
} V_004F02A0;

typedef struct {
    s32 f0;
    s32 f4;
    V_004F02A0 v;
} T_004F02A0;

typedef struct {
    u32 *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} BN_004F02A0;

typedef struct {
    u8 pad[0x1C8];
    s32 days[2][13];
} C_004F02A0;

extern u8 D_L39_00478BF8[];
extern u8 D_L39_00478C18[];
extern u8 D_L39_00478C40[];

extern void *func_L39_004DBA08(void);
extern BN_004F02A0 *func_L39_004FC380_004F02A0(void);
extern s32 func_L39_004FC6F8_004F02A0(BN_004F02A0 *, unsigned long);
extern unsigned long func_L39_004FD228_004F02A0(BN_004F02A0 *, unsigned long);
extern BN_004F02A0 *func_L39_004FC580_004F02A0(BN_004F02A0 *);
extern s32 func_L39_004FD500_004F02A0(BN_004F02A0 *, unsigned long);
extern s32 func_L39_004FD678_004F02A0(BN_004F02A0 *, unsigned long);
extern unsigned long func_L39_004FD2D0_004F02A0(BN_004F02A0 *, unsigned long);
extern s32 func_L39_004FB9A0_004F02A0(BN_004F02A0 *, BN_004F02A0 *, BN_004F02A0 *);
extern s32 func_L39_004FBDA0_004F02A0(BN_004F02A0 *, BN_004F02A0 *, BN_004F02A0 *);
extern s32 func_L39_004FD3B0_004F02A0(BN_004F02A0 *, unsigned long);
extern void func_L39_004FC228_004F02A0(BN_004F02A0 *);
extern s32 func_L39_004FCB28_004F02A0(BN_004F02A0 *, BN_004F02A0 *, s32);
extern unsigned long func_L39_004FC668_004F02A0(BN_004F02A0 *);
extern void func_0011D534(void *, s32, s32);
extern s32 func_00120048(u8 *, u8 *, ...);

s32 func_L39_004F02A0(T_004F02A0 *out, s32 type, u8 *buf, s32 *plen, s32 buflen) {
    C_004F02A0 *ctx;
    s32 ret;
    V_004F02A0 *t;

    ctx = func_L39_004DBA08();
    ret = 0;

    if (buf == 0 || out == 0) {
        ret = 0x2721;
        goto end;
    }
    t = &out->v;
    if (type == 1 || type == 2 || type == 6) {
        s32 day = -1;
        s32 year, yday, m, leap;

        s32 hour, min, sec;
        V_004F02A0 tmp;
        BN_004F02A0 *bn3;
        s32 neg = 0;
        BN_004F02A0 *bn4;
        BN_004F02A0 *bn;
        BN_004F02A0 *bn2;
        bn = func_L39_004FC380_004F02A0();
        if (bn == 0) {
            ret = 0x2715;
            goto end;
        }
        if (out->v.hi < 0) {
            tmp.hi = ~out->v.hi;
            tmp.lo = ~t->lo;
            tmp.ns = t->ns;
            t = &tmp;
            t->lo++;
            if (t->lo == 0) {
                t->hi++;
            }
            neg = 1;
        }
        func_L39_004FC6F8_004F02A0(bn, t->hi);
        func_L39_004FCB28_004F02A0(bn, bn, 32);
        func_L39_004FD3B0_004F02A0(bn, t->lo);
        if (neg) {
            bn->neg = 1;
        }
        sec = (s32)func_L39_004FD2D0_004F02A0(bn, 60);
        min = (s32)func_L39_004FD2D0_004F02A0(bn, 60);
        hour = (s32)func_L39_004FD2D0_004F02A0(bn, 24);
        bn2 = func_L39_004FC580_004F02A0(bn);
        if (bn2 == 0) {
            ret = 0x2715;
            goto end;
        }
        func_L39_004FD678_004F02A0(bn2, 400);
        func_L39_004FD2D0_004F02A0(bn2, 146097);
        bn3 = func_L39_004FC580_004F02A0(bn2);
        if (bn3 == 0) {
            ret = 0x2715;
            goto end;
        }
        func_L39_004FD3B0_004F02A0(bn2, 1970);
        bn4 = func_L39_004FC580_004F02A0(bn2);
        if (bn4 == 0) {
            ret = 0x2715;
            goto end;
        }
        if (bn->neg == 0) {
            func_L39_004FD500_004F02A0(bn4, 1);
        }
        func_L39_004FD678_004F02A0(bn3, 365);
        func_L39_004FD2D0_004F02A0(bn4, 4);
        func_L39_004FB9A0_004F02A0(bn3, bn3, bn4);
        func_L39_004FD2D0_004F02A0(bn4, 25);
        func_L39_004FBDA0_004F02A0(bn3, bn3, bn4);
        func_L39_004FD2D0_004F02A0(bn4, 4);
        func_L39_004FB9A0_004F02A0(bn3, bn3, bn4);
        func_L39_004FD500_004F02A0(bn3, 477);
        if (bn->neg != 0 && bn2->neg == 0 &&
            !(func_L39_004FD228_004F02A0(bn2, 400) == 0 || (func_L39_004FD228_004F02A0(bn2, 4) == 0 && func_L39_004FD228_004F02A0(bn2, 100) != 0))) {
            func_L39_004FD3B0_004F02A0(bn3, 1);
        }
        func_L39_004FBDA0_004F02A0(bn, bn, bn3);
        if (bn->neg != 0) {
            func_L39_004FD500_004F02A0(bn2, 1);
            func_L39_004FD3B0_004F02A0(bn, (func_L39_004FD228_004F02A0(bn2, 400) == 0 || (func_L39_004FD228_004F02A0(bn2, 4) == 0 && func_L39_004FD228_004F02A0(bn2, 100) != 0)) ? 366 : 365);
        }
        leap = 0;
        yday = (s32)func_L39_004FC668_004F02A0(bn);
        if (func_L39_004FD228_004F02A0(bn2, 400) == 0 || (func_L39_004FD228_004F02A0(bn2, 4) == 0 && func_L39_004FD228_004F02A0(bn2, 100) != 0)) {
            if (yday < 366) {
                leap = 1;
            } else {
                func_L39_004FD3B0_004F02A0(bn2, 1);
                yday -= 366;
            }
        } else if (yday >= 365) {
            func_L39_004FD3B0_004F02A0(bn2, 1);
            yday -= 365;
            if (func_L39_004FD228_004F02A0(bn2, 400) == 0 || (func_L39_004FD228_004F02A0(bn2, 4) == 0 && func_L39_004FD228_004F02A0(bn2, 100) != 0)) {
                leap = 1;
            }
        }
        for (m = 1; m < 13; m++) {
            if (yday < ctx->days[leap][m]) {
                day = yday - ctx->days[leap][m - 1];
                break;
            }
        }
        day++;
        if (type == 1) {
            year = (s32)func_L39_004FC668_004F02A0(bn2);
            if (bn2->neg != 0 || year > 0x801 || year < 0x79E) {
                ret = 0x2723;
                goto end;
            }
            *plen = 14;
            if (buflen < 14) {
                ret = 0x2720;
                goto end;
            }
            func_00120048(buf, D_L39_00478BF8, year % 100, m, day, hour, min, sec);
        } else if (type == 2) {
            year = (s32)func_L39_004FC668_004F02A0(bn2);
            if (bn2->neg != 0 || year > 9999) {
                ret = 0x2723;
                goto end;
            }
            *plen = 17;
            if (buflen < 17) {
                ret = 0x2720;
                goto end;
            }
            func_00120048(buf, D_L39_00478C18, year, m, day, hour, min, sec, t->ns / 100000000);
        } else if (type == 6) {
            year = (s32)func_L39_004FC668_004F02A0(bn2);
            if (bn2->neg != 0 || year > 9999) {
                ret = 0x2723;
                goto end;
            }
            *plen = 20;
            if (buflen < 20) {
                ret = 0x2720;
                goto end;
            }
            func_00120048(buf, D_L39_00478C40, year, m, day, hour, min, sec);
        }
        func_L39_004FC228_004F02A0(bn);
        func_L39_004FC228_004F02A0(bn2);
        func_L39_004FC228_004F02A0(bn3);
        func_L39_004FC228_004F02A0(bn4);
    } else if (type == 3) {
        s32 n = 8;
        s32 fill = 0;
        s32 sign = 1;
        s32 found = 0;
        u32 i;
        s32 v;
        u8 *p;
        u8 *q;

        if (t->hi < 0) {
            sign = -1;
            fill = -1;
        }
        v = sign * t->hi;
        for (i = 3; (s32)i >= 0; i--) {
            if (((v >> (i * 8)) & 0xFF) != 0) {
                found = 1;
                break;
            }
            n--;
        }
        if (!found) {
            v = sign * t->lo;
            for (i = 3; (s32)i >= 0; i--) {
                if (((v >> (i * 8)) & 0xFF) != 0) {
                    break;
                }
                n--;
            }
        }
        if (buflen < n) {
            *plen = n;
            ret = 0x2720;
            goto end;
        }
        func_0011D534(buf, fill, buflen - n);
        *plen = buflen;
        p = buf + buflen - 1;
        q = (u8 *)&t->lo;
        i = 0;
        *p-- = *q++;
        if (n != 0) {
            do {
                if (++i >= 4) {
                    break;
                }
                *p-- = *q++;
            } while (i != n);
            if (i != n) {
                q = (u8 *)&t->hi;
                *p-- = *q++;
                i = 0;
                if (n != 4) {
                    do {
                        if (++i >= 4) {
                            break;
                        }
                        *p-- = *q++;
                    } while (i + 4 != n);
                }
            }
        }
    } else {
        goto err;
    }
    goto end;
    do {
err:
        ret = 0x2724;
    } while (0);
end:
    return ret;
}
/* localdecomp:end func_L39_004F02A0 */

/* localdecomp:start func_L39_004F0A78 */
typedef struct {
    s32 val;
    s32 width;
    s8 sep;
} F_004F0A78;

typedef struct {
    u32 *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} BN_004F0A78;

typedef struct {
    u8 pad[0x1C8];
    s32 days[2][13];
} C_004F0A78;

typedef struct {
    s32 f0;
    s32 f4;
    u32 hi;
    u32 lo;
    s32 ns;
} T_004F0A78;

typedef struct {
    F_004F0A78 f[10];
} FA_004F0A78;

extern FA_004F0A78 D_L39_00478C68;
extern u8 D_001B3331[];

extern void *func_L39_004DBA08(void);
extern BN_004F0A78 *func_L39_004FC380(void);
extern s32 func_L39_004F1230(u8 *, u32, F_004F0A78 *, s32);
extern s32 func_L39_004FC6F8(BN_004F0A78 *, unsigned long);
extern unsigned long func_L39_004FD228(BN_004F0A78 *, unsigned long);
extern BN_004F0A78 *func_L39_004FC580(BN_004F0A78 *);
extern s32 func_L39_004FD500(BN_004F0A78 *, unsigned long);
extern s32 func_L39_004FD678(BN_004F0A78 *, unsigned long);
extern unsigned long func_L39_004FD2D0(BN_004F0A78 *, unsigned long);
extern s32 func_L39_004FB9A0(BN_004F0A78 *, BN_004F0A78 *, BN_004F0A78 *);
extern s32 func_L39_004FBDA0(BN_004F0A78 *, BN_004F0A78 *, BN_004F0A78 *);
extern s32 func_L39_004FD3B0(BN_004F0A78 *, unsigned long);
extern void func_L39_004FC370(BN_004F0A78 *);
extern BN_004F0A78 *func_L39_004FC5C0(BN_004F0A78 *, BN_004F0A78 *);
extern s32 func_L39_004FCA98(BN_004F0A78 *, s32);
extern s32 func_L39_004FC158(BN_004F0A78 *);
extern s32 func_L39_004FC8C0(BN_004F0A78 *, u8 *);
extern void func_L39_004FC228(BN_004F0A78 *);
extern s32 func_L39_004F1498(T_004F0A78 *, T_004F0A78 *, long);

s32 func_L39_004F0A78(T_004F0A78 *out, s32 type, u8 *data, u32 len) {
    s32 ret;
    s32 frac;
    s32 tzh;
    s32 tzm;
    s32 tzs;
    C_004F0A78 *ctx;
    u32 *t;

    frac = 0;
    ctx = func_L39_004DBA08();
    ret = 0;
    tzh = 0;
    tzm = 0;
    tzs = 0;

    if (data == 0 || out == 0) {
        ret = 0x2721;
        goto end;
    }
    t = &out->hi;
    if (type == 1 || type == 2 || type == 6) {
        s32 notleap = 0;
        FA_004F0A78 fa = D_L39_00478C68;
        BN_004F0A78 *bn;
        BN_004F0A78 *bn2;
        BN_004F0A78 tmp;
        u8 buf[8];
        s32 n;
        s32 year, month, day, hour, min, sec;
        s32 c;
        s32 leap;

        bn = func_L39_004FC380();
        if (bn == 0) {
            ret = 0x2715;
            goto end;
        }
        if (type == 2) {
            fa.f[0].width = 4;
            fa.f[6].width = 1;
        } else if (type == 6) {
            fa.f[0].width = 4;
            fa.f[1].sep = fa.f[2].sep = fa.f[3].sep = fa.f[4].sep = fa.f[5].sep = ':';
        }
        n = func_L39_004F1230(data, len, fa.f, 10);
        year = fa.f[0].val;
        month = fa.f[1].val;
        day = fa.f[2].val;
        hour = fa.f[3].val;
        min = fa.f[4].val;
        sec = fa.f[5].val;
        c = fa.f[6].sep;
        if (type == 1) {
            if (n < 5) {
                ret = 0x2726;
                goto end;
            }
            if (year < 50) {
                year += 100;
            }
            year += 1900;
            if (n == 5) {
                sec = 0;
                c = fa.f[5].sep;
            } else if (n == 7) {
                tzs = fa.f[5].sep;
                tzh = sec;
                tzm = fa.f[6].val;
            } else if (n == 8) {
                tzh = fa.f[6].val;
                tzs = c;
                tzm = fa.f[7].val;
            }
            func_L39_004FC6F8(bn, year);
        } else if (type == 6) {
            if (n != 6) {
                ret = 0x2724;
                goto end;
            }
            c = 'Z';
            func_L39_004FC6F8(bn, year);
        } else {
            if (n < 7) {
                ret = 0x2724;
                goto end;
            }
            frac = fa.f[6].val;
            c = fa.f[7].sep;
            if (n == 9) {
                tzh = fa.f[7].val;
                tzs = c;
                tzm = fa.f[8].val;
            }
            func_L39_004FC6F8(bn, year);
        }
        leap = 0;
        if (func_L39_004FD228(bn, 400) == 0 || (func_L39_004FD228(bn, 4) == 0 && func_L39_004FD228(bn, 100) != 0)) {
            leap = 1;
        } else {
            notleap = bn->neg == 0;
        }
        if (month > 12) {
            ret = 0x2726;
            goto end;
        }
        if (ctx->days[leap][month] < ctx->days[leap][month - 1] + day) {
            ret = 0x2726;
            goto end;
        }
        if (hour > 23 || min > 59 || sec > 60 || tzh > 12 || tzm > 59) {
            ret = 0x2726;
            goto end;
        }
        if (tzs != '+' && tzs != '-') {
            s32 u = (D_001B3331[c] & 2) ? c - 0x20 : c;
            if (u != 'Z') {
                ret = 0x2726;
                goto end;
            }
        }
        if (sec == 60) {
            sec = 59;
        }
        bn2 = func_L39_004FC580(bn);
        if (bn2 == 0) {
            ret = 0x2715;
            goto end;
        }
        func_L39_004FD500(bn, 1970);
        if (bn->neg == 0) {
            func_L39_004FD500(bn2, 1);
        }
        func_L39_004FD678(bn, 365);
        func_L39_004FD2D0(bn2, 4);
        func_L39_004FB9A0(bn, bn, bn2);
        func_L39_004FD2D0(bn2, 25);
        func_L39_004FBDA0(bn, bn, bn2);
        func_L39_004FD2D0(bn2, 4);
        func_L39_004FB9A0(bn, bn, bn2);
        func_L39_004FD500(bn, 477);
        if (notleap && bn->neg != 0) {
            func_L39_004FD3B0(bn, 1);
        }
        func_L39_004FD3B0(bn, ctx->days[leap][month - 1]);
        func_L39_004FD3B0(bn, day - 1);
        func_L39_004FD678(bn, 24);
        func_L39_004FD3B0(bn, hour);
        func_L39_004FD678(bn, 60);
        func_L39_004FD3B0(bn, min);
        func_L39_004FD678(bn, 60);
        func_L39_004FD3B0(bn, sec);
        func_L39_004FC370(&tmp);
        func_L39_004FC5C0(&tmp, bn);
        func_L39_004FCA98(&tmp, 0x40);
        buf[0] = buf[1] = buf[2] = buf[3] = 0;
        buf[4] = buf[5] = buf[6] = buf[7] = 0;
        func_L39_004FC8C0(&tmp, &buf[8 - (func_L39_004FC158(&tmp) + 7) / 8]);
        func_L39_004FC228(&tmp);
        t[1] = (unsigned long)buf[7] | ((unsigned long)buf[6] << 8) | ((unsigned long)buf[5] << 16) | ((unsigned long)buf[4] << 24);
        t[0] = (unsigned long)buf[3] | ((unsigned long)buf[2] << 8) | ((unsigned long)buf[1] << 16) | ((unsigned long)buf[0] << 24);
        if (bn->neg != 0) {
            t[0] = ~t[0];
            t[1] = ~t[1] + 1;
            if (t[1] == 0) {
                t[0]++;
            }
        }
        t[2] = frac * 100000000;
        func_L39_004FC228(bn);
        func_L39_004FC228(bn2);
        {
            s32 off = (tzh * 60 + tzm) * 60;
            if (tzs == '+') {
                off = -off;
            }
            func_L39_004F1498(out, out, off * 1000);
        }
    } else if (type == 3) {
        u8 *p;
        u8 *q;
        u32 i;

        if (len > 8) {
            ret = 0x2726;
            goto end;
        }
        t[2] = 0;
        t[1] = 0;
        t[0] = 0;
        p = data + len - 1;
        q = (u8 *)&t[1];
        *q++ = *p--;
        i = 0;
        if (p >= data) {
            do {
                if (++i >= 4) {
                    break;
                }
                *q++ = *p--;
            } while (p >= data);
        }
        if (p >= data) {
            q = (u8 *)&t[0];
            *q++ = *p--;
            i = 0;
            if (p >= data) {
                do {
                    if (++i >= 4) {
                        break;
                    }
                    *q++ = *p--;
                } while (p >= data);
            }
        }
    } else {
        ret = 0x2724;
        goto end;
    }
end:
    return ret;
}
/* localdecomp:end func_L39_004F0A78 */

INCLUDE_ASM("asm/levels", func_L39_004F1230);

INCLUDE_ASM("asm/levels", func_L39_004F1358);

/* localdecomp:start func_L39_004F1498 */
typedef struct {
    s32 hi;
    u32 lo;
    u32 ns;
} V_004F1498;

extern void *func_L39_004DBA08(void);
extern long func_00130090(long, long);
extern long func_0012E840(long, long);

s32 func_L39_004F1498(T_004F0A78 *dst, T_004F0A78 *src, long ms) {
    s32 r = 0;
    s32 carry = 0;
    void *ctx = func_L39_004DBA08();
    V_004F1498 *s;
    V_004F1498 *d;
    s32 ns, sec;
    u32 n;
    u32 os;
    s32 adj;

    if (dst == 0) {
        r = 0x2721;
    } else {
        s = (src == 0) ? (V_004F1498 *)((u8 *)ctx + 0x230) : (V_004F1498 *)&src->hi;
        d = (V_004F1498 *)&dst->hi;
        ns = func_00130090(ms, 1000) * 1000000;
        sec = func_0012E840(ms, 1000);
        if (s->hi < 0) {
            ns = -ns;
        }
        if (ns < 0 && s->ns < (u32)-ns) {
            sec--;
            adj = ns + 1000000000;
            d->ns = s->ns + adj;
        } else {
            n = s->ns + ns;
            d->ns = n;
            if (n > 999999999) {
                sec++;
                d->ns = n - 1000000000;
            }
        }
        os = s->lo;
        d->lo = os + sec;
        if (sec > 0 && d->lo < os) {
            carry = 1;
        } else if (sec < 0) {
            carry = (os < d->lo) ? -1 : 0;
        }
        d->hi = s->hi + carry;
    }
    return r;
}
/* localdecomp:end func_L39_004F1498 */

/* localdecomp:start func_L39_004F1608 */
extern s32 func_L39_004ECA10(void);

s32 func_L39_004F1608(T_004F0A78 *t) {
    s32 r = 0;
    long now;

    if (t == 0) {
        r = 0x2721;
    } else {
        now = func_L39_004ECA10();
        if (now == -1) {
            r = 0x2723;
        } else {
            t->lo = now;
            t->ns = 0;
            t->hi = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_004F1608 */
