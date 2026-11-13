#include "common.h"

/* localdecomp:start func_L19_00307350 */
__asm__(".extern D_L19_001DC534, 4");
__asm__(".extern D_L19_001DC538, 4");
extern f32 D_L19_001DC534;
extern f32 D_L19_001DC538;
typedef struct { f32 x0; f32 x4; } S_307350;
__asm__(".extern D_L19_001E0E00, 16");
extern S_307350 D_L19_001E0E00;
extern f32 D_L19_001E0E10;
extern s32 D_L19_001E0E14;
extern f32 func_003824E0(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038CEA8(void *);

void func_L19_00307350(s32 mode) {
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
    if (D_L19_001DC534 >= 0.0f)
        f22 = D_L19_001DC534;
    if (D_L19_001DC538 >= 0.0f)
        f23 = D_L19_001DC538;
    f20 = f2 * 0.020000001f;
    f21 = -f20;
    D_L19_001E0E00.x0 = func_003824E0(f21, f20);
    D_L19_001E0E00.x4 = func_003824E0(f21, f20);
    D_L19_001E0E10 = func_003824E0((f24 * 5.0f + 2.0f) / 6.0f, (f25 * 5.0f + 2.0f) / 6.0f);
    v[0] = f20;
    v[1] = f20;
    r = func_0038CED8(&D_L19_001E0E00);
    r = r / func_0038CEA8(v);
    D_L19_001E0E14 = (s32)(r * (f23 - f22) + f22);
}
/* localdecomp:end func_L19_00307350 */

typedef struct { f32 x, y, z, w; } V_3074D8 __attribute__((aligned(16)));

/* localdecomp:start func_L19_003074D8 */
extern f32 D_L19_001E8E68[];
extern s32 func_003D3CB0(V_3074D8 *, V_3074D8 *, s32, s32, s32);

f32 func_L19_003074D8(V_3074D8 *p) {
    V_3074D8 a;
    V_3074D8 b;

    a = *p;
    b = *p;
    a.z = 400.0f;
    b.z = 90.0f;
    if (func_003D3CB0(&a, &b, 18, 0, 0) != 0)
        return D_L19_001E8E68[0];
    return 90.0f;
}
/* localdecomp:end func_L19_003074D8 */

INCLUDE_ASM("asm/levels", func_L19_00307548);
