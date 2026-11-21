/* functional: high. Draft 6 diff (instruction order only); verified packet layout, scale 1.0/1.0/0.125 (0x3E000000), loops 64x4, uv tables 2B7470/2B7474 against asm */
#include "common.h"
#include "vu0.h"
typedef struct {
    vu0_v4 vertices[4];
    u32 colors[4];
    float uv[4][2];
    unsigned long header, texture, flags, blend;
    vu0_v4 matrix[3];
} Packet_00393150;
extern int D_001DE018_sda, D_001DE008_sda, D_001DE004_sda;
extern int D_001DE00C_sda, D_001DE010_sda, D_001DE014_sda, D_001DE01C_sda;
extern float D_001DE020_sda;
extern s16 D_L01_002B7070_00393150[][8];
extern float D_L01_002B6B70_00393150[][4];
extern float D_L01_002B7470_00393150[][2];
extern float D_L01_002B7474_00393150[][2];
__asm__(".extern D_001DE004_sda, 4");
__asm__(".extern D_001DE008_sda, 4");
__asm__(".extern D_001DE00C_sda, 4");
__asm__(".extern D_001DE010_sda, 4");
__asm__(".extern D_001DE014_sda, 4");
__asm__(".extern D_001DE018_sda, 4");
__asm__(".extern D_001DE01C_sda, 4");
__asm__(".extern D_001DE020_sda, 4");
void func_L01_00393150(u8 *obj) {
    extern unsigned long func_00389598(int);
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_003D2DA0(void *, int, int);
    Packet_00393150 packet;
    vu0_v4 normal;
    u8 *vars = *(u8 **)(obj + 0x68);
    void *rotation = obj + 0xC0;
    int i, j;
    float *baseU; float *baseV;
    packet.texture = func_00389598(D_001DE018_sda);
    packet.blend = D_001DE004_sda | ((long)D_001DE008_sda << 2) | ((long)D_001DE00C_sda << 4) | ((long)D_001DE010_sda << 6) | ((long)D_001DE014_sda << 32);
    qzero(&packet.matrix[0]);
    qzero(&packet.matrix[1]);
    qzero(&packet.matrix[2]);
    packet.flags = 0xFF9000000260;
    packet.header = 0;
    packet.matrix[0].x = *(float *)(vars + 0x10);
    packet.matrix[1].y = *(float *)(vars + 0x10);
    packet.matrix[2].z = *(float *)(vars + 0x10) * 0.125f;
    { u32 c = D_001DE01C_sda + (*(int *)(vars + 0x24) << 24);
    packet.colors[3] = c; packet.colors[2] = c; packet.colors[1] = c; packet.colors[0] = c; }
    func_003C5180(obj + 0x10, &normal, 1);
    baseU = &packet.uv[0][0]; baseV = &packet.uv[0][1];
    for (i = 0; i < 64; i++) {
        float *v;
        float *u;
        s16 *row = D_L01_002B7070_00393150[i];
        vu0_v4 *vert = packet.vertices;
        v = baseV;
        u = baseU;
        for (j = 3; j >= 0; j--) {
            int uv = row[1];
            func_0038CE20((float *)vert, D_L01_002B6B70_00393150[row[0]], D_001DE020_sda);
            *u = D_L01_002B7470_00393150[uv][0];
            *v = D_L01_002B7474_00393150[uv][0];
            func_0038D000(vert, vert, packet.matrix);
            func_0038D000(vert, vert, rotation);
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*vert) : "m"(*vert), "m"(*(vu0_v4 *)(obj+0x10)) : "vf1", "vf2");
            func_0038CF68(&normal, &normal, 0.5f);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*vert) : "m"(*vert), "m"(normal) : "vf1", "vf2");
            row += 2; u += 2; v += 2; vert++;
        }
        func_003D2DA0(&packet, 0, 0);
    }
}
