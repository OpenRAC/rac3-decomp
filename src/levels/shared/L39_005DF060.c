#include "common.h"

/* declared by functions of L39_005DED10.c, which this file was cut from */
extern void func_L01_00516AA0(int, int, int);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L39_005DEDD8(void);

/* localdecomp:start func_L39_005DF060 */
/* log: callee alias func_L01_004D2110_005DF060 (stub is another copy in levels 40+). */
/* log: id local = 10 diff (s0 for temp); inline i + 0x6xxxx at each use = MATCH with --as ps2as (float constants inline, file needs @ps2as) */
extern u8 D_001D821C_sda;
extern void func_L01_004D2110_005DF060(s32);
extern void func_L01_00484A80(s32);
extern s32 func_003B5060(s32);
extern s32 func_003E5360(s32);
extern s32 func_00381FF0(s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern void func_003E6FF0(s32, s32);
extern void func_L39_005DEDD8(void);
void func_L39_005DF060(s32 a0) {
    s32 i;
    s32 id;
    D_001D821C_sda = 1;
    func_L01_004D2110_005DF060(1);
    func_L01_00484A80(0x60000);
    func_003B5060(0x60001);
    func_003B5060(0x60002);
    func_003B5060(0x60003);
    func_003B5060(0x60004);

    func_003E5360(0x60005);
    func_L01_00516AA0(0x60005, 1, 0);
    func_L01_00516AA0(0x60005, 0x40, 1);
    func_L01_00516AA0(0x60005, 0x2000, 1);
    func_L01_00516FD8(0x60005, func_00381FF0(0x1332));
    func_L01_005170B8(0x60005, 0x8066CCFF);
    func_L01_00516470(0x60005, 0.28f, 0.25f);
    func_003E8630(0x60001, 0x60005);

    func_003E5360(0x60006);
    func_L01_00516AA0(0x60006, 1, 0);
    func_L01_00516AA0(0x60006, 0x40, 1);
    func_L01_00516AA0(0x60006, 0x2000, 1);
    func_L01_00516FD8(0x60006, func_00381FF0(0x1336));
    func_L01_005170B8(0x60006, 0x8066CCFF);
    func_L01_00516470(0x60006, 0.62f, 0.25f);
    func_003E8630(0x60001, 0x60006);

    func_003E5360(0x60007);
    func_L01_00516AA0(0x60007, 1, 0);
    func_L01_00516AA0(0x60007, 0x40, 1);
    func_L01_00516AA0(0x60007, 0x2000, 1);
    func_L01_00516FD8(0x60007, func_00381FF0(0x1337));
    func_L01_005170B8(0x60007, 0x8066CCFF);
    func_L01_00516470(0x60007, 0.83f, 0.25f);
    func_003E8630(0x60001, 0x60007);

    for (i = 0; i < 16; i++) {
        func_003E5360(i + 0x60008);
        func_L01_00516AA0(i + 0x60008, 1, 0);
        func_L01_00516AA0(i + 0x60008, 0x40, 1);
        func_L01_00516AA0(i + 0x60008, 0x2000, 1);
        func_L01_005170B8(i + 0x60008, 0x8066CCFF);
        func_003E8630(0x60002, i + 0x60008);

        func_003E5360(i + 0x60018);
        func_L01_00516AA0(i + 0x60018, 1, 0);
        func_L01_00516AA0(i + 0x60018, 0x40, 1);
        func_L01_00516AA0(i + 0x60018, 0x2000, 1);
        func_L01_005170B8(i + 0x60018, 0x8066CCFF);
        func_003E8630(0x60003, i + 0x60018);

        func_003E5360(i + 0x60028);
        func_L01_00516AA0(i + 0x60028, 1, 0);
        func_L01_00516AA0(i + 0x60028, 0x40, 1);
        func_L01_00516AA0(i + 0x60028, 0x2000, 1);
        func_L01_005170B8(i + 0x60028, 0x8066CCFF);
        func_003E8630(0x60004, i + 0x60028);
    }

    func_003E5360(0x60038);
    func_L01_00516AA0(0x60038, 1, 0);
    func_L01_00516AA0(0x60038, 0x40, 1);
    func_L01_00516FD8(0x60038, func_00381FF0(0x12A5));
    func_L01_005170B8(0x60038, 0x8066CCFF);
    func_L01_00516470(0x60038, 0.5f, 0.8438f);
    func_003E8630(0x60001, 0x60038);

    func_003E8630(0x60000, 0x60001);
    func_003E8630(0x60000, 0x60002);
    func_003E8630(0x60000, 0x60003);
    func_003E8630(0x60000, 0x60004);
    func_003E8348(0x18, 0x60000);
    func_003E6FF0(a0, 1);
    func_L39_005DEDD8();
    func_L01_004D2110_005DF060(0);
}
/* localdecomp:end func_L39_005DF060 */

/* localdecomp:start func_L39_005DF510 */
typedef struct B_005DF510 B_005DF510;
typedef struct { void *f0; s32 f4, f8, fC, f10; B_005DF510 *f14; } A_005DF510;
struct B_005DF510 { void *f0; s32 f4, f8, fC, f10, f14; B_005DF510 *f18; };
typedef struct {
    u8 pad0[0x18];
    s16 a[8][2];
    u8 pad1[0x10];
    u8 b[8];
    u8 c[8];
    u8 pad2[0x198 - 0x58];
    s16 d[8];
} T_005DF510;
extern u8 *D_L39_00241640;
__asm__(".extern D_L39_00241640, 16");
extern u8 *D_L39_0024CE20[] __attribute__((section(".sdata")));
extern T_005DF510 D_L39_00352940;
extern s32 func_L39_0066C7D8(s32);
s32 func_L39_005DF510(A_005DF510 *a, B_005DF510 *b) {
    u8 *p = D_L39_00241640;
    s32 flag = 0;
    s32 n = 0;
    s32 i, j, k, cnt;
    if (p != 0) {
        flag = *(s32 *)(p + 0x180) == 1;
    }
    for (i = 0; i < 8; i++) {
        if (D_L39_0024CE20[i] != 0) {
            b[n].f0 = p + i * 16;
            b[n].f18 = 0;
            if (flag) {
                b[n].f8 = D_L39_00352940.c[i];
                b[n].f4 = D_L39_00352940.b[i];
            } else {
                b[n].f8 = D_L39_00352940.a[i][1];
                b[n].f4 = D_L39_00352940.a[i][0] - D_L39_00352940.d[i];
            }
            b[n].f10 = i;
            b[n].f14 = *(s32 *)(D_L39_0024CE20[i] + 0x2548);
            b[n].fC = b[n].f4 - b[n].f8;
            n++;
        }
        a[i].f14 = 0;
        a[i].f10 = -1;
    }
    cnt = n;
    n = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < cnt; j++) {
            if (b[j].f14 == i) {
                B_005DF510 *q;
                if (a[n].f14 == 0) {
                    a[n].f0 = (void *)func_L39_0066C7D8(i);
                    a[n].f14 = &b[j];
                    a[n].f8 = b[j].f8;
                    a[n].f4 = b[j].f4;
                    a[n].fC = b[j].fC;
                    a[n].f10 = i;
                } else {
                    q = a[n].f14;
                    a[n].f8 += b[j].f8;
                    a[n].f4 += b[j].f4;
                    if (q->fC < b[j].fC) {
                        b[j].f18 = q;
                        a[n].f14 = &b[j];
                    } else {
                        for (; q->f18 != 0 && q->f18->fC >= b[j].fC; q = q->f18) ;
                        b[j].f18 = q->f18;
                        q->f18 = &b[j];
                    }
                }
            }
        }
        if (a[n].f14 != 0) {
            n++;
        }
    }
    for (i = 1; i < n; i++) {
        A_005DF510 t = a[i];
        k = i;
        while (k > 0 && (a[k - 1].f4 < t.f4 || (a[k - 1].f4 == t.f4 && t.f8 < a[k - 1].f8))) {
            a[k] = a[k - 1];
            k--;
        }
        if (k != i) {
            a[k] = t;
        }
    }
    return n;
}
/* localdecomp:end func_L39_005DF510 */

