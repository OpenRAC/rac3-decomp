#include "common.h"

typedef struct S_00504410 {
    u8 pad[0x20];
    u8 *f20;
    void (*f24)(void);
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
} S_00504410;

INCLUDE_ASM("asm/levels", func_L39_005013E0);

INCLUDE_ASM("asm/levels", func_L39_00501658);

INCLUDE_ASM("asm/levels", func_L39_005017A0);

INCLUDE_ASM("asm/levels", func_L39_00501B08);

INCLUDE_ASM("asm/levels", func_L39_00502618);

INCLUDE_ASM("asm/levels", func_L39_00502FF8);

INCLUDE_ASM("asm/levels", func_L39_005031A8);

INCLUDE_ASM("asm/levels", func_L39_00503360);

INCLUDE_ASM("asm/levels", func_L39_00503B20);

INCLUDE_ASM("asm/levels", func_L39_005042F8);

/* localdecomp:start func_L39_00504410 */
extern u8 D_L39_0050C0B8[];
extern void func_L39_0050C110(void);
extern S_00504410 *func_L39_004DBA08(void);

s32 func_L39_00504410(void) {
    S_00504410 *p = func_L39_004DBA08();

    p->f20 = D_L39_0050C0B8;
    p->f24 = func_L39_0050C110;
    p->f28 = 0;
    p->f2C = 0;
    p->f30 = 0;
    p->f34 = 0;
    p->f38 = 0;
    return 1;
}
/* localdecomp:end func_L39_00504410 */

INCLUDE_ASM("asm/levels", func_L39_00504460);

INCLUDE_ASM("asm/levels", func_L39_00504488);

INCLUDE_ASM("asm/levels", func_L39_005044B0);

INCLUDE_ASM("asm/levels", func_L39_005044D8);

INCLUDE_ASM("asm/levels", func_L39_00504500);

INCLUDE_ASM("asm/levels", func_L39_00504528);

INCLUDE_ASM("asm/levels", func_L39_00504588);

/* localdecomp:start func_L39_005045A8 */
typedef struct Type1 {
    s32 f0;
    s32 f4;
    char _p8[0x58 - 0x8];
    s32 f58;
    s32 f5C;
} Type1;

/* from rac4-decomp's func_L00_005403B8, renamed */
void func_L39_005045A8(Type1 *arg0) {
    arg0->f5C = 0;
    arg0->f0 = 0;
    arg0->f58 = 0;
    arg0->f4 = 30;
}
/* localdecomp:end func_L39_005045A8 */

INCLUDE_ASM("asm/levels", func_L39_005045C0);

INCLUDE_ASM("asm/levels", func_L39_005047E8);

INCLUDE_ASM("asm/levels", func_L39_00504970);

INCLUDE_ASM("asm/levels", func_L39_005049D8);

/* localdecomp:start func_L39_00504A30 */
typedef struct S_504A30_B S_504A30_B;
typedef struct {
    char _p0[0x14];
    void (*f14)(S_504A30_B *arg0);
} S_504A30_A;
struct S_504A30_B {
    S_504A30_A *f0;
};

/* from rac4-decomp's func_L00_0051EE28 */
void func_L39_00504A30(S_504A30_B *arg0) {
    arg0->f0->f14(arg0);
}
/* localdecomp:end func_L39_00504A30 */

INCLUDE_ASM("asm/levels", func_L39_00504A58);

/* localdecomp:start func_L39_00504B50 */
extern void func_L39_004DE5D0(void);
extern void func_L39_004DE650(void);

/* from rac4-decomp's func_L00_00540960, renamed */
void func_L39_00504B50(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg4 < 0) {
        arg4 = arg0[1];
    }
    if (arg4 != 0) {
        func_L39_004DE5D0();
    } else {
        func_L39_004DE650();
    }
}
/* localdecomp:end func_L39_00504B50 */

INCLUDE_ASM("asm/levels", func_L39_00504B90);

INCLUDE_ASM("asm/levels", func_L39_00504C80);

/* localdecomp:start func_L39_00504DF8 */
s32 func_L39_00504DF8(s32 arg0) {
    return arg0 + 0x2C;
}
/* localdecomp:end func_L39_00504DF8 */

INCLUDE_ASM("asm/levels", func_L39_00504E00);
