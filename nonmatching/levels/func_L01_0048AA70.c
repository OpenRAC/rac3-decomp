/* PAL near miss (b8-s3): 2 words differ: retail builds the address of D_001D545C with `lui $v1` and loads into the same
 * register (`lui $v1, hi; lw $v1, lo($v1)`), here `lui $v0` / `lw $v1, lo($v0)`. Everything else matches. Tried:
 * a local copy of the value, early return, test order, .data/.sdata sections, unsized/sized declarations.
 * The declarations of func_L01_0047EBE0 and func_L01_00517748 come from earlier blocks of L01_004838A0.c.
 */
#include "common.h"
/* localdecomp:start func_L01_0048AA70 */
extern s32 D_001D545C[];
extern void func_003BB0E8(s32);
extern void func_003A5348(s32, s32, s32);
extern void func_L01_00516090_0048AA70(s32);

void func_L01_0048AA70(s32 a0, s32 a1) {
    if (a1 >= 2 && a1 != D_001D545C[0] && (a1 != 3 || D_001D545C[0] != 6)) {
        func_003BB0E8(a1);
        func_003A5348(0x14, 0, 0);
        func_L01_00517748(func_L01_0047EBE0());
        func_L01_00516090_0048AA70(a0);
    }
}
