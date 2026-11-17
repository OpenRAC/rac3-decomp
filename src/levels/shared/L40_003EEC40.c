#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003EEC40;

typedef struct {
    u8 b[16];
} B_003EEE80;
typedef struct {
    u8 pad0[8];
    s32 id;
    u8 pad0C[0x11C];
    s32 time;
} G_003EEE80;
typedef union {
    u8 b[8];
    u32 w[2];
} Buf_003EEE80;

/* localdecomp:start func_L40_003EEC40 */
#include "vu0.h"


__asm__(".extern D_L40_00246DFC, 4");
__asm__(".extern D_L40_00246D38, 4");
extern f32 D_L40_00246DFC;
extern f32 D_L40_00246D38;
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L40_00482190(void *, void *, s32, f32, f32, f32);

void func_L40_003EEC40(u8 *o, u8 *src) {
    u8 *v = *(u8 **)(o + 0x68);
    V_003EEC40 d;
    f32 len;
    f32 dist;
    f32 c;
    V_003EEC40 *p;

    if (*(s32 *)(v + 0x264) == 0x539) {
        *(u128_t *)(o + 0x10) = *(u128_t *)src;
        return;
    }
    p = &d;
    dist = func_0038CF38(o + 0x10, v + 0x340);
    vec_sub_ab(p, v + 0x2E0, o + 0x10);
    len = func_0038CEA8(p);
    c = 0.020000001f;
    if (len < D_L40_00246DFC * c) {
        return;
    }
    func_0038CE20(&d, &d, 0.048f);
    vec_sub_ab(&d, &d, v + 0x110);
    if (D_L40_00246D38 < dist) {
        func_0038CE20(&d, &d, 0.1872f);
    } else {
        func_0038CE20(&d, &d, 0.36f);
    }
    d.z = d.z * 0.88f;
    vec_add_ab(v + 0x110, v + 0x110, &d);
    if (func_L40_00482190(o, v + 0x110, 0, 0.7f, 0.4f, 0.0f) != 0) {
        if (10.0f < len) {
            *(s32 *)(v + 0x290) += 1;
            if (*(s32 *)(v + 0x290) >= 0x12) {
                *(u128_t *)(o + 0x10) = *(u128_t *)(v + 0x2E0);
                *(s32 *)(v + 0x290) = 0;
            }
        }
    } else {
        *(s32 *)(v + 0x290) = 0;
    }
    len = 1.1f;
    if (dist < len) {
        f32 d = len - dist;
        f32 a = func_0038D160(*(f32 *)(v + 0x340) - *(f32 *)(o + 0x10),
                              *(f32 *)(v + 0x344) - *(f32 *)(o + 0x14));
        *(f32 *)(v + 0x110) -= d * func_0038D098(a) * 0.14400001f;
        d *= func_0038D0B0(a);
        d *= 0.14400001f;
        *(f32 *)(v + 0x114) -= d;
    }
}
/* localdecomp:end func_L40_003EEC40 */

/* localdecomp:start func_L40_003EEE80 */
#include "vu0.h"

#define F32(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(u8 **)((u8 *)(p) + (o)))


extern G_003EEE80 D_001A5CD0;
extern s32 D_001A5DF8[];
__asm__(".extern D_L40_00246D90, 4");
extern f32 D_L40_00246D90;
__asm__(".extern D_L40_00246D94, 4");
extern f32 D_L40_00246D94;
__asm__(".extern D_L40_00246E04, 4");
extern s32 D_L40_00246E04;
extern s32 D_L40_0024112C;
extern s32 D_L40_00249750[2];
extern u8 *D_L40_0025B998[];
extern u8 D_L40_003BFE20[];

