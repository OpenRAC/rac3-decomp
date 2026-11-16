/* PAL near miss (Claude wave S2/pal): flags: byte-exact only with "-mvu0-use-vf0-vf2" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 * Worker's note: MATCH only with -mvu0-use-vf0-vf2 added to the line of src/levels/shared/L01_0050F9E8.c (vec_add_ab, fabs_asm, vu0_v4 struct copy). The file declares D_001A4BE0 as D_001A4BE0_t (line 210): the block reads it through its own G_00512D38 cast and declares no ...
 */
#include "common.h"

typedef struct {
    u8 pad0[0xC20];
    s32 xC20;
    s32 xC24;
    s32 xC28;
} D_001A4BE0_t;
extern D_001A4BE0_t D_001A4BE0;

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
    vec_add_ab(&t, &t, &g->v80);
    t.z += 0.5f;
    t.z = func_003C3D30(&t, 0, 0, 0.5f);
    if (fabs_asm(g->v80.z - t.z) > 0.3f) {
        return;
    }
    func_L01_00511A40(&g->v80, 1, g->f98);
    g->v80 = t;
}
/* localdecomp:end func_L01_00512D38 */
