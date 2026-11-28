/* PAL near miss (wave 13 r28, 2026-11-28), first draft (fresh entry): 274 positional diff under the file's line, most of
 * them a one-word shift. Control flow, callee prototypes, both loops, the DecU/DecF/GtF helpers of the sibling
 * func_L40_0053E760 ((DecU ^ 0x14) != 0, (u8)GtF > 0.0f), the in = 0; if (d < X) in = 1 arms, the float register
 * allocation (separate d per block) and the tail match retail. Left: loop.c hoists only the constant 1 out of the
 * first loop; retail also hoists 0x109D and 0x539 into /, which spills a2 to 0x10() and puts bestIdx in
 * . The threshold is close: a pointer biv (rec++) hoists all five constants including 4.0f and -1.0f, dropping the
 * zlimit block hoists them too, so the original's first loop is a few RTL insns shorter than this one. With that,
 * vec should share 0x0() with the decode buffers (here it gets 0x10, frame space retail uses for the a2 spill). */
#include "common.h"

/* localdecomp:start func_L40_0053E1A8 */
#include "vu0.h"
typedef int Q_0053E1A8 __attribute__((mode(TI)));
typedef union Buf_0053E1A8 { u8 b[8]; u32 w[2]; f32 f[2]; } Buf_0053E1A8;
typedef struct { u8 pad0[0x10]; Q_0053E1A8 q10; } R_0053E1A8;
typedef struct { s32 w0; s32 w1; u8 *w2; } Rec_0053E1A8;
extern u8 D_L40_003BFE20[];
extern Rec_0053E1A8 D_L40_003478D0[];
extern u8 *D_L40_00249330[];
extern u8 *D_L40_00241640[];
extern u8 *D_L40_0035746C[];

static __inline__ u32 DecU_0053E1A8(u8 *q) {
    Buf_0053E1A8 buf;
    u32 a;
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
        *d++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    buf.w[0] = a;
    buf.w[1] ^= a;
    return buf.w[1];
}

static __inline__ f32 DecF_0053E1A8(u8 *q) {
    Buf_0053E1A8 buf;
    u32 a;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0.0f;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    buf.w[0] = a;
    buf.w[1] ^= a;
    return buf.f[1];
}

static __inline__ s32 GtF_0053E1A8(u8 *q, f32 v) {
    return DecF_0053E1A8(q) > v;
}

