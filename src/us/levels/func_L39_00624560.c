#include "common.h"

/* NTSC-U counterpart of func_L39_00626D38 (src/levels/shared/L39_00626D38.c) */
extern u8 D_L39_004998A0[];
extern u8 D_L39_004998A0[];
extern void func_L39_0062FAE0(void *, void *, void *, f32);

/* localdecomp:start func_L39_00624560 */
#include "vu0.h"
typedef union Buf_00626D38 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
    f32 f[2];
} Buf_00626D38;

typedef struct V4_00626D38 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00626D38;

typedef struct Sub_00626D38 {
    u8 pad0[0x39];
    u8 b39;
} Sub_00626D38;

typedef struct Moby_00626D38 {
    u8 pad0[0x10];
    V4_00626D38 pos;
    u8 pad20[0x14];
    u16 h34;
    u8 pad36[0x32];
    Sub_00626D38 *p68;
    u8 pad6C[0x28];
    s8 b94;
    u8 pad95[0x13];
    u8 bA8;
    u8 padA9;
    s16 hAA;
} Moby_00626D38;

typedef struct Rec_00626D38 {
    u8 pad0[0x10];
    V4_00626D38 pos;
    Moby_00626D38 *f20;
    s32 f24;
    u8 b28;
    u8 pad29[7];
    s32 f30;
    u8 pad34[4];
    Moby_00626D38 *f38;
    u8 pad3C[4];
} Rec_00626D38;

typedef struct Dmg_00626D38 {
    u8 pad0[0xE];
    u8 bE;
} Dmg_00626D38;

typedef struct Hit_00626D38 {
    u8 pad0[0x2C];
    f32 f2C;
} Hit_00626D38;

typedef struct Vt_00626D38 {
    u8 pad0[0x34];
    s32 (*f34)(void *, s32, s32, s32, s32);
    void (*f38)(void *, void *, s32, s32, s32);
} Vt_00626D38;

extern u8 D_L39_004998A0[];
extern u8 D_L39_004998A1[];
extern u32 D_L39_0024BAC8;
extern s32 D_001D5A18_sda_00624560;
extern s32 D_001DA8E0_sda_00624560;
extern Rec_00626D38 D_L39_00263AC0[];
extern void func_L39_00624540(u8 *);
extern Hit_00626D38 *func_L01_00444358(void *, s32, s32);
extern s32 func_L39_0065FDA0(void *, s32, s32);
extern void *func_L39_0065FCD0(void *, s32, s32, s32);
extern void func_L39_006601C8(void *, void *, s32);
extern s32 func_L39_006241C0(void *, void *, s32);
extern u8 *func_L39_0061AA60(s32);
extern void func_L39_00638D98(void *, s32);
extern void func_L39_006378A8(void *);
extern void func_L39_0062F938(void *, void *, s32, f32, f32, f32);
extern s32 func_L01_003EFFE0(s32, s32);
extern void func_L39_006377E8(void *, s32, s32);
extern void func_L39_00624138(void *, void *, s32, f32, f32);
extern void func_L39_0062FAE0(void *, void *, void *, f32);
extern void func_003BF4F8(s32, void *);
struct Ret_00628428;
extern struct Ret_00628428 *func_0037E0B8(void *);

static __inline__ u32 DecU_00626D38(u8 *q) {
    Buf_00626D38 buf;
    u32 a;
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
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    buf.w[0] = a;
    buf.w[1] ^= a;
    return buf.w[1];
}

static __inline__ f32 DecF_00626D38(u8 *q) {
    Buf_00626D38 buf;
    u32 a;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0.0f;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    buf.w[0] = a;
    buf.w[1] ^= a;
    return buf.f[1];
}

