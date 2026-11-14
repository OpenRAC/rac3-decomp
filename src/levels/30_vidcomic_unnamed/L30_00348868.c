#include "common.h"

/* localdecomp:start func_L30_00348868 */
__asm__(".extern D_001DF71C, 16");
extern u8 *D_001DF71C;
extern u8 D_001A4C60[];
typedef struct { u8 pad0[0x24]; u8 *p24; u8 pad28[0x34 - 0x28]; u16 h34; u8 pad36[0x98 - 0x36]; s32 w98; u8 pad9c[0x100 - 0x9C]; } M_00348868;
typedef struct { u8 pad0[0x20]; f32 f20; s32 w24; s32 w28; s32 w2C; } S_00348868;
extern S_00348868 D_L30_001E22C0;
extern u8 D_00142732[];
extern s32 func_0038CAD0(void *);
extern void func_L30_003497B0(void *);
extern s32 func_00382380(void *, s32, s32);
extern void func_L30_0034A0A8(s32 unused, s32 flag);
extern s32 func_L01_004561B8(void *);
extern s32 func_L30_00349968(u8 *a0, u32 a1, s32 a2);
extern s32 func_L30_00349EE8(void *);
extern void func_L30_00349390(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L04_00325460(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32, s32);
extern void func_L30_00349630(void *, void *, float *);
extern void func_L30_00348EE0(u8 *a0);
extern void func_L30_00349098(u8 *a0);
extern void func_L30_00349280(u8 *a0);
extern void func_L30_003496D8(void *);

void func_L30_00348868(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x68);
    M_00348868 *m;
    f32 v[4];

    switch (a0[0x20]) {
    case 0:
        func_L30_003497B0(a0);
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_00382380(D_001A4C60, *(s32 *)(q + 0x98), 0)) {
            m = (M_00348868 *)D_001DF71C;
            m[*(s32 *)(q + 0x90)].h34 &= 0xFFBE;
            m[*(s32 *)(q + 0x90)].h34 |= *(u16 *)(m[*(s32 *)(q + 0x90)].p24 + 0x44) & 0x1000;
            m[*(s32 *)(q + 0x90)].w98 = *(s32 *)(m[*(s32 *)(q + 0x90)].p24 + 0x10);
            func_L30_0034A0A8((s32)a0, 1);
            func_L01_004450F0(a0, 3, -1);
        }
        break;
    case 3:
        func_L01_004561B8(a0);
        {
            s32 *t = (s32 *)(q + 0x9C);
            s32 i;

            for (i = 0; i < 1; i++) {
                if (!func_L30_00349968(a0, t[i], 1)) {
                    t[i] = func_L30_00349EE8(a0);
                }
            }
        }
        if (!func_L30_00349968(a0, 0, 0)) {
            func_L30_00349390(a0);
        }
        if (*(s32 *)(q + 0xB0) <= *(s32 *)(q + 0xB4)) {
            func_L01_004450F0(a0, 4, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(a0)) {
            D_L30_001E22C0.f20 = 2.0f;
            D_L30_001E22C0.w28 = 0x1E;
            D_L30_001E22C0.w2C = 0;
        }
        {
            s32 *t = (s32 *)(q + 0x9C);
            s32 i;

            for (i = 0; i < 2; i++) {
                if (!func_L30_00349968(a0, t[i], 1)) {
                    t[i] = func_L30_00349EE8(a0);
                }
            }
        }
        if (!func_L30_00349968(a0, 0, 0)) {
            func_L30_00349390(a0);
        }
        if (*(s32 *)(q + 0xB0) <= *(s32 *)(q + 0xB8)) {
            func_L01_004450F0(a0, 5, -1);
        }
        break;
    case 5:
        if (func_L01_004561B8(a0)) {
            D_L30_001E22C0.f20 = 2.0f;
            D_L30_001E22C0.w28 = 0x1E;
            D_L30_001E22C0.w2C = 0;
        }
        {
            s32 *t = (s32 *)(q + 0x9C);
            s32 i;

            for (i = 0; i < 3; i++) {
                if (!func_L30_00349968(a0, t[i], 1)) {
                    t[i] = func_L30_00349EE8(a0);
                }
            }
        }
        if (!func_L30_00349968(a0, 0, 0)) {
            func_L30_00349390(a0);
        }
        if (*(s32 *)(q + 0xB0) <= 0) {
            func_L01_004450F0(a0, 6, -1);
        }
        break;
    case 6:
        if (func_L01_004561B8(a0)) {
            *(s32 *)(q + 0xD0) = 0x19;
            *(s32 *)(q + 0xF0) = 0x1F4;
            if (a0[0x43] != 1) {
                func_003C3A10(a0, 1, 0, 8);
            }
        }
        if (func_0038CAD0(q + 0xD0)) {
            func_L30_00349630(a0, 0, v);
            v[0] += func_003824E0(-1.5f, 1.5f);
            *(s32 *)(q + 0xD0) = 0x19;
            func_L04_00325460(v, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 1.0f, 20.0f, 1, 1, 0, 0);
        }
        if (func_0038CAD0(q + 0xF0)) {
            D_00142732[0] = 1;
        }
        break;
    }
    func_L30_00348EE0(a0);
    func_L30_00349098(a0);
    func_L30_00349280(a0);
    func_L30_003496D8(a0);
}
/* localdecomp:end func_L30_00348868 */

