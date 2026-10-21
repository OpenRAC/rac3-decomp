/* US draft of func_003A90A0 (rac3-uya-decomp func_003A3B50, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003A90A0 */
extern s32 D_001DA05C;
extern s32 D_001DA048[];
extern s32 D_001DA058;
extern s32 D_001D5BA4;
extern s32 D_001D5BA8;
extern s32 D_001D9D30;
extern s32 D_001D9D34;
extern s32 D_001D9D38;
void func_003A90A0(void) {
    u32 t = (D_001DA048[D_001DA05C] + D_001DA058) & 0xFFFFE000;
    s32 a = t - D_001D5BA4;
    D_001D9D34 = t - D_001D5BA8;
    D_001D9D38 = a - 0x2000;
    D_001D9D30 = a;
}
/* localdecomp:end func_003A90A0 */
