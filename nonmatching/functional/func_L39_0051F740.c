/* functional: high. Instruction stream equal after masking regs except scheduling; needs vu0 flag line. */
#include "vu0.h"
typedef struct {
    vu0_v4 pos;
    u8 pad10[8];
    u8 b18, b19;
    u16 h1A;
    s32 f1C, f20, f24, f28, f2C;
} Hit_0051F740;
typedef struct { u8 pad[0x20]; f32 f20; s32 f24, f28, f2C; u8 tail[0x430]; } Row_0051F740;
typedef struct { u8 pad[0x34]; f32 damage; u8 tail[0x48]; } Weapon_0051F740;
typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 state; u8 p21[0x13]; u16 flags; u8 p36[0x32]; void *pvar; u8 p6C[0x3E]; s16 oclass; } M_0051F740;
typedef struct { u8 p0[0x24C9]; u8 id; u8 p24CA[0x5A]; M_0051F740 *moby; u8 p2528[0x1C]; s32 index; s32 value; } Owner_0051F740;
typedef struct { u8 p0[0x10]; f32 phase; s32 timer; f32 step; s32 opacity; s32 p20; s32 timer24; s32 handle; s32 value; Owner_0051F740 *owner; } P_0051F740;
extern Row_0051F740 D_L39_0024DE80[];
extern Owner_0051F740 *D_L39_0024CE20[];
extern M_0051F740 *D_L39_002637C0[];
extern Weapon_0051F740 D_L39_0049C890[];
extern u8 D_L39_0049CB10[];
extern s32 func_L01_00457458(s32, s32);
extern s32 func_L01_004572B0(void *, s32, s32 *);
extern void func_L01_00457480(s32, s32);
extern void func_L39_0051FD90(void *, void *);
extern s32 func_L39_005BE900(void *, s32, f32);
extern void func_L39_005FFDF8(s32);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern void func_L39_005FFE78(void);
extern s32 func_00382348(void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L39_00648AE0(void *, s32);
extern void func_L01_00446760(void *, void *, s32, f32, void *);
extern void func_L01_00446978(void *, void *);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern void func_L39_00520350(void *);
extern void func_L01_00404A10(void *, void *);

/* Multiplayer-menu level: an area-damage burst (explosion) object. State 0 sets it up and tells the
 * owner's player data, state 1 damages everything in a growing radius once per frame, state 2 fades
 * its opacity out, state 6 deletes it. */
void func_L39_0051F740(M_0051F740 *m) {
    vu0_v4 pos, delta;
    Hit_0051F740 hit;
    s32 handle;
    P_0051F740 *d = m->pvar;
    s32 count, remaining;
    vu0_v4 *position;
    M_0051F740 **p;
    f32 radius, fraction;

    if (m->state && !func_L01_00457458(m->oclass, d->handle)) {
        func_003C2880(m);
        return;
    }
    switch (m->state) {
    case 0:
        m->state = 1;
        d->phase = 0.0f;
        d->timer = 17;
        d->step = 0.8000000715255737f;
        d->opacity = 0x7F;
        d->timer24 = 0x6F;
        d->handle = func_L01_004572B0(m, 0, &handle);
        func_L01_00457480(m->oclass, d->handle);
        pos = m->pos;
        pos.z += 1.0f;
        func_L39_0051FD90(m, &m->pos);
        if (d->owner) {
            delta = pos;
            delta.w = 2.0f;
            if (func_L39_005BE900(&delta, 0, 100.0f) != -1) {
                D_L39_0024DE80[d->owner->id].f20 = 0.44999998807907104f;
                D_L39_0024DE80[d->owner->id].f28 = 33;
                D_L39_0024DE80[d->owner->id].f2C = 0;
            }
        }
        /* fall through */
    case 1:
        d->timer24 -= 5;
        if (d->timer24 < 0) d->timer24 = 0;
        position = &m->pos;
        radius = (1.0f - (f32)d->timer / 17.0f) * 6.0f + 0.0010000000474974513f;
        d->phase += d->step;
        {
            Owner_0051F740 *owner = D_L39_0024CE20[d->owner->index];
            s32 id;
            if (owner) id = *(s32 *)((u8 *)owner + 0x2548);
            else id = -1;
            func_L39_005FFDF8(id);
        }
        count = func_003D4D00(position, 0, m, 0, radius);
        func_L39_005FFE78();
        if (count > 0) {
            Weapon_0051F740 *weapons = D_L39_0049C890;
            for (p = D_L39_002637C0, remaining = count; remaining; p++, remaining--) {
                if (!func_00382348(*p) && !((*p)->flags & 0x4000)) goto next;
                if (!d->owner || *p == d->owner->moby) {
                    if ((*p)->oclass != 0x1068) goto next;
                }
                if ((*p)->oclass != 0xA5A) {
                    vec_sub_ba(&delta, &(*p)->pos, &m->pos);
                    func_0038CF68(&delta, &delta, 1.0f);
                    func_0038CF68(&hit, &hit, 1.0f);
                    {
                        Weapon_0051F740 *weapon;
                        if (func_L39_00648AE0(d->owner, 5))
                            weapon = weapons + (s8)D_L39_0049CB10[0x21];
                        else weapon = weapons + 5;
                        func_L01_00446760(&hit, m, 0x01030001, weapon->damage, &delta);
                    }
                    hit.pos = delta;
                    hit.f20 = 1;
                    hit.pos.w = 5627.9248046875f;
                    hit.b18 = 5;
                    hit.b19 = 3;
                    hit.h1A = (u16)(*p)->oclass;
                    hit.f28 = d->value;
                    func_L01_00446978(*p, &hit);
                }
            next: ;
            }
        }
        if (func_0038CAD0(&d->timer)) {
            m->state = 2;
            d->timer = 33;
        }
        break;
    case 2:
        fraction = (f32)d->timer / 40.0f;
        d->phase += d->step;
        if (func_0038CAD0(&d->timer)) {
            if (d->opacity) --d->opacity;
            else {
                d->opacity = 0;
                m->state = 6;
            }
        } else {
            d->opacity = (s32)(fraction * 127.0f);
        }
        break;
    case 6:
        d->phase += d->step;
        func_003C2880(m);
        return;
    }
    func_L01_00404A10(func_L39_00520350, m);
}
