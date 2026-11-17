#include "common.h"

/* localdecomp:start func_L36_00355290 */
s32 func_L36_00355290(s32 x)
{
    s32 r;

    if ((u32)x < 2) {
        return 4;
    }
    if (x == 2 || x == 9) {
        return 8;
    }
    if (x == 3 || x == 10) {
        return 0xB;
    }
    if (x == 4 || x == 11) {
        return 0xE;
    }
    if (x == 5 || x == 12) {
        return 0x11;
    }
    if (x == 6) {
        return 3;
    }
    if (x == 7) {
        return 4;
    }
    r = 5;
    if (x != 8) {
        r = 4;
    }
    return r;
}
/* localdecomp:end func_L36_00355290 */

/* localdecomp:start func_L36_00355330 */
void *func_L36_00355330(u8 *a0, s32 a1) {
    u8 **p = (u8 **)(*(u8 **)(a0 + 0x68) + 0x8C);
    s32 i;
    u8 *c;

    for (i = 0; i < 13; i++, p++) {
        if (*p != 0) {
            c = *(u8 **)(*p + 0x68);
            if (*(s16 *)(c + 0x46) == 0) {
                if (a1 == 0) {
                    *(s32 *)(c + 0x5C) = 1;
                    return *p;
                }
                a1--;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L36_00355330 */

/* localdecomp:start func_L36_00355388 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_355388;
typedef struct { u8 pad[0x20]; V4_355388 a; V4_355388 b; u8 pad40[0x1C]; s32 n; } O_355388;
void func_L36_00355388(u8 *a0, V4_355388 *v) {
    O_355388 *p;
    if (a0 != 0) {
        p = *(O_355388 **)(a0 + 0x68);
        p->a = *v;
        p->b = *v;
        p->n = 2;
    }
}
/* localdecomp:end func_L36_00355388 */

/* localdecomp:start func_L36_003553B8 */
__asm__(".extern D_L36_001DD7F8, 8");
extern f32 D_L36_001DD7F8[2];
extern f32 D_L36_001DD87C;
extern f32 D_L36_001DD92C;
extern f32 D_L36_001DD930;
extern f32 func_0038D160(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *func_L36_00353F58(u8 *, f32 *, s32, f32);
typedef struct { u8 pad0[4]; s16 n; u8 pad6[0x7A]; s32 f80; u8 pad84[8]; u8 *arr[6]; } S_3553B8;
void func_L36_003553B8(u8 *a0, f32 *a1, f32 a2, f32 a3) {
    S_3553B8 *s = *(S_3553B8 **)(a0 + 0x68);
    s32 i;
    f32 lo;
    f32 hi;
    f32 ang;
    f32 v[4];
    if (a2 != a3) {
        hi = a2 / (f32)s->n;
        lo = a3 / (f32)s->n;
        for (i = 0; i < 6; i++) {
            if (lo < D_L36_001DD7F8[i] && D_L36_001DD7F8[i] <= hi) {
                s->f80 &= ~(1 << i);
                ang = func_0038D160(a1[0], a1[2]);
                v[0] = func_0038D098(func_0038DB48(ang + func_003824E0(-D_L36_001DD92C, D_L36_001DD92C))) * D_L36_001DD87C;
                v[2] = func_0038D0B0(func_0038DB48(ang + func_003824E0(-D_L36_001DD92C, D_L36_001DD92C))) * D_L36_001DD87C;
                v[1] = 0.0f;
                s->arr[i] = func_L36_00353F58(a0, v, i, func_003824E0(-D_L36_001DD930, D_L36_001DD930));
            }
        }
    }
    *(s16 *)(a0 + 0x7C) = *(u16 *)&s->f80 & 0x3F;
}
/* localdecomp:end func_L36_003553B8 */
