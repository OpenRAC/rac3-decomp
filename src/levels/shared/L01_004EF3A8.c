#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_004EF3A8);

/* localdecomp:start func_L01_004EF6F0 */
#include "vu0.h"
extern s32 D_L01_001D673C;
extern vu0_q D_001A4C60[];
extern u8 D_001A4EC0[];
extern s32 D_001A71A0[];
void func_L01_004EF6F0(vu0_v4 *out, vu0_v4 *low, s32 mode, f32 height, f32 depth) {
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_0044A850(void *, void *);
    vu0_v4 offset, copy;
    if (mode) {
        if (D_L01_001D673C) func_0038CF68(&offset, D_001A4EC0, -depth);
        else func_0038CF68(&offset, (u8 *)D_001A71A0[0] + 0xE0, depth);
        vec_add_ba(low, D_001A4C60, &offset);
        if (D_L01_001D673C)
            func_0038CF68(&offset, (u8 *)D_001A4C60 + 0x260, -height);
        else
            func_0038CF68(&offset, *(u8 **)((u8 *)D_001A4C60 + 0x2540) + 0xE0, height);
        vec_add_ba(out, D_001A4C60, &offset);
        *(vu0_q *)&copy = *(vu0_q *)out;
        func_L01_0044A850(&copy, low);
    } else {
        *(vu0_q *)low = D_001A4C60[0];
        *(vu0_q *)&offset = *(vu0_q *)low;
        low->z += depth;
        if (low->z < 0.0f) low->z = 0.0f;
        *(vu0_q *)out = *(vu0_q *)&offset;
        out->z += height;
    }
}
/* localdecomp:end func_L01_004EF6F0 */

INCLUDE_ASM("asm/levels", func_L01_004EF840);

/* localdecomp:start func_L01_004F02D8 */
#include "vu0.h"
extern u8 D_001A4BE0_004F0558[];
typedef struct { u8 pad[0x364]; s32 value; } Clear_004F02D8;
extern f32 D_001A4C68[];
void func_L01_004F02D8(void) {
    extern f32 func_L01_005114B0(void *);
    extern f32 func_0038CF38(void *, void *);
    extern void func_L01_00448340(void *, void *, void *, f32, f32, f32);
    extern void func_L01_004482A0(void *, f32, void *, f32, f32, f32);
    u8 *h = D_001A4BE0_004F0558;
    if (h[0x25F4]) {
        if (*(s16 *)(D_001A4BE0_004F0558 + 0x36E) != 0) goto clear;
        if (*(f32 *)(h + 0x33C) < 0.0f) {
            if (fabs_asm(*(f32 *)(h + 0x33C)) < fabs_asm(func_L01_005114B0(h + 0xF0)) + 0.01f) {
                if (!h[0x2A7] || func_0038CF38(h + 0x260, h + 0x80) > *(f32 *)(h + 0x284) * 0.5f) {
                    *(vu0_q *)(h + 0x80) = *(vu0_q *)(h + 0x2F0);
                } else {
                    func_L01_00448340(h + 0x80, h + 0x2F0, &((Clear_004F02D8 *)h)->value, 0.07200000435113907f, 0.3024f, 0.10000001f);
                }
            } else {
                func_L01_00448340(h + 0x80, h + 0x2F0, &((Clear_004F02D8 *)h)->value, 0.07200000435113907f, 0.3024f, 0.10000001f);
            }
        } else {
            goto clear;
        }
    } else {
        if (*(s16 *)(D_001A4BE0_004F0558 + 0x36E) != 0) goto clear;
        if (*(f32 *)(h + 0x88) < *(f32 *)(h + 0x338)) {
            if (fabs_asm(*(f32 *)(h + 0x88) - *(f32 *)(h + 0x338)) < fabs_asm(*(f32 *)(h + 0xF8)) + 0.01f) {
                if (!h[0x2A7] || func_0038CF38(h + 0x260, h + 0x80) > *(f32 *)(h + 0x284) * 0.5f) {
                    *(f32 *)(h + 0x88) = *(f32 *)(h + 0x338);
                } else {
                    func_L01_004482A0(h + 0x88, *(f32 *)(D_001A4BE0_004F0558 + 0x338), &((Clear_004F02D8 *)h)->value, 0.07200000435113907f, 0.24480001628398895f, 0.10000001f);
                }
            } else {
                if (*(f32 *)(h + 0x128) < 0.0f) {
                    *(f32 *)(h + 0x88) -= *(f32 *)(h + 0x128);
                    if (*(f32 *)(h + 0x88) > *(f32 *)(h + 0x338)) *(f32 *)(h + 0x88) = *(f32 *)(h + 0x338);
                }
                func_L01_004482A0(D_001A4C68, *(f32 *)((u8 *)D_001A4C68 + 0x2B0), (u8 *)D_001A4C68 + 0x2DC, 0.07200000435113907f, 0.24480001628398895f, 0.10000001f);
            }
        } else {
            goto clear;
        }
    }
    return;
clear:
    ((Clear_004F02D8 *)D_001A4BE0_004F0558)->value = 0;
}
/* localdecomp:end func_L01_004F02D8 */

/* localdecomp:start func_L01_004F0558 */
#include "vu0.h"
extern u8 D_001A4BE0_004F0558[];
extern void func_00382760(void *, f32, f32, f32);
extern void func_0038CE20_004F0558(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);

void func_L01_004F0558(f32 a, f32 b) {
    u8 *v = D_001A4BE0_004F0558 + 0x9E0;
    u8 *h = D_001A4BE0_004F0558;
    f32 len;

    func_00382760(v, *(f32 *)(h + 0x9F0), *(f32 *)(h + 0x9F8), *(f32 *)(h + 0x9F4));
    func_0038CE20_004F0558(v, v, a);
    len = func_0038CEA8(v);
    if (len <= b) {
        qzero(v);
    } else {
        func_0038CF68(v, v, len - b);
    }
}
/* localdecomp:end func_L01_004F0558 */

/* localdecomp:start func_L01_004F05F0 */
typedef int Q_004F05F0 __attribute__((mode(TI)));
extern void func_L01_00511178(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);

f32 func_L01_004F05F0(Q_004F05F0 *in) {
    Q_004F05F0 v[2];

    v[0] = *in;
    qzero(&v[1]);
    func_L01_00511178(&v[1], &v[1], 1.0f);
    return func_0038CE68(&v[0], &v[1]);
}
/* localdecomp:end func_L01_004F05F0 */

INCLUDE_ASM("asm/levels", func_L01_004F0640);

/* localdecomp:start func_L01_004F0AB0 */
typedef int s128_004ECCD8 __attribute__((mode(TI)));

typedef struct {
    u8 pad[128];
    s128_004ECCD8 out;
    u8 pad2[9972 - 144];
    s32 idx;
    s32 count;
} St_004ECCD8;

extern St_004ECCD8 D_001A4BE0;
extern s128_004ECCD8 D_001A6C20[];
extern s32 func_L01_004F0640(s32);

void func_L01_004F0AB0(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        if (func_L01_004F0640(i) == 1) {
            return;
        }
        if (D_001A4BE0.count > 1) {
            D_001A4BE0.count--;
            D_001A4BE0.idx = (D_001A4BE0.idx + 31) % 32;
        }
        D_001A4BE0.out = D_001A6C20[D_001A4BE0.idx];
    }
}
/* localdecomp:end func_L01_004F0AB0 */

INCLUDE_ASM("asm/levels", func_L01_004F0B78);

/* localdecomp:start func_L01_004F1190 */
typedef struct {
    f32 v[4];
} Vec4ED3B8;

typedef struct {
    u8 pad0[0x1B4];
    f32 f1B4;
} Cam4ED3B8;

extern Vec4ED3B8 D_001A4CF0[];
extern void func_0038CE20(Vec4ED3B8 *, Vec4ED3B8 *, f32);

void func_L01_004F1190(f32 s) {
    Vec4ED3B8 *p = D_001A4CF0;
    func_0038CE20(p, p, s);
    func_0038CE20(p + 1, p + 1, s);
    func_0038CE20(p + 2, p + 2, s);
    func_0038CE20(p - 2, p - 2, s);
    func_0038CE20(p + 5, p + 5, s);
    {
        Cam4ED3B8 *c = (Cam4ED3B8 *)(p - 17);
        c->f1B4 *= s;
    }
}
/* localdecomp:end func_L01_004F1190 */

