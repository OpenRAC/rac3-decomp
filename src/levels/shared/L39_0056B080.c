#include "common.h"

/* localdecomp:start func_L39_0056B080 */
typedef struct {
    u8 pad0[0x100];
    f32 f100;
    f32 f104;
    u8 pad108[0x1A0 - 0x108];
    s32 w1A0;
} Pad_0056B080;

typedef struct {
    u8 pad0[0x40];
    u8 pos[0x10];
    u8 pad50[0xF0 - 0x50];
    u8 *wF0;
    s32 wF4;
    s32 wF8;
    s32 wFC;
    s32 w100;
    s32 w104;
    u8 pad108[0x11C - 0x108];
    s32 w11C;
    u8 pad120[0x126 - 0x120];
    s16 h126;
    u8 pad128[0x12C - 0x128];
    u8 b12C;
    u8 pad12D[0x133 - 0x12D];
    u8 b133;
    Pad_0056B080 *p134;
    u8 pad138[0x144 - 0x138];
    s32 w144;
    f32 f148;
    u8 pad14C[0x2B0 - 0x14C];
} St_0056B080;

typedef struct {
    u8 pad0[0x108];
    f32 f108[6];
    u8 pad120[0x144 - 0x120];
    struct {
        u8 *w144;
        s32 w148;
    } s144;
    u8 pad14C[4];
    St_0056B080 st;
    void (*fn400)(s32);
    u8 pad404[0x460 - 0x404];
} Ent_0056B080;

typedef struct {
    u8 pad0[0xD0];
    f32 fD0;
    u8 padD4[0x104 - 0xD4];
    f32 f104;
    u8 pad108[0x110 - 0x108];
    f32 f110;
    s32 w114;
} P60_0056B080;

typedef struct {
    u8 pad0[0x4E];
    s16 h4E;
} P210_0056B080;

typedef struct {
    s32 w0;
    u8 pad4[0xC];
    s32 w10;
} P260_0056B080;

typedef struct {
    u8 pad0[0x12];
    s16 h12;
    s16 h14;
    s16 h16;
    u8 pad18[0x130 - 0x18];
    f32 f130;
} Cam_0056B080;

typedef struct {
    u8 pad0[0x70];
    Cam_0056B080 *cam;
    u8 pad74[0x94 - 0x74];
    s32 player;
} Obj_0056B080;

extern Ent_0056B080 D_L39_0024DE80[];
extern s32 D_L39_0024B858[] __attribute__((section(".sdata")));
extern s32 D_L39_002429BC;
__asm__(".extern D_L39_002429BC, 16");
extern f32 D_L39_00242388[] __attribute__((section(".sdata")));
extern s32 D_L39_002637C0[];
extern f32 D_L39_0024B690;
extern s32 D_L39_0024B6AC;
__asm__(".extern D_L39_0024B690, 4");
__asm__(".extern D_L39_0024B6AC, 4");

extern s32 func_L01_003F2B58(s32 player);
extern void func_L01_003E8BD0(s32 player, s32 both, f32 distance, f32 gain);
extern void func_L01_003E8C28(s32 player, f32 height, f32 gain);
extern void func_L01_003E8D80(s32 player, s32 a);
extern void func_L01_003E8DB8(s32 player, f32 spring, f32 damping);
extern void func_L01_003E8E10(s32 player, f32 spring, f32 damping);
extern void func_L01_003E8E70(s32 player);
extern void func_L01_003E8EA8(s32 player);
extern void func_L01_003E8EE8(s32 player, s32 a);
extern void func_L01_003E8F20(s32 player, f32 x, f32 y, f32 z);
extern void func_L01_003E9250(s32 player, void *direction, f32 speed, f32 a);
extern void func_L01_003E92B0(s32 player, void *direction, f32 speed, f32 a);
extern s32 func_003D4D00(void *centre, f32 radius, s32 kinds, void *skip, s32 extra);
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(s16 *count);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *func_00382348(s32);

static __inline__ u8 state_0056B080(u8 *m)
{
    return m[0x20];
}

