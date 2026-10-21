/* US draft of func_00389F18 (rac3-uya-decomp func_00385840, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00389F18 */
extern s32 D_001D9C0C_00389F18;
extern s32 D_00226B00[];
extern s32 D_00226A00_00389F18[];
void func_00389F18(s32 a, s32 b) {
    s32 n = D_001D9C0C_00389F18;
    if (n < 0x40) {
        D_00226A00_00389F18[n] = a;
        D_00226B00[n] = b;
        D_001D9C0C_00389F18 = n + 1;
    }
}
/* localdecomp:end func_00389F18 */
