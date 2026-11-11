#include "common.h"

/* localdecomp:start func_L01_003068B8 */
typedef int s128_003068B8 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x20];
    s128_003068B8 flame_pos[2]; /* 0x20 */
    u8 pad40[0x4F0 - 0x40];
    f32 u_speed[4];             /* 0x4F0: each flame's u scroll a frame */
    f32 u[4];                   /* 0x500 */
    f32 strength;               /* 0x510 */
    s32 active;                 /* 0x514 */
    s32 phase;                  /* 0x518: 0 growing, 2 holding, 1 falling */
    f32 rate;                   /* 0x51C: the spring's */
    s32 hold;                   /* 0x520: frames */
    u8 pad524[0x530 - 0x524];
} Pool_003068B8;

__asm__(".extern D_L01_001DC5C8, 4");
extern Pool_003068B8 *D_L01_001DC5C8; /* the 10 pools */
extern void func_L01_004CAB30(void *out, void *pos);
extern f32 func_L01_004482A0(f32 *value, f32 target, f32 *rate, f32 gain, f32 damping, f32 cap);
extern s32 func_0038CAD0(void *timer);

/* lava_pools_update: the Lava Gun's 10 burning pools: each one's flames keep to what they
   stand on and their textures scroll; its strength springs to 0.5 (game_spring 0.0024,
   0.00024, at most 0.024 a frame: NTSC's x 1.2), holds 50 frames and springs back to 0. */
void func_L01_003068B8(void)
{
    s32 i;
    s32 j;
    Pool_003068B8 *pool;
    f32 full;
    f32 none;

    for (i = 0; i < 10; i++) {
        /* the slot's address, index first */
        pool = (Pool_003068B8 *)(i * sizeof(Pool_003068B8) + (u32)D_L01_001DC5C8);
        if (pool->active != 1) {
            continue;
        }
        for (j = 0; j < 2; j++) {
            func_L01_004CAB30(&pool->flame_pos[j], &pool->flame_pos[j]);
            pool->u[j] += pool->u_speed[j];
            if (pool->u[j] <= -8.0f) {
                pool->u[j] += 8.0f;
            }
        }
        if (pool->phase == 0) {
            full = 0.5f;
            func_L01_004482A0(&pool->strength, full, &pool->rate, 0.0024f, 0.00024000001f, 0.024f);
            if (pool->strength == full) {
                pool->phase = 2;
                pool->hold = 50;
            }
        } else if (pool->phase == 1) {
            none = 0.0f;
            func_L01_004482A0(&pool->strength, none, &pool->rate, 0.0024f, 0.00024000001f, 0.024f);
            if (pool->strength == none) {
                pool->active = 0;
            }
        } else if (func_0038CAD0(&pool->hold) != 0) {
            pool->phase = 1;
        }
    }
}
/* localdecomp:end func_L01_003068B8 */

INCLUDE_ASM("asm/levels", func_L01_00306A98);

/* localdecomp:start func_L01_00307058 */
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