/* localdecomp:start func_L30_00348C30 */
#include "vu0.h"
typedef struct { vu0_v4 v; u8 p10[8]; u8 b18; u8 b19; u16 h1A; u8 p1C[0x14]; } S_00348C30;
extern u8 D_001A4C60[];
extern vu0_v4 D_L30_001E9020;
extern f32 D_L30_001DD308;
__asm__(".extern D_L30_001DD308, 4");
extern void func_003C2EC0(void *, s32, void *);
extern void func_L30_003494F0(void *, void *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_0040A8C0(void *, void *, s32, s32, u32, u32, u32, u32, f32, f32, f32);

void func_L30_00348C30(u8 *a0) {
    vu0_v4 dir;
    vu0_v4 from;
    S_00348C30 s;
    vu0_v4 mtx[4];
    vu0_v4 hit;
    vu0_v4 vel;
    s32 i;
    f32 r;

    func_003C2EC0(a0, 4, mtx);
    from = mtx[3];
    func_L30_003494F0(a0, &dir);
    func_L01_00446760(&s, a0, 1, &dir, 1.0f);
    s.h1A = *(u16 *)(a0 + 0xAA);
    func_0038CF68(&dir, &dir, D_L30_001DD308);
    vec_add_ab(&dir, &dir, &from);
    from.y = ((f32 *)D_001A4C60)[1];
    dir.y = ((f32 *)D_001A4C60)[1];
    if (func_003D3CB0(&from, &dir, 0, a0, &s)) {
        for (i = 0; i < 2; i++) {
            hit = D_L30_001E9020;
            func_003C4C18(&hit, 0.3f);
            vel.x = func_003824E0(0.0f, 1.2f * (1.0f / 60.0f));
            vel.y = func_003824E0(0.0f, 1.2f * (1.0f / 60.0f));
            vel.z = func_003824E0(2.4f * (1.0f / 60.0f), 2.4f * (1.0f / 60.0f) + 6.0f * (1.0f / 60.0f));
            {
                s32 n = func_00382498(0, 2) - 1;

                r = func_003824E0(0.25f, 1.25f) * 210000.0f;
                func_L01_0046FB40(&hit, &vel, 0x25, 0x808080, n, 0x60, 0, 0, r, r * 0.1f, 0.002f);
            }
        }
    }
    func_L01_0040A8C0(&from, &hit, 0x15, 1, 0x3F2020FF, 0x3F2020FF, 0x3F2020FF, 0x3F2020FF, 0.3f, 1.0f, 0.0f);
    func_L01_0040A8C0(&from, &hit, 0x15, 1, 0x3F2020FF, 0x3F2020FF, 0x3F2020FF, 0x3F2020FF, 0.1f, 1.0f, 0.0f);
}
/* localdecomp:end func_L30_00348C30 */

/* localdecomp:start func_L30_00348EE0 */
__asm__(".extern D_001DF71C, 16");
extern u8 *D_001DF71C;
extern s32 D_L30_001DD1F0[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD1F0, 8");
extern f32 D_L30_001DD368;
__asm__(".extern D_L30_001DD368, 4");
extern f32 D_L30_001DD36C;
__asm__(".extern D_L30_001DD36C, 4");
extern u8 D_L30_001D66B0;
extern s32 func_0038CAD0(void *);
extern f32 func_L30_00349550(void *, s32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L30_00321070(void *arg0, f32 fparg0);
extern void func_L30_0034A058(void *a, s32 unused, void *c);

void func_L30_00348EE0(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x68);
    s32 n = D_L30_001DD1F0[a0[0x20] - 3];
    u8 *p;

    if (!func_0038CAD0(q + 0xF0)) {
        p = D_001DF71C;
        p += *(s32 *)(q + 0xE4) << 8;
        func_L30_00321070(p, func_003C4088(D_L30_001DD36C, D_L30_001DD368, func_L30_00349550(a0, 3)));
        if ((f32)*(s32 *)(q + 0xE8) < (1.0f - (f32)*(s32 *)(q + 0xF0) / (f32)n) * 2) {
            *(s32 *)(q + 0xE8) += 1;
            func_L30_0034A058(a0, (s32)&D_L30_001D66B0, (void *)3);
        }
    } else {
        *(s32 *)(q + 0xE8) = 0;
    }
    if (!func_0038CAD0(q + 0x100)) {
        p = D_001DF71C;
        p += *(s32 *)(q + 0xF4) << 8;
        func_L30_00321070(p, func_003C4088(D_L30_001DD36C, D_L30_001DD368, func_L30_00349550(a0, 4)));
        if ((f32)*(s32 *)(q + 0xF8) < (1.0f - (f32)*(s32 *)(q + 0x100) / (f32)n) * 2) {
            *(s32 *)(q + 0xF8) += 1;
            func_L30_0034A058(a0, (s32)&D_L30_001D66B0, (void *)4);
        }
    } else {
        *(s32 *)(q + 0xF8) = 0;
    }
}
/* localdecomp:end func_L30_00348EE0 */

/* localdecomp:start func_L30_00349098 */
extern u8 D_001A4C60[];
extern f32 D_L30_001DD2E4;
__asm__(".extern D_L30_001DD2E4, 4");
extern f32 D_L30_001DD2E8;
__asm__(".extern D_L30_001DD2E8, 4");
extern f32 D_L30_001DD2EC;
__asm__(".extern D_L30_001DD2EC, 4");
extern f32 D_L30_001DD304;
__asm__(".extern D_L30_001DD304, 4");
extern s32 func_0038CAD0(void *);
extern void func_L30_00349470(u8 *a0, void *a1);
extern void func_L30_00349630(void *, void *, float *);
extern f32 func_L30_00349550(void *, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_004DB8A8(s32 a0);
extern void func_L01_0044E850(f32, f32, void *, void *, s32);

void func_L30_00349098(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x68);
    f32 v[4];
    f32 w[4];
    f32 t;
    f32 a;
    s32 flag;

    if (func_0038CAD0(q + 0xD0)) {
        *(f32 *)(q + 0x64) = 0.0f;
        *(f32 *)(q + 0x68) = 0.0f;
    } else {
        switch (*(s32 *)(q + 0xCC)) {
        case 1:
            func_L30_00349470(a0, D_001A4C60);
            break;
        case 2:
            func_L30_00349630(a0, *(void **)(q + 0x9C), v);
            func_L30_00349470(a0, v);
            break;
        case 4:
            t = func_L30_00349550(a0, 0);
            flag = 0;
            func_L30_00349630(a0, 0, w);
            if (*(s32 *)(q + 0xC0) == 0) {
                t = 1.0f - t;
            }
            if (t < D_L30_001DD2EC) {
                t = 0.0f;
            } else if (1.0f - D_L30_001DD2EC < t) {
                t = 1.0f;
            } else {
                flag = 1;
                t = (t - D_L30_001DD2EC) / (1.0f - (D_L30_001DD2EC + D_L30_001DD2EC));
            }
            a = t - 0.5f;
            w[0] += func_0038D098(D_L30_001DD304 * a + 4.712389f);
            w[2] += func_0038D0B0(D_L30_001DD304 * a + 4.712389f);
            func_L30_00349470(a0, w);
            if (flag) {
                func_L01_004DB8A8((s32)a0);
            }
            break;
        case 3:
        case 5:
        case 6:
            break;
        }
    }
    func_L01_0044E850(D_L30_001DD2E4, D_L30_001DD2E8, a0, q, 3);
}
/* localdecomp:end func_L30_00349098 */
