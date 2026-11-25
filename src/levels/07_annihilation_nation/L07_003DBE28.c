#include "common.h"
#include "vu0.h"
#include "structs/moby.h"

/* localdecomp:start func_L07_003DBE28 */
void func_L01_00404808(void *, void *);
s32 func_L01_004561B8(void *);
void func_L07_003DC0C8(void *);
void func_L07_003DC6E8(void *);
extern s32 D_L07_001DE908;
extern s32 D_L07_001DE928;
__asm__(".extern D_L07_001DE908, 4");
__asm__(".extern D_L07_001DE928, 4");
extern u8 D_L07_003DC940[];

void func_L07_003DBE28(void *arg0) {
    u16 temp_v1_2;
    u8 temp_v1;
    void *temp_s1;

    temp_v1 = *(u8 *)((u8 *)arg0 + 0x20);
    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    switch (temp_v1) {                              /* irregular */
    case 0:
        if (func_L01_004561B8(arg0) != 0) {
            *(void **)((u8 *)temp_s1 + 0x114) = &D_L07_001DE908;
        }
        if ((u16) (*(u16 *)((u8 *)arg0 + 0x96)) >= 0x12U) {
            *(void **)((u8 *)temp_s1 + 0x110) = &D_L07_001DE908;
        }
        break;
    case 1:
        if (func_L01_004561B8(arg0) != 0) {
            *(void **)((u8 *)temp_s1 + 0x114) = &D_L07_001DE928;
        }
        if ((u16) (*(u16 *)((u8 *)arg0 + 0x96)) >= 0x12U) {
            *(void **)((u8 *)temp_s1 + 0x110) = &D_L07_001DE928;
        }
        func_L07_003DC6E8(arg0);
        break;
    }
    func_L07_003DC0C8(arg0);
    func_L01_00404808(D_L07_003DC940, arg0);
    temp_v1_2 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1_2 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1_2 + 1);
    }
}
/* localdecomp:end func_L07_003DBE28 */

/* localdecomp:start func_L07_003DBF10 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003DBF10;
typedef struct { u8 pad_0[0x100]; V_003DBF10 vector; u8 pad_110[8]; s32 joint; f32 duration; s32 pad_120; s32 timer; f32 gain; } P_003DBF10;
extern struct Moby *func_003C24B0(s32,s32);
extern void func_L01_004450F0(void *,s32,s32);
extern void func_L01_0044FD88(struct Moby *,struct Moby *,s32,s32);
extern void func_003C7C38(struct Moby *);
extern void func_L07_003DC040(struct Moby *);
struct Moby *func_L07_003DBF10(struct Moby *parent, s32 joint, V_003DBF10 *vector, f32 gain, f32 duration) {
    V_003DBF10 value = *vector;
    struct Moby *moby = func_003C24B0(0x1D3F,0x130);
    P_003DBF10 *p;
    if (moby) {
        struct MobyClass *cls = moby->pclass;
        moby->pad_30[0] = 0xFF;
        moby->draw_dist = parent->draw_dist;
        moby->scale = cls->scale * 0.3f;
        moby->mode_flags |= 0x100;
        p = moby->pvar;
        func_L01_004450F0(moby,0,0);
        moby->parent = parent;
        func_L01_0044FD88(parent,moby,joint,0);
        moby->mode_flags &= ~2;
        p->duration = duration;
        p->joint = joint;
        p->vector = value;
        p->gain = gain;
        func_003C7C38(moby);
        func_L07_003DC040(moby);
        p->timer = -1;
    }
    return moby;
}
/* localdecomp:end func_L07_003DBF10 */

/* localdecomp:start func_L07_003DC020 */
void func_L01_004450F0(void *, s32, s32);
void func_L07_003DC020(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        func_L01_004450F0((void *)arg0, arg1, -1);
    }
}
/* localdecomp:end func_L07_003DC020 */

/* localdecomp:start func_L07_003DC040 */
typedef int Q_3DC040 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_3DC040;
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 D_L07_001DE908;
__asm__(".extern D_L07_001DE908, 4");
void func_L07_003DC040(struct Moby *self) {
    V_3DC040 matrix[4];
    V_3DC040 step;
    P_003DBF10 *state = self->pvar;
    u8 *p = (u8 *)state;
    Q_3DC040 *pos;
    Q_3DC040 translation;
    s32 i;
    func_003C2EC0(self->parent, state->joint, matrix);
    translation = *(Q_3DC040 *)&matrix[3];
    *(Q_3DC040 *)p = translation;
    *(Q_3DC040 *)(p + 0x80) = translation;
    func_0038CF68(&step, matrix, *(f32 *)&D_L07_001DE908);
    pos = (Q_3DC040 *)(p + 0x10);
    for (i = 6; i >= 0; i--) {
        vec_add_ab(pos, pos-1, &step);
        pos[8] = *pos;
        pos++;
    }
    *(void **)(p+0x114) = &D_L07_001DE908;
    *(void **)(p+0x110) = &D_L07_001DE908;
}
/* localdecomp:end func_L07_003DC040 */

/* localdecomp:start func_L07_003DC0C8 */
typedef struct {
    f32 link_length;
    f32 accel_z;
    f32 velocity_scale;
    f32 floor_offset;
    f32 anchor_radius;
    u8 constraint_passes;
    u8 fixed_count;
    u8 anchor_start;
    u8 max_span;
    u8 pad18[8];
} RopeParams_003DC0C8;

