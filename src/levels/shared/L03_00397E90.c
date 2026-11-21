#include "common.h"

/* localdecomp:start func_L03_00397E90 */
typedef int Q_00397E90 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x4D8];
    s32 id;
    f32 speed;
    f32 target;
    s32 timer;
    s32 effect;
} V_00397E90;

extern void func_L03_00398500(u8 *);
extern void func_L01_0044F450(void *, void *);
extern u8 *D_L03_001DFA80;
extern u8 D_001426E8[], D_001A30B0[], D_001A4C60[];
extern s32 D_L03_002D09B0[];
extern u8 *D_001D52FC;
extern s16 D_001A4DF2[];
extern u16 D_001A801C[], D_001A8538[];
extern s32 D_001A74A4[];
extern u8 D_001D5530[] __attribute__((section(".sdata")));
extern u8 D_00142660[], D_001426E0[], D_001426F4[];
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L03_00398E30(u8 *, s32, s32);
extern void func_L03_00399010(u8 *, s32, s32);
extern s32 func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_005003D0(s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_L01_003F3740(s32);
extern void func_L01_003F3768(s32);
extern s32 func_0038CAD0(void *);
extern void func_L01_0041A5B0(s32, s32);
extern f32 func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern s32 func_0039EF28(void);
extern void func_L01_0041BE28(s32, s32);
extern void func_L03_00398900(u8 *);
extern void func_L03_00398A78(u8 *);
extern void func_L03_00398D50(u8 *);

void func_L03_00397E90(u8 *a) {
    V_00397E90 *d;
    s32 i;
    func_L03_00398500(a);
    d = *(V_00397E90 **)(a + 0x68);
    func_L01_0044F450(a, d);
    *(Q_00397E90 *)(D_L03_001DFA80 + (d->id << 7) + 0x30) = *(Q_00397E90 *)(a + 0x10);
    switch (a[0x20]) {
    case 1:
        if (D_001426E8[0]) {
            { s32 h = d->effect; u8 *p;
            if (h == -1 || ((p = D_001A30B0 + (h << 7)), (*(u8 **)(p + 0xDC) != a || p[0xD0] == 0)))
                d->effect = func_003A52A0(1, 4, a); }
            func_L01_004450F0(a, 2, -1);
        }
        break;
    case 2:
        func_L03_00398E30(a, 0, 3);
        break;
    case 3:
        if (func_00382380(D_001A4C60, d->id, 0)) func_L01_004450F0(a, 4, -1);
        break;
    case 4:
        if (!func_00382380(D_001A4C60, d->id, 0)) {
            func_L01_004450F0(a, 3, -1);
            break;
        }
        func_L01_00452560(0, 11, 0xA26, 1, 0, 0, 0);
        if (D_L03_002D09B0[0] == 11 && (*(s32 *)(D_001D52FC + 0x1A4) & 0x10)) {
            *(s32 *)(D_001A4C60 + 0x2844) = 1;
            func_L01_005003D0(0x74, 1);
            { s32 h = d->effect; u8 *p;
            if (h == -1 || ((p = D_001A30B0 + (h << 7)), (*(u8 **)(p + 0xDC) != a || p[0xD0] == 0)))
                d->effect = func_003A52A0(1, 4, a); }
            func_L01_004450F0(a, 5, -1);
        }
        break;
    case 5:
        func_L03_00399010(a, 0, 6);
        break;
    case 6:
        if (func_L01_004561B8(a)) {
            func_L01_003F3740(0);
            d->timer = 125;
        }
        D_001A4DF2[0] = 4;
        if (func_0038CAD0(&d->timer) && !D_001A801C[0]) func_L01_0041A5B0(0xB88, 0x2B);
        func_003C41A0((f32 *)(a + 0x14), &d->speed, 325.0f, 0.003200000152f, 0.003200000152f, 0.3200000226f);
        if (*(f32 *)(a + 0x14) == 325.0f) {
            { s32 h = d->effect; u8 *p;
            if (h != -1 && ((p = D_001A30B0 + (h << 7)), (*(u8 **)(p + 0xDC) == a && p[0xD0]))) func_003A4F28(h); }
            d->effect = -1;
            d->effect = func_003A52A0(1, 4, a);
            func_L01_003F3768(0);
            func_L01_004450F0(a, 7, -1);
        }
        break;
    case 7:
        func_L03_00398E30(a, 1, 9);
        break;
    case 9:
        if (func_00382380(D_001A4C60, d->id, 0)) func_L01_004450F0(a, 10, -1);
        break;
    case 10: {
        s32 on = 1;
        func_L01_00452560(0, 11, 0xA27, on, 0, 0, 0);
        if (D_L03_002D09B0[0] == 11 && (*(s32 *)(D_001D52FC + 0x1A4) & 0x10)) {
            D_001A74A4[0] = on;
            func_L01_005003D0(0x74, 1);
            { s32 h = d->effect; u8 *p;
            if (h == -1 || ((p = D_001A30B0 + (h << 7)), (*(u8 **)(p + 0xDC) != a || p[0xD0] == 0)))
                d->effect = func_003A52A0(1, 4, a); }
            func_L01_004450F0(a, 11, -1);
        } else if (!func_00382380(D_001A4C60, d->id, 0)) {
            func_L01_004450F0(a, 9, -1);
        }
        break;
    }
    case 11:
        func_L03_00399010(a, 1, 12);
        break;
    case 12:
        if (func_L01_004561B8(a)) func_L01_003F3740(0);
        if (D_001D5530[4] && !D_001A8538[0]) func_L01_0041A5B0(0xCF1, 0x98);
        D_001A4DF2[0] = 4;
        func_003C41A0((f32 *)(a + 0x14), &d->speed, d->target, 0.003200000152f, 0.003200000152f, 0.3200000226f);
        if (*(f32 *)(a + 0x14) == d->target) {
            u8 *gs = D_00142660;
            for (i = 1; i < 5; i++) {
                if ((u32)i < 8 && ((D_001426E0[0x3E] >> i) & 1)
                    && ((u32)i >= 8 || (((D_001426E0[0x75] >> i) ^ 1) & 1))
                    && *(s16 *)(gs + 0x40) < i) {
                    if ((u32)i < 8) D_001426E0[0x75] |= 1 << i;
                    func_0039EF28();
                    func_L01_0041A5B0(0xC9A, 0x5D);
                    switch (i) {
                    case 2: func_L01_0041BE28(0x15FA, 0x131); break;
                    case 3: func_L01_0041BE28(0x15FB, 0x132); break;
                    }
                }
            }
            { s32 h = d->effect; u8 *p;
            if (h != -1 && ((p = D_001A30B0 + (h << 7)), (*(u8 **)(p + 0xDC) == a && p[0xD0]))) func_003A4F28(h); }
            d->effect = -1;
            d->effect = func_003A52A0(1, 4, a);
            func_L01_004450F0(a, 2, -1);
            func_L01_003F3768(0);
        }
        break;
    case 13:
        if (D_001426F4[0]) {
            func_L03_00398900(a);
            func_L03_00398A78(a);
            func_L03_00398D50(a);
            func_L01_004450F0(a, 9, -1);
        }
        break;
    }
}
/* localdecomp:end func_L03_00397E90 */

/* localdecomp:start func_L03_00398500 */
extern u8 *D_L03_001DF99C_00398500;
extern s32 D_001D545C;
extern u8 D_00142CBE[];
extern s32 D_00142C14[];
extern u8 D_00142754[];
extern s32 D_00142C18[];
extern u8 D_001426F4[];
extern f32 D_001A4C64[];
extern void func_L01_0044ED88_00398500(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044F888_00398500(void *, s32, s32, void *, s32);
extern void func_L01_004450F0_00398500(void *, s32, s32);
extern void func_L03_00398760_00398500(u8 *);
extern void func_L03_00398A78_00398500(u8 *);
extern void func_L03_00398BF0_00398500(u8 *);
extern void func_L03_00398D50_00398500(u8 *);
extern void func_L03_00398DA0_00398500(u8 *, s32, s32);

void func_L03_00398500(u8 *m) {
    u8 *v;
    s32 i;
    if (m[0x20] != 0) {
        return;
    }
    v = *(u8 **)(m + 0x68);
    *(f32 *)(v + 0x4E0) = *(f32 *)(m + 0x14);
    func_L01_0044ED88_00398500(m, v, 0xC, *(s32 *)(v + 0x4C4), *(s32 *)(v + 0x4C0), -1, 7, 0);
    for (i = 0; i < 12; i++) {
        u8 *e = (u8 *)((s32)v + i * 0x50);
        if (e[0x4C] == 0) {
            s16 id = *(s16 *)(e + 0x48);
            u8 *t = D_L03_001DF99C_00398500 + (id << 8);
            s16 k = *(s16 *)(t + 0xAA);
            if (k == 0x18DD || k == 0x18EB) {
                u8 *q = *(u8 **)(t + 0x68);
                func_L01_0044F888_00398500(v, 0, id, v + 0x3C0 + q[0] * 0x80 + q[1] * 0x20, 0x80);
            }
        }
    }
    if (D_001D545C == 3) {
        if ((D_00142CBE[0] != 0 && !(D_00142C14[0] & 0x400000)) ||
            (D_00142754[0] != 0 && !(D_00142C18[0] & 0x1000000))) {
            func_L03_00398D50_00398500(m);
            func_L01_004450F0_00398500(m, 9, -1);
        } else {
            func_L03_00398DA0_00398500(m, 0, -1);
            func_L03_00398DA0_00398500(m, 1, -1);
            func_L01_004450F0_00398500(m, 1, -1);
        }
        *(s16 *)(v + 0x4EC) = -1;
        *(s32 *)(v + 0x4E8) = -1;
    } else if (D_001426F4[0] != 0) {
        func_L03_00398A78_00398500(m);
        if (*(f32 *)(m + 0x14) > D_001A4C64[0]) {
            func_L03_00398DA0_00398500(m, 0, 1);
            func_L03_00398DA0_00398500(m, 1, -1);
            func_L01_004450F0_00398500(m, 3, -1);
        } else {
            func_L03_00398D50_00398500(m);
            func_L01_004450F0_00398500(m, 9, -1);
        }
    } else {
        func_L03_00398760_00398500(m);
        func_L03_00398BF0_00398500(m);
        func_L01_004450F0_00398500(m, 0xD, -1);
    }
}
/* localdecomp:end func_L03_00398500 */

/* localdecomp:start func_L03_00398760 */
typedef struct {
    u8 pad0[0x3C];
    u16 flags3C;
} E_A_00398760;

typedef struct {
    u8 pad0[0x24];
    u8 *p24;
    u8 pad28[0xC];
    u16 flags34;
    u8 pad36[0x62];
    s32 w98;
} E_B_00398760;

extern s16 **D_L03_001D6764_00398760;
extern u8 *D_L03_001E0854_00398760;
extern E_A_00398760 *D_L03_0023A700_00398760[];
extern s16 *D_L03_0021C620_00398760[];
extern u8 *D_L03_001DF99C_00398760;
extern s32 D_L03_001DF9D8_00398760;
extern void func_L01_004AA7E8_00398760(E_B_00398760 *, s32);

void func_L03_00398760(u8 *a0) {
    u8 *b = *(u8 **)(a0 + 0x68);
    s16 *p;
    u8 *e;
    E_B_00398760 *t;
    s16 *r;
    s32 n;
    p = D_L03_001D6764_00398760[*(s32 *)(b + 0x4C0)];
    while (p != 0) {
        if (p[-1] < 0 && p != D_L03_001D6764_00398760[*(s32 *)(b + 0x4C0)]) break;
        e = D_L03_001E0854_00398760 + ((u16)p[0] & 0x7FFF) * 32;
        if (e == 0) break;
        p += 1;
        D_L03_0023A700_00398760[e[0x1D]]->flags3C |= 1;
    }
    r = D_L03_0021C620_00398760[*(s32 *)(b + 0x4C4)];
    while (((n = *(s32 *)(b + 0x4C4)) & 0xFF) != 0xFF && n <= D_L03_001DF9D8_00398760 && r != 0) {
        if (r[-1] < 0 && r != D_L03_0021C620_00398760[n]) break;
        t = (E_B_00398760 *)(D_L03_001DF99C_00398760 + (((u16)r[0] & 0x7FFF) << 8));
        if (t == 0) break;
        t->w98 = 0;
        t->flags34 |= 0x41;
        t->flags34 &= 0xEFFF;
        func_L01_004AA7E8_00398760(t, 1);
        r += 1;
    }
}
/* localdecomp:end func_L03_00398760 */

/* localdecomp:start func_L03_00398900 */
typedef struct {
    u8 pad0[0x3C];
    u16 flags3C;
} E_A_00398900;

typedef struct {
    u8 pad0[0x24];
    u8 *p24;
    u8 pad28[0xC];
    u16 flags34;
    u8 pad36[0x62];
    s32 w98;
} E_B_00398900;

extern s16 **D_L03_001D6764_00398900;
extern u8 *D_L03_001E0854_00398900;
extern E_A_00398900 *D_L03_0023A700_00398900[];
extern s16 *D_L03_0021C620_00398900[];
extern u8 *D_L03_001DF99C_00398900;
extern s32 D_L03_001DF9D8_00398900;

void func_L03_00398900(u8 *a0) {
    u8 *b = *(u8 **)(a0 + 0x68);
    s16 *p;
    u8 *e;
    E_B_00398900 *t;
    s16 *r;
    s32 n;
    p = D_L03_001D6764_00398900[*(s32 *)(b + 0x4C0)];
    while (p != 0) {
        if (p[-1] < 0 && p != D_L03_001D6764_00398900[*(s32 *)(b + 0x4C0)]) break;
        e = D_L03_001E0854_00398900 + ((u16)p[0] & 0x7FFF) * 32;
        if (e == 0) break;
        p += 1;
        D_L03_0023A700_00398900[e[0x1D]]->flags3C &= 0xFFFE;
    }
    r = D_L03_0021C620_00398900[*(s32 *)(b + 0x4C4)];
    while (((n = *(s32 *)(b + 0x4C4)) & 0xFF) != 0xFF && n <= D_L03_001DF9D8_00398900 && r != 0) {
        if (r[-1] < 0 && r != D_L03_0021C620_00398900[n]) break;
        t = (E_B_00398900 *)(D_L03_001DF99C_00398900 + (((u16)r[0] & 0x7FFF) << 8));
        if (t == 0) break;
        t->flags34 &= 0xFFBE;
        t->flags34 |= *(u16 *)(t->p24 + 0x44) & 0x1000;
        t->w98 = *(s32 *)(t->p24 + 0x10);
        r += 1;
    }
}
/* localdecomp:end func_L03_00398900 */

/* localdecomp:start func_L03_00398A78 */
typedef struct {
    u8 pad0[0x3C];
    u16 flags3C;
} E_A_00398A78;

typedef struct {
    u8 pad0[0x24];
    u8 *p24;
    u8 pad28[0xC];
    u16 flags34;
    u8 pad36[0x62];
    s32 w98;
} E_B_00398A78;

extern s16 **D_L03_001D6764_00398A78;
__asm__(".extern D_L03_001D6764_00398A78, 4");
extern u8 *D_L03_001E0854_00398A78;
extern E_A_00398A78 *D_L03_0023A700_00398A78[];
extern s16 *D_L03_0021C620_00398A78[];
extern u8 *D_L03_001DF99C_00398A78;
extern s32 D_L03_001DF9D8_00398A78;
__asm__(".extern D_L03_001DF9D8_00398A78, 4");
extern void func_L01_004AA7E8_00398A78(E_B_00398A78 *, s32);

void func_L03_00398A78(u8 *a0) {
    u8 *b = *(u8 **)(a0 + 0x68);
    s16 *p;
    u8 *e;
    E_B_00398A78 *t;
    s32 n;
    if (*(s32 *)(b + 0x4C8) != -1) {
        s16 **list = D_L03_001D6764_00398A78;
        p = list[*(s32 *)(b + 0x4C8)];
        while (p != 0) {
            if (p[-1] < 0 && p != D_L03_001D6764_00398A78[*(s32 *)(b + 0x4C8)]) break;
            e = D_L03_001E0854_00398A78 + ((u16)p[0] & 0x7FFF) * 32;
            if (e == 0) break;
            p += 1;
            D_L03_0023A700_00398A78[e[0x1D]]->flags3C |= 1;
        }
    }
    if (*(s32 *)(b + 0x4CC) != -1) {
        s16 *r = D_L03_0021C620_00398A78[*(s32 *)(b + 0x4CC)];
        while (((n = *(s32 *)(b + 0x4CC)) & 0xFF) != 0xFF && n <= D_L03_001DF9D8_00398A78 && r != 0) {
            if (r[-1] < 0 && r != D_L03_0021C620_00398A78[n]) break;
            t = (E_B_00398A78 *)(D_L03_001DF99C_00398A78 + (((u16)r[0] & 0x7FFF) << 8));
            if (t == 0) break;
            t->w98 = 0;
            t->flags34 |= 0x41;
            t->flags34 &= 0xEFFF;
            func_L01_004AA7E8_00398A78(t, 1);
            r += 1;
        }
    }
}
/* localdecomp:end func_L03_00398A78 */

/* localdecomp:start func_L03_00398BF0 */
typedef struct {
    u8 pad0[0x3C];
    u16 flags3C;
} E_A_00398BF0;

typedef struct {
    u8 pad0[0x24];
    u8 *p24;
    u8 pad28[0xC];
    u16 flags34;
    u8 pad36[0x62];
    s32 w98;
} E_B_00398BF0;

extern s16 **D_L03_001D6764_00398BF0;
__asm__(".extern D_L03_001D6764_00398BF0, 4");
extern u8 *D_L03_001E0854_00398BF0;
extern E_A_00398900 *D_L03_0023A700_00398BF0[];
extern s16 *D_L03_0021C620_00398BF0[];
extern u8 *D_L03_001DF99C_00398BF0;
extern s32 D_L03_001DF9D8_00398BF0;
__asm__(".extern D_L03_001DF9D8_00398BF0, 4");

void func_L03_00398BF0(u8 *a0) {
    u8 *b = *(u8 **)(a0 + 0x68);
    s16 *p;
    u8 *e;
    E_B_00398BF0 *t;
    u8 *q;
    s32 m;
    s32 n;
    if (*(s32 *)(b + 0x4C8) != -1) {
        s16 **list = D_L03_001D6764_00398BF0;
        p = list[*(s32 *)(b + 0x4C8)];
        m = -2;
        while (p != 0) {
            if (p[-1] < 0 && p != D_L03_001D6764_00398BF0[*(s32 *)(b + 0x4C8)]) break;
            e = D_L03_001E0854_00398BF0 + ((u16)p[0] & 0x7FFF) * 32;
            if (e == 0) break;
            p += 1;
            D_L03_0023A700_00398BF0[e[0x1D]]->flags3C &= m;
        }
    }
    if (*(s32 *)(b + 0x4CC) != -1) {
        s16 *r = D_L03_0021C620_00398BF0[*(s32 *)(b + 0x4CC)];
        while (((n = *(s32 *)(b + 0x4CC)) & 0xFF) != 0xFF && n <= D_L03_001DF9D8_00398BF0 && r != 0) {
            if (r[-1] < 0 && r != D_L03_0021C620_00398BF0[n]) break;
            t = (E_B_00398BF0 *)(D_L03_001DF99C_00398BF0 + (((u16)r[0] & 0x7FFF) << 8));
            r += 1;
            if (t == 0) break;
            t->flags34 &= 0xFFBE;
            t->flags34 |= *(u16 *)(t->p24 + 0x44) & 0x1000;
            t->w98 = *(s32 *)(t->p24 + 0x10);
        }
    }
}
/* localdecomp:end func_L03_00398BF0 */

/* localdecomp:start func_L03_00398D50 */
extern void func_L03_00398DA0(u8 *, s32, s32);

void func_L03_00398D50(u8 *obj) {
    func_L03_00398DA0(obj, 0, -1);
    func_L03_00398DA0(obj, 1, 1);
    *(f32 *)(obj + 20) = 325.0f;
}
/* localdecomp:end func_L03_00398D50 */

/* localdecomp:start func_L03_00398DA0 */
void func_L03_00398DA0(u8 *a0, s32 i, s32 mode) {
    s32 k;
    u8 *b = *(u8 **)(a0 + 0x68);
    f32 *p;
    b += 0x3C0;
    p = (f32 *)((i << 7) + (s32)b);
    for (k = 0; k < 4; k++) {
        if (mode == 1) {
            *p = (f32)k * 0.0047996556f + 0.39269909f;
        } else {
            *p = (f32)k * -0.39269909f;
        }
        p += 8;
    }
}
/* localdecomp:end func_L03_00398DA0 */

/* localdecomp:start func_L03_00398E30 */
typedef struct {
    u8 pad[0x4D0];
    f32 target;
    f32 speed;
    u8 pad4D8[0x10];
    s32 effect;
    s16 state;
} Vars_398E30;
extern f32 func_L03_00399218(s32, s32);
extern f32 func_L01_00448890(void *, void *, f32, f32, f32, f32, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern u8 D_001A30B0[];
extern void func_003A4F28(s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L03_00398E30(u8 *m, s32 index, s32 state) {
    Vars_398E30 *v = *(Vars_398E30 **)(m + 0x68);
    f32 *angle;
    f32 step, target;
    s32 i;
    s32 effect;
    u8 *e;
    if (v->state == -1) {
        v->speed = 0.0f;
        v->state = 3;
        v->target = func_L03_00399218(3, 1);
    }
    angle = (f32 *)((u8 *)v + 0x3C0 + (index << 7) + v->state * 0x20);
    target = func_L03_00399218(0, 1);
    step = func_L01_00448890(angle, &v->speed, target, 0.00069813174f, 0.00069813174f, 54.000004f, 0);
    for (i = 3; i > v->state; i--) {
        f32 *p = (f32 *)((index << 7) + (u32)v + (i << 5));
        *(f32 *)((u8 *)p + 0x3C0) = func_0038DAB8(*(f32 *)((u8 *)p + 0x3C0), step);
    }
    if (func_0038DB00(*(f32 *)((u8 *)v + ((v->state << 5) + (index << 7)) + 0x3C0), v->target) >= 0.0f) {
        if (v->state > 0) {
            v->state--;
            v->target = func_L03_00399218(v->state, 1);
        } else {
            v->speed = 0.0f;
            v->state = -1;
            effect = v->effect;
            if (effect != -1) {
                e = D_001A30B0 + (effect << 7);
                if (*(u8 **)(e + 0xDC) == m && e[0xD0]) {
                    func_003A4F28(effect);
                }
            }
            v->effect = -1;
            func_L01_004450F0(m, state, -1);
        }
    }
}
/* localdecomp:end func_L03_00398E30 */

/* localdecomp:start func_L03_00399010 */
typedef struct {
    u8 pad[0x4D0];
    f32 target;
    f32 speed;
    u8 pad4D8[0x10];
    s32 effect;
    s16 state;
} Vars_399010;
extern f32 func_L03_00399218(s32, s32);
extern f32 func_L01_00448890(void *, void *, f32, f32, f32, f32, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern s32 D_001A74A4[];
__asm__(".extern D_001A74A4, 16");
extern u8 D_001A30B0[];
extern void func_L01_005003D0(s32, s32);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_004450F0(void *, s32, s32);

void func_L03_00399010(u8 *m, s32 index, s32 state) {
    Vars_399010 *v = *(Vars_399010 **)(m + 0x68);
    f32 *angle;
    f32 step, target;
    s32 i;
    s32 effect;
    u8 *e;
    if (v->state == -1) {
        v->state = 0;
        v->speed = 0.0f;
        v->target = func_L03_00399218(0, -1);
    }
    angle = (f32 *)((u8 *)v + 0x3C0 + (index << 7) + v->state * 0x20);
    target = func_L03_00399218(3, -1);
    step = func_L01_00448890(angle, &v->speed, target, 0.00069813174f, 0.00069813174f, 54.000004f, 0);
    for (i = 3; i > v->state; i--) {
        f32 *p = (f32 *)((index << 7) + (u32)v + (i << 5));
        *(f32 *)((u8 *)p + 0x3C0) = func_0038DAB8(*(f32 *)((u8 *)p + 0x3C0), step);
    }
    if (func_0038DB00(*(f32 *)((u8 *)v + ((v->state << 5) + (index << 7)) + 0x3C0), v->target) <= 0.0f) {
        if (v->state < 3) {
            v->state++;
            v->target = func_L03_00399218(v->state, -1);
        } else {
            v->speed = 0.0f;
            v->state = -1;
            D_001A74A4[0] = 0;
            func_L01_005003D0(0, 1);
            effect = v->effect;
            if (effect != -1) {
                e = D_001A30B0 + (effect << 7);
                if (*(u8 **)(e + 0xDC) == m && e[0xD0]) {
                    func_003A4F28(effect);
                }
            }
            v->effect = -1;
            v->effect = func_003A52A0(0, 4, m);
            func_L01_004450F0(m, state, -1);
        }
    }
}
/* localdecomp:end func_L03_00399010 */

/* localdecomp:start func_L03_00399218 */
f32 func_L03_00399218(s32 a0, s32 a1) {
    if (a1 == 1) {
        return (f32)(a0 - 1) * -0.39269909262657166f + 0.0047996556386351585f;
    }
    return (f32)a0 * -0.39269909262657166f;
}
/* localdecomp:end func_L03_00399218 */
