#include "common.h"

/* NTSC-U counterpart of func_L01_003C35A0 (src/levels/shared/L01_003BE598.c): 1/60.0f for 0.02f, its $gp tables moved */
/* localdecomp:start func_L01_003C1D38 */
typedef int s128_003C1D38 __attribute__((mode(TI)));
typedef struct { u8 pad[0x20]; u8 b20; } M_003C1D38;
extern s32 D_L01_001D6694;
extern s32 D_L01_001DEC08;
__asm__(".extern D_L01_001DEC08, 8");
extern s32 D_L01_001DEC18;
__asm__(".extern D_L01_001DEC18, 8");
extern s32 D_L01_001DEC28;
__asm__(".extern D_L01_001DEC28, 8");
extern void func_003BDA38(M_003C1D38 *, s32, s128_003C1D38 *);
extern void func_003BF6A8(s128_003C1D38 *, f32);
extern f32 func_0037E250(f32 a, f32 b);
extern void func_L01_0046A9C8(M_003C1D38 *, s128_003C1D38 *, s128_003C1D38 *, s32 *, s32);

/* agent_jets_emit: an agent's jets (V4 and up) while it hovers and lands: three type 0x4A
   particles a frame at its point 0 */
void func_L01_003C1D38(M_003C1D38 *agent)
{
    s128_003C1D38 q[5];

    if (D_L01_001D6694 == 2)
        return;
    q[0] = 0;
    func_003BDA38(agent, 0, &q[1]);
    ((f32 *)&q[1])[3] = 0.0f;
    q[2] = q[1];
    q[3] = q[1];
    q[4] = q[1];
    func_003BF6A8(&q[1], 0.025f);
    func_003BF6A8(&q[2], 0.025f);
    func_003BF6A8(&q[3], 0.025f);
    func_003BF6A8(&q[4], 0.025f);
    ((f32 *)&q[0])[2] = -(func_0037E250(30.0f, 40.0f) * 0.016666668f) * 0.1f;
    func_L01_0046A9C8(agent, &q[2], &q[0], &D_L01_001DEC08, 1);
    ((f32 *)&q[0])[2] = -(func_0037E250(30.0f, 40.0f) * 0.016666668f) * 0.1f;
    func_L01_0046A9C8(agent, &q[3], &q[0], &D_L01_001DEC18, 1);
    ((f32 *)&q[0])[2] = -(func_0037E250(30.0f, 40.0f) * 0.016666668f) * 0.1f;
    func_L01_0046A9C8(agent, &q[4], &q[0], &D_L01_001DEC28, 1);
}
/* localdecomp:end func_L01_003C1D38 */
