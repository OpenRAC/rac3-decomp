#include "common.h"

/* declared by functions of L39_00621600.c, which this file was cut from */
extern u8 D_L39_004997E0[];

/* localdecomp:start func_L39_006217C0 */
/* log: v1 (shared locals across the three decode blocks) 127 diff, of which ~1 nop before div.s
   (needs config/levels/divs_nops.txt row, not mine to add). v2: per-block locals. */
typedef union Buf_006217C0 {
    u8 b[8];
    u32 w[2];
} Buf_006217C0;

typedef int u128_6217C0 __attribute__((mode(TI)));
extern u8 D_L39_004997E0[];
extern s32 D_L39_0025F758 __attribute__((section(".data")));
extern u128_6217C0 D_L39_0025F760[];
extern s32 func_L39_00631A20(u8 *, s32, f32 *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern s32 func_L39_00634E58(u8 *, s32, f32, f32);
extern s32 func_L39_005B8928(s32);
extern s32 func_L39_006212E8(void *);

void func_L39_006217C0(u8 *g) {
    f32 ang;
    f32 tmp;
    f32 f2;
    f32 lim;
    f32 sc;
    s32 sel;
    s32 x1;
    s32 v;

    g[0x1A08] = 0;
    {
        Buf_006217C0 buf;
        u8 *p = g + 0x1A17;
        if (*p == 0) {
            x1 = 0;
        } else {
            s32 n = *p;
            s32 m = n + 1;
            s32 k = ((s32)p - n) & 7;
            u8 *d = buf.b;
            s32 i;
            u32 b;
            for (i = 0; i < 24; i += 3) {
                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            buf.w[0] ^= (u32)p;
            b = buf.w[1] ^ buf.w[0];
            buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
            x1 = buf.b[4];
        }
    }
    if (x1 == 0) return;
    if (*(s16 *)(g + 0x348) != 0) return;
    if (g[0x1A0B] != 0) return;
    ang = 0.0f;
    tmp = ang;
    func_L39_00631A20(g, (*(u8 **)(g + 0x2524))[0x43], &tmp);
    if (tmp != ang) return;
    lim = g[0x1A08] ? 1.5999999f : 1.3f;
    sc = g[0x1A07] ? 0.7f : 0.57f;
    if (*(s32 *)(g + 0x1310) == 2) {
        ang = func_0038DAB8(*(f32 *)(g + 0x1200), 0.17453292f);
        if (ang > 0.34906584f) ang = 0.34906584f;
        if (ang < -1.3962634f) ang = -1.3962634f;
        if (g[0x1A05] != 0) ang = func_0038DAB8(ang, -0.15707964f);
    } else {
        if (func_L39_00634E58(g, 0, sc, lim)) {
            if (!(g[0x1A07] && D_L39_0025F758 && func_L39_005B8928(D_L39_0025F758))) {
                ang = func_0038CF00(g + 0xA0, D_L39_0025F760);
                ang = (1.3f - (ang - *(f32 *)(g + 0x1F4))) / 1.3f * 1.25f * -1.2217305f;
                if (ang > -0.5235988f) ang = -0.5235988f;
                if (ang < -1.2217305f) ang = -1.2217305f;
            }
            g[0x1A08] = 1;
        }
        if (*(s32 *)(g + 0x1310) == 1) {
            f32 lo = -1.3962634f;
            f32 hi = 0.34906584f;
            if (g[0x1A08] == 0 || *(f32 *)(g + 0x1200) < ang) {
                ang = *(f32 *)(g + 0x1200);
                if (ang > hi) {
                    ang = hi;
                } else if (ang < lo) {
                    ang = lo;
                }
                g[0x1A08] = 0;
                v = func_L39_006212E8(g);
                if (g[0x1A05] != 0) {
                    ang = func_0038DAB8(ang, -0.1134464f);
                } else {
                    s32 x2;
                    u8 *p = g + 0x19E6;
                    if (*p == 0) {
                        x2 = 0;
                    } else {
                        Buf_006217C0 buf;
                        s32 n = *p;
                        s32 m = n + 1;
                        s32 k = ((s32)p - n) & 7;
                        u8 *d = buf.b;
                        s32 i;
                        for (i = 0; i < 40; i += 5) {
                            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                        }
                        buf.w[0] ^= (u32)p;
                        buf.w[1] ^= buf.w[0];
                        x2 = buf.w[1];
                    }
                    if (x2 == 0) {
                        if ((u32)(v - 3) < 2 || v == 0x13 || v == 0x12) {
                            ang = func_0038DAB8(ang, 0.14835298f);
                        }
                    }
                }
            }
        }
    }
    if (ang == 0.0f) return;
    f2 = 0.0f;
    sel = -1;
    if (*(s32 *)(g + 0x474) == 2) sel = *(s32 *)(g + 0x478);
    if (sel == 4) {
        f2 = ang * -0.00997331f;
        if (f2 > 0.6981317f) f2 = 0.6981317f;
    }
    if (*(s32 *)(g + 0x1310) == 2) {
        *(f32 *)(g + 0xE34) = 0.43200004f;
        *(f32 *)(g + 0xE38) = 1.296f;
    } else {
        *(f32 *)(g + 0xE34) = 0.072000004f;
        *(f32 *)(g + 0xE38) = 0.43200004f;
    }
    *(f32 *)(g + 0xDF4) = ang;
    *(f32 *)(g + 0xDF0) = f2;
    {
        s32 x3;
        Buf_006217C0 buf;
        u8 *p = g + 0x1A17;
        if (*p == 0) {
            x3 = 0;
        } else {
            s32 n = *p;
            s32 m = n + 1;
            s32 k = ((s32)p - n) & 7;
            u8 *d = buf.b;
            s32 i;
            u32 b;
            for (i = 0; i < 24; i += 3) {
                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            buf.w[0] ^= (u32)p;
            b = buf.w[1] ^ buf.w[0];
            buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
            x3 = buf.b[4];
        }
        if ((x3 ^ 2) == 0) {
            *(f32 *)(g + 0xD84) = *(f32 *)(g + 0xE34);
            *(f32 *)(g + 0xD88) = *(f32 *)(g + 0xE38);
            *(f32 *)(g + 0xD44) = *(f32 *)(g + 0xDF4);
            *(f32 *)(g + 0xD40) = *(f32 *)(g + 0xDF0);
        }
    }
}
/* localdecomp:end func_L39_006217C0 */
