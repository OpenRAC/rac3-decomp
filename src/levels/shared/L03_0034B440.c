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

INCLUDE_ASM("asm/levels", func_L03_0034B6C0);

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
