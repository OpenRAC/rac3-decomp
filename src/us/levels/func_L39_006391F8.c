#include "common.h"

/* NTSC-U counterpart of func_L39_0063BA40 (src/levels/shared/L39_0063B970.c): 18 -> 21; 0.46 -> 0.383333; 0.4 -> 0.333333; 4 -> 5 */
extern u8 D_L39_004998A0[];
#include "vu0.h"
extern void func_0037E4B8(void *, f32, f32, f32);

/* localdecomp:start func_L39_006391F8 */
#include "vu0.h"
typedef union Buf_0063BA40 {
    u8 b[8];
    u32 w[2];
} Buf_0063BA40;

typedef struct V_0063BA40 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0063BA40;

typedef struct M_0063BA40 {
    V_0063BA40 r[3];
} M_0063BA40;

extern u8 D_L39_004998A0[];
extern void func_L39_0063A9F8(void *arg0, s32 arg1);
extern s32 func_L39_00639128(u8 *);
extern f32 func_00389380(f32, f32);
extern s32 func_L39_00639598();
extern void func_L39_00630040(void *, void *, void *, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_00388BD0(void *, void *);
extern void func_00388EB8(void *, void *, void *);
extern void func_003BF360(void *, void *);
extern void func_L01_0044B090(void *, char *);
extern void func_L01_0044B0B8(void *, int, int, float);
extern void func_003BE4F0(void *, s32, s32, s32);

/* reads an obfuscated 32-bit state stored as an index byte at q */
static __inline__ u32 get_state_0063BA40(u8 *q) {
    Buf_0063BA40 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

void func_L39_006391F8(u8 *o) {
    s32 flag;
    u8 *m;
    u8 *p;
    u8 *q;

    if (o[0x46A] != 0) {
        return;
    }
    *(s16 *)(o + 0x24A0) = 0;
    if (*(s32 *)(o + 0x251C) != 0) {
        func_L39_0063A9F8(o, 0);
        return;
    }
    flag = *(s32 *)(o + 0x1310) == 2;
    if ((get_state_0063BA40(o + 0x19E4) ^ 1) == 0 || (get_state_0063BA40(o + 0x19E4) ^ 0x1D) == 0 ||
        o[0x24FE] != 0) {
        flag = *(s32 *)(o + 0x2F0) >= 21;
    }
    if (flag && func_L39_00639128(o) == 0) {
        *(f32 *)(o + 0x1084) = *(f32 *)(o + 0x23B8);
        *(f32 *)(o + 0x1088) = func_00389380(-*(f32 *)(o + 0x23B4), 0.12217305f);
    }
    m = *(u8 **)(o + 0x450);
    if (func_L39_00639598(o, m) != 0) {
        V_0063BA40 v;
        M_0063BA40 a;
        M_0063BA40 b;

        o[0x46A] = 1;
        m[0x20] = 10;
        *(s16 *)(m + 0x96) = 0;
        p = *(u8 **)(m + 0x68);
        if (*(f32 *)(o + 0x208) < 1.2f && 0.663225114f < *(f32 *)(o + 0x210) && o[0x214] == 0) {
            *(s16 *)(p + 0x76) = 1;
        }
        q = p + 0x40;
        qzero(q);
        if (!flag) {
            func_L39_00630040(o, q, q, 1.0f);
        } else {
            func_0037E4B8(q, 1.0f, *(f32 *)(o + 0x1084), *(f32 *)(o + 0x1088));
        }
        qzero(&v);
        func_00388BD0(&a, &v);
        if (flag) {
            v.x = *(f32 *)(o + 0x23B0);
            v.y = *(f32 *)(o + 0x23B4);
            v.z = *(f32 *)(o + 0x23B8);
            func_00388BD0(&b, &v);
            func_00388EB8(&a, &b, &a);
        } else {
            func_00388EB8(&a, *(u8 **)(o + 0x2524) + 0xC0, &a);
        }
        func_003BF360(&a, m + 0xF0);
        *(u16 *)(m + 0x34) &= ~0x100;
        *(f32 *)(p + 0x60) = 0.383333355f;
        *(s32 *)(p + 0x64) = 0;
        if (*(f32 *)(o + 0x1B4) < 0.333333343f) {
            func_L01_0044B090(m, (char *)(o + 0x1780));
            func_L01_0044B0B8(o + 0x1780, 0x30, 3, 0.0f);
            func_L01_0044B0B8(o + 0x1780, 0x17, 5, 0.0f);
        }
        func_003BE4F0(m, 6, 0, 5);
    }
}
/* localdecomp:end func_L39_006391F8 */
