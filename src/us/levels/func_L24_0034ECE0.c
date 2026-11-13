#include "common.h"

/* NTSC-U counterpart of func_L24_0034FBE8 (src/levels/24_insomniac_museum/L24_0034F040.c) */
#include "vu0.h"
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_003BDA38(void *, s32, void *);

/* localdecomp:start func_L24_0034ECE0 */
#include "vu0.h"
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_L24_003504C0(void *, void *, void *, s32, s32, f32, f32, f32, f32);
__asm__(".extern D_L24_001DD518, 4");
__asm__(".extern D_L24_001DD51C, 4");
__asm__(".extern D_L24_001DD520, 4");
__asm__(".extern D_L24_001DD524, 2");
extern f32 D_L24_001DD518;
extern f32 D_L24_001DD51C;
extern f32 D_L24_001DD520;
extern u16 D_L24_001DD524;

void func_L24_0034ECE0(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 out[4];
    f32 a[4];
    f32 b[4];
    f32 k;

    *(vu0_q *)a = 0;
    qzero(b);
    b[2] = func_00389380(*(f32 *)(s + 0x140), *(f32 *)(obj + 0xF8));
    b[1] = *(f32 *)(s + 0x148);
    k = D_L24_001DD518 * 0.016666668f;
    func_0037E4B8(a, k, func_00389380(*(f32 *)(s + 0x140), *(f32 *)(obj + 0xF8)), -*(f32 *)(s + 0x148));
    vec_add_ab(a, a, s + 0x100);
    func_003BDA38(obj, 2, out);
    if (func_L24_003504C0(out, obj, a, 2, 3, D_L24_001DD51C, D_L24_001DD520, 2.0f, 2.0f) != 0) {
        *(s16 *)(s + 0x168) = D_L24_001DD524;
    }
}
/* localdecomp:end func_L24_0034ECE0 */
