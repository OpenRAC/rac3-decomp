#include "common.h"

/* NTSC-U counterpart of func_L24_00350190 (src/levels/24_insomniac_museum/L24_0034F040.c): 0.02 -> 0.0166667; 0.0004 -> 0.000277778 */
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern f32 D_L24_001DD518;
extern f32 D_L24_001DD51C;
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L24_0034F270 */
#include "vu0.h"
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_004C3E68(f32, void *, void *, void *, void *, void *, s32, s32);
__asm__(".extern D_L24_001DD518, 4");
__asm__(".extern D_L24_001DD51C, 4");
extern f32 D_L24_001DD518;
extern f32 D_L24_001DD51C;

void func_L24_0034F270(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 out[4];
    f32 a[4];
    f32 b[4];
    f32 k;

    *(u128_t *)a = 0;
    qzero(b);
    b[2] = func_0038DAB8(*(f32 *)(s + 0x140), *(f32 *)(obj + 0xF8));
    b[1] = *(f32 *)(s + 0x148);
    k = D_L24_001DD518 * 0.0166666675f;
    func_00382760(a, k, func_0038DAB8(*(f32 *)(s + 0x140), *(f32 *)(obj + 0xF8)), -*(f32 *)(s + 0x148));
    vec_add_ba(a, a, s + 0x100);
    func_003C2F58(obj, 2, out);
    s[0x1A4] = func_L01_004C3E68(D_L24_001DD51C * 0.000277777785f, out, a, s + 0x170, s + 0x180, obj, 0, 0);
}
/* localdecomp:end func_L24_0034F270 */
