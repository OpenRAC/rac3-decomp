#include "common.h"

/* NTSC-U counterpart of func_L01_0046A610 (src/levels/shared/L01_00462978.c) */
extern u8 *func_L01_0045E438(s32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_0045E438(s32);
extern u8 *func_L01_0045E438(s32);
extern u8 *func_L01_0045E438(s32);

/* localdecomp:start func_L01_00466F98 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_46A610;
typedef struct {
    f32 velocity[3];               /* 0x20 */
    f32 gravity;                   /* 0x2C */
    u8 spin_step;                  /* 0x30: a frame */
    u8 rgb[3];                     /* 0x31: the colour it starts from */
    f32 size_step;                 /* 0x34: a frame */
    f32 drag;                      /* 0x38: velocity kept a frame, 1.0 for none */
    s16 life_start;                /* 0x3C */
    s16 alpha_start;               /* 0x3E */
} Ember_46A610;
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
    Vec_46A610 position;           /* 0x10 */
    Ember_46A610 ember;            /* 0x20 */
} Particle_46A610;

extern u8 *D_L01_002211C8[];
extern u8 *func_L01_0045E438(s32);
extern s32 func_0037E1D8(s32);

/* particle_spawn_ember: a type 0x2C particle, an ember or spark that fades to nothing over its
 * life, grows a set step a frame, keeps drag of its velocity and falls by gravity; NTSC-U takes
 * the per-frame rates as they come (PAL scales them by 1.2 for 50 Hz). */
Particle_46A610 *func_L01_00466F98(Vec_46A610 *position, f32 *velocity, s32 life, s32 alpha, s32 rgb, s32 spin_step,
                                   f32 size, f32 size_step, f32 drag, f32 gravity, f32 w) {
    Particle_46A610 *p = (Particle_46A610 *)func_L01_0045E438(0x2C);

    if (p != 0) {
        Ember_46A610 *ember;

        p->position = *position;
        p->size = size;
        p->position.w = w;
        p->flags = 0;
        p->rgba = (alpha << 24) | rgb;
        p->render2 = 0x44;
        p->render = 0x48;
        p->spin = func_0037E1D8(0xFF);
        p->texture = *D_L01_002211C8[0];
        p->life = life;
        ember = &p->ember;
        ember->velocity[0] = velocity[0];
        ember->velocity[1] = velocity[1];
        ember->velocity[2] = velocity[2];
        ember->spin_step = spin_step;
        ember->size_step = size_step;
        ember->drag = drag;
        ember->rgb[0] = rgb;
        ember->rgb[1] = rgb >> 8;
        ember->rgb[2] = rgb >> 16;
        ember->life_start = life;
        ember->alpha_start = alpha;
        ember->gravity = gravity;
    }
    return p;
}
/* localdecomp:end func_L01_00466F98 */
