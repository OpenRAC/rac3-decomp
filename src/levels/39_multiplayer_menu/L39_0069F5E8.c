#include "common.h"

/* localdecomp:start func_L39_0069F5E8 */
typedef struct Type1 {
    char _p0[0x2a8];
    u8 f2a8[20];
} Type1;

/* from rac4-decomp's func_L00_00763480 */
void func_L39_0069F5E8(Type1 *arg0, u8 *arg1) {
    s32 i;
    for (i = 0; i < 8; i++) {
        arg0->f2a8[i] = arg1[i];
    }
}
/* localdecomp:end func_L39_0069F5E8 */

/* localdecomp:start func_L39_0069F618 */
typedef struct {
    char _p0[0x2A8];
    u8 f2A8[8];
} S_69F618;

/* from rac4-decomp's func_L00_007634B0 */
void func_L39_0069F618(S_69F618 *arg0, u8 *arg1) {
    s32 i;
    for (i = 0; i < 8; i++) {
        arg1[i] = arg0->f2A8[i];
    }
}
/* localdecomp:end func_L39_0069F618 */

LINKER_REMNANT("asm/levels", func_L39_0069F648);
