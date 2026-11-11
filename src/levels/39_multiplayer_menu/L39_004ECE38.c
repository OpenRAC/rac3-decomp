#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_004ECE38);

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

INCLUDE_ASM("asm/levels", func_L39_004F01D8);

INCLUDE_ASM("asm/levels", func_L39_004F02A0);

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

INCLUDE_ASM("asm/levels", func_L39_004F1498);

INCLUDE_ASM("asm/levels", func_L39_004F1608);
