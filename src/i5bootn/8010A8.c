#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_008010A8 */
/* Sony 2.9-ee library code: word copy of n bytes (n rounded down to whole words). */
int func_008010A8(unsigned int *d, unsigned int *s, unsigned int n) {
    unsigned int i;
    n >>= 2;
    for (i = 0; i < n; i++)
        *d++ = *s++;
    return 0;
}
/* localdecomp:end func_008010A8 */

LINKER_REMNANT("asm/i5bootn/remnants", func_008010E0);

ASM_FUNC("asm/i5bootn/handwritten", func_008010E8);
