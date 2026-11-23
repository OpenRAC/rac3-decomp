/* functional: high. Based on PAL near-miss draft, re-verified block by block against the asm (offsets 0x110/0x120/0x130/0x140-0x14C, callee names); inline-asm VU0 helpers replaced with plain float xyz math. 118 diff words are VU0/register scheduling only */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Q_0044E468;
typedef struct {
    u8 pad0[0x10]; Q_0044E468 pos;
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
    Q_0044E468 matrix[3]; Q_0044E468 rotation;
} M_0044E468;
typedef struct {
    Q_0044E468 pos[8]; Q_0044E468 rotation[8];
    s32 ids[4]; s32 delay[4];
    M_0044E468 *items[4]; f32 scale[4];
    s16 index, history;
    M_0044E468 *parent;
    s32 count, active;
} O_0044E468;
extern void func_L01_0044E740(void *);
extern void func_003C29B0(void *);
extern void func_003C7C38(void *);
extern void func_0038CE20(void *, void *, f32);

void func_L01_0044E468(O_0044E468 *o, s32 fade) {
    Q_0044E468 delta;
    M_0044E468 *m;
    s32 i, slot, done, amount;
    if (o->active == 0) return;
    if (o->parent == 0 || o->parent->state == 254 || o->parent->state == 253) {
        func_L01_0044E740(o);
        return;
    }
    o->pos[o->index] = o->parent->pos;
    o->rotation[o->index] = o->parent->rotation;
    o->index = (o->index + 1) % 8;
    o->history++;
    if (o->history > 8) o->history = 8;
    for (i = 0; i < o->count; i++) {
        s32 delay = o->delay[i];
        if (o->history >= delay) {
            m = o->items[i];
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
            m->pos = o->pos[slot];
            m->rotation = o->rotation[slot];
            if (o->scale[i] != 0.0f) {
                delta.x = m->pos.x - o->parent->pos.x;
                delta.y = m->pos.y - o->parent->pos.y;
                delta.z = m->pos.z - o->parent->pos.z;
                func_0038CE20(&delta, &delta, o->scale[i]);
                m->pos.x = m->pos.x + delta.x;
                m->pos.y = m->pos.y + delta.y;
                m->pos.z = m->pos.z + delta.z;
            }
            func_003C7C38(m);
            if (o->parent->flags & 0x8000) {
                m->matrix[0] = o->parent->matrix[0];
                m->matrix[1] = o->parent->matrix[1];
                m->matrix[2] = o->parent->matrix[2];
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
