#include "common.h"

/* localdecomp:start func_L01_003F6F10 */
extern s32 D_L01_001E5500[];

void func_L01_003F6F10(void) {
    D_L01_001E5500[0] = 0;
}
/* localdecomp:end func_L01_003F6F10 */

/* localdecomp:start func_L01_003F6F20 */
typedef int u128_3F6F20 __attribute__((mode(TI)));

typedef struct {
    u128_3F6F20 point;  /* the world point, projected each frame */
    f32 scale;
    u32 rgba;
    s32 texture;
    f32 angle;
    s32 owner;
    u8 has_point;       /* 1: at point, 0: at the screen point */
    u8 player;
    s16 shrink;
    f32 step;
    s32 kind;
    f32 sx;             /* the screen point */
    f32 sy;
    f32 w;
    f32 h;
} Marker_3F6F20;

typedef struct {
    Marker_3F6F20 items[14];
    s32 count;
} Markers_3F6F20;

__asm__(".extern D_L01_001D6078, 4");
extern s32 D_L01_001D6694;
extern Markers_3F6F20 D_L01_001E5180;
extern s32 D_L01_001D6078;
extern f32 func_0038CF00(void *, void *);

/* reticle_marker_add: queues a screen marker for this frame (14 at most), unless the owner
   already has one at the same screen point or world point; its alpha is capped. */
void func_L01_003F6F20(s32 player, s32 owner, f32 scale, u32 rgba, u128_3F6F20 *world,
                       f32 angle, f32 step, f32 sx, f32 sy, f32 w, f32 h, s32 texture, s32 kind) {
    Marker_3F6F20 *m;
    s32 i;

    if (D_L01_001D6694 == 2) {
        return;
    }
    if (D_L01_001E5180.count >= 14) {
        return;
    }
    for (i = 0; i < D_L01_001E5180.count; i++) {
        if (D_L01_001E5180.items[i].owner != owner) {
            continue;
        }
        if (world == 0 && D_L01_001E5180.items[i].has_point == 0 &&
            D_L01_001E5180.items[i].sx == sx && D_L01_001E5180.items[i].sy == sy) {
            return;
        }
        if (world != 0 && D_L01_001E5180.items[i].has_point == 1 &&
            func_0038CF00(&D_L01_001E5180.items[i], world) == 0.0f) {
            return;
        }
    }
    m = &D_L01_001E5180.items[D_L01_001E5180.count];
    m->owner = owner;
    m->scale = scale;
    m->texture = texture;
    m->angle = angle;
    m->w = w;
    m->h = h;
    m->rgba = rgba;
    m->player = player;
    if ((s32)(rgba >> 24) > D_L01_001D6078) {
        m->rgba = (rgba & 0xFFFFFF) | (D_L01_001D6078 << 24);
    }
    m->sx = sx;
    m->sy = sy;
    if (world != 0) {
        m->point = *world;
        m->has_point = 1;
    } else {
        m->has_point = 0;
    }
    if (kind == -1) {
        m->kind = 2;
        m->step = 1.5707964f; /* pi / 2 */
        m->shrink = 0;
    } else {
        m->kind = kind;
        m->step = step;
        m->shrink = 4;
    }
    D_L01_001E5180.count++;
}
/* localdecomp:end func_L01_003F6F20 */