extern void func_L01_00305C50(S_35A8A0 *);
extern long func_00389598(s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(f32 *);
extern void func_0038D328(f32 *, f32 *);
extern void func_0038CE20(f32 *, f32 *, f32);
extern void func_003D2DA0(S_35A8A0 *, f32 *, s32);

void func_L01_00307058(s32 unused, f32 *pos, f32 *dir, s32 color, f32 scale) {
    S_35A8A0 s;

    func_L01_00305C50(&s);
    s.x50 = 0;
    s.x5C = 1.0f;
    s.x60 = 1.0f;
    s.x68 = 1.0f;
    s.x6C = 1.0f;
    s.x54 = 0;
    s.x58 = 0;
    s.x64 = 0;
    s.x78 = func_00389598(11);
    s.x80 = 0xFF9000000260L;
    s.x88 = 0x8000000048L;
    s.x70 = 0;
    s.c4C = color;
    s.c48 = color;
    s.c44 = color;
    s.c40 = color;
    s.rot[3] = 0.0f;
    s.rot[2] = func_0038D160(dir[0], dir[1]);
    s.rot[1] = -func_0038D160(func_0038CED8(dir), dir[2]);
    s.rot[0] = 0.0f;
    func_0038D328(s.r[0], s.rot);
    s.r[3][3] = 1.0f;
    s.r[3][0] = pos[0];
    s.r[3][1] = pos[1];
    s.r[3][2] = pos[2];
    func_0038CE20(s.m[0], s.m[0], scale);
    func_0038CE20(s.m[1], s.m[1], scale);
    func_0038CE20(s.m[2], s.m[2], scale);
    func_0038CE20(s.m[3], s.m[3], scale);
    func_003D2DA0(&s, s.r[0], 0);
}
/* localdecomp:end func_L01_00307058 */

INCLUDE_ASM("asm/levels", func_L01_003071C8);

INCLUDE_ASM("asm/levels", func_L01_00307858);

INCLUDE_ASM("asm/levels", func_L01_00308238);

INCLUDE_ASM("asm/levels", func_L01_003082D0);

/* localdecomp:start func_L01_003083E8 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L01_003083E8(s32 a0, f32 *e, s32 n)
{
    s32 i;
    f32 *p;

    for (i = 0; i < n; i++) {
        p = &e[i * 32];
        p[0] = func_0038DAB8(p[0], p[3]);
        p[1] = func_0038DAB8(p[1], p[4]);
        p[2] = func_0038DAB8(p[2], p[5]);
        p[9] = func_0038DAB8(p[9], p[12]);
        p[10] = func_0038DAB8(p[10], p[13]);
        p[11] = func_0038DAB8(p[11], p[14]);
        p[20] = func_0038D098(p[0]) * p[6];
        p[21] = func_0038D0B0(p[1]) * p[7];
        p[22] = -func_0038D0B0(p[2]) * p[8];
        p[24] = func_0038D098(p[9]) * p[15];
        p[25] = func_0038D0B0(p[10]) * p[16];
        p[26] = -func_0038D0B0(p[11]) * p[17];
    }
}
/* localdecomp:end func_L01_003083E8 */

INCLUDE_ASM("asm/levels", func_L01_00308508);

LINKER_REMNANT("asm/levels", func_L01_003086C8);

INCLUDE_ASM("asm/levels", func_L01_003086D0);

INCLUDE_ASM("asm/levels", func_L01_00308808);

/* localdecomp:start func_L01_00308848 */
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_003D9508(s32, s32, s32, s32, f32, f32, f32);

void func_L01_00308848(s32 unused, s32 target, u32 color, s32 n, f32 scale) {
    f32 size;
    color |= func_00382498(n >> 1, n) << 24;
    size = func_003824E0(scale * 0.75f, scale);
    size = size + size;
    func_003D9508(target, 44, color, 1, size, 0.08f, func_00382538());
}
/* localdecomp:end func_L01_00308848 */

INCLUDE_ASM("asm/levels", func_L01_003088D8);

/* localdecomp:start func_L01_00308D50 */
typedef struct {
    f32 v[4][4];
    u8 pad40[0x10];
    f32 w[4][2];
    unsigned long d70;
    u8 pad78[8];
    unsigned long d80;
} Obj317488;

void func_L01_00308D50(Obj317488 *o) {
    o->d80 = 0xFF9000000260;
    o->d70 = 0;
    o->w[0][0] = 0;
    o->w[1][0] = 0;
    o->w[2][0] = 1.0f;
    o->w[3][0] = 1.0f;
    o->w[0][1] = 0;
    o->w[1][1] = 1.0f;
    o->w[2][1] = 0;
    o->w[3][1] = 1.0f;
    o->v[0][2] = -2.0f;
    o->v[1][2] = 2.0f;
    o->v[2][2] = -2.0f;
    o->v[3][2] = 2.0f;
    o->v[0][1] = -2.0f;
    o->v[1][1] = -2.0f;
    o->v[2][1] = 2.0f;
    o->v[3][1] = 2.0f;
    o->v[0][0] = 0;
    o->v[1][0] = 0;
    o->v[2][0] = 0;
    o->v[3][0] = 0;
    o->v[0][3] = 1.0f;
    o->v[1][3] = 1.0f;
    o->v[2][3] = 1.0f;
    o->v[3][3] = 1.0f;
}
/* localdecomp:end func_L01_00308D50 */

INCLUDE_ASM("asm/levels", func_L01_00308DE0);

INCLUDE_ASM("asm/levels", func_L01_00308E88);

INCLUDE_ASM("asm/levels", func_L01_003090E0);

INCLUDE_ASM("asm/levels", func_L01_003091A8);

/* localdecomp:start func_L01_003094A0 */
typedef int s128_003094A0 __attribute__((mode(TI)));
typedef union {
    s128_003094A0 q;
    f32 f[4];
} Dir_003094A0;
/* struct CameraVolumeSlot (structs/camera.h) */
typedef struct {
    f32 distance;
    f32 height;
    f32 look_height;
    f32 tilt;
    f32 fov;
    f32 drag;
    u8 look_blend;
    u8 look_blend2;
    s16 stick_lock;
    u8 priority;
    u8 in_use;
    u8 steer;
    u8 steer_idle;
    Dir_003094A0 direction;
    s16 rest_timer;
    s16 rest_frames;
} VolumeSlot_003094A0;
/* struct CameraVolumePvars (structs/camera.h) */
typedef struct {
    s32 cuboid;
    f32 distance;
    f32 height;
    f32 look_height;
    f32 tilt;
    f32 fov;
    f32 drag;
    s16 stiff_look;
    s16 stick_lock;
    u8 priority;
    u8 in_use;
    u8 steer;
    u8 steer_idle;
    s16 rest_timer;
    s16 rest_frames;
    s32 inside;
    VolumeSlot_003094A0 *slot;
    Dir_003094A0 direction;
    s32 group;
} VolumePvars_003094A0;

/* camera_volume_fill: copies a camera volume moby's pvars that are set (-1 or 0 meaning
   unset) into the follow camera's override slot it holds. */
void func_L01_003094A0(u8 *volume)
{
    VolumePvars_003094A0 *pv = *(VolumePvars_003094A0 **)(volume + 0x68);
    f32 unset = -1.0f;

    if (pv->distance != unset) {
        pv->slot->distance = pv->distance;
    }
    if (pv->height != unset) {
        pv->slot->height = pv->height;
    }
    if (pv->look_height != unset) {
        pv->slot->look_height = pv->look_height;
    }
    if (pv->tilt != unset) {
        pv->slot->tilt = pv->tilt;
    }
    if (pv->fov != unset) {
        pv->slot->fov = pv->fov;
    }
    if (pv->drag != unset) {
        pv->slot->drag = pv->drag;
    }
    if (pv->stiff_look != -1) {
        pv->slot->look_blend = pv->stiff_look;
    }
    if (pv->stick_lock != -1) {
        pv->slot->stick_lock = pv->stick_lock;
    }
    if (pv->priority != 0) {
        pv->slot->priority = pv->priority;
    }
    if (pv->in_use != 0) {
        pv->slot->in_use = pv->in_use;
    }
    if (pv->steer != 0) {
        pv->slot->steer = pv->steer;
    }
    if (pv->steer_idle != 0) {
        pv->slot->steer_idle = pv->steer_idle;
    }
    if (pv->rest_timer != -1) {
        pv->slot->rest_timer = pv->rest_timer;
    }
    if (pv->rest_frames != -1) {
        pv->slot->rest_frames = pv->rest_frames;
    }
    if (pv->direction.f[0] != unset) {
        pv->slot->direction.q = pv->direction.q;
    }
}
/* localdecomp:end func_L01_003094A0 */

/* localdecomp:start func_L01_00309628 */
extern u8 D_001A4C60[];
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern s32 func_L01_003F2A50(s32, s32);
extern void func_L01_003F2AF8(s32, s32);
extern void func_L01_003094A0(u8 *);

void func_L01_00309628(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 104);
    if (func_00382380(D_001A4C60, p[0], 0) != 0 && p[10] == 0) {
        if (func_L01_00445AD0(p[16], -1, 0) != 0) {
            p[11] = func_L01_003F2A50(0, 5);
            p[10] = 1;
            func_L01_003094A0(a0);
            return;
        }
    }
    if (p[10] != 0) {
        if (func_00382380(D_001A4C60, p[0], 0) == 0 || func_L01_00445AD0(p[16], -1, 0) == 0) {
            func_L01_003F2AF8(0, p[11]);
            p[10] = 0;
        }
    }
}
/* localdecomp:end func_L01_00309628 */

