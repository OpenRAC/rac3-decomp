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

/* localdecomp:start func_L39_004E2EA0 */
typedef struct V_004E2EA0 {
    void *f0;
    void *f4;
    void *f8;
    s32 (*fC)(void *, s32, s32, s32, s32, s32, s32, s32);
} V_004E2EA0;
typedef struct O_004E2EA0 {
    V_004E2EA0 *vt;
} O_004E2EA0;

s32 func_L39_004E2EA0(O_004E2EA0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return arg0->vt->fC(arg0, 3, arg1, arg2, arg3, arg4, arg5, arg6);
}
/* localdecomp:end func_L39_004E2EA0 */

/* localdecomp:start func_L39_004E2EF0 */
typedef struct V_004E2EF0 {
    void *f0;
    void *f4;
    void *f8;
    s32 (*fC)(void *, s32, s32, s32, s32, s32, s32, s32);
} V_004E2EF0;
typedef struct O_004E2EF0 {
    V_004E2EF0 *vt;
} O_004E2EF0;

s32 func_L39_004E2EF0(O_004E2EF0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return arg0->vt->fC(arg0, 2, arg1, arg2, arg3, arg4, arg5, arg6);
}
/* localdecomp:end func_L39_004E2EF0 */

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

/* localdecomp:start func_L39_004E2F70 */
typedef struct V_004E2F70 {
    void *f0;
    void *f4;
    void *f8;
    s32 (*fC)(void *, s32, s32, s32, s32, s32, s32, s32);
} V_004E2F70;
typedef struct O_004E2F70 {
    V_004E2F70 *vt;
} O_004E2F70;

s32 func_L39_004E2F70(O_004E2F70 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return arg0->vt->fC(arg0, 6, arg1, arg2, arg3, arg4, arg5, arg6);
}
/* localdecomp:end func_L39_004E2F70 */

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

/* localdecomp:start func_L39_004E36B0 */
extern s32 func_L39_004E3748(void *, s32, u8 *, u32 *, u32, s32, s32, s32);
extern s32 func_L39_004E3B68(void *, s32, s32, u32 *, u32, s32, u32, s32);
extern s32 func_L39_004E3CB8(void *, s32, s32, u32 *, u32, s32, u32, s32);
extern s32 func_L39_004E3EB8(void *, s32, s32, u32 *, u32, s32, u32, s32);
extern s32 func_L39_004E3FC0(void *, s32, s32, u32 *, u32, s32, u32, s32);

s32 func_L39_004E36B0(void *arg0, s32 arg1, s32 arg2, u32 *arg3, u32 arg4, s32 arg5, u32 arg6, s32 arg7) {
    switch (arg1) {
    case 1:
    case 10:
        return func_L39_004E3748(arg0, arg1, (u8 *)arg2, arg3, arg4, arg5, arg6, arg7);
    case 4:
        return func_L39_004E3FC0(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    case 2:
        return func_L39_004E3B68(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    case 3:
        return func_L39_004E3CB8(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    case 9:
        return func_L39_004E3EB8(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    }
    return 2;
}
/* localdecomp:end func_L39_004E36B0 */
