#include "common.h"

/* NTSC-U counterpart of func_L05_003DC320 (src/levels/05_daxx/L05_003DBE18.c) */
/* localdecomp:start func_L05_003D9EE0 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_003DC320;
extern void func_003888C8(void *, void *, void *);
extern s32 func_0037E208(s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern f32 D_001DF1BC_sda_003D9EE0;
__asm__(".extern D_001DF1BC_sda_003D9EE0, 4");
extern f32 D_001DF1C0_sda_003D9EE0;
__asm__(".extern D_001DF1C0_sda_003D9EE0, 4");

void func_L05_003D9EE0(u8 *p) {
    V4_003DC320 a;
    V4_003DC320 b;
    s32 r;
    s32 *q;

    q = *(s32 **)(p + 0x68);
    b = (V4_003DC320){0.0f, 0.0f, 0.0f, 0.0f};
    b.z = D_001DF1BC_sda_003D9EE0 * (1.0f / D_001DF1C0_sda_003D9EE0);
    a = b;
    b = (V4_003DC320){0.0f, 0.0f, 0.0f, 0.0f};
    b.x = 0.033333335f;
    b.z = 0.033333335f;
    func_003888C8(&b, &b, p + 0xC0);
    r = func_0037E208(3, 6);
    func_L02_003E0520(p, &a, 0.0f, &b, r, 0, 0, 0.033333335f, 0.9f, 15.0f, 1.0f);
    b.x = -0.033333335f;
    b.z = 0.040000003f;
    func_003888C8(&b, &b, p + 0xC0);
    r = func_0037E208(3, 6);
    func_L02_003E0520(p, &a, 0.0f, &b, r, 1, 0, 0.033333335f, 0.9f, 15.0f, 1.0f);
    *q = func_0037E208(90, 180);
}
/* localdecomp:end func_L05_003D9EE0 */
