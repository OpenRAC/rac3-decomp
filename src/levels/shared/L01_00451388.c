#include "common.h"

/* localdecomp:start func_L01_00451388 */
extern void func_003C5278_00451388(void *);
 
void func_L01_00451388(void *p) {
    func_003C5278_00451388((u8 *)p + 0x10);
}
/* localdecomp:end func_L01_00451388 */

INCLUDE_ASM("asm/levels", func_L01_004513A8);

LINKER_REMNANT("asm/levels", func_L01_00451578);

/* localdecomp:start func_L01_00451580 */
extern s32 D_L01_001D6740[];
extern u8 D_L01_001DFC50[];
extern u8 D_L01_001D6750[];
extern f32 func_0038CF00(void *, void *);
f32 func_L01_00451580(void *a0) {
    if (D_L01_001D6740[0] != 0) {
        return 100.0f - func_0038CF00(a0, D_L01_001D6750);
    }
    return func_0038CF00(a0, D_L01_001DFC50);
}
/* localdecomp:end func_L01_00451580 */

/* localdecomp:start func_L01_004515D8 */
extern void func_0038CE20(f32 *, void *, f32);

extern void func_003C5370(s32, f32 *, s32);
void func_L01_004515D8(s32 a, s32 b, s32 c) {
    f32 buf[4];
    ((void (*)(f32 *, f32))func_0038CE20)(buf, -1.0f);
    func_003C5370(a, buf, c);
}
/* localdecomp:end func_L01_004515D8 */
