#include "common.h"

/* NTSC-U counterpart of func_L19_003AF428 (src/levels/shared/L19_003AF1D0.c) */
typedef struct Eff_003AF1D0 {
    u8 pad0[0x2C];
    f32 f2C;
} Eff_003AF1D0;
extern Eff_003AF1D0 *func_L19_003AD7D8(void *, void *, void *);

/* localdecomp:start func_L19_003AD7D8 */
/* from the NTSC-U draft of func_L19_003AD7D8 (nonmatching/levels/func_L19_003AD7D8.c) */
#include "vu0.h"

extern vu0_v4 D_L19_001E8E60_003AD7D8;
extern u8 *func_003BCFB0(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00452E70(void *, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);
struct Eff_003AF1D0; /* func_L19_003AF1D0 declares this function as Eff_003AF1D0 *(void *, void *, void *) */

struct Eff_003AF1D0 *func_L19_003AD7D8(void *a0, void *a1, void *a2) {
    f32 v0[4] __attribute__((aligned(16)));
    f32 v10[4] __attribute__((aligned(16)));
    u8 *m;
    u8 *d;
    vu0_q q;

    m = func_003BCFB0(0x1AB7, 0x80);
    if (m != 0) {
        d = *(u8 **)(m + 0x68);
        *(s32 *)d = 0xC8;
        *(f32 *)(d + 8) = func_0037E250(-0.034906588f, 0.034906588f);
        *(vu0_q *)(d + 0x20) = *(vu0_q *)a2;
        func_L01_00452E70(m, a0);
        q = *(vu0_q *)a1;
        *(vu0_q *)(m + 0x10) = q;
        *(vu0_q *)v10 = q;
        func_00388830(v0, d + 0x20, -0.5f);
        vec_add_ab(v0, v0, v10);
        if (func_003CE740(v0, v10, 2, 0, 0) != 0) {
            *(vu0_q *)(m + 0x10) = *(vu0_q *)&D_L19_001E8E60_003AD7D8;
            func_003886E8(d + 0x20, d + 0x20, -1.0f);
        }
        func_L01_00441FB8(m, 0, 0);
    }
    return (struct Eff_003AF1D0 *)m;
}
/* localdecomp:end func_L19_003AD7D8 */
