/* PAL near miss (Claude wave S/pal): flags: byte-exact only with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 * Worker's note: byte-exact (func_0038CF68(&v0,obj+0xC0,D_001DC610_sda), func_0038CE20(&v10,&v0,-1.0f), vec_add_ba(dst1,&v0,obj+0x10), vec_add_ab(dst2,&v10,obj+0x10)) only with -mvu0-use-vf0-vf2, which the file line lacks; without it vu0.h fails (vf17 spilled)
 */
#include "common.h"

/* localdecomp:start func_L19_0030D928 */
#include "vu0.h"
extern f32 D_001DC610_sda;
__asm__(".extern D_001DC610_sda, 4");
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);

void func_L19_0030D928(u8 *obj, void *dst1, void *dst2) {
    vu0_v4 v0;
    vu0_v4 v10;

    func_0038CF68(&v0, obj + 0xC0, D_001DC610_sda);
    func_0038CE20(&v10, &v0, -1.0f);
    vec_add_ba(dst1, &v0, obj + 0x10);
    vec_add_ab(dst2, &v10, obj + 0x10);
}
/* localdecomp:end func_L19_0030D928 */
