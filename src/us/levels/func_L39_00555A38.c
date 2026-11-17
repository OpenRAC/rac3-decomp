#include "common.h"

/* NTSC-U counterpart of func_L39_00556448 (src/levels/shared/L39_00554E60.c) */
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
#include "vu0.h"
extern s32 func_L39_005B24C8(s32, s32);

/* localdecomp:start func_L39_00555A38 */
#include "vu0.h"

extern s32 D_001A5F78[];
extern vu0_v4 D_L39_0025F860[];
extern u8 *func_003BCFB0(s32, s32);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_L39_005562B0(void *);
extern void func_003C26C8(void *);

u8 *func_L39_00555A38(u8 *a0, u8 *a1, s32 a2) {
    u8 *m;
    u8 *state;
    f32 t;
    vu0_v4 tmp;

    m = func_003BCFB0(0x10AD, 0xC0);
    if (m != 0) {
        m[0x30] = 0x7F;
        *(s16 *)(m + 0x32) = 0x7F;
        m[0x31] = 1;
        state = *(u8 **)(m + 0x68);
        *(vu0_q *)(m + 0x10) = *(vu0_q *)(a0 + 0x10);
        *(vu0_q *)(m + 0xF0) = *(vu0_q *)(a0 + 0xF0);
        *(f32 *)(m + 0xF0) = 0.0f;
        *(f32 *)(m + 0xF4) = 0.0f;
        if (*(s16 *)(a1 + 0x2D8) != 0) {
            func_00388830(m + 0x10, a1 + 0x40, 1.5f);
            vec_add_ab(m + 0x10, m + 0x10, a1 + 0xA0);
        }
        tmp = *(vu0_v4 *)(m + 0x10);
        tmp.z += 1.0f;
        if (func_003CE740(&tmp, m + 0x10, 2, 0, 0) != 0) {
            func_00388830(&tmp, &D_L39_0025F860[2], 0.005f);
            vec_add_ab(m + 0x10, &D_L39_0025F860[0], &tmp);
        }
        m[0x20] = 0;
        *(s16 *)(state + 0x76) = 0;
        *(s16 *)(state + 0x74) = func_L39_005B24C8(120, 300);
        *(s32 *)(state + 0x90) = 600;
        *(s32 *)(state + 0x94) = 30;
        *(s32 *)(state + 0x7C) = 0;
        *(s32 *)(state + 0x98) = 0;
        *(s32 *)(state + 0x9C) = *(s32 *)(a1 + 0x2544);
        func_L39_005562B0(m);
        *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
        *(f32 *)(state + 0x88) = 1.0f;
        t = (f32)(a2 - D_001A5F78[0]) / 1000.0f;
        if (t < 0.0f) {
            t = 0.017f;
        }
        *(s32 *)(state + 0x80) = (s32)(t * 60.0f);
        func_003C26C8(m);
    }
    return m;
}
/* localdecomp:end func_L39_00555A38 */
