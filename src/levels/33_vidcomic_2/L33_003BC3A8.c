#include "common.h"

typedef struct { u8 p0[0x24]; s32 w24; u8 p28[0x44]; s32 w6C; u8 p70[0x24]; s32 w94; } S_001CCFD0_003BC3A8;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; u8 *p68; } S_003BC3A8;
typedef struct { u8 p0[0x28]; s32 w28; } S_003BC3A8_q;

typedef struct { u8 pad0[0x28]; s32 f28; } S_003BC478_P;
typedef struct { u8 pad0[0x68]; S_003BC478_P *f68; } S_003BC478_A;
typedef struct {
    u8 pad0[0x70]; s16 f70; u8 pad72[4]; s16 f76;
    u8 pad78[0x20]; s16 f98; u8 pad9A[4]; s16 f9E;
} S_1CCFD0_003BC478;

extern void func_003A1798(void *);

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

/* localdecomp:start func_L33_003BC440 */
extern s32 func_L30_0034CA78(void);

void func_L33_003BC440(u8 *a0) {
    s32 *q = *(s32 **)(a0 + 0x68);
    a0[0x30] = 0xFF;
    q[0x24 / 4] = func_L30_0034CA78();
    q[0x28 / 4] = 0;
}
/* localdecomp:end func_L33_003BC440 */

/* localdecomp:start func_L33_003BC478 */
void func_L33_003BC478(u8 *a0) {
    S_003BC478_P *p = ((S_003BC478_A *)a0)->f68;

    if ((*(S_1CCFD0_003BC478 *)&D_001CCFD0).f70 >= 7000) {
        if (p->f28 != 0) {
            p->f28 = 0;
        }
    }
    if ((*(S_1CCFD0_003BC478 *)&D_001CCFD0).f76 == 0 && (*(S_1CCFD0_003BC478 *)&D_001CCFD0).f9E == 3 && (*(S_1CCFD0_003BC478 *)&D_001CCFD0).f98 < 7000) {
        func_003A1798(&D_001CCFD0);
        p->f28 = 0;
    }
}
/* localdecomp:end func_L33_003BC478 */

INCLUDE_ASM("asm/levels", func_L33_003BC500);
