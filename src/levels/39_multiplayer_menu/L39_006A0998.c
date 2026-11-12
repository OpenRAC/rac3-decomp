#include "common.h"

/* localdecomp:start func_L39_006A0998 */
/* best: 3 diff (--as ps2as; default assembler 57). Only diff: retail computes a1 = a0+0x2B4 before the two
 * mov.s f12/f13 = 0.5. Tried struct fields, casts of a0. */
extern void func_L39_00688460(void *a0, void *p1, void *p2, void *p3, void *p4, void *p5, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5);
extern s32 func_L39_0067F1B0(void);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8630(s32, s32);
extern s32 D_001DBC5C_sda;
typedef struct {
    u8 pad0[0x2B0];
    s32 a, b, c, d, e, f, g;
} S_006A0998;
void func_L39_006A0998(S_006A0998 *a0)
{
    func_L39_00688460(a0, &a0->b, &a0->e, &a0->c, &a0->d, &a0->a,
                      0.5f, 0.5f, 1.0f, 1.0f, 0.7f);
    a0->f = func_L39_0067F1B0();
    func_003E9270(a0->f, 0x332299DE, 0.5f, 0.58f, 0.25f, 0.05f, 0.004f, 0.005f);
    func_003E8630(D_001DBC5C_sda, a0->f);
    a0->g = func_L39_0067F1B0();
    func_003E9138(a0->g, 0x332299DE, 0, 0.5f, 0.36f, 0.44f, 0.005f);
    func_003E8630(D_001DBC5C_sda, a0->g);
}
/* localdecomp:end func_L39_006A0998 */
