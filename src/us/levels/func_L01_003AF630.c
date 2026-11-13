#include "common.h"

/* NTSC-U counterpart of func_L01_003B0E00 (src/levels/01_veldin/L01_003AF290.c): 0.7 -> 0.583333 */
#include "vu0.h"

/* localdecomp:start func_L01_003AF630 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B0E00;
extern V4_3B0E00 D_L01_001E2A40_003AF630;
extern void func_003BDA38(void *, s32, void *);
extern void func_00388830(void *dst, void *src, f32 s);
extern void func_L01_003CB388(void *, void *, void *, void *, f32);

void func_L01_003AF630(u8 *a0, void *a1) {
    V4_3B0E00 v0;
    V4_3B0E00 v10;
    V4_3B0E00 v20;
    V4_3B0E00 v30;
    u8 *p = *(u8 **)(a0 + 0x68);
    func_003BDA38(a0, 12, &v0);
    func_003BDA38(a0, 11, &v10);
    vec_sub_ba(&v20, &D_L01_001E2A40_003AF630, &v10);
    func_00388830(&v20, &v20, 0.5f);
    vec_add_ba(&v20, &v20, &v10);
    vec_sub_ab(&v30, &v10, &v0);
    func_00388830(&v30, &v30, 0.583333373f);
    func_L01_003CB388(a0, &v20, &v30, a1, *(s32 *)(p + 0x354) == -1 ? (f32)p[0x44] : 0.0f);
}
/* localdecomp:end func_L01_003AF630 */
