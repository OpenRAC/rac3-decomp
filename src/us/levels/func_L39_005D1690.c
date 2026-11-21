#include "common.h"

/* NTSC-U counterpart of func_L39_005D3B70 (src/levels/shared/L39_005D3B70.c) */
/* localdecomp:start func_L39_005D1690 */
typedef int u128_005D3B70 __attribute__((mode(TI)));

typedef struct Q_005D3B70 {
    u128_005D3B70 v;
    s32 w10;
} Q_005D3B70;

typedef struct S_005D3B70 {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u32 w4;
    u8 b8;
    u8 b9;
    s16 h0A;
    f32 f0C;
    u128_005D3B70 v10;
    Q_005D3B70 q;
} S_005D3B70;

extern u8 *D_L39_00296ACC[];
extern void *func_003C7B98(s32);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_L39_005B2498(s32);
extern s32 func_L39_005B24C8(s32, s32);
extern f32 func_L39_005B2510(f32, f32);

void *func_L39_005D1690(void *a0, void *a1, s32 a2, f32 f) {
    S_005D3B70 *p;
    Q_005D3B70 *q;

    p = func_003C7B98(0x6D);
    if (p != 0) {
        u128_005D3B70 pos = *(u128_005D3B70 *)a0;
        s32 value = 0x44;
        do {
            p->b3 = a2;
            p->v10 = pos;
            p->b1 = 0;
            q = &p->q;
            p->b9 = value;
            p->b8 = func_L39_005B2498(0xFF);
            p->h0A = func_L39_005B24C8(5, 0x32);
            q->v = *(u128_005D3B70 *)a1;
            p->f0C = f * 210000.0f * 2.5f;
            q->w10 = func_L39_005B24C8(0x40, 0x80);
            p->b2 = *D_L39_00296ACC[0];
            p->w4 = func_003894A0(0x103080, 0, func_L39_005B2510(0.0f, 0.5f)) | (q->w10 << 24);
        } while (0);
    }
    return p;
}
/* localdecomp:end func_L39_005D1690 */
