#include "common.h"

/* declared by functions of L39_00634F38.c, which this file was cut from */
extern u8 D_L39_004997E0[];

/* localdecomp:start func_L39_00637310 */
extern u8 D_L39_004997E0[];
extern s32 D_001D5A18_sda;
extern s32 D_L39_00241128;

static inline u32 Dec_00637310(u8 *q) {
    u32 buf[2];
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
    d = (u8 *)buf;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf[0] ^= (u32)q;
    buf[1] ^= buf[0];
    return buf[1];
}

static inline f32 DecFv_00637310(u8 *q) {
    u32 buf[2];
    f32 r;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        r = 0.0f;
    } else {
        n = *q;
        k = ((u32)q - n) & 7;
        m = n + 1;
        d = (u8 *)buf;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        buf[0] ^= (u32)q;
        buf[1] ^= buf[0];
        r = *(f32 *)&buf[1];
    }
    return r;
}

s32 func_L39_00637310(u8 *o, s32 a1, s32 a2) {
    s32 flag = 0;
    s32 v;
    s32 z;
    f32 zero;

    if ((Dec_00637310(o + 0x19E4) ^ 0x39) == 0 || (Dec_00637310(o + 0x19E4) ^ 0x8E) == 0 ||
        ((Dec_00637310(o + 0x19E4) ^ 0x90) == 0 &&
         ((Dec_00637310(o + 0x19E7) ^ 0x39) == 0 || (Dec_00637310(o + 0x19E7) ^ 0x8E) == 0))) {
        if (a1 == 0x7A || a1 == 0x7E || a1 == 0x76) {
            flag = 1;
        }
    }
    if (!flag && (Dec_00637310(o + 0x19E6) ^ 0x14) == 0) {
        s32 t;
        if (a1 != 0x63 || a2 != 2) return 0;
        t = D_L39_00241128;
        v = t;
    } else {
        v = D_001D5A18_sda;
    }
    if ((v == 2 || v == 6) && a2 != 2) return 0;
    if (flag) return 1;
    zero = 0.0f;
    z = DecFv_00637310(o + 0x2476) == zero;
    if (!(u8)z) return 1;
    if ((Dec_00637310(o + 0x19E6) ^ 2) == 0 || (Dec_00637310(o + 0x19E6) ^ 7) == 0) {
        if (a1 != 6 && a1 != 0x39 && a1 != 0x76 && a1 != 0x7A && a1 != 0x7B && a1 != 0x7E &&
            a1 != 0x69 && a1 != 0x7F && a1 != 0x81 && a1 != 0x90) {
            return 0;
        }
        return 1;
    }
    return 1;
}
/* localdecomp:end func_L39_00637310 */

/* localdecomp:start func_L39_006378B0 */
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
extern u8 D_L39_004997E0[];
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_L01_004482A0(f32 *, f32 *, f32, f32, f32, f32);

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
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    buf.w[0] = a;
    buf.w[1] ^= a;
    return buf.w[1];
}

void func_L39_006378B0(S_006378B0 *self) {
    f32 a;
    f32 b;

    if (self->w2F0 >= 9 || self->f13E0 < 0.0f
        || (decode_006378B0(&self->b19E8) ^ 0x11) == 0
        || (decode_006378B0(&self->b19EB) ^ 0x11) == 0
        || (decode_006378B0(&self->b19E4) ^ 0x90) == 0) {
        b = self->f13E0;
        a = self->f13E4;
        a = a - (b * 0.0072000003f + a * 0.054000005f);
        self->f13E4 = a;
        if (fabs_asm(b) < 0.001f) {
            if (a < 0.0001f) self->f13E4 = 0.0f;
        }
    }
    self->f13E0 = self->f13E0 + self->f13E4;
    if ((decode_006378B0(&self->b19E4) ^ 0x35) == 0 && self->f13E0 > 0.0f) {
        if (self->f13E4 > 0.0f) self->f13E4 = 0.0f;
        func_003C4138(&self->f13E0, 0.0f, 0.014f);
    }
    if ((decode_006378B0(&self->b19E4) ^ 0x7E) != 0) {
        if ((decode_006378B0(&self->b19E4) ^ 0x90) != 0) {
            func_L01_004482A0(&self->f13EC, &self->f13F0, self->f2C0, 0.03888f, 0.43200004f, 0.0f);
        }
    }
    self->fA8 = self->f13EC + -0.12f + self->f13E0;
}
/* localdecomp:end func_L39_006378B0 */
