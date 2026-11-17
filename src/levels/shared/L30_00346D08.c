#include "common.h"

/* localdecomp:start func_L30_00346D08 */
extern s32 D_L30_001DCF4C;
extern s32 D_L30_001DCF44;
extern f32 D_L30_001DCF40;
extern u8 D_L30_001E11A8[];

extern int func_L01_004561B8(u8 *);
extern void func_L01_004AAC98(int, int, u8 *, int);
extern void func_L30_0034CB68(u8 *, void *, int, int, int, int, f32, f32);
extern void func_L30_0034C8A8(void *, u8 *);
extern int func_0038CAD0(void *);
extern void func_003C2880(u8 *);

void func_L30_00346D08(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 104);
    if (func_L01_004561B8(moby)) {
        *(s32 *)(vars + 164) = D_L30_001DCF4C;
        func_L01_004AAC98(29, 0, moby, 4963);
    }
    func_L30_0034CB68(moby, vars + 144, 0, -1, 0, 0, (f32)D_L30_001DCF44, D_L30_001DCF40);
    func_L30_0034C8A8(D_L30_001E11A8, moby);
    if (func_0038CAD0(vars + 164)) {
        func_003C2880(moby);
    }
}
/* localdecomp:end func_L30_00346D08 */

INCLUDE_ASM("asm/levels", func_L30_00346DA8);
