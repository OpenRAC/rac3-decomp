#include "common.h"
#include "vu0.h"

typedef struct {
    f32 m[4][4];
    s32 c40, c44, c48, c4C;
    s32 x50, x54, x58;
    f32 x5C, x60;
    s32 x64;
    f32 x68, x6C;
    long x70, x78, x80, x88;
    f32 r[4][4];
    f32 rot[4];
} S_35A8A0;
typedef struct {
    f32 v[4];
    s32 w16;
    f32 f20;
    s32 w24;
    s32 w28;
    f32 f32_;
    s32 w36;
    f32 f40;
    f32 f44;
} S_0030CD20;
typedef int s128_00309B80 __attribute__((mode(TI)));
extern u8 D_001A4C60[];
extern void func_0038CF68(S_0030CD20 *, S_0030CD20 *, f32);
extern long func_00389598(s32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_0038D328(f32 *, f32 *);
extern u8 *func_003C24B0(s32, s32);
extern void func_003D2DA0(S_35A8A0 *, f32 *, s32);
extern s32 func_L01_004C85C8(u8 *ball, s32 a1, f32 x, f32 y, f32 z);
extern void func_L01_004CAC78();
extern u8 *D_L01_001E1724;
extern S_0030CD20 *D_L01_001E1720;

/* localdecomp:start func_L01_0030D258 */
void func_L01_0030D258(s32 a0) {
    s32 i;

    for (i = 0; i < 64; i++) {
        if (D_L01_001E1720[i].w16 == a0) {
            D_L01_001E1720[i].w16 = 0;
        }
    }
}
/* localdecomp:end func_L01_0030D258 */

/* localdecomp:start func_L01_0030D288 */
#include "vu0.h"
extern S_0030CD20 *D_L01_001E1720;
void func_L01_0030D288(void *owner) {
    extern void func_0038CF68(S_0030CD20 *, S_0030CD20 *, f32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_0038D098(f32);
    extern void func_L01_0030DC38(void *,void *,s32,f32,f32,s32,f32,s32,s32);
    vu0_v4 pos;
    S_0030CD20 *p;
    s32 i;
    s32 alpha;
    f32 weight;
    for (i=0; i<64; i++) {
        p=(S_0030CD20 *)(i*sizeof(S_0030CD20)+(u32)D_L01_001E1720);
        if (p->w16 == (s32)owner) {
            *(f32 *)&p->w36=6.2831855f-((f32)p->w24*6.2831855f)/(f32)(p->w28-1);
            func_0038CF68((S_0030CD20 *)&pos,p,p->f20);
            alpha=func_00382498(48,80);
            weight=(func_0038D098(*(f32 *)&p->w36-3.1415927f)+1.0f)*0.5f;
            vec_add_ab(&pos,&pos,(u8 *)owner+0x10);
            func_L01_0030DC38((u8 *)owner+0x10,&pos,0x800000,*(f32 *)(*(u8 **)((u8 *)owner+0x68)+0x18)*0.25f,0.0f,(s32)(alpha*weight),p->f32_,47,2);
        }
    }
}
/* localdecomp:end func_L01_0030D288 */

/* localdecomp:start func_L01_0030D408 */
typedef struct {
    f32 velocity[4];
    s32 life;       /* 0x10: frames */
    s32 slot;       /* 0x14: its place among the 5 */
    f32 radius;     /* 0x18 */
    s32 x1C;
    u8 pad20[0x10];
    s32 sound;      /* 0x30 */
    s32 x34;
    s32 x38;
    s32 level;      /* 0x3C */
    s32 gun_class;  /* 0x40 */
    s32 shadow;     /* 0x44 */
} CoilBall_0030D408;
typedef struct {
    u8 pad0[0x8C];
    s32 used;       /* 0x8C */
    u8 pad90[0x10];
} CoilArc_0030D408;
__asm__(".extern D_L01_001DC650, 4");
__asm__(".extern D_L01_001DC654, 4");
extern s32 D_L01_001DC650;
extern s32 D_L01_001DC654;
extern s32 D_L01_00271AF0[];
extern s32 func_L01_0030D678(void);
extern u8 *func_L01_00457410(u8 *);
/* coil_ball_spawn: the Plasma Coil's ball (class 0xA9B) from pos at velocity x 1.2 (PAL's
   frame), in the first free of 5 slots; none while 4 are out. In the aiming camera modes it
   bends toward the aim point. The first one also clears the sparks' and arcs' slots; each
   ball gets 20 sparks. One pointer holds the gun's vars, read before the once-only test, and
   then the buffer they point to: it conflicts with $a0 that way and gets $v0. */
u8 *func_L01_0030D408(u8 *gun, s32 level, s128_00309B80 *pos, f32 *velocity)
{
    u8 *ball;
    CoilBall_0030D408 *vars;
    f32 at[4];
    s128_00309B80 *place;
    s32 i;
    u8 *buf;
    if (func_L01_0030D678() != 0) {
        return 0;
    }
    for (i = 0; i < 5; i++) {
        if (D_L01_00271AF0[i * 4] == 0) {
            break;
        }
    }
    ball = func_003C24B0(0xA9B, 0x80);
    if (ball != 0) {
        ball[0x20] = 0;
        *(u16 *)(ball + 0x32) = 0xFF;
        ball[0x30] = 0xFF;
        vars = *(CoilBall_0030D408 **)(ball + 0x68);
        place = (s128_00309B80 *)(ball + 0x10);
        *place = *pos;
        *(s128_00309B80 *)at = *place;
        /* its shadow made at the hero, then put where it starts */
        *place = *(s128_00309B80 *)D_001A4C60;
        vars->shadow = func_L01_004C85C8(ball, 0, 1.0f, 1.0f, 1.0f);
        *place = *(s128_00309B80 *)at;
        func_0038CF68((S_0030CD20 *)vars, (S_0030CD20 *)velocity, 1.2f);
        /* the hero's camera mode: not the follow camera */
        if (*(s32 *)(D_001A4C60 + 0x1630) != 0) {
            /* within 35 u, turned at most 80 degrees */
            ((void (*)(void *, void *, f32, f32, f32))func_L01_004CAC78)(vars, place, func_0038CEA8(vars), 35.0f, 1.3962634f);
        }
        /* 133 frames: the US's 160 */
        vars->life = 133;
        vars->sound = 17;
        vars->slot = i;
        D_L01_00271AF0[i * 4] = (s32)ball;
        D_L01_001DC650++;
        vars->radius = 2.5f;
        vars->level = level;
        vars->x1C = 0;
        vars->x34 = 0;
        vars->x38 = 0;
        vars->gun_class = *(s16 *)(gun + 0xAA);
        buf = *(u8 **)(gun + 0x68);
        if (D_L01_001DC654 == 0) {
            buf = *(u8 **)(buf + 8);
            D_L01_001E1720 = (S_0030CD20 *)buf;
            D_L01_001E1724 = func_L01_00457410(buf + 0xC00);
            func_L01_00457410(D_L01_001E1724 + 0x780);
            D_L01_001DC654 = 1;
            for (i = 63; i >= 0; i--) {
                D_L01_001E1720[i].w16 = 0;
            }
            for (i = 0; i < 12; i++) {
                ((CoilArc_0030D408 *)D_L01_001E1724)[i].used = 0;
            }
        }
        for (i = 0; i < 20; i++) {
            func_L01_0030CFC0((s32)ball);
        }
    }
    return ball;
}
/* localdecomp:end func_L01_0030D408 */

/* localdecomp:start func_L01_0030D678 */
__asm__(".extern D_L01_001DC650, 4");
extern s32 D_L01_001DC650;

s32 func_L01_0030D678(void) {
    return D_L01_001DC650 == 4;
}
/* localdecomp:end func_L01_0030D678 */

/* localdecomp:start func_L01_0030D688 */
extern s32 D_L01_00271AF0[];
extern s32 D_L01_001DC650;
void func_L01_0030D688(void) {
    s32 i;
    for (i = 4; i >= 0; i--) {
        D_L01_00271AF0[i * 4] = 0;
    }
    D_L01_001DC650 = 0;
}
/* localdecomp:end func_L01_0030D688 */

/* localdecomp:start func_L01_0030D6B8 */
extern s32 D_L01_00271AF0[];
__asm__(".extern D_L01_001DC650, 4");
extern s32 D_L01_001DC650;
extern void func_L01_0030D258(s32);
extern void func_L01_004C8668(s32);
extern void func_003C2880(void *);

void func_L01_0030D6B8(u8 *obj) {
    u8 *v = *(u8 **)(obj + 0x68);
    s32 i = *(s32 *)(v + 0x14);

    D_L01_001DC650--;
    D_L01_00271AF0[i * 4] = 0;
    ((void (*)(void *))func_L01_0030D258)(obj);
    func_L01_004C8668(*(s32 *)(v + 0x44));
    func_003C2880(obj);
}
/* localdecomp:end func_L01_0030D6B8 */

/* localdecomp:start func_L01_0030D720 */
void func_L01_0030D720(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_0030D720 */

/* localdecomp:start func_L01_0030D7A8 */
#include "vu0.h"
void func_L01_0030D7A8(f32 *out, f32 *start, f32 *end, f32 *control0, f32 *control1, f32 t) {
    f32 t2, t3;
    f32 a, b, c;
    if (t == 0.0f) {
        *(vu0_q *)out = *(vu0_q *)start;
        return;
    }
    if (t == 1.0f) {
        *(vu0_q *)out = *(vu0_q *)end;
        return;
    }
    t2 = t * t;
    t3 = t2 * t;
    a = (control1[0] - end[0]) - (control0[0] - start[0]);
    b = (control0[0] - start[0]) - a;
    c = end[0] - control0[0];
    out[0] = a * t3 + b * t2 + c * t + start[0];
    a = (control1[1] - end[1]) - (control0[1] - start[1]);
    b = (control0[1] - start[1]) - a;
    c = end[1] - control0[1];
    out[1] = a * t3 + b * t2 + c * t + start[1];
    a = (control1[2] - end[2]) - (control0[2] - start[2]);
    b = (control0[2] - start[2]) - a;
    c = end[2] - control0[2];
    out[2] = a * t3 + b * t2 + c * t + start[2];
    out[3] = 0.0f;
}
/* localdecomp:end func_L01_0030D7A8 */

/* localdecomp:start func_L01_0030D8C0 */
extern void func_0038CE20(f32 *, f32 *, f32);
void func_L01_0030D8C0(f32 *m, f32 s) {
    func_0038CE20(m, m, s);
    func_0038CE20(m + 4, m + 4, s);
    func_0038CE20(m + 8, m + 8, s);
    func_0038CE20(m + 12, m + 12, s);
}
/* localdecomp:end func_L01_0030D8C0 */

/* localdecomp:start func_L01_0030D928 */
extern void func_L01_0030DAD0(u8 *, s32, s32, s32, s32, f32, f32);
extern void func_L01_0030CEB8(u8 *m);
extern void func_003A9440(int, long);
extern void func_L01_0030D288(void *);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);

void func_L01_0030D928(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    u8 *q;
    f32 s;

    if (p == 0) {
        return;
    }
    ((void (*)(s32, unsigned long))func_003A9440)(71, 0x53001);
    ((void (*)(void *))func_L01_0030CEB8)(a0);
    func_L01_0030D288(a0);
    q = a0 + 16;
    s = *(f32 *)(p + 24);
    s *= 0.5f;
    ((void (*)(void *, s32, f32, s32, f32, s32, s32))func_L01_0030DAD0)(q, 0x103080, s, func_00382498(80, 96), func_00382538(), 49, 2);
    s = *(f32 *)(p + 24);
    s *= 0.3f;
    ((void (*)(void *, s32, f32, s32, f32, s32, s32))func_L01_0030DAD0)(q, 0xFFFFFF, s, func_00382498(80, 96), func_00382538(), 49, 2);
    s = *(f32 *)(p + 24);
    s *= 0.7f;
    ((void (*)(void *, s32, f32, s32, f32, s32, s32))func_L01_0030DAD0)(q, 0x803010, s, func_00382498(8, 22), func_00382538(), 11, 2);
    s = *(f32 *)(p + 24);
    s *= 0.45f;
    ((void (*)(void *, s32, f32, s32, f32, s32, s32))func_L01_0030DAD0)(q, 0x803010, s, func_00382498(32, 64), func_00382538(), 11, 2);
    ((void (*)(s32, unsigned long))func_003A9440)(71, 0x5360B);
}
/* localdecomp:end func_L01_0030D928 */

/* localdecomp:start func_L01_0030DAD0 */
/* Ported from rac2-decomp rac2-decomp/src/game/003173B0.c:1025-1065. */

void func_L01_0030DAD0(u8 *position, s32 color, s32 resource, s32 mode, s32 flag, f32 scale, f32 alpha)
{
    extern void func_L01_0030D8C0(f32 *, f32);
    extern f32 D_L01_001E2880[];
    extern f32 func_0038CF38(void *, void *);

    unsigned char work[0xE0];
    unsigned int rgba;
    unsigned long mode_bits;
    float first_angle;
    float second_angle;
    float distance;

    func_L01_0030D720(work);
    *(long *)(work + 0x78) = func_00389598(mode);

    mode_bits = ((unsigned long)flag << 2) | 0x0000008000000040UL;
    *(long *)(work + 0x88) = mode_bits;
    *(long *)(work + 0x80) = 0x0000FF9000000260UL;

    rgba = (unsigned int)color + ((unsigned int)resource << 24);
    *(int *)(work + 0x4C) = rgba;
    *(int *)(work + 0x48) = rgba;
    *(int *)(work + 0x44) = rgba;
    *(int *)(work + 0x40) = rgba;
    *(long *)(work + 0x70) = 0;

    *(int *)(work + 0xDC) = 0;
    first_angle = func_0038D160(D_L01_001E2880[0x140 / 4] - *(float *)(position + 0),
                                D_L01_001E2880[0x144 / 4] - *(float *)(position + 4));
    *(float *)(work + 0xD8) = first_angle;

    distance = func_0038CF38(position, &D_L01_001E2880[0x140 / 4]);
    second_angle = func_0038D160(distance, D_L01_001E2880[0x148 / 4] - *(float *)(position + 8));
    *(float *)(work + 0xD0) = alpha;
    *(float *)(work + 0xD4) = -second_angle;

    func_0038D328((f32 *)(work + 0x90), (f32 *)(work + 0xD0));
    *(float *)(work + 0xC0) = *(float *)(position + 0);
    *(float *)(work + 0xC4) = *(float *)(position + 4);
    *(float *)(work + 0xC8) = *(float *)(position + 8);
    *(float *)(work + 0xCC) = 1.0f;
    func_L01_0030D8C0((f32 *)work, scale);
    func_003D2DA0((S_35A8A0 *)work, (f32 *)(work + 0x90), 0);
}
/* localdecomp:end func_L01_0030DAD0 */

INCLUDE_ASM("asm/levels", func_L01_0030DC38);

/* localdecomp:start func_L01_0030DF88 */
#include "vu0.h"
void func_L01_0030DF88(u8 *owner, u8 *arc) {
    extern void func_L01_0030D7A8(void *, void *, void *, void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(S_0030CD20 *, S_0030CD20 *, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_0030E198(u8 *, s32, void *, s32);
    vu0_v4 points[25];
    vu0_v4 first, second, jitter;
    s32 i;
    for (i = 0; i < 24; i++) {
        *(vu0_q *)&first = *(vu0_q *)arc;
        *(vu0_q *)&second = *(vu0_q *)(arc + 0x10);
        vec_add_ab(&first, &first, arc + 0x20);
        vec_add_ba(&second, &second, arc + 0x30);
        func_L01_0030D7A8(&points[i], arc + 0x20, arc + 0x30, &first, &second, (f32)i / 23.0f);
        jitter.w = 0.0f;
        jitter.x = func_003824E0(-0.1f, 0.1f);
        jitter.y = func_003824E0(-0.1f, 0.1f);
        jitter.z = func_003824E0(-0.1f, 0.1f);
        func_0038CF68((S_0030CD20 *)&jitter, (S_0030CD20 *)&jitter, 0.075f);
        vec_add_ab(&points[i], &points[i], &jitter);
    }
    if (*(s32 *)(arc + 0x88) >= 8) {
        func_L01_0030E198(owner, func_00382498(64, 128), points, 25);
    } else {
        func_L01_0030E198(owner, func_00382498(0, 64), points, 25);
    }
}
/* localdecomp:end func_L01_0030DF88 */

/* localdecomp:start func_L01_0030E158 */
void func_L01_0030E158(vu0_v4 *base, s32 i) {
    vu0_v4 tmp;
    vec_sub_ab(&tmp, &base[i - 2], &base[i - 3]);
    vec_add_ab(&base[i - 1], &base[i - 2], &tmp);
}
/* localdecomp:end func_L01_0030E158 */

INCLUDE_ASM("asm/levels", func_L01_0030E198);
