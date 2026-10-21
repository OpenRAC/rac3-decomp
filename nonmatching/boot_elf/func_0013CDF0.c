/* Near miss of func_0013CDF0 with its file's own flags: tools/check.py reports 5 diff
   (the version it replaces: 37).
   What differs: 5 words still differ (down from 31 for the US draft). Everything else matches
   retail byte for byte: frame size, saved registers, the $gp accesses (D_001D4DAC -0x7b04,
   D_001D4DB8 -0x7af8), the value loads `lui $v0,0x1d / lw $v0,0x4980($v0)`, the constant 1 in
   $v1, every branch offset and the 47-word length. What is left: (1) `q = &D_1D49BF` must be
   the atomic pair `lui $s1,0x1d / addiu $s1,$s1,0x49bf`, but with an unsized-array alias gcc
   emits the split form `lui $v0,0x1d / addiu $s1,$v0,0x49bf` and interleaves the argument's
   `lui $a0,0x1d` between the two (3 words); (2) the loop's...
*/

/* PAL candidate for func_0013CDF0.
   Retail reaches D_1D4980 (0x1D4980) and D_1D49BF (0x1D49BF) with lui/%hi +
   %lo, never through $gp. The shared declaration in 13C8D0.c is sized (4/1
   bytes), so gcc would put them in small data and reach them through $gp.
   The aliases below are unsized arrays, which are never small data.
   Aliases (at the retail addresses):
     D_1D4980_0013CDF0_1 = 0x1D4980 (&D_1D4980, first call)
     D_1D49BF_0013CDF0   = 0x1D49BF (&D_1D49BF) */

/* localdecomp:start func_0013CDF0 */
extern s32 D_001D4DAC;
extern s32 D_001D4DB8;
extern s32 D_1D4980_0013CDF0_1[];
extern u8 D_1D49BF_0013CDF0[];
extern s32 func_0012B098();
extern void func_0011F7C8(void *, void *);
extern s32 func_0013B620(void);
s32 func_0013CDF0(s32 mode) {
    u8 *q;
    if (D_001D4DAC == 0) return func_0012B098(mode);
    q = &D_1D49BF_0013CDF0[0];
    func_0011F7C8(&D_1D4980_0013CDF0_1[0], q);
    D_001D4DB8 = *(s32 *)0x1D4980 == 0;
    if (D_001D4DB8 != 1) {
        if (mode == 1) return 1;
        while (D_001D4DB8 == 0) {
            func_0013B620();
            func_0011F7C8((void *)0x1D4980, q);
            D_001D4DB8 = *(s32 *)0x1D4980 == 0;
        }
    }
    return 0;
}
/* localdecomp:end func_0013CDF0 */
