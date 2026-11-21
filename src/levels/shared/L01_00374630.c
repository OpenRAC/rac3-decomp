#include "common.h"

/* localdecomp:start func_L01_00374630 */
extern s32 func_0038CAD0(void *);
extern void func_L01_003743C8(void *);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L01_00374630(u8 *obj) {
    u8 *v = *(u8 **)(obj + 104);
    u8 *m;

    if (func_0038CAD0(v + 84) != 0) {
        return;
    }
    func_L01_003743C8(obj);
    func_L01_003743C8(obj);
    m = v + 16;
    func_003D9508(m, 49, 0x3F204090, 1, 0.9f, 0.0f, func_00382538());
    func_003D9508(m, 49, 0x3F204090, 1, 0.9f, 0.0f, func_00382538());
    func_003D9508(m, 11, 0x3F204090, 1, 0.9f, 0.08f, 0.0f);
    func_003D9508(m, 65, 0x3F909090, 1, 1.0f, 0.0f, func_003824E0(30.0f, 60.0f) * 0.017453292f);
}
/* localdecomp:end func_L01_00374630 */

LINKER_REMNANT("asm/levels", func_L01_00374770);

/* localdecomp:start func_L01_00374790 */
typedef int u128_374790 __attribute__((mode(TI)));

typedef struct {
    f32 dir_pos[4];   /* 0x00 */
    f32 pad10[4];
    u128_374790 color;     /* 0x20 */
    f32 f30;
    s32 x34;
    void *owner;      /* 0x38 */
    u8 pad3c[0x4C - 0x3C];
    s32 x4c;
    u8 pad50[4];
    s32 x54;
    u8 pad58[4];
    s32 x5c;
    u8 pad60[4];
    s32 x64;
    f32 size;         /* 0x68 */
    s32 x6c;
    f32 x70;
    f32 x74;
    s32 x78;
    s32 x7c;
    s32 x80;
    u8 pad84[8];
    s32 x8c;
    f32 f90;
    s32 x94;
} R_374790;

typedef struct {
    u8 pad0[0x10];
    u128_374790 pos;       /* 0x10 */
    u8 x20;
    u8 pad21[0xF];
    u8 x30;
    u8 pad31;
    s16 x32;
    u16 flags;        /* 0x34 */
    u8 pad36[0x68 - 0x36];
    R_374790 *state;  /* 0x68 */
    u8 pad6c[0x98 - 0x6C];
    s32 x98;
} M_374790;

extern u8 *func_003C24B0(s32, s32);
extern f32 func_00382538(void);
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CF68(f32, void *, void *);
extern s32 func_L01_004C85C8(void *, f32, f32, f32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_004AA7E8(void *, s32);
typedef struct { s32 w[0x2900 / 4]; } Hw_374790;
extern Hw_374790 D_001A4BE0;

/* rift_spawn: spawn the Rift Inducer's rift (class 0x186B) from the gun */
M_374790 *func_L01_00374790(void *owner, u128_374790 *pos, u128_374790 *dir, f32 size) {
    M_374790 *m = (M_374790 *)func_003C24B0(0x186B, 0x700);
    R_374790 *r;
    u128_374790 *mpos;
    u128_374790 col;

    if (m != 0) {
        m->x20 = 0;
        m->x32 = 0xFF;
        m->x30 = 0xFF;
        mpos = &m->pos;
        r = m->state;
        m->pos = *pos;
        *(u128_374790 *)r = *dir;
        r->owner = owner;
        r->f30 = func_00382538();
        r->x34 = 0;
        func_L01_004C7D98(mpos, &r->pad10);
        func_0038CF68(0.1f, &r->pad10, &r->pad10);
        col = *(u128_374790 *)((u8 *)D_001A4BE0.w[0x25C0 / 4] + 0xD0);
        r->size = size;
        r->x4c = 0;
        r->x54 = 0;
        r->x5c = 0;
        r->x78 = 0;
        r->x7c = 0;
        r->x80 = 0;
        r->x64 = -1;
        r->x70 = 2.25f;
        r->x74 = 2.25f;
        r->x6c = -1;
        r->color = col;
        r->x8c = func_L01_004C85C8(m, 1.0f, 1.0f, 1.0f, 0);
        r->f90 = func_003824E0(7.0f, 23.0f);
        r->x94 = 0;
        m->x98 = 0;
        m->flags = (m->flags | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
    }
    return m;
}
/* localdecomp:end func_L01_00374790 */

/* localdecomp:start func_L01_00374908 */
typedef struct S_3738B0 S_3738B0;

typedef struct {
    u8 pad0[0x54];
    S_3738B0 *w54;
} S_3738B0m;

struct S_3738B0 {
    u8 pad0[0x10];
    f32 pos[4];
    u8 pad20[0x68 - 0x20];
    S_3738B0m *p68;
};

/* the six rift slots are reached from the first one: a scalar here, so the compiler leaves its address to the assembler (lui/addiu in one register) */
extern S_3738B0 *D_L01_001E10E0;
extern f32 func_L01_0040E548(f32 *a0, f32 *a1);

void func_L01_00374908(S_3738B0 *a0, S_3738B0 *a1) {
    S_3738B0m *m;
    S_3738B0m *q;
    S_3738B0 **pp;
    f32 d;
    s32 i;

    if (a0 == 0 || a1 == 0) {
        return;
    }
    m = a0->p68;
    for (i = 0; i < 6; i++) {
        pp = &D_L01_001E10E0 + i;
        if (*pp == 0) {
            continue;
        }
        q = (*pp)->p68;
        if (q == 0 || q->w54 != a1) {
            continue;
        }
        if (m == 0) {
            return;
        }
        d = func_L01_0040E548(a0->pos, a1->pos);
        if (d < func_L01_0040E548((*pp)->pos, a1->pos)) {
            m->w54 = a1;
            q->w54 = 0;
        }
        return;
    }
    m->w54 = a1;
}
/* localdecomp:end func_L01_00374908 */

INCLUDE_ASM("asm/levels", func_L01_003749E8);

LINKER_REMNANT("asm/levels", func_L01_00376170);

INCLUDE_ASM("asm/levels", func_L01_00376178);

INCLUDE_ASM("asm/levels", func_L01_00376490);

INCLUDE_ASM("asm/levels", func_L01_00376D08);

/* localdecomp:start func_L01_003770A8 */
__asm__(".extern D_L01_001DDAD4, 4");
__asm__(".extern D_L01_001DDAE0, 4");
__asm__(".extern D_L01_001DDAEC, 4");
__asm__(".extern D_L01_001DDAE4, 4");
__asm__(".extern D_L01_001DDAF0, 4");
__asm__(".extern D_L01_001DDAE8, 4");
__asm__(".extern D_L01_001DDAF4, 4");
__asm__(".extern D_L01_001DDAF8, 4");

typedef struct {
    u8 pad0[0x10];
    f32 pos[4];       /* 0x10 */
    u8 pad20[0x68 - 0x20];
    u8 *state;        /* 0x68 */
} M_3770A8;

extern f32 D_L01_001DDAD4;   /* spin of the first billboard, degrees a frame */
extern f32 D_L01_001DDAE0;
extern f32 D_L01_001DDAEC;
extern f32 D_L01_001DDAE4;
extern f32 D_L01_001DDAF0;
extern f32 D_L01_001DDAE8;
extern f32 D_L01_001DDAF4;
extern f32 D_L01_001DDAF8;   /* the drawn size */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern void func_L01_0040AAC8(void *, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32);

/* rift_flight_draw: the rift's in-flight draw within 96 u of the view */
void func_L01_003770A8(M_3770A8 *obj) {
    f32 *q = obj->pos;
    f32 *st = (f32 *)obj->state;
    f32 s;
    f32 r;

    st[12] = func_0038DAB8(st[12], D_L01_001DDAD4 * 0.017453292f);
    D_L01_001DDAE0 = func_0038DAB8(D_L01_001DDAE0, func_003824E0(-0.5f, -1.0f) * 0.017453292f);
    D_L01_001DDAEC = func_0038DAB8(D_L01_001DDAEC, func_003824E0(-1.0f, -2.0f) * 0.017453292f);
    D_L01_001DDAE4 = func_0038DAB8(D_L01_001DDAE4, func_003824E0(-1.0f, -1.5f) * 0.017453292f);
    D_L01_001DDAF0 = func_0038DAB8(D_L01_001DDAF0, func_003824E0(-1.5f, -2.5f) * 0.017453292f);
    D_L01_001DDAE8 = func_0038DAB8(D_L01_001DDAE8, func_003824E0(-0.5f, -1.5f) * 0.017453292f);
    D_L01_001DDAF4 = func_0038DAB8(D_L01_001DDAF4, func_003824E0(-0.5f, -1.5f) * 0.017453292f);
    func_003D9508(q, 76, 0x6FFF4040, 1, D_L01_001DDAF8 * 1.2f, 0.01f, D_L01_001DDAF0);
    func_003D9508(q, 76, 0x7FFF0032, 1, D_L01_001DDAF8 * 0.7f, 0.01f, -D_L01_001DDAEC);
    func_003D9508(q, 76, 0x7F701010, 1, D_L01_001DDAF8 * 0.2f, 0.01f, D_L01_001DDAEC);
    func_003D9508(q, 75, 0x7F204080, 1, D_L01_001DDAF8 * 0.7f, 0.01f, D_L01_001DDAF0);
    func_L01_0040AAC8(q, 71, 72, 0x4FFF0032, 0, D_L01_001DDAF8, 1.0f, 1.4f, D_L01_001DDAE0, D_L01_001DDAEC, 0.0f);
    func_L01_0040AAC8(q, 71, 72, 0x4F804020, 0, D_L01_001DDAF8, 1.0f, 1.4f, D_L01_001DDAE4, D_L01_001DDAF0, 0.05f);
    func_L01_0040AAC8(q, 71, 72, 0x4F20207F, 0, D_L01_001DDAF8, 1.0f, 1.4f, D_L01_001DDAE8, D_L01_001DDAF4, 0.1f);
    s = D_L01_001DDAF8 * 1.4f;
    r = func_00382538();
    func_003D9508(q, 11, 0x3FFF2040, 1, s, 0.01f, r);
}
/* localdecomp:end func_L01_003770A8 */

INCLUDE_ASM("asm/levels", func_L01_003773C0);

/* localdecomp:start func_L01_003778D0 */
void func_L01_003778D0(S_3738B0 *a0) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if ((&D_L01_001E10E0)[i] == 0) {
            (&D_L01_001E10E0)[i] = a0;
            return;
        }
    }
}
/* localdecomp:end func_L01_003778D0 */