/* localdecomp:start func_L39_005DF8F8 */
typedef s32 (*Fn3_005DF8F8)(s32, s32, s32);
typedef union { u32 w[2]; u16 h[4]; u8 b[8]; } Buf_005DF8F8;

extern s32 D_001D8208_sda[2];
__asm__(".extern D_001D8208_sda, 8");
extern u8 D_001D8218_sda[8];
__asm__(".extern D_001D8218_sda, 8");
extern char D_001D8228_sda[4];
__asm__(".extern D_001D8228_sda, 4");
extern u8 D_L39_0024C4E0[] __attribute__((section(".sdata")));
extern u8 D_L39_004997E0[];
extern char D_L39_00243930[];
extern char D_L39_00243938[];
extern char D_L39_002B59B0[][64];
extern char D_L39_002B5AB0[][10];
extern char D_L39_002B5B50[][10];
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00241120, 16");

extern s32 func_L01_00517688(void);
extern s32 func_L39_00610490(void *);
extern s32 func_L39_005E0310(s32);
extern u8 *func_L39_0061BF38(s32);
extern s32 func_00381FF0(s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L39_0066C788(s32);
extern s32 func_00120048(char *, char *, ...);
extern s32 func_001321C8(f32);

void func_L39_005DF8F8(void) {
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

    pl = func_L01_00517688();
    if (D_001D8208_sda[pl] != 0) {
        D_001D8208_sda[pl]--;
    } else {
        func_L39_005DEDD8();
        D_001D8218_sda[pl] = 1;
    }
    if (D_001D8218_sda[pl] != 0) {
        return;
    }
    mode = func_L39_00610490((void *)func_L39_005E0310(pl));
    if (mode != 1) {
        return;
    }
    g = func_L39_0061BF38(pl);
    if (D_L39_00241640 != 0) {
        s32 t = *(s32 *)(D_L39_00241640 + 0x180);
        if (t == 2) {
            func_L01_00516FD8(0x60006, func_00381FF0(0x1336));
            func_L01_00516FD8(0x60007, func_00381FF0(0x1337));
        } else if (t == mode) {
            func_L01_00516FD8(0x60006, func_00381FF0(0x1B73));
            func_L01_00516FD8(0x60007, func_00381FF0(0x1B74));
        }
    }
    if (D_L39_0024C4E0[pl] != 0) {
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
                    *d++ = D_L39_004997E0[m + ((k + ii) & 7) * 255];
                }
                buf.w[0] ^= (u32)q;
                buf.w[1] ^= buf.w[0];
                x = buf.w[1];
            }
        }
        if ((x ^ 0x90) == 0) {
            u16 v;
            ((Fn3_005DF8F8)func_L01_00516AA0)(0x60038, 1, 1);
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
                        *d++ = D_L39_004997E0[m + ((k + ii) & 7) * 255];
                    }
                    a = buf.w[0] ^ (u32)q;
                    b = buf.w[1] ^ a;
                    buf.w[0] = a;
                    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
                    v = buf.h[2];
                }
            }
            if ((s16)v <= 0) {
                func_L01_00516FD8(0x60038, func_00381FF0(0x12A5));
                { s32 d = *D_L39_00241120; if (d >= 3) func_L01_00517538(0x60038, 0.6f, 0.6f); else if (d >= 2) func_L01_00517538(0x60038, 0.8f, 0.8f); else func_L01_00517538(0x60038, 1.0f, 1.0f); }
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
                            *d++ = D_L39_004997E0[m + ((k + ii) & 7) * 255];
                        }
                        a = buf.w[0] ^ (u32)q;
                        b = buf.w[1] ^ a;
                        buf.w[0] = a;
                        buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
                        v = buf.h[2];
                    }
                }
                out = D_L39_002B59B0[pl];
                r = func_001321C8((f32)(s16)v / 50.0f);
                func_00120048(out, D_L39_00243930, r, func_00381FF0(0x12BD));
                func_L01_00516FD8(0x60038, (s32)out);
                { s32 d = *D_L39_00241120; if (d >= 3) func_L01_00517538(0x60038, 0.6f, 0.6f); else if (d >= 2) func_L01_00517538(0x60038, 0.8f, 0.8f); else func_L01_00517538(0x60038, 1.0f, 1.0f); }
            }
        } else {
            ((Fn3_005DF8F8)func_L01_00516AA0)(0x60038, 1, 0);
        }
    } else {
        ((Fn3_005DF8F8)func_L01_00516AA0)(0x60038, 1, 0);
    }

    func_L01_00516470(0x60005, 0.28f, 0.25f);
    y = 0.06f;
    n = 0;
    func_L01_00516470(0x60006, 0.62f, 0.25f);
    sub = 0.0f;
    func_L01_00516470(0x60007, 0.83f, 0.25f);
    ((Fn3_005DF8F8)func_L01_00516AA0)(0x60005, 1, 1);
    ((Fn3_005DF8F8)func_L01_00516AA0)(0x60006, 1, 1);
    ((Fn3_005DF8F8)func_L01_00516AA0)(0x60007, 1, 1);
    cnt = func_L39_005DF510(arr, scratch);
    if (((s8 *)D_L39_00241640)[0x19D] != 0) {
        sub = 0.13f;
    }
    for (i = 0; i < cnt; i++) {
        node = arr[i].f14;
        if (((s8 *)D_L39_00241640)[0x19D] != 0) {
            s32 a = 0x60008 + n;
            s32 b = 0x60018 + n;
            func_00120048(D_L39_002B5AB0[n], D_001D8228_sda, arr[i].f4);
            z = y + 0.25f;
            func_00120048(D_L39_002B5B50[n], D_001D8228_sda, arr[i].f8);
            func_L01_00516FD8(a, (s32)arr[i].f0);
            func_L01_00516FD8(b, (s32)D_L39_002B5AB0[n]);
            func_L01_00516FD8(0x60028 + n, (s32)D_L39_002B5B50[n]);
            ((Fn3_005DF8F8)func_L01_00516AA0)(a, 0x200, 1);
            ((Fn3_005DF8F8)func_L01_00516AA0)(a, 0x400, 0);
            func_L01_00516470(a, 0.28f - sub, z);
            func_L01_00516470(b, 0.62f, z);
            func_L01_00516470(0x60028 + n, 0.83f, z);
            ((Fn3_005DF8F8)func_L01_00516AA0)(a, 1, 1);
            ((Fn3_005DF8F8)func_L01_00516AA0)(b, 1, 1);
            ((Fn3_005DF8F8)func_L01_00516AA0)(0x60028 + n, 1, 1);
            {
                s32 col = func_L39_0066C788(arr[i].f10);
                func_L01_005170B8(a, col);
                func_L01_005170B8(b, col);
                func_L01_005170B8(0x60028 + n, col);
            }
            dy = 0.04f;
            y += dy;
            n++;
        }
        for (; node != 0; node = node->f18) {
            s32 a = 0x60008 + n;
            s32 b = 0x60018 + n;
            s32 c = 0x60028 + n;
            func_00120048(D_L39_002B5AB0[n], D_L39_00243938, node->f4);
            z = y + 0.25f;
            func_00120048(D_L39_002B5AB0[n + 16], D_L39_00243938, node->f8);
            func_L01_00516FD8(a, (s32)node->f0);
            func_L01_00516FD8(b, (s32)D_L39_002B5AB0[n]);
            func_L01_00516FD8(c, (s32)D_L39_002B5AB0[n + 16]);
            func_L01_00516470(a, 0.28f, z);
            func_L01_00516470(b, 0.62f, z);
            func_L01_00516470(c, 0.83f, z);
            ((Fn3_005DF8F8)func_L01_00516AA0)(a, 0x200, 1);
            ((Fn3_005DF8F8)func_L01_00516AA0)(a, 0x400, 1);
            ((Fn3_005DF8F8)func_L01_00516AA0)(a, 1, 1);
            ((Fn3_005DF8F8)func_L01_00516AA0)(b, 1, 1);
            ((Fn3_005DF8F8)func_L01_00516AA0)(c, 1, 1);
            if (node->f10 == *(s32 *)(g + 0x2544)) {
                func_L01_005170B8(a, 0x8000FF00);
                func_L01_005170B8(b, 0x8000FF00);
                func_L01_005170B8(c, 0x8000FF00);
            } else {
                func_L01_005170B8(a, 0x8066CCFF);
                func_L01_005170B8(b, 0x8066CCFF);
                func_L01_005170B8(c, 0x8066CCFF);
            }
            dy = 0.04f;
            y += dy;
            n++;
        }
    }
    for (i = n; i < 16; i++) {
        ((Fn3_005DF8F8)func_L01_00516AA0)(0x60008 + i, 1, 0);
        ((Fn3_005DF8F8)func_L01_00516AA0)(0x60018 + i, 1, 0);
        ((Fn3_005DF8F8)func_L01_00516AA0)(0x60028 + i, 1, 0);
    }
}
/* localdecomp:end func_L39_005DF8F8 */
