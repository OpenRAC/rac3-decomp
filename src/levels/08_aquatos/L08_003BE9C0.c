#include "common.h"

/* localdecomp:start func_L08_003BE9C0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003BE9C0;
__asm__(".extern D_L08_001DE818, 4");
__asm__(".extern D_L08_001DE81C, 4");
__asm__(".extern D_L08_001DE820, 4");
__asm__(".extern D_L08_001DE824, 4");
extern s32 D_L08_001DE818;
extern s32 D_L08_001DE81C;
extern f32 D_L08_001DE820;
extern f32 D_L08_001DE824;
extern void func_00382580(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *out, void *v, f32 r);
extern s32 func_00382498(s32, s32);
extern void *func_L01_00470668(void *, void *, s32, f32);

void func_L08_003BE9C0(V4_003BE9C0 *at, V4_003BE9C0 *offset, f32 scale) {
    V4_003BE9C0 pos;
    V4_003BE9C0 v;
    f32 r;
    s32 i;
    s32 n;

    pos = *at;
    for (i = 0; i < D_L08_001DE818; i++) {
        r = D_L08_001DE820 * scale;
        func_00382580(&v, r * 0.5f, r);
        vec_add_ab(&v, &v, offset);
        func_0038CF68(&v, &v, func_003824E0(D_L08_001DE824 * 0.5f, D_L08_001DE824) * 0.020000001f);
        n = (func_00382498((f32)D_L08_001DE81C * 0.5f, D_L08_001DE81C) * 5 + 2) / 6;
        func_L01_00470668(&pos, &v, n, func_003824E0(10.0f, 15.0f) * 0.00040000002f);
    }
}
/* localdecomp:end func_L08_003BE9C0 */

INCLUDE_ASM("asm/levels", func_L08_003BEB20);