void func_L39_0056B080(Obj_0056B080 *a)
{
    s32 flag = 0;
    s32 player = a->player;
    Ent_0056B080 *ent = &D_L39_0024DE80[player];
    St_0056B080 *st = &ent->st;
    P60_0056B080 *p60 = (P60_0056B080 *)((u8 *)a->cam + 0x60);
    P210_0056B080 *p210 = (P210_0056B080 *)((u8 *)a->cam + 0x210);
    P260_0056B080 *p260 = (P260_0056B080 *)((u8 *)a->cam + 0x260);
    s32 camvol;
    s32 i;
    f32 t;
    f32 v[4];
    f32 sum;
    f32 gain;
    void *pos;
    s32 n;
    s32 k;
    Ent_0056B080 *e;
    Ent_0056B080 *e2;

    camvol = func_L01_003F2B58(player);
    if (st->w100 == 0x7E || st->w100 == 0x7A || st->w100 == 0x90) {
        p210->h4E = 1;
    }
    if (st->w11C == 0 || p60->w114 != 0) {
        t = p60->f110;
        if (t > 2.0f) {
            t = 2.0f;
        }
        p60->f104 = (D_L39_0024B690 - 0.002f) * (t * 0.5f) + 0.002f;
        if (st->w11C != 0) {
            func_0038CAD0(&p60->w114);
        } else {
            p60->w114 = 12;
        }
    }
    if (st->w104 == 0x1E) {
        a->cam->f130 = 0.75f;
        func_L01_003E8E10(player, 0.04f, 0.2f);
    }
    if (st->wFC == 0xD && st->w144 != 0) {
        f32 ang = func_0038DAB8(st->f148, 3.1415927f);
        v[0] = func_0038D098(ang);
        v[1] = func_0038D0B0(ang);
        v[2] = 0.0f;
        func_L01_003E9250(player, v, 0.20943952f, v[2]);
        func_L01_003E8EA8(player);
    }
    if (st->w104 == 0x11) {
        p60->fD0 = 0.25f;
        func_L01_003E8C28(player, 0.5f, 0.003f);
        D_L39_0024B858[player] = 0xB4;
    } else {
        func_L01_003E8EE8(player, 0x14);
        D_L39_0024B858[player] = 0x94;
    }
    if (st->w104 == 5 && D_L39_002429BC == 0) {
        a->cam->f130 = 0.25f;
        flag = 1;
        func_L01_003E8C28(player, 2.5f, 0.003f);
    }
    if (st->w104 == 0x10) {
        p60->fD0 = 0.25f;
    }
    if (st->b12C != 0 && st->b133 != 0 && p260->w0 == 0 && camvol == -1) {
        gain = 0.003f;
        func_L01_003E8BD0(player, 1, 6.75f, gain);
        if (flag == 0) {
            p60->fD0 = 2.0f;
            func_L01_003E8C28(player, 2.75f, gain);
        }
    }
    if (ent->fn400 != 0) {
        ent->fn400(player);
    }
    e = &D_L39_0024DE80[player];
    if (e->s144.w144 != 0) {
        if (p260->w10 < 2) {
            if (state_0056B080(e->s144.w144) == 0xFE || state_0056B080(e->s144.w144) == 0xFD) {
                e->s144.w144 = 0;
            } else {
                if (__builtin_fabsf(st->p134->f100) >= 0.3f || __builtin_fabsf(st->p134->f104) >= 0.3f) {
                    e->s144.w148 = 0x215;
                }
                e2 = &D_L39_0024DE80[player];
                if (e2->s144.w148 >= 0x14E) {
                    func_0038CAD0(&D_L39_0024DE80[player].s144.w148);
                    if (e2->s144.w148 < 0x14E) {
                        e2->s144.w148 = 0;
                    }
                } else {
                    e2->s144.w148 = e2->s144.w148 + 1;
                    if (e2->s144.w148 >= 0x14E) {
                        e2->s144.w148 = 0x14D;
                    }
                    func_L01_003E92B0(player, e2->s144.w144 + 0x10, (f32)e2->s144.w148 / 333.0f * 1.5707964f, 0.0f);
                    func_L01_003E8EA8(player);
                    func_L01_003E8DB8(player, 0.03f, 0.2f);
                }
            }
        }
    }
    if (st->w100 == 0x83) {
        func_L01_003E8EA8(player);
        func_L01_003E8DB8(player, 1.0f, 1.0f);
        func_L01_003E8E10(player, 0.06f, 0.2f);
        func_L01_003E8E70(player);
    }
    if (st->w100 == 0x7D) {
        func_L01_003E8DB8(player, 0.04f, 0.2f);
        func_L01_003E9250(player, st->wF0 + 0xC0, 0.7853982f, 0.017453292f);
        func_L01_003E8BD0(player, 0, 3.0f, 0.003f);
        func_L01_003E8F20(player, -1.0f, -1.0f, 0.18f);
        func_L01_003E8E70(player);
    }
    if (p260->w10 < 2 && st->w100 != 0x83 && st->w100 != 0x7D &&
        (st->h126 != 0 || ((st->w100 == 0x80 || st->w100 == 0x84) && (st->p134->w1A0 & 3) != 0))) {
        func_L01_003E8D80(player, 0);
        pos = st->pos;
        func_L01_003E8EA8(player);
        func_L01_003E8DB8(player, 0.04f, 0.2f);
        {
            Cam_0056B080 *c = a->cam;
            c->h16 = 0;
            c->h12 = 0;
            c->h14 = 0;
        }
    } else {
    pos = st->pos;
    if (D_L39_0024B6AC != 0) {
        Cam_0056B080 *c = a->cam;
        f32 t;
        sum = 0.0f;
        for (i = 0; i < 4; i++) {
            v[i] = func_0038DBA0(ent->f108[i + 1], ent->f108[i + 2]);
            sum += v[i];
        }
        sum *= 0.25f;
        t = sum * 5.0f;
        if (t > 1.0f) {
            t = 1.0f;
        }
        t = 1.0f - t;
        if (t < 0.3f) {
            c->h12 = 0x1B;
        }
        if (c->h12 != 0) {
            if (func_0038CB00(&c->h12)) {
                c->h14 = 0x25;
            }
            func_L01_003E8EA8(player);
            c->h16 = c->h16 + 1;
            if (c->h16 >= 0x1A) {
                c->h16 = 0x19;
            }
            func_L01_003E8DB8(player, (f32)c->h16 / 25.0f * (0.04f - 0.015f) + 0.015f, 0.2f);
            D_L39_00242388[player] = 0.0f;
        } else if (c->h14 != 0) {
            func_0038CB00(&c->h14);
            D_L39_00242388[player] = (f32)c->h14 / 37.0f * -0.85f + 0.85f;
            c->h16 = 0;
        } else {
            c->h16 = 0;
            D_L39_00242388[player] = 0.85f;
        }
    }
    }
    p260->w10 = 0;
    n = func_003D4D00(pos, 15.0f, 1, st->wF0, 0);
    if (n > 0) {
        for (k = 0; k < n; k++) {
            u8 *o = func_00382348(D_L39_002637C0[k]);
            if (o != 0 && (f32)o[0xD] != 0.0f) {
                p260->w10 = 1;
                break;
            }
        }
    }
}
/* localdecomp:end func_L39_0056B080 */

INCLUDE_ASM("asm/levels", func_L39_0056B940);
