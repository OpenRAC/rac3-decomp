/* PAL near miss (Claude wave S2/pal): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: byte-exact only with -mvu0-use-vf0-vf2 (vec_add_ab(out,d+0x10,&v), file line lacks it). Also a prototype note: the file's LATER block (func_L01_0039E0C8, line 205) declares func_0038D890/func_0038CF68 with Vec4_0039E0C8 * and D_L01_001E2080_0039E0C8; my block ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0039E018 */
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern u8 D_L01_001E2080[8];

void func_L01_0039E018(u8 *obj, f32 *out, s32 idx) {
    vu0_v4 v;
    u8 *d = *(u8 **)(obj + 0x68);
    u8 *p;

    func_0038D890(&v, D_L01_001E2080 + idx * 16, d + 0x20, *(f32 *)(d + 0x2C));
    p = *(u8 **)(d + (idx << 2) + 0x30);
    if (p != 0 && obj[0x20] == 2) {
        func_0038CF68(&v, &v, *(f32 *)(p + 0x28));
    }
    vec_add_ab(out, d + 0x10, &v);
    out[2] += *(f32 *)d;
}
/* localdecomp:end func_L01_0039E018 */
