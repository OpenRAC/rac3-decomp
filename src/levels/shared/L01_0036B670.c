#include "common.h"

typedef struct {
    u8 pad0[104];
    u8 *inner;
} Obj3899C0;
typedef struct {
    u8 b[8];
} Pair_371CB8;
typedef struct {
    u8 pad0[16];
    f32 pos[4];
    u8 pad32[4];
    s32 i36;
    s32 i40;
    u8 pad44[4];
    f32 f48;
} Obj_371CB8;

INCLUDE_ASM("asm/levels", func_L01_0036B670);

INCLUDE_ASM("asm/levels", func_L01_0036C828);

INCLUDE_ASM("asm/levels", func_L01_0036CB08);

INCLUDE_ASM("asm/levels", func_L01_0036D018);

INCLUDE_ASM("asm/levels", func_L01_0036D8C8);

/* localdecomp:start func_L01_0036DB20 */
extern s32 D_L01_001E1D18;
extern void func_003C2F58(s32, s32, void *);
extern void func_L01_0036DB78(void *, s32, s32, f32, f32, f32, f32);
void func_L01_0036DB20(s32 a0) {
    u8 buf[16];
    func_003C2F58(a0, 0, buf);
    func_L01_0036DB78(buf, 66, D_L01_001E1D18 * 5, 1.0f, 0.0f, 0.0f, 0.9f);
}
/* localdecomp:end func_L01_0036DB20 */

/* localdecomp:start func_L01_0036DB78 */
extern s32 D_L01_001DD870;
__asm__(".extern D_L01_001DD870, 4");
extern s32 D_L01_001DD878;
__asm__(".extern D_L01_001DD878, 4");
extern s32 D_L01_001DD87C;
__asm__(".extern D_L01_001DD87C, 4");
extern s32 D_L01_001DD880;
__asm__(".extern D_L01_001DD880, 4");
extern s32 D_L01_001DD884;
__asm__(".extern D_L01_001DD884, 4");
extern s32 D_L01_001DD888;
__asm__(".extern D_L01_001DD888, 4");
extern s32 D_L01_001DD88C;
__asm__(".extern D_L01_001DD88C, 4");
extern s32 D_L01_001DD890;
__asm__(".extern D_L01_001DD890, 4");
extern s32 D_L01_001DD894;
__asm__(".extern D_L01_001DD894, 4");
extern s32 D_L01_001DD898;
__asm__(".extern D_L01_001DD898, 4");
extern s32 D_L01_001DD89C;
__asm__(".extern D_L01_001DD89C, 4");
extern s32 D_L01_001DD8A0;
__asm__(".extern D_L01_001DD8A0, 4");
extern s32 D_L01_001DD8A4;
__asm__(".extern D_L01_001DD8A4, 4");
extern s32 D_L01_001DD8A8;
__asm__(".extern D_L01_001DD8A8, 4");
extern s32 D_L01_001DD8CC;
__asm__(".extern D_L01_001DD8CC, 4");
typedef struct {
    u8 pad_0[0x150];
    s16 width;                 /* 0x150: the frame's width */
    s16 height;                /* 0x152: the frame's height */
} Screen_36DB78;

extern s32 D_001D5520;
extern s32 D_001A1ED0[];
extern Screen_36DB78 D_001CFEC0;
extern void func_L01_004C5E28(void);
extern void func_003A9440(s32 code, long value);
extern void func_003D1030(void);
extern long func_00389598(s32 tex);
extern void func_0038B4D0(s32 x0, s32 y0, s32 x1, s32 y1, s32 u0, s32 v0, s32 u1, s32 v1, long colour, long tex);

/* screen_warp_draw: redraws the frame (texture -7) in four mirrored quarters through the warp's
   texture; the Nitro, Flux scope and RY3NO code have copies */
