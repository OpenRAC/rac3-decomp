/* Near miss of func_00393290 with its file's own flags: tools/check.py reports 4 diff
   (the US draft it started from: 7).
   What differs: 4 diffs left, all from one register-allocation difference: the value loaded
   from D_00227600[0] lands in $v0 (coalesced with the %hi part of D_00227600's address)
   instead of retail's $a0. That also flips the addu operand order (ours `addu $v1, $v1, $v0`
   vs retail `addu $v1, $a0, $v1`) and the placement of the constant's `lui $v1, 6` (retail
   emits it before the load). Everything else matches retail byte for byte: the 44-byte length,
   `lui $v0, 0x22` / `lw ..., 0x7600($v0)`, `lui $v1, 6` / `ori $v1, $v1, 0x4000`, and both
   globals written as `lui $at, %hi(D_...)` + `sw ..., %lo(D_...)($at)`,...
*/

/* PAL retail match attempt for func_00393290 (4 diffs left, see work/RESULTS.md).

   Retail reaches D_001D9E98/D_001D9E9C with lui %hi / sw %lo, not $gp: the two
   symbols are 16 bytes each, so gcc must not treat them as small data.  An
   unsized array is never small data, so it always gets lui (docs/wiki/
   Matching-Patterns.md, "Globals: gp vs lui"), which needs a per-function
   alias name because the file declares the plain names as sized scalars
   (`extern s32 D_001D9E98;`), and those declarations are what the checker's
   context puts in front of this file.

   Everything else matches retail: 44 bytes, lui/addiu of the 0x64000 constant,
   lui $at + sw %lo($at) for both globals, jr $ra + nop. */

extern s32 D_00227600[];
extern s32 D_001D9E98_00393290[];
extern s32 D_001D9E9C_00393290[];
void func_00393290(void) {
    s32 a = D_00227600[0];
    D_001D9E98_00393290[0] = a;
    D_001D9E9C_00393290[0] = a + 0x64000;
}
