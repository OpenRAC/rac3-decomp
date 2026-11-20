#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t v0, v1, v2;
    u128_t matrix[3];
} Local_51FC18;

typedef struct __attribute__((packed)) { s32 values[2]; } Pair;

/* declared by functions of L39_0051F740.c, which this file was cut from */
extern void func_0038CF68(void *, void *, f32);

/* localdecomp:start func_L39_00522328 */
#include "vu0.h"

typedef union Buf_00522328 {
    u8 b[8];
    u32 w[2];
} Buf_00522328;

typedef struct Ent_00522328 {
    u8 pad0[0x21];
    s8 b21;
    u8 pad22[0x30 - 0x22];
    f32 f30;
    u8 pad34[0x80 - 0x34];
} Ent_00522328;

typedef struct Hit_00522328 {
    vu0_v4 pos;
    u8 pad10[0x18 - 0x10];
    u8 b18;
    u8 b19;
    s16 h1A;
    u8 pad1C[4];
    s32 w20;
} Hit_00522328;

typedef struct E40_00522328 {
    u8 pad0[0x30];
    s32 w30;
    s32 w34;
    s32 w38;
    s32 w3C;
} E40_00522328;

typedef struct Slot_00522328 {
    u8 pad0[0xD0];
    u8 bD0;
    u8 padD1[0xDC - 0xD1];
    u8 *pDC;
} Slot_00522328;

extern u8 D_L39_0039B240[];
extern u8 D_L39_00387240[];
extern u8 D_L39_00396C40[];
extern u8 D_001FE020[];
extern u8 *D_L39_0024CE20[8] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024CE20, 32");
extern Ent_00522328 D_L39_0049C890[];
extern u8 *D_L39_002637C0[];
extern u8 D_L39_004997E0[];
extern s32 D_L39_0024112C;
extern f32 D_L39_0024A9C0;
extern f32 D_L39_0024A9C4;
extern f32 D_L39_0024A9C8;
extern f32 D_L39_0024A9CC;
extern f32 D_L39_0024A9D0;
extern f32 D_L39_0024A9D4;
extern f32 D_L39_0024A9D8;
__asm__(".extern D_L39_0024A9C0, 4");
__asm__(".extern D_L39_0024A9C4, 4");
__asm__(".extern D_L39_0024A9C8, 4");
__asm__(".extern D_L39_0024A9CC, 4");
__asm__(".extern D_L39_0024A9D0, 4");
__asm__(".extern D_L39_0024A9D4, 4");
__asm__(".extern D_L39_0024A9D8, 4");

