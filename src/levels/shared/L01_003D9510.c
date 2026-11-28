#include "common.h"
#include "vu0.h"

typedef int s128_3D8F20 __attribute__((mode(TI)));
typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 pad[0x6C]; f32 scale; u8 pad70[0x80]; } Row_003DD9C8;

/* localdecomp:start func_L01_003D9510 */
extern s32 D_L01_001D6740;
extern s16 D_001A4F48[];

s32 func_L01_003D9510(void) {
    s32 r = 0;
    if (D_L01_001D6740 != 0 || D_001A4F48[0] != 0) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L01_003D9510 */

/* localdecomp:start func_L01_003D9540 */
extern s32 D_L01_001D673C_003D9540;
s32 func_L01_003D9540(void) {
    return D_L01_001D673C_003D9540;
}
/* localdecomp:end func_L01_003D9540 */

/* localdecomp:start func_L01_003D9548 */
typedef struct Moby_003D9548 Moby_003D9548;

typedef struct {
    u8 pad0[0x46];
    u8 type;                        /* 0x46 */
} Class_003D9548;

struct Moby_003D9548 {
    u8 pad0[0x10];
    vu0_v4 pos;                     /* 0x10 */
    u8 state;                       /* 0x20 */
    u8 pad21[3];
    Class_003D9548 *cls;            /* 0x24 */
    u8 pad28[0x34 - 0x28];
    u16 flags;                      /* 0x34 */
    u8 pad36[0x42 - 0x36];
    u8 anim_state;                  /* 0x42 */
    u8 anim;                        /* 0x43 */
    u8 pad44[0x68 - 0x44];
    struct Vars_003D9548 *vars;     /* 0x68 */
    u8 pad6C[0x98 - 0x6C];
    s32 w98;                        /* 0x98 */
    u8 pad9C[0xC0 - 0x9C];
    u128_t m[3];                    /* 0xC0 */
    u8 padF0[8];
    f32 rot;                        /* 0xF8 */
};

typedef struct Vars_003D9548 {
    u8 pad0[0x14];
    f32 speed;                      /* 0x14 */
    Moby_003D9548 *home;            /* 0x18 */
    f32 turn;                       /* 0x1C */
    u8 pad20[0x28 - 0x20];
    Moby_003D9548 *target;          /* 0x28 */
    u8 pad2C[0x3C - 0x2C];
    s32 count;                      /* 0x3C */
    u8 pad40[0x48 - 0x40];
    s32 synced;                     /* 0x48 */
    s32 sound;                      /* 0x4C */
} Vars_003D9548;

typedef struct {
    u8 pad0[0x80];
    f32 x;                          /* 0x80 */
    f32 y;                          /* 0x84 */
    u8 pad88[0x25C0 - 0x88];
    Moby_003D9548 *ride;            /* 0x25C0 */
} Hero_003D9548;

extern Hero_003D9548 D_001A4BE0_003D9548;
extern f32 D_001A4C60[];
extern s32 D_001A71A0[];
extern u8 D_001425C0[];
/* a weapon row (include/structs/weapon.h, struct WeaponRow): 0xF0 bytes, damage at 0x6C */
typedef struct {
    u8 pad0[0x6C];
    f32 damage;                     /* 0x6C */
    u8 pad70[0xF0 - 0x70];
} Row_003D9548;

extern Row_003D9548 D_L01_002C5600_003D9548[];
extern vu0_v4 D_L01_001E2420 __attribute__((section(".sdata")));
extern u8 D_L01_001E2430[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001E2420, 16");
__asm__(".extern D_L01_001E2430, 16");

/* the 8-byte stub at 0x3D9540 in level 01; other levels call another copy of it (func_L01_003BEAA0 in level 02) */
extern s32 func_L01_003D9540_003D9548(void);
extern s32 func_L01_003D9510(void);
extern s32 func_L01_003D9FD0(void *);
extern void func_L01_003DB588(u8 *);
extern void func_L01_003DAAE0(void *);
extern s32 func_0038CAD0(void *);
/* the file declares func_L01_004450F0 with void * and with u8 * (in other functions): an alias of its own */
extern void func_L01_004450F0_003D9548(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern u8 *func_00382348_003D9548(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_00448340(void *, void *, void *, f32, f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00446780(void *, void *, s32, f32, f32, f32, s32, s32, s32);
extern Moby_003D9548 *func_L01_00450010(void *, f32, f32, f32, f32, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_004395E0(void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CF00(void *, void *);
/* declared as func_L01_003DF1B0 (waiting to land in this file) declares it: the callback takes the moby */
extern void func_L01_00404808(void (*)(u8 *), void *);

/* moves pos toward target through vel, the same acceleration on both axes */
static __inline__ void move_003D9548(vu0_v4 *pos, vu0_v4 *target, f32 *vel, f32 acc, f32 max) {
    func_L01_00448340(pos, target, vel, acc, acc, max);
}

void func_L01_003D9548(Moby_003D9548 *m) {
    Vars_003D9548 *v = m->vars;
    vu0_v4 a, b, c;
    f32 f;                          /* the distance, then the turn angle */
    f32 d4;
    f32 saved;                      /* the distance in state 2, the old speed in state 4 */
    f32 saved2;
    u8 *r;
    Moby_003D9548 *t;
    Moby_003D9548 *n;
    Moby_003D9548 *h;

    if (func_L01_003D9FD0(m) != 0) {
        return;
    }

    switch (m->state) {
    case 0:
        if (func_0038CAD0(D_L01_001E2430) == 0) {
            func_L01_003DB588((u8 *)m);
        } else {
            func_L01_004450F0_003D9548(m, 3, -1);
            if (m->anim != 2) {
                func_003C3A10(m, 2, 0, 0);
            }
        }
        break;
    case 1:
        break;
    case 2:
        m->w98 = 0;
        if (func_L01_003D9540_003D9548() || ((s32 (*)(void *))func_L01_003D9510)(m)) {
            v->synced = 1;
            m->flags |= 0x100;
            m->m[0] = D_001A4BE0_003D9548.ride->m[0];
            m->m[1] = D_001A4BE0_003D9548.ride->m[1];
            m->m[2] = D_001A4BE0_003D9548.ride->m[2];
        }
        t = v->target;
        if (t != 0 && t->state != 0xFE && t->state != 0xFD) {
            *(u128_t *)&a = *(u128_t *)&t->pos;
            r = func_00382348_003D9548(v->target);
            if (r != 0) {
                func_0038CE20(&a, v->target->m + 2, *(f32 *)(r + 0x10));
                vec_add_ab(&a, &a, &v->target->pos);
            }
            f = func_L01_0040E548(&a, &m->pos);
            move_003D9548(&m->pos, &a, &v->speed, 0.00160000008f, 0.26000002f);
            saved = f;
            if (!(func_L01_003D9540_003D9548() || ((s32 (*)(void *))func_L01_003D9510)(m))) {
                f32 *rot = &m->rot;
                f = func_0038D160(a.x - m->pos.x, a.y - m->pos.y);
                func_L01_00448890(rot, f, &v->turn, 0.0062831854f, 0.0062831854f, 0.31415927f, 0);
            }
            if (saved < 0.75f) {
                if (v->sound == 0) {
                    v->sound = 8;
                    func_003A52A0(3, 0, m);
                }
                v->count++;
                func_L01_00446780(m, &m->pos, 0x110000, 2.0f, (D_L01_002C5600_003D9548 + D_001425C0[0x8F])->damage * 0.2f, 1.0f, 0, 1, 0);
                *(u128_t *)&b = *(u128_t *)&m->pos;
                n = func_L01_00450010(&b, 1.0471976f, 30.0f, -1.0f, -1.0f, 0);
                v->target = n;
                if (n != 0 && !(n->flags & 2) && n->state != 0xFE && n->state != 0xFD && n->cls != 0 && n->cls->type == 5) {
                    *(u128_t *)&b = *(u128_t *)&n->pos;
                    r = func_00382348_003D9548(v->target);
                    if (r != 0) {
                        func_0038CE20(&b, v->target->m + 2, *(f32 *)(r + 0x10));
                        vec_add_ab(&b, &b, &v->target->pos);
                    }
                    if (func_003D3CB0(&m->pos, &b, 2, m, 0) != 0) {
                        v->target = 0;
                        func_L01_004450F0_003D9548(m, 3, -1);
                        if (m->anim != 3) {
                            func_003C3A10(m, 3, 0, 0);
                        }
                    }
                } else {
                    v->target = 0;
                }
            }
        } else {
            v->target = 0;
            func_L01_004450F0_003D9548(m, 3, -1);
            if (m->anim != 3) {
                func_003C3A10(m, 3, 0, 0);
            }
        }
        break;
    case 3:
        if (func_L01_003D9540_003D9548() || ((s32 (*)(void *))func_L01_003D9510)(m)) {
            v->synced = 1;
            m->flags |= 0x100;
            m->m[0] = D_001A4BE0_003D9548.ride->m[0];
            m->m[1] = D_001A4BE0_003D9548.ride->m[1];
            m->m[2] = D_001A4BE0_003D9548.ride->m[2];
        }
        m->w98 = 0;
        func_L01_00448340(&m->pos, &D_L01_001E2420, &v->speed,
                          func_003824E0(3.0f, 4.0f) * 0.000400000019f,
                          func_003824E0(2.0f, 3.0f) * 0.000400000019f,
                          func_003824E0(6.0f, 8.0f) * 0.020000001415610313f);
        if (!(func_L01_003D9540_003D9548() || ((s32 (*)(void *))func_L01_003D9510)(m))) {
            func_L01_00448890(&m->rot, func_0038D160(D_001A4BE0_003D9548.x - m->pos.x, D_001A4BE0_003D9548.y - m->pos.y), &v->turn, 0.012566371f, 0.012566371f, 0.62831855f, 0);
        }
        {
            f32 t3 = func_L01_004395E0(m);
            if (m->anim_state == 2 && t3 >= 9.0f && m->anim != 3) {
                func_003C3A10(m, 3, 0, 0);
            }
        }
        if (func_0038CF38(&m->pos, &D_L01_001E2420) < 0.5f) {
            func_L01_004450F0_003D9548(m, 4, -1);
            if (m->anim != 3) {
                func_003C3A10(m, 3, 0, 0);
            }
        }
        break;
    case 4:
        if (func_L01_003D9540_003D9548() || ((s32 (*)(void *))func_L01_003D9510)(m)) {
            v->synced = 1;
            m->flags |= 0x100;
            m->m[0] = D_001A4BE0_003D9548.ride->m[0];
            m->m[1] = D_001A4BE0_003D9548.ride->m[1];
            m->m[2] = D_001A4BE0_003D9548.ride->m[2];
        }
        m->w98 = 0;
        d4 = func_L01_0040E548(&m->pos, D_001A4C60);
        if (d4 > 50.0f) {
            move_003D9548(&m->pos, &D_L01_001E2420, &v->speed, 0.00160000008f, 0.20000002f);
        } else if (d4 > 20.0f && d4 < 50.0f) {
            *(u128_t *)&a = *(u128_t *)&m->pos;
            saved = v->speed;
            move_003D9548(&a, &D_L01_001E2420, &v->speed, 0.00160000008f, 0.20000002f);
            vec_sub_ba(&b, &a, &m->pos);
            func_0038CF68(&b, &b, 0.2f);
            vec_add_ab(&c, &b, &m->pos);
            if (func_003D3CB0(&m->pos, &c, 0, m, 0) != 0) {
                v->speed = saved;
            } else {
                *(u128_t *)&m->pos = *(u128_t *)&a;
            }
        } else {
            *(u128_t *)&a = *(u128_t *)&m->pos;
            saved2 = v->speed;
            func_L01_00448340(&a, &D_L01_001E2420, &v->speed,
                              func_003824E0(0.5f, 1.0f) * 0.000400000019f,
                              func_003824E0(0.5f, 1.0f) * 0.000400000019f,
                              func_003824E0(3.0f, 6.0f) * 0.020000001415610313f);
            vec_sub_ba(&b, &a, &m->pos);
            func_0038CF68(&b, &b, 0.2f);
            vec_add_ab(&c, &b, &m->pos);
            if (func_003D3CB0(&m->pos, &c, 0, m, 0) != 0) {
                v->speed = saved2;
            } else {
                *(u128_t *)&m->pos = *(u128_t *)&a;
            }
        }
        if (!(func_L01_003D9540_003D9548() || ((s32 (*)(void *))func_L01_003D9510)(m))) {
            h = v->home;
            if (h != 0 && h->state != 0xFE && h->state != 0xFD) {
                func_L01_00448890(&m->rot, func_0038D160(h->pos.x - m->pos.x, h->pos.y - m->pos.y), &v->turn, 0.012566371f, 0.012566371f, 0.62831855f, 0);
            } else if (func_0038CF00(&m->pos, &D_L01_001E2420) < 0.1f) {
                vec_add_ab(&a, &m->pos, (u8 *)D_001A71A0[0] + 0xC0);
                func_L01_00448890(&m->rot, func_0038D160(a.x - m->pos.x, a.y - m->pos.y), &v->turn, 0.002792527f, 0.002792527f, 0.13962635f, 0);
            } else {
                func_L01_00448890(&m->rot, func_0038D160(D_L01_001E2420.x - m->pos.x, D_L01_001E2420.y - m->pos.y), &v->turn, 0.0062831854f, 0.0062831854f, 0.31415927f, 0);
            }
        }
        break;
    case 5:
        break;
    }

    if (!(func_L01_003D9540_003D9548() || ((s32 (*)(void *))func_L01_003D9510)(m)) && v != 0 && v->synced != 0) {
        v->synced = 0;
        m->flags &= ~0x100;
        m->m[0] = D_001A4BE0_003D9548.ride->m[0];
        m->m[1] = D_001A4BE0_003D9548.ride->m[1];
        m->m[2] = D_001A4BE0_003D9548.ride->m[2];
    }
    func_L01_00404808((void (*)(u8 *))func_L01_003DAAE0, m);
}
/* localdecomp:end func_L01_003D9548 */

/* localdecomp:start func_L01_003D9FD0 */
typedef struct { f32 r,g,b,padC,x,y,z,radius; } Light_003D9FD0;
extern Light_003D9FD0 D_L01_001F1B40[];
s32 func_L01_003D9FD0(void *self) {
    u8 *obj = self;
    extern void func_L01_004471A8(void *, f32);
    extern s32 func_L01_00424B88(void *, f32, f32, u32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern u8 *func_00382348(void *);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_L01_003DA6E8(void *);
    extern void func_L01_003DABC8(void *);
    vu0_v4 pos;
    vu0_v4 targetpos;
    u8 *state = *(u8 **)(obj + 0x68);
    u8 *objpos;
    f32 phase, bob;
    s32 color;
    if (!state) return 1;
    objpos = obj+0x10;
    func_L01_004471A8(obj, 0.6f);
    func_0038CAD0(state + 0x4C);
    if (*(s32 *)(state + 0x30) == -1)
        *(s32 *)(state + 0x30) = func_L01_00424B88(objpos, 5.5f, 0.0f, 0x4080FF);
    *(vu0_q *)&pos = *(vu0_q *)(obj + 0x10);
    if (*(s32 *)(state + 0x30) >= 0) {
        ((Light_003D9FD0 *)((*(s32 *)(state+0x30)<<5)+(s32)D_L01_001F1B40))->x = pos.x;
        ((Light_003D9FD0 *)((*(s32 *)(state+0x30)<<5)+(s32)D_L01_001F1B40))->y = pos.y;
        ((Light_003D9FD0 *)((*(s32 *)(state+0x30)<<5)+(s32)D_L01_001F1B40))->z = pos.z;
        phase = func_003824E0(800.0f,160.0f) * 0.01745329238474369f;
        phase = func_0038DAB8(*(f32 *)(state+0x34), phase * 0.020000001415610313f);
        *(f32 *)(state+0x34) = phase;
        ((Light_003D9FD0 *)((*(s32 *)(state+0x30)<<5)+(s32)D_L01_001F1B40))->radius = (func_0038D0B0(phase * 0.1f) * 0.5f + 0.5f) + 3.5f;
        color = func_0038DBD8(0x3065FF,0x5585FF,func_0038D0B0(*(f32 *)(state+0x34))*0.5f+0.5f);
        ((Light_003D9FD0 *)((*(s32 *)(state+0x30)<<5)+(s32)D_L01_001F1B40))->r = (color & 255) * 0.0078125f;
        ((Light_003D9FD0 *)((*(s32 *)(state+0x30)<<5)+(s32)D_L01_001F1B40))->g = ((color >> 8) & 255) * 0.0078125f;
        ((Light_003D9FD0 *)((*(s32 *)(state+0x30)<<5)+(s32)D_L01_001F1B40))->b = ((color >> 16) & 255) * 0.0078125f;
    }
    if (obj[0x20] != 2 && obj[0x20] != 3 && obj[0x20] != 0) {
        u8 *target;
        *(vu0_q *)&targetpos = *(vu0_q *)(obj+0x10);
        target = (u8 *)func_L01_00450010(&targetpos,1.0471975803375244f,30.0f,-1.0f,-1.0f,0);
        *(u8 **)(state+0x28) = target;
        if (!target || (*(u16 *)(target+0x34)&2) || target[0x20] == 0xFE || target[0x20] == 0xFD ||
            !*(u8 **)(target+0x24) || (*(u8 **)(target+0x24))[0x46] != 5) goto clear_target;
        {
            u8 *data;
            *(vu0_q *)&targetpos = *(vu0_q *)(target+0x10);
            data = func_00382348(*(u8 **)(state+0x28));
            if (data) {
                func_0038CE20(&targetpos, *(u8 **)(state+0x28)+0xE0, *(f32 *)(data+0x10));
                vec_add_ab(&targetpos,&targetpos,*(u8 **)(state+0x28)+0x10);
            }
            if (func_003D3CB0(objpos,&targetpos,2,obj,0)) {
                *(u8 **)(state+0x28) = 0;
                func_L01_004450F0(obj,3,-1);
                if (obj[0x43] != 3) func_003C3A10(obj,3,0,0);
            } else {
                func_L01_004450F0(obj,2,-1);
                func_003C3A10(obj,5,0,8);
            }
        }
        goto search_done;
clear_target:
        *(u8 **)(state+0x28) = 0;
    }
search_done:
    if (obj[0x20] == 2) {
        *(f32 *)(state+0xC) = func_0038DAB8(*(f32 *)(state+0xC),*(f32 *)(state+8));
        bob = func_0038D0B0(*(f32 *)(state+0xC));
        bob *= func_003824E0(0.01f,0.03f);
        *(f32 *)(obj+0x18) += bob;
    } else {
        *(f32 *)(state+0xC) = func_0038DAB8(*(f32 *)(state+0xC),*(f32 *)(state+8));
        bob = func_0038D0B0(*(f32 *)(state+0xC));
        bob *= func_003824E0(0.0025f,0.0075f);
        *(f32 *)(obj+0x18) += bob;
    }
    func_L01_003DA6E8(obj);
    if (*(s32 *)(state+0x3C) >= 11) func_L01_003DABC8(obj);
    return 0;
}
/* localdecomp:end func_L01_003D9FD0 */

/* localdecomp:start func_L01_003DA3F0 */
#include "vu0.h"
typedef int Q_003DA3F0 __attribute__((mode(TI)));
typedef vu0_v4 V_003DA3F0;
extern s32 D_L01_001D6740;
extern s32 D_L01_001D673C;
extern s32 D_L01_001D67B0;
extern s32 D_001D545C_003DA3F0;
__asm__(".extern D_001D545C_003DA3F0, 16");
extern s32 D_L01_001DDBB0;
extern vu0_v4 D_L01_001E29C0;
__asm__(".extern D_L01_001DDBB0, 4");
u8 *func_L01_003DA3F0(u8 *old) {
    extern u8 *func_003C24B0_003DA3F0(s32,s32);
    extern f32 func_003824E0(f32,f32);
    extern void func_L01_003DB3F8_003DA3F0(void);
    extern void func_L01_003DB680_003DA3F0(void *);
    extern void func_L01_00459C50(s32);
    extern void func_L01_004C7D98(void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_0038CE90(void *,void *,void *);
    extern void func_0038D570(void *,void *);
    extern void func_003C48A8(void *,void *);
    extern void func_L01_004443E8(void *,s32,s32);
    extern u8 *func_00382348_003DA3F0(u8 *);
    extern void func_003C2880(u8 *);
    extern void func_L01_004450F0_003DA3F0(u8 *,s32,s32);
    extern void func_003C7C38(void *);
    V_003DA3F0 a,b,c;
    f32 matrix[16] __attribute__((aligned(16)));
    u8 *obj=func_003C24B0_003DA3F0(0x1D3E,0x100);
    u8 *v,*h,*rotation;
    s32 i;
    if (obj) {
        obj[0x30]=127; *(u16 *)(obj+0x32)=127; obj[0x31]=1;
        *(Q_003DA3F0 *)(obj+0x10)=*(Q_003DA3F0 *)(old+0x10);
        v=*(u8 **)(obj+0x68);
        *(f32 *)(v+0)=func_003824E0(4.0f,5.5f);
        *(f32 *)(v+4)=func_003824E0(5.5f,6.5f);
        *(u32 *)(obj+0x78)=0x80808080;
        *(f32 *)(obj+0x2C)=*(f32 *)(*(u8 **)(obj+0x24)+0x24)*0.7f;
        *(f32 *)(v+8)=func_003824E0(0.02617993950843811f,0.06981317698955536f);
        *(s32 *)(v+0x24)=-1;
        *(s32 *)(v+0x30)=-1;
        *(s32 *)(v+0x3C)=0;
        *(s32 *)D_L01_001E2430=50;
        D_L01_001DDBB0=0;
        func_L01_003DB3F8_003DA3F0();
        for(i=63;i>=0;i--) func_L01_003DB680_003DA3F0(&a);
        if(D_001D545C_003DA3F0==5 && *(s16 *)(old+0xAA)==0x19DB) {
            if(++D_L01_001D67B0>=15) func_L01_00459C50(7);
        }
        if(D_L01_001D6740 || D_L01_001D673C) {
            func_L01_004C7D98(obj+0x10,&a);
            rotation=obj+0xF0;
            func_0038CF68(&a,&a,-1.0f);
            vec_sub_ba(&b,&D_L01_001E29C0,obj+0x10);
            func_0038CF68(&b,&b,1.0f);
            func_0038CE90(&b,&b,&a);
            func_0038CE90(&c,&b,&a);
            *(Q_003DA3F0 *)(obj+0xC0)=*(Q_003DA3F0 *)&c;
            *(Q_003DA3F0 *)(obj+0xD0)=*(Q_003DA3F0 *)&b;
            *(Q_003DA3F0 *)(obj+0xE0)=*(Q_003DA3F0 *)&a;
            *(Q_003DA3F0 *)(obj+0xF0)=*(Q_003DA3F0 *)(obj+0x10);
            func_0038D570(matrix,obj+0xC0);
            func_003C48A8(matrix,rotation);
        }
        *(s32 *)(v+0x48)=0;
        *(s32 *)(v+0x4C)=8;
        if(*(u16 *)(obj+0x34)&0x1000) func_L01_004443E8(old,0,3);
        h=func_00382348_003DA3F0(old);
        if(h && h[0xE]==1) h[0xE]=2;
        else func_003C2880(old);
        *(s32 *)(v+0x28)=0;
        *(s32 *)(v+0x20)=2500;
        *(s32 *)(obj+0x98)=*(s32 *)(*(u8 **)(obj+0x24)+0x10);
        func_L01_004450F0_003DA3F0(obj,0,-1);
        if(obj[0x43]!=1) func_003C3A10(obj,1,0,0);
        func_003C7C38(obj);
    }
    return obj;
}
/* localdecomp:end func_L01_003DA3F0 */

/* localdecomp:start func_L01_003DA6E8 */
extern u8 *D_L01_00221098[];
void func_L01_003DA6E8(u8 *obj) {
    extern s32 func_00382498(s32,s32);
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32,f32);
    extern void func_003C2F58(void *,s32,s128_3D8F20 *);
    extern void func_L01_004C7D98(void *,void *);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_0038CF68(void *,void *,f32);
    extern u8 *func_L01_004713C8(void *,void *,s32,s32,s32,s32,s32,s32,f32,f32,f32);
    extern u8 *func_L01_004669B0(void *,s32,void *,s32,s32,f32,f32,f32,f32);
    extern void func_L01_003DB200(void *,void *);
    extern s32 func_0013D3E0(void);
    extern void func_L01_00466F50(void *,void *,s32,f32,f32);
    union {s128_3D8F20 q; f32 v[4];} pos;
    s128_3D8F20 vel,point;
    s32 i,color,kind;
    f32 scale;
    u8 *particle;
    for(i=0;i<8;i++) {
        u8 *particle;
        func_003C2F58(obj,func_00382498(1,13),&pos.q);
        pos.v[0]+=func_003824E0(-0.02f,0.02f);
        pos.v[1]+=func_003824E0(-0.02f,0.02f);
        pos.v[2]+=func_003824E0(-0.02f,0.02f);
        func_L01_004C7D98(obj+0x10,&vel);
        func_0038CE20(&vel,&vel,func_003824E0(0.4f,1.0f)*0.020000001415610313f);
        if(func_00382468(4)) color=func_00382498(64,100)|0x5F404000;
        else color=(func_00382498(150,100)<<16)|0x5F002C2C;
        particle=func_L01_004713C8(&pos,&vel,(func_00382498(10,15)*5+2)/6,color,1,79,0,0,58800.0f,27299.998046875f,0.0f);
        if(particle)particle[2]=D_L01_00221098[0x5B][0];
    }
    func_L01_004C7D98(obj+0x10,&vel);
    func_0038CE20(&vel,&vel,func_003824E0(0.4f,1.0f)*0.020000001415610313f);
    pos.v[0]+=func_003824E0(-0.02f,0.02f);
    pos.v[1]+=func_003824E0(-0.02f,0.02f);
    pos.v[2]+=func_003824E0(-0.02f,0.02f);
    kind=func_00382468(5)+1;
    scale=func_003824E0(0.25f,0.4f)*210000.0f;
    color=func_00382498(64,80)|0x404000;
    particle=func_L01_004669B0(&pos,kind,&vel,color,0,0.0f,0.99f,0.995f,scale);
    if(particle) {
        particle[3]=func_00382468(2)?68:72;
        *(s16 *)(particle+0xA)=2;
    }
    if(obj[0x20]==2) {
        func_003C2F58(obj,0,&point);
        func_L01_003DB200(obj,&point);
    }
    func_003C2F58(obj,17,&point);
    func_0038CF68(&vel,&vel,func_003824E0(0.0025f,0.01f));
    if(func_0013D3E0()%15==0)func_L01_00466F50(&point,&vel,0,-1.0f,0.0f);
}
/* localdecomp:end func_L01_003DA6E8 */

/* localdecomp:start func_L01_003DAAE0 */
extern void func_003C2F58(void *, s32, s128_3D8F20 *);
extern f32 func_003824E0(f32, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
void func_L01_003DAAE0(void *m) {
    s128_3D8F20 v;
    func_003C2F58(m, 14, &v);
    func_003D9508(&v, 11, 0x40202080, 1, func_003824E0(0.09f, 0.16f), 0.08f, 0.0f);
    func_003C2F58(m, 15, &v);
    func_003D9508(&v, 11, 0x40202080, 1, func_003824E0(0.09f, 0.16f), 0.08f, 0.0f);
}
/* localdecomp:end func_L01_003DAAE0 */

/* localdecomp:start func_L01_003DABC8 */
typedef struct { u8 p0[0x140]; f32 x, y; } Camera_003DABC8;
typedef struct { u8 p0[0x6C]; f32 power; u8 p70[0xF0 - 0x70]; } Weapon_003DABC8;
typedef struct {
    vu0_v4 direction;
    u8 p10[8]; u8 kind, mode; u16 cls;
    s32 w1C, flags; u8 p24[12];
} Damage_003DABC8;
extern Camera_003DABC8 D_L01_001E2880;
extern u8 D_001425C0[];
extern Weapon_003DABC8 D_L01_002C5600_003DABC8[];
extern u8 *D_L01_001EEA80[];
extern s32 D_L01_001DAFEC;
__asm__(".extern D_L01_001E2430, 16");
extern s32 D_L01_001DDBB0_003DABC8;
void func_L01_003DABC8(u8 *self) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_004668A0(void *, void *, u32, u32, s32, f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_L01_00471BF0(void *, void *, s32);
    extern void func_L01_003D6158(void *, s32, s32, s32, s32, f32, f32);
    extern void func_L01_003002A8(void *, void *, void *);
    extern void *func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
        s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    extern s32 func_003A52A0(s32, s32, void *);
    extern s32 func_003D4D00(void *, s32, f32, void *, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern void func_L01_00446978(void *, void *);
    extern void func_L01_00424D88(s32);
    extern void func_003C2880(void *);
    vu0_v4 velocity, position;
    Damage_003DABC8 damage;
    u8 *vars = *(u8 **)(self + 0x68);
    s32 i, count;

    u8 **list;
    for (i = 29; i >= 0; --i) {
        f32 speed, yaw, pitch;
        speed = func_003824E0(0.0f, 0.37f);
        yaw = func_00382538();
        func_00382760(&position, speed, yaw, func_00382538());
        position.z += func_003824E0(0.35f, 0.6f);
        vec_add_ba(&position, &position, self + 0x10);
        speed = func_003824E0(0.0030000002589076757f, 0.024000002071261406f);
        yaw = func_00382538();
        func_00382760(&velocity, speed, yaw, func_00382538());
        func_L01_004668A0(&position, &velocity, 0x4F7F7F7F, 0x202020, func_00382498(25, 47), 150000.0f);
    }
    {
    u8 *place = self + 0x10;
    for (i = 49; i >= 0; --i) {
        f32 yaw, speed, pitch, angle;
        yaw = func_0038D160(D_L01_001E2880.x - *(f32 *)(self + 0x10), D_L01_001E2880.y - *(f32 *)(self + 0x14));
        func_L01_00443A18(1.0f, 2.0f);
        velocity.x = *(f32 *)(self + 0x10) + func_L01_00443A18(0.0f, 0.15f);
        velocity.y = *(f32 *)(self + 0x14) + func_L01_00443A18(0.0f, 0.15f);
        velocity.z = *(f32 *)(self + 0x18) + func_L01_00443A18(0.0f, 0.15f);
        speed = func_003824E0(3.0f, 7.0f);
        pitch = func_L01_00443A18(0.0f, 2.6179938316345215f);
        speed *= 0.020000001415610313f;
        angle = func_0038DAB8(yaw, pitch);
        position.x = func_0038D098(angle) * speed;
        position.y = func_0038D0B0(angle) * speed;
        position.z = 0.0f;
        position.z = func_003824E0(5.0f, 10.0f) * 0.020000001415610313f;
        func_L01_00471BF0(&velocity, &position, 0x8E);
    }
    func_L01_003D6158(self, 0x4E, 0x4F, 10, 1, 1.5f, 1.2f);
    for (i = 9; i >= 0; --i) {
        f32 speed, yaw, pitch;
        speed = func_003824E0(0.0f, 0.35f);
        yaw = func_00382538();
        func_00382760(&position, speed, yaw, func_00382538());
        position.z += 0.25f;
        vec_add_ba(&position, &position, self + 0x10);
        { f32 next_speed = func_003824E0(0.06000000238418579f, 0.12000000476837158f);
        f32 next_yaw = func_00382538();
        func_00382760(&velocity, next_speed, next_yaw, 1.2217304706573486f); }
        velocity.z = func_003824E0(3.0f, 5.0f) * 0.020000001415610313f;
        func_L01_003002A8(self, &position, &velocity);
    }
    func_L01_003303B8(place, 1, 25, 20, 20, 20, 45, 2, 0.8f, 0.0f, 0.0f, 0.0f,
        0, 1, 1, 0, 0, 0, 0x10000, D_L01_001DAFEC, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_003A52A0(3, 0, self);
    count = func_003D4D00(place, 0, 3.0f, self, 0);
    if (count > 0) {
        s32 remaining;
        list = D_L01_001EEA80;
        remaining = count;
        do {
            u8 *moby = *list;
            if ((*(u8 **)(moby + 0x24))[0x46] == 5 || (*(u16 *)(moby + 0x34) & 0x4000)) {
                vec_sub_ba(&velocity, moby + 0x10, self + 0x10);
                func_0038CF68(&velocity, &velocity, 1.0f);
                func_0038CF68(&damage, &damage, 1.0f);
                func_L01_00446760(&damage, self, 0x1010000, &velocity, ((Weapon_003DABC8 *)((u32)D_L01_002C5600_003DABC8 + D_001425C0[0x8F] * sizeof(Weapon_003DABC8)))->power * 0.2f);
                damage.flags = 1;
                *(vu0_q *)&damage.direction = *(vu0_q *)&velocity;
                damage.direction.w = 5627.9248046875f;
                damage.kind = 5;
                damage.mode = 3;
                damage.cls = *(u16 *)(moby + 0xAA);
                func_L01_00446978(moby, &damage);
            }
            --remaining;
            ++list;
        } while (remaining);
    }
    if (*(s32 *)(vars + 0x30) != -1) {
        func_L01_00424D88(*(s32 *)(vars + 0x30));
        *(s32 *)(vars + 0x30) = -1;
    }
    D_L01_001DDBB0_003DABC8 = 1;
    *(s32 *)D_L01_001E2430 = 50;
    func_003C2880(self);
    }
}
/* localdecomp:end func_L01_003DABC8 */

/* localdecomp:start func_L01_003DB200 */
#include "vu0.h"
extern vu0_v4 D_001A4EC0;
void func_L01_003DB200(u8 *obj, vu0_q *position) {
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_0013D3E0(void);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    vu0_v4 input;
    vu0_v4 velocity;
    vu0_v4 pos;
    vu0_v4 delta;
    s32 count, frames, mode, intensity;
    s32 i;
    u32 color;
    f32 speed;
    *(vu0_q *)&input = *position;
    *(vu0_q *)&pos = *(vu0_q *)&input;
    vec_sub_ab(&delta, obj + 0x10, &input);
    func_0038CF68(&delta, &delta, 0.1f);
    i = 9;
    while (i >= 0) {
        u8 *particle;
        {
            f32 n = func_L01_00443A18(1.0f, 3.0f);
            count = n;
        }
        {
            f32 scale = func_003824E0(0.2f, 1.0f);
            func_0038CE20(&velocity, &D_001A4EC0, -(scale * 0.020000001415610313f));
        }
        frames = func_00382498(30, 55);
        {
            f32 s = func_003824E0(200.0f, 1000.0f);
            speed = s;
        }
        {
            s32 r = func_0013D3E0();
            if (r & 2) { color = 0x104080; intensity = 64; speed += speed; }
            else { color = 0x4080FF; intensity = 80; }
        }
        particle = func_L01_0046A610(&pos, &velocity, (frames * 5 + 2) / 6, intensity, color, count, 31500.001953125f, speed, 1.0f, 0.0f, 0.0f);
        vec_add_ab(&pos, &pos, &delta);
        if (particle) {
            u8 *tex = D_L01_00221098[0x17];
            particle[2] = tex[0];
            particle[3] = intensity == 80 ? 0x48 : 0x44;
        }
        i--;
    }
}
/* localdecomp:end func_L01_003DB200 */

/* localdecomp:start func_L01_003DB3F8 */
extern u8 D_L01_002A2E40_003DB3F8[];

void func_L01_003DB3F8(void) {
    s32 i;
    u8 *h = D_L01_002A2E40_003DB3F8;

    for (i = 0; i < 64; i++) {
        *(s32 *)(h + i * 0x30 + 0x20) = 0;
    }
}
/* localdecomp:end func_L01_003DB3F8 */

/* localdecomp:start func_L01_003DB428 */
typedef struct {
    u128_t position;           /* 0x00 */
    u8 pad_10[0x20 - 0x10];
    s32 active;                /* 0x20 */
    u8 pad_24[0x28 - 0x24];
    f32 phase;                 /* 0x28 */
    u8 pad_2C[0x30 - 0x2C];
} Duck_3DB428;

/* The V5 ducks in flight, 64 slots */
extern Duck_3DB428 D_L01_002A2E40[];
extern f32 func_0038D0B0(f32 angle);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern void func_L01_003DB768(void *position, s32 texture, s32 blend, f32 size, f32 a, f32 b, f32 c);

/* qwack_duck_v5_star_draw: draws each V5 Qwack-O-Ray duck in flight: two stars of texture 57
   turning both ways, pulsing with the duck's phase, and a 0x3B glow */
void func_L01_003DB428(void) {
    s32 i;

    for (i = 0; i < 64; i++) {
        if (D_L01_002A2E40[i].active != 0) {
            Duck_3DB428 *duck = &D_L01_002A2E40[i];

            func_003D9508(duck, 0x39, 0x207F7F8F, 1, func_0038D0B0(duck->phase) * 0.25f + 0.5f, -0.1f, duck->phase);
            func_003D9508(duck, 0x39, 0x207F7F8F, 1, func_0038D0B0(duck->phase) * 0.25f + 0.5f, -0.1f, -duck->phase);
            func_L01_003DB768(duck, 0x3B, 1, (func_0038D0B0(duck->phase) * 0.7f + 0.75f) * 0.1f, 0.2f, 0.0f, 0.005f);
        }
    }
}
/* localdecomp:end func_L01_003DB428 */

/* localdecomp:start func_L01_003DB588 */
extern Duck_3DB428 D_L01_002A2E40[64];
void func_L01_003DB588(u8 *obj) {
    extern void func_L01_004C7D98(void *,void *);
    extern void func_0038D890(void *,void *,void *,f32);
    extern f32 func_0038DAB8(f32,f32);
    extern void func_L01_003DB428(void);
    extern void func_L01_00404A10_003DB588(void (*)(void),void *);
    vu0_v4 base;
    vu0_v4 temp;
    Duck_3DB428 *p;
    Duck_3DB428 *end;
    u8 *dir;
    f32 c;
    s32 address;
    func_L01_004C7D98(obj+0x10,&base);
    address=(s32)D_L01_002A2E40;
    dir=(u8 *)(address+0x10);
    p=(Duck_3DB428 *)address;
    end=(Duck_3DB428 *)((u8 *)p+0xC00);
    do {
        if (p->active) {
            func_0038D890(&temp,dir,&base,p->phase);
            vec_add_ab(p,&temp,obj+0x10);
            p->phase=func_0038DAB8(p->phase,*(f32 *)((u8 *)p+0x24));
            c=func_0038D0B0(p->phase);
            c*=func_003824E0(0.01f,0.015f);
            *(f32 *)((u8 *)p+8)+=c;
        }
        p++;
        dir+=0x30;
    } while ((s32)p<(s32)end);
    func_L01_00404A10_003DB588(func_L01_003DB428,obj);
}
/* localdecomp:end func_L01_003DB588 */

/* localdecomp:start func_L01_003DB680 */
void func_L01_003DB680(void) {
    extern f32 func_003824E0(f32, f32);
    Duck_3DB428 *p = D_L01_002A2E40;
    Duck_3DB428 *end = (Duck_3DB428 *)((u8 *)p + 0xC00);
    do {
        if (!p->active) {
            p->active = 1;
            *(f32 *)((u8 *)p + 0x10) = func_003824E0(-0.65f, 0.65f);
            *(f32 *)((u8 *)p + 0x14) = func_003824E0(-0.65f, 0.65f);
            *(f32 *)((u8 *)p + 0x18) = func_003824E0(0.3f, 1.0f);
            *(f32 *)((u8 *)p + 0x1C) = 1.0f;
            *(f32 *)((u8 *)p + 0x24) = func_003824E0(0.10471975803375244f, 0.19198623299598694f);
            break;
        }
        p++;
    } while ((s32)p < (s32)end);
}
/* localdecomp:end func_L01_003DB680 */

/* localdecomp:start func_L01_003DB768 */
#include "vu0.h"
typedef struct {
    vu0_v4 v[4]; u32 color[4]; f32 uv[4][2];
    u8 pad70[0x18]; unsigned long tag;
} Draw_003DB768;
typedef struct {
    Draw_003DB768 draw;
    vu0_v4 basis[3]; vu0_v4 pos; vu0_v4 delta; vu0_v4 matrix[3];
} Work_003DB768;
extern vu0_v4 D_L01_001E29C0;
extern vu0_v4 D_001A4EC0;
extern vu0_v4 D_L01_001D7C50[];
void func_L01_003DB768(void *position, s32 texture, s32 blend, f32 size, f32 offset, f32 angle, f32 jitter) {
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038D308(void *, void *);
    extern void func_0038D5F0(void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003A9440(s32, unsigned long);
    extern void func_003D2DA0(void *, s32, s32);
    extern void func_00389478(void *, f32 *, f32 *);
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    Work_003DB768 w;
    s32 i;
    func_003D93B0(&w.draw, texture, 1, 0x80);
    w.draw.tag = 0x800000004A;
    w.draw.color[3] = 0x80808080;
    w.draw.color[2] = 0x80808080;
    w.draw.color[1] = 0x80808080;
    w.draw.color[0] = 0x80808080;
    *(u128_t *)&w.pos = *(u128_t *)position;
    w.draw.uv[0][0] = 0; w.draw.uv[0][1] = 0;
    w.draw.uv[1][0] = 0; w.draw.uv[1][1] = 1;
    w.draw.uv[2][0] = 1; w.draw.uv[2][1] = 0;
    w.draw.uv[3][0] = 1; w.draw.uv[3][1] = 1;
    vec_sub_ab(&w.basis[0], &D_L01_001E29C0, &w.pos);
    func_0038CF68(&w.basis[0], &w.basis[0], 1.0f);
    func_0038CE90(&w.basis[1], &w.basis[0], &D_001A4EC0);
    func_0038CF68(&w.basis[1], &w.basis[1], 1.0f);
    func_0038CE90(&w.basis[2], &w.basis[1], &w.basis[0]);
    if (angle != 0.0f) {
        *(u128_t *)&w.delta = 0;
        w.delta.x = angle;
        func_0038D308(w.matrix, &w.delta);
        func_0038D5F0(w.basis, w.basis, w.matrix);
    }
    func_0038CE20(&w.delta, w.basis, offset);
    vec_add_ab(&w.pos, &w.pos, &w.delta);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&w.draw.v[i], &D_L01_001D7C50[i], size);
        func_0038D028(&w.draw.v[i], &w.draw.v[i], w.basis);
    }
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&w.draw, 0, 0);
    if (blend) {
        s32 k;
        s32 j;
        *(u128_t *)&w.matrix[0] = *(u128_t *)&w.draw.v[0];
        for (k = 1; k < 4; k++) vec_add_ba(&w.matrix[0], &w.matrix[0], &w.draw.v[k]);
        func_0038CE20(&w.matrix[0], &w.matrix[0], 0.25f);
        for (j = 0; j < 4; j++) {
            vec_sub_ba(&w.matrix[1], &w.draw.v[j], &w.matrix[0]);
            func_0038CE20(&w.matrix[1], &w.matrix[1], 2.0f);
            vec_add_ab(&w.matrix[1], &w.matrix[0], &w.matrix[1]);
            func_00389478(&w.matrix[1], &w.draw.uv[j][0], &w.draw.uv[j][1]);
            if (!func_00382468(1)) {
                w.draw.uv[j][0] += func_003824E0(-jitter, jitter);
                w.draw.uv[j][1] += func_003824E0(-jitter, jitter);
            }
            if (w.draw.uv[j][0] > 1.0f) w.draw.uv[j][0] = 1.0f;
            else if (w.draw.uv[j][0] < 0.0f) w.draw.uv[j][0] = 0.0f;
            if (w.draw.uv[j][1] > 1.0f) w.draw.uv[j][1] = 1.0f;
            else if (w.draw.uv[j][1] < 0.0f) w.draw.uv[j][1] = 0.0f;
        }
    } else {
        s32 j;
        for (j = 0; j < 4; j++) {
            func_00389478(&w.draw.v[j], &w.draw.uv[j][0], &w.draw.uv[j][1]);
            if (!func_00382468(1)) {
                w.draw.uv[j][0] += func_003824E0(-jitter, jitter);
                w.draw.uv[j][1] += func_003824E0(-jitter, jitter);
            }
            if (w.draw.uv[j][0] > 1.0f) w.draw.uv[j][0] = 1.0f;
            else if (w.draw.uv[j][0] < 0.0f) w.draw.uv[j][0] = 0.0f;
            if (w.draw.uv[j][1] > 1.0f) w.draw.uv[j][1] = 1.0f;
            else if (w.draw.uv[j][1] < 0.0f) w.draw.uv[j][1] = 0.0f;
        }
    }
    func_003D93B0(&w.draw, -1, 6, 0x80);
    func_003A9440(0x47, 0x53001);
    func_003D2DA0(&w.draw, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L01_003DB768 */

/* localdecomp:start func_L01_003DBC60 */
extern u8 D_L01_001DF538[8];
__asm__(".extern D_L01_001DF538, 8");

u8 *func_L01_003DBC60(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 0) {
        *a2 = 4;
        return D_L01_001DF538;
    }
    return 0;
}
/* localdecomp:end func_L01_003DBC60 */

/* localdecomp:start func_L01_003DBC80 */
typedef struct {
    vu0_v4 position;
    u8 pad10[8];
    u8 kind, pad19;
    u16 cls;
    s32 pad1C;
    u32 flags;
    u8 pad24[12];
} Damage_003DBC80;
typedef struct {
    vu0_q direction;
    f32 life;
    s32 ticks, flag, state;
    f32 length;
    s32 lead, target;
} Vars_003DBC80;
typedef struct {
    u8 pad0[0xD0]; u8 active; u8 padD1[11]; u8 *owner;
} Handle_003DBC80;
extern u8 D_001A30B0[];
extern u8 *D_L01_001EEA80[];
extern s32 D_001A71A0[];
extern f32 D_L01_001DF500;
extern f32 D_L01_001DF504;
extern f32 D_L01_001DF508;
extern s32 D_L01_001DF50C;
extern s32 D_L01_001DF510;
extern f32 D_L01_001DF514;
extern f32 D_L01_001DF51C;
extern s32 D_L01_001DF528;
extern s32 D_L01_001DF530;
extern s32 D_L01_001DF534;
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DF500, 4");
__asm__(".extern D_L01_001DF504, 4");
__asm__(".extern D_L01_001DF508, 4");
__asm__(".extern D_L01_001DF50C, 4");
__asm__(".extern D_L01_001DF510, 4");
__asm__(".extern D_L01_001DF514, 4");
__asm__(".extern D_L01_001DF51C, 4");
__asm__(".extern D_L01_001DF530, 4");
__asm__(".extern D_L01_001DF534, 4");
__asm__(".extern D_L01_001DF528, 4");
static __inline__ s32 weak_003DBC80(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0x68);
    return *(s32 *)(vars + 0xE8) > *(s32 *)(vars + 0xE4);
}
void func_L01_003DBC80(void *object) {
    extern s32 func_003A52A0(s32, s32, void *);
    extern void func_003A4F28(s32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern void func_L01_003DC780(void *, void *);
    extern void func_L01_003DC400(u8 *, u8 *, void *);
    extern void func_L01_00446760(void *, void *, u32, void *, f32);
    extern void func_L01_00446978(void *, void *);
    extern f32 func_00382538(void);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_003D4D00(void *, s32, f32, void *, s32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_0038CAD0(void *);
    extern void func_003C2880(u8 *);
    extern s32 func_L01_00470150(void *, void *, u32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern void *func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
        s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    struct { vu0_q next; Damage_003DBC80 hit; vu0_v4 temp; Damage_003DBC80 special; } w;
    Handle_003DBC80 *handle;
    f32 desired;
    u8 *self;
    Vars_003DBC80 *v;
    s32 count, i;
    s32 weak;
    u8 **list;
    u8 *other;
    u8 *owner;
    f32 range;
    u32 color;
    f32 scale;
    s32 now;
    self = object;
    v = *(Vars_003DBC80 **)(self + 0x68);
    if (v->lead) {
        if (v->target == -1) goto acquire;
        handle = (Handle_003DBC80 *)(D_001A30B0 + (v->target << 7));
        if (handle->owner == self && handle->active != 0) goto acquired;
acquire:
        v->target = func_003A52A0(0, 4, self);
    acquired:;

    }
    desired = D_L01_001DF500;
    if (v->length < desired) {
        v->length += D_L01_001DF504;
        if (v->length > desired) v->length = desired;
    } else if (v->length > desired) {
        v->length -= D_L01_001DF508;
        desired = D_L01_001DF500;
    if (v->length < desired) v->length = D_L01_001DF500;
    }
    if (*(u16 *)(self + 0xB2) & 1) *(f32 *)(self + 0xF0) = func_0038DAB8(*(f32 *)(self + 0xF0), D_L01_001DF51C);
    else *(f32 *)(self + 0xF0) = func_0038DB00(*(f32 *)(self + 0xF0), D_L01_001DF51C);
    func_L01_003DC780(self, v);
    vec_add_ba(&w.next, self + 0x10, &v->direction);
    func_L01_00446760(&w.hit, *(void **)(self + 0xB8), 0x20000001, v, v->life);
    w.hit.kind = 3;
    w.hit.cls = *(u16 *)(self + 0xAA);
    w.hit.position.x = func_0038D098(func_00382538()) * 4.000000476837158f;
    w.hit.position.y = func_0038D0B0(func_00382538()) * 4.000000476837158f;
    w.hit.position.z = 0.0f;
    w.hit.position.w = 5627.9248046875f;
    w.hit.flags |= 1;
    if (v->ticks > D_L01_001DF510 && !v->flag) {
        if (!weak_003DBC80(*(u8 **)(self + 0xB8))) {
            range = (f32)(D_L01_001DF510 + 12);
            func_0038CE20(&w.temp, v, range);
            vec_add_ab(&w.temp, &w.temp, self + 0x10);
            if (func_003D4D00(self + 0x10, 0x11, D_L01_001DF514 * 1.5f, *(void **)(self + 0xB8), 0)) {
                v->ticks = func_00382498(D_L01_001DF50C, D_L01_001DF510);
            } else {
                func_0038CE20(&w.temp, v, range * 0.5f);
                vec_add_ab(&w.temp, &w.temp, self + 0x10);
                if (func_003D4D00(self + 0x10, 0x11, D_L01_001DF514 * 1.5f, *(void **)(self + 0xB8), 0))
                    v->ticks = func_00382498(D_L01_001DF50C, D_L01_001DF510) / 2;
            }
        }
    }
    count = func_003D4D00(self + 0x10, 0x11, D_L01_001DF514, *(void **)(self + 0xB8), 0);
    if (count == 0 && func_0038CAD0(&v->ticks) == 0) goto no_collision;
    {
        weak = weak_003DBC80(*(u8 **)(self + 0xB8));
        for (i = 0; i < count; i++) {
            other = D_L01_001EEA80[i];
            if (*(s16 *)(other + 0xAA) == 0x1AE6) {
                if (weak) {
                    func_L01_00446760(&w.special, *(void **)(self + 0xB8), 1, v, 9999.0f);
                    w.special.kind = 3;
                    w.special.cls = *(u16 *)(self + 0xAA);
                    func_L01_00446978(other, &w.special);
                }
            } else func_L01_00446978(other, &w.hit);
        }
        func_L01_003303B8(self + 0x10, 0, 20, 15, 15, 15, 35, 0, 1.75f, 0.0f, 0.0f, 2.0f,
            0, 0, 0, 0, 0, 1, 0x01010000, 0, 0x00388EF7, 0x63F7, 0x00407FFF, 0x20FF, 0x8FFF, 0x003064FF,
            0x7F60A0FF, 0x280000FF, 0x003064FF, 0);
        if (v->target != -1) {
            handle = (Handle_003DBC80 *)(D_001A30B0 + (v->target << 7));
            if (handle->owner == self && handle->active) func_003A4F28(v->target);
        }
        now = D_L01_001DFB40;
        v->target = -1;
        if (now + D_L01_001DF534 < D_L01_001DF530) D_L01_001DF528 = -1;
        if (D_L01_001DF530 < now || count) {
            func_003A52A0(1, 0, self);
            D_L01_001DF530 = D_L01_001DFB40 + D_L01_001DF534;
        }
        func_003C2880(self);
        return;
    }
no_collision:
    {
        if (!v->state) {
            if (v->flag && v->flag == D_001A71A0[0]) { color = 0x7F0000FF; scale = 3.0f; }
            else { color = 0x7F10203F; scale = 2.25f; }
            qzero(&w.temp);
            w.temp.x = -1.2f;
            v->state = func_L01_00470150(&w.temp, self, color, -1, 1, -1, 0, *(s16 *)(self + 0x32), 0, 0, scale * 210000.0f, -0.1f, 1.0f);
        }
        func_L01_003DC400(self, (u8 *)v, &w.next);
        *(vu0_q *)(self + 0x10) = w.next;
    }
}
/* localdecomp:end func_L01_003DBC80 */

/* localdecomp:start func_L01_003DC268 */
typedef struct {
    u128_t direction;
    f32 life;
    s32 ticks;
    s32 flag;
    s32 state;
    f32 length;
    s32 lead;
    s32 target;
} Vars_003DC268;
typedef struct {
    u8 pad0[16];
    u128_t position;
    u8 pad20[4];
    u8 *cls;
    u8 pad28[4];
    f32 scale;
    u8 opacity;
    u8 mode;
    u16 flags;
    u8 pad34[0x34];
    Vars_003DC268 *vars;
    u8 pad6C[0x4C];
    void *parent;
    u8 padBC[4];
    u8 matrix[0x30];
    f32 rotation[4];
} Obj_003DC268;
extern s32 D_L01_001DF4F8;
extern s32 D_L01_001DF4FC;
extern s32 D_L01_001DF528;
extern s32 D_L01_001DF52C;
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DF4F8, 4");
__asm__(".extern D_L01_001DF4FC, 4");
__asm__(".extern D_L01_001DF528, 4");
__asm__(".extern D_L01_001DF52C, 4");
Obj_003DC268 *func_L01_003DC268(void *parent, s32 flag, u128_t *pos, f32 *dir, f32 life) {
    extern Obj_003DC268 *func_003C24B0(s32, s32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    extern void func_0038D308(void *, void *);
    extern f32 func_0038CEA8(void *);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_003C7C38(void *);
    Obj_003DC268 *obj;
    Vars_003DC268 *v;
    s32 end;
    s32 now;
    obj = func_003C24B0(7556, 128);
    if (obj) {
        v = obj->vars;
        obj->parent = parent;
        v->flag = flag;
        obj->opacity = 255;
        obj->flags = 128;
        obj->mode = 1;
        obj->scale = *(f32 *)(obj->cls + 36) * 0.75f;
        obj->position = *pos;
        obj->rotation[1] = -func_0038D160(func_0038CED8(dir), dir[2]);
        obj->rotation[2] = func_0038D160(dir[0], dir[1]);
        func_0038D308(obj->matrix, obj->rotation);
        v->direction = *(u128_t *)dir;
        v->length = func_0038CEA8(dir);
        v->life = life;
        if (v->flag) v->ticks = D_L01_001DF4F8 * 2;
        else v->ticks = func_00382498(D_L01_001DF4FC, D_L01_001DF4F8);
        now = D_L01_001DFB40;
        v->target = -1;
        v->state = 0;
        end = now + D_L01_001DF52C;
        if (end < D_L01_001DF528) D_L01_001DF528 = -1;
        if (D_L01_001DF528 < now) {
            v->lead = 1;
            D_L01_001DF528 = end;
        } else v->lead = 0;
        func_L01_004450F0(obj, 1, -1);
        func_003C7C38(obj);
    }
    return obj;
}
/* localdecomp:end func_L01_003DC268 */

/* localdecomp:start func_L01_003DC400 */
#include "vu0.h"
extern f32 D_L01_001DF518;
extern s32 D_001A71A0[];
__asm__(".extern D_L01_001DF518, 4");
void func_L01_003DC400(u8 *obj, u8 *hit, void *point) {
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CEA8(void *);
    extern s32 func_00382498(s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern void func_L01_004669B0(void *, s32, void *, s32, s32, f32, f32, f32, f32);
    extern void func_L01_004668A0(void *, void *, s32, s32, s32, f32);
    vu0_v4 old, velocity, pos, delta;
    s32 shade, color, choice, rgb, blue, low, high;
    f32 length;
    f32 size;
    *(u128_t *)&old = *(u128_t *)point;
    *(u128_t *)&pos = *(u128_t *)(obj + 0x10);
    func_0038CE20(&pos, obj + 0xC0, -1.2f);
    vec_add_ab(&pos, &pos, obj + 0x10);
    length = func_0038CEA8(hit);
    func_0038CE20(&velocity, obj + 0xC0, length * D_L01_001DF518);
    shade = func_00382498(32, 64);
    { s32 red = shade + 8;
    s32 green = shade << 8;
    green |= 0x7F000000;
    red <<= 16;
    red |= green;
    color = red | shade; }
    choice = func_00382498(0, 2) - 1;
    func_L01_004669B0(&pos, choice, &velocity, color, 0, 0.25f, 0.8f, 1.01f, func_003824E0(1.5f, 2.0f) * 210000.0f);
    vec_sub_ba(&delta, obj + 0x10, &old);
    func_0038CE20(&delta, &delta, 0.5f);
    vec_add_ab(&pos, &pos, &delta);
    shade = func_00382498(64, 128);
    low = (shade << 8) | 0x40000000;
    rgb = (shade << 16) | low;
    color = rgb | shade;
    size = func_003824E0(2.0f, 2.5f) * 210000.0f;
    func_L01_004668A0(&pos, &velocity, color, 0x101010, (func_00382498(25, 30) * 5 + 2) / 6, size);
    if (*(s32 *)(hit + 0x18) != 0 && *(s32 *)(hit + 0x18) == D_001A71A0[0]) {
        color = rgb | (shade << 1);
        size = func_003824E0(2.5f, 3.0f) * 210000.0f;
        func_L01_004668A0(&pos, &velocity, color, 0x101010, (func_00382498(25, 30) * 5 + 2) / 6, size);
    }
}
/* localdecomp:end func_L01_003DC400 */

/* localdecomp:start func_L01_003DC690 */
#include "vu0.h"
void func_L01_003DC690(u8 *m, u8 *out, vu0_q *target, f32 rate) {
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_L01_00448690(void *, s32, f32, f32);
    extern void func_0038D308(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    vu0_v4 pos;
    vu0_v4 delta;
    f32 pitch;
    f32 yaw;
    pos = *(vu0_v4 *)target;
    vec_sub_ba(&delta, &pos, m + 0x10);
    if (delta.z < 3.0f) pitch = -1.5707963705062866f;
    else pitch = -func_0038D160(func_0038CED8(&delta), delta.z);
    func_L01_00448690(m + 0xF4, 0, pitch, rate);
    yaw = func_0038D160(delta.x, delta.y);
    func_L01_00448690(m + 0xF8, 0, yaw, rate);
    func_0038D308(m + 0xC0, m + 0xF0);
    func_0038CE20(out, m + 0xC0, *(f32 *)(out + 0x20));
}
/* localdecomp:end func_L01_003DC690 */

INCLUDE_ASM("asm/levels", func_L01_003DC780);

INCLUDE_ASM("asm/levels", func_L01_003DCAA0);

LINKER_REMNANT("asm/levels", func_L01_003DD0F0);

/* localdecomp:start func_L01_003DD0F8 */
#include "structs/weapon.h"
typedef vu0_v4 V_003DD0F8;
typedef int Q_003DD0F8 __attribute__((mode(TI)));
typedef struct {
    u8 pad_0[0x10];
    V_003DD0F8 pos;
    u8 state;
    u8 pad_21[0x31 - 0x21];
    u8 b31;
    u8 pad_32[0x34 - 0x32];
    u16 flags;
} Tg_003DD0F8;
typedef struct {
    u8 pad_0[0x10];
    Q_003DD0F8 pos;
} Owner_003DD0F8;
typedef struct {
    f32 aim_x, aim_y, aim_z;
    Owner_003DD0F8 *owner;   /* 0x0C */
    Q_003DD0F8 hist[4];      /* 0x10 */
    V_003DD0F8 sun;          /* 0x50 */
    Tg_003DD0F8 *target;     /* 0x60 */
    u8 pad_64[4];
    f32 speed;               /* 0x68 */
    f32 turn;                /* 0x6C */
    f32 spin_rate;           /* 0x70 */
    s16 timer;               /* 0x74 */
    u8 pad_76;
    u8 trail;                /* 0x77 */
    f32 spin;                /* 0x78 */
    u8 pad_7C[4];
    Q_003DD0F8 dir;          /* 0x80 */
    u8 pad_90[0x10];
    s32 sound;               /* 0xA0 */
    s32 shadow;              /* 0xA4 */
    s16 life;                /* 0xA8 */
    u8 pad_AA[0xBC - 0xAA];
    s32 sun_pending;         /* 0xBC */
} Shot_003DD0F8;
typedef struct {
    u8 pad_0[0x10];
    Q_003DD0F8 pos;
    u8 pad_20[0x34 - 0x20];
    u16 flags;
    u8 pad_36[0x68 - 0x36];
    Shot_003DD0F8 *pvar;
    u8 pad_6C[0xAA - 0x6C];
    s16 oclass;
    u8 pad_AC[0xBC - 0xAC];
    u8 hit;
    u8 pad_BD[0xC0 - 0xBD];
    V_003DD0F8 right;        /* 0xC0 */
    V_003DD0F8 fwd;          /* 0xD0 */
    V_003DD0F8 up;           /* 0xE0 */
    u8 pad_F0[8];
    f32 yaw;                 /* 0xF8 */
} M_003DD0F8;
typedef struct {
    V_003DD0F8 v;
    s32 moby;
    s32 flags;
    u8 b18;
    u8 b19;
    s16 oclass;
    f32 damage;
    s32 w20;
    u8 pad_24[0xC];
} Dmg_003DD0F8;
typedef struct {
    u8 pad_0[0x18];
    void *moby;
    s32 w1C;
    Q_003DD0F8 pos;
    u8 pad_30[0x10];
    V_003DD0F8 normal;
} Hit_003DD0F8;
typedef struct {
    u8 pad_0[0x25C0];
    void *body;
} Hero_003DD0F8;
typedef struct { u8 b[0x80]; } Snd80_003DD0F8;
extern Hit_003DD0F8 D_L01_001EAA00_003DD0F8;
extern V_003DD0F8 D_L01_001E29C0_003DD0F8;
extern Hero_003DD0F8 D_001A4BE0_003DD0F8;
extern Snd80_003DD0F8 D_001A30B0_003DD0F8[];
extern struct WeaponRow D_L01_002C5600_003DD0F8[];
extern s16 D_L01_001E0140[] __attribute__((section(".sdata")));

static __inline__ void qcopy_003DD0F8(void *d, void *s) {
    *(Q_003DD0F8 *)d = *(Q_003DD0F8 *)s;
}

/* ryno_missile_v2_update: the v1 missile's update (func_L01_00384518) with the trail history, the
 * sun spawn and the seeker blast. */
void func_L01_003DD0F8(M_003DD0F8 *m) {
    extern void func_003C5180(void *, void *, s32);
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern u8 *func_00382348(void *);
    extern void func_L01_004C8688(s32, void *, s32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D850(void *, void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038CF00(void *, void *);
    extern void func_L01_004CB128(void *, void *, s32);
    extern void func_L01_003DEFE8(void *);
    extern void func_L01_0044BEC8(void *, s16 *);
    extern void func_L01_003DE418();
    extern void func_L01_003DE488();
    extern void func_L01_00404A10(void *, void *);
    extern void func_L01_003DE1D8();
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_003C3D30(void *, s32, s32, f32);
    extern void func_L01_003DDDA8();
    extern void func_L01_004C8668(s32);
    extern void func_003C2880(void *);
    extern s32 func_0038CB00(s16 *);
    extern f32 func_0038CF38(void *, void *);
    extern void func_003A4F28(s32);
    V_003DD0F8 start;
    V_003DD0F8 out[2];
    V_003DD0F8 q;
    V_003DD0F8 d;
    V_003DD0F8 e;
    V_003DD0F8 f;
    Dmg_003DD0F8 dmg;
    V_003DD0F8 dir;
    V_003DD0F8 n;
    V_003DD0F8 v;
    void *skip;
    Shot_003DD0F8 *w;
    Tg_003DD0F8 *t;
    f32 *info;
    s32 ok;
    s32 i;

    w = m->pvar;
    t = w->target;
    *(Q_003DD0F8 *)&start = m->pos;
    skip = 0;
    func_003C5180(&m->pos, out, 1);
    if (func_L01_004CB2D8() != 0) {
        func_L01_004CAB30(&m->pos, &m->pos);
    }
    if (func_0038CAD0(&w->life) == 0) {
        m->pos = w->owner->pos;
        return;
    }
    for (i = 3; i > 0; i--) {
        func_0038CDF8(&w->hist[i], &w->hist[i], &w->hist[i - 1], 0.2f);
    }
    w->hist[0] = m->pos;
    if (t != 0) {
        info = (f32 *)func_00382348(t);
        if ((t->flags & 2) || t->state == 0xFE || t->state == 0xFD || t->b31 == 0 || (info != 0 && *info <= 0.0f)) {
            w->target = 0;
            t = 0;
        }
    }
    func_L01_004C8688(w->shadow, &w->dir, 0);
    qcopy_003DD0F8(&m->right, &w->dir);
    func_0038CE90(&m->fwd, &m->right, out);
    func_0038CF68(&m->fwd, &m->fwd, 1.0f);
    func_0038CE90(&m->up, &m->fwd, &m->right);
    if (t != 0) {
        w->aim_x = out[1].x;
        w->aim_y = out[1].y;
        w->aim_z = out[1].z;
    }
    if (fabs_asm(w->turn) > 0.0031f) {
        *(Q_003DD0F8 *)&q = *(Q_003DD0F8 *)&m->right;
        func_003C4840(&d, &m->fwd, w->turn * 0.017453292f);
        func_0038D850(&m->right, &m->right, &d);
        func_0038D850(&m->up, &m->up, &d);
        func_003C4840(&d, &q, w->spin);
        func_0038D850(&m->right, &m->right, &d);
        func_0038D850(&m->fwd, &m->fwd, &d);
        func_0038D850(&m->up, &m->up, &d);
        func_003C4840(&d, &m->right, w->spin);
        func_0038D850(&m->fwd, &m->fwd, &d);
        func_0038D850(&m->up, &m->up, &d);
        w->spin = func_0038DAB8(w->spin, w->spin_rate * 0.017453292f);
    }
    m->right.w = m->fwd.w = m->up.w = 0.0f;
    if (t != 0) {
        func_0038CE20(&q, &m->right, w->speed);
        vec_add_ab(&m->pos, &m->pos, &q);
        if (func_0038CF00(&t->pos, &m->pos) < 5.0f) {
            func_L01_004CB128(&e, t, 0);
            vec_sub_ab(&d, &e, &m->pos);
            func_0038CF68(&q, &d, w->speed);
            vec_add_ab(&m->pos, &m->pos, &q);
            func_L01_004CAB30(&m->pos, &m->pos);
        }
    } else if ((D_L01_002C5600_003DD0F8 + D_001425C0[0x97])->level >= 4) {
        func_0038CE20(&q, &m->right, w->speed);
        vec_add_ab(&m->pos, &m->pos, &q);
        vec_sub_ab(&d, &w->sun, &m->pos);
        func_0038CF68(&q, &d, w->speed);
        vec_add_ab(&m->pos, &m->pos, &q);
        func_L01_004CAB30(&m->pos, &m->pos);
        if (w->sun_pending != 0) {
            w->sun_pending = 0;
            func_L01_003DEFE8(&w->sun);
        }
    } else {
        func_0038CE20(&q, &m->right, w->speed);
        vec_add_ab(&m->pos, &m->pos, &q);
    }
    if (((f32 *)&m->pos)[0] < 2.0f || ((f32 *)&m->pos)[0] > 1021.0f || ((f32 *)&m->pos)[1] < 2.0f
        || ((f32 *)&m->pos)[1] > 1021.0f || ((f32 *)&m->pos)[2] < 2.0f || ((f32 *)&m->pos)[2] > 1021.0f) {
        func_L01_0044BEC8(m, D_L01_001E0140);
        func_003C2880(m);
        return;
    }
    func_L01_003DE418(m, &d);
    if (++w->trail >= 4) {
        func_L01_00404A10(func_L01_003DE488, m);
    }
    if ((D_L01_002C5600_003DD0F8 + D_001425C0[0x97])->level >= 2) {
        func_L01_003DE1D8(m, &start);
    }
    *(Q_003DD0F8 *)&e = m->pos;
    func_0038CE20(&f, out, -0.3f);
    vec_add_ab(&f, &m->pos, &f);
    if (func_003D3CB0(&e, &f, 2, 0, 0) != 0) {
        func_0038CE20(&e, out, 0.3f);
        vec_add_ab(&m->pos, &D_L01_001EAA00_003DD0F8.pos, &e);
    }
    dmg.moby = (s32)m;
    dmg.flags = 0x1030000;
    dmg.w20 = 1;
    dmg.damage = (D_L01_002C5600_003DD0F8 + D_001425C0[0x97])->damage;
    if (m->flags & 0x100) {
        *(Q_003DD0F8 *)&dir = *(Q_003DD0F8 *)&q;
    } else {
        dir.x = func_0038D098(m->yaw);
        dir.y = func_0038D0B0(m->yaw);
        dir.z = 0.0f;
    }
    dir.w = 5627.925f;
    dir.z = 1.5f;
    *(Q_003DD0F8 *)&dmg.v = *(Q_003DD0F8 *)&dir;
    func_0038CF68(&dmg.v, &dmg.v, 1.0f);
    dmg.v.w = 5627.925f;
    dmg.b18 = 3;
    dmg.oclass = m->oclass;
    dmg.b19 = 1;
    if (func_003D3CB0(&start, &m->pos, 0, D_001A4BE0_003DD0F8.body, 0) != 0) {
        if (D_L01_001EAA00_003DD0F8.moby != 0) {
            if (D_L01_001EAA00_003DD0F8.moby != D_001A4BE0_003DD0F8.body && D_L01_001EAA00_003DD0F8.moby != w->owner) {
                skip = m;
                m->hit = 2;
                m->pos = D_L01_001EAA00_003DD0F8.pos;
            }
        } else if (D_L01_001EAA00_003DD0F8.w1C > 0) {
            m->hit = 1;
            m->pos = D_L01_001EAA00_003DD0F8.pos;
        }
    }
    if (m->hit != 0) {
        ok = 1;
        qcopy_003DD0F8(&m->pos, &D_L01_001EAA00_003DD0F8.pos);
        func_003C5180(&m->pos, &n, 1);
        if (D_L01_001EAA00_003DD0F8.moby != 0 && D_L01_001EAA00_003DD0F8.w1C <= 0) {
            vec_sub_ab(&v, &D_L01_001E29C0_003DD0F8, &m->pos);
            func_0038CF68(&v, &v, 1.0f);
        } else {
            func_0038CF68(&v, &D_L01_001EAA00_003DD0F8.normal, 1.0f);
            if (fabs_asm(func_0038CE68(&v, &n)) >= 0.1f) {
                ok = 0;
            }
        }
        if (ok) {
            func_003C3D30(&m->pos, 0, 0, 0.5f);
        }
        func_L01_003DDDA8(m, &n, skip);
        func_L01_0044BEC8(m, D_L01_001E0140);
        func_L01_004C8668(w->shadow);
        func_003C2880(m);
        return;
    }
    if (func_0038CB00(&w->timer) == 0 && !(func_0038CF38(&m->pos, D_001A4C60) > 60.0f)) {
        return;
    }
    if (w->sound != -1) {
        Snd80_003DD0F8 *s = &D_001A30B0_003DD0F8[w->sound];
        if (*(void **)&s->b[0xDC] == m && s->b[0xD0] != 0) {
            func_003A4F28(w->sound);
        }
    }
    w->sound = -1;
    func_L01_0044BEC8(m, D_L01_001E0140);
    func_L01_004C8668(w->shadow);
    func_003C2880(m);
}
/* localdecomp:end func_L01_003DD0F8 */

/* localdecomp:start func_L01_003DD9C8 */
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
extern u8 D_00142657[];
extern Row_003DD9C8 D_L01_002C5600[];
extern f32 D_L01_001D66B0;
void func_L01_003DD9C8(u8 *owner, f32 *origin) {
    extern f32 func_0038D160(f32, f32);
    extern void func_L01_00446780(void *, void *, s32, f32, f32, f32, s32, s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern void func_L01_00470C78(void *, s32, s32, s32, s32, void *, s32, s32, s32, s32, f32, f32);
    vu0_v4 delta;
    f32 velocity[4], point[4];
    f32 heading, speed, pitch, angle;
    Row_003DD9C8 *row;
    f32 *v, *p;
    s32 spin, i;
    vec_sub_ab(&delta, &D_L01_001E29C0, origin);
    heading = func_0038D160(delta.x, delta.y);
    row = &D_L01_002C5600[D_00142657[0]];
    func_L01_00446780(owner, origin, 0x08110000, 1.25f, row->scale, 1.0f, 0, 1, 0);
    p = point;
    v = velocity;
    for (i = 0; i < 4; i++) {
        speed = func_003824E0(0.5f, 1.0f);
        spin = (s32)func_L01_00443A18(1.0f, 2.0f);
        func_003824E0(0.05f, 0.2f);
        {
            f32 units = 210000.0f;
            pitch = func_003824E0(0.0f, 1.3962633609771729f);
            angle = func_0038DAB8(heading, func_L01_00443A18(0.0f, 1.3962633609771729f));
            func_00382760(v, speed * 0.020000001f, angle, pitch);
            point[0] = origin[0] + func_L01_00443A18(0.0f, 0.1f);
            point[1] = origin[1] + func_L01_00443A18(0.0f, 0.1f);
            point[2] = origin[2] + func_L01_00443A18(0.0f, 0.1f);
            func_L01_0046A610(p, v, 25, 127, 0x20207F, spin, func_003824E0(0.05f, 0.2f) * units, 500.0f, 1.0f, 0.0f, 1.0f);
        }
    }
    func_L01_00470C78(origin, 66, 0x64A0A0FF, 2, 4, &D_L01_001D66B0, 0, 1, 6, 1, 0.1f, 1.05f);
    func_L01_00470C78(origin, 50, 0x3C0A32F7, 2, 0, &D_L01_001D66B0, 0, 0, 6, 1, 0.4f, 2.05f);
    func_L01_00470C78(origin, 66, 0x320A32F7, 0, 2, &D_L01_001D66B0, 0, 4, 6, 1, 0.15f, 1.65f);
    func_L01_00470C78(origin, 44, 0x3C0014F7, 2, 0, &D_L01_001D66B0, 3, 0, 6, 1, 0.5f, 2.35f);
    func_L01_00470C78(origin, 44, 0x1E0014F7, 1, -2, &D_L01_001D66B0, 3, 4, 6, 1, 0.3f, 1.75f);
}
/* localdecomp:end func_L01_003DD9C8 */

/* localdecomp:start func_L01_003DDDA8 */
extern u8 D_001425C0[];
extern u8 *D_L01_001EEA80[];
typedef struct {
    u8 p0[0x25C0];
    u8 *camera;            /* 0x25C0 */
    u8 p25C4[0x28C8 - 0x25C4];
    u8 shift;              /* 0x28C8 */
} Game_003DDDA8;
extern Game_003DDDA8 D_001A4BE0_003DDDA8;
typedef struct {
    u8 p0[0x25C];
    s32 bolts;             /* 0x25C */
} Save_003DDDA8;
extern Save_003DDDA8 D_00142DE0_003DDDA8;
extern s32 D_00142660[];
extern s32 D_001D545C;
extern u8 D_001BBE90[];
extern u8 D_L01_001D60E0[] __attribute__((section(".sdata")));
extern u8 D_L01_001D60D8[] __attribute__((section(".sdata")));
extern u8 D_001426E0[];
extern f32 D_L01_001DAA34;
extern f32 D_L01_002F1600[];
typedef struct {
    u128_t velocity;
    u8 pad[0x10];
    s32 flags;
    u8 rest[0xC];
} Damage_003DDDA8;
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D4D00(void *, s32, f32, void *, s32);
extern s32 func_L01_004006C8(u8 *, s32, s32);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_00315900(void *, s32, void *);
extern void func_L01_00446748(void *, void *, s32, f32);
extern void func_L01_00446978(void *, void *);
extern void func_L01_003DE198(void);
extern u8 *func_00382348(void);

static __inline__ Row_003DD9C8 *row_003DDDA8(void) {
    return &D_L01_002C5600[D_001425C0[0x97]];
}

static __inline__ s32 scale_003DDDA8(s32 n) {
    return (f32)n * ((D_001D545C == 7 && D_001426E0[0x7B]) ? D_L01_001DAA34 : D_L01_002F1600[D_001D545C]);
}

void func_L01_003DDDA8(u8 *obj, u128_t *direction) {
    struct {
        u128_t impulse;
        Damage_003DDDA8 damage;
    } f;
    u8 *pos;
    s32 count;
    s32 i;
    f32 radius;

    func_0038CE20(&f.impulse, direction, -3.0f);
    radius = 4.0f;
    if (row_003DDDA8()->pad[1] >= 4) {
        radius = 1.0f;
    }
    pos = obj + 0x10;
    count = func_003D4D00(pos, 16, radius, obj, 0);
    if (count != 0) {
        for (i = 0; i < count; i++) {
            u8 *state;

            if (D_L01_001EEA80[i] == D_001A4BE0_003DDDA8.camera || *(s16 *)(obj + 0xAA) == 0x1A90) {
                continue;
            }
            state = ((u8 *(*)(void *))func_00382348)(D_L01_001EEA80[i]);
            if (D_L01_001EEA80[i] != 0 && *(u8 **)(D_L01_001EEA80[i] + 0x24) != 0
                && (*(u8 **)(D_L01_001EEA80[i] + 0x24))[0x46] == 5 && state != 0 && state[0xE] != 3) {
                if (*(f32 *)state > row_003DDDA8()->scale) {
                    f.damage.flags = 1;
                    func_0038CE20(&f.damage.velocity, obj + 0xD0, -1.0f);
                    ((f32 *)&f.damage.velocity)[3] = 5627.925f;
                    func_L01_00446748(&f.damage, D_L01_001EEA80[i], 0x110000, row_003DDDA8()->scale);
                    func_L01_00446978(D_L01_001EEA80[i], &f.damage);
                } else {
                    s32 bonus = (D_00142660[14] + 49) / 50;
                    u16 id = *(u16 *)(D_L01_001EEA80[i] + 0xB2);
                    s32 bits = D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)];
                    s32 reward;

                    if (((id & 1) ? bits >> 4 : bits) & 8) {
                        reward = func_L01_004006C8(D_L01_001D60E0, *(u16 *)(D_L01_001EEA80[i] + 0xB6), *(s16 *)(D_L01_001EEA80[i] + 0xB2));
                    } else {
                        reward = func_L01_004006C8(D_L01_001D60D8, *(u16 *)(D_L01_001EEA80[i] + 0xB6), *(s16 *)(D_L01_001EEA80[i] + 0xB2));
                    }
                    reward <<= D_001A4BE0_003DDDA8.shift;
                    if (func_L01_0041A4F0()) {
                        reward = scale_003DDDA8(reward);
                    }
                    D_00142DE0_003DDDA8.bolts += reward + bonus;
                    func_L01_00315900(D_L01_001EEA80[i], 2, func_L01_003DE198);
                }
            } else if (D_L01_001EEA80[i] != 0 && *(u8 **)(D_L01_001EEA80[i] + 0x24) != 0
                       && (*(u8 **)(D_L01_001EEA80[i] + 0x24))[0x46] == 5 && state != 0 && state[0xE] == 3) {
                f.damage.flags = 1;
                func_0038CE20(&f.damage.velocity, obj + 0xD0, -1.0f);
                ((f32 *)&f.damage.velocity)[3] = 5627.925f;
                func_L01_00446748(&f.damage, D_L01_001EEA80[i], 0x110000, row_003DDDA8()->scale);
                func_L01_00446978(D_L01_001EEA80[i], &f.damage);
            } else {
                func_L01_003DD9C8(obj, (f32 *)(obj + 0x10));
            }
        }
    } else {
        func_L01_003DD9C8(obj, (f32 *)pos);
    }
}
/* localdecomp:end func_L01_003DDDA8 */

/* localdecomp:start func_L01_003DE198 */
extern u8 *func_00382348(void);

void func_L01_003DE198(void) {
    u8 *p = func_00382348();
    if (p != 0 && (u8)(p[14] - 1) < 2) {
        p[14] = 2;
    }
}
/* localdecomp:end func_L01_003DE198 */

/* localdecomp:start func_L01_003DE1D8 */
#include "vu0.h"
extern vu0_v4 D_001A4EC0;
extern s32 D_L01_001DF540;
extern u8 *D_L01_001DF544;
__asm__(".extern D_L01_001DF540, 4");
__asm__(".extern D_L01_001DF544, 4");
void func_L01_003DE1D8(u8 *self, vu0_q *source) {
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_0013D3E0(void);
    extern u8 *func_L01_0046A610_003DE1D8(void *, void *, s32, s32, u32, s32, f32, f32, f32, f32, f32);
    vu0_v4 input;
    vu0_v4 velocity;
    vu0_v4 position;
    vu0_v4 step;
    f32 length;
    u8 *state;
    s32 count, i;
    *(vu0_q *)&input = *source;
    state = *(u8 **)(self + 0x68);
    length = *(f32 *)(state + 0x68);
    *(vu0_q *)&position = *(vu0_q *)&input;
    vec_sub_ab(&step, self + 0x10, &input);
    count = (s32)(length / 0.1f) / 4;
    func_0038CF68(&step, &step, length / count);
    for (i = 0; i < count; i++) {
        s32 kind = (s32)func_L01_00443A18(1.0f, 3.0f);
        s32 life;
        s32 texture;
        f32 size;
        u32 color;
        u8 *particle;
        f32 r = func_003824E0(0.2f, 1.0f);
        func_0038CE20(&velocity, &D_001A4EC0, -(r * 0.020000001415610313f));
        life = func_00382498(20, 40);
        size = func_003824E0(200.0f, 1000.0f);
        if (func_0013D3E0() & 2) { texture = 80; color = 0x204080; }
        else { texture = 80; color = 0x4080FF; }
        particle = func_L01_0046A610_003DE1D8(&position, &velocity, (life * 5 + 2) / 6, texture, color, kind, 21000.0f, size, 1.0f, 0.0f, 1.0f);
        vec_add_ab(&position, &position, &step);
        if (particle) {
            particle[2] = *(u8 *)((s32)D_L01_00221098[D_L01_001DF540] + (s32)D_L01_001DF544);
            particle[3] = texture == 64 ? 0x48 : 0x44;
        }
    }
}
/* localdecomp:end func_L01_003DE1D8 */

/* localdecomp:start func_L01_003DE418 */
extern void func_0038D000(void *, void *, void *);

void func_L01_003DE418(u8 *obj, u128_t *out) {
    vu0_v4 v;

    *(vu0_q *)&v = 0;
    v.x = -0.1f;
    v.w = 1.0f;
    func_0038D000(&v, &v, obj + 0xC0);
    vec_add_ba(out, &v, obj + 0x10);
}
/* localdecomp:end func_L01_003DE418 */

/* localdecomp:start func_L01_003DE488 */

extern void func_L01_003DE418(u8 *, u128_t *);
extern void func_L01_003DE510(u128_t *, u8 *, s32, s32, f32, f32, f32);
extern void func_L01_00409B08(u128_t *, s32, s32);

void func_L01_003DE488(u8 *m) {
    u128_t a;
    u128_t b;
    u8 *t;

    t = *(u8 **)(m + 104);
    if (t != 0) {
        func_L01_003DE418(m, &a);
        b = *(u128_t *)(m + 16);
        func_L01_003DE510(&b, t + 16, 0x1030FF, 4, 0.0f, 0.85f, 0.25f);
        func_L01_00409B08(&a, 0x2040FF, 0);
    }
}
/* localdecomp:end func_L01_003DE488 */

/* localdecomp:start func_L01_003DE510 */
typedef union { vu0_q q; f32 f[4]; } V_3DE510;
typedef struct {
    V_3DE510 pos[4];
    u32 color[4];
    f32 uv[4][2];
    u8 tail[0x20];
} Poly_3DE510;
extern vu0_v4 D_L01_001E29C0;
void func_L01_003DE510(u128_t *start_arg, u8 *points_arg, s32 color, s32 count, f32 phase, f32 width, f32 step)
{
    V_3DE510 *start = (V_3DE510 *)start_arg;
    V_3DE510 *points = (V_3DE510 *)points_arg;
    extern void func_003D93B0(void *,s32,s32,s32);
    extern s32 func_0013D3E0(void);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_0038CE90(void *,void *,void *);
    extern void func_0038D028(void *,void *,void *);
    extern void func_003D2DA0(void *,s32,s32);
    V_3DE510 origin;
    Poly_3DE510 outer,inner;
    V_3DE510 matrix[4];
    V_3DE510 offset,offset2;
    s32 i,next;
    s32 bytes;
    f32 u,v,u2,v2;
    origin.q=start->q;
    start=&origin;
    func_003D93B0(&outer,43,1,128);
    func_003D93B0(&inner,43,1,128);
    offset2.q=offset.q=0;
    width*=0.25f;
    outer.color[0]=outer.color[1]=color;
    inner.color[0]=inner.color[1]=color;
    outer.color[2]=outer.color[3]=color;
    inner.color[2]=inner.color[3]=color;
    offset.f[3]=1.0f;
    offset2.f[3]=1.0f;
    offset.f[2]=width;
    offset2.f[2]=width+width;
    if ((func_0013D3E0()&1)==0) {
        outer.uv[0][0]=phase+0.0f;
        outer.uv[0][1]=0.0f;
        outer.uv[1][0]=phase+0.0f;
        outer.uv[1][1]=1.0f;
        outer.uv[2][0]=step+phase;
        outer.uv[2][1]=0.0f;
        outer.uv[3][0]=step+phase;
        outer.uv[3][1]=1.0f;
        inner.uv[0][0]=phase+0.0f;
        inner.uv[0][1]=0.0f;
        inner.uv[1][0]=phase+0.0f;
        inner.uv[1][1]=1.0f;
        inner.uv[2][0]=step+phase;
        inner.uv[2][1]=0.0f;
        inner.uv[3][0]=step+phase;
        inner.uv[3][1]=1.0f;
    } else {
        outer.uv[0][0]=phase+0.0f;
        outer.uv[0][1]=1.0f;
        outer.uv[1][0]=phase+0.0f;
        outer.uv[1][1]=0.0f;
        outer.uv[2][0]=step+phase;
        outer.uv[2][1]=1.0f;
        outer.uv[3][0]=step+phase;
        outer.uv[3][1]=0.0f;
        inner.uv[0][0]=phase+0.0f;
        inner.uv[0][1]=1.0f;
        inner.uv[1][0]=phase+0.0f;
        inner.uv[1][1]=0.0f;
        inner.uv[2][0]=step+phase;
        inner.uv[2][1]=1.0f;
        inner.uv[3][0]=step+phase;
        inner.uv[3][1]=0.0f;
    }
    vec_sub_ba(&matrix[0],points,start);
    func_0038CF68(&matrix[0],&matrix[0],1.0f);
    vec_sub_ba(&matrix[1],&D_L01_001E29C0,start);
    func_0038CE90(&matrix[2],&matrix[1],&matrix[0]);
    i=0;
    bytes=count<<4;
    func_0038CF68(&matrix[2],&matrix[2],1.0f);
    func_0038CE90(&matrix[1],&matrix[0],&matrix[2]);
    matrix[3].q=start->q;
    outer.pos[0].q=offset.q;
    inner.pos[0].q=offset2.q;
    func_0038CE20(outer.pos[1].f,outer.pos[0].f,-1.0f);
    func_0038CE20(inner.pos[1].f,inner.pos[0].f,-1.0f);
    func_0038D028(&outer.pos[0],&outer.pos[0],matrix);
    func_0038D028(&outer.pos[1],&outer.pos[1],matrix);
    func_0038D028(&inner.pos[0],&inner.pos[0],matrix);
    func_0038D028(&inner.pos[1],&inner.pos[1],matrix);
    while (i<count-1) {
        next=i+1;
        vec_sub_ab(&matrix[0],points+i+1,points+i);
        func_0038CF68(&matrix[0],&matrix[0],1.0f);
        vec_sub_ab(&matrix[1],&D_L01_001E29C0,points+i);
        func_0038CE90(&matrix[2],&matrix[1],&matrix[0]);
        func_0038CF68(&matrix[2],&matrix[2],1.0f);
        func_0038CE90(&matrix[1],&matrix[0],&matrix[2]);
        offset.f[2]*=0.7f;
        matrix[3].q=points[i].q;
        offset2.f[2]=offset.f[2]+offset.f[2];
        outer.pos[2].q=offset.q;
        inner.pos[2].q=offset2.q;
        func_0038CE20(outer.pos[3].f,outer.pos[2].f,-1.0f);
        func_0038CE20(inner.pos[3].f,inner.pos[2].f,-1.0f);
        func_0038D028(&outer.pos[2],&outer.pos[2],matrix);
        func_0038D028(&outer.pos[3],&outer.pos[3],matrix);
        func_0038D028(&inner.pos[2],&inner.pos[2],matrix);
        func_0038D028(&inner.pos[3],&inner.pos[3],matrix);
        u=step*(f32)next; v=u+step;
        if (u>=1.0f) {u-=1.0f;v-=1.0f;}
                outer.uv[0][0]=u+phase;outer.uv[1][0]=u+phase;
        outer.uv[2][0]=v+phase;outer.uv[3][0]=v+phase;
        inner.uv[0][0]=u+phase;inner.uv[1][0]=u+phase;
        inner.uv[2][0]=v+phase;inner.uv[3][0]=v+phase;
        func_003D2DA0(&outer,0,0);
        func_003D2DA0(&inner,0,0);
        if (i!=0) {
            outer.color[0]=outer.color[1]=color|0x7F000000;
            inner.color[0]=inner.color[1]=color|0x3F000000;
        }
        i=next;
        outer.pos[0].q=outer.pos[2].q;
        outer.pos[1].q=outer.pos[3].q;
        inner.pos[0].q=inner.pos[2].q;
        inner.pos[1].q=inner.pos[3].q;
        outer.color[2]=outer.color[3]=color|0x7F000000;
        inner.color[2]=inner.color[3]=color|0x3F000000;
    }
    matrix[3].q=((V_3DE510 *)(bytes+(s32)points))[-1].q;
    offset.f[2]*=0.7f;
    offset2.f[2]=offset.f[2]+offset.f[2];
    inner.pos[2].q=offset2.q;
    outer.pos[2].q=offset.q;
    func_0038CE20(outer.pos[3].f,outer.pos[2].f,-1.0f);
    func_0038CE20(inner.pos[3].f,inner.pos[2].f,-1.0f);
    func_0038D028(&outer.pos[2],&outer.pos[2],matrix);
    func_0038D028(&outer.pos[3],&outer.pos[3],matrix);
    func_0038D028(&inner.pos[2],&inner.pos[2],matrix);
    func_0038D028(&inner.pos[3],&inner.pos[3],matrix);
    u2=step*(f32)(i+1);v2=u2+step;
    outer.color[2]=outer.color[3]=color;
    inner.color[2]=inner.color[3]=color;
    if (u2>=1.0f) {u2-=1.0f;v2-=1.0f;}
    outer.uv[0][0]=u2+phase;outer.uv[1][0]=u2+phase;
    outer.uv[2][0]=v2+phase;outer.uv[3][0]=v2+phase;
    inner.uv[0][0]=u2+phase;inner.uv[1][0]=u2+phase;
    inner.uv[2][0]=v2+phase;inner.uv[3][0]=v2+phase;
    func_003D2DA0(&outer,0,0);
    func_003D2DA0(&inner,0,0);
}
/* localdecomp:end func_L01_003DE510 */

/* localdecomp:start func_L01_003DEB40 */
void func_L01_003DEB40(u8 *obj) {
    extern s32 func_00382468(s32);
    u8 *v = *(u8 **)(obj + 0x68);
    s32 i;
    for (i = 0; i < 4; i++) ((f32 *)v)[i] = func_00382468(255);
    *(f32 *)(v + 0x10) = -1.0f;
    *(f32 *)(v + 0x14) = -2.25f;
    *(f32 *)(v + 0x18) = 1.25f;
    *(f32 *)(v + 0x1c) = 2.5f;
     { s32 j; for (j = 1; j <= 4; j++) ((s32 *)(v + 0x20))[j-1] = (j * 320 - 3) / 6; }
    *(f32 *)(v + 0x3c) = *(f32 *)(v + 0x30) = 2.5f;
    *(f32 *)(v + 0x38) = *(f32 *)(v + 0x34) = 3.0f;
}
/* localdecomp:end func_L01_003DEB40 */

/* localdecomp:start func_L01_003DEC20 */
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
typedef struct { f32 phase[4], step[4]; s32 timer[4]; f32 size[4]; } State_003DEC20;
void func_L01_003DEC20(u8 *obj) {
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_0038CAD0(void *);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern void func_L01_0046C2E8(void *, s32, s32, s32, s32, s32, s32, s32, f32);
    vu0_v4 pos, delta;
    State_003DEC20 *vars = *(State_003DEC20 **)(obj + 0x68);
    s32 i;
    s32 color;
    vec_sub_ab(&pos,&D_L01_001E29C0,obj+0x10);
    func_0038CF68(&pos,&pos,-0.3f);
    func_0038CF68(&delta,&pos,0.1f);
    vec_add_ba(&pos,&pos,obj+0x10);
    for (i = 0; i < 4; i++) {
        vars->phase[i] += vars->step[i];
        if (vars->phase[i] >= 255.0f) vars->phase[i] -= 255.0f;
        else if (vars->phase[i] <= 0.0f) vars->phase[i] += 255.0f;
        if (func_0038CAD0(&vars->timer[i])) vars->timer[i] = 212;
        color = func_0038DBD8(0x4040FFFF, 0x1040FFFF, fabs_asm(0.5f - (f32)(212 - vars->timer[i]) / 212.0f));
        func_L01_0046C2E8(&pos, color, ((s32)vars->phase[i]) & 255, 53, 1, 2, 0, 0, vars->size[i]);
        vec_add_ab(&pos, &pos, &delta);
    }
}
/* localdecomp:end func_L01_003DEC20 */

/* localdecomp:start func_L01_003DEDF8 */
#include "vu0.h"
extern u8 D_00142CC0[];
extern u8 D_00142D60[];
extern f32 D_001A4C60[];
extern f32 D_L01_001DF548;
__asm__(".extern D_L01_001DF548, 4");
void func_L01_003DEDF8(u8 *obj) {
    extern void func_L01_003DEB40(u8 *);
    extern void func_003C2880(u8 *);
    extern void func_L01_004450F0(u8 *, s32, s32);
    extern void func_L01_003DEC20_003DEDF8(u8 *);
    extern f32 func_L01_0040E570(void *, void *);
    extern void func_L01_00451F60(s32, s32, s32);
    extern s32 func_0039EF28(void);
    extern s32 func_L01_00436620(s32);
    extern s32 func_L01_0041A5B0(s32, s32);
    s32 state = obj[0x20];
    switch (state) {
    case 0:
        func_L01_003DEB40(obj);
        if (D_00142CC0[0]) {
            func_003C2880(obj);
        } else {
            func_L01_004450F0(obj, 1, -1);
        }
        break;
    case 1:
        func_L01_003DEC20_003DEDF8(obj);
        if (func_L01_0040E570(obj + 0x10, D_001A4C60) < D_L01_001DF548 * D_L01_001DF548) {
            if (fabs_asm(*(f32 *)(obj + 0x18) - D_001A4C60[2]) < D_L01_001DF548) {
                func_L01_00451F60(0xAF7, -1, 0);
                D_00142CC0[0] = state;
                D_00142D60[0] = state;
                func_0039EF28();
                obj[0x31] = 0;
                *(u16 *)(obj + 0x34) |= 1;
                func_L01_004450F0(obj, 2, -1);
            }
        }
        break;
    case 2:
        if (!func_L01_00436620(0) && func_L01_0041A5B0(0x1627, 0x138)) {
            func_003C2880(obj);
        }
        break;
    }
}
/* localdecomp:end func_L01_003DEDF8 */

/* localdecomp:start func_L01_003DEF68 */
typedef struct {
    u8 p0[0x1210];
    s32 w1210;
    u8 p1214[0xC];
    s32 w1220;
} S_003DEF68;
extern S_003DEF68 D_001A4BE0;
extern s32 D_L01_001D6694;
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern void func_003A0EC0(s32, s32, s32, s32, s32);

void func_L01_003DEF68(u8 *obj) {
    if (obj[0x20] == 0) {
        obj[0x20] = 1;
    }
    if (D_L01_001D6694 == 0) {
        u8 *hero = D_001D52FC;
        if ((*(s32 *)(hero + 0x1A4) & D_001A4BE0.w1210) != 0) {
            if (D_001A4BE0.w1220 >= 0x13) {
                func_003A0EC0(5, 1, 4, 0, 0);
            }
        }
    }
}
/* localdecomp:end func_L01_003DEF68 */

/* localdecomp:start func_L01_003DEFE8 */
extern vu0_v4 D_L01_001E29C0;
extern s32 D_L01_001DF550;
__asm__(".extern D_L01_001DF550, 4");
u8 *func_L01_003DEFE8(u128_t *position) {
    extern Obj_003DC268 *func_003C24B0(s32,s32);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_003C5180(void *,void *,s32);
    extern void func_0038CE90(void *,void *,void *);
    extern void func_L01_003DF7A8(void *,void *,f32,f32,f32,s32,u32,u32,f32,s32,s32);
    vu0_v4 direction;
    vu0_v4 normal;
    u8 *obj=(u8 *)func_003C24B0(0x1df6,128);
    u8 *vars;
    s32 i;
    if(obj) {
        obj[0x30]=255;
        *(s16 *)(obj+0x32)=255;
        obj[0x20]=0;
        *(u128_t *)(obj+0x10)=*position;
        vars=*(u8 **)(obj+0x68);
        *(f32 *)(obj+0x1c)=1.0f;
        vec_sub_ba(&direction,&D_L01_001E29C0,obj+0x10);
        func_0038CF68(&direction,&direction,1.0f);
        func_003C5180(obj+0x10,&normal,1);
        *(u128_t *)(obj+0xc0)=*(u128_t *)&direction;
        func_0038CE90(obj+0xd0,obj+0xc0,&normal);
        func_0038CF68(obj+0xd0,obj+0xd0,1.0f);
        func_0038CE90(obj+0xe0,obj+0xd0,obj+0xc0);
        *(f32 *)(obj+0xcc)=*(f32 *)(obj+0xdc)=*(f32 *)(obj+0xec)=0.0f;
        *(s32 *)(vars+8)=53;
        *(s32 *)(vars+0x10)=25;
        *(s32 *)(vars+0xc)=-1;
        *(s32 *)(vars+0x14)=0;
        obj[0x20]=1;
        *(s32 *)(vars+0x18)=-1;
        *(s32 *)(vars+0x28)=0;
        for(i=0;i<24;i++) {
            func_L01_003DF7A8(obj,obj+0x10,0.03490658476948738f,0.3f,1.1f,D_L01_001DF550,0x204080ff,0x204080ff,4.0f,255,255);
        }
    }
    return obj;
}
/* localdecomp:end func_L01_003DEFE8 */

/* localdecomp:start func_L01_003DF1B0 */
extern vu0_v4 D_L01_001E29E0;
extern s32 D_L01_001DF54C;
__asm__(".extern D_L01_001DF54C, 4");
extern u8 D_001425C0[];
extern u8 D_L01_002A3A40[];
typedef struct {
    u8 p0[0x25C0];
    u8 *camera;            /* 0x25C0 */
} Game_003DF1B0;
extern Game_003DF1B0 D_001A4BE0_003DF1B0;
typedef struct {
    u128_t velocity;
    u8 pad[0x10];
    s32 flags;
    u8 rest[0xC];
} Damage_003DF1B0;
typedef struct { u8 p0[0x20]; s32 owner; u8 p24[0x2C]; } Spark_003DF1B0;
static __inline__ Row_003DD9C8 *row_003DF1B0(void) {
    return &D_L01_002C5600[D_001425C0[0x97]];
}
void func_L01_003DF1B0(u8 *obj) {
    extern void func_L01_00404808(void (*)(u8 *), void *);
    extern void func_L01_003DF620(u8 *);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_00404A10_003DF1B0(void (*)(u8 *), void *);
    extern void func_L01_003DF558(u8 *);
    extern void func_0038CBA0(void *, s32);
    extern void func_L01_004C84D8(void *);
    extern u8 *func_L01_004501E8(void *, void *, s32 *, f32, f32, f32, f32, void *, s32, s32, f32, s32, void *, s32, s32, s32);
    extern u8 *func_00382348(void);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_00446748(void *, void *, s32, f32);
    extern void func_L01_00446978(void *, void *);
    extern void func_L01_004AAC98(s32, s32, void *, s32);
    extern void func_L01_00315900(void *, s32, void *);
    extern void func_L01_003DE198(void);
    extern void func_003C2880(u8 *);
    u8 *vars = *(u8 **)(obj + 0x68);
    vu0_v4 direction;
    u8 *objects[32];
    Damage_003DF1B0 damage;
    s32 count;
    s32 i;
    s32 start;
    start = 0;
    if (obj[0x20] != 1) func_L01_00404808(func_L01_003DF620, obj);
    if (obj[0x20] == 1) {
        if (func_0038CAD0(vars + 0x10)) {
            obj[0x20] = 5;
            *(s32 *)(vars + 4) = (D_L01_001DF54C * 5 + 2) / 6;
        }
    } else if (obj[0x20] == 5) {
        if (func_0038CAD0(vars + 8)) {
            obj[0x20] = 3;
            *(s32 *)(vars + 8) = 53;
        } else func_L01_00404A10_003DF1B0(func_L01_003DF558, obj);
    } else if (obj[0x20] == 3) {
        {
            vu0_v4 *d = &direction;
            *d = D_L01_001E29E0;
        }
        func_0038CBA0(objects, 128);
        func_L01_004C84D8(obj);
        func_L01_004501E8(obj + 0x10, &direction, &count, 4.71238899230957f, 1.3962633609771729f, 60.0f, 0.0f, objects, 32, 0, 0.0f, 0, 0, 1, -1, 0);
        for (i = 0; i < count; i++) {
            u8 *state = ((u8 *(*)(void *))func_00382348)(objects[i]);
            if (objects[i] != 0 && *(u8 **)(objects[i] + 0x24) != 0
                && (*(u8 **)(objects[i] + 0x24))[0x46] == 5 && state != 0 && state[0xE] != 3) {
                if (*(f32 *)state > row_003DF1B0()->scale) {
                    damage.flags = 1;
                    func_0038CE20(&damage.velocity, obj + 0xD0, -1.0f);
                    ((f32 *)&damage.velocity)[3] = 5627.925f;
                    func_L01_00446748(&damage, objects[i], 0x110000, row_003DF1B0()->scale);
                    func_L01_00446978(objects[i], &damage);
                } else {
                    func_L01_004AAC98(2, 0, D_001A4BE0_003DF1B0.camera, 500);
                    func_L01_00315900(objects[i], 4, func_L01_003DE198);
                }
            } else if (objects[i] != 0 && *(u8 **)(objects[i] + 0x24) != 0
                       && (*(u8 **)(objects[i] + 0x24))[0x46] == 5 && state != 0 && state[0xE] == 3) {
                damage.flags = 1;
                func_0038CE20(&damage.velocity, obj + 0xD0, -1.0f);
                ((f32 *)&damage.velocity)[3] = 5627.925f;
                func_L01_00446748(&damage, objects[i], 0x110000, row_003DF1B0()->scale);
                func_L01_00446978(objects[i], &damage);
            }
        }
        {
            s32 n;
            for (n = start; n < 24; n++) {
                ((Spark_003DF1B0 *)D_L01_002A3A40)[n].owner = 0;
            }
        }
        func_003C2880(obj);
    }
}
/* localdecomp:end func_L01_003DF1B0 */

/* localdecomp:start func_L01_003DF558 */
extern void func_003A9440(s32, unsigned long);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern s16 D_001CFEC0[];

void func_L01_003DF558(u8 *p)
{
    s32 *o = *(s32 **)(p + 0x68);
    s32 c;
    s32 rgba;

    c = 0x80 - o[2] * 2;
    rgba = c << 24 | c << 16 | c << 8 | c;
    func_003A9440(0x42, 0x48);
    func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], rgba);
    func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], rgba);
    func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], rgba);
    func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], rgba);
}
/* localdecomp:end func_L01_003DF558 */

/* localdecomp:start func_L01_003DF620 */
typedef struct { u8 p[0x20]; f32 angle; s32 timer; } State_003DF620;
typedef struct { vu0_v4 position; void *owner; u8 p24[4]; f32 scale; u8 p2C[4]; s32 a, b, c, d; f32 e, f, phase; u8 p3C[0x14]; } Row_003DF620;
extern u8 D_L01_002A3A40[];
extern s32 D_L01_001DF550;
__asm__(".extern D_L01_001DF550, 4");
void func_L01_003DF620(u8 *obj) {
    extern void func_0038D890(void *, void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_0040A8C0(void *, void *, s32, s32, f32, f32, s32, s32, s32, s32, f32);
    vu0_v4 out;
    vu0_v4 origin;
    State_003DF620 *state;
    Row_003DF620 *row;
    u8 *base;
    s32 n, count;
    state = *(State_003DF620 **)(obj + 0x68);
    if (state != 0) {
        count = 0;
        for (n = 0; n < 24; n++) {
            base = D_L01_002A3A40 + n * 0x50;
            row = (Row_003DF620 *)(base + 0x10);
            if (row->owner != obj) goto next;
            if (count < (120 - state->timer) / 5) {
                func_0038D890(&row->position, &row->position, base, row->scale);
                count++;
                row->phase += 0.06f;
                func_0038CF68(&row->position, &row->position, row->phase);
                vec_add_ab(&out, &row->position, obj + 0x10);
                *(u128_t *)&origin = *(u128_t *)(obj + 0x10);
                func_L01_0040A8C0(&origin, &out, D_L01_001DF550, 1, row->e, row->f, row->a, row->b, row->c, row->d, state->angle);
            }
        next:;
        }
        state->angle -= 0.018f;
        if (state->angle <= -8.0f) state->angle += 8.0f;
    }
}
/* localdecomp:end func_L01_003DF620 */

/* localdecomp:start func_L01_003DF7A8 */
#include "vu0.h"
typedef struct { vu0_v4 position; void *owner; u8 p24[4]; f32 scale; u8 p2C[4]; s32 a, b, c, d; f32 e, f, phase; u8 p3C[0x14]; } Row_003DF7A8;
extern vu0_v4 D_L01_001E29C0;
void func_L01_003DF7A8(void *owner, void *origin, f32 scale, f32 e, f32 f, s32 mode, u32 a, u32 b, f32 phase, s32 c, s32 d) {
    extern void func_00382580(void *, f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    vu0_v4 view;
    u8 *p;
    s32 n;
    Row_003DF7A8 *r;
    for (n = 0; n < 24; n++) {
        p = D_L01_002A3A40 + n * 0x50;
        r=(Row_003DF7A8 *)(p+0x10);
        if (!r->owner) {
            r->owner=owner;
            r->scale=scale;
            r->a=a; r->b=b; r->c=c; r->d=d;
            r->e=e; r->f=f; r->phase=phase;
            *(s32 *)r->p2C=mode;
            func_00382580(p,1.0f,1.0f);
            vec_sub_ab(&view,&D_L01_001E29C0,origin);
            func_0038CF68(&view,&view,1.0f);
            func_0038CE90(r,p,&view);
            func_0038CF68(r,r,phase);
            break;
        }
    }
}
/* localdecomp:end func_L01_003DF7A8 */

/* localdecomp:start func_L01_003DF8B8 */
void func_L01_003DF8B8(void) {

}
/* localdecomp:end func_L01_003DF8B8 */

/* localdecomp:start func_L01_003DF8C0 */
extern s32 D_001A71A0[];
extern s32 D_001D52F0;
__asm__(".extern D_001D52F0, 16");
typedef struct { vu0_v4 pos; u8 b[0x460 - 0x10]; } E_003DF8C0;
extern E_003DF8C0 D_L01_001E2A40[];
extern vu0_v4 D_L01_001EAA40;
extern u8 *D_L01_00221098[];
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_003DF8B8(void);

void func_L01_003DF8C0(u8 *m) {
    extern void func_L01_0044C638(u8 *, s32, u8 *, u8 *, u8 *, u8 *);
    extern void func_L01_0044C870(u8 *, s32, u8 *, void *);
    extern s32 func_0038CB00(void *);
    extern void func_003C2880(u8 *);
    extern void func_00382580(void *, f32, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_00382538(void);
    extern f32 func_L01_00443A18(f32, f32);
    extern s32 func_L01_00470668(u8 *, void *, s32, f32);
    extern s32 func_L01_002FB660(u8 *, void *, s32, s32, s32, s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_0038D890(void *, void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern s32 func_L01_003FB640(void *, f32, s32, s32);
    extern void func_L01_00404A10(void (*)(void), void *);
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    vu0_v4 zero;
    vu0_v4 p;
    vu0_v4 q20;
    vu0_v4 q30;
    vu0_v4 q40;
    vu0_v4 v50;
    u8 *vars = *(u8 **)(m + 0x68);
    f32 y;
    f32 angle;
    u8 *part;
    vu0_v4 *e;

    if (*(s32 *)(vars + 0x38) != 0) {
        func_L01_0044C638(m, *(s32 *)(vars + 0x38), m + 0x10, m + 0xF0, m + 0x10, m + 0xF0);
    }
    if (func_0038CB00(vars + 0x10) == 0) {
    qzero(&zero);
    if (*(s32 *)(vars + 0x38) != 0) {
        func_L01_0044C870(m, *(s32 *)(vars + 0x38), m + 0x10, &zero);
    }
    if (*(s16 *)(vars + 0x10) == 0x3A) {
        for (k = 0; k < *(s16 *)(vars + 0x32); k++) {
            func_00382580(&p, *(f32 *)(vars + 0xC) * 0.30000001f, *(f32 *)(vars + 0xC) * 0.40000004f);
            vec_add_ab(&p, &p, &zero);
            func_L01_00470668(m + 0x10, &p, (func_00382498(25, 40) * 5 + 2) / 6, 0.00584f);
        }
    }
    if (*(s16 *)(vars + 0x10) == 0x38) {
        for (j = 0; j < *(s16 *)(vars + 0x30); j++) {
            angle = func_003824E0(0.43633232f, 0.78539819f);
            y = func_00382538();
            func_00382760(&p, func_003824E0(10.0f, 20.0f) * 0.020000001f * *(f32 *)(vars + 0xC), y, angle);
            vec_add_ab(&p, &p, &zero);
            func_L01_002FB660(m + 0x10, &p, func_00382498(100, 125), 2, 0, 1);
        }
    }
    if (*(s16 *)(vars + 0x10) == 0x37 && *(s16 *)(vars + 0x3C) != 0) {
        angle = func_00382538();
        func_00382580(&p, 1.0f, 1.0f);
        vec_sub_ba(&q20, &D_L01_001E2A40[D_001D52F0].pos, m + 0x10);
        func_0038CE90(&q30, &q20, &p);
        func_0038CF68(&q30, &q30, 1.0f);
        for (n = 0; n < 100; n++) {
            s32 a = (s32)func_L01_00443A18(2.0f, 5.0f);
            func_0038D890(&q40, &q30, &p, angle);
            func_0038CF68(&q40, &q40, *(f32 *)(vars + 0xC) * 0.30000001f);
            part = func_L01_004713C8(m + 0x10, &q40, (func_00382498(20, 27) * 5 + 2) / 6, *(u32 *)(vars + 0x60), a, 0x4F, 0, 1,
                                     *(f32 *)(vars + 0xC) * 231000.0f, *(f32 *)(vars + 0xC) * 252000.02f, 0.0f);
            if (part != 0) {
                part[2] = D_L01_00221098[0x5C][0];
            }
            angle = func_0038DAB8(angle, 0.063466519f);
        }
    }
    if (*(s16 *)(vars + 0x10) == 0x36 && *(s16 *)(vars + 0x16) != 0) {
        angle = func_00382538();
        if (func_L01_003FB640(m + 0x10, 1.0f, 20, D_001A71A0[0]) != 0) {
            e = &D_L01_001EAA40;
            p = e[0];
            q20 = e[-2];
        } else {
            func_00382580(&p, 1.0f, 1.0f);
            q20 = *(vu0_v4 *)(m + 0x10);
        }
        func_0038CF68(&p, &p, 0.05f);
        vec_add_ba(&q20, &q20, &p);
        func_0038CF68(&p, &p, 1.0f);
        vec_sub_ba(&q30, &D_L01_001E2A40[D_001D52F0].pos, m + 0x10);
        func_0038CE90(&q40, &q30, &p);
        func_0038CF68(&q40, &q40, 1.0f);
        if (*(s16 *)(vars + 0x36) != 0) {
            for (i = 0; i < 100; i++) {
                s32 a = (s32)func_L01_00443A18(2.0f, 5.0f);
                func_0038D890(&v50, &q40, &p, angle);
                func_0038CF68(&v50, &v50, func_003824E0(5.0f, 9.0f) * 0.020000001f * *(f32 *)(vars + 0xC));
                if (i % 3 == 0) {
                    part = func_L01_004713C8(&q20, &v50, (func_00382498(20, 27) * 5 + 2) / 6, *(u32 *)(vars + 0x60), a, 0x4F, 0, 1,
                                             *(f32 *)(vars + 0xC) * 231000.0f, *(f32 *)(vars + 0xC) * 252000.02f, 0.0f);
                    if (part != 0) {
                        part[2] = D_L01_00221098[0x5C][0];
                    }
                }
                angle = func_0038DAB8(angle, 0.063466519f);
            }
        } else {
            for (n = 0; n < 100; n++) {
                s32 a = (s32)func_L01_00443A18(2.0f, 5.0f);
                func_0038D890(&v50, &q40, &p, angle);
                func_0038CF68(&v50, &v50, *(f32 *)(vars + 0xC) * 0.30000001f);
                part = func_L01_004713C8(&q20, &v50, (func_00382498(20, 27) * 5 + 2) / 6, *(u32 *)(vars + 0x60), a, 0x4F, 0, 1,
                                         *(f32 *)(vars + 0xC) * 231000.0f, *(f32 *)(vars + 0xC) * 252000.02f, 0.0f);
                if (part != 0) {
                    part[2] = D_L01_00221098[0x5C][0];
                }
                angle = func_0038DAB8(angle, 0.063466519f);
            }
        }
    }
    func_0038CB00(vars + 0x14);
    func_L01_00404A10(func_L01_003DF8B8, m);
    } else {
        func_003C2880(m);
    }
}
/* localdecomp:end func_L01_003DF8C0 */

/* localdecomp:start func_L01_003E0058 */
Obj_003DC268 *func_L01_003E0058(u128_t *position, u128_t *direction) {
    extern Obj_003DC268 *func_003C24B0(s32, s32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_00382538(void);
    extern void func_0038D308(void *, void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_003C4840(f32, void *, void *);
    extern s32 func_L01_004C85C8(void *, s32, f32, f32, f32);
    extern void func_003C7C38(void *);
    Obj_003DC268 *obj = func_003C24B0(0x1E05, 0x80);
    u8 *state;
    if (obj != 0) {
        obj->pad20[0] = 0;
        obj->opacity = obj->flags = 255;
        state = (u8 *)obj->vars;
        obj->position = *position;
        *(u128_t *)state = *direction;
        *(s16 *)(state + 0x20) = (func_00382498(300, 500) * 5 + 2) / 6;
        *(u16 *)((u8 *)obj + 0x34) |= 0x100;
        *(f32 *)((u8 *)obj + 0xF0) = func_00382538();
        *(f32 *)((u8 *)obj + 0xF4) = func_00382538();
        *(f32 *)((u8 *)obj + 0xF8) = func_00382538();
        obj->pad20[3] = 64;
        func_0038D308((u8 *)obj + 0xC0, (u8 *)obj + 0xF0);
        func_003C4840(func_003824E0(0.05235988f, 0.10471976f), state + 0x10, (u8 *)obj + 0xD0);
        *(f32 *)((u8 *)obj + 0x2C) = *(f32 *)(*(u8 **)((u8 *)obj + 0x24) + 0x24) * func_003824E0(0.25f, 0.3f);
        *(s32 *)(state + 0x28) = func_L01_004C85C8(obj, 0, 1.0f, 1.0f, 1.0f);
        func_003C7C38(obj);
    }
    return obj;
}
/* localdecomp:end func_L01_003E0058 */

INCLUDE_ASM("asm/levels", func_L01_003E01B8);
