#include "common.h"

/* localdecomp:start func_L39_0053EB68 */
#include "vu0.h"

extern u32 D_L39_0024AE38_0053EB68;
extern u32 D_L39_0024AE3C_0053EB68;
extern u32 D_L39_0024AE34_0053EB68;
extern u32 D_L39_0024AE48_0053EB68;
extern u32 D_L39_0024AE4C_0053EB68;
extern u32 D_L39_0024AE50_0053EB68;
extern u32 D_L39_0024AE54_0053EB68;
extern u32 D_L39_0024AE58_0053EB68;
extern u32 D_L39_0024AE5C_0053EB68;
extern u32 D_L39_0024AE60_0053EB68;
extern u32 D_L39_0024AE64_0053EB68;
extern u32 D_L39_0024AE68_0053EB68;
extern u32 D_L39_0024AE6C_0053EB68;
extern u32 D_L39_0024AE70_0053EB68;
extern u32 D_L39_0024AE74_0053EB68;
extern u32 D_L39_0024AE78_0053EB68;
extern u32 D_L39_0024AE7C_0053EB68;
extern u32 D_L39_0024AE80_0053EB68;
extern u32 D_L39_0024AE84_0053EB68;
extern u32 D_L39_0024AE88_0053EB68;
extern f32 D_L39_0024AE24_0053EB68;
extern f32 D_L39_0024AE28_0053EB68;
extern f32 D_L39_0024AE2C_0053EB68;
extern f32 D_L39_0024AE30_0053EB68;
__asm__(".extern D_L39_0024AE38_0053EB68, 4");
__asm__(".extern D_L39_0024AE3C_0053EB68, 4");
__asm__(".extern D_L39_0024AE34_0053EB68, 4");
__asm__(".extern D_L39_0024AE48_0053EB68, 4");
__asm__(".extern D_L39_0024AE4C_0053EB68, 4");
__asm__(".extern D_L39_0024AE50_0053EB68, 4");
__asm__(".extern D_L39_0024AE54_0053EB68, 4");
__asm__(".extern D_L39_0024AE58_0053EB68, 4");
__asm__(".extern D_L39_0024AE5C_0053EB68, 4");
__asm__(".extern D_L39_0024AE60_0053EB68, 4");
__asm__(".extern D_L39_0024AE64_0053EB68, 4");
__asm__(".extern D_L39_0024AE68_0053EB68, 4");
__asm__(".extern D_L39_0024AE6C_0053EB68, 4");
__asm__(".extern D_L39_0024AE70_0053EB68, 4");
__asm__(".extern D_L39_0024AE74_0053EB68, 4");
__asm__(".extern D_L39_0024AE78_0053EB68, 4");
__asm__(".extern D_L39_0024AE7C_0053EB68, 4");
__asm__(".extern D_L39_0024AE80_0053EB68, 4");
__asm__(".extern D_L39_0024AE84_0053EB68, 4");
__asm__(".extern D_L39_0024AE88_0053EB68, 4");
__asm__(".extern D_L39_0024AE24_0053EB68, 4");
__asm__(".extern D_L39_0024AE28_0053EB68, 4");
__asm__(".extern D_L39_0024AE2C_0053EB68, 4");
__asm__(".extern D_L39_0024AE30_0053EB68, 4");
extern vu0_v4 D_L39_0024DE00;
extern void func_L01_0030AB70(void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);
extern f32 func_L39_005B44C8(void);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

typedef struct {
    vu0_v4 v[4];
    u32 color[4];
    f32 uv[8];
    u8 pad[32];
} __attribute__((aligned(16))) S_0053EB68;

