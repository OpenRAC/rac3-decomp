/* Near miss of func_003881B0 with its file's own flags: tools/check.py reports 2 diff
   (the version it replaces: 4).
   What differs: Only the middle word of each 64-bit constant differs: ours `dsll $a1,$a1,0x10`
   vs retail `dsll $a1,$a1,0x18` (shift 16 vs 24); the surrounding `ori $a1,$zero,0x8000` and
   `ori $a1,$a1,0x44` now match.
*/

/* US draft of func_003881B0 (rac3-uya-decomp func_00383B08, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003881B0 */
extern void func_00392440(s32, s32, s32, s32);
extern void func_003A9440(s32, unsigned long);
extern void func_00392868(s32, s32);
void func_003881B0(s32 a0, s32 a1) {
    s32 n = a0 + a1;
    if (n > 16) {
        n = 16;
    }
    func_00392440(a0, a1, ((0x3FF000 - (4 << n)) >> 13) << 13, 1);
    func_003A9440(0x47, 0x30000);
    func_003A9440(0x42, 0x80000044UL);
    func_00392868(0x100, 0x100);
    func_003A9440(0x42, 0x80000044UL);
}
/* localdecomp:end func_003881B0 */
