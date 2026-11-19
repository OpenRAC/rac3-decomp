#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad[0x68];
    u8 *w68;
} Moby_003BD218;
typedef int s128_3C1AB8 __attribute__((mode(TI)));
typedef union { s128_3C1AB8 q; f32 f[4]; } V_3C1AB8;
typedef struct {
    u8 pad[0x38];
    f32 f38;
    u8 pad3C[0x180 - 0x3C];
    s128_3C1AB8 v180;
    s128_3C1AB8 v190;
    s128_3C1AB8 v1A0;
    u8 pad1B0[0x1D0 - 0x1B0];
    s32 w1D0;
} P_3C1AB8;
typedef struct {
    u8 pad[0x10];
    s128_3C1AB8 pos;
    u8 pad20[0x68 - 0x20];
    P_3C1AB8 *p68;
} M_3C1AB8;
typedef int s128_3C1EE0 __attribute__((mode(TI)));
typedef struct { u8 pad[0x20]; u8 b20; } M_3C1EE0;
typedef struct {
    u8 pad0;
    u8 unk1;
    u8 pad2[106];
    f32 unk6C;
    u8 pad70[128];
} S_002C5640;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[88];
    s32 a[6];
    s32 b[4];
    s32 c[4];
    u8 pad1[224];
    u8 d[16];
} Obj_003C3C68;
typedef int u128_3C3E90 __attribute__((mode(TI)));
typedef struct { u8 pad[0x25C4]; s32 w25C4; u8 pad25C8[0x283C - 0x25C8]; f32 f283C; } G_3C4008;
typedef struct { u8 pad[0x98]; s32 w98; } P_3C4008;
typedef struct { u8 pad[0x54]; P_3C4008 *p54; u8 pad58[0x100 - 0x58]; u8 b100; } B_3C4008;
typedef struct { u8 pad[0x20]; u8 b20; } M_3C4008;
typedef struct {
    u8 pad0[1724];
    s32 idx;
    s32 arr[1];
} S_3C40F0;
typedef struct {
    u8 p0[0x24];
    s32 id;
    u8 p28[0x698];
    s32 a1728[36];
    s32 a1872[4];
} O_3C41F8;
typedef struct { u8 p0[0x34]; u16 h52; u8 p36[0xCA]; } M_3C41F8;
typedef struct M3C48A8 M3C48A8;
typedef struct {
    u8 pad0[80];
    s32 link;
    u8 pad84[1360 - 84];
    M3C48A8 *child;
} V3C48A8;
struct M3C48A8 {
    u8 pad0[32];
    u8 state;
    u8 pad21[52 - 33];
    u16 flags;
    u8 pad36[104 - 54];
    V3C48A8 *vars;
    u8 pad6C[152 - 108];
    s32 f98;
    u8 pad9C[256 - 156];
};
typedef struct {
    u8 pad0[258];
    u8 active;
    u8 pad103[264 - 259];
    s32 group;
} O3C48A8;

LINKER_REMNANT("asm/levels", func_L01_003BE598);

/* localdecomp:start func_L01_003BE5A0 */
#include "vu0.h"
extern f32 D_L01_001DEB80;
extern f32 D_L01_001DEB84;
__asm__(".extern D_L01_001DEB80, 4");
__asm__(".extern D_L01_001DEB84, 4");
extern s32 D_001A71A0[];
typedef struct { u128_t position, normal; } HitPair_003BE5A0;
extern HitPair_003BE5A0 D_L01_001EAA30;
extern vu0_v4 D_L01_001EAA20;
void func_L01_003BE5A0(u8 *m) {
    extern f32 func_0038DAB8(f32, f32);
    extern void func_003C5278(void *, void *, void *, f32);
    extern s32 func_L01_003FB640(void *, s32, s32, f32);
    extern f32 func_0038CE68(void *, void *);
    extern void func_L01_0040E790(void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, M_3C1AB8 *, s32);
    extern f32 func_0038CEA8(void *);
    extern s32 func_0038CAD0(void *);
    extern s32 func_L01_004561B8(u8 *);
    extern void func_L01_0044C638(u8 *, M_3C1AB8 *, void *, void *, void *, void *);
    extern void func_L01_004450F0(u8 *, s32, s32);
    extern s32 func_L01_00448070(s32, s32, f32);
    extern void func_003C2880(u8 *);
    V_3C1AB8 a, b;
    u8 *p = *(u8 **)(m + 0x68);
    f32 *velocity;
    u8 *pos;
    u8 *ground_pos;
    u8 *normal;
    f32 fade;
    s32 one = 1;
    u8 *hit;
    M_3C1AB8 *object;
    switch (m[0x20]) {
    case 0:
        pos = m + 0x10;
        a.q = *(u128_t *)pos;
        velocity = (f32 *)(p + 0x20);
        *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(m + 0xF8), *(f32 *)(p + 8));
        vec_add_ab(pos, pos, velocity);
        func_003C5278(pos, velocity, velocity, D_L01_001DEB80 * 0.00040000002f);
        if (func_L01_003FB640(pos, 4, D_001A71A0[0], 0.07f)) {
            *(u128_t *)pos = D_L01_001EAA30.position;
            normal = (u8 *)&D_L01_001EAA30.normal;
            if (func_0038CE68(velocity, normal) < 0.0f) {
                func_L01_0040E790(velocity, velocity, normal);
                func_0038CE20(velocity, velocity, 0.15f);
            }
            goto speed_check;
        } else if (func_003D3CB0(&a, pos, 2, 0, 0)) {
            *(u128_t *)pos = *(u128_t *)&D_L01_001EAA20;
            func_L01_0040E790(velocity, velocity, (u8 *)&D_L01_001EAA20 + 0x20);
            func_0038CE20(velocity, velocity, 0.15f);
speed_check:
            if (func_0038CEA8(velocity) < 0.014f) {
                m[0x20] = one;
                break;
            }
        }
        if (func_0038CAD0(p) || *(f32 *)(m + 0x10) < 2.0f || *(f32 *)(m + 0x10) > 1021.0f ||
            *(f32 *)(m + 0x14) < 2.0f || *(f32 *)(m + 0x14) > 1021.0f ||
            *(f32 *)(m + 0x18) < 2.0f) goto destroy;
        if (!(*(f32 *)(m + 0x18) > 1021.0f)) break;
        goto destroy;
    case 1:
        if (func_L01_004561B8(m)) {
            a.q = *(u128_t *)(m + 0x10);
            a.f[2] += 1.0f;
            b.q = a.q;
            b.f[2] = 0.0f;
            if (func_003D3CB0(&a, &b, 0, (M_3C1AB8 *)m, 0)) *(f32 *)(m + 0x18) = D_L01_001EAA20.z + 0.057f;
        } else {
            ground_pos = m + 0x10;
            a.q = *(u128_t *)ground_pos;
            a.f[2] += 1.0f;
            b.q = a.q;
            b.f[2] = 0.0f;
            if (func_003D3CB0(&a, &b, 0, (M_3C1AB8 *)m, 0)) {
                /* The collision record starts 0x20 bytes before its position vector. */
                hit = (u8 *)&D_L01_001EAA20 - 0x20;
                object = *(M_3C1AB8 **)(hit + 0x18);
                if (object != 0) func_L01_0044C638(m, object, ground_pos, m + 0xF0, ground_pos, m + 0xF0);
                else *(f32 *)(m + 0x18) = *(f32 *)(hit + 0x28) + 0.057f;
            }
        }
        if (m[0x95] == 1) func_L01_004450F0(m, 2, -1);
        break;
    case 2:
        if (func_L01_004561B8(m)) *(u16 *)(m + 0x34) |= 0x2800;
        ground_pos = m + 0x10;
        a.q = *(u128_t *)ground_pos;
        a.f[2] += 1.0f;
        b.q = a.q;
        b.f[2] = 0.0f;
        if (func_003D3CB0(&a, &b, 0, (M_3C1AB8 *)m, 0)) {
            hit = (u8 *)&D_L01_001EAA20 - 0x20;
            object = *(M_3C1AB8 **)(hit + 0x18);
            if (object != 0) func_L01_0044C638(m, object, ground_pos, m + 0xF0, ground_pos, m + 0xF0);
            else *(f32 *)(m + 0x18) = *(f32 *)(hit + 0x28) + 0.057f;
        }
        fade = (f32)*(u16 *)(m + 0x96) / D_L01_001DEB84;
        fade = 1.0f < fade ? 1.0f : fade;
        m[0x23] = func_L01_00448070(128, 0, fade);
        if (m[0x23] < 2) {
destroy:
            func_003C2880(m);
            return;
        }
        break;
    }
    (*(u16 *)(m + 0x96))++;
}
/* localdecomp:end func_L01_003BE5A0 */

