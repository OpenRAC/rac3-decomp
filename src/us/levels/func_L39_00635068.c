#include "common.h"

/* NTSC-U counterpart of func_L39_006378B0 (src/levels/shared/L39_00637310.c) */
extern u8 D_L39_004998A0[];
extern u8 D_L39_004998A0[];

/* localdecomp:start func_L39_00635068 */
#include "vu0.h"
typedef union { u8 b[8]; u32 w[2]; } Buf_006378B0;
typedef struct {
    u8 p0[0xA8];
    f32 fA8;
    u8 p1[0x2C0 - 0xAC];
    f32 f2C0;
    u8 p2[0x2F0 - 0x2C4];
    s32 w2F0;
    u8 p3[0x13E0 - 0x2F4];
    f32 f13E0;
    f32 f13E4;
    u8 p4[4];
    f32 f13EC;
    f32 f13F0;
    u8 p5[0x19E4 - 0x13F4];
    u8 b19E4;
    u8 p6[3];
    u8 b19E8;
    u8 p7[2];
    u8 b19EB;
} S_006378B0;
extern u8 D_L39_004998A0[];
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_L01_00445168(f32 *, f32 *, f32, f32, f32, f32);

/* the protected-byte decode the original inlined at each read (func_L39_00636F30 has it expanded) */
static __inline__ u32 decode_006378B0(u8 *q) {
    Buf_006378B0 buf;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;
    u32 a;

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
    buf.w[0] = a;
    buf.w[1] ^= a;
    return buf.w[1];
}

void func_L39_00635068(S_006378B0 *self) {
    f32 a;
    f32 b;

    if (self->w2F0 >= 11 || self->f13E0 < 0.0f
        || (decode_006378B0(&self->b19E8) ^ 0x11) == 0
        || (decode_006378B0(&self->b19EB) ^ 0x11) == 0
        || (decode_006378B0(&self->b19E4) ^ 0x90) == 0) {
        b = self->f13E0;
        a = self->f13E4;
        a = a - (b * 0.005f + a * 0.045f);
        self->f13E4 = a;
        if (fabs_asm(b) < 0.001f) {
            if (a < 0.0001f) self->f13E4 = 0.0f;
        }
    }
    self->f13E0 = self->f13E0 + self->f13E4;
    if ((decode_006378B0(&self->b19E4) ^ 0x35) == 0 && self->f13E0 > 0.0f) {
        if (self->f13E4 > 0.0f) self->f13E4 = 0.0f;
        func_003BEBF8(&self->f13E0, 0.0f, 0.0116666667f);
    }
    if ((decode_006378B0(&self->b19E4) ^ 0x7E) != 0) {
        if ((decode_006378B0(&self->b19E4) ^ 0x90) != 0) {
            func_L01_00445168(&self->f13EC, &self->f13F0, self->f2C0, 0.027f, 0.3f, 0.0f);
        }
    }
    self->fA8 = self->f13EC + -0.12f + self->f13E0;
}
/* localdecomp:end func_L39_00635068 */
