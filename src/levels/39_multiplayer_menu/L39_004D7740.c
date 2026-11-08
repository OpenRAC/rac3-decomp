#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_004D7740);

INCLUDE_ASM("asm/levels", func_L39_004D7770);

INCLUDE_ASM("asm/levels", func_L39_004D7B38);

INCLUDE_ASM("asm/levels", func_L39_004D8110);

INCLUDE_ASM("asm/levels", func_L39_004D8168);

INCLUDE_ASM("asm/levels", func_L39_004D83E0);

INCLUDE_ASM("asm/levels", func_L39_004D8660);

INCLUDE_ASM("asm/levels", func_L39_004D8BC0);

INCLUDE_ASM("asm/levels", func_L39_004D8CB0);

INCLUDE_ASM("asm/levels", func_L39_004D8E10);

INCLUDE_ASM("asm/levels", func_L39_004D8F00);

INCLUDE_ASM("asm/levels", func_L39_004D8FD0);

INCLUDE_ASM("asm/levels", func_L39_004D9058);

INCLUDE_ASM("asm/levels", func_L39_004D9168);

INCLUDE_ASM("asm/levels", func_L39_004D9330);

INCLUDE_ASM("asm/levels", func_L39_004D9508);

INCLUDE_ASM("asm/levels", func_L39_004D9610);

INCLUDE_ASM("asm/levels", func_L39_004D9650);

INCLUDE_ASM("asm/levels", func_L39_004D98F8);

INCLUDE_ASM("asm/levels", func_L39_004D9CA0);

INCLUDE_ASM("asm/levels", func_L39_004D9ED8);

INCLUDE_ASM("asm/levels", func_L39_004D9F28);

INCLUDE_ASM("asm/levels", func_L39_004DA054);

INCLUDE_ASM("asm/levels", func_L39_004DA068);

INCLUDE_ASM("asm/levels", func_L39_004DA968);

INCLUDE_ASM("asm/levels", func_L39_004DA9E8);

INCLUDE_ASM("asm/levels", func_L39_004DAAB0);

INCLUDE_ASM("asm/levels", func_L39_004DAB90);

INCLUDE_ASM("asm/levels", func_L39_004DACB0);

/* localdecomp:start func_L39_004DAE28 */
extern void func_L39_004DAE48(s32 arg0, s32 arg1, s32 arg2, s32 *arg3);

/* from rac4-decomp's func_L00_00516C28, renamed */
void func_L39_004DAE28(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 t = arg3;
    func_L39_004DAE48(arg0, arg1, arg2, &t);
}
/* localdecomp:end func_L39_004DAE28 */

INCLUDE_ASM("asm/levels", func_L39_004DAE48);

INCLUDE_ASM("asm/levels", func_L39_004DAF40);

INCLUDE_ASM("asm/levels", func_L39_004DAFC0);

/* localdecomp:start func_L39_004DB038 */
s32 func_L39_004DB038(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x18));
}
/* localdecomp:end func_L39_004DB038 */

INCLUDE_ASM("asm/levels", func_L39_004DB040);

INCLUDE_ASM("asm/levels", func_L39_004DB090);

INCLUDE_ASM("asm/levels", func_L39_004DB0D8);

/* localdecomp:start func_L39_004DB110 */
extern void func_L39_004BC6C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void *func_L39_004BEED8(s32 arg0);
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} Type1;

