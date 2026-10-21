#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_00444F38);

INCLUDE_ASM("asm/levels", func_L01_004450F0);

INCLUDE_ASM("asm/levels", func_L01_00445130);

/* localdecomp:start func_L01_00445170 */
void func_L01_00445170(u8 *a, u8 v) {
    a[149] = v;
    a[190] &= ~2;
}
/* localdecomp:end func_L01_00445170 */

/* localdecomp:start func_L01_00445188 */
void func_L01_00445188(u8 *a, u8 v) {
    a[188] = v;
    a[190] &= ~0x20;
}
/* localdecomp:end func_L01_00445188 */

/* localdecomp:start func_L01_004451A0 */
float func_L01_004451A0(float x) {
    return x * x;
}
/* localdecomp:end func_L01_004451A0 */

/* localdecomp:start func_L01_004451A8 */
f32 func_L01_004451A8(f32 t) {
    t = 1.0f - t;
    return 1.0f - t * t;
}
/* localdecomp:end func_L01_004451A8 */

LINKER_REMNANT("asm/levels", func_L01_004451C8);

/* localdecomp:start func_L01_004451D0 */
f32 func_L01_004451D0(f32 p0, f32 p1, f32 p2, f32 p3, f32 t) {
    f32 t2 = t * t;
    f32 a = (p3 - p2) - (p0 - p1);
    f32 b = (p0 - p1) - a;
    return a * (t2 * t) + b * t2 + (p2 - p0) * t + p1;
}
/* localdecomp:end func_L01_004451D0 */

INCLUDE_ASM("asm/levels", func_L01_00445208);
