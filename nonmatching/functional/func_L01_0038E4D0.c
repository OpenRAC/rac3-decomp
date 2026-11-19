/* functional: high. Codex near-miss draft: 6 words differ with the file's flags (a0/a1/a2 move and lwc1 ordering only), 14 at level 02. Loop of 64 quads x 4 vertices, matrix from moby scale at p+0x34. vu0.h qzero and VU0 asm for the vector adds. */
#include "common.h"
#include "vu0.h"
typedef struct {
    s128 vertices[4];
    s32 colors[4];
    f32 uv[4][2];
    unsigned long zero, texture, alpha, test;
} Packet_0038E4D0;
extern s32 D_001DDFC0_sda, D_001DDFB0_sda, D_001DDFAC_sda;
extern s32 D_001DDFB4_sda, D_001DDFB8_sda, D_001DDFBC_sda, D_001DDFC4_sda;
extern f32 D_001DDF30_sda;
__asm__(".extern D_001DDFC0_sda, 4");
__asm__(".extern D_001DDFB0_sda, 4");
__asm__(".extern D_001DDFAC_sda, 4");
__asm__(".extern D_001DDFB4_sda, 4");
__asm__(".extern D_001DDFB8_sda, 4");
__asm__(".extern D_001DDFBC_sda, 4");
__asm__(".extern D_001DDFC4_sda, 4");
__asm__(".extern D_001DDF30_sda, 4");
extern s16 D_L01_002B42E0[][8];
extern s128 D_L01_002B3DE0[];
extern f32 D_L01_002B46E0[][2];
extern f32 D_L01_002B46E4[][2];
typedef struct { u8 pad[0x25C0]; u8 *camera; } Scene_0038E4D0;
extern Scene_0038E4D0 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
static __inline__ s128 *camera_0038E4D0(Scene_0038E4D0 *base) {
    return (s128 *)(base->camera + 0xC0);
}
void func_L01_0038E4D0(u8 *moby) {
    extern unsigned long func_00389598(s32);
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CE20(s128 *, s128 *, f32);
    extern void func_0038D000(s128 *, s128 *, s128 *);
    extern void func_003D2DA0(void *, s32, s32);
    Packet_0038E4D0 packet;
    s128 matrix[3];
    s128 offset;
    f32 *u, *v;
    u8 *p = *(u8 **)(moby + 0x68);
    s32 i, j, uv;
    packet.texture = func_00389598(D_001DDFC0_sda);
    packet.test = (unsigned long)D_001DDFAC_sda |
        ((unsigned long)D_001DDFB0_sda << 2) |
        ((unsigned long)D_001DDFB4_sda << 4) |
        ((unsigned long)D_001DDFB8_sda << 6) |
        ((unsigned long)D_001DDFBC_sda << 32);
    packet.alpha = 0xFF9000000260UL;
    qzero(&matrix[0]);
    qzero(&matrix[1]);
    qzero(&matrix[2]);
    packet.zero = 0;
    ((f32 *)&matrix[0])[0] = *(f32 *)(p + 0x34) * 2.0f;
    ((f32 *)&matrix[1])[1] = *(f32 *)(p + 0x34) * 2.0f;
    ((f32 *)&matrix[2])[2] = *(f32 *)(p + 0x34) * 0.25f;
    packet.colors[3] = D_001DDFC4_sda + (*(s32 *)(p + 0x30) << 24);
    packet.colors[2] = packet.colors[3];
    packet.colors[1] = packet.colors[3];
    packet.colors[0] = packet.colors[3];
    func_003C5180(p + 0x10, &offset, 1);
    func_0038CE20(&offset, &offset, 0.25f);
    u = &packet.uv[0][0];
    v = &packet.uv[0][1];
    for (i = 0; i < 64; i++) {
        f32 *vp = v, *up = u;
        s16 *entry = D_L01_002B42E0[i];
        s128 *vertex = packet.vertices;
        j = 3;
        do {
            uv = entry[1];
            func_0038CE20(vertex, &D_L01_002B3DE0[entry[0]], D_001DDF30_sda);
            j--;
            entry += 2;
            *up = D_L01_002B46E0[uv][0];
            *vp = D_L01_002B46E4[uv][0];
            up += 2;
            func_0038D000(vertex, vertex, matrix);
            vp += 2;
            func_0038D000(vertex, vertex, camera_0038E4D0(&D_001A4BE0));
            __asm__ volatile (
                "lqc2 $vf1, 0(%0)\n"
                "lqc2 $vf2, 16(%1)\n"
                "vadd.xyz $vf1, $vf1, $vf2\n"
                "sqc2 $vf1, 0(%0)\n"
                "lqc2 $vf2, 0(%0)\n"
                "lqc2 $vf1, %2\n"
                "vadd.xyz $vf2, $vf2, $vf1\n"
                "sqc2 $vf2, 0(%0)\n"
                : : "r"(vertex), "r"(p), "m"(offset) : "memory");
            vertex++;
        } while (j >= 0);
        func_003D2DA0(&packet, 0, 0);
    }
}
