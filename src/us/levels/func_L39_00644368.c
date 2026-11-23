#include "common.h"

/* NTSC-U counterpart of func_L39_00646B98 (src/levels/shared/L39_00646980.c): the easing rates scaled for 60 Hz */
/* localdecomp:start func_L39_00644368 */
#include "vu0.h"

extern u8 D_L39_004998A0[];

extern void func_L39_0062FD10(void *, void *, void *, f32);
extern f32 func_L39_0062FE30(u8 *, f32 *);
extern f32 func_003887C8(void *, void *);
extern void func_003BEC60(void *, f32, f32, f32, f32, void *);
extern void func_00388830(void *, s32, f32);

typedef union Buf_00644368 {
    u8 b[8];
    u32 w[2];
} Buf_00644368;

static __inline__ u32 Dec_00644368(u8 *q) {
    Buf_00644368 buf;
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

static __inline__ s32 DecEq_00644368(u8 *q, s32 v) {
    return Dec_00644368(q) == v;
}

/* eases the speed at 0x132C (rate at 0x1330) towards t, then the point at 0x1180 = direction * speed + 0xA0 */
static __inline__ void Move_00644368(u8 *o, f32 t) {
    func_003BEC60(o + 0x132C, t, 0.00888888911f, 0.00888888911f, 1.06666672f, o + 0x1330);
    func_00388830(o + 0x1180, *(s32 *)(o + 0x1288) + 0x20, *(f32 *)(o + 0x132C));
    __asm__ __volatile__(
        "lqc2 $vf1, 0x1180(%0)\n"
        "lqc2 $vf2, 0xA0(%0)\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, 0x1180(%0)\n"
        : : "r"(o) : "memory");
}

void func_L39_00644368(u8 *o) {
    f32 t;
    f32 d;

    if (*(f32 *)(o + 0x132C) == 0.0f) {
        *(f32 *)(o + 0x132C) = 1.15f;
    }
    if (*(s32 *)(o + 0x1310) == 1) {
        t = 2.0f;
    } else {
        if (((DecEq_00644368(o + 0x19E4, 4) || DecEq_00644368(o + 0x19E4, 0x15)) && *(s32 *)(o + 0x1310) == 2) ||
            o[0x24FD] != 0) {
            t = 0.6f;
        } else {
            t = 1.15f;
        }
        if (DecEq_00644368(o + 0x19E6, 3)) {
            t = 1.75f;
        }
    }
    *(vu0_q *)(o + 0x1170) = *(vu0_q *)(o + 0x140);
    if (*(s32 *)(o + 0x1310) == 1) {
        if (!DecEq_00644368(o + 0x19E6, 4)) {
            *(s32 *)(o + 0x1334) = 0;
        } else if (!DecEq_00644368(o + 0x19E4, 0x83)) {
            if (*(f32 *)(o + 0x2AC) < 3.0f && *(s32 *)(o + 0x1334) == 0) {
                func_L39_0062FD10(o, o + 0x1170, o + 0x140, 0.0f);
                *(f32 *)(o + 0x132C) -= func_L39_0062FE30(o, (f32 *)(o + 0x140));
                d = func_003887C8(o + 0x260, o + 0xA0);
                if (d > 1.0f) {
                    d = *(f32 *)(o + 0x2AC);
                }
                t = 2.0f - d;
            } else {
                *(s32 *)(o + 0x1334) = 1;
            }
        } else {
            *(s32 *)(o + 0x1334) = 0;
        }
    }
    Move_00644368(o, t);
    if (DecEq_00644368(o + 0x19E6, 0x19) || DecEq_00644368(o + 0x19E4, 0x68)) {
        f32 f = *(f32 *)(o + 0x2C4) + 0.75f;
        if (*(f32 *)(o + 0x1188) < f) {
            *(f32 *)(o + 0x1188) = f;
        }
    }
}
/* localdecomp:end func_L39_00644368 */