INCLUDE_ASM("asm/levels", func_L01_00309708);

/* localdecomp:start func_L01_00309B70 */
void func_L01_00309B70(u8 *a) {
    a[32] = 3;
}
/* localdecomp:end func_L01_00309B70 */

/* localdecomp:start func_L01_00309B80 */
typedef int s128_00309B80 __attribute__((mode(TI)));
typedef struct {
    s128_00309B80 velocity; /* u a frame */
    u8 pad10[0x10];
    s128_00309B80 start_velocity;
    u8 pad30[4];
    s32 fly_ticks;          /* 0x34 */
    u8 pad38[8];
    s32 level;              /* 0x40 */
    s32 gun_class;          /* 0x44 */
    u8 pad48[4];
    f32 x4C;
    s32 x50;
    s32 x54;
    s32 x58;
    s32 light;              /* 0x5C */
} StormVars_00309B80;

__asm__(".extern D_L01_001DC630, 4");
extern s32 D_L01_001DC630;
extern u8 D_001A4BE0[];
extern u8 *func_003C24B0(s32, s32);
extern f32 func_0038CEA8(void *);
extern void func_L01_004CAC78(f32 speed, f32 range, f32 max_angle, void *out, void *from);
extern s32 func_L01_004C85C8(u8 *ball, s32 a1, f32 x, f32 y, f32 z);
extern s32 func_L01_00424CB0(void *pos, f32 radius, f32 x, f32 r, f32 g, f32 b);
extern f32 func_00382538(void);
extern void func_0038D308(void *matrix, void *rotation);

