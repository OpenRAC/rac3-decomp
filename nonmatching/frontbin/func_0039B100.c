/* Near miss of func_0039B100 with its file's own flags: tools/check.py reports 3 diff
   (the version it replaces: 23).
   What differs: 3 diffs left, all from the order of the first three instructions: ours emits
   the array base's `lui $v0, 0x14` first (gcc hoists the %hi of the symbol D_00142430 to the
   top of the block), then `lui $a0, 0x1d` / `lw $a0, 0x4cec($a0)` (the D_001D4CEC load), then
   `addiu $a2, $v0, 0x2430`; retail has the load pair first (`lui $a0, 0x1d` / `lw $a0,
   0x4cec($a0)`) and the array base (`lui $v0, 0x14` / `addiu $a2, $v0, 0x2430`) after it. All
   remaining 22 instructions match byte for byte: registers ($a0 value, $v1 mask, $v0/$a2 array
   base, $at for the final store), the $gp stores (-0x7BC4/-0x7BC8),...
*/

/* func_0039B100: retail reads D_001D4CEC with a lui+lw pair and writes it through
   $gp; D_001D4CE8 likewise (one lui store plus two $gp stores).
   The $gp accesses need a sized declaration, the lui ones an unsized array
   (wiki: "Globals: gp vs lui", "Mixed access in one function"). The aliases
   live at the same addresses (config/frontbin/symbol_addrs_resolved.txt). */

/* localdecomp:start func_0039B100 */
extern s32 D_00142430_0039B100[];
extern s32 D_001D4CE8_g;
extern s32 D_001D4CEC_g;

void func_0039B100(void) {
    s32 *s;
    D_001D4CEC_g = *(s32 *)0x001D4CEC & ~0x20;
    s = D_00142430_0039B100;
    if (s[2] == 2) {
        if (s[5] == 0) {
            D_001D4CE8_g = 7;
            return;
        }
        if (s[4]) {
            s[4] = 0;
            D_001D4CE8_g = 0xB;
            return;
        }
        *(s32 *)0x001D4CE8 = 0xB;
    }
}
/* localdecomp:end func_0039B100 */
