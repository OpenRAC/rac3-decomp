#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L07_00351240. */
/* localdecomp:start func_U_L07_00350588 */
typedef struct { u8 pad0[0x25C0]; s32 x25C0; u8 pad25C4[0x2808 - 0x25C4]; u8 *x2808; } H_00351240;
extern H_00351240 D_001A4BE0;
extern u8 D_001A4CF0[];
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
extern s32 D_L07_001DD600_00350588;
__asm__(".extern D_L07_001DD600_00350588, 4");
extern f32 D_L07_001DD604_00350588;
__asm__(".extern D_L07_001DD604_00350588, 4");
extern f32 D_L07_001DD608_00350588;
__asm__(".extern D_L07_001DD608_00350588, 4");
extern s32 func_00388398(void *);
extern s32 func_003883C8(void *);
extern void func_L01_00445F50(s32, void *, s32);
extern void func_003BDA38(void *, s32, void *);
extern f32 func_003887C8(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_003887A0(void *);
extern f32 func_00389380(f32, f32);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);

void func_U_L07_00350588(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    vu0_v4 a;
    vu0_v4 b;
    f32 k;
    f32 r;

    func_00388398(v + 0x298);
    func_003883C8(v + 0x29C);
    if (*(u16 *)(o + 0x96) <= 0xFFFE) {
        *(u16 *)(o + 0x96) += 1;
    }
    if (D_001A4BE0.x2808 == o && D_L07_001DD600_00350588 == 0) {
        D_L07_001DD600_00350588 = 60;
    }
    if (D_L07_001DD600_00350588 > 0) {
        func_L01_00445F50(D_001A4BE0.x25C0, D_L07_001D66B0, 0xFFFF);
        func_00388398(&D_L07_001DD600_00350588);
    }
    func_003BDA38(o, 1, &a);
    if (o[0x20] != 5) {
        r = func_003887C8(&a, v + 0x220);
        k = 0.5f;
        func_003886E8(&b, D_001A4CF0, (r - 1.0f) * 2.0f);
        b.z = 0.0f;
        vec_add_ab(&b, &b, v + 0x220);
        vec_sub_ab(&a, &b, &a);
        *(f32 *)(v + 0x318) = func_003893C8(func_00388A28(a.x, a.y), *(f32 *)(o + 0xF8));
        func_003BDA38(o, 0, &a);
        vec_sub_ab(&a, &b, &a);
        r = func_003893C8(-func_00388A28(func_003887A0(&a), a.z), *(f32 *)(o + 0xF0));
        *(f32 *)(v + 0x390) = r;
        *(f32 *)(v + 0x420) = r;
    } else {
        k = 0.085f;
        *(f32 *)(v + 0x318) = func_00389380(*(f32 *)(v + 0x2F8), 0.5235988f);
    }
    func_L01_0044B5C8(o, v + 0x2B0, 2, D_L07_001DD604_00350588 * k, D_L07_001DD608_00350588 * k);
    func_L01_0044B5C8(o, v + 0x330, 0, D_L07_001DD604_00350588 * k, D_L07_001DD608_00350588 * k);
    func_L01_0044B5C8(o, v + 0x3C0, 1, D_L07_001DD604_00350588 * k, D_L07_001DD608_00350588 * k);
}
/* localdecomp:end func_U_L07_00350588 */
