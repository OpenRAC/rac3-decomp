#include "common.h"

/* localdecomp:start func_L01_0046B5E8 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    s128 vec;
    s16 h10;
    u8 b12;
    u8 b13;
    u8 b14;
    u8 b15;
    u8 b16;
    u8 b17;
    s32 w18;
    f32 f1C;
} __attribute__((aligned(16))) Inner_0046B5E8;

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
    Inner_0046B5E8 in;
} __attribute__((aligned(16))) Part_0046B5E8;

extern Part_0046B5E8 *func_L01_0045E438(s32 id);
extern s32 func_0013D3E0(void);
extern f32 func_0037E250(f32 low, f32 high);
extern f32 func_0037E2A8(void);
extern void func_0037E4B8(void *dst, f32 a, f32 b, f32 c);
extern u8 *D_L01_002211FC[];

Part_0046B5E8 *func_L01_0046B5E8(s128 *pos, u8 a1, u8 a2, s16 a3, u8 t0, u8 t1, s32 t2, f32 f12, f32 f13) {
    Part_0046B5E8 *p = func_L01_0045E438(0x51);
    Inner_0046B5E8 *in;
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
        in->b12 = a2;
        in->b13 = t0;
        in->w18 = t2;
        in->f1C = f12;
        in->b17 = a1;
        in->h10 = a3;
        in->b15 = t1;
        switch (in->b12) {
        case 0:
            p->hA = a3;
            p->w4 = 0xFF808080;
            in->b14 = 0;
            break;
        case 1:
            f12 = func_0037E250(3.0f, 9.0f) * f13;
            f12 = f12 * 0.016666668f;
            f13 = func_0037E2A8();
            func_0037E4B8(in, f12, f13, func_0037E250(1.3439035f, 1.7976891f));
            p->fC = 42000.0f;
            v = (func_0013D3E0() & 0x1F) + 0x10;
            in->b16 = v;
            p->w4 = (in->b16 << 24) | 0x808080;
            p->hA = t1;
            in->b14 = 1;
            break;
        }
    }
    return p;
}
/* localdecomp:end func_L01_0046B5E8 */
