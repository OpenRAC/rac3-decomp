#include "common.h"

/* NTSC-U counterpart of func_L39_005289D0 (src/levels/shared/L39_00528EE8.c) */
/* localdecomp:start func_L39_005289D0 */
#include "vu0.h"
typedef int u128_005289D0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_005289D0;
typedef struct { u8 pad0[0x10]; V_005289D0 pos; u8 pad20[0x68 - 0x20]; u8 *x68; } O_005289D0;
typedef struct { u8 pad0[0x38]; f32 f38; } M_005289D0;

extern u8 *D_L39_00296974[];
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B2568(f32, f32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0019D650(void);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L39_005289D0(O_005289D0 *o, void *a1) {
    V_005289D0 v0;
    V_005289D0 v10;
    M_005289D0 *m = (M_005289D0 *)o->x68;
    f32 size;
    s32 n;
    s32 color;
    s32 c;
    u8 *p;

    size = func_L39_005B2510(200.0f, 1000.0f);
    n = (s32)func_L39_005B2568(1.0f, 3.0f);
    *(u128_005289D0 *)&v10 = 0;
    v10.x = func_L39_005B2510(-1.0f, 1.0f);
    v10.y = func_L39_005B2510(-1.0f, 1.0f);
    v10.z = func_L39_005B2510(-1.0f, 1.0f);
    *(u128_005289D0 *)&v0 = *(u128_005289D0 *)&v10;
    func_00388830(&v0, &v0, func_L39_005B2510(0.1f, 0.2f) * 0.016666668f);
    func_00388830(&v10, a1, -func_L39_005B2510(0.0016666668f, 0.016666668f));
    vec_add_ba(&v0, &v0, &v10);
    func_00388830(&v10, a1, func_L39_005B2510(0.0f, 1.0f) * m->f38);
    vec_add_ba(&v10, &v10, &o->pos);
    if ((func_0019D650() & 1) != 0) {
        c = 0x40;
        color = 0;
        size = size + size;
    } else {
        color = 0x406080;
        c = 0x7F;
    }
    p = func_L01_00466F98(&v10, &v0, func_L39_005B24C8(0x1C, 0x28), c, color, n, 273000.0f, size, 1.0f, 0.0f, 0.0f);
    if (p != 0) {
        p[2] = *D_L39_00296974[0];
        p[3] = c == 0x7F ? 0x48 : 0x44;
    }
}
/* localdecomp:end func_L39_005289D0 */
