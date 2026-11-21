#include "common.h"

/* NTSC-U counterpart of func_L03_00399D30 (src/levels/03_starship_phoenix/L03_00399D30.c): 0.002 -> 0.00138889; 0.02 -> 0.0166667 */
/* localdecomp:start func_L03_00398650 */
#include "vu0.h"
typedef struct { u8 pad0[0x10]; vu0_v4 pos; } A_00399D30;
extern u8 *D_L03_0021F318[];
extern f32 func_0037E2A8(void);
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);

/* the unit vector at angle ang in the xy plane */
static __inline__ vu0_v4 angle_dir_00399D30(f32 ang) {
    vu0_v4 t;
    *(vu0_q *)&t = 0;
    t.x = func_00388978(ang);
    t.y = func_00388960(ang);
    return t;
}

void func_L03_00398650(void *arg) {
    A_00399D30 *a = arg;
    vu0_v4 vel;
    vu0_v4 pos;
    int i;
    for (i = 0; i >= 0; i--) {
        s32 n;
        u8 *p;
        {
            vu0_v4 dir;
            dir = angle_dir_00399D30(func_0037E2A8());
            {
                f32 sp = func_0037E250(4.0f, 6.0f) * 0.0166666675f;
                f32 life = (sp + sp) / 0.00138888892f;
                f32 k = func_0037E250(0.8f, 1.6f);
                n = life;
                func_00388830(&vel, &dir, (1.2f - k) / life * 0.5f);
                vel.z = sp;
                func_00388830(&dir, &dir, k);
            }
            vec_add_ba(&pos, &a->pos, &dir);
        }
        {
            f32 z = func_0037E250(0.5f, 1.5f);
            s32 sign = func_0037E1D8(2) != 0 ? -2 : 2;
            z *= 210000.0f;
            p = ((u8 *(*)(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32))func_L01_0046C468)(
                &pos, &vel, n, 0x7FFFFFFF, sign, 0x7F, 0x7F, z, z, 0.00138888892f, 0);
        }
        if (p != 0) {
            p[2] = D_L03_0021F318[23][0];
            p[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L03_00398650 */
