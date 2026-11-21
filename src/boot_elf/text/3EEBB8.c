#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_003EEBB8 */
/* from frontbin twin func_003EE800 */
void func_003EEBB8(u8 *p, f32 *a) {
    *(f32 *)(p + 0x10) = a[0] + (a[2] - a[0]) * 0.5f;
    *(f32 *)(p + 0x14) = a[1] + (a[3] - a[1]) * 0.5f;
}
/* localdecomp:end func_003EEBB8 */
