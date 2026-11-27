#include "common.h"

/* localdecomp:start func_L39_00548130 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00548130;

extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern void *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern f32 func_L39_005B44C8(void);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_L01_00448D88(u32, s32);
extern s32 func_L39_005B43C8(s32, s32);
extern void *func_L39_005C7B40(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);

void func_L39_00548130(u8 *self, V4_00548130 *pos) {
    V4_00548130 q;
    V4_00548130 dir;
    V4_00548130 up = { 0.3f, -1.0f, 0.0f };
    V4_00548130 center;
    V4_00548130 step;
    V4_00548130 p60;
    V4_00548130 drift;
    V4_00548130 off;
    V4_00548130 p90;
    u8 *p;
    f32 ang;
    f32 life;
    f32 scale;
    s32 i;
    s32 j;
    s32 n;
    u8 *e;
    u8 *sub;

    up.w = 1.0f;
    ang = 0.0f;
    p = *(u8 **)(*(u8 **)(self + 0x68) + 0x50);
    if (p == 0) {
        return;
    }
    center = *pos;
    func_0038D890(&up, p + 0x380, p + 0x390, 0.34906584f);
    dir = up;
    qzero(&drift);
    if (*(s32 *)(p + 0x2D0) != 0) {
        func_0038CE20(&drift, p + 0x140, 1.7f);
    }
    func_0038CE20(&off, p + 0x380, 0.4f);
    vec_add_ab(&center, &center, &off);
    for (i = 0; i < 20; i++) {
        ang = func_0038DAB8(ang, func_L39_005B4410(0.0f, 0.62831855f));
        func_0038CE20(&step, &dir, func_L39_005B4410(0.24000001f, 0.32000002f));
        vec_add_ab(&step, &step, &drift);
        p60.x = center.x + func_L39_005B4468(0.0f, 0.3f);
        p60.y = center.y + func_L39_005B4468(0.0f, 0.3f);
        p60.z = center.z + func_L39_005B4468(0.0f, 0.3f);
        n = func_L39_005B4468(1.0f, 2.0f);
        e = func_L01_004669B0(&p60, 0.0f, 1.0f, 1.01f, func_L39_005B4410(0.2f, 0.75f) * 210000.0f,
                              n, p + 0x140, 0x7F202020, 0);
        if (e != 0) {
            e[3] = 0x44;
            *(s16 *)(e + 0xA) = 50;
            e[9] = 0x44;
            sub = e + 0x20;
            *(f32 *)(sub + 0x1C) = 4.0f;
            *(s32 *)(sub + 0x4) = 3;
            sub[0xA] = 0x30;
            sub[0xB] = e[0xA];
        }
        p60.x = center.x + func_L39_005B4468(0.0f, 0.6f);
        p60.y = center.y + func_L39_005B4468(0.0f, 0.6f);
        p60.z = center.z + func_L39_005B4468(0.0f, 0.6f);
        life = func_L39_005B4410(0.2f, 1.75f);
        vec_sub_ab(&p60, &p60, &step);
        func_L01_0046A610(&p60, &step, 5, 0x7F, 0x404040, n, life * 210000.0f, 500.0f, 0.95f, 0.0f, 0.0f);
        if (fabs_asm(ang) > 1e-5f) {
            func_003C4840(&q, p + 0x380, ang);
            func_0038D850(&dir, &up, &q);
        }
    }
    func_0038CE20(&up, p + 0x380, func_L39_005B4410(8.0f, 12.0f) * 0.020000001f);
    scale = 0.5f;
    for (j = 0; j < 2; j++) {
        f32 pitch = func_L39_005B4410(0.2617994f, 1.3962634f);
        f32 yaw = func_L39_005B44C8();
        func_00382760(&p90, scale * (func_L39_005B4410(7.0f, 10.5f) * 0.020000001f), yaw, pitch);
        vec_add_ab(&p90, &p90, &up);
        p90.z += 0.060000002f;
        {
            s32 c0 = func_L01_00448D88(0x4F007FFF, 0);
            s32 c1 = func_L01_00448D88(0x1F00007F, 0);
            func_L39_005C7B40(pos, &p90, c0, c1, func_L39_005B43C8(50, 100), 1, -1, -1, 0, scale * 40000.0f);
        }
    }
}
/* localdecomp:end func_L39_00548130 */

/* localdecomp:start func_L39_00548648 */
/* func_L39_00548648: a beam effect's draw callback (rac2's beam_draw_ring_and_core in
 * src/levels/shared/L00_003A6538-g8.c is the same routine). The flag D_L39_00241118 is in small data
 * (docs/build/globals.md, "Small data at an offset"): retail loads it with the assembler's lui+lw
 * macro after the lbu it is compared with. */
