#include "common.h"

/* localdecomp:start func_L39_005CDE78 */
#include "vu0.h"
/* from func_L39_005C7F38 (same record) */
typedef int s128_005CDE78 __attribute__((mode(TI)));

typedef struct Src_005CDE78 {
    char pad0[0x10];
    s128_005CDE78 v10;
} Src_005CDE78;

typedef struct Rec_005CDE78 {
    f32 f0;
    f32 f4;
    f32 f8;
    Src_005CDE78 *pC;
    f32 f10;
    f32 f14;
    f32 f18;
    s32 w1C;
} Rec_005CDE78;

extern u8 *D_L39_002968EC[];
extern u8 *func_L39_005C4390(s32);

u8 *func_L39_005CDE78(s128_005CDE78 *a0, f32 *a1, s32 a2, s32 a3, u8 t0, s32 t1, s32 t2, s32 t3, f32 f12) {
    u8 *o;
    Rec_005CDE78 *e;
    s128_005CDE78 v;

    o = func_L39_005C4390(0x3C);
    if (o != 0) {
        *(s128_005CDE78 *)(o + 16) = *a0;
        e = (Rec_005CDE78 *)(o + 32);
        e->f0 = a1[0];
        e->f4 = a1[1];
        e->f8 = a1[2];
        e->pC = (Src_005CDE78 *)t3;
        e->w1C = t1;
        if (t1 == 1) {
            qzero(&v);
            if (e->pC != 0) {
                v = e->pC->v10;
            }
            e->f10 = ((f32 *)(o + 16))[0] - ((f32 *)&v)[0];
            e->f14 = ((f32 *)(o + 16))[1] - ((f32 *)&v)[1];
            e->f18 = ((f32 *)(o + 16))[2] - ((f32 *)&v)[2];
        }
        *(s32 *)(o + 4) = a2;
        o[9] = ((t2 >> 5) << 4) + 1;
        o[3] = 0x48;
        *(f32 *)(o + 12) = f12 * 210000.0f;
        o[8] = t0;
        o[1] = 0;
        o[2] = **D_L39_002968EC;
        *(s16 *)(o + 10) = a3;
    }
    return o;
}
/* localdecomp:end func_L39_005CDE78 */