void func_L01_0036DB78(void *buf, s32 tex, s32 alpha, f32 a, f32 b, f32 c, f32 d)
{
    long colour;
    long frame_tex;
    s32 w;
    s32 h;

    func_L01_004C5E28();
    if (D_001D5520) {
        D_L01_001DD8CC = -1;
        D_L01_001DD8A4 = 0xEC;
        D_L01_001DD8A8 = 0xF0;
    }
    func_003A9440(0x4E, (D_001A1ED0[2] >> 13) | 0x1000000 | 0x100000000);
    func_003A9440(0x42, (long)D_L01_001DD87C | ((long)D_L01_001DD880 << 2) | ((long)D_L01_001DD884 << 4) | ((long)D_L01_001DD888 << 6) | 0x8000000000);
    func_003D1030();
    frame_tex = func_00389598(D_L01_001DD870);
    colour = (alpha << 24) | 0x7F7F7F;
    func_0038B4D0(0, 0, (s32)(D_001CFEC0.width * 0.5f), (s32)(D_001CFEC0.height * 0.5f), 0, 0, 0xFF, 0xFF, colour, frame_tex);
    func_0038B4D0(D_001CFEC0.width, 0, -(s32)(D_001CFEC0.width * 0.5f), (s32)(D_001CFEC0.height * 0.5f), 0, 0, 0xFF, 0xFF, colour, frame_tex);
    func_0038B4D0(0, D_001CFEC0.height, (s32)(D_001CFEC0.width * 0.5f), -(s32)(D_001CFEC0.height * 0.5f), 0, 0, 0xFF, 0xFF, colour, frame_tex);
    func_0038B4D0(D_001CFEC0.width, D_001CFEC0.height, -(s32)(D_001CFEC0.width * 0.5f), -(s32)(D_001CFEC0.height * 0.5f), 0, 0, 0xFF, 0xFF, colour, frame_tex);
    func_003A9440(0x42, (long)D_L01_001DD87C | ((long)D_L01_001DD880 << 2) | ((long)D_L01_001DD884 << 4) | ((long)D_L01_001DD888 << 6) | 0x8000000000);
    func_003A9440(0x42, (long)D_L01_001DD88C | ((long)D_L01_001DD890 << 2) | ((long)D_L01_001DD894 << 4) | ((long)D_L01_001DD898 << 6) | 0x8000000000);
    func_0038B4D0(0, 0, D_001CFEC0.width, D_001CFEC0.height, D_L01_001DD89C, D_L01_001DD8A0, D_L01_001DD8A4, D_L01_001DD8A8, D_L01_001DD878, func_00389598(D_L01_001DD8CC));
    func_003A9440(0x4E, 0x1000000 | (D_001A1ED0[2] >> 13));
}
/* localdecomp:end func_L01_0036DB78 */

INCLUDE_ASM("asm/levels", func_L01_0036DEB0);

INCLUDE_ASM("asm/levels", func_L01_0036E120);

INCLUDE_ASM("asm/levels", func_L01_0036E578);

LINKER_REMNANT("asm/levels", func_L01_0036F118);

INCLUDE_ASM("asm/levels", func_L01_0036F120);

INCLUDE_ASM("asm/levels", func_L01_0036F330);

/* localdecomp:start func_L01_0036F9F8 */

extern s32 func_L01_005119E0(s32);
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, f32);

