/* functional: high. Written from the PAL asm (no draft). Three textured-quad effect passes (8 rotated billboards, an optional 40-spark burst, two spinning quads, a fade quad and a full-screen tint), drawn through the func_003D93B0 quad descriptor (layout as B_3D3FA0 in src/frontbin/3D9378.c). Constants, $gp globals (gp+0xF74..0xF98 = D_L01_001DD824..848), vector op order and every call argument checked against the asm. func_0038D850 rotates by a quaternion built by func_003C4840 (16-byte vector), not a matrix. */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_0036D018;
typedef struct { Vec_0036D018 p[4]; s32 c[4]; f32 uv[8]; long t70, t78, t80, t88; } Quad_0036D018;
typedef struct {
    u8 pad0[8];
    s16 count;
    s16 s0A;
    f32 angle0C;
    Vec_0036D018 pos10;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    Vec_0036D018 v30;
    s32 i40;
    f32 f44;
    u8 pad48[0x54 - 0x48];
    s32 i54;
} Vars_0036D018;
typedef struct { u8 pad[0x80]; f32 x; f32 y; } Hero_0036D018;
typedef struct { u8 pad[0x5C]; u8 *p5C; } T_221098_0036D018;
typedef struct { u8 pad_0[0x150]; s16 width; s16 height; } Screen_0036D018;
extern Hero_0036D018 D_001A4BE0;
extern Screen_0036D018 D_001CFEC0;
extern Vec_0036D018 D_L01_001E2A40;
extern f32 D_L01_001E2880[];
extern T_221098_0036D018 D_L01_00221098;
extern f32 D_L01_001DD824;
__asm__(".extern D_L01_001DD824, 4");
extern f32 D_L01_001DD828;
__asm__(".extern D_L01_001DD828, 4");
extern f32 D_L01_001DD82C;
__asm__(".extern D_L01_001DD82C, 4");
extern f32 D_L01_001DD830;
__asm__(".extern D_L01_001DD830, 4");
extern f32 D_L01_001DD834;
__asm__(".extern D_L01_001DD834, 4");
extern f32 D_L01_001DD838;
__asm__(".extern D_L01_001DD838, 4");
extern f32 D_L01_001DD83C;
__asm__(".extern D_L01_001DD83C, 4");
extern f32 D_L01_001DD840;
__asm__(".extern D_L01_001DD840, 4");
extern f32 D_L01_001DD848;
__asm__(".extern D_L01_001DD848, 4");
static __inline__ void add_0036D018(Vec_0036D018 *d, Vec_0036D018 *a, Vec_0036D018 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void sub_0036D018(Vec_0036D018 *d, Vec_0036D018 *a, Vec_0036D018 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
void func_L01_0036D018(u8 *moby) {
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_003D93B0(void *, s32, s32, long);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D850(void *, void *, void *);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern void func_003A9440(s32, long);
    extern void func_0038AF30(s32, s32, s32, s32, s32);
    Quad_0036D018 q;
    Vec_0036D018 V90, VA0, VB0, VC0, VD0, VE0, VF0, V100, V110, V120, V130, V140, V150, Q;
    Vars_0036D018 *vars = *(Vars_0036D018 **)(moby + 0x68);
    f32 a, yaw, t, scale;
    s32 i, col, life;
    u8 *spark;

    V90 = vars->pos10;
    func_003C5180(&V90, &VA0, 1);
    sub_0036D018(&VB0, &D_L01_001E2A40, &V90);
    func_0038CF68(&VB0, &VB0, 1.0f);
    if (vars->count) {
        a = (f32)vars->count * vars->f20;
        func_003D93B0(&q, 0x1A, 1, 0x80);
        a = a * 255.0f;
        q.uv[0] = 0.5f; q.uv[1] = 0.0f; q.uv[2] = 0.5f; q.uv[3] = 1.0f;
        q.uv[4] = 1.0f; q.uv[5] = 0.0f; q.uv[6] = 1.0f; q.uv[7] = 1.0f;
        col = ((s32)a << 24) | 0x2040FF;
        q.c[0] = col; q.c[3] = col; q.c[2] = col; q.c[1] = col;
        func_0038CE20(&VC0, &VA0, D_L01_001DD824);
        add_0036D018(&VD0, &V90, &VC0);
        func_003C4840(&Q, &VB0, vars->angle0C);
        func_0038D850(&VC0, &VC0, &Q);
        for (i = 0; i < 8; i++) {
            func_0038CE90(&VF0, &VB0, &VC0);
            func_0038CF68(&VF0, &VF0, D_L01_001DD828);
            t = D_L01_001DD82C / D_L01_001DD828;
            add_0036D018(&q.p[0], &V90, &VF0);
            sub_0036D018(&q.p[1], &V90, &VF0);
            func_0038CE20(&VF0, &VF0, t);
            add_0036D018(&V100, &V90, &VC0);
            add_0036D018(&q.p[2], &V100, &VF0);
            sub_0036D018(&q.p[3], &V100, &VF0);
            func_003D2DA0(&q, 0, 0);
            if (i < 7) {
                func_003C4840(&Q, &VB0, 0.7853981852531433f);
                func_0038D850(&VC0, &VC0, &Q);
            }
        }
        if (vars->i54) {
            for (i = 39; i >= 0; i--) {
                yaw = func_0038D160(D_001A4BE0.x - D_L01_001E2880[0x50], D_001A4BE0.y - D_L01_001E2880[0x51]);
                func_L01_00443A18(1.0f, 2.0f);
                VF0.x = *(f32 *)(moby + 0x10) + func_L01_00443A18(0.0f, 0.15000000596046448f);
                VF0.y = *(f32 *)(moby + 0x14) + func_L01_00443A18(0.0f, 0.15000000596046448f);
                VF0.z = *(f32 *)(moby + 0x18) - 0.30000001192092896f;
                yaw = func_0038DAB8(yaw, func_L01_00443A18(0.0f, -6.2831854820251465f));
                V100.x = func_0038D098(yaw) * 0.20000001788139343f;
                V100.y = func_0038D0B0(yaw) * 0.20000001788139343f;
                V100.z = 0.0f;
                life = (func_00382498(10, 30) * 5 + 2) / 6;
                spark = func_L01_004713C8(&VF0, &V100, life, 0x707070, func_00382498(-2, -4), 0x30, 0, 0,
                                          63000.00390625f, 168000.0f, 0.0f);
                if (spark)
                    spark[2] = *D_L01_00221098.p5C;
            }
        }
    }
    scale = (f32)vars->s0A * vars->f24;
    vars->f28 = func_0038DAB8(vars->f28, D_L01_001DD838 * 0.01745329238474369f);
    vars->f2C = func_0038DAB8(vars->f2C, D_L01_001DD83C * 0.01745329238474369f);
    func_003D93B0(&q, 0x3D, 1, 0x80);
    a = scale * 20.0f;
    q.uv[0] = 0.0f; q.uv[1] = 0.0f; q.uv[2] = 0.0f; q.uv[3] = 1.0f;
    q.uv[4] = 1.0f; q.uv[5] = 0.0f; q.uv[6] = 1.0f; q.uv[7] = 1.0f;
    col = ((s32)a << 24) | 0x8080FF;
    q.c[0] = col; q.c[3] = col; q.c[2] = col; q.c[1] = col;
    func_0038CE20(&VC0, &vars->v30, scale * -16.0f + 16.0f);
    add_0036D018(&VD0, &V90, &VC0);
    sub_0036D018(&VE0, &D_L01_001E2A40, &VD0);
    func_0038CF68(&VE0, &VE0, 1.0f);
    func_003C4840(&Q, &VE0, vars->f28);
    func_0038CE90(&V100, &VE0, &VA0);
    func_0038CE90(&V110, &V100, &VE0);
    func_0038D850(&V120, &V110, &Q);
    t = D_L01_001DD830 - D_L01_001DD834;
    t = t * scale;
    t = D_L01_001DD834 + t;
    func_0038CF68(&V120, &V120, t);
    func_0038CE90(&V130, &VE0, &V120);
    func_0038CF68(&V130, &V130, t);
    add_0036D018(&V140, &VD0, &V120);
    add_0036D018(&q.p[0], &V140, &V130);
    sub_0036D018(&q.p[1], &V140, &V130);
    sub_0036D018(&V140, &VD0, &V120);
    add_0036D018(&q.p[2], &V140, &V130);
    sub_0036D018(&q.p[3], &V140, &V130);
    func_003D2DA0(&q, 0, 0);
    func_003C4840(&Q, &VE0, vars->f2C);
    func_0038D850(&V120, &V110, &Q);
    func_0038CE20(&V120, &V120, t);
    func_0038CE90(&V130, &VE0, &V120);
    func_0038CF68(&V130, &V130, t);
    add_0036D018(&V140, &VD0, &V120);
    add_0036D018(&q.p[0], &V140, &V130);
    sub_0036D018(&q.p[1], &V140, &V130);
    sub_0036D018(&V140, &VD0, &V120);
    add_0036D018(&q.p[2], &V140, &V130);
    sub_0036D018(&q.p[3], &V140, &V130);
    func_003D2DA0(&q, 0, 0);
    if (vars->i40) {
        scale = (f32)vars->i40 * vars->f44;
        func_003D93B0(&q, 0xB, 4, 0x80);
        col = ((s32)(scale * 255.0f) << 24) | 0x808080;
        q.c[0] = col; q.c[3] = col; q.c[2] = col; q.c[1] = col;
        func_0038CE20(&V150, &VB0, -0.10000000149011612f);
        add_0036D018(&VD0, &D_L01_001E2A40, &V150);
        func_0038CE90(&V130, &VB0, &VA0);
        func_0038CF68(&V130, &V130, D_L01_001DD840);
        func_0038CE90(&V120, &V130, &VB0);
        func_0038CF68(&V120, &V120, D_L01_001DD840);
        add_0036D018(&V140, &VD0, &V120);
        add_0036D018(&q.p[0], &V140, &V130);
        sub_0036D018(&q.p[1], &V140, &V130);
        sub_0036D018(&V140, &VD0, &V120);
        add_0036D018(&q.p[2], &V140, &V130);
        sub_0036D018(&q.p[3], &V140, &V130);
        func_003D2DA0(&q, 0, 0);
        col = ((s32)(D_L01_001DD848 * scale) << 24) | 0x808080;
        q.c[0] = col; q.c[3] = col; q.c[2] = col; q.c[1] = col;
        func_003A9440(0x42, 0x48);
        func_0038AF30(0, D_001CFEC0.height, 0, D_001CFEC0.width, q.c[0]);
    }
}
