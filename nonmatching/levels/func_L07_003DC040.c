/* PAL near miss (Claude wave S/pal): flags: byte-exact only with "-mvu0-use-vf0-vf2 added to the file line" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 * Worker's note: byte-exact with -mvu0-use-vf0-vf2 only (vec_add_ab from vu0.h in the 7-step chain loop); L07_003DBE28.c line has no vu0 flag. D_L07_001DE908 read as *(f32 *)&D (file declares it s32); store q once in a local, then s[0] before s[0x80], and +0x114 before ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003DC040 */
typedef int Quad_003DC040 __attribute__((mode(TI)));
typedef struct Out_003DC040 {
    u8 pad00[0x30];
    Quad_003DC040 q30;
} Out_003DC040;

extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 D_L07_001DE908;

void func_L07_003DC040(u8 *self) {
    u8 *s = *(u8 **)(self + 0x68);
    Out_003DC040 out;
    vu0_v4 tmp;
    u8 *v;
    s32 i;
    Quad_003DC040 q;

    func_003C2EC0(*(void **)(self + 0xB8), *(s32 *)(s + 0x118), &out);
    q = out.q30;
    *(Quad_003DC040 *)s = q;
    *(Quad_003DC040 *)(s + 0x80) = q;
    func_0038CF68(&tmp, &out, *(f32 *)&D_L07_001DE908);
    v = s + 0x10;
    for (i = 6; i >= 0; i--) {
        vec_add_ab(v, v - 0x10, &tmp);
        *(Quad_003DC040 *)(v + 0x80) = *(Quad_003DC040 *)v;
        v += 0x10;
    }
    *(void **)(s + 0x114) = &D_L07_001DE908;
    *(void **)(s + 0x110) = &D_L07_001DE908;
}
/* localdecomp:end func_L07_003DC040 */