void func_L01_0036F9F8(Obj3899C0 *obj) {
    u8 *p = obj->inner;
    if (*(s32 *)(p + 36) == 0) {
        return;
    }
    if (func_L01_005119E0(-1)) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_0036F9F8 */

INCLUDE_ASM("asm/levels", func_L01_0036FA50);

INCLUDE_ASM("asm/levels", func_L01_0036FF90);

INCLUDE_ASM("asm/levels", func_L01_003706F0);

INCLUDE_ASM("asm/levels", func_L01_00370A48);

/* localdecomp:start func_L01_00371C98 */
void func_L01_00371C98(u8 *a) {
    a[0x20] = 1;
}
/* localdecomp:end func_L01_00371C98 */

INCLUDE_ASM("asm/levels", func_L01_00371CA8);

LINKER_REMNANT("asm/levels", func_L01_00372120);

/* localdecomp:start func_L01_00372128 */
typedef int u128_372128 __attribute__((mode(TI)));
typedef struct {
    u8 pad_0[0x18C];
    s32 first_drawn;           /* 0x18C: set once rotation is kept */
    u128_372128 places[8];     /* 0x190: the ring of kept places */
    u128_372128 turns[8];      /* 0x210: each place's turn */
    u128_372128 rotation;      /* 0x290: the disc's rotation at its first draw */
    u8 trail[0x2C0 - 0x2A0];   /* 0x2A0: the trail's own state */
    s32 count;                 /* 0x2C0: places kept */
    s32 newest;                /* 0x2C4: the newest place's slot */
    f32 share;                 /* 0x2C8: share of the frames to the next kept place */
    u8 pad_2CC[0x2D4 - 0x2CC];
    s32 level;                 /* 0x2D4: the gun's level, 1 = V2 */
} DiscVars_372128;
typedef struct {
    u8 pad_0[0x10];
    u128_372128 position;
    u8 pad_20[0x68 - 0x20];
    DiscVars_372128 *vars;
    u8 pad_6C[0xF0 - 0x6C];
    u128_372128 rotation;
} Moby_372128;

extern void func_003C3FC0(u128_372128 *out, u128_372128 *angles);
extern void func_L01_00408C98(void *trail, s32 kind, u128_372128 *places, u128_372128 *turns,
                              s32 newest, s32 count, u32 head_colour, u32 tail_colour, f32 share,
                              s32 texture);

/* disc_blade_ribbon_draw: the Disc Blade's ribbon trail from V2: keeps the disc's place and turn
   in the ring and draws it with fx_trail, its colours by level */
void func_L01_00372128(Moby_372128 *disc) {
    DiscVars_372128 *vars = disc->vars;
    u32 head_colour;
    u32 tail_colour;
    s32 texture;

    if (vars->first_drawn != 0) {
        func_003C3FC0(&vars->turns[vars->newest], &vars->rotation);
    } else {
        func_003C3FC0(&vars->turns[vars->newest], &disc->rotation);
        vars->rotation = disc->rotation;
        vars->first_drawn = 1;
    }
    (&vars->places[0])[vars->newest] = disc->position;
    /* V2: (0xFF, 0x80, 0x40) at 0x6F to (0xFF, 0x20, 0) */
    head_colour = 0x6F4080FF;
    tail_colour = 0x20FF;
    texture = 8;
    if (vars->level == 2) {
        /* V3: (0x40, 0x80, 0xFF) at 0x6F to (0, 0x20, 0xFF), texture 29 */
        head_colour = 0x6FFF8040;
        tail_colour = 0xFF2000;
        texture = 0x1D;
    }
    if (vars->level == 3) {
        /* V4: (0x20, 0x10, 0xFF) at 0x4F to (0, 0, 0xFF), texture 60 */
        head_colour = 0x4FFF1020;
        tail_colour = 0xFF0000;
        texture = 0x3C;
    }
    if (vars->level >= 4) {
        /* V5: (0xFF, 0x10, 0x20) at 0x4F to (0xFF, 0, 0) */
        head_colour = 0x4F2010FF;
        tail_colour = 0xFF;
        texture = 0x3C;
    }
    func_L01_00408C98(vars->trail, 2, vars->places, vars->turns, vars->newest, vars->count,
                      head_colour, tail_colour, vars->share, texture);
}
/* localdecomp:end func_L01_00372128 */

/* localdecomp:start func_L01_00372240 */
typedef struct {
    u8 pad_0[0x180];
    f32 phase;                 /* 0x180: the turning phase of the sprites' rolls */
    u8 pad_184[0x2D4 - 0x184];
    s32 level;                 /* 0x2D4: the gun's level, 1 = V2 */
} DiscVars_372240;
typedef struct {
    u8 pad_0[0x10];
    u8 position[0x10];
    u8 pad_20[0x68 - 0x20];
    DiscVars_372240 *vars;
} Moby_372240;

extern s32 D_L01_001DD9A8;
__asm__(".extern D_L01_001DD9A8, 4");
extern f32 D_L01_001DD9BC;
__asm__(".extern D_L01_001DD9BC, 4");
extern f32 D_L01_001DD9C0;
__asm__(".extern D_L01_001DD9C0, 4");
extern f32 D_L01_001DD9C4;
__asm__(".extern D_L01_001DD9C4, 4");

extern f32 func_0038DAB8(f32 a, f32 b);
extern f32 func_00382538(void);
extern void func_003D9508(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);

/* disc_blade_sprites_draw: the Disc Blade's disc draws, to V4, added billboards of textures 57, 49
   and 47 on it, rolled by a turning phase */
void func_L01_00372240(Moby_372240 *disc) {
    DiscVars_372240 *vars = disc->vars;
    u32 colour_a = 0x207F7F7F;  /* grey 0x7F at 0x20 */
    u32 colour_b = 0x10007FFF;  /* (0xFF, 0x7F, 0) at 0x10 */
    f32 phase;

    phase = func_0038DAB8(vars->phase, D_L01_001DD9BC * 0.01745329238474369f);
    vars->phase = phase;
    if ((u32)(vars->level - 2) < 2) {
        colour_a = 0x20FF2020;  /* V3-V4 (0x20, 0x20, 0xFF) */
        colour_b = 0x10FF7F00;  /* V3-V4 (0, 0x7F, 0xFF) */
    }
    if (vars->level < 4) {
        func_003D9508(disc->position, D_L01_001DD9A8, colour_a, 1, D_L01_001DD9C4, 0.0799999982118f,
                      func_0038DAB8(-vars->phase * 1.5f, 0.0f));
        func_003D9508(disc->position, D_L01_001DD9A8, colour_a, 1, D_L01_001DD9C4, 0.0799999982118f,
                      vars->phase * 0.5f);
        func_003D9508(disc->position, D_L01_001DD9A8, colour_a, 1, D_L01_001DD9C4, 0.0799999982118f,
                      func_0038DAB8(vars->phase * 2.5f, 0.0f));
        func_003D9508(disc->position, 0x31, colour_b, 1, 0.36000001430511475f, 0.0799999982118f,
                      vars->phase * 0.5f);
        func_003D9508(disc->position, 0x31, colour_b, 1, 0.36000001430511475f, 0.0799999982118f,
                      vars->phase * -0.5f);
        func_003D9508(disc->position, 0x2F, 0x507F7F7F, 1, D_L01_001DD9C0, 0.0799999982118f,
                      func_00382538());
    }
}
/* localdecomp:end func_L01_00372240 */

INCLUDE_ASM("asm/levels", func_L01_00372430);

/* localdecomp:start func_L01_003727B8 */
typedef struct {
    u8 pad_0[0x80];
    f32 x;                     /* 0x80: position */
    f32 y;                     /* 0x84 */
    u8 pad_88[0x1210 - 0x88];
    s32 fire_button;           /* 0x1210: the button the item fires on */
    u8 pad_1214[0x25C4 - 0x1214];
    s32 state;                 /* 0x25C4: the hero's state (0x1D aiming) */
    u8 pad_25C8[0x25ED - 0x25C8];
    u8 no_firing;              /* 0x25ED: guns refuse to fire while set */
    u8 pad_25EE[0x28BC - 0x25EE];
    s32 aiming_fire_wait;      /* 0x28BC: 40 outside state 29 */
} Hero_3727B8;
typedef struct {
    u8 pad_0[0x20];
    s32 timer;                 /* 0x20: frames to the next phase */
    s32 w24;                   /* 0x24 */
    s32 w28;                   /* 0x28: 1 once the glove is ready */
} GloveVars_3727B8;
typedef struct {
    u8 pad_0[0x20];
    u8 phase;                  /* 0x20: 0 start, 1 ready, 2 throwing, 3 wait */
    u8 pad_21[0x31 - 0x21];
    u8 level_flag;             /* 0x31 */
    u8 pad_32[0x68 - 0x32];
    GloveVars_3727B8 *vars;    /* 0x68 */
    u8 pad_6C[0x7C - 0x6C];
    s16 bangles;               /* 0x7C: the glove's bangles by level */
} Glove_3727B8;
typedef struct { u8 pad[0x5C]; u8 *p5C; } T_221098;

extern Hero_3727B8 D_001A4BE0;
extern u8 *D_001D52FC;
extern u8 D_00142627[];
typedef struct { u8 pad_0; u8 kind; u8 pad_2[0xEE]; } Row_3727B8;
extern Row_3727B8 D_L01_002C5600[];
extern f32 D_L01_001E2880[];
extern T_221098 D_L01_00221098;
extern f32 D_L01_002F4D7C[];

extern void func_L01_004C7438(void *out, void *in, s32 a, s32 b, f32 c, f32 d, f32 e, f32 f);
extern s32 func_0038CAD0(s32 *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *dst, void *src, f32 s);
extern s32 func_L01_0037C720_003727B8(void);
extern s32 func_L01_005118D0(s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_004EA7D8(s32);
extern void func_L01_00377A10(f32, void *, void *, void *);
extern void func_L01_004EAA80(void);
extern s32 func_L01_004C7A18(f32 h, void *a, void *b, void *c, void *d, void *e, s32 f, s32 g);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32 a, f32 b);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8(void *a, void *b, s32 life, s32 colour, s32 c, s32 d, s32 e, s32 f, f32 g, f32 h, f32 i);
extern void func_L01_00372CE8(u8 *moby);
extern void func_L01_00404A10_003727B8(void *, u8 *);

/* holo_glove_update: the Holo Shield Glove's update: phase 2 to throw, 1 for no ammo, 3 with none
   left; each frame it also puffs sparks round the hand */
void func_L01_003727B8(Glove_3727B8 *glove)
{
    GloveVars_3727B8 *vars = glove->vars;
    f32 v[20];
    f32 *pos;
    s32 can_throw;
    u8 kind;
    Row_3727B8 *row;
    s32 i;
    s32 life;
    f32 yaw;
    f32 speed;

    func_003C2F58((s32)glove, 0, &v[0]);
    pos = &v[4];
    speed = 5.0f;
    if (D_001A4BE0.state == 0x1D)
        speed = 8.0f;
    func_L01_004C7438(pos, &v[0], 0, 0, 1.5f, speed, 0.30000001192092896f, 0.004399999976158142f);
    if (glove->level_flag)
        D_L01_002F4D7C[0] = 0.10000000149011612f;
    can_throw = 1;
    if (D_001A4BE0.state == 0x1D) {
        if (func_0038CAD0(&D_001A4BE0.aiming_fire_wait) == 0)
            can_throw = 0;
    } else {
        D_001A4BE0.aiming_fire_wait = 0x21;
    }
    row = D_L01_002C5600 + D_00142627[0];
    kind = row->kind;
    if (kind == 3)
        glove->bangles = 7;
    if (kind == 2)
        glove->bangles = 3;
    else if (kind == 1)
        glove->bangles = kind;
    switch (glove->phase) {
    case 0:
        glove->phase = 1;
        vars->w28 = 1;
        vars->w24 = 0;
    case 1:
        if ((*(s32 *)(D_001D52FC + 0x1A4) & D_001A4BE0.fire_button) ||
            ((*(s32 *)(D_001D52FC + 0x1A4) & 8) && D_001A4BE0.state == 0x1D)) {
            if (D_001A4BE0.no_firing == 0 && can_throw) {
                if (func_L01_0037C720_003727B8() || vars->w28 == 0) {
                    func_003A52A0(3, 0, glove);
                } else if (func_L01_005118D0(-1, 1)) {
                    func_003A52A0(2, 0, glove);
                    func_L01_004EA7D8(-1);
                    glove->phase = 2;
                    vars->timer = 0x11;
                } else {
                    func_003A52A0(1, 0, glove);
                }
            }
        }
        break;
    case 2:
        if (func_0038CAD0(&vars->timer)) {
            if (func_0038CEA8(pos) > 0.40000003576278687f)
                func_0038CF68(pos, pos, 0.40000003576278687f);
            func_L01_00377A10(1.0f, glove, &v[0], pos);
            func_L01_004EAA80();
            glove->phase = 3;
            vars->timer = 0x32;
        }
        break;
    case 3:
        if (func_0038CAD0(&vars->timer))
            glove->phase = 1;
        break;
    }
    if (glove->phase == 3)
        return;
    if (func_L01_0037C720_003727B8())
        return;
    vars->w24 = func_L01_004C7A18(0.004399999976158142f, &v[0], pos, vars, (u8 *)vars + 0x10, 0, 0, 0);
    func_003C2F58((s32)glove, 1, &v[8]);
    for (i = 3; i >= 0; i--) {
        yaw = func_0038D160(D_001A4BE0.x - D_L01_001E2880[0x50], D_001A4BE0.y - D_L01_001E2880[0x51]);
        func_L01_00443A18(1.0f, 2.0f);
        v[12] = v[8] + func_003824E0(-0.15f, 0.15f);
        v[13] = v[9] + func_003824E0(-0.15f, 0.15f);
        v[14] = v[10] + func_003824E0(-0.15f, 0.15f);
        yaw = func_0038DAB8(yaw, func_L01_00443A18(0.0f, -6.2831854820251465f));
        v[16] = func_0038D098(yaw) * 0.015000000596046448f;
        v[17] = func_0038D0B0(yaw) * 0.015000000596046448f;
        v[18] = 0.0f;
        life = (func_00382498(10, 30) * 5 + 2) / 6;
        {
            u8 *spark = func_L01_004713C8(&v[12], &v[16], life, 0x804020, func_00382498(-2, -4), 0x7F, 0, 0,
                                         46200.0f, 16800.0f, 0.000800000037997961f);
            if (spark)
                spark[2] = D_L01_00221098.p5C[0];
        }
    }
    func_L01_00404A10_003727B8(func_L01_00372CE8, (u8 *)glove);
}
/* localdecomp:end func_L01_003727B8 */

/* localdecomp:start func_L01_00372CE8 */
extern void func_003C2F58(s32, s32, void *);
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, f32);


