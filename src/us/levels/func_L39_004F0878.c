#include "common.h"

/* NTSC-U counterpart of func_L39_004F0A78 (src/levels/39_multiplayer_menu/L39_004ECE38.c) */
extern void *func_L39_004DB808(void);

/* localdecomp:start func_L39_004F0878 */
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

extern FA_004F0A78 D_L39_00478D68;
extern u8 D_001B34B1[];

extern void *func_L39_004DB808(void);
extern BN_004F0A78 *func_L39_004FC180(void);
extern s32 func_L39_004F1030(u8 *, u32, F_004F0A78 *, s32);
extern s32 func_L39_004FC4F8(BN_004F0A78 *, unsigned long);
extern unsigned long func_L39_004FD028(BN_004F0A78 *, unsigned long);
extern BN_004F0A78 *func_L39_004FC380_004F0878(BN_004F0A78 *);
extern s32 func_L39_004FD300(BN_004F0A78 *, unsigned long);
extern s32 func_L39_004FD478(BN_004F0A78 *, unsigned long);
extern unsigned long func_L39_004FD0D0(BN_004F0A78 *, unsigned long);
extern s32 func_L39_004FB7A0(BN_004F0A78 *, BN_004F0A78 *, BN_004F0A78 *);
extern s32 func_L39_004FBBA0(BN_004F0A78 *, BN_004F0A78 *, BN_004F0A78 *);
extern s32 func_L39_004FD1B0(BN_004F0A78 *, unsigned long);
extern void func_L39_004FC170(BN_004F0A78 *);
extern BN_004F0A78 *func_L39_004FC3C0(BN_004F0A78 *, BN_004F0A78 *);
extern s32 func_L39_004FC898(BN_004F0A78 *, s32);
extern s32 func_L39_004FBF58(BN_004F0A78 *);
extern s32 func_L39_004FC6C0(BN_004F0A78 *, u8 *);
extern void func_L39_004FC028(BN_004F0A78 *);
extern s32 func_L39_004F1298(T_004F0A78 *, T_004F0A78 *, long);

s32 func_L39_004F0878(T_004F0A78 *out, s32 type, u8 *data, u32 len) {
    s32 ret;
    s32 frac;
    s32 tzh;
    s32 tzm;
    s32 tzs;
    C_004F0A78 *ctx;
    u32 *t;

    frac = 0;
    ctx = func_L39_004DB808();
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
        FA_004F0A78 fa = D_L39_00478D68;
        BN_004F0A78 *bn;
        BN_004F0A78 *bn2;
        BN_004F0A78 tmp;
        u8 buf[8];
        s32 n;
        s32 year, month, day, hour, min, sec;
        s32 c;
        s32 leap;

        bn = func_L39_004FC180();
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
        n = func_L39_004F1030(data, len, fa.f, 10);
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
            func_L39_004FC4F8(bn, year);
        } else if (type == 6) {
            if (n != 6) {
                ret = 0x2724;
                goto end;
            }
            c = 'Z';
            func_L39_004FC4F8(bn, year);
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
            func_L39_004FC4F8(bn, year);
        }
        leap = 0;
        if (func_L39_004FD028(bn, 400) == 0 || (func_L39_004FD028(bn, 4) == 0 && func_L39_004FD028(bn, 100) != 0)) {
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
            s32 u = (D_001B34B1[c] & 2) ? c - 0x20 : c;
            if (u != 'Z') {
                ret = 0x2726;
                goto end;
            }
        }
        if (sec == 60) {
            sec = 59;
        }
        bn2 = func_L39_004FC380_004F0878(bn);
        if (bn2 == 0) {
            ret = 0x2715;
            goto end;
        }
        func_L39_004FD300(bn, 1970);
        if (bn->neg == 0) {
            func_L39_004FD300(bn2, 1);
        }
        func_L39_004FD478(bn, 365);
        func_L39_004FD0D0(bn2, 4);
        func_L39_004FB7A0(bn, bn, bn2);
        func_L39_004FD0D0(bn2, 25);
        func_L39_004FBBA0(bn, bn, bn2);
        func_L39_004FD0D0(bn2, 4);
        func_L39_004FB7A0(bn, bn, bn2);
        func_L39_004FD300(bn, 477);
        if (notleap && bn->neg != 0) {
            func_L39_004FD1B0(bn, 1);
        }
        func_L39_004FD1B0(bn, ctx->days[leap][month - 1]);
        func_L39_004FD1B0(bn, day - 1);
        func_L39_004FD478(bn, 24);
        func_L39_004FD1B0(bn, hour);
        func_L39_004FD478(bn, 60);
        func_L39_004FD1B0(bn, min);
        func_L39_004FD478(bn, 60);
        func_L39_004FD1B0(bn, sec);
        func_L39_004FC170(&tmp);
        func_L39_004FC3C0(&tmp, bn);
        func_L39_004FC898(&tmp, 0x40);
        buf[0] = buf[1] = buf[2] = buf[3] = 0;
        buf[4] = buf[5] = buf[6] = buf[7] = 0;
        func_L39_004FC6C0(&tmp, &buf[8 - (func_L39_004FBF58(&tmp) + 7) / 8]);
        func_L39_004FC028(&tmp);
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
        func_L39_004FC028(bn);
        func_L39_004FC028(bn2);
        {
            s32 off = (tzh * 60 + tzm) * 60;
            if (tzs == '+') {
                off = -off;
            }
            func_L39_004F1298(out, out, off * 1000);
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
/* localdecomp:end func_L39_004F0878 */
