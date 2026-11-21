/* functional: high. Draft read against asm; second pass sets colours to -1. VU0 inline asm only. */
#include "common.h"
/* localdecomp:start func_L01_00381500 */
typedef int Q_00381500 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00381500;
typedef struct { Q_00381500 pos[4]; s32 color[4]; f32 uv[8]; long zero, texture, tex1, alpha; } Quad_00381500;
extern Q_00381500 D_001DDC80_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001DDC80_sda, 4");
extern f32 D_001DDCC0_sda;
extern f32 D_001DDCC4_sda;
extern f32 D_001DDCC8_sda;
extern s32 D_001DDCCC_sda;
__asm__(".extern D_001DDCC0_sda, 4");
__asm__(".extern D_001DDCC4_sda, 4");
__asm__(".extern D_001DDCC8_sda, 4");
__asm__(".extern D_001DDCCC_sda, 4");
extern V_00381500 D_L01_0028F5A0_00381500;
extern V_00381500 D_L01_001E29C0_00381500;
extern Q_00381500 D_001A4EC0_00381500;
void func_L01_00381500(u8 *moby) {
    extern long func_00389598(s32);
    extern void func_0038CE20(Q_00381500 *, Q_00381500 *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    Quad_00381500 q;
    Q_00381500 matrix[4];
    struct { Q_00381500 temp, dir; } v;
    s32 i;
    q.texture = func_00389598(11);
    q.tex1 = 0xFF9000000260L;
    q.alpha = 0x8000000048L;
    q.color[0] = q.color[1] = q.color[2] = q.color[3] = D_001DDCCC_sda;
    q.zero = 0;
    q.uv[0] = 0.0f; q.uv[1] = 0.0f;
    q.uv[2] = 0.0f; q.uv[3] = 1.0f;
    q.uv[4] = 1.0f; q.uv[5] = 0.0f;
    q.uv[6] = 1.0f; q.uv[7] = 1.0f;
    func_0038CF68(&v.dir, moby + 0xD0, D_001DDCC8_sda);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
      : "=m"(matrix[3]) : "m"(v.dir), "m"(D_L01_0028F5A0_00381500) : "vf1", "vf2");
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
      : "=m"(v.dir) : "m"(D_L01_001E29C0_00381500), "m"(matrix[3]) : "vf1", "vf2");
    func_0038CF68(&matrix[0], &v.dir, 1.0f);
    func_0038CE90(&matrix[1], &matrix[0], &D_001A4EC0_00381500);
    func_0038CF68(&matrix[1], &matrix[1], -1.0f);
    func_0038CE90(&matrix[2], &matrix[1], &matrix[0]);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&v.temp, &D_001DDC80_sda[i], D_001DDCC0_sda);
        func_0038D028(&q.pos[i], &v.temp, matrix);
    }
    func_003D2DA0(&q, 0, 0);
    q.color[0] = q.color[1] = q.color[2] = q.color[3] = -1;
    for (i = 0; i < 4; i++) {
        func_0038CE20(&v.temp, &D_001DDC80_sda[i], D_001DDCC4_sda);
        func_0038D028(&q.pos[i], &v.temp, matrix);
    }
    func_003D2DA0(&q, 0, 0);
}
/* localdecomp:end func_L01_00381500 */
