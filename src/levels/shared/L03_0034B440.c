#include "common.h"

/* localdecomp:start func_L03_0034B440 */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DB48(f32);

f32 func_L03_0034B440(s32 invert, s32 mode, s32 shape, f32 t, f32 period) {
    f32 phase;
    f32 v;
    f32 r;

    phase = (f32)((s32)t % (s32)period) / period;
    if (invert == 1) {
        phase = 1.0f - phase;
    }
    switch (shape) {
    case 0:
        v = phase;
        break;
    case 1:
        v = 0.5f - func_0038D098(phase * 3.1415927f) * 0.5f;
        break;
    case 2:
        if (phase < 0.5f) {
            v = (phase + phase) * phase;
        } else {
            v = (phase + phase) * (2.0f - phase) - 1.0f;
        }
        break;
    case 3:
        if (phase < 0.5f) {
            v = func_0038D0B0(phase * 3.1415927f) * 0.5f;
        } else {
            v = 1.0f - func_0038D0B0((1.0f - phase) * 3.1415927f) * 0.5f;
        }
        break;
    case 4:
        if (phase < 0.5f) {
            v = (phase + phase) * (1.0f - phase);
        } else {
            v = (phase + phase) * (phase - 1.0f) + 1.0f;
        }
        break;
    case 5:
        v = (func_0038D098(phase * 6.2831855f) + 1.0f) * 0.5f;
        break;
    }
    switch (mode) {
    case 0:
        r = v;
        break;
    case 3:
        r = (v + v) - 1.0f;
        break;
    case 1:
        r = func_0038DB48(v * 6.2831855f);
        break;
    case 2:
        r = func_0038DB48(v * 1.5707964f);
        break;
    }
    return r;
}
/* localdecomp:end func_L03_0034B440 */

