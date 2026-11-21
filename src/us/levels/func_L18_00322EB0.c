#include "common.h"

/* NTSC-U counterpart of func_L18_00323518 (src/levels/shared/L18_00322F80.c) */
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);

/* localdecomp:start func_L18_00322EB0 */
#include "vu0.h"
typedef struct { u8 p0[0x38]; f32 f38; } P_00323518;
typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 p20[0x48]; P_00323518 *vars; } M_00323518;
extern u8 *D_L18_002211F4 __attribute__((section(".data")));
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0013D3E0(void);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L18_00322EB0(M_00323518 *m, vu0_v4 *dir) {
    P_00323518 *p = m->vars;
    vu0_v4 vel;
    vu0_v4 pos;
    f32 size;
    s32 n;
    s32 alpha;
    s32 color;
    u8 *q;

    size = func_0037E250(200.0f, 1000.0f);
    n = func_L01_00440918(1.0f, 3.0f);
    pos = (vu0_v4){0};
    pos.x = func_0037E250(-1.0f, 1.0f);
    pos.y = func_0037E250(-1.0f, 1.0f);
    pos.z = func_0037E250(-1.0f, 1.0f);
    vel = pos;
    func_00388830(&vel, &vel, func_0037E250(0.1f, 0.2f) * 0.016666668f);
    func_00388830(&pos, dir, -func_0037E250(0.0016666668f, 0.016666668f));
    vec_add_ba(&vel, &vel, &pos);
    func_00388830(&pos, dir, func_0037E250(0.0f, 1.0f) * p->f38);
    vec_add_ba(&pos, &pos, &m->pos);
    if (func_0013D3E0() & 1) {
        alpha = 0x40;
        color = 0;
        size += size;
    } else {
        color = 0x406080;
        alpha = 0x7F;
    }
    q = func_L01_00466F98(&pos, &vel, func_0037E208(0x1C, 0x28), alpha, color, n, 273000.0f, size, 1.0f, 0.0f, 0.0f);
    if (q != 0) {
        q[2] = *D_L18_002211F4;
        q[3] = alpha == 0x7F ? 0x48 : 0x44;
    }
}
/* localdecomp:end func_L18_00322EB0 */
