/* functional: high. Codex near-miss draft (189 words differ, interleaving and loop allocation only); I re-read it against the retail asm block by block: basis from D_001E2A40 - pos, optional rotation by param 5, 4 corners from D_001D7C50 scaled by width, centroid of 4 vertices, UV from vertex-centroid*scale via func_00389478, two draws with modes 0x800000004A and 0x2000000054, GS regs 71 set to 0x31001, 0x53001, 0x5360B. Same behaviour. */
#include "common.h"
#include "vu0.h"
typedef struct {
    s128 vertices[4];
    u32 color[4];
    f32 uv[8];
    u8 pad70[0x18];
    unsigned long mode;
} Packet_0038D180;
extern s128 D_L01_001E2A40[];
extern s128 D_001A4EC0[];
extern s128 D_L01_001D7C50[];
void func_L01_0038D180(s128 *position, s32 texture, f32 width, f32 offset, f32 rotation, f32 scale) {
    extern void func_0038CE20(s128 *, s128 *, f32);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038D308(void *, void *);
    extern void func_0038D5F0(void *, void *, void *);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    extern void func_00389478(void *, void *, void *);
    Packet_0038D180 packet;
    struct { s128 basis[3]; s128 pos; S_38C110v temp; union { s128 rotation[3]; struct { s128 center; s128 adjusted; } points; } work; } frame;
    s32 i;

    func_003D93B0(&packet, texture, 1, 128);
    frame.pos = *position;
    packet.mode = 0x800000004AUL;
    packet.color[0] = 0x80808080;
    packet.color[1] = 0x80808080;
    packet.color[2] = 0x80808080;
    packet.color[3] = 0x80808080;
    packet.uv[0] = 0.0f;
    packet.uv[1] = 0.0f;
    packet.uv[2] = 0.0f;
    packet.uv[3] = 1.0f;
    packet.uv[4] = 1.0f;
    packet.uv[5] = 0.0f;
    packet.uv[6] = 1.0f;
    packet.uv[7] = 1.0f;
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(frame.basis[0]) : "m"(D_L01_001E2A40[0]), "m"(frame.pos) : "vf1", "vf2");
    func_0038CF68(&frame.basis[0], &frame.basis[0], 1.0f);
    func_0038CE90(&frame.basis[1], &frame.basis[0], D_001A4EC0);
    func_0038CF68(&frame.basis[1], &frame.basis[1], 1.0f);
    func_0038CE90(&frame.basis[2], &frame.basis[1], &frame.basis[0]);
    if (rotation != 0.0f) {
        *(s128 *)&frame.temp = 0;
        frame.temp.x = rotation;
        func_0038D308(frame.work.rotation, &frame.temp);
        func_0038D5F0(&frame.basis[0], &frame.basis[0], frame.work.rotation);
    }
    func_0038CE20((s128 *)&frame.temp, &frame.basis[0], offset);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(frame.pos) : "m"(frame.pos), "m"(*(s128 *)&frame.temp) : "vf1", "vf2");
    { s128 *corner = D_L01_001D7C50;
    s128 *v = packet.vertices;
    i = 3;
    do {
        func_0038CE20(v, corner++, width);
        func_0038D028(v, v, &frame.basis[0]);
        v++;
    } while (--i >= 0);
    }
    func_003A9440(71, 0x31001);
    func_003D2DA0(&packet, 0, 0);
    frame.work.points.center = packet.vertices[0];
    { s128 *v = &packet.vertices[1];
    i = 2;
    do {
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(frame.work.points.center) : "m"(*v++), "m"(frame.work.points.center) : "vf1", "vf2");
    } while (--i >= 0);
    }
    func_0038CE20(&frame.work.points.center, &frame.work.points.center, 0.25f);
    { s128 *v = packet.vertices;
    f32 *uv = packet.uv;
    f32 *uv2 = packet.uv + 1;
    i = 3;
    do {
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(frame.work.points.adjusted) : "m"(*v), "m"(frame.work.points.center) : "vf1", "vf2");
        func_0038CE20(&frame.work.points.adjusted, &frame.work.points.adjusted, scale);
        v++;
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(frame.work.points.adjusted) : "m"(frame.work.points.center), "m"(frame.work.points.adjusted) : "vf1", "vf2");
        func_00389478(&frame.work.points.adjusted, uv, uv2);
        uv += 2;
        uv2 += 2;
    } while (--i >= 0);
    }
    func_003D93B0(&packet, -1, 1, 128);
    packet.mode = 0x2000000054UL;
    func_003A9440(71, 0x53001);
    func_003D2DA0(&packet, 0, 0);
    func_003A9440(71, 0x5360B);
}
