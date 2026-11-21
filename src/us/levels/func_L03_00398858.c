#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L03_00399F38 (src/levels/03_starship_phoenix/L03_00399D30.c): 1/60 s step instead of 0.02 */
/* localdecomp:start func_L03_00398858 */
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; u8 *p68; } A_00398858;
extern u8 *D_L03_0021F318[];
extern f32 func_0037E2A8(void);
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);

void func_L03_00398858(void *arg) {
    A_00398858 *a = arg;
    u8 *s = a->p68;
    vu0_v4 vel;
    vu0_v4 pos;
    vu0_v4 dir;
    int i;
    for (i = 2; i >= 0; i--) {
        s32 n;
        f32 z;
        u8 *p;
        {
            f32 ang = func_0037E2A8();
            vu0_v4 t;
            *(vu0_q *)&t = 0;
            t.x = func_00388978(ang);
            t.y = func_00388960(ang);
            dir = t;
        }
        func_00388830(&vel, &dir, func_0037E250(2.0f, 4.0f) * 0.016666668f);
        n = func_0037E208(0x3C, 0x78);
        {
            f32 h = a->pos.z - *(f32 *)(s + 0x44);
            if (h > 1.0f) h = 1.0f;
            z = func_0037E250(h * 0.5f, h);
        }
        func_00388830(&dir, &dir, 1.7f);
        vec_add_ba(&pos, &a->pos, &dir);
        pos.z = *(f32 *)(s + 0x44) + z * 0.5f;
        {
            s32 sign = func_0037E1D8(2) != 0 ? -2 : 2;
            p = ((u8 *(*)(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32))func_L01_0046C468)(
                &pos, &vel, n, 0x7FFFFFFF, sign, 0x7F, 0x20, z * 210000.0f, 0.0f, 0.0f, 0);
        }
        if (p != 0) {
            p[2] = D_L03_0021F318[23][0];
            p[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L03_00398858 */