/* localdecomp:start func_L01_004F1220 */
#include "vu0.h"
typedef struct {
    u8 p0[0xF0]; vu0_v4 velocity;
    u8 p100[0x140-0x100]; vu0_q copied;
    u8 p150[0x174-0x150]; f32 speed_a; f32 speed_b;
    u8 p17c[0x190-0x17c]; vu0_q target;
    f32 angle; u8 p1a4[0x1b0-0x1a4]; f32 target_speed; f32 speed;
    u8 p1b8[0x2a7-0x1b8]; u8 b2a7;
    u8 p2a8[0x36a-0x2a8]; s16 h36a;
    u8 p36c[0x4f4-0x36c]; s16 h4f4;
    u8 p4f6[0x9e0-0x4f6]; vu0_q q9e0;
    u8 p9f0[0x1434-0x9f0]; s16 lock;
    u8 p1436[0x16b0-0x1436]; s32 camera;
    u8 p16b4[0x25c4-0x16b4]; s32 state;
    u8 p25c8[4]; s32 state_type;
    u8 p25d0[0x25f4-0x25d0]; u8 mode;
} Hero_004F1220;
extern Hero_004F1220 D_001A4BE0_004F1220;
extern vu0_v4 D_001A4CD0_004F1220;
extern vu0_q D_001A4D70_004F1220;
void func_L01_004F1220(f32 delta) {
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038CED8(void *);
    extern void func_0038CFB8(void *, void *, f32);
    extern f32 func_L01_004F05F0(Q_004F05F0 *);
    extern void func_L01_00511508(void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_L01_00511408(void *);
    extern void func_L01_00511588(void *, void *, f32);
    extern s32 func_L01_004606E8(s32, s32, s32, s32);
    vu0_v4 v;
    vu0_v4 saved;
    vu0_v4 projected;
    vu0_v4 *velocity;
    vu0_q *target;
    Hero_004F1220 *tail;
    f32 angle, speed, dot, a, b;
    s32 locked;
    switch (D_001A4BE0_004F1220.mode) {
    case 0:
        angle = D_001A4BE0_004F1220.angle;
        speed = D_001A4BE0_004F1220.target_speed;
        if (D_001A4BE0_004F1220.state_type == 4 && D_001A4BE0_004F1220.h4f4 != 0 && D_001A4BE0_004F1220.b2a7 != 0) speed = 0.100000009f;
        if (D_001A4BE0_004F1220.h36a != 0 && D_001A4BE0_004F1220.state == 14 && speed > 0.0200000014f) speed = 0.0200000014f;
        v.x = func_0038D098(angle) * speed;
        v.y = func_0038D0B0(angle) * speed;
        v.z = D_001A4BE0_004F1220.velocity.z;
        dot = -(D_001A4BE0_004F1220.velocity.x * v.x + D_001A4BE0_004F1220.velocity.y * v.y);
        a = func_0038CED8(&v);
        b = func_0038CED8(&D_001A4BE0_004F1220.velocity);
        if (a == 0.0f || b == 0.0f) dot = 0.0f;
        else { dot /= a; dot /= b; }
        if (D_001A4BE0_004F1220.state == 176) dot += 0.5f;
        else { dot += 1.0f; dot *= 1.5f; }
        if (dot > 3.0f) dot = 3.0f;
        if (dot < 1.0f) dot = 1.0f;
        velocity = &D_001A4CD0_004F1220;
        vec_sub_ab(&v, &v, &D_001A4CD0_004F1220);
        delta *= dot;
        if (delta < func_0038CED8(&v)) func_0038CFB8(&v, &v, delta);
        vec_add_ab(velocity, velocity, &v);
        *(vu0_q *)((u8 *)velocity + 0x50) = *(vu0_q *)velocity;
        *(vu0_q *)&saved = *(vu0_q *)((u8 *)velocity + 0x8F0);
        tail = (Hero_004F1220 *)((u8 *)velocity - 0xF0);
        b = func_L01_004F05F0((Q_004F05F0 *)&saved);
        locked = tail->lock;
        tail->speed = tail->speed_b - b;
        break;
    case 1:
    case 2:
        target = &D_001A4D70_004F1220;
        *(vu0_q *)&saved = *target;
        speed = *(f32 *)((u8 *)target + 0x20);
        func_L01_00511508(&v, &saved, 0.0f);
        target = (vu0_q *)((u8 *)target - 0xA0);
        func_0038CF68(&v, &v, speed);
        func_L01_00511508(&projected, target, 0.0f);
        dot = -func_0038CE68(&projected, &v);
        a = func_L01_00511408(&v);
        b = func_L01_00511408(target);
        if (a == 0.0f || b == 0.0f) dot = 0.0f;
        else { dot /= a; dot /= b; }
        dot += 1.0f;
        dot *= 1.5f;
        if (dot > 3.0f) dot = 3.0f;
        if (dot < 1.0f) dot = 1.0f;
        vec_sub_ab(&v, &v, &D_001A4CD0_004F1220);
        func_L01_00511508(&v, &v, 0.0f);
        delta *= dot;
        if (delta < func_L01_00511408(&v)) func_L01_00511588(&v, &v, delta);
        vec_add_ab(&D_001A4CD0_004F1220, &D_001A4CD0_004F1220, &v);
        tail = (Hero_004F1220 *)((u8 *)&D_001A4CD0_004F1220 - 0xF0);
        locked = tail->lock;
        tail->speed = tail->speed_b;
        break;
    default:
        return;
    }
    if (locked != 0 || (tail->camera == 1 && func_L01_004606E8(40, 2, 0, 0) != 0)) tail->speed = tail->speed_a;
}
/* localdecomp:end func_L01_004F1220 */

INCLUDE_ASM("asm/levels", func_L01_004F1638);

INCLUDE_ASM("asm/levels", func_L01_004F1C88);

/* localdecomp:start func_L01_004F2880 */
#include "vu0.h"
typedef struct {
    vu0_q start;
    u8 p10[0x80-0x10]; vu0_v4 pos;
    u8 p90[8]; f32 yaw;
    u8 p9c[0x190-0x9c]; vu0_q saved;
    f32 saved_yaw;
    u8 p1a4[0xba0-0x1a4]; vu0_v4 delta;
    u8 pbb0[0xbc4-0xbb0]; void *target; s32 active; f32 angle;
    u8 pbd0[0x1434-0xbd0]; s16 lock;
    u8 p1436[0x16b0-0x1436]; s32 mode;
    u8 p16b4[0x2838-0x16b4]; f32 mag;
} Hero_004F2880;
void func_L01_004F2880(f32 a, f32 b, f32 c) {
    extern s32 func_L01_004606E8(s32,s32,s32,s32);
    extern void func_L01_004EE850(s32,f32);
    extern void *func_L01_004E9980(f32,f32,f32,f32,void *,s32,s32);
    extern f32 func_0038D160(f32,f32);
    extern void func_L01_00511508(void *,void *,f32);
    Hero_004F2880 *h=(Hero_004F2880 *)&D_001A4BE0;
    vu0_q v;
    f32 angle;
    u8 *target;
    if (h->active != 0) return;
    v=h->start;
    angle=h->yaw;
    if (h->mag > 0.5f && h->lock == 0 &&
        (h->mode != 1 || func_L01_004606E8(40,2,0,0)==0)) {
        func_L01_004EE850(0,1.0f);
        v=h->saved;
        h->active=1;
        h->target=0;
        angle=h->saved_yaw;
    }
    target=func_L01_004E9980(a,angle,b,c,&v,-1,0);
    if (target != 0 && (((Hero_004F2880 *)&D_001A4BE0)->target == 0 || ((Hero_004F2880 *)&D_001A4BE0)->active != 0)) {
        ((Hero_004F2880 *)&D_001A4BE0)->angle=func_0038D160(*(f32 *)(target+0x10)-((Hero_004F2880 *)&D_001A4BE0)->pos.x,*(f32 *)(target+0x14)-((Hero_004F2880 *)&D_001A4BE0)->pos.y);
        vec_sub_ab(&((Hero_004F2880 *)&D_001A4BE0)->delta,target+0x10,&((Hero_004F2880 *)&D_001A4BE0)->pos);
        ((Hero_004F2880 *)&D_001A4BE0)->target=target;
    } else {
        ((Hero_004F2880 *)&D_001A4BE0)->angle=angle;
        *(vu0_q *)&((Hero_004F2880 *)&D_001A4BE0)->delta=v;
    }
    func_L01_00511508(&((Hero_004F2880 *)&D_001A4BE0)->delta,&((Hero_004F2880 *)&D_001A4BE0)->delta,0.0f);
}
/* localdecomp:end func_L01_004F2880 */

/* localdecomp:start func_L01_004F2A08 */
typedef int s128_4F2A08 __attribute__((mode(TI)));
typedef union {
    s128_4F2A08 q;
    struct {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    } v;
} V_4F2A08;
typedef struct {
    u8 pad0[0x60];
    f32 target_x;
    f32 target_y;
    f32 target_z;
    u8 pad6C[0xA4 - 0x6C];
    f32 gain;
    f32 damping;
    f32 one;
} Spring_4F2A08;
/* the hero's joint springs (43, from D_L01_002F4540) */
typedef struct {
    Spring_4F2A08 root;
    Spring_4F2A08 waist;
    Spring_4F2A08 chest;
    Spring_4F2A08 neck;
    Spring_4F2A08 legs[4];
    Spring_4F2A08 other_clavicle;
    Spring_4F2A08 gun_clavicle;
    Spring_4F2A08 elbow;
    Spring_4F2A08 spring11;
    Spring_4F2A08 eyes;
    Spring_4F2A08 tail[4];
} Springs_4F2A08;
typedef struct {
    u8 pad0[0x40];
    u8 matrix[0x40]; /* 0x40: his rotation */
    V_4F2A08 pos; /* 0x80 */
    u8 pad90[0x35C - 0x90];
    s32 ground_moby;
    u8 pad360[0x368 - 0x360];
    s16 on_slope;
    u8 pad36A[0x25C4 - 0x36A];
    s32 state;
    u8 pad25C8[0x25EB - 0x25C8];
    u8 firing_held;
    u8 hold_type; /* 0 none, 1 one hand, 2 both */
    u8 pad25ED[0x25F4 - 0x25ED];
    u8 b25F4; /* 1: the clavicles drop near (330, 245, 138) */
    u8 pad25F5[0x2874 - 0x25F5];
    s16 gun_arm_raised;
} H_4F2A08;
extern s32 D_001D545C; /* the level */
extern Springs_4F2A08 D_L01_002F4540;
extern void func_0038D028(f32 *out, void *a, void *b);
extern f32 func_0038CF00(void *a, void *b);
extern void func_L01_004E63A8(f32 gain, f32 damping);

/* hero_slope_lean: on a slope, not firing a held gun, the waist leans with the ground's tilt
   (up to 21 deg; 7 deg with a gun), the neck half of it back, the clavicles against it with a
   gun not raised; the tail too. */
void func_L01_004F2A08(void) {
    V_4F2A08 v; /* the ground's down in his frame, then a spot */
    f32 limit;
    f32 lean;
    f32 tilt;
    f32 tail;
    s32 near;

    if (D_001D545C == 21) {
        return;
    }
    if ((*(H_4F2A08 *)&D_001A4BE0).on_slope != 0 && (*(H_4F2A08 *)&D_001A4BE0).firing_held == 0) {
        v.q = 0;
        v.v.z = -1.0f;
        func_0038D028(&v.v.x, &v, (*(H_4F2A08 *)&D_001A4BE0).matrix);
        func_L01_004E63A8(0.018720001f, 0.432000041f);
        limit = 0.366519153f; /* 21 deg */
        if ((*(H_4F2A08 *)&D_001A4BE0).state == 0x72) {
            limit = 0.0872664601f; /* 5 deg */
        } else if ((*(H_4F2A08 *)&D_001A4BE0).state == 0x73 || (*(H_4F2A08 *)&D_001A4BE0).state == 4) {
            limit = 0.191986218f; /* 11 deg */
        }
        if ((*(H_4F2A08 *)&D_001A4BE0).hold_type != 0 && limit > 0.122173049f) {
            limit = 0.122173049f; /* 7 deg with a gun */
        }
        if ((*(H_4F2A08 *)&D_001A4BE0).ground_moby != 0 && limit > 0.157079637f) {
            limit = 0.157079637f; /* 9 deg on a moby */
        }
        if ((*(H_4F2A08 *)&D_001A4BE0).gun_arm_raised == 0) {
            lean = v.v.x * 0.698131680f; /* 40 deg */
            if (lean > limit) {
                lean = limit;
            } else if (lean < -limit) {
                lean = -limit;
            }
            D_L01_002F4540.waist.target_y = lean;
            D_L01_002F4540.neck.target_y = -lean * 0.5f;
            if ((*(H_4F2A08 *)&D_001A4BE0).hold_type != 0) {
                D_L01_002F4540.other_clavicle.target_y = -lean;
                D_L01_002F4540.gun_clavicle.target_y = -lean;
            }
        }
        tilt = -v.v.y * 0.698131680f;
        if (tilt > limit) {
            tilt = limit;
        } else if (tilt < -limit) {
            tilt = -limit;
        }
        D_L01_002F4540.waist.target_x = tilt;
        D_L01_002F4540.neck.target_x = -tilt * 0.25f;
        tail = -v.v.x * 1.22173047f; /* 70 deg */
        if (tail > 0.994837642f) {
            tail = 0.994837642f; /* 57 deg */
        }
        if (tail < -0.122173049f) {
            tail = -0.122173049f;
        }
        if (v.v.z > 0.850000024f) {
            if (tail < 1.39626336f) {
                tail = 1.39626336f; /* 80 deg */
            }
        } else if (v.v.z > 0.5f) {
            if (tail < 1.22173047f) {
                tail = 1.22173047f;
            }
        }
        tilt = v.v.y * 1.22173047f;
        D_L01_002F4540.tail[0].target_y = tail * 0.569999993f;
        D_L01_002F4540.tail[1].target_y = tail * 0.5f;
        D_L01_002F4540.tail[2].target_y = tail * 0.5f;
        D_L01_002F4540.tail[3].target_y = tail * 0.349999994f;
        if (tilt > 1.22173047f) {
            tilt = 1.22173047f;
        } else if (tilt < -1.22173047f) {
            tilt = -1.22173047f;
        }
        D_L01_002F4540.tail[3].target_x = tilt;
        D_L01_002F4540.tail[0].target_x = tilt * 0.699999988f;
        D_L01_002F4540.tail[1].target_x = tilt * 0.699999988f;
        D_L01_002F4540.tail[2].target_x = tilt * 0.699999988f;
    }
    if ((*(H_4F2A08 *)&D_001A4BE0).b25F4 == 1) {
        v.q = 0;
        v.v.x = 330.0f;
        v.v.y = 245.0f;
        v.v.z = 138.0f;
        near = 0;
        if (func_0038CF00(&(*(H_4F2A08 *)&D_001A4BE0).pos, &v) < 35.0f) {
            near = 1;
        }
        if ((*(H_4F2A08 *)&D_001A4BE0).hold_type != 0 && near) {
            D_L01_002F4540.gun_clavicle.gain = 0.0720000044f;
            D_L01_002F4540.gun_clavicle.damping = 0.432000041f;
            D_L01_002F4540.gun_clavicle.target_y = -0.226892799f;
            D_L01_002F4540.other_clavicle.gain = 0.0720000044f;
            D_L01_002F4540.other_clavicle.damping = 0.432000041f;
            D_L01_002F4540.other_clavicle.target_y = -0.226892799f;
        }
    }
}
/* localdecomp:end func_L01_004F2A08 */

/* localdecomp:start func_L01_004F2E68 */
#include "vu0.h"
typedef struct {
    u8 pad_0[0x98];
    f32 yaw; /* 0x98: rot.z */
    u8 pad_9C[0x118 - 0x9C];
    f32 vel_z; /* 0x118: vel.z */
    u8 pad_11C[0x174 - 0x11C];
    f32 speed_own_b; /* 0x174 */
    u8 pad_178[0x1A0 - 0x178];
    f32 move_angle; /* 0x1A0 */
    f32 yaw_rate; /* 0x1A4 */
    f32 turn_left; /* 0x1A8 */
    u8 pad_1AC[0x1B8 - 0x1AC];
    s32 state_timer; /* 0x1B8 */
    u8 pad_1BC[0x3EF - 0x1BC];
    u8 skid; /* 0x3EF: skid flag of the walk */
    u8 pad_3F0[0x1420 - 0x3F0];
    f32 strafe_vec[4]; /* 0x1420: lock-on block +0x00 */
    u8 pad_1430[0x1434 - 0x1430];
    s16 lockon_strafing; /* 0x1434 */
    u8 lockon_strafe_back; /* 0x1436 */
    u8 pad_1437;
    f32 lockon_strafe_heading; /* 0x1438 */
    u8 pad_143C[0x16B0 - 0x143C];
    s32 camera_mode; /* 0x16B0: 0 follow, 1 lock-strafe, 2 first person */
    u8 pad_16B4[0x25C4 - 0x16B4];
    s32 state; /* 0x25C4 */
    s32 substate; /* 0x25C8 */
    s32 state_type; /* 0x25CC */
    u8 pad_25D0[0x25EC - 0x25D0];
    u8 hold_type; /* 0x25EC: 0 none, 1 one hand, 2 both */
    u8 pad_25ED[0x25F4 - 0x25ED];
    u8 clavicles_near; /* 0x25F4 */
    u8 pad_25F5[0x2838 - 0x25F5];
    f32 stick_mag; /* 0x2838 */
} H_4F2E68;

extern void func_L01_004E6390(f32 a, f32 b);
extern void func_L01_004E63C0(f32 a, f32 b);
extern void func_L01_004E63D8(f32 a, f32 b);
extern f32 func_0038DB00(f32 a, f32 b);
extern f32 func_0038DAB8(f32 a, f32 b);
extern f32 func_0038D0B0(f32 a);
extern f32 func_0038D098(f32 a);
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern f32 func_L01_004F4E20_004F2E68(void *a0, void *a1);

/* hero_body_twist: procedural joint offsets on top of the animation. Sideways strafing
   turns the root by the strafe's angle to the hero's yaw; the walk, the glide and the
   jumps lean the body by the turn and the yaw rate. */
void func_L01_004F2E68(void)
{

    if ((*(H_4F2E68 *)&D_001A4BE0).lockon_strafing != 0 || ((*(H_4F2E68 *)&D_001A4BE0).camera_mode == 1 && func_L01_004606E8(0x28, 2, 0, 0) != 0)) {
        if (0.150000006f < (*(H_4F2E68 *)&D_001A4BE0).stick_mag && (*(H_4F2E68 *)&D_001A4BE0).state != 0x0B && (*(H_4F2E68 *)&D_001A4BE0).state != 0x66 && (*(H_4F2E68 *)&D_001A4BE0).state != 0x69
            && (*(H_4F2E68 *)&D_001A4BE0).lockon_strafe_back == 0) {
            /* sideways strafe: the root turns to the strafe heading, minus the hero's yaw */
            f32 lean;

            D_L01_002F4540.root.gain = 0.0532800034f;
            D_L01_002F4540.waist.gain = 0.0360000022f;
            D_L01_002F4540.root.damping = 0.388800025f;
            D_L01_002F4540.waist.damping = 0.388800025f;
            if ((*(H_4F2E68 *)&D_001A4BE0).clavicles_near != 0) {
                lean = func_L01_004F4E20_004F2E68((*(H_4F2E68 *)&D_001A4BE0).strafe_vec, 0);
            } else {
                lean = func_0038DB00((*(H_4F2E68 *)&D_001A4BE0).lockon_strafe_heading, (*(H_4F2E68 *)&D_001A4BE0).yaw);
            }
            D_L01_002F4540.root.target_z = lean;
            D_L01_002F4540.waist.target_z = -lean;
            return;
        }
    }

    if ((*(H_4F2E68 *)&D_001A4BE0).state == 2) {
        f32 damping = 0.200000003f;
        f32 gain = 0.0399999991f;
        func_L01_004E6390(gain, damping);
        func_L01_004E63A8(gain, damping);
        func_L01_004E63C0(gain, damping);
        func_L01_004E63D8(0.0199999996f, damping);
        if ((*(H_4F2E68 *)&D_001A4BE0).substate == 1) {
            f32 lean;
            f32 c;

            lean = (*(H_4F2E68 *)&D_001A4BE0).yaw_rate * 17.0f;
            if (1.39999998f < lean) {
                lean = 1.39999998f;
            } else if (lean < -1.39999998f) {
                lean = -1.39999998f;
            }
            {
                f32 lim = fabs_asm((*(H_4F2E68 *)&D_001A4BE0).turn_left);
                if (lim * 3.0f < lean) {
                    lean = lim * 3.0f;
                } else {
                    lim = -lim;
                    if (lean < lim * 3.0f) {
                        lean = lim * 3.0f;
                    }
                }
            }
            if ((*(H_4F2E68 *)&D_001A4BE0).skid != 0) {
                if (1.10000002f < lean) {
                    lean = 1.10000002f;
                } else if (lean < -1.10000002f) {
                    lean = -1.10000002f;
                }
                func_L01_004E63A8(0.0791999996f, 0.432000041f);
                func_L01_004E63D8(0.100800008f, 0.432000041f);
                {
                    f32 lim = fabs_asm((*(H_4F2E68 *)&D_001A4BE0).turn_left);
                    if (lim < lean) {
                        lean = lim;
                    } else if (lean < -lim) {
                        lean = -lim;
                    }
                }
            }
            c = -lean;
            D_L01_002F4540.root.target_x = c * 0.109999999f;
            if ((*(H_4F2E68 *)&D_001A4BE0).skid != 0) {
                D_L01_002F4540.root.target_x = D_L01_002F4540.root.target_x * 0.25f;
            }
            {
                f32 speed = (*(H_4F2E68 *)&D_001A4BE0).speed_own_b / 0.114000008f;
                if (1.0f < speed) {
                    speed = 1.0f;
                }
                if (speed < 0.0f) {
                    speed = 0.0f;
                }
                D_L01_002F4540.root.target_x = D_L01_002F4540.root.target_x * speed;
            }
            D_L01_002F4540.waist.target_z = lean * 0.310000002f;
            if ((*(H_4F2E68 *)&D_001A4BE0).skid != 0) {
                D_L01_002F4540.waist.target_z = 0.0f;
            }
            {
            f32 a = fabs_asm(lean);
            D_L01_002F4540.chest.target_x = lean * -0.150000006f;
            D_L01_002F4540.neck.target_y = a * -0.150000006f;
            D_L01_002F4540.tail[0].target_z = c * 0.349999994f;
            D_L01_002F4540.neck.target_z = lean * 0.699999988f;
            D_L01_002F4540.tail[1].target_z = c * 0.300000012f;
            D_L01_002F4540.neck.target_x = a * 0.159999996f;
            D_L01_002F4540.tail[1].target_y = a * 0.200000003f;
            D_L01_002F4540.tail[2].target_z = c * 0.300000012f;
            D_L01_002F4540.tail[0].target_y = a * 0.349999994f;
            D_L01_002F4540.tail[3].target_z = c * 0.300000012f;
            }
            return;
        }
        {
        f32 turn_copy = (*(H_4F2E68 *)&D_001A4BE0).turn_left;
        f32 step;
        f32 c;

        if ((*(H_4F2E68 *)&D_001A4BE0).stick_mag < 0.800000012f && (*(H_4F2E68 *)&D_001A4BE0).state_timer < 33) {
            step = (f32)(33 - (*(H_4F2E68 *)&D_001A4BE0).state_timer) * 0.0872664601f;
            func_003C4138(&turn_copy, 0.0f, step);
        }
        c = turn_copy * 0.5f;
        if (0.800000012f < c) {
            c = 0.800000012f;
        } else if (c < -0.800000012f) {
            c = -0.800000012f;
        }
        c = c * fabs_asm(c) * 1.25f;
        D_L01_002F4540.waist.target_z = c;
        D_L01_002F4540.neck.target_z = c;
        D_L01_002F4540.neck.target_y = fabs_asm(c) * 0.25f;
        D_L01_002F4540.tail[0].target_z = -c * 0.349999994f;
        D_L01_002F4540.tail[1].target_z = -c * 0.300000012f;
        D_L01_002F4540.tail[2].target_z = -c * 0.300000012f;
        D_L01_002F4540.tail[3].target_z = -c * 0.300000012f;
        }
        return;
    }

    if ((*(H_4F2E68 *)&D_001A4BE0).state == 8) {
        f32 c;
        f32 a;

        func_L01_004E6390(0.00800000038f, 0.0799999982f);
        func_L01_004E63A8(0.0149999997f, 0.0799999982f);
        func_L01_004E63C0(0.0149999997f, 0.0799999982f);
        func_L01_004E63D8(0.00800000038f, 0.100000001f);
        c = (*(H_4F2E68 *)&D_001A4BE0).turn_left * 1.60000002f;
        if (1.25f < c) {
            c = 1.25f;
        } else if (c < -1.25f) {
            c = -1.25f;
        }
        D_L01_002F4540.root.target_x = -c * 0.519999981f;
        if (0.280000001f < D_L01_002F4540.root.target_x) {
            D_L01_002F4540.root.target_x = 0.280000001f;
        } else if (D_L01_002F4540.root.target_x < -0.280000001f) {
            D_L01_002F4540.root.target_x = -0.280000001f;
        }
        D_L01_002F4540.neck.target_z = c * 1.20000005f;
        D_L01_002F4540.waist.target_z = c * 0.579999983f;
        D_L01_002F4540.chest.target_x = c * -0.280000001f;
        if (0.600000024f < D_L01_002F4540.neck.target_z) {
            D_L01_002F4540.neck.target_z = 0.600000024f;
        } else if (D_L01_002F4540.neck.target_z < -0.600000024f) {
            D_L01_002F4540.neck.target_z = -0.600000024f;
        }
        D_L01_002F4540.neck.target_y = fabs_asm(c) * 0.200000003f;
        if (0.200000003f < D_L01_002F4540.neck.target_y) {
            D_L01_002F4540.neck.target_y = 0.200000003f;
        } else if (D_L01_002F4540.neck.target_y < -0.200000003f) {
            D_L01_002F4540.neck.target_y = -0.200000003f;
        }
        D_L01_002F4540.neck.target_x = fabs_asm(c) * 0.159999996f;
        D_L01_002F4540.tail[0].target_z = -c * 0.349999994f;
        D_L01_002F4540.tail[1].target_z = -c * 0.300000012f;
        D_L01_002F4540.tail[2].target_z = -c * 0.300000012f;
        D_L01_002F4540.tail[3].target_z = -c * 0.300000012f;
        return;
    }

    if ((*(H_4F2E68 *)&D_001A4BE0).state == 0x87) {
        f32 c;
        f32 a;
        f32 step;
        func_L01_004E6390(0.0170000009f, 0.330000013f);
        func_L01_004E63A8(0.0149999997f, 0.25f);
        func_L01_004E63C0(0.0149999997f, 0.25f);
        func_L01_004E63D8(0.00800000038f, 0.25f);
        c = (*(H_4F2E68 *)&D_001A4BE0).turn_left * 0.699999988f;
        if (1.20000005f < c) {
            c = 1.20000005f;
        } else if (c < -1.20000005f) {
            c = -1.20000005f;
        }
        D_L01_002F4540.root.target_x = -c * 0.519999981f;
        if (0.280000001f < D_L01_002F4540.root.target_x) {
            D_L01_002F4540.root.target_x = 0.280000001f;
        } else if (D_L01_002F4540.root.target_x < -0.280000001f) {
            D_L01_002F4540.root.target_x = -0.280000001f;
        }
        D_L01_002F4540.neck.target_z = c * 1.20000005f;
        D_L01_002F4540.waist.target_z = c * 0.579999983f;
        D_L01_002F4540.chest.target_x = c * -0.280000001f;
        if (0.600000024f < D_L01_002F4540.neck.target_z) {
            D_L01_002F4540.neck.target_z = 0.600000024f;
        } else if (D_L01_002F4540.neck.target_z < -0.600000024f) {
            D_L01_002F4540.neck.target_z = -0.600000024f;
        }
        D_L01_002F4540.neck.target_x = fabs_asm(c) * 0.159999996f;
        D_L01_002F4540.root.target_y = func_0038DAB8(D_L01_002F4540.root.target_y, -0.122173049f);
        if (0.100000001f < (*(H_4F2E68 *)&D_001A4BE0).stick_mag) {
            a = func_0038DB00((*(H_4F2E68 *)&D_001A4BE0).move_angle, (*(H_4F2E68 *)&D_001A4BE0).yaw);
            step = (*(H_4F2E68 *)&D_001A4BE0).stick_mag * 0.610865235f;
            D_L01_002F4540.root.target_x = -func_0038D0B0(a) * step;
            D_L01_002F4540.root.target_y = func_0038DAB8(D_L01_002F4540.root.target_y, func_0038D098(a) * step);
            if (0.471238881f < D_L01_002F4540.root.target_x) {
                D_L01_002F4540.root.target_x = 0.471238881f;
            } else if (D_L01_002F4540.root.target_x < -0.471238881f) {
                D_L01_002F4540.root.target_x = -0.471238881f;
            }
            if (0.471238881f < D_L01_002F4540.root.target_y) {
                D_L01_002F4540.root.target_y = 0.471238881f;
            } else if (D_L01_002F4540.root.target_y < -0.471238881f) {
                D_L01_002F4540.root.target_y = -0.471238881f;
            }
        }
        D_L01_002F4540.other_clavicle.gain = 0.0250000004f;
        D_L01_002F4540.other_clavicle.damping = 0.370000005f;
        D_L01_002F4540.gun_clavicle.gain = 0.0250000004f;
        D_L01_002F4540.gun_clavicle.damping = 0.370000005f;
        {
            f32 lean;
            s32 arm_one = 1;
            s32 arm_two = 1;
            if ((*(H_4F2E68 *)&D_001A4BE0).hold_type == 1) {
                arm_two = 0;
            } else if ((*(H_4F2E68 *)&D_001A4BE0).hold_type == 2) {
                arm_one = 0;
                arm_two = 0;
            }
            lean = func_0038DAB8((*(H_4F2E68 *)&D_001A4BE0).vel_z * 5.0f, 0.296705961f);
            if (arm_one != 0) {
                D_L01_002F4540.other_clavicle.target_z = -0.34906584f;
                D_L01_002F4540.other_clavicle.target_x = -lean;
                if (0.610865235f < -lean) {
                    D_L01_002F4540.other_clavicle.target_x = 0.610865235f;
                } else if (-lean < -0.610865235f) {
                    D_L01_002F4540.other_clavicle.target_x = -0.610865235f;
                }
            }
            if (arm_two != 0) {
                D_L01_002F4540.gun_clavicle.target_x = lean;
                D_L01_002F4540.gun_clavicle.target_z = 0.34906584f;
                if (0.610865235f < lean) {
                    D_L01_002F4540.gun_clavicle.target_x = 0.610865235f;
                } else if (lean < -0.610865235f) {
                    D_L01_002F4540.gun_clavicle.target_x = -0.610865235f;
                }
            }
        }
        D_L01_002F4540.neck.target_y = -(*(H_4F2E68 *)&D_001A4BE0).vel_z * 7.69999981f;
        if (0.645771801f < D_L01_002F4540.neck.target_y) {
            D_L01_002F4540.neck.target_y = 0.645771801f;
        } else if (D_L01_002F4540.neck.target_y < -0.645771801f) {
            D_L01_002F4540.neck.target_y = -0.645771801f;
        }
        D_L01_002F4540.tail[0].target_z = -c * 0.349999994f;
        D_L01_002F4540.tail[1].target_z = -c * 0.300000012f;
        D_L01_002F4540.tail[2].target_z = -c * 0.300000012f;
        D_L01_002F4540.tail[3].target_z = -c * 0.300000012f;
        return;
    }

    if ((*(H_4F2E68 *)&D_001A4BE0).state_type == 2 || (*(H_4F2E68 *)&D_001A4BE0).state_type == 4) {
        f32 c;
        func_L01_004E6390(0.0399999991f, 0.200000003f);
        func_L01_004E63A8(0.0399999991f, 0.200000003f);
        func_L01_004E63C0(0.0399999991f, 0.200000003f);
        func_L01_004E63D8(0.0199999996f, 0.200000003f);
        c = (*(H_4F2E68 *)&D_001A4BE0).turn_left;
        if (1.39999998f < c) {
            c = 1.39999998f;
        } else if (c < -1.39999998f) {
            c = -1.39999998f;
        }
        D_L01_002F4540.waist.target_z = c * 0.289999992f;
        D_L01_002F4540.chest.target_x = c * -0.270000011f;
        D_L01_002F4540.neck.target_z = c * 0.870000005f;
        D_L01_002F4540.tail[0].target_z = -c * 0.349999994f;
        D_L01_002F4540.tail[1].target_z = -c * 0.300000012f;
        D_L01_002F4540.tail[2].target_z = -c * 0.300000012f;
        D_L01_002F4540.tail[3].target_z = -c * 0.300000012f;
    }
}
/* localdecomp:end func_L01_004F2E68 */

/* localdecomp:start func_L01_004F3BE0 */
#include "vu0.h"
extern St_004ECCD8 D_001A4BE0;
typedef struct {
    u8 p0[0x10E0]; f32 f10E0; u8 p10E4[4]; f32 f10E8;
    u8 p10EC[0x1190-0x10EC]; f32 f1190, f1194, f1198;
    u8 p119C[0x1240-0x119C]; f32 f1240;
} Springs_004F3BE0;
extern Springs_004F3BE0 D_L01_002F4540_004F3BE0;
void func_L01_004F3BE0(void) {
    if ((*(H_4F2E68 *)&D_001A4BE0).state == 0x40) {
        f32 c = (*(H_4F2E68 *)&D_001A4BE0).yaw_rate * 9.0f;
        f32 speed;
        f32 neg;
        if (c > 0.7f) c = 0.7f;
        else if (c < -0.7f) c = -0.7f;
        c = c * fabs_asm(c) * 1.25f;
        neg = -c;
        D_L01_002F4540_004F3BE0.f1240 = neg * 0.2f;
        speed = (*(H_4F2E68 *)&D_001A4BE0).speed_own_b / 0.06000000238418579f;
        if (speed > 1.0f) speed = 1.0f;
        if (speed < 0.0f) speed = 0.0f;
        D_L01_002F4540_004F3BE0.f1240 *= speed;
        D_L01_002F4540_004F3BE0.f10E8 = c;
        D_L01_002F4540_004F3BE0.f10E0 = neg * 0.35f;
        D_L01_002F4540_004F3BE0.f1198 = c * 1.35f;
        D_L01_002F4540_004F3BE0.f1194 = fabs_asm(c) * 0.25f;
    } else if ((*(H_4F2E68 *)&D_001A4BE0).state == 0x4B) {
        f32 c = (*(H_4F2E68 *)&D_001A4BE0).turn_left * 1.6f;
        if (c > 1.25f) c = 1.25f;
        else if (c < -1.25f) c = -1.25f;
        D_L01_002F4540_004F3BE0.f1240 = -c * 0.52f;
        if (D_L01_002F4540_004F3BE0.f1240 > 0.28f) D_L01_002F4540_004F3BE0.f1240 = 0.28f;
        else if (D_L01_002F4540_004F3BE0.f1240 < -0.28f) D_L01_002F4540_004F3BE0.f1240 = -0.28f;
        D_L01_002F4540_004F3BE0.f1198 = c * 1.7f;
        D_L01_002F4540_004F3BE0.f10E8 = c * 0.58f;
        if (D_L01_002F4540_004F3BE0.f1198 > 0.7f) D_L01_002F4540_004F3BE0.f1198 = 0.7f;
        else if (D_L01_002F4540_004F3BE0.f1198 < -0.7f) D_L01_002F4540_004F3BE0.f1198 = -0.7f;
        D_L01_002F4540_004F3BE0.f1194 = fabs_asm(c) * 0.2f;
        if (D_L01_002F4540_004F3BE0.f1194 > 0.2f) D_L01_002F4540_004F3BE0.f1194 = 0.2f;
        else if (D_L01_002F4540_004F3BE0.f1194 < -0.2f) D_L01_002F4540_004F3BE0.f1194 = -0.2f;
        D_L01_002F4540_004F3BE0.f1190 = fabs_asm(c) * 0.16f;
    } else if ((*(H_4F2E68 *)&D_001A4BE0).state_type == 2 || (*(H_4F2E68 *)&D_001A4BE0).state_type == 4) {
        f32 c = (*(H_4F2E68 *)&D_001A4BE0).turn_left;
        if (c > 1.4f) c = 1.4f;
        else if (c < -1.4f) c = -1.4f;
        D_L01_002F4540_004F3BE0.f10E8 = c * 0.29f;
        D_L01_002F4540_004F3BE0.f1198 = c * 0.87f;
    }
}
/* localdecomp:end func_L01_004F3BE0 */

INCLUDE_ASM("asm/levels", func_L01_004F3F40);

/* localdecomp:start func_L01_004F40A8 */
#include "vu0.h"
extern void func_0038D328(void *, void *);
extern void func_0038D5B0(void *, void *);
extern s32 D_001A71A0[];
extern void func_0038D028(f32 *out, void *a, void *b);
extern f32 func_0038D160(f32 a, f32 b);

void func_L01_004F40A8(vu0_v4 *a0, f32 *a1) {
    vu0_v4 m[4];
    vu0_v4 n[4];
    vu0_v4 v;

    v = *a0;
    func_0038D328(m, (u8 *)D_001A71A0[0] + 0xF0);
    func_0038D5B0(n, m);
    func_0038D028(&v.x, &v, n);
    a1[0] = func_0038D160(sqrt_asm(v.x * v.x + v.z * v.z), v.y);
    a1[1] = -func_0038D160(v.z, v.x);
}
/* localdecomp:end func_L01_004F40A8 */

/* localdecomp:start func_L01_004F4148 */
#include "vu0.h"
extern St_004ECCD8 D_001A4BE0;
extern u8 D_001A4C84[];
extern u8 D_001A4C70[];
void func_L01_004F4148(void *direction, vu0_q *out, void *position, f32 a, f32 b, f32 c) {
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_0038D160(f32, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038D348(void *, void *);
    extern void func_0038D640(void *, void *, void *);
    extern void func_0038D028(f32 *, void *, void *);
    extern f32 func_L01_00448728(f32 *, void *, s32, f32, f32, f32, f32);
    extern void func_003C48A8(void *, void *);
    vu0_v4 m0[4], m1[4], rotation, cross;
    f32 value = 0.0f;
    f32 dot, angle, roll, pitch;
    out[0] = ((vu0_q *)&D_001A4BE0)[0];
    out[1] = ((vu0_q *)&D_001A4BE0)[1];
    out[2] = ((vu0_q *)&D_001A4BE0)[2];
    out[3] = ((vu0_q *)&D_001A4BE0)[3];
    dot = func_0038CE68(direction, &out[2]);
    angle = func_0038D160(dot, sqrt_asm(1.0f - dot * dot));
    func_0038CE90(&cross, direction, &out[2]);
    if (cross.z < 0.99f) {
        roll = func_0038D160(cross.x, cross.y);
        rotation.x = 0.0f;
        rotation.y = 0.0f;
        rotation.z = -roll;
        func_0038D348(m1, &rotation);
        func_0038D640(out, m1, out);
        func_0038D028(&cross.x, &cross, m1);
        pitch = func_0038D160(cross.z, cross.x);
        rotation.x = 0.0f;
        rotation.z = 0.0f;
        rotation.y = -pitch;
        func_0038D348(m0, &rotation);
        func_0038D640(out, m0, out);
        func_0038D028(&cross.x, &cross, m0);
    } else {
        roll = 0.0f;
        pitch = roll;
    }
    if (position) {
        rotation.z = angle;
        rotation.x = 0;
    } else {
        func_L01_00448728(&value, D_001A4C84, 0, angle, a, b, c);
        rotation.z = value;
        rotation.x = 0;
    }
    rotation.y = 0;
    func_0038D348(m1, &rotation);
    func_0038D640(out, m1, out);
    rotation.y = pitch;
    rotation.z = 0;
    func_0038D348(m0, &rotation);
    func_0038D640(out, m0, out);
    rotation.z = roll;
    rotation.y = 0;
    func_0038D348(m1, &rotation);
    func_0038D640(out, m1, out);
    if (position) func_003C48A8(out, position);
    else func_003C48A8(out, D_001A4C70);
}
/* localdecomp:end func_L01_004F4148 */

/* localdecomp:start func_L01_004F4410 */
#include "vu0.h"
typedef struct { u8 pad[0x218]; s16 h218; u8 pad21A[0x2C0 - 0x21A]; vu0_v4 direction; u8 pad2D0[0x33C - 0x2D0]; f32 f33C; u8 pad340[0x36E - 0x340]; s16 h36E; u8 pad370[0x25F4 - 0x370]; u8 mode; } Hero_004F4410;
void func_L01_004F4410(void) {
    extern void func_0038D028(f32 *, void *, void *);
    extern void func_0038CE20(Vec4ED3B8 *, Vec4ED3B8 *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_L01_004F4148(void *, vu0_q *, void *, f32, f32, f32);
    vu0_q matrix[4];
    vu0_v4 dir, before, after, copy;
    Hero_004F4410 *h = (Hero_004F4410 *)&D_001A4BE0;
    f32 a, b;
    *(vu0_q *)&dir = 0;
    *(vu0_q *)&before = 0;
    *(vu0_q *)&after = 0;
    dir.z = 1.0f;
    after.z = before.z = 0.8f;
    func_0038D028(&before.x, &before, h);
    a = 0.05040000379085541f;
    b = 0.4320000410079956f;
    { s32 mode = h->mode;
    dir = h->direction;
    if (mode == 2) func_0038CE20((Vec4ED3B8 *)&dir, (Vec4ED3B8 *)((u8 *)h + 0x2E0), -1.0f); }
    if (h->mode == 1 && (*(s16 *)((u8 *)h + 0x36E) < 8 || h->f33C < 1.0f))
        dir = h->direction;
    if (((Hero_004F4410 *)&D_001A4BE0)->h36E != 0 && ((Hero_004F4410 *)&D_001A4BE0)->h218 != 0) a = b = 0.001440000138245523f;
    h = (Hero_004F4410 *)&D_001A4BE0;
    if (*(s32 *)((u8 *)h + 0x16B0)) func_0038D000((u8 *)h + 0x1630, (u8 *)h + 0x1630, (u8 *)h + 0x40);
    func_L01_004F4148(&dir, matrix, 0, a, b, 0.0f);
    if (*(s32 *)((u8 *)h + 0x16B0)) func_0038D000((u8 *)h + 0x1630, (u8 *)h + 0x1630, matrix);
    if (h->mode == 1 && *(s16 *)((u8 *)h + 0x36E) != 0) {
        func_0038D028(&after.x, &after, matrix);
        __asm__(
            "lqc2 $vf1, %2\n\t"
            "lqc2 $vf2, %0\n\t"
            "vsub.xyz $vf2, $vf2, $vf1\n\t"
            "lqc2 $vf1, %3\n\t"
            "sqc2 $vf1, %1\n\t"
            "sqc2 $vf2, %0\n\t"
            "lqc2 $vf1, %0\n\t"
            "lqc2 $vf2, %1\n\t"
            "vadd.xyz $vf1, $vf1, $vf2\n\t"
            "sqc2 $vf1, %0"
            : "+m"(*(vu0_v4 *)((u8 *)h + 0x80)), "=m"(copy)
            : "m"(after), "m"(before)
            : "vf1", "vf2");
    }
}
/* localdecomp:end func_L01_004F4410 */

/* localdecomp:start func_L01_004F45F0 */
void func_L01_004F45F0(void) {
    extern f32 func_L01_00448728(void *, f32, void *, f32, f32, f32, s32);
    extern void func_L01_004EEC98(f32, f32, f32);
    extern void func_L01_004F4410(void);
    vu0_q v;
    u8 *h = (u8 *)&D_001A4BE0;
    s32 mode = h[0x25F4];
    if (*(s16 *)(h + 0x218)) mode = 1;
    switch (mode) {
    case 0: {
        s32 state = *(s32 *)(h + 0x25C4);
        if (state == 36 || state == 37 || *(s32 *)(h + 0x25CC) == 17 || state == 121 || state == 48 || state == 44 || state == 43) return;
        v = *(vu0_q *)(h + 0x90);
        func_L01_00448728(&v, 0.0f, h + 0xA0, 0.02160000056028366f, 0.4320000410079956f, 0.10471975803375244f, 0);
        func_L01_00448728((u8 *)&v + 4, 0.0f, h + 0xA4, 0.02160000056028366f, 0.4320000410079956f, 0.10471975803375244f, 0);
        func_L01_004EEC98(*(f32 *)(h + 0xA0), *(f32 *)(h + 0xA4), 0.0f);
        break;
    }
    case 1:
    case 2:
        ((void (*)(s32))func_L01_004F4410)(mode);
        break;
    }
}
/* localdecomp:end func_L01_004F45F0 */

/* localdecomp:start func_L01_004F4730 */
typedef struct {
    u8 p0[0xF0];
    vu0_q pos;
    u8 pF0[0x70 - 0x10];
    vu0_q vel;
} H_4F4730;
extern f32 func_L01_00511408(void *);
extern void func_L01_00511508(void *, void *, f32);
extern void func_L01_00511588(void *, void *, f32);

void func_L01_004F4730(f32 a0) {
    f32 d = func_L01_00511408(&(*(H_4F4730 *)&D_001A4BE0).vel);
    f32 z;
    f32 t;
    if (0.001f < d) {
        z = 0.0f;
        func_L01_00511508(&(*(H_4F4730 *)&D_001A4BE0).vel, &(*(H_4F4730 *)&D_001A4BE0).vel, z);
        t = d - a0;
        if (t < z) {
            t = z;
        }
        func_L01_00511588(&(*(H_4F4730 *)&D_001A4BE0).vel, &(*(H_4F4730 *)&D_001A4BE0).vel, t);
        vec_add_ba(&(*(H_4F4730 *)&D_001A4BE0).pos, &(*(H_4F4730 *)&D_001A4BE0).pos, &(*(H_4F4730 *)&D_001A4BE0).vel);
    } else {
        qzero(&(*(H_4F4730 *)&D_001A4BE0).vel);
    }
}
/* localdecomp:end func_L01_004F4730 */

/* localdecomp:start func_L01_004F47F0 */
#include "vu0.h"
typedef struct {
 u8 pad0[0x88];
 f32 z;
 u8 pad8C[0xC];
 f32 yaw;
 u8 pad9C[0x54];
 vu0_v4 velocity;
 u8 pad100[0x70];
 f32 speed;
 u8 pad174[0x2C];
 f32 heading;
 u8 pad1A4[0xC];
 f32 magnitude;
 u8 pad1B4[0x4];
 s32 ticks;
 u8 pad1BC[0x104];
 vu0_v4 slope;
 u8 pad2D0[0x68];
 f32 floor;
 u8 pad33C[0x4];
 f32 slope_angle;
 f32 last_angle;
 u8 pad348[0x98];
 f32 alignment;
 f32 last_slope;
 u8 pad3E8[0x5F8];
 vu0_v4 push;
 f32 push_time;
 u8 pad9F4[0xA40];
 s16 lock;
 u8 pad1436[0x2];
 f32 lock_heading;
 u8 pad143C[0x274];
 s32 camera;
 u8 pad16B4[0xF10];
 s32 state;
 u8 pad25C8[0x270];
 f32 stick;
} Hero_004F47F0;
typedef struct { u8 pad[0x1d4]; s32 active; } State_004F47F0;
extern State_004F47F0 *D_001D52FC;
extern St_004ECCD8 D_001A4BE0;
extern u8 D_001A4CD0[];
extern vu0_v4 D_001A4D20;
void func_L01_004F47F0(void) {
 extern void func_L01_004EE850(s32,f32);
 extern s32 func_L01_004606E8(s32,s32,s32,s32);
 extern void func_L01_004EE400(void);
 extern void func_L01_004F2E68(void);
 extern void func_L01_004EEDD0(s32,f32,f32,f32);
 extern f32 func_0038D098(f32);
 extern f32 func_0038D0B0(f32);
 extern void func_L01_004F0558(f32,f32);
 extern f32 func_0038CED8(void *);
 extern f32 func_0038CE68(void *,void *);
 extern f32 func_0038CEA8(void *);
 extern void func_0038CF68(void *,void *,f32);
 extern f32 func_0038D160(f32,f32);
 extern void func_0038CE20(Vec4ED3B8 *,Vec4ED3B8 *,f32);
 extern void func_L01_004EF3A8(s32);
 vu0_v4 desired,original,push,delta,other;
 f32 heading,amount,step,component,length,rate;
 func_L01_004EE850(0,1.0f);
 if((*(Hero_004F47F0 *)&D_001A4BE0).lock ||
   ((*(Hero_004F47F0 *)&D_001A4BE0).camera==1 && func_L01_004606E8(40,2,0,0))) {
  func_L01_004EE400();
  func_L01_004F2E68();
 } else {
  func_L01_004EEDD0(0,0.028800001367926598f,0.2880000174045563f,0.07330383360385895f);
 }
 if((*(Hero_004F47F0 *)&D_001A4BE0).state==19) {
  if((*(Hero_004F47F0 *)&D_001A4BE0).stick<0.2f)
   (*(Hero_004F47F0 *)&D_001A4BE0).heading=(*(Hero_004F47F0 *)&D_001A4BE0).yaw;
  (*(Hero_004F47F0 *)&D_001A4BE0).magnitude=0.4f;
 } else if((*(Hero_004F47F0 *)&D_001A4BE0).state==21) {
  (*(Hero_004F47F0 *)&D_001A4BE0).magnitude=0;
 }
 heading=(*(Hero_004F47F0 *)&D_001A4BE0).heading;
 if((*(Hero_004F47F0 *)&D_001A4BE0).lock ||
   ((*(Hero_004F47F0 *)&D_001A4BE0).camera==1 && func_L01_004606E8(40,2,0,0))) {
  heading=(*(Hero_004F47F0 *)&D_001A4BE0).lock_heading;
 }
 desired.x=func_0038D098(heading)*((*(Hero_004F47F0 *)&D_001A4BE0).magnitude*0.11800000816583633f);
 desired.y=func_0038D0B0(heading)*((*(Hero_004F47F0 *)&D_001A4BE0).magnitude*0.11800000816583633f);
 desired.z=0;
 original=desired;
 if((*(Hero_004F47F0 *)&D_001A4BE0).push_time>0) {
  func_L01_004F0558(0.7f,0.0f);
  push=(*(Hero_004F47F0 *)&D_001A4BE0).push;
  vec_add_ba(&desired,&desired,&(*(Hero_004F47F0 *)&D_001A4BE0).push);
  qzero(&(*(Hero_004F47F0 *)&D_001A4BE0).push);
 }
 amount=-((*(Hero_004F47F0 *)&D_001A4BE0).velocity.x*desired.x+
          (*(Hero_004F47F0 *)&D_001A4BE0).velocity.y*desired.y);
 if(amount>0) {
  amount/=func_0038CED8(&desired);
  amount/=func_0038CED8(&(*(Hero_004F47F0 *)&D_001A4BE0).velocity);
 }
 if(amount>1) amount=1;
 if(amount<0) amount=0;
 step=(*(Hero_004F47F0 *)&D_001A4BE0).magnitude*0.0009800000116229057f;
 step+=amount*0.000800000037997961f;
 if(D_001D52FC->active) step=0.00044000003254041076f;
 if((*(Hero_004F47F0 *)&D_001A4BE0).state==19 &&
    (*(Hero_004F47F0 *)&D_001A4BE0).ticks<12 &&
    (*(Hero_004F47F0 *)&D_001A4BE0).speed<0.06000000238418579f) step=0.004399999976158142f;
 if((*(Hero_004F47F0 *)&D_001A4BE0).speed>0.11800000816583633f) step=0.0052000004798173904f;
 if((*(Hero_004F47F0 *)&D_001A4BE0).push_time>0) {
  component=-func_0038CE68(&original,&push);
  length=func_0038CEA8(&original);
  if(length>0) component/=length;
  length=func_0038CED8(&push);
  rate=(length-component)/length*0.0012000000569969416f;
  if((*(Hero_004F47F0 *)&D_001A4BE0).stick<0.3f && rate<0.0012000000569969416f) rate=0.0012000000569969416f;
  if(rate>step) step=rate;
 }
 vec_sub_ab(&delta,&desired,((u8 *)&D_001A4BE0+0x140));
 delta.z=0;
 if(func_0038CEA8(&delta)>step) func_0038CF68(&delta,&delta,step);
 vec_add_ab(((u8 *)&D_001A4BE0+0xf0),((u8 *)&D_001A4BE0+0x140),&delta);
 if((*(Hero_004F47F0 *)&D_001A4BE0).slope_angle>0.0872664600610733f) {
  f32 slope_heading,slope_rate,slope_amount;
  slope_heading=func_0038D160((*(Hero_004F47F0 *)&D_001A4BE0).slope.x,(*(Hero_004F47F0 *)&D_001A4BE0).slope.y);
  slope_amount=(*(Hero_004F47F0 *)&D_001A4BE0).slope_angle*0.1600000113248825f/0.7853981852531433f;
  slope_rate=(*(Hero_004F47F0 *)&D_001A4BE0).slope_angle*0.0034000002779066563f/0.7853981852531433f;
  delta.x=func_0038D098(slope_heading)*slope_amount;
  delta.y=func_0038D0B0(slope_heading)*slope_amount;
  delta.z=0;
  vec_sub_ba(&other,&delta,((u8 *)&D_001A4BE0+0xf0));
  other.z=0;
  if(func_0038CEA8(&other)>slope_rate) func_0038CF68(&other,&other,slope_rate);
  vec_add_ab(((u8 *)&D_001A4BE0+0xf0),((u8 *)&D_001A4BE0+0xf0),&other);
 }
 delta=*(vu0_v4 *)((u8 *)&D_001A4BE0+0xf0);
 delta.z=0;
 (*(Hero_004F47F0 *)&D_001A4BE0).alignment=func_0038CE68(&delta,&desired);
 { f32 length=func_0038CEA8(&desired);
 if(length>0) (*(Hero_004F47F0 *)&D_001A4BE0).alignment/=length*0.11800000816583633f; }
 func_L01_004EF3A8(0);
 if((*(Hero_004F47F0 *)&D_001A4BE0).last_slope<0.01745329238474369f &&
    (*(Hero_004F47F0 *)&D_001A4BE0).last_angle>0.0872664600610733f) {
  func_0038CE20((Vec4ED3B8 *)((u8 *)&D_001A4BE0+0xf0),(Vec4ED3B8 *)((u8 *)&D_001A4BE0+0xf0),
                func_0038D098((*(Hero_004F47F0 *)&D_001A4BE0).last_angle));
 }
 (*(Hero_004F47F0 *)&D_001A4BE0).last_slope=(*(Hero_004F47F0 *)&D_001A4BE0).last_angle;
 if(fabs_asm((*(Hero_004F47F0 *)&D_001A4BE0).z-(*(Hero_004F47F0 *)&D_001A4BE0).floor)<0.15f)
  (*(Hero_004F47F0 *)&D_001A4BE0).z=(*(Hero_004F47F0 *)&D_001A4BE0).floor;
}
/* localdecomp:end func_L01_004F47F0 */

/* localdecomp:start func_L01_004F4E20 */
extern u8 D_001A4C20[];
extern void func_0038D028(f32 *out, void *a, void *b);
extern f32 func_0038D160(f32 a, f32 b);
extern void func_L01_004485E0(void *p, f32 a, f32 b);

void func_L01_004F4E20(void *a0, void *a1)
{
    f32 v[4];
    func_0038D028(v, a0, D_001A4C20);
    func_L01_004485E0(a1, func_0038D160(v[0], v[1]), 0.0f);
}
/* localdecomp:end func_L01_004F4E20 */

/* localdecomp:start func_L01_004F4E70 */
extern St_004ECCD8 D_001A4BE0;
typedef int u128_4F1068 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x10];
    u128_4F1068 v10;
} S_4F1068b;

typedef struct {
    u8 pad0[0x80];
    u128_4F1068 v80;
    u8 pad90[0xBF8 - 0x90];
    S_4F1068b *pBF8;
    u8 padBFC[0x25C0 - 0xBFC];
    S_4F1068b *p25C0;
    u8 pad25C4[0x25E4 - 0x25C4];
    u8 b25E4;
} S_4F1068;

extern s32 func_003A52A0(s32 a0, s32 a1, S_4F1068b *a2);

s32 func_L01_004F4E70(s32 a0, s32 a1) {
    S_4F1068 *s = ((S_4F1068 *)&D_001A4BE0);
    if (s->b25E4 == 3) {
        if (s->pBF8 != 0) {
            s->pBF8->v10 = s->v80;
            return func_003A52A0(a0, a1, s->pBF8);
        }
    } else {
        return func_003A52A0(a0, a1, s->p25C0);
    }
    return -1;
}
/* localdecomp:end func_L01_004F4E70 */

/* localdecomp:start func_L01_004F4ED0 */
extern s32 D_001A71A0[];
extern void func_L01_004AA760(s32, s32);
void func_L01_004F4ED0(s32 a) {
    func_L01_004AA760(a, D_001A71A0[0]);
}
/* localdecomp:end func_L01_004F4ED0 */

/* localdecomp:start func_L01_004F4EF8 */
extern void func_L01_004F4ED0(s32);
void func_L01_004F4EF8(void) {
    func_L01_004F4ED0(25);
}
/* localdecomp:end func_L01_004F4EF8 */

/* localdecomp:start func_L01_004F4F18 */
extern s32 func_003A52A0(s32 a0, s32 a1, S_4F1068b *a2);
extern St_004ECCD8 D_001A4BE0;
typedef struct {
    u8 pad0[202];
    s16 idx;
    u8 pad1[4];
    u8 active;
    u8 pad2[11];
    s32 id;
    u8 pad3[52];
} Slot;

typedef struct {
    u8 pad[10124];
    s32 slot[9];
    s32 id[9];
} SlotMap;

extern u8 D_001A30B0[];

void func_L01_004F4F18(s32 i, s32 id, s32 x) {
    s32 s;
    Slot *e;

    s = (*(SlotMap *)&D_001A4BE0).slot[i];
    if (s != -1) {
        e = (Slot *)(D_001A30B0 + s * 128);
        if (e->id == id && e->active != 0) {
            goto done;
        }
    }
    (*(SlotMap *)&D_001A4BE0).slot[i] = ((s32 (*)(s32, s32, s32))func_003A52A0)(x, 4, id);
done:
    (*(SlotMap *)&D_001A4BE0).id[i] = id;
}
/* localdecomp:end func_L01_004F4F18 */

/* localdecomp:start func_L01_004F4FC0 */
extern St_004ECCD8 D_001A4BE0;
typedef struct { s16 on; s16 a; s16 b; s16 c; } Slot_4F4FC0;
void func_L01_004F4FC0(s32 a, s32 b, s32 c) {
    u8 *h = (u8 *)&D_001A4BE0;
    Slot_4F4FC0 *s = (Slot_4F4FC0 *)(h + 0x274C);
    s32 i = 0;
    do {
        if (s->on == 0) {
            s->on = 1;
            s->c = c;
            s->b = b;
            s->a = a;
            return;
        }
        i++;
        s++;
    } while (i < 8);
}
/* localdecomp:end func_L01_004F4FC0 */

INCLUDE_ASM("asm/levels", func_L01_004F5010);

/* localdecomp:start func_L01_004F50C8 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x80]; vu0_q pos; vu0_v4 rot;
    u8 padA0[0x36E - 0xA0]; s16 active;
    u8 pad370[0x3C0 - 0x370]; s32 f3C0; s32 flags;
    u8 pad3C8[0xBF8 - 0x3C8]; void *pBF8;
    u8 padBFC[0x1580 - 0xBFC]; f32 f1580;
    u8 pad1584[0x15A0 - 0x1584]; s32 f15A0;
    u8 pad15A4[0x1630 - 0x15A4]; vu0_q q1630;
    u8 pad1640[0x16CC - 0x1640]; f32 f16CC;
    u8 pad16D0[0x25C0 - 0x16D0]; u8 *moby;
    u8 pad25C4[8]; s32 state_type;
    u8 pad25D0[0x26F8 - 0x25D0]; s32 f26F8;
    u8 pad26FC[0x27FC - 0x26FC]; s32 f27FC;
    u8 pad2800[0x2877 - 0x2800]; u8 b2877;
} Hero_004F50C8;
extern St_004ECCD8 D_001A4BE0;
extern vu0_q D_001A4C60[];
extern s32 D_L01_001E2E90[];
void func_L01_004F50C8(vu0_q *pos, vu0_q *rot, s32 state, s32 reset) {
    extern void func_L01_004606A8(s32);
    extern void func_0038D328(void *, void *);
    extern void func_0038D308(void *, void *);
    extern void func_L01_004ED5F8(void);
    extern void func_L01_0044E740(void *);
    extern void func_L01_004EAA80(void);
    extern void func_L01_004E04E8(void);
    extern void func_L01_005003D0(s32, s32);
    extern void func_L01_0050FDD8(s32, s32);
    extern void *func_L01_004E9200(s32);
    extern s32 func_L01_004EDFA8(void *);
    extern void func_003C3938(void *, s32, s32);
    extern void func_L01_004EF840(void);
    extern f32 func_0038CF00(void *, void *);
    extern void func_L01_003F5AC0(s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00412E70(void *, void *, void *, f32, f32);
    extern void func_L01_00513FD8(void);
    extern void func_L01_0043B260(void *);
    Hero_004F50C8 *h;
    Hero_004F50C8 *h2;
    void *p;
    vu0_q v;
    f32 yaw;
    func_L01_004606A8(0);
    h = (Hero_004F50C8 *)&D_001A4BE0;
    h->f26F8 = 0;
    h->pos = *pos;
    *(vu0_q *)(h->moby + 0x10) = *pos;
    *(vu0_q *)&h->rot = *rot;
    func_0038D328(h, &h->rot);
    func_0038D308(h->moby + 0xC0, &h->rot);
    *(f32 *)((u8 *)h + 0x1580) = h->rot.z;
    *(vu0_q *)((u8 *)h + 0x1630) = *(vu0_q *)h;
    *(s32 *)((u8 *)h + 0x15A0) = 0;
    func_L01_004ED5F8();
    func_L01_0044E740((u8 *)h + 0x1B90);
    func_L01_0044E740((u8 *)h + 0x1CE0);
    h->flags &= ~1;
    *(s16 *)((u8 *)h + 0x36E) = 1;
    h->flags &= ~2;
    *(s32 *)((u8 *)h + 0x3C0) = 0;
    *(s32 *)((u8 *)h + 0x27FC) = 0;
    h->b2877 = 0;
    func_L01_004EAA80();
    func_L01_004E04E8();
    if (state != -1) func_L01_005003D0(state, 2);
    func_L01_0050FDD8(h->moby[0x43], h->moby[0x41]);
    p = func_L01_004E9200(0);
    if (func_L01_004EDFA8(p)) func_003C3938(p, 1, 0);
    if (h->state_type == 17) D_L01_001E2E90[0] = 1;
    else D_L01_001E2E90[0] = 0;
    func_L01_004EF840();
    if (func_0038CF00(D_001A4C60, (u8 *)D_001A4C60 + 0x270) < 1.0f)
        D_001A4C60[0] = D_001A4C60[0x27];
    if (reset) func_L01_003F5AC0(0, 1);
    h2 = (Hero_004F50C8 *)((u8 *)D_001A4C60 - 0x80);
    func_0038CF68(&v, (u8 *)D_001A4C60 - 0x60, h2->f16CC);
    yaw = h2->rot.z;
    vec_add_ba(&v, &v, D_001A4C60);
    func_L01_00412E70((u8 *)D_001A4C60 + 0x14C0, &v, h2->pBF8, yaw, 0.0f);
    func_L01_00513FD8();
    func_L01_0043B260(h2->moby);
}
/* localdecomp:end func_L01_004F50C8 */

/* localdecomp:start func_L01_004F52E0 */
#include "vu0.h"
extern u8 D_001A4CD0[];
typedef struct {
    u8 p0[0x1C]; s32 count;
    u8 p20[0x20]; vu0_v4 normal;
} Hit_004F52E0;
extern Hit_004F52E0 D_L01_001EAA00[];
s32 func_L01_004F52E0(f32 scale, f32 minimum, f32 height)
{
    extern f32 func_L01_00511408(void *);
    extern void func_0038CE20(Vec4ED3B8 *, Vec4ED3B8 *, f32);
    extern void func_L01_00511588(void *, void *, f32);
    extern void func_L01_00511178(void *, void *, f32);
    extern void func_L01_00511508(void *, void *, f32);
    extern void func_L01_00511280(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern f32 func_L01_00511848(void *);
    extern void func_L01_004F1190(f32);
    Vec4ED3B8 v[2];
    u8 *h;
    u8 *early;
    u8 *ground;
    Hit_004F52E0 *hit;
    s32 allowed;
    if (func_L01_00511408(D_001A4CD0) == 0.0f) return 0;
    early = D_001A4CD0 - 0xF0;
    if (*(f32 *)(early + 0x2838) > 0.5f && *(s32 *)(early + 0x25CC) != 6 &&
        *(s16 *)(early + 0x214) == 0 && early[0x1479] == 0) return 0;
    ground = (u8 *)&D_001A4BE0;
    if (*(s16 *)(ground + 0x36E) != 0 && *(s32 *)(ground + 0x25C4) != 0x80) return 0;
    func_0038CE20(&v[0], (Vec4ED3B8 *)(ground + 0xF0), scale);
    if (minimum > 0.0f && func_L01_00511408(v) < minimum) {
        func_L01_00511588(v, v, 0.0f);
        func_L01_00511178(v, v, minimum);
    }
    func_L01_00511508(v, v, 0.0f);
    vec_add_ab(v, v, D_001A4C60);
    *(vu0_q *)&v[1] = *(vu0_q *)&v[0];
    if (*((u8 *)D_001A4C60 + 0x2564) == 5) func_L01_00511280(v, v, 1.0f);
    else func_L01_00511280(v, v, 0.3f);
    h = (u8 *)&D_001A4BE0;
    height = -height;
    if (h[0x25E4] == 2) height = -0.7f;
    func_L01_00511280(&v[1], &v[1], height);
    allowed = 1;
    if (func_003D3CB0(v, &v[1], 4, *(void **)(h + 0x25C0), 0) &&
        (hit = D_L01_001EAA00)->count > 0) {
        if (func_L01_00511848(&hit->normal) <= 0.87266463f ||
            *(s32 *)(h + 0x25C4) == 0x80) allowed = 0;
    }
    if (!allowed) return 0;
    func_L01_004F1190(0.0f);
    return 1;
}
/* localdecomp:end func_L01_004F52E0 */

INCLUDE_ASM("asm/levels", func_L01_004F5540);

/* localdecomp:start func_L01_004F5730 */
#include "vu0.h"
typedef struct { vu0_v4 position; f32 pad10, pitch, yaw; } Camera_004F5730;
extern Camera_004F5730 D_L01_001E2A40;
extern vu0_v4 D_L01_001EAA20;
s32 func_L01_004F5730(void) {
    extern s32 func_003D3CB0(void *,void *,s32,void *,s32);
    extern void func_L01_005110E8(void *,s32,f32,f32,f32);
    extern f32 func_0038CED8(void *);
    vu0_v4 target,hit,delta;
    u8 *hero;
    func_00382760(&target,10.0f,D_L01_001E2A40.yaw,-D_L01_001E2A40.pitch);
    vec_add_ab(&target,&target,&D_L01_001E2A40.position);
    hero=(u8 *)&D_001A4BE0;
    if (func_003D3CB0(&D_L01_001E2A40,&target,4,*(void **)(hero+0x25C0),0)) {
    func_L01_005110E8(&hit,1,0.5f,0.0f,0.5f);
    vec_sub_ba(&delta,&D_L01_001EAA20,&hit);
    *(f32 *)(hero+0xBE4)=func_0038D160(delta.x,delta.y);
    *(f32 *)(hero+0xBE8)=func_0038D160(func_0038CED8(&delta),delta.z);
    return 1;
    } else return 0;
}
/* localdecomp:end func_L01_004F5730 */

INCLUDE_ASM("asm/levels", func_L01_004F5810);

INCLUDE_ASM("asm/levels", func_L01_004F5AE8);

/* localdecomp:start func_L01_004F5DC8 */
extern St_004ECCD8 D_001A4BE0;
typedef int s128_4F1FC0 __attribute__((mode(TI)));
typedef int s64_4F1FC0 __attribute__((mode(DI)));

typedef struct {
    u8 pad0[128];
    s128_4F1FC0 q80;
    s128_4F1FC0 q90;
    u8 padA0[2908];
    u8 *unkBFC;
    u8 padC00[6592];
    u8 *unk25C0;
} S_001A4BE0;

extern u8 D_L01_001FDBD0[];
extern s32 D_L01_001FD180[];
extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(u8 *);
extern void func_L01_004ED3F8(s32, s32, u8 *);

void func_L01_004F5DC8(void) {
    s32 type = 5947;
    u8 *m;

    if (D_L01_001FDBD0[6734] != 255 && D_L01_001FD180[D_L01_001FDBD0[6734]] != 0) {
        type = 6734;
    }
    m = func_003C24B0(type, 128);
    ((S_001A4BE0 *)&D_001A4BE0)[0].unkBFC = m;
    if (m != 0) {
        *(s128_4F1FC0 *)(m + 16) = ((S_001A4BE0 *)&D_001A4BE0)[0].q80;
        *(s128_4F1FC0 *)(((S_001A4BE0 *)&D_001A4BE0)[0].unkBFC + 240) = ((S_001A4BE0 *)&D_001A4BE0)[0].q90;
        *(s16 *)(((S_001A4BE0 *)&D_001A4BE0)[0].unkBFC + 50) = 64;
        ((S_001A4BE0 *)&D_001A4BE0)[0].unkBFC[49] = 1;
        *(s32 *)(((S_001A4BE0 *)&D_001A4BE0)[0].unkBFC + 120) = 0;
        *(s64_4F1FC0 *)(((S_001A4BE0 *)&D_001A4BE0)[0].unkBFC + 56) = *(s64_4F1FC0 *)(((S_001A4BE0 *)&D_001A4BE0)[0].unk25C0 + 56);
        func_003C7C38(((S_001A4BE0 *)&D_001A4BE0)[0].unkBFC);
        func_L01_004ED3F8(3, 81, ((S_001A4BE0 *)&D_001A4BE0)[0].unkBFC);
    }
}
/* localdecomp:end func_L01_004F5DC8 */
