/* PAL near miss (Claude wave S/pal): flags: byte-exact only with "-mvu0-use-vf0-vf2 added to the file line" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 * Worker's note: byte-exact with -mvu0-use-vf0-vf2 only (vec_add_ab from vu0.h in a 19-step chain loop; same shape as func_L07_003DC040); L07_003A70B0.c line has no vu0 flag. s[0x2BA] is a u8 arg; q local, s[0] before s[0x140], +0x294 before +0x290. C in near/
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003A7558 */
typedef int Quad_003A7558 __attribute__((mode(TI)));
typedef struct Out_003A7558 {
    u8 pad00[0x30];
    Quad_003A7558 q30;
} Out_003A7558;

extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 D_L07_001DE350;

void func_L07_003A7558(u8 *self) {
    u8 *s = *(u8 **)(self + 0x68);
    Out_003A7558 out;
    vu0_v4 tmp;
    u8 *v;
    s32 i;
    Quad_003A7558 q;

    func_003C2EC0(*(void **)(self + 0xB8), s[0x2BA], &out);
    q = out.q30;
    *(Quad_003A7558 *)s = q;
    *(Quad_003A7558 *)(s + 0x140) = q;
    func_0038CF68(&tmp, &out, *(f32 *)&D_L07_001DE350);
    v = s + 0x10;
    for (i = 18; i >= 0; i--) {
        vec_add_ab(v, v - 0x10, &tmp);
        *(Quad_003A7558 *)(v + 0x140) = *(Quad_003A7558 *)v;
        v += 0x10;
    }
    *(void **)(s + 0x294) = &D_L07_001DE350;
    *(void **)(s + 0x290) = &D_L07_001DE350;
}
/* localdecomp:end func_L07_003A7558 */