extern u8 *func_L39_0066C3C8(u8 *, void *);
extern void func_L40_003F0B28(u8 *, s32);
extern u8 *func_L39_0061BFB0(s32);
extern s32 func_L40_0053DAE8(s32, s32);
extern void func_L40_003ED980(u8 *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L40_003F1660(u8 *, s32, s32, s32);
extern void func_L39_005F2FF8(void *, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L40_003F0D58(u8 *);
extern f32 func_0038CF00(void *, void *);
extern s32 func_L40_0053F018(u8 *);
extern u8 *func_L39_0066C2B8(void);
extern s32 func_L39_0066C280(s32, s32, s32, s32, u8 *);
extern void func_L40_0053F068(u8 *, s32, s32);
extern void func_L40_0053F038(u8 *, s32);
extern s32 func_L39_0066C1F0(s32);
extern void func_L40_003EDC68(u8 *, s32, s32);
extern void func_L40_003F19E0(void *);
extern void func_L40_003F17E0(u8 *);
extern void func_L40_003F1568(u8 *);
extern void func_L39_0066C470(s32);
extern void func_L40_0053F6E0(u8 *);
extern u8 *func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L40_003F11C8(u8 *, s32);
extern u8 *func_L40_0053E760(s32, void *, s32, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);


static inline u32 dec_3EEE80(u8 *q) {
    u32 b;
    u32 n;

    if (*q == 0) {
        b = 0;
    } else {
        Buf_003EEE80 buf;
        u8 *dp;
        u32 a;
        s32 k;
        s32 m;
        s32 j;

        n = *q;
        k = ((u32)q - n) & 7;
        m = n + 1;
        dp = buf.b;
        for (j = 0; j < 40; j += 5) {
            *dp++ = D_L40_003BFE20[m + ((k + j) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = b;
    }
    return b;
}

static inline s32 hit31_3EEE80(u8 *pl) {
    u8 *e = PTR(pl, 0x2530);
    u16 hit;

    if (e != 0 && e[0x27B] != 0) {
        hit = 0;
        if ((dec_3EEE80(pl + 0x19E4) ^ 0x31) == 0) {
            hit++;
        }
    } else {
        hit = 0;
    }
    return hit;
}

static inline s32 alive_3EEE80(u8 *pl) {
    u8 *q = pl + 0x2476;
    f32 f;
    f32 zero;

    zero = 0.0f;
    if (*q == 0) {
        f = zero;
    } else {
        Buf_003EEE80 buf;
        u8 *dp;
        u32 a;
        u32 n;
        s32 k;
        s32 m;
        s32 j;

        n = *q;
        k = ((u32)q - n) & 7;
        m = n + 1;
        dp = buf.b;
        for (j = 0; j < 40; j += 5) {
            *dp++ = D_L40_003BFE20[m + ((k + j) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q;
        buf.w[0] = a;
        buf.w[1] = buf.w[1] ^ a;
        f = *(f32 *)&buf.w[1];
    }
    {
        s32 ok = f > zero;
        return ok;
    }
}

void func_L40_003EEE80(s32 uid, u8 *m) {
    u8 *q = PTR(m, 0x90);
    u8 *v = PTR(m, 0x68);
    u8 *msg;
    u8 *pl;

    if (U8(m, 0x20) == 0x1C) {
        msg = PTR(q, 0x38);
        while (msg != 0) {
            msg = func_L39_0066C3C8(msg, q + 0x38);
        }
        return;
    }
    msg = PTR(q, 0x38);
    while (msg != 0) {
        u8 *hdr = msg + 8;
        if (D_001A5CD0.time < S32(hdr, 8)) {
            msg = PTR(msg, 0x84);
            continue;
        }
        switch (S32(msg, 8)) {
        case 1: {
            u8 *data = msg + 0x18;
            switch (S32(hdr, 0xC)) {
            case 0: {
                S32(v, 0x304) = S32(data, 0);
                S32(v, 0x29C) = S32(data, 0);
                S32(v, 0x2B4) = D_001A5CD0.time;
                func_L40_003F0B28(m, S32(v, 0x304));
                pl = func_L39_0061BFB0(S32(v, 0x29C));
                if (pl != 0 && PTR(pl, 0x2558) != 0 && S32(v, 0x2C0) == -1) {
                    func_L40_0053DAE8(uid, S32(PTR(PTR(pl, 0x2558), 4), 0x40));
                    S32(v, 0x2C0) = S32(PTR(PTR(pl, 0x2558), 4), 0x40);
                }
                {
                    s32 t = -1;
                    if (pl != 0 && PTR(pl, 0x2558) != 0) {
                        t = S32(PTR(PTR(pl, 0x2558), 4), 0x40);
                    }
                    func_L40_003ED980(m, t);
                }
                func_L01_004450F0(m, 0x17, -1);
                break;
            }
            case 1: {
                s32 x;
                x = S32(data, 0);
                S32(v, 0x308) = x;
                if (x == -1) {
                    if (S32(v, 0x29C) != 0) {
                        func_L01_004450F0(m, 0x17, -1);
                    } else {
                        func_L01_004450F0(m, 1, -1);
                    }
                } else {
                    if (U8(m, 0x20) == 0x1B) {
                        break;
                    }
                    func_L01_004450F0(m, 0xC, -1);
                }
                break;
            }
            case 2: {
                B_003EEE80 tmp;
                vu0_q a[1];
                vu0_q b[1];
                vu0_v4 d;
                {
                    tmp = *(B_003EEE80 *)data;
                    vec_sub_ab(&d, v + 0x2D0, &tmp);
                    data += 0x10;
                    b[0] = *(vu0_q *)&d;
                    a[0] = *(vu0_q *)&d;
                    *(vu0_q *)(v + 0x2D0) = *(vu0_q *)&tmp;
                    *(B_003EEE80 *)(v + 0x370) = *(B_003EEE80 *)data;
                    data += 0x10;
                    *(B_003EEE80 *)(v + 0x380) = *(B_003EEE80 *)data;
                    ((struct { u8 _p[0x2B4]; s32 v; } *)v)->v = S32(data, 0x10);
                    if (!(D_L40_00246D90 < (f32)(D_001A5CD0.time - S32(v, 0x2B4)))) {
                        U8(m, 0x20) = 0x18;
                    }
                }
                break;
            }
            case 3:
                S32(v, 0x280) = S32(data, 0);
                break;
            case 4:
                func_L01_004450F0(m, 0x1B, -1);
                func_L40_003F1660(m, 0, 0, 8);
                S32(m, 0x98) = 0;
                U16(m, 0x34) = (U16(m, 0x34) | 0x41) & ~0x1000;
                func_L39_005F2FF8(m, 1);
                break;
            case 5: {
                u8 *t;
                func_L01_004450F0(m, 0x17, -1);
                t = PTR(m, 0x24);
                U16(m, 0x34) &= ~0x41;
                U16(m, 0x34) |= U16(t, 0x44) & 0x1000;
                S32(m, 0x98) = S32(t, 0x10);
                F32(m, 0x10) = F32(data, 0);
                data += 4;
                F32(m, 0x14) = F32(data, 0);
                F32(m, 0x18) = F32(data, 4) + 1.3f;
                F32(m, 0x18) = func_003C3D30(m + 0x10, 0, 0, 0.5f);
                S32(v, 0x2B4) = D_001A5CD0.time;
                break;
            }
            case 6:
                func_L40_003F0D58(m);
                break;
            case 7: {
                B_003EEE80 tmp;
                {
                    tmp = *(B_003EEE80 *)data;
                    func_0038CF00(v + 0x390, &tmp);
                    func_0038CF00(v + 0x390, m + 0x10);
                    *(vu0_q *)(v + 0x390) = *(vu0_q *)&tmp;
                    if (U8(m, 0x20) == 1) {
                        func_L01_004450F0(m, 3, -1);
                    }
                }
                break;
            }
            }
            msg = func_L39_0066C3C8(msg, q + 0x38);
            break;
        }
        case 2:
            func_L01_004450F0(m, 0x1C, -1);
            func_L39_0066C3C8(msg, q + 0x38);
            return;
        case 4:
            if (func_L40_0053F018(m) != 0 && U8(v, 0x33C) == 0) {
                u8 *p;
                u8 *w;
                U8(v, 0x33C) = 1;
                S32(v, 0x26C) = S32(msg, 0x18);
                p = func_L39_0066C2B8();
                if (p == 0) {
                    return;
                }
                w = p + func_L39_0066C280(5, uid, D_001A5CD0.time + 0x1F4, S32(hdr, 0xC), p);
                *(s32 *)w = S32(v, 0x26C);
                w += 4;
                *(s32 *)p = w - p;
            }
            msg = func_L39_0066C3C8(msg, q + 0x38);
            break;
        case 5: {
            u8 *data;
            U8(v, 0x33C) = 1;
            data = msg + 0x18;
            if (S32(hdr, 0xC) != D_001A5CD0.id) {
                func_L40_0053F068(m, S32(hdr, 0xC), S32(hdr, 8));
            } else {
                func_L40_0053F038(m, S32(hdr, 8));
                S32(v, 0x300) = 2;
                U8(v, 0x33D) = 0;
                if (func_L39_0066C1F0(D_L40_00249750[0]) == 0) {
                    D_L40_00249750[0] = uid;
                } else {
                    D_L40_00249750[1] = uid;
                }
            }
            S32(v, 0x26C) = S32(data, 0);
            msg = func_L39_0066C3C8(msg, q + 0x38);
            break;
        }
        default:
            msg = func_L39_0066C3C8(msg, q + 0x38);
            break;
        }
    }
    if (U8(m, 0x20) == 0x18 && D_L40_00246D94 < (f32)(D_001A5DF8[0] - S32(v, 0x2B4))) {
        if (S16(v, 0x254) != 0) {
            U8(m, 0x20) = 0x19;
        } else {
            U8(m, 0x20) = 0x17;
        }
        {
            f32 z = F32(m, 0x18);
            *(vu0_q *)(m + 0x10) = *(vu0_q *)(v + 0x2D0);
            F32(m, 0x18) = z;
        }
        *(vu0_q *)(m + 0xF0) = *(vu0_q *)(v + 0x370);
        *(vu0_q *)(v + 0x110) = *(vu0_q *)(v + 0x380);
        if (D_L40_00246E04 == 1) {
            {
                vu0_v4 tmp;
                {
                    *(vu0_q *)&tmp = *(vu0_q *)(v + 0x2D0);
                    func_L40_003F19E0(&tmp);
                }
            }
            {
                vu0_v4 tmp;
                {
                    *(vu0_q *)&tmp = *(vu0_q *)(v + 0x370);
                    func_L40_003F19E0(&tmp);
                }
            }
        }
        S32(v, 0x12C) = D_L40_0024112C - 1;
    }
    if (S32(v, 0x304) != 0) {
        if (U8(m, 0x20) == 0x17 || U8(m, 0x20) == 0x19) {
            s32 now = D_001A5DF8[0];
            if (D_L40_00246D90 < (f32)(now - S32(v, 0x2B4))) {
                S32(v, 0x2B4) = now;
                U8(m, 0x20) = 0x18;
                func_L40_003EDC68(m, uid, func_L40_0053F018(m));
                return;
            }
        }
        pl = func_L39_0061BFB0(S32(v, 0x29C));
        if (pl != 0 && (dec_3EEE80(pl + 0x19E6) ^ 0x14) != 0 && (u8)hit31_3EEE80(pl) == 0 && (u8)alive_3EEE80(pl)) {
            *(vu0_q *)(v + 0x340) = *(vu0_q *)(PTR(pl, 0x2524) + 0x10);
            F32(v, 0x240) = F32(PTR(pl, 0x2524), 0xF8);
            if (S16(v, 0x254) == 1) {
                if (U8(m, 0x20) == 0x17) {
                    func_L01_004450F0(m, 0x19, -1);
                }
            } else if (U8(m, 0x20) == 0x19) {
                func_L01_004450F0(m, 0x17, -1);
            }
            if (S32(v, 0x264) == 0x539) {
                func_L40_003F17E0(m);
            }
        } else if (pl != 0 && ((dec_3EEE80(pl + 0x19E6) ^ 0x14) == 0 || (u8)hit31_3EEE80(pl) != 0) && U8(m, 0x20) != 0x1C) {
            u8 *o;
            func_L40_003F1568(m);
            func_L39_0066C470(uid);
            func_L40_0053F6E0(m);
            o = func_L01_003303B8(m + 0x10, 0, 5, 5, 5, 10, 10, 3, 1.0f, 0.0f, 0.0f, 2.0f, 0, 1, 0, 0, 0, 0, 0x1010000, 0,
                                  0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            if (o != 0) {
                PTR(o, 0xB8) = m;
            }
            func_L01_004450F0(m, 0x25, -1);
            S32(m, 0x98) = 0;
            U16(m, 0x34) = (U16(m, 0x34) | 0x41) & ~0x1000;
            func_L39_005F2FF8(m, 1);
            return;
        }
        func_L40_003F11C8(m, uid);
    }
    if (U8(m, 0x20) != 0xC || S32(v, 0x308) == 0) {
        return;
    }
    if (((u32)S32(v, 0x29C) >> 28) == D_001A5CD0.id) {
        func_L39_0061BFB0(S32(v, 0x29C));
    }
    if (S32(v, 0x308) == -1) {
        if (S32(v, 0x304) != 0) {
            func_L01_004450F0(m, 0x17, -1);
        } else {
            func_L01_004450F0(m, 1, -1);
        }
    }
    PTR(v, 0x230) = func_L40_0053E760(S32(v, 0x308), v + 0x220, -1, 1);
    if (PTR(v, 0x230) == 0) {
        S16(v, 0x234) = 0;
        return;
    }
    {
        vu0_v4 b;
        vu0_v4 a;
        {
            vu0_v4 *pb;
            b = *(vu0_v4 *)(v + 0x220);
            a = *(vu0_v4 *)(m + 0x10);
            b.z += 0.1f;
            a.z += 0.5f;
            pb = &b;
            if (S16(v, 0x234) == 1) {
                vu0_v4 *pa;
                if ((D_L40_0024112C & 0x1F) != (((s32)m >> 8) & 0x1F)) {
                    return;
                }
                pa = &a;
                if (func_0038CF00(pa, pb) < 50.0f) {
                    if (func_003D3CB0(pa, pb, 0, m, 0) == 0 ||
                        (D_L40_0025B998[0] != 0 && D_L40_0025B998[0] == PTR(v, 0x230))) {
                        S16(v, 0x234) = 1;
                    } else {
                        S16(v, 0x234) = 0;
                    }
                } else {
                    S16(v, 0x234) = 0;
                }
            } else {
                vu0_v4 *pa;
                if ((D_L40_0024112C & 7) != (((s32)m >> 8) & 7)) {
                    return;
                }
                pa = &a;
                if (func_0038CF00(pa, pb) < 50.0f) {
                    if (func_003D3CB0(pa, pb, 0, m, 0) == 0 ||
                        (D_L40_0025B998[0] != 0 && D_L40_0025B998[0] == PTR(v, 0x230))) {
                        S16(v, 0x234) = 1;
                    } else {
                        S16(v, 0x234) = 0;
                    }
                } else {
                    S16(v, 0x234) = 0;
                }
            }
        }
    }
}
/* localdecomp:end func_L40_003EEE80 */

/* localdecomp:start func_L40_003EFC00 */
#include "vu0.h"
__asm__(".extern D_L40_00246D94, 4");
extern f32 D_L40_00246D94;
extern s32 D_001A5DF8[];
extern void func_0038CE20(void *d, void *s, f32 k);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_L40_003F1E48(u8 *m, void *p, f32 yaw);

void func_L40_003EFC00(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    vu0_v4 d;
    s32 n;
    f32 len;
    f32 yaw;
    f32 k;

    vec_sub_ba(&d, v + 0x2D0, m + 0x10);
    n = *(s32 *)(v + 0x2B4) + (s32)D_L40_00246D94 - D_001A5DF8[0];
    n = (s32)(n * 0.06f);
    d.z = 0.0f;
    if (n <= 0) {
        n = 0;
    }
    n += 1;
    k = 1.0f / n;
    func_0038CE20(v + 0x110, &d, k);
    len = func_0038CEA8(v + 0x110);
    if (len == 0.0f) {
        *(s32 *)(v + 0x250) -= 1;
    } else {
        yaw = func_0038D160(*(f32 *)(v + 0x2D0) - *(f32 *)(m + 0x10), *(f32 *)(v + 0x2D4) - *(f32 *)(m + 0x14));
        if (n != 1) {
            func_L40_003F1E48(m, v + 0x2D0, yaw);
        } else {
            func_L40_003F1E48(m, v + 0x2D0, yaw);
        }
        *(s32 *)(v + 0x250) -= 1;
    }
}
/* localdecomp:end func_L40_003EFC00 */