typedef struct {
    vu0_v4 link[8];
    vu0_v4 prev[8];
    vu0_v4 anchor;
    RopeParams_003DC0C8 *params_from;
    RopeParams_003DC0C8 *params_to;
    s32 joint;
    u8 pad11C[12];
    f32 floor_z;
} RopeState_003DC0C8;

extern void func_L07_003DC598(RopeParams_003DC0C8 *, RopeParams_003DC0C8 *, RopeParams_003DC0C8 *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L07_003DC4C8(void *, void *, s32, s32, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_L01_0040E4C0(void *);

void func_L07_003DC0C8(void *moby) {
    struct Moby *obj = moby;
    RopeParams_003DC0C8 params;
    vu0_v4 gravity, step, saved, delta, scaled;
    RopeState_003DC0C8 *state;
    f32 radius_sq, correction;
    s32 i, index, pass, span, next_index;
    vu0_v4 *link, *previous, *first, *next_first;
    vu0_v4 *anchor, *anchor_pos;

    state = obj->pvar;
    func_L07_003DC598(&params, state->params_from, state->params_to,
                      (f32)*(u16 *)((u8 *)obj + 0x96) / 17.0f);
    if (*(u16 *)((u8 *)obj + 0x96) < 17) {
        params.velocity_scale = 1.0f;
    }

    *(vu0_q *)&step = 0;
    step.z = params.accel_z;
    anchor = &state->anchor;
    gravity = step;
    func_L01_0044FD88(obj->parent, obj, state->joint, 0);
    obj->mode_flags &= 0xFFFD;
    *(vu0_q *)&state->link[0] = *(vu0_q *)&obj->position;
    *(vu0_q *)&state->prev[0] = *(vu0_q *)&obj->position;
    func_0038CF68(&step, obj->matrix, params.link_length);
    i = 1;
    anchor_pos = &saved;

    for (; i < params.fixed_count; i++) {
        vec_add_ab(&state->link[i], &state->link[i - 1], &step);
        *(vu0_q *)&state->prev[i] = *(vu0_q *)&state->link[i];
    }
    link = &state->link[params.fixed_count];
    previous = &state->prev[params.fixed_count];
    index = params.fixed_count;
    for (; index < 8; link++, previous++, index++) {
        *(vu0_q *)&saved = *(vu0_q *)link;
        vec_sub_ba(&delta, link, previous);
        func_0038CE20(&delta, &delta, params.velocity_scale);
        vec_add_ab(link, link, &delta);
        vec_add_ab(link, link, &gravity);
        *(vu0_q *)previous = *(vu0_q *)&saved;
    }

    for (pass = 0; pass < params.constraint_passes; pass++) {
        first = &state->link[0];
        for (index = 0; index < 7; index = next_index) {
            span = 1;
            next_index = index + 1;
            next_first = first + 1;
            if (span <= params.max_span && next_index < 8) {
                s32 in_bounds;

                do {
                    f32 rest = (f32)span * params.link_length;

                    func_L07_003DC4C8(first, first + span, index >= params.fixed_count,
                                      index + span >= params.fixed_count, rest * rest);
                    ++span;
                    in_bounds = (index + span < 8);
                } while (span <= params.max_span && in_bounds);
            }
            first = next_first;
        }
    }

    func_0038D000(anchor_pos, anchor, obj->parent->matrix);
    vec_add_ab(&saved, &saved, &obj->parent->position);

    link = state->link;
    for (index = 0; index < 8; index++, link++) {
        f32 lower = params.floor_offset + state->floor_z;
        if (link->z < lower) {
            link->z = lower;
        }
        if (index >= params.anchor_start) {
            vec_sub_ab(&delta, &saved, link);
            radius_sq = params.anchor_radius * params.anchor_radius;
            correction = func_L01_0040E4C0(&delta);
            correction = radius_sq / (correction + radius_sq) - 0.5f;
            if (correction > 0.0f) {
                func_0038CE20(&scaled, &delta, correction + correction);
                vec_sub_ab(link, link, &scaled);
            }
            if (link->z < saved.z) {
                delta.z = 0.0f;
                correction = radius_sq / (func_L01_0040E4C0(&delta) + radius_sq) - 0.5f;
                if (correction > 0.0f) {
                    func_0038CE20(&scaled, &delta, correction + correction);
                    vec_sub_ab(link, link, &scaled);
                }
            }
        }
    }
}
/* localdecomp:end func_L07_003DC0C8 */

/* localdecomp:start func_L07_003DC4C8 */
extern f32 func_L01_0040E4C0(void *);
extern void func_0038CE20(void *, void *, f32);

void func_L07_003DC4C8(void *a, void *b, s32 move_a, s32 move_b, f32 radius) {
    vu0_v4 delta;
    f32 length;
    vec_sub_ab(&delta, b, a);
    length = func_L01_0040E4C0(&delta);
    radius = radius / (length + radius);
    func_0038CE20(&delta, &delta, radius - 0.5f);
    if (move_a) vec_sub_ab(a, a, &delta);
    if (move_b) vec_add_ab(b, b, &delta);
}
/* localdecomp:end func_L07_003DC4C8 */
