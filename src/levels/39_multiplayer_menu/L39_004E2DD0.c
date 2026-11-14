#include "common.h"

/* localdecomp:start func_L39_004E2DD0 */
typedef struct Type1 Type1;
typedef struct Type2 {
    s32 (*f0)(Type1 *arg0, s32 arg1, s32 arg2, s32 arg3);
} Type2;
struct Type1 {
    Type2 *f0;
};

/* from rac4-decomp's func_L00_0051EBD0, renamed */
s32 func_L39_004E2DD0(Type1 *arg0, Type2 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0->f0 = arg1;
    return arg1->f0(arg0, arg2, arg3, arg4);
}
/* localdecomp:end func_L39_004E2DD0 */

/* localdecomp:start func_L39_004E2E00 */
typedef struct S_004E2E00 S_004E2E00;
typedef struct V_004E2E00 {
    char _p0[0xC];
    s32 (*fC)(S_004E2E00 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
} V_004E2E00;
struct S_004E2E00 {
    V_004E2E00 *f0;
};

/* from rac4-decomp's func_L00_0051EC00 */
s32 func_L39_004E2E00(S_004E2E00 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return arg0->f0->fC(arg0, 1, arg1, arg2, arg3, arg4, arg5, arg6);
}
/* localdecomp:end func_L39_004E2E00 */

/* localdecomp:start func_L39_004E2E50 */
typedef struct S_004E2E50 S_004E2E50;
typedef struct V_004E2E50 {
    char _p0[0xC];
    s32 (*fC)(S_004E2E50 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
} V_004E2E50;
struct S_004E2E50 {
    V_004E2E50 *f0;
};

/* from rac4-decomp's func_L00_0051EC00 */
s32 func_L39_004E2E50(S_004E2E50 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return arg0->f0->fC(arg0, 4, arg1, arg2, arg3, arg4, arg5, arg6);
}
/* localdecomp:end func_L39_004E2E50 */

INCLUDE_ASM("asm/levels", func_L39_004E2EA0);

INCLUDE_ASM("asm/levels", func_L39_004E2EF0);

/* localdecomp:start func_L39_004E2F40 */
typedef struct S_004E2F40 S_004E2F40;
typedef struct V_004E2F40 {
    char _p0[0x8];
    void (*f8)(S_004E2F40 *arg0, s32 arg1, s32 arg2, s32 arg3);
} V_004E2F40;
struct S_004E2F40 {
    V_004E2F40 *f0;
};

/* from rac4-decomp's func_L00_0051ED40 */
void func_L39_004E2F40(S_004E2F40 *arg0, s32 arg1) {
    arg0->f0->f8(arg0, 5, 0, arg1);
}
/* localdecomp:end func_L39_004E2F40 */

INCLUDE_ASM("asm/levels", func_L39_004E2F70);

/* localdecomp:start func_L39_004E2FC0 */
typedef struct S_004E2FC0 S_004E2FC0;
typedef struct V_004E2FC0 {
    char _p0[0x10];
    s32 (*f10)(S_004E2FC0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
} V_004E2FC0;
struct S_004E2FC0 {
    V_004E2FC0 *f0;
};

s32 func_L39_004E2FC0(S_004E2FC0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return arg0->f0->f10(arg0, 8, arg1, arg2, arg3, arg4);
}
/* localdecomp:end func_L39_004E2FC0 */

/* localdecomp:start func_L39_004E3000 */
void func_L39_004E3000(void *arg0, s32 arg1, s32 arg2) {
    ((void (*)(void *, s32, s32, s32))(*(s32 *)(*(s32 *)arg0 + 0x18)))(arg0, 0x101, arg2, arg1);
}
/* localdecomp:end func_L39_004E3000 */

/* localdecomp:start func_L39_004E3028 */
typedef struct S_004E3028 S_004E3028;
typedef struct V_004E3028 {
    char _p0[0x18];
    void (*f18)(S_004E3028 *arg0);
} V_004E3028;
struct S_004E3028 {
    V_004E3028 *f0;
};

/* from rac4-decomp's func_L00_0051EE28 */
void func_L39_004E3028(S_004E3028 *arg0) {
    arg0->f0->f18(arg0);
}
/* localdecomp:end func_L39_004E3028 */

/* localdecomp:start func_L39_004E3050 */
extern s32 D_L39_0046D2E0[];

void *func_L39_004E3050(void) {
    return D_L39_0046D2E0;
}
/* localdecomp:end func_L39_004E3050 */

INCLUDE_ASM("asm/levels", func_L39_004E3060);

INCLUDE_ASM("asm/levels", func_L39_004E3178);

INCLUDE_ASM("asm/levels", func_L39_004E36B0);

INCLUDE_ASM("asm/levels", func_L39_004E3748);

INCLUDE_ASM("asm/levels", func_L39_004E38F0);
