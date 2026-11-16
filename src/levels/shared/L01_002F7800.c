#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_002F7800 */
void func_L01_002F7800(void) {
}
/* localdecomp:end func_L01_002F7800 */

/* localdecomp:start func_L01_002F7808 */
typedef struct {
    float a[4];
    float b[4];
} Pair_002F7888;
typedef struct {
    u8 pad[16];
    float f;
    u8 pad2[8];
} Src_002F7888;
__asm__(".extern D_L01_001DC2C0, 4");
extern s32 D_L01_001DC2C0;
extern Pair_002F7888 D_L01_0026E050[];
extern Src_002F7888 D_L01_002BE708[];
extern void func_0038D750(float *, s32, float);
void func_L01_002F7808(void) {
    s32 i;
    if (D_L01_001DC2C0 == 0) {
        for (i = 0; i < 10; i++) {
            func_0038D750(D_L01_0026E050[i].a, 0, D_L01_002BE708[i].f);
            func_0038D750(D_L01_0026E050[i - 1].b, 0, -D_L01_002BE708[i].f);
        }
        D_L01_001DC2C0 = 1;
    }
}
/* localdecomp:end func_L01_002F7808 */

INCLUDE_ASM("asm/levels", func_L01_002F78B0);

INCLUDE_ASM("asm/levels", func_L01_002F88E0);

INCLUDE_ASM("asm/levels", func_L01_002F8AA8);

INCLUDE_ASM("asm/levels", func_L01_002F8D40);

/* localdecomp:start func_L01_002F8F10 */
void func_L01_002F8F10(void) {

}
/* localdecomp:end func_L01_002F8F10 */

LINKER_REMNANT("asm/levels", func_L01_002F8F18);

INCLUDE_ASM("asm/levels", func_L01_002F8F20);

INCLUDE_ASM("asm/levels", func_L01_002F9310);

/* localdecomp:start func_L01_002F94F8 */
typedef struct {
    u8 pad[0xAA];
    u16 f_AA;
} S_002F94F8;

s32 func_L01_002F94F8(S_002F94F8 *p) {
    u16 v = p->f_AA;
    if ((u32)(v - 13) < 7) {
        return (s16)v - 13;
    }
    switch ((s16)v) {
    case 7516:
        return 7;
    case 7517:
        return 8;
    case 7077:
        return 9;
    default:
        return 0;
    }
}
/* localdecomp:end func_L01_002F94F8 */

/* localdecomp:start func_L01_002F9578 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_2F9578;

typedef struct {
    Vec_2F9578 origin; /* 0x00: the spawner's second point (explosion_spawn: the blast raised) */
    void *owner;       /* 0x10: the moby it is for, or 0 */
    s32 life;          /* 0x14: ticks it lives */
    f32 scale;         /* 0x18: its full scale */
    s16 timer;         /* 0x1C: ticks left */
    s16 opacity;       /* 0x1E: its opacity while it holds */
} DomeVars_2F9578;

typedef struct {
    u8 pad_0[0x10];
    Vec_2F9578 position; /* 0x10 */
    u8 state;            /* 0x20 */
    u8 pad_21[0x23 - 0x21];
    u8 opacity;          /* 0x23 */
    u8 pad_24[0x2C - 0x24];
    f32 scale;           /* 0x2C */
    u8 update_dist;      /* 0x30: names for 0x30-0x32 from Horizon Private Server's libuya */
    u8 drawn;            /* 0x31 */
    s16 draw_dist;       /* 0x32 */
    u8 pad_34[0x68 - 0x34];
    DomeVars_2F9578 *vars; /* 0x68 */
    u8 pad_6C[0xF0 - 0x6C];
    Vec_2F9578 rotation; /* 0xF0: angles x, y, z */
} DomeMoby_2F9578;

