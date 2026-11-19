/* functional: medium. Written from asm (no draft), 518 diff (frame 0x30 smaller: retail has dead stores). Omitted deliberately: dead strand vector at sp+0xC0, dead mode/colour word and sqc2 to sp+0xF0 in phase 1, and the unreachable bnez $7 (const 0) branch that scales by 0.25; phase-1 packet writes are stack-only and overwritten. Declares D_L01_00291750 etc. itself (this is the file's first function; later decls in the file are the same) */
#include "common.h"
#include "vu0.h"
typedef struct { f32 vertices[16]; u32 color[4]; f32 uv[8]; unsigned long zero, texture, flags, mode; } Packet_0038EB80;
typedef struct { u8 pad0[0x140]; f32 pos[4]; } Camera_0038EB80;
typedef struct { s32 index; f32 scale; s32 pad8; s32 stamp; } Vars_0038EB80;
typedef struct { f32 f[4]; } __attribute__((aligned(16))) Vec_0038EB80;
extern Camera_0038EB80 D_L01_001E2880;
extern s32 D_001DFB40;
extern s32 D_001DDFC8_sda, D_001DDFCC_sda, D_001DDFD0_sda, D_001DDFD4_sda;
extern f32 D_001DDFD8_sda, D_001DDFDC_sda;
__asm__(".extern D_001DDFC8_sda, 4");
__asm__(".extern D_001DDFCC_sda, 4");
__asm__(".extern D_001DDFD0_sda, 4");
__asm__(".extern D_001DDFD4_sda, 4");
__asm__(".extern D_001DDFD8_sda, 4");
__asm__(".extern D_001DDFDC_sda, 4");
extern f32 D_L01_002B62E0[][4];
extern vu0_v4 D_L01_002B4990[];
extern s16 D_L01_002B5220[][12];
extern f32 D_L01_002B5E20[][2];
extern s32 D_L01_001E1FF8[];
extern vu0_q D_L01_00291750[][4][137];
extern f32 D_L01_0029C290[][4][137];
extern f32 D_L01_001E1F50[] __attribute__((section(".sdata")));
extern s32 D_L01_001E1F68[] __attribute__((section(".sdata")));
extern s32 D_L01_001E1FE0[] __attribute__((section(".sdata")));
extern s32 D_L01_001E1F98[] __attribute__((section(".sdata")));
void func_L01_0038EB80(u8 *obj) {
    extern unsigned long func_00389598(s32);
    extern void func_003A9440(s32, unsigned long);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038CF38(f32 *, f32 *);
    extern void func_0038D328(f32 *, f32 *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_003D2DA0(void *, void *, s32);
    extern s32 func_0038CAD0(void *);
    extern void func_003C2880(u8 *);
    Packet_0038EB80 packet;
    f32 matrix[16];
    Vec_0038EB80 angles;
    Vec_0038EB80 tmp;
    Vars_0038EB80 *v = *(Vars_0038EB80 **)(obj + 0x68);
    s32 s, i, q, k;
    packet.texture = func_00389598(0x39);
    packet.flags = 0xFF9000000260UL;
    packet.zero = 0;
    func_003A9440(0x47, 0x53001);
    angles.f[0] = *(f32 *)(obj + 0xF0);
    angles.f[3] = 0.0f;
    angles.f[2] = func_0038D160(D_L01_001E2880.pos[0] - *(f32 *)(obj + 0x10), D_L01_001E2880.pos[1] - *(f32 *)(obj + 0x14));
    angles.f[1] = -func_0038D160(func_0038CF38((f32 *)(obj + 0x10), D_L01_001E2880.pos), D_L01_001E2880.pos[2] - *(f32 *)(obj + 0x18));
    /* phase 1: per strand, retail rebuilds the camera matrix, nudges every 5th
     * point of the strand's trail (i = 10..40) and walks the 42 quads writing
     * the scrolling u coordinate back to the table; the packet it fills here is
     * overwritten before the only draw in phase 2. Retail also builds a dead
     * strand-position vector and a dead mode/colour word; omitted. */
    for (s = 0; s < 4; s++) {
        func_0038D328(matrix, angles.f);
        for (i = 0; i < 45; i++) {
            if (i % 5 == 0 && i >= 6) {
                vu0_v4 *pt = (vu0_v4 *)&D_L01_00291750[v->index][s][i];
                func_0038CE20(tmp.f, D_L01_002B62E0[i], D_L01_0029C290[v->index][s][i]);
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(*pt) : "m"(*pt), "m"(tmp) : "vf1", "vf2");
            }
        }
        for (q = 0; q < 42; q++) {
            for (k = 0; k < 4; k++) {
                s32 vi = D_L01_002B5220[q][k * 3];
                s32 ui = D_L01_002B5220[q][k * 3 + 1];
                vu0_v4 *pt = (vu0_v4 *)&D_L01_00291750[v->index][s][vi];
                f32 u, nu;
                __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                    : "=m"(tmp) : "m"(D_L01_002B4990[vi]), "m"(*pt) : "vf1", "vf2");
                func_0038CE20(&packet.vertices[k * 4], tmp.f, D_001DDFD8_sda * v->scale);
                u = D_L01_002B5E20[ui][0];
                packet.uv[k * 2] = u;
                packet.uv[k * 2 + 1] = D_L01_002B5E20[ui][1];
                nu = u + 0.0001f;
                D_L01_002B5E20[ui][0] = nu;
                if (8.0f < nu) D_L01_002B5E20[ui][0] = nu - 8.0f;
            }
        }
    }
    /* phase 2: the one billboard quad at the object */
    packet.texture = func_00389598(0x39);
    packet.flags = 0xFF9000000260UL;
    packet.zero = 0;
    packet.mode = (unsigned long)D_001DDFC8_sda | ((unsigned long)D_001DDFCC_sda << 2) |
        ((unsigned long)D_001DDFD0_sda << 4) | ((unsigned long)D_001DDFD4_sda << 6) |
        ((unsigned long)D_L01_001E1F68[v->index] << 32);
    packet.vertices[0] = 0.0f;  packet.vertices[1] = -2.0f; packet.vertices[2] = -2.0f;
    packet.vertices[4] = 0.0f;  packet.vertices[5] = -2.0f; packet.vertices[6] = 2.0f;
    packet.vertices[8] = 0.0f;  packet.vertices[9] = 2.0f;  packet.vertices[10] = -2.0f;
    packet.vertices[12] = 0.0f; packet.vertices[13] = 2.0f; packet.vertices[14] = 2.0f;
    packet.color[0] = 0x7F204080;
    packet.color[1] = 0x7F204080;
    packet.color[2] = 0x7F204080;
    packet.color[3] = 0x7F204080;
    packet.uv[0] = 0.0f; packet.uv[1] = 0.0f;
    packet.uv[2] = 1.0f; packet.uv[3] = 0.0f;
    packet.uv[4] = 0.0f; packet.uv[5] = 1.0f;
    packet.uv[6] = 1.0f; packet.uv[7] = 1.0f;
    func_0038D328(matrix, angles.f);
    func_0038CE20(&packet.vertices[0], &packet.vertices[0], D_L01_001E1F50[v->index] * v->scale);
    func_0038CE20(&packet.vertices[4], &packet.vertices[4], D_L01_001E1F50[v->index] * v->scale);
    func_0038CE20(&packet.vertices[8], &packet.vertices[8], D_L01_001E1F50[v->index] * v->scale);
    func_0038CE20(&packet.vertices[12], &packet.vertices[12], D_L01_001E1F50[v->index] * v->scale);
    matrix[12] = *(f32 *)(obj + 0x10);
    matrix[13] = *(f32 *)(obj + 0x14);
    matrix[14] = *(f32 *)(obj + 0x18);
    matrix[15] = 1.0f;
    func_003D2DA0(&packet, matrix, 0);
    /* phase 3: grow/fade once per frame stamp, destroy when faded out */
    if (v->stamp != D_001DFB40) {
        D_L01_001E1F50[v->index] += 0.4f;
        D_L01_001E1F68[v->index] -= 5;
        if (D_L01_001E1F68[v->index] < 0) D_L01_001E1F68[v->index] = 0;
        if (v->stamp != D_001DFB40 && func_0038CAD0(&D_L01_001E1FE0[v->index])) {
            D_L01_001E1F98[v->index] -= 8;
            if (D_L01_001E1F98[v->index] < 0) {
                f32 left = D_001DDFDC_sda - 1.0f;
                D_L01_001E1F98[v->index] = 0;
                D_L01_001E1FF8[v->index] = 0;
                D_001DDFDC_sda = left;
                func_003C2880(obj);
                return;
            }
        }
    }
    func_003A9440(0x47, 0x5360B);
    v->stamp = D_001DFB40;
}
