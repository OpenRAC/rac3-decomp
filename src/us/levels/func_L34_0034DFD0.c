#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L34_0034DFD0 */
typedef struct {
    u8 pad0[0x14]; u8 b14; u8 pad15[0x50-0x15];
    vu0_q pos; s32 flags; s32 gate; f32 f68; s32 timer;
    f32 speed; s32 mode; f32 f78; f32 phase; s32 duration; s32 cooldown; s32 timeout;
} State_34DFD0;
typedef struct {
    u8 pad0[0x10]; vu0_q pos; u8 state; u8 pad21[3]; u8 *model;
    u8 pad28[0xC]; u16 flags; u8 pad36[0xD]; u8 anim;
    u8 pad44[0x1C]; u8 status; u8 pad61[7]; State_34DFD0 *vars;
    u8 pad6c[0x28]; u8 previous; u8 pad95[3]; s32 collision;
} Moby_34DFD0;
extern s32 D_L34_001DD740;
extern f32 D_L34_001DD744;
extern s32 D_L34_001DD74C;
extern s32 D_L34_001DD750;
extern f32 D_L34_001DD754;
__asm__(".extern D_L34_001DD740, 4");
__asm__(".extern D_L34_001DD744, 4");
__asm__(".extern D_L34_001DD74C, 4");
__asm__(".extern D_L34_001DD750, 4");
__asm__(".extern D_L34_001DD754, 4");
extern u8 D_001A4C60[];
extern s32 func_L01_00452EC8(void *);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32,
    f32, f32, f32, f32, s32, s32, s32, s32, s32, s32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);
extern void func_L01_004A6DF8(void *, s32);
extern s32 func_L30_0034C9F8_0034DFD0(void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L34_0034E7E0(void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L34_0034E938(void *);
extern s32 func_L01_0044AF40(void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L30_0034B420(void *, void *, void *, f32, s32, s32);
extern void func_L34_0034E8A8(void *);
extern void func_L34_0034E808(void *);
extern s32 func_0037E0F0(void *, s32, s32);
extern void func_L34_0034E608(void *);

void func_L34_0034DFD0(Moby_34DFD0 *m) {
    State_34DFD0 *s = m->vars;
    switch (m->state) {
    case 0x42:
        if (func_L01_00452EC8(m)) {
            func_L01_0032FE90(&m->pos, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1,
                0.9f, 0.0f, 0.0f, 2.0f,
                1, 1, 0, 0, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            m->pos = s->pos;
            s->flags &= ~4;
            if ((s->flags & 2) || (((*(u8 *)&s->flags) ^ 1) & 1)) {
                func_003BD360(m);
                return;
            }
            m->collision = 0;
            m->flags = (m->flags | 0x41) & ~0x1000;
            func_L01_004A6DF8(m, 1);
        }
        if (func_L30_0034C9F8_0034DFD0(&m->pos, 1.5f)) {
            if ((s->flags & 1) == 0) break;
            if (s->flags & 4) {
                m->flags &= ~0x41;
                m->flags |= *(u16 *)(m->model + 0x44) & 0x1000;
                m->collision = *(s32 *)(m->model + 0x10);
                func_L01_00441FB8(m, 0, -1);
            }
        } else {
            s->flags |= 4;
        }
        break;
    case 0:
        func_L34_0034E7E0(m);
        func_L01_00441FB8(m, 5, -1);
        break;
    case 1:
        if (func_L01_00452EC8(m)) {
            if (m->anim != 1) func_003BE4F0(m, 1, 0, D_L34_001DD740);
            s->cooldown = s->duration;
            if (m->previous != 4) s->timer = 0;
        }
        s->timer += 1;
        s->phase = (f32)s->timer * s->speed /
            ((fabs_asm(s->f78) + fabs_asm(s->f68)) * 3.1415927410125732f);
        func_L34_0034E938(m);
        if (s->cooldown == 0) {
            if (m->anim != 2) func_003BE4F0(m, 2, 0, D_L34_001DD740);
            else {
                if (s->duration != -1 && func_L01_0044AF40(m, D_L34_001DD744)) {
                    f32 v[4] __attribute__((aligned(16)));
                    f32 *p = v;
                    qzero(v);
                    v[2] = -1.0f;
                    func_00388830(p, p, D_L34_001DD754);
                    func_L30_0034B420(m, p, &m->pos, (f32)s->b14, D_L34_001DD750, D_L34_001DD750);
                }
                if (m->status & 2) {
                    s->cooldown = s->duration;
                    if (m->anim != 1) func_003BE4F0(m, 1, 0, D_L34_001DD740);
                }
            }
        }
        break;
    case 2:
        if (func_L01_00452EC8(m)) {
            if (m->anim != 1) func_003BE4F0(m, 1, 0, D_L34_001DD740);
            s->cooldown = s->duration;
        }
        if (s->cooldown == 0) {
            if (m->anim != 2) func_003BE4F0(m, 2, 0, D_L34_001DD740);
            else {
                if (s->duration != -1 && func_L01_0044AF40(m, D_L34_001DD744)) {
                    f32 v[4] __attribute__((aligned(16)));
                    f32 *p = v;
                    qzero(v);
                    v[2] = -1.0f;
                    func_00388830(p, p, D_L34_001DD754);
                    func_L30_0034B420(m, p, &m->pos, (f32)s->b14, D_L34_001DD750, D_L34_001DD750);
                }
                if (m->status & 2) {
                    s->cooldown = s->duration;
                    if (m->anim != 1) func_003BE4F0(m, 1, 0, D_L34_001DD740);
                }
            }
        }
        func_L34_0034E8A8(m);
        break;
    case 3:
        if (func_L01_00452EC8(m)) {
            if (m->anim != 1) func_003BE4F0(m, 1, 0, D_L34_001DD740);
            if (m->previous != 4) s->timer = 0;
        }
        s->timer += 1;
        s->phase = s->speed * (f32)s->timer /
            ((fabs_asm(s->f68) + fabs_asm(s->f78)) * 0.7853981852531433f);
        if (s->phase > 1.0f) func_L01_00441FB8(m, 2, -1);
        else func_L34_0034E808(m);
        break;
    case 4:
        if (func_L01_00452EC8(m)) {
            if (m->anim != 3) func_003BE4F0(m, 3, 0, D_L34_001DD740);
            s->timeout = D_L34_001DD74C;
        }
        if (m->status & 2) func_L01_00441FB8(m, m->previous, -1);
        break;
    case 5:
        if (func_L01_00452EC8(m)) {
            if (m->anim != 0) func_003BE4F0(m, 0, 0, D_L34_001DD740);
        }
        if (!(s->gate ? func_0037E0F0(D_001A4C60, s->gate, 0) : func_L30_0034C9F8_0034DFD0(&m->pos, 1.5f))) break;
        if (s->mode) func_L01_00441FB8(m, 1, -1);
        else func_L01_00441FB8(m, 3, -1);
        break;
    }
    func_L34_0034E608(m);
}
/* localdecomp:end func_L34_0034DFD0 */
