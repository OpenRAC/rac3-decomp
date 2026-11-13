#include "common.h"

/* declared by functions of L40_00424920.c, which this file was cut from */
extern u8 *func_L39_0066DD30(s32, s32, s32);

/* localdecomp:start func_L40_00424F88 */
extern s32 func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_L39_00662AA0(s32 a0, void *a1, s32 a2);
void func_L40_00424F88(s32 a0, s32 a1) {
    s32 x;
    s32 r = func_L39_0066DCC8(a0, 0, 0, 250);
    x = a1;
    func_L39_00662AA0(r, &x, 4);
}
/* localdecomp:end func_L40_00424F88 */

/* localdecomp:start func_L40_00424FD0 */
extern void func_L39_00662AA0(s32 a0, void *a1, s32 a2);
extern s32 func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 *func_L39_0066DD30(s32 a0, s32 a1, s32 a2);
extern void func_L39_006626E8(u8 *a0);

void func_L40_00424FD0(s32 id, s32 value) {
    u8 *p;

    ((void (*)(u8 *a0, s32 a1, s32 a2))func_L39_00662AA0)(((u8 * (*)(s32 a0, s32 a1, s32 a2, s32 a3))func_L39_0066DCC8)(id, 1, 0, 250), value, 8);
    p = func_L39_0066DD30(id, 2, 0);
    if (p != 0 && p[85] != 0) {
        func_L39_006626E8(p);
    }
}
/* localdecomp:end func_L40_00424FD0 */

/* localdecomp:start func_L40_00425050 */
extern u8 *func_L39_0066DD30(s32 a0, s32 a1, s32 a2);
s32 func_L40_00425050(s32 a0) {
    return ((s32 (*)(s32, s32, s32))func_L39_0066DD30)(a0, 0, 0) != 0;
}
/* localdecomp:end func_L40_00425050 */

/* localdecomp:start func_L40_00425078 */
extern u8 *func_L39_0066DD30(s32 a0, s32 a1, s32 a2);
s32 func_L40_00425078(s32 a0) {
    return ((s32 (*)(s32, s32, s32))func_L39_0066DD30)(a0, 1, 0) != 0;
}
/* localdecomp:end func_L40_00425078 */

INCLUDE_ASM("asm/levels", func_L40_004250A0);
