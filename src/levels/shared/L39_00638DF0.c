#include "common.h"

/* localdecomp:start func_L39_00638DF0 */
typedef struct {
    u8 pad0[12];
    s16 h12;
    u8 pad1[33 - 14];
    s8 b33;
    u8 pad2[128 - 34];
} Ent_00638DF0;
typedef struct {
    s32 pad0[13];
    s32 (*fn34)(void *, s32, s32, s32, s32);
} Vt_00638DF0;
extern Ent_00638DF0 D_L39_0049C890[];
extern void func_L39_00622288(u8 *);
extern s32 func_L39_00648AE0(u8 *, s32);
extern void func_003C4BB0(void *, f32);
extern void func_L39_0062B4A8(void *, s32, s32, s32, f32);

s32 func_L39_00638DF0(u8 *p) {
    s32 i;
    s32 v;
    Ent_00638DF0 *e;

    if (p[0x1A07] != 0 && p[0x1A05] != 0 && p[0x1A08] == 0) {
        i = -1;
        if (*(s32 *)(p + 0x474) == 2) i = *(s32 *)(p + 0x478);
        if (i != *(s32 *)(p + 0x244C)) {
            func_L39_00622288(p);
        } else if (*(s32 *)(p + 0x3FC) >= 5) {
            if (func_L39_00648AE0(p, i)) {
                e = &D_L39_0049C890[D_L39_0049C890[i].b33];
            } else {
                e = &D_L39_0049C890[i];
            }
            v = e->h12;
            if (((Vt_00638DF0 *)*(void **)(p + 0x14))->fn34(p, 0, 0, 0, 1) != 0) {
                func_003C4BB0(p + 0x190, 0.030000001f);
                if (*(f32 *)(p + 0xFB4) > 0.030000001f) *(f32 *)(p + 0xFB4) = 0.030000001f;
                func_L39_0062B4A8(p, v, 0, 0, 9.0f);
                if (*(s32 *)(p + 0x748) != 0) *(s32 *)(p + 0x754) = 1;
                *(s32 *)(p + 0x2448) = v;
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00638DF0 */

/* localdecomp:start func_L39_00638F50 */
typedef int u128_t __attribute__((mode(TI)));
typedef union V4_00638F50 {
    u128_t q;
    f32 f[4];
} V4_00638F50;

extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern V4_00638F50 D_L39_0025F760;

s32 func_L39_00638F50(u8 *g) {
    V4_00638F50 a;
    V4_00638F50 b;
    f32 d;

    if (g[0x1A06] == 2) {
        return 0;
    }
    if (*(f32 *)(g + 0x1A4) < *(f32 *)(g + 0x1F4) / 17.0f) {
        return 0;
    }
    if (func_0038DBA0(func_0038D160(*(f32 *)(g + 0x140), *(f32 *)(g + 0x144)), *(f32 *)(g + 0xB8)) > 0.5235988f) {
        return 0;
    }
    a.q = *(u128_t *)(g + 0xA0);
    a.f[0] += func_0038D098(*(f32 *)(g + 0xB8)) * (*(f32 *)(g + 0x1F4) * 0.75f);
    a.f[1] += func_0038D0B0(*(f32 *)(g + 0xB8)) * (*(f32 *)(g + 0x1F4) * 0.75f);
    b.q = a.q;
    a.f[2] += 0.47f;
    b.f[2] -= 1.0f;
    if (func_003D3CB0(&a, &b, 2, *(void **)(g + 0x2524), 0) == 0) {
        return 0;
    }
    d = D_L39_0025F760.f[2] - *(f32 *)(g + 0xA8);
    if (d < 0.37f && -1.0f < d) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00638F50 */

/* localdecomp:start func_L39_006390D0 */
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);

void func_L39_006390D0(u8 *g) {
    f32 a;
    f32 b;

    if (*(s32 *)(g + 0x4A0) != 0) {
        *(f32 *)(g + 0xACC) = 0.01f;
        *(f32 *)(g + 0xB7C) = 0.01f;
    }
    if ((*(unsigned long *)(g + 0x1A08) & 0xFFFF000000UL) == 0) {
        s32 t = -1;
        s32 r;

        if (*(s32 *)(g + 0x474) == 2) {
            t = *(s32 *)(g + 0x478);
        }
        if (t == 6 || t == 0xC) {
            r = 1;
        } else {
            r = 0;
        }
        if (r) {
            *(f32 *)(g + 0xF9C) = 0.1f;
        }
    }
    if (__builtin_fabsf(*(f32 *)(g + 0x290)) > 0.015f || __builtin_fabsf(*(f32 *)(g + 0x294)) > 0.015f ||
        __builtin_fabsf(*(f32 *)(g + 0x298)) > 0.017453292f || __builtin_fabsf(*(f32 *)(g + 0x29C)) > 0.017453292f ||
        __builtin_fabsf(*(f32 *)(g + 0x2A0)) > 0.017453292f || __builtin_fabsf(*(f32 *)(g + 0x2A4)) > 0.017453292f) {
        if (*(s16 *)(g + 0x2D8) != 1) {
            *(f32 *)(g + 0xA84) = -*(f32 *)(g + 0x298);
            *(f32 *)(g + 0xB34) = -*(f32 *)(g + 0x29C);
            a = func_0038D160(0.2f, *(f32 *)(g + 0x290)) * 1.2f;
            b = -func_0038D160(0.2f, *(f32 *)(g + 0x294)) * 1.2f;
            if (a > 0.7853982f) {
                a = 0.7853982f;
            }
            if (a < -0.17453292f) {
                a = -0.17453292f;
            }
            if (b > 0.17453292f) {
                b = 0.17453292f;
            }
            if (b < -0.7853982f) {
                b = -0.7853982f;
            }
            *(f32 *)(g + 0xBE0) = a;
            *(f32 *)(g + 0xC90) = b;
            *(f32 *)(g + 0xA80) = -func_0038DB00(*(f32 *)(g + 0x2A0), -a);
            *(f32 *)(g + 0xB30) = -func_0038DB00(*(f32 *)(g + 0x2A4), -b);
        }
    }
}
/* localdecomp:end func_L39_006390D0 */
