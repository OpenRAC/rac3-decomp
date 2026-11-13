#include "common.h"

/* localdecomp:start func_L39_005C5C20 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    s128 v;
    s32 w16;
    s32 w20;
    s16 h24;
    s16 h26;
    f32 f28;
} Sub_005C5C20;

extern f32 D_L39_0024BC48;
extern u8 *D_L39_00296958[];
extern s32 func_L39_005B2498(s32);
extern u8 *func_003C7B98(s32);
extern u8 func_0019D650(void);

u8 *func_L39_005C5C20(s128 *a0, s128 *a1, s32 a2, s32 a3, s32 t0, s32 t1, f32 f12) {
    u8 *o;
    Sub_005C5C20 *e;
    u8 *p;

    if (t0 == 0) {
        return 0;
    }
    {
        if (0.9f < D_L39_0024BC48) {
            if (func_L39_005B2498(3) == 0) {
                return 0;
            }
        }
        if (0.95f < D_L39_0024BC48) {
            if (func_L39_005B2498(2) == 0) {
                return 0;
            }
        }
        if (1.0f < D_L39_0024BC48) {
            if (func_L39_005B2498(1) == 0) {
                return 0;
            }
        }
    }
    o = func_003C7B98(16);
    if (o != 0) {
        *(s128 *)(o + 16) = *a0;
        *(s32 *)(o + 4) = a2;
        o[1] = 0;
        *(f32 *)(o + 12) = f12;
        o[9] = 68;
        o[3] = 68;
        o[8] = func_0019D650();
        p = D_L39_00296958[0] + t1;
        if (t1 == 3) {
            p = D_L39_00296958[0];
        }
        e = (Sub_005C5C20 *)(o + 32);
        o[2] = *p;
        *(s16 *)(o + 10) = t0;
        e->h24 = t0;
        e->f28 = f12;
        e->w16 = a2;
        e->w20 = a3;
        e->h26 = t1;
        e->v = *a1;
        ((f32 *)e)[3] = ((f32 *)a0)[2] - 0.5f;
    }
    return o;
}
/* localdecomp:end func_L39_005C5C20 */
