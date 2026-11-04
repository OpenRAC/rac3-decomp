#include "common.h"

typedef struct {
    u8 pad0[0x84];
    s32 f84;
} S_Sub_003BC958;
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad1[0x47];
    S_Sub_003BC958 *f68;
} S_Obj_003BC958;
typedef struct {
    u8 pad0[0x24];
    s32 f24;
    u8 pad1[0x44];
    s32 f6C;
    s16 f70;
    u8 pad2[4];
    s16 f76;
    u8 pad3[0x1C];
    s32 f94;
    s16 f98;
    u8 pad4[4];
    s16 f9E;
} S_1CCFD0_003BC958;

INCLUDE_ASM("asm/levels", func_L35_003BC4B8);

INCLUDE_ASM("asm/levels", func_L35_003BC828);

/* localdecomp:start func_L35_003BC958 */
extern S_1CCFD0_003BC958 D_001CCFD0;
extern void func_L35_003BC9F0(void *);
extern void func_L35_003BCA28(S_Obj_003BC958 *);
extern void func_L35_003BCAB8(void *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L35_003BC958(S_Obj_003BC958 *arg) {
    S_Sub_003BC958 *s = arg->f68;

    if (arg->f20 == 0) {
        func_L35_003BC9F0(arg);
        func_L01_004450F0((u8 *)arg, 1, -1);
    }
    if (D_001CCFD0.f6C == 0 && D_001CCFD0.f24 == -1 && D_001CCFD0.f94 == 0 && s->f84 == 0) {
        func_L35_003BCAB8(arg);
    }
    func_L35_003BCA28(arg);
}
/* localdecomp:end func_L35_003BC958 */

INCLUDE_ASM("asm/levels", func_L35_003BC9F0);

/* localdecomp:start func_L35_003BCA28 */
extern S_1CCFD0_003BC958 D_001CCFD0;
extern s32 func_003A1798(void);

void func_L35_003BCA28(S_Obj_003BC958 *a)
{
    S_Sub_003BC958 *p = a->f68;

    if (D_001CCFD0.f70 >= 0x1B58) {
        if (p->f84 != 0) {
            p->f84 = 0;
            D_001CCFD0.f24 = -1;
        }
    }
    if (D_001CCFD0.f76 == 0 && D_001CCFD0.f9E == 3 && D_001CCFD0.f98 < 0x1B58) {
        func_003A1798();
        p->f84 = 0;
    }
}
/* localdecomp:end func_L35_003BCA28 */

INCLUDE_ASM("asm/levels", func_L35_003BCAB8);
