/* US draft of func_003B4A10 (rac3-uya-decomp func_003B4860, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003B4A10 */
extern u8 D_001D88D8[];
void **func_003B4A10(void **p) { p[0] = (void *)1; p[1] = D_001D88D8; p[2] = 0; p[3] = 0; p[4] = 0; return p; }
/* localdecomp:end func_003B4A10 */
