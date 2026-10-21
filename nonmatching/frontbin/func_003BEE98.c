/* US draft of func_003BEE98 (rac3-uya-decomp func_003B99A0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003BEE98 */
extern u8 D_001DA2D4[];
extern u8 D_001DA300[];
extern s32 D_001D9364[];
u8 func_003BDBF8(void);
s32 func_003BEE98(s32 a) {
    s32 r = 0;
    if ((D_001DA2D4[0] = func_003BDBF8()) != 0 && a) {
        r = D_001DA300[0] != 0;
    }
    D_001D9364[0] = 1;
    return r;
}
/* localdecomp:end func_003BEE98 */
