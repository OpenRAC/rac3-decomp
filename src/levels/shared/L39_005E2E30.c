#include "common.h"

struct S { char pad[0x164]; int a; int b; };

/* localdecomp:start func_L39_005E2E30 */
extern s32 D_001D82DC_sda;
extern s32 D_001D82E4_sda;
extern s32 D_002403F8;
__asm__(".extern D_002403F8, 16");
extern void func_L01_00480A98(void);
extern void func_L39_005A5DE0(void (*)(void), s32, s32);
extern void func_L39_005E31D8(void);
extern void func_L39_005E3618(void);
extern void func_L01_003119D8(void);
extern void func_195008(s32);

void func_L39_005E2E30(void) {
    switch (D_001D82DC_sda) {
    case 0:
        func_L39_005A5DE0(func_L01_00480A98, 0, 0);
        func_L39_005E31D8();
        D_001D82E4_sda = 30;
        D_001D82DC_sda++;
        break;
    case 1:
        func_L39_005E31D8();
        {
        s32 t = D_001D82E4_sda;
        if (t > 0) {
            t--;
            D_001D82E4_sda = t;
        }
        D_001D82E4_sda = t;
        if (t == 0) {
            func_L39_005E3618();
        }
        }
        break;
    case 2:
        if (D_002403F8 == 1 || D_002403F8 == 18) {
            func_195008(1);
        }
        func_L01_003119D8();
        break;
    }
}
/* localdecomp:end func_L39_005E2E30 */

/* localdecomp:start func_L39_005E2F10 */
extern struct S D_001A43E0;
void func_L39_005E2F10(void)
{
    if (D_001A43E0.a < 0) {
        D_001A43E0.b = 0;
        D_001A43E0.a = 0x20;
    }
}
/* localdecomp:end func_L39_005E2F10 */
