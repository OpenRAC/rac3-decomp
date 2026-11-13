#include "common.h"

/* localdecomp:start func_L01_0048DC28 */
extern s32 D_001D5520 __attribute__((section(".data")));
extern s32 D_001D5520_sda;
extern s32 D_L01_001D8D9C;
extern s32 D_L01_001D8DC8;
extern char D_L01_002EAF78[];
extern void func_003B0F58(void);
extern s32 func_0037DF98(s32);
extern void func_0011B2E8(char *, s32, s32);
extern s32 func_003B4220(s32, s32, s32, s32, s32);
extern void func_003B41F8(s32, s32);

void func_L01_0048DC28(s32 pad) {
    s32 a;
    s32 b;
    if (pad & 0xA040) {
        if (D_001D5520 != 0) {
            D_001D5520_sda = !D_001D5520;
            func_003B0F58();
        } else {
            func_0011B2E8(D_L01_002EAF78, func_0037DF98(0x50A), D_L01_001D8D9C);
            b = func_0037DF98(0x8E2);
            a = func_0037DF98(0x8DF);
            func_003B4220(0, b, a, (s32)D_L01_002EAF78, 0);
            func_003B41F8(0x40, 0x10);
            D_L01_001D8DC8 = 1;
        }
    }
}
/* localdecomp:end func_L01_0048DC28 */
