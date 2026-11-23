#include "common.h"

/* NTSC-U counterpart of func_L19_003C70C0 (src/levels/19_thran_asteroid_belt/L19_003C6708.c) */
#include "vu0.h"
#include "vu0.h"
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);

/* localdecomp:start func_L19_003C5110 */
typedef struct {
    u8 pad0[0x70];
    f32 f70;
    f32 f74;
    s32 w78;
    s32 w7C;
    f32 f80;
    s32 w84;
    s32 w88;
    s32 w8C;
} S_3C70C0;
typedef struct {
    u8 pad0[0x20];
    f32 f20;
    u8 pad24[4];
    s32 w28;
    s32 w2C;
} G_3C70C0;
extern s32 func_L01_00448E90(void *);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_00388398(void *);
extern void func_0039FE80(s32, s32, void *);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_0037E0F0(void *, s32, s32);
extern void func_L01_004367A0(void *, u16 *, s32 *);
extern u8 *func_L01_003F5830(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_L13_0044A168(void *, s32, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern u8 *func_L01_00467730(void *, void *, f32);
extern f32 func_003BEC60(void *, void *, f32, f32, f32, f32);
extern void func_003BF838(void *, void *, void *, void *);
extern void func_L19_003D3E70(u8 *);
extern u8 D_001A4C60[];
extern s32 D_001A4F3C[];
extern u8 D_L19_001D66F0_003C5110[8];
extern s32 D_L19_001DF240_003C5110;
extern f32 D_L19_001E8E68_003C5110[];
extern G_3C70C0 D_L19_001E2100_003C5110;
__asm__(".extern D_L19_001DEA88, 4");
__asm__(".extern D_L19_001DEA8C, 4");
__asm__(".extern D_L19_001DEA90, 4");
__asm__(".extern D_L19_001DEA94, 4");
__asm__(".extern D_L19_001DEA98, 4");
__asm__(".extern D_L19_001DEA9C, 4");
__asm__(".extern D_L19_001DEAA0, 4");
__asm__(".extern D_L19_001DEAA4, 4");
__asm__(".extern D_L19_001DEAA8, 4");
__asm__(".extern D_L19_001DEAAC, 4");
extern f32 D_L19_001DEA88;
extern f32 D_L19_001DEA8C;
extern f32 D_L19_001DEA90;
extern f32 D_L19_001DEA94;
extern f32 D_L19_001DEA98;
extern f32 D_L19_001DEA9C;
extern s32 D_L19_001DEAA0;
extern f32 D_L19_001DEAA4;
extern f32 D_L19_001DEAA8;
extern s32 D_L19_001DEAAC;

void func_L19_003C5110(u8 *m) {
    vu0_v4 pos;
    vu0_v4 d;
    vu0_v4 a;
    vu0_v4 b;
    u16 cnt;
    s32 n;
    S_3C70C0 *s;
    G_3C70C0 *g;
    u8 *r;
    s32 below;
    s32 i;
    s32 j;
    s32 k;
    s32 hit;
    s32 prev;
    s32 r2;
    f32 ang;
    f32 rad;
    f32 sc;
    f32 rnd;

    if (func_L01_00448E90(m + 0x10) == 0) {
        return;
    }
    *(vu0_q *)&pos = *(vu0_q *)(m + 0x10);
    s = *(S_3C70C0 **)(m + 0x68);
    switch (m[0x20]) {
    case 0:
        s->w84 = -1;
        s->f70 = 0.0f;
        s->w88 = 0;
        *(f32 *)(m + 0xF8) = func_0037E2A8();
        *(s16 *)(m + 0x7C) = 0;
        if (s->w78 >= 0) {
            func_L01_00441FB8(m, 1, -1);
        } else {
            func_L01_00441FB8(m, 2, -1);
        }
        break;
    case 1:
        if (func_L01_00452EC8(m) != 0) {
            *(vu0_q *)&a = *(vu0_q *)(m + 0x10);
            *(s16 *)(m + 0x7C) = 0xFF;
            *(vu0_q *)&d = *(vu0_q *)(m + 0x10);
            a.z = a.z + 100.0f;
            if (func_003CE740(&d, &a, 2, m, 0) != 0) {
                *(f32 *)(m + 0x18) = D_L19_001E8E68_003C5110[0] + D_L19_001DEA94;
            }
        }
        if (s->w88 == 0) {
            if (s->w84 < 0) {
                if ((D_L19_001DF240_003C5110 & 7) == (((s32)m >> 8) & 7)) {
                    if (func_0037E0F0(D_001A4C60, s->w78, 0) != 0) {
                        s->w84 = s->w7C;
                        g = &D_L19_001E2100_003C5110;
                        if (g->w28 < s->w84) {
                            g->f20 = D_L19_001DEAA8;
                            g->w28 = s->w84;
                            g->w2C = 0;
                        }
                    }
                }
            }
            if (s->w84 > 0) {
                func_L01_004367A0(m, &cnt, &n);
                for (i = 0; i < n; i++) {
                    if (s->w84 - 1 == s->w7C * i / n) {
                        r = func_L01_003F5830(m, 1, *(s16 *)(m + 0xAA), i, m + 0x10, m + 0xF0, D_L19_001D66F0_003C5110, 0xFF, 0.0f, 10.0f, 0xB4, 0, 0x80);
                        *(void (**)(u8 *))(r + 0x64) = func_L19_003D3E70;
                        *(u16 *)(m + 0x7C) = *(u16 *)(m + 0x7C) & ~(1 << i);
                    }
                }
                j = 0;
                while (j < D_L19_001DEAAC) {
                    j++;
                    rnd = func_0037E2A8();
                    func_0037E4B8(&d, 1.0f, rnd, func_0037E2A8());
                    vec_add_ab(&d, &d, m + 0x10);
                    qzero(&a);
                    a.z = -0.016666668f;
                    a.w = 1.0f;
                    func_L13_0044A168(&d, 0, &a, 10.0f);
                }
                func_00388398(&s->w84);
            }
            if (s->w84 == 0) {
                func_0039FE80(0, 0, m);
                s->w88 = 1;
                s->f80 = s->f74 - D_L19_001DEA88;
            }
        } else {
            hit = *(f32 *)(m + 0x18) + D_L19_001DEA98 < s->f74;
            func_003BEC60(m + 0x18, (u8 *)s + 0x70, s->f80, 0.0027777778f, 0.0055555556f, 1.6666667f);
            below = *(f32 *)(m + 0x18) + D_L19_001DEA98 < s->f74;
            if (below != 0) {
                if (hit == 0) {
                    func_0039FE80(1, 0, m);
                }
                for (k = 0; k < D_L19_001DEAA0; k++) {
                    ang = func_0037E2A8();
                    rad = func_0037E250(D_L19_001DEAA4 * 0.5f, D_L19_001DEAA4);
                    d.x = func_00388960(ang) * rad;
                    d.y = func_00388978(ang) * rad;
                    d.z = 0.0f;
                    vec_add_ab(&d, &d, m + 0x10);
                    d.z = s->f74;
                    ang = ang + func_0037E250(-0.17453292f, 0.17453292f);
                    sc = -s->f70 * func_0037E250(0.2f, 0.5f);
                    a.x = func_00388960(ang) * sc;
                    a.y = func_00388978(ang) * sc;
                    a.z = 0.0f;
                    a.z = -s->f70 * func_0037E250(0.2f, 0.5f);
                    a.w = 0.5f;
                    func_003886E8(&b, &a, 0.5f);
                    b.z = 0.0f;
                    b.w = 0.75f;
                    r = func_L01_00467730(&d, &a, func_0037E250(0.25f, 0.75f));
                    if (r != 0) {
                        *(s32 *)(r + 4) = 0x50908080;
                    }
                }
            }
            if (fabs_asm(*(f32 *)(m + 0x18) - s->f80) < 0.0001f) {
                func_L01_00441FB8(m, 2, -1);
            }
        }
        break;
    case 2:
        prev = s->w8C;
        s->w8C = D_001A4F3C[0] == (s32)m;
        prev = prev != 0;
        r2 = func_L01_00452EC8(m);
        if (r2 != 0 || s->w8C != prev || fabs_asm(*(f32 *)(m + 0x18) - s->f80) < 0.0001f) {
            s->f80 = s->f74 - (s->w8C != 0 ? D_L19_001DEA8C : D_L19_001DEA88);
            s->f80 = s->f80 + func_0037E250(-D_L19_001DEA90, D_L19_001DEA90);
        }
        func_003BEC60(m + 0x18, (u8 *)s + 0x70, s->f80, 0.00008333334f, 0.00008333334f, 0.16666667f);
        if (*(f32 *)(m + 0x18) < s->f80 - D_L19_001DEA9C) {
            if (s->f70 < 0.0f) {
                s->f70 = 0.0f;
            }
        }
        break;
    }
    vec_sub_ab(&d, m + 0x10, &pos);
    func_003BF838((u8 *)s + 0x30, &d, m + 0xF0, m + 0xF0);
}
/* localdecomp:end func_L19_003C5110 */
