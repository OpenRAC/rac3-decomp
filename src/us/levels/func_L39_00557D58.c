#include "common.h"

/* NTSC-U counterpart of func_L39_005587D0 (src/levels/shared/L39_00558508.c): 0.01 -> 0.00833333 */
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern f32 func_00389380(f32, f32);
#include "vu0.h"
extern f32 func_00388800(void *, void *);
#include "vu0.h"
extern f32 func_00388800(void *, void *);

/* localdecomp:start func_L39_00557D58 */
#include "vu0.h"
typedef struct { u8 p0[0x270]; f32 vx; f32 vy; } S_005587D0;
typedef struct { u8 p0[0xC]; f32 r; vu0_v4 pos; } O_005587D0;
extern S_005587D0 *func_L39_00665D48(s32);
extern f32 func_00388770(void *);
extern f32 func_00388800(void *, void *);
extern f32 func_003893C8(f32, f32);
extern f32 func_00388730();
extern f32 D_L39_0024B414;
__asm__(".extern D_L39_0024B414, 4");
f32 func_L39_00557D58(void *a0, void *a1, f32 ang) {
    O_005587D0 *a = a0;
    O_005587D0 *b = a1;
    S_005587D0 *s;
    f32 dir;
    f32 to;
    f32 dist;
    f32 lim;
    vu0_v4 perp;
    vu0_v4 diff;
    vu0_v4 tmp;

    s = func_L39_00665D48((s32)b);
    if (s == 0) return 0.0f;
    if (func_00388770(&s->vx) < 0.00833333377f) return 0.0f;
    dir = func_00388A28(s->vx, s->vy);
    to = func_00388A28(a->pos.x - b->pos.x, a->pos.y - b->pos.y);
    dist = func_00388800(&b->pos, &a->pos);
    if (b->r * 3.0f < dist) {
        lim = 30.0f;
    } else if (b->r + b->r < dist) {
        lim = 60.0f;
    } else {
        lim = 90.0f;
    }
    if (func_00389468(dir, to) < lim * 0.017453292f && dist < D_L39_0024B414) {
        perp.x = -s->vy;
        perp.y = s->vx;
        perp.z = 0.0f;
        vec_sub_ab(&tmp, &a->pos, &b->pos);
        diff = tmp;
        if (func_00388730(&s->vx, &perp) > 0.0f) {
            to = func_003893C8(func_00389380(to, 1.5707964f), ang);
        } else {
            to = func_003893C8(func_003893C8(to, -1.5707964f), ang);
        }
        return to;
    }
    return 0.0f;
}
/* localdecomp:end func_L39_00557D58 */
