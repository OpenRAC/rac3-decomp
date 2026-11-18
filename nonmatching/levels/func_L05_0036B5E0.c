/* Near miss (2 diffs) of func_L05_0036B5E0 (PAL 50 Hz version of the NTSC-U twin func_L05_0036A0D0), worker b11-v1.
 * Needs "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (cut the file at 0x0036B5E0 and 0x0036B870).
 * Still differs: the order of `addiu $t1, $zero, 1` and `mov.s $f13, $f24` before the jal to func_L01_004708C8
 * (retail sets t1 first). Tried: lifting the count call into a local, moving sz, col wording.
 * Also tried (orchestrator b11), none moved the pair: an f32 local for the 0.5f (set in the loop: 7 diffs;
 * before it: 150), an s32 local for the first 1 (150), sz computed after pos (105), col as a ternary, 0.5 as a
 * double, the random count in a block local, an up-counting loop (all 2). A scheduler tie between two
 * independent argument moves, as func_L12_003D5418 and func_L03_003B8FA0 (round 3).
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_0036B5E0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0036B5E0;
typedef struct { u8 pad0[8]; s32 w8; } S_0036B5E0;

extern u8 *D_L05_00220758[];
extern void func_003C5180(void *, void *, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004708C8(void *, void *, s32, s32, f32, f32, s32, s32, s32, s32, s32);
extern void func_00382580(void *, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004735F0(void *, void *, s32, f32);

void func_L05_0036B5E0(u8 *self) {
    S_0036B5E0 *s3;
    V4_0036B5E0 tmp;
    V4_0036B5E0 vel;
    V4_0036B5E0 pos;
    s32 i;
    s32 col;
    f32 el;
    f32 ang;
    f32 sz;
    u8 *o;

    s3 = *(S_0036B5E0 **)(self + 0x68);
    func_003C5180(self + 0x10, &tmp, 1);
    for (i = 2; i >= 0; i--) {
        col = 0x4F808080;
        el = func_003824E0(-0.9599311f, -1.3962634f);
        ang = func_00382538();
        func_00382760(&vel, func_003824E0(0.0f, 0.5f) * 0.020000001f, ang, el);
        sz = func_003824E0(0.65f, 0.85f) * 210000.0f;
        pos.x = *(f32 *)(self + 0x10) + func_L01_00443A18(0.0f, 0.3f);
        pos.y = *(f32 *)(self + 0x14) + func_L01_00443A18(0.0f, 0.3f);
        pos.z = *(f32 *)(self + 0x18) + func_L01_00443A18(0.0f, 0.3f);
        if (s3->w8 != 0) {
            col = 0x4F202080;
        }
        o = func_L01_004708C8(&pos, &vel, col, 0x08101010, sz, 0.5f, func_00382498(17, 29), 1, 1, -1, 1);
        if (o != 0) {
            if (s3->w8 != 0) {
                o[2] = D_L05_00220758[0x16C / 4][0];
            } else {
                o[2] = D_L05_00220758[0x16C / 4][1];
            }
        }
    }
    func_00382580(&vel, 0.0f, 0.025f);
    vec_add_ba(&vel, &vel, self + 0x10);
    vec_sub_ba(&pos, self + 0x10, &vel);
    func_0038CF68(&pos, &pos, -0.015000001f);
    func_L01_004735F0(&vel, &pos, 0x11, 5.0f);
}
/* localdecomp:end func_L05_0036B5E0 */
