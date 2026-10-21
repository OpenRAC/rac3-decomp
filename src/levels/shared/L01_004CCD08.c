#include "common.h"

/* localdecomp:start func_L01_004CCD08 */
extern u8 *func_003AB020(u8 *);

extern u8 D_L01_001DB1D8[];
u8 *func_L01_004CCD08(u8 *p) {
    func_003AB020(p);
    *(u8 **)(p + 0x24) = D_L01_001DB1D8;
    return p;
}
/* localdecomp:end func_L01_004CCD08 */
