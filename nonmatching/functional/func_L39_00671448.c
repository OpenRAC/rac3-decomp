/* functional: medium. Compiles at level 39 (no draft; written from the PAL asm). Differences: retail's empty M-iteration spin loop after the random pick is omitted (no effect); vsub/vadd.xyz as float math with w kept; per-function aliases D_L39_*_00671448 for globals typed differently by other files. Candidate-list semantics (a3 flag, wrap-around random pick, weighted top-M sort) transcribed block by block but not named beyond 'spawn slot picker'. */
#include "common.h"
#include "vu0.h"

typedef union Dec_00671448 {
    u8 b[8];
    u32 w[2];
} Dec_00671448;

extern u8 D_L39_00352940_00671448[];
extern u8 *D_L39_00241640_00671448;
extern u8 *D_L39_0024C000;
extern u8 *D_L39_0024BF5C;
extern u8 *D_L39_0024CE20_00671448[];
extern s16 D_L39_00293F38[];
extern vu0_v4 D_L39_0025F770;
extern vu0_v4 D_L39_0025F760;
extern f32 D_L39_0024642C __attribute__((section(".sdata")));
extern u8 D_L39_004997E0[];
extern s32 func_L39_005B4398(s32);
extern void *func_0011D534(void *, s32, s32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_L01_0040E4C0(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

/* keyed byte-table decode of the protected word at q (0 when unset) */
static u32 dec_00671448(u8 *q) {
    Dec_00671448 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    return b;
}

/* d.xyz += s.xyz (w kept), as vadd.xyz */
static void vadd_00671448(vu0_v4 *d, vu0_v4 *s) {
    d->x = d->x + s->x;
    d->y = d->y + s->y;
    d->z = d->z + s->z;
}

/* d.xyz -= s.xyz (w kept), as vsub.xyz */
static void vsub_00671448(vu0_v4 *d, vu0_v4 *s) {
    d->x = d->x - s->x;
    d->y = d->y - s->y;
    d->z = d->z - s->z;
}

/* Picks a spawn slot id for player p from the level's candidate list and writes its position to out
   and its facing quad to out2. */
void func_L39_00671448(u8 *p, vu0_v4 *out, vu0_v4 *out2, s32 flag) {
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    f32 wC[64];
    f32 wA[64];
    s32 wB[64];
    u8 *G;
    s32 mode;
    s32 *list;
    s32 res;
    f32 best;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 q;
    s32 e;
    s32 base;
    f32 sc;
    u8 *pl;

    G = D_L39_00241640_00671448;
    res = -1;
    best = 0.0f;
    mode = *(s32 *)(G + 0x180);
    if (mode == 2) {
        list = *(s32 **)(D_L39_00352940_00671448 + 0x214);
    } else {
        list = *(s32 **)(D_L39_00352940_00671448 + 0x20C);
    }

    if (*(s32 *)(G + 0x180) == 2) {
        if (flag != 0) {
            s32 n = 0;
            s32 per;
            s32 want;
            s32 c = 0;

            for (i = 0; i < 64; i++) {
                if (list[i] != -1) {
                    n++;
                }
            }
            per = n / *(s32 *)(G + 0x178);
            want = *(s32 *)(p + 0x2544);
            if (per >= 2) {
                want = want * per + func_L39_005B4398(per);
            }
            for (i = 0; i < 64; i++) {
                if (list[i] == -1) {
                    continue;
                }
                if (c == want) {
                    res = list[i];
                    break;
                }
                c++;
            }
        } else if (*(s32 *)(*(u8 **)(D_L39_00352940_00671448 + 0x214) + 0x104) != 0) {
            s32 r = func_L39_005B4398(0x40);
            s32 s = 0;
            s32 done = 0;

            if (r <= 0 && list[0] != -1) {
                res = list[0];
                done = 1;
            }
            s = 1;
            while (!done) {
                if (s >= 64) {
                    s = 0;
                }
                if (r > 0) {
                    if (list[s] != -1) {
                        r--;
                    }
                    if (r > 0) {
                        s++;
                        continue;
                    }
                }
                if (list[s] == -1) {
                    s++;
                    continue;
                }
                res = list[s];
                done = 1;
            }
        } else {
            u8 *X = *(u8 **)(D_L39_00352940_00671448 + 0x214);
            s32 M;

            func_0011D534(wC, 0, 0x100);
            for (j = 0; j < 8; j++) {
                pl = D_L39_0024CE20_00671448[j];
                if (pl == 0) {
                    continue;
                }
                for (k = 0; k < 64; k++) {
                    e = list[k];
                    if (e == -1) {
                        continue;
                    }
                    v10 = *(vu0_v4 *)(D_L39_0024C000 + (e << 7) + 0x30);
                    sc = func_0038CF00(pl + 0xA0, &v10);
                    if (40.0f <= sc) {
                        sc = (sc - 40.0f) * (sc - 40.0f) * 6.1035156e-05f;
                    } else {
                        sc = (sc - 40.0f) * (sc - 40.0f) * 0.00390625f;
                    }
                    wC[k] = wC[k] + (1.0f - sc) * 1000.0f;
                }
            }
            for (j = 0; j < 8; j++) {
                s16 *tb;

                if (j == *(s32 *)(p + 0x2544)) {
                    continue;
                }
                tb = (s16 *)((u8 *)D_L39_00293F38 + (j << 7));
                if (tb[0] <= 0) {
                    continue;
                }
                for (m = 1; m <= tb[0]; m++) {
                    pl = D_L39_0024BF5C + (tb[m] << 8);
                    if (pl == 0) {
                        continue;
                    }
                    for (k = 0; k < 64; k++) {
                        e = list[k];
                        if (e == -1) {
                            continue;
                        }
                        v10 = *(vu0_v4 *)(D_L39_0024C000 + (e << 7) + 0x30);
                        if (func_0038CF00(pl + 0x10, &v10) < 4.0f) {
                            wC[k] = wC[k] + -1000.0f;
                        }
                    }
                }
            }
            for (i = 0; i < 64; i++) {
                wA[i] = -1000000.0f;
                wB[i] = -1;
            }
            M = *(s32 *)(X + 0x108);
            for (k = 0; k < 64; k++) {
                for (m = 0; m < *(s32 *)(*(u8 **)(D_L39_00352940_00671448 + 0x214) + 0x108); m++) {
                    if (list[k] == -1) {
                        continue;
                    }
                    if (wA[m] < wC[k]) {
                        M = *(s32 *)(*(u8 **)(D_L39_00352940_00671448 + 0x214) + 0x108);
                        for (q = M - 1; q >= m + 1; q--) {
                            wA[q] = wA[q - 1];
                            wB[q] = wB[q - 1];
                        }
                        wA[m] = wC[k];
                        wB[m] = list[k];
                        break;
                    }
                }
            }
            /* retail runs an empty M-iteration loop here */
            res = wB[func_L39_005B4398(*(s32 *)(*(u8 **)(D_L39_00352940_00671448 + 0x214) + 0x108))];
        }
    } else {
        u8 *Q = *(u8 **)(p + 0x2558);

        if (Q != 0) {
            s32 a = *(s32 *)(Q + 0xC60);

            if (a != -1) {
                if (*(s32 *)((u8 *)list + 0x88 + a * 4) == *(s32 *)(p + 0x2548)) {
                    res = list[a];
                }
            } else {
                s32 b = *(s32 *)(Q + 0xC64);

                if (b != -1) {
                    if (*(s32 *)((u8 *)list + 0xA8 + b * 4) == *(s32 *)(p + 0x2548)) {
                        res = *(s32 *)((u8 *)list + 0x20 + b * 4);
                    }
                }
            }
        }
    }

    if (res == -1) {
        for (i = 0; i < 8; i++) {
            f32 far = 0.0f;

            e = list[i];
            if (e == -1) {
                continue;
            }
            if (*(s32 *)((u8 *)list + 0xC8 + i * 4) != *(s32 *)(p + 0x2548)) {
                continue;
            }
            v10 = *(vu0_v4 *)(D_L39_0024C000 + (e << 7) + 0x30);
            for (j = 0; j < 8; j++) {
                pl = D_L39_0024CE20_00671448[j];
                if (pl == 0) {
                    break;
                }
                if (pl == p) {
                    continue;
                }
                v0 = *(vu0_v4 *)(pl + 0xA0);
                vsub_00671448(&v0, &v10);
                sc = func_L01_0040E4C0(&v0);
                if (far < sc) {
                    far = sc;
                }
            }
            if (best < far || res == -1) {
                best = far;
                res = list[i];
            }
        }
        if (res == -1) {
            res = list[0];
            if (res == -1) {
                return;
            }
        }
    }

    base = res << 7;
    *out = *(vu0_v4 *)(D_L39_0024C000 + base + 0x30);
    if (*(s32 *)(D_L39_00241640_00671448 + 0x180) != 2) {
        i = 0;
        sc = (f32)*(s32 *)(p + 0x2544) * *(f32 *)(p + 0x1F4);
        func_0038CE20(&v0, D_L39_0024C000 + base + 0x10, sc + sc);
        vadd_00671448(out, &v0);
        func_0038CE20(&v0, D_L39_0024C000 + base + 0x20, *(f32 *)(p + 0x1F4) * 1.05f);
        vadd_00671448(out, &v0);
        while (func_L01_003FB640(out, 0x24, *(u8 **)(p + 0x2524), *(f32 *)(p + 0x1F4)) != 0 && i < 4) {
            i++;
            out->x = D_L39_0025F770.x;
            out->y = D_L39_0025F770.y;
            out->z = D_L39_0025F770.z;
        }
    } else {
        i = 0;
        for (j = 0; j < 8; j++) {
            pl = D_L39_0024CE20_00671448[j];
            if (pl == 0) {
                continue;
            }
            if ((dec_00671448(pl + 0x19E6) ^ 0x14) == 0) {
                i++;
                continue;
            }
            if ((dec_00671448(pl + 0x19E4) ^ 0x7A) == 0) {
                i++;
            }
        }
        if (i >= 2) {
            sc = (f32)*(s32 *)(p + 0x2544) * 6.2831855f * 0.125f;
            func_00382760(&v0, *(f32 *)(p + 0x1F4), sc, 0.0f);
            vadd_00671448(out, &v0);
        }
        func_0038CE20(&v0, D_L39_0024C000 + base + 0x20, *(f32 *)(p + 0x1F4) * 1.05f);
        vadd_00671448(out, &v0);
        if (func_L01_003FB640(out, 0x25, *(u8 **)(p + 0x2524), *(f32 *)(p + 0x1F4)) != 0) {
            func_0038CF68(&v20, D_L39_0024C000 + base, *(f32 *)(p + 0x1F4) * 4.8f);
            vsub_00671448(out, &v20);
            func_0038CF68(&v20, D_L39_0024C000 + base, *(f32 *)(p + 0x1F4) * 2.2f);
            while (func_L01_003FB640(out, 0x25, *(u8 **)(p + 0x2524), *(f32 *)(p + 0x1F4)) != 0 && i < 4) {
                vadd_00671448(out, &v20);
                i++;
            }
        }
    }

    vsub_00671448(out, &v0);
    v30 = *out;
    v20 = *out;
    func_0038CE20(&v0, D_L39_0024C000 + base + 0x20, 2.0f);
    vadd_00671448(&v20, &v0);
    func_0038CE20(&v0, D_L39_0024C000 + base + 0x20, -30.0f);
    vadd_00671448(&v30, &v0);
    if (func_003D3CB0(&v20, &v30, 0x32, *(u8 **)(p + 0x2524), 0) != 0) {
        *out = D_L39_0025F760;
        func_0038CF68(&v0, (u8 *)&D_L39_0025F760 + 0x20, D_L39_0024642C);
        vadd_00671448(out, &v0);
    }
    *out2 = *(vu0_v4 *)(D_L39_0024C000 + base + 0x70);
}
