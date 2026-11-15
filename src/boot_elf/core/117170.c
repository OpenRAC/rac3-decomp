#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 116F80.c's earlier functions */
extern void func_0011B240(s32);
extern void func_0013AFE8(s32) __attribute__((noreturn));

typedef struct Reent_116F98 {
    u8 pad0[0xC];
    void *err;
} Reent_116F98;
extern void *D_0013D770[];
extern char D_00150080[];
extern s32 func_00118950(void *, char *, ...);
extern void func_00116F80(void);

/* declarations of 116FD0.c's earlier functions */
typedef struct At_116FD0 {
    struct At_116FD0 *next;
    s32 ind;
    void (*fns[32])(void);
} At_116FD0;
typedef struct {
    u8 pad148[0x148];
    At_116FD0 *atexit;
    At_116FD0 atexit0;
} Reent_116FD0;
extern void *D_0013D770[];
extern void *func_001194E8(u32);

extern long func_0011BFD8(s32, s32, s32);

extern s32 func_0011A160();

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00117170);

/* localdecomp:start func_001171C8 */
typedef struct Bigint_1171C8 {
    struct Bigint_1171C8 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Bigint_1171C8;
extern s32 func_0011ABB8(Bigint_1171C8 *, Bigint_1171C8 *);

s32 func_001171C8(Bigint_1171C8 *b, Bigint_1171C8 *S)
{
    s32 n;
    s32 borrow, y;
    u32 carry, q, ys;
    u32 *bx, *bxe, *sx, *sxe;
    s32 z;
    u32 si, zs;

    n = S->wds;
    if (b->wds < n) {
        return 0;
    }
    sx = S->x;
    sxe = sx + --n;
    bx = b->x;
    bxe = bx + n;
    q = *bxe / (*sxe + 1);
    if (q) {
        borrow = 0;
        carry = 0;
        do {
            si = *sx++;
            ys = (si & 0xFFFF) * q + carry;
            zs = (si >> 16) * q + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xFFFF) - (ys & 0xFFFF) + borrow;
            borrow = y >> 16;
            z = (*bx >> 16) - (zs & 0xFFFF) + borrow;
            borrow = z >> 16;
            ((u16 *)bx)[1] = (u16)z;
            ((u16 *)bx)[0] = (u16)y;
            bx++;
        } while (sx <= sxe);
        if (!*bxe) {
            bx = b->x;
            while (--bxe > bx && !*bxe) {
                --n;
            }
            b->wds = n;
        }
    }
    if (func_0011ABB8(b, S) >= 0) {
        q++;
        borrow = 0;
        carry = 0;
        bx = b->x;
        sx = S->x;
        do {
            si = *sx++;
            ys = (si & 0xFFFF) + carry;
            zs = (si >> 16) + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xFFFF) - (ys & 0xFFFF) + borrow;
            borrow = y >> 16;
            z = (*bx >> 16) - (zs & 0xFFFF) + borrow;
            borrow = z >> 16;
            ((u16 *)bx)[1] = (u16)z;
            ((u16 *)bx)[0] = (u16)y;
            bx++;
        } while (sx <= sxe);
        bx = b->x;
        bxe = bx + n;
        if (!*bxe) {
            while (--bxe > bx && !*bxe) {
                --n;
            }
            b->wds = n;
        }
    }
    return q;
}
/* localdecomp:end func_001171C8 */

/* localdecomp:start func_001173F8 */
typedef union {
    double d;
    u32 L[2];
} Dbl_1173F8;
typedef struct Reent_1173F8 {
    u8 pad0[0x40];
    Bigint_1171C8 *result;
    s32 result_k;
} Reent_1173F8;
extern double D_00150278[];
extern double D_00150340[];

