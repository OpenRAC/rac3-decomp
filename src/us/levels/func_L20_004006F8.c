#include "common.h"

/* NTSC-U counterpart of func_L20_00402AD0 (src/levels/20_final_boss/L20_004026A0.c) */
#include "vu0.h"
extern u8 D_L20_00220258_004006F8[];
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_0037E1D8(s32);

/* localdecomp:start func_L20_004006F8 */
#include "vu0.h"
typedef struct {
    vu0_v4 vel;
    s32 field10;
    f32 scale;
    u8 pad18[2];
    s16 chance;
    f32 distance;
    f32 period;
    f32 total;
    f32 fraction;
    f32 rate;
} State_00402AD0;
extern u8 D_L20_00220258_004006F8[] __attribute__((section(".sdata")));
void func_L20_004006F8(u8 *obj, State_00402AD0 *s) {
    extern s32 func_0037E208(s32, s32);
    extern f32 func_0037E250(f32, f32);
    extern void func_00388830(void *, void *, f32);
    extern f32 func_00388770(void *);
    extern void func_003BF6A8(void *, f32);
    extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);
    extern s32 func_0037E1D8(s32);
    vu0_v4 pos, step, spawn, dir;
    f32 amount, speed, distance, width, height, factor;
    s32 count, life, i;
    u8 *p;
    pos = *(vu0_v4 *)(obj + 0x10);
    vec_add_ab(obj + 0x10, obj + 0x10, &s->vel);
    amount = s->rate * (1.5f / s->period);
    count = amount;
    s->fraction += amount - (f32)count;
    if (s->fraction >= 1.0f) {
        s->fraction -= 1.0f;
        count++;
    }
    if (count > 0) {
        func_00388830(&step, s, s->period / (f32)count);
        distance = s->distance;
        speed = func_00388770(&step);
        for (i = 0; i < count; i++) {
            vec_add_ab(&pos, &pos, &step);
            life = func_0037E208(90, 110);
            distance += speed;
            width = s->scale * func_0037E250(1.5f, 2.0f);
            factor = ((s->total - distance) / s->total) * 0.8f + 0.19999999f;
            spawn = pos;
            height = width + width;
            width *= factor;
            height *= factor;
            func_003BF6A8(&pos, s->scale * 0.15f);
            qzero(&dir);
            p = func_L01_00472438(&spawn, &dir, life, func_0037E208(-1, 1), s->field10, 0, 0,
                                 width * 210000.0f, height * 210000.0f, 0.0f);
            if (p) {
                u8 *g = D_L20_00220258_004006F8;
                p[9] = 0xF2;
                p[2] = (*(u8 **)(g + 0x184))[3];
                if (s->chance > 0 && func_0037E1D8(s->chance) == 0) p[3] = 0x44;
            }

        }
    }
}
/* localdecomp:end func_L20_004006F8 */
