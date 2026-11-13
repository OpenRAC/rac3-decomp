#include "common.h"

/* localdecomp:start func_L39_00524380 */
typedef int u128_t_00524380 __attribute__((mode(TI)));
extern void func_L01_00305CB8(void *);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_0019D510();

void func_L39_00524380(u8 *self, f32 *p, void *a2, void *a3) {
    s32 i, j, off;
    u8 *rec;
    u8 *sub;
    u8 *obj = *(u8 **)(self + 0x68);
    f32 f, g;
    f32 *vec, *vel, *pos;
    s32 *rnd;

    for (i = 0; i < 10; i++) {
        rec = (u8 *)(i * 0x530 + *(s32 *)(obj + 0x60));
        if (*(s32 *)(rec + 0x514) != 0)
            continue;
        rnd = (s32 *)(rec + 0x4E0);
        pos = (f32 *)(rec + 0x500);
        vel = (f32 *)(rec + 0x4F0);
        vec = (f32 *)rec;
        for (j = 0; j < 2; j++) {
            off = j * 0x90;
            sub = rec + off;
            func_L01_00305CB8(rec + (off + 0x2A0));
            func_L01_00305CB8(rec + (off + 0x60));
            f = func_L39_005B4410(0.3f, 0.5f);
            *(f32 *)(sub + 0x64) *= f;
            *(f32 *)(sub + 0x74) *= f;
            *(f32 *)(sub + 0x84) *= f;
            *(f32 *)(sub + 0x94) *= f;
            g = func_L39_005B4410(0.9f, 1.0f);
            *(f32 *)(sub + 0x78) *= g;
            *(f32 *)(sub + 0x98) *= g;
            *(f32 *)(sub + 0x74) *= 0.4f;
            *(f32 *)(sub + 0x94) *= 0.4f;
            vec[0x20 / 4 + j * 4] = p[0] + func_L39_005B4410(-0.1f, 0.1f);
            vec[0x24 / 4 + j * 4] = p[1] + func_L39_005B4410(-0.1f, 0.1f);
            vec[0x28 / 4 + j * 4] = p[2];
            vec[0x2C / 4 + j * 4] = 1.0f;
            vel[j] = func_L39_005B4410(-0.02f, -0.01f);
            pos[j] = func_L39_005B4410(-7.99f, 0.0f);
            rnd[j] = func_0019D510() % 2;
        }
        *(s32 *)(rec + 0x510) = 0;
        *(s32 *)(rec + 0x514) = 1;
        *(s32 *)(rec + 0x518) = 0;
        *(s32 *)(rec + 0x51C) = 0;
        *(u128_t_00524380 *)(rec + 0x10) = *(u128_t_00524380 *)a3;
        *(u128_t_00524380 *)rec = *(u128_t_00524380 *)a2;
        return;
    }
}
/* localdecomp:end func_L39_00524380 */

/* localdecomp:start func_L39_00524610 */
extern f32 func_L01_004482A0(f32 *, f32, f32 *, f32, f32, f32);
extern s32 func_0038CAD0(void *);

void func_L39_00524610(u8 *self)
{
    s32 i, axis;
    u8 *rec;
    f32 *vel, *pos, v;
    u8 *obj = *(u8 **)(self + 0x68);

    for (i = 0; i < 10; i++) {
        rec = (u8 *)(i * 0x530 + *(s32 *)(obj + 0x60));
        if (*(s32 *)(rec + 0x514) != 1)
            continue;
        vel = (f32 *)(rec + 0x4F0);
        pos = (f32 *)(rec + 0x500);
        for (axis = 0; axis < 2; axis++) {
            v = pos[axis] + vel[axis];
            pos[axis] = v;
            if (v <= -8.0f)
                pos[axis] = v + 8.0f;
        }
        if (*(s32 *)(rec + 0x518) == 0) {
            func_L01_004482A0((f32 *)(rec + 0x510), 0.5f, (f32 *)(rec + 0x51C), 0.0024f, 0.00024000001f, 0.024f);
            if (*(f32 *)(rec + 0x510) == 0.5f) {
                *(s32 *)(rec + 0x518) = 2;
                *(s32 *)(rec + 0x520) = 50;
            }
        } else if (*(s32 *)(rec + 0x518) == 1) {
            func_L01_004482A0((f32 *)(rec + 0x510), 0.0f, (f32 *)(rec + 0x51C), 0.0024f, 0.00024000001f, 0.024f);
            if (*(f32 *)(rec + 0x510) == 0.0f)
                *(s32 *)(rec + 0x514) = 0;
        } else if (func_0038CAD0(rec + 0x520)) {
            *(s32 *)(rec + 0x518) = 1;
        }
    }
}
/* localdecomp:end func_L39_00524610 */

INCLUDE_ASM("asm/levels", func_L39_005247C0);