/* localdecomp:start func_L03_0034B6C0 */
/* from the NTSC-U draft of func_L03_0034AB00 (nonmatching/levels/func_L03_0034B6C0.c), PAL names */
typedef int Q_0034B6C0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0034B6C0;
extern s32 func_L01_0044C108(void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_00439880(void *, u16 *, s32 *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00452F78(void *, s32, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
void func_L03_0034BBA0(void *arg0);
extern void func_003C2880(void *);
long func_L03_0034BC80(f32 *a, f32 *b);
extern f32 func_003824E0(f32, f32);
extern u8 D_L03_001FC3D0[];
typedef struct { u8 pad[0x18]; u8 *f18; } G9200_0034B6C0;
typedef struct { u8 pad[0x20]; f32 f20; s32 f24; s32 f28; s32 f2C; } G24C0_0034B6C0;
extern G9200_0034B6C0 D_L03_001E9200;
extern G24C0_0034B6C0 D_L03_001E24C0;

void func_L03_0034B6C0(u8 *m) {
    V_0034B6C0 bottom, top;
    u16 result;
    s32 result2;
    u8 *v;
    s32 i;
    s32 j;
    s32 *ids;
    V_0034B6C0 *pb;
    u16 old;
    f32 height;

    if (!func_L01_0044C108(m + 0x10)) return;
    v = *(u8 **)(m + 0x68);
    switch (m[0x20]) {
    case 0:
        *(u16 *)(m + 0x34) |= 0x100;
        *(u16 *)(v + 0x152) = 0;
        for (i = 0; i < 2; i++) {
            if (((s32 *)(v + 0x154))[i] != -1) (*(u16 *)(v + 0x152))++;
        }
        ids = (s32 *)(v + 0x154);
        for (j = 0; j < 2; j++) {
            if (D_L03_001FC3D0[ids[j]] == 255) *(u16 *)(v + 0x152) = 0;
        }
        *(f32 *)(m + 0x18) = func_003C3D30(m + 0x10, 0, 0, 0.5f);
        func_L01_00439880(m, &result, &result2);
        *(Q_0034B6C0 *)&bottom = *(Q_0034B6C0 *)(m + 0x10);
        *(Q_0034B6C0 *)&top = *(Q_0034B6C0 *)(m + 0x10);
        top.z += 0.5f;
        bottom.z -= 1.0f;
        *(u16 *)(m + 0x7C) = result;
        pb = &bottom;
        if (func_003D3CB0(&top, pb, 0, m, 0)) {
            if (D_L03_001E9200.f18) {
                u8 *other;
                *(u16 *)(v + 0x152) = 0;
                other = D_L03_001E9200.f18;
                *(u8 **)(v + 0x15C) = other;
                *(Q_0034B6C0 *)(m + 0xF0) = *(Q_0034B6C0 *)(other + 0x10);
            }
        }
        *(u16 *)(v + 0x152) |= 0x80;
        if (*(f32 *)(v + 0x30) <= 0.0f) *(f32 *)(v + 0x30) = 30.0f;
        if (*(s16 *)(v + 0x34) <= 0) *(f32 *)(v + 0x30) = 30.0f;
        func_L01_004450F0(m, 1, -1);
    case 1:
        old = *(u16 *)(m + 0x7C);
        if (func_L01_00452F78(m, 0, 0, 0)) *(u16 *)(v + 0x36) = *(u16 *)(v + 0x150);
        if (old != *(u16 *)(m + 0x7C) && !m[0xBC]) {
            func_003A52A0(0, 0, m);
            m[0xBC] = 17;
        }
        if (m[0xBC]) m[0xBC]--;
        if (*(f32 *)(v + 0x30) <= 0.0f) {
            V_0034B6C0 *p = &bottom;
            *(Q_0034B6C0 *)p = *(Q_0034B6C0 *)(m + 0xE0);
            func_0038CF68(p, p, 0.0400000028f);
            func_L01_00451FE0(m, 65535, p, 255, 180, 0, 0, 35, 0, 3, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
            func_003A52A0(0, 0, m);
            func_L03_0034BBA0(m);
            func_003C2880(m);
            return;
        }
        if (*(u8 **)(v + 0x15C)) {
            u8 *other = *(u8 **)(v + 0x15C);
            if (other[0x20] == 254 || (*(u8 **)(v + 0x15C))[0x20] == 253) {
                *(u8 **)(v + 0x15C) = 0;
                *(u16 *)(v + 0x152) &= 0xFF7F;
            }
        }
        if ((*(u8 **)(v + 0x15C) == 0 || func_L03_0034BC80((f32 *)(*(u8 **)(v + 0x15C) + 0x10), (f32 *)(m + 0xF0))) && (*(u16 *)(v + 0x152) & 0x80)) return;
        *(u16 *)(v + 0x152) &= 0xFF7F;
        height = func_003C3D30(m + 0x10, 0, 0, 0.5f);
        if (height < *(f32 *)(m + 0x18)) {
            *(f32 *)(m + 0x18) -= 0.0980000123f;
            if (*(f32 *)(m + 0x18) < height) {
                D_L03_001E24C0.f20 = func_003824E0(0.0f, 0.25f);
                D_L03_001E24C0.f28 = 17;
                D_L03_001E24C0.f2C = 0;
                *(f32 *)(m + 0x18) = height;
                *(u16 *)(v + 0x152) |= 0x80;
            }
        }
        break;
    case 2:
        break;
    }
}
/* localdecomp:end func_L03_0034B6C0 */

/* localdecomp:start func_L03_0034BAF0 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 D_L03_001FC3D0[];
extern u8 *func_003C24B0(s32 a, s32 b);
extern void func_003C7C38(u8 *m);

u8 *func_L03_0034BAF0(u8 *a0, s32 a1) {
    u8 *m;

    if (D_L03_001FC3D0[a1] == 255) {
        return 0;
    }
    if (a1 == 0) {
        return 0;
    }
    m = func_003C24B0(a1, 128);
    if (m != 0) {
        *(u128_t *)(m + 16) = *(u128_t *)(a0 + 16);
        *(u128_t *)(m + 240) = *(u128_t *)(a0 + 240);
        *(long *)(m + 56) = *(long *)(a0 + 56);
        *(u8 *)(m + 48) = *(u8 *)(a0 + 48);
        *(s16 *)(m + 50) = *(u8 *)(a0 + 48);
        *(u8 **)(m + 184) = a0;
        *(u8 *)(m + 49) = 1;
        if (*(s32 *)(m + 36) != 0) {
            func_003C7C38(m);
        }
        return m;
    }
    return 0;
}
/* localdecomp:end func_L03_0034BAF0 */

/* localdecomp:start func_L03_0034BBA0 */
extern s32 func_00382468(s32);
u8 *func_L03_0034BAF0(u8 *a0, s32 a1);

/* from rac4-decomp's func_L01_004BE460, renamed, constants adapted */
void func_L03_0034BBA0(void *arg0) {
    char *p = *(char **)((char *)arg0 + 0x68);
    u16 flags;
    s32 a;
    s32 b;
    flags = *(u16 *)(p + 0x152) & 0xFF7F;
    *(u16 *)(p + 0x152) = flags;
    if (flags == 0)
        return;
    a = *(s32 *)(p + 0x154);
    b = *(s32 *)(p + 0x158);
    if (a != -1 && b != -1) {
        switch (func_00382468(3)) {
        case 0:
            func_L03_0034BAF0(arg0, *(s32 *)(p + 0x154));
            break;
        case 2:
            func_L03_0034BAF0(arg0, *(s32 *)(p + 0x154));
        case 1:
            func_L03_0034BAF0(arg0, *(s32 *)(p + 0x158));
            break;
        }
    } else if (a != -1 && a != b) {
        func_L03_0034BAF0(arg0, a);
    } else if (b != -1) {
        func_L03_0034BAF0(arg0, b);
    }
}
/* localdecomp:end func_L03_0034BBA0 */

/* localdecomp:start func_L03_0034BC80 */
extern s32 func_L02_003E6F38(f32, f32, f32);

long func_L03_0034BC80(f32 *a, f32 *b) {
    long r = 0;
    if (func_L02_003E6F38(a[0], b[0], 0.001f) && func_L02_003E6F38(a[1], b[1], 0.001f)) {
        s32 t = func_L02_003E6F38(a[2], b[2], 0.001f) != 0;
        r = t;
    }
    return r;
}
/* localdecomp:end func_L03_0034BC80 */
