/* functional: medium. Written from the asm (no draft): 382 diff; 51 jals identical in order, all constants identical (0.2f is 0x3E4CCCCE here), same instruction multiset except VU register numbering (vf1/vf2 order), stack slot placement and the discarded func_L01_00443A18(1.0,2.0) RNG call which is kept; the repeated 6-store quad build is a local static inline helper ribbon_00388EE0 of lqc2/vadd/vsub inline asm; gp float globals D_L01_001DDDC4..E8 named by address (meaning of each not worked out) */
#include "common.h"
#include "vu0.h"
typedef struct {
    vu0_v4 position[4];
    u32 colour[4];
    f32 uv[4][2];
    u8 pad70[0x20];
} Quad_00388EE0;
typedef struct { u8 pad[0x150]; s16 h150; s16 h152; } S_1CFEC0_00388EE0;
extern S_1CFEC0_00388EE0 D_001CFEC0[];
extern u8 D_001A4BE0[];
extern u8 D_L01_001E2880[];
extern vu0_v4 D_L01_001E2A40;
extern u8 *D_L01_00221098[];
extern f32 D_L01_001DDDC4, D_L01_001DDDC8, D_L01_001DDDCC, D_L01_001DDDD0, D_L01_001DDDD4;
extern f32 D_L01_001DDDD8, D_L01_001DDDDC, D_L01_001DDDE0, D_L01_001DDDE8;
__asm__(".extern D_L01_001DDDC4, 4");
__asm__(".extern D_L01_001DDDC8, 4");
__asm__(".extern D_L01_001DDDCC, 4");
__asm__(".extern D_L01_001DDDD0, 4");
__asm__(".extern D_L01_001DDDD4, 4");
__asm__(".extern D_L01_001DDDD8, 4");
__asm__(".extern D_L01_001DDDDC, 4");
__asm__(".extern D_L01_001DDDE0, 4");
__asm__(".extern D_L01_001DDDE8, 4");
static __inline__ void vadd_00388EE0(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void vsub_00388EE0(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void ribbon_00388EE0(Quad_00388EE0 *q, vu0_v4 *c, vu0_v4 *a, vu0_v4 *b, vu0_v4 *t) {
    vadd_00388EE0(t, c, a);
    vadd_00388EE0(&q->position[0], t, b);
    vsub_00388EE0(&q->position[1], t, b);
    vsub_00388EE0(t, c, a);
    vadd_00388EE0(&q->position[2], t, b);
    vsub_00388EE0(&q->position[3], t, b);
}
/* functional: lightning/beam effect draw callback of the beam moby */
void func_L01_00388EE0(u8 *moby) {
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_003D93B0(void *, s32, s32, s32);
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
    extern void func_0038AF30(s32, s32, s32, s32, s32);
    extern void func_0038CE20(void *, void *, f32);
    Quad_00388EE0 quad;
    vu0_v4 p90, pa0, pb0, pc0, pd0, pe0, pf0, h100, h110, h120, h130, h140, h150;
    u8 *vars = *(u8 **)(moby + 0x68);
    s32 i, life, spin, colour;
    f32 intensity, angle, lerp;
    u8 *p;

    *(vu0_q *)&p90 = *(vu0_q *)(vars + 0x10);
    func_003C5180(&p90, &pa0, 1);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(pb0) : "m"(D_L01_001E2A40), "m"(p90) : "vf1", "vf2");
    func_0038CF68(&pb0, &pb0, 1.0f);

    if (*(s16 *)(vars + 8) != 0) {
        intensity = (f32)*(s16 *)(vars + 8) * *(f32 *)(vars + 0x20);
        func_003D93B0(&quad, 0x1A, 1, 0x80);
        colour = ((s32)(intensity * 255.0f) << 24) | 0xFF4020;
        quad.uv[0][0] = 0.5f; quad.uv[0][1] = 0.0f;
        quad.uv[1][0] = 0.5f; quad.uv[1][1] = 1.0f;
        quad.uv[2][0] = 1.0f; quad.uv[2][1] = 0.0f;
        quad.uv[3][0] = 1.0f; quad.uv[3][1] = 1.0f;
        quad.colour[0] = colour; quad.colour[1] = colour; quad.colour[2] = colour; quad.colour[3] = colour;
        func_0038CE20(&pc0, &pa0, D_L01_001DDDC4);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(pd0) : "m"(p90), "m"(pc0) : "vf1", "vf2");
        func_003C4840(&pe0, &pb0, *(f32 *)(vars + 0x68));
        func_0038D850(&pc0, &pc0, &pe0);
        for (i = 0; i < 8; i++) {
            func_0038CE90(&pf0, &pb0, &pc0);
            func_0038CF68(&pf0, &pf0, D_L01_001DDDC8);
            vadd_00388EE0(&quad.position[0], &p90, &pf0);
            vsub_00388EE0(&quad.position[1], &p90, &pf0);
            func_0038CE20(&pf0, &pf0, D_L01_001DDDCC / D_L01_001DDDC8);
            vadd_00388EE0(&h100, &p90, &pc0);
            vadd_00388EE0(&quad.position[2], &h100, &pf0);
            vsub_00388EE0(&quad.position[3], &h100, &pf0);
            func_003D2DA0(&quad, 0, 0);
            if (i < 7) {
                func_003C4840(&pe0, &pb0, 0.7853982f);
                func_0038D850(&pc0, &pc0, &pe0);
            }
        }
        if (*(s32 *)(D_001A4BE0 + 0x25C4) != 7) {
            for (i = 0x27; i >= 0; i--) {
                angle = func_0038D160(*(f32 *)(D_001A4BE0 + 0x80) - *(f32 *)(D_L01_001E2880 + 0x140),
                                      *(f32 *)(D_001A4BE0 + 0x84) - *(f32 *)(D_L01_001E2880 + 0x144));
                func_L01_00443A18(1.0f, 2.0f);
                pf0.x = *(f32 *)(moby + 0x10) + func_L01_00443A18(0.0f, 0.15f);
                pf0.y = *(f32 *)(moby + 0x14) + func_L01_00443A18(0.0f, 0.15f);
                pf0.z = *(f32 *)(moby + 0x18) - 0.3f;
                angle = func_0038DAB8(angle, func_L01_00443A18(0.0f, -6.2831855f));
                h100.x = func_0038D098(angle) * 0.20000001788139343f;
                h100.y = func_0038D0B0(angle) * 0.20000001788139343f;
                h100.z = 0.0f;
                life = (func_00382498(10, 30) * 5 + 2) / 6;
                spin = func_00382498(-2, -4);
                p = func_L01_004713C8(&pf0, &h100, life, 0x707070, spin, 0x40, 0, 0, 63000.00390625f, 168000.0f, 0.0f);
                if (p) p[2] = (*(u8 **)((u8 *)D_L01_00221098 + 0x5C))[0];
            }
        }
    }
    intensity = (f32)*(s16 *)(vars + 0xA) * *(f32 *)(vars + 0x24);
    *(f32 *)(vars + 0x28) = func_0038DAB8(*(f32 *)(vars + 0x28), D_L01_001DDDD8 * 0.01745329238474369f);
    *(f32 *)(vars + 0x2C) = func_0038DAB8(*(f32 *)(vars + 0x2C), D_L01_001DDDDC * 0.01745329238474369f);
    func_003D93B0(&quad, 0x3D, 1, 0x80);
    colour = ((s32)(intensity * 20.0f) << 24) | 0xFF8080;
    quad.uv[0][0] = 0.0f; quad.uv[0][1] = 0.0f;
    quad.uv[1][0] = 0.0f; quad.uv[1][1] = 1.0f;
    quad.uv[2][0] = 1.0f; quad.uv[2][1] = 0.0f;
    quad.uv[3][0] = 1.0f; quad.uv[3][1] = 1.0f;
    quad.colour[0] = colour; quad.colour[3] = colour; quad.colour[2] = colour; quad.colour[1] = colour;
    func_0038CE20(&pc0, vars + 0x30, intensity * -16.0f + 16.0f);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(pd0) : "m"(p90), "m"(pc0) : "vf1", "vf2");
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(pe0) : "m"(D_L01_001E2A40), "m"(pd0) : "vf1", "vf2");
    func_0038CF68(&pe0, &pe0, 1.0f);
    func_003C4840(&pf0, &pe0, *(f32 *)(vars + 0x28));
    func_0038CE90(&h100, &pe0, &pa0);
    func_0038CE90(&h110, &h100, &pe0);
    func_0038D850(&h120, &h110, &pf0);
    lerp = D_L01_001DDDD4 + (D_L01_001DDDD0 - D_L01_001DDDD4) * intensity;
    func_0038CF68(&h120, &h120, lerp);
    func_0038CE90(&h130, &pe0, &h120);
    func_0038CF68(&h130, &h130, lerp);
    ribbon_00388EE0(&quad, &pd0, &h120, &h130, &h140);
    func_003D2DA0(&quad, 0, 0);
    func_003C4840(&pf0, &pe0, *(f32 *)(vars + 0x2C));
    func_0038D850(&h120, &h110, &pf0);
    func_0038CE20(&h120, &h120, lerp);
    func_0038CE90(&h130, &pe0, &h120);
    func_0038CF68(&h130, &h130, lerp);
    ribbon_00388EE0(&quad, &pd0, &h120, &h130, &h140);
    func_003D2DA0(&quad, 0, 0);
    if (*(s32 *)(vars + 0x40) != 0) {
        intensity = (f32)*(s32 *)(vars + 0x40) * *(f32 *)(vars + 0x44);
        func_003D93B0(&quad, 0xB, 4, 0x80);
        colour = ((s32)(intensity * 255.0f) << 24) | 0x808080;
        quad.colour[0] = colour; quad.colour[3] = colour; quad.colour[2] = colour; quad.colour[1] = colour;
        func_0038CE20(&h150, &pb0, -0.1f);
        vadd_00388EE0(&pd0, &D_L01_001E2A40, &h150);
        func_0038CE90(&h130, &pb0, &pa0);
        func_0038CF68(&h130, &h130, D_L01_001DDDE0);
        func_0038CE90(&h120, &h130, &pb0);
        func_0038CF68(&h120, &h120, D_L01_001DDDE0);
        ribbon_00388EE0(&quad, &pd0, &h120, &h130, &h140);
        func_003D2DA0(&quad, 0, 0);
        colour = ((s32)(D_L01_001DDDE8 * intensity) << 24) | 0x808080;
        quad.colour[0] = colour; quad.colour[3] = colour; quad.colour[2] = colour; quad.colour[1] = colour;
        func_003A9440(0x42, 0x48);
        func_0038AF30(0, D_001CFEC0->h152, 0, D_001CFEC0->h150, quad.colour[0]);
    }
}
