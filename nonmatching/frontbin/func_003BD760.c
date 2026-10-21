/* US draft of func_003BD760 (rac3-uya-decomp func_003B8280, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003BD760 */
extern u8 D_001DA2A0[];
extern s32 D_001DA2B0[];
extern f32 D_001DA2B4[];
extern f32 D_001DA2B8[];
extern void func_003BFEF0(void *, s32, f32, f32);
void func_003BD760(void) {
    func_003BFEF0(D_001DA2A0, D_001DA2B0[0], D_001DA2B4[0], D_001DA2B8[0]);
}
/* localdecomp:end func_003BD760 */
