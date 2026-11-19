/* functional: medium. Near-miss draft from the PAL assembly (Codex waves), re-checked at level 01: compiles in the file context with relocations resolved (callees/globals as retail); 196 words differ in VU0 ordering/register allocation; not byte-identical, behaviour as retail. */
#include "vu0.h"
typedef struct { s16 age, life, active; s16 pad6; f32 start, end, fade; s32 pad14; s32 glow, background; u8 pad20[0x18]; s32 beam; } State_0031F2E8;
typedef struct { u8 pad[0x150]; s16 width, height; } Screen_0031F2E8;
typedef struct { f32 position[4][4]; u32 color[4]; f32 uv[8]; u8 pad[0x20]; } __attribute__((aligned(16))) Packet_0031F2E8;
static __inline__ void sub_0031F2E8(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void add_0031F2E8(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
extern Screen_0031F2E8 D_001CFEC0;
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern s32 D_001D52F0;
extern u8 D_L01_001E2A40[] __attribute__((section(".sdata")));
void func_L01_0031F2E8(u8 *object) {
    extern void func_003A9440(s32, s32);
    extern void func_0038AF30(s32, s32, s32, s32, u32);
    extern void func_L01_0031F688(u8 *, s32, s32, f32, f32, f32, f32, f32);
    extern void func_003C5180(u8 *, f32 *, s32);
    extern s32 func_003D93B0(void *, s32, s32, s32);
    extern void func_0038CF68(f32 *, s32, f32);
    extern void func_0038CE90(f32 *, f32 *, f32 *);
    extern void func_003D2DA0(void *, s32, s32);
    Packet_0031F2E8 packet;
    f32 normal[4], direction[4], scaled[4], center[4], side[4], up[4], corner[4];
    State_0031F2E8 *s = *(State_0031F2E8 **)(object + 0x68);
    u8 *position = object + 0x10;
    f32 alpha;
    u32 color;
    if (s->life - s->age < 2 && s->active != 0 && s->background != 0) {
        func_003A9440(0x42, 0x48);
        func_0038AF30(0, D_001CFEC0.height, 0, D_001CFEC0.width, 0x80808080);
    }
    if (s->glow != 0) {
        if (s->life - s->age < 10) {
            f32 blend = (s->life - s->age) / 10.0f;
            func_L01_0031F688(position, 0x3B, 0, s->start + (s->end - s->start) * blend, 0.5f, 0.0f, 0.0f, 0.0f);
        } else if ((u16)(s->age - 46) < 4) {
            f32 blend = (s->age - 45) / 10.0f;
            func_L01_0031F688(position, 0x3B, 0, s->start + (s->end - s->start) * blend, 0.5f, 0.0f, 0.0f, 0.0f);
        }
    }
    if (s->active != 0 && D_001D545C_sda != 13 && D_001D545C_sda != 16 && s->beam != 0) {
        func_003C5180(position, normal, 1);
        alpha = s->active * s->fade;
        func_003D93B0(&packet, 11, 4, 128);
        alpha *= 255.0f;
        color = ((s32)alpha << 24) | 0xFFFFFF;
        packet.color[0] = packet.color[1] = packet.color[2] = packet.color[3] = color;
        packet.uv[0] = 0.0f;
        packet.uv[1] = 0.0f;
        packet.uv[2] = 0.0f;
        packet.uv[3] = 1.0f;
        packet.uv[4] = 1.0f;
        packet.uv[5] = 0.0f;
        packet.uv[6] = 1.0f;
        packet.uv[7] = 1.0f;
        sub_0031F2E8(direction, position, D_L01_001E2A40 + D_001D52F0 * 0x460);
        func_0038CF68(scaled, (s32)direction, 0.1f);
        add_0031F2E8(center, D_L01_001E2A40 + D_001D52F0 * 0x460, scaled);
        func_0038CE90(side, direction, normal);
        func_0038CF68(side, (s32)side, 0.075f);
        func_0038CE90(up, side, direction);
        func_0038CF68(up, (s32)up, 0.075f);
        add_0031F2E8(corner, center, up);
        add_0031F2E8(packet.position[0], side, corner);
        sub_0031F2E8(packet.position[1], corner, side);
        sub_0031F2E8(corner, center, up);
        add_0031F2E8(packet.position[2], side, corner);
        sub_0031F2E8(packet.position[3], corner, side);
        func_003D2DA0(&packet, 0, 0);
    }
}
