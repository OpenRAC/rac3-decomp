/* NTSC-U draft (Claude wave C3): C of func_L18_00353350, the NTSC-U twin of func_L18_00353F58, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L18_00353350", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (native MATCH, 572 B) only with an extra @ps2as on the PAL counterpart file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division): its float constants are lui/ori/mtc1 in retail, gp-relative .lit4 loads with plain ee-as. native written from ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L18_00353F58 (src/levels/shared/L18_00350FB0.c) */
/* localdecomp:start func_L18_00353350 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_353F58;
extern f32 D_001DD3F4_sda;
__asm__(".extern D_001DD3F4_sda, 4");
extern f32 D_001DD3F8_sda;
__asm__(".extern D_001DD3F8_sda, 4");
extern f32 D_001DD3FC_sda;
__asm__(".extern D_001DD3FC_sda, 4");
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern void func_003BDA38(void *, s32, void *);
extern void func_L01_003D72E0(void *, void *, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0032FE90(V4_353F58 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L18_00353350(u8 *obj, s32 n, s32 *arr) {
    V4_353F58 v;
    V4_353F58 dir;
    s32 pick;
    s32 i;
    f32 r;

    if (obj[0xBC] == 9) {
        if (func_0037E1D8(15) == 0) {
            pick = func_0037E1D8(n);
        } else {
            pick = -1;
        }
        dir = (V4_353F58){0.0f, 0.0f, D_001DD3FC_sda * 0.016666668f, 0.0f};
        for (i = 0; i < 3; i++) {
            r = func_0037E250(D_001DD3F4_sda, D_001DD3F4_sda + 0.3f);
            func_003BDA38(obj, arr[i], &v);
            func_L01_003D72E0(&v, &dir, -100000.0f, r, D_001DD3F8_sda, 10, 2, 0, 2, 0x40, 0);
            func_L01_003D72E0(&v, &dir, -100000.0f, r, D_001DD3F8_sda, 20, 2, 0, 2, 0x40, 0);
            if (pick == i) {
                func_L01_0032FE90(&v, 0, 5, 0, 5, 10, 0, 0, 0.5f, 0.0f, 0.0f, 2.0f,
                    0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            }
        }
    }
}
/* localdecomp:end func_L18_00353350 */
