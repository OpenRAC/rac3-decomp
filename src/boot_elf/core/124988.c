#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_00124988 */
typedef struct { s32 pad0; s32 f4; s32 f8; s32 fc; s32 f10; void *f14; s32 f18; s32 f1c; s32 f20; s32 f24; s32 f28; s32 f2c; s32 f30; void *f34; } S_124988;
extern s32 D_0013E310[];
extern s32 D_0013E314[];
extern u8 D_00150DC0[];
extern u8 D_00150DD0[];
extern s32 func_0011EE20(void *);
void func_00124988(void) {
    S_124988 s;
    s.f4 = 1;
    s.f8 = 1;
    s.f14 = D_00150DC0;
    s.f24 = 1;
    s.f28 = 1;
    s.f34 = D_00150DD0;
    D_0013E310[0] = func_0011EE20(&s);
    D_0013E314[0] = func_0011EE20((u8 *)&s + 0x20);
}
/* localdecomp:end func_00124988 */

LINKER_REMNANT("asm/boot_elf/remnants", func_001249E8);

/* localdecomp:start func_001249F0 */
s32 func_001249F0(u32 *dst, u32 *src, u32 n) {
    u32 i;

    n >>= 2;
    for (i = 0; i < n; i++) {
        *dst++ = *src++;
    }
    return 0;
}
/* localdecomp:end func_001249F0 */

/* localdecomp:start func_00124A28 */
u32 *func_00124A28(u32 *p, u32 *end, u32 val) {
    while (*p != val && p < end) {
        p++;
    }
    return p < end ? p : 0;
}
/* localdecomp:end func_00124A28 */
