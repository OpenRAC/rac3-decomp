/* func_L01_00514DD0: 3 diff (shared L01 pass draft at 6, then round 2's escalation of its sibling func_L01_00514D78,
   b9-nm1-a/-b). The same form as func_L01_00514D78's draft: the parameters reassigned in place and the address as an
   integer sum give retail's lw $a0,($a0), sll $a1,$a1,2 and index-first addu; what still differs is the entry, which
   retail loads into $v1 and copies to $a0 (move $a0,$v1) where this C loads it straight into $a0. The third parameter
   is passed through untouched (func_L01_0047EA90 calls it with three arguments and retail never sets $a2); the
   two-parameter form is also 3 diffs. Callee func_003EDAD0 sets or clears flag `mask` of the entry.
   Round 5 (nm/b12-n2): with an UNINITIALISED `void *p;` set only inside the bounds if and `if (p == 0) return 0;` after it, the
   entry lands in $v1 with retail's `beqz $v1; move $a0,$v1` and slot order (the same as D78's draft note), leaving only the first
   beqz, which gcc threads to the join test instead of retail's direct jump to move $v0,$zero: no plain C found with p live at
   entry and no join. */
#include "common.h"
/* localdecomp:start func_L01_00514DD0 */
extern void func_003EDAD0(void *p, s32 mask, s32 set);

s32 func_L01_00514DD0(u8 **o, u32 i, s32 set) {
    void *p;
    if (i < 0x23) {
        o = (u8 **)*o;
        i <<= 2;
        p = *(void **)(i + (u32)o + 0x50);
        if (p != 0) {
            func_003EDAD0(p, 1, set);
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_00514DD0 */
