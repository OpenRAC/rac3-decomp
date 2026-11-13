#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_003C4F88);

INCLUDE_ASM("asm/levels", func_L05_003C6080);

INCLUDE_ASM("asm/levels", func_L05_003C63A8);

/* localdecomp:start func_L05_003C66F0 */
extern void func_L01_004443E8(void *, s32, s32);
extern void func_L01_00452310(void *m, s32 a, void *b, s32 c, s32 d, f32 x0, f32 x1, f32 x2,
                              f32 x3, f32 x4, u8 e, f32 x5, f32 x6, s32 f, s32 g);
extern void func_L01_00459C50(s32);
extern s32 D_001D545C;
extern s32 D_L05_001D67BC;
extern u8 D_L05_001D66B0[8];

void func_L05_003C66F0(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    if (D_001D545C == 0x11 && (pv[0x60] != 0 || pv[0x47] == 0x87)) {
        D_L05_001D67BC = D_L05_001D67BC + 1;
        if (D_L05_001D67BC >= 0x28) {
            func_L01_00459C50(0x13);
        }
    }
    func_L01_004443E8(a0, 0, 3);
    func_L01_00452310(a0, 0x3FFF, D_L05_001D66B0, 1, 0x28, -1.0f, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0);
}
/* localdecomp:end func_L05_003C66F0 */

INCLUDE_ASM("asm/levels", func_L05_003C67C0);
