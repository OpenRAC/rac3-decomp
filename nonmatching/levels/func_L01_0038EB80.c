/* func_L01_0038EB80 (Claude wave 14 r73, 2026-11-28). First draft kept here. */
/* PAL first draft (wr73, wave 14; fresh entry): 515 words differ (wave10/p10/check.py, level 01, the file's
 * flags). Built from the native port's functional C (nonmatching/functional/func_L01_0038EB80.c, 518): vu0.h
 * vec_add_ab for the quad-corner add, a j-form lqc2/vadd/sqc2 sequence for the trail nudge that stores the sum to
 * the point and to a stack copy as retail does (sp+0xF0), and phase 1's matrix translation row (strand position
 * D_L01_0029EE60, w = 1), mode word and colour word that retail writes before the nudge. Still differs: retail
 * keeps a second copy of the nudge loop that scales by 0.25 behind `bnez $7` on a register that is always 0
 * (a pseudo whose zero reload rematerialises; not reproduced), the quad loop keeps seven values in t0-t5/$13
 * across func_0038CE20 with sq/lq caller saves (here other registers), the frame is 0x20 smaller, and the
 * register numbering of the strand loop differs throughout (ours 480 instructions, retail 543). */
#include "common.h"

/* localdecomp:start func_L01_0038EB80 */
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
extern f32 D_L01_0029EE60[][4][4];
extern s32 D_L01_0029ED60[][4];
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
    vu0_v4 sum;
    u32 color;
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
     * overwritten before the only draw in phase 2. */
    for (s = 0; s < 4; s++) {
        func_0038D328(matrix, angles.f);
        matrix[12] = D_L01_0029EE60[v->index][s][0];
        matrix[13] = D_L01_0029EE60[v->index][s][1];
        matrix[15] = 1.0f;
        matrix[14] = D_L01_0029EE60[v->index][s][2];
        packet.mode = (unsigned long)D_001DDFC8_sda | ((unsigned long)D_001DDFCC_sda << 2) |
            ((unsigned long)D_001DDFD0_sda << 4) | ((unsigned long)D_001DDFD4_sda << 6) | 0x8000000000UL;
        color = (D_L01_0029ED60[v->index][s] << 24) | 0x808080;
        packet.color[0] = color;
        packet.color[3] = color;
        packet.color[2] = color;
        packet.color[1] = color;
        for (i = 0; i < 45; i++) {
            if (i % 5 == 0 && i >= 6) {
                vu0_v4 *pt = (vu0_v4 *)&D_L01_00291750[v->index][s][i];
                vu0_q qa, qb;
                func_0038CE20(tmp.f, D_L01_002B62E0[i], D_L01_0029C290[v->index][s][i]);
                __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(tmp));
                __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*pt));
                __asm__("vadd.xyz %0, %0, %1" : "+j"(qa) : "j"(qb));
                __asm__("sqc2 %1, %0" : "=m"(*pt) : "j"(qa));
                __asm__("sqc2 %1, %0" : "=m"(sum) : "j"(qa));
            }
        }
        for (q = 0; q < 42; q++) {
            for (k = 0; k < 4; k++) {
                s32 vi = D_L01_002B5220[q][k * 3];
                s32 ui = D_L01_002B5220[q][k * 3 + 1];
                vu0_v4 *pt = (vu0_v4 *)&D_L01_00291750[v->index][s][vi];
                f32 u, nu;
                vec_add_ab(&tmp, &D_L01_002B4990[vi], pt);
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
/* localdecomp:end func_L01_0038EB80 */
