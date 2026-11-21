/* exact: matches byte-identical at L39 under the file flags (D_00296874 kept unsized so it loads via lui like retail). */
#include "vu0.h"
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0019D510(void);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern u8 *D_00296874[];
typedef struct { u8 pad0[0x38]; f32 x38; } M_00528EE8;
typedef struct { u8 pad0[0x10]; f32 pos[4]; u8 pad20[0x68 - 0x20]; M_00528EE8 *x68; } O_00528EE8;

void func_L39_00528EE8(O_00528EE8 *o, f32 *dir) {
    f32 v0[4] __attribute__((aligned(16)));
    f32 v1[4] __attribute__((aligned(16)));
    M_00528EE8 *m = o->x68;
    f32 speed;
    s32 n;
    s32 a;
    s32 color;
    s32 cnt;
    u8 *p;

    speed = func_L39_005B4410(200.0f, 1000.0f);
    n = (s32)func_L39_005B4468(1.0f, 3.0f);
    *(u128_t *)v1 = 0;
    v1[0] = func_L39_005B4410(-1.0f, 1.0f);
    v1[1] = func_L39_005B4410(-1.0f, 1.0f);
    v1[2] = func_L39_005B4410(-1.0f, 1.0f);
    *(u128_t *)v0 = *(u128_t *)v1;
    func_0038CF68(v0, v0, func_L39_005B4410(0.1f, 0.2f) * 0.020000001f);
    func_0038CF68(v1, dir, -func_L39_005B4410(0.002f, 0.020000001f));
    vec_add_ab(v0, v0, v1);
    func_0038CF68(v1, dir, func_L39_005B4410(0.0f, 1.0f) * m->x38);
    vec_add_ab(v1, v1, o->pos);
    if (func_0019D510() & 1) {
        a = 0x40;
        color = 0;
        speed += speed;
    } else {
        a = 0x7F;
        color = 0x406080;
    }
    cnt = func_L39_005B43C8(0x1C, 0x28);
    p = func_L01_0046A610(v1, v0, (cnt * 5 + 2) / 6, a, color, n, 273000.0f, speed, 1.0f, 0.0f, 0.0f);
    if (p != 0) {
        p[2] = *D_00296874[0];
        p[3] = (a == 0x7F) ? 0x48 : 0x44;
    }
}