extern s32 func_0038CAD0(void *);
extern void func_L01_004C8668(s32);
extern void func_L39_0061C4D0(u8 *, u8 **);
extern s32 func_L39_00639D90(void *);
extern s32 func_L39_005FFD20(f32, f32 *, s32 *, s32);
extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L39_005F3088(s32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
extern s32 func_L39_006732D0(void *, s32, s32, s32);
extern s32 func_L39_00673498(void *, s32);
extern s32 func_L39_00620CF8(u8 *, s32);
extern void func_L01_004482A0(f32 *, f32 *, f32, f32, f32, f32);
extern void func_L39_00621D60(void *, s32);
extern s32 func_L39_005F2FA0(s32, s32);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L39_005FFDF8(s32);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern void func_L39_005FFE78(void);
extern s32 func_L39_00648AE0(u8 *, s32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446978(void *, void *);
extern void func_L39_00622288(void *);
extern void func_0038D000(void *, void *, void *);
extern void func_L39_00674320(u8 *);
extern void func_L01_00457588(void *, void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern f32 func_0038D0B0(f32);
extern void func_0038D890(void *, void *, void *, f32);
extern s32 func_L39_005BE900(void *, s32, f32);
extern void func_L39_00522FA8(void *, s32);
extern void func_L39_00522EE8(char *object);
extern void func_L39_00524610(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L39_00523948(char *obj);
extern void func_L39_005236F0(void *obj, u128_t *p1, u128_t *p2, s32 arg);

static __inline__ u32 Dec_00522328(u8 *q, Buf_00522328 *buf) {
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
    d = buf->b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf->w[0] ^ (u32)q;
    b = buf->w[1] ^ a;
    buf->w[0] = a;
    buf->w[1] = b;
    return b;
}

static __inline__ s32 DecEq_00522328(u8 *q, Buf_00522328 *buf, u32 v) {
    return Dec_00522328(q, buf) == v;
}

static __inline__ Ent_00522328 *Weap_00522328(s32 i) {
    return &D_L39_0049C890[i];
}

void func_L39_00522328(u8 *obj)
{
    vu0_v4 v0;
    union {
        vu0_v4 v;
        Buf_00522328 buf;
    } tmp;
    f32 dist;
    u8 *st;
    u8 *g;
    s32 i = 0;
    s32 state;
    s32 h;
    s32 lvl;

    st = *(u8 **)(obj + 0x68);
    g = *(u8 **)(st + 0x2C);
    func_0038CAD0(st + 0x28);
    if (g != 0 && *(s32 *)(g + 0x474) == 3) {
        for (; i < 0x23; i++) {
            u8 *e = *(u8 **)(st + 0x5C) + (i << 6);
            if (*(s32 *)(e + 0x38) >= 0) {
                func_L01_004C8668(*(s32 *)(e + 0x38));
                *(s32 *)(e + 0x38) = -1;
            }
        }
    }
    if (obj[0x20] == 0) {
        func_L39_0061C4D0(obj, (u8 **)(st + 0x2C));
        g = *(u8 **)(st + 0x2C);
        *(u8 **)(st + 0x60) = D_L39_0039B240 + *(s32 *)(g + 0x2544) * 0x33E0;
        *(u8 **)(st + 0x58) = D_L39_00387240 + *(s32 *)(g + 0x2544) * 0x1F40;
        *(u8 **)(st + 0x5C) = D_L39_00396C40 + *(s32 *)(g + 0x2544) * 0x8C0;
        for (i = 0; i < 0x7D; i++) {
            (*(E40_00522328 **)(st + 0x58))[i].w30 = 1;
        }
        for (i = 0; i < 10; i++) {
            *(s32 *)(*(u8 **)(st + 0x60) + i * 0x530 + 0x514) = 0;
        }
        for (i = 0; i < 0x23; i++) {
            (*(E40_00522328 **)(st + 0x5C))[i].w38 = -1;
        }
        *(s32 *)(st + 0x24) = 0;
        *(s32 *)(st + 0x38) = 0;
        *(s32 *)(st + 0x30) = 0;
        *(s32 *)(st + 0x34) = 0;
        *(s32 *)(st + 0x44) = 0;
        *(s32 *)(st + 0x40) = 0;
        *(s32 *)(st + 0x48) = 0;
        *(s32 *)(st + 0x4C) = 0;
        *(s32 *)(st + 0x54) = 0;
        obj[0x20] = 1;
        *(s32 *)(st + 0x20) = -1;
    }
    if (func_L39_00639D90(g) != 0) {
        s32 c = func_L39_005FFD20(150.0f, (f32 *)(g + 0x1338), (s32 *)(g + 0x133C), *(f32 *)(g + 0x1250) >= 1.0f);
        if (g[0x1A14] != 0) {
            func_L01_003F6F20(g[0x24C9], obj, c, 0, 0x21, -1, 4, 0.8f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        }
    }
    if (g != 0 && *(s32 *)(g + 0x474) == 3) {
        h = *(s32 *)(st + 0x20);
        if (h != -1 && ((Slot_00522328 *)(D_001FE020 + (h << 7)))->pDC == obj && ((Slot_00522328 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
            func_L39_005F3088(h);
        }
        *(s32 *)(st + 0x20) = -1;
        return;
    }
    func_003C2F58(obj, 0, st);
    if (obj[0x42] == obj[0x43] && (obj[0x60] & 2)) {
        func_L01_00444F38(obj, 1, 0, 2, 0);
    }
    state = func_L39_006732D0(g + 0x1A40, 0, 1, 0);
    if (g != 0 && (u8)func_L39_00673498(g + 0x1A40, 0) != 0 && func_L39_00620CF8(g, -1) != 0 &&
            (*(unsigned long *)(g + 0x1A08) & 0xFFFF000000UL) == 0) {
            s32 n;
            s32 j;
            func_L01_004482A0((f32 *)(st + 0x40), (f32 *)(st + 0x44), 10.0f, 0.009000001f, 0.0024f, 12.0f);
            func_L39_00621D60(g, -1);
            if (func_L39_005F2FA0((s32)obj, *(s32 *)(st + 0x20)) == 0) {
                *(s32 *)(st + 0x20) = func_L39_005F33E0(0, 4, obj);
            }
            if (obj[0x43] != 2) {
                func_003C3A10(obj, 2, 0, 0);
            }
            {
                s32 id = *(s32 *)(g + 0x2544);
                u8 *p = D_L39_0024CE20[id];
                id = p != 0 ? *(s32 *)(p + 0x2548) : -1;
                func_L39_005FFDF8(id);
            }
            n = func_003D4D00(st, 0x10, obj, 0, 0.5f);
            func_L39_005FFE78();
            for (j = 0; j < n; j++) {
                if (D_L39_002637C0[j] == *(u8 **)(g + 0x2524)) {
                    continue;
                }
            {
                Hit_00522328 hit;
                Ent_00522328 *ent;

                vec_sub_ab(&tmp.v, D_L39_002637C0[j] + 0x10, obj + 0x10);
                func_0038CF68(&tmp.v, &tmp.v, 1.0f);
                func_0038CF68(&hit, &hit, 1.0f);
                if (func_L39_00648AE0(g, 7)) {
                    ent = &D_L39_0049C890[Weap_00522328(7)->b21];
                } else {
                    ent = Weap_00522328(7);
                }
                func_L01_00446760(&hit, obj, 0x1110001, &tmp.v, ent->f30);
                hit.pos = tmp.v;
                hit.pos.w = 5627.925f;
                hit.w20 = 1;
                hit.b18 = 9;
                hit.b19 = 1;
                hit.h1A = *(s16 *)(D_L39_002637C0[j] + 0xAA);
                func_L01_00446978(D_L39_002637C0[j], &hit);
                if (*(s32 *)(st + 0x28) <= 0) {
                    func_L39_005F33E0(1, 0, obj);
                    *(s32 *)(st + 0x28) = 5;
                }
            }
            }
        } else if (g != 0) {
            h = *(s32 *)(st + 0x20);
            if (h != -1 && ((Slot_00522328 *)(D_001FE020 + (h << 7)))->pDC == obj && ((Slot_00522328 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
                func_L39_005F3088(h);
            }
            *(s32 *)(st + 0x20) = -1;
            if (state == 4) {
                func_L39_005F33E0(2, 0, obj);
            }
            if (g[0x1A0B] != 0) {
                *(f32 *)(st + 0x40) = 0.0f;
            } else {
                func_L01_004482A0((f32 *)(st + 0x40), (f32 *)(st + 0x44), 0.0f, 0.072000004f, 0.012f, 0.15f);
            }
            func_L39_00622288(g);
        }
    if (g != 0 && DecEq_00522328(g + 0x19E4, &tmp.buf, 1)) {
        (*(void (**)(void *, s32, s32, s32, s32))(*(u8 **)(g + 0x14) + 0x34))(g, 0x1D, 1, 0, 1);
    }
    func_003C2F58(obj, 0, st);
    qzero(&v0);
    v0.y = -1.0f;
    func_0038D000(&v0, &v0, obj + 0xC0);
    v0.z += 0.02f;
    func_0038CF68(&v0, &v0, *(f32 *)(st + 0x40) * 0.05f);
    if (g != 0) {
        *(u8 **)(g + 0x1078) = 0;
        if (g[0x1A14] == 0) {
            func_L39_00674320(g);
            if (*(u8 **)(g + 0x1078) != 0) {
                *(f32 *)(g + 0x1250) = 0.95f;
            }
        } else if (g[0x1A08] == 0 && *(s32 *)(g + 0x1310) != 0 && *(f32 *)(g + 0x1250) > 0.9f) {
            *(s32 *)(g + 0x1078) = *(s32 *)(g + 0x122C);
        }
        if (g != 0 && *(u8 **)(g + 0x1078) != 0) {
            f32 r;
            func_L01_00457588(*(u8 **)(g + 0x1078), st, &tmp.v, *(f32 *)(st + 0x40) * 0.05f);
            r = func_0038CF38(*(u8 **)(g + 0x1078) + 0x10, st);
            tmp.v.z += D_L39_0024A9D0 * 0.020000001f * r * r;
            func_0038CDF8(&v0, &v0, &tmp.v, (*(f32 *)(g + 0x1250) - 0.9f) / 0.100000024f);
        }
    }
    {
        vu0_v4 off;
        f32 a;
        f32 b;

        *(u128_t *)&off = 0;
        a = (f32)(D_L39_0024112C % 31) / 31.166666f * 6.28318f - 3.14159f;
        b = (f32)(D_L39_0024112C % 37) / 37.833332f * 6.28318f - 3.14159f;
        off.y = func_0038D0B0(a) * D_L39_0024A9D4;
        off.z = func_0038D0B0(b) * D_L39_0024A9D8;
        tmp.v = off;
    }
    func_0038D000(&tmp.v, &tmp.v, obj + 0xC0);
    vec_add_ab(&v0, &v0, &tmp.v);
    *(u128_t *)(st + 0x10) = *(u128_t *)st;
    if (g != 0) {
        if (Dec_00522328(g + 0x19E4, &tmp.buf) != 0) {
            func_0038D890(&v0, &v0, *(u8 **)(g + 0x2524) + 0xD0, -0.09817477f);
        }
    }
    if (*(f32 *)(st + 0x40) != 0.0f) {
        func_L39_005236F0(obj, (u128_t *)st, (u128_t *)&v0, 0x21);
    }
    *(f32 *)(st + 0x48) -= 0.1f;
    if (*(f32 *)(st + 0x48) <= -8.0f) {
        *(f32 *)(st + 0x48) += 8.0f;
    }
    *(f32 *)(st + 0x4C) -= 0.025f;
    if (*(f32 *)(st + 0x4C) <= -8.0f) {
        *(f32 *)(st + 0x4C) += 8.0f;
    }
    lvl = 4;
    if (*(f32 *)(st + 0x40) != 0.0f) {
        tmp.v = *(vu0_v4 *)(obj + 0x10);
        tmp.v.w = 1.0f;
        if (func_L39_005BE900(&tmp.v, (s32)&dist, D_L39_0024A9CC) != -1) {
            if (dist < D_L39_0024A9C0 * D_L39_0024A9C0) {
                lvl = 0;
            } else if (dist < D_L39_0024A9C4 * D_L39_0024A9C4) {
                lvl = 1;
            } else if (dist < D_L39_0024A9C8 * D_L39_0024A9C8) {
                lvl = 2;
            } else {
                lvl = 3;
            }
        }
        func_L39_00522FA8(obj, lvl);
        if (lvl < 4) {
            func_L39_00522EE8((char *)obj);
        }
    } else {
        *(s32 *)(st + 0x34) = 0;
        *(s32 *)(st + 0x24) = 0;
        *(s32 *)(st + 0x38) = 0;
        *(s32 *)(st + 0x30) = 0;
    }
    func_L39_00524610(obj);
    tmp.v = *(vu0_v4 *)(obj + 0x10);
    tmp.v.w = 25.0f;
    if (func_L39_005BE900(&tmp.v, 0, 96.0f) >= 0) {
        func_L01_00404A10(func_L39_00523948, obj);
    }
}
/* localdecomp:end func_L39_00522328 */
