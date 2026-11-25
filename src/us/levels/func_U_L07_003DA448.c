#include "common.h"
#include "vu0.h"
#include "structs/moby.h"

/* NTSC-U counterpart of func_L07_003DC0C8. */
/* localdecomp:start func_U_L07_003DA448 */
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

extern void func_U_003DA918(RopeParams_003DC0C8 *, RopeParams_003DC0C8 *, RopeParams_003DC0C8 *, f32);
extern void func_U_0040CA00(void *, void *, f32);
extern void func_U_0044D078(struct Moby *, struct Moby *, s32, s32);
extern void func_U_0040C7A0(void *, void *, f32);
extern void func_U_003DA848(void *, void *, s32, s32, f32);
extern void func_U_0040CBE0(void *, void *, void *);
extern f32 func_U_0040C8A0(void *);

void func_U_L07_003DA448(void *moby) {
    struct Moby *obj = moby;
    RopeParams_003DC0C8 params;
    vu0_v4 gravity, step, saved, delta, scaled;
    RopeState_003DC0C8 *state;
    f32 radius_sq, correction;
    s32 i, index, pass, span, next_index;
    vu0_v4 *link, *previous, *first, *next_first;
    vu0_v4 *anchor, *anchor_pos;

    state = obj->pvar;
    func_U_003DA918(&params, state->params_from, state->params_to,
                      (f32)*(u16 *)((u8 *)obj + 0x96) / 20.0f);
    if (*(u16 *)((u8 *)obj + 0x96) < 20) {
        params.velocity_scale = 1.0f;
    }

    *(vu0_q *)&step = 0;
    step.z = params.accel_z;
    anchor = &state->anchor;
    gravity = step;
    func_U_0044D078(obj->parent, obj, state->joint, 0);
    obj->mode_flags &= 0xFFFD;
    *(vu0_q *)&state->link[0] = *(vu0_q *)&obj->position;
    *(vu0_q *)&state->prev[0] = *(vu0_q *)&obj->position;
    func_U_0040CA00(&step, obj->matrix, params.link_length);
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
        func_U_0040C7A0(&delta, &delta, params.velocity_scale);
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

                    func_U_003DA848(first, first + span, index >= params.fixed_count,
                                      index + span >= params.fixed_count, rest * rest);
                    ++span;
                    in_bounds = (index + span < 8);
                } while (span <= params.max_span && in_bounds);
            }
            first = next_first;
        }
    }

    func_U_0040CBE0(anchor_pos, anchor, obj->parent->matrix);
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
            correction = func_U_0040C8A0(&delta);
            correction = radius_sq / (correction + radius_sq) - 0.5f;
            if (correction > 0.0f) {
                func_U_0040C7A0(&scaled, &delta, correction + correction);
                vec_sub_ab(link, link, &scaled);
            }
            if (link->z < saved.z) {
                delta.z = 0.0f;
                correction = radius_sq / (func_U_0040C8A0(&delta) + radius_sq) - 0.5f;
                if (correction > 0.0f) {
                    func_U_0040C7A0(&scaled, &delta, correction + correction);
                    vec_sub_ab(link, link, &scaled);
                }
            }
        }
    }
}
/* localdecomp:end func_U_L07_003DA448 */
