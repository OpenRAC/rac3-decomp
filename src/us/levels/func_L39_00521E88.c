#include "common.h"

/* NTSC-U counterpart of func_L39_00522328 (src/levels/shared/L39_00522328.c) */
typedef int u128_t __attribute__((mode(TI)));
extern void func_00388830(void *, void *, f32);

/* localdecomp:start func_L39_00521E88 */
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

extern u8 D_L39_0039B340[];
extern u8 D_L39_00387340[];
extern u8 D_L39_00396D40[];
extern u8 D_L39_001FE1A0[];
extern u8 *D_L39_0024CF20[8] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024CF20, 32");
extern Ent_00522328 D_L39_0049C950[];
extern u8 *D_L39_002638C0[];
extern u8 D_L39_004998A0[];
extern s32 D_L39_002412AC;
extern f32 D_L39_0024AAD0_00521E88;
extern f32 D_L39_0024AAD4;
extern f32 D_L39_0024AAD8_00521E88;
extern f32 D_L39_0024AADC;
extern f32 D_L39_0024AAE0_00521E88;
extern f32 D_L39_0024AAE4;
extern f32 D_L39_0024AAE8;
__asm__(".extern D_L39_0024AAD0_00521E88, 4");
__asm__(".extern D_L39_0024AAD4, 4");
__asm__(".extern D_L39_0024AAD8_00521E88, 4");
__asm__(".extern D_L39_0024AADC, 4");
__asm__(".extern D_L39_0024AAE0_00521E88, 4");
__asm__(".extern D_L39_0024AAE4, 4");
__asm__(".extern D_L39_0024AAE8, 4");