extern Pair_371CB8 D_L01_001DD9D0[];
extern void func_L01_004C7D98(void *a, void *b);
extern f32 func_0038CE68(void *a, void *b);
extern f32 func_0038DAB8(f32 a, f32 b);
extern s32 func_L01_004CB2D8(void);
extern void func_L01_004CAB30(void *a, void *b);
extern void func_003D9508(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);
extern f32 func_00382538(void);

void func_L01_00372CE8(u8 *moby) {
    u8 buf[16];
    Pair_371CB8 tmp;
    f32 vec[4];
    Obj_371CB8 *o = *(Obj_371CB8 **)(moby + 104);

    func_L01_004C7D98(o, buf);
    if (func_0038CE68(o->pos, buf) <= 0.9f) {
        o->i40 = 0;
    } else {
        o->i40 = 1;
    }
    tmp = D_L01_001DD9D0[0];
    if (o->i36) {
        if (o->i40) {
            ((void (*)(f32 s, void *a, void *b, void *c, s32 d))func_L01_004C70A8)(1.0f, o, o->pos, 0, 1);
        } else {
            ((void (*)(f32 s, void *a, void *b, void *c, s32 d))func_L01_004C70A8)(1.0f, o, o->pos, &tmp, 1);
        }
    }
    ((void (*)(void *a, s32 b, void *c))func_003C2F58)(moby, 1, vec);
    o->f48 = func_0038DAB8(o->f48, 0.017453292f);
    if (func_L01_004CB2D8()) {
        func_L01_004CAB30(vec, vec);
    }
    func_003D9508(vec, 57, 0x50505050, 1, 0.25f, 0.0f, func_0038DAB8(o->f48 * 2.5f, 0.0f));
    func_003D9508(vec, 42, 0x307F2040, 1, 0.25f, 0.0f, func_0038DAB8(-o->f48 * 1.5f, 0.0f));
    func_003D9508(vec, 44, 0x307F2040, 1, 0.25f, 0.0f, func_0038DAB8(o->f48, 0.0f));
    func_003D9508(vec, 49, 0x30FF7F00, 1, 0.18f, 0.0f, o->f48 * 0.5f);
    func_003D9508(vec, 49, 0x0030FF7F, 1, 0.18f, 0.0f, o->f48 * -0.5f);
    func_003D9508(vec, 47, 0x607F7F7F, 1, 0.06f, 0.0f, func_00382538());
}
/* localdecomp:end func_L01_00372CE8 */

