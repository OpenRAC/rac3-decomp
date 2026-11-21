/* functional: high. 205 diff = scheduling/stack-slot only. Fixed vs draft: retail stores func_L01_00393EF8's returned pointer into D_L01_001E2020[face] (draft dropped it); file declares it void so called via a function-pointer cast, integration should give it a u8* return type. All constants/branches verified vs asm */
#include "common.h"
#include "vu0.h"
typedef struct {
    V_003919E0 vertices[4];
    u32 color[4];
    f32 uv[8];
    unsigned long flags, texture, primitive, mode;
} Packet_003937E8;
__asm__(".extern D_L01_001DE058, 4");
extern s32 D_L01_001DE058;
__asm__(".extern D_L01_001DE048, 4");
extern s32 D_L01_001DE048;
__asm__(".extern D_L01_001DE044, 4");
extern s32 D_L01_001DE044;
__asm__(".extern D_L01_001DE04C, 4");
extern s32 D_L01_001DE04C;
__asm__(".extern D_L01_001DE050, 4");
extern s32 D_L01_001DE050;
__asm__(".extern D_L01_001DE054, 4");
extern s32 D_L01_001DE054;
__asm__(".extern D_L01_001DE05C, 4");
extern s32 D_L01_001DE05C;
__asm__(".extern D_L01_001DE060, 4");
extern f32 D_L01_001DE060;
__asm__(".extern D_L01_001DDFFC, 4");
extern f32 D_L01_001DDFFC;
extern s16 D_L01_002BA0E0[][8];
extern f32 D_L01_002B9880[][4];
extern f32 D_L01_002BA9E0[][2];
extern V_003919E0 D_L01_001E2A40[];
extern u8 **D_L01_001E2020;
void func_L01_003937E8(u8 *moby) {
    extern unsigned long func_00389598(s32);
    extern void func_0038D000(f32 *, f32 *, f32 *);
    extern f32 func_0038CED8(f32 *);
    extern f32 func_L01_004451A8(f32);
    extern void func_003D2DA0(void *, s32, s32);
    extern void func_L01_00393EF8(void *, s32, f32, f32, s32);
    Packet_003937E8 packet;
    V_003919E0 matrix[3], view, center, saved, edge0, edge1;
    u8 *vars = *(u8 **)(moby + 0x68);
    s32 face = 0;
    packet.texture = func_00389598(D_L01_001DE058);
    qzero(&matrix[0]);
    qzero(&matrix[1]);
    qzero(&matrix[2]);
    packet.primitive = 0xFF9000000260UL;
    packet.mode = (unsigned long)D_L01_001DE044 | ((unsigned long)D_L01_001DE048 << 2) |
        ((unsigned long)D_L01_001DE04C << 4) | ((unsigned long)D_L01_001DE050 << 6) |
        ((unsigned long)D_L01_001DE054 << 32);
    packet.flags = 0;
    matrix[0].f[0] = 1.0f + *(f32 *)(vars + 0x10) * 0.0625f;
    matrix[1].f[1] = 1.0f + *(f32 *)(vars + 0x10) * 0.0625f;
    matrix[2].f[2] = 1.0f;
    packet.color[0] = D_L01_001DE05C + (*(s32 *)(vars + 0x1C) << 24);
    packet.color[1] = packet.color[0];
    packet.color[2] = packet.color[0];
    packet.color[3] = packet.color[0];
    do {
        s16 *indices = D_L01_002BA0E0[face];
        V_003919E0 *vertex = packet.vertices;
        f32 *u = packet.uv, *v = packet.uv + 1;
        s32 count = 3;
        do {
            s32 texcoord = indices[1];
            func_0038CE20(vertex->f, D_L01_002B9880[indices[0]], D_L01_001DE060);
            vertex++;
            *u = D_L01_002BA9E0[texcoord][0];
            *v = D_L01_002BA9E0[texcoord][1] - D_L01_001DDFFC;
            indices += 2;
            u += 2;
            v += 2;
        } while (--count >= 0);
        qzero(&center);
        vertex = packet.vertices;
        count = 3;
        do {
            f32 length, bump, z;
            func_0038D000(vertex->f, vertex->f, matrix[0].f);
            length = func_0038CED8(vertex->f);
            bump = 1.5f - length / 1.5f;
            if (bump < 0.0f) bump = 0.0f;
            bump = func_L01_004451A8(bump / 1.5f) * 1.5f;
            z = vertex->f[2] + bump * *(f32 *)(vars + 0x10) * 0.00825f;
            vertex->f[2] = z;
            vertex->f[2] = z + *(f32 *)(vars + 0x10) * 0.15f;
            func_0038D000(vertex->f, vertex->f, (f32 *)(moby + 0xC0));
            vertex->f[0] += *(f32 *)(moby + 0x10);
            vertex->f[1] += *(f32 *)(moby + 0x14);
            vertex->f[2] += *(f32 *)(moby + 0x18);
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(center) : "m"(*vertex), "m"(center) : "vf1", "vf2");
            vertex++;
        } while (--count >= 0);
        func_0038CE20(center.f, center.f, 0.25f);
        saved.q = center.q;
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(view) : "m"(center), "m"(D_L01_001E2A40[0]) : "vf1", "vf2");
        func_0038CF68(&view, &view, 1.0f);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(edge0) : "m"(packet.vertices[0]), "m"(packet.vertices[2]) : "vf1", "vf2");
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(edge1) : "m"(packet.vertices[2]), "m"(packet.vertices[1]) : "vf1", "vf2");
        func_0038CE90(center.f, edge0.f, edge1.f);
        func_0038CF68(&center, &center, 1.0f);
        if (func_0038CE68(view.f, center.f) > 0.0f) {
            u8 *effect = D_L01_001E2020[face];
            if (effect == 0 || *(s32 *)(effect + 0x7C) == 0) {
                if (moby[0x20] != 6) {
                    /* retail stores the callee's returned slot pointer; the file declares it void, so call through a cast */
                    D_L01_001E2020[face] = ((u8 *(*)(void *, s32, f32, f32, s32))func_L01_00393EF8)(D_L01_001E2018, 1, 0.0f, 0.0f, (s32)&saved);
                } else if (effect != 0) {
                    D_L01_001E2020[face] = 0;
                }
            }
            if (D_L01_001E2020[face]) *(s128 *)D_L01_001E2020[face] = saved.q;
            func_003D2DA0(&packet, 0, 0);
        }
        face++;
    } while (face < 143);
}
