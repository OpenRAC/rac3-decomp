#include "common.h"

/* localdecomp:start func_L40_003DA9A0 */
#include "vu0.h"

typedef int q_003DA9A0 __attribute__((mode(TI)));

typedef struct {
    f32 f0;
    f32 f4;
    s16 s8;
    s16 pad_A;
    f32 fC;
    vu0_v4 pos;
    f32 dir[3];
    f32 f2C;
    u8 *p[4];
    u8 pad_40[2];
    u8 b42;
    u8 b43;
    s16 s44[4];
    u8 pad_4C[4];
    f32 f50[4];
} S_003DA9A0;

extern void *D_L40_00249640_003DA9A0;
extern vu0_v4 D_L40_00249650[8] __attribute__((section(".sdata")));
extern const f32 D_L40_002469A0[] __attribute__((section(".sdata")));
extern vu0_v4 D_L40_00249FC0;

extern void func_0038CF68(void *, void *, f32);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005B4398(s32);
extern void func_0038D308(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_00382760(void *, f32, f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern void func_003C5278(void *, void *, void *, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L40_003DA2D0(void);
extern s32 func_L39_005BE900(void *, s32, f32);
extern void func_L01_00404808(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_0039E018(void *, void *, s32);
extern void func_L40_003DA8D8(void *, void *, s32);
extern void func_L40_003DA390(void *);
extern void func_L40_003DAE50(u8 *);

void func_L40_003DA9A0(u8 *m) {
    S_003DA9A0 *d = *(S_003DA9A0 **)(m + 0x68);
    u8 *t;
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    f32 f;
    f32 a;
    vu0_v4 v;
    u8 buf[16];

    switch (m[0x20]) {
    case 0:
        m[0x20] = 1;
        *(u16 *)(m + 0x34) |= 0x41;
        *(void **)(m + 0x98) = 0;
        m[0xBC] = 0;
        *(q_003DA9A0 *)(m + 0x10) = *(q_003DA9A0 *)(*(u8 **)(m + 0xB8) + 0x10);
        *(q_003DA9A0 *)(m + 0xF0) = *(q_003DA9A0 *)(*(u8 **)(m + 0xB8) + 0xF0);
        func_0038CF68(&d->pos, m + 0xE0, 0.5f);
        vec_add_ab(&d->pos, &d->pos, m + 0x10);
        *(s32 *)&d->f0 = 0;
        d->s8 = 0;
        f = d->f0;
        d->f4 = func_L39_005B4410(f, 3.1415927f);
        d->fC = f;
        d->b42 = 0;
        for (i = 0; i < 4; i++) {
            d->f50[i] = func_L39_005B4398(0xFF);
            d->s44[i] = 0x4B;
        }
        for (j = 3; j >= 0; j--) {
            d->p[j] = 0;
        }
        if (D_L40_00249640_003DA9A0 == 0) {
            func_0038D308(m + 0xC0, m + 0xF0);
            D_L40_00249640_003DA9A0 = m;
            m[0x30] = 0xFF;
            func_0038CF68(&D_L40_00249650[0], m + 0xC0, 0.25f);
            D_L40_00249650[4] = *(vu0_v4 *)(m + 0xE0);
            func_0038CF68(&D_L40_00249650[1], m + 0xD0, 0.25f);
            D_L40_00249650[5] = *(vu0_v4 *)(m + 0xC0);
            func_0038CF68(&D_L40_00249650[2], m + 0xE0, 0.25f);
            D_L40_00249650[6] = *(vu0_v4 *)(m + 0xD0);
            vec_add_ab(&D_L40_00249650[3], m + 0xC0, m + 0xE0);
            func_0038CF68(&D_L40_00249650[3], &D_L40_00249650[3], 0.25f);
            func_0038CE90(&D_L40_00249650[7], &D_L40_00249650[3], m + 0xD0);
        }
        a = func_L39_005B4410(0.0f, 6.2831855f);
        func_00382760(d->dir, 1.0f, a, func_L39_005B4410(-1.5707964f, 1.5707964f));
        d->f2C = func_L39_005B4468(0.785398f, 1.5707964f);
    case 1:
        t = *(u8 **)(m + 0xB8);
        *(q_003DA9A0 *)(m + 0x10) = *(q_003DA9A0 *)(t + 0x10);
        *(q_003DA9A0 *)(&d->pos) = *(q_003DA9A0 *)(t + 0x10);
        func_003C5278(m + 0x10, &d->pos, &d->pos, -0.5f);
        m[0x20] = 2;
    case 2:
        *(q_003DA9A0 *)(&d->pos) = *(q_003DA9A0 *)(m + 0x10);
        d->pos.z += 0.5f;
        for (k = 0; k < 4; k++) {
            u8 *p = d->p[k];
            if (p != 0) {
                p += 0x20;
                *(f32 *)(p + 8) = func_0038D0B0(*(f32 *)(p + 0xC)) * 0.15f + 0.25f;
                *(f32 *)(p + 0xC) = func_0038DAB8(*(f32 *)(p + 0xC), D_L40_002469A0[k]);
            }
        }
        d->f0 = func_0038D0B0(d->f4) * 0.06f;
        d->f4 = func_0038DAB8(d->f4, 0.034906585f);
        if (D_L40_00249640_003DA9A0 == m) {
            func_L40_003DA2D0();
        }
        *(q_003DA9A0 *)&v = *(q_003DA9A0 *)(m + 0x10);
        func_003C5278(m + 0x10, &v, &v, -0.5f);
        v.w = 1.0f;
        if (func_L39_005BE900(&v, 0, 48.0f) >= 0) {
            func_L01_00404808(func_L40_003DAE50, m);
            func_0038CF38(m + 0x10, &D_L40_00249FC0);
            for (n = 0; n < 4; n++) {
                func_L01_0039E018(m, buf, n);
                func_L40_003DA8D8(m, buf, n);
            }
        }
        do {
        } while (0); /* an empty macro: its loop note aligns the case 3 label (retail's nop) */
        break;
    case 3:
        func_L40_003DA390(m);
        break;
    case 4:
        if (D_L40_00249640_003DA9A0 == m) {
            func_L40_003DA2D0();
        }
        break;
    }
}
/* localdecomp:end func_L40_003DA9A0 */

/* localdecomp:start func_L40_003DAE50 */
#include "vu0.h"

typedef int q_003DAE50 __attribute__((mode(TI)));

typedef struct {
    u8 pad_00[0x40];
    u32 col[4];
    u8 pad_50[0x20];
} P_003DAE50;

typedef struct {
    unsigned long a;
    unsigned long b;
    unsigned long c;
    unsigned long d;
} G_003DAE50;

extern vu0_v4 D_L40_00249F40;

extern long func_L39_00589890(s32);
extern void func_003A9440(s32, unsigned long);
extern void func_003C5278(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);

void func_L40_003DAE50(u8 *m) {
    u8 *d;
    u8 *t;
    P_003DAE50 p;
    G_003DAE50 pkt;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 pos;
    vu0_v4 dir;
    u32 cc;
    vu0_v4 *pa;
    f32 f;

    d = *(u8 **)(m + 0x68);
    if (m == 0 || d == 0) {
        return;
    }
    pkt.b = func_L39_00589890(0x15);
    pkt.c = 0xFF9000000260;
    pkt.d = 0x1000000044;
    pkt.a = 0;
    func_003A9440(0x47, 0x53001);
    if (m[0x20] == 1) {
        t = *(u8 **)(m + 0xB8);
        *(q_003DAE50 *)(m + 0x10) = *(q_003DAE50 *)(t + 0x10);
        *(q_003DAE50 *)(d + 0x10) = *(q_003DAE50 *)(t + 0x10);
        func_003C5278(m + 0x10, d + 0x10, d + 0x10, -0.5f);
    }
    pa = &a;
    pos.x = *(f32 *)(m + 0x10);
    pos.y = *(f32 *)(m + 0x14);
    pos.z = *(f32 *)(m + 0x18);
    func_003C5278(m + 0x10, &pos, &pos, -0.5f - *(f32 *)d);
    pos.w = 1.0f;
    vec_sub_ba(&dir, &D_L40_00249F40, &pos);
    func_0038CF68(pa, &dir, 1.0f);
    func_0038CE90(&b, pa, *(u8 **)(m + 0xB8) + 0xE0);
    func_0038CF68(&b, &b, 1.0f);
    func_0038CE90(&c, &b, pa);
    cc = d[0x43] ? 0x50804080 : 0x50804040;
    p.col[3] = cc;
    p.col[2] = cc;
    p.col[1] = cc;
    p.col[0] = cc;
    f = func_L39_005B4410(-0.15f, -0.3f);
    *(f32 *)(d + 0xC) = func_0038DAB8(*(f32 *)(d + 0xC), f * 0.017453292f);
    func_003D9508(d + 0x10, 0x43, 0x4FFF4040, 1, 0.4f, 0.0f, *(f32 *)(d + 0xC));
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L40_003DAE50 */
