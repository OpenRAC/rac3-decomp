#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L22_003B6D30 */
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_L01_0040E548(void *, void *);
typedef struct { u8 p0[0x80]; f32 x; f32 y; u8 p1[0x25C0 - 0x88]; u8 *hero; } G_003B6D30;
extern G_003B6D30 D_1A4BE0;
typedef struct { u8 p[0x30]; f32 x; f32 y; u8 q[0x48]; } R_003B6D30;
extern R_003B6D30 *D_L22_001DFE80;
__asm__(".extern D_L22_001DFE80, 16");

s32 func_L22_003B6D30(u8 *self, u8 *other) {
    u8 *p;
    u8 *hero;
    f32 a;
    s32 r;
    s32 r2;

    p = *(u8 **)(self + 0x68);
    if (other == 0 || self == 0 || *(s32 *)(p + 0x460) != 0) {
        return 0;
    }
    hero = D_1A4BE0.hero;
    if (hero == 0) {
        return 0;
    }
    if (*(s16 *)(hero + 0xAA) != 0x173B && *(s16 *)(hero + 0xAA) != 0x1A4E) {
        return 0;
    }
    if (*(s32 *)(p + 0x4C0) > 0 && *(s32 *)(p + 0x4A0) == 0) {
        r = 0;
        a = func_0038D160(D_L22_001DFE80[*(s32 *)(p + 0x4B8)].x - *(f32 *)(self + 0x10), D_L22_001DFE80[*(s32 *)(p + 0x4B8)].y - *(f32 *)(self + 0x14));
        if (func_0038DBA0(func_0038D160(D_1A4BE0.x - *(f32 *)(self + 0x10),
                                        D_1A4BE0.y - *(f32 *)(self + 0x14)), a) < 2.0943952f) {
            if (func_L01_0040E548(other + 0x10, self + 0x10) < 25.0f) {
                if (other[0x43] == 0x12 || other[0x43] == 0x17) {
                    r = 1;
                }
            }
        }
        return r;
    }
    r2 = 0;
    if (func_L01_0040E548(other + 0x10, self + 0x10) < 25.0f) {
        if (other[0x43] == 0x12 || other[0x43] == 0x17) {
            r2 = 1;
        }
    }
    return r2;
}
/* localdecomp:end func_L22_003B6D30 */

INCLUDE_ASM("asm/levels", func_L22_003B6EE8);

/* localdecomp:start func_L22_003B7150 */
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);

void func_L22_003B7150(u8 *a0) {
    vu0_v4 v;
    u8 *s;
    f32 t = *(f32 *)(a0 + 0xC) / 500.0f;

    *(vu0_q *)&v = *(vu0_q *)(a0 + 0x10);
    v.z += t;
    s = *(u8 **)(a0 + 0x68);
    if (*(s32 *)(s + 0x46C) >= 0) {
        func_003D9508(&v, *(s32 *)(s + 0x46C) + 100, 0x7F7F7F7F, 0, 0.3f, 0.08f, 0.0f);
    }
}
/* localdecomp:end func_L22_003B7150 */
