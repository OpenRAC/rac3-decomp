/* Near miss of func_003BBC00 with its file's own flags: tools/check.py reports 14 diff
   (the version it replaces: 35).
   What differs: globals now absolute (lui/addiu) like PAL retail and the rest of the body
   matches, but (1) gcc hoists the lui/addiu of D_001DA218 ahead of the `sll $a0,2` (retail
   keeps the shift first, so $v0/$v1 swap, `lw $s1,($v0)` becomes `lw $s1,($v1)`, the -1 lands
   in $v0 instead of $v1, and `lui $t2` lands between the lui/addiu pair); tried incomplete-
   array vs sized-array declarations, array vs pointer-cast access, all gave the same 14 diffs.
   (2) the 8th argument must be a 64-bit copy (retail `daddu $t3,$s0,$0`); this compiler cannot
   convert a pointer to 64-bit ("unsupported wide integer operation")...
*/

/* PAL candidate for func_003BBC00 (boot_elf).
   PAL differences from the US draft:
   - D_1DA1F0/D_1DA218/D_1DA240 are addressed absolutely (lui/addiu) in the
     PAL retail, so they are declared as incomplete arrays here (an array of
     known size 4 is gp-relative under -G8); D_001D8CE0 stays gp-relative.
   - the last argument of func_13C0B8 is a 64-bit value in the PAL retail
     (daddu $t3,$s0,$zero), and the callback func_003BBBF0 takes its pointer
     as a 64-bit value too (dsll32/dsra32). */

/* localdecomp:start func_003BBC00 */
__asm__(".extern D_001D8CE0_003BBC00, 4");
extern s32 D_001D8CE0_003BBC00;
extern s32 D_001DA1F0_003BBC00pal[];
extern s32 D_001DA218_003BBC00pal[];
extern s32 D_001DA240_003BBC00pal[];
extern void func_13CA20();
extern void func_13CA28();
extern void func_13B620_003BBC00();
extern void func_13C0B8pal(s32, s32, s32, s32, s32, s32, void *, void *);
extern void func_003BBBF0();

void func_003BBC00(s32 a) {
    s32 i;
    s32 *p;
    if (a >= 0 && a < D_001D8CE0_003BBC00) {
        i = D_001DA218_003BBC00pal[a] * 4;
        p = (s32 *)((u8 *)D_001DA240_003BBC00pal + i);
        *p = -1;
        func_13CA20();
        func_13C0B8pal(*(s32 *)((u8 *)D_001DA1F0_003BBC00pal + i), 0, 0x400, 0, 0, 0, func_003BBBF0, p);
        func_13CA28();
        func_13B620_003BBC00();
    }
}
/* localdecomp:end func_003BBC00 */