/* from rac2-decomp's func_L16_003E7248 */
void func_L39_0053EB68(u8 *unused, int ua, f32 uf, int ub, int uc, f32 ug, f32 uh, int ud,
                       u8 *object) {
    S_0053EB68 packet;
    vu0_v4 nearPoint, viewDelta, beamStep, farPoint, side;
    f32 *state = *(f32 **)(object + 0x68);
    u8 *position;
    f32 *uv;
    s32 i;

    func_L01_0030AB70(&packet);
    func_003D93B0(&packet, D_L39_0024AE38_0053EB68, 0, 0x80);
    packet.color[0] = packet.color[1] =
        (D_L39_0024AE58_0053EB68 << 24) | (D_L39_0024AE54_0053EB68 << 16) | (D_L39_0024AE50_0053EB68 << 8) | D_L39_0024AE4C_0053EB68;
    packet.color[2] = packet.color[3] =
        (D_L39_0024AE68_0053EB68 << 24) | (D_L39_0024AE64_0053EB68 << 16) | (D_L39_0024AE60_0053EB68 << 8) | D_L39_0024AE5C_0053EB68;
    packet.uv[0] = 0;
    packet.uv[1] = 0;
    packet.uv[2] = 0;
    packet.uv[3] = 1.0f;
    packet.uv[4] = 1.0f;
    packet.uv[5] = 0;
    packet.uv[6] = 1.0f;
    packet.uv[7] = 1.0f;
    for (uv = packet.uv, i = 3; i >= 0; i--, uv += 2) {
        *uv -= state[10];
        if (*uv <= 7.0f) {
            *uv += 7.0f;
        }
    }
    state[10] += 0.1f;
    if (state[10] >= 4.0f) {
        state[10] -= 4.0f;
    }

    func_0038CF68(&nearPoint, state, -0.17f);
    position = object + 0x10;
    vec_add_ba(&nearPoint, position, &nearPoint);
    vec_sub_ba(&viewDelta, position, &D_L39_0024DE00);
    func_0038CF68(&beamStep, state, -4.0f);
    vec_add_ba(&farPoint, &nearPoint, &beamStep);
    func_0038CE90(&side, &viewDelta, &beamStep);
    func_0038CF68(&side, &side, D_L39_0024AE2C_0053EB68);
    vec_add_ba(&packet.v[0], position, &side);
    vec_sub_ab(&packet.v[1], position, &side);
    vec_add_ba(&packet.v[2], &farPoint, &side);
    vec_sub_ab(&packet.v[3], &farPoint, &side);
    func_003D2DA0(&packet, 0, 0);
    packet.color[0] = packet.color[2];
    packet.color[1] = packet.color[3];
    packet.color[2] = packet.color[3] = 0x801010;
    *(vu0_q *)&packet.v[0] = *(vu0_q *)&packet.v[2];
    *(vu0_q *)&packet.v[1] = *(vu0_q *)&packet.v[3];
    vec_add_ba(&packet.v[2], &packet.v[2], &beamStep);
    vec_add_ab(&packet.v[3], &packet.v[3], &beamStep);
    func_003D2DA0(&packet, 0, 0);

    func_003D93B0(&packet, D_L39_0024AE3C_0053EB68, 1, 0x80);
    packet.color[0] = packet.color[1] =
        (D_L39_0024AE78_0053EB68 << 24) | (D_L39_0024AE74_0053EB68 << 16) | (D_L39_0024AE70_0053EB68 << 8) | D_L39_0024AE6C_0053EB68;
    packet.uv[0] = 0;
    packet.uv[1] = 0;
    packet.uv[2] = 0;
    packet.uv[3] = 1.0f;
    packet.uv[4] = 1.0f;
    packet.uv[5] = 0;
    packet.uv[6] = 1.0f;
    packet.uv[7] = 1.0f;
    packet.color[2] = packet.color[3] =
        (D_L39_0024AE74_0053EB68 << 16) | (D_L39_0024AE70_0053EB68 << 8) | D_L39_0024AE6C_0053EB68;
    func_0038CF68(&side, &side, D_L39_0024AE24_0053EB68);
    vec_add_ba(&packet.v[0], position, &side);
    vec_sub_ab(&packet.v[1], position, &side);
    vec_add_ab(&farPoint, position, &beamStep);
    vec_add_ba(&farPoint, &farPoint, &beamStep);
    vec_add_ab(&packet.v[2], &farPoint, &side);
    vec_sub_ba(&packet.v[3], &farPoint, &side);
    func_003D2DA0(&packet, 0, 0);

    packet.color[0] = packet.color[1] =
        (D_L39_0024AE78_0053EB68 << 24) | (D_L39_0024AE74_0053EB68 << 16) | (D_L39_0024AE70_0053EB68 << 8) | D_L39_0024AE6C_0053EB68;
    packet.color[2] = packet.color[3] =
        (D_L39_0024AE74_0053EB68 << 16) | (D_L39_0024AE70_0053EB68 << 8) | D_L39_0024AE6C_0053EB68;
    func_0038CF68(&side, &side, D_L39_0024AE28_0053EB68);
    func_0038CF68(&nearPoint, state, -0.1f);
    vec_add_ba(&nearPoint, position, &nearPoint);
    vec_add_ab(&packet.v[0], &nearPoint, &side);
    vec_sub_ab(&packet.v[1], &nearPoint, &side);
    vec_add_ab(&farPoint, &nearPoint, &beamStep);
    vec_add_ba(&farPoint, &farPoint, &beamStep);
    vec_add_ab(&packet.v[2], &farPoint, &side);
    vec_sub_ba(&packet.v[3], &farPoint, &side);
    func_003D2DA0(&packet, 0, 0);

    packet.color[0] = packet.color[1] =
        (D_L39_0024AE88_0053EB68 << 24) | (D_L39_0024AE84_0053EB68 << 16) | (D_L39_0024AE80_0053EB68 << 8) | D_L39_0024AE6C_0053EB68;
    packet.color[2] = packet.color[3] =
        (D_L39_0024AE84_0053EB68 << 16) | (D_L39_0024AE80_0053EB68 << 8) | D_L39_0024AE7C_0053EB68;
    func_0038CF68(&side, &side, D_L39_0024AE28_0053EB68);
    func_0038CF68(&nearPoint, state, -0.1f);
    vec_add_ba(&nearPoint, position, &nearPoint);
    vec_add_ab(&packet.v[0], &nearPoint, &side);
    vec_sub_ab(&packet.v[1], &nearPoint, &side);
    vec_add_ab(&farPoint, &nearPoint, &beamStep);
    vec_add_ba(&farPoint, &farPoint, &beamStep);
    vec_add_ab(&packet.v[2], &farPoint, &side);
    vec_sub_ba(&packet.v[3], &farPoint, &side);
    func_003D2DA0(&packet, 0, 0);

    packet.color[0] = packet.color[1] = 0x40FFFFFF;
    packet.color[2] = packet.color[3] =
        (D_L39_0024AE74_0053EB68 << 16) | (D_L39_0024AE70_0053EB68 << 8) | D_L39_0024AE6C_0053EB68;
    func_0038CF68(&side, &side, D_L39_0024AE24_0053EB68);
    vec_add_ba(&packet.v[0], position, &side);
    vec_sub_ab(&packet.v[1], position, &side);
    func_0038CF68(&beamStep, state, -0.6f);
    vec_add_ba(&farPoint, position, &beamStep);
    vec_add_ab(&farPoint, &farPoint, &beamStep);
    vec_add_ab(&packet.v[2], &farPoint, &side);
    vec_sub_ab(&packet.v[3], &farPoint, &side);
    func_003D2DA0(&packet, 0, 0);
    func_003D9508(position, D_L39_0024AE34_0053EB68, D_L39_0024AE48_0053EB68, 1, D_L39_0024AE30_0053EB68, 0.08f,
                  func_L39_005B44C8());
}
/* localdecomp:end func_L39_0053EB68 */