s32 func_L40_0053E1A8(u8 *obj, s32 a1, s32 a2, s32 a3, f32 radius, f32 radius2, f32 zlimit) {
    extern f32 func_L01_0040E570(void *, void *);
    extern s32 func_L39_006481F8(void *);
    extern s32 *func_L39_0061D7B0(void *);
    f32 r2;
    f32 bestA;
    f32 bestB;
    u8 *g;
    u8 *h;
    u8 *o;
    s32 *res;
    s32 bestIdx;
    s32 bestId;
    s32 in;
    s32 i;
    s32 x;
    s32 y;

    r2 = radius * radius;
    bestIdx = -1;
    bestA = 999999.0f;
    for (i = 0; i < 40; i++) {
        f32 d;

        if (D_L40_003478D0[i].w0 == 0) {
            continue;
        }
        if (D_L40_003478D0[i].w2[0x31] != 1) {
            continue;
        }
        if (*(s32 *)D_L40_003478D0[i].w2 != D_L40_003478D0[i].w0) {
            continue;
        }
        if (D_L40_003478D0[i].w1 == a1) {
            continue;
        }
        if (*(s16 *)(*(u8 **)(D_L40_003478D0[i].w2 + 0x1C) + 0xAA) == 0x109D
            && *(s32 *)(*(u8 **)(*(u8 **)(D_L40_003478D0[i].w2 + 0x1C) + 0x68) + 0x264) == 0x539) {
            continue;
        }
        d = func_L01_0040E570(obj + 0x10, *(u8 **)(D_L40_003478D0[i].w2 + 0x1C) + 0x10);
        in = 0;
        if (*(s32 *)(D_L40_003478D0[i].w2 + 0x1C) == a3) {
            if (d < r2 * 4.0f) {
                in = 1;
            }
        } else {
            if (d < r2) {
                in = 1;
            }
        }
        if (zlimit != -1.0f) {
            if (zlimit < __builtin_fabsf(*(f32 *)(obj + 0x18) - *(f32 *)(*(u8 **)(D_L40_003478D0[i].w2 + 0x1C) + 0x18))) {
                in = 0;
            }
        }
        if (in == 0) {
            continue;
        }
        if (d < bestA) {
            bestA = d;
            bestIdx = i;
        }
    }

    bestId = -1;
    bestB = 9999.0f;
    for (i = 0; i < 8; i++) {

        g = D_L40_00249330[i];
        if (g == 0) {
            continue;
        }
        if (func_L39_006481F8(g) == 0) {
            continue;
        }
        if (*(s32 *)(g + 0x2548) == a1) {
            continue;
        }
        if ((DecU_0053E1A8(g + 0x19E6) ^ 0x14) == 0) {
            continue;
        }
        if (!(u8)GtF_0053E1A8(g + 0x2476, 0.0f)) {
            continue;
        }
        {
            Q_0053E1A8 vec;
            f32 d;

            h = *(u8 **)(g + 0x2528);
            if (h != 0 && *(R_0053E1A8 **)(h + 0x2D0) != 0) {
                vec = (*(R_0053E1A8 **)(*(u8 **)(g + 0x2528) + 0x2D0))->q10;
            } else if (*(s32 *)(g + 0x2558) != 0 && *(R_0053E1A8 **)(g + 0x2524) != 0) {
                vec = (*(R_0053E1A8 **)(g + 0x2524))->q10;
            } else {
                qzero(&vec);
            }
            d = func_L01_0040E570(obj + 0x10, &vec);
            in = 0;
            if ((*(u8 **)(g + 0x2528) != 0 && a3 == *(s32 *)(*(u8 **)(g + 0x2528) + 0x2D0))
                || *(s32 *)(g + 0x2524) == a3) {
                if (d < r2 * 4.0f) {
                    in = 1;
                }
            } else {
                if (d < r2) {
                    in = 1;
                }
            }
            if (zlimit != -1.0f) {
                if (zlimit < __builtin_fabsf(*(f32 *)(obj + 0x18) - ((f32 *)&vec)[2])) {
                    in = 0;
                }
            }
            if (in == 0) {
                continue;
            }
            if (d < bestB) {
                bestId = *(s32 *)g;
                bestB = d;
            }
        }
    }

    if (*(s32 *)(D_L40_00241640[0] + 0x180) == 0) {
        if (a1 == 0) {
            x = *(s32 *)(D_L40_0035746C[0] + 0x44);
        } else {
            x = *(s32 *)(D_L40_0035746C[0] + 0x40);
        }
        if (x != -1) {
            y = *(s32 *)(*(u8 **)(D_L40_0024845C + (x << 8) + 0x68) + 0xB4);
            if (y != -1) {
                f32 d;

                o = D_L40_0024845C + (y << 8);
                d = func_L01_0040E570(o + 0x10, obj + 0x10);
                if (d < r2 && d < bestB) {
                    if (__builtin_fabsf(*(f32 *)(o + 0x18) - *(f32 *)(obj + 0x18)) < 15.0f) {
                        res = func_L39_0061D7B0(o);
                        if (res != 0) {
                            bestId = *res;
                            bestB = d;
                        }
                    }
                }
            }
        }
    }

    if (bestIdx == -1 && bestId == -1) {
        if (a2 == 0) {
            return -1;
        }
        if (radius2 == -1.0f) {
            return func_L40_0053DE38(a1, obj, r2);
        }
        return func_L40_0053DE38(a1, obj, radius2 * radius2);
    }
    if (bestB < bestA) {
        return bestId;
    }
    return D_L40_003478D0[bestIdx].w0;
}
/* localdecomp:end func_L40_0053E1A8 */
