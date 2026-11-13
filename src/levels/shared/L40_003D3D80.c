#include "common.h"

/* localdecomp:start func_L40_003D3D80 */
typedef int Q_003D3D80 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003D3D80;
extern u8 *D_L40_002495D0[16];
extern void func_L01_00446BC8(u8 *, u8 *, s32, u8 *, f32);

void func_L40_003D3D80(u8 *m, s32 cls) {
    s32 i;
    u8 *e;
    V4_003D3D80 v;

    if (m == 0) {
        return;
    }
    for (i = 0; i < 16; i++) {
        e = D_L40_002495D0[i];
        if (e != 0 && *(u8 **)(*(u8 **)(e + 0x68) + 0x70) == m) {
            *(Q_003D3D80 *)&v = 0;
            v.x = 1.0f;
            v.y = 1.0f;
            v.z = 1.0f;
            v.w = 1.0f;
            func_L01_00446BC8(e, m, 0x10000, (u8 *)&v, 5.0f);
            return;
        }
    }
}
/* localdecomp:end func_L40_003D3D80 */
