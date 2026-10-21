/* Near miss of func_00393990 with its file's own flags: tools/check.py reports 16 diff
   (the version it replaces: 28).
   What differs: 14 diffs left: the loop now matches (pointer walk, base+0x64, i in $a2) and
   the tail uses one element pointer, but (1) retail materialises D_00331AE0 in split hi/lo
   form - `lui $v0,0x33; move $a3,$v0; addiu $v0,$v0,0x1ae0` and rebuilds it in the tail with
   `addiu $a3,$a3,0x1ae0` - while the candidate copies the whole address (`move $a3,$v0`) and
   reuses it, so the reload keeps the full address instead of the hi part; (2) the retail tail
   is 6 instructions (`mult $a2,$a2,$v0` overwriting the index, `addu $v1,$a3,$a2`, `sw
   $a1,0x24($v1)`, `move $a0,$v1`, `lw $v0,0x68($a0)`, `bnez`, `move...
*/

/* PAL candidate for func_00393990 (retail boot_elf).
   The array is walked through a pointer and the element is taken through one
   pointer, so the compiler keeps D_00331AE0's address in a register (and adds
   the field offsets to the element pointer) instead of folding every field
   address into its own constant. */

/* localdecomp:start func_00393990 */
void func_00393990(s32 id, s32 v) {
    s32 i;
    S_38ED78 *p = D_00331AE0;
    for (i = 0; i < 13; i++) {
        if (p[i].id == id) break;
    }
    if (i < 13) {
        S_38ED78 *q = &D_00331AE0[i];
        q->f24 = v;
        if (!q->f68) q->f4 = v;
    }
}
/* localdecomp:end func_00393990 */
