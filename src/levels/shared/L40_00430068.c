#include "common.h"

/* localdecomp:start func_L40_00430068 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L40_00430068(s32 a0) {
    return func_L39_0066DD30(a0, 0, 0) != 0;
}
/* localdecomp:end func_L40_00430068 */

/* localdecomp:start func_L40_00430090 */
extern s32 func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_L39_00662AA0(s32 a0, void *a1, s32 a2);
void func_L40_00430090(s32 a0, s32 a1) {
    s32 x;
    s32 r = func_L39_0066DCC8(a0, 0, 0, 250);
    x = a1;
    func_L39_00662AA0(r, &x, 4);
}
/* localdecomp:end func_L40_00430090 */

/* localdecomp:start func_L40_004300D8 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L40_004300D8(s32 a0) {
    return func_L39_0066DD30(a0, 1, 0) != 0;
}
/* localdecomp:end func_L40_004300D8 */

/* localdecomp:start func_L40_00430100 */
extern void func_L39_00662AA0(s32 a0, void *a1, s32 a2);
extern s32 func_L39_0066DCC8(s32, s32, s32, s32);
void func_L40_00430100(s32 a0, s32 a1, u8 a2) {
    u8 buf[4];
    s32 h = func_L39_0066DCC8(a0, 1, 0, 0);
    buf[0] = a1;
    ((void (*)(s32, u8 *, s32))func_L39_00662AA0)(h, buf, 1);
    buf[0] = a2;
    ((void (*)(s32, u8 *, s32))func_L39_00662AA0)(h, buf, 1);
}
/* localdecomp:end func_L40_00430100 */

/* localdecomp:start func_L40_00430170 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L40_00430170(s32 a0) {
    return func_L39_0066DD30(a0, 2, 0) != 0;
}
/* localdecomp:end func_L40_00430170 */

/* localdecomp:start func_L40_00430198 */
extern void func_L39_00662AA0(s32 a0, void *a1, s32 a2);
extern s32 func_L39_0066DCC8(s32, s32, s32, s32);

void func_L40_00430198(u8 *a0) {
    ((void (*)(void *, u8 *, s32))func_L39_00662AA0)(((void * (*)(u8 *, s32, s32, s32))func_L39_0066DCC8)(a0, 2, 0, 250), a0 + 16, 16);
}
/* localdecomp:end func_L40_00430198 */

INCLUDE_ASM("asm/levels", func_L40_004301D8);

INCLUDE_ASM("asm/levels", func_L40_004305B0);

INCLUDE_ASM("asm/levels", func_L40_00430608);
