/* US draft of func_00387218 (rac3-uya-decomp func_00382F40, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00387218 */
extern s32 func_00386730();
extern void func_0038CB78();
extern s32 D_001D9D54;
extern s32 D_00227480[];

void func_00387218(void) {
    if (D_001D9D54 == 0) {
        func_0038CB78(D_00227480, -1, 0x80);
    } else if (D_001D9D54 == 2) {
        func_00386730();
    }
}
/* localdecomp:end func_00387218 */
