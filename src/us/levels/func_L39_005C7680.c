#include "common.h"

/* NTSC-U counterpart of func_L39_005C9A00 (src/levels/shared/L39_005C9A00.c) */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    u8 b8;
    u8 b9;
    u8 padA[2];
    float fC;
    u128_t v10;
    u128_t v20;
    s32 w30;
    s32 w34;
    s32 w38;
} Eff005C9A00;

/* localdecomp:start func_L39_005C7680 */
extern u8 *D_L39_00296984[];
extern void *func_003CD108_005C7680(s32);
extern s32 func_0019D650(void);
Eff005C9A00 *func_L39_005C7680(u128_t *pos, u128_t *vec, s32 color, s32 val, float f) {
    Eff005C9A00 *e = func_003CD108_005C7680(0x1B);
    s32 *t;
    if (e != 0) {
        e->v10 = *pos;
        t = (s32 *)&e->v20;
        e->b8 = func_0019D650();
        e->b9 = 0x74;
        e->b3 = 0x48;
        e->fC = f;
        e->w4 = color;
        e->b1 = 0;
        e->b2 = *D_L39_00296984[0];
        t[6] = color >> 24;
        e->v20 = *vec;
        t[4] = val;
        t[5] = val;
    }
    return e;
}
/* localdecomp:end func_L39_005C7680 */