extern DomeMoby_2F9578 *func_003C24B0_002F9578(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern void func_003C7C38(u8 *);

/* explosion_dome_spawn: spawns the explosions' dome (class 0x70) at place, at its class's scale
 * times factor, turned at random on all three axes, tinted (r, g, b), for life ticks. */
DomeMoby_2F9578 *func_L01_002F9578(f32 factor, void *owner, Vec_2F9578 *place, Vec_2F9578 *origin,
                                   s32 life, u8 r, u8 g, u8 b, u8 opacity)
{
    DomeMoby_2F9578 *moby;
    DomeVars_2F9578 *vars;
    Vec_2F9578 rotation;

    moby = func_003C24B0_002F9578(0x70, 0x80);
    if (moby != 0) {
        vars = moby->vars;
        {
            Vec_2F9578 turn = { 0 }; /* -pi to pi on each axis */
            turn.x = func_003824E0(-3.1415927f, 3.1415927f);
            turn.y = func_003824E0(-3.1415927f, 3.1415927f);
            turn.z = func_003824E0(-3.1415927f, 3.1415927f);
            rotation = turn;
        }
        moby->state = 0;
        moby->opacity = opacity;
        moby->update_dist = 0xFF;
        moby->draw_dist = 0x1FF;
        moby->drawn = 1;
        func_L01_0043B9E8((u8 *)moby, r, g, b);
        vars->scale = moby->scale * factor;
        moby->scale = 0.0f;
        vars->owner = owner;
        moby->position = *place;
        vars->origin = *origin;
        moby->rotation = rotation;
        vars->life = life;
        vars->timer = vars->life - 3; /* it starts with 3 ticks gone */
        moby->scale = (f32)(life - vars->timer) * vars->scale / (f32)life;
        vars->opacity = opacity;
        func_003C7C38((u8 *)moby);
    }
    return moby;
}
/* localdecomp:end func_L01_002F9578 */

/* localdecomp:start func_L01_002F9738 */
typedef struct {
    u8 pad_0[0x14];
    s32 life;    /* 0x14: ticks it lives */
    f32 scale;   /* 0x18: its full scale */
    s16 timer;   /* 0x1C: ticks left */
    s16 opacity; /* 0x1E: its opacity while it holds */
} DomeVars_2F9738;

typedef struct {
    u8 pad_0[0x23];
    u8 opacity;  /* 0x23 */
    u8 pad_24[0x2C - 0x24];
    f32 scale;   /* 0x2C */
    u8 pad_30[0x68 - 0x30];
    DomeVars_2F9738 *vars; /* 0x68 */
    u8 pad_6C[0xF0 - 0x6C];
    f32 rotation[3]; /* 0xF0: angles x, y, z */
} DomeMoby_2F9738;

extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CB00(void *p);
extern void func_003C2880(void *);

/* explosion_dome_update: the explosions' dome (class 0x70) grows to its scale over its life,
 * turns on all three axes and fades over the last half of its life. */
void func_L01_002F9738(DomeMoby_2F9738 *moby)
{
    DomeVars_2F9738 *vars = moby->vars;
    f32 turn = 0.06283186f; /* 2 pi / 100 rad (3.6 degrees) a frame: NTSC-U turns 3 degrees at 60 Hz */
    s32 half;

    moby->scale = (f32)(vars->life - vars->timer) * vars->scale / (f32)vars->life;
    moby->rotation[0] = func_0038DAB8(moby->rotation[0], turn);
    moby->rotation[1] = func_0038DAB8(moby->rotation[1], turn);
    moby->rotation[2] = func_0038DAB8(moby->rotation[2], turn);
    if (func_0038CB00(&vars->timer)) {
        func_003C2880(moby);
        return;
    }
    half = vars->life / 2;
    if (vars->timer < half) {
        moby->opacity = vars->timer * vars->opacity / half;
    }
}
/* localdecomp:end func_L01_002F9738 */

INCLUDE_ASM("asm/levels", func_L01_002F9830);

/* localdecomp:start func_L01_002F98F8 */
typedef int Q_002F98F8 __attribute__((mode(TI)));
u8 *func_L01_002F98F8(Q_002F98F8 *position, Q_002F98F8 *origin) {
    extern s32 func_L01_004C85C8(u8 *, s32, f32, f32, f32);
    u8 *moby = (u8 *)func_003C24B0(0x79, 0x80);
    u8 *vars;
    if (moby) {
        moby[0x30] = 0xFF;
        *(s16 *)(moby + 0x32) = 0x1FF;
        moby[0x31] = 1;
        moby[0x20] = 0;
        vars = *(u8 **)(moby + 0x68);
        *(Q_002F98F8 *)(moby + 0x10) = *position;
        *(Q_002F98F8 *)vars = *origin;
        *(s32 *)(vars + 0x14) = 0;
        *(s32 *)(vars + 0x10) = 25;
        *(s32 *)(vars + 0x18) = 250;
        *(f32 *)(moby + 0xF0) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(moby + 0xF4) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(moby + 0xF8) = func_003824E0(-3.1415927f, 3.1415927f);
        *(s32 *)(moby + 0xFC) = 0;
        func_003C7C38(moby);
        *(s32 *)(vars + 0x1C) = func_L01_004C85C8(moby, 0, 1.0f, 1.0f, 1.0f);
    }
    return moby;
}
/* localdecomp:end func_L01_002F98F8 */

INCLUDE_ASM("asm/levels", func_L01_002F9A18);

INCLUDE_ASM("asm/levels", func_L01_002F9B08);

INCLUDE_ASM("asm/levels", func_L01_002F9F20);

INCLUDE_ASM("asm/levels", func_L01_002FA1F8);

INCLUDE_ASM("asm/levels", func_L01_002FAAA0);

INCLUDE_ASM("asm/levels", func_L01_002FB208);

INCLUDE_ASM("asm/levels", func_L01_002FB2F0);

/* localdecomp:start func_L01_002FB5A8 */
extern s32 func_00382468(s32);
extern f32 func_003C3EC8(u8 *position, f32 *out);
extern void func_0038CE20(f32 *, f32 *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00468678(u8 *position, f32 *velocity, s32 colour, f32 size, f32 f13);

/* One frame in four on average, a bubble (particle_spawn_bubble, type 0x22) at the moby, moving
 * at a quarter of the vector its vars start with; func_003C3EC8's result (it also writes the
 * buffer, which the scale then overwrites) goes to the bubble as its f13. */
void func_L01_002FB5A8(u8 *moby)
{
    f32 velocity[4];
    f32 got;
    u8 *vars = *(u8 **)(moby + 0x68);

    if (func_00382468(4) != 0) {
        return;
    }
    got = func_003C3EC8(moby + 0x10, velocity);
    func_0038CE20(velocity, (f32 *)vars, 0.25f);
    func_L01_00468678(moby + 0x10, velocity, 0x88A0A0A0, func_003824E0(0.05f, 0.1f) * 210000.0f, got);
}
/* localdecomp:end func_L01_002FB5A8 */

INCLUDE_ASM("asm/levels", func_L01_002FB660);

INCLUDE_ASM("asm/levels", func_L01_002FB7D8);

INCLUDE_ASM("asm/levels", func_L01_002FBB10);

INCLUDE_ASM("asm/levels", func_L01_002FBCD0);

INCLUDE_ASM("asm/levels", func_L01_002FC3E8);

/* localdecomp:start func_L01_002FC8A8 */
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
} S_2FC880b;

typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x30 - 0x21];
    u8 b30;
    u8 b31;
    s16 h32;
    u8 pad34[0x68 - 0x34];
    S_2FC880b *p68;
} S_2FC880;

