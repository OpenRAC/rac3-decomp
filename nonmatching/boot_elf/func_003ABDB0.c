/* Near miss of func_003ABDB0 with its file's own flags: tools/check.py reports 1 diff
   (the US draft it started from: 7).
   What differs: Only one word still differs: gcc builds the 32-bit constant 0x3357E0 as `lui
   $v0, 0x33 ; ori $v0, $v0, 0x57e0`, retail has `lui $v0, %hi(D_003357E0) ; addiu $v0, $v0,
   %lo(D_003357E0)`. With this file's own flags (-mno-split-addresses) gcc materialises the
   address of a global as ONE assembler macro (`la`), so the %hi/%lo halves always come out
   adjacent (7 diffs, the draft) and cannot be spread apart; the split form only appears for
   indexed uses (retail func_00393990) or call arguments (retail func_003AACF8), both of which
   need extra instructions here. Writing the address as a plain constant...
*/

/* US draft of func_003ABDB0 (rac3-uya-decomp func_003ABC10, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `-mno-split-addresses` (a single-function override).

   Attempt notes: with this file's flags (-mno-split-addresses) gcc materialises the address of
   D_003357E0 as ONE assembler macro ("la"), so the pair comes out adjacent:
       lui $v0, 0x33 ; addiu $v0, $v0, 0x57e0
   while retail (built in split-address mode) has the two halves as separate instructions with
   the %hi hoisted to the top of the block:
       lui $v0, %hi(D_003357E0) ; ... ; addiu $v0, $v0, %lo(D_003357E0)
   Writing the address as a plain constant gets the retail schedule exactly (the constant is
   built as two separate instructions), but gcc then uses "ori" for the low half instead of
   "addiu" (this compiler always uses ori for 32-bit constants, 1247 to 0 in the retail asm),
   so one word still differs. */

/* localdecomp:start func_003ABDB0 */
extern s32 D_003357E0[];
extern void func_003AB3F0();
typedef struct { u8 pad[4]; f32 *v; u8 p2[0x28-8]; void *p28; u8 p3[4]; long l30; s32 w38; s32 w3C; } S_3A6450;
void func_003ABDB0(S_3A6450 *p) {
    func_003AB3F0(p);
    p->p28 = (void *)0x3357E0;
    p->l30 = 1;
    p->w38 = 0;
    p->v[0] = 1.0f;
    p->v[1] = 1.0f;
    p->w3C = 1;
}
/* localdecomp:end func_003ABDB0 */
