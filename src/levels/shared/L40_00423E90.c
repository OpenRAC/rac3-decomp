#include "common.h"

/* localdecomp:start func_L40_00423E90 */
typedef int Q_00423E90 __attribute__((mode(TI)));

typedef union Buf_00423E90 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
    f32 f[4];
    Q_00423E90 q;
} Buf_00423E90;

typedef struct Ent_00423E90 {
    s16 h0;
    u8 pad2[0x1E - 0x2];
    s16 h1E;
    u8 pad20;
    s8 b21;
    u8 pad22[0x80 - 0x22];
} Ent_00423E90;

typedef struct V_00423E90 {
    u8 pad0[0x78];
    s32 w78;
    s32 w7C;
    s32 w80;
} V_00423E90;

typedef struct G_00423E90 {
    u8 pad0[8];
    u32 w8;
} G_00423E90;

extern G_00423E90 D_001A5CD0;
extern u8 D_L40_003BFE20[];
extern u8 D_L40_003BFE21[];
extern u8 D_L40_003AA040[];
extern u8 D_L40_003AA041[];
__asm__(".extern D_L40_00247EC8, 16");
extern u32 D_L40_00247EC8;
extern Ent_00423E90 D_L40_003C2ED0[];

extern s32 func_L39_005F3488(s32, s32, void *, s32);
extern s32 func_L39_005F3718(s32, void *);
extern s32 func_L40_004224E0(u8 *a0);
extern s32 func_L40_00422540(u8 *a0);
extern s32 func_L40_00422550(u8 *);
extern s32 func_L40_00422560(u8 *a0);
extern void func_L39_00673540(void *, s32, s32);
extern s32 func_L39_00648AE0(u8 *, s32);
extern void func_L01_00451F60(s32, s32, s32);
extern void func_L40_003DA6A8(s32, u8 *);
extern s32 func_L39_00648840(void *, s32);
extern void func_L39_00648960(void *, s32);

