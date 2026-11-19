/* functional: high. 169 words differ at level_01, from scheduling/register allocation and gp vs lui addressing of D_L01_001DFC08 and D_L01_001E10xx (retail uses both forms for the scratch-pool pointer); same calls, arguments and order. Declares D_L01_001EAA00 as a local hit-record struct: conflicts with other files declaring it in the same TU (see L01_004463D0.c Ring_443938, L01_004FE668.c Dir_004FE668). Callees func_0038CDF8=lerp(out,a,b,t), func_0038CF00=distance, func_0038CF68=set length, func_003A92F0=switch scratch buffer. */
#include "vu0.h"

typedef struct {
    s32 word0;
    u8 pad4[0x14];
    s32 object;
    u8 pad1C[4];
    vu0_v4 hit_position;
    vu0_v4 saved_hit;
    vu0_v4 direction;
} Hit_446E38;

extern Hit_446E38 D_L01_001EAA00;
extern s32 D_L01_001E1060[];
extern s32 D_L01_001E1068[];
extern s32 D_L01_001E1070[];
extern s32 D_L01_001E1074[];
extern u8 *D_L01_001DFC08;

extern void func_0038CDF8(void *, void *, void *, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003A92F0(s32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern s32 func_L01_003FDCA0(void *, void *, f32);
extern s32 func_L01_003FE1D8(void *, void *, f32);
extern s32 func_L01_003FE378(void *, void *, s32, f32);
extern s32 func_L01_003FE540(void *, void *, void *, f32, f32);

f32 func_L01_00446E38(f32 *a, f32 *b, s32 flags, void *list, f32 radius) {
    vu0_v4 mid;
    f32 len, h, t;
    s32 n, k, i;
    s32 want_extra = (flags >> 8) & 1;
    s32 mask;
    u8 *entry;

    func_0038CDF8(&mid, a, b, 0.5f);
    t = 1.0f;
    len = func_0038CF00(a, b);
    h = radius + len * 0.5f;

    D_L01_001DFC08 = (u8 *)(D_L01_001E1060[D_L01_001E1074[0]] + D_L01_001E1070[0] - 0x8000);
    if ((s32)D_L01_001DFC08 < D_L01_001E1068[0] + 0x1000) {
        func_003A92F0(1);
        D_L01_001DFC08 = (u8 *)(D_L01_001E1060[1 - D_L01_001E1074[0]] + D_L01_001E1070[0] - 0x8000);
    }

    mask = (flags & 0xA7) | 0x50;
    n = func_L01_003FB640(&mid, mask, list, h);
    if (mask & 0x80) {
        k = func_L01_003FDCA0(&mid, D_L01_001DFC08, h);
        D_L01_001DFC08 -= k << 6;
        n += k;
    }
    if (want_extra) {
        k = func_L01_003FE1D8(&mid, D_L01_001DFC08, h);
        D_L01_001DFC08 -= k << 6;
        n += k;
    }

    if (n != 0) {
        qzero(&D_L01_001EAA00.direction);
        if (func_L01_003FE378(a, b, n, radius)) {
            t = func_0038CF00(&D_L01_001EAA00.hit_position, a) / len;
            func_0038CF68(&D_L01_001EAA00.direction, &D_L01_001EAA00.direction, 1.0f);
        }
        if (n > 0) {
            entry = D_L01_001DFC08;
            for (i = n; i != 0; i--, entry += 0x40) {
                if (func_L01_003FE540(a, b, entry, radius, t)) {
                    t = func_0038CF00(&D_L01_001EAA00.hit_position, a) / len;
                    func_0038CF68(&D_L01_001EAA00.direction, &D_L01_001EAA00.direction, 1.0f);
                }
            }
        }
    }

    if (t < 1.0f) {
        vec_copy(&D_L01_001EAA00.saved_hit, &D_L01_001EAA00.hit_position);
        func_0038CE20(&D_L01_001EAA00.hit_position, &D_L01_001EAA00.direction, -radius);
        vec_add_ba(&D_L01_001EAA00.hit_position, &D_L01_001EAA00.hit_position, &D_L01_001EAA00.saved_hit);
        if (D_L01_001EAA00.object == D_L01_001EAA00.word0) {
            D_L01_001EAA00.object = 0;
        }
    }
    return t;
}
