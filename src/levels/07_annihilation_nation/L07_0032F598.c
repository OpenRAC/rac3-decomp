#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_0032F598);

INCLUDE_ASM("asm/levels", func_L07_0032F988);

INCLUDE_ASM("asm/levels", func_L07_0032FDC8);

INCLUDE_ASM("asm/levels", func_L07_003303B0);

INCLUDE_ASM("asm/levels", func_L07_003304C0);

INCLUDE_ASM("asm/levels", func_L07_00330748);

INCLUDE_ASM("asm/levels", func_L07_00330828);

INCLUDE_ASM("asm/levels", func_L07_003309A0);

INCLUDE_ASM("asm/levels", func_L07_00330AA0);

/* localdecomp:start func_L07_00330F30 */
extern u8 D_001426E0[];
extern u8 D_001A74A9[];
extern s32 D_00142848[];
extern void func_L01_003F1760(void);
extern void func_L01_004450F0(void *, s32, s32);
void func_L07_00330F30(u8 *arg0) {
    D_001A74A9[0] = 0;
    if (D_001426E0[0xE3] != 0) {
        D_00142848[0] = D_001426E0[0xE3] - 1;
        D_001426E0[0xE3] = 0;
    }
    func_L01_003F1760();
    func_L01_004450F0(arg0, 8, -1);
}
/* localdecomp:end func_L07_00330F30 */

/* localdecomp:start func_L07_00330F98 */
extern void func_L07_003328D0(s32);
extern void func_L01_004AA760(s32, s32);
extern void func_L01_004596E8(s32, void (*)(void));
extern void func_L07_00331890(s32);
extern void func_L07_003332B8(void);
extern s32 D_L07_001D7B20;

void func_L07_00330F98(s32 arg0) {
    void (*deflt)(void);

    func_L07_003328D0(arg0);
    func_L01_004AA760(0, arg0);
    func_L01_004AA760(1, arg0);
    func_L01_004AA760(2, arg0);
    deflt = func_L07_003332B8;
    D_L07_001D7B20 = -1;
    func_L01_004596E8(0, deflt);
    func_L07_00331890(arg0);
}
/* localdecomp:end func_L07_00330F98 */

INCLUDE_ASM("asm/levels", func_L07_00331008);

/* localdecomp:start func_L07_003310E8 */
extern s32 *func_L07_00333918(void *);

void func_L07_003310E8(u8 *arg0, void *arg1) {
    s32 *r = func_L07_00333918(arg1);

    if (*(u8 *)((u8 *)r + 0x1C) == 1) {
        s16 *q = (s16 *)(*(s32 *)(arg0 + 0x68) + 0x90);
        s16 *p = q + *(u8 *)((u8 *)r + 0x1D);

        if (*p != -1) {
            *p += 1;
        }
    }
    *(u8 *)((u8 *)r + 0x1C) = 0;
}
/* localdecomp:end func_L07_003310E8 */

INCLUDE_ASM("asm/levels", func_L07_00331158);

/* localdecomp:start func_L07_00331288 */
extern void func_L07_003312E8(s32, s32);

void func_L07_00331288(s32 a0)
{
    s32 i;

    for (i = 0; i < 6; i++) {
        if (i < 3 || i > 4) {
            func_L07_003312E8(a0, i);
        }
    }
}
/* localdecomp:end func_L07_00331288 */

INCLUDE_ASM("asm/levels", func_L07_003312E8);