char *func_001173F8(Reent_1173F8 *ptr, double _d, s32 mode, s32 ndigits, s32 *decpt, s32 *sign, char **rve)
{
    extern void *func_0011A3F8();
    extern void func_0011A4A0();
    extern void *func_0011A4D0();
    extern struct Big_11ADB0 *func_0011ADB0();
    extern struct Big_11A718 *func_0011A718();
    extern void *func_0011A960();
    extern struct Bigint_0011A750 *func_0011A750();
    extern struct Bigint_0011AA60 *func_0011AA60();
    extern struct Bigint_0011AC20 *func_0011AC20();
    extern s32 func_0011A5D8();
    extern void *func_0011A0B0();
    s32 bbits, b2, b5, be, dig, i, ieps, ilim, ilim0, ilim1, j, j1, k, k0,
        k_check, leftright, m2, m5, s2, s5, spec_case, try_quick;
    Dbl_1173F8 d, d2, eps;
    s32 L;
    s32 denorm;
    u32 x;
    Bigint_1171C8 *b, *b1, *delta, *mlo, *mhi, *S;
    double ds;
    char *s, *s0;

    d.d = _d;

    if (ptr->result) {
        ptr->result->k = ptr->result_k;
        ptr->result->maxwds = 1 << ptr->result_k;
        func_0011A4A0(ptr, ptr->result);
        ptr->result = 0;
    }

    if (d.L[1] & 0x80000000) {
        *sign = 1;
        d.L[1] &= ~0x80000000;
    } else {
        *sign = 0;
    }

    if ((d.L[1] & 0x7ff00000) == 0x7ff00000) {
        *decpt = 9999;
        s = !d.L[0] && !(d.L[1] & 0xfffff) ? "Infinity" : "NaN";
        if (rve) {
            *rve = s[3] ? s + 8 : s + 3;
        }
        return s;
    }
    if (!d.d) {
        *decpt = 1;
        s = "0";
        if (rve) {
            *rve = s + 1;
        }
        return s;
    }

    b = (Bigint_1171C8 *)func_0011ADB0(ptr, d.d, &be, &bbits);
    if ((i = (s32)(d.L[1] >> 20 & (0x7ff00000 >> 20))) != 0) {
        d2.d = d.d;
        d2.L[1] &= 0xfffff;
        d2.L[1] |= 0x3ff00000;
        i -= 1023;
        denorm = 0;
    } else {
        i = bbits + be + (1023 + (53 - 1) - 1);
        x = i > 32 ? d.L[1] << (64 - i) | d.L[0] >> (i - 32) : d.L[0] << (32 - i);
        d2.d = x;
        d2.L[1] -= 31 * 0x100000;
        i -= (1023 + (53 - 1) - 1) + 1;
        denorm = 1;
    }
    ds = (d2.d - 1.5) * 0.289529654602168 + 0.1760912590558 + i * 0.301029995663981;
    k = (s32)ds;
    if (ds < 0. && ds != k) {
        k--;
    }
    k_check = 1;
    if (k >= 0 && k <= 22) {
        if (d.d < D_00150278[k]) {
            k--;
        }
        k_check = 0;
    }
    j = bbits - i - 1;
    if (j >= 0) {
        b2 = 0;
        s2 = j;
    } else {
        b2 = -j;
        s2 = 0;
    }
    if (k >= 0) {
        b5 = 0;
        s5 = k;
        s2 += k;
    } else {
        b2 -= k;
        b5 = -k;
        s5 = 0;
    }
    if (mode < 0 || mode > 9) {
        mode = 0;
    }
    try_quick = 1;
    if (mode > 5) {
        mode -= 4;
        try_quick = 0;
    }
    leftright = 1;
    ilim = ilim1 = -1;
    switch (mode) {
    case 0:
    case 1:
        i = 18;
        ndigits = 0;
        break;
    case 2:
        leftright = 0;
        /* fallthrough */
    case 4:
        if (ndigits <= 0) {
            ndigits = 1;
        }
        ilim = ilim1 = i = ndigits;
        break;
    case 3:
        leftright = 0;
        /* fallthrough */
    case 5:
        i = ndigits + k + 1;
        ilim = i;
        ilim1 = i - 1;
        if (i <= 0) {
            i = 1;
        }
    }
    j = sizeof(u32);
    for (ptr->result_k = 0; sizeof(Bigint_1171C8) - sizeof(u32) + j <= i; j <<= 1) {
        ptr->result_k++;
    }
    ptr->result = (Bigint_1171C8 *)func_0011A3F8(ptr, ptr->result_k);
    s = s0 = (char *)ptr->result;

    if (ilim >= 0 && ilim <= 14 && try_quick) {
        i = 0;
        d2.d = d.d;
        k0 = k;
        ilim0 = ilim;
        ieps = 2;
        if (k > 0) {
            ds = D_00150278[k & 0xf];
            j = k >> 4;
            if (j & 0x10) {
                j &= 0x10 - 1;
                d.d /= D_00150340[5 - 1];
                ieps++;
            }
            for (; j; j >>= 1, i++) {
                if (j & 1) {
                    ieps++;
                    ds *= D_00150340[i];
                }
            }
            d.d /= ds;
        } else if ((j1 = -k) != 0) {
            d.d *= D_00150278[j1 & 0xf];
            for (j = j1 >> 4; j; j >>= 1, i++) {
                if (j & 1) {
                    ieps++;
                    d.d *= D_00150340[i];
                }
            }
        }
        if (k_check && d.d < 1. && ilim > 0) {
            if (ilim1 <= 0) {
                goto fast_failed;
            }
            ilim = ilim1;
            k--;
            d.d *= 10.;
            ieps++;
        }
        eps.d = ieps * d.d + 7.;
        eps.L[1] -= (53 - 1) * 0x100000;
        if (ilim == 0) {
            S = mhi = 0;
            d.d -= 5.;
            if (d.d > eps.d) {
                goto one_digit;
            }
            if (d.d < -eps.d) {
                goto no_digits;
            }
            goto fast_failed;
        }
        if (leftright) {
            eps.d = 0.5 / D_00150278[ilim - 1] - eps.d;
            for (i = 0;;) {
                L = d.d;
                d.d -= L;
                *s++ = '0' + (s32)L;
                if (d.d < eps.d) {
                    goto ret1;
                }
                if (1. - d.d < eps.d) {
                    goto bump_up;
                }
                if (++i >= ilim) {
                    break;
                }
                eps.d *= 10.;
                d.d *= 10.;
            }
        } else {
            eps.d *= D_00150278[ilim - 1];
            for (i = 1;; i++, d.d *= 10.) {
                L = d.d;
                d.d -= L;
                *s++ = '0' + (s32)L;
                if (i == ilim) {
                    if (d.d > 0.5 + eps.d) {
                        goto bump_up;
                    } else if (d.d < 0.5 - eps.d) {
                        while (*--s == '0') {
                        }
                        s++;
                        goto ret1;
                    }
                    break;
                }
            }
        }
    fast_failed:
        s = s0;
        d.d = d2.d;
        k = k0;
        ilim = ilim0;
    }

    if (be >= 0 && k <= 14) {
        ds = D_00150278[k];
        if (ndigits < 0 && ilim <= 0) {
            S = mhi = 0;
            if (ilim < 0 || d.d <= 5 * ds) {
                goto no_digits;
            }
            goto one_digit;
        }
        for (i = 1;; i++) {
            L = d.d / ds;
            d.d -= L * ds;
            *s++ = '0' + (s32)L;
            if (i == ilim) {
                d.d += d.d;
                if (d.d > ds || (d.d == ds && L & 1)) {
                bump_up:
                    while (*--s == '9') {
                        if (s == s0) {
                            k++;
                            *s = '0';
                            break;
                        }
                    }
                    ++*s++;
                }
                break;
            }
            if (!(d.d *= 10.)) {
                break;
            }
        }
        goto ret1;
    }

    m2 = b2;
    m5 = b5;
    mhi = mlo = 0;
    if (leftright) {
        if (mode < 2) {
            i = denorm ? be + (1023 + (53 - 1) - 1 + 1) : 1 + 53 - bbits;
        } else {
            j = ilim - 1;
            if (m5 >= j) {
                m5 -= j;
            } else {
                s5 += j -= m5;
                b5 += j;
                m5 = 0;
            }
            if ((i = ilim) < 0) {
                m2 -= i;
                i = 0;
            }
        }
        b2 += i;
        s2 += i;
        mhi = (Bigint_1171C8 *)func_0011A718(ptr, 1);
    }
    if (m2 > 0 && s2 > 0) {
        i = m2 < s2 ? m2 : s2;
        b2 -= i;
        m2 -= i;
        s2 -= i;
    }
    if (b5 > 0) {
        if (leftright) {
            if (m5 > 0) {
                mhi = (Bigint_1171C8 *)func_0011A960(ptr, mhi, m5);
                b1 = (Bigint_1171C8 *)func_0011A750(ptr, mhi, b);
                func_0011A4A0(ptr, b);
                b = b1;
            }
            if ((j = b5 - m5) != 0) {
                b = (Bigint_1171C8 *)func_0011A960(ptr, b, j);
            }
        } else {
            b = (Bigint_1171C8 *)func_0011A960(ptr, b, b5);
        }
    }
    S = (Bigint_1171C8 *)func_0011A718(ptr, 1);
    if (s5 > 0) {
        S = (Bigint_1171C8 *)func_0011A960(ptr, S, s5);
    }

    spec_case = 0;
    if (mode < 2) {
        if (!d.L[0] && !(d.L[1] & 0xfffff) && d.L[1] & 0x7ff00000) {
            b2 += 1;
            s2 += 1;
            spec_case = 1;
        }
    }

    if ((i = ((s5 ? 32 - func_0011A5D8(S->x[S->wds - 1]) : 1) + s2) & 0x1f) != 0) {
        i = 32 - i;
    }
    if (i > 4) {
        i -= 4;
        b2 += i;
        m2 += i;
        s2 += i;
    } else if (i < 4) {
        i += 28;
        b2 += i;
        m2 += i;
        s2 += i;
    }
    if (b2 > 0) {
        b = (Bigint_1171C8 *)func_0011AA60(ptr, b, b2);
    }
    if (s2 > 0) {
        S = (Bigint_1171C8 *)func_0011AA60(ptr, S, s2);
    }
    if (k_check) {
        if (func_0011ABB8(b, S) < 0) {
            k--;
            b = (Bigint_1171C8 *)func_0011A4D0(ptr, b, 10, 0);
            if (leftright) {
                mhi = (Bigint_1171C8 *)func_0011A4D0(ptr, mhi, 10, 0);
            }
            ilim = ilim1;
        }
    }
    if (ilim <= 0 && mode > 2) {
        if (ilim < 0 || func_0011ABB8(b, S = (Bigint_1171C8 *)func_0011A4D0(ptr, S, 5, 0)) <= 0) {
        no_digits:
            k = -1 - ndigits;
            goto ret;
        }
    one_digit:
        *s++ = '1';
        k++;
        goto ret;
    }
    if (leftright) {
        if (m2 > 0) {
            mhi = (Bigint_1171C8 *)func_0011AA60(ptr, mhi, m2);
        }

        mlo = mhi;
        if (spec_case) {
            mhi = (Bigint_1171C8 *)func_0011A3F8(ptr, mhi->k);
            func_0011A0B0((char *)&mhi->sign, (char *)&mlo->sign, mlo->wds * sizeof(s32) + 2 * sizeof(int));
            mhi = (Bigint_1171C8 *)func_0011AA60(ptr, mhi, 1);
        }

        for (i = 1;; i++) {
            dig = func_001171C8(b, S) + '0';
            j = func_0011ABB8(b, mlo);
            delta = (Bigint_1171C8 *)func_0011AC20(ptr, S, mhi);
            j1 = delta->sign ? 1 : func_0011ABB8(b, delta);
            func_0011A4A0(ptr, delta);
            if (j1 == 0 && !mode && !(d.L[0] & 1)) {
                if (dig == '9') {
                    goto round_9_up;
                }
                if (j > 0) {
                    dig++;
                }
                *s++ = dig;
                goto ret;
            }
            if (j < 0 || (j == 0 && !mode && !(d.L[0] & 1))) {
                if (j1 > 0) {
                    b = (Bigint_1171C8 *)func_0011AA60(ptr, b, 1);
                    j1 = func_0011ABB8(b, S);
                    if ((j1 > 0 || (j1 == 0 && dig & 1)) && dig++ == '9') {
                        goto round_9_up;
                    }
                }
                *s++ = dig;
                goto ret;
            }
            if (j1 > 0) {
                if (dig == '9') {
                round_9_up:
                    *s++ = '9';
                    goto roundoff;
                }
                *s++ = dig + 1;
                goto ret;
            }
            *s++ = dig;
            if (i == ilim) {
                break;
            }
            b = (Bigint_1171C8 *)func_0011A4D0(ptr, b, 10, 0);
            if (mlo == mhi) {
                mlo = mhi = (Bigint_1171C8 *)func_0011A4D0(ptr, mhi, 10, 0);
            } else {
                mlo = (Bigint_1171C8 *)func_0011A4D0(ptr, mlo, 10, 0);
                mhi = (Bigint_1171C8 *)func_0011A4D0(ptr, mhi, 10, 0);
            }
        }
    } else {
        for (i = 1;; i++) {
            *s++ = dig = func_001171C8(b, S) + '0';
            if (i >= ilim) {
                break;
            }
            b = (Bigint_1171C8 *)func_0011A4D0(ptr, b, 10, 0);
        }
    }

    b = (Bigint_1171C8 *)func_0011AA60(ptr, b, 1);
    j = func_0011ABB8(b, S);
    if (j > 0 || (j == 0 && dig & 1)) {
    roundoff:
        while (*--s == '9') {
            if (s == s0) {
                k++;
                *s++ = '1';
                goto ret;
            }
        }
        ++*s++;
    } else {
        while (*--s == '0') {
        }
        s++;
    }
ret:
    func_0011A4A0(ptr, S);
    if (mhi) {
        if (mlo && mlo != mhi) {
            func_0011A4A0(ptr, mlo);
        }
        func_0011A4A0(ptr, mhi);
    }
ret1:
    func_0011A4A0(ptr, b);
    *s = 0;
    *decpt = k + 1;
    if (rve) {
        *rve = s;
    }
    return s0;
}
/* localdecomp:end func_001173F8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011865C);
