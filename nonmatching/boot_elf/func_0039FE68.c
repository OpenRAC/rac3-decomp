/* Near miss of func_0039FE68 with its file's own flags: tools/check.py reports 7 diff
   (the version it replaces: 18).
   What differs: 7 diffs left, all in the final block: retail materialises D_00143140's address
   as an adjacent pair (`lui $v1,0x14` + `addiu $v1,$v1,0x3140`) and then `sll $a0,$a0,2` +
   `addu $a0,$a0,$v1`, with the loaded element in $v0; eegcc emits gcc's split form (`lui
   $v0,0x14` + `sll $a0,$a0,2` + `addiu $v0,$v0,0x3140` + `addu $a0,$a0,$v0`) and puts the
   element in $v1. Everything before that now matches: the $gp delay-slot reads of D_001D545C
   and the lui/lw re-read after the call (retail was built with SN's Ps2EeAs, which rewrites a
   two-instruction lui access inside a branch delay slot into a $gp...
*/

/* Candidate for func_0039FE68 (boot_elf, PAL).
   Retail reads D_001D545C through $gp in the two branch delay slots (the
   func_0039FD58 argument and the index loaded in the bne delay slot) and
   through lui/lw after the call, so the delay-slot reads use the sized
   declaration and the re-read after the call uses a constant address. */

/* localdecomp:start func_0039FE68 */
void func_0039FE68(void *arg0) {
    S_39AAF0 *p = &D_0022CF80_0039FE68;
    s32 r;
    s32 idx;
    if (p->f10 != 0) {
        if (p->f28 == 0) {
            func_0038CF58(arg0, 0, 0x800);
            return;
        }
        func_0039FD58(D_001D545C);
        r = func_0038E100(arg0, 0x800, p->f14, p->fC);
        idx = D_001D545C;
        if (r == -1) {
            func_0039FF28(arg0);
            idx = *(s32 *)0x001D545C;
        }
        if (D_00143140[idx] < r) D_00143140[idx] = r;
    }
}
/* localdecomp:end func_0039FE68 */
