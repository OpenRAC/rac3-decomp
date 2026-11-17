#include "common.h"

typedef struct {
    u8 f[28];
} V7;

/* localdecomp:start func_L24_003CB5A8 */
extern u8 D_001A4C60[];
extern s16 D_001A4DC0[];
extern u8 *D_001D52FC;
extern u8 D_L24_001DEAD0[];
__asm__(".extern D_L24_001E1B30, 8");
__asm__(".extern D_L24_001E1B70, 8");
extern u8 D_L24_001E1B30[8];
extern u8 D_L24_001E1B70[8];
extern f32 func_0038CF38(void *, void *);
extern s32 func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern u8 *func_L24_003CB900(u8 *);
extern void func_L24_003CB990(u8 *, void *, s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_11B2E8();
extern void func_L03_0034B348(s32);

void func_L24_003CB5A8(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 0x68);
    s32 v;
    switch (a0[0x20]) {
    case 0:
        p[1] = -1;
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_0038CF38(a0 + 0x10, D_001A4C60) <= 2.5f) {
            func_L01_00452560(0, 0xD, 0x169F, 1, 0, 0, 0);
            if (*(u32 *)(D_001D52FC + 0x1A4) & 0x10) {
                func_L01_004450F0(a0, 2, -1);
            }
        }
        break;
    case 2:
        D_001A4DC0[0] = 5;
        if (func_L01_004561B8(a0) != 0) {
            p[1] = -1;
            p[0] = (s32)func_L24_003CB900(a0);
            func_11B2E8(D_L24_001E1B30, D_L24_001DEAD0, func_00381FF0(0x16A1));
            func_11B2E8(D_L24_001E1B70, D_L24_001DEAD0, func_00381FF0(0x16A3));
            func_L24_003CB990((u8 *)p[0], &p[1], (s32)D_L24_001E1B30, 4);
            func_L24_003CB990((u8 *)p[0], &p[1], (s32)D_L24_001E1B70, 4);
        }
        func_L01_00452560(0, 1, 0, 1, 0, 0, 0);
        if (p[0] != 0 && *(s16 *)(p[0] + 0xAA) == 0x1F13 && *(u8 *)(p[0] + 0x20) != 0xFE && *(u8 *)(p[0] + 0x20) != 0xFD) {
            break;
        }
        if (p[1] == 0) {
            v = 0x1E;
        } else if (p[1] == 1) {
            v = 0x24;
        } else {
            goto other;
        }
        func_L03_0034B348(v);
        func_L01_004450F0(a0, 1, -1);
        break;
    other:
        func_L01_004450F0(a0, 1, -1);
        break;
    }
}
/* localdecomp:end func_L24_003CB5A8 */

/* localdecomp:start func_L24_003CB7C0 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} S_3CB7C0;
extern s16 D_001A4DC0[];
extern s32 D_L24_001DF2B8;
extern u8 *D_001D52FC;
extern void *D_L24_002A2D50[];
extern void func_003C2880(void *);
extern void func_L01_00448248(void *, s32, s32);
extern void func_L01_00404808(void *, void *);
extern void func_L24_003CBA10(char *);

void func_L24_003CB7C0(u8 *a0) {
    S_3CB7C0 *p = *(S_3CB7C0 **)(a0 + 0x68);
    u32 btn;
    D_L24_001DF2B8 = 1;
    D_001A4DC0[0] = 5;
    if (*(unsigned long *)(D_001D52FC + 0x1A0) & 0x9000000000UL) {
        *(s32 *)D_L24_002A2D50[p->f0] = -1;
        func_003C2880(a0);
        return;
    }
    btn = *(u32 *)(D_001D52FC + 0x1A4);
    if (btn & 0x4000) {
        func_L01_00448248(p, p->f4 - 1, 1);
        if (p->f8 < p->f0 - 0xF) {
            p->f8++;
        }
    } else if ((btn & 0x1000) == 0) {
        if ((btn & 0x40) != 0) {
            *(s32 *)D_L24_002A2D50[p->f0] = p->f0;
            func_003C2880(a0);
            return;
        }
    } else {
        func_L01_00448248(p, 0, 1);
        if (p->f0 < p->f8) {
            p->f8--;
        }
    }
    func_L01_00404808(func_L24_003CBA10, a0);
}
/* localdecomp:end func_L24_003CB7C0 */

