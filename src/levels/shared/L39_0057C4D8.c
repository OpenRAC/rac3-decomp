#include "common.h"

/* localdecomp:start func_L39_0057C4D8 */
typedef struct { u8 p0[0x20]; u8 b20; } H_57B530;
typedef struct { u8 p0[0x10]; f32 f10; u8 p14[0xC]; H_57B530 *f20; u8 b24; u8 b25; u8 p26[0xA]; f32 f30, f34; u8 p38[8]; } E_57B530;
typedef struct { E_57B530 e[14]; s32 n; } T_57B530;
extern T_57B530 D_L39_00257900;
extern s32 D_L39_00242914;
extern s32 D_L39_00240300, D_L39_00240304, D_L39_00240310, D_L39_00240314;
extern void func_003860A8(f32 *, void *);
extern void func_00385398(void *, f32, f32);
void func_L39_0057C4D8(s32 a) {
    f32 v[2];
    s32 i;
    E_57B530 *p;
    if (D_L39_00257900.n == 0) return;
    for (i = 0; i < D_L39_00257900.n; i++) {
        p = &D_L39_00257900.e[i];
        if (p->b25 != a || p->f20 == 0 || p->f20->b20 == 0xFE || p->f20->b20 == 0xFD) continue;
        if (p->b24 != 0) {
            func_003860A8(v, p);
            v[0] = (v[0] - (f32)D_L39_00240310) * 0.0625f;
            v[1] = (v[1] - (f32)D_L39_00240314) * 0.0625f;
        } else {
            v[0] = (f32)D_L39_00240300 * p->f30;
            v[1] = (f32)D_L39_00240304 * p->f34;
        }
        if (D_L39_00242914 != 0) p->f10 *= 0.75f;
        func_00385398(p, v[0], v[1]);
    }
    if (D_L39_00242914 == 0) D_L39_00257900.n = 0;
}
/* localdecomp:end func_L39_0057C4D8 */
