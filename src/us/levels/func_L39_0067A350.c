#include "common.h"

/* localdecomp:start func_L39_0067A350 */
extern void func_001954A8(void *);
extern void func_001954C0(void *);
extern u8 D_L39_0067A008[];

/* Calls func_001954A8 and then func_001954C0 on D_L39_0067A008. */
void func_L39_0067A350(void) {
    func_001954A8(D_L39_0067A008);
    func_001954C0(D_L39_0067A008);
}
/* localdecomp:end func_L39_0067A350 */