LINKER_REMNANT("asm/levels", func_L01_003BEA58);

/* localdecomp:start func_L01_003BEA60 */

extern s32 D_L01_001D6740;
extern s16 D_001A4F48[];

s32 func_L01_003BEA60(Moby_003BD218 *m) {
    u8 *p = m->w68;
    if ((p != 0 && *(s32 *)(p + 264) == 2) || D_L01_001D6740 != 0 || D_001A4F48[0] != 0) return 1;
    return 0;
}
/* localdecomp:end func_L01_003BEA60 */

/* localdecomp:start func_L01_003BEAA0 */
extern s32 D_L01_001D673C_003BEAA0;
s32 func_L01_003BEAA0(void) {
    return D_L01_001D673C_003BEAA0;
}
/* localdecomp:end func_L01_003BEAA0 */

/* localdecomp:start func_L01_003BEAA8 */
s32 func_L01_003BEAA8(u32 a) {
    s32 r = 0;
    if (a < 2 || a == 11 || a == 13 || a == 14) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L01_003BEAA8 */

INCLUDE_ASM("asm/levels", func_L01_003BEAE0);

INCLUDE_ASM("asm/levels", func_L01_003C1978);

INCLUDE_ASM("asm/levels", func_L01_003C27E0);

/* localdecomp:start func_L01_003C2E10 */
/* The hero's four agent slots (the agent on each, 0 when free); declared small so the
   address is one la, as retail builds it. */
extern s32 D_L01_001E2200[2];

/* agent_slot_free: whether one of the hero's four agent slots has no agent hovering on it */
s32 func_L01_003C2E10(void) {
    s32 slot;

    for (slot = 0; slot < 4; slot++) {
        if (D_L01_001E2200[slot] == 0) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_003C2E10 */

/* localdecomp:start func_L01_003C2E48 */
s32 func_L01_003C2E48(s32 a0) {
    s32 slot;

    for (slot = 0; slot < 4; slot++) {
        if (D_L01_001E2200[slot] == 0) {
            D_L01_001E2200[slot] = a0;
            return slot;
        }
    }
    return -1;
}
/* localdecomp:end func_L01_003C2E48 */

/* localdecomp:start func_L01_003C2E88 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x38];
    f32 height;
    u8 pad3C[0x180 - 0x3C];
    vu0_q destination;
    vu0_q desired;
    u8 pad1A0[0x10];
    vu0_q best;
    u8 pad1C0[4];
    f32 best_distance;
    u8 pad1C8[8];
    void *target;
} Path_003C2E88;
typedef struct { u8 pad[0x18]; void *object; } Hit_003C2E88;
typedef struct { u8 pad[0xD0]; vu0_q position; u8 padE0[0x25C0 - 0xE0]; void *moby; } Hero_003C2E88;
extern u8 D_001A4BE0[];
extern Hit_003C2E88 D_L01_001EAA00;
extern vu0_v4 D_L01_001EAA20;
void func_L01_003C2E88(M_3C1AB8 *m, f32 minimum) {
    extern u8 *func_00382348(void *);
    extern f32 func_L01_0040E548(void *, void *);
    extern s32 func_003D3CB0(void *, void *, s32, M_3C1AB8 *, s32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038CF38(void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    vu0_v4 start;
    vu0_v4 end;
    vu0_v4 candidate;
    vu0_v4 direction;
    vu0_v4 displacement;
    Path_003C2E88 *p = (Path_003C2E88 *)m->p68;
    u8 *target;
    f32 angle;
    f32 distance;
    f32 degrees;
    f32 step;
    f32 collision_distance;
    f32 score;
    p->destination = p->desired;
    *(vu0_q *)&start = m->pos;
    *(vu0_q *)&end = p->desired;
    start.z += p->height;
    end.z += p->height;
    target = func_00382348(p->target);
    if (p->target == ((Hero_003C2E88 *)D_001A4BE0)->moby) {
        *(vu0_q *)&end = ((Hero_003C2E88 *)D_001A4BE0)->position;
    } else if (target != 0) {
        end.z += *(f32 *)(target + 0x10);
    }
    if (func_L01_0040E548(&start, &end) >= 3600.0f) return;
    if (!func_003D3CB0(&start, &end, 16, m, 0)) return;
    if (D_L01_001EAA00.object != 0 && D_L01_001EAA00.object == p->target) return;
    for (degrees = 10.0f; degrees <= 160.0f; degrees += 10.0f) {
        vec_sub_ab(&direction, &end, &start);
        angle = func_0038D160(direction.x, direction.y);
        distance = func_0038CED8(&direction);
        if (distance < minimum) distance = minimum;
        step = degrees * 0.01745329238474369f;
        candidate.x = func_0038D098(func_0038DAB8(step, angle)) * distance;
        candidate.y = func_0038D0B0(func_0038DAB8(step, angle)) * distance;
        candidate.z = 0.0f;
        vec_add_ab(&candidate, &start, &candidate);
        if (candidate.x < 0.0f) candidate.x = 0.5f;
        if (candidate.y < 0.0f) candidate.y = 0.5f;
        if (candidate.z < 0.0f) candidate.z = 0.5f;
        if (!func_003D3CB0(&start, &candidate, 16, m, 0)) {
            p->destination = *(vu0_q *)&candidate;
            return;
        }
        if (D_L01_001EAA00.object != 0 && D_L01_001EAA00.object == p->target) {
            p->destination = *(vu0_q *)&candidate;
        }
        vec_sub_ab(&displacement, &m->pos, &D_L01_001EAA20);
        collision_distance = func_0038CED8(&displacement);
        if (p->best_distance < collision_distance && degrees < 60.0f) {
            score = func_0038CF38(&D_L01_001EAA20, &p->desired);
            if (score < func_0038CF38(&p->best, &p->desired)) {
                p->best_distance = collision_distance;
                p->best = *(vu0_q *)&D_L01_001EAA20;
            }
        }
        step = -(degrees * 0.01745329238474369f);
        candidate.x = func_0038D098(func_0038DAB8(step, angle)) * distance;
        candidate.y = func_0038D0B0(func_0038DAB8(step, angle)) * distance;
        candidate.z = 0.0f;
        vec_add_ab(&candidate, &start, &candidate);
        if (candidate.x < 0.0f) candidate.x = 0.5f;
        if (candidate.y < 0.0f) candidate.y = 0.5f;
        if (candidate.z < 0.0f) candidate.z = 0.5f;
        if (!func_003D3CB0(&start, &candidate, 16, m, 0)) {
            p->destination = *(vu0_q *)&candidate;
            return;
        }
        if (D_L01_001EAA00.object != 0 && D_L01_001EAA00.object == p->target) {
            p->destination = *(vu0_q *)&candidate;
        }
        vec_sub_ab(&displacement, &m->pos, &D_L01_001EAA20);
        collision_distance = func_0038CED8(&displacement);
        if (p->best_distance < collision_distance && degrees < 60.0f) {
            p->best_distance = collision_distance;
            p->best = *(vu0_q *)&D_L01_001EAA20;
        }
    }
    p->destination = p->best;
}
/* localdecomp:end func_L01_003C2E88 */

/* localdecomp:start func_L01_003C3320 */
extern s32 D_L01_001EAA18[];
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, M_3C1AB8 *, s32);
void func_L01_003C3320(M_3C1AB8 *m) {
    V_3C1AB8 a;
    V_3C1AB8 b;
    P_3C1AB8 *p;
    a.q = m->pos;
    p = m->p68;
    a.f[2] += 0.1f;
    b.q = p->v190;
    a.f[2] += p->f38;
    b.f[2] += p->f38;
    if (3600.0f <= func_L01_0040E548(&a, &b)) {
        return;
    }
    if (func_003D3CB0(&a, &b, 16, m, 0) != 0) {
        if (D_L01_001EAA18[0] == 0) {
            return;
        }
        if (D_L01_001EAA18[0] != p->w1D0) {
            return;
        }
    }
    p->v180 = p->v190;
    p->v1A0 = p->v190;
}
/* localdecomp:end func_L01_003C3320 */

LINKER_REMNANT("asm/levels", func_L01_003C3408);

/* localdecomp:start func_L01_003C3410 */
#include "vu0.h"
extern u128_t D_L01_001EAA40;
s32 func_L01_003C3410(u8 *o) {
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_003C3D30(void *,s32,s32,f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32,f32);
    V_3C1AB8 a,b,c;
    u8 *d;
    f32 height, z, angle;
    a.q=*(u128_t *)(o+0x10);
    d=*(u8 **)(o+0x68);
    b.f[0]=func_0038D098(*(f32 *)(o+0xF8));
    b.f[1]=func_0038D0B0(*(f32 *)(o+0xF8));
    b.f[2]=0;
    vec_add_ab(&a,&a,&b);
    height=func_003C3D30(&a,34,0,0.5f);
    if(height<*(f32 *)(o+0x18) && *(f32 *)(d+0x3C)<fabs_asm(height-*(f32 *)(o+0x18))) {
        b.f[0]=func_0038D098(*(f32 *)(o+0xF8))*9.0f;
        b.f[1]=func_0038D0B0(*(f32 *)(o+0xF8))*9.0f;
        b.f[2]=0;
        vec_add_ab(&a,o+0x10,&b);
        *(u128_t *)(d+0x160)=a.q;
        height=func_003C3D30(&a,34,0,6.0f);
        z=*(f32 *)(o+0x18)-2.0f;
        c.q=D_L01_001EAA40;
        angle=func_0038CED8(&c);
        angle=func_0038D160(c.f[2],angle);
        if(z<height && angle<0.1745329201221466f) {
            *(f32 *)(d+0x1CC)=height;
            return 1;
        }
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L01_003C3410 */

/* localdecomp:start func_L01_003C35A0 */
extern s32 D_L01_001D6694;
extern s32 D_L01_001DEBC8;
__asm__(".extern D_L01_001DEBC8, 8");
extern s32 D_L01_001DEBD8;
__asm__(".extern D_L01_001DEBD8, 8");
extern s32 D_L01_001DEBE8;
__asm__(".extern D_L01_001DEBE8, 8");
extern void func_003C2F58(M_3C1EE0 *, s32, s128_3C1EE0 *);
extern void func_003C4C18(s128_3C1EE0 *, f32);
extern f32 func_003824E0(f32 a, f32 b);
extern void func_L01_0046E078(M_3C1EE0 *, s128_3C1EE0 *, s128_3C1EE0 *, s32 *, s32);

/* agent_jets_emit: an agent's jets (V4 and up) while it hovers and lands: three type 0x4A
   particles a frame at its point 0 */
void func_L01_003C35A0(M_3C1EE0 *agent)
{
    s128_3C1EE0 q[5];

    if (D_L01_001D6694 == 2)
        return;
    q[0] = 0;
    func_003C2F58(agent, 0, &q[1]);
    ((f32 *)&q[1])[3] = 0.0f;
    q[2] = q[1];
    q[3] = q[1];
    q[4] = q[1];
    func_003C4C18(&q[1], 0.025f);
    func_003C4C18(&q[2], 0.025f);
    func_003C4C18(&q[3], 0.025f);
    func_003C4C18(&q[4], 0.025f);
    ((f32 *)&q[0])[2] = -(func_003824E0(30.0f, 40.0f) * 0.02000000141561031f) * 0.1f;
    func_L01_0046E078(agent, &q[2], &q[0], &D_L01_001DEBC8, 1);
    ((f32 *)&q[0])[2] = -(func_003824E0(30.0f, 40.0f) * 0.02000000141561031f) * 0.1f;
    func_L01_0046E078(agent, &q[3], &q[0], &D_L01_001DEBD8, 1);
    ((f32 *)&q[0])[2] = -(func_003824E0(30.0f, 40.0f) * 0.02000000141561031f) * 0.1f;
    func_L01_0046E078(agent, &q[4], &q[0], &D_L01_001DEBE8, 1);
}
/* localdecomp:end func_L01_003C35A0 */

/* localdecomp:start func_L01_003C3748 */
extern void func_003C2F58(M_3C1EE0 *, s32, s128_3C1EE0 *);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
void func_L01_003C3748(M_3C1EE0 *m) {
    s128_3C1EE0 v;
    u32 col;
    if (m == 0) {
        return;
    }
    if (m->b20 == 254) {
        return;
    }
    if (m->b20 == 253) {
        return;
    }
    col = (m->b20 == 5) ? 0x40202080 : 0x40802020;
    func_003C2F58(m, 2, &v);
    func_003D9508(&v, 11, col, 1, 0.1f, 0.08f, 0.0f);
    func_003C2F58(m, 3, &v);
    func_003D9508(&v, 11, col, 1, 0.1f, 0.08f, 0.0f);
}
/* localdecomp:end func_L01_003C3748 */

/* localdecomp:start func_L01_003C3830 */
#include "vu0.h"
extern s32 D_L01_001E2210[1];
extern s32 D_L01_001DD6E8;
extern vu0_q D_L01_001E21C0[] __attribute__((section(".sdata")));
extern s32 D_L01_001E2200[2];
void func_L01_003C3830(void) {
    s32 i, j;
    s32 *slot;
    vu0_q *p;
    for (i = 7; i >= 0; i--) {
        D_L01_001E2210[i] = 0;
    }
    D_L01_001DD6E8 = 0;
    slot = D_L01_001E2200;
    p = D_L01_001E21C0;
    for (j = 3; j >= 0; j--) {
        qzero(p);
        *slot = 0;
        p++;
        slot++;
    }
}
/* localdecomp:end func_L01_003C3830 */

/* localdecomp:start func_L01_003C3898 */
extern s32 D_L01_001E2210[1];

s32 func_L01_003C3898(void)
{
    s32 i;
    s32 *p;

    i = 0;
    p = D_L01_001E2210;
    for (; i < 8; i++) {
        if (*p == 0)
            return 0;
        p++;
    }
    return 1;
}
/* localdecomp:end func_L01_003C3898 */

/* localdecomp:start func_L01_003C38D0 */
extern s32 D_001A71A0[];
extern s32 D_L01_001E2200[2];
extern s32 D_L01_001E2210[1];
extern s32 D_L01_001DD6E8;
void func_L01_003C38D0(u8 *obj) {
    extern void func_L01_004C8598(s32);
    extern void func_L01_003F5EE0(u8 *);
    extern void func_003C2880(u8 *);
    u8 *p;
    s32 i;
    func_L01_004C8598(D_001A71A0[0]);
    p = *(u8 **)(obj + 0x68);
    func_L01_003F5EE0(obj);
    if (p != 0 && *(s16 *)(p + 0x15C) != -1) {
        D_L01_001E2200[*(s16 *)(p + 0x15C)] = 0;
    }
    for (i = 0; i < 8; i++) {
        if (D_L01_001E2210[i] == (s32)obj) {
            D_L01_001E2210[i] = 0;
            break;
        }
    }
    D_L01_001DD6E8--;
    if (D_L01_001DD6E8 < 0) D_L01_001DD6E8 = 0;
    func_003C2880(obj);
}
/* localdecomp:end func_L01_003C38D0 */

/* localdecomp:start func_L01_003C39A8 */

extern u8 D_001425C0[];
extern S_002C5640 D_L01_002C5600[];

extern void func_L01_004C7D98(u8 *, u8 *);
extern u8 *func_L01_00392908(u8 *, u8 *);
extern void func_003A52A0(s32, s32, u8 *);
extern s32 func_L01_003BEAA0_003C39A8(void);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_004CB2D8(void);
extern void func_L01_003C38D0(u8 *);

void func_L01_003C39A8(u8 *arg0) {
    u8 buf[16];
    u8 *v;
    u8 x;
    s32 t;

    x = D_L01_002C5600[D_001425C0[87]].unk1;
    t = x < 4;
    if (!t) {
        func_L01_004C7D98(arg0 + 16, buf);
        v = func_L01_00392908(arg0 + 16, buf);
        if (v != 0) {
            *(s32 *)(v + 184) = *(s32 *)(arg0 + 184);
        }
    } else if (x == 0 || !t) {
        func_003A52A0(0, 0, arg0);
        func_L01_003303B8(arg0 + 16, 0, 20, 20, 20, 20, 0, 2, 0.5f, 0.0f, 0.0f, 2.0f,
                      func_L01_003BEAA0_003C39A8() == 0, 1, 0, 0, 1, 1, 0x1010000, 0, 0x388EF7, 25591, 0x407FFF, 8447, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_L01_00446780(arg0, arg0 + 16, 0x1010000, 0, 1, 0, 2.0f, D_L01_002C5600[D_001425C0[87]].unk6C, 0.0f);
    }
    if (func_L01_004CB2D8() != 0) {
        func_L01_003303B8(arg0 + 16, 0, 3, 3, 3, 6, 3, 0, 0.5f, 0.0f, 0.0f, 2.0f,
                      0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 25591, 0x407FFF, 8447, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    }
    func_L01_003C38D0(arg0);
}
/* localdecomp:end func_L01_003C39A8 */

/* localdecomp:start func_L01_003C3C50 */
extern s32 func_L01_003C3898(void);
extern s32 func_00382468(s32);
extern void func_L01_003C39A8(u8 *);

void func_L01_003C3C50(u8 *arg) {
    s32 i;
    if (((s32 (*)(u8 *))func_L01_003C3898)(arg) == 0) {
        for (i = 0; i < 8; i++) {
            if (((u8 **)D_L01_001E2210)[i] == 0) {
                ((u8 **)D_L01_001E2210)[i] = arg;
                return;
            }
        }
    } else {
        s32 idx = func_00382468(8);
        func_L01_003C39A8(((u8 **)D_L01_001E2210)[idx]);
        ((u8 **)D_L01_001E2210)[idx] = arg;
    }
}
/* localdecomp:end func_L01_003C3C50 */

/* localdecomp:start func_L01_003C3CE8 */
extern s32 D_L01_002BB3E0[];
s32 *func_L01_003C3CE8(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 0) {
        *a2 = 104;
        return D_L01_002BB3E0;
    }
    return 0;
}
/* localdecomp:end func_L01_003C3CE8 */

INCLUDE_ASM("asm/levels", func_L01_003C3D08);

INCLUDE_ASM("asm/levels", func_L01_003C4C40);

/* localdecomp:start func_L01_003C5110 */

extern void func_003C7C38(u8 *a0);

void func_L01_003C5110(void *a0, u8 *a1) {
    s32 i;
    u8 **pp = (u8 **)(a1 + 64);
    for (i = 4; i >= 0; i--) {
        u8 *m = *pp++;
        if (m != 0) {
            u8 *v = *(u8 **)(m + 104);
            func_003C7C38(m);
            *(u128_t *)(v + 112) = *(u128_t *)(m + 16);
            *(u128_t *)(v + 128) = *(u128_t *)(m + 240);
        }
    }
}
/* localdecomp:end func_L01_003C5110 */

/* localdecomp:start func_L01_003C5188 */
extern void func_003C4DA8(void *, void *, void *, void *);

void func_L01_003C5188(u8 *a0, u8 *a1) {
    u8 **pp = (u8 **)(a1 + 0x40);
    s32 i;

    for (i = 0; i < 5; i++) {
        u8 *p = pp[i];

        if (p != 0) {
            u8 *v = *(u8 **)(p + 0x68);
            u128_t tmp;

            func_003C7C38(p);
            vec_sub_ab(&tmp, p + 0x10, v + 0x70);
            func_003C4DA8(v + 0x30, &tmp, v + 0x80, p + 0xF0);
            *(u128_t *)(v + 0x70) = *(u128_t *)(p + 0x10);
            *(u128_t *)(v + 0x80) = *(u128_t *)(p + 0xF0);
        }
    }
}
/* localdecomp:end func_L01_003C5188 */

/* localdecomp:start func_L01_003C5220 */

extern void func_0038D308(u8 *, u8 *);
extern void func_L01_0044F450(u8 *, u8 *);
extern void func_L01_003C5188(u8 *, u8 *);

void func_L01_003C5220(u8 *a0, u8 *a1) {
    func_0038D308(a0 + 192, a0 + 240);
    func_L01_0044F450(a0, a1 + 368);
    *(u128_t *)(a1 + 272) = *(u128_t *)(a0 + 16);
    *(u128_t *)(a1 + 288) = *(u128_t *)(a0 + 240);
    *(f32 *)(a1 + 248) = *(f32 *)(a1 + 1652);
    *(f32 *)(a1 + 252) = *(f32 *)(a1 + 1704);
    func_L01_003C5188(a0, a1);
}
/* localdecomp:end func_L01_003C5220 */

INCLUDE_ASM("asm/levels", func_L01_003C5290);

/* localdecomp:start func_L01_003C54E8 */
extern void func_L01_003C5CA8(void *self, u8 *obj);

extern void func_L01_0044F8D8(void *, s32);
extern void func_003CD250(s32);

void func_L01_003C54E8(void *self, Obj_003C3C68 *o) {
    s32 i;

    func_L01_0044F8D8(o->d, 0);
    ((void (*)(void *, Obj_003C3C68 *))func_L01_003C5CA8)(self, o);
    for (i = 0; i < 6; i++) {
        if (o->a[i] != 0) {
            func_003CD250(o->a[i]);
            o->a[i] = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        if (o->b[i] != 0) {
            func_003CD250(o->b[i]);
            o->b[i] = 0;
        }
        if (o->c[i] != 0) {
            func_003CD250(o->c[i]);
            o->c[i] = 0;
        }
    }
}
/* localdecomp:end func_L01_003C54E8 */

/* localdecomp:start func_L01_003C55B8 */
extern u16 **D_L01_001D6764;
extern u8 *D_L01_001E0ED4;
s32 func_L01_003C55B8(void *a0, u8 *a1) {
    u16 *p = D_L01_001D6764[*(s32 *)(a1 + 0x20)];
    u8 *e = D_L01_001E0ED4 + ((*p & 0x7FFF) << 5);

    return e[0x1C] != 0;
}
/* localdecomp:end func_L01_003C55B8 */

/* localdecomp:start func_L01_003C55F8 */
extern s32 D_L01_001DEE54;
s32 func_L01_003C55F8(void) {
    return D_L01_001DEE54;
}
/* localdecomp:end func_L01_003C55F8 */

/* localdecomp:start func_L01_003C5600 */
u8 func_L01_003C5600(u8 *a) {
    return *(*(u8 **)(a + 0x68) + 0x103);
}
/* localdecomp:end func_L01_003C5600 */

/* localdecomp:start func_L01_003C5610 */
extern void func_L01_003C6F68(void *, s32);
void func_L01_003C5610(void *p) {
    func_L01_003C6F68(p, *(s32 *)((u8 *)p + 0x68));
}
/* localdecomp:end func_L01_003C5610 */

/* localdecomp:start func_L01_003C5630 */
extern void func_L01_003C6EF0(void *, s32);
void func_L01_003C5630(void *p) {
    func_L01_003C6EF0(p, *(s32 *)((u8 *)p + 0x68));
}
/* localdecomp:end func_L01_003C5630 */

/* localdecomp:start func_L01_003C5650 */
extern void func_L01_00456230(u8 *o, s32 a);

void func_L01_003C5650(u8 *a) {
    u8 *p = *(u8 **)(a + 104);
    func_L01_00456230(a, 1);
    p[259] = 1;
}
/* localdecomp:end func_L01_003C5650 */

/* localdecomp:start func_L01_003C5688 */
void func_L01_003C5688(u8 *obj) {
    (*(u8 **)(obj + 104))[259] = 1;
}
/* localdecomp:end func_L01_003C5688 */

/* localdecomp:start func_L01_003C5698 */
extern s32 D_001D545C;
extern u8 D_001BBC40[][16];
extern u8 D_L01_001DFE80[1];

s32 func_L01_003C5698(u8 *a0, u8 *a1) {
    s32 i;
    if ((a0[0xB0] != 0xFF && (D_001BBC40[D_001D545C][a0[0xB0]] & 0x80)) ||
        ((i = *(s32 *)(a1 + 0x6B4)) != -1 && (D_L01_001DFE80[i] & 0x80))) {
        return *(s32 *)(a1 + 0x6B8);
    }
    return *(s32 *)(a1 + 0x6B0);
}
/* localdecomp:end func_L01_003C5698 */

/* localdecomp:start func_L01_003C5710 */

void func_L01_003C5710(u8 *a0, u128_3C3E90 *a1, u128_3C3E90 *a2) {
    *(u128_3C3E90 *)(a0 + 0x00) = *a1;
    *(u128_3C3E90 *)(a0 + 0x10) = *a2;
}
/* localdecomp:end func_L01_003C5710 */

/* localdecomp:start func_L01_003C5728 */
extern void func_L01_003C5110(void *a0, u8 *a1);

extern void func_L01_003C5710(u8 *, u128_t *, u128_t *);
extern void func_0038D308(u8 *, u8 *);
extern void func_L01_0044F450(u8 *, u8 *);

void func_L01_003C5728(u8 *m, u8 *b, u128_t *pos, u128_t *dir) {
    func_L01_003C5710(b, pos, dir);
    *(u128_t *)(m + 16) = *pos;
    *(u128_t *)(m + 240) = *dir;
    func_0038D308(m + 192, m + 240);
    func_L01_0044F450(m, b + 368);
    ((void (*)(u8 *, u8 *))func_L01_003C5110)(m, b);
}
/* localdecomp:end func_L01_003C5728 */

/* localdecomp:start func_L01_003C57B0 */
extern void func_L01_003C5728(u8 *m, u8 *b, u128_t *pos, u128_t *dir);
extern char *D_L01_001E0100;
void func_L01_003C57B0(void *a, void *b, int i) {
    char *p = D_L01_001E0100 + i * 128;
    ((void (*)(void *, void *, char *, char *))func_L01_003C5728)(a, b, p + 48, p + 112);
}
/* localdecomp:end func_L01_003C57B0 */

/* localdecomp:start func_L01_003C57E0 */
extern u8 D_001A4BE0[];
extern s32 func_00382380(u8 *, s32, s32);
extern void func_L01_00456230(u8 *o, s32 a);

void func_L01_003C57E0(u8 *a0, u8 *a1) {
    u8 *p = D_001A4BE0;
    s32 v = *(s32 *)(p + 9668);
    if (v == 116 || v == 49 || v == 101) {
        return;
    }
    if (*(s32 *)(p + 860) == *(s32 *)(a1 + 72) ||
        (*(s32 *)(a1 + 204) != -1 && func_00382380(p + 128, *(s32 *)(a1 + 204), 0) != 0)) {
        func_L01_00456230(a0, 1);
        a1[259] = 1;
    } else {
        func_L01_00456230(a0, 0);
    }
}
/* localdecomp:end func_L01_003C57E0 */

/* localdecomp:start func_L01_003C5888 */
extern u8 D_001A4BE0[];
extern s32 func_L01_00511A98(void);
extern void func_L01_00511AE8(void);
extern s32 func_L01_003C6860(M_3C4008 *);
extern s32 func_L01_00456250(M_3C4008 *);
void func_L01_003C5888(M_3C4008 *m, B_3C4008 *b) {
    if (b->b100 == 0) {
        return;
    }
    if (func_L01_00511A98() != 0) {
        if (b->b100 == 2) {
            return;
        }
        if ((*(G_3C4008 *)&D_001A4BE0).w25C4 == 105) {
            return;
        }
        if (m->b20 == 5 && func_L01_003C6860(m) != 0) {
            if (b->p54 == 0) {
                return;
            }
            if (b->p54->w98 == 0) {
                return;
            }
        }
        if (func_L01_00456250(m) != 0) {
            return;
        }
        if (!(0.9f < (*(G_3C4008 *)&D_001A4BE0).f283C)) {
            return;
        }
        func_L01_00511AE8();
        b->b100 = 0;
    } else {
        b->b100 = 0;
    }
}
/* localdecomp:end func_L01_003C5888 */

/* localdecomp:start func_L01_003C5970 */
extern struct U_3C41F8 D_L01_001E001C __attribute__((section(".sdata")));
extern s32 D_L01_001F3F40[];
extern u16 *D_L01_0021DE20[];
extern s32 D_L01_001E0058;
extern void func_L01_0042B068(s32, s32);
extern void func_L01_003C5290(u8 *, u8 *);


void func_L01_003C5970(u8 *m, u8 *v) {
    s32 e = ((S_3C40F0 *)v)->arr[((S_3C40F0 *)v)->idx];
    u16 *list;
    u8 *o;

    if (e != -1 && e != D_L01_001F3F40[0]) {
        func_L01_0042B068(e, 0);
    }
    func_L01_003C5290(m, v);
    list = D_L01_0021DE20[*(s32 *)(v + 36)];
    while ((*(s32 *)(v + 36) & 0xFF) != 255 && *(s32 *)(v + 36) <= D_L01_001E0058 && list != 0 &&
           ((s16)list[-1] >= 0 || list == D_L01_0021DE20[*(s32 *)(v + 36)])) {
        o = (*(u8 * *)&D_L01_001E001C) + ((*list & 0x7FFF) << 8);
        if (o == 0) {
            break;
        }
        list++;
        *(u16 *)(o + 52) &= 0xFF7F;
    }
}
/* localdecomp:end func_L01_003C5970 */

/* localdecomp:start func_L01_003C5A78 */
extern void func_L01_003C5290(u8 *, u8 *);

extern u16 *D_L01_0021DE20[];
extern s32 D_L01_001E0058;
extern struct U_3C41F8 D_L01_001E001C __attribute__((section(".sdata")));
extern s32 D_L01_001F3F40[];
extern void func_L01_0042B068(s32 a, s32 b);

void func_L01_003C5A78(void *a, O_3C41F8 *o, s32 i) {
    u16 *p;
    M_3C41F8 *e;
    s32 s = o->a1872[i];

    if (s == -1) {
        s32 t = o->a1728[i];
        if (t != s && t != D_L01_001F3F40[0]) {
            func_L01_0042B068(t, 0);
        }
    } else if (s != D_L01_001F3F40[0]) {
        func_L01_0042B068(s, 0);
    }
    ((void (*)(void *a, O_3C41F8 *o))func_L01_003C5290)(a, o);
    for (p = D_L01_0021DE20[o->id];
         (o->id & 0xFF) != 0xFF && o->id <= D_L01_001E0058 && p != 0 &&
         ((s16)p[-1] >= 0 || p == D_L01_0021DE20[o->id]);
         p++) {
        e = *(M_3C41F8 **)&D_L01_001E001C + (p[0] & 0x7FFF);
        if (e == 0) {
            break;
        }
        e->h52 &= 0xFF7F;
    }
}
/* localdecomp:end func_L01_003C5A78 */

/* localdecomp:start func_L01_003C5BA8 */
extern s32 func_00382380(u8 *, s32, s32);
extern s32 D_001D545C;
extern u8 D_001BBC40[][16];
extern u8 D_001A4C60[];


s32 func_L01_003C5BA8(s32 unused, u8 *obj) {
    s32 i;
    s32 *p = (s32 *)(obj + 1856);
    for (i = 0; i < 4; i++, p++) {
        s32 a = p[-4];
        s32 b;
        if (a == -1) {
            continue;
        }
        b = p[0];
        if (b != -1 && !(D_001BBC40[D_001D545C][b] & 0x80)) {
            continue;
        }
        if (((s32 (*)(void *a, s32 b, s32 c))func_00382380)(D_001A4C60, a, 0) != 0) {
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_L01_003C5BA8 */

/* localdecomp:start func_L01_003C5C60 */
extern void func_L01_003F5E88(u8 *);
void func_L01_003C5C60(s32 a0, u8 *a1) {
    u8 *s = *(u8 **)(a1 + 84);
    if (s != 0 && *(s32 *)(s + 152) == 0) {
        func_L01_003F5E88(s);
        *(s32 *)(s + 152) = *(s32 *)(*(u8 **)(s + 36) + 16);
    }
}
/* localdecomp:end func_L01_003C5C60 */

/* localdecomp:start func_L01_003C5CA8 */
extern void func_L01_003F5EE0(u8 *);

void func_L01_003C5CA8(void *self, u8 *obj) {
    u8 *s = *(u8 **)(obj + 84);
    if (s != 0 && *(s32 *)(s + 152) != 0) {
        func_L01_003F5EE0(s);
        *(s32 *)(s + 152) = 0;
    }
}
/* localdecomp:end func_L01_003C5CA8 */

INCLUDE_ASM("asm/levels", func_L01_003C5CE8);

INCLUDE_ASM("asm/levels", func_L01_003C5DF0);

/* localdecomp:start func_L01_003C5EC0 */
void func_L01_003C5DF0(s32, s32, s32);
void func_L01_003EB5E0(s32, s32);
extern s32 D_L01_001DF95C;

void func_L01_003C5EC0(s32 arg0, s32 arg1) {
    func_L01_003EB5E0(0, 3);
    func_L01_003C5DF0(arg0, arg1, 0);
    D_L01_001DF95C = 0;
}
/* localdecomp:end func_L01_003C5EC0 */

/* localdecomp:start func_L01_003C5F10 */
extern u8 *D_L01_001E001C_003C5F10;
extern u16 *D_L01_0021DE20[];
extern s32 D_L01_001E0058;
void func_L01_003C5F10(void *self, O3C48A8 *obj) {
    extern void func_L01_003C64E0(void *, s32, u128_t *, f32 *);
    extern void func_0038D308(u8 *, u8 *);
    extern void func_L01_0044FD88(u8 *, u8 *, s32, s32);
    u128_t pos;
    f32 angle;
    u16 *p;
    u8 *m, *v, *o, *child;
    s32 i = 0;
    s32 g;
    p = D_L01_0021DE20[obj->group];
    while (g = obj->group, (g & 255) != 255 && g <= D_L01_001E0058 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L01_0021DE20[g])) {
        m = D_L01_001E001C_003C5F10 + ((*p & 0x7FFF) << 8);
        if (m == 0) break;
        if (m[0x20] == 254) goto next;
        if (m[0x20] == 253) goto next;
        v = *(u8 **)(m + 0x68);
        *(u16 *)(m + 0x34) &= 0xFFFD;
        func_L01_003C64E0(self, i, &pos, &angle);
        *(u128_t *)(m + 0x10) = pos;
        *(f32 *)(m + 0xF8) = angle;
        if (*(s32 *)(v + 0x50) == -1) goto next;
        o = D_L01_001E001C_003C5F10 + (*(s32 *)(v + 0x50) << 8);
        *(u128_t *)(o + 0x10) = pos;
        *(f32 *)(o + 0xF8) = angle;
        if (!(*(u16 *)(o + 0x34) & 2) && o[0x31] && !(*(u16 *)(o + 0x34) & 0x80)) goto next;
        child = *(u8 **)(*(u8 **)(o + 0x68) + 0x550);
        *(u16 *)(o + 0x34) &= 0xFFBC;
        *(u16 *)(o + 0x34) |= *(u16 *)(*(u8 **)(o + 0x24) + 0x44) & 0x1000;
        { s32 data = *(s32 *)(*(u8 **)(o + 0x24) + 0x10);
        *(u16 *)(o + 0x34) &= 0xFF7F;
        *(s32 *)(o + 0x98) = data; }
        func_0038D308(m + 0xC0, m + 0xF0);
        func_0038D308(o + 0xC0, o + 0xF0);
        if (child != 0) {
            *(u16 *)(child + 0x34) &= 0xFFBE;
            *(u16 *)(child + 0x34) |= *(u16 *)(*(u8 **)(child + 0x24) + 0x44) & 0x1000;
            { s32 data = *(s32 *)(*(u8 **)(child + 0x24) + 0x10);
            *(u16 *)(child + 0x34) &= 0xFF7F;
            *(s32 *)(child + 0x98) = data; }
            func_L01_0044FD88(o, child, 0, 0);
        }
next:
        i++;
        p++;
    }
    obj->active = 1;
}
/* localdecomp:end func_L01_003C5F10 */

/* localdecomp:start func_L01_003C6128 */
extern struct U_3C41F8 D_L01_001E001C __attribute__((section(".sdata")));
extern u16 *D_L01_0021DE20[];
extern s32 D_L01_001E0058;
extern void func_L01_004AA7E8(M3C48A8 *m, s32 a1);
void func_L01_003C6128(void *a0, O3C48A8 *obj) {
    s16 *p;
    M3C48A8 *m;
    M3C48A8 *o;
    M3C48A8 *c;
    s32 g;

    p = ((s16 * *)&D_L01_0021DE20)[obj->group];
    while (g = obj->group, (g & 0xFF) != 255 && g <= D_L01_001E0058 && p != 0 &&
             (p[-1] >= 0 || p == ((s16 * *)&D_L01_0021DE20)[g])) {
        m = &(*(M3C48A8 * *)&D_L01_001E001C)[*p & 0x7FFF];
        if (m == 0) {
            break;
        }
        if (m->state == 254) {
            goto next;
        }
        if (m->state == 253) {
            goto next;
        }
        if (m->flags & 2) {
            goto next;
        }
        if (m->vars->link == -1) {
            goto next;
        }
        o = &(*(M3C48A8 * *)&D_L01_001E001C)[m->vars->link];
        c = o->vars->child;
        m->flags |= 2;
        o->f98 = 0;
        o->flags = (o->flags | 0x43) & ~0x1000;
        func_L01_004AA7E8(o, 1);
        if (c != 0) {
            c->f98 = 0;
            c->flags = (c->flags | 0x41) & ~0x1000;
            func_L01_004AA7E8(c, 1);
        }
next:
        p++;
    }
    obj->active = 0;
}
/* localdecomp:end func_L01_003C6128 */

/* localdecomp:start func_L01_003C6288 */
typedef struct {
    u8 p0[0x170];
    s32 x170;
    s32 x174;
    u8 p178[8];
    s32 x180;
} V_003C6288;

extern f32 func_0038DAB8(f32, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_004F50C8(void *, void *, s32, s32);
__asm__(".extern D_L01_001DEDD0, 8");
extern u8 D_L01_001DEDD0[8];
extern u8 D_001A4BE0[];

void func_L01_003C6288(u8 *obj) {
    vu0_v4 a;
    vu0_v4 b;

    func_L01_003C5970(obj, *(u8 **)(obj + 0x68));
    func_0038D000(&a, D_L01_001DEDD0, obj + 0xC0);
    vec_add_ba(&a, &a, obj + 0x10);
    qzero(&b);
    b.z = func_0038DAB8(*(f32 *)(obj + 0xF8), 3.1415927f);
    (*(V_003C6288 *)&D_001A4BE0).x170 = 0;
    (*(V_003C6288 *)&D_001A4BE0).x174 = 0;
    (*(V_003C6288 *)&D_001A4BE0).x180 = 0;
    func_L01_004F50C8(&a, &b, 0x74, 1);
}
/* localdecomp:end func_L01_003C6288 */

/* localdecomp:start func_L01_003C6318 */
extern void func_0038CF68(void *, void *, f32);

void func_L01_003C6318(u8 *obj, f32 *out) {
    vec_neg(out, obj + 0xC0);
    out[2] = 0.0f;
    func_0038CF68(out, out, 1.0f);
}
/* localdecomp:end func_L01_003C6318 */

/* localdecomp:start func_L01_003C6350 */
extern f32 func_0038DAB8(f32, f32);

void func_L01_003C6350(u8 *obj, u8 *out) {
    qzero(out);
    *(f32 *)(out + 8) = func_0038DAB8(*(f32 *)(obj + 0xF8), 3.1415927f);
}
/* localdecomp:end func_L01_003C6350 */

/* localdecomp:start func_L01_003C6390 */
#include "vu0.h"
extern u8 D_L01_001DEDE0[8];
__asm__(".extern D_L01_001DEDE0, 8");
void func_L01_003C6390(u8 *obj, void *out) {
    extern void func_0038D000(void *, void *, void *);
    func_0038D000(out, D_L01_001DEDE0, obj+0xC0);
    vec_add_ba(out,out,obj+0x10);
}
/* localdecomp:end func_L01_003C6390 */

/* localdecomp:start func_L01_003C63E0 */
#include "vu0.h"
extern s32 D_L01_001F3F40[];
extern char *D_L01_001E0100;
extern u8 D_L01_001DEE10[8];
extern u8 D_L01_001DEDF0[8];
extern f32 D_L01_001DEE20;
extern u8 D_001A4CD0[];
__asm__(".extern D_L01_001E0100, 4");
__asm__(".extern D_L01_001DEE10, 8");
__asm__(".extern D_L01_001DEDF0, 8");
__asm__(".extern D_L01_001DEE20, 4");
void func_L01_003C63E0(u8 *obj,s32 flag) {
    extern void func_L01_003C5970(u8 *,u8 *);
    extern void func_0038D000(void *,void *,void *);
    extern f32 func_0038DAB8(f32,f32);
    extern void func_0038CBA0(void *,s32);
    extern void func_L01_004F50C8(void *,void *,s32,s32);
    vu0_v4 pos,rot;
    u8 *v=*(u8 **)(obj+0x68);
    func_L01_003C5970(obj,v);
    if(D_L01_001F3F40[0]==*(s32 *)(v+0xE0) && *(s32 *)(v+0xE4)!=-1) {
        char *p=D_L01_001E0100+(*(s32 *)(v+0xE4)<<7);
        *(vu0_q *)&pos=*(vu0_q *)(p+0x30);
        *(vu0_q *)&rot=*(vu0_q *)(p+0x70);
    } else {
        if(flag)func_0038D000(&pos,D_L01_001DEE10,obj+0xC0);
        else func_0038D000(&pos,D_L01_001DEDF0,obj+0xC0);
        vec_add_ab(&pos,&pos,obj+0x10);
        qzero(&rot);
        if(flag)rot.z=func_0038DAB8(*(f32 *)(obj+0xF8),D_L01_001DEE20);
        else rot.z=*(f32 *)(obj+0xF8);
    }
    func_0038CBA0(D_001A4CD0,0xA0);
    func_L01_004F50C8(&pos,&rot,0x74,1);
}
/* localdecomp:end func_L01_003C63E0 */