static __inline__ s16 Dec16_00626D38(u8 *q) {
    Buf_00626D38 buf;
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
    for (i = 0; i < 24; i += 3) {
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

static __inline__ void Prep_00626D38(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_004998A0[0];
    } else {
        t = *q;
        *q = D_L39_004998A1[0];
        D_L39_004998A1[0] = t;
    }
}

static __inline__ void Set16_00626D38(u8 *q, s16 v) {
    u8 *hk = q;
    Buf_00626D38 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_00626D38(q);
    buf.h[2] = v;
    key = ((u32 *)D_L39_004998A0)[((u32)hk * D_L39_0024BAC8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    buf.w[0] = (u32)q ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_004998A0[m + ((k + i) & 7) * 255] = *d++;
    }
}

static __inline__ void PutByte_00626D38(void *x, u8 b) {
    func_L39_006601C8(x, &b, 1);
}

static __inline__ s32 GtF_00626D38(u8 *q, f32 v) {
    return DecF_00626D38(q) > v;
}

static __inline__ s32 Gt16_00626D38(u8 *q, s16 v) {
    return Dec16_00626D38(q) > v;
}

static __inline__ s32 EqF_00626D38(u8 *q, f32 v) {
    return DecF_00626D38(q) == v;
}

static __inline__ s32 IsLocal_00626D38(u8 *g) {
    return g[0x1A14] != 0;
}

s32 func_L39_00624560(u8 *g, s32 a1) {
    Rec_00626D38 *rec;
    Moby_00626D38 *m;
    s32 bit;
    s32 wait;
    Dmg_00626D38 *r;
    s32 flag;
    s32 open;
    Moby_00626D38 *o;
    s32 team;

    if ((DecU_00626D38(g + 0x19E6) ^ 0x14) == 0) {
        return 0;
    }
    if ((DecU_00626D38(g + 0x19E4) ^ 0x7A) == 0) {
        return 0;
    }
    if ((DecU_00626D38(g + 0x19E4) ^ 0x31) == 0) {
        return 0;
    }
    if (D_001D5A18_sda_00624560 != 0) {
        return 0;
    }
    if (Dec16_00626D38(g + 0x311) == 0 && (u8)GtF_00626D38(g + 0x2476, 0.0f) &&
        (DecU_00626D38(g + 0x19E4) ^ 6) != 0 && (DecU_00626D38(g + 0x19E4) ^ 0x16) != 0 &&
        (DecU_00626D38(g + 0x19E4) ^ 0x8F) != 0 && (DecU_00626D38(g + 0x19E4) ^ 0x8E) != 0) {
        func_L39_00624540(g);
    }

    rec = 0;
    m = 0;
    if ((*(Moby_00626D38 **)(g + 0x2524))->bA8 != 0xFF) {
        rec = &D_L39_00263AC0[(*(Moby_00626D38 **)(g + 0x2524))->bA8];
        m = rec->f20;
    }
    if (rec != 0) {
        bit = rec->f24 >> 3;
        bit &= 1;
    } else {
        bit = 0;
    }
    wait = 0;
    if (bit == 0) {
        if (m == 0 || (m->hAA != 0x1099 && (m->hAA != 0x18AB || *(s32 *)(g + 0x24D0) != 10))) {
            if ((DecU_00626D38(g + 0x19E6) ^ 7) == 0 || Dec16_00626D38(g + 0x311) != 0) {
                Hit_00626D38 *h = func_L01_00444358(*(void **)(g + 0x2524), 1, 1);
                if (h != 0 && *(s32 *)(g + 0x24D4) < (s32)h->f2C) {
                    wait = *(s32 *)(g + 0x24D4);
                }
                if (wait == 0) {
                    return 0;
                }
            }
        }
    }
    if (bit == 0 && m != 0 && m->hAA == 0x18AB && *(s32 *)(g + 0x24D0) == 10 &&
        Gt16_00626D38(g + 0x311, 0x28)) {
        return 0;
    }

    r = (Dmg_00626D38 *)func_0037E0B8(*(void **)(g + 0x2524));
    if (r != 0 && (r->bE == 2 || r->bE == 4)) {
        if (IsLocal_00626D38(g) &&
            (*(s32 *)(g + 0x254C) == 0 ||
             (*(s32 *)(g + 0x254C) == 5 && *(u8 **)(g + 0x2528) != 0 &&
              *(s16 *)(*(u8 **)(g + 0x2528) + 0x2FC) == 2))) {
            if (r->bE == 2) {
                if (func_L39_0065FDA0(g, 5, 0) == 0) {
                    void *x = func_L39_0065FCD0(g, 5, 0, 0);
                    if (*(u8 **)(g + 0x2460) != 0) {
                        PutByte_00626D38(x, (*(u8 **)(g + 0x2460))[0x2544]);
                    } else {
                        PutByte_00626D38(x, 0xFF);
                    }
                    if (g[0x2464] != 0) {
                        PutByte_00626D38(x, 0x2D);
                    } else {
                        PutByte_00626D38(x, 0xF);
                    }
                    *(s32 *)(g + 0x2460) = 0;
                }
            } else {
                if (func_L39_0065FDA0(g, 7, 0) == 0) {
                    void *x = func_L39_0065FCD0(g, 7, 0, 0);
                    if (*(u8 **)(g + 0x2460) != 0) {
                        PutByte_00626D38(x, (*(u8 **)(g + 0x2460))[0x2544]);
                    } else {
                        PutByte_00626D38(x, 0xFF);
                    }
                    if (g[0x2464] != 0) {
                        PutByte_00626D38(x, 0x2D);
                    } else {
                        PutByte_00626D38(x, 0xF);
                    }
                    *(s32 *)(g + 0x2460) = 0;
                }
            }
        }
        r->bE = 1;
        return 0;
    }

    if ((*(Moby_00626D38 **)(g + 0x2524))->bA8 == 0xFF) {
        return 0;
    }
    if (rec->f38 != *(Moby_00626D38 **)(g + 0x2524)) {
        return 0;
    }
    if ((rec->f24 & 9) == 0) {
        return 0;
    }
    if (D_001DA8E0_sda_00624560 != 0 && func_L39_006241C0(g, m, bit) == 0 && bit == 0) {
        return 0;
    }
    o = rec->f20;
    flag = 1;
    *(Moby_00626D38 **)(g + 0x245C) = o;
    if (IsLocal_00626D38(g)) {
        flag = 0;
    } else if (*(s32 *)(g + 0x24D0) == 3 && (rec->f24 & 0x1000000) == 0) {
        s32 isx = o != 0 && o->hAA == 0x1097 && o->p68 != 0 && o->p68->b39 != 0;
        if (!IsLocal_00626D38(g) && isx) {
            flag = 0;
        }
    }
    *(s8 *)(g + 0x2502) = -1;
    team = -1;
    if (*(s32 *)(g + 0x24D0) == 4) {
        Moby_00626D38 *t = *(Moby_00626D38 **)(g + 0x245C);
        if (t != 0 && t->hAA == 0x108C) {
            u8 *p;
            team = t->b94;
            p = func_L39_0061AA60(*(s32 *)(g + 0x24CC));
            if (p != 0 && (p[3] & 0xF) == 0 && p[0x1A14] != 0) {
                *(s8 *)(g + 0x2502) = team;
            }
        }
    }
    if (bit == 0) {
        if (flag != 0) {
            return 0;
        }
        if (wait != 0) {
            func_L39_00638D98(g, wait);
            return 0;
        }
    }
    open = *(s32 *)(g + 0x24D0) == 3 && (rec->f24 & 0x1000000) == 0;
    if (a1 == 0) {
        return 1;
    }
    {
        s32 zero;
        s32 big;
        s32 stop;
        V4_00626D38 v;

        func_L39_006378A8(g);
        zero = 0;
        big = 0;
        stop = 0;
        if (rec->f30 & 1) {
            v = rec->pos;
            if (rec->pos.w == 5627.9248f) {
                big = 1;
            }
        } else if (rec->f20 != 0) {
            vec_sub_ba(&v, g + 0xA0, &rec->f20->pos);
        } else {
            func_L39_0062F938(g, &v, 0, -1.0f, 0.0f, 0.0f);
        }
        if ((DecU_00626D38(g + 0x19E4) ^ 0x37) == 0) {
            (*(Moby_00626D38 **)(g + 0x2524))->h34 &= 0x7FFF;
        }
        if ((DecU_00626D38(g + 0x19E4) ^ 0x8F) == 0 && !(rec->f24 & 8)) {
            Hit_00626D38 *h = func_L01_00444358(*(void **)(g + 0x2524), 1, 0);
            if (h != 0) {
                func_L39_00638D98(g, (s32)h->f2C);
                func_L01_003EFFE0(0x12, *(s32 *)(g + 0x2534));
            }
            if ((u8)EqF_00626D38(g + 0x2476, 0.0f)) {
                (*(Vt_00626D38 **)(g + 0x14))->f34(g, 0x16, 1, 0, 1);
            }
            Set16_00626D38(g + 0x311, 0x2F);
            if (*(s16 *)(g + 0x342) == 0) {
                *(s16 *)(g + 0x342) = 18;
            }
            func_L39_006377E8(g, 0x14, 0);
            return 0;
        }
        if (rec->f24 & 8) {
            (*(Vt_00626D38 **)(g + 0x14))->f34(g, 0x8E, 1, 0, 1);
            *(s16 *)(g + 0x320) = 0xC8;
        } else {
            Hit_00626D38 *h = func_L01_00444358(*(void **)(g + 0x2524), 1, 1);
            if (!((*(s32 *)(g + 0x24D0) == 2 && (h == 0 || (s32)h->f2C < 2)) ||
                  (!IsLocal_00626D38(g) && open != 0 && (DecU_00626D38(g + 0x19E4) ^ 0x7D) == 0))) {
                (*(Vt_00626D38 **)(g + 0x14))->f34(g, 0x16, 1, 0, 1);
            } else {
                func_L39_00638D98(g, (s32)h->f2C);
                zero = 1;
                func_L01_003EFFE0(0x12, *(s32 *)(g + 0x2534));
                (*(Moby_00626D38 **)(g + 0x2524))->bA8 = 0xFF;
            }
        }
        if ((DecU_00626D38(g + 0x19E4) ^ 0x8E) == 0) {
            qzero(&v);
            stop = 1;
        } else {
            func_L39_00624138(g, &v, big, g[0x377] != 0 ? 0.0f : 0.055000003427267075f, 0.028333336114883423f);
            if (big != 0 && rec->b28 == 4) {
                func_L39_0062FAE0(g, &v, &v, 2.0f);
            }
        }
        if (zero != 0) {
            qzero(&v);
        }
        {
            vu0_q qv;
            vu0_q qa;
            vu0_q qb;

            __asm__("lqc2 %0, %1" : "=j"(qv) : "m"(v));
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(g + 0x120)));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qv));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(g + 0x120)) : "j"(qa));
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(g + 0x140)));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qb) : "j"(qb), "j"(qv));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(g + 0x140)) : "j"(qb));
        }
        if (g[0x1A14] != 0 && open == 0) {
            (*(Vt_00626D38 **)(g + 0x14))->f38(g, &v, stop, team, zero);
        }
        if (!IsLocal_00626D38(g) && open != 0) {
            func_003BF4F8(*(s32 *)(g + 0x2524), g + 0x2504);
        }
    }
    return 1;
}
/* localdecomp:end func_L39_00624560 */
