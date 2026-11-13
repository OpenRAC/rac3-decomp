#include "common.h"

/* localdecomp:start func_L39_0060D738 */
/* from this repo's func_003D7D30 (front end, same code) */
extern s32 func_003D6A20_0060D738(s32 *, s32);
extern void func_003D7DE8(void);
extern void func_003D8500(void);
__asm__(".extern D_L39_00241494, 16");
__asm__(".extern D_L39_002414A8, 16");
__asm__(".extern D_L39_002414AC, 16");
__asm__(".extern D_L39_00241474, 16");
extern s32 D_001D5D80_sda, D_001D5D88_sda, D_001D5D8C_sda, D_001D5D94_sda;
extern s32 D_L39_00241494, D_L39_002414A8, D_L39_002414AC, D_L39_00241474;
extern s32 D_001FC454[];
void func_L39_0060D738(void) {
    s32 p, r1, r2, r3;
    D_001D5D80_sda = 0x3FA000;
    D_L39_00241494 = 0x3FE000;
    D_L39_002414AC = 0x400000;
    p = 0x379000;
    r1 = func_003D6A20_0060D738(&p, 0x40000);
    p = 0x379000;
    D_001D5D8C_sda = r1;
    r2 = func_003D6A20_0060D738(&p, 0x40000);
    D_001D5D94_sda = r2;
    r3 = func_003D6A20_0060D738(&p, 0x40000);
    D_L39_002414A8 = r3;
    D_001D5D88_sda = D_001FC454[0];
    func_003D7DE8();
    func_003D8500();
    D_L39_00241474 = D_L39_00241474 | 1;
}
/* localdecomp:end func_L39_0060D738 */