INCLUDE_ASM("asm/levels", func_L01_00372F78);

/* localdecomp:start func_L01_00373368 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_373368;
typedef struct {
    Vec_373368 start;
    Vec_373368 pos_10;
    Vec_373368 target;
    u8 pad_30[0x34 - 0x30];
    f32 speed;
    f32 age;
    f32 damage;
} PulseVars_373368;
typedef struct Moby_373368 {
    u8 pad_0[0x10];
    Vec_373368 position;
    s8 state;
    u8 pad_21[0x30 - 0x21];
    u8 unk_30;
    u8 unk_31;
    u16 unk_32;
    u8 pad_34[0x38 - 0x34];
    long unk_38;
    u8 pad_40[0x68 - 0x40];
    PulseVars_373368 *vars;
    u8 pad_6C[0xB8 - 0x6C];
    struct Moby_373368 *owner;
} Moby_373368;

extern void *func_003C24B0(s32 class_id, s32 flags);

/* holo_pulse_spawn: spawns the Ultrashield's pulse (class 0x1869) from shield, for damage,
   leaving from start toward target */
Moby_373368 *func_L01_00373368(Moby_373368 *shield, Vec_373368 *from, Vec_373368 *to, f32 damage) {
    Vec_373368 start = *from;
    Vec_373368 target = *to;
    Moby_373368 *pulse = func_003C24B0(0x1869, 0x80);

    if (pulse != 0) {
        PulseVars_373368 *vars;

        pulse->unk_30 = 0xFF;
        pulse->unk_32 = 0xFF;
        pulse->unk_31 = 1;
        pulse->state = 0;
        pulse->owner = shield;
        vars = pulse->vars;
        pulse->unk_38 = shield->unk_38;
        pulse->position = vars->start;
        vars->start = start;
        vars->target = target;
        vars->damage = damage;
        vars->age = 0.0f;
        vars->speed = 0.0f;
    }
    return pulse;
}
/* localdecomp:end func_L01_00373368 */

/* localdecomp:start func_L01_00373410 */
void func_L01_00373410(Moby_373368 *pulse) {
    extern void func_L01_00373438_00373410(Moby_373368 *, Vec_373368 *);
    Vec_373368 start=pulse->vars->start;
    func_L01_00373438_00373410(pulse,&start);
}
/* localdecomp:end func_L01_00373410 */
