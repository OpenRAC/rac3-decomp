#include "common.h"

/* NTSC-U counterpart of func_L01_004AD808 (src/levels/shared/L01_004AD7A8.c) */
/* localdecomp:start func_L01_004A9DE8 */
#include "vu0.h"

typedef int u128_004AD808 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_004AD808;
typedef struct { u8 pad0[0x10]; V_004AD808 pos; } O_004AD808;

extern u128_004AD808 D_L01_002EDF00[];
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_003888C8(void *, void *, void *);
extern s32 func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);

void func_L01_004A9DE8(void *a0, f32 z0) {
    O_004AD808 *o = a0;
    V_004AD808 v10;
    V_004AD808 v20;
    V_004AD808 v30;
    V_004AD808 *pv = &v10;
    u128_004AD808 *row;
    s32 i;

    for (i = 0; i < 6; i++) {
        v10.x = func_0037E250(-0.016666668f, 0.016666668f);
        v10.y = func_0037E250(-0.016666668f, 0.016666668f);
        v10.z = z0 + func_0037E250(-0.004166667f, 0.004166667f);
        v10.w = 0.4f;
        *(u128_004AD808 *)&v20 = *(u128_004AD808 *)&v10;
        v20.w = 0.6f;
        row = &D_L01_002EDF00[i];
        *(u128_004AD808 *)&v30 = *row;
        func_003888C8(&v30, &v30, (u8 *)o + 0xC0);
        vec_add_ab(&v30, &v30, &o->pos);
        func_L01_0045FEC8(&v30, pv, &v20, 0x30F0F0F0, 0x14F0F0F0, 4, 4, func_0037E1D8(4) + 4, 0x17);
    }
}
/* localdecomp:end func_L01_004A9DE8 */
