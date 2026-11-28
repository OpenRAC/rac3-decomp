/* func_L04_00356690 (Claude wave 14 r72, 2026-11-28). First draft kept here. */
/* PAL near miss (wave 14 r72, 2026-11-28): func_L04_00356690 (1684 B, level 04 only), the draw callback that
 * func_L04_00356318 registers (func_L01_00404808): seven 0x90-byte strip buffers built with func_003D9450, their
 * v/z lanes shifted by the object's f0C/f04/f08, then drawn twice through func_L04_0041AE18 with the VU0 vector
 * adds. First draft (fresh entry, from retail with the functional port's field map): 332 diff with the file's line
 * and the divs row `func_L04_00356690 2` (two nops before its one div.s; check with --divs 2).
 * The frame layout is retail's (matrix 0x00, v 0x40, buffers 0x50-0x43F, the two colours at 0x440, vA/vV/vT at
 * 0x450-0x47F, k0/k1 0x480/0x490, z 0x4A0, rot 0x4C0, VU0 copies 0x4F0-0x52F, saves 0x530); the $gp addresses of
 * the five tables need `section(".sdata")` plus a 4-byte .extern hint; vV/vT start as TImode zero stores.
 * Prologue to the second func_0038DBD8 fade matches. Still differs: the bc1f slot after the second 0.2 test (gcc
 * fills it with the D_L04_001DD37C load, retail leaves a nop: retail never puts those loads in a slot), which shifts
 * the rest; the VU0 loop's copy/add order is approximate. */
#include "common.h"

/* localdecomp:start func_L04_00356690 */
#include "vu0.h"
typedef struct {
    f32 f00;
    f32 f04;
    f32 f08;
    f32 f0C;
    u8 pad10[0x10];
    f32 f20;
} P_00356690;
extern u8 D_L04_001E27C0[];
__asm__(".extern D_L04_001DD370, 4");
__asm__(".extern D_L04_001DD320, 4");
__asm__(".extern D_L04_001DD330, 4");
__asm__(".extern D_L04_001DD350, 4");
__asm__(".extern D_L04_001DD390, 4");
__asm__(".extern D_L04_001DD3D0, 4");
__asm__(".extern D_L04_001DD410, 4");
__asm__(".extern D_L04_001DD450, 4");
__asm__(".extern D_L04_001DD454, 4");
__asm__(".extern D_L04_001DD458, 4");
__asm__(".extern D_L04_001DD45C, 4");
__asm__(".extern D_L04_001DD460, 4");
extern s32 D_L04_001DD370;
extern s32 D_L04_001DD374;
extern s32 D_L04_001DD378;
extern s32 D_L04_001DD37C;
extern s32 D_L04_001DD320;
extern s32 D_L04_001DD324;
extern u8 D_L04_001DD330[] __attribute__((section(".sdata")));
extern u8 D_L04_001DD350[] __attribute__((section(".sdata")));
extern vu0_v4 D_L04_001DD390[] __attribute__((section(".sdata")));
extern vu0_v4 D_L04_001DD3D0[] __attribute__((section(".sdata")));
extern vu0_v4 D_L04_001DD410[] __attribute__((section(".sdata")));
extern f32 D_L04_001DD450;
extern f32 D_L04_001DD454;
extern f32 D_L04_001DD458;
extern s32 D_L04_001DD45C;
extern s32 D_L04_001DD460;

