/* US draft of func_003ABBE8 (rac3-uya-decomp func_003ABA48, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003ABBE8 */
extern void func_003AB520();
extern void func_003AC300();
extern s32 D_001D81E8_003AB520;

void func_003ABBE8(void *arg0, s32 arg1) {
    s32 temp_a0;

    (*(s32 **)((u8 *)(arg0) + 0x24)) = &D_001D81E8_003AB520;
    temp_a0 = (*(s32 *)((u8 *)(arg0) + 0x20));
    if ((temp_a0 != 0) && ((*(u8 *)((u8 *)(arg0) + 0x2C)) == 0)) {
        func_003AC300(temp_a0, (*(s32 *)((u8 *)(arg0) + 0x28)));
    }
    func_003AB520(arg0, arg1);
}
/* localdecomp:end func_003ABBE8 */
