#include "common.h"

/* localdecomp:start func_L01_004CD368 */
extern void func_003AB168();
extern u8 D_L01_001DB1F0_004CD368[];

void func_L01_004CD368(u8 *p) {
    *(void **)(p + 0x24) = D_L01_001DB1F0_004CD368;
    func_003AB168(p);
}
/* localdecomp:end func_L01_004CD368 */
