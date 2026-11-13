#include "common.h"

/* localdecomp:start func_L39_0060B428 */
extern void func_003861F0(void);
extern void func_L39_00587E80(void);
extern void func_L39_0060B478(void);
extern void func_L01_00415728(void);
extern s32 D_L39_0024BB58;
extern void (*D_L39_00245820)(void);
void func_L39_0060B428(void) {
    func_003861F0();
    func_L39_00587E80();
    D_L39_0024BB58 = -1;
    if (D_L39_00245820 != 0) {
        D_L39_00245820();
    }
    func_L39_0060B478();
    func_L01_00415728();
}
/* localdecomp:end func_L39_0060B428 */
