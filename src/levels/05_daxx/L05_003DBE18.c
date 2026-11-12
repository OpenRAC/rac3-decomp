#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003DBE18 */
typedef int u128_t_3DBE18 __attribute__((mode(TI)));
extern f32 D_L05_001DF168;
__asm__(".extern D_L05_001DF168, 4");
extern f32 D_L05_001DF16C;
__asm__(".extern D_L05_001DF16C, 4");
extern s32 D_L05_001DF160;
__asm__(".extern D_L05_001DF160, 4");
extern s32 D_L05_001DF164;
__asm__(".extern D_L05_001DF164, 4");
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 *func_L01_00452460(void *, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_0038D000(void *, void *, void *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L05_003DBE18(u8 *a0) {
    vu0_v4 c;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 *cp;
    u8 *m;

    if (func_L01_00447490(a0, -1, 0) != 0) {
        cp = &c;
        m = a0 + 0xC0;
        c = *(vu0_v4 *)m;
        c.z -= 0.5f;
        func_0038CF68(cp, cp, 0.120000005f);
        func_L01_00451FE0(a0, 0x7F, cp, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_003A52A0(0, 0, a0);
        func_L01_00452460(a0, 0x1E5E, 0);
        *(u128_t_3DBE18 *)&b = 0;
        b.x = D_L05_001DF168;
        a = b;
        func_0038CE20(&a, &a, 15.651901f);
        *(u128_t_3DBE18 *)&b = 0;
        b.z = -0.14000001f;
        func_L02_003E2E38(a0, &a, 0.1f, &b, 0x14, 0, 0, 0.18f, 1.5f, 20.0f, 1.0f);
        func_0038CE20(&a, &a, *(f32 *)(a0 + 0x2C));
        func_0038D000(&a, &a, m);
        vec_add_ab(&a, &a, a0 + 0x10);
        func_L01_003303B8(&a, 0, 0, 0, 0, 2, 5, 0, D_L05_001DF16C * 15.651901f * 0.06389f, 0.0f, 0.0f, 0.0f,
                          0, 0, 0, 0, 0, 0, 0x1000000, 0, D_L05_001DF160, D_L05_001DF160, 0, 0, 0, 0,
                          D_L05_001DF164, D_L05_001DF164, 0, 0);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L05_003DBE18 */

/* localdecomp:start func_L05_003DC0B0 */
typedef int u128_t_3DC0B0 __attribute__((mode(TI)));
extern u8 D_L05_001D66B0[8];
__asm__(".extern D_L05_001D66B0, 16");
extern f32 D_L05_001DF170;
__asm__(".extern D_L05_001DF170, 4");
extern f32 D_L05_001DF174;
__asm__(".extern D_L05_001DF174, 4");
extern f32 D_L05_001DF178;
__asm__(".extern D_L05_001DF178, 4");
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

void func_L05_003DC0B0(u8 *a0) {
    vu0_v4 a;
    vu0_v4 b;

    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 0x7F, D_L05_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_00452460(a0, 0x1E85, 0);
        *(u128_t_3DC0B0 *)&b = 0;
        b.y = D_L05_001DF170;
        b.z = D_L05_001DF174;
        a = b;
        func_0038CE20(&a, &a, 5.7342734f);
        *(u128_t_3DC0B0 *)&b = 0;
        b.z = -0.14000001f;
        func_L02_003E2E38(a0, &a, 0.1f, &b, 0x14, 0, 0, 0.18f, 1.5f, 20.0f, 1.0f);
        func_0038CE20(&a, &a, *(f32 *)(a0 + 0x2C));
        func_0038D000(&a, &a, a0 + 0xC0);
        vec_add_ab(&a, &a, a0 + 0x10);
        func_L01_003303B8(&a, 0, 0, 0, 0, 2, 5, 0, D_L05_001DF178 * 5.7342734f * 0.17439000f, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x27B2F3, 0xBDFFF, 0, 0, 0, 0, 0x7F27B2F3, 0x280BDFFF, 0, 0);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L05_003DC0B0 */

/* localdecomp:start func_L05_003DC320 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_003DC320;
extern void func_0038D000(void *, void *, void *);
extern s32 func_00382498(s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern f32 D_001DF17C_sda;
__asm__(".extern D_001DF17C_sda, 4");
extern f32 D_001DF180_sda;
__asm__(".extern D_001DF180_sda, 4");

void func_L05_003DC320(u8 *p) {
    V4_003DC320 a;
    V4_003DC320 b;
    s32 r;
    s32 *q;

    q = *(s32 **)(p + 0x68);
    b = (V4_003DC320){0.0f, 0.0f, 0.0f, 0.0f};
    b.z = D_001DF17C_sda * (1.0f / D_001DF180_sda);
    a = b;
    b = (V4_003DC320){0.0f, 0.0f, 0.0f, 0.0f};
    b.x = 0.040000003f;
    b.z = 0.040000003f;
    func_0038D000(&b, &b, p + 0xC0);
    r = func_00382498(3, 6);
    func_L02_003E2E38(p, &a, 0.0f, &b, r, 0, 0, 0.040000003f, 0.9f, 15.0f, 1.0f);
    b.x = -0.040000003f;
    b.z = 0.048000004f;
    func_0038D000(&b, &b, p + 0xC0);
    r = func_00382498(3, 6);
    func_L02_003E2E38(p, &a, 0.0f, &b, r, 1, 0, 0.040000003f, 0.9f, 15.0f, 1.0f);
    r = func_00382498(90, 180);
    *q = (r * 5 + 2) / 6;
}
/* localdecomp:end func_L05_003DC320 */
