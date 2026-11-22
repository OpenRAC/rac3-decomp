/* func_L01_0048F390: 1 word differs. The $gp reload of D_001D52FC in the bnez delay slot: retail lw $v1,-0x75B4($gp), check.py resolves this sdata array to 0x4A4C($gp). A _sda name or .extern changes the code shape instead. */
#include "common.h"
extern s16 D_001CCFD4[];
extern void func_L01_0048F4E0(void);
extern void func_L01_00516090(void *);
void func_L01_0048F390(void *a0) {
    func_L01_0047EC88();
    func_L01_0048F4E0();
    if ((*(s32 *)(D_001D52FC[0] + 0x1C4) & 0xD10) && D_001CCFD4[0] == 0) {
        func_L01_00517748(func_L01_0047EBE0());
        func_L01_00516090(a0);
        return;
    }
    if (*(s32 *)(D_001D52FC[0] + 0x1C4) & 0x80) {
        func_L01_00517748((void *)func_L01_0048EE70());
        func_L01_00516090(a0);
    }
}
