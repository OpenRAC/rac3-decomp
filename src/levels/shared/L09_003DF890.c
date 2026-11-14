#include "common.h"

typedef struct {
    u8 pad00[0x10];
    f32 roll;       /* 0x10: grows by 1 degree a frame */
    u8 pad14[0x10];
    s32 tracer;     /* 0x24: draws the tracer */
    f32 flown;      /* 0x28: u */
} N60Draw_003DFF48;

INCLUDE_ASM("asm/levels", func_L09_003DF890);

INCLUDE_ASM("asm/levels", func_L09_003DF968);

INCLUDE_ASM("asm/levels", func_L09_003DFD68);

/* localdecomp:start func_L09_003DFF48 */
/* rac3 src/levels/shared/L01_0035BF48.c: func_L01_0035C8D0, matched on master */


extern f32 func_0038DAB8(f32 a, f32 b);
extern void func_003D9508(u8 *pos, s32 texture, u32 colour, s32 blend, f32 half, f32 push, f32 roll);
extern f32 func_00382538(void);
extern f32 func_0038CEA8(void *);
extern void func_L09_003DFD68(u8 *bullet);

/* n60_bullet_draw: an N60 Storm bullet in flight, additive: three stars (57) rolling at -1.5,
   0.5 and 2.5 times its roll, two yellow flames (49) at +-0.5 times it, a glow (47) at a new
   roll each frame; with the tracer, it starts once the bullet has flown 2 u. */
void func_L09_003DFF48(u8 *bullet)
{
    N60Draw_003DFF48 *vars = *(N60Draw_003DFF48 **)(bullet + 0x68);
    u8 *pos;

    pos = bullet + 0x10;
    /* 1 degree a frame */
    vars->roll = func_0038DAB8(vars->roll, 0.017453292f);
    /* grey 0x7F at alpha 0x20 */
    func_003D9508(pos, 0x39, 0x207F7F7F, 1, 0.75f, 0.08f, func_0038DAB8(-vars->roll * 1.5f, 0.0f));
    func_003D9508(pos, 0x39, 0x207F7F7F, 1, 0.75f, 0.08f, vars->roll * 0.5f);
    func_003D9508(pos, 0x39, 0x207F7F7F, 1, 0.75f, 0.08f, func_0038DAB8(vars->roll * 2.5f, 0.0f));
    /* yellow (0xFF, 0xFF, 0) at alpha 0x10 */
    func_003D9508(pos, 0x31, 0x1000FFFF, 1, 0.5f, 0.08f, vars->roll * 0.5f);
    func_003D9508(pos, 0x31, 0x1000FFFF, 1, 0.5f, 0.08f, vars->roll * -0.5f);
    /* grey at alpha 0x50 */
    func_003D9508(pos, 0x2F, 0x507F7F7F, 1, 0.2f, 0.08f, func_00382538());
    if (vars->tracer != 0) {
        vars->flown += func_0038CEA8(vars);
        if (vars->flown > 2.0f) {
            func_L09_003DFD68(bullet);
        }
    }
}
/* localdecomp:end func_L09_003DFF48 */

INCLUDE_ASM("asm/levels", func_L09_003E0140);

INCLUDE_ASM("asm/levels", func_L09_003E0360);
