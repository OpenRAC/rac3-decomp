/* functional: high. 21 diff words at the file's flags (scheduling/register only; the lqc2 helper operands do not assemble with the stock ee-as). All offsets, callee args and the lwc1-in-likely-delay-slot (p+0x38 saved only on the else path) checked against retail. */
#include "vu0.h"
extern u8 D_001A4BE0[];
extern u8 D_L01_001EAA30[];
extern s32 D_001D673C;
extern s32 func_L01_003FB640(void *, s32, s32, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_0040E790(void *, void *, void *);

void func_L01_0033ED30(u8 *m) {
    u8 *p = *(u8 **)(m + 0x68);
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    f32 save;
    f32 d;
    u8 *h = D_001A4BE0;

    if (func_L01_003FB640(m + 0x10, 0, *(s32 *)(D_001A4BE0 + 0x25C0), 0.25f) != 0) {
        *(vu0_q *)(m + 0x10) = *(vu0_q *)D_L01_001EAA30;
        if (D_001D673C != 0) {
            vec_sub_ab(&a, h + 0xB0, m + 0x10);
            func_0038CF68(&a, &a, 1.0f);
            d = func_0038CE68(&a, p + 0x30);
            func_0038CE20(&b, &a, d);
            vec_sub_ab(&c, p + 0x30, &b);
            func_L01_0040E790(p + 0x30, &c, D_L01_001EAA30 + 0x10);
            vec_add_ab(p + 0x30, p + 0x30, &b);
        } else {
            save = *(f32 *)(p + 0x38);
            *(s32 *)(p + 0x38) = 0;
            func_L01_0040E790(p + 0x30, p + 0x30, D_L01_001EAA30 + 0x10);
            *(f32 *)(p + 0x38) = save;
        }
    }
}