s32 func_L40_00423E90(u8 *a0, u8 *r) {
    V_00423E90 *s = *(V_00423E90 **)(a0 + 0x68);
    f32 f;
    f32 g;
    u32 x;
    s16 ok;

    if (r != 0) {
    f32 zero = 0.0f;
    {
        u8 *q = r + 0x2476;
        Buf_00423E90 buf;
        s32 n, k, m, i;
        u8 *d;
        if (*q == 0) {
            f = zero;
        } else {
            n = *q;
            k = ((u32)q - n) & 7;
            m = n + 1;
            d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
            }
            buf.w[0] ^= (u32)q;
            buf.w[1] ^= buf.w[0];
            f = buf.f[1];
        }
    }
    ok = zero < f;
    if ((u8)ok) {
    {
        u8 *q = r + 0x19E6;
        Buf_00423E90 buf;
        s32 n, k, m, i;
        u8 *d;
        if (*q == 0) {
            x = 0;
        } else {
            n = *q;
            k = ((u32)q - n) & 7;
            m = n + 1;
            d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
            }
            buf.w[0] ^= (u32)q;
            buf.w[1] ^= buf.w[0];
            x = buf.w[1];
        }
    }
    if ((x ^ 20) != 0) {
    if ((*(u32 *)r >> 28) == D_001A5CD0.w8) {
        s32 h = func_L39_005F3488(1, 0, a0, 0x1ABA);
        {
            Buf_00423E90 fx;
            fx.q = 0;
            fx.f[2] = 0.5f;
            func_L39_005F3718(h, &fx);
        }
    }
    if (func_L40_004224E0(a0)) {
        Ent_00423E90 *e;
        s32 i;
        func_L39_00673540(r + 0x1A40, s->w7C, 0);
        i = s->w7C;
        if (func_L39_00648AE0(r, i)) {
            e = D_L40_003C2ED0 + D_L40_003C2ED0[i].b21;
        } else {
            e = &D_L40_003C2ED0[i];
        }
        {
            u8 *q;
            s16 vv;
            u8 *hk;
            Buf_00423E90 buf;
            u32 key;
            s32 k, m, j, tt;
            u8 *dp;

            q = (u8 *)(s->w7C + (u32)r); q += 0x1A52;
            vv = e->h1E;
            hk = q;
            if (*q == 0) {
                *q = ++D_L40_003AA040[0];
            } else {
                tt = *q;
                *q = D_L40_003AA041[0];
                D_L40_003AA041[0] = tt;
            }
            key = ((u32 *)D_L40_003AA040)[((u32)hk * D_L40_00247EC8) % 418];
            k = ((u32)q - *q) & 7;
            buf.h[2] = vv;
            buf.w[0] = (u32)q ^ key;
            buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
            m = *q + 1;
            dp = buf.b;
            for (j = 0; j < 24; j += 3) {
                D_L40_003AA040[((k + j) & 7) * 209 + m] = *dp++;
            }
        }
        if (r[0x1A14] != 0) {
            Ent_00423E90 *e2;
            i = s->w7C;
            if (func_L39_00648AE0(r, i)) {
                e2 = D_L40_003C2ED0 + D_L40_003C2ED0[i].b21;
            } else {
                e2 = &D_L40_003C2ED0[i];
            }
            func_L01_00451F60(e2->h0, -1, r[0x24C9]);
        }
    } else if (func_L40_00422540(a0)) {
        Ent_00423E90 *e;
        s32 i;
        func_L39_00673540(r + 0x1A40, s->w80, 0);
        i = s->w80;
        if (func_L39_00648AE0(r, i)) {
            e = D_L40_003C2ED0 + D_L40_003C2ED0[i].b21;
        } else {
            e = &D_L40_003C2ED0[i];
        }
        {
            u8 *q;
            s16 vv;
            u8 *hk;
            Buf_00423E90 buf;
            u32 key;
            s32 k, m, j, tt;
            u8 *dp;

            q = (u8 *)(s->w80 + (u32)r); q += 0x1A52;
            vv = e->h1E;
            hk = q;
            if (*q == 0) {
                *q = ++D_L40_003AA040[0];
            } else {
                tt = *q;
                *q = D_L40_003AA041[0];
                D_L40_003AA041[0] = tt;
            }
            key = ((u32 *)D_L40_003AA040)[((u32)hk * D_L40_00247EC8) % 418];
            k = ((u32)q - *q) & 7;
            buf.h[2] = vv;
            buf.w[0] = (u32)q ^ key;
            buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
            m = *q + 1;
            dp = buf.b;
            for (j = 0; j < 24; j += 3) {
                D_L40_003AA040[((k + j) & 7) * 209 + m] = *dp++;
            }
        }
        if (r[0x1A14] != 0) {
            Ent_00423E90 *e2;
            i = s->w80;
            if (func_L39_00648AE0(r, i)) {
                e2 = D_L40_003C2ED0 + D_L40_003C2ED0[i].b21;
            } else {
                e2 = &D_L40_003C2ED0[i];
            }
            func_L01_00451F60(e2->h0, -1, r[0x24C9]);
        }
    } else if (func_L40_00422550(a0)) {
        if (s->w78 != 0) {
            func_L40_003DA6A8(s->w78, r);
            s->w78 = 0;
        }
        {
            u8 *q = r + 0x2554;
            Buf_00423E90 buf;
            s32 n, k, m, i;
            u8 *d;
            if (*q == 0) {
                g = 0.0f;
            } else {
                n = *q;
                k = ((u32)q - n) & 7;
                m = n + 1;
                d = buf.b;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
                }
                buf.w[0] ^= (u32)q;
                buf.w[1] ^= buf.w[0];
                g = buf.f[1];
            }
        }
        {
            u8 *q = r + 0x2476;
            u8 *hk = q;
            Buf_00423E90 buf;
            u32 key;
            s32 k, m, i, tt;
            u8 *d;
            if (*q == 0) {
                *q = ++D_L40_003BFE20[0];
            } else {
                tt = *q;
                *q = D_L40_003BFE21[0];
                D_L40_003BFE21[0] = tt;
            }
            key = ((u32 *)D_L40_003BFE20)[((u32)hk * D_L40_00247EC8) % 510];
            k = ((u32)q - *q) & 7;
            buf.w[0] = (u32)q ^ key;
            buf.f[1] = g;
            buf.w[1] ^= key;
            m = *q + 1;
            d = buf.b;
            for (i = 0; i < 40; i += 5) {
                D_L40_003BFE20[m + ((k + i) & 7) * 255] = *d++;
            }
        }
        if (r[0x1A14] != 0) {
            *(s32 *)(r + 0x2514) = 300;
            if (func_L39_00648840(r, 15) == 0) {
                func_L39_00648960(r, 15);
            } else {
                func_L01_00451F60(0x1250, -1, r[0x24C9]);
            }
        }
    } else {
        func_L40_00422560(a0);
    }
    return 1;
    }
    }
    }
    return 0;
}
/* localdecomp:end func_L40_00423E90 */


