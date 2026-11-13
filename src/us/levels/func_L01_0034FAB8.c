#include "common.h"

/* localdecomp:start func_L01_0034FAB8 */
extern s32 D_L01_001DD4DC;
__asm__(".extern D_L01_001DD4DC, 4");
extern s32 D_L01_001D6694_0034FAB8;
__asm__(".extern D_L01_001D6694_0034FAB8, 4");
extern s32 D_L01_001DD4E8;
__asm__(".extern D_L01_001DD4E8, 4");
extern s32 D_L01_001DD4EC;
__asm__(".extern D_L01_001DD4EC, 4");
extern u8 *D_001D52FC;
extern u8 D_001A4BE0[];
extern void func_L01_0034FB78(u8 *);
extern s32 func_0039FE80(s32, s32, u8 *);

void func_L01_0034FAB8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 held;
    func_L01_0034FB78(a0);
    if (D_L01_001DD4DC != 0 && D_L01_001D6694_0034FAB8 == 0) {
        u8 *hero = D_001A4BE0;
        held = *(s32 *)(D_001D52FC + 0x1A4);
        if ((held & *(s32 *)(hero + 0x1210)) != 0 && D_L01_001DD4E8 != 1 && D_L01_001DD4E8 != 2 &&
            *(u8 *)(hero + 0x25ED) == 0 && (held & 8) == 0) {
            *(s32 *)(p + 0x2C) = 0;
            func_0039FE80(3, 0, a0);
            D_L01_001DD4E8 = 1;
            D_L01_001DD4EC = 0x2D;
            *(s32 *)(p + 0x24) = 0x2D;
        }
    }
}
/* localdecomp:end func_L01_0034FAB8 */

