#include "common.h"

/* localdecomp:start func_L16_003E8330 */
typedef int q_003E8330 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E8330;

extern f32 D_L16_001DF60C;
extern f32 D_L16_001DF610;
extern f32 D_L16_001DF614;
__asm__(".extern D_L16_001DF60C, 4");
__asm__(".extern D_L16_001DF610, 4");
__asm__(".extern D_L16_001DF614, 4");

extern f32 func_003824E0(f32, f32);
extern void func_0038D000(void *, void *, void *);
extern s32 func_00382498(s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);

/* from rac3's func_L05_003DB9F8 */
void func_L16_003E8330(u8 *a0) {
    V4_003E8330 b;
    V4_003E8330 v;
    V4_003E8330 w;
    q_003E8330 z;
    f32 inv;
    s32 *p;
    s32 r;
    u8 *c;

    inv = 1.0f / D_L16_001DF614;
    z = 0;
    *(q_003E8330 *)&w = z;
    *(q_003E8330 *)&v = z;
    c = a0 + 0xC0;
    p = *(s32 **)(a0 + 0x68);
    w.x = 0.040000003f;
    v.y = D_L16_001DF60C * inv;
    v.z = D_L16_001DF610 * inv;
    b = v;
    w.y = func_003824E0(-1.0f, 1.0f) * 0.020000001f;
    w.z = -0.040000003f;
    v = w;
    func_0038D000(&v, &v, c);
    r = func_00382498(3, 6);
    func_L02_003E2E38(a0, &b, 0.0f, &v, r, 0, 0, 0.040000003f, 2.5f, 15.0f, 1.0f);
    v.x = 0.040000003f;
    v.y = func_003824E0(-1.0f, 1.0f) * 0.020000001f;
    v.z = -0.048000004f;
    func_0038D000(&v, &v, c);
    r = func_00382498(3, 6);
    func_L02_003E2E38(a0, &b, 0.0f, &v, r, 3, 0, 0.040000003f, 2.5f, 15.0f, 1.0f);
    r = func_00382498(0x5A, 0xB4);
    *p = (r * 5 + 2) / 6;
}
/* localdecomp:end func_L16_003E8330 */
