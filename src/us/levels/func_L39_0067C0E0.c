#include "common.h"

/* localdecomp:start func_L39_0067C0E0 */
extern s32 func_00126150(void);
extern s32 func_001260F0(s32, s32);
extern void func_001916E0(void);
extern s32 D_001E19E0_sda;

void func_L39_0067C0E0(void) {
    D_001E19E0_sda = func_001260F0(func_00126150(), 0x3C);
    func_001916E0();
}
/* localdecomp:end func_L39_0067C0E0 */
