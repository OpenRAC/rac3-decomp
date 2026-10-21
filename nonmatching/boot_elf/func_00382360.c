/* US draft of func_00382360 (rac3-uya-decomp func_00382380, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00382360 */
extern void *D_001D99A0;
typedef struct { u8 pad0[0x2C]; s32 f2C; } S_00318CC0_0037DF28;
extern S_00318CC0_0037DF28 D_0031CC80[];

s32 func_00382360(s32 arg0) {
    s32 var_a1;
    s32 var_a2;

    var_a2 = -1;
    var_a1 = 0;
    if (D_0031CC80->f2C > 0) {
        if ((*(s32 *)((u8 *)(D_001D99A0) + 4)) == arg0) {
            var_a2 = 0;
        } else {
loop_4:
            var_a1 += 1;
            if (var_a1 < D_0031CC80->f2C) {
                if ((*(s32 *)((u8 *)(((var_a1 * 0x10) + D_001D99A0)) + 4)) == arg0) {
                    var_a2 = var_a1;
                } else {
                    goto loop_4;
                }
            }
        }
    }
    return var_a2;
}
/* localdecomp:end func_00382360 */