/* storm_ball_spawn: throws the Plasma Storm's ball (class 0x9A9) from pos at velocity (1/3
   u a frame along the aim), for 100 frames (120 at 60 Hz); in the aiming camera modes the
   velocity is bent toward the aim point. A light and a random spin go with it. */
u8 *func_L01_00309B80(u8 *gun, s32 level, s128_00309B80 *pos, s128_00309B80 *velocity)
{
    u8 *ball = func_003C24B0(0x9A9, 0x80);
    StormVars_00309B80 *vars;
    f32 one;
    f32 zero;

    if (ball != 0) {
        ball[0x30] = 0xFF;
        *(u16 *)(ball + 0x32) = 0x1FF;
        *(u16 *)(ball + 0x34) |= 0x100;
        vars = *(StormVars_00309B80 **)(ball + 0x68);
        vars->gun_class = *(s16 *)(gun + 0xAA);
        vars->level = level;
        vars->fly_ticks = 100;
        vars->x4C = 0.01f;
        *(s128_00309B80 *)(ball + 0x10) = *pos;
        /* the hero's camera mode (hero + 0x16B0): not the follow camera */
        if (*(s32 *)(D_001A4BE0 + 0x16B0) != 0) {
            /* within 35 u, turned at most 80 degrees */
            func_L01_004CAC78(func_0038CEA8(velocity), 35.0f, 1.3962634f, velocity, ball + 0x10);
        }
        vars->velocity = *velocity;
        one = 1.0f;
        zero = 0.0f;
        vars->start_velocity = *velocity;
        vars->x50 = func_L01_004C85C8(ball, 0, one, one, one);
        vars->x54 = 0;
        vars->x58 = 0;
        ball[0x20] = 0;
        D_L01_001DC630++;
        /* a light in (0.25, 0.14, 1.0) */
        vars->light = func_L01_00424CB0(ball + 0x10, zero, zero, 0.25f, 0.14f, one);
        *(f32 *)(ball + 0xF0) = func_00382538();
        *(f32 *)(ball + 0xF4) = func_00382538();
        *(f32 *)(ball + 0xF8) = func_00382538();
        *(f32 *)(ball + 0xFC) = zero;
        func_0038D308(ball + 0xC0, ball + 0xF0);
    }
    return ball;
}
/* localdecomp:end func_L01_00309B80 */

