#include "common.h"
#include "vu0.h"

/* declared by functions of L32_003A0BB8.c, which this file was cut from */
void func_L01_004450F0(s32, s32, s32);
s32 func_L01_004561B8(void *);
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern u8 *D_L32_001DFE1C;

/* declared by functions of L32_003A44A8.c, which this file was cut from */
extern u8 *D_L32_002A3E50[];
extern s32 D_L32_001DE980;
extern s32 D_L32_001E2320;
extern u8 D_00142660[];
extern void func_L01_004AA7E8(void *, s32);
extern u8 D_L32_001DE964;
extern f32 func_003824E0(f32, f32);
void func_L32_003A52A8(void *, s32);
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DEA88;
extern f32 D_L32_001DEA50;
extern s32 func_L01_004561B8(void *);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A52A8(void *, s32);
extern s32 D_L32_001DE9BC;
extern s32 func_0038CAD0(void *);
extern void func_L32_003A5850(void *arg0);

/* localdecomp:start func_L32_003A5E48 */
extern f32 D_L32_001DE8E8;
extern f32 D_L32_001DE8E4;
extern f32 D_L32_001DEA44;
extern s32 D_L32_001DE9BC;
extern s32 D_L32_001DEAD8;
extern f32 D_L32_001DE944;
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DEA88;
extern f32 D_L32_001DE940;
extern f32 D_L32_001DE8F4;
extern f32 D_L32_001DE934;
__asm__(".extern D_L32_001DE8E8, 4");
__asm__(".extern D_L32_001DE8E4, 4");
__asm__(".extern D_L32_001DEA44, 4");
__asm__(".extern D_L32_001DE9BC, 4");
__asm__(".extern D_L32_001DEAD8, 4");
__asm__(".extern D_L32_001DE944, 4");
__asm__(".extern D_L32_001DE9D4, 4");
__asm__(".extern D_L32_001DEA88, 4");
__asm__(".extern D_L32_001DE940, 4");
__asm__(".extern D_L32_001DE8F4, 4");
__asm__(".extern D_L32_001DE934, 4");
extern u8 D_L32_002A2E40[];
extern s32 D_L32_001E2320;
__asm__(".extern D_L32_001E2320, 16");
extern f32 func_L01_004395E0(void *);
extern s32 func_L01_004561B8(void *);
extern void func_L02_003BAAB0(void *, void *);
extern void func_L30_0034C8A8(void *, void *);
s32 func_L32_00349958(u8 *, s32, f32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A4360(void *);
extern f32 func_0038DB00(f32, f32);
extern void func_L32_003A52A8(void *, s32);

void func_L32_003A5E48(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    f32 f20;
    f32 dist;
    f32 acc;
    f32 x;
    f32 k;
    s32 n;
    s32 h;
    s32 m;
    s32 lim;
    s32 t;
    s32 d;
    s32 full;
    s8 old;

    f20 = func_L01_004395E0(a0);
    if (func_L01_004561B8(a0) != 0) {
        x = *(f32 *)(a0 + 0x10);
        if (*(f32 *)(a0 + 0xF8) == D_L32_001DE8E8) {
            dist = *(f32 *)(v + 0x178) - x;
        } else {
            dist = *(f32 *)(v + 0x180) - x;
        }
        acc = D_L32_001DEA44;
        if (!(dist < 0.0f)) {
            acc = -acc;
        }
        lim = D_L32_001DEAD8;
        *(s32 *)(v + 0x128) = D_L32_001DE9BC;
        n = (s32)sqrt_asm(dist * -2.0f / acc);
        h = n / 2;
        *(s32 *)(v + 0xA8) = n;
        if (lim < h) {
            h = lim;
        }
        *(s32 *)(v + 0x124) = h;
        *(f32 *)(v + 0x90) = -acc * (f32)n;
        func_L02_003BAAB0(a0, D_L32_002A2E40);
        func_L30_0034C8A8(&D_L32_001E2320, a0);
    }
    if (*(s32 *)(v + 0x124) >= 0) {
        d = (s32)((*(s32 *)(v + 0x124) < *(s32 *)(v + 0xA8) ? -127.0f : 127.0f) / (f32)D_L32_001DEAD8);
        t = a0[0x23];
        old = t;
        t += d;
        full = (u8)old >= 0x7F;
        if (t < 0) {
            t = 0;
        }
        if (t >= 0x80) {
            t = 0x7F;
        }
        a0[0x23] = t;
        if ((u8)t < 0x7F) {
            *(u16 *)(a0 + 0x34) |= 8;
        } else {
            *(u16 *)(a0 + 0x34) &= ~8;
            if (!full) {
                func_L02_003BAAB0(a0, D_L32_002A2E40);
        func_L30_0034C8A8(&D_L32_001E2320, a0);
            }
        }
    }
    m = *(s32 *)(v + 0xA8);
    if (m != 0) {
        k = D_L32_001DE944;
        m--;
        *(s32 *)(v + 0xA8) = m;
        func_L32_00349958(a0, m, k);
    } else {
        *(f32 *)(a0 + 0x48) = 1.0f;
    }
    *(s32 *)(v + 0x110) = func_L30_0034D1E8(a0, a0 + 0x10, v + 0x90, v + 0x140,
        D_L32_001DE9D4, D_L32_001DE9D4, D_L32_001DEA88, 0.0f, 0.0f, D_L32_001DEA44, 1, 1, 1, 0);
    if ((a0[0x60] & 2) || D_L32_001DE940 <= f20) {
        *(s32 *)(v + 0x124) = -1;
        a0[0x23] = 0x7F;
        *(u16 *)(a0 + 0x34) &= ~8;
        *(s32 *)(v + 0xF4) = -1;
        func_L32_003A4360(a0);
        x = *(f32 *)(a0 + 0x10);
        if (fabs_asm(*(f32 *)(v + 0xE0) - x) < D_L32_001DE8F4) {
            if (fabs_asm(func_0038DB00(x < *(f32 *)(v + 0x17C) ? D_L32_001DE8E8 : D_L32_001DE8E4, *(f32 *)(a0 + 0xF8))) <= D_L32_001DE934) {
                func_L32_003A52A8(a0, 1);
            } else {
                func_L32_003A52A8(a0, 0x12);
            }
        } else {
            func_L32_003A52A8(a0, 0xD);
        }
    }
}
/* localdecomp:end func_L32_003A5E48 */

/* localdecomp:start func_L32_003A6168 */
extern f32 D_L32_001DE8E8;
extern f32 D_L32_001DE934;
extern f32 D_L32_001DE914;
extern f32 D_L32_001DEA48;
extern s32 D_L32_001DE9C8;
extern f32 D_L32_001DE944;
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DEA88;
extern f32 D_L32_001DE940;
extern f32 D_L32_001DEB34;
__asm__(".extern D_L32_001DE8E8, 4");
__asm__(".extern D_L32_001DE934, 4");
__asm__(".extern D_L32_001DE914, 4");
__asm__(".extern D_L32_001DEA48, 4");
__asm__(".extern D_L32_001DE9C8, 4");
__asm__(".extern D_L32_001DE944, 4");
__asm__(".extern D_L32_001DE9D4, 4");
__asm__(".extern D_L32_001DEA88, 4");
__asm__(".extern D_L32_001DE940, 4");
__asm__(".extern D_L32_001DEB34, 4");
extern f32 func_L01_004395E0(void *);
s32 func_L32_00349958(u8 *, s32, f32);
s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
void func_L32_003A52A8(void *, s32);

typedef struct {
    u8 pad0[0x90];
    f32 speed;      /* 0x90 */
    u8 pad94[0x14];
    s32 timer;      /* 0xA8 */
    u8 padAC[0x54];
    s32 f100;       /* 0x100 */
    u8 pad104[0xC];
    s32 f110;       /* 0x110 */
    u8 pad114[0x14];
    s32 f128;       /* 0x128 */
    u8 pad12C[8];
    s32 f134;       /* 0x134 */
    s32 f138;       /* 0x138 */
    u8 pad13C[4];
    u8 f140[0x10];  /* 0x140 */
} S_003A6168;

void func_L32_003A6168(void *arg0) {
    S_003A6168 *p = *(S_003A6168 **)((u8 *)arg0 + 0x68);
    f32 f20;
    f32 v;
    s32 n;

    f20 = func_L01_004395E0(arg0);
    if (func_L01_004561B8(arg0) != 0) {
        if (fabs_asm(*(f32 *)((u8 *)arg0 + 0xF8) - D_L32_001DE8E8) < D_L32_001DE934) {
            v = -D_L32_001DE914;
        } else {
            v = D_L32_001DE914;
        }
        p->timer = fabs_asm(v) / D_L32_001DEA48;
        p->speed = v;
        if (p->f128 < D_L32_001DE9C8) {
            p->f128 = D_L32_001DE9C8;
        }
    }
    n = p->timer;
    if (n != 0) {
        n--;
        p->timer = n;
        func_L32_00349958(arg0, n, D_L32_001DE944);
    } else {
        *(f32 *)((u8 *)arg0 + 0x48) = 1.0f;
    }
    p->f110 = func_L30_0034D1E8(arg0, (u8 *)arg0 + 0x10, &p->speed, p->f140,
        D_L32_001DE9D4, D_L32_001DE9D4, D_L32_001DEA88, 0.0f, 0.0f, D_L32_001DEA48, 1, 1, 1, 0);
    if ((*(u8 *)((u8 *)arg0 + 0x60) & 2) || D_L32_001DE940 <= f20) {
        func_L32_003A52A8(arg0, p->f100 != 0 ? 16 : 15);
    }
    if (D_L32_001DEB34 <= f20 && p->f134 != 0 && p->f138 != 0) {
        func_L32_003A52A8(arg0, p->f100 != 0 ? 16 : 15);
    }
}
/* localdecomp:end func_L32_003A6168 */

/* localdecomp:start func_L32_003A6308 */
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DEA88;
extern f32 D_L32_001DEA50;
extern s32 D_L32_001DE990;
extern s32 D_L32_001DEA74;
extern u8 D_L32_001DE964;
__asm__(".extern D_L32_001DE9D4, 4");
__asm__(".extern D_L32_001DEA88, 4");
__asm__(".extern D_L32_001DEA50, 4");
__asm__(".extern D_L32_001DE990, 4");
__asm__(".extern D_L32_001DEA74, 4");
__asm__(".extern D_L32_001DE964, 1");
extern s32 func_L01_004561B8(void *);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A52A8(void *, s32);
extern s32 func_0038CAD0(void *);
extern void func_L32_003A5850(void *arg0);

void func_L32_003A6308(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 r, a, b;
    if (func_L01_004561B8(a0)) {
        *(s32 *)(v + 0xA8) = D_L32_001DE990;
    }
    r = func_L30_0034D1E8(a0, a0 + 0x10, v + 0x90, v + 0x140, D_L32_001DE9D4, D_L32_001DE9D4, D_L32_001DEA88, 0.0f, 0.0f, D_L32_001DEA50, 1, 1, 1, 0);
    a = D_L32_001DE990;
    b = D_L32_001DEA74;
    *(s32 *)(v + 0x110) = r;
    if (*(s32 *)(v + 0xA8) < a - b && D_L32_001DE964 && *(s32 *)(v + 0xFC)) {
        func_L32_003A52A8(a0, 0x11);
    } else if (func_0038CAD0(v + 0xA8)) {
        func_L32_003A5850(a0);
    }
}
/* localdecomp:end func_L32_003A6308 */

/* localdecomp:start func_L32_003A63E0 */
extern f32 D_L32_001DE994;
extern f32 D_L32_001DE950;
extern f32 D_L32_001DE998;
extern f32 D_L32_001DE9B0;
extern f32 D_L32_001DE9A8;
extern f32 D_L32_001DE9AC;
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DEA88;
extern f32 D_L32_001DEA80;
extern f32 D_L32_001DEA50;
__asm__(".extern D_L32_001DE994, 4");
__asm__(".extern D_L32_001DE950, 4");
__asm__(".extern D_L32_001DE998, 4");
__asm__(".extern D_L32_001DE9B0, 4");
__asm__(".extern D_L32_001DE9A8, 4");
__asm__(".extern D_L32_001DE9AC, 4");
__asm__(".extern D_L32_001DE9D4, 4");
__asm__(".extern D_L32_001DEA88, 4");
__asm__(".extern D_L32_001DEA80, 4");
__asm__(".extern D_L32_001DEA50, 4");
extern f32 func_L01_004395E0(void *);
extern void func_L32_003A4270(void *);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A52A8(void *, s32);

void func_L32_003A63E0(void *arg0) {
    u8 *a0 = arg0;
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 v[4] __attribute__((aligned(16)));
    f32 f20;
    f32 d;
    f32 t;
    f32 nl;
    f32 g;
    f32 s;
    s32 n;

    f20 = func_L01_004395E0(a0);
    if (func_L01_004561B8(a0) != 0) {
        func_L32_003A4270(a0);
        *(s32 *)(p + 0x120) = 0;
        *(f32 *)(p + 0x90) = 0.0f;
    }
    if (D_L32_001DE994 <= f20 && *(s32 *)(p + 0x120) == 0 && a0[0x42] == a0[0x43]) {
        *(s32 *)(p + 0x120) = 1;
        nl = -D_L32_001DE998;
        d = *(f32 *)(p + 0xE0) - *(f32 *)(a0 + 0x10);
        if (nl < d && d <= 0.0f) {
            d = nl;
        }
        if (0.0f <= d && d < D_L32_001DE998) {
            d = D_L32_001DE998;
        }
        t = D_L32_001DE9B0 * fabs_asm(d);
        if (D_L32_001DE9A8 < t) {
            t = D_L32_001DE9A8;
        } else if (t < D_L32_001DE9AC) {
            t = D_L32_001DE9AC;
        }
        g = D_L32_001DE950;
        s = sqrt_asm(g * -2.0f * t);
        *(f32 *)(p + 0x98) = s;
        n = (s32)fabs_asm((s + s) / g);
        if (n <= 0) {
            n = 1;
        }
        *(f32 *)(p + 0x90) = d / (f32)n;
    }
    qzero(v);
    v[2] = D_L32_001DE950;
    *(s32 *)(p + 0x110) = func_L30_0034D1E8(a0, a0 + 0x10, p + 0x90, v, D_L32_001DE9D4, D_L32_001DE9D4,
                          D_L32_001DEA88, D_L32_001DEA80, 0.0f, D_L32_001DEA50, 1, 1, 1, 0);
    if (a0[0x60] & 2) {
        func_L32_003A52A8(a0, 8);
    }
    if (*(s32 *)(p + 0x120) == 1 && *(f32 *)(p + 0x98) <= 0.0f) {
        func_L32_003A52A8(a0, 9);
    }
}
/* localdecomp:end func_L32_003A63E0 */

/* localdecomp:start func_L32_003A6608 */
extern f32 D_L32_001DE950;
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DEA88;
extern f32 D_L32_001DEA80;
extern f32 D_L32_001DEA50;
__asm__(".extern D_L32_001DE950, 4");
__asm__(".extern D_L32_001DE9D4, 4");
__asm__(".extern D_L32_001DEA88, 4");
__asm__(".extern D_L32_001DEA80, 4");
__asm__(".extern D_L32_001DEA50, 4");
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A52A8(void *, s32);

void func_L32_003A6608(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    f32 v[4] __attribute__((aligned(16)));
    s32 r;

    qzero(v);
    v[2] = D_L32_001DE950;
    r = func_L30_0034D1E8(arg0, (u8 *)arg0 + 0x10, p + 0x90, v, D_L32_001DE9D4, D_L32_001DE9D4,
                          D_L32_001DEA88, D_L32_001DEA80, 0.0f, D_L32_001DEA50, 1, 1, 1, 0);
    *(s32 *)(p + 0x110) = r;
    if (*(f32 *)(p + 0x98) <= 0.0f || r != 0) {
        func_L32_003A52A8(arg0, 9);
    }
}
/* localdecomp:end func_L32_003A6608 */

/* localdecomp:start func_L32_003A66B0 */
extern f32 D_L32_001DE9A0;
extern f32 D_L32_001DE99C;
extern f32 D_L32_001DE950;
extern f32 D_L32_001DEA80;
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DEA88;
extern f32 D_L32_001DEA4C;
extern f32 D_L32_001DE9B4;
extern f32 D_L32_001DE9A4;
extern f32 D_L32_001DE938;
__asm__(".extern D_L32_001DE9A0, 4");
__asm__(".extern D_L32_001DE99C, 4");
__asm__(".extern D_L32_001DE950, 4");
__asm__(".extern D_L32_001DEA80, 4");
__asm__(".extern D_L32_001DE9D4, 4");
__asm__(".extern D_L32_001DEA88, 4");
__asm__(".extern D_L32_001DEA4C, 4");
__asm__(".extern D_L32_001DE9B4, 4");
__asm__(".extern D_L32_001DE9A4, 4");
__asm__(".extern D_L32_001DE938, 4");
extern f32 func_L32_00348900(u8 *);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern s32 func_L32_00349630(void *, void *, f32, f32, f32, f32, f32, f32, f32);
extern void func_L30_0034CB68(void *, void *, s32, s32, void *, s32, f32, f32);
extern void func_L32_003A52A8(void *, s32);

void func_L32_003A66B0(void *arg0) {
    u8 *a0 = arg0;
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 v[4] __attribute__((aligned(16)));
    f32 f;
    s32 near;
    s32 done;
    s32 s;

    f = func_L32_00348900(a0);
    near = 1;
    if (!(D_L32_001DE9A0 <= f)) {
        near = 0;
    }
    done = 0;
    if ((a0[0x60] & 2) || D_L32_001DE99C <= f) {
        done = 1;
    }
    qzero(v);
    v[2] = D_L32_001DE950;
    *(s32 *)(p + 0x110) = func_L30_0034D1E8(a0, a0 + 0x10, p + 0x90, v, D_L32_001DE9D4, D_L32_001DE9D4,
                          D_L32_001DEA88, *(s32 *)(p + 0x110) == 0 ? D_L32_001DEA80 : 0.0f, 0.0f,
                          D_L32_001DEA4C, 1, 1, 1, 0);
    if (*(s32 *)(p + 0x110) == 0) {
        func_L32_00349630(a0, a0 + 0x10, D_L32_001DE9D4, *(f32 *)(p + 0x98), D_L32_001DE950,
                          D_L32_001DE9B4, D_L32_001DE9A4, D_L32_001DE950, D_L32_001DE9D4);
        func_L30_0034CB68(a0, v, 1, -1, a0 + 0x10, 0, (f32)p[0x44], D_L32_001DE938);
    } else {
        *(f32 *)(a0 + 0x48) = 1.0f;
        *(f32 *)(p + 0x90) = 0.0f;
    }
    s = *(s32 *)(p + 0xF4);
    if (s == -3 && done) {
        func_L32_003A52A8(a0, 0x11);
    } else if (s == -1 || s == 0 || s == 2) {
        if (*(s32 *)(p + 0x100) != 0 ? *(f32 *)(a0 + 0x10) < *(f32 *)(p + 0x17C)
                                      : *(f32 *)(p + 0x17C) < *(f32 *)(a0 + 0x10)) {
            if (near) {
                func_L32_003A52A8(a0, 0x12);
            }
        } else if (done) {
            func_L32_003A52A8(a0, s == -1 ? 1 : (s == 0 ? 10 : 0x14));
        }
    } else if (s == 1) {
        if (*(s32 *)(p + 0xFC) != 0) {
            if (done) {
                func_L32_003A52A8(a0, 0xE);
            }
        } else if (near) {
            func_L32_003A52A8(a0, 0x12);
        }
    }
}
/* localdecomp:end func_L32_003A66B0 */

/* localdecomp:start func_L32_003A6920 */
__asm__(".extern D_L32_001DEACC, 4");
__asm__(".extern D_L32_001DEAC8, 4");
__asm__(".extern D_L32_001DEAB8, 4");
__asm__(".extern D_L32_001DEAB4, 4");
__asm__(".extern D_L32_001DEABC, 4");
__asm__(".extern D_L32_001DEAD4, 4");
__asm__(".extern D_L32_001DEAC4, 4");
__asm__(".extern D_L32_001DE9CC, 4");
__asm__(".extern D_L32_001DEB38, 4");
__asm__(".extern D_L32_001DEAD0, 4");
extern f32 D_L32_001DEACC;
extern f32 D_L32_001DEAC8;
extern s32 D_L32_001DEAB8;
extern s32 D_L32_001DEAB4;
extern f32 D_L32_001DEABC;
extern s32 D_L32_001DEAD4;
extern f32 D_L32_001DEAC4;
extern f32 D_L32_001DE9CC;
extern f32 D_L32_001DEB38;
extern f32 D_L32_001DEAD0;
extern s32 D_L32_001DF9C0;
extern u8 D_001A4C60[];
extern u8 *D_L32_002A3E50[];

typedef struct {
    u8 pad0[0x10];
    f32 x, y, z;
    u8 pad1C[0x23 - 0x1C];
    u8 alpha;
    u8 *cls;
    u8 pad28[0x34 - 0x28];
    u16 flags;
    u8 pad36[0x98 - 0x36];
    s32 f98;
    u8 pad9C[0xF8 - 0x9C];
    f32 fF8;
} M_003A6920;

extern f32 func_L03_0034B440(f32, f32, f32, s32, s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L30_0034C958(vu0_v4 *, f32);
extern u8 *func_L32_003B47A0(void *, void *, f32);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_0038CAD0(void *);
extern void func_L32_003A52A8(void *, s32);

void func_L32_003A6920(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 sx;
    f32 ex;
    f32 t;
    f32 f;
    f32 x;
    f32 o;
    s32 i;
    s32 placed;
    u8 *e;
    vu0_v4 buf;
    vu0_v4 vec;

    if (func_L01_004561B8(a0) != 0) {
        (*(M_003A6920 **)(p + 0x16C))->flags &= ~0x41;
        (*(M_003A6920 **)(p + 0x16C))->flags |= *(u16 *)((*(M_003A6920 **)(p + 0x16C))->cls + 0x44) & 0x1000;
        (*(M_003A6920 **)(p + 0x16C))->f98 = *(s32 *)((*(M_003A6920 **)(p + 0x16C))->cls + 0x10);
        (*(M_003A6920 **)(p + 0x170))->flags &= ~0x41;
        (*(M_003A6920 **)(p + 0x170))->flags |= *(u16 *)((*(M_003A6920 **)(p + 0x170))->cls + 0x44) & 0x1000;
        (*(M_003A6920 **)(p + 0x170))->f98 = *(s32 *)((*(M_003A6920 **)(p + 0x170))->cls + 0x10);
        (*(M_003A6920 **)(p + 0x16C))->x = (*(M_003A6920 **)(p + 0x170))->x = *(f32 *)(a0 + 0x10);
        (*(M_003A6920 **)(p + 0x16C))->y = *(f32 *)(a0 + 0x14) - D_L32_001DEACC;
        (*(M_003A6920 **)(p + 0x170))->y = *(f32 *)(a0 + 0x14) + D_L32_001DEACC;
        (*(M_003A6920 **)(p + 0x16C))->z = (*(M_003A6920 **)(p + 0x170))->z = *(f32 *)(a0 + 0x18) + D_L32_001DEAC8;
        (*(M_003A6920 **)(p + 0x16C))->fF8 = (*(M_003A6920 **)(p + 0x170))->fF8 = *(f32 *)(a0 + 0xF8);
        (*(M_003A6920 **)(p + 0x16C))->alpha = (*(M_003A6920 **)(p + 0x170))->alpha = 0;
        *(s32 *)(p + 0x11C) = 0;
        *(s32 *)(p + 0xA8) = D_L32_001DEAB8 - 1;
    }
    if (*(s32 *)(p + 0x11C) == 0) {
        f = func_L03_0034B440((f32)*(s32 *)(p + 0xA8), (f32)D_L32_001DEAB8, 1.0f, 1, 0, 0);
        (*(M_003A6920 **)(p + 0x16C))->alpha = (*(M_003A6920 **)(p + 0x170))->alpha = (s32)(f * 127.0f);
        if (func_0038CAD0(p + 0xA8) != 0) {
            *(s32 *)(p + 0xA8) = D_L32_001DEAB4 - 1;
            *(s32 *)(p + 0x11C) = 1;
            (*(M_003A6920 **)(p + 0x16C))->alpha = (*(M_003A6920 **)(p + 0x170))->alpha = 0x7F;
        }
    }
    if (*(s32 *)(p + 0x11C) == 1) {
        x = *(f32 *)(a0 + 0x10);
        if (*(s32 *)(p + 0x100) != 0) {
            o = -D_L32_001DEABC;
            sx = x + o;
        } else {
            sx = x + D_L32_001DEABC;
        }
        if (*(s32 *)(p + 0x100) == 0) {
            ex = *(f32 *)(p + 0x180) - D_L32_001DEABC;
        } else {
            ex = *(f32 *)(p + 0x178) + D_L32_001DEABC;
        }
        t = func_L03_0034B440((f32)*(s32 *)(p + 0xA8), (f32)D_L32_001DEAB4, 1.0f, 1, 0, 0);
        if (D_L32_001DF9C0 % D_L32_001DEAD4 == 0) {
            placed = 0;
            func_003C2F58(*(void **)(p + 0x170), 0, &buf);
            vec = *(vu0_v4 *)D_001A4C60;
            vec.x = func_003C4088(ex, sx, t);
            vec.z = *(f32 *)(p + 0x174) + D_L32_001DEAC4;
            func_L30_0034C958(&vec, D_L32_001DE9CC);
            buf.y += D_L32_001DEB38 * (1.0f - t);
            e = func_L32_003B47A0(&buf, &vec, D_L32_001DEAD0);
            for (i = 0; i < 32 && !placed; i++) {
                if (D_L32_002A3E50[i] == 0) {
                    D_L32_002A3E50[i] = e;
                    placed = 1;
                }
            }
        }
        if (func_0038CAD0(p + 0xA8) != 0) {
            *(s32 *)(p + 0xA8) = D_L32_001DEAB8;
            *(s32 *)(p + 0x11C) = 2;
        }
    }
    if (*(s32 *)(p + 0x11C) == 2) {
        f = func_L03_0034B440((f32)*(s32 *)(p + 0xA8), (f32)D_L32_001DEAB8, 1.0f, 0, 0, 0);
        (*(M_003A6920 **)(p + 0x16C))->alpha = (*(M_003A6920 **)(p + 0x170))->alpha = (s32)(f * 127.0f);
        if (func_0038CAD0(p + 0xA8) != 0) {
            (*(M_003A6920 **)(p + 0x16C))->flags |= 0x41;
            (*(M_003A6920 **)(p + 0x16C))->flags &= ~0x1000;
            (*(M_003A6920 **)(p + 0x16C))->f98 = 0;
            func_L01_004AA7E8(*(void **)(p + 0x16C), 1);
            (*(M_003A6920 **)(p + 0x170))->flags |= 0x41;
            (*(M_003A6920 **)(p + 0x170))->flags &= ~0x1000;
            (*(M_003A6920 **)(p + 0x170))->f98 = 0;
            func_L01_004AA7E8(*(void **)(p + 0x170), 1);
            func_L32_003A52A8(a0, 0xC);
        }
    }
}
/* localdecomp:end func_L32_003A6920 */

/* localdecomp:start func_L32_003A6D70 */
__asm__(".extern D_L32_001DEA74, 4");
__asm__(".extern D_L32_001DE8F0, 4");
__asm__(".extern D_L32_001DE8EC, 4");
__asm__(".extern D_L32_001DEA84, 4");
__asm__(".extern D_L32_001DE8DC, 4");
__asm__(".extern D_L32_001DE8F4, 4");
__asm__(".extern D_L32_001DE9D4, 4");
__asm__(".extern D_L32_001DEA88, 4");
__asm__(".extern D_L32_001DEA50, 4");
__asm__(".extern D_L32_001DE9D8, 4");
extern s32 D_L32_001DEA74;
extern f32 D_L32_001DE8F0;
extern f32 D_L32_001DE8EC;
extern f32 D_L32_001DEA84;
extern f32 D_L32_001DE8DC;
extern f32 D_L32_001DE8F4;
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DEA88;
extern f32 D_L32_001DEA50;
extern f32 D_L32_001DE9D8;
extern u8 D_001A4C60[];
extern s32 D_001A4BE0[];
extern s32 func_L01_004561B8(void *);
extern void func_L32_003A4360(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L31_00346B10(void *, void *, f32, f32, f32, f32, f32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A52A8(void *, s32);
extern f32 func_0038CF00(void *, void *);

void func_L32_003A6D70(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 f;
    f32 x;

    if (func_L01_004561B8(a0) != 0) {
        func_L32_003A4360(a0);
    }
    if (*(s32 *)(p + 0x100) != 0 ? *(f32 *)(p + 0x90) > 0.0f : *(f32 *)(p + 0x90) < 0.0f) {
        if (a0[0x43] != 4) {
            func_003C3A10(a0, 4, 0, D_L32_001DEA74);
        }
        *(f32 *)(a0 + 0x48) = D_L32_001DE8F0 * fabs_asm(*(f32 *)(p + 0x90)) / D_L32_001DEA84;
    } else {
        if (a0[0x43] != 3) {
            func_003C3A10(a0, 3, 0, D_L32_001DEA74);
        }
        *(f32 *)(a0 + 0x48) = D_L32_001DE8EC * fabs_asm(*(f32 *)(p + 0x90)) / D_L32_001DEA84;
    }
    func_L31_00346B10(a0, p + 0x90, *(f32 *)(p + 0xE0), D_L32_001DE8F4, D_L32_001DEA84, D_L32_001DE8DC, D_L32_001DE8DC);
    *(s32 *)(p + 0x110) = func_L30_0034D1E8(a0, a0 + 0x10, p + 0x90, p + 0x140, D_L32_001DE9D4, D_L32_001DE9D4,
                                            D_L32_001DEA88, D_L32_001DEA84, 0.0f, D_L32_001DEA50, 1, 1, 1, 0);
    f = *(f32 *)(a0 + 0x48);
    if (f > 5.0f) {
        *(f32 *)(a0 + 0x48) = 5.0f;
    } else if (f < 0.5f) {
        *(f32 *)(a0 + 0x48) = 0.5f;
    }
    /* hero pos.x (struct Hero +0x80) */
    if ((*(f32 *)((u8 *)D_001A4BE0 + 0x80) - *(f32 *)(a0 + 0x10)) * (*(f32 *)(p + 0xE0) - *(f32 *)(a0 + 0x10)) > 0.0f) {
        if (*(s32 *)(p + 0xF4) == 1) {
            func_L32_003A52A8(a0, 0x12);
        }
        if (*(s32 *)(p + 0xF4) == 2 || *(s32 *)(p + 0xF4) == 0) {
            func_L32_003A52A8(a0, 7);
        }
    }
    if (func_0038CF00(a0 + 0x10, D_001A4C60) < D_L32_001DE9D8 && *(s32 *)(p + 0xFC) != 0 && *(s32 *)(p + 0xF0) != 0) {
        func_L32_003A52A8(a0, *(s32 *)(p + 0x100) != 0 ? 0x10 : 0xF);
        return;
    }
    if (fabs_asm(*(f32 *)(p + 0xE0) - *(f32 *)(a0 + 0x10)) < D_L32_001DE8F4) {
        x = *(f32 *)(a0 + 0x10);
        if (*(s32 *)(p + 0xF4) == 1) {
            func_L32_003A52A8(a0, *(s32 *)(p + 0xFC) != 0 ? 7 : 0x12);
        } else if (*(s32 *)(p + 0xF4) == 0 || *(s32 *)(p + 0xF4) == 2) {
            if (*(s32 *)(p + 0x100) != 0 ? x < *(f32 *)(p + 0x17C) : *(f32 *)(p + 0x17C) < x) {
                func_L32_003A52A8(a0, 0x12);
            } else {
                func_L32_003A52A8(a0, *(s32 *)(p + 0xF4) == 0 ? 0xA : 0x14);
            }
        } else if (*(s32 *)(p + 0xF4) == -1) {
            func_L32_003A52A8(a0, 0x12);
        }
    }
}
/* localdecomp:end func_L32_003A6D70 */

/* localdecomp:start func_L32_003A70A0 */
__asm__(".extern D_L32_001DE8DC, 4");
__asm__(".extern D_L32_001DE8F4, 4");
__asm__(".extern D_L32_001DEA84, 4");
__asm__(".extern D_L32_001DE9D4, 4");
__asm__(".extern D_L32_001DEA88, 4");
__asm__(".extern D_L32_001DEA50, 4");
__asm__(".extern D_L32_001DE8EC, 4");
__asm__(".extern D_L32_001DE93C, 4");
extern f32 D_L32_001DE8DC;
extern f32 D_L32_001DE8F4;
extern f32 D_L32_001DEA84;
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DEA88;
extern f32 D_L32_001DEA50;
extern f32 D_L32_001DE8EC;
extern s32 D_L32_001DE93C;
extern u8 D_001A4C60[];
extern void func_L31_00346B10(void *, void *, f32, f32, f32, f32, f32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A52A8(void *, s32);

void func_L32_003A70A0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 f;
    s32 r;

    func_L31_00346B10(a0, p + 0x90, *(f32 *)D_001A4C60, D_L32_001DE8F4, D_L32_001DEA84, D_L32_001DE8DC, D_L32_001DE8DC);
    r = func_L30_0034D1E8(a0, a0 + 0x10, p + 0x90, p + 0x140, D_L32_001DE9D4, D_L32_001DE9D4,
                                            D_L32_001DEA88, D_L32_001DEA84, 0.0f, D_L32_001DEA50, 1, 1, 1, 0);
    f = D_L32_001DE8EC * fabs_asm(*(f32 *)(p + 0x90)) / D_L32_001DEA84;
    *(s32 *)(p + 0x110) = r;
    *(f32 *)(a0 + 0x48) = f;
    if (f > 5.0f) {
        *(f32 *)(a0 + 0x48) = 5.0f;
    } else if (f < 0.5f) {
        *(f32 *)(a0 + 0x48) = 0.5f;
    }
    if (*(s32 *)(p + 0xFC) == 0 || *(s32 *)(p + 0x12C) == 0) {
        func_L32_003A52A8(a0, 0x12);
    } else if (*(s32 *)(p + 0x134) != 0 && *(s32 *)(p + 0x138) != 0 && *(s32 *)(p + 0xF0) != 0) {
        s32 lim = D_L32_001DE93C;
        if (lim < ++*(s32 *)(p + 0x108)) {
            func_L32_003A52A8(a0, *(s32 *)(p + 0x100) != 0 ? 0x10 : 0xF);
        }
    }
}
/* localdecomp:end func_L32_003A70A0 */

/* localdecomp:start func_L32_003A7210 */
__asm__(".extern D_L32_001DE9E0, 4");
__asm__(".extern D_L32_001DEA08, 4");
__asm__(".extern D_L32_001DEA04, 4");
__asm__(".extern D_L32_001DEA34, 4");
__asm__(".extern D_L32_001DEA30, 4");
__asm__(".extern D_L32_001DEA38, 4");
__asm__(".extern D_L32_001DEA8C, 4");
__asm__(".extern D_L32_001DE9D4, 4");
__asm__(".extern D_L32_001DEA88, 4");
__asm__(".extern D_L32_001DEA54, 4");
__asm__(".extern D_L32_001DE9F8, 4");
__asm__(".extern D_L32_001DE9F4, 4");
__asm__(".extern D_L32_001DEA24, 4");
__asm__(".extern D_L32_001DEA20, 4");
__asm__(".extern D_L32_001DE90C, 4");
__asm__(".extern D_L32_001DE910, 4");
__asm__(".extern D_L32_001DE9EC, 4");
__asm__(".extern D_L32_001DE9FC, 4");
__asm__(".extern D_L32_001DEA18, 4");
__asm__(".extern D_L32_001DEA28, 4");
__asm__(".extern D_L32_001DE9C4, 4");
__asm__(".extern D_L32_001DE930, 4");
__asm__(".extern D_L32_001DE9B8, 4");
__asm__(".extern D_L32_001DEA3C, 4");
__asm__(".extern D_L32_001DE964, 1");
extern f32 D_L32_001DE9E0;
extern f32 D_L32_001DEA08;
extern f32 D_L32_001DEA04;
extern f32 D_L32_001DEA34;
extern f32 D_L32_001DEA30;
extern f32 D_L32_001DEA38;
extern f32 D_L32_001DEA8C;
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DEA88;
extern f32 D_L32_001DEA54;
extern f32 D_L32_001DE9F8;
extern f32 D_L32_001DE9F4;
extern f32 D_L32_001DEA24;
extern f32 D_L32_001DEA20;
extern f32 D_L32_001DE90C;
extern f32 D_L32_001DE910;
extern f32 D_L32_001DE9EC;
extern f32 D_L32_001DE9FC;
extern f32 D_L32_001DEA18;
extern f32 D_L32_001DEA28;
extern f32 D_L32_001DE9C4;
extern f32 D_L32_001DE930;
extern f32 D_L32_001DE9B8;
extern s32 D_L32_001DEA3C;
extern u8 D_L32_001DE964;
extern u8 *D_001E9998 __attribute__((section(".data")));
extern u8 D_001A4C60[];
extern f32 func_L01_004395E0(void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_00382498(s32, s32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern f32 func_L30_0034CE78(u8 *);
extern void func_003C2F58(void *, s32, void *);
extern void func_L32_00347FE8(u8 *, void *, f32, f32, s32, s32, s32, s32, s32);
extern void func_L32_003A52A8(void *, s32);
extern void func_L32_003A5850(void *arg0);

typedef struct {
    f32 x, y, z, w;
} V_003A7210 __attribute__((aligned(16)));

typedef struct {
    u8 pad0[0x84];
    f32 f84;
    u8 pad88[0x25C0 - 0x88];
    u8 *p25C0;
} S_1A4BE0_003A7210;
extern s32 D_001A4BE0[];

void func_L32_003A7210(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 t;
    f32 v;

    t = func_L01_004395E0(a0);
    if (func_L01_004561B8(a0) != 0) {
        if (a0[0x94] == 0xD) {
            *(s32 *)(p + 0x120) = 1;
        } else if (a0[0x94] == 4) {
            *(s32 *)(p + 0x120) = 2;
        } else if (a0[0x94] == 0xF || a0[0x94] == 0x10) {
            *(f32 *)(a0 + 0x48) = D_L32_001DE9E0;
            if (*(s32 *)(p + 0x120) <= 0) {
                *(s32 *)(p + 0x120) = 1;
            }
        } else if (a0[0x94] == 0xE) {
            s32 r = func_00382498(2, 3);
            *(s32 *)(p + 0x120) = r;
            *(s32 *)(p + 0x11C) = r == 3 && func_00382498(0, D_L32_001DEA3C) == 0;
        } else {
            *(s32 *)(p + 0x120) = 2;
        }
        *(f32 *)(p + 0x90) = 0.0f;
    }
    if ((a0[0x20] == 0xF && D_L32_001DEA08 < t && t < D_L32_001DEA04)
        || (a0[0x20] == 0x10 && D_L32_001DEA34 < t && t < D_L32_001DEA30)) {
        f32 o = *(f32 *)(p + 0x90);
        f32 k;
        f32 r;

        if (*(s32 *)(p + 0x100) != 0) {
            k = -D_L32_001DEA38;
            r = o + k;
        } else {
            k = D_L32_001DEA38;
            r = o + k;
        }
        *(f32 *)(p + 0x90) = r;
        v = D_L32_001DEA8C;
    } else {
        v = 0.0f;
    }
    *(s32 *)(p + 0x110) = func_L30_0034D1E8(a0, a0 + 0x10, p + 0x90, p + 0x140, D_L32_001DE9D4, D_L32_001DE9D4,
                                            D_L32_001DEA88, v, D_L32_001DEA54, 0.0f, 1, 1, 1, 0);
    if ((a0[0x20] == 0xF && D_L32_001DE9F8 < t && t < D_L32_001DE9F4)
        || (a0[0x20] == 0x10 && D_L32_001DEA24 < t && t < D_L32_001DEA20 && *(s32 *)(p + 0xFC) != 0)) {
        V_003A7210 a;
        V_003A7210 b;
        V_003A7210 d;
        f32 s;
        f32 o;
        f32 k;
        f32 r;

        qzero(&a);
        s = 1.0f;
        if (*(s32 *)(p + 0x100) != 0) {
            s = -1.0f;
        }
        b.x = *(f32 *)(a0 + 0x10);
        a.x = s;
        b.y = ((S_1A4BE0_003A7210 *)D_001A4BE0)->f84;
        b.z = *(f32 *)(a0 + 0x18) + func_L30_0034CE78(((S_1A4BE0_003A7210 *)D_001A4BE0)->p25C0);
        func_003C2F58(a0, a0[0x20] != 0xF, &d);
        o = d.x;
        if (b.x < o) {
            k = -D_L32_001DE90C;
            r = o + k;
        } else {
            k = D_L32_001DE90C;
            r = o + k;
        }
        d.x = r;
        func_L32_00347FE8(a0, &a, p[0x44], D_L32_001DE910, -1, -1, (s32)&d, (s32)&b, 1);
        if (D_001E9998 != 0 && *(s16 *)(D_001E9998 + 0xAA) == *(s16 *)(((S_1A4BE0_003A7210 *)D_001A4BE0)->p25C0 + 0xAA)) {
            D_L32_001DE964 = 1;
        }
    }
    if ((a0[0x60] & 2)
        || (a0[0x20] == 0xF && a0[0x42] == 8
            && ((*(s32 *)(p + 0x120) >= 2 && D_L32_001DE9EC < t) || D_L32_001DE9FC <= t))
        || (a0[0x20] == 0x10 && a0[0x43] == 9
            && ((*(s32 *)(p + 0x120) >= 2 && D_L32_001DEA18 < t) || D_L32_001DEA28 <= t))) {
        if (--*(s32 *)(p + 0x120) != 0) {
            func_L32_003A52A8(a0, a0[0x20] == 0xF ? 0x10 : 0xF);
        } else {
            func_L32_003A5850(a0);
            if (*(s32 *)(p + 0xF4) == 1) {
                if (*(s32 *)(p + 0x11C) != 0) {
                    func_L32_003A52A8(a0, 2);
                } else if (D_L32_001DE964 != 0 && *(s32 *)(p + 0xFC) != 0) {
                    func_L32_003A52A8(a0, 0x11);
                } else if (*(s32 *)(p + 0xFC) != 0) {
                    f32 d = *(s32 *)(p + 0x100) != 0 ? fabs_asm(*(f32 *)(a0 + 0x10) - (*(f32 *)(p + 0x180) - D_L32_001DE9C4))
                                                     : fabs_asm(*(f32 *)(a0 + 0x10) - (*(f32 *)(p + 0x178) + D_L32_001DE9C4));

                    if (*(s32 *)(p + 0x134) != 0 && *(s32 *)(p + 0x138) != 0 && *(s32 *)(p + 0xF0) != 0) {
                        func_L32_003A52A8(a0, *(s32 *)(p + 0x100) != 0 ? 0x10 : 0xF);
                    } else if (d < D_L32_001DE930) {
                        func_L32_003A52A8(a0, 0x12);
                    } else if (d < fabs_asm(*(f32 *)D_001A4C60 - *(f32 *)(a0 + 0x10))) {
                        func_L32_003A52A8(a0, 0xE);
                    } else {
                        func_L32_003A52A8(a0, 0xD);
                    }
                } else {
                    f32 d = *(s32 *)(p + 0x100) == 0 ? fabs_asm(*(f32 *)(a0 + 0x10) - (*(f32 *)(p + 0x180) - D_L32_001DE9C4))
                                                     : fabs_asm(*(f32 *)(a0 + 0x10) - (*(f32 *)(p + 0x178) + D_L32_001DE9C4));

                    if (fabs_asm(D_L32_001DE9B8 * (*(f32 *)(p + 0x180) - *(f32 *)(p + 0x178))) < d) {
                        func_L32_003A52A8(a0, 7);
                    } else {
                        func_L32_003A52A8(a0, 0x12);
                    }
                }
            }
        }
        D_L32_001DE964 = 0;
    }
}
/* localdecomp:end func_L32_003A7210 */

/* localdecomp:start func_L32_003A77D8 */
__asm__(".extern D_L32_001DE9D4, 4");
__asm__(".extern D_L32_001DEA88, 4");
__asm__(".extern D_L32_001DEA50, 4");
__asm__(".extern D_L32_001DEB3C, 4");
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DEA88;
extern f32 D_L32_001DEA50;
extern f32 D_L32_001DEB3C;
extern s32 D_001A4BE0[];
extern u8 D_00142660[];
extern s32 func_L01_004561B8(void *);
extern void func_L32_003C3F98(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A52A8(void *, s32);
extern void func_L32_003A5850(void *arg0);

void func_L32_003A77D8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 st;

    if (func_L01_004561B8(a0) != 0) {
        st = *(s32 *)(p + 0xF4);
        if (st == -3 && !(D_001A4BE0[0x6CE] & 4)) {
            D_001A4BE0[0x6CE] |= 4; /* byte 0x1B38 */
            D_00142660[0x77] |= 4;
            func_L32_003C3F98(*(s32 *)(p + 0x184), 1);
            func_L32_003C3F98(*(s32 *)(p + 0x184), 6);
        } else if (st == 0 || st == 2) {
            if (func_003824E0(0.0f, 1.0f) < D_L32_001DEB3C) {
                func_L32_003C3F98(*(s32 *)(p + 0x184), func_00382498(0, 1) ? 0 : 2);
            }
        }
    }
    *(s32 *)(p + 0x110) = func_L30_0034D1E8(a0, a0 + 0x10, p + 0x90, p + 0x140, D_L32_001DE9D4, D_L32_001DE9D4,
                                            D_L32_001DEA88, 0.0f, 0.0f, D_L32_001DEA50, 1, 1, 1, 0);
    if (*(s32 *)(p + 0x134) != 0 && *(s32 *)(p + 0x138) != 0 && *(s32 *)(p + 0xF0) != 0) {
        func_L32_003A52A8(a0, *(s32 *)(p + 0x100) != 0 ? 0x10 : 0xF);
    }
    if (a0[0x60] & 2) {
        func_L32_003A5850(a0);
    }
}
/* localdecomp:end func_L32_003A77D8 */

/* localdecomp:start func_L32_003A7948 */
__asm__(".extern D_L32_001DE8E8, 4");
__asm__(".extern D_L32_001DE8E4, 4");
__asm__(".extern D_L32_001DEA78, 4");
__asm__(".extern D_L32_001DEA7C, 4");
__asm__(".extern D_L32_001DEA84, 4");
__asm__(".extern D_L32_001DE8DC, 4");
__asm__(".extern D_L32_001DE9D4, 4");
__asm__(".extern D_L32_001DEA88, 4");
__asm__(".extern D_L32_001DEA50, 4");
__asm__(".extern D_L32_001DE8EC, 4");
__asm__(".extern D_L32_001DE934, 4");
__asm__(".extern D_L32_001DE9C4, 4");
__asm__(".extern D_L32_001DE8F4, 4");
__asm__(".extern D_L32_001DE9E8, 4");
__asm__(".extern D_L32_001DEA0C, 4");
extern f32 D_L32_001DE8E8;
extern f32 D_L32_001DE8E4;
extern f32 D_L32_001DEA78;
extern f32 D_L32_001DEA7C;
extern f32 D_L32_001DEA84;
extern f32 D_L32_001DE8DC;
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DEA88;
extern f32 D_L32_001DEA50;
extern f32 D_L32_001DE8EC;
extern f32 D_L32_001DE934;
extern f32 D_L32_001DE9C4;
extern f32 D_L32_001DE8F4;
extern f32 D_L32_001DE9E8;
extern f32 D_L32_001DEA0C;
extern u8 D_001A4C60[];
extern s32 func_L01_004561B8(void *);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L32_003A52A8(void *, s32);

void func_L32_003A7948(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 dir;
    f32 ang;
    f32 spd;
    f32 a;
    f32 step;
    f32 cur;
    f32 lim;
    f32 k;
    f32 t;
    f32 rate;
    f32 anim;
    s32 r;
    s32 edge;

    if (func_L01_004561B8(a0) != 0) {
        *(s32 *)(p + 0x130) = 0;
        *(f32 *)(p + 0x90) = 0.0f;
    }
    if (*(s32 *)(p + 0xF4) == 1) {
        dir = *(f32 *)(a0 + 0x10) < *(f32 *)D_001A4C60 ? D_L32_001DE8E8 : D_L32_001DE8E4;
    } else if (*(s32 *)(p + 0xF4) == 0 || *(s32 *)(p + 0xF4) == 2 || *(s32 *)(p + 0xF4) == -1) {
        dir = *(f32 *)(a0 + 0x10) < *(f32 *)(p + 0x17C) ? D_L32_001DE8E8 : D_L32_001DE8E4;
    }
    func_L01_00448890(a0 + 0xF8, p + 0x130, dir == D_L32_001DE8E4 ? -1 : 1, dir, D_L32_001DEA78, D_L32_001DEA78, D_L32_001DEA7C);
    ang = func_0038DB00(dir, *(f32 *)(a0 + 0xF8));
    spd = func_0038D098(func_0038DB48(ang));
    if (spd < 0.0f) {
        spd = 0.0f;
    }
    spd = D_L32_001DEA84 * fabs_asm(spd);
    if (spd > 0.0f && *(s32 *)(p + 0xF4) != 2 && *(s32 *)(p + 0xF4) != -1 && *(s32 *)(p + 0xF4) != 0) {
        cur = *(f32 *)(p + 0x90);
        if (dir != D_L32_001DE8E8) {
            step = -D_L32_001DE8DC;
        } else {
            step = D_L32_001DE8DC;
        }
        *(f32 *)(p + 0x90) = cur + step;
    }
    a = fabs_asm(ang);
    r = func_L30_0034D1E8(a0, a0 + 0x10, p + 0x90, p + 0x140, D_L32_001DE9D4, D_L32_001DE9D4,
                          D_L32_001DEA88, spd, 0.0f, D_L32_001DEA50, 1, 1, 1, 0);
    k = D_L32_001DE8EC;
    rate = k * fabs_asm(*(f32 *)(p + 0x90)) / D_L32_001DEA84;
    t = a / 2.0943952f;
    *(s32 *)(p + 0x110) = r;
    anim = func_003C4088(rate, k, t);
    lim = D_L32_001DE934;
    *(f32 *)(a0 + 0x48) = anim;
    if (a <= lim) {
        edge = 0;
        if (*(f32 *)(a0 + 0x10) <= *(f32 *)(p + 0x178) + D_L32_001DE9C4 + D_L32_001DE8F4 ||
            *(f32 *)(p + 0x180) - D_L32_001DE9C4 - D_L32_001DE8F4 <= *(f32 *)(a0 + 0x10)) {
            edge = 1;
        }
        if (*(s32 *)(p + 0xF4) == -1) {
            func_L32_003A52A8(a0, edge ? 1 : 0xD);
        }
        if (*(s32 *)(p + 0xF4) == 0) {
            func_L32_003A52A8(a0, edge ? 0xA : 0xD);
        }
        if (*(s32 *)(p + 0xF4) == 1) {
            if (func_003824E0(0.0f, 1.0f) < D_L32_001DE9E8 &&
                D_L32_001DEA0C <= fabs_asm(*(f32 *)D_001A4C60 - *(f32 *)(a0 + 0x10))) {
                func_L32_003A52A8(a0, 7);
            } else {
                func_L32_003A52A8(a0, 0xE);
            }
        }
        if (*(s32 *)(p + 0xF4) == 2) {
            func_L32_003A52A8(a0, edge ? 0x14 : 0xD);
        }
    }
}
/* localdecomp:end func_L32_003A7948 */

/* localdecomp:start func_L32_003A7C88 */
__asm__(".extern D_L32_001DEC54, 4");
__asm__(".extern D_L32_001DE980, 4");
__asm__(".extern D_L32_001DE8E0, 4");
extern s32 D_L32_001DEC54;
extern s32 D_L32_001DE980;
extern s32 D_L32_001DE984;
extern s32 D_L32_001DE988;
extern s32 D_L32_001DE8E0;
extern f32 D_L32_001E1AF0;
extern f32 D_L32_001E1AF4;
extern f32 D_L32_001E1AF8;
extern f32 D_L32_001E1AFC;
extern f32 D_L32_001E1B00;
extern f32 D_L32_001E1B04;
extern s32 func_L01_004561B8(void *);
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern void func_L30_004CF4B0(s32, s32);
extern void func_L01_0045F1E8(s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_L32_003A52A8(void *, s32);
extern u8 D_001A4C60[];
extern u8 *D_L32_001DFE1C;

void func_L32_003A7C88(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *e;
    u8 *m;
    f32 a, b, c;
    s32 h;

    if (func_L01_004561B8(a0) != 0) {
        *(s32 *)(p + 0x120) = -1;
    }
    if (func_00382380(D_001A4C60, *(s32 *)(p + 0xD8), 0) != 0) {
        m = *(u8 **)(p + 0x160);
        if (m != 0) {
            m = *(u8 **)(m + 0x68);
            if (m != 0 && *(s32 *)(p + 0xD4) != 0 && *(s32 *)(p + 0xC0) != -1 && *(s32 *)(p + 0xD0) != -1
                && *(s32 *)(p + 0x120) == -1) {
                e = m + 0x4C;
                *(f32 *)(e + (*(s32 *)(p + 0xC0) << 5)) = 1.0f;
                *(s32 *)(e + (*(s32 *)(p + 0xD0) << 5)) = 0;
                D_L32_001DEC54 = 0;
                func_L30_004CF4B0(0x74, 1);
                *(s32 *)(p + 0x11C) = 0;
                if (*(s32 *)(p + 0xC4) != -1) {
                    func_L01_00456230(D_L32_001DFE1C + (*(s32 *)(p + 0xC4) << 8), 1);
                }
                h = *(s32 *)(p + 0x194);
                a = D_L32_001DE980;
                b = D_L32_001DE984;
                c = D_L32_001DE988;
                D_L32_001E1AF4 = a;
                D_L32_001E1AFC = b;
                D_L32_001E1B04 = c;
                D_L32_001E1AF0 = a;
                D_L32_001E1AF8 = b;
                D_L32_001E1B00 = c;
                *(s32 *)(p + 0x120) = D_L32_001DE8E0;
                func_L01_0045F1E8(h, -1);
            }
        }
    }
    if (*(s32 *)(p + 0x120) >= 0) {
        if (func_0038CAD0(p + 0x120) != 0) {
            func_L32_003A52A8(a0, 9);
        }
    }
}
/* localdecomp:end func_L32_003A7C88 */

/* localdecomp:start func_L32_003A7E18 */
extern s32 D_L32_001DEA68;
extern s32 D_L32_001DEA64;
extern s32 D_L32_001DE9D0;
extern f32 D_L32_001DEA98;
extern f32 D_L32_001DEA9C;
extern f32 D_L32_001DEAA0;
__asm__(".extern D_L32_001DEA68, 4");
__asm__(".extern D_L32_001DEA64, 4");
__asm__(".extern D_L32_001DE9D0, 4");
__asm__(".extern D_L32_001DEA98, 4");
__asm__(".extern D_L32_001DEA9C, 4");
__asm__(".extern D_L32_001DEAA0, 4");
extern s32 func_L01_004561B8(void *);
extern f32 func_003824E0(f32, f32);
extern void func_L32_003A52A8(void *, s32);
extern s32 func_0038CAD0(void *);
extern void func_L32_003A5850(void *arg0);
extern void func_L32_003BE8E0(void *, s32);

void func_L32_003A7E18(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 pos;
    f32 x, y, k;
    if (func_L01_004561B8(a0)) {
        s32 e = D_L32_001DEA68;
        *(s32 *)(v + 0xA8) = 0;
        *(s32 *)(v + 0x120) = e;
        x = *(f32 *)(a0 + 0x10);
        *(f32 *)(v + 0x13C) = x;
        if (*(s32 *)(v + 0x100)) {
            y = x - D_L32_001DEA98;
        } else {
            y = x + D_L32_001DEA98;
        }
        k = D_L32_001DEA9C;
        *(f32 *)(v + 0x13C) = y;
        *(f32 *)(v + 0x13C) += func_003824E0(-k, k);
    }
    if (func_0038CAD0(v + 0x120)) {
        s32 t;
        s32 d = D_L32_001DEA68;
        s32 u = D_L32_001DEA64;
        *(s32 *)(v + 0xA8) += 1;
        *(s32 *)(v + 0x120) = d;
        t = u - d;
        pos = *(vu0_v4 *)(a0 + 0x10);
        pos.x = *(f32 *)(v + 0x13C);
        pos.z = *(f32 *)(v + 0x174);
        func_L32_003BE8E0(&pos, *(s32 *)(v + 0xA8) * t);
        x = *(f32 *)(v + 0x13C);
        if (*(s32 *)(v + 0x100)) {
            *(f32 *)(v + 0x13C) = x - D_L32_001DEAA0;
        } else {
            *(f32 *)(v + 0x13C) = x + D_L32_001DEAA0;
        }
    }
    if (*(s32 *)(v + 0xA8) >= D_L32_001DE9D0) {
        if (*(s32 *)(v + 0xFC)) {
            func_L32_003A52A8(a0, 0x11);
        } else {
            func_L32_003A5850(a0);
        }
    }
}
/* localdecomp:end func_L32_003A7E18 */

INCLUDE_ASM("asm/levels", func_L32_003A7F48);
