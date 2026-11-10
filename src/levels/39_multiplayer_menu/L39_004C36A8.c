#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_004C36A8);

INCLUDE_ASM("asm/levels", func_L39_004C37E0);

INCLUDE_ASM("asm/levels", func_L39_004C39F8);

INCLUDE_ASM("asm/levels", func_L39_004C3BB8);

INCLUDE_ASM("asm/levels", func_L39_004C3CC0);

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

INCLUDE_ASM("asm/levels", func_L39_004C3E28);

INCLUDE_ASM("asm/levels", func_L39_004C3F68);

INCLUDE_ASM("asm/levels", func_L39_004C4168);

/* localdecomp:start func_L39_004C4198 */
typedef struct {
    char _p0[0x14];
    s32 f14;
} T_004C4198;
typedef struct {
    char _p0[0x64];
    s32 f64;
    char _p68[0xDC - 0x68];
    T_004C4198 *fDC;
} S_004C4198;

s32 func_L39_004C4198(S_004C4198 *arg0) {
    T_004C4198 *p;
    s32 w;

    if (arg0 != 0) {
        if (arg0->f64 != 0) {
            return arg0->f64;
        }
        p = arg0->fDC;
        if (p != 0) {
            w = p->f14;
            if (w != 0) {
                return w;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L39_004C4198 */

INCLUDE_ASM("asm/levels", func_L39_004C41D0);

INCLUDE_ASM("asm/levels", func_L39_004C4270);

INCLUDE_ASM("asm/levels", func_L39_004C43D8);

INCLUDE_ASM("asm/levels", func_L39_004C46A8);

INCLUDE_ASM("asm/levels", func_L39_004C47C0);

INCLUDE_ASM("asm/levels", func_L39_004C47D0);

INCLUDE_ASM("asm/levels", func_L39_004C47F8);

INCLUDE_ASM("asm/levels", func_L39_004C4908);

INCLUDE_ASM("asm/levels", func_L39_004C4998);
