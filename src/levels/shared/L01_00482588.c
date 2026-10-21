#include "common.h"

/* localdecomp:start func_L01_00482588 */
extern s32 func_L01_00482588(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E06E8;
extern s32 D_L01_001E06D0[2];
extern void func_003B77A0();
extern void func_003B7E38();
extern void func_003B7C88();
extern void func_003B7F08(void);
extern void func_003B7F30();
s32 func_L01_00482588(void) {
    if (D_L01_001E06E8 == 0) {
        func_003E6FA0(D_L01_001E06D0, (s32)func_003B77A0, (s32)func_003B7E38, (s32)func_003B7C88, (s32)func_003B7F08, (s32)func_003B7F30);
        D_L01_001E06E8 = 1;
    }
    return (s32)D_L01_001E06D0;
}
/* localdecomp:end func_L01_00482588 */
