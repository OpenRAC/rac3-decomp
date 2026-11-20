#include "common.h"

/* declared by functions of L39_00543818.c, which this file was cut from */
extern s32 D_L39_002412DC;

/* localdecomp:start func_L39_00543AA8 */
#include "vu0.h"

typedef struct {
    u8 pad00[0x24];
    u8 *p24;
    u8 pad28[0x70];
    s32 f98;
    u8 pad9C[0xE];
    s16 fAA;
    u8 padAC[0x54];
} E_00543AA8;

typedef struct {
    u8 pad00[0x18];
    u8 *m18;
    u8 pad1C[0x14];
    vu0_v4 v30;
    vu0_v4 v40;
} S_00543AA8;

extern u8 *D_L39_0024AEC0[2] __attribute__((section(".sdata")));
extern f32 D_L39_0024AEDC __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AEDC, 4");
extern u8 *D_L39_00241640;
extern u8 *D_L39_002637C0[];
extern E_00543AA8 *D_L39_0024BF5C;
__asm__(".extern D_L39_0024BF5C, 16");
extern u8 *D_L39_0024C000;
extern u8 *D_L39_0024BC4C;
extern S_00543AA8 D_L39_0025F740;

extern void func_L18_00353110(void *);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern u8 *func_L39_0061D7B0(void *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_00456500(void *, s32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_004464C8(void *, void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_L01_00446E38(void *, void *, s32, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern s32 func_L01_003FDCA0(void *, s32, f32);

s32 func_L39_00543AA8(void *arg) {
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    u8 *list[12];
    vu0_v4 v90;
    s32 ret;
    s32 flag;
    s32 tries;
    s32 all;
    s32 n;
    u8 *a;
    u8 *s;
    u8 *opp;
    E_00543AA8 *tbl;
    s32 *slots;
    s32 cnt;
    s32 i;
    f32 f;
    f32 f2;

    a = arg;
    ret = 0;
    opp = 0;
    s = *(u8 **)(a + 0x68);
    func_L18_00353110(a);
    flag = 0;
    qzero(&v20);
    tries = 0;
    all = 1;
    if (D_L39_00241640 != 0) {
        if (((s8 *)D_L39_00241640)[0x18F] == 0) {
            all = 0;
        }
    }
    {
        u8 *q = *(u8 **)(s + 0x384);
        if (q != 0) {
            u8 *r = *(u8 **)(q + 0x2D8);
            if (r != 0 && r[0x1A14] != 0) {
                if (D_L39_0024AEC0[0] == a && D_L39_0024AEC0[1] != 0) {
                    opp = D_L39_0024AEC0[1];
                } else if (D_L39_0024AEC0[1] == a && D_L39_0024AEC0[0] != 0) {
                    opp = D_L39_0024AEC0[0];
                }
            }
        }
    }

    n = 0;
    cnt = func_003D4D00(a + 0x10, 0, a, 0, 4.5f);
    slots = (s32 *)(s + 0x308);
    for (i = 0; i < cnt; i++) {
        u8 *m = func_L39_0061D7B0(D_L39_002637C0[i]);
        if (m != 0) {
            u32 k = (*(u32 *)m & 0x0F000000) >> 24;
            if (k == 0 || k == 2) {
                *(s32 *)(D_L39_002637C0[i] + 0x98) = 0;
                list[n++] = D_L39_002637C0[i];
            }
        }
    }
    {
        E_00543AA8 *t = D_L39_0024BF5C;
        s32 *p = slots;
        for (i = 0; i < 18; i++, p++) {
            if (*p != -1) {
                E_00543AA8 *e = &t[*p];
                if (all != 0 || e->fAA != 0x10C6) {
                    e->f98 = *(s32 *)(e->p24 + 0x10);
                }
            }
        }
    }
    if (*(s32 *)(s + 0x3BC) != 0) {
        if (*(s32 *)(s + 0x3EC) != -1 && func_00382380(a + 0x10, *(s32 *)(s + 0x3EC), 0) == 0) {
            vec_sub_ba(&v20, D_L39_0024C000 + *(s32 *)(s + 0x3EC) * 128 + 0x30, a + 0x10);
            v20.z = 0.0f;
            func_0038CF68(&v20, &v20, 0.0003f);
            vec_add_ab(s + 0x3F0, s + 0x3F0, &v20);
        } else if (*(s32 *)(s + 0x43C) != -1 && func_L01_00456500(a + 0x10, *(s32 *)(s + 0x43C)) == 0) {
            u8 *grp = D_L39_0024BC4C + (*(s32 *)(s + 0x43C) * 0x30 + 0x20);
            s32 j;
            s32 best = -1;
            s32 second = -1;
            f32 bestd = 999999.0f;
            f32 secondd = 999999.0f;
            for (j = 0; j < *(s16 *)(grp + 0x12); j++) {
                f32 d = func_L01_0040E570(D_L39_0024C000 + (*(s32 **)(grp + 0x20))[j] * 128 + 0x30, a + 0x10);
                if (d < bestd) {
                    second = best;
                    secondd = bestd;
                    bestd = d;
                    best = j;
                } else if (d < secondd) {
                    secondd = d;
                    second = j;
                }
            }
            func_L01_004464C8(&v90, D_L39_0024C000 + best * 128 + 0x30, D_L39_0024C000 + second * 128 + 0x30, a + 0x10);
            vec_sub_ba(&v20, &v90, a + 0x10);
            v20.z = 0.0f;
            func_0038CF68(&v20, &v20, 0.0003f);
            vec_add_ab(s + 0x3F0, s + 0x3F0, &v20);
        } else {
            *(f32 *)(s + 0x3F0) -= *(f32 *)(s + 0x3F0) * 0.09f;
            if (fabs_asm(*(f32 *)(s + 0x3F0)) < 0.01f) {
                *(f32 *)(s + 0x3F0) = 0.0f;
            }
            *(f32 *)(s + 0x3F4) -= *(f32 *)(s + 0x3F4) * 0.09f;
            if (fabs_asm(*(f32 *)(s + 0x3F4)) < 0.01f) {
                *(f32 *)(s + 0x3F4) = 0.0f;
            }
            *(f32 *)(s + 0x3F8) -= *(f32 *)(s + 0x3F8) * 0.09f;
            if (fabs_asm(*(f32 *)(s + 0x3F8)) < 0.01f) {
                *(f32 *)(s + 0x3F8) = 0.0f;
            }
        }
        vec_add_ab(s + 0x290, s + 0x290, s + 0x3F0);
        if (*(f32 *)(a + 0x18) > *(f32 *)(s + 0x300)) {
            *(f32 *)(a + 0x18) = *(f32 *)(s + 0x300);
            if (0.0f < *(f32 *)(s + 0x298)) {
                *(f32 *)(s + 0x298) = 0.0f;
            }
        } else if (*(f32 *)(a + 0x18) < *(f32 *)(s + 0x304)) {
            *(f32 *)(s + 0x298) += 0.014f;
        }
        if (*(s32 *)(s + 0x3BC) != 0) {
            *(vu0_q *)&v20 = *(vu0_q *)(s + 0x290);
        }
        if (*(s32 *)(s + 0x3BC) != 0) {
            *(f32 *)(a + 0x18) += 0.5f;
        }
    }
    vec_add_ba(&v0, a + 0x10, &v20);
    if (opp != 0 && opp[0xBC] != 7 && opp[0xBC] != 9 && opp[0xBC] != 10) {
        vec_sub_ab(&v20, &v0, opp + 0x10);
        if (func_0038CEA8(&v20) < 5.0f) {
            func_0038CF68(&v20, &v20, 5.0f);
            vec_add_ba(&v0, &v20, opp + 0x10);
        }
    }
    vec_sub_ab(&v40, &v0, a + 0x10);
again:
    f = func_L01_00446E38(a + 0x10, &v0, 0x84, a, 2.5f);
    if (0.0f <= f && f < 1.0f) {
hit:
        func_0038CF68(&v30, &D_L39_0025F740.v40, 1.0f);
        func_0038CE20(&v90, &v30, 0.008f);
        vec_add_ab(a + 0x10, a + 0x10, &v90);
        if (f == 0.0f) {
            if (tries == 0 || (tries < 3 && 0.0f < func_0038CE68(&v50, &v30))) {
                v50 = v30;
                flag = 0;
                tries++;
                goto again;
            }
        }
        f2 = func_0038CE68(&v40, &v30);
        ret = 1;
        func_0038CE20(&v20, &v30, f2 * -1.01f);
        vec_add_ba(s + 0x290, s + 0x290, &v20);
        func_0038CE20(&v10, &v40, f);
        vec_add_ab(a + 0x10, a + 0x10, &v10);
        if (D_L39_002412DC == 0x2B || D_L39_002412DC == 0x35) {
            if (D_L39_0025F740.m18 != 0 && *(s16 *)(D_L39_0025F740.m18 + 0xAA) == 0x1B23) {
                *(f32 *)(s + 0x298) += D_L39_0024AEDC * 0.00040000002f;
                if (*(f32 *)(a + 0x18) < *(f32 *)(D_L39_0025F740.m18 + 0x18)) {
                    *(f32 *)(a + 0x18) = *(f32 *)(D_L39_0025F740.m18 + 0x18) + 0.15f;
                }
            }
        }
        {
            u8 *q = *(u8 **)(s + 0x384);
            if (q != 0) {
                u8 *m = D_L39_0025F740.m18;
                if (m != 0 && *(s32 *)(q + 0x2D8) == 0 && *(s32 *)(q + 0x2DC) == 0
                    && (*(s16 *)(m + 0xAA) == 0x10C6 || *(s16 *)(m + 0xAA) == 0x1A47)) {
                    func_0038CE90(&v90, &D_L39_0025F740.v40, a + 0xC0);
                    if (0.0f < v90.z) {
                        func_0038CE20(&v90, &v90, -0.0392f);
                    } else {
                        func_0038CE20(&v90, &v90, 0.0392f);
                    }
                    vec_add_ab(s + 0x290, s + 0x290, &v90);
                    *(f32 *)(s + 0x298) -= 0.011760001f;
                }
            }
        }
        if (*(f32 *)(s + 0x298) < 0.0f) {
            u8 *m = D_L39_0025F740.m18;
            if (m == 0 || *(s16 *)(m + 0xAA) == 0x10C6 || *(s16 *)(m + 0xAA) == 0x1A47) {
                *(f32 *)(s + 0x298) = 0.0f;
            }
        }
        if (flag == 0) {
            func_0038CE20(&v40, s + 0x290, 1.0f - f);
            vec_add_ba(&v90, a + 0x10, &v40);
            f = func_L01_00446E38(a + 0x10, &v90, 0x84, a, 2.5f);
            if (f < 1.0f) {
                if (0.0f <= f) {
                    flag = 1;
                    goto hit;
                }
            } else {
                vec_add_ab(a + 0x10, a + 0x10, &v40);
            }
        }
    } else {
        vec_add_ab(a + 0x10, a + 0x10, &v40);
    }
    {
        s32 k;
        for (k = 0; k < 4; k++) {
            s32 moved = 0;
            if (func_L01_003FB640(a + 0x10, 4, a, 2.5f) != 0) {
                *(vu0_q *)(a + 0x10) = *(vu0_q *)&D_L39_0025F740.v30;
                moved = 1;
            }
            if (func_L01_003FDCA0(a + 0x10, 0, 2.5f) != 0) {
                *(vu0_q *)(a + 0x10) = *(vu0_q *)&D_L39_0025F740.v30;
                moved = 1;
            }
            if (moved == 0) {
                break;
            }
        }
    }
    if (*(s32 *)(s + 0x3BC) != 0) {
        *(f32 *)(a + 0x18) -= 0.5f;
    }
    if (*(f32 *)(a + 0x10) < 10.0f) *(f32 *)(a + 0x10) = 10.0f;
    if (1013.0f < *(f32 *)(a + 0x10)) *(f32 *)(a + 0x10) = 1013.0f;
    if (*(f32 *)(a + 0x14) < 10.0f) *(f32 *)(a + 0x14) = 10.0f;
    if (1013.0f < *(f32 *)(a + 0x14)) *(f32 *)(a + 0x14) = 1013.0f;
    if (*(f32 *)(a + 0x18) < 10.0f) *(f32 *)(a + 0x18) = 10.0f;
    if (1013.0f < *(f32 *)(a + 0x18)) *(f32 *)(a + 0x18) = 1013.0f;
    tbl = D_L39_0024BF5C;
    for (i = 0; i < 18; i++) {
        s32 idx = slots[i];
        if (idx != -1) {
            E_00543AA8 *e = &tbl[idx];
            if (all != 0 || e->fAA != 0x10C6) {
                e->f98 = 0;
            }
        }
    }
    if (n > 0) {
        u8 **p = list;
        for (i = n; i != 0; i--) {
            u8 *m = *p++;
            *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
        }
    }
    *(f32 *)(s + 0x368) = *(f32 *)(a + 0x18);
    *(vu0_q *)(s + 0x420) = *(vu0_q *)(a + 0x10);
    return ret;
}
/* localdecomp:end func_L39_00543AA8 */
