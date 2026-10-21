/* US draft of func_0039BC10 (rac3-uya-decomp func_00396E20, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0039BC10 */
extern s32 D_00142438[];
extern u32 D_001D4CEC_0039BC10;
extern s32 D_001D4CE8_0039BC10;
extern void func_0039C028(void);
void func_0039BC10(void) {
    s32 v;
    if (D_00142438[0] != 2) {
        v = 4;
    } else {
        u32 f = D_001D4CEC_0039BC10;
        if (f & 0x20) {
            func_0039C028();
            v = 0x12;
        } else if (f & 0x2000) {
            v = 0x1D;
        } else {
            return;
        }
    }
    D_001D4CE8_0039BC10 = v;
}
/* localdecomp:end func_0039BC10 */
