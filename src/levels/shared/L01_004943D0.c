#include "common.h"

/* localdecomp:start func_L01_004943D0 */
typedef struct {
    char _p0[0xC];
    s32 fC;
    s32 f10;
} S_004943D0;

/* from rac4-decomp's func_L00_0062A688 */
s32 func_L01_004943D0(S_004943D0 *object)
{
    s32 value = object->f10;
    if (value != 0) {
        return value;
    }
    return object->fC;
}
/* localdecomp:end func_L01_004943D0 */
