/* functional: high. Same behaviour as retail; only instruction scheduling differs (8 words: lq/sq and target store order around the lui constant). */
#include "common.h"
/* localdecomp:start func_L01_004FFA10 */
typedef struct {
    u8 pad0[0x80]; s128 pos; u8 pad90[8]; f32 angle;
    u8 pad9C[0x212-0x9C]; s16 disabled;
    u8 pad214[0x5EC-0x214]; f32 alt_angle;
    u8 pad5F0[0xA24-0x5F0]; Moby_4FB8C8 *target; s32 result;
    u8 padA2C[0xA38-0xA2C]; s32 target_id;
    u8 padA3C[4]; f32 target_value; f32 score;
    u8 padA48[0x25CC-0xA48]; s32 state;
} Hero_004FFA10;
typedef struct { s32 state; f32 value; s32 id; u8 padC[0x1C-0xC]; s32 handle; f32 range; } Data_004FFA10;
extern Veldin1A4BE0 D_001A4BE0;
extern H_4FBE48 D_001A4C60;
extern Moby_4FB8C8 *D_L01_001F0368[];
s32 func_L01_004FFA10(void) {
    extern f32 func_0038CF00(void *, void *);
    extern f32 func_0038CF38(void *, void *);
    extern f32 func_L01_004E9470(f32, f32, f32, f32, Moby_4FB8C8 *, s32 *);
    extern s32 func_00382380(void *, s32, s32);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    Q_4FB8C8 start, end;
    s32 flag;
    Moby_4FB8C8 *m, *best_m;
    Data_004FFA10 *data;
    Hero_004FFA10 *hero;
    Hero_004FFA10 *output;
    Data_004FFA10 *selected;
    f32 best, distance, angle, range, cone, limit, score;
    s32 i;
    if (((Hero_004FFA10 *)&D_001A4BE0)->state == 13) return ((Hero_004FFA10 *)&D_001A4BE0)->result;
    ((Hero_004FFA10 *)&D_001A4BE0)->result = 0;
    if (((Hero_004FFA10 *)&D_001A4BE0)->disabled != 0) return 0;
    best = 100000000.0f;
    best_m = 0;
    for (i = 0; i < 32; i++) {
        m = D_L01_001F0368[i];
        if (m == 0) break;
        if (m->h52 & 1) continue;
        if (!(m->h52 & 0x1000)) continue;
        data = (Data_004FFA10 *)m->pv;
        if (data->state != 0) continue;
        distance = func_0038CF00(&D_001A4C60, &m->pos);
        if (data->range != 0.0f && data->range < distance) continue;
        if (30.0f < distance) continue;
        cone = 0.52359879f;
        limit = -1.0f;
        if (D_001A4C60.f9540 == 1 || D_001A4C60.f9540 == 29) {
            cone = limit = 0.08726646f;
        }
        hero = (Hero_004FFA10 *)&D_001A4BE0;
        angle = hero->angle;
        if (hero->state == 15) angle = hero->alt_angle;
        range = 30.0f;
        if (data->range != 0.0f) range = data->range;
        score = func_L01_004E9470(angle, range, cone, limit, m, &flag);
        if (flag != 0) continue;
        if (func_0038CF38(&hero->pos, &m->pos) < 4.0f) continue;
        if (m->b49 == 0) score += 10.0f;
        if (data->handle >= 0 && func_00382380(&hero->pos, data->handle, 0)) continue;
        if (score < best) {
            best = score;
            best_m = m;
        }
    }
    output = (Hero_004FFA10 *)&D_001A4BE0;
    if (best_m != 0) {
        start.q = output->pos;
        output->target = best_m;
        start.v.z += 0.5f;
        end.q = best_m->pos;
        selected = (Data_004FFA10 *)best_m->pv;
        output->target_id = selected->id;
        output->target_value = selected->value;
        output->score = best;
        if (func_003D3CB0(&start, &end, 2, 0, 0) == 0) output->result = 1;
    }
    return ((Hero_004FFA10 *)&D_001A4BE0)->result;
}
/* localdecomp:end func_L01_004FFA10 */