INCLUDE_ASM("asm/levels", func_L01_00309D28);

INCLUDE_ASM("asm/levels", func_L01_0030A130);

/* localdecomp:start func_L01_0030A140 */
typedef struct {
    u8 pad0[140];
    s32 a;
    u8 pad1[16];
} A00309EA0;

typedef struct {
    u8 pad0[160];
    s32 a;
    u8 pad1[12];
} B00309EA0;

extern A00309EA0 D_L01_0026FD30[30];
extern B00309EA0 D_L01_00270FF0[16];
extern s32 D_L01_001DC630;

void func_L01_0030A140(void) {
    s32 i;
    for (i = 29; i >= 0; i--) {
        D_L01_0026FD30[i].a = 0;
    }
    for (i = 15; i >= 0; i--) {
        D_L01_00270FF0[i].a = 0;
    }
    D_L01_001DC630 = 0;
}
/* localdecomp:end func_L01_0030A140 */

/* localdecomp:start func_L01_0030A198 */
extern void func_003D9508(s32, s32, s32, s32, f32, f32, f32);
extern void func_003A9440(int, long);
extern int func_00382498(int, int);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_L01_0030AA38(void *);
extern void func_L01_0030B818(void *);

void func_L01_0030A198(u8 *m) {
    u8 *p = *(u8 **)(m + 104);

    func_003A9440(71, 0x53001);
    ((void (*)(void *, int, int, int, f32, f32, f32))func_003D9508)(m + 16, 44, (func_00382498(128, 200) << 24) | 0x72FF, 1,
                  func_003824E0(0.38500002f, 0.415f) * *(f32 *)(p + 76), -0.01f, func_00382538());
    ((void (*)(void *, int, int, int, f32, f32, f32))func_003D9508)(m + 16, 45, (func_00382498(4, 40) << 24) | 0xDDB973, 1,
                  *(f32 *)(p + 76) * 1.225f, 0.0f, func_00382538());
    ((void (*)(void *, int, int, int, f32, f32, f32))func_003D9508)(m + 16, 41, (func_00382498(4, 40) << 24) | 0xDDB973, 1,
                  *(f32 *)(p + 76) * 0.6f, 0.0f, func_00382538());
    ((void (*)(void *, int, int, int, f32, f32, f32))func_003D9508)(m + 16, 42, (func_00382498(4, 45) << 24) | 0xDDB973, 1,
                  func_003824E0(0.975f, 1.025f) * *(f32 *)(p + 76), 0.0f, func_00382538());
    ((void (*)(void *, int, int, int, f32, f32, f32))func_003D9508)(m + 16, 42, (func_00382498(4, 45) << 24) | 0xDDB973, 1,
                  func_003824E0(0.975f, 1.025f) * *(f32 *)(p + 76), 0.0f, func_00382538());
    func_L01_0030AA38(m);
    func_L01_0030B818(m);
    func_003A9440(71, 0x5360B);
}
/* localdecomp:end func_L01_0030A198 */

INCLUDE_ASM("asm/levels", func_L01_0030A3E8);

INCLUDE_ASM("asm/levels", func_L01_0030A670);

INCLUDE_ASM("asm/levels", func_L01_0030AA38);

/* localdecomp:start func_L01_0030AB70 */
void func_L01_0030AB70(u8 *p)
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
/* localdecomp:end func_L01_0030AB70 */

INCLUDE_ASM("asm/levels", func_L01_0030ABF8);

INCLUDE_ASM("asm/levels", func_L01_0030AD10);

INCLUDE_ASM("asm/levels", func_L01_0030AED8);

