#include "common.h"

/* localdecomp:start func_L02_00307520 */
/* from the NTSC-U draft of func_L02_00307298 (nonmatching/levels/func_L02_00307520.c) */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } V_00307520;
typedef struct {
    char pad0[0x58]; u8 a58, a59, a5a; char p5b[0x15];
    s32 path, instant, index, timer; f32 rate, base_z, speed; s32 wait;
    f32 start_z; s32 pad94; void *area; s32 short_wait, long_wait;
} Data_00307520;
typedef struct {
    char p0[0x10]; V_00307520 pos; u8 state; char p21[0xf];
    u8 opacity, p31; u16 p32, flags; char p36[0xd];
    u8 anim; char p44[0x1c]; u8 bits; char p61[7]; Data_00307520 *data;
    char p6c[0x54]; V_00307520 matrix[3]; V_00307520 rotation;
} Moby_00307520;
typedef struct { s32 count; char pad4[0xc]; V_00307520 points[1]; } Path_00307520;
typedef struct {
    char p0[0x80]; V_00307520 pos, orientation; char pa0[0x50];
    V_00307520 velocity, extra, step, projected, flat; char p140[0xb0]; s16 locked;
    char p1f2[0x15e]; f32 ground; char p354[0xc]; s32 active;
    char p364[0x2260]; s32 state, p25c8, previous;
    char p25d0[0x15]; u8 lock;
} Hero_00307520;
extern Hero_00307520 D_001A4BE0;
extern Path_00307520 *D_L02_0021C700[];
extern f32 D_L02_001DC4F4;
__asm__(".extern D_L02_001DC4F4, 4");
typedef struct { char p[0x140]; V_00307520 pos140; V_00307520 pos150; } S_00307520;
extern S_00307520 D_L02_001E1140;
extern u8 D_001439F4[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern void func_003C2880(void *);
extern s32 func_00382468(s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CF00(void *, void *);
extern s32 func_0038CAD0(void *);
extern s32 func_00382380(void *, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D308(void *, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L02_00307BB8(void *, void *);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern s32 func_L01_004463F8(void *, void *, s32);
extern s32 func_L01_004561B8(void *);
extern void func_L01_004EDE10(void);

void func_L02_00307520(Moby_00307520 *m) {
    V_00307520 v0, v1, v2;
    Data_00307520 *p = m->data;
    switch (m->state) {
    case 0:
        if (p->instant) {
            p->a58 = 15;
            p->a5a = 12;
            m->state = 2;
            m->opacity = 255;
            m->flags |= 1;
            p->base_z = m->pos.z;
            p->wait = 25;
        } else {
            if (p->path == -1) { func_003C2880(m); break; }
            p->index = func_00382468(D_L02_0021C700[p->path]->count);
            p->timer = 500;
            if (m->anim != 1) func_003C3A10(m, 1, 0, 8);
            m->pos.z = D_L02_0021C700[p->path]->points[0].z - D_L02_001DC4F4;
            p->start_z = m->pos.z;
            m->state = 1;
        }
        break;
    case 1:
        *(vu0_q *)&v0 = *(vu0_q *)&D_L02_0021C700[p->path]->points[p->index];
        func_L01_00448890(&m->rotation.z, func_0038D160(v0.x - m->pos.x, v0.y - m->pos.y), &p->rate, 0.0012566371588036418f, 0.0012566371588036418f, 0.06283185631036758f, 0);
        func_0038CF68(&v1, &m->matrix[0], 0.06000000238418579f);
        vec_add_ab(&m->pos, &m->pos, &v1);
        if (func_0038CF00(&m->pos, &v0) < 3.0f || func_0038CAD0(&p->timer)) {
            s32 k = func_00382468(D_L02_0021C700[p->path]->count);
            p->index = (p->index + k) % D_L02_0021C700[p->path]->count;
            p->timer = 500;
        }
        break;
    case 2:
        func_0038CAD0(&p->wait);
        if (fabs_asm(D_001A4BE0.ground - p->base_z) < 0.8f && D_001A4BE0.previous == 18 && !func_00382380(&D_001A4BE0.pos, (s32)p->area, 0)) {
            if (p->wait) break;
            m->rotation.y = -1.5533430576324463f;
            m->rotation.z = func_0038DAB8(D_L02_001E1140.pos150.z, 1.5707963705062866f);
            func_0038D308(&m->matrix[0], &m->rotation);
            *(vu0_q *)&m->pos = *(vu0_q *)&D_001A4BE0.pos;
            func_0038CF68(&v0, &m->matrix[2], D_L02_001DC4F4);
            vec_sub_ab(&m->pos, &m->pos, &v0);
            p->speed = 0.1600000113248825f;
            m->flags &= 0xfffe;
            func_003A52A0(1, 0, m);
            if (m->anim != 2) func_003C3A10(m, 2, 10, 4);
            m->state = 3;
            *(vu0_q *)&v1 = *(vu0_q *)&D_001A4BE0.pos;
            v1.z = D_001A4BE0.ground;
            func_L02_00307BB8(m, &v1);
            func_L01_004F50C8(&D_001A4BE0.pos, &D_001A4BE0.orientation, 49, 0);
            D_001A4BE0.lock = 1;
            if (!D_001439F4[0]) func_L01_003EB438(0, &D_L02_001E1140.pos140, &D_L02_001E1140.pos150, 0, 0, 0);
        } else if (D_001A4BE0.state != 18 && D_001A4BE0.active) {
            if (p->path != -1 && func_L01_004463F8(&D_001A4BE0.pos, &D_L02_0021C700[p->path]->points[0], D_L02_0021C700[p->path]->count)) p->wait = (p->long_wait * 5 + 2) / 6;
            else p->wait = (p->short_wait * 5 + 2) / 6;
        }
        break;
    case 3:
        if (func_L01_004561B8(m)) func_003A52A0(1, 0, m);
        qzero(&D_001A4BE0.velocity);
        qzero(&D_001A4BE0.step);
        qzero(&D_001A4BE0.projected);
        qzero(&D_001A4BE0.flat);
        D_001A4BE0.locked = 3;
        D_001A4BE0.lock = 1;
        m->pos.z += p->speed;
        if (D_001D545C != 9) p->speed -= 0.004f;
        else p->speed -= 0.008f;
        if (p->speed < 0.04000000283122063f) {
            func_0038CF68(&v0, &m->matrix[2], D_L02_001DC4F4);
            func_L01_00448890(&m->rotation.y, 1.5533430576324463f, &p->rate, 0.005026548635214567f, 0.005026548635214567f, 0.5026548504829407f, 0);
            func_0038D308(&m->matrix[0], &m->rotation);
            func_0038CF68(&v1, &m->matrix[2], D_L02_001DC4F4);
            vec_sub_ba(&v2, &v1, &v0);
            vec_sub_ab(&m->pos, &m->pos, &v2);
        }
        if (p->speed < 0 && m->pos.z < D_001A4BE0.ground) {
            *(vu0_q *)&v0 = *(vu0_q *)&D_001A4BE0.pos;
            v0.z = D_001A4BE0.ground;
            func_L02_00307BB8(m, &v0);
        }
        if (p->speed < 0 && m->pos.z < p->base_z) func_L01_004EDE10();
        if ((m->bits & 2) && m->anim != 1) func_003C3A10(m, 1, 0, 8);
        break;
    }
}
/* localdecomp:end func_L02_00307520 */
