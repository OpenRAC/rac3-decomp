#include "common.h"

/* NTSC-U counterpart of func_L19_00307350 (src/levels/19_thran_asteroid_belt/L19_00307350.c) */
/* localdecomp:start func_L19_003070B8 */
__asm__(".extern D_L19_001DC574, 4");
__asm__(".extern D_L19_001DC578, 4");
extern f32 D_L19_001DC574;
extern f32 D_L19_001DC578;
typedef struct { f32 x0; f32 x4; } S_307350;
__asm__(".extern D_L19_001E0E00_003070B8, 16");
extern S_307350 D_L19_001E0E00_003070B8;
extern f32 D_L19_001E0E10_003070B8;
extern s32 D_L19_001E0E14_003070B8;
extern f32 func_0037E250(f32, f32);
extern f32 func_003887A0(void *);
extern f32 func_00388770(void *);

void func_L19_003070B8(s32 mode) {
    f32 v[2];
    f32 f2;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;
    f32 f24;
    f32 f25;
    f32 r;

    if (mode == 0) {
        f2 = 5.0f;
        f25 = 10.0f;
        f24 = 2.0f;
        f23 = 8.0f;
        f22 = 4.0f;
    } else {
        f2 = 2.5f;
        f25 = 10.0f;
        f24 = 20.0f;
        f23 = 3.0f;
        f22 = 2.0f;
    }
    if (D_L19_001DC574 >= 0.0f)
        f22 = D_L19_001DC574;
    if (D_L19_001DC578 >= 0.0f)
        f23 = D_L19_001DC578;
    f20 = f2 * 0.0166666675f;
    f21 = -f20;
    D_L19_001E0E00_003070B8.x0 = func_0037E250(f21, f20);
    D_L19_001E0E00_003070B8.x4 = func_0037E250(f21, f20);
    D_L19_001E0E10_003070B8 = func_0037E250(f24, f25);
    v[0] = f20;
    v[1] = f20;
    r = func_003887A0(&D_L19_001E0E00_003070B8);
    r = r / func_00388770(v);
    D_L19_001E0E14_003070B8 = (s32)(r * (f23 - f22) + f22);
}
/* localdecomp:end func_L19_003070B8 */
