/* func_L01_00514D78: 4 diff (round 2: b9-t5 draft, then two escalation workers, b9-nm1-a/-b, about 90 wordings).
   Reassigning the parameters in place (o = *o; i <<= 2) gives retail's lw $a0,($a0) and sll $a1,$a1,2, and the
   address written as an integer sum gives its index-first addu $v0,$a1,$a0 (pointer sums always come out base first).
   What still differs: retail loads the entry into $v1 and copies it to $a0 in the jal delay slot (move $a0,$v1); this C
   loads it straight into $a0, so the branch and both delay slots differ. Only an entry whose live range starts before
   the bounds compare (void *p = 0; before the if) gets $v1 and the move, at the cost of a join retail does not have
   (21 diffs). Inline helpers (accessor, call wrapper, call-if), copies of the entry, other types and callee declarations,
   --mode N, --as ps2as and --as newas all stay at 4 to 7. Callee func_003EDAF8 tests flag `mask` of the entry.
   Round 5 (nm/b12-n2): an UNINITIALISED `void *p;` (assigned only inside the bounds if, `if (p == 0) return 0;` after it)
   gives retail's allocation exactly (lw $v1,0x50($v0); beqz $v1; move $a0,$v1; 3 diffs) because p is then live from the
   entry; but gcc threads the first beqz to that join test (reading garbage), where retail's goes straight to move $v0,$zero,
   so it is no match. Also tried: once-while, result variable, goto, ternary and else-zero forms (10), the file's other flag
   sets (-fopt-stack removed: 10, -mno-split-addresses: 4). */
#include "common.h"
/* localdecomp:start func_L01_00514D78 */
extern s32 func_003EDAF8(void *p, s32 mask);

s32 func_L01_00514D78(u8 **o, u32 i, u8 *out) {
    void *p;
    if (i < 0x23) {
        o = (u8 **)*o;
        i <<= 2;
        p = *(void **)(i + (u32)o + 0x50);
        if (p != 0) {
            *out = func_003EDAF8(p, 1);
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_00514D78 */
