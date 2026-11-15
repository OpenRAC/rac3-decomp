#include "common.h"

/* declared by functions of L08_0037CD98.c, which this file was cut from */
typedef int q_0037CD98 __attribute__((mode(TI)));

/* localdecomp:start func_L08_0037D450 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0037D450;
typedef struct {
    V_0037D450 h[3];
    V_0037D450 v[8][8];
    V_0037D450 uv[8][8];
    f32 a[8][8];
    f32 b[8][8];
} E_0037D450;
typedef struct {
    V_0037D450 m[4];
    s32 c40, c44, c48, c4C;
    f32 uv[4][2];
    long x70, x78, x80, x88;
} S_0037D450;
extern E_0037D450 D_0028FF60[];
extern f32 D_001DDA80;
__asm__(".extern D_001DDA80, 4");
extern void func_00389478(void *, f32 *, f32 *);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, void *, s32);

void func_L08_0037D450(void) {
    S_0037D450 s;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 n;
    s32 c;
    f32 d;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 8; j++) {
            for (k = 0; k < 8; k++) {
                func_00389478(&D_0028FF60[i].v[j][k], &D_0028FF60[i].uv[j][k].x, &D_0028FF60[i].uv[j][k].y);
                D_0028FF60[i].a[j][k] = func_0038D0B0(D_0028FF60[i].b[j][k] = func_0038DAB8(D_0028FF60[i].b[j][k], func_003824E0(0.0f, 4.0f) * 0.017453292f)) * 0.5f + 0.5f;
                d = D_001DDA80;
                D_0028FF60[i].uv[j][k].x += d + (-d - d) * D_0028FF60[i].a[j][k];
                D_0028FF60[i].uv[j][k].y += -d + (d + d) * D_0028FF60[i].a[j][k];
            }
        }
        s.x78 = func_00389598(-1);
        s.x80 = 0xFF9000000260L;
        s.x70 = 5;
        s.x88 = 0x8000000000L;
        c = 0x80808080;
        s.c4C = c;
        s.c48 = c;
        s.c44 = c;
        s.c40 = c;
        for (m = 0; m < 7; m++) {
            for (n = 0; n < 7; n++) {
                *(q_0037CD98 *)&s.m[0] = *(q_0037CD98 *)&D_0028FF60[i].v[m + 1][n];
                *(q_0037CD98 *)&s.m[1] = *(q_0037CD98 *)&D_0028FF60[i].v[m][n];
                *(q_0037CD98 *)&s.m[2] = *(q_0037CD98 *)&D_0028FF60[i].v[m + 1][n + 1];
                *(q_0037CD98 *)&s.m[3] = *(q_0037CD98 *)&D_0028FF60[i].v[m][n + 1];
                s.uv[0][0] = D_0028FF60[i].uv[m + 1][n].x;
                s.uv[0][1] = D_0028FF60[i].uv[m + 1][n].y;
                s.uv[1][0] = D_0028FF60[i].uv[m][n].x;
                s.uv[1][1] = D_0028FF60[i].uv[m][n].y;
                s.uv[2][0] = D_0028FF60[i].uv[m + 1][n + 1].x;
                s.uv[2][1] = D_0028FF60[i].uv[m + 1][n + 1].y;
                s.uv[3][0] = D_0028FF60[i].uv[m][n + 1].x;
                s.uv[3][1] = D_0028FF60[i].uv[m][n + 1].y;
                func_003D2DA0(&s, 0, 0);
            }
        }
    }
}
/* localdecomp:end func_L08_0037D450 */
