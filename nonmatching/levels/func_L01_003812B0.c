/* Near miss: func_L01_003812B0 (qwack_beam_pulses_draw). Same instructions as retail, but register allocation differs:
   retail keeps the colour base in $a2 and the pulse index in $a0 (i+1 in $a1), this C gets $v1 and $a1, which moves the
   scheduling of the loads in the loop (53 words differ, all from that). Needs @ps2as and size hints for the $gp globals. */
#include "structs/weapon.h"

typedef int u128_3812B0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3812B0;
typedef struct {
    V_3812B0 v[4];                 /* the quad's corners */
    s32 c[4];                      /* colour of each corner */
    f32 uv[8];
    long t70, tex0, t80, t88;
} Quad_3812B0;

extern u8 D_001425C0[];
extern struct WeaponRow D_L01_002C5600[];
__asm__(".extern D_L01_001DDC30, 4");
__asm__(".extern D_L01_001DDC34, 4");
__asm__(".extern D_L01_001DDC80, 4");
extern s32 D_L01_001DDC30;
extern s32 D_L01_001DDC34;
extern s32 D_L01_001DDC80;
extern u8 D_L01_001E1E80[];
extern f32 D_L01_001E1E70[];
extern f32 D_L01_001E1E50[];
extern V_3812B0 D_L01_001E1E10[];
extern V_3812B0 D_L01_001E1DE0[];
extern V_3812B0 D_001A4EC0[];
extern long func_00389598(s32);
extern void func_0038CE20(void *out, void *in, f32 scale);
extern void func_0038CE90(void *out, void *a, void *b);
extern void func_0038CF68(void *out, void *in, f32 length);
extern void func_0038D028(void *out, void *in, void *matrix);
extern void func_003D2DA0(void *quad, s32 a1, s32 a2);

/* qwack_beam_pulses_draw: the Qwack-O-Ray beam's pulses, up to three: every 45 frames a ring of 8 runs from the gun at 8 u/s, growing from half 0.1 to 1.5 */
void func_L01_003812B0(void) {
    Quad_3812B0 quad;
    V_3812B0 rows[4];              /* the pulse's matrix: x, y, z axes and position */
    V_3812B0 scaled;
    s32 base;
    s32 i;
    s32 k;
    s32 alpha;

    quad.tex0 = func_00389598(8);
    quad.t88 = 0x8000000048L;
    quad.t80 = 0xFF9000000260L;
    quad.t70 = 0;
    quad.uv[0] = 0.0f;
    quad.uv[1] = 0.0f;
    quad.uv[2] = 0.0f;
    quad.uv[3] = 1.0f;
    quad.uv[4] = 1.0f;
    quad.uv[5] = 0.0f;
    quad.uv[6] = 1.0f;
    quad.uv[7] = 1.0f;
    base = ((D_L01_002C5600 + D_001425C0[0x8F])->level < 4 ? D_L01_001DDC30 : D_L01_001DDC34) & 0xFFFFFF;
    for (i = 0; i < 3; i++) {
        if (D_L01_001E1E80[i] == 0) continue;
        alpha = (s32)D_L01_001E1E50[i];
        rows[0] = D_L01_001E1E10[i];
        rows[3] = D_L01_001E1DE0[i];
        quad.c[0] = base | (alpha << 24);
        quad.c[1] = quad.c[0];
        quad.c[2] = quad.c[0];
        quad.c[3] = quad.c[0];
        func_0038CE20(&rows[2], D_001A4EC0, -1.0f);
        func_0038CE90(&rows[1], &rows[0], &rows[2]);
        func_0038CF68(&rows[1], &rows[1], 1.0f);
        func_0038CE90(&rows[2], &rows[1], &rows[0]);
        for (k = 0; k < 4; k++) {
            func_0038CE20(&scaled, &((V_3812B0 *)&D_L01_001DDC80)[k], D_L01_001E1E70[i]);
            func_0038D028(&quad.v[k], &scaled, rows);
        }
        func_003D2DA0(&quad, 0, 0);
    }
}
