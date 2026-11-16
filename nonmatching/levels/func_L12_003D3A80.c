/* PAL near miss (Claude wave S/pal): flags: byte-exact only with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 * Worker's note: byte-exact (vec_neg(&t.b,&t.b) between func_003C2EC0 and func_0038CE20) only with -mvu0-use-vf0-vf2, which the file line lacks; without it vu0.h vec_neg fails (vf17 spilled)
 */
#include "common.h"

/* localdecomp:start func_L12_003D3A80 */
#include "vu0.h"
typedef struct { vu0_v4 a; vu0_v4 b; vu0_v4 c; } T_3D3A80;
extern f32 D_001DEF18_sda;
__asm__(".extern D_001DEF18_sda, 4");
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L12_003D50C8(void *, s32, void *, void *, f32);

void func_L12_003D3A80(u8 *obj, u8 *other) {
    vu0_v4 v0;
    T_3D3A80 t;
    vu0_v4 w;

    func_003C2EC0(obj, 1, &t);
    vec_neg(&t.b, &t.b);
    func_0038CE20(&v0, &t.b, D_001DEF18_sda);
    func_L12_003D50C8(obj, *(s32 *)(other + 0x140), &w, &v0, (f32)other[0x44]);
}
/* localdecomp:end func_L12_003D3A80 */