extern S_2FC880 *func_003C24B0(s32 a0, s32 a1);

S_2FC880 *func_L01_002FC8A8(s32 a0) {
    S_2FC880 *p = func_003C24B0(167, 128);
    if (p != 0) {
        S_2FC880b *q = p->p68;
        q->w4 = a0;
        q->w0 = 0;
        q->w8 = 0;
        q->wC = 0;
        p->b30 = 255;
        p->h32 = 126;
        p->b31 = 0;
        p->b20 = 0;
    }
    return p;
}
/* localdecomp:end func_L01_002FC8A8 */

INCLUDE_ASM("asm/levels", func_L01_002FC910);

INCLUDE_ASM("asm/levels", func_L01_002FCDC0);

/* localdecomp:start func_L01_002FD090 */
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, float);
void func_L01_002FD090(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (*(s32 *)(p + 36) != 0) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_002FD090 */

/* localdecomp:start func_L01_002FD0C8 */
#include "vu0.h"
__asm__(".extern D_L01_001DC434, 4");
extern f32 D_L01_001DC434;
extern vu0_q D_L01_001E16C0[1] __attribute__((section(".sdata")));
void func_L01_002FD0C8(u8 *p) {
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern u32 func_0038DBD8(u32, u32, f32);
    extern void func_L01_002FD818(u8 *);
    extern void func_003D9508(vu0_q *, s32, u32, s32, f32, f32, f32);
    f32 t, a, b, c;
    u32 x, y, z;
    D_L01_001DC434 = func_0038DAB8(D_L01_001DC434, 0.15f);
    t = (func_0038D098(D_L01_001DC434) + 1.0f) * 0.5f;
    a = t * 0.0625f + 0.0625f;
    b = t * 0.19999998807907104f + 0.15f;
    c = t * 0.125f + 0.125f;
    x = func_0038DBD8(0x2F007F00, 0x3F007F00, t);
    y = func_0038DBD8(0x2F7F7F7F, 0x5F7F7F7F, t);
    z = func_0038DBD8(0x10208040, 0x10208040, t);
    func_L01_002FD818(p);
    func_003D9508(D_L01_001E16C0, 0x31, x, 1, c, 0.125f, 0.0f);
    func_003D9508(D_L01_001E16C0, 0x31, y, 1, a, 0.124f, 0.0f);
    func_003D9508(D_L01_001E16C0, 0xB, z, 1, b, 0.123f, 0.0f);
}
/* localdecomp:end func_L01_002FD0C8 */

INCLUDE_ASM("asm/levels", func_L01_002FD288);

/* localdecomp:start func_L01_002FD530 */
typedef struct {
    f32 pos[4], second[4], origin[4], attached[4];
    f32 angle[3], velocity[3], scale[3];
    f32 angle2[3], velocity2[3], scale2[3];
    s32 timer, kind;
    u8 *owner;
    s32 remaining, duration, finished;
} Effect_002FD530;
extern Effect_002FD530 D_L01_0026EAB0[];
extern vu0_q D_L01_001E16C0[1] __attribute__((section(".sdata")));
void func_L01_002FD530(s32 kind) {
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern u8 *func_00382348(u8 *);
    extern void func_L01_00451290(u8 *, f32 *, s32);
    extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
    extern s32 func_0038CAD0(s32 *);
    f32 offset[4] __attribute__((aligned(16)));
    vu0_q *origin = D_L01_001E16C0;
    Effect_002FD530 *base = D_L01_0026EAB0;
    s32 i;
    Effect_002FD530 *p;
    u8 *attachment;
    for (i = 0; i < 3; i++) {
        p = &base[i];
        if (p->kind != kind) continue;
        *(vu0_q *)p->origin = *origin;
        if (p->remaining) {
            p->angle[0] = func_0038DAB8(p->angle[0], p->velocity[0] * 100.0f);
            p->angle[1] = func_0038DAB8(p->angle[1], p->velocity[1] * 100.0f);
            p->angle[2] = func_0038DAB8(p->angle[2], p->velocity[2] * 100.0f);
            p->angle2[0] = func_0038DAB8(p->angle2[0], p->velocity2[0] * 100.0f);
            p->angle2[1] = func_0038DAB8(p->angle2[1], p->velocity2[1] * 100.0f);
            p->angle2[2] = func_0038DAB8(p->angle2[2], p->velocity2[2] * 100.0f);
        } else {
            p->angle[0] = func_0038DAB8(p->angle[0], p->velocity[0] * 50.0f);
            p->angle[1] = func_0038DAB8(p->angle[1], p->velocity[1] * 50.0f);
            p->angle[2] = func_0038DAB8(p->angle[2], p->velocity[2] * 50.0f);
            p->angle2[0] = func_0038DAB8(p->angle2[0], p->velocity2[0] * 50.0f);
            p->angle2[1] = func_0038DAB8(p->angle2[1], p->velocity2[1] * 50.0f);
            p->angle2[2] = func_0038DAB8(p->angle2[2], p->velocity2[2] * 50.0f);
        }
        p->pos[0] = func_0038D098(p->angle[0]) * p->scale[0];
        p->pos[1] = func_0038D0B0(p->angle[1]) * p->scale[1];
        p->pos[2] = -func_0038D0B0(p->angle[2]) * p->scale[2];
        p->second[0] = func_0038D098(p->angle2[0]) * p->scale2[0];
        p->second[1] = func_0038D0B0(p->angle2[1]) * p->scale2[1];
        p->second[2] = -func_0038D0B0(p->angle2[2]) * p->scale2[2];
        if (p->owner) {
            attachment = func_00382348(p->owner);
            if (attachment) {
                func_L01_00451290(p->owner, offset, 1);
                func_0038CE20(offset, offset, *(f32 *)(attachment + 0x10));
                vec_add_ab(p->attached, offset, p->owner + 0x10);
            } else {
                *(vu0_q *)p->attached = *(vu0_q *)(p->owner + 0x10);
            }
            func_0038CDF8(p->attached, p->origin, p->attached, 1.0f - (f32)p->remaining / (f32)p->duration);
        }
        if (func_0038CAD0(&p->remaining)) {
            if (!p->finished) p->finished = 1;
            if (func_0038CAD0(&p->timer)) p->kind = 0;
        }
    }
}
/* localdecomp:end func_L01_002FD530 */

INCLUDE_ASM("asm/levels", func_L01_002FD818);

/* localdecomp:start func_L01_002FD988 */
void func_L01_002FD988(f32 *p) {
    *(long *)(p + 32) = 0x0000FF9000000260L;
    *(long *)(p + 28) = 0;
    p[20] = 0.0f;
    p[21] = 0.0f;
    p[22] = 1.0f;
    p[23] = 0.0f;
    p[24] = 0.0f;
    p[25] = 1.0f;
    p[26] = 1.0f;
    p[27] = 1.0f;
    p[2] = -1.0f;
    p[6] = 1.0f;
    p[10] = -1.0f;
    p[14] = 1.0f;
    p[1] = -1.0f;
    p[5] = -1.0f;
    p[9] = 1.0f;
    p[13] = 1.0f;
    p[0] = 0.0f;
    p[4] = 0.0f;
    p[8] = 0.0f;
    p[12] = 0.0f;
    p[3] = 1.0f;
    p[7] = 1.0f;
    p[11] = 1.0f;
    p[15] = 1.0f;
}
/* localdecomp:end func_L01_002FD988 */

INCLUDE_ASM("asm/levels", func_L01_002FDA10);

/* localdecomp:start func_L01_002FDBD8 */
void func_L01_002FDBD8(f32 (*pts)[4], s32 n) {
    f32 d[4];

    vec_sub_ab(d, pts[n - 2], pts[n - 3]);
    vec_add_ab(pts[n - 1], pts[n - 2], d);
}
/* localdecomp:end func_L01_002FDBD8 */

INCLUDE_ASM("asm/levels", func_L01_002FDC18);

INCLUDE_ASM("asm/levels", func_L01_002FE0A0);

INCLUDE_ASM("asm/levels", func_L01_002FE280);
