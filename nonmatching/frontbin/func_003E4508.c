/* US draft of func_003E4508 (rac3-uya-decomp func_003DEFB8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003E4508 */
extern u8 D_00142CC0[];
extern u8 D_001426E0[];
extern s32 func_003E81F0(s32, f32, f32);
void func_003E4508(void) {
    if (D_00142CC0[0]) {
        u8 *s = D_001426E0;
        f32 r = 0.0f;
        if (s[0xD4]) r = (f32)s[0xD3] / (f32)s[0xD4];
        func_003E81F0(0x90008, r * 0.0430830009f, 0.0504160002f);
    }
}
/* localdecomp:end func_003E4508 */
