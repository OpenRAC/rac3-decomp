#include "common.h"

/* NTSC-U counterpart of func_L39_005DF8F8 (src/levels/shared/L39_005DF060.c) */
extern void func_L01_00512AB0(int, int, int);
extern void func_L01_00512AB0(s32, s32, s32);
extern void func_L39_005DC830(void);
extern s32 func_0037DF98(s32);
extern void func_L01_00512AB0(s32, s32, s32);
extern s32 func_L01_00512FE8(s32, s32);
extern s32 func_L01_005130C8(s32, s32);
extern s32 func_L01_00512480(s32, f32, f32);
extern void func_L39_005DC830(void);
typedef struct B_005DF510 B_005DF510;
typedef struct { void *f0; s32 f4, f8, fC, f10; B_005DF510 *f14; } A_005DF510;
struct B_005DF510 { void *f0; s32 f4, f8, fC, f10, f14; B_005DF510 *f18; };
extern u8 *D_L39_002417C0;

/* localdecomp:start func_L39_005DD350 */
typedef s32 (*Fn3_005DF8F8)(s32, s32, s32);
typedef union { u32 w[2]; u16 h[4]; u8 b[8]; } Buf_005DF8F8;

extern s32 D_001D81C0_sda[2];
__asm__(".extern D_001D81C0_sda, 8");
extern u8 D_001D81D0_sda[8];
__asm__(".extern D_001D81D0_sda, 8");
extern char D_001D81E0_sda_005DD350[4];
__asm__(".extern D_001D81E0_sda_005DD350, 4");
extern u8 D_L39_0024C5E0_005DD350[] __attribute__((section(".sdata")));
extern u8 D_L39_004998A0[];
extern char D_L39_00243A68[];
extern char D_L39_00243A70[];
extern char D_L39_002B5AB0_005DD350[][64];
extern char D_L39_002B5BB0[][10];
extern char D_L39_002B5C50[][10];
extern s32 *D_L39_002412A0;
__asm__(".extern D_L39_002412A0, 16");

extern s32 func_L01_00513698(void);
extern s32 func_L39_0060DD90(void *);
extern s32 func_L39_005DDD68(s32);
extern u8 *func_L39_006197C0(s32);
extern s32 func_0037DF98(s32);
extern s32 func_L01_00512FE8(s32, s32);
extern s32 func_L01_00512480(s32, f32, f32);
extern s32 func_L01_00513548(s32, f32, f32);
extern s32 func_L01_005130C8(s32, s32);
extern s32 func_L39_00669E80(s32);
extern s32 func_00120048(char *, char *, ...);
extern s32 func_001321C8(f32);

