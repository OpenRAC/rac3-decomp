#include "common.h"

/* localdecomp:start func_L39_00563370 */
#include "vu0.h"

extern u8 *func_003C24B0(s32, s32);
extern void func_0038D308(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_L01_004C93E0(s32);
extern f32 func_L01_004C93D8(void);
extern void func_L39_005F33E0(s32, s32, void *);
extern f32 D_L39_0024B518;
__asm__(".extern D_L39_0024B518, 4");
extern f32 D_L39_0024D714;
extern u8 D_L39_003CCF80[];
extern vu0_v4 D_L39_0024D640 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024D640, 16");
extern vu0_v4 D_L39_0024D650 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024D650, 16");
extern vu0_v4 D_L39_0024D660 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024D660, 16");
extern u8 D_L39_0024D670[] __attribute__((section(".sdata")));
extern s32 D_L39_0024D680[] __attribute__((section(".sdata")));
extern s32 D_L39_0024D690[] __attribute__((section(".sdata")));
extern s16 D_L39_0024D6D0[] __attribute__((section(".sdata")));

typedef struct {
    f32 f0;
    s32 pad4[2];
    s32 fC;
    s32 f10;
    s32 f14;
    s16 a18[4];
    s32 a20[4];
    s32 pad30[4];
    u8 *f40;
} V_00563370;

u8 *func_L39_00563370(u8 *arg0)
{
    u8 *m;
    V_00563370 *v;
    u8 *b;
    vu0_v4 *r2;

    m = func_003C24B0(0x1B37, 0x80);
    if (m != 0) {
        v = *(V_00563370 **)(m + 0x68);
        v->f40 = arg0;
        m[0x30] = 0xFF;
        m[0x20] = 1;
        *(u16 *)(m + 0x34) |= 0x41;
        func_0038D308(m + 0xC0, m + 0xF0);
        {
            s32 j;

            for (j = 3; j >= 0; j--) {
                D_L39_0024D680[j] = 0;
            }
        }
        b = D_L39_003CCF80;
        func_0038CF68(b, m + 0xC0, D_L39_0024B518);
        r2 = (vu0_v4 *)(m + 0xE0);
        D_L39_0024D640 = *r2;
        func_0038CF68(b + 0x140, m + 0xD0, D_L39_0024B518);
        D_L39_0024D650 = *(vu0_v4 *)(m + 0xC0);
        func_0038CF68(b + 0x280, r2, D_L39_0024B518);
        D_L39_0024D660 = *(vu0_v4 *)(m + 0xD0);
        vec_add_ba(b + 0x3C0, m + 0xC0, r2);
        func_0038CF68(b + 0x3C0, b + 0x3C0, D_L39_0024B518);
        func_0038CE90(D_L39_0024D670, b + 0x3C0, m + 0xD0);
        {
            s32 j;

            for (j = 7; j >= 0; j--) {
                D_L39_0024D690[j] = 0;
            }
        }
        {
            s32 j;

            for (j = 4; j >= 0; j--) {
                D_L39_0024D6D0[j] = 0;
            }
        }
        D_L39_0024D714 = 1.0f;
        func_L01_004C93E0(0);
        v->f0 = func_L01_004C93D8();
        *(vu0_v4 *)(m + 0x10) = *(vu0_v4 *)(v->f40 + 0xA0);
        v->fC = -1;
        v->f10 = 0;
        v->f14 = 0x19;
        {
            s32 j;

            for (j = 3; j >= 0; j--) {
                v->a18[j] = 0;
            }
        }
        {
            s32 j;

            for (j = 3; j >= 0; j--) {
                v->a20[j] = 0;
            }
        }
        func_L39_005F33E0(1, 0, m);
    }
    return m;
}
/* localdecomp:end func_L39_00563370 */

/* localdecomp:start func_L39_005635D0 */
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

extern s32 D_L39_00241128;
__asm__(".extern D_L39_00241128, 16");
extern f32 D_L39_0024B504;
extern s32 D_L39_0024B514;
extern s32 D_L39_0024B548;
extern s32 D_L39_0024B4E8;
extern s32 D_L39_0024B4EC;
extern s32 D_L39_0024B4F0;
extern s32 D_L39_0024B4F4;
extern s32 D_L39_0024B530;
extern s32 D_L39_0024B534;
extern f32 D_L39_0024B538;
extern s32 D_L39_0024B53C;
extern f32 D_L39_0024B540;
typedef struct {
    u8 pad0[0xD0];
    u8 active;
    u8 padD1[0xB];
    u8 *owner;
} Slot_005635D0;
extern u8 D_001FE020[];
extern void func_L39_005F33E0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_004C93D8(void);
extern f32 D_L39_0024B518;
__asm__(".extern D_L39_0024B504, 4");
__asm__(".extern D_L39_0024B514, 4");
__asm__(".extern D_L39_0024B518, 4");
__asm__(".extern D_L39_0024B548, 4");
__asm__(".extern D_L39_0024B4E8, 4");
__asm__(".extern D_L39_0024B4EC, 4");
__asm__(".extern D_L39_0024B4F0, 4");
__asm__(".extern D_L39_0024B4F4, 4");
__asm__(".extern D_L39_0024B530, 4");
__asm__(".extern D_L39_0024B534, 4");
__asm__(".extern D_L39_0024B538, 4");
__asm__(".extern D_L39_0024B53C, 4");
__asm__(".extern D_L39_0024B540, 4");
extern s32 D_L39_0024D690[] __attribute__((section(".sdata")));
extern s16 D_L39_0024D6D0[] __attribute__((section(".sdata")));
extern s32 D_L39_0024D6B0[] __attribute__((section(".sdata")));
extern s16 D_L39_0024D6E0[] __attribute__((section(".sdata")));
extern s16 D_L39_0024D6F0[] __attribute__((section(".sdata")));
extern vu0_v4 D_L39_0024DE00;
extern u8 D_L39_00296818[];
extern Moby_005635D0 *D_L39_002637C0[];
extern vu0_v4 D_L39_003CD480[][10];

extern void func_L01_004C93B0(void);
extern s32 func_L39_005F2FA0(s32, s32);
extern void func_L39_005F3088(s32);
extern s32 func_L39_00565008(u8 *, f32);
extern void func_L01_003119E0(void);
extern void func_003C2880(void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_0038CB00(void *);
extern s32 func_0038CAD0(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C2F58(s32, s32, u8 *);
extern s32 func_L39_005B43C8(s32, s32);
extern f32 func_L39_005B44C8(void);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L01_0046CA28(u8 *a0, s32 a1, s32 a2, s32 a3);
extern s32 func_L01_0040E050(void *);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern u8 *func_00382348(void *);
extern void func_L01_00446978(void *, void *);
extern void func_L01_00343658(void *, s32);
extern void func_00382580(void *, f32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_L01_00404808(void *, void *);
extern void func_L39_00563DB8(u8 *);

static __inline__ void vcopy_005635D0(vu0_v4 *d, vu0_v4 *v)
{
    *d = *v;
}

void func_L39_005635D0(u8 *arg0)
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
    if (D_L39_00241128 != 0) {
        return;
    }
    vcopy_005635D0(&self->pos, &v->ship->pos);
    func_L01_004C93B0();
    if (D_L39_00241128 == 0) {
        if (func_L39_005F2FA0((s32)self, v->handle) == 0) {
            v->handle = ((s32 (*)(s32, s32, void *))func_L39_005F33E0)(3, 4, self);
        }
    } else if (func_L39_005F2FA0((s32)self, v->handle) != 0) {
        h = v->handle;
        if (h != -1 && ((Slot_005635D0 *)(D_001FE020 + (h << 7)))->owner == (u8 *)self && ((Slot_005635D0 *)(D_001FE020 + (h << 7)))->active != 0) {
            func_L39_005F3088(h);
        }
        v->handle = -1;
    }
    t = func_L01_004C93D8();
    if (func_L39_00565008(arg0, t) == 0 || D_L39_0024B514 == 40) {
        h = v->handle;
        if (h != -1 && ((Slot_005635D0 *)(D_001FE020 + (h << 7)))->owner == (u8 *)self && ((Slot_005635D0 *)(D_001FE020 + (h << 7)))->active != 0) {
            func_L39_005F3088(h);
        }
        v->handle = -1;
        D_L39_0024B514 = 0;
        func_L01_003119E0();
        func_L39_005F33E0(2, 0, self);
        func_003C2880(self);
        return;
    }
    if (t != v->t) {
        v->timer = (D_L39_0024B548 * 5 + 2) / 6;
        v->t = t;
    }
    f = (f32)v->timer / (f32)((D_L39_0024B548 * 5 + 2) / 6);
    if (self->oclass == 0x1B37) {
        v->color = func_0038DBD8(D_L39_0024B4E8, D_L39_0024B4EC, f);
    } else {
        v->color = func_0038DBD8(D_L39_0024B4F0, D_L39_0024B4F4, f);
    }
    func_0038CB00(&v->timer);
    func_0038CE20(&off, v->ship->moby->mE0, 0.75f);
    vec_add_ba(&self->pos, &v->ship->pos, &off);
    func_003C2F58((s32)v->ship->moby, 10, (u8 *)&base);

    g = D_L39_00296818;
    for (i = 0; i < 8; i++) {
        if (((Part_005635D0 **)D_L39_0024D690)[i] == 0) {
            s32 n2 = (func_L39_005B43C8(D_L39_0024B530, D_L39_0024B534) * 5 + 2) / 6;

            func_00382760(&pos, D_L39_0024B518, func_L39_005B44C8(), func_L39_005B44C8());
            vec_add_ab(&pos, &pos, &base);
            p = ((Part_005635D0 **)D_L39_0024D690)[i] = (Part_005635D0 *)func_L01_0046CA28((u8 *)&pos, n2, 2, 1);
            if (p != 0) {
                PartSub_005635D0 *q = &p->sub;

                q->x = p->x - self->pos.x;
                q->y = p->y - self->pos.y;
                q->z = p->z - self->pos.z;
                q->owner = self;
                p->color = D_L39_0024B53C | v->color;
                p->size = D_L39_0024B538 * 210000.0f;
                p->b2 = (*(u8 **)(g + 0xF8))[1];
                D_L39_0024D6B0[i] = n2;
            }
            p = (Part_005635D0 *)func_L01_0046CA28((u8 *)&pos, n2, 2, 1);
            if (p != 0) {
                PartSub_005635D0 *q = &p->sub;

                q->x = p->x - self->pos.x;
                q->y = p->y - self->pos.y;
                q->z = p->z - self->pos.z;
                q->owner = self;
                p->color = 0x307F7F7F;
                p->size = D_L39_0024B538 * 210000.0f * 0.3f;
                p->b2 = (*(u8 **)(g + 0xF8))[1];
            }
        } else if (func_0038CAD0(&D_L39_0024D6B0[i]) != 0) {
            ((Part_005635D0 **)D_L39_0024D690)[i] = 0;
        }
    }

    func_0038CAD0(&v->t14);
    for (j = 0; j < 4; j++) {
        if (func_0038CB00(&v->t18[j]) != 0) {
            v->i20[j] = 0;
        }
    }

    if (func_L01_0040E050(&v->hitTimer) != 0) {
        s32 count = func_003D4D00(&self->pos, 1, v->ship->moby, 0, D_L39_0024B504 * 0.3f);

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
                Moby_005635D0 *m = D_L39_002637C0[k];
                f32 *bs;

                if (m->b31 == 0 || m == 0 || m->state == 0xFE || m->state == 0xFD) {
                    continue;
                }
                if (m->info == 0 || m->info->kind != 5) {
                    continue;
                }
                bs = (f32 *)func_00382348(m);
                if (bs != 0) {
                    if (bs[0] <= 0.0f) {
                        continue;
                    }
                    func_0038CE20(&a, self->mE0, bs[4]);
                    vec_add_ab(&pos, &m->pos, &a);
                } else {
                    vcopy_005635D0(&pos, &m->pos);
                }
                vec_sub_ab(&hit.dir, &pos, &self->pos);
                func_0038CF68(&hit, &hit, 1.0f);
                func_L01_00446978(m, &hit);
                func_0038CE20(&a, &hit, D_L39_0024B504 * 0.3f);
                vec_add_ba(&tip, &self->pos, &a);
                func_L01_00343658(&tip, v->color);
                v->hitTimer = 0.5f;
            }
        }
    }

    vcopy_005635D0(&pos, &base);
    for (b = 0; b < 5; b++) {
        if (func_0038CB00(&D_L39_0024D6D0[b]) != 0) {
            D_L39_0024D6D0[b] = 0;
        }
        if (D_L39_0024D6D0[b] == 0) {
            vu0_v4 dir;
            vu0_v4 a;
            f32 sign;
            s32 n;

            s32 life = (func_L39_005B43C8(3, 0x2D) * 5 + 2) / 6;

            sign = 1.0f;
            D_L39_0024D6D0[b] = life;
            D_L39_0024D6F0[b] = life;
            D_L39_0024D6E0[b] = 0x40;
            func_00382580(&dir, D_L39_0024B540, D_L39_0024B540);
            vcopy_005635D0(&D_L39_003CD480[b][0], &pos);
            D_L39_003CD480[b][0].w = 0.04f;
            for (n = 1; n < 10; n++) {
                vec_sub_ab(&a, &D_L39_003CD480[b][n - 1], &D_L39_0024DE00);
                func_0038D890(&dir, &dir, &a, func_L39_005B4410(0.08726646f, 1.3089969f) * sign);
                sign = -sign;
                vec_add_ab(&D_L39_003CD480[b][n], &D_L39_003CD480[b][n - 1], &dir);
                D_L39_003CD480[b][n].w = 0.04f;
            }
        }
    }
    func_L01_00404808(func_L39_00563DB8, arg0);
}
/* localdecomp:end func_L39_005635D0 */
