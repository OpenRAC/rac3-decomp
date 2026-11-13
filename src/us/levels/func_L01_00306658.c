#include "common.h"

/* NTSC-U counterpart of func_L01_003068B8 (src/levels/shared/L01_003068B8.c): 0.0024 -> 0.002; 0.00024 -> 0.0002; 0.024 -> 0.02; 50 -> 60 */
/* localdecomp:start func_L01_00306658 */
typedef int s128_003068B8 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x20];
    s128_003068B8 flame_pos[2]; /* 0x20 */
    u8 pad40[0x4F0 - 0x40];
    f32 u_speed[4];             /* 0x4F0: each flame's u scroll a frame */
    f32 u[4];                   /* 0x500 */
    f32 strength;               /* 0x510 */
    s32 active;                 /* 0x514 */
    s32 phase;                  /* 0x518: 0 growing, 2 holding, 1 falling */
    f32 rate;                   /* 0x51C: the spring's */
    s32 hold;                   /* 0x520: frames */
    u8 pad524[0x530 - 0x524];
} Pool_003068B8;

__asm__(".extern D_L01_001DC608, 4");
extern Pool_003068B8 *D_L01_001DC608; /* the 10 pools */
extern void func_L01_004C6EC8(void *out, void *pos);
extern f32 func_L01_00445168(f32 *value, f32 target, f32 *rate, f32 gain, f32 damping, f32 cap);
extern s32 func_0038CAD0(void *timer);

/* lava_pools_update: the Lava Gun's 10 burning pools: each one's flames keep to what they
   stand on and their textures scroll; its strength springs to 0.5 (game_spring 0.0024,
   0.00024, at most 0.024 a frame: NTSC's x 1.2), holds 60 frames and springs back to 0. */
void func_L01_00306658(void)
{
    s32 i;
    s32 j;
    Pool_003068B8 *pool;
    f32 full;
    f32 none;

    for (i = 0; i < 10; i++) {
        /* the slot's address, index first */
        pool = (Pool_003068B8 *)(i * sizeof(Pool_003068B8) + (u32)D_L01_001DC608);
        if (pool->active != 1) {
            continue;
        }
        for (j = 0; j < 2; j++) {
            func_L01_004C6EC8(&pool->flame_pos[j], &pool->flame_pos[j]);
            pool->u[j] += pool->u_speed[j];
            if (pool->u[j] <= -8.0f) {
                pool->u[j] += 8.0f;
            }
        }
        if (pool->phase == 0) {
            full = 0.5f;
            func_L01_00445168(&pool->strength, full, &pool->rate, 0.00200000009f, 0.000199999995f, 0.0199999996f);
            if (pool->strength == full) {
                pool->phase = 2;
                pool->hold = 60;
            }
        } else if (pool->phase == 1) {
            none = 0.0f;
            func_L01_00445168(&pool->strength, none, &pool->rate, 0.00200000009f, 0.000199999995f, 0.0199999996f);
            if (pool->strength == none) {
                pool->active = 0;
            }
        } else if (func_0038CAD0(&pool->hold) != 0) {
            pool->phase = 1;
        }
    }
}
/* localdecomp:end func_L01_00306658 */