void func_L39_005DD350(void) {
    Buf_005DF8F8 buf;
    A_005DF510 arr[8];
    B_005DF510 scratch[8];
    s32 pl;
    s32 mode = 0;
    u8 *g;
    s32 n;
    s32 cnt = 0;
    s32 i = 0;
    f32 y;
    f32 sub;
    f32 z;
    f32 dy;
    B_005DF510 *node = 0;

    pl = func_L01_00513698();
    if (D_001D81C0_sda[pl] != 0) {
        D_001D81C0_sda[pl]--;
    } else {
        func_L39_005DC830();
        D_001D81D0_sda[pl] = 1;
    }
    if (D_001D81D0_sda[pl] != 0) {
        return;
    }
    mode = func_L39_0060DD90((void *)func_L39_005DDD68(pl));
    if (mode != 1) {
        return;
    }
    g = func_L39_006197C0(pl);
    if (D_L39_002417C0 != 0) {
        s32 t = *(s32 *)(D_L39_002417C0 + 0x180);
        if (t == 2) {
            func_L01_00512FE8(0x60006, func_0037DF98(0x1336));
            func_L01_00512FE8(0x60007, func_0037DF98(0x1337));
        } else if (t == mode) {
            func_L01_00512FE8(0x60006, func_0037DF98(0x1B73));
            func_L01_00512FE8(0x60007, func_0037DF98(0x1B74));
        }
    }
    if (D_L39_0024C5E0_005DD350[pl] != 0) {
        u32 x;
        {
            u8 *q = g + 0x19E4;
            s32 k, m, ii, nn;
            u8 *d;
            if (*q == 0) {
                x = 0;
            } else {
                nn = *q;
                k = ((u32)q - nn) & 7;
                m = nn + 1;
                d = buf.b;
                for (ii = 0; ii < 40; ii += 5) {
                    *d++ = D_L39_004998A0[m + ((k + ii) & 7) * 255];
                }
                buf.w[0] ^= (u32)q;
                buf.w[1] ^= buf.w[0];
                x = buf.w[1];
            }
        }
        if ((x ^ 0x90) == 0) {
            u16 v;
            ((Fn3_005DF8F8)func_L01_00512AB0)(0x60038, 1, 1);
            {
                u8 *q = g + 0x31C;
                s32 k, m, ii, nn;
                u32 a, b;
                u8 *d;
                if (*q == 0) {
                    v = 0;
                } else {
                    nn = *q;
                    k = ((u32)q - nn) & 7;
                    m = nn + 1;
                    d = buf.b;
                    for (ii = 0; ii < 24; ii += 3) {
                        *d++ = D_L39_004998A0[m + ((k + ii) & 7) * 255];
                    }
                    a = buf.w[0] ^ (u32)q;
                    b = buf.w[1] ^ a;
                    buf.w[0] = a;
                    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
                    v = buf.h[2];
                }
            }
            if ((s16)v <= 0) {
                func_L01_00512FE8(0x60038, func_0037DF98(0x12A5));
                { s32 d = *D_L39_002412A0; if (d >= 3) func_L01_00513548(0x60038, 0.6f, 0.6f); else if (d >= 2) func_L01_00513548(0x60038, 0.8f, 0.8f); else func_L01_00513548(0x60038, 1.0f, 1.0f); }
            } else {
                s32 r;
                char *out;
                {
                    u8 *q = g + 0x31C;
                    s32 k, m, ii, nn;
                    u32 a, b;
                    u8 *d;
                    if (*q == 0) {
                        v = 0;
                    } else {
                        nn = *q;
                        k = ((u32)q - nn) & 7;
                        m = nn + 1;
                        d = buf.b;
                        for (ii = 0; ii < 24; ii += 3) {
                            *d++ = D_L39_004998A0[m + ((k + ii) & 7) * 255];
                        }
                        a = buf.w[0] ^ (u32)q;
                        b = buf.w[1] ^ a;
                        buf.w[0] = a;
                        buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
                        v = buf.h[2];
                    }
                }
                out = D_L39_002B5AB0_005DD350[pl];
                r = func_001321C8((f32)(s16)v / 60.0f);
                func_00120048(out, D_L39_00243A68, r, func_0037DF98(0x12BD));
                func_L01_00512FE8(0x60038, (s32)out);
                { s32 d = *D_L39_002412A0; if (d >= 3) func_L01_00513548(0x60038, 0.6f, 0.6f); else if (d >= 2) func_L01_00513548(0x60038, 0.8f, 0.8f); else func_L01_00513548(0x60038, 1.0f, 1.0f); }
            }
        } else {
            ((Fn3_005DF8F8)func_L01_00512AB0)(0x60038, 1, 0);
        }
    } else {
        ((Fn3_005DF8F8)func_L01_00512AB0)(0x60038, 1, 0);
    }

    func_L01_00512480(0x60005, 0.28f, 0.25f);
    y = 0.06f;
    n = 0;
    func_L01_00512480(0x60006, 0.62f, 0.25f);
    sub = 0.0f;
    func_L01_00512480(0x60007, 0.83f, 0.25f);
    ((Fn3_005DF8F8)func_L01_00512AB0)(0x60005, 1, 1);
    ((Fn3_005DF8F8)func_L01_00512AB0)(0x60006, 1, 1);
    ((Fn3_005DF8F8)func_L01_00512AB0)(0x60007, 1, 1);
    cnt = func_L39_005DCF68(arr, scratch);
    if (((s8 *)D_L39_002417C0)[0x19D] != 0) {
        sub = 0.13f;
    }
    for (i = 0; i < cnt; i++) {
        node = arr[i].f14;
        if (((s8 *)D_L39_002417C0)[0x19D] != 0) {
            s32 a = 0x60008 + n;
            s32 b = 0x60018 + n;
            func_00120048(D_L39_002B5BB0[n], D_001D81E0_sda_005DD350, arr[i].f4);
            z = y + 0.25f;
            func_00120048(D_L39_002B5C50[n], D_001D81E0_sda_005DD350, arr[i].f8);
            func_L01_00512FE8(a, (s32)arr[i].f0);
            func_L01_00512FE8(b, (s32)D_L39_002B5BB0[n]);
            func_L01_00512FE8(0x60028 + n, (s32)D_L39_002B5C50[n]);
            ((Fn3_005DF8F8)func_L01_00512AB0)(a, 0x200, 1);
            ((Fn3_005DF8F8)func_L01_00512AB0)(a, 0x400, 0);
            func_L01_00512480(a, 0.28f - sub, z);
            func_L01_00512480(b, 0.62f, z);
            func_L01_00512480(0x60028 + n, 0.83f, z);
            ((Fn3_005DF8F8)func_L01_00512AB0)(a, 1, 1);
            ((Fn3_005DF8F8)func_L01_00512AB0)(b, 1, 1);
            ((Fn3_005DF8F8)func_L01_00512AB0)(0x60028 + n, 1, 1);
            {
                s32 col = func_L39_00669E80(arr[i].f10);
                func_L01_005130C8(a, col);
                func_L01_005130C8(b, col);
                func_L01_005130C8(0x60028 + n, col);
            }
            dy = 0.04f;
            y += dy;
            n++;
        }
        for (; node != 0; node = node->f18) {
            s32 a = 0x60008 + n;
            s32 b = 0x60018 + n;
            s32 c = 0x60028 + n;
            func_00120048(D_L39_002B5BB0[n], D_L39_00243A70, node->f4);
            z = y + 0.25f;
            func_00120048(D_L39_002B5BB0[n + 16], D_L39_00243A70, node->f8);
            func_L01_00512FE8(a, (s32)node->f0);
            func_L01_00512FE8(b, (s32)D_L39_002B5BB0[n]);
            func_L01_00512FE8(c, (s32)D_L39_002B5BB0[n + 16]);
            func_L01_00512480(a, 0.28f, z);
            func_L01_00512480(b, 0.62f, z);
            func_L01_00512480(c, 0.83f, z);
            ((Fn3_005DF8F8)func_L01_00512AB0)(a, 0x200, 1);
            ((Fn3_005DF8F8)func_L01_00512AB0)(a, 0x400, 1);
            ((Fn3_005DF8F8)func_L01_00512AB0)(a, 1, 1);
            ((Fn3_005DF8F8)func_L01_00512AB0)(b, 1, 1);
            ((Fn3_005DF8F8)func_L01_00512AB0)(c, 1, 1);
            if (node->f10 == *(s32 *)(g + 0x2544)) {
                func_L01_005130C8(a, 0x8000FF00);
                func_L01_005130C8(b, 0x8000FF00);
                func_L01_005130C8(c, 0x8000FF00);
            } else {
                func_L01_005130C8(a, 0x8066CCFF);
                func_L01_005130C8(b, 0x8066CCFF);
                func_L01_005130C8(c, 0x8066CCFF);
            }
            dy = 0.04f;
            y += dy;
            n++;
        }
    }
    for (i = n; i < 16; i++) {
        ((Fn3_005DF8F8)func_L01_00512AB0)(0x60008 + i, 1, 0);
        ((Fn3_005DF8F8)func_L01_00512AB0)(0x60018 + i, 1, 0);
        ((Fn3_005DF8F8)func_L01_00512AB0)(0x60028 + i, 1, 0);
    }
}
/* localdecomp:end func_L39_005DD350 */
