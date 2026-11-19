/* functional: high. Read against asm: loop, bounds, table and tail all match; diffs are stack layout and scheduling. */
#include "vu0.h"
extern f32 D_L31_001E12B4;
extern s32 D_L31_001E12B0;
extern f32 D_L31_00284A10[];
extern u8 *D_L31_001DF880;
extern u8 *D_L31_0021D740[];
extern f32 D_001A4C64[];
extern f32 D_L31_001DD1C0;
extern s32 D_L31_001DD1AC;
extern void func_L30_0034CCD0(u8 *, f32 *, f32 *, f32 *, f32 *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_L31_0034E0F0(void *, s32, s32, s32, s32);
extern void func_L31_0034B850(void *, void *, f32);

/* Vid-comic 1 camera path set-up: builds the 512-entry arc-length table D_L31_00284A10 for the stored
 * path, finds where it crosses the two bounds fetched from the object, picks the travel direction and
 * starts the follow-up effect. */
void func_L31_0034CD18(u8 *obj) {
    u8 *v = *(u8 **)(obj + 0x68);
    f32 bnd[4];
    f32 q[4];
    vu0_v4 p0, p1;
    vu0_v4 fx;
    f32 t0, t1, f20, cross;
    s32 i;
    s32 k;
    u8 *path;
    s32 dir;

    bnd[0] = 0.0f;
    bnd[1] = 0.0f;
    bnd[2] = 0.0f;
    bnd[3] = 0.0f;
    k = *(s32 *)(v + 0xF8);
    if (k != -1) {
        func_L30_0034CCD0(D_L31_001DF880 + (k << 7), &bnd[0], &bnd[1], &bnd[2], &bnd[3]);
    }
    *(f32 *)(v + 0x130) = 0.0f;
    *(f32 *)(v + 0x134) = 1.0f;
    D_L31_001E12B4 = 0.0f;
    D_L31_00284A10[0] = 0.0f;
    for (i = 1; i < 0x200; i++) {
        t0 = (f32)(i - 1) / 511.0f;
        func_L31_0034B850(obj, &p0, t0);
        t1 = (f32)i / 511.0f;
        func_L31_0034B850(obj, &p1, t1);
        D_L31_001E12B4 += func_0038CF00(&p0, &p1);
        D_L31_00284A10[i] = D_L31_001E12B4;
        cross = (p0.x - bnd[0]) * (p1.x - bnd[0]);
        if (cross < 0.0f) {
            *(f32 *)(v + 0x130) = func_003C4088(t0, t1, fabs_asm(bnd[0] - p0.x) / fabs_asm(p1.x - p0.x));
        }
        cross = (p0.x - bnd[1]) * (p1.x - bnd[1]);
        if (cross < 0.0f) {
            *(f32 *)(v + 0x134) = func_003C4088(t0, t1, fabs_asm(bnd[1] - p0.x) / fabs_asm(p1.x - p0.x));
        }
    }
    path = D_L31_0021D740[*(s32 *)(v + 0x80 + *(s32 *)(v + 0xC8) * 4)];
    dir = *(f32 *)(path + 0x10) < *(f32 *)(path + *(s32 *)path * 16 - 16 + 0x10);
    D_L31_001E12B0 = dir;
    if (dir == 0) {
        *(f32 *)(obj + 0xF8) = 3.1415927f;
    } else {
        *(s32 *)(obj + 0xF8) = 0;
    }
    if (*(s32 *)(v + 0x150) != 0) return;
    if (*(s32 *)(v + 0x154) != 0) return;
    k = *(s32 *)(v + 0xF8);
    func_L30_0034CCD0(D_L31_001DF880 + (k << 7), &q[0], &q[1], &q[2], &q[3]);
    f20 = (q[0] + q[1]) * 0.5f;
    if (func_00382498(0, 1) != 0) {
        f20 += 4.0f;
    }
    if (func_00382498(0, 1) != 0) {
        f20 += -4.0f;
    }
    fx.x = f20;
    fx.y = D_001A4C64[0];
    fx.z = q[3] + D_L31_001DD1C0;
    *(s32 *)(v + 0x150) = func_L31_0034E0F0(&fx, 1, D_L31_001DD1AC, 0, -1);
    qzero(v + 0x140);
}
