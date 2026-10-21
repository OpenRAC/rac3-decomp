/* US draft of func_003BDCB0 (rac3-uya-decomp func_003B87B8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003BDCB0 */
extern s32 D_001D8CFC;
extern s32 D_001D8CF8;
extern s32 D_001DA268[];
extern s8 D_001DA290[];
void func_003BDCB0(s32 n, s32 *p, s32 v) {
    s32 i;
    for (i = 0; i < 10; i++) {
        if (i < n) D_001DA268[i] = p[i];
        else D_001DA268[i] = -1;
        D_001DA290[i] = 0;
        }
    D_001D8CFC = v;
    D_001D8CF8 = n;
}
/* localdecomp:end func_003BDCB0 */
