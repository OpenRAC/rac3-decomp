/* r04 wave 12 retry of func_00393168 (21 diff with the file's flags; the draft: 25). Changed against the draft: no n4
   variable (gcse kept the prologue's n * 4 in $s1 across the call; retail recomputes it), the call is the file's
   void func_00392FD0(s32, s32) with the incoming a1 passed through (retail never touches $a1), one alias for
   D_001D9EA0. Still differs: the a2 copy and the constant 1 swap $s6/$s7; D_001A1F08 is a literal address in retail
   (lui $v0 / lw $s4, 0x1F08($v0)), an extern gives lui $s4 / lw $s4 under -mno-split-addresses; retail computes
   n * 4 for end before the n != 0 branch (delay slot) and copies the ternary's value from $v0 to $s3. */
#include "common.h"

/* localdecomp:start func_00393168 */
extern S_38E930 *D_001D9EA0_00393168x[];
extern E_38E930 *D_001D9EAC_00393168x[];
extern s32 D_001A1F08_00393168x[];

void func_00393168(s32 n, s32 size, s32 a2) {
    S_38E930 *p;
    s32 i, end, pos;
    s32 b6, b7, sz;

    if (D_001D9EA0_00393168x[0]->c[n] == 0) {
        func_00392FD0(0, size);
    }
    pos = D_001A1F08_00393168x[0];
    p = D_001D9EA0_00393168x[0];
    i = (n != 0) ? p->b[n - 1] : 0;
    end = *(s32 *)((u8 *)p + n * 4 + 0x34);
    for (; i < end; i++) {
        s32 s = pos >> 8;
        b6 = D_001D9EAC_00393168x[0][i].b6;
        b7 = D_001D9EAC_00393168x[0][i].b7;
        sz = 1 << (b6 + b7);
        func_00397980(D_001D9EAC_00393168x[0][i].w0, s, 0x1B, b6, b7, a2);
        D_001D9EAC_00393168x[0][i].h4 = s;
        pos += sz << 2;
        D_001D5D50 = pos;
    }
}
/* localdecomp:end func_00393168 */
