#include "common.h"

INCLUDE_ASM("asm/levels", func_L36_0037BDF0);

/* localdecomp:start func_L36_0037C440 */
extern long func_00389598(s32);
extern f32 func_0038D0B0(f32);
extern void func_003D9508(u8 *, s32, s32, s32, f32, f32, f32);
extern void func_L36_0037CF50(u8 *, u8 *, s32, s32, f32, f32, f32, f32);
void func_L36_0037C440(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *p;
    f32 *q;
    s32 i;
    *(long *)(s + 0x50) = func_00389598(-1);
    q = (f32 *)(s + 0x290);
    p = s + 0x60;
    i = 0x1B;
    do {
        i--;
        func_003D9508(p, 0x39, 0x207F7F8F, 1, func_0038D0B0(q[0]) * 0.25f + 0.5f, -0.1f, q[0]);
        func_003D9508(p, 0x39, 0x207F7F8F, 1, func_0038D0B0(q[0]) * 0.25f + 0.5f, -0.1f, -q[0]);
        func_L36_0037CF50(a0, p, 0x3B, 1, (func_0038D0B0(q[0]) * 0.7f + 0.75f) * 0.1f, 0.2f, 0.0f, 0.005f);
        q++;
        p += 0x10;
    } while (i >= 0);
}
/* localdecomp:end func_L36_0037C440 */

INCLUDE_ASM("asm/levels", func_L36_0037C5C0);

/* localdecomp:start func_L36_0037C740 */
#include "vu0.h"
extern void func_L01_004C7D98(u8 *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00404A10(void *, u8 *);
extern void func_L36_0037C5C0(u8 *);
extern void func_L36_0037C440(u8 *);
void func_L36_0037C740(u8 *a0, s32 a1) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 v0, v1, v2;
    u8 *p;
    f32 *q;
    s32 i;
    f32 t;
    func_L01_004C7D98(a0 + 0x10, &v0);
    q = (f32 *)(s + 0x290);
    p = s + 0x60;
    i = 0x1B;
    do {
        vec_sub_ab(&v1, p, a0 + 0x10);
        func_0038D890(&v2, &v1, &v0, 0.0872664626f);
        i--;
        vec_add_ab(p, &v2, a0 + 0x10);
        *q = func_0038DAB8(q[0], q[-28]);
        t = func_0038D0B0(*q);
        q++;
        t = t * func_003824E0(0.01f, 0.015f);
        *(f32 *)(p + 8) += t;
        p += 0x10;
    } while (i >= 0);
    if (a1 != 0) {
        func_L01_00404A10(func_L36_0037C5C0, a0);
    } else {
        func_L01_00404A10(func_L36_0037C440, a0);
    }
}
/* localdecomp:end func_L36_0037C740 */

INCLUDE_ASM("asm/levels", func_L36_0037C880);

INCLUDE_ASM("asm/levels", func_L36_0037CA40);

INCLUDE_ASM("asm/levels", func_L36_0037CF50);
