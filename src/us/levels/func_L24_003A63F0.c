#include "common.h"

/* NTSC-U counterpart of func_L24_003A7FD8 (src/levels/24_insomniac_museum/L24_003A7AA8.c): 5 -> 6; 8 -> 10 */
#include "vu0.h"
extern void func_003BEB58(void *, void *, void *, f32);
extern void func_003BD9A0(void *, s32, void *);
extern void func_00388830(void *, void *, f32);

/* localdecomp:start func_L24_003A63F0 */

extern void func_003BD9A0(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_L03_004307B8(void *, void *, void *, s32, s32, s32, s32, f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_003BEB58(void *, void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00462FD0(void *, void *, s32, s32, s32, s32, f32);

void func_L24_003A63F0(void *a0, u8 *a1) {
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 d[16] __attribute__((aligned(16)));
    f32 f[4] __attribute__((aligned(16)));
    f32 zero = 0.0f;
    func_003BD9A0(a0, 0, d);
    *(vu0_q *)a = *(vu0_q *)d;
    func_00388830(a, a, 0.1f);
    vec_add_ab(a, a, &d[12]);
    func_L03_004307B8(a0, a, a1 + 0x970, 0x10000, 0, 1, 0, (f32)(*(s32 *)(a1 + 0x95C) + 4), zero);
    *(vu0_q *)f = *(vu0_q *)(a1 + 0x970);
    func_003BEB58(b, a, f, func_0037E250(zero, 1.0f));
    *(vu0_q *)c = *(vu0_q *)d;
    func_00388830(c, c, 0.02f);
    func_L01_00462FD0(b, c, 0x40000FFF, 0x10000FF, func_0037E208(6, 10), 1, 25000.0f);
}
/* localdecomp:end func_L24_003A63F0 */
