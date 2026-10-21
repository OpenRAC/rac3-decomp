#include "common.h"

/* localdecomp:start func_L01_00517688 */
extern void func_L01_00517688(void);
extern void *func_003E6C08();

extern void func_L01_00515DE0(void *);
extern u8 D_L01_001E15E0[];
 
void func_L01_00517688(void) {
    void *x = D_L01_001E15E0;
    if (*(s32 *)((u8 *)x + 0x4) == 0) {
        x = func_003E6C08();
    }
    func_L01_00515DE0(x);
}
/* localdecomp:end func_L01_00517688 */

LINKER_REMNANT("asm/levels", func_L01_005176C0);
