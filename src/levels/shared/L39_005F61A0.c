#include "common.h"

/* localdecomp:start func_L39_005F61A0 */
extern void func_003A9440(s32, unsigned long);
extern void func_001264E0(s32);
extern void func_003D9E28(void);
extern void func_003D9C00(void);
extern void func_003DCEA0(void);
extern void func_003DAD90(void);
extern void func_003DC160(void);
extern void func_003A8F90(void *);
extern void func_0038CD28(void *, void *, s32);
extern u8 D_001159B0[];
extern u8 D_00100AE0[];
extern s32 D_001D4BE0;
extern s32 D_L39_002402F4;
extern u8 *D_L39_0024CAD0;
extern u8 D_L39_002446E0[];

void func_L39_005F61A0(void)
{
    func_003A9440(0x47, 0x5340B);
    D_001D4BE0 = D_L39_002402F4;
    func_001264E0(0);
    func_003D9E28();
    func_003D9C00();
    func_001264E0(0);
    func_003DCEA0();
    func_003A8F90(D_001159B0);
    func_003DAD90();
    func_003DC160();
    func_003A8F90(D_00100AE0);
    func_0038CD28(D_L39_0024CAD0, D_L39_002446E0, 0x20);
    D_L39_0024CAD0 += 0x20;
}
/* localdecomp:end func_L39_005F61A0 */
