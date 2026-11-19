/* functional: medium. Rewritten from asm incl. packet field offsets and grid indexing; GS packet/D_L30 grid arrays named by catalogue; vec asm replaced by plain float ops (VU reg pressure compile error); 304 diff = scheduling/regalloc; the y components of grid verts come from func_L30_0034C540's earlier output (retail never stores y) */
#include "vu0.h"
typedef struct {
    vu0_v4 p[4];
    u32 rgba[4];
    f32 uv[8];
    unsigned long state[4];
} Pkt_00345BD0;
extern s32 D_L30_001DCEC4;
extern s32 D_L30_001DCED0;
extern f32 D_L30_001DCE90;
extern f32 D_L30_001DCED4;
__asm__(".extern D_L30_001DCEC4, 4");
__asm__(".extern D_L30_001DCED0, 4");
__asm__(".extern D_L30_001DCE90, 4");
__asm__(".extern D_L30_001DCED4, 4");
extern vu0_v4 D_001E2240;
extern f32 D_L30_001E1148[8];
extern f32 D_L30_001E1168[8];
extern f32 D_L30_00283B60[64];
extern f32 D_L30_00283C60[64];
extern void func_L30_00343AC8(void *, void *, f32 *, f32 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L30_0034C540(void *, void *, f32, f32, f32, s32);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003A9440(s32, unsigned long);
extern void func_003D2DA0(void *, s32, s32);
extern void func_L30_00346080(u8 *, void *, f32 *, f32 *, f32, f32, f32, f32);

void func_L30_00345BD0(u8 *obj) {
    u8 *v = *(u8 **)(obj + 0x68);
    Pkt_00345BD0 pkt;
    vu0_v4 center;
    vu0_v4 toCam;
    vu0_v4 vtx;
    vu0_v4 off;
    f32 w;
    f32 h;
    f32 phase;
    f32 scale;
    f32 radius;
    f32 diam;
    f32 amp;
    s32 i;
    s32 j;

    func_L30_00343AC8(obj, &off, &w, &h);
    *(vu0_q *)&center = *(vu0_q *)(v + 0x130);
    if (obj[0x20] == 1) {
        phase = 1.0f - *(f32 *)(v + 0x160);
    } else {
        phase = *(f32 *)(v + 0x160);
    }
    toCam.x = D_001E2240.x - center.x;
    toCam.y = D_001E2240.y - center.y;
    toCam.z = D_001E2240.z - center.z;
    scale = D_L30_001DCE90 * (1.0f - phase) + 1.0f;
    radius = sqrt_asm(w * w + h * h) * scale;
    amp = w * scale;
    func_0038CF68(&toCam, &toCam, D_L30_001DCED4);
    diam = radius + radius;
    center.x += toCam.x;
    center.y += toCam.y;
    center.z += toCam.z;
    func_L30_0034C540(&pkt, &center, diam, diam, 0.0f, 0);
    func_003D93B0(&pkt, 0x3B, 1, 0x80);
    pkt.state[3] = (0x8000UL << 24) | 0x4A;
    pkt.rgba[0] = D_L30_001DCEC4;
    pkt.rgba[1] = D_L30_001DCEC4;
    pkt.rgba[2] = D_L30_001DCEC4;
    pkt.rgba[3] = D_L30_001DCEC4;
    pkt.uv[0] = 0.0f;
    pkt.uv[1] = 0.0f;
    pkt.uv[2] = 0.0f;
    pkt.uv[3] = 1.0f;
    pkt.uv[4] = 1.0f;
    pkt.uv[5] = 0.0f;
    pkt.uv[6] = 1.0f;
    pkt.uv[7] = 1.0f;
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&pkt, 0, 0);
    func_003D93B0(&pkt, -1, 2, 0x80);
    pkt.state[3] = (0x8000UL << 24) | 0x54;
    func_003A9440(0x47, 0x53001);
    for (i = 0; i < 8; i++) {
        f32 t = diam * ((f32)i / 7.0f);
        D_L30_001E1168[i] = (center.z - radius) + t;
        D_L30_001E1148[i] = (center.x - radius) + t;
    }
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            vtx.x = D_L30_001E1148[i];
            vtx.y = center.y;
            vtx.z = D_L30_001E1168[j];
            vtx.w = 1.0f;
            func_L30_00346080(obj, &vtx, &D_L30_00283B60[i * 8 + j], &D_L30_00283C60[i * 8 + j],
                              (f32)i / 7.0f, (f32)j / 7.0f, amp, phase);
        }
    }
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            pkt.p[0].x = D_L30_001E1148[i];
            pkt.rgba[0] = D_L30_001DCED0;
            pkt.p[1].x = D_L30_001E1148[i + 1];
            pkt.rgba[3] = D_L30_001DCED0;
            pkt.rgba[2] = D_L30_001DCED0;
            pkt.rgba[1] = D_L30_001DCED0;
            pkt.p[0].z = D_L30_001E1168[j];
            pkt.p[2].z = D_L30_001E1168[j + 1];
            pkt.uv[0] = D_L30_00283B60[i * 8 + j];
            pkt.uv[1] = D_L30_00283C60[i * 8 + j];
            pkt.uv[2] = D_L30_00283B60[(i + 1) * 8 + j];
            pkt.uv[3] = D_L30_00283C60[(i + 1) * 8 + j];
            pkt.uv[4] = D_L30_00283B60[i * 8 + j + 1];
            pkt.uv[5] = D_L30_00283C60[i * 8 + j + 1];
            pkt.uv[6] = D_L30_00283B60[(i + 1) * 8 + j + 1];
            pkt.uv[7] = D_L30_00283C60[(i + 1) * 8 + j + 1];
            pkt.p[2].x = D_L30_001E1148[i];
            pkt.p[3].x = D_L30_001E1148[i + 1];
            pkt.p[1].z = D_L30_001E1168[j];
            pkt.p[3].z = D_L30_001E1168[j + 1];
            func_003D2DA0(&pkt, 0, 0);
        }
    }
    func_003A9440(0x47, 0x5360B);
}
