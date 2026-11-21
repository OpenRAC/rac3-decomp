/* functional: medium. Written from the PAL assembly: sibling of func_L01_002FAAA0 (destruction effect with a hit-test, 10+4+1 debris spawns via func_L01_002FB660, N colour-table particle bursts via func_L01_00464690, shock-ring effects via func_L01_00304018 for dist > 9, light flash). Callee prototypes follow neighbours where known (func_003D4D00, func_L01_00447718); others (func_L01_00304018, func_L01_00448D28/88, func_L01_00464690) are guessed from register use. Unrun-block risk: all of it, from disassembly only. */
#include "vu0.h"
typedef struct { u8 b[0x50]; } Params_002FA1F8;
typedef struct { s32 c[6]; } Cols_002FA1F8;
extern Params_002FA1F8 D_L01_002BE820;
extern Cols_002FA1F8 D_L01_001DC318;
extern Cols_002FA1F8 D_L01_001DC330;
extern vu0_v4 D_L01_001E2A40;
extern u8 D_L01_001EEA80[];
void func_L01_002FA1F8(u8 *self, f32 *dir, f32 *axis) {
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_0038CEA8(f32 *);
    extern s32 func_003D4D00(u8 *, s32, u8 *, s32, f32);
    extern void func_L01_00447718(u8 *, vu0_v4 *, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038CE68(f32 *, f32 *);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern void func_L01_0040E6B8(f32 *, f32 *, f32);
    extern s32 func_L01_00448D88(s32, s32);
    extern void func_L01_00464690(u8 *, f32 *, s32, s32, s32, s32, s32, s32, f32, f32);
    extern void func_L01_00304018(u8 *, u8 *, f32 *, s32, f32, s32, s32, s32, s32);
    extern void func_L01_00448D28(s32 *, s32 *, s32 *, s32);
    extern void func_003A52A0(s32, s32, u8 *);
    extern void func_L01_003006C0(void *, u8 *, s32, s32);
    Params_002FA1F8 params;
    Cols_002FA1F8 colsA, colsB;
    vu0_v4 v60, v70, v80, v90;
    s32 cr[3];
    s32 *vars = *(s32 **)(self + 0x68);
    f32 dist, r, f24, f20;
    s32 i, n, hit, count, ca, cb, na, nb;

    params = D_L01_002BE820;
    func_0038CE20(dir, dir, 2.0f);
    vec_sub_ab(&v60, &D_L01_001E2A40, self + 0x10);
    dist = func_0038CEA8((f32 *)&v60);
    hit = func_003D4D00(self + 0x10, 0x10, self, 0, 1.0f);
    v80 = *(vu0_v4 *)(self + 0x10);
    func_L01_00447718(self, &v80, D_L01_001EEA80, hit, 0, 0x01030000, 2, 1, 1.0f, 1.0f, 1.0f, -1);
    self[0x20] = 1;
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
    f24 = dist + dist;
    for (i = 3; i >= 0; i--) {
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
        r = func_003824E0(6.5f, 10.0f);
        func_0038CF68((f32 *)&v80, (f32 *)&v80, 2.0f * r * 0.020000001415610313f);
        vec_add_ab(&v80, &v80, dir);
        n = func_00382498(50, 75);
        func_L01_002FB660((void *)(self + 0x10), (void *)&v80, n, 1, 1, 0);
    }
    qzero(&v90);
    v90.x = func_003824E0(-1.0f, 1.0f);
    v90.y = func_003824E0(-1.0f, 1.0f);
    v90.z = func_003824E0(-1.0f, 1.0f);
    v60.z = v60.z + dist * 0.5f;
    v80 = v90;
    func_0038CF68((f32 *)&v80, (f32 *)&v80, (dist / 5.0f) * 0.020000001415610313f);
    func_0038CF68((f32 *)&v60, (f32 *)&v60, f24 * 0.020000001415610313f);
    vec_add_ab(&v80, &v80, &v60);
    func_L01_0040E6B8((f32 *)&v80, (f32 *)&v80, 0.20000001788139343f);
    n = func_00382498(50, 75);
    func_L01_002FB660((void *)(self + 0x10), (void *)&v80, n, 1, 1, 0);
    if (dist < 6.0f) {
        count = (s32)dist + 1;
    } else {
        count = 4;
    }
    f24 = 0.0f;
    if (dist < 7.0f) {
        f24 = 7.0f - dist;
    }
    if (count > 0) {
        i = count;
        do {
            f20 = 2.0f * 400000.0f;
            r = func_003824E0(8.0f, 10.0f);
            f20 = 2.0f * r;
            colsA = D_L01_001DC318;
            f20 = f20 * 0.020000001415610313f;
            colsB = D_L01_001DC330;
            f20 = f20 - f24 * 0.020000001415610313f;
            ca = func_L01_00448D88(colsA.c[func_00382468(6)], 1);
            cb = func_L01_00448D88(colsB.c[func_00382468(6)], 1);
            na = func_00382498(12, 17);
            nb = func_00382498(21, 25);
            func_L01_00464690(self + 0x10, dir, ca, cb, na, nb, 0, 0, 2.0f * 400000.0f, f20);
            i--;
        } while (i != 0);
    }
    if (dist > 9.0f) {
        f20 = 2.0f * 4.0f;
        func_L01_00304018(self, self + 0x10, dir, 0xC, f20, 0x7F, 0x7F, 0x7F, 0x20);
        cr[0] = 0x7F;
        cr[1] = 0x20;
        cr[2] = 0;
        func_L01_00448D28(&cr[0], &cr[1], &cr[2], 1);
        func_L01_00304018(self, self + 0x10, dir, 0x14, f20, (u8)cr[0], (u8)cr[1], (u8)cr[2], 0x20);
    }
    cr[1] = 0x3F;
    cr[0] = 0x7F;
    cr[2] = 0;
    func_L01_00448D28(&cr[0], &cr[1], &cr[2], 1);
    func_L01_00304018(self, self + 0x10, dir, 0x11, 2.0f * 4.0f, (u8)cr[0], (u8)cr[1], (u8)cr[2], 0x30);
    cr[0] = 0x60;
    cr[1] = 0x10;
    cr[2] = 0;
    func_L01_00448D28(&cr[0], &cr[1], &cr[2], 1);
    func_L01_00304018(self, self + 0x10, dir, 0x16, 2.0f * 3.5f, (u8)cr[0], (u8)cr[1], (u8)cr[2], 0x40);
    cr[0] = 0x20;
    cr[1] = 0;
    cr[2] = 0;
    func_L01_00448D28(&cr[0], &cr[1], &cr[2], 1);
    func_L01_00304018(self, self + 0x10, dir, 0x18, 2.0f * 3.0f, (u8)cr[0], (u8)cr[1], (u8)cr[2], 0x20);
    *vars = 0;
    self[0xBC] = 0;
    func_003A52A0(0, 0, self);
    if (dist < 20.0f) {
        *(f32 *)((u8 *)&D_L01_001E2A40 + 0x20) = 0.4000000059604645f - dist * 0.017500000074505806f;
    } else {
        *(f32 *)((u8 *)&D_L01_001E2A40 + 0x20) = 0.050000011920928955f;
    }
    *(s32 *)((u8 *)&D_L01_001E2A40 + 0x28) = 0x15;
    *(s32 *)((u8 *)&D_L01_001E2A40 + 0x2C) = 0;
    func_L01_003006C0(&params, self + 0x10, 0, 0);
}
