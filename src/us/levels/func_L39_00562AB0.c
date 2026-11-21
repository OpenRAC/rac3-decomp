#include "common.h"

/* NTSC-U counterpart of func_L39_005635D0 (src/levels/shared/L39_00563370.c) */
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
extern f32 func_L01_004C5828(void);
extern void func_L39_005F0CE0(s32, s32, void *);
extern f32 D_L39_0024B628;
extern s32 D_L39_0024D790[] __attribute__((section(".sdata")));
extern s16 D_L39_0024D7D0[] __attribute__((section(".sdata")));

/* localdecomp:start func_L39_00562AB0 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x46];
    u8 kind;
} Info_005635D0;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[3];
    Info_005635D0 *info;
    u8 pad28[9];
    u8 b31;
    u8 pad32[0x36];
    void *vars;
    u8 pad6C[0x3E];
    s16 oclass;
    u8 padAC[0x34];
    u8 mE0[0x10];
} Moby_005635D0;

typedef struct {
    u8 pad0[0xA0];
    vu0_v4 pos;
    u8 padB0[0x2474];
    Moby_005635D0 *moby;
} Ship_005635D0;

typedef struct {
    f32 t;
    s16 timer;
    s16 pad6;
    s32 color;
    s32 handle;
    f32 hitTimer;
    s32 t14;
    s16 t18[4];
    s32 i20[4];
    u8 pad30[0x10];
    Ship_005635D0 *ship;
} Vars_005635D0;

typedef struct {
    u8 pad0[4];
    Moby_005635D0 *owner;
    u8 pad8[8];
    f32 x;
    f32 y;
    f32 z;
} PartSub_005635D0;

typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 pad3;
    s32 color;
    u8 pad8[4];
    f32 size;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    PartSub_005635D0 sub;
} Part_005635D0;

typedef struct {
    vu0_v4 dir;
    Moby_005635D0 *src;
    s32 flags;
    u8 b18;
    u8 b19;
    s16 oclass;
    s32 i1C;
    s32 i20;
} Hit_005635D0;

extern s32 D_L39_002412A8;
__asm__(".extern D_L39_002412A8, 16");
extern f32 D_L39_0024B614;
extern s32 D_L39_0024B624;
extern s32 D_L39_0024B658;
extern s32 D_L39_0024B5F8;
extern s32 D_L39_0024B5FC;
extern s32 D_L39_0024B600;
extern s32 D_L39_0024B604;
extern s32 D_L39_0024B640;
extern s32 D_L39_0024B644;
extern f32 D_L39_0024B648;
extern s32 D_L39_0024B64C;
extern f32 D_L39_0024B650;
typedef struct {
    u8 pad0[0xD0];
    u8 active;
    u8 padD1[0xB];
    u8 *owner;
} Slot_005635D0;
extern u8 D_L39_001FE1A0[];
extern void func_L39_005F0CE0(s32, s32, void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_L01_004C5828(void);
extern f32 D_L39_0024B628;
__asm__(".extern D_L39_0024B614, 4");
__asm__(".extern D_L39_0024B624, 4");
__asm__(".extern D_L39_0024B628, 4");
__asm__(".extern D_L39_0024B658, 4");
__asm__(".extern D_L39_0024B5F8, 4");
__asm__(".extern D_L39_0024B5FC, 4");
__asm__(".extern D_L39_0024B600, 4");
__asm__(".extern D_L39_0024B604, 4");
__asm__(".extern D_L39_0024B640, 4");
__asm__(".extern D_L39_0024B644, 4");
__asm__(".extern D_L39_0024B648, 4");
__asm__(".extern D_L39_0024B64C, 4");
__asm__(".extern D_L39_0024B650, 4");
extern s32 D_L39_0024D790[] __attribute__((section(".sdata")));
extern s16 D_L39_0024D7D0[] __attribute__((section(".sdata")));
extern s32 D_L39_0024D7B0_00562AB0[] __attribute__((section(".sdata")));
extern s16 D_L39_0024D7E0[] __attribute__((section(".sdata")));
extern s16 D_L39_0024D7F0_00562AB0[] __attribute__((section(".sdata")));
extern vu0_v4 D_L39_0024DF00;
extern u8 D_L39_00296918[];
extern Moby_005635D0 *D_L39_002638C0[];
extern vu0_v4 D_L39_003CD580[][10];

extern void func_L01_004C5800(void);
extern s32 func_L39_005F08A0(s32, s32);
extern void func_L39_005F0988(s32);
extern s32 func_L39_00564490(u8 *, f32);
extern void func_L01_003116F0(void);
extern void func_003BD360(void *);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_003883C8(void *);
extern s32 func_00388398(void *);
extern void func_003886E8(void *, void *, f32);
extern void func_003BDA38(s32, s32, u8 *);
extern s32 func_L39_005B24C8(s32, s32);
extern f32 func_L39_005B25C8_00562AB0(void);
extern void func_0037E4B8(void *, f32, f32, f32);
extern u8 *func_L01_00469378(u8 *a0, s32 a1, s32 a2, s32 a3);
extern s32 func_L01_0040BB20(void *);
extern s32 func_003CF790(void *, s32, void *, s32, f32);
extern u8 *func_0037E0B8(void *);
extern void func_L01_00443840(void *, void *);
extern void func_L01_00342DB8(void *, s32);
extern void func_0037E2F0(void *, f32, f32);
extern f32 func_L39_005B2510(f32, f32);
extern void func_00389158(void *, void *, void *, f32);
extern void func_L01_00402498(void *, void *);
extern void func_L39_00563240(u8 *);

static __inline__ void vcopy_005635D0(vu0_v4 *d, vu0_v4 *v)
{
    *d = *v;
}

void func_L39_00562AB0(u8 *arg0)
{
    Moby_005635D0 *self = (Moby_005635D0 *)arg0;
    Vars_005635D0 *v;
    s32 h;
    f32 t;
    s32 i;
    s32 j;
    s32 k;
    s32 b;
    Part_005635D0 *p;
    vu0_v4 off;
    vu0_v4 base;
    vu0_v4 pos;
    f32 f;
    u8 *g;

    v = self->vars;
    if (D_L39_002412A8 != 0) {
        return;
    }
    vcopy_005635D0(&self->pos, &v->ship->pos);
    func_L01_004C5800();
    if (D_L39_002412A8 == 0) {
        if (func_L39_005F08A0((s32)self, v->handle) == 0) {
            v->handle = ((s32 (*)(s32, s32, void *))func_L39_005F0CE0)(3, 4, self);
        }
    } else if (func_L39_005F08A0((s32)self, v->handle) != 0) {
        h = v->handle;
        if (h != -1 && ((Slot_005635D0 *)(D_L39_001FE1A0 + (h << 7)))->owner == (u8 *)self && ((Slot_005635D0 *)(D_L39_001FE1A0 + (h << 7)))->active != 0) {
            func_L39_005F0988(h);
        }
        v->handle = -1;
    }
    t = func_L01_004C5828();
    if (func_L39_00564490(arg0, t) == 0 || D_L39_0024B624 == 40) {
        h = v->handle;
        if (h != -1 && ((Slot_005635D0 *)(D_L39_001FE1A0 + (h << 7)))->owner == (u8 *)self && ((Slot_005635D0 *)(D_L39_001FE1A0 + (h << 7)))->active != 0) {
            func_L39_005F0988(h);
        }
        v->handle = -1;
        D_L39_0024B624 = 0;
        func_L01_003116F0();
        func_L39_005F0CE0(2, 0, self);
        func_003BD360(self);
        return;
    }
    if (t != v->t) {
        v->timer = D_L39_0024B658;
        v->t = t;
    }
    f = (f32)v->timer / (f32)(D_L39_0024B658);
    if (self->oclass == 0x1B37) {
        v->color = func_003894A0(D_L39_0024B5F8, D_L39_0024B5FC, f);
    } else {
        v->color = func_003894A0(D_L39_0024B600, D_L39_0024B604, f);
    }
    func_003883C8(&v->timer);
    func_003886E8(&off, v->ship->moby->mE0, 0.75f);
    vec_add_ba(&self->pos, &v->ship->pos, &off);
    func_003BDA38((s32)v->ship->moby, 10, (u8 *)&base);

    g = D_L39_00296918;
    for (i = 0; i < 8; i++) {
        if (((Part_005635D0 **)D_L39_0024D790)[i] == 0) {
            s32 n2 = func_L39_005B24C8(D_L39_0024B640, D_L39_0024B644);

            func_0037E4B8(&pos, D_L39_0024B628, func_L39_005B25C8_00562AB0(), func_L39_005B25C8_00562AB0());
            vec_add_ab(&pos, &pos, &base);
            p = ((Part_005635D0 **)D_L39_0024D790)[i] = (Part_005635D0 *)func_L01_00469378((u8 *)&pos, n2, 2, 1);
            if (p != 0) {
                PartSub_005635D0 *q = &p->sub;

                q->x = p->x - self->pos.x;
                q->y = p->y - self->pos.y;
                q->z = p->z - self->pos.z;
                q->owner = self;
                p->color = D_L39_0024B64C | v->color;
                p->size = D_L39_0024B648 * 210000.0f;
                p->b2 = (*(u8 **)(g + 0xF8))[1];
                D_L39_0024D7B0_00562AB0[i] = n2;
            }
            p = (Part_005635D0 *)func_L01_00469378((u8 *)&pos, n2, 2, 1);
            if (p != 0) {
                PartSub_005635D0 *q = &p->sub;

                q->x = p->x - self->pos.x;
                q->y = p->y - self->pos.y;
                q->z = p->z - self->pos.z;
                q->owner = self;
                p->color = 0x307F7F7F;
                p->size = D_L39_0024B648 * 210000.0f * 0.3f;
                p->b2 = (*(u8 **)(g + 0xF8))[1];
            }
        } else if (func_00388398(&D_L39_0024D7B0_00562AB0[i]) != 0) {
            ((Part_005635D0 **)D_L39_0024D790)[i] = 0;
        }
    }

    func_00388398(&v->t14);
    for (j = 0; j < 4; j++) {
        if (func_003883C8(&v->t18[j]) != 0) {
            v->i20[j] = 0;
        }
    }

    if (func_L01_0040BB20(&v->hitTimer) != 0) {
        s32 count = func_003CF790(&self->pos, 1, v->ship->moby, 0, D_L39_0024B614 * 0.3f);

        if (count != 0) {
            Hit_005635D0 hit;
            vu0_v4 a;
            vu0_v4 tip;

            hit.flags = 0x10000;
            hit.i20 = 1;
            hit.dir.w = 5627.9248f;
            hit.b18 = 3;
            hit.b19 = 2;
            hit.oclass = self->oclass;
            hit.src = self;
            hit.i1C = 0;
            for (k = 0; k < count; k++) {
                Moby_005635D0 *m = D_L39_002638C0[k];
                f32 *bs;

                if (m->b31 == 0 || m == 0 || m->state == 0xFE || m->state == 0xFD) {
                    continue;
                }
                if (m->info == 0 || m->info->kind != 5) {
                    continue;
                }
                bs = (f32 *)func_0037E0B8(m);
                if (bs != 0) {
                    if (bs[0] <= 0.0f) {
                        continue;
                    }
                    func_003886E8(&a, self->mE0, bs[4]);
                    vec_add_ab(&pos, &m->pos, &a);
                } else {
                    vcopy_005635D0(&pos, &m->pos);
                }
                vec_sub_ab(&hit.dir, &pos, &self->pos);
                func_00388830(&hit, &hit, 1.0f);
                func_L01_00443840(m, &hit);
                func_003886E8(&a, &hit, D_L39_0024B614 * 0.3f);
                vec_add_ba(&tip, &self->pos, &a);
                func_L01_00342DB8(&tip, v->color);
                v->hitTimer = 0.5f;
            }
        }
    }

    vcopy_005635D0(&pos, &base);
    for (b = 0; b < 5; b++) {
        if (func_003883C8(&D_L39_0024D7D0[b]) != 0) {
            D_L39_0024D7D0[b] = 0;
        }
        if (D_L39_0024D7D0[b] == 0) {
            vu0_v4 dir;
            vu0_v4 a;
            f32 sign;
            s32 n;

            s32 life = func_L39_005B24C8(3, 0x2D);

            sign = 1.0f;
            D_L39_0024D7D0[b] = life;
            D_L39_0024D7F0_00562AB0[b] = life;
            D_L39_0024D7E0[b] = 0x40;
            func_0037E2F0(&dir, D_L39_0024B650, D_L39_0024B650);
            vcopy_005635D0(&D_L39_003CD580[b][0], &pos);
            D_L39_003CD580[b][0].w = 0.04f;
            for (n = 1; n < 10; n++) {
                vec_sub_ab(&a, &D_L39_003CD580[b][n - 1], &D_L39_0024DF00);
                func_00389158(&dir, &dir, &a, func_L39_005B2510(0.08726646f, 1.3089969f) * sign);
                sign = -sign;
                vec_add_ab(&D_L39_003CD580[b][n], &D_L39_003CD580[b][n - 1], &dir);
                D_L39_003CD580[b][n].w = 0.04f;
            }
        }
    }
    func_L01_00402498(func_L39_00563240, arg0);
}
/* localdecomp:end func_L39_00562AB0 */
