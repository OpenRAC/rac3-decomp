/* US draft of func_00382918 (rac3-uya-decomp func_00382938, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00382918 */
extern s32 func_0013D3E0(void);
f32 func_00382918(void) {
    return (f32)(func_0013D3E0() - 0x4000) * 3.1415927f * (1.0f / 16384.0f);
}
/* localdecomp:end func_00382918 */
