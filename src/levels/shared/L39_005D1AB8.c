#include "common.h"

/* localdecomp:start func_L39_005D1AB8 */
/* LOG func_L39_005D1AB8: body matches retail's instructions (only prologue/epilogue differ).
 * 49 diff with the file's flags: retail saves $s0-$fp/$ra with sq in ascending 16-byte slots (frame 0xB0) =
 * the sq_ra layout (asm_filter.py sq_ra_funcs) built without -fopt-stack; and the float constant 0x39D1B718 is
 * built inline (lui/ori/mtc1) which needs @ps2as (without it: lwc1 from $gp). With --as ps2as --flags=-fno-opt-stack:
 * 20 diff, all of them the sq slot order ($ra lowest in gcc, highest in retail), which the sq_ra rewrite fixes.
 * Source order that matters: q+0xC store after the quad copy; a7 != -1 arm first.
 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_L39_005C4390(s32);
extern int func_0019D510(void);
extern unsigned char *D_L39_00296984[];

/* from this file's neighbour func_L39_005C8990 (same effect-spawn shape) */
void *func_L39_005D1AB8(void *a0, void *a1, int a2, int a3, int a4, int a5, int a6, int a7, float f, float g, int h)
{
    char *p;
    char *q;

    if (a4 == 0)
        return 0;
    p = (char *)func_L39_005C4390(0x5B);
    if (p != 0) {
        *(u128_t *)(p + 0x10) = *(u128_t *)a0;
        *(int *)(p + 4) = a2;
        *(float *)(p + 0x1C) = h;
        *(unsigned char *)(p + 9) = 0xA4;
        if (a7 != -1)
            *(unsigned char *)(p + 3) = a7;
        else
            *(unsigned char *)(p + 3) = 0x48;
        *(unsigned char *)(p + 1) = 0;
        *(float *)(p + 0xC) = f;
        *(unsigned char *)(p + 8) = func_0019D510();
        if (a6 == -1)
            *(unsigned char *)(p + 2) = (*D_L39_00296984)[0];
        else
            *(unsigned char *)(p + 2) = (*D_L39_00296984)[a6];
        *(short *)(p + 0xA) = a4;
        q = p + 0x20;
        *(short *)(q + 0x18) = a4;
        *(float *)(q + 0x1C) = f;
        *(int *)(q + 0x10) = a2;
        *(int *)(q + 0x14) = a3;
        *(short *)(q + 0x1A) = a5;
        *(u128_t *)q = *(u128_t *)a1;
        *(float *)(q + 0xC) = g * 0.000400000019f;
    }
    return p;
}
/* localdecomp:end func_L39_005D1AB8 */
