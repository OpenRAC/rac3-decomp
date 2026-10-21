/* US draft of func_003C0C40 (rac3-uya-decomp func_003BB730, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003C0C40 */
extern s32 D_001D4BC0;
extern u8 D_002D1FC0_003C0C40[];
extern void func_00389240();
extern void func_00390F50(s32, s32, unsigned long, u8 *, s32, f32);
extern void func_00389370();
void func_003C0C40(void) {
    func_00389240(1);
    func_00390F50(D_001D4BC0 >> 1, 0xA0, 0x80FFFFFF, D_002D1FC0_003C0C40, -1, 1.2f);
    func_00389370();
}
/* localdecomp:end func_003C0C40 */