typedef struct {
    vu0_v4 position[4];
    u32 colour[4];
    f32 uv[4][2];
    u8 pad70[0x20];
} Quad_00548648;

typedef struct {
    u8 pad0[8];
    s16 count;      /* 0x08 */
    s16 fade;       /* 0x0A */
    f32 angle;      /* 0x0C */
    vu0_v4 pos;     /* 0x10 */
    f32 alpha;      /* 0x20 */
    f32 fade_step;  /* 0x24 */
    f32 spin0;      /* 0x28 */
    f32 spin1;      /* 0x2C */
    vu0_v4 dir;     /* 0x30 */
    s32 glow;       /* 0x40 */
    f32 glow_step;  /* 0x44 */
} Vars_00548648;

typedef struct { u8 pad[0x150]; s16 display_width, display_height; } FsAa_00548648;

extern FsAa_00548648 D_00228580;
extern s32 D_L39_00241118 __attribute__((section(".sdata")));
extern f32 D_L39_0024AFB4;
extern f32 D_L39_0024AFB8;
extern f32 D_L39_0024AFBC;
extern f32 D_L39_0024AFC0;
extern f32 D_L39_0024AFC4;
extern f32 D_L39_0024AFC8;
extern f32 D_L39_0024AFCC;
extern f32 D_L39_0024AFD0;
extern f32 D_L39_0024AFD8;
__asm__(".extern D_L39_0024AFB4, 4");
__asm__(".extern D_L39_0024AFB8, 4");
__asm__(".extern D_L39_0024AFBC, 4");
__asm__(".extern D_L39_0024AFC0, 4");
__asm__(".extern D_L39_0024AFC4, 4");
__asm__(".extern D_L39_0024AFC8, 4");
__asm__(".extern D_L39_0024AFCC, 4");
__asm__(".extern D_L39_0024AFD0, 4");
__asm__(".extern D_L39_0024AFD8, 4");

