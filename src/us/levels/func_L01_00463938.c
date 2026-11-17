#include "common.h"

/* NTSC-U counterpart of func_L01_00466F50 (src/levels/shared/L01_00462978.c): 67 -> 80 */
extern u8 *func_L01_0045E438(s32);
extern u8 *func_L01_0045E438(s32);
extern u8 *func_L01_0045E438(s32);

/* localdecomp:start func_L01_00463938 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_466F50;
typedef struct {
    Vec_466F50 velocity;           /* 0x20: w is the gravity (0: 22.7 u/s^2) */
    f32 red_fade;                  /* 0x30: 1 white to yellow to red, -1 to green */
    f32 green_fade;                /* 0x34 */
    f32 blue_fade;                 /* 0x38 */
    f32 alpha;                     /* 0x3C */
} Spark_466F50;
typedef struct {
    u8 type;                       /* 0x00 */
    s8 flags;                      /* 0x01 */
    u8 texture;                    /* 0x02 */
    u8 render;                     /* 0x03 */
    u32 rgba;                      /* 0x04 */
    u8 spin;                       /* 0x08 */
    u8 render2;                    /* 0x09 */
    s16 life;                      /* 0x0A */
    f32 size;                      /* 0x0C: world units x 210000 */
    Vec_466F50 position;           /* 0x10 */
    Spark_466F50 spark;            /* 0x20 */
} Particle_466F50;

extern u8 *D_L01_0022117C[];
extern u8 *func_L01_0045E438(s32);
extern u32 func_L01_00445B88(f32 r, f32 g, f32 b, f32 a);
extern f32 func_003824E0_00463938(f32 low, f32 high);

/* particle_spawn_spark: a type 0x19 particle, a drop or spark at position moving at velocity
 * that falls by gravity, shrinks and stops where it meets the world: white at alpha 0.6 going
 * to red, or to green if green is set; a negative size is a random 5000-30000. */
void func_L01_00463938(Vec_466F50 *position, Vec_466F50 *velocity, s32 green, f32 size, f32 gravity) {
    Particle_466F50 *p = (Particle_466F50 *)func_L01_0045E438(0x19);

    if (p != 0) {
        Spark_466F50 *spark;

        p->position = *position;
        spark = &p->spark;
        if (!green) {
            p->rgba = func_L01_00445B88(1.0f, 1.0f, 1.0f, 0.6f);
            spark->red_fade = 1.0f;
            spark->green_fade = 1.0f;
            spark->blue_fade = 1.0f;
        } else {
            p->rgba = func_L01_00445B88(1.0f, 1.0f, 1.0f, 0.6f);
            spark->red_fade = -1.0f;
            spark->green_fade = -1.0f;
            spark->blue_fade = -1.0f;
        }
        p->render2 = 0x44;
        p->render = 0x48;
        p->flags = 0;
        if (size < 0.0f) p->size = func_003824E0_00463938(5000.0f, 30000.0f);
        else p->size = size;
        p->spin = 0;
        p->texture = *D_L01_0022117C[0];
        spark->alpha = 0.6f;
        p->life = 0x50;
        spark->velocity = *velocity;
        spark->velocity.w = gravity;
    }
}
/* localdecomp:end func_L01_00463938 */
