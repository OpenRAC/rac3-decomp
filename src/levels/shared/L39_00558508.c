#include "common.h"

typedef struct Obj_00559980 {
    u8 pad0[0x10];
    u8 *ptr[5];
    u8 pad1[0xE0 - 0x24];
    u8 item[5][0x10];
} Obj_00559980;

/* declared by functions of L39_00557E48.c, which this file was cut from */
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DAB8(f32, f32);

/* localdecomp:start func_L39_00558508 */
#include "vu0.h"
extern f32 func_0038CF38(void *, void *);

f32 func_L39_00558508(void *a, void *b, f32 r) {
    vu0_v4 copy;
    vu0_v4 d;
    f32 dist;

    vec_sub_ab(&d, a, b);
    copy = d;
    dist = func_0038CF38(a, b);
    if (r * 3.0f < dist) {
        return 0.523598790f;
    }
    if (r * 1.5f < dist) {
        return 1.04719758f;
    }
    return 2.09439516f;
}
/* localdecomp:end func_L39_00558508 */

/* localdecomp:start func_L39_005585B0 */
#include "vu0.h"
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
s32 func_L39_005585B0(void *pa, void *pb, f32 r, f32 ang) {
    vu0_v4 *a = pa;
    vu0_v4 *b = pb;
    vu0_v4 diff;
    vu0_v4 tmp;
    f32 dist;
    f32 a1;
    f32 a2;
    f32 d0;
    f32 d1;
    f32 d2;

    vec_sub_ab(&tmp, a, b);
    diff = tmp;
    dist = func_0038CF38(a, b);
    if (r * 3.0f < dist) {
        r = r * 1.5f;
    } else if (!(r * 1.5f < dist)) {
        if (func_0038DBA0(func_0038D160(b->x - a->x, b->y - a->y), ang) >= 1.5707964f) return 0;
        return 1;
    } else {
        r = r + r;
    }
    tmp.x = -diff.y;
    tmp.y = diff.x;
    tmp.z = 0.0f;
    func_0038CF68(&tmp, &tmp, r);
    vec_add_ab(&tmp, &tmp, b);
    a1 = func_0038D160(tmp.x - a->x, tmp.y - a->y);
    tmp.x = diff.y;
    tmp.y = -diff.x;
    tmp.z = 0.0f;
    func_0038CF68(&tmp, &tmp, r);
    vec_add_ba(&tmp, &tmp, b);
    a2 = func_0038D160(tmp.x - a->x, tmp.y - a->y);
    d0 = func_0038DBA0(a1, a2);
    d1 = func_0038DBA0(a1, ang);
    d2 = func_0038DBA0(a2, ang);
    if (d2 < d1) d2 = d1;
    if (d2 < d0) return 1;
    return 0;
}
/* localdecomp:end func_L39_005585B0 */

/* localdecomp:start func_L39_005587D0 */
#include "vu0.h"
typedef struct { u8 p0[0x270]; f32 vx; f32 vy; } S_005587D0;
typedef struct { u8 p0[0xC]; f32 r; vu0_v4 pos; } O_005587D0;
extern S_005587D0 *func_L39_00668620(s32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038CE68();
extern f32 D_L39_0024B304;
__asm__(".extern D_L39_0024B304, 4");
f32 func_L39_005587D0(void *a0, void *a1, f32 ang) {
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

    s = func_L39_00668620((s32)b);
    if (s == 0) return 0.0f;
    if (func_0038CEA8(&s->vx) < 0.010000001f) return 0.0f;
    dir = func_0038D160(s->vx, s->vy);
    to = func_0038D160(a->pos.x - b->pos.x, a->pos.y - b->pos.y);
    dist = func_0038CF38(&b->pos, &a->pos);
    if (b->r * 3.0f < dist) {
        lim = 30.0f;
    } else if (b->r + b->r < dist) {
        lim = 60.0f;
    } else {
        lim = 90.0f;
    }
    if (func_0038DBA0(dir, to) < lim * 0.017453292f && dist < D_L39_0024B304) {
        perp.x = -s->vy;
        perp.y = s->vx;
        perp.z = 0.0f;
        vec_sub_ab(&tmp, &a->pos, &b->pos);
        diff = tmp;
        if (func_0038CE68(&s->vx, &perp) > 0.0f) {
            to = func_0038DB00(func_0038DAB8(to, 1.5707964f), ang);
        } else {
            to = func_0038DB00(func_0038DB00(to, -1.5707964f), ang);
        }
        return to;
    }
    return 0.0f;
}
/* localdecomp:end func_L39_005587D0 */
