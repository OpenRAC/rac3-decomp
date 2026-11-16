#include "common.h"

/* NTSC-U counterpart of func_L24_003A7CE8 (src/levels/24_insomniac_museum/L24_003A7AA8.c) */
#include "vu0.h"
typedef struct {
    u8 pad0[0x28];
    f32 f28;
    u8 pad2C[4];
} S_3A7AA8;
extern S_3A7AA8 D_L24_002B9460_003A6110[];
extern void func_003BEB58(void *, void *, void *, f32);

/* localdecomp:start func_L24_003A6110 */
extern void func_003BD9A0(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00462FD0(void *, void *, s32, s32, s32, s32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_003BEB58(void *, void *, void *, f32);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_0037E1D8(s32);
extern void func_L01_00460318(void *, void *, s32, s32, s32, s32, s32, s32);

void func_L24_003A6110(void *a0, u8 *a1) {
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    f32 e[16] __attribute__((aligned(16)));
    s32 n;
    s32 i;

    qzero(d);
    func_003BD9A0(a0, 0, e);
    *(vu0_q *)a = *(vu0_q *)e;
    func_00388830(a, a, 0.3f);
    vec_add_ab(a, a, &e[12]);
    func_L01_00462FD0(a, d, 0x70000FF, 0x10000FF, func_0037E208(10, 15), 1, 50000.0f);
    if (*(s32 *)(a1 + 0x980) != 0) {
        n = *(s32 *)(a1 + 0x980) - 1;
        func_003BDA38(a0, 2, b);
        func_003BDA38(a0, 1, c);
        for (i = 0; i < 3; i++) {
            func_003BEB58(a, c, b, func_0037E250(0.4f, 1.0f));
            qzero(d);
            d[0] = func_0037E250(-0.02f, 0.02f);
            d[1] = func_0037E250(-0.02f, 0.02f);
            if (func_0037E1D8(5) == 0) {
                func_00388830(d, d, 20.0f);
            }
            d[2] = func_0037E250(0.05f, 0.1f);
            a[2] = a[2] - 0.5f;
            func_L01_00460318(a, d, *(s32 *)&D_L24_002B9460_003A6110[n].pad0[0], *(s32 *)&D_L24_002B9460_003A6110[n].pad0[4], *(s32 *)&D_L24_002B9460_003A6110[n].pad0[16], *(s32 *)&D_L24_002B9460_003A6110[n].pad0[8], *(s32 *)&D_L24_002B9460_003A6110[n].pad0[12], 1);
        }
    }
}
/* localdecomp:end func_L24_003A6110 */
