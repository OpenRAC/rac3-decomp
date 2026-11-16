#include "common.h"

/* NTSC-U counterpart of func_L16_003E8330 (src/levels/16_kerwan/L16_003E8330.c) */
/* localdecomp:start func_L16_003E6400 */
typedef int q_003E8330 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E8330;

extern f32 D_L16_001DF64C_003E6400;
extern f32 D_L16_001DF650_003E6400;
extern f32 D_L16_001DF654_003E6400;
__asm__(".extern D_L16_001DF64C_003E6400, 4");
__asm__(".extern D_L16_001DF650_003E6400, 4");
__asm__(".extern D_L16_001DF654_003E6400, 4");

extern f32 func_0037E250(f32, f32);
extern void func_003888C8(void *, void *, void *);
extern s32 func_0037E208(s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);

/* from rac3's func_L05_003DB9F8 */
void func_L16_003E6400(u8 *a0) {
    V4_003E8330 b;
    V4_003E8330 v;
    V4_003E8330 w;
    q_003E8330 z;
    f32 inv;
    s32 *p;
    s32 r;
    u8 *c;

    inv = 1.0f / D_L16_001DF654_003E6400;
    z = 0;
    *(q_003E8330 *)&w = z;
    *(q_003E8330 *)&v = z;
    c = a0 + 0xC0;
    p = *(s32 **)(a0 + 0x68);
    w.x = 0.0333333350718f;
    v.y = D_L16_001DF64C_003E6400 * inv;
    v.z = D_L16_001DF650_003E6400 * inv;
    b = v;
    w.y = func_0037E250(-1.0f, 1.0f) * 0.0166666675359f;
    w.z = -0.0333333350718f;
    v = w;
    func_003888C8(&v, &v, c);
    r = func_0037E208(3, 6);
    func_L02_003E0520(a0, &b, 0.0f, &v, r, 0, 0, 0.0333333350718f, 2.5f, 15.0f, 1.0f);
    v.x = 0.0333333350718f;
    v.y = func_0037E250(-1.0f, 1.0f) * 0.0166666675359f;
    v.z = -0.0400000028312f;
    func_003888C8(&v, &v, c);
    r = func_0037E208(3, 6);
    func_L02_003E0520(a0, &b, 0.0f, &v, r, 3, 0, 0.0333333350718f, 2.5f, 15.0f, 1.0f);
    r = func_0037E208(0x5A, 0xB4);
    *p = r;
}
/* localdecomp:end func_L16_003E6400 */
