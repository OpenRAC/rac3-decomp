/* US draft of func_0038E4C8 (rac3-uya-decomp func_0038E410, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_0038E4C8 */
/* func_0038E458 (filed as a linker remnant) is this function's jr delay slot and alignment nop. */
extern u8 D_00144440[];
extern u8 D_00143E40[];
extern u8 D_0014A840[];
extern u8 D_0014A240[];
extern void func_0038E1F8(s32, void *, void *);
void func_0038E4C8(void) {
    func_0038E1F8(0, D_00144440, D_00143E40);
    func_0038E1F8(1, D_0014A840, D_0014A240);
    func_0038E530(0);
}
/* localdecomp:end func_0038E4C8 */
