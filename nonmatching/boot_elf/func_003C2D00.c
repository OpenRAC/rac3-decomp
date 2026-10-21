/* Near miss of func_003C2D00 with its file's own flags: tools/check.py reports 6 diff
   (the version it replaces: 20).
   What differs: Addressing now matches retail exactly (the four lui/%hi+%lo globals get
   `__asm__(".extern D_001DA4CC/BC/C8/C0, 16")` size hints so the assembler does not use $gp;
   D_001DA4C4 stays $gp in the delay slot). Only register allocation differs: gcc puts `start`
   in $v0 and `end` in $v1, retail has `start` in $v1 and `end` in $v0 (move $v0,$a1 / addu
   $v1,$v0,$a2 / move $a0,$v0 / sw $v1 vs retail move $v1,$a1 / addu $v0,$v1,$a2 / move $a0,$v1
   / sw $v0). Tried: calling func_0038CF58 through an `s32` cast (7 diffs, changed scheduling
   only), and the plain draft body without the register pins (6 diffs,...
*/

/* PAL candidate for func_003C2D00.
 *
 * Retail reaches D_001DA4CC, D_001DA4BC, D_001DA4C8 and D_001DA4C0 through
 * lui/%hi + %lo (they are not small data there), while D_001DA4C4 is written
 * through $gp in the call's delay slot.  With the file's own flags (no
 * @ps2as) the assembler only drops a $gp reference to a symbol it knows is
 * bigger than 8 bytes, so the four big ones get a size hint.
 */

/* localdecomp:start func_003C2D00 */
extern int D_001DA4CC;
extern int D_001DA4BC;
extern int D_001DA4C8;
extern int D_001DA4C0;
extern int D_001DA4C4;
/* Ps2EeAs only uses $gp for these if it knows they are small before the use. */
__asm__(".extern D_001DA4CC, 16");
__asm__(".extern D_001DA4BC, 16");
__asm__(".extern D_001DA4C8, 16");
__asm__(".extern D_001DA4C0, 16");
__asm__(".extern D_001DA4C4, 4");
extern void func_0038CF58(void *, int, int);

unsigned int func_003C2D00(int count, int base) {
    int size;
    int start = base;
    int end;
    size = count * 4;
    end = start + size;

    D_001DA4CC = end;
    D_001DA4BC = start;
    D_001DA4C8 = start;
    D_001DA4C0 = 0;
    D_001DA4C4 = 0;
    func_0038CF58((void *)start, 0, size);
    return (D_001DA4CC + 0x3F) & 0xFFFFFFC0;
}
/* localdecomp:end func_003C2D00 */
