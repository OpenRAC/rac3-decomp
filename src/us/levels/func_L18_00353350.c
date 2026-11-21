#include "common.h"

/* NTSC-U counterpart of func_L18_00353F58 (src/levels/shared/L18_003537D8.c): 60 Hz step 1/60.0f */
/* localdecomp:start func_L18_00353350 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00353F58;
extern f32 D_L18_001DD3F4;
__asm__(".extern D_L18_001DD3F4, 4");
extern f32 D_L18_001DD3F8;
__asm__(".extern D_L18_001DD3F8, 4");
extern f32 D_L18_001DD3FC;
__asm__(".extern D_L18_001DD3FC, 4");
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern void func_003BDA38(void *, s32, void *);
extern void func_L01_003D72E0(void *, void *, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L18_00353350(void *o, s32 n, void *a) {
    u8 *obj = (u8 *)o;
    s32 *arr = (s32 *)a;
    V4_00353F58 v;
    V4_00353F58 dir;
    s32 pick;
    s32 i;
    f32 r;

    if (obj[0xBC] == 9) {
        if (func_0037E1D8(15) == 0) {
            pick = func_0037E1D8(n);
        } else {
            pick = -1;
        }
        dir = (V4_00353F58){0.0f, 0.0f, D_L18_001DD3FC * 0.016666668f, 0.0f};
        for (i = 0; i < 3; i++) {
            r = func_0037E250(D_L18_001DD3F4, D_L18_001DD3F4 + 0.3f);
            func_003BDA38(obj, arr[i], &v);
            func_L01_003D72E0(&v, &dir, -100000.0f, r, D_L18_001DD3F8, 10, 2, 0, 2, 0x40, 0);
            func_L01_003D72E0(&v, &dir, -100000.0f, r, D_L18_001DD3F8, 20, 2, 0, 2, 0x40, 0);
            if (pick == i) {
                func_L01_0032FE90(&v, 0, 5, 0, 5, 10, 0, 0, 0.5f, 0.0f, 0.0f, 2.0f,
                    0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            }
        }
    }
}
/* localdecomp:end func_L18_00353350 */
