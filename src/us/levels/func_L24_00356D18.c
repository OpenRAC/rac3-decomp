#include "common.h"

/* NTSC-U counterpart of func_L24_00357D50 (src/levels/24_insomniac_museum/L24_00356100.c): 0.00288 -> 0.002; 150 -> 180 */
#include "vu0.h"
extern void func_003BDA38(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern void func_003BDA38(void *, s32, void *);
#include "vu0.h"
#include "vu0.h"
extern void func_003BDA38(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
#include "vu0.h"
extern void func_003BDA38(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
#include "vu0.h"
extern void func_003BDA38(void *, s32, void *);

/* localdecomp:start func_L24_00356D18 */
#include "vu0.h"
extern void func_003BDA38(void *, s32, void *);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E1D8(s32);
extern void func_L01_00467DA8(f32 *, s32, s32, s32, s32, f32 *, f32, f32, f32, s32);

void func_L24_00356D18(u8 *obj) {
    f32 d[4];
    f32 a[4];
    f32 c[4];
    f32 f;
    s32 n;
    s32 r;

    n = 3;
    do {
        func_003BDA38(obj, 7, a);
        n--;
        a[0] += func_0037E250(-0.15f, 0.15f);
        a[1] += func_0037E250(-0.15f, 0.15f);
        a[2] += func_0037E250(-0.15f, 0.15f);
        *(vu0_q *)c = *(vu0_q *)(obj + 0xC0);
        func_00388830(c, c, 0.5f);
        vec_add_ab(a, a, c);
        *(vu0_q *)d = *(vu0_q *)(obj + 0xC0);
        d[0] += func_0037E250(-0.07f, 0.07f);
        d[1] += func_0037E250(-0.07f, 0.07f);
        d[2] += func_0037E250(0.0f, 0.3f);
        func_00388830(d, d, func_0037E250(0.05f, 0.2f));
        f = func_0037E250(0.15f, 0.3f);
        r = func_0037E1D8(2);
        if (r == 0)
            r = r - 1;
        func_L01_00467DA8(a, 0xB4, 0x7F007FFF, 0, r, d, f * 0.1f, f, 0.00200000009f, 0);
    } while (n >= 0);
}
/* localdecomp:end func_L24_00356D18 */