INCLUDE_ASM("asm/levels", func_L01_0030AF18);

INCLUDE_ASM("asm/levels", func_L01_0030B400);

INCLUDE_ASM("asm/levels", func_L01_0030B670);

INCLUDE_ASM("asm/levels", func_L01_0030B818);

INCLUDE_ASM("asm/levels", func_L01_0030B880);

INCLUDE_ASM("asm/levels", func_L01_0030B9C8);

INCLUDE_ASM("asm/levels", func_L01_0030BF20);

INCLUDE_ASM("asm/levels", func_L01_0030C1B8);

/* localdecomp:start func_L01_0030C860 */
void func_L01_0030C860(u8 *a) {
    a[32] = 4;
}
/* localdecomp:end func_L01_0030C860 */

LINKER_REMNANT("asm/levels", func_L01_0030C870);

INCLUDE_ASM("asm/levels", func_L01_0030C878);

INCLUDE_ASM("asm/levels", func_L01_0030CB20);

/* localdecomp:start func_L01_0030CEB8 */
extern u8 *D_L01_001E1724;
extern void func_L01_0030DF88(u8 *, u8 *);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern void func_L01_0030DAD0(u8 *, s32, s32, s32, s32, f32, f32);

void func_L01_0030CEB8(u8 *m) {
    s32 off = 0;
    s32 i = 11;
    u8 *e;
    s32 a;

    do {
        e = (u8 *)(off + (s32)D_L01_001E1724);
        i--;
        off += 160;
        if (*(u8 **)(e + 140) == m) {
            func_L01_0030DF88(m, e);
            if (*(s32 *)(e + 148) == 0) {
                a = func_00382498(80, 96);
                func_L01_0030DAD0(e + 48, 0x103080, a, 49, 2, 0.5f, func_00382538());
                a = func_00382498(80, 96);
                func_L01_0030DAD0(e + 48, 0xFFFFFF, a, 49, 2, 0.3f, func_00382538());
            }
        }
    } while (i >= 0);
}
/* localdecomp:end func_L01_0030CEB8 */

/* localdecomp:start func_L01_0030CFC0 */
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
extern S_0030CD20 *D_L01_001E1720;
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(S_0030CD20 *, S_0030CD20 *, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_0013D3E0(void);
void func_L01_0030CFC0(s32 a0) {
    S_0030CD20 *p;
    s32 i;
    s32 v;
    for (i = 0; i < 64; i++) {
        p = &D_L01_001E1720[i];
        if (p->w16 == 0) {
            p->v[0] = func_003824E0(-1.0f, 1.0f);
            p->v[1] = func_003824E0(-1.0f, 1.0f);
            p->v[2] = func_003824E0(-1.0f, 1.0f);
            func_0038CF68(p, p, p->f20);
            v = func_00382498(20, 50);
            p->w24 = v;
            p->w28 = v;
            p->f32_ = func_003824E0(-1.0f, 1.0f);
            p->w16 = a0;
            p->w36 = 0;
            p->f40 = (func_0013D3E0() & 1) ? -1.0f : 1.0f;
            p->f44 = 1.0f;
            p->f20 = func_003824E0(0.7f, 0.9f);
            return;
        }
    }
}
/* localdecomp:end func_L01_0030CFC0 */

INCLUDE_ASM("asm/levels", func_L01_0030D0D8);

INCLUDE_ASM("asm/levels", func_L01_0030D258);

INCLUDE_ASM("asm/levels", func_L01_0030D288);

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

INCLUDE_ASM("asm/levels", func_L01_0030D678);

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

INCLUDE_ASM("asm/levels", func_L01_0030D6B8);

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

INCLUDE_ASM("asm/levels", func_L01_0030D7A8);

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

INCLUDE_ASM("asm/levels", func_L01_0030DAD0);

INCLUDE_ASM("asm/levels", func_L01_0030DC38);

INCLUDE_ASM("asm/levels", func_L01_0030DF88);

INCLUDE_ASM("asm/levels", func_L01_0030E158);

INCLUDE_ASM("asm/levels", func_L01_0030E198);