extern void func_003D93B0(Quad_00548648 *, s32, s32, s32);
extern void func_003D2DA0(Quad_00548648 *, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern void func_003C4840(void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L39_005BC330(void *, void *, s32);
extern void func_003A9440(s32, s32);
extern void func_0038AF30(s32, s32, s32, s32, u32);

static __inline__ s32 has_vars_00548648(u8 *m) {
    return *(Vars_00548648 **)(m + 0x68) != 0;
}

void func_L39_00548648(u8 *moby) {
    Quad_00548648 quad;
    vu0_v4 center;
    vu0_v4 up;
    vu0_v4 eye;
    vu0_v4 arm;
    vu0_v4 mid;
    vu0_v4 rot;
    vu0_v4 side;
    vu0_v4 tip;
    vu0_v4 across;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 back;
    Vars_00548648 *vars;
    u8 *p;
    f32 alpha;
    f32 t;
    f32 len;
    s32 i;
    u32 colour;

    if (moby == 0) return;
    if (moby[0x20] == 0xFE) return;
    if (moby[0x20] == 0xFD) return;
    if (!has_vars_00548648(moby)) return;
    vars = *(Vars_00548648 **)(moby + 0x68);
    if (*(u8 **)((u8 *)vars + 0x50) == 0) return;
    p = *(u8 **)((u8 *)vars + 0x50);
    center = vars->pos;
    func_L39_005BC330(&center, &up, 1);
    vec_sub_ab(&eye, p + 0x23A0, &center);
    func_0038CF68(&eye, &eye, 1.0f);
    if (vars->count != 0) {
        alpha = (f32)vars->count * vars->alpha;
        func_003D93B0(&quad, 0xB, 1, 0x80);
        colour = ((s32)(alpha * 255.0f) << 24) | 0x2040FF;
        quad.colour[3] = colour;
        quad.colour[2] = colour;
        quad.colour[1] = colour;
        quad.colour[0] = colour;
        quad.uv[0][0] = 0.5f;
        quad.uv[0][1] = 0.0f;
        quad.uv[1][0] = 0.5f;
        quad.uv[1][1] = 1.0f;
        quad.uv[2][0] = 1.0f;
        quad.uv[2][1] = 0.0f;
        quad.uv[3][0] = 1.0f;
        quad.uv[3][1] = 1.0f;
        func_0038CE20(&arm, &up, D_L39_0024AFB4);
        vec_add_ab(&mid, &center, &arm);
        func_003C4840(&rot, &eye, vars->angle);
        func_0038D850(&arm, &arm, &rot);
        for (i = 0; i < 8; i++) {
            func_0038CE90(&side, &eye, &arm);
            func_0038CF68(&side, &side, D_L39_0024AFB8);
            vec_add_ab(&quad.position[0], &center, &side);
            vec_sub_ab(&quad.position[1], &center, &side);
            func_0038CE20(&side, &side, D_L39_0024AFBC / D_L39_0024AFB8);
            vec_add_ab(&tip, &center, &arm);
            vec_add_ab(&quad.position[2], &tip, &side);
            vec_sub_ab(&quad.position[3], &tip, &side);
            func_003D2DA0(&quad, 0, 0);
            if (i < 7) {
                func_003C4840(&rot, &eye, 0.7853982f);
                func_0038D850(&arm, &arm, &rot);
            }
        }
    }
    len = (f32)vars->fade * vars->fade_step;
    vars->spin0 = func_0038DAB8(vars->spin0, D_L39_0024AFC8 * 0.017453292f);
    vars->spin1 = func_0038DAB8(vars->spin1, D_L39_0024AFCC * 0.017453292f);
    func_003D93B0(&quad, 0x38, 1, 0x80);
    colour = ((s32)(len * 20.0f) << 24) | 0x8080FF;
    quad.uv[0][0] = 0.0f;
    quad.uv[0][1] = 0.0f;
    quad.uv[1][0] = 0.0f;
    quad.uv[1][1] = 1.0f;
    quad.uv[2][0] = 1.0f;
    quad.uv[2][1] = 0.0f;
    quad.colour[3] = colour;
    quad.colour[2] = colour;
    quad.colour[1] = colour;
    quad.colour[0] = colour;
    quad.uv[3][0] = 1.0f;
    quad.uv[3][1] = 1.0f;
    func_0038CE20(&arm, &vars->dir, len * -16.0f + 16.0f);
    vec_add_ab(&mid, &center, &arm);
    vec_sub_ab(&rot, p + 0x23A0, &mid);
    func_0038CF68(&rot, &rot, 1.0f);
    func_003C4840(&side, &rot, vars->spin0);
    func_0038CE90(&tip, &rot, &up);
    func_0038CE90(&across, &tip, &rot);
    func_0038D850(&a, &across, &side);
    t = D_L39_0024AFC4 + (D_L39_0024AFC0 - D_L39_0024AFC4) * len;
    func_0038CF68(&a, &a, t);
    func_0038CE90(&b, &rot, &a);
    func_0038CF68(&b, &b, t);
    vec_add_ab(&c, &mid, &a);
    vec_add_ab(&quad.position[0], &c, &b);
    vec_sub_ab(&quad.position[1], &c, &b);
    vec_sub_ab(&c, &mid, &a);
    vec_add_ab(&quad.position[2], &c, &b);
    vec_sub_ab(&quad.position[3], &c, &b);
    func_003D2DA0(&quad, 0, 0);
    func_003C4840(&side, &rot, vars->spin1);
    func_0038D850(&a, &across, &side);
    func_0038CE20(&a, &a, t);
    func_0038CE90(&b, &rot, &a);
    func_0038CF68(&b, &b, t);
    vec_add_ab(&c, &mid, &a);
    vec_add_ab(&quad.position[0], &c, &b);
    vec_sub_ab(&quad.position[1], &c, &b);
    vec_sub_ab(&c, &mid, &a);
    vec_add_ab(&quad.position[2], &c, &b);
    vec_sub_ab(&quad.position[3], &c, &b);
    func_003D2DA0(&quad, 0, 0);
    if (vars->glow != 0) {
        len = (f32)vars->glow * vars->glow_step;
        func_003D93B0(&quad, 0xB, 4, 0x80);
        colour = ((s32)(len * 255.0f) << 24) | 0x808080;
        quad.colour[3] = colour;
        quad.colour[2] = colour;
        quad.colour[1] = colour;
        quad.colour[0] = colour;
        func_0038CE20(&back, &eye, -0.1f);
        vec_add_ab(&mid, p + 0x23A0, &back);
        func_0038CE90(&b, &eye, &up);
        func_0038CF68(&b, &b, D_L39_0024AFD0);
        func_0038CE90(&a, &b, &eye);
        func_0038CF68(&a, &a, D_L39_0024AFD0);
        vec_add_ab(&c, &mid, &a);
        vec_add_ab(&quad.position[0], &c, &b);
        vec_sub_ab(&quad.position[1], &c, &b);
        vec_sub_ab(&c, &mid, &a);
        vec_add_ab(&quad.position[2], &c, &b);
        vec_sub_ab(&quad.position[3], &c, &b);
        func_003D2DA0(&quad, 0, 0);
        quad.colour[0] = quad.colour[1] = quad.colour[2] = quad.colour[3] = ((s32)(D_L39_0024AFD8 * len) << 24) | 0x808080;
        if (p[0x1A14] != 0 && p[0x24C9] == D_L39_00241118) {
            func_003A9440(0x42, 0x48);
            func_0038AF30(0, D_00228580.display_height, 0, D_00228580.display_width, quad.colour[0]);
        }
    }
}
/* localdecomp:end func_L39_00548648 */
