#include "common.h"

/* localdecomp:start func_L39_005ABE58 */
/* from rac2-decomp's func_002A0180 */
extern void func_001264E0(s32);
extern u8 D_L39_0047FB60[];
extern void *D_L39_0024BB70;
__asm__(".extern D_L39_0024BB70, 12");
extern s32 D_L39_0024BB78;
extern void func_003CB300(void *, s32);
extern void func_0038CD28(void *, void *, s32);

void func_L39_005ABE58(void) {
    func_001264E0(0);
    func_0038CD28((void *)0x70003800, D_L39_0047FB60, 0x800);
    func_003CB300(D_L39_0024BB70, D_L39_0024BB78);
}
/* localdecomp:end func_L39_005ABE58 */
