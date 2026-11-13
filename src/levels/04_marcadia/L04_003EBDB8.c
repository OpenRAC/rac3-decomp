#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_003EBDB8 */
typedef int u128_t_3EBDB8 __attribute__((mode(TI)));
extern u8 D_L04_001D66B0[8];
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 *func_L01_00452460(void *, s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L04_003EBDB8(u8 *a0) {
    vu0_v4 b;
    vu0_v4 a;
    f32 t;
    u8 *e;

    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 0x7FF, D_L04_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        e = func_L01_00452460(a0, 0x1CC9, 0);
        if (e != 0) {
            *(s32 *)(e + 0x98) = *(s32 *)(*(u8 **)(e + 0x24) + 0x10);
        }
        t = *(f32 *)(a0 + 0x2C) / 0.14969000f;
        *(u128_t_3EBDB8 *)&a = 0;
        a.z = t + t;
        b = a;
        *(u128_t_3EBDB8 *)&a = 0;
        a.z = -0.14000001f;
        func_L02_003E2E38(a0, &b, 0.1f, &a, 0x50, 3, 0.18f, 2.5f, 20.0f, 1.0f, 0);
        vec_add_ab(&b, &b, a0 + 0x10);
        func_L01_003303B8(&b, 0, 0, 0, 0, 2, 5, 0, t, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x27B2F3, 0xBDFFF, 0, 0, 0, 0, 0x7F27B2F3, 0x280BDFFF, 0, 0);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L04_003EBDB8 */

/* localdecomp:start func_L04_003EC000 */
typedef int u128_t_3EC000 __attribute__((mode(TI)));
extern u8 D_L04_001D66B0[8];
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 *func_L01_00452460(void *, s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L04_003EC000(u8 *a0) {
    vu0_v4 b;
    vu0_v4 a;
    f32 t;

    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 0xF, D_L04_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_00452460(a0, 0x1F25, 0);
        t = *(f32 *)(a0 + 0x2C) / 0.03721f;
        *(u128_t_3EC000 *)&b = 0;
        b.y = -0.3f;
        b.z = t * 0.2f;
        func_0038D000(&b, &b, a0 + 0xC0);
        *(u128_t_3EC000 *)&a = 0;
        a.z = -0.14000001f;
        func_L02_003E2E38(a0, &b, 0.1f, &a, 0x50, 3, 0.18f, 2.5f, 20.0f, 1.0f, 0);
        vec_add_ab(&b, &b, a0 + 0x10);
        func_L01_003303B8(&b, 0, 0, 0, 0, 2, 5, 0, t * 0.6f, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x27B2F3, 0xBDFFF, 0, 0, 0, 0, 0x7F27B2F3, 0x280BDFFF, 0, 0);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L04_003EC000 */

/* localdecomp:start func_L04_003EC268 */
extern u8 D_L04_001D66B0[8];
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L04_003EC268(void *o) {
    if (func_L01_00447490(o, -1, 0) != 0) {
        func_003A52A0(0, 0, o);
        func_L01_00451FE0(o, 15, D_L04_001D66B0, 2.0f, 4.0f, 2.0f, 4.0f, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f, 0, 3);
        func_L01_00451E78(o, 1, 0.0f);
        func_003C2880(o);
    }
}
/* localdecomp:end func_L04_003EC268 */
