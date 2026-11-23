#include "common.h"

/* NTSC-U counterpart of func_L01_004669B0 (src/levels/shared/L01_00465878.c) */
#include "vu0.h"
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_0045E438(s32);
#include "vu0.h"
#include "vu0.h"
extern u8 *func_L01_0045E438(s32);
#include "vu0.h"

/* localdecomp:start func_L01_004633E8 */
typedef int Quad_4669B0 __attribute__((mode(TI)));
typedef struct {
    u32 rgba;                      /* 0x20: the colour it fades from */
    s32 pad_24;                    /* 0x24 */
    s16 spin_rate;                 /* 0x28: turn a frame, random sign */
    u8 pad_2A[2];
    f32 grow;                      /* 0x2C: size factor a frame */
    Quad_4669B0 drift;             /* 0x30: w is 25.0 */
} Cloud_4669B0;
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
    f32 x;                         /* 0x10: the position */
    f32 y;                         /* 0x14 */
    f32 z;                         /* 0x18 */
    f32 fade_start;                /* 0x1C */
    Cloud_4669B0 cloud;            /* 0x20 */
} Smoke_4669B0;

extern u8 *D_L01_00221174_004633E8[];
extern u8 *func_L01_0045E438(s32);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);

/* particle_spawn_smoke: a type 0x17 particle, the dark smoke: it appears at position jittered by up
 * to jitter, grows by a factor from grow_min to grow_max a frame and fades in before it fades out. */
Smoke_4669B0 *func_L01_004633E8(Quad_4669B0 *position, s32 spin_rate, Quad_4669B0 *drift, u32 rgba, s32 fade_start,
                                f32 jitter, f32 grow_min, f32 grow_max, f32 size) {
    Smoke_4669B0 *p = (Smoke_4669B0 *)func_L01_0045E438(0x17);
    Cloud_4669B0 *cloud;

    if (p != 0) {
        *(Quad_4669B0 *)&p->x = *position;
        p->flags = 0;
        p->render2 = 0x74;
        p->render = 0x48;
        p->rgba = rgba | 0x20000000;
        cloud = &p->cloud;
        p->size = size;
        p->spin = 0;
        p->texture = *D_L01_00221174_004633E8[0];
        p->x += func_L01_00440918(0.0f, jitter);
        p->y += func_L01_00440918(0.0f, jitter);
        p->z += func_L01_00440918(0.0f, jitter);
        p->fade_start = fade_start;
        p->life = 10;
        cloud->pad_24 = 0;
        cloud->rgba = rgba;
        if (func_0037E1D8(2) != 0) cloud->spin_rate = spin_rate;
        else cloud->spin_rate = -spin_rate;
        cloud->grow = func_0037E250(grow_min, grow_max);
        cloud->drift = *drift;
        ((f32 *)&cloud->drift)[3] = 30.0f;
    }
    return p;
}
/* localdecomp:end func_L01_004633E8 */
