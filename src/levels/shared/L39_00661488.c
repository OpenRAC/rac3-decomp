#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    u8 b0C;
    u8 b0D;
    u8 b0E;
} S_006618D8;
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x128 - 8];
    s32 w128;
    u8 pad12C[0x170 - 0x12C];
    s32 w170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} S_1A5CD0_006618D8;

/* declared by functions of L39_0065D0A0.c, which this file was cut from */
extern u8 D_L39_004997E0[];

/* localdecomp:start func_L39_00661488 */
#include "vu0.h"

typedef union Buf_00661488 {
    u8 b[8];
    u32 w[2];
    vu0_v4 v;
} Buf_00661488;

typedef struct Aux_00661488 {
    u8 pad0[0x50];
    struct { u8 pad0[0x86]; s16 h86; } *p50;
} Aux_00661488;

typedef struct S_00661488 {
    u8 pad0[0x40];
    u8 v40[0x10];
    u8 pad50[0xA0 - 0x50];
    u8 vA0[0x10];
    u8 padB0[0x1310 - 0xB0];
    u32 s1310;
    u8 pad1314[0x19E4 - 0x1314];
    u8 b19E4;
    u8 pad19E5;
    u8 b19E6;
    u8 pad19E7[0x2378 - 0x19E7];
    s32 a2378[8];
    s32 s2398;
    s32 s239C;
    u8 v23A0[0x10];
    u8 v23B0[0xC];
    f32 f23BC;
    u8 v23C0[0x10];
    u8 pad23D0[0x24FD - 0x23D0];
    u8 b24FD;
    u8 pad24FE[0x2530 - 0x24FE];
    Aux_00661488 *p2530;
    struct { u8 pad0[0x568]; s32 s568; } *p2534;
} S_00661488;

extern u8 D_L39_004997E0[];
extern void func_0038CF68(s32 a, s32 b, f32 x);
extern void func_L39_005BA418(void *, void *);
extern void func_0038D308(void *, void *);

void func_L39_00661488(S_00661488 *s) {
    Buf_00661488 buf;
    s32 d;
    s32 base;
    s32 idx;
    f32 a;
    f32 b;
    f32 z;

    if (s->p2530->p50->h86 != 0x21) {
        base = s->p2534->s568 - 7;
        d = s->s2398 - base;
        idx = d % 8;
        if (idx > s->s239C - 1) {
            idx = 0;
        }
        if (s->s1310 < 2) {
            a = 2.0f;
            b = -3.0f;
        } else {
            if (((({
                    u32 r;
                    u8 *q = &s->b19E4;
                    if (*q == 0) {
                        r = 0;
                    } else {
                        u32 x, y;
                        s32 n = *q;
                        s32 k = ((u32)q - n) & 7;
                        s32 m = n + 1;
                        s32 i;
                        u8 *dd = buf.b;
                        for (i = 0; i < 40; i += 5) {
                            *dd++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                        }
                        x = buf.w[0] ^ (u32)q;
                        y = buf.w[1] ^ x;
                        buf.w[0] = x;
                        buf.w[1] = y;
                        r = y;
                    }
                    r == 4;
                }) ||
                  ({
                    u32 r;
                    u8 *q = &s->b19E4;
                    if (*q == 0) {
                        r = 0;
                    } else {
                        u32 x, y;
                        s32 n = *q;
                        s32 k = ((u32)q - n) & 7;
                        s32 m = n + 1;
                        s32 i;
                        u8 *dd = buf.b;
                        for (i = 0; i < 40; i += 5) {
                            *dd++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                        }
                        x = buf.w[0] ^ (u32)q;
                        y = buf.w[1] ^ x;
                        buf.w[0] = x;
                        buf.w[1] = y;
                        r = y;
                    }
                    r == 0x15;
                })) &&
                 s->s1310 == 2) ||
                s->b24FD != 0) {
                a = 0.6f;
            } else {
                a = 1.15f;
            }
            if (({
                    u32 r;
                    u8 *q = &s->b19E6;
                    if (*q == 0) {
                        r = 0;
                    } else {
                        u32 x, y;
                        s32 n = *q;
                        s32 k = ((u32)q - n) & 7;
                        s32 m = n + 1;
                        s32 i;
                        u8 *dd = buf.b;
                        for (i = 0; i < 40; i += 5) {
                            *dd++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                        }
                        x = buf.w[0] ^ (u32)q;
                        y = buf.w[1] ^ x;
                        buf.w[0] = x;
                        buf.w[1] = y;
                        r = y;
                    }
                    r == 3;
                })) {
                a = 1.75f;
            }
            b = 0.0f;
        }
        z = 0.0f;
        func_0038CF68((s32)s->v23A0, (s32)s->v40, a);
        vec_add_ab(s->v23A0, s->v23A0, s->vA0);
        if (b != z) {
            func_0038CF68((s32)&buf, (s32)s->v23C0, b);
            vec_add_ab(s->v23A0, s->v23A0, &buf);
        }
        func_L39_005BA418(s->v23B0, &s->a2378[idx]);
        s->f23BC = z;
        func_0038D308(s->v23C0, s->v23B0);
    }
}
/* localdecomp:end func_L39_00661488 */
