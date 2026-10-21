#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_004AC1C0);

LINKER_REMNANT("asm/levels", func_L01_004AC610);

INCLUDE_ASM("asm/levels", func_L01_004AC618);

LINKER_REMNANT("asm/levels", func_L01_004AC838);

INCLUDE_ASM("asm/levels", func_L01_004AC840);

/* localdecomp:start func_L01_004AC8A8 */
typedef struct {
    u8 pad0[16];
    s32 f10;
} Sub_4A8EB8;
typedef struct {
    u8 pad0[36];
    Sub_4A8EB8 *p24;
    u8 pad28[12];
    u16 h34;
    u8 pad36[98];
    s32 f98;
} Obj_4A8EB8;
extern Obj_4A8EB8 *D_0016C580[];
extern void func_003A56A0(void);
extern void func_003A58C0(Obj_4A8EB8 *, s32);
void func_L01_004AC8A8(void) {
    Obj_4A8EB8 *o = D_0016C580[0];
    if (o != 0) {
        o->h34 &= 0xFFFC;
        func_003A56A0();
        func_003A58C0(D_0016C580[0], 0);
        D_0016C580[0]->f98 = D_0016C580[0]->p24->f10;
    }
}
/* localdecomp:end func_L01_004AC8A8 */

INCLUDE_ASM("asm/levels", func_L01_004AC900);

/* localdecomp:start func_L01_004ACB38 */
extern u8 D_001A4BE0[];
extern u8 D_001CCFD0[];
extern u16 D_0016C5AA[];
extern void func_L01_0045F328(s32);
extern void func_003A4288(void);
extern void func_L01_0041A6E0(void);
extern void func_L01_004AC900(s32);

void func_L01_004ACB38(void)
{
    u8 *g = D_001A4BE0;
    u8 *p;

    if (*(s32 *)(g + 10320) <= 0) {
        *(s32 *)(g + 10320) = 1;
    }
    func_L01_0045F328(0);
    p = D_001CCFD0;
    if (*(u16 *)(p + 118) != 6 && *(u16 *)(p + 118) != 7) {
        *(u16 *)(p + 118) = 5;
    }
    if (*(u16 *)(p + 158) != 6 && *(u16 *)(p + 158) != 7) {
        *(u16 *)(p + 158) = 5;
    }
    func_003A4288();
    func_L01_0041A6E0();
    func_L01_004AC900(0);
    D_0016C5AA[0] = 0;
}
/* localdecomp:end func_L01_004ACB38 */

INCLUDE_ASM("asm/levels", func_L01_004ACBC8);

INCLUDE_ASM("asm/levels", func_L01_004ACD40);

INCLUDE_ASM("asm/levels", func_L01_004ACDB0);

INCLUDE_ASM("asm/levels", func_L01_004ACF48);
