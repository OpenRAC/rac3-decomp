/* functional: high. Written from the PAL asm only (no draft); every offset, constant, call argument and the call order followed instruction by instruction. The retail frame is mirrored: 4x4 matrix at sp+0x00, scratch vec at sp+0x40, seven 0x90-byte mesh buffers at sp+0x50.. (kept as one byte array because loop 1 writes across buffer boundaries), colours at sp+0x440/0x444, vectors at 0x450..0x490, rotation matrix at 0x4C0. Vector w lanes follow the vadd/vsub.xyz destination-register rule (some results keep the w of the second operand). check.py was not tried for exactness. */
#include "common.h"
#include "vu0.h"

typedef struct P_L04_00356690 {
    f32 f00;
    f32 f04;
    f32 f08;
    f32 f0C;
    u8 pad10[0x10];
    f32 f20;
} P_L04_00356690;

extern u8 D_001E27C0[];
extern s32 D_001DD370_sda;
__asm__(".extern D_001DD370_sda, 4");
extern s32 D_001DD374;
extern s32 D_001DD378;
extern s32 D_001DD37C;
extern s32 D_001DD320_sda;
__asm__(".extern D_001DD320_sda, 4");
extern s32 D_001DD324;
extern u8 D_001DD330[];
__asm__(".extern D_001DD330, 16");
extern u8 D_001DD350[];
__asm__(".extern D_001DD350, 16");
extern u8 D_001DD390[];
__asm__(".extern D_001DD390, 16");
extern u8 D_001DD3D0[];
__asm__(".extern D_001DD3D0, 16");
extern u8 D_001DD410[];
__asm__(".extern D_001DD410, 16");
extern f32 D_001DD450_sda;
__asm__(".extern D_001DD450_sda, 4");
extern f32 D_001DD454_sda;
__asm__(".extern D_001DD454_sda, 4");
extern f32 D_001DD458_sda;
__asm__(".extern D_001DD458_sda, 4");
extern s32 D_001DD45C_sda;
__asm__(".extern D_001DD45C_sda, 4");
extern s32 D_001DD460_sda;
__asm__(".extern D_001DD460_sda, 4");

