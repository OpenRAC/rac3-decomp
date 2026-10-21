/* US draft of func_003935B0 (rac3-uya-decomp func_0038ED78, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003935B0 */
void func_003935B0(s32 id, s32 v) {
    s32 i;
    for (i = 0; i < 13; i++) {
        if (D_00331AE0[i].id == id) break;
    }
    if (i < 13) {
        D_00331AE0[i].f24 = v;
        if (!D_00331AE0[i].f68) D_00331AE0[i].f4 = v;
    }
}
/* localdecomp:end func_003935B0 */