/* localdecomp:start func_L01_00377908 */
extern S_3738B0 *D_L01_001E10E0;
s32 func_L01_00377908(void) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (((s32 *)&D_L01_001E10E0)[i] == 0) return 0;
    }
    return 1;
}
/* localdecomp:end func_L01_00377908 */

/* localdecomp:start func_L01_00377940 */
extern S_3738B0 *D_L01_001E10E0;
extern s32 func_00382468(s32 a0);
s32 func_L01_00377940(void) {
    s32 i;
    u8 *e;
    i = func_00382468(4);
    e = ((u8 * *)&D_L01_001E10E0)[i];
    if (e != 0) {
        e[32] = 3;
        ((u8 * *)&D_L01_001E10E0)[i] = 0;
        return 1;
    }
    for (i = 0; i < 6; i++) {
        e = ((u8 * *)&D_L01_001E10E0)[i];
        if (e != 0) {
            e[32] = 3;
            ((u8 * *)&D_L01_001E10E0)[i] = 0;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_00377940 */

/* localdecomp:start func_L01_003779C8 */
extern S_3738B0 *D_L01_001E10E0;
int func_L01_003779C8(int a)
{
    int i;
    for (i = 0; i < 6; i++) {
        if (((int *)&D_L01_001E10E0)[i] == a) {
            ((int *)&D_L01_001E10E0)[i] = 0;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_003779C8 */

LINKER_REMNANT("asm/levels", func_L01_00377A08);

/* localdecomp:start func_L01_00377A10 */
typedef int u128_377A10 __attribute__((mode(TI)));

typedef struct {
    u128_377A10 dir_pos;   /* 0x00 */
    f32 f10;
    s32 x14;
    f32 width;        /* 0x18 */
    f32 height;       /* 0x1C */
    s32 x20;
    s16 s24;
    s16 life;         /* 0x26 */
    s32 x28;
    f32 size;         /* 0x2C */
    s32 x30;
    u8 pad34[0x54 - 0x34];
    s32 x54;
    void *owner;      /* 0x58 */
    s32 x5c;
    s32 x60;
    s32 x64;
} P_377A10;

typedef struct {
    u8 pad0[0x24];
    f32 scale;
} C_377A10;

typedef struct {
    u8 pad0[0x10];
    u128_377A10 pos;       /* 0x10 */
    u8 x20;
    u8 pad21[2];
    u8 alpha;         /* 0x23 */
    C_377A10 *cls;    /* 0x24 */
    u8 pad28[4];
    f32 scale;        /* 0x2C */
    u8 x30;
    u8 pad31;
    s16 x32;
    u16 flags;        /* 0x34 */
    u8 pad36[0x68 - 0x36];
    P_377A10 *state;  /* 0x68 */
    u8 pad6c[0x98 - 0x6C];
    s32 x98;
    u8 pad9c[0xC0 - 0x9C];
    u128_377A10 rows[4];   /* 0xC0 */
} M_377A10;

extern u8 *func_003C24B0(s32, s32);
extern f32 func_00382538(void);
extern void func_0038CF68(f32, void *, void *);
extern s32 func_L01_004C85C8(void *, f32, f32, f32, s32);
extern s32 D_001D60EC;
extern s32 D_001D545C;
extern f32 D_L01_002F16F0[];
extern u8 D_001425C0[];
extern Hw_374790 D_001A4BE0; /* the hero, as rift_spawn above declares it */

/* holo_shield_spawn: make the shield (class 0x186D) as it leaves the glove */
M_377A10 *func_L01_00377A10(void *owner, u128_377A10 *pos, u128_377A10 *dir, f32 size) {
    M_377A10 *m = (M_377A10 *)func_003C24B0(0x186D, 0x900);
    P_377A10 *p;
    u128_377A10 *up;

    if (m != 0) {
        m->x20 = 0;
        m->x32 = 0xFF;
        m->x30 = 0xFF;
        p = m->state;
        m->pos = *pos;
        p->dir_pos = *dir;
        p->f10 = func_00382538();
        p->x28 = -1;
        p->size = size;
        p->x30 = 25;
        p->x14 = 0;
        p->width = 0.05f;
        p->height = 0.05f;
        if (D_001425C0[0xD2] != 0) {
            p->life = (s16)((f32)D_001D60EC * 0.75f * D_L01_002F16F0[D_001D545C]);
        } else {
            p->life = (s16)((f32)D_001D60EC * 0.75f);
        }
        p->x54 = 1;
        if (p->life == 0) {
            p->life = 4;
        }
        p->owner = owner;
        p->x20 = 0x25;
        p->x64 = 150;
        p->s24 = 0;
        up = &m->rows[2];
        m->scale = m->cls->scale * 3.25f;
        m->alpha = 0x14;
        m->flags |= 0x100;
        m->rows[3] = *(u128_377A10 *)((u8 *)D_001A4BE0.w[0x25C0 / 4] + 0xF0);
        m->rows[0] = *(u128_377A10 *)((u8 *)D_001A4BE0.w[0x25C0 / 4] + 0xC0);
        m->rows[1] = *(u128_377A10 *)((u8 *)D_001A4BE0.w[0x25C0 / 4] + 0xD0);
        m->rows[2] = *(u128_377A10 *)((u8 *)D_001A4BE0.w[0x25C0 / 4] + 0xE0);
        func_0038CF68(p->width, &m->rows[1], &m->rows[1]);
        func_0038CF68(p->height, up, up);
        p->x60 = func_L01_004C85C8(m, 1.0f, 1.0f, 1.0f, 0);
        m->x98 = 0;
        m->flags |= 4;
    }
    return m;
}
/* localdecomp:end func_L01_00377A10 */

INCLUDE_ASM("asm/levels", func_L01_00377C38);

/* localdecomp:start func_L01_00379368 */
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L01_00379368(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (p != 0) {
        *(s32 *)(p + 20) = 0;
    }
    func_L01_004450F0(a0, 5, -1);
}
/* localdecomp:end func_L01_00379368 */

/* localdecomp:start func_L01_00379398 */
#include "structs/weapon.h"
__asm__(".extern D_L01_001DDB14, 4");
__asm__(".extern D_L01_001DDB18, 4");
__asm__(".extern D_L01_001DDB1C, 4");
__asm__(".extern D_L01_001DDB20, 4");
__asm__(".extern D_L01_001DDB44, 4");
__asm__(".extern D_L01_001DDB48, 4");
__asm__(".extern D_L01_001DDB4C, 4");
__asm__(".extern D_L01_001DDB50, 4");
__asm__(".extern D_L01_001DDB54, 4");

__asm__(".extern D_L01_001DDB24, 4");
__asm__(".extern D_L01_001DDB28, 4");
__asm__(".extern D_L01_001DDB2C, 4");
__asm__(".extern D_L01_001DDB30, 4");
__asm__(".extern D_L01_001DDB34, 4");
__asm__(".extern D_L01_001DDB38, 4");
__asm__(".extern D_L01_001DDB3C, 4");
__asm__(".extern D_L01_001DDB40, 4");

typedef struct {
    u8 pad0[0x10];
    f32 pos[4];       /* 0x10 */
    u8 pad20[0x68 - 0x20];
    u8 *state;        /* 0x68 */
} M_379398;

typedef struct {
    u8 pad0[0x34];
    f32 roll34;
    f32 roll38;
    f32 roll3c;
    u8 pad40[4];
    f32 roll44;
    f32 roll48;
    f32 roll4c;
} W_379398;

extern f32 D_L01_001DDB14;   /* near distance of the fade-in */
extern f32 D_L01_001DDB18;   /* far distance of the fade-in */
extern f32 D_L01_001DDB1C;
extern f32 D_L01_001DDB20;
extern s32 D_L01_001DDB44;
extern s32 D_L01_001DDB48;
extern s32 D_L01_001DDB4C;
extern s32 D_L01_001DDB50;
extern s32 D_L01_001DDB54;
extern s32 D_L01_001DDB24;
extern s32 D_L01_001DDB28;
extern s32 D_L01_001DDB2C;
extern s32 D_L01_001DDB30;
extern s32 D_L01_001DDB34;
extern s32 D_L01_001DDB38;
extern s32 D_L01_001DDB3C;
extern s32 D_L01_001DDB40;
extern u8 D_001425C0[];
extern struct WeaponRow D_L01_002C5600[];
extern u8 D_L01_001E29C0[];
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_0037BE80(void *, void *, s32, s32, u32, f32, f32, f32, f32, f32, f32, s32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern void func_L01_0037BCF8(void *, void *, s32, u32, s32, f32, f32, f32);

/* holo_wall_draw_v3: the standing shield's wall from V3 */
void func_L01_00379398(M_379398 *obj) {
    W_379398 *w = (W_379398 *)obj->state;
    f32 dist;
    f32 t;
    f32 fadeA;
    f32 fadeB;
    u32 ca, cb, cc, cd;
    f32 *q2, *q3, *q4, *q5, *q6;

    w->roll44 = func_0038DAB8(w->roll44, func_003824E0(-0.5f, -1.0f) * 0.017453292f);
    w->roll34 = func_0038DAB8(w->roll34, func_003824E0(-1.0f, -2.0f) * 0.017453292f);
    w->roll48 = func_0038DAB8(w->roll48, func_003824E0(-1.0f, -1.5f) * 0.017453292f);
    w->roll38 = func_0038DAB8(w->roll38, func_003824E0(-1.5f, -2.5f) * 0.017453292f);
    w->roll4c = func_0038DAB8(w->roll4c, func_003824E0(-0.5f, -1.5f) * 0.017453292f);
    w->roll3c = func_0038DAB8(w->roll3c, func_003824E0(-0.5f, -1.5f) * 0.017453292f);
    dist = func_L01_0040E570(obj->pos, D_L01_001E29C0);
    if (dist < D_L01_001DDB18) {
        t = (dist - D_L01_001DDB14) / (D_L01_001DDB18 - D_L01_001DDB14);
    } else {
        t = 1.0f;
    }
    fadeA = t < 0.0f ? 0.0f : t;
    if (dist < D_L01_001DDB20) {
        t = (dist - D_L01_001DDB1C) / (D_L01_001DDB20 - D_L01_001DDB1C);
    } else {
        t = 1.0f;
    }
    fadeB = t < 0.0f ? 0.0f : t;
    if (0.25f < fadeB && D_L01_001DDB28 != 0) {
        ca = 0x4FFF4020;
        if (fadeB != 1.0f) {
            s32 al = 0x7F;
            u8 b = (s32)(fadeB * 79.0f);
            unsigned long a = b;
            if ((a >> 7) == 0) {
                al = b;
            }
            ca = (al << 24) | 0xFF4020;
        }
        q2 = obj->pos;
        func_003D9508(q2, 57, ca, 1, 0.2f, 0.0f, w->roll34);
        func_003D9508(q2, 57, ca, 1, 0.2f, 0.0f, -w->roll3c);
    }
    if (0.25f < fadeB && D_L01_001DDB2C != 0) {
        cb = 0x3FFF2040;
        if (fadeB != 1.0f) {
            s32 al = 0x7F;
            u8 b = (s32)(fadeB * 63.0f);
            unsigned long a = b;
            if ((a >> 7) == 0) {
                al = b;
            }
            cb = (al << 24) | 0xFF2040;
        }
        q3 = obj->pos;
        func_L01_0037BCF8(obj, q3, 11, cb, 1, 0.22500001f, 0.01f, w->roll38);
        cb = 0x157F1010;
        if (fadeB != 1.0f) {
            s32 al = 0x7F;
            u8 b = (s32)(fadeB * 21.0f);
            unsigned long a = b;
            if ((a >> 7) == 0) {
                al = b;
            }
            cb = (al << 24) | 0x7F1010;
        }
        func_L01_0037BCF8(obj, q3, 11, cb, 1, 1.0f, 0.01f, w->roll38);
    }
    if (0.0f < fadeB && D_L01_001DDB30 != 0) {
        cc = 0x4F204080;
        if (fadeB != 1.0f) {
            s32 al = 0x7F;
            u8 b = (s32)(fadeB * 79.0f);
            unsigned long a = b;
            if ((a >> 7) == 0) {
                al = b;
            }
            cc = (al << 24) | 0x204080;
        }
        q4 = obj->pos;
        func_L01_0037BCF8(obj, q4, 27, cc, 1, 1.15f, 0.0f, w->roll34);
        func_L01_0037BCF8(obj, q4, 27, cc, 1, 1.15f, 0.0f, w->roll38);
        cc = 0x1FFF1010;
        if (fadeB != 1.0f) {
            s32 al = 0x7F;
            u8 b = (s32)(fadeB * 31.0f);
            unsigned long a = b;
            if ((a >> 7) == 0) {
                al = b;
            }
            cc = (al << 24) | 0xFF1010;
        }
        func_L01_0037BCF8(obj, q4, 8, cc, 1, 1.1f, 0.01f, w->roll38);
    }
    if ((D_L01_002C5600 + D_001425C0[0x67])->level >= 4 && D_L01_001DDB34 != 0) {
        func_L01_0037BCF8(obj, obj->pos, D_L01_001DDB24, 0x5F204080, 1, 1.15f, 0.0f, w->roll38);
    }
    if (D_L01_001DDB40 != 0) {
        func_L01_0037BE80(obj, obj->pos, 67, 67, 0x2F404040, 1.0f, 1.0f, 1.0f, w->roll44, w->roll34, 0.0f, 0);
    }
    if (0.0f < fadeA && D_L01_001DDB38 != 0) {
        cd = 0x2F604040;
        if (fadeA != 1.0f) {
            s32 al = 0x7F;
            u8 b = (s32)(fadeA * 47.0f);
            unsigned long a = b;
            if ((a >> 7) == 0) {
                al = b;
            }
            cd = (al << 24) | 0x604040;
        }
        q5 = obj->pos;
        func_L01_0037BE80(obj, q5, 67, 67, cd, 1.0f, 1.0f, 1.0f, w->roll48, w->roll38, 0.02f, 0);
        func_L01_0037BE80(obj, q5, 67, 67, cd, 1.0f, 1.0f, 1.0f, w->roll48, w->roll38, -0.02f, 0);
    }
    if (0.25f < fadeB && D_L01_001DDB3C != 0) {
        cd = 0x2F80407F;
        if (fadeB != 1.0f) {
            s32 al = 0x7F;
            u8 b = (s32)(fadeB * 47.0f);
            unsigned long a = b;
            if ((a >> 7) == 0) {
                al = b;
            }
            cd = (al << 24) | 0x80407F;
        }
        q6 = obj->pos;
        func_L01_0037BE80(obj, q6, 67, 67, cd, 1.0f, 1.0f, 1.0f, w->roll4c, w->roll3c, 0.04f, 0);
        func_L01_0037BE80(obj, q6, 67, 67, cd, 1.0f, 1.0f, 1.0f, w->roll4c, w->roll3c, -0.04f, 0);
    }
}
/* localdecomp:end func_L01_00379398 */

/* localdecomp:start func_L01_00379B20 */
#include "structs/moby.h"
__asm__(".extern D_L01_001DDB14, 4");
__asm__(".extern D_L01_001DDB18, 4");
__asm__(".extern D_L01_001DDB1C, 4");
__asm__(".extern D_L01_001DDB20, 4");
__asm__(".extern D_L01_001DDB44, 4");
__asm__(".extern D_L01_001DDB48, 4");
__asm__(".extern D_L01_001DDB4C, 4");
__asm__(".extern D_L01_001DDB50, 4");
__asm__(".extern D_L01_001DDB54, 4");

/* The standing Holo Shield's pvars, as its draws read them. */
typedef struct {
    u8 pad_0[0x34];
    f32 quad_spin[3];              /* 0x34: the quads' turns (and the strips' second), stepped a random few degrees a frame */
    u8 pad_40[0x44 - 0x40];
    f32 strip_spin[3];             /* 0x44: the masked strips' turns */
} HoloShield_379B20;

extern f32 D_L01_001DDB14;   /* near distance of the fade-in */
extern f32 D_L01_001DDB18;   /* far distance of the fade-in */
extern f32 D_L01_001DDB1C;
extern f32 D_L01_001DDB20;
extern s32 D_L01_001DDB44;
extern s32 D_L01_001DDB48;
extern s32 D_L01_001DDB4C;
extern s32 D_L01_001DDB50;
extern s32 D_L01_001DDB54;
extern u8 D_L01_001E29C0[];      /* the point the fades measure from */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_0037BE80(void *, void *, s32, s32, u32, f32, f32, f32, f32, f32, f32, s32);
extern void func_L01_0037BCF8(void *, void *, s32, u32, s32, f32, f32, f32);

/* holo_wall_draw_v1: draw the standing Holo Shield's wall (V1-V2) */
void func_L01_00379B20(struct Moby *shield) {
    Vec4f *centre_a, *centre_b, *centre_c;
    HoloShield_379B20 *vars = shield->pvar;
    f32 dist;
    f32 t;
    f32 fade_a;
    f32 fade_b;
    u32 rgba_a, rgba_b, rgba_c, rgba_d;

    vars->strip_spin[0] = func_0038DAB8(vars->strip_spin[0], func_003824E0(-0.5f, -1.0f) * 0.017453292f);
    vars->quad_spin[0] = func_0038DAB8(vars->quad_spin[0], func_003824E0(-1.0f, -2.0f) * 0.017453292f);
    vars->strip_spin[1] = func_0038DAB8(vars->strip_spin[1], func_003824E0(-1.0f, -1.5f) * 0.017453292f);
    vars->quad_spin[1] = func_0038DAB8(vars->quad_spin[1], func_003824E0(1.5f, 2.5f) * 0.017453292f);
    vars->strip_spin[2] = func_0038DAB8(vars->strip_spin[2], func_003824E0(-0.5f, -1.5f) * 0.017453292f);
    vars->quad_spin[2] = func_0038DAB8(vars->quad_spin[2], func_003824E0(0.5f, 1.5f) * 0.017453292f);
    dist = func_L01_0040E570(&shield->position, D_L01_001E29C0);
    if (dist < D_L01_001DDB18) {
        t = (dist - D_L01_001DDB14) / (D_L01_001DDB18 - D_L01_001DDB14);
    } else {
        t = 1.0f;
    }
    fade_a = t < 0.0f ? 0.0f : t;
    if (dist < D_L01_001DDB20) {
        t = (dist - D_L01_001DDB1C) / (D_L01_001DDB20 - D_L01_001DDB1C);
    } else {
        t = 1.0f;
    }
    fade_b = t < 0.0f ? 0.0f : t;
    if (D_L01_001DDB44 != 0) {
        func_L01_0037BE80(shield, &shield->position, 71, 72, 0x8FFF0032, 1.0f, 1.0f, 1.7f, vars->strip_spin[0], vars->quad_spin[0], 0.0f, 0);
    }
    if (fade_a > 0.0f && D_L01_001DDB48 != 0) {
        rgba_a = 0x2F804020;
        if (fade_a != 1.0f) {
            s32 alpha = 0x7F;
            u8 scaled = (s32)(fade_a * 47.0f);
            unsigned long wide = scaled;
            if ((wide >> 7) == 0) {
                alpha = scaled;
            }
            rgba_a = (alpha << 24) | 0x804020;
        }
        centre_a = &shield->position;
        func_L01_0037BCF8(shield, centre_a, 27, rgba_a, 1, 1.15f, 0.0f, vars->quad_spin[0]);
        func_L01_0037BCF8(shield, centre_a, 27, rgba_a, 1, 1.15f, 0.0f, vars->quad_spin[1]);
    }
    if (fade_b > 0.0f && D_L01_001DDB4C != 0) {
        rgba_b = 0x7FFF0032;
        if (fade_b != 1.0f) {
            s32 full = 0x7F;
            u8 scaled = (s32)((f32)full * fade_b);
            unsigned long wide = scaled;
            s32 alpha = (wide >> 7) == 0 ? scaled : 0x7F;
            rgba_b = (alpha << 24) | 0xFF0032;
        }
        centre_b = &shield->position;
        func_L01_0037BCF8(shield, centre_b, 76, rgba_b, 1, 0.5f, 0.0f, -vars->quad_spin[1]);
        rgba_b = 0x7F300505;
        if (fade_b != 1.0f) {
            s32 full = 0x7F;
            u8 scaled = (s32)((f32)full * fade_b);
            unsigned long wide = scaled;
            s32 alpha = (wide >> 7) == 0 ? scaled : 0x7F;
            rgba_b = (alpha << 24) | 0x300505;
        }
        func_L01_0037BCF8(shield, centre_b, 76, rgba_b, 1, 0.2f, 0.0f, vars->quad_spin[1]);
    }
    if (fade_a > 0.0f && D_L01_001DDB50 != 0) {
        rgba_c = 0x8F804020;
        if (fade_a != 1.0f) {
            s32 alpha = 0x7F;
            u8 scaled = (s32)(fade_a * 143.0f);
            unsigned long wide = scaled;
            if ((wide >> 7) == 0) {
                alpha = scaled;
            }
            rgba_c = (alpha << 24) | 0x804020;
        }
        centre_c = &shield->position;
        func_L01_0037BE80(shield, centre_c, 71, 72, rgba_c, 1.0f, 1.0f, 1.7f, vars->strip_spin[1], vars->quad_spin[1], 0.05f, 0);
        rgba_c = 0x8F20207F;
        if (fade_a != 1.0f) {
            s32 alpha = 0x7F;
            u8 scaled = (s32)(fade_a * 143.0f);
            unsigned long wide = scaled;
            if ((wide >> 7) == 0) {
                alpha = scaled;
            }
            rgba_c = (alpha << 24) | 0x20207F;
        }
        func_L01_0037BE80(shield, centre_c, 71, 72, rgba_c, 1.0f, 1.0f, 1.7f, vars->strip_spin[2], vars->quad_spin[2], 0.1f, 0);
    }
    if (fade_b > 0.0f && D_L01_001DDB54 != 0) {
        rgba_d = 0x7F204080;
        if (fade_b != 1.0f) {
            s32 full = 0x7F;
            u8 scaled = (s32)((f32)full * fade_b);
            unsigned long wide = scaled;
            s32 alpha = (wide >> 7) == 0 ? scaled : 0x7F;
            rgba_d = (alpha << 24) | 0x204080;
        }
        func_L01_0037BCF8(shield, &shield->position, 75, rgba_d, 0, 0.6f, 0.0f, vars->quad_spin[0]);
    }
}
/* localdecomp:end func_L01_00379B20 */

/* localdecomp:start func_L01_0037A0F8 */
#include "structs/weapon.h"
__asm__(".extern D_L01_001DDB14, 4");
__asm__(".extern D_L01_001DDB18, 4");
__asm__(".extern D_L01_001DDB1C, 4");
__asm__(".extern D_L01_001DDB20, 4");
__asm__(".extern D_L01_001DDB44, 4");
__asm__(".extern D_L01_001DDB48, 4");
__asm__(".extern D_L01_001DDB4C, 4");
__asm__(".extern D_L01_001DDB50, 4");
__asm__(".extern D_L01_001DDB54, 4");

__asm__(".extern D_L01_001DDB24, 4");
__asm__(".extern D_L01_001DDB28, 4");
__asm__(".extern D_L01_001DDB2C, 4");
__asm__(".extern D_L01_001DDB30, 4");
__asm__(".extern D_L01_001DDB34, 4");
__asm__(".extern D_L01_001DDB38, 4");
__asm__(".extern D_L01_001DDB3C, 4");
__asm__(".extern D_L01_001DDB40, 4");

typedef struct {
    u8 pad0[0x10];
    f32 pos[4];       /* 0x10 */
    u8 pad20[0x68 - 0x20];
    u8 *state;        /* 0x68 */
} M_37A0F8;

typedef struct {
    u8 pad0[0x34];
    f32 roll34;
    f32 roll38;
    f32 roll3c;
    f32 grow;         /* 0x40: how far the hit ring has grown */
    f32 roll44;
    f32 roll48;
    f32 roll4c;
} W_37A0F8;

extern f32 D_L01_001DDB14;   /* near distance of the fade-in */
extern f32 D_L01_001DDB18;   /* far distance of the fade-in */
extern f32 D_L01_001DDB1C;
extern f32 D_L01_001DDB20;
extern s32 D_L01_001DDB44;
extern s32 D_L01_001DDB48;
extern s32 D_L01_001DDB4C;
extern s32 D_L01_001DDB50;
extern s32 D_L01_001DDB54;
extern s32 D_L01_001DDB24;
extern s32 D_L01_001DDB28;
extern s32 D_L01_001DDB2C;
extern s32 D_L01_001DDB30;
extern s32 D_L01_001DDB34;
extern s32 D_L01_001DDB38;
extern s32 D_L01_001DDB3C;
extern s32 D_L01_001DDB40;
extern u8 D_001425C0[];
extern struct WeaponRow D_L01_002C5600[];
extern u8 D_L01_001E29C0[];
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_0037BE80(void *, void *, s32, s32, u32, f32, f32, f32, f32, f32, f32, s32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern void func_L01_0037BCF8(void *, void *, s32, u32, s32, f32, f32, f32);

static inline u32 func_L01_0037A0F8_fade(u32 color, f32 fade, f32 scale) {
    unsigned long a;
    u8 b;
    s32 al;

    if (fade != 1.0f) {
        al = 0x7F;
        b = (s32)(fade * scale);
        a = b;
        if ((a >> 7) == 0) {
            al = b;
        }
        color = (al << 24) | (color & 0xFFFFFF);
    }
    return color;
}

/* holo_hit_draw_v3: the wall as a hit shakes it, from V3 */
void func_L01_0037A0F8(M_37A0F8 *obj) {
    W_37A0F8 *w = (W_37A0F8 *)obj->state;
    f32 dist;
    f32 t;
    f32 fadeA;
    f32 fadeB;
    u32 ca, cb, cc, cd, ce;
    unsigned long a;
    u8 b;
    s32 al;
    u32 rgb;
    f32 *q;

    w->roll44 = func_0038DAB8(w->roll44, func_003824E0(-0.5f, -1.0f) * 0.017453292f);
    w->roll34 = func_0038DAB8(w->roll34, func_003824E0(-1.0f, -2.0f) * 0.017453292f);
    w->roll48 = func_0038DAB8(w->roll48, func_003824E0(-1.0f, -1.5f) * 0.017453292f);
    w->roll38 = func_0038DAB8(w->roll38, func_003824E0(-1.5f, -2.5f) * 0.017453292f);
    w->roll4c = func_0038DAB8(w->roll4c, func_003824E0(-0.5f, -1.5f) * 0.017453292f);
    w->roll3c = func_0038DAB8(w->roll3c, func_003824E0(-0.5f, -1.5f) * 0.017453292f);
    dist = func_L01_0040E570(obj->pos, D_L01_001E29C0);
    if (dist < D_L01_001DDB18) {
        t = (dist - D_L01_001DDB14) / (D_L01_001DDB18 - D_L01_001DDB14);
    } else {
        t = 1.0f;
    }
    fadeA = t < 0.0f ? 0.0f : t;
    if (dist < D_L01_001DDB20) {
        t = (dist - D_L01_001DDB1C) / (D_L01_001DDB20 - D_L01_001DDB1C);
    } else {
        t = 1.0f;
    }
    fadeB = t < 0.0f ? 0.0f : t;
    q = obj->pos;
    if (0.25f < fadeB && D_L01_001DDB28 != 0) {
        {
            ca = 0x4FFF4020;
            ca = func_L01_0037A0F8_fade(ca, fadeB, 79.0f);
            func_003D9508(q, 57, ca, 1, 0.2f, 0.0f, w->roll34);
            func_003D9508(q, 57, ca, 1, 0.2f, 0.0f, -w->roll3c);
        }
    }
    if (0.25f < fadeB && D_L01_001DDB2C != 0) {
        {
            cb = 0x3FFF2040;
        cb = func_L01_0037A0F8_fade(cb, fadeB, 63.0f);
            func_L01_0037BCF8(obj, q, 11, cb, 1, 0.22500001f, 0.01f, w->roll38);
            cb = 0x157F1010;
        cb = func_L01_0037A0F8_fade(cb, fadeB, 21.0f);
            func_L01_0037BCF8(obj, q, 11, cb, 1, 1.0f, 0.01f, w->roll38);
        }
    }
    if (0.0f < fadeB && D_L01_001DDB30 != 0) {
        cc = 0x4F204080;
        cc = func_L01_0037A0F8_fade(cc, fadeB, 79.0f);
        func_L01_0037BCF8(obj, q, 27, cc, 1, 1.15f, 0.0f, w->roll34);
        func_L01_0037BCF8(obj, q, 27, cc, 1, 1.15f, 0.0f, w->roll38);
    }
    if ((D_L01_002C5600 + D_001425C0[0x67])->level >= 4 && D_L01_001DDB34 != 0) {
        func_L01_0037BCF8(obj, q, D_L01_001DDB24, 0x5F204080, 1, 1.15f, 0.0f, w->roll38);
    }
    if (w->grow < 1.1f) {
        w->grow += 0.05f;
        func_L01_0037BCF8(obj, q, 8, 0x25204080, 1, w->grow, 0.01f, w->roll38);
    }
    func_L01_0037BCF8(obj, q, 8, 0x4F204080, 1, 1.1f, 0.01f, w->roll38);
    if (D_L01_001DDB40 != 0) {
        func_L01_0037BE80(obj, q, 67, 67, 0x2F404040, 1.0f, 1.0f, 1.0f, w->roll44, w->roll34, 0.0f, 0);
    }
    if (0.0f < fadeA && D_L01_001DDB38 != 0) {
        cd = 0x2F604040;
        cd = func_L01_0037A0F8_fade(cd, fadeA, 47.0f);
        func_L01_0037BE80(obj, q, 67, 67, cd, 1.0f, 1.0f, 1.0f, w->roll48, w->roll38, 0.02f, 0);
        func_L01_0037BE80(obj, q, 67, 67, cd, 1.0f, 1.0f, 1.0f, w->roll48, w->roll38, -0.02f, 0);
    }
    if (0.25f < fadeB && D_L01_001DDB3C != 0) {
        ce = 0x2F80407F;
        ce = func_L01_0037A0F8_fade(ce, fadeB, 47.0f);
        func_L01_0037BE80(obj, q, 67, 67, ce, 1.0f, 1.0f, 1.0f, w->roll4c, w->roll3c, 0.04f, 0);
        func_L01_0037BE80(obj, q, 67, 67, ce, 1.0f, 1.0f, 1.0f, w->roll4c, w->roll3c, -0.04f, 0);
    }
}
/* localdecomp:end func_L01_0037A0F8 */

/* localdecomp:start func_L01_0037A880 */
__asm__(".extern D_L01_001DDB14, 4");
__asm__(".extern D_L01_001DDB18, 4");
__asm__(".extern D_L01_001DDB1C, 4");
__asm__(".extern D_L01_001DDB20, 4");
__asm__(".extern D_L01_001DDB44, 4");
__asm__(".extern D_L01_001DDB4C, 4");
__asm__(".extern D_L01_001DDB50, 4");
__asm__(".extern D_L01_001DDB54, 4");

typedef struct {
    u8 pad0[0x10];
    f32 pos[4];       /* 0x10 */
    u8 pad20[0x68 - 0x20];
    u8 *state;        /* 0x68 */
} M_37A880;

typedef struct {
    u8 pad0[0x34];
    f32 roll34;
    f32 roll38;
    f32 roll3c;
    f32 pad40;
    f32 roll44;
    f32 roll48;
    f32 roll4c;
} W_37A880;

static inline u32 fade_0037A880(u32 color, f32 fade) {
    if (fade != 1.0f) {
        u8 a = (color >> 24) * fade;
        s32 alpha = 127;
        if (a < 128) alpha = a;
        color = (alpha << 24) | (color & 0xFFFFFF);
    }
    return color;
}

void func_L01_0037A880(M_37A880 *obj) {
    W_37A880 *w = (W_37A880 *)obj->state;
    f32 dist;
    f32 t;
    f32 fadeA;
    f32 fadeB;
    f32 *q;

    w->roll44 = func_0038DAB8(w->roll44, func_003824E0(-0.5f, -1.0f) * 0.017453292f);
    w->roll34 = func_0038DAB8(w->roll34, func_003824E0(-1.0f, -2.0f) * 0.017453292f);
    w->roll48 = func_0038DAB8(w->roll48, func_003824E0(-1.0f, -1.5f) * 0.017453292f);
    w->roll38 = func_0038DAB8(w->roll38, func_003824E0(1.5f, 2.5f) * 0.017453292f);
    w->roll4c = func_0038DAB8(w->roll4c, func_003824E0(-0.5f, -1.5f) * 0.017453292f);
    w->roll3c = func_0038DAB8(w->roll3c, func_003824E0(0.5f, 1.5f) * 0.017453292f);
    dist = func_L01_0040E570(obj->pos, D_L01_001E29C0);
    if (dist < D_L01_001DDB18) {
        t = (dist - D_L01_001DDB14) / (D_L01_001DDB18 - D_L01_001DDB14);
    } else {
        t = 1.0f;
    }
    fadeA = t < 0.0f ? 0.0f : t;
    if (dist < D_L01_001DDB20) {
        t = (dist - D_L01_001DDB1C) / (D_L01_001DDB20 - D_L01_001DDB1C);
    } else {
        t = 1.0f;
    }
    fadeB = t < 0.0f ? 0.0f : t;
    q = obj->pos;
    if (D_L01_001DDB44 != 0) {
        func_L01_0037BE80(obj, q, 71, 72, 0x8F800032, 1.0f, 1.0f, 1.7f, w->roll44, w->roll34, 0.0f, 0);
    }
    if (0.0f < fadeA && D_L01_001DDB50 != 0) {
        func_L01_0037BE80(obj, q, 71, 72, fade_0037A880(0x8F204080, fadeA), 1.0f, 1.0f, 1.7f, w->roll48, w->roll38, 0.05f, 0);
        func_L01_0037BE80(obj, q, 71, 72, fade_0037A880(0x8F7F2020, fadeA), 1.0f, 1.0f, 1.7f, w->roll4c, w->roll3c, 0.1f, 0);
    }
    func_L01_0037BCF8(obj, q, 27, 0x2F2040FF, 1, 1.15f, 0.0f, w->roll34);
    func_L01_0037BCF8(obj, q, 27, 0x2F2040FF, 1, 1.15f, 0.0f, w->roll38);
    if (0.0f < fadeB && D_L01_001DDB4C != 0) {
        func_L01_0037BCF8(obj, q, 76, fade_0037A880(0x7F320080, fadeB), 1, 0.5f, 0.0f, -w->roll38);
        func_L01_0037BCF8(obj, q, 76, fade_0037A880(0x7F050530, fadeB), 1, 0.2f, 0.0f, w->roll38);
    }
    if (0.0f < fadeB && D_L01_001DDB54 != 0) {
        func_L01_0037BCF8(obj, q, 75, fade_0037A880(0x7F204080, fadeB), 0, 0.6f, 0.0f, w->roll34);
    }
}
/* localdecomp:end func_L01_0037A880 */

/* localdecomp:start func_L01_0037ADE0 */
#include "structs/moby.h"
#include "structs/weapon.h"
__asm__(".extern D_L01_001DDB14, 4");
__asm__(".extern D_L01_001DDB18, 4");
__asm__(".extern D_L01_001DDB1C, 4");
__asm__(".extern D_L01_001DDB20, 4");
__asm__(".extern D_L01_001DDB24, 4");
__asm__(".extern D_L01_001DDB28, 4");
__asm__(".extern D_L01_001DDB2C, 4");
__asm__(".extern D_L01_001DDB30, 4");
__asm__(".extern D_L01_001DDB34, 4");
__asm__(".extern D_L01_001DDB38, 4");
__asm__(".extern D_L01_001DDB3C, 4");
__asm__(".extern D_L01_001DDB40, 4");

/* The standing Holo Shield's pvars, as its draws read them. */
typedef struct {
    u8 pad_0[0x14];
    s32 frame;                     /* 0x14: frames since the fold started */
    u8 pad_18[0x34 - 0x18];
    f32 quad_spin[3];              /* 0x34: the quads' turns (and the strips' second), stepped a random few degrees a frame */
    u8 pad_40[0x44 - 0x40];
    f32 strip_spin[3];             /* 0x44: the masked strips' turns */
} HoloShield_37ADE0;

extern f32 D_L01_001DDB14;   /* near distance of the fade-in */
extern f32 D_L01_001DDB18;   /* far distance of the fade-in */
extern f32 D_L01_001DDB1C;
extern f32 D_L01_001DDB20;
extern s32 D_L01_001DDB24;
extern s32 D_L01_001DDB28;
extern s32 D_L01_001DDB2C;
extern s32 D_L01_001DDB30;
extern s32 D_L01_001DDB34;
extern s32 D_L01_001DDB38;
extern s32 D_L01_001DDB3C;
extern s32 D_L01_001DDB40;
extern u8 D_001425C0[];
extern struct WeaponRow D_L01_002C5600[];
extern u8 D_L01_001E29C0[];      /* the point the fades measure from */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_0037BE80(void *, void *, s32, s32, u32, f32, f32, f32, f32, f32, f32, s32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern void func_L01_0037BCF8(void *, void *, s32, u32, s32, f32, f32, f32);

/* holo_fold_draw_v3: the folding shield from V3 (state 5): holo_wall_draw_v3's layers, each alpha
   falling 2 a frame (the disc 3), the stars at half size; sets the moby's alpha to 0x15 less the frame. */
void func_L01_0037ADE0(struct Moby *shield) {
    HoloShield_37ADE0 *vars = shield->pvar;

    f32 dist;
    f32 t;
    f32 fade_a;
    f32 fade_b;
    u32 rgba_a, rgba_b, rgba_c, rgba_d;

    if (vars == 0) {
        return;
    }
    vars->strip_spin[0] = func_0038DAB8(vars->strip_spin[0], func_003824E0(-0.5f, -1.0f) * 0.017453292f);
    vars->quad_spin[0] = func_0038DAB8(vars->quad_spin[0], func_003824E0(-1.0f, -2.0f) * 0.017453292f);
    vars->strip_spin[1] = func_0038DAB8(vars->strip_spin[1], func_003824E0(-1.0f, -1.5f) * 0.017453292f);
    vars->quad_spin[1] = func_0038DAB8(vars->quad_spin[1], func_003824E0(-1.5f, -2.5f) * 0.017453292f);
    vars->strip_spin[2] = func_0038DAB8(vars->strip_spin[2], func_003824E0(-0.5f, -1.5f) * 0.017453292f);
    vars->quad_spin[2] = func_0038DAB8(vars->quad_spin[2], func_003824E0(-0.5f, -1.5f) * 0.017453292f);
    dist = func_L01_0040E570(&shield->position, D_L01_001E29C0);
    if (dist < D_L01_001DDB18) {
        t = (dist - D_L01_001DDB14) / (D_L01_001DDB18 - D_L01_001DDB14);
    } else {
        t = 1.0f;
    }
    fade_a = t < 0.0f ? 0.0f : t;
    if (dist < D_L01_001DDB20) {
        t = (dist - D_L01_001DDB1C) / (D_L01_001DDB20 - D_L01_001DDB1C);
    } else {
        t = 1.0f;
    }
    fade_b = t < 0.0f ? 0.0f : t;
    if (0.25f < fade_b && D_L01_001DDB28 != 0) {
        rgba_a = 0x4FFF4020;
        if (fade_b != 1.0f) {
            s32 alpha = 0x7F;
            u8 scaled = (s32)(fade_b * 79.0f);
            unsigned long wide = scaled;
            if ((wide >> 7) == 0) {
                alpha = scaled;
            }
            rgba_a = (alpha << 24) | 0xFF4020;
        }
        func_003D9508(&shield->position, 57, ((0x4F - vars->frame * 2) << 24) | (rgba_a & 0xFFFFFF), 1, 0.1875f, 0.0f, vars->quad_spin[0]);
        func_003D9508(&shield->position, 57, ((0x4F - vars->frame * 2) << 24) | (rgba_a & 0xFFFFFF), 1, 0.1875f, 0.0f, -vars->quad_spin[2]);
    }
    if (0.25f < fade_b && D_L01_001DDB2C != 0) {
        rgba_b = 0x3FFF2040;
        if (fade_b != 1.0f) {
            s32 alpha = 0x7F;
            u8 scaled = (s32)(fade_b * 63.0f);
            unsigned long wide = scaled;
            if ((wide >> 7) == 0) {
                alpha = scaled;
            }
            rgba_b = (alpha << 24) | 0xFF2040;
        }
        func_L01_0037BCF8(shield, &shield->position, 11, ((0x3F - vars->frame * 2) << 24) | (rgba_b & 0xFFFFFF), 1, 0.22500001f, 0.01f, vars->quad_spin[1]);
        rgba_b = 0x157F1010;
        if (fade_b != 1.0f) {
            s32 alpha = 0x7F;
            u8 scaled = (s32)(fade_b * 21.0f);
            unsigned long wide = scaled;
            if ((wide >> 7) == 0) {
                alpha = scaled;
            }
            rgba_b = (alpha << 24) | 0x7F1010;
        }
        func_L01_0037BCF8(shield, &shield->position, 11, ((0x15 - vars->frame * 2) << 24) | (rgba_b & 0xFFFFFF), 1, 1.0f, 0.01f, vars->quad_spin[1]);
    }
    if (0.0f < fade_b && D_L01_001DDB30 != 0) {
        rgba_c = 0x4F204080;
        if (fade_b != 1.0f) {
            s32 alpha = 0x7F;
            u8 scaled = (s32)(fade_b * 79.0f);
            unsigned long wide = scaled;
            if ((wide >> 7) == 0) {
                alpha = scaled;
            }
            rgba_c = (alpha << 24) | 0x204080;
        }
        func_L01_0037BCF8(shield, &shield->position, 27, ((0x4F - vars->frame * 2) << 24) | (rgba_c & 0xFFFFFF), 1, 1.15f, 0.0f, vars->quad_spin[0]);
        func_L01_0037BCF8(shield, &shield->position, 27, ((0x4F - vars->frame * 2) << 24) | (rgba_c & 0xFFFFFF), 1, 1.15f, 0.0f, vars->quad_spin[1]);
        rgba_c = 0x1FFF1010;
        if (fade_b != 1.0f) {
            s32 alpha = 0x7F;
            u8 scaled = (s32)(fade_b * 31.0f);
            unsigned long wide = scaled;
            if ((wide >> 7) == 0) {
                alpha = scaled;
            }
            rgba_c = (alpha << 24) | 0xFF1010;
        }
        func_L01_0037BCF8(shield, &shield->position, 8, ((0x3F - vars->frame * 2) << 24) | (rgba_c & 0xFFFFFF), 1, 1.1f, 0.01f, vars->quad_spin[1]);
    }
    if ((D_L01_002C5600 + D_001425C0[0x67])->level /* the Holo Shield Glove (item 0x67) */ >= 4 && D_L01_001DDB34 != 0) {
        func_L01_0037BCF8(shield, &shield->position, D_L01_001DDB24, ((0x4F - vars->frame * 3) << 24) | 0x204080, 1, 1.15f, 0.0f, vars->quad_spin[1]);
    }
    if (D_L01_001DDB40 != 0) {
        func_L01_0037BE80(shield, &shield->position, 67, 67, ((0x2F - vars->frame * 2) << 24) | 0x404040, 1.0f, 1.0f, 1.0f, vars->strip_spin[0], vars->quad_spin[0], 0.0f, 0);
    }
    if (0.0f < fade_a && D_L01_001DDB38 != 0) {
        rgba_d = 0x2F604040;
        if (fade_a != 1.0f) {
            s32 alpha = 0x7F;
            u8 scaled = (s32)(fade_a * 47.0f);
            unsigned long wide = scaled;
            if ((wide >> 7) == 0) {
                alpha = scaled;
            }
            rgba_d = (alpha << 24) | 0x604040;
        }
        func_L01_0037BE80(shield, &shield->position, 67, 67, ((0x2F - vars->frame * 2) << 24) | (rgba_d & 0xFFFFFF), 1.0f, 1.0f, 1.0f, vars->strip_spin[1], vars->quad_spin[1], 0.02f, 0);
        func_L01_0037BE80(shield, &shield->position, 67, 67, ((0x2F - vars->frame * 2) << 24) | (rgba_d & 0xFFFFFF), 1.0f, 1.0f, 1.0f, vars->strip_spin[1], vars->quad_spin[1], -0.02f, 0);
    }
    if (0.25f < fade_b && D_L01_001DDB3C != 0) {
        rgba_d = 0x2F80407F;
        if (fade_b != 1.0f) {
            s32 alpha = 0x7F;
            u8 scaled = (s32)(fade_b * 47.0f);
            unsigned long wide = scaled;
            if ((wide >> 7) == 0) {
                alpha = scaled;
            }
            rgba_d = (alpha << 24) | 0x80407F;
        }
        func_L01_0037BE80(shield, &shield->position, 67, 67, ((0x3F - vars->frame * 2) << 24) | (rgba_d & 0xFFFFFF), 1.0f, 1.0f, 1.0f, vars->strip_spin[2], vars->quad_spin[2], 0.04f, 0);
        func_L01_0037BE80(shield, &shield->position, 67, 67, ((0x3F - vars->frame * 2) << 24) | (rgba_d & 0xFFFFFF), 1.0f, 1.0f, 1.0f, vars->strip_spin[2], vars->quad_spin[2], -0.04f, 0);
    }
    shield->opacity = 0x15 - vars->frame;
}
/* localdecomp:end func_L01_0037ADE0 */

/* localdecomp:start func_L01_0037B6C0 */
#include "structs/moby.h"
__asm__(".extern D_L01_001DDB14, 4");
__asm__(".extern D_L01_001DDB18, 4");
__asm__(".extern D_L01_001DDB1C, 4");
__asm__(".extern D_L01_001DDB20, 4");
__asm__(".extern D_L01_001DDB44, 4");
__asm__(".extern D_L01_001DDB48, 4");
__asm__(".extern D_L01_001DDB4C, 4");
__asm__(".extern D_L01_001DDB50, 4");
__asm__(".extern D_L01_001DDB54, 4");

/* The standing Holo Shield's pvars, as its draws read them. */
typedef struct {
    u8 pad_0[0x14];
    s32 frame;                     /* 0x14: frames since the fold started */
    u8 pad_18[0x34 - 0x18];
    f32 quad_spin[3];              /* 0x34: the quads' turns (and the strips' second), stepped a random few degrees a frame */
    u8 pad_40[0x44 - 0x40];
    f32 strip_spin[3];             /* 0x44: the masked strips' turns */
} HoloShield_37B6C0;

extern f32 D_L01_001DDB14;   /* near distance of the fade-in */
extern f32 D_L01_001DDB18;   /* far distance of the fade-in */
extern f32 D_L01_001DDB1C;
extern f32 D_L01_001DDB20;
extern s32 D_L01_001DDB44;
extern s32 D_L01_001DDB48;
extern s32 D_L01_001DDB4C;
extern s32 D_L01_001DDB50;
extern s32 D_L01_001DDB54;
extern u8 D_L01_001E29C0[];      /* the point the fades measure from */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_0037BE80(void *, void *, s32, s32, u32, f32, f32, f32, f32, f32, f32, s32);
extern void func_L01_0037BCF8(void *, void *, s32, u32, s32, f32, f32, f32);


/* holo_fold_draw_v1: the folding shield from V1: holo_wall_draw_v1's layers in another order, each
   alpha falling 2 a frame, the 0x4C pair without the distance fade; sets the moby's alpha to 0x15 less the frame. */
void func_L01_0037B6C0(struct Moby *shield) {
    HoloShield_37B6C0 *vars = shield->pvar;
    f32 dist;
    f32 t;
    f32 fade_a;
    f32 fade_b;
    u32 rgba_a, rgba_c, rgba_d;

    if (vars == 0) {
        return;
    }
    vars->strip_spin[0] = func_0038DAB8(vars->strip_spin[0], func_003824E0(-0.5f, -1.0f) * 0.017453292f);
    vars->quad_spin[0] = func_0038DAB8(vars->quad_spin[0], func_003824E0(-1.0f, -2.0f) * 0.017453292f);
    vars->strip_spin[1] = func_0038DAB8(vars->strip_spin[1], func_003824E0(-1.0f, -1.5f) * 0.017453292f);
    vars->quad_spin[1] = func_0038DAB8(vars->quad_spin[1], func_003824E0(1.5f, 2.5f) * 0.017453292f);
    vars->strip_spin[2] = func_0038DAB8(vars->strip_spin[2], func_003824E0(-0.5f, -1.5f) * 0.017453292f);
    vars->quad_spin[2] = func_0038DAB8(vars->quad_spin[2], func_003824E0(0.5f, 1.5f) * 0.017453292f);
    dist = func_L01_0040E570(&shield->position, D_L01_001E29C0);
    if (dist < D_L01_001DDB18) {
        t = (dist - D_L01_001DDB14) / (D_L01_001DDB18 - D_L01_001DDB14);
    } else {
        t = 1.0f;
    }
    fade_a = t < 0.0f ? 0.0f : t;
    if (dist < D_L01_001DDB20) {
        t = (dist - D_L01_001DDB1C) / (D_L01_001DDB20 - D_L01_001DDB1C);
    } else {
        t = 1.0f;
    }
    fade_b = t < 0.0f ? 0.0f : t;
    if (D_L01_001DDB44 != 0) {
        func_L01_0037BE80(shield, &shield->position, 71, 72, ((0x8F - vars->frame * 2) << 24) | 0xFF0032, 1.0f, 1.0f, 1.7f, vars->strip_spin[0], vars->quad_spin[0], 0.0f, 0);
    }
    if (0.0f < fade_a && D_L01_001DDB50 != 0) {
        rgba_c = 0x8F804020;
        if (fade_a != 1.0f) {
            s32 alpha = 0x7F;
            u8 scaled = (s32)(fade_a * 143.0f);
            unsigned long wide = scaled;
            if ((wide >> 7) == 0) {
                alpha = scaled;
            }
            rgba_c = (alpha << 24) | 0x804020;
        }
        func_L01_0037BE80(shield, &shield->position, 71, 72, ((0x8F - vars->frame * 2) << 24) | (rgba_c & 0xFFFFFF), 1.0f, 1.0f, 1.7f, vars->strip_spin[1], vars->quad_spin[1], 0.05f, 0);
        rgba_c = 0x8F20207F;
        if (fade_a != 1.0f) {
            s32 full = 0x8F;
            u8 scaled = (s32)((f32)full * fade_a);
            unsigned long wide = scaled;
            s32 alpha = (wide >> 7) == 0 ? scaled : 0x7F;
            rgba_c = (alpha << 24) | 0x20207F;
        }
        func_L01_0037BE80(shield, &shield->position, 71, 72, ((0x8F - vars->frame * 2) << 24) | (rgba_c & 0xFFFFFF), 1.0f, 1.0f, 1.7f, vars->strip_spin[2], vars->quad_spin[2], 0.1f, 0);
    }
    if (0.0f < fade_a && D_L01_001DDB48 != 0) {
        rgba_a = 0x2F804020;
        if (fade_a != 1.0f) {
            s32 alpha = 0x7F;
            u8 scaled = (s32)(fade_a * 47.0f);
            unsigned long wide = scaled;
            if ((wide >> 7) == 0) {
                alpha = scaled;
            }
            rgba_a = (alpha << 24) | 0x804020;
        }
        func_L01_0037BCF8(shield, &shield->position, 27, ((0x2F - vars->frame * 2) << 24) | (rgba_a & 0xFFFFFF), 1, 1.15f, 0.0f, vars->quad_spin[0]);
        func_L01_0037BCF8(shield, &shield->position, 27, ((0x2F - vars->frame * 2) << 24) | (rgba_a & 0xFFFFFF), 1, 1.15f, 0.0f, vars->quad_spin[1]);
    }
    if (0.0f < fade_b && D_L01_001DDB4C != 0) {
        func_L01_0037BCF8(shield, &shield->position, 76, ((0x7F - vars->frame * 2) << 24) | 0xFF0032, 1, 0.5f, 0.0f, -vars->quad_spin[1]);
        func_L01_0037BCF8(shield, &shield->position, 76, ((0x7F - vars->frame * 2) << 24) | 0x300505, 1, 0.2f, 0.0f, vars->quad_spin[1]);
    }
    if (0.0f < fade_b && D_L01_001DDB54 != 0) {
        rgba_d = 0x7F204080;
        if (fade_b != 1.0f) {
            s32 full = 0x7F;
            u8 scaled = (s32)((f32)full * fade_b);
            unsigned long wide = scaled;
            s32 alpha = (wide >> 7) == 0 ? scaled : 0x7F;
            rgba_d = (alpha << 24) | 0x204080;
        }
        func_L01_0037BCF8(shield, &shield->position, 75, ((0x7F - vars->frame * 2) << 24) | (rgba_d & 0xFFFFFF), 0, 0.6f, 0.0f, vars->quad_spin[0]);
    }
    shield->opacity = 0x15 - vars->frame;
}
/* localdecomp:end func_L01_0037B6C0 */
