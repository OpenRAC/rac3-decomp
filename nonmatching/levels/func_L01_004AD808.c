/* NTSC-U draft (Claude wave K): C of func_L01_004A9DE8, the NTSC-U twin of func_L01_004AD808, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 42 words differ on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L01_004A9DE8", whose code is not the PAL one).
 * Worker's note: Needs -mvu0-use-vf0-vf2 (vec_add_ab) and @ps2as (lui/ori float literals) added to the PAL line. Particle ring: 6x { v10 = (rnd(+-1/60), rnd(+-1/60), z0 + rnd(+-1/240), 0.4f); v20 = v10 with w 0.6f; v30 = D_L01_002EDF00[i], func_003888C8(v30, v30, o+0xC0), ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_004AD7A8 (src/levels/shared/L01_004AD7A8.c) */
/* localdecomp:start func_L01_004A9DE8 */
#include "vu0.h"
typedef int u128_004A9DE8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_004A9DE8;
typedef struct { u8 pad0[0x10]; V_004A9DE8 pos; } O_004A9DE8;

extern u128_004A9DE8 D_L01_002EDF00[];
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_003888C8(void *, void *, void *);
extern void func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);

void func_L01_004A9DE8(O_004A9DE8 *o, f32 z0) {
    V_004A9DE8 v10;
    V_004A9DE8 v20;
    V_004A9DE8 v30;
    u32 i;

    for (i = 0; i < 6; i++) {
        v10.x = func_0037E250(-0.016666668f, 0.016666668f);
        v10.y = func_0037E250(-0.016666668f, 0.016666668f);
        v10.z = z0 + func_0037E250(-0.0041666669f, 0.0041666669f);
        v10.w = 0.4f;
        *(u128_004A9DE8 *)&v20 = *(u128_004A9DE8 *)&v10;
        v20.w = 0.6f;
        *(u128_004A9DE8 *)&v30 = D_L01_002EDF00[i];
        func_003888C8(&v30, &v30, (u8 *)o + 0xC0);
        vec_add_ab(&v30, &v30, &o->pos);
        func_L01_0045FEC8(&v30, &v10, &v20, 0x30F0F0F0, 0x14F0F0F0, 4, 4, func_0037E1D8(4) + 4, 0x17);
    }
}
/* localdecomp:end func_L01_004A9DE8 */
