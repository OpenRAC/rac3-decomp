#include "common.h"

/* localdecomp:start func_L22_003E9FF0 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(u8 *);

u8 *func_L22_003E9FF0(u8 *parent, s32 oclass)
{
    u8 *obj = func_003C24B0(oclass, 128);

    if (obj != 0) {
        *(u16 *)(obj + 50) = 255;
        obj[49] = 1;
        *(f32 *)(obj + 44) *= *(f32 *)(parent + 44) / *(f32 *)(*(u8 **)(parent + 36) + 36);
        *(u128_t *)(obj + 16) = *(u128_t *)(parent + 16);
        *(u128_t *)(obj + 240) = *(u128_t *)(parent + 240);
        *(long *)(obj + 56) = *(long *)(parent + 56);
        *(u16 *)(obj + 52) = 0;
        func_003C7C38(obj);
        return obj;
    }
    return 0;
}
/* localdecomp:end func_L22_003E9FF0 */

/* localdecomp:start func_L22_003EA088 */
#include "vu0.h"
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 *func_L22_003E9FF0(u8 *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L02_00429840(void *, void *, f32, s32, s32, void *, f32, f32, f32, s32, void *, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_003303B8(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
extern u8 D_L22_001D66B0[8];
__asm__(".extern D_L22_001D66B0, 16");

void func_L22_003EA088(u8 *a0, s32 a1, s16 a2, s32 a3, s32 a4, f32 f1, f32 f2, f32 f3) {
    vu0_v4 v;
    vu0_v4 w;
    vu0_v4 *pv;
    func_003A52A0(0, 0, a0);
    func_L01_00451FE0(a0, a1, D_L22_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f, 0, 3);
    if (a3 != 0) {
        func_L22_003E9FF0(a0, a3);
    }
    *(u128_t *)&v = *(u128_t *)(a0 + 16);
    *(u128_t *)&w = *(u128_t *)(a0 + 192 + a2 * 16);
    pv = &v;
    func_0038CF68(&w, &w, *(f32 *)(a0 + 44) / *(f32 *)(*(u8 **)(a0 + 36) + 36) * f1);
    v.z += *(f32 *)(a0 + 44) / *(f32 *)(*(u8 **)(a0 + 36) + 36) * f2;
    vec_add_ab(pv, pv, &w);
    func_L02_00429840(a0, pv, 0.5f, 20, 0, D_L22_001D66B0, 20.0f, 0.3f, 0.6f, a4, 0, 75);
    func_L02_003E2E38(a0, pv, 1.0f, D_L22_001D66B0, 15, 0, 1, 0.050000004f, 2.5f, 5.0f, 1.0f);
    func_L01_003303B8(pv, *(f32 *)(a0 + 44) / *(f32 *)(*(u8 **)(a0 + 36) + 36) * f3, 1, 15, 0, 0, 3, 5, 0, 0.0f, 0.0f, 0.0f,
        1, 1, 1, 0, 0, 1, 0x1000000, 0, 0x20408F, 0x5080, 0x3060, 0x202060, 0, 0, 0x7F2080FF, 0x280000FF, 0x5070, 0);
    func_L01_00451E78(a0, 1, 0.0f);
    func_003C2880(a0);
}
/* localdecomp:end func_L22_003EA088 */

/* localdecomp:start func_L22_003EA388 */
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L22_003EA088(u8 *, s32, s16, s32, s32, f32, f32, f32);

void func_L22_003EA388(void *a0) {
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_L22_003EA088(a0, 0x7FF, 0, 0x1EC0, 0x80000020, 1.0f, 0.0f, 1.8f);
    }
}
/* localdecomp:end func_L22_003EA388 */

/* localdecomp:start func_L22_003EA3F0 */
#include "vu0.h"
extern void func_L01_004450F0(void *, s32, s32);
extern void func_0038D308(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern u8 D_L22_001DF390[8];
__asm__(".extern D_L22_001DF390, 8");

void func_L22_003EA3F0(u8 *a0) {
    vu0_v4 v;
    vu0_v4 w;
    vu0_v4 t;
    u8 *q;
    f32 f20, f21, f22, f23;
    if (a0[0x20] == 0) {
        s32 n = *(u16 *)(a0 + 0x96) + 1;
        *(u16 *)(a0 + 0x96) = n;
        if ((u16)n >= 0x125) {
            func_L01_004450F0(a0, 1, -1);
            return;
        }
        q = a0 + 0xC0;
        func_0038D308(q, a0 + 0xF0);
        f20 = -0.051f;
        func_0038D000(&t, D_L22_001DF390, q);
        vec_add_ba(&v, a0 + 0x10, &t);
        func_0038CF68(&w, q, f20);
        w.z += f20;
        func_003C4C18(&v, 0.01f);
        func_003C4C18(&w, 0.02f);
        func_0038D000(&w, &w, q);
        f22 = 210000.0f;
        f21 = func_003824E0(0.25f, 0.35f) * f22;
        f23 = func_003824E0(0.7f, 0.9f) * f22;
        func_L01_0046FB40(&v, &w, 17, 0x808080, 30, 96, 32, f21, f23, func_003824E0(-0.007f, -0.01f), 0);
    }
}
/* localdecomp:end func_L22_003EA3F0 */
