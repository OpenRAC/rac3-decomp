/* NTSC-U draft (2026-11-14, Claude worker): C of func_L05_0036A0D0, the NTSC-U twin of func_L05_0036B5E0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L05_0036B268.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L05_0036B5E0 (src/levels/shared/L05_0036A450.c) */
#include "vu0.h"

/* localdecomp:start func_L05_0036A0D0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0036A0D0;
typedef struct { u8 pad0[8]; s32 w8; } S_0036A0D0;

extern u8 *D_L05_002207D8[];
extern void func_003BFC18(void *, void *, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern void func_0037E4B8(void *, f32, f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_0046D1D0(void *, void *, s32, s32, f32, f32, s32, s32, s32, s32, s32);
extern void func_0037E2F0(void *, f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_0046FE70(void *, void *, s32, f32);

void func_L05_0036A0D0(u8 *self) {
    S_0036A0D0 *s3;
    V4_0036A0D0 tmp;
    V4_0036A0D0 vel;
    V4_0036A0D0 pos;
    s32 i;
    s32 col;
    f32 el;
    f32 ang;
    f32 sz;
    u8 *o;
    u8 *t;

    s3 = *(S_0036A0D0 **)(self + 0x68);
    func_003BFC18(self + 0x10, &tmp, 1);
    for (i = 2; i >= 0; i--) {
        col = 0x4F808080;
        el = func_0037E250(-0.9599311f, -1.3962634f);
        ang = func_0037E2A8();
        func_0037E4B8(&vel, func_0037E250(0.0f, 0.5f) * 0.0166666675f, ang, el);
        sz = func_0037E250(0.65f, 0.85f) * 210000.0f;
        pos.x = *(f32 *)(self + 0x10) + func_L01_00440918(0.0f, 0.3f);
        pos.y = *(f32 *)(self + 0x14) + func_L01_00440918(0.0f, 0.3f);
        pos.z = *(f32 *)(self + 0x18) + func_L01_00440918(0.0f, 0.3f);
        if (s3->w8 != 0) {
            col = 0x4F202080;
        }
        o = func_L01_0046D1D0(&pos, &vel, col, 0x08101010, sz, 0.5f, func_0037E208(20, 35), 1, 1, -1, 1);
        if (o != 0) {
            t = D_L05_002207D8[0x16C / 4];
            if (s3->w8 != 0) {
                o[2] = t[0];
            } else {
                o[2] = t[1];
            }
        }
    }
    func_0037E2F0(&vel, 0.0f, 0.025f);
    vec_add_ba(&vel, &vel, self + 0x10);
    vec_sub_ba(&pos, self + 0x10, &vel);
    func_00388830(&pos, &pos, -0.0125f);
    func_L01_0046FE70(&vel, &pos, 0x14, 5.0f);
}
/* localdecomp:end func_L05_0036A0D0 */
