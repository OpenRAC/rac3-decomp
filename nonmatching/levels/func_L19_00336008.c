/* PAL near miss (Claude wave S/pal): near miss: 6 words differ with "@ps2as and -mvu0-use-vf0-vf2 needed (vec_add_ba, 1.0f lui/mtc1), neither is on the L19_003357A0.c line" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 * Worker's note: 6 diff (best, near/ file, with both flags added): only the function start differs: retail does `lui v1; addiu v1; addiu sp; lq v0,0(v1); sd ra; beqz a1; sq v0,0(a0)` (address in $v1, value $v0), mine `addiu sp; lui v0; sd ra; addiu v0; lq v1,0(v0); beqz; sq ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L19_00336008 */
typedef int Quad_00336008 __attribute__((mode(TI)));

extern Quad_00336008 D_L19_001D66F0;
extern void func_0038CE20(void *, void *, f32);

void func_L19_00336008(u8 *out, u8 *arr, s32 n) {
    f32 cnt;

    *(Quad_00336008 *)out = D_L19_001D66F0;
    if (arr == 0) {
        return;
    }
    if (n == 0) {
        return;
    }
    cnt = (f32)n;
    arr += 0x10;
    if (n > 0) {
        do {
            vec_add_ba(out, out, arr);
            arr += 0x10;
            n--;
        } while (n != 0);
    }
    func_0038CE20(out, out, 1.0f / cnt);
}
/* localdecomp:end func_L19_00336008 */
