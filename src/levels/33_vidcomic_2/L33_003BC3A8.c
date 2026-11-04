#include "common.h"

typedef struct { u8 p0[0x24]; s32 w24; u8 p28[0x44]; s32 w6C; u8 p70[0x24]; s32 w94; } S_001CCFD0_003BC3A8;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; u8 *p68; } S_003BC3A8;
typedef struct { u8 p0[0x28]; s32 w28; } S_003BC3A8_q;

/* localdecomp:start func_L33_003BC3A8 */
extern S_001CCFD0_003BC3A8 D_001CCFD0;
extern void func_L33_003BC440(u8 *);
extern void func_L33_003BC478(u8 *);
extern void func_L33_003BC500(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L33_003BC3A8(u8 *a0) {
    S_003BC3A8 *p = (S_003BC3A8 *)a0;
    S_003BC3A8_q *q = (S_003BC3A8_q *)p->p68;
    if (p->b20 == 0) {
        func_L33_003BC440(a0);
        func_L01_004450F0(a0, 1, -1);
    }
    if (D_001CCFD0.w6C == 0 && D_001CCFD0.w24 == -1 && D_001CCFD0.w94 == 0 && q->w28 == 0) {
        func_L33_003BC500(a0);
    }
    func_L33_003BC478(a0);
}
/* localdecomp:end func_L33_003BC3A8 */

INCLUDE_ASM("asm/levels", func_L33_003BC440);

INCLUDE_ASM("asm/levels", func_L33_003BC478);

INCLUDE_ASM("asm/levels", func_L33_003BC500);
