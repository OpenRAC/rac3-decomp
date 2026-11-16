#include "common.h"

/* localdecomp:start func_L03_0034AF98 */
extern s32 D_001D4CF0;
extern s32 D_001D545C;
extern void func_0039EC28(s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C2880(u8 *);
void func_L03_0034AF98(u8 *a0) {
    a0[48] = 255;
    func_0039EC28(0, D_001D4CF0);
    if (D_001D545C == 1337 || D_001D545C == 24) {
        func_L01_004450F0(a0, 1, -1);
    } else {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L03_0034AF98 */

/* localdecomp:start func_L03_0034B008 */
extern s32 func_L01_004561B8(void *);
extern void func_L01_005003D0(s32, s32);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB3C0(s32, void *);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_00392DF0(s32, s32);
extern u8 D_L03_001E24C0[];
extern u8 *D_L03_001DFA80;
extern u8 D_001427BB[];
extern u8 *D_001D52FC;

void func_L03_0034B008(u8 *a0) {
    s32 *v = *(s32 **)(a0 + 0x68);
    u16 t;
    if (func_L01_004561B8(a0) != 0) {
        *(u16 *)(a0 + 0x96) = 0;
        func_L01_005003D0(0x74, 1);
        func_L01_003EB438(0, D_L03_001E24C0, D_L03_001E24C0 + 0x10, 1, 0x64, 0);
        func_L01_003EB3C0(0, D_L03_001DFA80 + (*v << 7) + 0x70);
        func_L01_003EB350(0, D_L03_001DFA80 + (*v << 7) + 0x30);
        D_001427BB[0] = 0;
        func_0039EC28(0, 3);
    }
    t = *(u16 *)(a0 + 0x96);
    if (t < 0x64) {
        *(u16 *)(a0 + 0x96) = t + 1;
    }
    func_L01_00452560(0, 5, 0x1A5C, 1, 0, 0, 0);
    if (*(s32 *)(D_001D52FC + 0x1A4) & 0x800) {
        D_001427BB[0] = 0;
        func_00392DF0(3, 1);
    }
}
/* localdecomp:end func_L03_0034B008 */
