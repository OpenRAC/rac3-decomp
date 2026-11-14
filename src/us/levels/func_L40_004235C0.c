#include "common.h"

/* NTSC-U counterpart of func_L40_00423E90 (src/levels/shared/L40_00423528.c): 300 -> 360 */
/* localdecomp:start func_L40_004235C0 */
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

extern G_00423E90 D_001A5E50;
extern u8 D_L40_003BFF60[];
extern u8 D_L40_003BFF61[];
extern u8 D_L40_003AA180[];
extern u8 D_L40_003AA181[];
__asm__(".extern D_L40_00248048, 16");
extern u32 D_L40_00248048;
extern Ent_00423E90 D_L40_003C3010[];

extern s32 func_L39_005F0D88(s32, s32, void *, s32);
extern void func_L39_005F1018(s32, void *);
extern s32 func_L40_00421C10(u8 *a0);
extern s32 func_L40_00421C70(u8 *a0);
extern s32 func_L40_00421C80(u8 *);
extern s32 func_L40_00421C90(u8 *a0);
extern void func_L39_00670BF8(void *, s32, s32);
extern s32 func_L39_00646268(u8 *, s32);
extern void func_L01_0044ECE0(s32, s32, s32);
extern void func_L40_003DA4A0(s32, u8 *);
extern s32 func_L39_00645FE0(void *, s32);
extern void func_L39_006460E8(void *, s32);

s32 func_L40_004235C0(u8 *a0, u8 *r) {
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
                *d++ = D_L40_003BFF60[m + ((k + i) & 7) * 255];
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
                *d++ = D_L40_003BFF60[m + ((k + i) & 7) * 255];
            }
            buf.w[0] ^= (u32)q;
            buf.w[1] ^= buf.w[0];
            x = buf.w[1];
        }
    }
    if ((x ^ 20) != 0) {
    if ((*(u32 *)r >> 28) == D_001A5E50.w8) {
        s32 h = func_L39_005F0D88(1, 0, a0, 0x1ABA);
        {
            Buf_00423E90 fx;
            fx.q = 0;
            fx.f[2] = 0.5f;
            func_L39_005F1018(h, &fx);
        }
    }
    if (func_L40_00421C10(a0)) {
        Ent_00423E90 *e;
        s32 i;
        func_L39_00670BF8(r + 0x1A40, s->w7C, 0);
        i = s->w7C;
        if (func_L39_00646268(r, i)) {
            e = D_L40_003C3010 + D_L40_003C3010[i].b21;
        } else {
            e = &D_L40_003C3010[i];
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
                *q = ++D_L40_003AA180[0];
            } else {
                tt = *q;
                *q = D_L40_003AA181[0];
                D_L40_003AA181[0] = tt;
            }
            key = ((u32 *)D_L40_003AA180)[((u32)hk * D_L40_00248048) % 418];
            k = ((u32)q - *q) & 7;
            buf.h[2] = vv;
            buf.w[0] = (u32)q ^ key;
            buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
            m = *q + 1;
            dp = buf.b;
            for (j = 0; j < 24; j += 3) {
                D_L40_003AA180[((k + j) & 7) * 209 + m] = *dp++;
            }
        }
        if (r[0x1A14] != 0) {
            Ent_00423E90 *e2;
            i = s->w7C;
            if (func_L39_00646268(r, i)) {
                e2 = D_L40_003C3010 + D_L40_003C3010[i].b21;
            } else {
                e2 = &D_L40_003C3010[i];
            }
            func_L01_0044ECE0(e2->h0, -1, r[0x24C9]);
        }
    } else if (func_L40_00421C70(a0)) {
        Ent_00423E90 *e;
        s32 i;
        func_L39_00670BF8(r + 0x1A40, s->w80, 0);
        i = s->w80;
        if (func_L39_00646268(r, i)) {
            e = D_L40_003C3010 + D_L40_003C3010[i].b21;
        } else {
            e = &D_L40_003C3010[i];
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
                *q = ++D_L40_003AA180[0];
            } else {
                tt = *q;
                *q = D_L40_003AA181[0];
                D_L40_003AA181[0] = tt;
            }
            key = ((u32 *)D_L40_003AA180)[((u32)hk * D_L40_00248048) % 418];
            k = ((u32)q - *q) & 7;
            buf.h[2] = vv;
            buf.w[0] = (u32)q ^ key;
            buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
            m = *q + 1;
            dp = buf.b;
            for (j = 0; j < 24; j += 3) {
                D_L40_003AA180[((k + j) & 7) * 209 + m] = *dp++;
            }
        }
        if (r[0x1A14] != 0) {
            Ent_00423E90 *e2;
            i = s->w80;
            if (func_L39_00646268(r, i)) {
                e2 = D_L40_003C3010 + D_L40_003C3010[i].b21;
            } else {
                e2 = &D_L40_003C3010[i];
            }
            func_L01_0044ECE0(e2->h0, -1, r[0x24C9]);
        }
    } else if (func_L40_00421C80(a0)) {
        if (s->w78 != 0) {
            func_L40_003DA4A0(s->w78, r);
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
                    *d++ = D_L40_003BFF60[m + ((k + i) & 7) * 255];
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
                *q = ++D_L40_003BFF60[0];
            } else {
                tt = *q;
                *q = D_L40_003BFF61[0];
                D_L40_003BFF61[0] = tt;
            }
            key = ((u32 *)D_L40_003BFF60)[((u32)hk * D_L40_00248048) % 510];
            k = ((u32)q - *q) & 7;
            buf.w[0] = (u32)q ^ key;
            buf.f[1] = g;
            buf.w[1] ^= key;
            m = *q + 1;
            d = buf.b;
            for (i = 0; i < 40; i += 5) {
                D_L40_003BFF60[m + ((k + i) & 7) * 255] = *d++;
            }
        }
        if (r[0x1A14] != 0) {
            *(s32 *)(r + 0x2514) = 360;
            if (func_L39_00645FE0(r, 15) == 0) {
                func_L39_006460E8(r, 15);
            } else {
                func_L01_0044ECE0(0x1250, -1, r[0x24C9]);
            }
        }
    } else {
        func_L40_00421C90(a0);
    }
    return 1;
    }
    }
    }
    return 0;
}
/* localdecomp:end func_L40_004235C0 */
