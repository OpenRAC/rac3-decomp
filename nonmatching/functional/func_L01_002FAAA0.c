/* functional: medium. Written from the PAL assembly: death/explosion effect for a Veldin object. 10 debris spawns (func_L01_002FB660), 150 bubbles/sparks (func_L01_00468678), then, if the ground height under the object is within 1.2 of the surface height, 100 dust particles (func_L01_0046CC58) and 20 large particles (func_L01_00465738); finally sets D_L01_001E2A40's light radius from the camera distance and spawns func_L01_003006C0. Callee float/int arg classes follow the neighbours' prototypes. Struct copy of D_L01_002BE820 (0x50 bytes) is done with a struct assignment. Unrun-block risk: the whole if-block and the random-call order are from the disassembly only. */
#include "vu0.h"
typedef struct { u8 b[0x50]; } Params_002FAAA0;
extern Params_002FAAA0 D_L01_002BE820;
extern vu0_v4 D_L01_001E2A40;
extern s32 D_L01_00221098[];
void func_L01_002FAAA0(u8 *self, f32 *dir, f32 *axis) {
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_0038CEA8(f32 *);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038CE68(f32 *, f32 *);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_003C3EC8(u8 *, f32 *);
    extern void func_L01_00468678(u8 *, f32 *, s32, f32, f32);
    extern void func_L01_004AAC98(s32, s32, u8 *, s32);
    extern f32 func_003C3D30(f32 *, s32, s32, f32);
    extern f32 func_L01_004463D0(f32 *);
    extern f32 func_00382538(void);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_L01_0046CC58(vu0_v4 *, vu0_v4 *, s32, s32, s32, s32, f32, f32, f32);
    extern s32 func_L01_00447470(s32, s32, f32);
    extern void func_L01_00465738(vu0_v4 *, vu0_v4 *, s32, s32, s32, s32, s32, s32, s32, f32);
    extern void func_L01_003006C0(void *, u8 *, s32, s32);
    Params_002FAAA0 params;
    vu0_v4 v60, v70, v80, v90, vA0, vB0;
    s32 *vars = *(s32 **)(self + 0x68);
    f32 dist, ground, r, r2, ang, mag, mag2, a, b;
    s32 i, n, colA, colB;

    params = D_L01_002BE820;
    func_0038CE20(dir, dir, 2.0f);
    vec_sub_ab(&v60, &D_L01_001E2A40, self + 0x10);
    dist = func_0038CEA8((f32 *)&v60);
    for (i = 9; i >= 0; i--) {
        qzero(&v90);
        v90.x = func_003824E0(-1.0f, 1.0f);
        v90.y = func_003824E0(-1.0f, 1.0f);
        v80 = v90;
        r = func_0038CE68((f32 *)&v80, axis);
        func_0038CF68((f32 *)&v70, axis, r);
        vec_sub_ab(&v80, &v80, &v70);
        r = func_003824E0(0.0f, 1.0f);
        func_0038CF68((f32 *)&v70, axis, r);
        vec_add_ab(&v80, &v80, &v70);
        r = func_003824E0(3.5f, 6.5f);
        func_0038CF68((f32 *)&v80, (f32 *)&v80, 2.0f * r * 0.020000001415610313f);
        vec_add_ab(&v80, &v80, dir);
        n = func_00382498(50, 100);
        func_L01_002FB660((void *)(self + 0x10), (void *)&v80, n, 0, 1, 0);
    }
    *(f32 *)(self + 0x18) = *(f32 *)(self + 0x18) + 1.0f;
    ground = func_003C3EC8(self + 0x10, (f32 *)&v80);
    *(f32 *)(self + 0x18) = *(f32 *)(self + 0x18) - 1.0f;
    for (i = 149; i >= 0; i--) {
        qzero(&vA0);
        vA0.x = func_003824E0(-1.0f, 1.0f);
        vA0.y = func_003824E0(-1.0f, 1.0f);
        vA0.z = func_003824E0(-0.5f, 2.0f);
        v90 = vA0;
        r = func_003824E0(0.08000000566244125f, 0.1600000113248825f);
        func_0038CF68((f32 *)&v90, (f32 *)&v90, 2.0f * r);
        r = func_003824E0(0.05000000074505806f, 0.10000000149011612f);
        func_L01_00468678(self + 0x10, (f32 *)&v90, 0x88A0A0A0, r * 210000.0f, ground);
    }
    *vars = 0;
    self[0xBC] = 0;
    func_L01_004AAC98(0x16, 0, self, 0);
    v90 = *(vu0_v4 *)(self + 0x10);
    v90.z = v90.z + 3.5f;
    ground = func_003C3D30((f32 *)&v90, 0, 0, 0.5f);
    r = func_L01_004463D0((f32 *)&v90);
    if (ground != r && (ground - r) < 1.2000000476837158f) {
        for (i = 99; i >= 0; i--) {
            qzero(&vB0);
            vB0.x = func_003824E0(-0.015000000596046448f, 0.015000000596046448f);
            vB0.y = func_003824E0(-0.015000000596046448f, 0.015000000596046448f);
            vB0.z = func_003824E0(0.08000000566244125f, 0.2800000309944153f);
            vA0 = vB0;
            mag = func_003824E0(0.0f, 0.3499999940395355f);
            ang = func_00382538();
            vB0.x = func_0038D098(ang) * mag;
            vB0.y = func_0038D0B0(ang) * mag;
            vB0.z = 0.0f;
            mag2 = mag * 0.020000001415610313f * 8.0f;
            vec_add_ab(&vB0, &vB0, self + 0x10);
            vB0.z = ground + 0.5f;
            vA0.z = vA0.z - mag2;
            r = func_003824E0(0.25f, 1.0f);
            func_L01_0046CC58(&vB0, &vA0, 0, 0x167F6060, 0x7F6060, 1, r, ground, 0.00800000037997961f);
        }
        for (i = 19; i >= 0; i--) {
            colA = func_L01_00447470(0x7F000000, 0x7F7F6060, func_003824E0(0.25f, 1.0f));
            colB = func_L01_00447470(0, 0x3F3030, func_003824E0(0.5f, 1.0f));
            vB0.x = func_003824E0(-3.0f, 3.0f);
            vB0.y = func_003824E0(-3.0f, 3.0f);
            vB0.z = func_003824E0(0.08000000566244125f, 0.2800000309944153f);
            r = func_003824E0(1.5f, 3.0f);
            func_0038CF68((f32 *)&vB0, (f32 *)&vB0, r * 0.020000001415610313f);
            r = func_003824E0(3.0f, 6.0f);
            vB0.z = r * 0.020000001415610313f;
            vA0 = *(vu0_v4 *)(self + 0x10);
            vA0.z = ground;
            r2 = func_003824E0(31500.001953125f, 52500.0f);
            n = func_00382498(0x4B, 0x7D);
            func_L01_00465738(&vA0, &vB0, colA, colB, n, 1, *(u8 *)D_L01_00221098[11], -1, 0, r2);
        }
    }
    if (dist < 20.0f) {
        *(f32 *)((u8 *)&D_L01_001E2A40 + 0x20) = 0.4000000059604645f - dist * 0.017500000074505806f;
    } else {
        *(f32 *)((u8 *)&D_L01_001E2A40 + 0x20) = 0.050000011920928955f;
    }
    *(s32 *)((u8 *)&D_L01_001E2A40 + 0x28) = 0x15;
    *(s32 *)((u8 *)&D_L01_001E2A40 + 0x2C) = 0;
    func_L01_003006C0(&params, self + 0x10, 0, 0);
    func_003C2880(self);
}