void func_L04_00356690(void *arg) {
    extern void func_0038D570(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003C5060(void *, void *, void *, s32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern void func_003D9450(void *, s32, s32, void *, void *, s32);
    extern void func_0038D308(void *, void *);
    extern void func_L04_0041AE18(void *, s32, void *, s32, void *);
    extern void *func_0011A264(void *, s32, s32);
    u8 *a = arg;
    P_00356690 *p;
    vu0_v4 m[4];
    vu0_v4 v;
    vu0_v4 mesh[7][9];
    s32 cc[2];
    vu0_v4 vA;
    vu0_v4 vV;
    vu0_v4 vT;
    vu0_v4 k0;
    vu0_v4 k1;
    vu0_v4 z[2];
    vu0_v4 rot[3];
    vu0_v4 tC;
    vu0_v4 tC2;
    vu0_v4 tB2;
    vu0_v4 tB;
    s32 col0, col1;
    f32 f, h;
    s32 mask;
    s32 k, i;

    p = *(P_00356690 **)(a + 0x68);
    func_0038D570(&m[0], a + 0xC0);
    m[3] = *(vu0_v4 *)(a + 0x10);
    m[3].w = 1.0f;
    func_0038CF68(&m[0], &m[0], 4.0f);
    func_0038CF68(&m[1], &m[1], 10.0f);
    vec_sub_ba(&v, D_L04_001E27C0, a + 0x10);
    func_003C5060(a, &v, &v, 0);
    if (v.x < 0.0f) {
        func_0038CE20(&m[0], &m[0], -1.0f);
    }
    h = func_0038D0B0(p->f20) * 0.5f + 0.5f;
    col0 = func_0038DBD8(D_L04_001DD370, D_L04_001DD374, h);
    col1 = func_0038DBD8(D_L04_001DD378, D_L04_001DD37C, h);
    f = p->f04;
    f = (f < 0.2f) ? 1.0f - f * 5.0f : f;
    cc[0] = func_0038DBD8(D_L04_001DD37C, D_L04_001DD37C & 0xFFFFFF, f);
    f = p->f08;
    f = (f < 0.2f) ? 1.0f - f * 5.0f : f;
    mask = 0xFFFFFF;
    cc[1] = func_0038DBD8(D_L04_001DD37C, D_L04_001DD37C & mask, f);
    if (p->f00 < 1.0f) {
        col0 = func_0038DBD8(col0 & mask, col0, p->f00);
        col1 = func_0038DBD8(col1 & mask, col1, p->f00);
        cc[0] = func_0038DBD8(cc[0] & mask, cc[0], p->f00);
        cc[1] = func_0038DBD8(cc[1] & mask, cc[1], p->f00);
    }
    func_003D9450(mesh[0], D_L04_001DD320, col0, D_L04_001DD330, D_L04_001DD390, 1);
    func_003D9450(mesh[1], D_L04_001DD324, col1, D_L04_001DD350, D_L04_001DD3D0, 1);
    func_003D9450(mesh[2], D_L04_001DD324, col1, D_L04_001DD350, D_L04_001DD410, 1);
    func_003D9450(mesh[3], D_L04_001DD324, cc[0], D_L04_001DD350, D_L04_001DD3D0, 1);
    func_003D9450(mesh[4], D_L04_001DD324, cc[0], D_L04_001DD350, D_L04_001DD410, 1);
    func_003D9450(mesh[5], D_L04_001DD324, cc[1], D_L04_001DD350, D_L04_001DD3D0, 1);
    func_003D9450(mesh[6], D_L04_001DD324, cc[1], D_L04_001DD350, D_L04_001DD410, 1);
    for (k = 0; k < 4; k++) {
        ((f32 *)&mesh[1][5])[2 * k] += p->f0C;
        ((f32 *)&mesh[2][5])[2 * k] -= p->f0C;
        ((f32 *)&mesh[3][5])[2 * k] += p->f0C;
        ((f32 *)&mesh[4][5])[2 * k] -= p->f0C;
        ((f32 *)&mesh[5][5])[2 * k] += p->f0C;
        ((f32 *)&mesh[6][5])[2 * k] -= p->f0C;
        mesh[3][k].z -= p->f04 * D_L04_001DD454;
        mesh[4][k].z += p->f04 * D_L04_001DD454;
        mesh[5][k].z -= p->f08 * D_L04_001DD454;
        mesh[6][k].z += p->f08 * D_L04_001DD454;
    }
    *(vu0_q *)&vV = 0;
    *(vu0_q *)&vT = 0;
    vT.z = D_L04_001DD450;
    vV.z = -3.1415927f / D_L04_001DD458;
    vA = vV;
    vV = vT;
    func_0011A264(z, 0, 0x20);
    z[0].z = p->f04 * D_L04_001DD454;
    k0 = z[0];
    z[1].z = p->f08 * D_L04_001DD454;
    k1 = z[1];
    func_0038D308(rot, &vA);
    func_L04_0041AE18(mesh, D_L04_001DD45C, rot, D_L04_001DD460, m);
    for (i = 0; i < 4; i++) {
        vec_add_ba(&mesh[0][i], &D_L04_001DD390[i], &vV);
        vec_add_ba(&mesh[1][i], &D_L04_001DD3D0[i], &vV);
        vec_copy(&tC, &D_L04_001DD410[i]);
        vec_copy(&tB, &D_L04_001DD3D0[i]);
        vec_add_ab(&mesh[2][i], &tC, &vV);
        vec_copy(&tC2, &D_L04_001DD410[i]);
        vec_add_ab(&tB, &tB, &vV);
        vec_copy(&tB2, &D_L04_001DD3D0[i]);
        vec_copy(&mesh[3][i], &tB);
        vec_copy(&tB, &D_L04_001DD410[i]);
        vec_add_ab(&mesh[4][i], &tC2, &vV);
        vec_add_ab(&mesh[5][i], &tB2, &vV);
        vec_add_ab(&mesh[6][i], &tB, &vV);
        vec_sub_ab(&mesh[3][i], &mesh[3][i], &k0);
        vec_add_ab(&mesh[4][i], &mesh[4][i], &k0);
        vec_sub_ab(&mesh[5][i], &mesh[5][i], &k1);
        vec_add_ab(&mesh[6][i], &mesh[6][i], &k1);
    }
    func_0038D308(rot, &vA);
    func_L04_0041AE18(mesh, D_L04_001DD45C, rot, D_L04_001DD460, m);
}
/* localdecomp:end func_L04_00356690 */
