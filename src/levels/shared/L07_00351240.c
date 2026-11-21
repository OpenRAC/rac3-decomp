#include "common.h"

/* localdecomp:start func_L07_00351240 */
#include "vu0.h"
typedef struct { u8 pad0[0x25C0]; s32 x25C0; u8 pad25C4[0x2808 - 0x25C4]; u8 *x2808; } H_00351240;
extern H_00351240 D_001A4BE0;
extern u8 D_001A4CF0[];
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
extern s32 D_L07_001DD5C0;
__asm__(".extern D_L07_001DD5C0, 4");
extern f32 D_L07_001DD5C4;
__asm__(".extern D_L07_001DD5C4, 4");
extern f32 D_L07_001DD5C8;
__asm__(".extern D_L07_001DD5C8, 4");
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_00449088(s32, void *, s32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L07_00351240(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    vu0_v4 a;
    vu0_v4 b;
    f32 k;
    f32 r;

    func_0038CAD0(v + 0x298);
    func_0038CB00(v + 0x29C);
    if (*(u16 *)(o + 0x96) <= 0xFFFE) {
        *(u16 *)(o + 0x96) += 1;
    }
    if (D_001A4BE0.x2808 == o && D_L07_001DD5C0 == 0) {
        D_L07_001DD5C0 = 50;
    }
    if (D_L07_001DD5C0 > 0) {
        func_L01_00449088(D_001A4BE0.x25C0, D_L07_001D66B0, 0xFFFF);
        func_0038CAD0(&D_L07_001DD5C0);
    }
    func_003C2F58(o, 1, &a);
    if (o[0x20] != 5) {
        r = func_0038CF00(&a, v + 0x220);
        k = 0.5f;
        func_0038CE20(&b, D_001A4CF0, (r - 1.0f) / 0.6f);
        b.z = 0.0f;
        vec_add_ab(&b, &b, v + 0x220);
        vec_sub_ab(&a, &b, &a);
        *(f32 *)(v + 0x318) = func_0038DB00(func_0038D160(a.x, a.y), *(f32 *)(o + 0xF8));
        func_003C2F58(o, 0, &a);
        vec_sub_ab(&a, &b, &a);
        r = func_0038DB00(-func_0038D160(func_0038CED8(&a), a.z), *(f32 *)(o + 0xF0));
        *(f32 *)(v + 0x390) = r;
        *(f32 *)(v + 0x420) = r;
    } else {
        k = 0.085f;
        *(f32 *)(v + 0x318) = func_0038DAB8(*(f32 *)(v + 0x2F8), 0.5235988f);
    }
    func_L01_0044E850(o, v + 0x2B0, 2, D_L07_001DD5C4 * 1.44f * k, D_L07_001DD5C8 * 1.44f * k);
    func_L01_0044E850(o, v + 0x330, 0, D_L07_001DD5C4 * 1.44f * k, D_L07_001DD5C8 * 1.44f * k);
    func_L01_0044E850(o, v + 0x3C0, 1, D_L07_001DD5C4 * 1.44f * k, D_L07_001DD5C8 * 1.44f * k);
}
/* localdecomp:end func_L07_00351240 */

/* localdecomp:start func_L07_00351498 */
extern void func_L07_00351498(u8 *);
extern u16 *D_L07_0021C020[];
extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");
extern s32 D_L07_001DF458 __attribute__((section(".sdata")));

/* from rac2-decomp's func_L16_0040D188 */
void func_L07_00351498(u8 *arg0)
{
    u16 *p;
    u8 *e;
    if (arg0[0x21] == 0xFF)
        return;
    p = D_L07_0021C020[arg0[0x21]];
    while (arg0[0x21] != 0xFF && arg0[0x21] <= D_L07_001DF458 && p != 0 &&
           ((p != 0 && (s16)p[-1] >= 0) || p == D_L07_0021C020[arg0[0x21]])) {
        e = D_L07_001DF41C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (*(s16 *)(e + 0xAA) == 0x161e)
            *(s32 *)(*(u8 **)(e + 0x68) + 0x2a4) = 1;
        else if (*(s16 *)(e + 0xAA) == 0xEA3)
            *(s32 *)(*(u8 **)(e + 0x68) + 0x27c) = 1;
        p++;
    }
}
/* localdecomp:end func_L07_00351498 */
