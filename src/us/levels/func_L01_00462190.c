#include "common.h"

/* NTSC-U counterpart of func_L01_00465738 (src/levels/shared/L01_00465738.c): 0.00584 -> 0.00405556 */
#include "structs/vector.h"

/* localdecomp:start func_L01_00462190 */
typedef int u128_465738 __attribute__((mode(TI)));
/* A type-0x0F particle, the fire and smoke puff (open-rac-engine docs/research/effects.md: it
   shrinks to nothing, lerps its colour to an end colour and falls). The first 0x30 bytes are
   struct Particle's (include/structs/effects.h); the rest is this type's own. */
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
    Vec4f position;                /* 0x10: w is the spawner's last integer argument, as a float */
    struct FirePuffMotion_465738 {
        Vec4f velocity;            /* 0x20: w is the gravity */
        u32 rgba_start;            /* 0x30: the colour it lerps from */
        u32 rgba_end;              /* 0x34: the colour it lerps to */
        s16 life_start;            /* 0x38 */
        s16 sheds;                 /* 0x3A: nonzero: sheds a child on odd frames, else keeps 0.96 of its velocity */
        f32 size_start;            /* 0x3C */
    } motion;
} FirePuff_465738;

extern u8 *D_L01_00221154_00462190[];

/* particle_spawn_fire_puff: spawns a type-0x0F particle, the fire and smoke puffs that shrink,
   lerp to an end colour and fall (open-rac-engine docs/research/effects.md). A texture or
   render byte of -1 takes the default. */
FirePuff_465738 *func_L01_00462190(u128_465738 *position, u128_465738 *velocity, s32 rgba, s32 rgba_end, s32 life, s32 sheds, s32 texture, s32 render, s32 w, f32 size) {
    extern FirePuff_465738 *func_L01_0045E438(s32);
    extern u8 func_0013D3E0(void);
    FirePuff_465738 *puff;
    struct FirePuffMotion_465738 *motion;
    if (life == 0) return 0;
    puff = func_L01_0045E438(15);
    if (puff != 0) {
        *(u128_465738 *)&puff->position = *position;
        puff->rgba = rgba;
        puff->position.w = w;
        puff->render2 = 0xA4;
        if (render != -1) puff->render = render;
        else puff->render = 0x48;
        puff->flags = 0;
        puff->size = size;
        puff->spin = func_0013D3E0();
        if (texture == -1) puff->texture = *D_L01_00221154_00462190[0];
        else puff->texture = texture;
        puff->life = life;
        motion = &puff->motion;
        motion->life_start = life;
        motion->size_start = size;
        motion->rgba_start = rgba;
        motion->rgba_end = rgba_end;
        motion->sheds = sheds;
        *(u128_465738 *)&puff->motion.velocity = *velocity;
        motion->velocity.w = 0.00405555591f;
    }
    return puff;
}
/* localdecomp:end func_L01_00462190 */
