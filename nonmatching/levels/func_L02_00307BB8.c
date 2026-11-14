/* NTSC-U draft (2026-11-14, Claude worker): C of func_L02_00307918, the NTSC-U twin of func_L02_00307BB8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L02_00307BB8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L02_00307918 */
typedef struct V_00307918 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00307918;

extern f32 D_L02_001DFAA8;
extern u8 D_L02_001D66B0[];

extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern void func_L01_00465410(void *, void *, s32, s32);
extern void func_L01_00440A88(void *, f32, f32);
extern u8 *func_L01_00467510(void *, void *, void *, f32, f32);

void func_L02_00307918(void *unused, f32 *pos) {
    V_00307918 v;
    f32 a;
    f32 s;
    s32 i;
    s32 j;
    s32 r;
    u8 *q;

    for (i = 15; i >= 0; i--) {
        a = func_0037E2A8();
        s = func_0037E250(0.0f, 0.050000004f);
        v.x = func_00388960(a) * s;
        v.y = func_00388978(a) * s;
        v.z = func_0037E250(0.050000004f, 0.108333334f);
        j = func_0037E208(90, 120);
        r = func_0037E1D8(2);
        func_L01_00465410(pos, &v, r, j);
    }
    i = 0;
    do {
        func_L01_00440A88(&v, 1.0f, 1.0f);
        v.z = D_L02_001DFAA8 + 0.05f;
        vec_add_ab(&v, &v, pos);
        a = func_0037E250(0.7f, 1.0f);
        q = func_L01_00467510(&v, D_L02_001D66B0, &D_L02_001DFAA8, a, (i == 0) ? 2.0f : -2.0f);
        i++;
        if (q != 0) {
            *(s16 *)(q + 0xA) = (s32)func_0037E250(30.0f, 60.0f);
        }
    } while (i < 16);
}
/* localdecomp:end func_L02_00307918 */