extern void func_0038D570(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C5060(void *, void *, void *, s32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003D9450(void *, s32, s32, void *, void *, s32);
extern void func_0038D308(void *, void *);
extern void func_L04_0041AE18(void *, s32, void *, s32, void *);
extern void *func_0011A264(void *, s32, s32);

void func_L04_00356690(void *arg) {
    u8 *a = arg;
    P_L04_00356690 *p = *(P_L04_00356690 **)(a + 0x68);
    vu0_v4 m[5];
    u8 mesh[0x3F0] __attribute__((aligned(16)));
    vu0_v4 vA;
    vu0_v4 vV;
    vu0_v4 vB;
    vu0_v4 k480;
    vu0_v4 k490;
    vu0_v4 z4A0[2];
    vu0_v4 rot[3];
    s32 col18, col19, t440, t444;
    f32 f, f20;
    s32 mask;
    s32 k, i;
    vu0_v4 t;

    func_0038D570(&m[0], a + 0xC0);
    m[3] = *(vu0_v4 *)(a + 0x10);
    m[3].w = 1.0f;
    func_0038CF68(&m[0], &m[0], 4.0f);
    func_0038CF68(&m[1], &m[1], 10.0f);
    vec_sub_ba(&m[4], D_001E27C0, a + 0x10);
    func_003C5060(a, &m[4], &m[4], 0);
    if (m[4].x < 0.0f) func_0038CE20(&m[0], &m[0], -1.0f);

    f20 = func_0038D0B0(p->f20) * 0.5f + 0.5f;
    col18 = func_0038DBD8(D_001DD370_sda, D_001DD374, f20);
    col19 = func_0038DBD8(D_001DD378, D_001DD37C, f20);
    f = p->f04;
    if (f < 0.2f) f = 1.0f - f * 5.0f;
    t440 = func_0038DBD8(D_001DD37C, D_001DD37C & 0xFFFFFF, f);
    f = p->f08;
    if (f < 0.2f) f = 1.0f - f * 5.0f;
    t444 = func_0038DBD8(D_001DD37C, D_001DD37C & 0xFFFFFF, f);
    mask = 0xFFFFFF;
    if (p->f00 < 1.0f) {
        col18 = func_0038DBD8(col18 & mask, col18, p->f00);
        col19 = func_0038DBD8(col19 & mask, col19, p->f00);
        t440 = func_0038DBD8(t440 & mask, t440, p->f00);
        t444 = func_0038DBD8(t444 & mask, t444, p->f00);
    }

    func_003D9450(mesh + 0x000, D_001DD320_sda, col18, D_001DD330, D_001DD390, 1);
    func_003D9450(mesh + 0x090, D_001DD324, col19, D_001DD350, D_001DD3D0, 1);
    func_003D9450(mesh + 0x120, D_001DD324, col19, D_001DD350, D_001DD410, 1);
    func_003D9450(mesh + 0x1B0, D_001DD324, t440, D_001DD350, D_001DD3D0, 1);
    func_003D9450(mesh + 0x240, D_001DD324, t440, D_001DD350, D_001DD410, 1);
    func_003D9450(mesh + 0x2D0, D_001DD324, t444, D_001DD350, D_001DD3D0, 1);
    func_003D9450(mesh + 0x360, D_001DD324, t444, D_001DD350, D_001DD410, 1);

    for (k = 0; k < 4; k++) {
        *(f32 *)(mesh + 0xE0 + 8 * k) += p->f0C;
        *(f32 *)(mesh + 0x170 + 8 * k) -= p->f0C;
        *(f32 *)(mesh + 0x200 + 8 * k) += p->f0C;
        *(f32 *)(mesh + 0x290 + 8 * k) -= p->f0C;
        *(f32 *)(mesh + 0x320 + 8 * k) += p->f0C;
        *(f32 *)(mesh + 0x3B0 + 8 * k) -= p->f0C;
        *(f32 *)(mesh + 0x1B8 + 16 * k) -= p->f04 * D_001DD454_sda;
        *(f32 *)(mesh + 0x248 + 16 * k) += p->f04 * D_001DD454_sda;
        *(f32 *)(mesh + 0x2D8 + 16 * k) -= p->f08 * D_001DD454_sda;
        *(f32 *)(mesh + 0x368 + 16 * k) += p->f08 * D_001DD454_sda;
    }

    vA.x = 0.0f; vA.y = 0.0f; vA.z = -3.1415927f / D_001DD458_sda; vA.w = 0.0f;
    vV.x = 0.0f; vV.y = 0.0f; vV.z = D_001DD450_sda; vV.w = 0.0f;
    vB = vV;
    func_0011A264(z4A0, 0, 0x20);
    z4A0[0].z = p->f04 * D_001DD454_sda;
    k480 = z4A0[0];
    z4A0[1].z = p->f08 * D_001DD454_sda;
    k490 = z4A0[1];
    func_0038D308(rot, &vA);
    func_L04_0041AE18(mesh, D_001DD45C_sda, rot, D_001DD460_sda, m);

    for (i = 0; i < 4; i++) {
        vu0_v4 *A = (vu0_v4 *)(D_001DD390 + 16 * i);
        vu0_v4 *B = (vu0_v4 *)(D_001DD3D0 + 16 * i);
        vu0_v4 *C = (vu0_v4 *)(D_001DD410 + 16 * i);
        vu0_v4 *m0 = (vu0_v4 *)(mesh + 0x000 + 16 * i);
        vu0_v4 *m1 = (vu0_v4 *)(mesh + 0x090 + 16 * i);
        vu0_v4 *m2 = (vu0_v4 *)(mesh + 0x120 + 16 * i);
        vu0_v4 *m3 = (vu0_v4 *)(mesh + 0x1B0 + 16 * i);
        vu0_v4 *m4 = (vu0_v4 *)(mesh + 0x240 + 16 * i);
        vu0_v4 *m5 = (vu0_v4 *)(mesh + 0x2D0 + 16 * i);
        vu0_v4 *m6 = (vu0_v4 *)(mesh + 0x360 + 16 * i);

        vec_add_ab(m0, A, &vV);
        m0->w = A->w;
        vec_add_ab(m1, B, &vV);
        m1->w = B->w;
        vec_add_ab(m2, C, &vV);
        m2->w = vV.w;
        vec_add_ab(m3, B, &vV);
        m3->w = B->w;
        vec_add_ab(m4, C, &vV);
        m4->w = vV.w;
        vec_add_ab(m5, B, &vV);
        m5->w = vV.w;
        vec_add_ab(m6, C, &vV);
        m6->w = vV.w;
        t = *m3;
        vec_sub_ab(m3, &t, &k480);
        m3->w = t.w;
        t = *m4;
        vec_add_ab(m4, &t, &k480);
        m4->w = t.w;
        t = *m5;
        vec_sub_ab(m5, &t, &k490);
        m5->w = t.w;
        t = *m6;
        vec_add_ab(m6, &t, &k490);
        m6->w = t.w;
    }
    func_0038D308(rot, &vA);
    func_L04_0041AE18(mesh, D_001DD45C_sda, rot, D_001DD460_sda, m);
}
