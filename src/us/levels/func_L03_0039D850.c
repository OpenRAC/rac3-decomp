#include "common.h"

/* NTSC-U counterpart of func_L03_0039F028 (src/levels/03_starship_phoenix/L03_0039E470.c) */
typedef struct { u8 pad0[0x16C]; u8 *p16C; } T_0039F028;
extern s32 func_0037E1D8(s32);
void func_00388830(void *, void *, f32);
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L03_0039D850(void *, void *, void *, f32);

/* localdecomp:start func_L03_0039D850 */
extern T_0039F028 D_L03_0021F318;
__asm__(".extern D_L03_0021F318, 16");
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_003BF6A8(f32 *v, f32 r);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L01_00470258(void *, void *, f32, s32, s32, s16, s32);

void func_L03_0039D850(void *arg, void *src, void *dir, f32 r) {
    vu0_v4 p0;
    vu0_v4 d;
    vu0_v4 pos;
    vu0_v4 t;
    vu0_v4 vel;
    int n;
    vu0_v4 *pp = &p0;
    vu0_v4 *pd = &d;
    p0 = *(vu0_v4 *)src;
    d = *(vu0_v4 *)dir;
    n = (s32)(r * 8.0f);
    {
        int j;
        for (j = 0; j < n; j++) {
            f32 k = func_0037E250(0.0f, r);
            s32 life;
            f32 sz;
            u8 *p;
            func_003886E8(&t, pd, k);
            vec_add_ba(&pos, pp, &t);
            func_003BF6A8(&pos.x, k * 0.19f + 0.01f);
            *(vu0_q *)&vel = 0;
            vel.z = k * 0.1000000089f + 0.1666666716f;
            life = func_0037E208(4, 6);
            sz = k * 294000.0f + 126000.01f;
            p = func_L01_00466F98(&pos, &vel, life, 0x7F, 0xFF4040, func_0037E1D8(2) != 0 ? 3 : -3, sz, -sz / (f32)life, 1.0f, 0.0f, 0.0f);
            if (p != 0) {
                p[2] = D_L03_0021F318.p16C[1];
            }
        }
    }
    if (func_0037E1D8(20) == 0) {
        f32 sz;
        func_00388830(&pos, pd, func_0037E250(0.05000000447f, 0.1333333403f));
        func_003BF6A8(&pos.x, 0.01666666754f);
        sz = func_0037E250(21000.0f, 63000.004f);
        func_L01_00470258(pp, &pos, sz, 0x80A02020, 0x20808080, func_0037E208(40, 60), 0);
    }
}
/* localdecomp:end func_L03_0039D850 */
