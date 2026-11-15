#include "common.h"

/* localdecomp:start func_L39_005C7B40 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    u8 b8;
    u8 b9;
    s16 hA;
    float fC;
    u128_t v10;
    u128_t v20;
    s32 w30;
    s32 w34;
    s16 h38;
    s16 h3A;
    float f3C;
} Eff005C7B40;

extern u8 *D_L39_00296854[];
extern void *func_003CD108(s32);
extern s32 func_0019D510(void);

/* from func_L39_005C9A00's shape */
Eff005C7B40 *func_L39_005C7B40(u128_t *pos, u128_t *vec, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, float f, s32 a9) {
    Eff005C7B40 *e;
    u8 *t;
    if (a4 == 0) {
        return 0;
    }
    e = func_003CD108(0xF);
    if (e != 0) {
        e->v10 = *pos;
        e->w4 = a2;
        *(float *)((u8 *)&e->v10 + 12) = (float)a9;
        e->b9 = 0xA4;
        if (a7 != -1) {
            e->b3 = a7;
        } else {
            e->b3 = 0x48;
        }
        e->b1 = 0;
        e->fC = f;
        e->b8 = func_0019D510();
        if (a6 == -1) {
            e->b2 = *D_L39_00296854[0];
        } else {
            e->b2 = a6;
        }
        e->hA = a4;
        t = (u8 *)&e->v20;
        *(s16 *)(t + 0x18) = a4;
        *(float *)(t + 0x1C) = f;
        *(s32 *)(t + 0x10) = a2;
        *(s32 *)(t + 0x14) = a3;
        *(s16 *)(t + 0x1A) = a5;
        e->v20 = *vec;
        *(float *)(t + 0xC) = 0.00584f;
    }
    return e;
}
/* localdecomp:end func_L39_005C7B40 */
