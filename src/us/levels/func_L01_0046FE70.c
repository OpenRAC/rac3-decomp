#include "common.h"

/* NTSC-U counterpart of func_L01_004735F0 (src/levels/shared/L01_004729D8.c) */
/* localdecomp:start func_L01_0046FE70 */
typedef int Quad_4735F0 __attribute__((mode(TI)));
typedef struct {
    u8 type;                       /* 0x00 */
    s8 flags;                      /* 0x01 */
    u8 texture;                    /* 0x02 */
    u8 render;                     /* 0x03 */
    u32 rgba;                      /* 0x04: R in the low byte */
    u8 spin;                       /* 0x08 */
    u8 render2;                    /* 0x09 */
    s16 life;                      /* 0x0A: frames */
    u32 end_rgba;                  /* 0x0C */
    Quad_4735F0 head;              /* 0x10: w is the half width */
    u8 pad_20[0xC];
    f32 drag;                      /* 0x2C: velocity kept a frame, 1.0 for none */
    Quad_4735F0 tail;              /* 0x30: w is the scale */
} Ray_4735F0;

extern u8 *D_L01_002212D4[];
/* func_L01_004618E0, under an alias: a later block declares it with its own particle type */
extern Ray_4735F0 *func_L01_0045E438_0046FE70(s32 type);

/* particle_spawn_ray: a type 0x6F particle, a ray from head to tail for life frames: white at
 * 0x64 at scale 1, else blue (0x20, 0x20, 0xFF), added, half width scale x 0.013. */
Ray_4735F0 *func_L01_0046FE70(Quad_4735F0 *head, Quad_4735F0 *tail, s32 life, f32 scale) {
    Ray_4735F0 *ray = func_L01_0045E438_0046FE70(0x6F);

    if (ray != 0) {
        if (scale != 1.0f) ray->rgba = 0x64FF2020;
        else ray->rgba = 0x64FFFFFF;
        ray->end_rgba = ray->rgba;
        ray->render2 = 0x22;
        ray->render = 0x48;
        ray->flags = 3;
        ray->texture = *D_L01_002212D4[0];
        ray->tail = *tail;
        ((f32 *)&ray->tail)[3] = scale;
        ray->head = *head;
        ray->life = life;
        ((f32 *)&ray->head)[3] = scale * 0.013f;
        ray->drag = 1.0f;
        ray->spin = (u8)ray->life - 15;
    }
    return ray;
}
/* localdecomp:end func_L01_0046FE70 */
