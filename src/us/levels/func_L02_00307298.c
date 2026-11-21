#include "common.h"

/* NTSC-U counterpart of func_L02_00307520 (src/levels/shared/L02_00307520.c) */
/* localdecomp:start func_L02_00307298 */
/* from the NTSC-U draft of func_L02_00307298 (nonmatching/levels/func_L02_00307298.c) */
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
extern Path_00307520 *D_L02_0021C780[];
extern f32 D_L02_001DC534;
__asm__(".extern D_L02_001DC534, 4");
typedef struct { char p[0x140]; V_00307520 pos140; V_00307520 pos150; } S_00307520;
extern S_00307520 D_L02_001E11C0;
extern u8 D_001439F4[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern void func_003BD360(void *);
extern s32 func_0037E1D8(s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_00388A28(f32, f32);
extern f32 func_L01_00445758(void *, f32, void *, f32, f32, f32, s32);
extern void func_00388830(void *, void *, f32);
extern f32 func_003887C8(void *, void *);
extern s32 func_00388398(void *);
extern s32 func_0037E0F0(void *, s32, s32);
extern f32 func_00389380(f32, f32);
extern void func_00388BD0(void *, void *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L02_00307918(void *, void *);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_L01_003E9588(s32, void *, void *, s32, s32, s32);
extern s32 func_L01_004432C0(void *, void *, s32);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_004EA040(void);

void func_L02_00307298(Moby_00307520 *m) {
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
            p->wait = 30;
        } else {
            if (p->path == -1) { func_003BD360(m); break; }
            p->index = func_0037E1D8(D_L02_0021C780[p->path]->count);
            p->timer = 600;
            if (m->anim != 1) func_003BE4F0(m, 1, 0, 10);
            m->pos.z = D_L02_0021C780[p->path]->points[0].z - D_L02_001DC534;
            p->start_z = m->pos.z;
            m->state = 1;
        }
        break;
    case 1:
        *(vu0_q *)&v0 = *(vu0_q *)&D_L02_0021C780[p->path]->points[p->index];
        func_L01_00445758(&m->rotation.z, func_00388A28(v0.x - m->pos.x, v0.y - m->pos.y), &p->rate, 0.0008726647f, 0.0008726647f, 0.052359883f, 0);
        func_00388830(&v1, &m->matrix[0], 0.050000004f);
        vec_add_ab(&m->pos, &m->pos, &v1);
        if (func_003887C8(&m->pos, &v0) < 3.0f || func_00388398(&p->timer)) {
            s32 k = func_0037E1D8(D_L02_0021C780[p->path]->count);
            p->index = (p->index + k) % D_L02_0021C780[p->path]->count;
            p->timer = 600;
        }
        break;
    case 2:
        func_00388398(&p->wait);
        if (fabs_asm(D_001A4BE0.ground - p->base_z) < 0.8f && D_001A4BE0.previous == 18 && !func_0037E0F0(&D_001A4BE0.pos, (s32)p->area, 0)) {
            if (p->wait) break;
            m->rotation.y = -1.5533430576324463f;
            m->rotation.z = func_00389380(D_L02_001E11C0.pos150.z, 1.5707963705062866f);
            func_00388BD0(&m->matrix[0], &m->rotation);
            *(vu0_q *)&m->pos = *(vu0_q *)&D_001A4BE0.pos;
            func_00388830(&v0, &m->matrix[2], D_L02_001DC534);
            vec_sub_ab(&m->pos, &m->pos, &v0);
            p->speed = 0.13333334f;
            m->flags &= 0xfffe;
            func_0039FE80(1, 0, m);
            if (m->anim != 2) func_003BE4F0(m, 2, 10, 5);
            m->state = 3;
            *(vu0_q *)&v1 = *(vu0_q *)&D_001A4BE0.pos;
            v1.z = D_001A4BE0.ground;
            func_L02_00307918(m, &v1);
            func_L01_004F12C0(&D_001A4BE0.pos, &D_001A4BE0.orientation, 49, 0);
            D_001A4BE0.lock = 1;
            if (!D_001439F4[0]) func_L01_003E9588(0, &D_L02_001E11C0.pos140, &D_L02_001E11C0.pos150, 0, 0, 0);
        } else if (D_001A4BE0.state != 18 && D_001A4BE0.active) {
            if (p->path != -1 && func_L01_004432C0(&D_001A4BE0.pos, &D_L02_0021C780[p->path]->points[0], D_L02_0021C780[p->path]->count)) p->wait = p->long_wait;
            else p->wait = p->short_wait;
        }
        break;
    case 3:
        if (func_L01_00452EC8(m)) func_0039FE80(1, 0, m);
        qzero(&D_001A4BE0.velocity);
        qzero(&D_001A4BE0.step);
        qzero(&D_001A4BE0.projected);
        qzero(&D_001A4BE0.flat);
        D_001A4BE0.locked = 3;
        D_001A4BE0.lock = 1;
        m->pos.z += p->speed;
        if (D_001D545C != 9) p->speed -= 0.0027777778f;
        else p->speed -= 0.0055555557f;
        if (p->speed < 0.033333335f) {
            func_00388830(&v0, &m->matrix[2], D_L02_001DC534);
            func_L01_00445758(&m->rotation.y, 1.5533430576324463f, &p->rate, 0.0034906587f, 0.0034906587f, 0.41887906f, 0);
            func_00388BD0(&m->matrix[0], &m->rotation);
            func_00388830(&v1, &m->matrix[2], D_L02_001DC534);
            vec_sub_ba(&v2, &v1, &v0);
            vec_sub_ab(&m->pos, &m->pos, &v2);
        }
        if (p->speed < 0 && m->pos.z < D_001A4BE0.ground) {
            *(vu0_q *)&v0 = *(vu0_q *)&D_001A4BE0.pos;
            v0.z = D_001A4BE0.ground;
            func_L02_00307918(m, &v0);
        }
        if (p->speed < 0 && m->pos.z < p->base_z) func_L01_004EA040();
        if ((m->bits & 2) && m->anim != 1) func_003BE4F0(m, 1, 0, 10);
        break;
    }
}
/* localdecomp:end func_L02_00307298 */
