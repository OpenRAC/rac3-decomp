#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_00430928);

INCLUDE_ASM("asm/levels", func_L40_00430DD0);

INCLUDE_ASM("asm/levels", func_L40_004311A8);

/* localdecomp:start func_L40_00431338 */
extern u8 *func_L39_0066DD30(s32, s32, s32);
extern void func_L39_00662B18(u8 *, void *, s32);

f32 func_L40_00431338(s32 a0, void *a1) {
    f32 v = 0.0f;
    u8 *o = func_L39_0066DD30(a0, 1, 1);
    if (o != 0) {
        o[84] = 0;
        func_L39_00662B18(o, &v, 4);
        func_L39_00662B18(o, a1, 8);
    }
    return v;
}
/* localdecomp:end func_L40_00431338 */

INCLUDE_ASM("asm/levels", func_L40_004313A0);

/* localdecomp:start func_L40_004314C0 */
extern u8 *func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_L39_00662AA0(u8 *a0, s32 a1, s32 a2);
extern u8 *func_L39_0066DD30(s32 a0, s32 a1, s32 a2);
extern void func_L39_006626E8(u8 *a0);

void func_L40_004314C0(s32 id, s32 value) {
    u8 *p;

    func_L39_00662AA0(func_L39_0066DCC8(id, 0, 0, 250), value, 8);
    p = func_L39_0066DD30(id, 1, 0);
    if (p != 0 && p[85] != 0) {
        func_L39_006626E8(p);
    }
}
/* localdecomp:end func_L40_004314C0 */

/* localdecomp:start func_L40_00431540 */
extern u8 *func_L39_0066DD30(s32 a0, s32 a1, s32 a2);
s32 func_L40_00431540(s32 a0) {
    return ((s32 (*)(s32, s32, s32))func_L39_0066DD30)(a0, 0, 0) != 0;
}
/* localdecomp:end func_L40_00431540 */

INCLUDE_ASM("asm/levels", func_L40_00431568);

INCLUDE_ASM("asm/levels", func_L40_00431768);
