/* PAL near miss (b8-s4): 5 differences, all the lui order of the two core globals: retail loads D_001D5475 (lui $a0, lbu) first and then D_001D4BA0 (lui $v0, lw); this C hoists both lui before the loads. Both are unsized arrays (lui access); the test written either way gives the same bytes. Matches at level 1 otherwise (the 14 other words). About 6 compiles.
 */
#include "common.h"
/* localdecomp:start func_L01_004809E8 */
extern void func_L01_00517918(s32);
extern s32 func_L01_00498610(s32);
extern s32 func_L01_004989C0(s32);
extern u8 *func_L01_00494160(s32);
extern void func_L01_0045FDF0(s32);
extern void func_L01_0047F018(s32);
extern void func_L01_00425FE0(void);
extern void func_L01_003F1E98(s32);
extern s32 D_L01_001D8318;
extern u8 D_001D5475[];
extern s32 D_001D4BA0[];

void func_L01_004809E8(void) {
    u8 *o;
    func_L01_00517918(0x10);
    func_L01_00517918(0x11);
    func_L01_004989C0(func_L01_00498610(0));
    o = func_L01_00494160(0);
    (*(void (**)(u8 *))(*(u8 **)(o + 4) + 0xC))(o);
    func_L01_0045FDF0(1);
    func_L01_0047F018(D_L01_001D8318);
    if (D_001D5475[0] != D_001D4BA0[0]) {
        func_L01_00425FE0();
    }
    func_L01_0045FDF0(1);
    func_L01_003F1E98(0);
}
/* localdecomp:end func_L01_004809E8 */
