#include "common.h"

/* localdecomp:start func_L03_003A2F18 */
extern u8 *D_L03_001DE560;
__asm__(".extern D_L03_001DE560, 4");
extern u8 D_001A4BE0[];
extern u8 D_00142660[];
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_L01_004180F8(void);
extern void func_00385B60(s32);
extern void func_L01_00422BD0(s16);
extern void func_003BD360(s32);

void func_L03_003A2F18(u8 *a0) {
    s32 a;
    u16 h;
    u8 *hero;
    u8 *tab;
    if (a0[0x20] == 0) {
        D_L03_001DE560 = a0;
        func_L01_00441FB8(a0, 1, -1);
    }
    if (a0[0x20] == 2) {
        func_L01_004180F8();
        func_00385B60(0x10);
        hero = D_001A4BE0;
        if (*(s32 *)(hero + 0x234) != 0) {
            tab = D_00142660;
            h = *(u16 *)(tab + 0x78);
            *(u16 *)(tab + 0x40) = h;
            func_L01_00422BD0(h);
            a = *(s32 *)(hero + 0x28CC);
            hero[0x28C9] = 0;
            if (a != 0) {
                func_003BD360(a);
                *(s32 *)(hero + 0x28CC) = 0;
            }
        }
        D_001A4BE0[0x25F2] = 1;
        func_L01_00441FB8(a0, 1, -1);
    }
}
/* localdecomp:end func_L03_003A2F18 */
