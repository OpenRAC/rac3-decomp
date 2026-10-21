/* Near miss of func_0039B088 with its file's own flags: tools/check.py reports 5 diff
   (the US draft it started from: 8).
   What differs: Instruction shapes, immediates, branch target and delay-slot constant are all
   correct (was 8 diff, now 5). What remains is only which register holds each address's high
   half: gcc CSEs the shared `%hi` (both globals are 0x1D____) into one `$v1`, giving `lui $v1
   / lbu $v0, 0x4cec($v1)` and `lui $v1 / sw $v0, 0x4ce8($v1)`. Retail reuses the destination
   for the load (`lui $v0 / lbu $v0, 0x4cec($v0)`) and uses `$at` as scratch for the store
   (`lui $at / sw $v0, 0x4ce8($at)`), i.e. two independent address materializations with
   different register conventions. Those are `-mno-split-addresses` +...
*/

/* localdecomp:start func_0039B088 */
/* Retail reaches both globals with split (lui + load/store) forms rather than
   $gp-relative, so both are declared unsized: an unsized array is never small
   data. The names embed the address (D_001D4CEC / D_001D4CE8) so no
   symbol_addrs entry is needed for the aliases. */
extern u8 D_001D4CEC_b088[];
extern s32 D_001D4CE8_b088[];
void func_0039B088(void) {
    if ((D_001D4CEC_b088[0] ^ 1) & 1) {
        D_001D4CE8_b088[0] = 4;
    }
}
/* localdecomp:end func_0039B088 */
