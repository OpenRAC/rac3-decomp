#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

typedef int Q __attribute__((mode(TI)));
typedef struct {u8 pad[0x30]; Q pos; u8 tail[0x40];} Rec;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 pad14[0xC];
    s32 ids[8];
    u8 quads[0x80];
} P_003AD358;

/* declared by functions of L19_003ADE70.c, which this file was cut from */
extern Rec *D_L19_001DF800_003AC268;
extern u8 D_1A30B0[];
extern void func_L19_003AE108(void *);
extern void func_L19_003AE5A8(void *);
extern int func_L01_004561B8(void *);
extern void func_003A4F28(int);

/* localdecomp:start func_L19_003AE108 */
#include "vu0.h"
extern s32 D_L19_001DF240;
extern vu0_v4 D_L19_001E8E60;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

/* the path points: D_L19_001DF800_003AC268 (the file's Rec view, reached through lui) and here
 * the same table through $gp, as retail reads it once */
typedef struct {
    u8 pad[0x30];
    vu0_v4 pos;
    u8 tail[0x40];
} R_003AE108;
__asm__(".extern D_L19_001DF800, 4");
extern R_003AE108 *D_L19_001DF800;

typedef struct {
    s32 mode;
    s32 period;
    s32 x8;
    s32 xC;
    s32 center;
    s32 x14;
    s32 flags;
    s32 phase;
    s32 a0;
    s32 a1;
    s32 b0;
    s32 b1;
    u8 pad30[0x10];
    vu0_v4 target;
} P_003AE108;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0x48];
    P_003AE108 *vars;
    u8 pad6C[0x84];
    f32 rot[3];
} M_003AE108;

/* bit 0 of the flags clear: the moby's own position follows the path */
static __inline__ s32 movespos_003AE108(P_003AE108 *p) {
    return !(*(u8 *)&p->flags & 1);
}

void func_L19_003AE108(void *arg) {
    M_003AE108 *o = arg;
    P_003AE108 *p = o->vars;
    vu0_v4 v[4];
    f32 t;
    s32 mode;

    t = (f32)((D_L19_001DF240 + p->phase) % p->period) / (f32)p->period;
    mode = p->mode;
    if (mode == 0) {
        t = func_0038D098((t - 0.5f) * 2.0f * 3.1415927f) * 0.5f + 0.5f;
        if (movespos_003AE108(p)) {
            vec_sub_ba(&v[0], &D_L19_001DF800_003AC268[p->a1].pos, &D_L19_001DF800_003AC268[p->a0].pos);
            func_0038CE20(&v[0], &v[0], t);
            vec_add_ab(&o->pos, &v[0], &D_L19_001DF800_003AC268[p->a0].pos);
        }
        if (!(p->flags & 2)) {
            vec_sub_ba(&v[0], &D_L19_001DF800_003AC268[p->b1].pos, &D_L19_001DF800_003AC268[p->b0].pos);
            func_0038CE20(&v[0], &v[0], t);
            vec_add_ab(&p->target, &v[0], &D_L19_001DF800_003AC268[p->b0].pos);
        }
        if (movespos_003AE108(p)) {
            vec_sub_ba(&v[0], &p->target, &o->pos);
            vec_sub_ab(&v[0], &o->pos, &v[0]);
            if (func_003D3CB0(&o->pos, &v[0], 2, o, 0)) {
                o->pos = D_L19_001E8E60;
            }
        }
    } else if (mode == 1) {
        f32 a = (t + t - 1.0f) * 3.1415927f;
        f32 s = func_0038D098(a);
        f32 c = func_0038D0B0(a);
        *(Q *)&v[0] = D_L19_001DF800_003AC268[p->center].pos;
        *(Q *)&v[1] = D_L19_001DF800_003AC268[p->a0].pos;
        *(Q *)&v[2] = D_L19_001DF800_003AC268[p->b0].pos;
        if (movespos_003AE108(p)) {
            vec_sub_ab(&v[3], &v[1], &v[0]);
            o->pos.x = v[0].x + (v[3].x * s - v[3].y * c);
            o->pos.y = v[0].y + (v[3].y * s + v[3].x * c);
        }
        if (!(p->flags & 2)) {
            vec_sub_ab(&v[3], &v[2], &v[0]);
            p->target.x = v[0].x + (v[3].x * s - v[3].y * c);
            p->target.y = v[0].y + (v[3].y * s + v[3].x * c);
        }
    } else if (mode == 2 || mode == 3) {
        if (func_L01_004561B8(o)) {
            vu0_v4 *pos = &o->pos;
            *(Q *)pos = D_L19_001DF800_003AC268[p->a0].pos;
            *(Q *)&p->target = D_L19_001DF800_003AC268[p->b0].pos;
            if (movespos_003AE108(p)) {
                vec_sub_ba(&v[0], &p->target, pos);
                vec_sub_ab(&v[0], pos, &v[0]);
                if (func_003D3CB0(pos, &v[0], 2, o, 0)) {
                    *pos = D_L19_001E8E60;
                }
            }
        }
    }
    if (!(p->flags & 4)) {
        o->rot[0] = -3.1415927f;
        o->rot[1] = -func_0038D160(func_0038CF38(&o->pos, &p->target), p->target.z - o->pos.z);
        if (func_L01_0040E570(&D_L19_001DF800_003AC268[p->a1].pos, &D_L19_001DF800_003AC268[p->a0].pos) > 0.0f) {
            R_003AE108 *r = D_L19_001DF800;
            o->rot[2] = func_0038D160(r[p->a0].pos.x - r[p->a1].pos.x, r[p->a0].pos.y - r[p->a1].pos.y);
        } else {
            o->rot[2] = func_0038D160(p->target.x - o->pos.x, p->target.y - o->pos.y);
        }
    }
}
/* localdecomp:end func_L19_003AE108 */

INCLUDE_ASM("asm/levels", func_L19_003AE5A8);
