/* NTSC-U draft (2026-11-14, Claude worker): C of func_L03_003B4B38, the NTSC-U twin of func_L03_003B6740, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "@ps2as" (src/levels/shared/L03_003B5C78.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L03_003B5C78 (src/levels/shared/L03_003B5C78.c) */
/* localdecomp:start func_L03_003B4B38 */
typedef int u128_003B4B38 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003B4B38;

extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_L01_00440A88(void *, f32, f32);
extern u8 *func_L01_00467DA8(void *, s32, s32, s32, s32, void *, s32, f32, f32, f32);

void func_L03_003B4B38(void *src, s32 n, s32 c1, s32 c2) {
    V4_003B4B38 v0;
    V4_003B4B38 v10;
    f32 r;
    s32 d;
    u8 *p;

    *(u128_003B4B38 *)&v0 = *(u128_003B4B38 *)src;
    while (n > 0) {
        r = func_0037E250(1.0f, 2.0f);
        d = func_0037E1D8(2);
        d = d != 0 ? d : -1;
        func_L01_00440A88(&v10, 0.05f, 0.25f);
        p = func_L01_00467DA8(&v0, 0x14, c1, 0, d, &v10, 0, r * 0.1f, r, 0.002f);
        if (p != 0) {
            p[9] = 0x74;
        }
        p = func_L01_00467DA8(&v0, 0x14, c2, 1, -d, &v10, 0, r * 0.07f, r * 0.7f, 0.002f);
        if (p != 0) {
            p[9] = 0x74;
        }
        n--;
    }
}
/* localdecomp:end func_L03_003B4B38 */
