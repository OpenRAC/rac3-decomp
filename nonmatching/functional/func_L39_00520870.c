/* functional: high. Same reads, writes, calls and call order as retail PAL; written from the PAL assembly with the structure of the NTSC-U draft but PAL's own constants, thresholds (0xCC, %27) and callees. Differences are register allocation/scheduling only. */
#include "vu0.h"

typedef vu0_v4 V_520870;
typedef struct {
    char p0[0x10];
    V_520870 pos;
    char p20[4];
    char *classdata;
    float p28, scale;
    char p30[0x38];
    char *data;
    char p6c[0x3e];
    unsigned short cls;
    char pac[0x10];
    unsigned char state;
    char pbd[0x33];
    V_520870 rot;
} M_520870;
typedef struct {
    V_520870 vel;
    void *owner;
    int flags;
    unsigned char a, b;
    unsigned short cls;
    float damage;
    int enabled, unused, extra;
} Hit_520870;
typedef union {
    V_520870 v[6];
    Hit_520870 hit;
} Scratch_520870;
typedef struct {
    char p0[0x18];
    char *obj;
    int count;
    V_520870 point, unused, normal;
} Collision_520870;

extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CFB8(void *, void *, f32);
extern void func_0038D328(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern f32 func_L18_00457C10(f32, f32, f32, f32, f32, f32 *);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L39_005C5FC8(void *, void *, s32, s32, s32, s32, s32, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_L01_0040E790(void *, void *, void *);
extern void func_L39_005B8978(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern s32 func_0019D510(void);
extern Collision_520870 D_L39_0025F740;

void func_L39_00520870(M_520870 *m)
{
    V_520870 old, impulse, point, dir, delta;
    Scratch_520870 s;
    char *p;
    float angle, f, radius;
    int life;
    unsigned char hit;

    if (!m) return;
    p = m->data;
    if (!p) return;
    *(vu0_q *)&impulse = 0;
    impulse.z = 0.160000011f;
    m->scale += (*(float *)(m->classdata + 0x24) - m->scale) * 0.0600000024f;
    *(float *)(p + 0x38) += ((1.20000005f - *(float *)(p + 0x38)) * 0.120000005f) * 1.44000006f;
    vec_sub_ab(&delta, p + 0x10, &m->pos);
    if (*(int *)(p + 0x34) < 0xCC) {
        angle = func_0038D160(delta.x, delta.y);
        m->rot.z = func_L18_00457C10(m->rot.z, angle, 0.0376991145f, 0, 0, (float *)(p + 0x3C));
        angle = func_0038D160(func_0038CED8(&delta), delta.z);
        m->rot.y = func_L18_00457C10(m->rot.y, -angle, 0.0376991145f, 0, 0, (float *)(p + 0x40));
        vec_sub_ab(&delta, p + 0x10, p + 0x20);
        angle = func_0038CEA8(&delta);
        if (angle < 6.0f) *(float *)(p + 0x44) *= angle / 6.0f;
        else *(float *)(p + 0x44) += 0.120000005f;
    }
    func_00382760(&dir, *(float *)(p + 0x38), m->rot.z, -m->rot.y);
    *(vu0_q *)&s.v[1] = 0;
    s.v[1].x = func_L39_005B4410(-1.0f, 1.0f);
    s.v[1].y = func_L39_005B4410(-1.0f, 1.0f);
    s.v[1].z = func_L39_005B4410(-1.0f, 1.0f);
    s.v[0] = s.v[1];
    func_0038CF68(&s.v[0], &s.v[0], func_L39_005B4410(0.1f, 0.2f) * 0.0200000014f);
    func_0038CF68(&point, &dir, -func_L39_005B4410(0.00200000009f, 0.0200000014f));
    vec_add_ba(&s.v[0], &s.v[0], &point);
    func_0038CF68(&point, &dir, func_L39_005B4410(0, 1.0f) * *(float *)(p + 0x38));
    vec_add_ab(&point, &point, &m->pos);
    life = (func_L39_005B43C8(28, 40) * 5 + 2) / 6;
    func_L39_005C5FC8(&point, &s.v[0], 0x6F00AFFF, 0x100000FF, life, 40, func_L39_005B43C8(40, 70), 1);
    *(vu0_q *)&old = *(vu0_q *)&m->pos;
    vec_add_ba(p + 0x20, p + 0x20, &dir);
    *(float *)(p + 0x48) = func_0038DAB8(*(float *)(p + 0x48), *(float *)(p + 0x50));
    *(float *)(p + 0x4C) = func_0038DAB8(*(float *)(p + 0x4C), *(float *)(p + 0x54));
    *(float *)(p + 0x48) = func_0038DAB8(*(float *)(p + 0x48), func_0038D0B0(*(float *)(p + 0x4C)) * 0.075000003f);
    if (*(float *)(p + 0x44) > 0.7f) *(float *)(p + 0x44) = 0.7f;
    hit = 0;
    goto move_first;
move_test:
    if (!(0.1f < *(float *)(p + 0x44))) goto move_done;
move_first:
    f = func_0038D0B0(*(float *)(p + 0x48));
    s.v[0].y = *(float *)(p + 0x44) * f * func_0038D098(*(float *)(p + 0x4C));
    f = func_0038D098(*(float *)(p + 0x48));
    s.v[0].z = *(float *)(p + 0x44) * f * func_0038D098(*(float *)(p + 0x4C));
    s.v[0].x = s.v[0].w = 0.0f;
    func_0038D328(&s.v[2], &m->rot);
    func_0038D028(&s.v[0], &s.v[0], &s.v[2]);
    vec_add_ba(&m->pos, &s.v[0], p + 0x20);
    if (!func_003D3CB0(&old, &m->pos, 6, *(void **)(p + 0x30), 0)) goto move_done;
    hit = 1;
    *(float *)(p + 0x44) = *(float *)(p + 0x44) * 0.7f;
    goto move_test;
move_done:
    if (hit) {
        m->rot.z = func_0038D160(m->pos.x - old.x, m->pos.y - old.y);
        m->rot.y = -func_0038D160(func_0038CF38(&old, &m->pos), m->pos.z - old.z);
        *(float *)(p + 0x3C) = 0;
        *(float *)(p + 0x40) = 0;
    }
    if (m->pos.x < 0 || m->pos.y < 0 || m->pos.z < 0) goto destroy;
    s.hit.owner = *(void **)(p + 0x30);
    s.hit.flags = 0x01030001;
    s.hit.damage = *(float *)(p + 0x5C);
    s.hit.enabled = 1;
    s.hit.vel = dir;
    func_0038CFB8(&s.hit.vel, &s.hit.vel, 1.0f);
    s.hit.vel.w = 5627.925f;
    s.hit.b = 3;
    s.hit.cls = m->cls;
    s.hit.vel.z = 1.0f;
    s.hit.a = 3;
    s.hit.extra = *(int *)(p + 0x60);
    if (func_003D3CB0(&old, &m->pos, 0, *(void **)(p + 0x30), &s.hit)) {
        if (D_L39_0025F740.obj) {
            if (D_L39_0025F740.obj == *(char **)(p + 0x30) || *(short *)(D_L39_0025F740.obj + 0xAA) == 0x1092) goto alive;
            m->state = 2;
            m->pos = D_L39_0025F740.point;
            func_L01_0040E790(&impulse, &dir, &D_L39_0025F740.normal);
            func_0038CF68(&impulse, &impulse, 0.0400000028f);
            func_L39_005B8978(m, &impulse, 0, 10, 3, 9, 0, 1, 0.0f, 0.0f, 4.0f, 2.0f, 9.0f, 1.0f, 15.0f, 1, -1, 0, 0x01010001);
            goto destroy;
        } else if (D_L39_0025F740.count > 0) {
            m->state = 1;
            m->pos = D_L39_0025F740.point;
            func_L01_0040E790(&impulse, &dir, &D_L39_0025F740.normal);
            func_0038CF68(&impulse, &impulse, 0.0400000028f);
            func_L39_005B8978(m, &impulse, 0, 10, 3, 9, 0, 1, 0.0f, *(float *)(p + 0x5C), 4.0f, 2.0f, 9.0f, 1.0f, 15.0f, 1, -1, 0, 0x01010001);
            goto destroy;
        }
    } else if (func_0038CAD0(p + 0x34)) {
destroy:
        func_003C2880(m);
        return;
    }
alive:
    if (*(int *)(p + 0x34) % 27 == 0) {
        if (func_0019D510() & 1) *(float *)(p + 0x50) *= func_L39_005B4410(-0.7f, -1.5f);
        if (func_0019D510() & 1) *(float *)(p + 0x54) *= func_L39_005B4410(-0.6f, -1.6f);
    }
}
