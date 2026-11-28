/* func_L01_002FA1F8 (Claude wave 14 r66, 2026-11-28). First draft kept here. */
/* PAL near miss (wave 14 r66, 2026-11-28), first draft of a fresh entry: 332 instruction diffs at level 01 under the
 * file's line with divs metadata '1' (one nop before retail's div.s). From the functional C (581 there) with, against
 * it: the 0x50-byte parameter block as five TImode words (retail copies it with lq/sq, not ldl/ldr), the zero vector as
 * a TImode zero store (por + sq, not qzero's sq $0), the vu0.h helpers in retail's load orders (vec_sub_ba /
 * vec_add_ba for the axis terms, vec_add_ab for dir), the factor 2.0 as a local `scale` (retail keeps it in $f25 and
 * multiplies at run time: this compiler does not fold float products through a register), 0.020000001f (0x3CA3D70B),
 * the six colour out-parameters as six s32 locals (retail's 0xE0-0xF4 slots), the file's prototypes for
 * func_0038CEA8 / func_0038CF68 / func_003A52A0 and func_L01_002FB660 (TImode pointers).
 * Left: retail also keeps 400000.0f in $f26 and computes scale * 400000.0f inside the count loop (one more FP save,
 * frame 0x1A0 here 0x190), loads 2.0 into $f25 right before the first call and passes it with mov.s, and the count
 * loop's setup order; do/while and inline-argument forms of that loop were worse (386-391 without divs). */
#include "common.h"

