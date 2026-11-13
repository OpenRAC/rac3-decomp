#include "common.h"

/* NTSC-U counterpart of func_L24_0034FA98 (src/levels/24_insomniac_museum/L24_0034F040.c) */
/* localdecomp:start func_L24_0034EBA8 */
#include "vu0.h"
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_003886E8(f32 *, void *, f32);
extern void func_003BDA38(void *, s32, void *);
extern void func_00388BD0(void *, void *);
extern void func_00388E78(void *, void *);
extern void func_003888F0(void *, void *, void *);
extern s32 func_L24_0034FA20(u8 *, void *, s32, f32, f32, f32, f32, f32, f32, f32);
__asm__(".extern D_L24_001DD4F0_0034EBA8, 4");
__asm__(".extern D_L24_001DD4D8_0034EBA8, 2");
extern f32 D_L24_001DD4F0_0034EBA8;
extern u16 D_L24_001DD4D8_0034EBA8;

void func_L24_0034EBA8(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 out[4];
    f32 a[4];
    f32 c[4];
    f32 b[4];
    u8 m1[0x30];
    u8 m2[0x40];
    f32 w[4];

    *(vu0_q *)a = 0;
    qzero(b);
    b[2] = func_00389380(*(f32 *)(s + 0x140), *(f32 *)(obj + 0xF8));
    b[1] = *(f32 *)(s + 0x148);
    func_0037E4B8(a, 1.0f, func_00389380(*(f32 *)(s + 0x140), *(f32 *)(obj + 0xF8)), -*(f32 *)(s + 0x148));
    func_003886E8(c, s + 0x100, 3.0f);
    vec_add_ab(a, a, c);
    func_003BDA38(obj, 2, out);
    func_00388BD0(m1, b);
    func_00388E78(m2, m1);
    func_003888F0(w, s + 0x100, m2);
    if (func_L24_0034FA20(obj, out, *(s32 *)(s + 0x15C), b[2], b[1], *(f32 *)(s + 0x160), b[2], b[1], w[0], D_L24_001DD4F0_0034EBA8) != 0) {
        *(s16 *)(s + 0x168) = D_L24_001DD4D8_0034EBA8;
    }
}
/* localdecomp:end func_L24_0034EBA8 */
