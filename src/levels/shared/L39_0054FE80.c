#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0054FE80);

/* localdecomp:start func_L39_00550358 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00550358;

typedef struct {
    f32 x, y, z;
} V3_00550358;

typedef struct {
    u8 pad0[2];
    u8 flags;
    u8 kind;
    s32 w4;
    u32 color;
    V3_00550358 pos;
    V3_00550358 dir;
} Out_00550358;

typedef struct {
    u8 pad0[0x3B0];
    V4_00550358 v3B0;
    u8 pad3C0[0x1180 - 0x3C0];
    V4_00550358 v1180;
    u8 pad1190[0x11A0 - 0x1190];
    V4_00550358 v11A0;
    u8 pad11B0[0x11C0 - 0x11B0];
    V4_00550358 v11C0;
    u8 pad11D0[0x122C - 0x11D0];
    s32 w122C;
    u8 pad1230[0x1250 - 0x1230];
    f32 f1250;
    u8 pad1254[0x12B0 - 0x1254];
    V4_00550358 v12B0;
    u8 pad12C0[0x1310 - 0x12C0];
    s32 w1310;
    u8 pad1314[0x19E4 - 0x1314];
    u8 b19E4;
    u8 pad19E5[0x1A08 - 0x19E5];
    u8 b1A08;
} G_00550358;

typedef struct {
    u8 pad0[0x30];
    s32 w30;
    u8 pad34[0x3C - 0x34];
    G_00550358 *g;
} H_00550358;

typedef struct {
    u8 pad0[0x68];
    H_00550358 *h;
    u8 pad6C[0xD0 - 0x6C];
    V4_00550358 vD0;
} Obj_00550358;

extern u8 D_L39_004997E0[];
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_003C2F58(void *, s32, void *);
extern u32 *func_L39_0061D7B0(s32);

void func_L39_00550358(Obj_00550358 *a0, Out_00550358 *a1) {
    H_00550358 *h;
    G_00550358 *g;
    V4_00550358 pos;
    V4_00550358 tmp;
    s32 x;
    V3_00550358 *pp;

    h = a0->h;
    a1->color = 0xFFFFFFFF;
    a1->w4 = -1;
    a1->flags |= 0x40;
    if (a1->kind != 8)
        return;
    if (h->g != 0 && ({
            u8 *p = &h->g->b19E4;
            u8 *b;
            s32 m;
            s32 k;
            s32 n;
            s32 i;

            if (*p == 0) {
                x = 0;
            } else {
                n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)&tmp;
                for (i = 0; i < 40; i += 5) {
                    *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                ((u32 *)&tmp)[0] ^= (u32)p;
                ((u32 *)&tmp)[1] ^= ((u32 *)&tmp)[0];
                x = ((u32 *)&tmp)[1];
            }
            x ^ 0x1D;
        }) == 0) {
        V4_00550358 b __attribute__((aligned(16)));
        V4_00550358 *q;

        pos = h->g->v1180;
        g = h->g;
        q = &g->v11A0;
        func_0038CE20(&tmp, &g->v11C0, -0.2f);
        func_0038CE20(&b, q, 0.1f);
        vec_add_ba(&pos, &pos, &b);
        vec_add_ab(&pos, &pos, &tmp);
        a1->flags |= 0x80;
    } else {
        func_003C2F58(a0, 0, &pos);
    }
    pp = &a1->pos;
    pp->x = pos.x;
    pp->y = pos.y;
    pp->z = pos.z;
    {
        G_00550358 *gg = h->g;

        if (gg != 0 && gg->b1A08 != 0) {
            func_0038CF68(&tmp, &a0->vD0, -1.0f);
            {
                V3_00550358 *dp = &a1->dir;

                dp->x = tmp.x;
                dp->y = tmp.y;
                dp->z = tmp.z;
            }
        } else if (gg != 0 && gg->w1310 != 0) {
            if (gg->w122C != 0) {
                u32 *e = func_L39_0061D7B0(h->w30);
                if (e != 0 && 1.0f <= h->g->f1250)
                    a1->color = *e;
            }
            vec_sub_ba(&tmp, &h->g->v12B0, &pos);
            func_0038CF68(&tmp, &tmp, 1.0f);
            if (func_0038CE68(&tmp, &h->g->v3B0) < 0.5f) {
                V4_00550358 *v = &h->g->v3B0;
                V3_00550358 *dp = &a1->dir;

                dp->x = v->x;
                dp->y = v->y;
                dp->z = v->z;
            } else {
                V3_00550358 *dp = &a1->dir;

                dp->x = tmp.x;
                dp->y = tmp.y;
                dp->z = tmp.z;
            }
        } else {
            func_0038CE20(&tmp, &a0->vD0, -1.0f);
            {
                V3_00550358 *dp = &a1->dir;

                dp->x = tmp.x;
                dp->y = tmp.y;
                dp->z = tmp.z;
            }
        }
    }
}
/* localdecomp:end func_L39_00550358 */
