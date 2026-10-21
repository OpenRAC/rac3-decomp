/* Near miss of func_00389EA0 with its file's own flags: tools/check.py reports 7 diff
   (the version it replaces: 24).
   What differs: Best (check 3) is 7 diffs: everything matches except the prologue order.
   Retail loads the counter first (`lui $v0, 0x1e` + `lw $v0, -0x63ec($v0)` before the callee-
   saved stores, with `move $s0, $zero` between `sd $s1` and `sd $s2` and `sd $ra` in the blez
   delay slot); gcc schedules the same load after the four `sd` stores, with `move $s0, $zero`
   in the blez delay slot. Loop body, re-read of the counter in the loop, `slt`/`bnel` offsets
   (-0x20) and the epilogue match byte for byte. The addressing problem is solved: retail
   reaches D_001D9C14 with `lui`/`%lo` (not `$gp`), so the counter must...
*/

/* PAL candidate for func_00389EA0 (frontbin).
 *
 * Started from the US draft (rac3-uya-decomp func_003857C8, commit 13cf5c5). The US
 * matched it only with @ps2as; here the file's own flags must produce the retail bytes.
 *
 * The counter is read through a literal address: retail reaches it with `lui`/`%lo`
 * (it is not small data, so a sized `extern s32` would give gcc's `$gp` form), and a
 * constant address is rematerialised at each read (`lui $v0, %hi(addr)` + `lw $v0,
 * %lo(addr)($v0)`), which is exactly retail's shape.  Reading it through a declared
 * symbol instead (unsized array, `extern s32 D_001D9C14[];` + `D_001D9C14[0]`) gives
 * gcc a computed address it hoists into a callee-saved register ($s3), which is not
 * retail's shape.
 */

/* localdecomp:start func_00389EA0 */
extern void (*D_00226E00[])(s32);
extern s32 D_00226F00[];
void func_00389EA0(void) {
    s32 i;
    for (i = 0; i < *(s32 *)0x001D9C14; i++) D_00226E00[i](D_00226F00[i]);
}
/* localdecomp:end func_00389EA0 */
