#include "common.h"

/* localdecomp:start func_L39_005D2720 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_005D2720;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    u8 b14;
    u8 b15;
} T_005D2720;
extern s32 func_0038CB00(u8 *);
extern void func_003CD250(u8 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_005FFB48(void *, void *);
extern void func_L39_005FF198(s32, void *, void *);
extern s32 D_L39_002429BC;
__asm__(".extern D_L39_002429BC, 16");

void func_L39_005D2720(u8 *a0) {
    T_005D2720 *t;
    V4_005D2720 a;
    V4_005D2720 b;
    s32 w;
    if (func_0038CB00(a0 + 10) != 0) {
        func_003CD250(a0);
        return;
    }
    t = (T_005D2720 *)(a0 + 32);
    w = *(s32 *)(a0 + 4);
    *(s32 *)(a0 + 4) = (w & 0xFFFFFF) | (((w >> 24) + t->b14) << 24);
    a.x = t->f0;
    a.w = 0.0f;
    a.y = t->f4;
    a.z = t->f8;
    vec_add_ab(a0 + 0x10, a0 + 0x10, &a);
    func_L39_005FFB48(a0 + 0x10, a0 + 0x10);
    if (D_L39_002429BC == 0) {
        t->f8 = t->f8 - t->fC;
    } else {
        func_L39_005FF198(0, a0 + 0x10, &b);
        func_0038CF68(&b, &b, -t->fC);
        vec_add_ab(a0 + 0x10, a0 + 0x10, &b);
    }
    a0[8] += t->b15;
    *(f32 *)(a0 + 12) += t->f10;
}
/* localdecomp:end func_L39_005D2720 */
