#include "common.h"

typedef int u128_t_3F07C0 __attribute__((mode(TI)));

typedef int u128_t_3F0A18 __attribute__((mode(TI)));

/* localdecomp:start func_L09_003F07C0 */
#include "vu0.h"

extern u8 D_L09_001D66B0[8];
__asm__(".extern D_L09_001D66B0, 16");
extern f32 D_L09_001DF528;
__asm__(".extern D_L09_001DF528, 4");
extern f32 D_L09_001DF52C;
__asm__(".extern D_L09_001DF52C, 4");
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 *func_L01_00452460(void *, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_0038D000(void *, void *, void *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L09_003F07C0(u8 *a0) {
    vu0_v4 a;
    vu0_v4 b;

    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 0x1F, D_L09_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_00452460(a0, 0x1EE0, 0);
        *(u128_t_3F07C0 *)&b = 0;
        b.z = D_L09_001DF528;
        a = b;
        func_0038CE20(&a, &a, 8.4480865f);
        *(u128_t_3F07C0 *)&b = 0;
        b.z = -0.14000001f;
        func_L02_003E2E38(a0, &a, 0.1f, &b, 0x14, 0, 0, 0.18f, *(f32 *)(a0 + 0x2C) * 12.672131f, 20.0f, 1.0f);
        func_0038CE20(&a, &a, *(f32 *)(a0 + 0x2C));
        func_0038D000(&a, &a, a0 + 0xC0);
        vec_add_ab(&a, &a, a0 + 0x10);
        func_L01_003303B8(&a, 0, 0, 0, 0, 2, 5, 0, D_L09_001DF52C * 8.4480865f * *(f32 *)(a0 + 0x2C), 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0xFF8A, 0xBD66, 0, 0, 0, 0, 0xFF8A, 0xBD66, 0, 0);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L09_003F07C0 */

/* localdecomp:start func_L09_003F0A18 */
#include "vu0.h"

extern u8 D_L09_001D66B0[8];
__asm__(".extern D_L09_001D66B0, 16");
extern f32 D_L09_001DF530;
__asm__(".extern D_L09_001DF530, 4");
extern f32 D_L09_001DF534;
__asm__(".extern D_L09_001DF534, 4");
extern s32 D_L09_001DFBC0;
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 *func_L01_00452460(void *, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_0038D000(void *, void *, void *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00451DB8(void *, f32 *, s32, s32, f32);

void func_L09_003F0A18(u8 *a0) {
    vu0_v4 a;
    vu0_v4 b;
    f32 *p = *(f32 **)(a0 + 0x68);

    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 0xFF, D_L09_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_00452460(a0, 0x1EAF, 0);
        *(u128_t_3F0A18 *)&b = 0;
        b.z = D_L09_001DF530;
        a = b;
        func_0038CE20(&a, &a, 2.7311214f);
        *(u128_t_3F0A18 *)&b = 0;
        b.z = -0.14000001f;
        func_L02_003E2E38(a0, &a, 0.1f, &b, 0x14, 0, 0, 0.18f, *(f32 *)(a0 + 0x2C) * 4.096682f, 20.0f, 1.0f);
        func_0038CE20(&a, &a, *(f32 *)(a0 + 0x2C));
        func_0038D000(&a, &a, a0 + 0xC0);
        vec_add_ab(&a, &a, a0 + 0x10);
        func_L01_003303B8(&a, 0, 0, 0, 0, 2, 5, 0, D_L09_001DF534 * 2.7311214f * *(f32 *)(a0 + 0x2C), 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x8EFFFE, 0x40FFFD, 0, 0, 0, 0, 0x8EFFFE, 0x40FFFD, 0, 0);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    } else {
        if (!D_L09_001DFBC0) {
            p[1] = func_003824E0(0.041887905f, 0.12566371f);
        } else if (a0[0x31]) {
            func_L01_00451DB8(a0, p, 0xB0B0B0B0, 0x60606060, p[1]);
        }
    }
}
/* localdecomp:end func_L09_003F0A18 */