/* localdecomp:start func_L24_003CB900 */
typedef int u128_t __attribute__((mode(TI)));
extern void *D_L24_002A2D50[];
extern s32 D_L24_002A2E50[];
extern u8 D_L24_001E1BB0[8];
extern u8 *func_003C24B0(s32, s32);

u8 *func_L24_003CB900(u8 *a0) {
    u8 *r = func_003C24B0(0x1F13, 0x80);
    s32 i;
    u128_t q;
    if (r != 0) {
        q = *(u128_t *)(a0 + 0x10);
        *(u8 **)(r + 0xB8) = a0;
        *(u128_t *)(r + 0x10) = q;
        r[0x30] = 0xFF;
        for (i = 0; i < 0x40; i++) {
            D_L24_002A2D50[i] = 0;
            D_L24_002A2E50[i] = 0;
            D_L24_001E1BB0[i] = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L24_003CB900 */

/* localdecomp:start func_L24_003CB990 */
extern void *D_L24_002A2D50[];
extern s32 D_L24_002A2E50[];
extern u8 D_L24_001E1BB0[8];

void func_L24_003CB990(u8 *a0, void *a1, s32 a2, s32 a3) {
    s32 *t = *(s32 **)(a0 + 0x68);
    s32 i;
    for (i = 0; i < 0x40; i++) {
        if (D_L24_002A2D50[i] == 0) {
            D_L24_002A2D50[i] = a1;
            D_L24_002A2E50[i] = a2;
            D_L24_001E1BB0[i] = a3;
            t[1]++;
            break;
        }
    }
}
/* localdecomp:end func_L24_003CB990 */

/* localdecomp:start func_L24_003CBA10 */
extern void func_003A9440(s32, unsigned long);
extern void func_L01_00421738(s32, s32, s32, s32, s32, s32);
extern s32 func_00381FF0(s32);
extern void func_L03_00400000(s32, s32, long, s32, s32);
extern s32 func_11B2E8();
extern s32 func_129A18(f32);

__asm__(".extern D_L24_001DEAD8, 4");
__asm__(".extern D_L24_001DEAE8, 4");
__asm__(".extern D_L24_001DEAEC, 4");
__asm__(".extern D_L24_001DEAF0, 4");
__asm__(".extern D_L24_001DEAF4, 4");
__asm__(".extern D_L24_001DEB04, 4");
extern s32 D_L24_001DEAD8;
extern s32 D_L24_001DEAE8;
extern s32 D_L24_001DEAEC;
extern s32 D_L24_001DEAF0;
extern s32 D_L24_001DEAF4;
extern s32 D_L24_001DEB04;
extern s32 D_L24_001DEADC;
extern s32 D_L24_001DEAE0;
extern s32 D_L24_001DEAFC;
extern char D_L24_001DEB08[];
extern char D_L24_001DEB10[];
extern char D_L24_001DEB18[];
extern char D_L24_001DEB20[];
extern char D_L24_001DEB28[];
extern u8 D_L24_001E1BB0[];
extern void *D_L24_002A2D50[];
extern s32 D_L24_002A2E50[];

void func_L24_003CBA10(char *obj) {
    char text[256];
    int *st;
    int i, count;
    st = *(int **)(obj + 0x68);
    count = 0;
    func_003A9440(0x42, 0x8000000044UL);
    func_L01_00421738(D_L24_001DEAD8, D_L24_001DEADC, D_L24_001DEAE0, D_L24_001DEADC + D_L24_001DEAE8 * (st[1] < 17 ? st[1] : 16), D_L24_001DEB04, 0);
    func_L03_00400000(D_L24_001DEAEC, 8, D_L24_001DEAFC, func_00381FF0(0x10AA), -1);
    for (i = 0; i < 0x40 - st[2] && count < st[1] && count < 16; i++) {
        if (D_L24_002A2D50[i + st[2]]) {
            count++;
            if (D_L24_002A2E50[i]) {
                func_11B2E8(text, D_L24_001DEB08, D_L24_002A2E50[i + st[2]]);
                func_L03_00400000(D_L24_001DEAF0, D_L24_001DEAF4 + i * D_L24_001DEAE8, D_L24_001DEAFC, (s32)text, -1);
            }
            if (st[0] == i + st[2]) {
                func_11B2E8(text, D_L24_001DEB10);
                func_L03_00400000(D_L24_001DEAF0 - 16, D_L24_001DEAF4 + i * D_L24_001DEAE8, 0x80008000UL, (s32)text, -1);
            }
            switch (D_L24_001E1BB0[i + st[2]]) {
            case 0:
                func_11B2E8(text, D_L24_001DEB18, *(int *)D_L24_002A2D50[i + st[2]]);
                func_L03_00400000(D_L24_001DEAEC, D_L24_001DEAF4 + i * D_L24_001DEAE8, 0x80008080UL, (s32)text, -1);
                break;
            case 1:
                func_11B2E8(text, D_L24_001DEB20, func_129A18(*(f32 *)D_L24_002A2D50[i + st[2]]));
                func_L03_00400000(D_L24_001DEAEC, D_L24_001DEAF4 + i * D_L24_001DEAE8, 0x80008080UL, (s32)text, -1);
                break;
            case 2:
                func_11B2E8(text, D_L24_001DEB18, *(u8 *)D_L24_002A2D50[i + st[2]]);
                func_L03_00400000(D_L24_001DEAEC, D_L24_001DEAF4 + i * D_L24_001DEAE8, 0x80008080UL, (s32)text, -1);
                break;
            case 3:
                func_11B2E8(text, D_L24_001DEB18, *(s16 *)D_L24_002A2D50[i + st[2]]);
                func_L03_00400000(D_L24_001DEAEC, D_L24_001DEAF4 + i * D_L24_001DEAE8, 0x80008080UL, (s32)text, -1);
                break;
            case 5: {
                u32 *p = (u32 *)D_L24_002A2D50[i + st[2]];
                func_11B2E8(text, D_L24_001DEB28, *p >> 16, ((u8 *)p)[1], *p & 0xFF);
                func_L03_00400000(D_L24_001DEAEC, D_L24_001DEAF4 + i * D_L24_001DEAE8, 0x80008080UL, (s32)text, -1);
                break;
            }
            case 4:
            default:
                break;
            }
        } else if (D_L24_002A2E50[i]) {
            count++;
            func_11B2E8(text, D_L24_001DEB08, D_L24_002A2E50[i + st[2]]);
            func_L03_00400000(D_L24_001DEAF0, D_L24_001DEAF4 + i * D_L24_001DEAE8, D_L24_001DEAFC, (s32)text, -1);
        }
    }
}
/* localdecomp:end func_L24_003CBA10 */

/* localdecomp:start func_L24_003CBDC8 */
extern s32 func_L01_00456250(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2880(void *);
extern f32 func_0038CF00(void *, void *);
extern f32 D_1A4C60[];

void func_L24_003CBDC8(u8 *a0) {
    s32 *q = *(s32 **)(a0 + 0x68);
    s32 *g;

    if (a0[0x20] == 0) {
        if (func_L01_00456250(a0) > 0) {
            func_003C2880(a0);
        } else {
            func_L01_004450F0(a0, 1, -1);
        }
    } else {
        if (func_L01_00456250(a0) > 0) {
            func_0038CF00(a0 + 0x10, D_1A4C60);
            g = (s32 *)0x140000;
            g[0x998] = g[0x998] + *q;
            func_003C2880(a0);
        }
    }
}
/* localdecomp:end func_L24_003CBDC8 */

/* localdecomp:start func_L24_003CBE68 */
typedef struct {
    s32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    u8 *f10;
    s32 f14;
    s32 f18;
    s32 f1C;
} V_003CBE68;

extern f32 func_003C3D30(void *, s32, s32, f32);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038D308(void *, void *);
extern void func_13D3D0(u32);
extern s32 func_00382468(s32);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L03_0043F5D0(s32, s32, f32);
extern void func_003C7C38(void *);
extern void func_L24_003CC248(u8 *);
extern u8 D_001A4BE0[];
extern u8 *D_001A4F3C __attribute__((section(".data")));
extern s32 D_L24_001DEB38[2];
__asm__(".extern D_L24_001DEB38, 8");
extern s32 D_001DEB40_sda[2];
__asm__(".extern D_001DEB40_sda, 8");
extern s32 D_L24_001DEB48[2];
__asm__(".extern D_L24_001DEB48, 8");
extern f32 D_L24_001DEB4C;
__asm__(".extern D_L24_001DEB4C, 4");
extern f32 D_L24_001DEB50;
__asm__(".extern D_L24_001DEB50, 4");
extern s32 D_L24_001DF0C0;

void func_L24_003CBE68(u8 *m) {
    V_003CBE68 *v = *(V_003CBE68 **)(m + 0x68);
    s32 *c;
    s32 n;
    s32 hr;
    s32 hg;
    s32 hb;
    s32 ha;

    switch (m[0x20]) {
    case 0:
        *(f32 *)(m + 0x18) = func_003C3D30(m + 0x10, 0, 0, 0.5f);
        if (v->f1C != 0) {
            u8 *o = func_003C24B0(0x19E0, 0x80);
            v->f10 = o;
            if (o != 0) {
                *(u16 *)(o + 0x34) |= 0x10;
                func_L01_00456160(v->f10, m);
                v->f10[0x21] = m[0x21];
            }
        }
        *(f32 *)(m + 0x18) += func_003824E0(0.0f, 0.5f) * 2.0f + 3.0f;
        *(f32 *)(m + 0xF8) += func_00382498(0, 90) * 0.017453292f;
        func_0038D308(m + 0xC0, m + 0xF0);
        v->fC = *(f32 *)(m + 0x18);
        if (v->f0 != 0) {
            func_13D3D0(*(volatile u32 *)0x10000800); /* T0_COUNT */
            v->f0 = func_00382468(1);
            v->f1C = 0;
        }
        *(u16 *)(m + 0x7C) = 1 << D_L24_001DEB48[v->f0];
        v->f14 = D_L24_001DEB38[D_L24_001DEB48[v->f0]];
        c = &D_L24_001DEB38[D_L24_001DEB48[v->f0]];
        {
            s32 g = ((u8 *)c)[1];
            u32 w = *c;
            s32 b = ((u8 *)c)[2];
            hg = g >> 1;
            hb = b >> 1;
            ha = w >> 25;
            hr = (s32)(w & 0xFF) >> 1;
            v->f18 = (ha << 24) | (hb << 16) | (hg << 8) | hr;
        }
        func_L01_004450F0(m, 1, -1);
        break;
    case 1:
        if (v->f1C != 0 && v->f10 != 0 && D_001A4F3C != 0 && D_001A4F3C == v->f10 &&
            D_001DEB40_sda[v->f0] != 0) {
            func_L01_00452560(0, 0xD, 0x16FF, 1, 0, 0, 0);
            if (*(s32 *)(D_001D52FC + 0x1A4) & 0x10) {
                func_L01_004450F0(m, 2, -1);
            }
        }
        break;
    case 2:
        D_001A4BE0[0x25ED] = 1;
        *(s16 *)(D_001A4BE0 + 0x1E0) = 5;
        func_L01_00404A10(func_L24_003CC248, m);
        if ((*(s32 *)(D_001D52FC + 0x1A4) & 0x10) || *(u16 *)(m + 0x96) >= 600) {
            func_L01_004450F0(m, 1, -1);
        }
        break;
    }
    func_L01_0044EAE0(m, &v->f4, &v->f8, D_L24_001DEB4C, D_L24_001DEB50 * 0.017453292f * 0.020000001f, v->fC);
    *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(m + 0xF8), 0.017453292f);
    *(u16 *)(m + 0x96) = 0;
    if (m[0x31] != 0) {
        n = 100;
        *(s32 *)(m + 0x78) = func_L03_0043F5D0(v->f14, v->f18, (f32)(D_L24_001DF0C0 % n) * 6.2831855f / (f32)n - 3.1415927f);
        if (v->f10 != 0) {
            *(s32 *)(v->f10 + 0x78) = *(s32 *)(m + 0x78);
            func_003C7C38(v->f10);
        }
    }
    (*(u16 *)(m + 0x96))++;
}
/* localdecomp:end func_L24_003CBE68 */

/* localdecomp:start func_L24_003CC248 */
extern u8 D_L24_001DEB58[];
extern s32 D_001DEB40_sda[2];
__asm__(".extern D_001DEB40_sda, 8");
extern s32 func_00381FF0(s32);
extern void func_003AF408(void *, u32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003A9440(s32, unsigned long);
extern void func_0038E138(void);

void func_L24_003CC248(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    V7 buf;
    s32 v;
    buf = *(V7 *)D_L24_001DEB58;
    v = func_00381FF0(D_001DEB40_sda[*(s32 *)st]);
    func_003AF408(&buf, 0x80F0F0F0, v, 1, 0, -1, 0, 0, 0, 0);
    func_003A9440(0x47, 0x5360B);
    func_0038E138();
}
/* localdecomp:end func_L24_003CC248 */
