#include "common.h"

/* NTSC-U counterpart of func_L01_0033D940 (src/levels/shared/L01_0033D2B8.c): 12 -> 15 */
#include "vu0.h"
extern u8 D_L01_001E1930;
extern void func_L01_0033D248(void *, void *, s32);
extern u8 D_L01_001E1930;

/* localdecomp:start func_L01_0033D248 */
#include "vu0.h"

typedef struct {
    f32 a[4];
    f32 b[4];
    vu0_v4 start;
    vu0_v4 pos;
    f32 ang0[3];
    f32 tgt0[3];
    f32 scale0[3];
    f32 ang1[3];
    f32 tgt1[3];
    f32 scale1[3];
    s32 life;
    void *key;
    void *parent;
    s32 timer;
    s32 duration;
    s32 started;
} Ent_0033D940;

extern Ent_0033D940 D_L01_00278C40_0033D248[];
extern u8 D_L01_001E1930;
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 *func_0037E0B8(void *);
extern void func_L01_0044E010(void *, void *, s32);
extern void func_003886E8(void *, void *, f32);

void func_L01_0033D248(void *key, void *parent, s32 time) {
    s32 i;
    vu0_v4 v;
    Ent_0033D940 *list = D_L01_00278C40_0033D248;

    for (i = 0; i < 3; i++) {
        Ent_0033D940 *e = &list[i];
        f32 *m;
        vu0_v4 *zero = (vu0_v4 *)&D_L01_001E1930;

        if (e->key != 0) {
            continue;
        }
        e->key = key;
        e->start = *zero;
        e->ang0[0] = func_0037E250(-3.1415927f, 3.1415927f);
        e->ang0[1] = func_0037E250(-3.1415927f, 3.1415927f);
        e->ang0[2] = func_0037E250(-3.1415927f, 3.1415927f);
        e->ang1[0] = func_0037E250(-3.1415927f, 3.1415927f);
        e->ang1[1] = func_0037E250(-3.1415927f, 3.1415927f);
        e->ang1[2] = func_0037E250(-3.1415927f, 3.1415927f);
        e->tgt0[0] = func_L01_00440918(0.001f, 0.005f);
        e->tgt0[1] = func_L01_00440918(0.001f, 0.005f);
        e->tgt0[2] = func_L01_00440918(0.001f, 0.005f);
        e->tgt1[0] = func_L01_00440918(0.001f, 0.005f);
        e->tgt1[1] = func_L01_00440918(0.001f, 0.005f);
        e->tgt1[2] = func_L01_00440918(0.001f, 0.005f);
        e->scale0[0] = func_0037E250(3.25f, 4.75f) * 0.5f;
        e->scale0[1] = func_0037E250(3.25f, 4.75f) * 0.5f;
        e->scale0[2] = func_0037E250(3.25f, 4.75f) * 0.5f;
        e->scale1[0] = func_0037E250(3.25f, 4.75f) * 0.5f;
        e->scale1[1] = func_0037E250(3.25f, 4.75f) * 0.5f;
        e->scale1[2] = func_0037E250(3.25f, 4.75f) * 0.5f;
        e->timer = time;
        qzero(e->a);
        e->duration = time;
        qzero(e->b);
        e->life = 0xF;
        e->parent = parent;
        e->started = 0;
        m = func_0037E0B8(parent);
        if (m != 0) {
            func_L01_0044E010(parent, &v, 1);
            func_003886E8(&v, &v, m[4]);
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(e->pos) : "m"(v), "m"(*(vu0_v4 *)((u8 *)parent + 0x10)) : "vf1", "vf2");
        } else {
            e->pos = *(vu0_v4 *)((u8 *)parent + 0x10);
        }
        return;
    }
}
/* localdecomp:end func_L01_0033D248 */
