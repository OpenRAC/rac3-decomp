/* functional: high. Written from the disassembly (no draft). Plain float C replaces retail's VU0 vadd.xyz; call order (and so the random-number sequence) kept exactly: rand_direction, rand(a7), rand_int, rand_range, spawn, then the colour/frame randoms. Params after the floats: (zlimit, scale, origin, motion, a2, a3, a4, count, size, a7, spread). */
#include "common.h"
/* localdecomp:start func_L01_003D8E60 */
typedef struct { f32 x, y, z, w; } V4_003D8E60 __attribute__((aligned(16)));
extern u8 *D_L01_00221098[];
extern f32 D_001DF4E0_sda;
extern f32 D_001DF4E4_sda;
extern u8 D_001DF4EC_sda;
extern s32 D_001DF4F0_sda;
__asm__(".extern D_001DF4E0_sda, 4");
__asm__(".extern D_001DF4E4_sda, 4");
__asm__(".extern D_001DF4EC_sda, 1");
__asm__(".extern D_001DF4F0_sda, 4");
void func_L01_003D8E60(f32 zlimit, f32 scale, f32 *origin, f32 *motion, s32 a2, s32 a3, s32 a4, s32 count, s32 size, s32 a7, f32 spread) {
    extern s32 func_L01_00459590(void *, s32, f32);
    extern void func_00382580(void *, f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);
    extern void func_L01_003D8DA0(void *);
    extern void func_L01_003D8C80(void *);
    V4_003D8E60 sphere, pos, vel;
    f32 range;
    s32 i, life, owner, rnd;
    u8 *particle;
    sphere.x = origin[0];
    sphere.y = origin[1];
    sphere.z = origin[2];
    sphere.w = scale + scale;
    range = 128.0f;
    if (size > 0x40) range = (f32)size;
    if (func_L01_00459590(&sphere, 0, range) < 0) return;
    owner = ((size >> 5) << 4) + 2;
    for (i = count; i > 0; i--) {
        func_00382580(&pos, scale * 0.15000000596046448f, scale * 0.4000000059604645f);
        pos.x = pos.x + origin[0];
        pos.y = pos.y + origin[1];
        pos.z = pos.z + origin[2];
        vel.x = 0.0f + motion[0];
        vel.y = 0.0f + motion[1];
        vel.z = 0.0f + motion[2];
        vel.w = 0.0f;
        if (a7 == 0 || func_00382468(a7) != 0) {
            f32 vx, vy;
            life = (a2 * 5 + 2) / 6;
            rnd = func_00382498(-5, 5);
            vx = D_001DF4E0_sda * scale;
            vy = D_001DF4E4_sda * scale;
            vx = vx * 210000.0f;
            vy = vy * 210000.0f;
            particle = func_L01_0046FB40(&pos, &vel, life, 0x808080, rnd, D_001DF4EC_sda, 0, 0, vx, vy,
                                         func_003824E0(spread * 0.0004000000189989805f, -0.000800000037997961f));
            if (particle) {
                particle[9] = owner;
                if (a7 == 0 && func_00382468(D_001DF4F0_sda) != 0) {
                    particle[2] = D_L01_00221098[0x5B][0];
                    particle[3] = 0x48;
                } else {
                    particle[2] = D_L01_00221098[0x5B][4];
                    particle[3] = func_00382468(4) ? 0x44 : 0x48;
                }
            }
        } else {
            f32 vx;
            life = (a2 * 5 + 2) / 6;
            scale = scale * 0.800000011920929f;
            rnd = func_00382498(-1, 2);
            vx = D_001DF4E4_sda * scale;
            vx = vx * 210000.0f;
            particle = func_L01_00475C60(&pos, &vel, life, rnd, 0x7F407FFF, 0x407FFF, 0, vx, vx,
                                         func_003824E0(spread * 1.5f, spread));
            if (particle) {
                particle[9] = owner;
                particle[2] = D_L01_00221098[0x61][3];
            }
        }
    }
    if (zlimit == -100000.0f || zlimit + 2.0f < origin[2]) {
        if (a3 != 0) {
            if (func_00382468(10 - a3) == 0) func_L01_003D8DA0(origin);
        }
        if (a4 != 0) {
            if (func_00382468(20 - a4) == 0) func_L01_003D8C80(origin);
        }
    }
}
/* localdecomp:end func_L01_003D8E60 */
