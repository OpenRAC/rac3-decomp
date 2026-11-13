/* near miss (level 3, Starship Phoenix): 76 differences: the one-pass twin of func_L03_00399F38 with the same interblock motion of the loop decrement (see there); it also needs a config/levels/divs_nops.txt row `func_L03_00399D30 1 2` (one nop before the first div.s, two before the second) and the z argument computed after func_00382468 (retail multiplies by 210000.0f after that call and passes the product twice) */
#include "common.h"

/* localdecomp:start func_L03_00399D30 */
#include "vu0.h"
typedef struct { u8 pad0[0x10]; vu0_v4 pos; } A_00399D30;
typedef struct { u8 pad0[0x5C]; u8 *p5C; } T_00399D30;
extern T_00399D30 D_L03_0021F298;
__asm__(".extern D_L03_0021F298, 16");
extern f32 func_00382538(void);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L03_00399D30(void *arg) {
    A_00399D30 *a = arg;
    vu0_v4 vel;
    vu0_v4 pos;
    vu0_v4 dir;
    int i;
    for (i = 0; i < 1; i++) {
        f32 ang = func_00382538();
        vu0_v4 t;
        f32 sp;
        f32 life;
        f32 k;
        f32 z;
        u8 *p;
        *(vu0_q *)&t = 0;
        t.x = func_0038D0B0(ang);
        t.y = func_0038D098(ang);
        dir = t;
        sp = func_003824E0(4.0f, 6.0f) * 0.020000001f;
        life = (sp + sp) / 0.002f;
        k = func_003824E0(0.8f, 1.6f);
        func_0038CF68(&vel, &dir, (1.2f - k) / life * 0.5f);
        vel.z = sp;
        func_0038CF68(&dir, &dir, k);
        vec_add_ba(&pos, &a->pos, &dir);
        z = func_003824E0(0.5f, 1.5f) * 210000.0f;
        p = func_L01_0046FB40(&pos, &vel, (s32)life, 0x7FFFFFFF, func_00382468(2) != 0 ? -2 : 2, 0x7F, 0x7F, z, z, 0.002f, 0);
        if (p != 0) {
            p[2] = D_L03_0021F298.p5C[0];
            p[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L03_00399D30 */
