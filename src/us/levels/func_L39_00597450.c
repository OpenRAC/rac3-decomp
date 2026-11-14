#include "common.h"

/* localdecomp:start func_L39_00597450 */
extern s32 func_0039BEA8(s32);
extern void func_00193F40(s32);
extern void func_0039CC78(void);
extern void func_00193680(void);
extern void func_L01_0045D318(s32);
extern s32 D_L39_0025F580[];

/* If func_0039BEA8(3) is zero, calls func_00193F40(0x4D), func_0039CC78 and func_00193680; then
 * calls func_L01_0045D318(0) and clears D_L39_0025F580[0]. */
void func_L39_00597450(void) {
    if (func_0039BEA8(3) == 0) {
        func_00193F40(0x4D);
        func_0039CC78();
        func_00193680();
    }
    func_L01_0045D318(0);
    D_L39_0025F580[0] = 0;
}
/* localdecomp:end func_L39_00597450 */
