/* NTSC-U draft (Codex wave 3): C of func_L39_0051F2D8, the NTSC-U twin of func_L39_0051F740, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 163 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_0051F2D8", whose code is not the PAL one).
 * Worker's note: 163 diff; best log func_L39_0051F2D8.09.log; NEEDS divs row 'func_L39_0051F2D8 2 2' (checked in memory). Register allocation, pointer lookup and VU0 block scheduling remain; j constraints fail with permitted flags (01.log). 9 checks.
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L39_0051F2D8 */
typedef struct {
    vu0_v4 pos;
    u8 pad10[8];
    u8 b18, b19;
    u16 h1A;
    s32 f1C, f20, f24, f28, f2C;
} Hit_51F2D8;
typedef struct { u8 pad[0x20]; f32 f20; s32 f24, f28, f2C; u8 tail[0x430]; } Row_51F2D8;
typedef struct { u8 pad[0x34]; f32 damage; u8 tail[0x48]; } Weapon_51F2D8;
typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 state; u8 p21[0x13]; u16 flags; u8 p36[0x32]; void *pvar; u8 p6C[0x3E]; s16 oclass; } M_51F2D8;
typedef struct { u8 p0[0x24C9]; u8 id; u8 p24CA[0x5A]; M_51F2D8 *moby; u8 p2528[0x1C]; s32 index; s32 value; } Owner_51F2D8;
typedef struct { u8 p0[0x10]; f32 phase; s32 timer; f32 step; s32 opacity; s32 p20; s32 timer24; s32 handle; s32 value; Owner_51F2D8 *owner; } P_51F2D8;
extern Row_51F2D8 D_L39_0024DF80[];
extern Owner_51F2D8 *D_L39_0024CF20[];
extern M_51F2D8 *D_L39_002638C0[];
extern Weapon_51F2D8 D_L39_0049C950[];
extern u8 D_L39_0049CBD0[];
extern s32 func_L01_00454168(s32, s32);
extern s32 func_L01_00453FC0(void *, s32, s32 *);
extern s32 func_L01_00454190(s32, s32);
extern void func_L39_0051F928(void *, void *);
extern s32 func_L39_005BC958(void *, s32, f32);
extern void func_L39_005FD658(s32);
extern s32 func_003CF790(void *, s32, void *, s32, f32);
extern void func_L39_005FD6D8(void);
extern s32 func_0037E0B8(void *);
extern void func_00388830(void *, f32, void *);
extern s32 func_L39_00646268(void *, s32);
extern void func_L01_00443628(void *, void *, s32, f32, void *);
extern void func_L01_00443840(void *, void *);
extern s32 func_00388398(void *);
extern void func_003BD360(void *);
extern void func_L39_0051FEE8(void *);
extern void func_L01_004026A0(void *, void *);

void func_L39_0051F2D8(M_51F2D8 *m) {
    vu0_v4 pos, delta;
    Hit_51F2D8 hit;
    s32 handle;
    P_51F2D8 *d = m->pvar;
    s32 count, remaining;
    vu0_v4 *position;
    M_51F2D8 **p;
    f32 radius, fraction;
    if (m->state && !func_L01_00454168(m->oclass, d->handle)) {
        func_003BD360(m);
        return;
    }
    switch (m->state) {
    case 0:
        m->state = 1;
        d->phase = 0.0f;
        d->timer = 20;
        d->step = 0.666666687f;
        d->opacity = 0x7F;
        d->timer24 = 0x6F;
        d->handle = func_L01_00453FC0(m, 0, &handle);
        func_L01_00454190(m->oclass, d->handle);
        pos = m->pos;
        pos.z += 1.0f;
        func_L39_0051F928(m, &m->pos);
        if (d->owner) {
            delta = pos;
            delta.w = 2.0f;
            if (func_L39_005BC958(&delta, 0, 100.0f) != -1) {
                D_L39_0024DF80[d->owner->id].f20 = 0.449999988f;
                D_L39_0024DF80[d->owner->id].f28 = 40;
                D_L39_0024DF80[d->owner->id].f2C = 0;
            }
        }
        /* Fall through. */
    case 1:
        d->timer24 -= 5;
        if (d->timer24 < 0) d->timer24 = 0;
        position = &m->pos;
        radius = (1.0f - (f32)d->timer / 20.0f) * 6.0f + 0.001f;
        d->phase += d->step;
        {
            Owner_51F2D8 *owner = D_L39_0024CF20[d->owner->index];
            s32 id;
            if (owner) id = owner->value;
            else id = -1;
            func_L39_005FD658(id);
        }
        count = func_003CF790(position, 0, m, 0, radius);
        func_L39_005FD6D8();
        if (count > 0) {
            Weapon_51F2D8 *weapons = D_L39_0049C950;
            for (p = D_L39_002638C0, remaining = count; remaining; p++, remaining--) {
                if (!func_0037E0B8(*p) && !((*p)->flags & 0x4000)) goto next;
                if (!d->owner || *p == d->owner->moby) {
                    if ((*p)->oclass != 0x1068) goto next;
                }
                if ((*p)->oclass != 0xA5A) {
                    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                        : "=m"(delta) : "m"(m->pos), "m"((*p)->pos) : "vf1", "vf2");
                    func_00388830(&delta, 1.0f, &delta);
                    func_00388830(&hit, 1.0f, &hit);
                    {
                        Weapon_51F2D8 *weapon;
                        if (func_L39_00646268(d->owner, 5))
                            weapon = weapons + (s8)D_L39_0049CBD0[0x21];
                        else weapon = weapons + 5;
                        func_L01_00443628(&hit, m, 0x01030001, weapon->damage, &delta);
                    }
                    hit.pos = delta;
                    hit.f20 = 1;
                    hit.pos.w = 5627.9248046875f;
                    hit.b18 = 5;
                    hit.b19 = 3;
                    hit.h1A = (u16)(*p)->oclass;
                    hit.f28 = d->value;
                    func_L01_00443840(*p, &hit);
                }
            next: ;
            }
        }
        if (func_00388398(&d->timer)) {
            m->state = 2;
            d->timer = 40;
        }
        break;
    case 2:
        fraction = (f32)d->timer / 40.0f;
        d->phase += d->step;
        if (func_00388398(&d->timer)) {
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
        func_003BD360(m);
        return;
    }
    func_L01_004026A0(func_L39_0051FEE8, m);
}
/* localdecomp:end func_L39_0051F2D8 */