/* localdecomp:start func_L01_002FA1F8 */
#include "vu0.h"
typedef int Q_002FA1F8 __attribute__((mode(TI)));
typedef struct { Q_002FA1F8 q[5]; } Params_002FA1F8;
typedef struct { s32 c[6]; } Cols_002FA1F8;
typedef struct { s32 c[3]; } RGB_002FA1F8;
extern Params_002FA1F8 D_L01_002BE820;
extern Cols_002FA1F8 D_L01_001DC318;
extern Cols_002FA1F8 D_L01_001DC330;
extern vu0_v4 D_L01_001E2A40;
extern u8 D_L01_001EEA80[];
void func_L01_002FA1F8(u8 *self, f32 *dir, f32 *axis) {
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_0038CEA8(void *);
    extern s32 func_003D4D00(u8 *, s32, u8 *, s32, f32);
    extern void func_L01_00447718(u8 *, vu0_v4 *, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038CE68(f32 *, f32 *);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern void func_L01_0040E6B8(f32 *, f32 *, f32);
    extern s32 func_L01_00448D88(s32, s32);
    extern void func_L01_00464690(u8 *, f32 *, s32, s32, s32, s32, s32, s32, f32, f32);
    extern void func_L01_00304018(u8 *, u8 *, f32 *, s32, f32, s32, s32, s32, s32);
    extern void func_L01_00448D28(s32 *, s32 *, s32 *, s32);
    extern s32 func_003A52A0(s32, s32, void *);
    extern void func_L01_003006C0(void *, u8 *, s32, s32);
    extern u8 *func_L01_002FB660(Q_002FA1F8 *, Q_002FA1F8 *, s32, s32, s32, s32);
    Params_002FA1F8 params;
    vu0_v4 v60, v70, v80, v90;
    Cols_002FA1F8 colsA, colsB;
    s32 r1, g1, b1;
    s32 r2, g2, b2;
    s32 *vars = *(s32 **)(self + 0x68);
    f32 scale = 2.0f;
    f32 dist, r, f24, f20;
    s32 i, n, hit, count, ca, cb, na;

    params = D_L01_002BE820;
    func_0038CE20(dir, dir, scale);
    vec_sub_ba(&v60, &D_L01_001E2A40, self + 0x10);
    dist = func_0038CEA8(&v60);
    hit = func_003D4D00(self + 0x10, 0x10, self, 0, 1.0f);
    *(Q_002FA1F8 *)&v80 = *(Q_002FA1F8 *)(self + 0x10);
    func_L01_00447718(self, &v80, D_L01_001EEA80, hit, 0, 0x01030000, 2, 1, 1.0f, 1.0f, 1.0f, -1);
    self[0x20] = 1;
    for (i = 9; i >= 0; i--) {
        *(Q_002FA1F8 *)&v90 = 0;
        v90.x = func_003824E0(-1.0f, 1.0f);
        v90.y = func_003824E0(-1.0f, 1.0f);
        *(Q_002FA1F8 *)&v80 = *(Q_002FA1F8 *)&v90;
        func_0038CF68(&v70, axis, func_0038CE68((f32 *)&v80, axis));
        vec_sub_ba(&v80, &v80, &v70);
        func_0038CF68(&v70, axis, func_003824E0(0.0f, 1.0f));
        vec_add_ba(&v80, &v80, &v70);
        func_0038CF68(&v80, &v80, scale * func_003824E0(3.5f, 6.5f) * 0.020000001f);
        vec_add_ab(&v80, &v80, dir);
        func_L01_002FB660((Q_002FA1F8 *)(self + 0x10), (Q_002FA1F8 *)&v80, func_00382498(50, 100), 0, 1, 0);
    }
    f24 = dist + dist;
    for (i = 3; i >= 0; i--) {
        *(Q_002FA1F8 *)&v90 = 0;
        v90.x = func_003824E0(-1.0f, 1.0f);
        v90.y = func_003824E0(-1.0f, 1.0f);
        *(Q_002FA1F8 *)&v80 = *(Q_002FA1F8 *)&v90;
        func_0038CF68(&v70, axis, func_0038CE68((f32 *)&v80, axis));
        vec_sub_ba(&v80, &v80, &v70);
        func_0038CF68(&v70, axis, func_003824E0(0.0f, 1.0f));
        vec_add_ba(&v80, &v80, &v70);
        func_0038CF68(&v80, &v80, scale * func_003824E0(6.5f, 10.0f) * 0.020000001f);
        vec_add_ab(&v80, &v80, dir);
        func_L01_002FB660((Q_002FA1F8 *)(self + 0x10), (Q_002FA1F8 *)&v80, func_00382498(50, 75), 1, 1, 0);
    }
    *(Q_002FA1F8 *)&v90 = 0;
    v90.x = func_003824E0(-1.0f, 1.0f);
    v90.y = func_003824E0(-1.0f, 1.0f);
    v90.z = func_003824E0(-1.0f, 1.0f);
    v60.z = v60.z + dist * 0.5f;
    *(Q_002FA1F8 *)&v80 = *(Q_002FA1F8 *)&v90;
    func_0038CF68(&v80, &v80, dist / 5.0f * 0.020000001f);
    func_0038CF68(&v60, &v60, f24 * 0.020000001f);
    vec_add_ab(&v80, &v80, &v60);
    func_L01_0040E6B8((f32 *)&v80, (f32 *)&v80, 0.20000002f);
    func_L01_002FB660((Q_002FA1F8 *)(self + 0x10), (Q_002FA1F8 *)&v80, func_00382498(50, 75), 1, 1, 0);
    if (dist < 6.0f) {
        count = (s32)dist + 1;
    } else {
        count = 4;
    }
    f24 = 0.0f;
    if (dist < 7.0f) {
        f24 = 7.0f - dist;
    }
    for (i = count; i > 0; i--) {
        f32 size = scale * 400000.0f;
        f20 = scale * func_003824E0(8.0f, 10.0f) * 0.020000001f - f24 * 0.020000001f;
        colsA = D_L01_001DC318;
        colsB = D_L01_001DC330;
        ca = func_L01_00448D88(colsA.c[func_00382468(6)], 1);
        cb = func_L01_00448D88(colsB.c[func_00382468(6)], 1);
        na = func_00382498(12, 17);
        func_L01_00464690(self + 0x10, dir, ca, cb, na, func_00382498(21, 25), 0, 0, size, f20);
    }
    if (dist > 9.0f) {
        f20 = scale * 4.0f;
        func_L01_00304018(self, self + 0x10, dir, 0xC, f20, 0x7F, 0x7F, 0x7F, 0x20);
        r1 = 0x7F;
        g1 = 0x20;
        b1 = 0;
        func_L01_00448D28(&r1, &g1, &b1, 1);
        func_L01_00304018(self, self + 0x10, dir, 0x14, f20, (u8)r1, (u8)g1, (u8)b1, 0x20);
    }
    g2 = 0x3F;
    r2 = 0x7F;
    b2 = 0;
    func_L01_00448D28(&r2, &g2, &b2, 1);
    func_L01_00304018(self, self + 0x10, dir, 0x11, scale * 4.0f, (u8)r2, (u8)g2, (u8)b2, 0x30);
    r2 = 0x60;
    g2 = 0x10;
    b2 = 0;
    func_L01_00448D28(&r2, &g2, &b2, 1);
    func_L01_00304018(self, self + 0x10, dir, 0x16, scale * 3.5f, (u8)r2, (u8)g2, (u8)b2, 0x40);
    r2 = 0x20;
    g2 = 0;
    b2 = 0;
    func_L01_00448D28(&r2, &g2, &b2, 1);
    func_L01_00304018(self, self + 0x10, dir, 0x18, scale * 3.0f, (u8)r2, (u8)g2, (u8)b2, 0x20);
    *vars = 0;
    self[0xBC] = 0;
    func_003A52A0(0, 0, self);
    if (dist < 20.0f) {
        *(f32 *)((u8 *)&D_L01_001E2A40 + 0x20) = 0.4f - dist * 0.0175f;
    } else {
        *(f32 *)((u8 *)&D_L01_001E2A40 + 0x20) = 0.050000012f;
    }
    *(s32 *)((u8 *)&D_L01_001E2A40 + 0x28) = 0x15;
    *(s32 *)((u8 *)&D_L01_001E2A40 + 0x2C) = 0;
    func_L01_003006C0(&params, self + 0x10, 0, 0);
}
/* localdecomp:end func_L01_002FA1F8 */
