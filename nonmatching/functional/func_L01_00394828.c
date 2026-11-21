/* functional: high. 59-word diff is constant-register choice and store order; same instruction multiset. */
#include "common.h"
/* localdecomp:start func_L01_00394828 */
#include "vu0.h"
typedef struct {
    f32 vertices[4][4];
    u32 colors[4];
    f32 uv[8];
    unsigned long state, texture, alpha, test;
} Packet_00394828;
extern V_003919E0 D_L01_001E2A40;
void func_L01_00394828(S_393258 *source, f32 scale, s32 color, s32 alpha, f32 roll, s32 texture, s32 mode, f32 offset)
{
    extern void func_L01_00394738(u8 *);
    extern void func_L01_003947C0(f32 *, f32);
    extern unsigned long func_00389598(s32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038CF38(void *, void *);
    extern void func_0038D328(f32 *, f32 *);
    extern void func_003D2DA0(void *, f32 *, s32);
    Packet_00394828 packet;
    f32 matrix[16] __attribute__((aligned(16)));
    f32 rotation[4] __attribute__((aligned(16)));
    f32 delta[4] __attribute__((aligned(16)));
    f32 *pos = (f32 *)source;
    f32 *camera = D_L01_001E2A40.f;
    u32 rgba;
    func_L01_00394738((u8 *)&packet);
    packet.texture = func_00389598(texture);
    rgba = (u32)color + ((u32)alpha << 24);
    packet.colors[0] = rgba;
    packet.test = ((long)mode << 2) | 0x0000008000000040UL;
    packet.colors[1] = packet.colors[2] = packet.colors[3] = rgba;
    packet.alpha = 0x0000FF9000000260UL;
    packet.state = 0;
    rotation[3] = 0.0f;
    rotation[2] = func_0038D160(camera[0] - pos[0], camera[1] - pos[1]);
    rotation[1] = -func_0038D160(func_0038CF38(pos, camera), camera[2] - pos[2]);
    rotation[0] = roll;
    func_0038D328(matrix, rotation);
    __asm__("lqc2 vf2,%1\n lqc2 vf1,%2\n vsub.xyz vf1,vf1,vf2\n sqc2 vf1,%0"
        : "=m"(*(vu0_v4 *)delta) : "m"(*(vu0_v4 *)source), "m"(D_L01_001E2A40) : "vf1", "vf2");
    func_0038CF68(delta, delta, offset);
    matrix[12] = pos[0] + delta[0];
    matrix[13] = pos[1] + delta[1];
    matrix[14] = pos[2] + delta[2];
    matrix[15] = 1.0f;
    func_L01_003947C0((f32 *)&packet, scale);
    func_003D2DA0(&packet, matrix, 0);
}
/* localdecomp:end func_L01_00394828 */
