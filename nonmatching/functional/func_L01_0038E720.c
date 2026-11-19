/* functional: high. Codex near-miss draft; I re-read it against the retail asm (packet layout, matrix scale slots 0/5/10 with 0.125, 64 x 4-vertex loop, camera+0xC0 matrix, both VU0 vadd.xyz blocks): same behaviour, 40 words differ only in scheduling/loop-table addressing. */
#include "common.h"
#include "vu0.h"
extern s32 D_001DDFC0_sda;
extern s32 D_001DDFAC_sda, D_001DDFB0_sda, D_001DDFB4_sda, D_001DDFB8_sda, D_001DDFBC_sda;
extern s32 D_001DDFC4_sda;
extern f32 D_001DDF30_sda;
__asm__(".extern D_001DDF30_sda, 4");
__asm__(".extern D_001DDFC4_sda, 4");
__asm__(".extern D_001DDFAC_sda, 4");
__asm__(".extern D_001DDFB0_sda, 4");
__asm__(".extern D_001DDFB4_sda, 4");
__asm__(".extern D_001DDFB8_sda, 4");
__asm__(".extern D_001DDFBC_sda, 4");
extern s16 D_L01_002B42E0[][8] __attribute__((section(".sdata")));
extern s128 D_L01_002B3DE0[];
extern f32 D_L01_002B46E0[][2];
extern f32 D_L01_002B46E4[][2];
typedef struct { u8 bytes[0x25C0]; u8 *camera; } Camera_0038E720;
extern Camera_0038E720 D_001A4BE0 __attribute__((section(".sdata")));
typedef struct {
    s128 verts[4];
    u32 color[4];
    f32 uv[8];
    unsigned long state[4];
    s128 matrix[3];
    s128 offset;
    f32 *u, *v;
} Packet_0038E720;
void func_L01_0038E720(void *obj) {
    extern unsigned long func_00389598(s32);
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CE20(s128 *, s128 *, f32);
    extern void func_0038D000(s128 *, s128 *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    Packet_0038E720 packet;
    u8 *vars = *(u8 **)((u8 *)obj + 0x68);
    unsigned long texture = func_00389598(D_001DDFC0_sda);
    s32 i, j;
    s128 *vertex;
    s16 *indices;
    f32 *u, *v;
    packet.state[0] = 0;
    packet.state[1] = texture;
    packet.state[2] = 0xFF9000000260UL;
    packet.state[3] = (unsigned long)D_001DDFAC_sda | ((unsigned long)D_001DDFB0_sda << 2) | ((unsigned long)D_001DDFB4_sda << 4) | ((unsigned long)D_001DDFB8_sda << 6) | ((unsigned long)D_001DDFBC_sda << 32);
    qzero(&packet.matrix[0]);
    qzero(&packet.matrix[1]);
    qzero(&packet.matrix[2]);
    ((f32 *)packet.matrix)[0] = *(f32 *)(vars + 0x34);
    ((f32 *)packet.matrix)[5] = *(f32 *)(vars + 0x34);
    ((f32 *)packet.matrix)[10] = *(f32 *)(vars + 0x34) * 0.125f;
    packet.color[0] = packet.color[1] = packet.color[2] = packet.color[3] = D_001DDFC4_sda + (*(s32 *)(vars + 0x30) << 24);
    func_003C5180(vars + 0x10, &packet.offset, 1);
    func_0038CE20(&packet.offset, &packet.offset, 0.25f);
    packet.u = &packet.uv[0];
    packet.v = &packet.uv[1];
    i = 0;
    do {
        s32 next = i + 1;
        v = packet.v;
        u = packet.u;
        vertex = packet.verts;
        indices = D_L01_002B42E0[i];
        for (j = 3; j >= 0; j--) {
            s32 uv = indices[1];
            func_0038CE20(vertex, &D_L01_002B3DE0[indices[0]], D_001DDF30_sda);
            {
                f32 a = D_L01_002B46E0[uv][0];
                f32 b = D_L01_002B46E4[uv][0];
                *u = a;
                *v = b;
            }
            indices += 2;
            func_0038D000(vertex, vertex, packet.matrix);
            u += 2;
            v += 2;
            func_0038D000(vertex, vertex, D_001A4BE0.camera + 0xC0);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(*vertex) : "m"(*vertex), "m"(*(s128 *)(vars + 0x10)) : "vf1", "vf2");
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                : "=m"(*vertex) : "m"(*vertex), "m"(packet.offset) : "vf1", "vf2");
            vertex++;
        }
        func_003D2DA0(&packet, 0, 0);
        i = next;
    } while (i < 64);
}
