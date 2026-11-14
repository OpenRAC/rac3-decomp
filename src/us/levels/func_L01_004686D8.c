#include "common.h"

/* NTSC-U counterpart of func_L01_0046BD88 (src/levels/shared/L01_0046A938.c) */
/* localdecomp:start func_L01_004686D8 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    s128 vec;
    u8 b10;
    u8 b11;
    u8 b12;
    u8 b13;
    u8 b14;
    u8 b15;
    u8 b16;
    u8 b17;
    s32 w18;
    f32 f1C;
} __attribute__((aligned(16))) Inner_004686D8;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u32 w4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    s128 pos;
    Inner_004686D8 in;
} __attribute__((aligned(16))) Part_004686D8;

extern Part_004686D8 *func_L01_0045E438(s32 id);
extern s32 func_0013D3E0(void);
extern f32 func_0037E250(f32 low, f32 high);
extern f32 func_0037E2A8(void);
extern void func_0037E4B8(void *dst, f32 a, f32 b, f32 c);
extern u8 *D_L01_002211FC[];

Part_004686D8 *func_L01_004686D8(s128 *pos, u8 a1, u8 a2, u8 a3, u8 t0, u8 t1, s32 t2, f32 f12, f32 f13) {
    Part_004686D8 *p = func_L01_0045E438(0x3A);
    Inner_004686D8 *in;
    u8 type;
    s32 v;

    if (p != 0) {
        p->pos = *pos;
        in = &p->in;
        p->b9 = 0x70;
        p->b3 = 0x44;
        p->b1 = 0;
        p->b2 = D_L01_002211FC[1][func_0013D3E0() & 7];
        p->fC = 21000.0f;
        p->b8 = func_0013D3E0();
        in->b10 = a1;
        in->b12 = a3;
        in->b13 = t0;
        in->w18 = t2;
        in->f1C = f12;
        in->b11 = a2;
        in->b15 = t1;
        type = in->b10;
        switch (type) {
        case 0:
        case 1:
            p->hA = a2;
            p->w4 = 0xFF808080;
            in->b14 = 0;
            break;
        case 2:
            f12 = func_0037E250(3.0f, 9.0f) * f13;
            f12 = f12 * 0.016666668f;
            f13 = func_0037E2A8();
            func_0037E4B8(in, f12, f13, func_0037E250(1.3439035f, 1.7976891f));
            p->fC = 42000.0f;
            v = (func_0013D3E0() & 0x1F) + 0x10;
            in->b16 = v;
            p->w4 = (in->b16 << 24) | 0x808080;
            p->hA = t1;
            in->b14 = type;
            break;
        }
    }
    return p;
}
/* localdecomp:end func_L01_004686D8 */
