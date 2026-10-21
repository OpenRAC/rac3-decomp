/* US draft of func_003BB530 (rac3-uya-decomp func_003B6050, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003BB530 */
extern s32 D_001DA1B0_003BB530[];
extern s32 D_001DA1B4_003BB530[];
s32 func_003BB530(s32 arg0) {
    s32 i = 0;
    s32 c1 = 0x4F000;
    s32 *q = D_001DA1B4_003BB530;
    s32 *p = D_001DA1B0_003BB530;
    do {
        i++;
        if (p[0] == arg0) return (q[0] & 1) ? c1 : 0x12C00;
        q += 2;
        p += 2;
    } while (i < 7);
    return -1;
}
/* localdecomp:end func_003BB530 */
