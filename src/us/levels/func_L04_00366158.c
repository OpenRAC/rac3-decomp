#include "common.h"

/* NTSC-U counterpart of func_L04_003672E8 (src/levels/04_marcadia/L04_00366800.c): 0.14 -> 0.116667; 0.18 -> 0.15 */
#include "vu0.h"
extern s32 func_0039FE80(s32, s32, void *);
extern void func_003886E8(f32 *, void *, f32);
extern void func_L04_00366158(void *);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);

/* localdecomp:start func_L04_00366158 */
typedef int u128_t_3672E8 __attribute__((mode(TI)));
extern u8 D_L04_001D66B0_00366158[8];
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 *func_L01_0044F1E8(void *, s32, s32);
extern void func_003886E8(f32 *, void *, f32);
extern void func_L02_00426140(void *, void *, s32, s32, void *, s32, s32, s32, f32, f32, f32, f32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_L02_00424E20(void *, f32 *, f32, f32, f32);
extern void func_L01_00447D00(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_0044EBF8(void *, s32, f32);

void func_L04_00366158(void *o) {
    u8 *a0 = o;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 a;
    vu0_v4 d;
    u8 *e;

    func_L01_0044ED60(a0, 0x3F, D_L04_001D66B0_00366158, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
    e = func_L01_0044F1E8(a0, 0x1C77, 0);
    *(s32 *)(a0 + 0x98) = 0;
    a0[0x31] = 0;
    *(u16 *)(a0 + 0x34) |= 1;
    if (e != 0) {
        *(s32 *)(e + 0x98) = *(s32 *)(*(u8 **)(e + 0x24) + 0x10);
    }
    *(u128_t_3672E8 *)&b = 0;
    b.z = 1.0f;
    func_003886E8(&c.x, &b, 4.0f);
    vec_add_ab(&b, &c, a0 + 0x10);
    func_L02_00426140(a0, &b, 7, 1, D_L04_001D66B0_00366158, 0x500092D6, 0, 0xB4, 0.25f, 3.0f, 0.5f, 0.75f);
    func_0039FE80(0, 0, a0);
    *(u128_t_3672E8 *)&c = 0;
    *(u128_t_3672E8 *)&a = 0;
    c.z = 18.0f;
    a.z = 0.116666675f;
    func_L02_003E0520(a0, &c, 0.1f, &a, 0x50, 3, 0, 0.150000006f, 1.0f, 20.0f, 1.0f);
    *(u128_t_3672E8 *)&d = 0;
    func_L02_00424E20(a0, &c.x, 0.0f, 0.0f, 18.0f);
    func_L01_00447D00(a0, &d, &c, 10, 3, 5, -1, 0, 0, -1, 0, 0x1010001, 0.0f, 0.0f, 0.0f, 1.0f, 9.0f, 0.5f, 0.0f);
    func_L01_0044EBF8(a0, 1, 0.0f);
}
/* localdecomp:end func_L04_00366158 */
