/* functional: high. Original uses the address bit (p>>8)&1 as a per-object random spin sign; the port must keep objects at stable addresses or substitute a stable per-object bit. Duration pick for phase+1 is quirky but matches the .s. Snippet includes vu0.h (file context lacks it). */
/* localdecomp:start func_L01_00474F38 */
#include "vu0.h"
typedef struct {
    vu0_v4 velocity;
    s16 timer, duration;
    u8 phase, first, second, third;
    f32 scale;
} State_00474F38;

static __inline__ void add_00474F38(void *d, void *a, void *b) {
    __asm__(
        "lqc2 $vf1, %2\n"
        "lqc2 $vf2, %1\n"
        "vadd.xyz $vf2, $vf2, $vf1\n"
        "sqc2 $vf2, %0"
        : "=m"(*(vu0_v4 *)d)
        : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b)
        : "vf1", "vf2");
}

static __inline__ void add_step_00474F38(void *d, void *a, void *b) {
    __asm__(
        "lqc2 $vf2, %2\n"
        "lqc2 $vf1, %1\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d)
        : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b)
        : "vf2", "vf1");
}

__asm__(".extern D_L01_001D7FA0, 4");
extern s32 D_L01_001D7FA0;
__asm__(".extern D_L01_001D7FA4, 4");
extern s32 D_L01_001D7FA4;
__asm__(".extern D_L01_001D7F94, 4");
extern s32 D_L01_001D7F94;
__asm__(".extern D_L01_001D7F90, 4");
extern s32 D_L01_001D7F90;
__asm__(".extern D_L01_001D7F98, 4");
extern s32 D_L01_001D7F98;
__asm__(".extern D_L01_001D7F9C, 4");
extern f32 D_L01_001D7F9C;
typedef struct {
    s32 type, color;
    u8 spin, pad9[3];
    f32 scale;
    vu0_v4 pos;
    State_00474F38 state;
} Particle_00474F38;
void func_L01_00474F38(Particle_00474F38 *p) {
    extern s32 func_0038CB00(void *);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_L01_00448070(s32, s32, f32);
    extern f32 func_003C4088(f32, f32, f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern void func_003CD250(u8 *);
    State_00474F38 *s = &p->state;
    vu0_v4 step;
    f32 ratio;

    if (func_0038CB00(&s->timer)) {
        s32 phase = (s32)++s->phase + 1;
        s32 duration;
        if (phase == 0) duration = s->first;
        else if (phase == 1) duration = s->second;
        else duration = s->third;
        s->timer = duration;
        s->duration = duration;
    }
    if (s->phase == 0) {
        s32 spin;
        s32 result;
        add_00474F38(&p->pos, &p->pos, &s->velocity);
        spin = p->spin;
        if (!(((s32)p >> 8) & 1)) result = spin - D_L01_001D7FA0;
        else result = spin + D_L01_001D7FA0;
        p->spin = result;
    } else if (s->phase == 1) {
        s32 n;
        s32 spin;
        ratio = (f32)s->timer;
        ratio /= (f32)s->duration;
        func_0038CE20(&step, s, ratio);
        n = func_L01_00448070(D_L01_001D7FA4, D_L01_001D7FA0, ratio);
        add_step_00474F38(&p->pos, &p->pos, &step);
        spin = p->spin + n;
        if (!(((s32)p >> 8) & 1)) spin = p->spin - n;
        p->spin = spin;
        p->scale = func_003C4088(s->scale, D_L01_001D7F9C, ratio);
        p->color = func_0038DBD8(D_L01_001D7F94, D_L01_001D7F90, ratio);
    } else if (s->phase == 2) {
        s32 n;
        s32 spin;
        ratio = (f32)s->timer;
        ratio /= (f32)s->duration;
        n = func_L01_00448070(0, D_L01_001D7FA4, ratio);
        spin = p->spin + n;
        if (!(((s32)p >> 8) & 1)) spin = p->spin - n;
        p->spin = spin;
        p->scale = func_003C4088(s->scale * 0.5f, s->scale, ratio);
        p->color = func_0038DBD8(D_L01_001D7F98, D_L01_001D7F94, ratio);
    } else {
        func_003CD250((u8 *)p);
    }
}
/* localdecomp:end func_L01_00474F38 */
