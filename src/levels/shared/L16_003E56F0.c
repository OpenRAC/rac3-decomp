#include "common.h"

/* localdecomp:start func_L16_003E56F0 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_003E56F0;
extern void func_0038D000(void *, void *, void *);
extern s32 func_00382498(s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern f32 D_L16_001DF484;
__asm__(".extern D_L16_001DF484, 4");
extern f32 D_L16_001DF488;
__asm__(".extern D_L16_001DF488, 4");

void func_L16_003E56F0(u8 *p) {
    V4_003E56F0 a;
    V4_003E56F0 b;
    s32 r;
    s32 *q;

    q = *(s32 **)(p + 0x68);
    b = (V4_003E56F0){0.0f, 0.0f, 0.0f, 0.0f};
    b.z = D_L16_001DF484 * (1.0f / D_L16_001DF488);
    a = b;
    b = (V4_003E56F0){0.0f, 0.0f, 0.0f, 0.0f};
    b.x = 0.040000003f;
    b.z = 0.040000003f;
    func_0038D000(&b, &b, p + 0xC0);
    r = func_00382498(3, 6);
    func_L02_003E2E38(p, &a, 0.0f, &b, r, 0, 0, 0.040000003f, 0.7f, 15.0f, 1.0f);
    b.x = -0.040000003f;
    b.z = 0.048000004f;
    func_0038D000(&b, &b, p + 0xC0);
    r = func_00382498(3, 6);
    func_L02_003E2E38(p, &a, 0.0f, &b, r, 1, 0, 0.040000003f, 0.7f, 15.0f, 1.0f);
    *q = (func_00382498(90, 180) * 5 + 2) / 6;
}
/* localdecomp:end func_L16_003E56F0 */
