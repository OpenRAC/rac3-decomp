#include "common.h"

/* NTSC-U counterpart of func_L01_0047E738 (src/levels/shared/L01_0047DBB0.c): 1500 -> 1800 */
typedef struct {
    u8 pad0[0x1C0];
    s32 w1C0;
    s32 w1C4;
} S_0047E680;
extern S_0047E680 *D_001D52FC;
extern u8 D_L01_001D672E_0047AED8b;
extern s32 func_0039EE68(void);
extern S_0047E680 *D_001D52FC;

/* localdecomp:start func_L01_0047AED8 */
extern void func_L01_00475040(void);
extern void func_L01_00475078(s32);
extern s32 func_0039EE68(void);
extern void func_L01_0047A240_0047AED8(void);
extern S_0047E680 *D_001D52FC;
extern s32 D_L01_001D8250;
extern u8 D_L01_001D672E_0047AED8;
extern u8 D_L01_001D672E_0047AED8b;
extern u32 D_001D4CEC;
__asm__(".extern D_L01_001D8250, 4");
__asm__(".extern D_L01_001D672E_0047AED8, 4");

void func_L01_0047AED8(void) {
    s32 n;

    func_L01_0047AE20();
    func_L01_00475040();
    func_L01_00475078(0);
    func_0039EE68();
    n = *(s32 *)((u8 *)D_001D52FC + 0x1A0);
    if (n != 0) {
        n = 0x708;
        D_L01_001D8250 = n;
    }
    D_L01_001D8250--;
    if (D_L01_001D8250 <= 0) {
        D_L01_001D8250 = 0;
        D_L01_001D672E_0047AED8 = 1;
    } else {
        D_L01_001D672E_0047AED8b = 0;
    }
    if (D_001D4CEC & 1) {
        func_L01_0047A240_0047AED8();
    }
}
/* localdecomp:end func_L01_0047AED8 */
