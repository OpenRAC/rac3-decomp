#include "common.h"

/* localdecomp:start func_L07_00473C80 */
typedef struct V_00473C80 { f32 x, y, z, w; } __attribute__((aligned(16))) V_00473C80;
typedef struct Payload_00473C80 {
    void *owner;
    f32 size_start, size_end;
    s16 fade, life_start;
    f32 offset;
    u8 joint, alpha, pad16, axis;
} Payload_00473C80;
typedef struct Effect_00473C80 {
    u8 type;
    s8 flags;
    u8 texture, render;
    u32 rgba;
    u8 spin, render2;
    s16 life;
    f32 size;
    V_00473C80 pos;
    Payload_00473C80 data;
} Effect_00473C80;

extern Effect_00473C80 *func_L01_004618E0(s32);
extern s32 func_00382468(s32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern u8 *D_L07_0021EC98[];

Effect_00473C80 *func_L07_00473C80(void *owner, u8 joint, f32 size_start, f32 size_end, f32 offset, u32 rgba, u8 alpha, s16 life, s16 fade, u8 axis, s32 table, s32 index) {
    V_00473C80 matrix[4];
    V_00473C80 delta;
    Effect_00473C80 *p;
    Payload_00473C80 *d;
    if (owner == 0) return 0;
    p = func_L01_004618E0(0x7A);
    if (p != 0) {
        d = &p->data;
        p->flags = 0;
        p->render2 = 0x44;
        p->size = size_start;
        p->render = 0x48;
        p->spin = func_00382468(0x100);
        p->texture = D_L07_0021EC98[table][index];
        p->rgba = rgba;
        d->owner = owner;
        p->life = life;
        d->joint = joint;
        d->size_start = size_start;
        d->size_end = size_end;
        d->life_start = life;
        d->fade = fade;
        d->axis = axis;
        d->alpha = alpha;
        d->offset = offset;
        if (offset != 0.0f) {
            func_003C2EC0(d->owner, d->joint, matrix);
            func_0038CF68(&delta, &matrix[d->axis], d->offset);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(p->pos) : "m"(matrix[3]), "m"(delta) : "vf1", "vf2");
        } else {
            func_003C2F58(d->owner, d->joint, &p->pos);
        }
    }
    return p;
}
/* localdecomp:end func_L07_00473C80 */
