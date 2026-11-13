#include "common.h"

/* declared by functions of L40_003DA2D0.c, which this file was cut from */
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);

/* localdecomp:start func_L40_003DA6A8 */
#include "vu0.h"

extern void func_0038CE20(void *, void *, f32);
extern void func_003C5278(void *, void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern s32 func_L39_005B43C8(s32, s32);

typedef struct { f32 x, y, z; } Vec3_003DA6A8;
typedef struct {
    u8 pad0[0x1C];
    s16 t0;
    s16 t1;
} S_003DA6A8;

void func_L40_003DA6A8(s32 arg0, u8 *a1) {
    u8 *a0 = (u8 *)arg0;
    vu0_v4 side;
    vu0_v4 off;
    vu0_v4 dir;
    vu0_v4 base;
    vu0_v4 up;
    vu0_v4 half;
    vu0_v4 pos;
    u8 *vars;
    u8 **pp;
    u8 *p;
    S_003DA6A8 *q;
    Vec3_003DA6A8 *src;
    Vec3_003DA6A8 *d;
    Vec3_003DA6A8 *e;
    s32 i;
    s32 r;

    vars = *(u8 **)(a0 + 0x68);
    *(u8 **)(vars + 0x4C) = a1;
    a0[0x20] = 3;
    *(s16 *)(vars + 0x40) = 250;
    func_0038CE20(&base, a1 + 0x250, -0.75f);
    vec_add_ba(&base, a1 + 0xA0, &base);
    func_0038CE20(&side, a1 + 0x250, -5.0f);
    vec_sub_ab(&dir, &base, a0 + 0x10);
    func_003C5278(a0 + 0x10, &dir, &dir, 0.5f);
    func_0038CE90(&up, &dir, &side);
    func_0038CE90(&side, &up, &dir);
    func_0038D890(&side, &side, &dir, -1.5707964f);
    func_0038CF68(&side, &side, 5.0f);
    func_0038CE20(&half, &dir, 0.5f);
    a0[0x30] = 0xFF;
    pp = (u8 **)(vars + 0x30);
    for (i = 0; i < 4; i++, pp++) {
        p = *pp;
        if (p != 0) {
            q = (S_003DA6A8 *)(p + 0x20);
            func_0038D890(&off, &side, &dir, i * 0.44854963f);
            vec_add_ab(&pos, &half, &off);
            d = (Vec3_003DA6A8 *)(p + 0x24);
            d->x = pos.x;
            d->y = pos.y;
            d->z = pos.z;
            e = (Vec3_003DA6A8 *)(p + 0x30);
            src = (Vec3_003DA6A8 *)(*pp + 0x10);
            e->x = src->x;
            e->y = src->y;
            e->z = src->z;
            r = (func_L39_005B43C8(20, 80) * 5 + 2) / 6;
            q->t0 = r;
            q->t1 = r;
        }
    }
}
/* localdecomp:end func_L40_003DA6A8 */
