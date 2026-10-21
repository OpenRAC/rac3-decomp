#include "common.h"

INCLUDE_ASM("asm/levels", func_L30_0034EB98);

INCLUDE_ASM("asm/levels", func_L30_0034EDE0);

INCLUDE_ASM("asm/levels", func_L30_0034EFB8);

INCLUDE_ASM("asm/levels", func_L30_0034F1A8);

INCLUDE_ASM("asm/levels", func_L30_0034F2D8);

INCLUDE_ASM("asm/levels", func_L30_0034F5D8);

INCLUDE_ASM("asm/levels", func_L30_0034F998);

INCLUDE_ASM("asm/levels", func_L30_0034FC30);

INCLUDE_ASM("asm/levels", func_L30_0034FE30);

INCLUDE_ASM("asm/levels", func_L30_00350050);

INCLUDE_ASM("asm/levels", func_L30_003501B0);

INCLUDE_ASM("asm/levels", func_L30_003502D0);

INCLUDE_ASM("asm/levels", func_L30_00350690);

/* localdecomp:start func_L30_00350970 */
extern void func_L30_0034DAC0(u8 *p);
extern void func_003C2880(u8 *p);

void func_L30_00350970(u8 *a) {
    func_L30_0034DAC0(*(u8 **)(a + 104) + 16);
    func_003C2880(a);
}
/* localdecomp:end func_L30_00350970 */

INCLUDE_ASM("asm/levels", func_L30_003509A8);

INCLUDE_ASM("asm/levels", func_L30_00350A30);

INCLUDE_ASM("asm/levels", func_L30_00350DB0);

INCLUDE_ASM("asm/levels", func_L30_00350EF0);

INCLUDE_ASM("asm/levels", func_L30_00350FA8);

INCLUDE_ASM("asm/levels", func_L30_003510C8);

/* localdecomp:start func_L30_003514D8 */
extern void func_003C2880(u8 *p);
typedef struct {
    u8 pad[0x80];
} S_1A30B0;

extern S_1A30B0 D_001A30B0[];
extern s32 D_001A71A0[];
extern void func_003A4F28(s32);

void func_L30_003514D8(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 i = *(s32 *)(v + 0x20);

    if (i != -1) {
        u8 *p = (u8 *)&D_001A30B0[i];
        if (*(s32 *)(p + 0xDC) == D_001A71A0[0] && *(p + 0xD0) != 0) {
            func_003A4F28(i);
        }
    }
    *(s32 *)(v + 0x20) = -1;
    ((void (*)(void *))func_003C2880)(m);
}
/* localdecomp:end func_L30_003514D8 */

INCLUDE_ASM("asm/levels", func_L30_00351558);

INCLUDE_ASM("asm/levels", func_L30_003518F0);

/* localdecomp:start func_L30_00351CB0 */
typedef int u128_350DA0 __attribute__((mode(TI)));
typedef struct { u8 pad[0x18]; s32 x18; } V_350DA0;
typedef struct { u8 pad[0x10]; u128_350DA0 pos; u8 pad20[0x10]; u8 x30; u8 pad31[0x68 - 0x31]; V_350DA0 *x68; } O_350DA0;
extern O_350DA0 *func_003C24B0(s32, s32);
extern void func_L30_00350EF0(O_350DA0 *);
O_350DA0 *func_L30_00351CB0(O_350DA0 *a) {
    O_350DA0 *o = func_003C24B0(5951, 128);
    if (o != 0) {
        o->x30 = 255;
        o->x68->x18 = 0;
        o->pos = a->pos;
        func_L30_00350EF0(o);
    }
    return o;
}
/* localdecomp:end func_L30_00351CB0 */

INCLUDE_ASM("asm/levels", func_L30_00351D10);

INCLUDE_ASM("asm/levels", func_L30_00352050);

INCLUDE_ASM("asm/levels", func_L30_00352208);
