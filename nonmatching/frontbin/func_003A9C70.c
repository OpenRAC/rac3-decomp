/* Near miss of func_003A9C70 with its file's own flags: tools/check.py reports 8 diff
   (the US draft it started from: 11).
   What differs: The cursor global is now reached with lui/lw (an unsized-array alias, since
   retail's D_001DA050 is not small data) and the function is the right 13 words, with the
   copy, the in-place +0x10 bump and all four struct stores byte-identical to retail. What
   still differs (8 words, the first eight): retail materialises the read address in the load's
   own destination (`lui $v0, %hi(D); lw $v0, %lo(D)($v0)`) and the write address in the
   assembler scratch (`lui $at, %hi(D); sw $v0, %lo(D)($at)`), while gcc hoists both split
   addresses to the top of the block into general registers (`lui $a1, 0x1e; lui...
*/

/* PAL candidate for func_003A9C70 (US draft: rac3-uya-decomp func_003A4720).
   Retail reaches the cursor at 0x001DA050 with lui/lw, so it is not small data:
   an unsized array is never small data, so the aliases below get a split
   address (lui %hi / lw %lo). Retail materialises the address twice (lui $v0
   for the read, lui $at for the write), so the read and the write use one
   alias each; the u32 temporary keeps the post-increment shape (copy the old
   cursor to p, bump the cursor in place, store it back). */

typedef struct { u32 a, b, c, d; } S_3A4720;
extern u32 D_001DA050_003A9C70_a[];   /* the cursor, read */
extern u32 D_001DA050_003A9C70_b[];   /* the cursor, written */
void func_003A9C70(u32 x) {
    u32 v = D_001DA050_003A9C70_a[0];
    S_3A4720 *p = (S_3A4720 *)v;
    v += 0x10;
    D_001DA050_003A9C70_b[0] = v;
    p->a = x + 0x90000000;
    p->b = 0; p->c = 0; p->d = 0;
}
