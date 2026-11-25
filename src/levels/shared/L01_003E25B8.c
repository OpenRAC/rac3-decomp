#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_003E25B8 */
typedef struct { f32 x, y, z, radius; f32 x2, y2, z2, kind; } Bound_003E2418;
extern vu0_v4 D_L01_001E2A40;
extern u8 D_L01_00221098[];
extern f32 D_L01_001DF5D0, D_L01_001DF5D4;
__asm__(".extern D_L01_001DF5D0, 4");
__asm__(".extern D_L01_001DF5D4, 4");
s32 func_L01_003E25B8(u8 *self, u8 *vars, vu0_q *velocity, s32 color1, s32 color2)
{
    extern s32 func_003C2B88(u8 *, s32);
    extern u8 func_0013D3E0(void);
    extern void func_00382580(void *, f32, f32);
    extern void func_0038CF68(vu0_q *, vu0_q *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
    extern f32 func_L01_0040E570(void *, void *);
    extern void func_0038CDF8(void *, void *, void *, f32);
    vu0_v4 first, second, position, offset, delta, center;
    Bound_003E2418 *bound;
    u8 *pg;
    f32 max_radius, max_height, radius, pull, size, d, r;
    s32 count, left, special, spin, life;
    u8 *particle;
    count = func_003C2B88(self, 0);
    if (count) {
    /* The collision query writes its bound records into the EE scratchpad. */
    bound = (Bound_003E2418 *)0x70000000;
    center = *(vu0_v4 *)(self + 0x10);
    max_radius = 0.010000000707805f;
    max_height = 0.1f;
    if (count > 0) {
    pg = D_L01_00221098;
    left = count;
    do {
        if (color1 && (!color2 || (func_0013D3E0() & 1))) {
            special = 1;
            radius = bound->radius * 1.25f;
            pull = D_L01_001DF5D0;
        } else {
            special = 0;
            radius = bound->radius;
            pull = D_L01_001DF5D4;
        }
        if (bound->kind == 0.0f) {
            position = *(vu0_v4 *)bound;
            position.w = 1.0f;
            func_00382580(&offset, 0.0f, radius);
            vec_add_ab(&position, &position, &offset);
            vec_sub_ab(&delta, &D_L01_001E2A40, &position);
            func_0038CF68((vu0_q *)&delta, (vu0_q *)&delta, pull);
            vec_add_ab(&position, &position, &delta);
            spin = (s32)func_L01_00443A18(2.0f, 5.0f);
            size = func_003824E0(0.7f, 1.0f) * bound->radius;
            if (special) {
                particle = func_L01_004713C8(&position, velocity, (func_00382498(10, 15) * 5 + 2) / 6, color1, spin, 0x30, 0x30, 0,
                    size * 6.0f * 210000.0f, 2100.0f, -0.0012000000569969416f);
                if (particle) {
                    particle[3] = 0x41;
                    particle[2] = **(u8 **)(pg + 0xD4);
                }
            } else {
                spin *= -2;
                particle = func_L01_004713C8(&position, velocity, (func_00382498(10, 15) * 5 + 2) / 6, color2, spin, 0x30, 0x30, 0,
                    size * 5.0f * 210000.0f, 4200.0f, 0.0012000000569969416f);
                if (particle) particle[2] = **(u8 **)(pg + 0xD4);
            }
            d = func_L01_0040E570(bound, &center);
            r = bound->radius;
            d += r * r;
            if (max_radius < d) max_radius = d;
            d = fabs_asm(bound->z - center.z) + r;
            if (max_height < d) max_height = d;
        } else {
            first = *(vu0_v4 *)bound;
            second = *(vu0_v4 *)((u8 *)bound + 0x10);
            first.w = 1.0f;
            second.w = 1.0f;
            func_0038CDF8(&position, &first, &second, func_003824E0(0.0f, 1.0f));
            func_00382580(&delta, 0.0f, radius);
            vec_add_ab(&position, &position, &delta);
            vec_sub_ab(&delta, &D_L01_001E2A40, &position);
            func_0038CF68((vu0_q *)&delta, (vu0_q *)&delta, pull);
            vec_add_ab(&position, &position, &delta);
            spin = (s32)func_L01_00443A18(2.0f, 5.0f);
            size = func_003824E0(0.7f, 1.0f) * bound->radius;
            if (special) {
                particle = func_L01_004713C8(&position, velocity, (func_00382498(10, 15) * 5 + 2) / 6, color1, spin, 0x30, 0x30, 0,
                    size * 6.0f * 210000.0f, 2100.0f, -0.0012000000569969416f);
                if (particle) {
                    particle[3] = 0x41;
                    particle[2] = **(u8 **)(pg + 0xD4);
                }
            } else {
                spin *= -2;
                particle = func_L01_004713C8(&position, velocity, (func_00382498(10, 15) * 5 + 2) / 6, color2, spin, 0x30, 0x30, 0,
                    size * 5.0f * 210000.0f, 4200.0f, 0.0012000000569969416f);
                if (particle) particle[2] = **(u8 **)(pg + 0xD4);
            }
            d = func_L01_0040E570(bound, &center);
            r = bound->radius;
            d += r * r;
            if (max_radius < d) max_radius = d;
            d = fabs_asm(bound->z - center.z) + r;
            if (max_height < d) max_height = d;
            d = func_L01_0040E570((u8 *)bound + 0x10, &center);
            r = bound->radius;
            d += r * r;
            if (max_radius < d) max_radius = d;
            d = fabs_asm(bound->z2 - center.z) + r;
            if (max_height < d) max_height = d;
        }
        ++bound;
    } while (--left);
    }
    *(f32 *)(vars + 0x10) = max_height;
    *(f32 *)(vars + 0x14) = sqrt_asm(max_radius);
    return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_003E25B8 */