extern s32 func_00388398(void *);
extern void func_L01_004C4AB8(s32);
extern void func_L39_00619D58(u8 *, u8 **);
extern s32 func_L39_00637548(void *);
extern s32 func_L39_005FD580(f32, f32 *, s32 *, s32);
extern void func_L01_003F4D78(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L39_005F0988(s32);
extern void func_003BDA38(void *, s32, void *);
extern void func_L01_00441E00(u8 *, s32, s32, s32, s32);
extern s32 func_L39_00670988(void *, s32, s32, s32);
extern s32 func_L39_00670B50(void *, s32);
extern s32 func_L39_0061E558(u8 *, s32);
extern void func_L01_00445168(f32 *, f32 *, f32, f32, f32, f32);
extern void func_L39_0061F5C0(void *, s32);
extern s32 func_L39_005F08A0(s32, s32);
extern s32 func_L39_005F0CE0(s32, s32, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L39_005FD658(s32);
extern s32 func_003CF790(void *, s32, void *, s32, f32);
extern void func_L39_005FD6D8(void);
extern s32 func_L39_00646268(u8 *, s32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_00443840(void *, void *);
extern void func_L39_0061FAE8(void *);
extern void func_003888C8(void *, void *, void *);
extern void func_L39_006719D8(u8 *);
extern void func_L01_00454298(void *, void *, void *, f32);
extern f32 func_00388800(void *, void *);
extern void func_003886C0(void *, void *, void *, f32);
extern f32 func_00388978(f32);
extern void func_00389158(void *, void *, void *, f32);
extern s32 func_L39_005BC958(void *, s32, f32);
extern void func_L39_00522B00(void *, s32);
extern void func_L39_00522A40(char *object);
extern void func_L39_00524168(void *);
extern void func_L01_004026A0(void *, void *);
extern void func_L39_005234A0(char *obj);
extern void func_L39_00523248(void *obj, u128_t *p1, u128_t *p2, s32 arg);

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
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
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
    return &D_L39_0049C950[i];
}

void func_L39_00521E88(u8 *obj)
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
    func_00388398(st + 0x28);
    if (g != 0 && *(s32 *)(g + 0x474) == 3) {
        for (; i < 0x23; i++) {
            u8 *e = *(u8 **)(st + 0x5C) + (i << 6);
            if (*(s32 *)(e + 0x38) >= 0) {
                func_L01_004C4AB8(*(s32 *)(e + 0x38));
                *(s32 *)(e + 0x38) = -1;
            }
        }
    }
    if (obj[0x20] == 0) {
        func_L39_00619D58(obj, (u8 **)(st + 0x2C));
        g = *(u8 **)(st + 0x2C);
        *(u8 **)(st + 0x60) = D_L39_0039B340 + *(s32 *)(g + 0x2544) * 0x33E0;
        *(u8 **)(st + 0x58) = D_L39_00387340 + *(s32 *)(g + 0x2544) * 0x1F40;
        *(u8 **)(st + 0x5C) = D_L39_00396D40 + *(s32 *)(g + 0x2544) * 0x8C0;
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
    if (func_L39_00637548(g) != 0) {
        s32 c = func_L39_005FD580(150.0f, (f32 *)(g + 0x1338), (s32 *)(g + 0x133C), *(f32 *)(g + 0x1250) >= 1.0f);
        if (g[0x1A14] != 0) {
            func_L01_003F4D78(g[0x24C9], obj, c, 0, 0x21, -1, 4, 0.8f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        }
    }
    if (g != 0 && *(s32 *)(g + 0x474) == 3) {
        h = *(s32 *)(st + 0x20);
        if (h != -1 && ((Slot_00522328 *)(D_L39_001FE1A0 + (h << 7)))->pDC == obj && ((Slot_00522328 *)(D_L39_001FE1A0 + (h << 7)))->bD0 != 0) {
            func_L39_005F0988(h);
        }
        *(s32 *)(st + 0x20) = -1;
        return;
    }
    func_003BDA38(obj, 0, st);
    if (obj[0x42] == obj[0x43] && (obj[0x60] & 2)) {
        func_L01_00441E00(obj, 1, 0, 2, 0);
    }
    state = func_L39_00670988(g + 0x1A40, 0, 1, 0);
    if (g != 0 && (u8)func_L39_00670B50(g + 0x1A40, 0) != 0 && func_L39_0061E558(g, -1) != 0 &&
            (*(unsigned long *)(g + 0x1A08) & 0xFFFF000000UL) == 0) {
            s32 n;
            s32 j;
            func_L01_00445168((f32 *)(st + 0x40), (f32 *)(st + 0x44), 10.0f, 0.0075f, 0.002f, 10.0f);
            func_L39_0061F5C0(g, -1);
            if (func_L39_005F08A0((s32)obj, *(s32 *)(st + 0x20)) == 0) {
                *(s32 *)(st + 0x20) = func_L39_005F0CE0(0, 4, obj);
            }
            if (obj[0x43] != 2) {
                func_003BE4F0(obj, 2, 0, 0);
            }
            {
                s32 id = *(s32 *)(g + 0x2544);
                u8 *p = D_L39_0024CF20[id];
                id = p != 0 ? *(s32 *)(p + 0x2548) : -1;
                func_L39_005FD658(id);
            }
            n = func_003CF790(st, 0x10, obj, 0, 0.5f);
            func_L39_005FD6D8();
            for (j = 0; j < n; j++) {
                if (D_L39_002638C0[j] == *(u8 **)(g + 0x2524)) {
                    continue;
                }
            {
                Hit_00522328 hit;
                Ent_00522328 *ent;

                vec_sub_ab(&tmp.v, D_L39_002638C0[j] + 0x10, obj + 0x10);
                func_00388830(&tmp.v, &tmp.v, 1.0f);
                func_00388830(&hit, &hit, 1.0f);
                if (func_L39_00646268(g, 7)) {
                    ent = &D_L39_0049C950[Weap_00522328(7)->b21];
                } else {
                    ent = Weap_00522328(7);
                }
                func_L01_00443628(&hit, obj, 0x1110001, &tmp.v, ent->f30);
                hit.pos = tmp.v;
                hit.pos.w = 5627.925f;
                hit.w20 = 1;
                hit.b18 = 9;
                hit.b19 = 1;
                hit.h1A = *(s16 *)(D_L39_002638C0[j] + 0xAA);
                func_L01_00443840(D_L39_002638C0[j], &hit);
                if (*(s32 *)(st + 0x28) <= 0) {
                    func_L39_005F0CE0(1, 0, obj);
                    *(s32 *)(st + 0x28) = 6;
                }
            }
            }
        } else if (g != 0) {
            h = *(s32 *)(st + 0x20);
            if (h != -1 && ((Slot_00522328 *)(D_L39_001FE1A0 + (h << 7)))->pDC == obj && ((Slot_00522328 *)(D_L39_001FE1A0 + (h << 7)))->bD0 != 0) {
                func_L39_005F0988(h);
            }
            *(s32 *)(st + 0x20) = -1;
            if (state == 4) {
                func_L39_005F0CE0(2, 0, obj);
            }
            if (g[0x1A0B] != 0) {
                *(f32 *)(st + 0x40) = 0.0f;
            } else {
                func_L01_00445168((f32 *)(st + 0x40), (f32 *)(st + 0x44), 0.0f, 0.06f, 0.01f, 0.125f);
            }
            func_L39_0061FAE8(g);
        }
    if (g != 0 && DecEq_00522328(g + 0x19E4, &tmp.buf, 1)) {
        (*(void (**)(void *, s32, s32, s32, s32))(*(u8 **)(g + 0x14) + 0x34))(g, 0x1D, 1, 0, 1);
    }
    func_003BDA38(obj, 0, st);
    qzero(&v0);
    v0.y = -1.0f;
    func_003888C8(&v0, &v0, obj + 0xC0);
    v0.z += 0.02f;
    func_00388830(&v0, &v0, *(f32 *)(st + 0x40) * 0.05f);
    if (g != 0) {
        *(u8 **)(g + 0x1078) = 0;
        if (g[0x1A14] == 0) {
            func_L39_006719D8(g);
            if (*(u8 **)(g + 0x1078) != 0) {
                *(f32 *)(g + 0x1250) = 0.95f;
            }
        } else if (g[0x1A08] == 0 && *(s32 *)(g + 0x1310) != 0 && *(f32 *)(g + 0x1250) > 0.9f) {
            *(s32 *)(g + 0x1078) = *(s32 *)(g + 0x122C);
        }
        if (g != 0 && *(u8 **)(g + 0x1078) != 0) {
            f32 r;
            func_L01_00454298(*(u8 **)(g + 0x1078), st, &tmp.v, *(f32 *)(st + 0x40) * 0.05f);
            r = func_00388800(*(u8 **)(g + 0x1078) + 0x10, st);
            tmp.v.z += D_L39_0024AAE0_00521E88 * 0.016666668f * r * r;
            func_003886C0(&v0, &v0, &tmp.v, (*(f32 *)(g + 0x1250) - 0.9f) / 0.100000024f);
        }
    }
    {
        vu0_v4 off;
        f32 a;
        f32 b;

        *(u128_t *)&off = 0;
        a = (f32)(D_L39_002412AC % 37) / 37.0f * 6.28318f - 3.14159f;
        b = (f32)(D_L39_002412AC % 45) / 45.0f * 6.28318f - 3.14159f;
        off.y = func_00388978(a) * D_L39_0024AAE4;
        off.z = func_00388978(b) * D_L39_0024AAE8;
        tmp.v = off;
    }
    func_003888C8(&tmp.v, &tmp.v, obj + 0xC0);
    vec_add_ab(&v0, &v0, &tmp.v);
    *(u128_t *)(st + 0x10) = *(u128_t *)st;
    if (g != 0) {
        if (Dec_00522328(g + 0x19E4, &tmp.buf) != 0) {
            func_00389158(&v0, &v0, *(u8 **)(g + 0x2524) + 0xD0, -0.09817477f);
        }
    }
    if (*(f32 *)(st + 0x40) != 0.0f) {
        func_L39_00523248(obj, (u128_t *)st, (u128_t *)&v0, 0x28);
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
        if (func_L39_005BC958(&tmp.v, (s32)&dist, D_L39_0024AADC) != -1) {
            if (dist < D_L39_0024AAD0_00521E88 * D_L39_0024AAD0_00521E88) {
                lvl = 0;
            } else if (dist < D_L39_0024AAD4 * D_L39_0024AAD4) {
                lvl = 1;
            } else if (dist < D_L39_0024AAD8_00521E88 * D_L39_0024AAD8_00521E88) {
                lvl = 2;
            } else {
                lvl = 3;
            }
        }
        func_L39_00522B00(obj, lvl);
        if (lvl < 4) {
            func_L39_00522A40((char *)obj);
        }
    } else {
        *(s32 *)(st + 0x34) = 0;
        *(s32 *)(st + 0x24) = 0;
        *(s32 *)(st + 0x38) = 0;
        *(s32 *)(st + 0x30) = 0;
    }
    func_L39_00524168(obj);
    tmp.v = *(vu0_v4 *)(obj + 0x10);
    tmp.v.w = 25.0f;
    if (func_L39_005BC958(&tmp.v, 0, 96.0f) >= 0) {
        func_L01_004026A0(func_L39_005234A0, obj);
    }
}
/* localdecomp:end func_L39_00521E88 */
