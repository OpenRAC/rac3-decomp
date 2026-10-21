#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3AC810;

INCLUDE_ASM("asm/levels", func_L13_003ABD48);

/* localdecomp:start func_L13_003ADA98 */
extern void func_L13_003AE698(u8 *a);

void func_L13_003ADA98(u8 *a, u8 *b) {
    if (b[939] != 0) {
        a[149] = 0;
    } else {
        a[149] = 1;
    }
    b[943] = 0;
    func_L13_003AE698(a);
}
/* localdecomp:end func_L13_003ADA98 */

INCLUDE_ASM("asm/levels", func_L13_003ADAD0);

INCLUDE_ASM("asm/levels", func_L13_003ADE00);

INCLUDE_ASM("asm/levels", func_L13_003AE508);

/* localdecomp:start func_L13_003AE5F8 */

extern S_3AC810 *func_L01_0043B548(s32, s32);
extern void func_003C2880(void *);

void func_L13_003AE5F8(u8 *m, s32 b) {
    if (*(s32 *)(*(u8 **)(m + 0x68) + 0x260) != 0) {
        S_3AC810 *v = func_L01_0043B548(6625, 108);
        v->f0(m);
        if (b) {
            v->f4(m);
        }
    } else {
        func_003C2880(m);
    }
}
/* localdecomp:end func_L13_003AE5F8 */

INCLUDE_ASM("asm/levels", func_L13_003AE678);

INCLUDE_ASM("asm/levels", func_L13_003AE698);

/* localdecomp:start func_L13_003AE880 */
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L13_003AE8C8(u8 *);
void func_L13_003AE880(u8 *a0) {
    if (*(s32 *)(*(u8 **)(a0 + 104) + 896) != -1) {
        func_L01_004450F0(a0, 8, -1);
    } else {
        func_L13_003AE8C8(a0);
    }
}
/* localdecomp:end func_L13_003AE880 */

INCLUDE_ASM("asm/levels", func_L13_003AE8C8);

INCLUDE_ASM("asm/levels", func_L13_003AE990);

/* localdecomp:start func_L13_003AEA10 */
extern void func_L13_003AEB48(void *);
extern void func_L13_003AEBC8(void *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L13_003AEA10(u8 *arg0)
{
    u8 *v = *(u8 **)(arg0 + 104);

    if (*(s32 *)(v + 908) != -1) {
        ((void (*)(u8 *))func_L13_003AEBC8)(arg0);
        func_L01_004450F0(arg0, 23, -1);
    } else if (*(s32 *)(v + 916) != -1) {
        ((void (*)(u8 *))func_L13_003AEBC8)(arg0);
        func_L01_004450F0(arg0, 21, -1);
    } else {
        ((void (*)(u8 *))func_L13_003AEB48)(arg0);
        func_L01_004450F0(arg0, 22, -1);
    }
}
/* localdecomp:end func_L13_003AEA10 */

INCLUDE_ASM("asm/levels", func_L13_003AEA98);

INCLUDE_ASM("asm/levels", func_L13_003AEB48);

INCLUDE_ASM("asm/levels", func_L13_003AEBC8);

INCLUDE_ASM("asm/levels", func_L13_003AEC48);

INCLUDE_ASM("asm/levels", func_L13_003AECE0);

INCLUDE_ASM("asm/levels", func_L13_003AEDD8);

INCLUDE_ASM("asm/levels", func_L13_003AEEB0);

INCLUDE_ASM("asm/levels", func_L13_003AF048);

INCLUDE_ASM("asm/levels", func_L13_003AF0B0);

INCLUDE_ASM("asm/levels", func_L13_003AF0E8);

/* localdecomp:start func_L13_003AF260 */
extern u8 *D_L13_001DF59C;
extern s32 func_L01_00445AD0(s32, s32, s32);

s32 func_L13_003AF260(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 104);
    u8 *m;

    if (*(s32 *)(p + 996) != 0) {
        *(s32 *)(p + 996) = 0;
        return 1;
    }
    if (*(s16 *)(p + 324) != 1) {
        return 0;
    }
    if (*(s32 *)(p + 924) != -1) {
        m = D_L13_001DF59C + (*(s32 *)(p + 924) << 8);
        if (m != 0 && m[32] != 254 && m[32] != 253) {
            return 0;
        }
    }
    if (*(s32 *)(p + 920) != -1 && func_L01_00445AD0(*(s32 *)(p + 920), -1, 0) != 0) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L13_003AF260 */

INCLUDE_ASM("asm/levels", func_L13_003AF2F8);

INCLUDE_ASM("asm/levels", func_L13_003AF3B8);

INCLUDE_ASM("asm/levels", func_L13_003AF5E8);