/* localdecomp:start func_L40_00424540 */
#include "vu0.h"

extern s32 D_L40_0024112C;
extern s32 D_L40_00249848;
extern s32 D_L40_0024984C;
extern s32 D_L40_00248380;
extern s32 D_L40_00247710;
__asm__(".extern D_L40_00247710, 4");
extern s32 D_L40_00247714;
__asm__(".extern D_L40_00247714, 4");

struct L40_00424540_obj {
    u8 pad[0xAA];
    s16 type;
};

void func_L40_00424540(u8 *obj, s32 unused, u8 *src) {
    extern s32 func_L39_005F33E0(s32, s32, void *);
    extern u8 *func_L01_004653B8(void *, s32, s32, f32, f32, f32, f32, f32);
    extern f32 func_L01_00448248(s32 *, s32, s32);
    extern void func_L01_00451FE0(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    vu0_v4 pos;
    vu0_v4 dir;
    vu0_v4 zero;
    s32 i;
    s32 c;
    s32 mask;
    s32 d;
    s32 r;

    if (abs_asm(D_L40_0024112C - D_L40_00249848) >= 2) {
        r = func_L39_005F33E0(0, 0, obj);
        *(vu0_q *)&dir = 0;
        dir.z = 0.5f;
        func_L39_005F3718(r, &dir);
        D_L40_00249848 = D_L40_0024112C;
    }
    if (abs_asm(D_L40_0024112C - D_L40_0024984C) >= 2) {
        D_L40_0024984C = D_L40_0024112C;
    }
    *(vu0_q *)&pos = *(vu0_q *)(obj + 0x10);
    pos.z = pos.z + 0.3f;
    func_L01_004653B8(&pos, 1, 0x40808080, 0.3f, 1.01f, 1.075f, 0.05f, 50000.0f);
    for (i = 0; i < 5; i++) {
        func_L01_004653B8(&pos, 1, 0x40808080, 0.3f, 1.01f, 1.07f, 0.05f, 50000.0f);
    }
    if (src != 0) {
        *(vu0_q *)&dir = *(vu0_q *)(src + 0x10);
    } else {
        qzero(&dir);
        dir.z = 1.0f;
    }
    d = abs_asm(D_L40_0024112C - D_L40_00247710);
    if (d >= 0xC9) {
        D_L40_00247710 = D_L40_0024112C;
        D_L40_00247714 = 0;
    } else if (D_L40_0024112C != D_L40_00247710) {
        func_L01_00448248(&D_L40_00247714, 0, d >> 2);
        D_L40_00247710 = D_L40_0024112C;
    }
    if (D_L40_00248380 >= 0xFB && D_L40_00247714 < 5) {
        c = 4;
    } else if (D_L40_00248380 >= 0xC9 && D_L40_00247714 < 10) {
        c = 3;
    } else if (D_L40_00248380 >= 0x97 && D_L40_00247714 < 15) {
        c = 2;
    } else {
        c = 0;
        if (D_L40_00248380 >= 0x65) {
            c = D_L40_00247714 < 20;
        }
    }
    if (c != 0) {
        mask = 0;
        D_L40_00247714 = D_L40_00247714 + c;
        switch (((struct L40_00424540_obj *)obj)->type) {
        case 0x1FF:
        case 0x1ABA:
        case 0x1ABB:
        case 0x1ABC:
        case 0x1ABD:
        case 0x1ABE:
        case 0x1ABF:
        case 0x1AC0:
        case 0x1AC1:
        case 0x1AF2:
        case 0x1B09:
        case 0x1B0A:
        case 0x1B0B:
        case 0x1B4B:
            switch (c) {
            case 1:
                mask = 1;
                break;
            case 2:
                mask = 5;
                break;
            case 3:
            default:
                mask = 0x25;
                break;
            }
            break;
        case 0x1F5:
        case 0x200:
            mask = (1 << (c - 1)) - 1;
            if (!(mask < 0x10)) {
                mask = 0xF;
            }
            break;
        }
        if (mask != 0) {
            qzero(&zero);
            func_L01_00451FE0(obj, mask, (u8 *)&zero, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        }
    }
    *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 1;
    func_L01_004450F0(obj, 3, -1);
    *(s32 *)(obj + 0x98) = 0;
    obj[0xBC] = 0xC;
}
/* localdecomp:end func_L40_00424540 */