/* from rac4-decomp's func_L00_00516F10, renamed */
void *func_L39_004DB110(void) {
    Type1 *p = (Type1 *)func_L39_004BEED8(0xC);
    if (p != 0) {
        p->f0 = 0;
        p->f8 = 0;
        p->f4 = 0;
        return p;
    }
    func_L39_004BC6C8(7, 0x65, 0x21, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004DB110 */

INCLUDE_ASM("asm/levels", func_L39_004DB168);

INCLUDE_ASM("asm/levels", func_L39_004DB1C0);

INCLUDE_ASM("asm/levels", func_L39_004DB660);

INCLUDE_ASM("asm/levels", func_L39_004DBA08);

INCLUDE_ASM("asm/levels", func_L39_004DC6C8);

INCLUDE_ASM("asm/levels", func_L39_004DCE68);

/* localdecomp:start func_L39_004DD210 */
extern void *(*D_L39_0046B638[])(void);
extern void func_L39_005042F8(void *);

void func_L39_004DD210(void) {
    func_L39_005042F8(D_L39_0046B638[0]());
}
/* localdecomp:end func_L39_004DD210 */

INCLUDE_ASM("asm/levels", func_L39_004DD240);

INCLUDE_ASM("asm/levels", func_L39_004DD250);

INCLUDE_ASM("asm/levels", func_L39_004DD2D8);

INCLUDE_ASM("asm/levels", func_L39_004DD340);

INCLUDE_ASM("asm/levels", func_L39_004DD378);

INCLUDE_ASM("asm/levels", func_L39_004DD4C0);

INCLUDE_ASM("asm/levels", func_L39_004DD520);

INCLUDE_ASM("asm/levels", func_L39_004DD5E0);

INCLUDE_ASM("asm/levels", func_L39_004DD668);

INCLUDE_ASM("asm/levels", func_L39_004DD690);

/* localdecomp:start func_L39_004DD778 */
typedef struct {
    char _p0[0x10];
    void (*f10)(s32 arg0, s32 arg1, unsigned long arg2);
} S2_4DD778;
typedef struct {
    S2_4DD778 *f0;
    char _p4[0xC - 0x4];
    s32 fC;
} S1_4DD778;

/* from rac4-decomp's func_L00_00519578 */
void func_L39_004DD778(S1_4DD778 *arg0, s32 arg1, u32 arg2) {
    arg0->f0->f10(arg0->fC, arg1, arg2);
}
/* localdecomp:end func_L39_004DD778 */

INCLUDE_ASM("asm/levels", func_L39_004DD7A8);

/* localdecomp:start func_L39_004DD808 */
extern void func_L39_004BC6C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void *func_L39_004DBA08(void);

/* from rac4-decomp's func_L00_00519608, renamed */
s32 func_L39_004DD808(void) {
    s32 (*f)(void) = *(s32 (**)(void))((char *)func_L39_004DBA08() + 0x20);
    if (f != 0) {
        return f();
    }
    func_L39_004BC6C8(0xA, 0x68, 0xE, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004DD808 */

INCLUDE_ASM("asm/levels", func_L39_004DD858);

INCLUDE_ASM("asm/levels", func_L39_004DD8B0);

INCLUDE_ASM("asm/levels", func_L39_004DD938);

INCLUDE_ASM("asm/levels", func_L39_004DDA88);

INCLUDE_ASM("asm/levels", func_L39_004DDAE8);

INCLUDE_ASM("asm/levels", func_L39_004DDBF0);

INCLUDE_ASM("asm/levels", func_L39_004DDD68);

INCLUDE_ASM("asm/levels", func_L39_004DDDD8);

INCLUDE_ASM("asm/levels", func_L39_004DDEE0);

INCLUDE_ASM("asm/levels", func_L39_004DDFB0);

INCLUDE_ASM("asm/levels", func_L39_004DDFC8);

INCLUDE_ASM("asm/levels", func_L39_004DE050);

INCLUDE_ASM("asm/levels", func_L39_004DE0C8);

INCLUDE_ASM("asm/levels", func_L39_004DE0F0);

INCLUDE_ASM("asm/levels", func_L39_004DE120);

INCLUDE_ASM("asm/levels", func_L39_004DE150);

INCLUDE_ASM("asm/levels", func_L39_004DE280);

INCLUDE_ASM("asm/levels", func_L39_004DE348);

INCLUDE_ASM("asm/levels", func_L39_004DE458);

INCLUDE_ASM("asm/levels", func_L39_004DE550);

INCLUDE_ASM("asm/levels", func_L39_004DE5D0);

INCLUDE_ASM("asm/levels", func_L39_004DE650);

INCLUDE_ASM("asm/levels", func_L39_004DE6D0);

INCLUDE_ASM("asm/levels", func_L39_004DE828);

INCLUDE_ASM("asm/levels", func_L39_004DE868);
