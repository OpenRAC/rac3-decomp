#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L40_003EEE80 (src/levels/shared/L40_003EEC40.c): the core globals at
 * their NTSC-U addresses and 10 in place of 8 for func_L40_003F11B8's last argument (60 Hz) */
/* localdecomp:start func_L40_003EE9D8 */
typedef struct {
    u8 b[16];
} B_003EE9D8;
typedef struct {
    u8 pad0[8];
    s32 id;
    u8 pad0C[0x11C];
    s32 time;
} G_003EE9D8;
typedef union {
    u8 b[8];
    u32 w[2];
} Buf_003EE9D8;



extern G_003EE9D8 D_001A5E50;
extern s32 D_001A5F78[];
__asm__(".extern D_L40_00246F10, 4");
extern f32 D_L40_00246F10;
__asm__(".extern D_L40_00246F14, 4");
extern f32 D_L40_00246F14;
__asm__(".extern D_L40_00246F84, 4");
extern s32 D_L40_00246F84;
extern s32 D_L40_002412AC;
extern s32 D_L40_002498D0[2];
extern u8 *D_L40_0025BB18[];
extern u8 D_L40_003BFF60[];

extern u8 *func_L39_00669AC0(u8 *, void *);
extern void func_L40_003F0680(u8 *, s32);
extern u8 *func_L39_00619838(s32);
extern s32 func_L40_0053B238(s32, s32);
extern void func_L40_003ED4E0(u8 *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L40_003F11B8(u8 *, s32, s32, s32);
extern void func_L39_005F08F8(void *, s32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_L40_003F08B0(u8 *);
extern f32 func_003887C8(void *, void *);
extern s32 func_L40_0053C768(u8 *);
extern u8 *func_L39_006699B0(void);
extern s32 func_L39_00669978(s32, s32, s32, s32, u8 *);
extern void func_L40_0053C7B8(u8 *, s32, s32);
extern void func_L40_0053C788(u8 *, s32);
extern s32 func_L39_006698E8(s32);
extern void func_L40_003ED7C8(u8 *, s32, s32);
extern void func_L40_003F1538(void *);
extern void func_L40_003F1338(u8 *);
extern void func_L40_003F10C0(u8 *);
extern void func_L39_00669B68(s32);
extern void func_L40_0053CE30(u8 *);
extern u8 *func_L01_0032FE90(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L40_003F0D20(u8 *, s32);
extern u8 *func_L40_0053BEB0(s32, void *, s32, s32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);


static inline u32 dec_003EE9D8(u8 *q) {
    u32 b;
    u32 n;

    if (*q == 0) {
        b = 0;
    } else {
        Buf_003EE9D8 buf;
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
            *dp++ = D_L40_003BFF60[m + ((k + j) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = b;
    }
    return b;
}

static inline s32 hit31_003EE9D8(u8 *pl) {
    u8 *e = *(u8 **)(pl + 0x2530);
    u16 hit;

    if (e != 0 && e[0x27B] != 0) {
        hit = 0;
        if ((dec_003EE9D8(pl + 0x19E4) ^ 0x31) == 0) {
            hit++;
        }
    } else {
        hit = 0;
    }
    return hit;
}

static inline s32 alive_003EE9D8(u8 *pl) {
    u8 *q = pl + 0x2476;
    f32 f;
    f32 zero;

    zero = 0.0f;
    if (*q == 0) {
        f = zero;
    } else {
        Buf_003EE9D8 buf;
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
            *dp++ = D_L40_003BFF60[m + ((k + j) & 7) * 255];
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

void func_L40_003EE9D8(s32 uid, u8 *m) {
    u8 *q = *(u8 **)(m + 0x90);
    u8 *v = *(u8 **)(m + 0x68);
    u8 *msg;
    u8 *pl;

    if (*(u8 *)(m + 0x20) == 0x1C) {
        msg = *(u8 **)(q + 0x38);
        while (msg != 0) {
            msg = func_L39_00669AC0(msg, q + 0x38);
        }
        return;
    }
    msg = *(u8 **)(q + 0x38);
    while (msg != 0) {
        u8 *hdr = msg + 8;
        if (D_001A5E50.time < *(s32 *)(hdr + 8)) {
            msg = *(u8 **)(msg + 0x84);
            continue;
        }
        switch (*(s32 *)(msg + 8)) {
        case 1: {
            u8 *data = msg + 0x18;
            switch (*(s32 *)(hdr + 0xC)) {
            case 0: {
                *(s32 *)(v + 0x304) = *(s32 *)(data);
                *(s32 *)(v + 0x29C) = *(s32 *)(data);
                *(s32 *)(v + 0x2B4) = D_001A5E50.time;
                func_L40_003F0680(m, *(s32 *)(v + 0x304));
                pl = func_L39_00619838(*(s32 *)(v + 0x29C));
                if (pl != 0 && *(u8 **)(pl + 0x2558) != 0 && *(s32 *)(v + 0x2C0) == -1) {
                    func_L40_0053B238(uid, *(s32 *)((*(u8 **)((*(u8 **)(pl + 0x2558)) + 4)) + 0x40));
                    *(s32 *)(v + 0x2C0) = *(s32 *)((*(u8 **)((*(u8 **)(pl + 0x2558)) + 4)) + 0x40);
                }
                {
                    s32 t = -1;
                    if (pl != 0 && *(u8 **)(pl + 0x2558) != 0) {
                        t = *(s32 *)((*(u8 **)((*(u8 **)(pl + 0x2558)) + 4)) + 0x40);
                    }
                    func_L40_003ED4E0(m, t);
                }
                func_L01_00441FB8(m, 0x17, -1);
                break;
            }
            case 1: {
                s32 x;
                x = *(s32 *)(data);
                *(s32 *)(v + 0x308) = x;
                if (x == -1) {
                    if (*(s32 *)(v + 0x29C) != 0) {
                        func_L01_00441FB8(m, 0x17, -1);
                    } else {
                        func_L01_00441FB8(m, 1, -1);
                    }
                } else {
                    if (*(u8 *)(m + 0x20) == 0x1B) {
                        break;
                    }
                    func_L01_00441FB8(m, 0xC, -1);
                }
                break;
            }
            case 2: {
                B_003EE9D8 tmp;
                vu0_q a[1];
                vu0_q b[1];
                vu0_v4 d;
                {
                    tmp = *(B_003EE9D8 *)data;
                    vec_sub_ab(&d, v + 0x2D0, &tmp);
                    data += 0x10;
                    b[0] = *(vu0_q *)&d;
                    a[0] = *(vu0_q *)&d;
                    *(vu0_q *)(v + 0x2D0) = *(vu0_q *)&tmp;
                    *(B_003EE9D8 *)(v + 0x370) = *(B_003EE9D8 *)data;
                    data += 0x10;
                    *(B_003EE9D8 *)(v + 0x380) = *(B_003EE9D8 *)data;
                    ((struct { u8 _p[0x2B4]; s32 v; } *)v)->v = *(s32 *)(data + 0x10);
                    if (!(D_L40_00246F10 < (f32)(D_001A5E50.time - *(s32 *)(v + 0x2B4)))) {
                        *(u8 *)(m + 0x20) = 0x18;
                    }
                }
                break;
            }
            case 3:
                *(s32 *)(v + 0x280) = *(s32 *)(data);
                break;
            case 4:
                func_L01_00441FB8(m, 0x1B, -1);
                func_L40_003F11B8(m, 0, 0, 10);
                *(s32 *)(m + 0x98) = 0;
                *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & ~0x1000;
                func_L39_005F08F8(m, 1);
                break;
            case 5: {
                u8 *t;
                func_L01_00441FB8(m, 0x17, -1);
                t = *(u8 **)(m + 0x24);
                *(u16 *)(m + 0x34) &= ~0x41;
                *(u16 *)(m + 0x34) |= *(u16 *)(t + 0x44) & 0x1000;
                *(s32 *)(m + 0x98) = *(s32 *)(t + 0x10);
                *(f32 *)(m + 0x10) = *(f32 *)(data);
                data += 4;
                *(f32 *)(m + 0x14) = *(f32 *)(data);
                *(f32 *)(m + 0x18) = *(f32 *)(data + 4) + 1.3f;
                *(f32 *)(m + 0x18) = func_003BE7F0(m + 0x10, 0, 0, 0.5f);
                *(s32 *)(v + 0x2B4) = D_001A5E50.time;
                break;
            }
            case 6:
                func_L40_003F08B0(m);
                break;
            case 7: {
                B_003EE9D8 tmp;
                {
                    tmp = *(B_003EE9D8 *)data;
                    func_003887C8(v + 0x390, &tmp);
                    func_003887C8(v + 0x390, m + 0x10);
                    *(vu0_q *)(v + 0x390) = *(vu0_q *)&tmp;
                    if (*(u8 *)(m + 0x20) == 1) {
                        func_L01_00441FB8(m, 3, -1);
                    }
                }
                break;
            }
            }
            msg = func_L39_00669AC0(msg, q + 0x38);
            break;
        }
        case 2:
            func_L01_00441FB8(m, 0x1C, -1);
            func_L39_00669AC0(msg, q + 0x38);
            return;
        case 4:
            if (func_L40_0053C768(m) != 0 && *(u8 *)(v + 0x33C) == 0) {
                u8 *p;
                u8 *w;
                *(u8 *)(v + 0x33C) = 1;
                *(s32 *)(v + 0x26C) = *(s32 *)(msg + 0x18);
                p = func_L39_006699B0();
                if (p == 0) {
                    return;
                }
                w = p + func_L39_00669978(5, uid, D_001A5E50.time + 0x1F4, *(s32 *)(hdr + 0xC), p);
                *(s32 *)w = *(s32 *)(v + 0x26C);
                w += 4;
                *(s32 *)p = w - p;
            }
            msg = func_L39_00669AC0(msg, q + 0x38);
            break;
        case 5: {
            u8 *data;
            *(u8 *)(v + 0x33C) = 1;
            data = msg + 0x18;
            if (*(s32 *)(hdr + 0xC) != D_001A5E50.id) {
                func_L40_0053C7B8(m, *(s32 *)(hdr + 0xC), *(s32 *)(hdr + 8));
            } else {
                func_L40_0053C788(m, *(s32 *)(hdr + 8));
                *(s32 *)(v + 0x300) = 2;
                *(u8 *)(v + 0x33D) = 0;
                if (func_L39_006698E8(D_L40_002498D0[0]) == 0) {
                    D_L40_002498D0[0] = uid;
                } else {
                    D_L40_002498D0[1] = uid;
                }
            }
            *(s32 *)(v + 0x26C) = *(s32 *)(data);
            msg = func_L39_00669AC0(msg, q + 0x38);
            break;
        }
        default:
            msg = func_L39_00669AC0(msg, q + 0x38);
            break;
        }
    }
    if (*(u8 *)(m + 0x20) == 0x18 && D_L40_00246F14 < (f32)(D_001A5F78[0] - *(s32 *)(v + 0x2B4))) {
        if (*(s16 *)(v + 0x254) != 0) {
            *(u8 *)(m + 0x20) = 0x19;
        } else {
            *(u8 *)(m + 0x20) = 0x17;
        }
        {
            f32 z = *(f32 *)(m + 0x18);
            *(vu0_q *)(m + 0x10) = *(vu0_q *)(v + 0x2D0);
            *(f32 *)(m + 0x18) = z;
        }
        *(vu0_q *)(m + 0xF0) = *(vu0_q *)(v + 0x370);
        *(vu0_q *)(v + 0x110) = *(vu0_q *)(v + 0x380);
        if (D_L40_00246F84 == 1) {
            {
                vu0_v4 tmp;
                {
                    *(vu0_q *)&tmp = *(vu0_q *)(v + 0x2D0);
                    func_L40_003F1538(&tmp);
                }
            }
            {
                vu0_v4 tmp;
                {
                    *(vu0_q *)&tmp = *(vu0_q *)(v + 0x370);
                    func_L40_003F1538(&tmp);
                }
            }
        }
        *(s32 *)(v + 0x12C) = D_L40_002412AC - 1;
    }
    if (*(s32 *)(v + 0x304) != 0) {
        if (*(u8 *)(m + 0x20) == 0x17 || *(u8 *)(m + 0x20) == 0x19) {
            s32 now = D_001A5F78[0];
            if (D_L40_00246F10 < (f32)(now - *(s32 *)(v + 0x2B4))) {
                *(s32 *)(v + 0x2B4) = now;
                *(u8 *)(m + 0x20) = 0x18;
                func_L40_003ED7C8(m, uid, func_L40_0053C768(m));
                return;
            }
        }
        pl = func_L39_00619838(*(s32 *)(v + 0x29C));
        if (pl != 0 && (dec_003EE9D8(pl + 0x19E6) ^ 0x14) != 0 && (u8)hit31_003EE9D8(pl) == 0 && (u8)alive_003EE9D8(pl)) {
            *(vu0_q *)(v + 0x340) = *(vu0_q *)(*(u8 **)(pl + 0x2524) + 0x10);
            *(f32 *)(v + 0x240) = *(f32 *)((*(u8 **)(pl + 0x2524)) + 0xF8);
            if (*(s16 *)(v + 0x254) == 1) {
                if (*(u8 *)(m + 0x20) == 0x17) {
                    func_L01_00441FB8(m, 0x19, -1);
                }
            } else if (*(u8 *)(m + 0x20) == 0x19) {
                func_L01_00441FB8(m, 0x17, -1);
            }
            if (*(s32 *)(v + 0x264) == 0x539) {
                func_L40_003F1338(m);
            }
        } else if (pl != 0 && ((dec_003EE9D8(pl + 0x19E6) ^ 0x14) == 0 || (u8)hit31_003EE9D8(pl) != 0) && *(u8 *)(m + 0x20) != 0x1C) {
            u8 *o;
            func_L40_003F10C0(m);
            func_L39_00669B68(uid);
            func_L40_0053CE30(m);
            o = func_L01_0032FE90(m + 0x10, 0, 5, 5, 5, 10, 10, 3, 1.0f, 0.0f, 0.0f, 2.0f, 0, 1, 0, 0, 0, 0, 0x1010000, 0,
                                  0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            if (o != 0) {
                *(u8 **)(o + 0xB8) = m;
            }
            func_L01_00441FB8(m, 0x25, -1);
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & ~0x1000;
            func_L39_005F08F8(m, 1);
            return;
        }
        func_L40_003F0D20(m, uid);
    }
    if (*(u8 *)(m + 0x20) != 0xC || *(s32 *)(v + 0x308) == 0) {
        return;
    }
    if (((u32)*(s32 *)(v + 0x29C) >> 28) == D_001A5E50.id) {
        func_L39_00619838(*(s32 *)(v + 0x29C));
    }
    if (*(s32 *)(v + 0x308) == -1) {
        if (*(s32 *)(v + 0x304) != 0) {
            func_L01_00441FB8(m, 0x17, -1);
        } else {
            func_L01_00441FB8(m, 1, -1);
        }
    }
    *(u8 **)(v + 0x230) = func_L40_0053BEB0(*(s32 *)(v + 0x308), v + 0x220, -1, 1);
    if (*(u8 **)(v + 0x230) == 0) {
        *(s16 *)(v + 0x234) = 0;
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
            if (*(s16 *)(v + 0x234) == 1) {
                vu0_v4 *pa;
                if ((D_L40_002412AC & 0x1F) != (((s32)m >> 8) & 0x1F)) {
                    return;
                }
                pa = &a;
                if (func_003887C8(pa, pb) < 50.0f) {
                    if (func_003CE740(pa, pb, 0, m, 0) == 0 ||
                        (D_L40_0025BB18[0] != 0 && D_L40_0025BB18[0] == *(u8 **)(v + 0x230))) {
                        *(s16 *)(v + 0x234) = 1;
                    } else {
                        *(s16 *)(v + 0x234) = 0;
                    }
                } else {
                    *(s16 *)(v + 0x234) = 0;
                }
            } else {
                vu0_v4 *pa;
                if ((D_L40_002412AC & 7) != (((s32)m >> 8) & 7)) {
                    return;
                }
                pa = &a;
                if (func_003887C8(pa, pb) < 50.0f) {
                    if (func_003CE740(pa, pb, 0, m, 0) == 0 ||
                        (D_L40_0025BB18[0] != 0 && D_L40_0025BB18[0] == *(u8 **)(v + 0x230))) {
                        *(s16 *)(v + 0x234) = 1;
                    } else {
                        *(s16 *)(v + 0x234) = 0;
                    }
                } else {
                    *(s16 *)(v + 0x234) = 0;
                }
            }
        }
    }
}
/* localdecomp:end func_L40_003EE9D8 */
