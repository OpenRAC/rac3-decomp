/* PAL near miss (opus-w18): 4 words differ with the file's flags (-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as; no divs_nops/sq_ra row); only the second up-vector setup before func_0038D308 differs: retail stores up.x, up.z then up.y in the jal slot, this C schedules up.y first and up.z in the slot. The t3 copy and the cols pointer are load-bearing: t3 sets gcse's expression table to 215 buckets, which gives retail's spill-slot order for the hoisted &c[]/&sq[] addresses. */
#include "common.h"
/* localdecomp:start func_L01_003365C0 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003365C0;
typedef struct {
    V4_003365C0 pos[4];
    u32 color[4];
    f32 uv[4][2];
    unsigned long w70, w78, w80, w88;
} Pkt_003365C0;
typedef struct {
    u8 pad[0x158];
    f32 roll;
} Cam_003365C0;
extern Cam_003365C0 D_L01_001E2880;
extern V4_003365C0 D_L01_002AF4C0[];
extern f32 D_L01_002AF550[][2];
extern u32 D_L01_002AF598[];
extern s32 D_L01_001DCF38[4][4] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DCF38, 4");
extern f32 D_L01_001DCF78;
__asm__(".extern D_L01_001DCF78, 4");
extern f32 D_L01_001DCF7C;
__asm__(".extern D_L01_001DCF7C, 4");
void func_L01_003365C0(u8 *m)
{
    extern void func_0038D308(void *, void *);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern unsigned long func_00389598(s32);
    extern void func_003D2DA0(void *, void *, s32);
    Pkt_003365C0 pkt;
    V4_003365C0 c[4];
    V4_003365C0 up;
    V4_003365C0 mat[3];
    V4_003365C0 sq[4];
    V4_003365C0 tmp[4];
    u8 *p;
    s32 i, j;
    s32 q0, q1, q2, q3;
    s32 t3;
    f32 t, a, na, z1, z2;
    u32 color;
    u8 *cols;

    p = *(u8 **)(m + 0x68);
    up.x = 0.0f;
    up.y = 0.0f;
    up.z = D_L01_001E2880.roll;
    func_0038D308(mat, &up);
    D_L01_001DCF78 += 0.01f;
    if (1.0f < D_L01_001DCF78) D_L01_001DCF78 -= 1.0f;
    pkt.w70 = 0;
    pkt.w80 = 1;
    pkt.w88 = 0x4000000044UL;
    pkt.w78 = func_00389598(0x18);
    for (i = 0; i < 4; i++) {
        func_0038D000(&c[0], &D_L01_002AF4C0[D_L01_001DCF38[i][0]], mat);
        func_0038D000(&c[1], &D_L01_002AF4C0[D_L01_001DCF38[i][1]], mat);
        cols = (u8 *)D_L01_002AF598;
        func_0038D000(&c[2], &D_L01_002AF4C0[D_L01_001DCF38[i][2]], mat);
        func_0038D000(&c[3], &D_L01_002AF4C0[D_L01_001DCF38[i][3]], mat);
        for (j = 0; j < 4; j++) {
            func_0038CE20(&c[j], &c[j], 0.5f);
        }
        pkt.pos[0].x = *(f32 *)(m + 0x10) + c[0].x * *(f32 *)(p + 0x90);
        pkt.pos[0].y = *(f32 *)(m + 0x14) + c[0].y * *(f32 *)(p + 0x90);
        pkt.pos[0].z = ((*(f32 *)(m + 0x18) + c[0].z) - 1.0f) + 1.45f;
        pkt.pos[1].x = *(f32 *)(m + 0x10) + c[1].x * *(f32 *)(p + 0x90);
        pkt.pos[1].y = *(f32 *)(m + 0x14) + c[1].y * *(f32 *)(p + 0x90);
        pkt.pos[1].z = ((*(f32 *)(m + 0x18) + c[1].z) - 1.0f) + 1.45f;
        pkt.pos[2].x = *(f32 *)(m + 0x10) + c[2].x * *(f32 *)(p + 0x90);
        pkt.pos[2].y = *(f32 *)(m + 0x14) + c[2].y * *(f32 *)(p + 0x90);
        pkt.pos[2].z = ((*(f32 *)(m + 0x18) + c[2].z) - 1.0f) + 1.45f;
        pkt.pos[3].x = *(f32 *)(m + 0x10) + c[3].x * *(f32 *)(p + 0x90);
        pkt.pos[3].y = *(f32 *)(m + 0x14) + c[3].y * *(f32 *)(p + 0x90);
        pkt.pos[3].z = ((*(f32 *)(m + 0x18) + c[3].z) - 1.0f) + 1.45f;
        q0 = D_L01_001DCF38[i][0];
        t3 = D_L01_001DCF38[i][3];
        q1 = D_L01_001DCF38[i][1];
        q2 = D_L01_001DCF38[i][2];
        q3 = t3;
        { s32 k = q0 * 4 + 36; if (*(s32 *)(p + 0x94) != 2) k = q0 * 4; pkt.color[0] = *(u32 *)(k + (s32)cols); }
        { s32 k = q1 * 4 + 36; if (*(s32 *)(p + 0x94) != 2) k = q1 * 4; pkt.color[1] = *(u32 *)(k + (s32)cols); }
        { s32 k = q2 * 4 + 36; if (*(s32 *)(p + 0x94) != 2) k = q2 * 4; pkt.color[2] = *(u32 *)(k + (s32)cols); }
        { s32 k = q3 * 4 + 36; if (*(s32 *)(p + 0x94) != 2) k = q3 * 4; pkt.color[3] = *(u32 *)(k + (s32)cols); }
        pkt.uv[0][0] = D_L01_002AF550[q0][0];
        pkt.uv[0][1] = D_L01_002AF550[q0][1] + D_L01_001DCF78;
        pkt.uv[1][0] = D_L01_002AF550[q1][0];
        pkt.uv[1][1] = D_L01_002AF550[q1][1] + D_L01_001DCF78;
        pkt.uv[2][0] = D_L01_002AF550[q2][0];
        pkt.uv[2][1] = D_L01_002AF550[q2][1] + D_L01_001DCF78;
        pkt.uv[3][0] = D_L01_002AF550[q3][0];
        pkt.uv[3][1] = D_L01_002AF550[q3][1] + D_L01_001DCF78;
        func_003D2DA0(&pkt, 0, 1);
    }
    pkt.w78 = func_00389598(0x1B);
    D_L01_001DCF7C += 0.01f;
    if (1.0f < D_L01_001DCF7C) D_L01_001DCF7C = 0.0f;
    t = D_L01_001DCF7C;
    a = t * 1.2f;
    na = -t * 1.2f;
    z1 = t * 1.4f + 1.1f;
    z2 = z1 - 0.2f;
    *(s128 *)&tmp[0] = 0;
    tmp[0].x = na * *(f32 *)(p + 0x90);
    tmp[0].y = na * *(f32 *)(p + 0x90);
    tmp[0].z = z1;
    *(s128 *)&tmp[1] = 0;
    tmp[1].x = a * *(f32 *)(p + 0x90);
    tmp[1].y = na * *(f32 *)(p + 0x90);
    tmp[1].z = z2;
    *(s128 *)&tmp[2] = 0;
    tmp[2].x = na * *(f32 *)(p + 0x90);
    tmp[2].y = a * *(f32 *)(p + 0x90);
    tmp[2].z = z1;
    *(s128 *)&tmp[3] = 0;
    tmp[3].x = a * *(f32 *)(p + 0x90);
    tmp[3].y = a * *(f32 *)(p + 0x90);
    tmp[3].z = z2;
    sq[0] = tmp[0];
    sq[1] = tmp[1];
    sq[2] = tmp[2];
    sq[3] = tmp[3];
    up.y = 0.0f;
    up.x = 0.0f;
    up.z = D_L01_001E2880.roll;
    func_0038D308(mat, &up);
    func_0038D000(&c[0], &sq[0], mat);
    func_0038D000(&c[1], &sq[1], mat);
    func_0038D000(&c[2], &sq[2], mat);
    func_0038D000(&c[3], &sq[3], mat);
    { s32 k; for (k = 0; k < 4; k++) {
        func_0038CE20(&c[k], &c[k], 0.5f);
    } }
    color = ((s32)((1.0f - D_L01_001DCF7C) * 128.0f) << 24) | 0x808080;
    pkt.pos[0].x = *(f32 *)(m + 0x10) + c[0].x;
    pkt.pos[0].y = *(f32 *)(m + 0x14) + c[0].y;
    pkt.pos[0].z = ((*(f32 *)(m + 0x18) + c[0].z) - 1.0f) + 1.45f;
    pkt.pos[1].x = *(f32 *)(m + 0x10) + c[1].x;
    pkt.pos[1].y = *(f32 *)(m + 0x14) + c[1].y;
    pkt.pos[1].z = ((*(f32 *)(m + 0x18) + c[1].z) - 1.0f) + 1.45f;
    pkt.pos[2].x = *(f32 *)(m + 0x10) + c[2].x;
    pkt.pos[2].y = *(f32 *)(m + 0x14) + c[2].y;
    pkt.pos[2].z = ((*(f32 *)(m + 0x18) + c[2].z) - 1.0f) + 1.45f;
    pkt.pos[3].x = *(f32 *)(m + 0x10) + c[3].x;
    pkt.pos[3].y = *(f32 *)(m + 0x14) + c[3].y;
    pkt.pos[3].z = ((*(f32 *)(m + 0x18) + c[3].z) - 1.0f) + 1.45f;
    pkt.color[0] = color;
    pkt.color[1] = color;
    pkt.color[2] = color;
    pkt.color[3] = color;
    pkt.uv[0][0] = 0.0f;
    pkt.uv[0][1] = 0.0f;
    pkt.uv[1][0] = 1.0f;
    pkt.uv[1][1] = 0.0f;
    pkt.uv[2][0] = 0.0f;
    pkt.uv[2][1] = 1.0f;
    pkt.uv[3][0] = 1.0f;
    pkt.uv[3][1] = 1.0f;
    func_003D2DA0(&pkt, 0, 1);
}
/* localdecomp:end func_L01_003365C0 */
