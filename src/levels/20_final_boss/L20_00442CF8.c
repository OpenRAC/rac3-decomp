#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L20_00442CF8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 a; u8 pad[0x20]; V4 b; V4 c; } Loc42;

extern void func_003C2EC0(void *a, s32 b, void *c);
extern void func_0038CF68(void *a, void *b, f32 c);
extern f32 func_003824E0(f32 a, f32 b);
extern void func_003D9508(void *p, s32 a, u32 color, s32 b, f32 f0, f32 f1, f32 f2);
extern void func_003C4C18(void *p, f32 x);
extern u8 D_001E2E20[];
__asm__(".extern D_001E2E20, 16");

void func_L20_00442CF8(u8 *arg0) {
    Loc42 l;
    f32 k;
    f32 c21 = 0.08f;
    f32 c20 = 0.0f;

    func_003C2EC0(arg0, 0, &l.a);
    func_0038CF68(&l.c, D_001E2E20, -2.0f);
    vec_add_ab(&l.c, &l.c, &l.b);
    k = func_003824E0(1.7f, 1.9f);
    func_003D9508(&l.c, 0xB, 0x80404080, 1, k, c21, c20);
    func_003C4C18(&l.c, 0.3f);
    k = func_003824E0(0.9f, 1.0f);
    func_003D9508(&l.c, 0xB, 0x80001080, 1, k, c21, c20);
}
/* localdecomp:end func_L20_00442CF8 */
