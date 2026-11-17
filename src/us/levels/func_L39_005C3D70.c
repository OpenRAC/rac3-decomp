#include "common.h"

/* localdecomp:start func_L39_005C3D70 */
typedef int Quad_5C3D70 __attribute__((mode(TI)));
typedef struct {
    Quad_5C3D70 velocity;          /* 0x20 */
    u32 rgba;                      /* 0x30: the colour it fades from */
    s32 spin_step;                 /* 0x34 */
    s16 size_start;                /* 0x38: x 1000 */
    s16 size_grow;                 /* 0x3A: x 1000, over its life */
    s32 life_start;                /* 0x3C */
} Puff_5C3D70;
typedef struct {
    u8 type;                       /* 0x00 */
    s8 flags;                      /* 0x01 */
    u8 texture;                    /* 0x02 */
    u8 render;                     /* 0x03: 0x48 added, 0x44 blended */
    u32 rgba;                      /* 0x04 */
    u8 spin;                       /* 0x08 */
    u8 render2;                    /* 0x09 */
    s16 life;                      /* 0x0A */
    s32 size;                      /* 0x0C */
    Quad_5C3D70 position;          /* 0x10 */
    Puff_5C3D70 puff;              /* 0x20 */
} Particle_5C3D70;

extern u8 *D_L39_00296928[];
extern u8 *func_003C7B98(s32);
extern u8 func_0019D650(void);

/* A type 4 particle, a smoke puff at position drifting at velocity, growing from size_start to
 * size_start + size_grow (x 1000) over its life and fading from rgba to nothing; added if added
 * is set, else blended. */
Particle_5C3D70 *func_L39_005C3D70(Quad_5C3D70 *position, Quad_5C3D70 *velocity, u32 rgba, s32 spin_step,
                                   s32 life, s32 size_grow, s32 size_start, s32 added) {
    Particle_5C3D70 *p = (Particle_5C3D70 *)func_003C7B98(4);

    if (p != 0) {
        Puff_5C3D70 *puff;

        p->position = *position;
        p->render2 = 0xA4;
        p->rgba = rgba;
        p->render = added ? 0x48 : 0x44;
        p->flags = 0;
        p->texture = *D_L39_00296928[0];
        p->spin = func_0019D650();
        puff = &p->puff;
        p->size = 0;
        p->position = *position;
        p->puff.velocity = *velocity;
        p->life = life;
        puff->life_start = life;
        puff->rgba = rgba;
        puff->spin_step = spin_step;
        puff->size_start = size_start;
        puff->size_grow = size_grow;
    }
    return p;
}
/* localdecomp:end func_L39_005C3D70 */
