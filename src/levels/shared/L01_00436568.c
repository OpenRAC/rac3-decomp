#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_00436568);

/* localdecomp:start func_L01_00436570 */
extern char *D_L01_001D67C8;
extern void func_L01_004D23E8(char *);

void func_L01_00436570(void) {
    char *v = D_L01_001D67C8;
    if (v != 0) {
        func_L01_004D23E8(v + 0x1FCA8);
    }
}
/* localdecomp:end func_L01_00436570 */

/* localdecomp:start func_L01_004365A0 */
extern char *D_L01_001D67C8;
extern void func_L01_004D24C0(char *);

void func_L01_004365A0(void) {
    char *v = D_L01_001D67C8;
    if (v != 0) {
        func_L01_004D24C0(v + 0x1FCA8);
    }
}
/* localdecomp:end func_L01_004365A0 */

INCLUDE_ASM("asm/levels", func_L01_004365D0);

/* localdecomp:start func_L01_004365D8 */
extern char *D_L01_001D67C8;
extern void func_L01_004CE670(u8 *, s32, s32, s32, s32);

void func_L01_004365D8(s32 a0, s32 a1, s32 a2, s32 a3) {
    u8 *p = (*(u8 * *)&D_L01_001D67C8);
    if (p != 0) {
        func_L01_004CE670(&p[0x1FCA8], a3, a0, a1, a2);
    }
}
/* localdecomp:end func_L01_004365D8 */

/* localdecomp:start func_L01_00436620 */
extern char *D_L01_001D67C8;
extern s32 func_L01_004CE720(u8 *, s32);

s32 func_L01_00436620(s32 a0) {
    u8 *p = (*(u8 * *)&D_L01_001D67C8);
    if (p != 0) {
        return func_L01_004CE720(p + 0x1FCA8, a0);
    }
    return 0;
}
/* localdecomp:end func_L01_00436620 */

/* localdecomp:start func_L01_00436660 */
extern char *D_L01_001D67C8;
typedef struct {
    u8 pad[0x1FCA8];
    u8 sub[4];
} Unk00433628;

extern void func_L01_004CE758(void *, s32, s32, s32);

void func_L01_00436660(s32 a0, s32 a1, s32 a2) {
    if ((*(Unk00433628 * *)&D_L01_001D67C8) != 0) {
        func_L01_004CE758((*(Unk00433628 * *)&D_L01_001D67C8)->sub, a2, a0, a1);
    }
}
/* localdecomp:end func_L01_00436660 */

/* localdecomp:start func_L01_004366A0 */
extern char *D_L01_001D67C8;
extern void func_L01_004CDEA8(u8 *, s32, s32);

void func_L01_004366A0(s32 a0, s32 a1) {
    u8 *p = (*(u8 * *)&D_L01_001D67C8);
    if (p != 0) {
        func_L01_004CDEA8(p + 0x1FCA8, a0, a1);
    }
}
/* localdecomp:end func_L01_004366A0 */

/* localdecomp:start func_L01_004366E0 */
extern char *D_L01_001D67C8;
extern void func_L01_004CDF10(char *);

void func_L01_004366E0(void) {
    char *v = D_L01_001D67C8;
    if (v != 0) {
        func_L01_004CDF10(v + 0x1FCA8);
    }
}
/* localdecomp:end func_L01_004366E0 */

INCLUDE_ASM("asm/levels", func_L01_00436710);

/* localdecomp:start func_L01_00436718 */
extern int D_00143950[];
extern void func_003AAE60(int);

void func_L01_00436718(void)
{
    func_003AAE60(D_00143950[0] != 0);
}
/* localdecomp:end func_L01_00436718 */

INCLUDE_ASM("asm/levels", func_L01_00436740);
