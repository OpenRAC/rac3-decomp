/* PAL near miss (Codex wave 6): near miss: 124 words differ with the file's flags.
 * Worker's note: 124 diff; logs/func_L01_0044E468.08.wrapper.log; ring history, clone updates, VU0 delta and fade reconstructed; remaining induction/register scheduling and VU0 scheduling differences after eight compiles.
 */
#include "common.h"
/* localdecomp:start func_L01_0044E468 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x10]; vu0_q pos;
    u8 state; u8 pad21[2]; u8 alpha;
    u8 pad24[0x40-0x24];
    u8 b40, b41, b42, b43;
    f32 f44;
    u8 pad48[0x58-0x48];
    s32 f58, f5C;
    u8 pad60[0x7C-0x60];
    u16 flags;
    u8 pad7E[0xAA-0x7E]; s16 mode;
    u8 padAC[0xC0-0xAC];
    vu0_q matrix[3]; vu0_q rotation;
} M_0044E468;
typedef struct {
    vu0_q pos[8]; vu0_q rotation[8];
    s32 ids[4]; s32 delay[4];
    M_0044E468 *items[4]; f32 scale[4];
    s16 index, history;
    M_0044E468 *parent;
    s32 count, active;
} O_0044E468;
void func_L01_0044E468(O_0044E468 *o, s32 fade) {
    extern void func_L01_0044E740();
    extern void func_003C29B0(void *);
    extern void func_003C7C38(u8 *);
    vu0_v4 delta;
    M_0044E468 *m;
    s32 i, slot, done, amount, offset;
    if (o->active == 0) return;
    if (o->parent == 0 || o->parent->state == 254 || o->parent->state == 253) {
        func_L01_0044E740(o);
        return;
    }
    *((vu0_q *)((o->index << 4) + (u32)o)) = o->parent->pos;
    ((vu0_q *)o)[o->index + 8] = o->parent->rotation;
    o->index = (o->index + 1) % 8;
    o->history++;
    if (o->history > 8) o->history = 8;
    for (i = 0, offset = 0; i < o->count; i++, offset += 4) {
        O_0044E468 *row = (O_0044E468 *)((u8 *)o + offset);
        s32 delay = row->delay[0];
        if (o->history >= delay) {
            m = row->items[0];
            m->b42 = o->parent->b42;
            slot = (o->index - delay + 8) % 8;
            m->b43 = o->parent->b43;
            m->b40 = o->parent->b40;
            m->b41 = o->parent->b41;
            m->f44 = o->parent->f44;
            if (m->mode == 0) {
                m->f58 = o->parent->f58;
                m->f5C = o->parent->f5C;
            } else {
                func_003C29B0(m);
            }
            m->pos = *((vu0_q *)((slot << 4) + (u32)o));
            m->rotation = ((vu0_q *)o)[slot + 8];
            { f32 scale = ((O_0044E468 *)((u8 *)o + offset))->scale[0];
            if (scale != 0.0f) {
                vec_sub_ab(&delta, &m->pos, &o->parent->pos);
                func_0038CE20(&delta, &delta, scale);
                vec_add_ab(&m->pos, &m->pos, &delta);
            }
            }
            func_003C7C38((u8 *)m);
            { M_0044E468 *parent = o->parent;
            if (parent->flags & 0x8000) {
                m->matrix[0] = parent->matrix[0];
                m->matrix[1] = parent->matrix[1];
                m->matrix[2] = parent->matrix[2];
            }
            }
        }
    }
    if (fade != 0) {
        done = 1;
        for (i = 0; i < o->count; i++) {
            M_0044E468 *item = o->items[i];
            if (item != 0) {
                amount = item->alpha;
                if (amount > fade) amount = fade;
                item->alpha -= amount;
                if (item->alpha != 0) done = 0;
            }
        }
        if (done != 0) func_L01_0044E740(o);
    }
}
/* localdecomp:end func_L01_0044E468 */
