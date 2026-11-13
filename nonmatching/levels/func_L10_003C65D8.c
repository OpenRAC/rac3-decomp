/* near miss (level 10, Zeldrin Starport): 3 differences, the same scheduling tie as func_L10_003C8428: among the stack arguments of func_L01_003303B8 retail loads 0x1000000 (lui $v1) before the first colour store and the constant 1 after it, this C loads the 1 first; every other instruction is retail's. Needs -mvu0-use-vf0-vf2 ... @ps2as and include/vu0.h on src/levels/10_zeldrin_starport/L10_003C64B0.c (func_L10_003C64B0 before it, with V4_3C64B0, is in that file); checked with --flags. A local for the 1 gives 107 differences */
#include "common.h"

/* localdecomp:start func_L10_003C65D8 */
#include "vu0.h"
typedef int u128_t_3C65D8 __attribute__((mode(TI)));
__asm__(".extern D_L10_001DE8A4, 4");
extern f32 D_L10_001DE8A4;
extern u8 D_L10_001D66B0[8];
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L10_003C65D8(u8 *m) {
    V4_3C64B0 p;
    V4_3C64B0 a;

    if (func_L01_00447490(m, -1, 0) != 0) {
        func_003A52A0(0, 0, m);
        func_L01_00451FE0(m, 0xF, D_L10_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f,
                          3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L10_003C64B0(m, 0x1EB2, 0);
        *(u128_t_3C65D8 *)&a = 0;
        a.z = D_L10_001DE8A4 * 29.976019f * *(f32 *)(m + 0x2C);
        p = a;
        func_0038D000(&p, &p, m + 0xC0);
        vec_add_ab(&p, &p, m + 0x10);
        func_L01_003303B8(&p, 0, 0, 0, 0, 2, 5, 0, *(f32 *)(m + 0x2C) * 10.491607f, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x27B2F3, 0xBDFFF, 0, 0, 0, 0, 0x7F27B2F3, 0x280BDFFF, 0, 0);
        func_L01_00451E78(m, 1, 0.0f);
        func_003C2880(m);
    }
}
/* localdecomp:end func_L10_003C65D8 */
