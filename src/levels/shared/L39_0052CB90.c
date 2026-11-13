#include "common.h"

/* localdecomp:start func_L39_0052CB90 */
typedef union Buf_0052CB90 {
    u8 b[8];
    u32 w[2];
} Buf_0052CB90;

typedef struct Inner_0052CB90 {
    u8 padA0_[0xA0];
    u8 bA0[0x10];
    u8 bB0[0x10];
    u8 pad0C0[0x19E4 - 0xC0];
    u8 b19E4;
    u8 pad19E5;
    u8 b19E6;
} Inner_0052CB90;

typedef struct Obj_0052CB90 {
    u8 pad0[0xC0];
    Inner_0052CB90 *pC0;
    u8 padC4[0x1F0 - 0xC4];
    s32 w1F0;
    u8 pad1F4[8];
    s32 w1FC;
} Obj_0052CB90;

typedef struct Self_0052CB90 {
    u8 pad0[0x68];
    Obj_0052CB90 *p68;
} Self_0052CB90;

extern u8 D_L39_004997E0[];
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_003EB5E0(s32, s32);
extern void func_L39_00637EC8(void *, void *, void *, s32, s32, s32, s32);

void func_L39_0052CB90(Self_0052CB90 *self) {
    Obj_0052CB90 *o = self->p68;

    if (o->w1F0 != 0) {
        o->w1F0 = 0;
        func_00382810(o->w1FC, 0, 0, 1.1100293f, 0.005f, 0.2f, 0.0f);
    }
    func_L01_003EB5E0(o->w1FC, 0);
    if (o->pC0 != 0) {
        u32 b1;
        {
            Buf_0052CB90 buf;
            u32 a;
            u32 b;
            s32 n;
            s32 k;
            s32 m;
            s32 i;
            u8 *d;
            u8 *q = &o->pC0->b19E6;

            if (*q == 0) {
                b1 = 0;
            } else {
                n = *q;
                k = ((u32)q - n) & 7;
                m = n + 1;
                d = buf.b;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                b = buf.w[1] ^ a;
                buf.w[0] = a;
                buf.w[1] = b;
                b1 = b;
            }
        }
        if ((b1 ^ 0x14) == 0) {
            o->pC0 = 0;
        } else {
            Inner_0052CB90 *p = o->pC0;
            u8 *pa = p->bA0;
            u8 *pb = p->bB0;
            u32 b2;
            {
                Buf_0052CB90 buf;
                u32 a;
                u32 b;
                s32 n;
                s32 k;
                s32 m;
                s32 i;
                u8 *d;
                u8 *q = &p->b19E4;

                if (*q == 0) {
                    b2 = 0;
                } else {
                    n = *q;
                    k = ((u32)q - n) & 7;
                    m = n + 1;
                    d = buf.b;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    a = buf.w[0] ^ (u32)q;
                    b = buf.w[1] ^ a;
                    buf.w[0] = a;
                    buf.w[1] = b;
                    b2 = b;
                }
            }
            func_L39_00637EC8(o->pC0, pa, pb, b2, 0, 1, 0);
            o->pC0 = 0;
        }
    }
}
/* localdecomp:end func_L39_0052CB90 */

INCLUDE_ASM("asm/levels", func_L39_0052CD40);
