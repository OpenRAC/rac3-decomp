#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_00381080 */
typedef unsigned int U128_00381080 __attribute__((mode(TI)));
extern u8 *D_001DA050_00381080;
extern u8 *D_001DA050;
__asm__(".extern D_001DA050_00381080, 16");
extern U128_00381080 D_001D7710;

void func_00381080(void) {
    *(u32 *)(D_001DA050_00381080 + 0) = 0x10000003;
    *(u32 *)(D_001DA050_00381080 + 4) = 0;
    *(u32 *)(D_001DA050_00381080 + 8) = 0;
    *(u32 *)(D_001DA050_00381080 + 12) = 0x50000003;
    { u8 *p = D_001DA050_00381080; D_001DA050_00381080 = p + 16; *(U128_00381080 *)(p + 16) = D_001D7710; }
    { u8 *p = D_001DA050_00381080; u8 *q = p + 16; D_001DA050_00381080 = q;
    *(unsigned long *)(p + 16) = 0x101;
    *(unsigned long *)(q + 8) = 0x80000000UL;
    *(unsigned long *)(q + 16) = 0x8FE86FF8UL;
    *(unsigned long *)(q + 24) = 0x8FE88FF8UL;
    }
    D_001DA050 = D_001DA050_00381080 + 32;
}
/* localdecomp:end func_00381080 */
