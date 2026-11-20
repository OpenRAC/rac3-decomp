/* functional: high. Plain C float math for the vadd.xyz (w lane untouched) and abs; the file's flags lack -mvu0-use-vf0-vf2 so the vu0.h helpers do not compile. Logic read against the retail asm. */
/* localdecomp:start func_L01_00512D38 */
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_00511A40(void *, s32, f32);

typedef struct {
    u8 pad0[0x80];
    vu0_v4 v80;
    u8 pad90[0x98 - 0x90];
    f32 f98;
} G_00512D38;

void func_L01_00512D38(void) {
    vu0_v4 t;
    G_00512D38 *g = (G_00512D38 *)&D_001A4BE0;

    func_0038CE20(&t, g, -0.75f);
    t.x += g->v80.x;
    t.y += g->v80.y;
    t.z += g->v80.z;
    t.z += 0.5f;
    t.z = func_003C3D30(&t, 0, 0, 0.5f);
    if ((g->v80.z - t.z > 0.3f || g->v80.z - t.z < -0.3f)) {
        return;
    }
    func_L01_00511A40(&g->v80, 1, g->f98);
    g->v80 = t;
}
/* localdecomp:end func_L01_00512D38 */
