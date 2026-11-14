#include "common.h"

/* NTSC-U counterpart of func_L07_003B4DF8 (src/levels/07_annihilation_nation/L07_003AF398.c) */
/* localdecomp:start func_L07_003B3508 */
typedef struct Tab_3B4DF8 {
    u8 pad0[0x1F0];
    u8 *sounds;
} Tab_3B4DF8;
extern Tab_3B4DF8 D_L07_0021EC98;
__asm__(".extern D_L07_0021EC98, 16");
extern void func_003BDA38(void *, s32, void *);
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L07_003B3508(void *arg0) {
    u8 *obj = (u8 *)arg0;
    f32 pos[4];
    f32 vel[4];
    s32 i;
    s32 j;
    s32 life;
    f32 a;
    f32 b;
    f32 c;
    u8 *p;

    for (i = 0; i < 2; i++) {
        func_003BDA38(obj, i + 0xE, pos);
        for (j = 1; j >= 0; j--) {
            func_003886E8(vel, obj + 0xC0, -func_0037E250(0.16666667f, 0.25f));
            func_003BF6A8(vel, 0.06666667f);
            life = func_0037E208(0x28, 0x3C);
            a = func_0037E250(63000.004f, 1.47e+05f);
            b = func_0037E250(3.15e+05f, 5.25e+05f);
            c = func_0037E250(-0.0027777778f, -0.0055555557f);
            p = func_L01_0046C468(pos, vel, life, 0x202020, func_0037E1D8(2) ? 3 : -3, 0x60, 0, 0, a, b, c);
            if (p != 0) {
                p[2] = D_L07_0021EC98.sounds[1];
                p[3] = 0x44;
            }
        }
    }
}
/* localdecomp:end func_L07_003B3508 */
