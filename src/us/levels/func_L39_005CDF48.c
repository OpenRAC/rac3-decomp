#include "common.h"

/* localdecomp:start func_L39_005CDF48 */
typedef int Quad_5CDF48 __attribute__((mode(TI)));
typedef struct {
    Quad_5CDF48 velocity;          /* 0x20 */
    f32 f10;                       /* 0x30 */
    s16 h14;                       /* 0x34 */
    s16 h16;                       /* 0x36 */
    u8 b18;                        /* 0x38 */
    u8 pad19[3];
    void *w1C;                     /* 0x3C */
} Puff_5CDF48;
typedef struct {
    u8 type;                       /* 0x00 */
    s8 flags;                      /* 0x01 */
    u8 texture;                    /* 0x02 */
    u8 render;                     /* 0x03 */
    u32 rgba;                      /* 0x04 */
    u8 spin;                       /* 0x08 */
    u8 render2;                    /* 0x09 */
    s16 life;                      /* 0x0A */
    f32 size;                      /* 0x0C */
    Quad_5CDF48 position;          /* 0x10 */
    Puff_5CDF48 puff;              /* 0x20 */
} Particle_5CDF48;

extern u8 *D_L39_00296A60 __attribute__((section(".data")));
extern u8 *func_003C7B98(s32);
extern u32 func_L01_00445B88(f32, f32, f32, f32);
extern f32 func_L39_005B2510(f32, f32);
extern s32 func_0019D650(void);

Particle_5CDF48 *func_L39_005CDF48(Quad_5CDF48 *pos, Quad_5CDF48 *vel, u8 kind, void *extra) {
    Particle_5CDF48 *p = (Particle_5CDF48 *)func_003C7B98(0x52);
    Puff_5CDF48 *puff;
    f32 r;

    if (p != 0) {
        p->position = *pos;
        puff = &p->puff;
        p->puff.velocity = *vel;
        p->rgba = func_L01_00445B88(0.7f, 0.7f, 0.7f, 0.08f);
        p->flags = 0;
        p->render2 = 0x44;
        p->render = 0x44;
        r = func_L39_005B2510(0.0f, 1.0f);
        puff->f10 = r;
        p->spin = (s32)(r * 256.0f);
        p->texture = D_L39_00296A60[func_0019D650() & 7];
        puff->b18 = kind;
        puff->h14 = 0;
        puff->h16 = 0;
        if (kind < 5) {
            p->size = func_L39_005B2510(7000.0f, 10000.0f);
            p->life = 0x12 - func_0019D650() % 15;
        } else {
            p->life = 0x12;
            p->size = 10000.0f;
        }
        puff->w1C = extra;
    }
    return p;
}
/* localdecomp:end func_L39_005CDF48 */
