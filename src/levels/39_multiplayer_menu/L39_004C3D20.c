#include "common.h"

/* localdecomp:start func_L39_004C3D20 */
typedef struct Type1 Type1;
typedef struct Type2 {
    char _p0[0x18];
    s32 (*f18)(Type1 *arg0);
} Type2;
struct Type1 {
    char _p0[0x8];
    Type2 *f8;
    char _pC[0x18 - 0xC];
    s32 f18;
    char _p1C[0x2C - 0x1C];
    s32 f2C;
};

/* from rac4-decomp's func_L00_004FFB20, renamed */
s32 func_L39_004C3D20(Type1 *arg0) {
    if ((arg0->f2C & 2) == 0) {
        return arg0->f8->f18(arg0);
    }
    arg0->f18 = 1;
    return 0;
}
/* localdecomp:end func_L39_004C3D20 */

INCLUDE_ASM("asm/levels", func_L39_004C3D60);

INCLUDE_ASM("asm/levels", func_L39_004C3DC0);
