#include "common.h"

/* NTSC-U counterpart of func_L39_005FB7D0 (src/levels/shared/L39_005FB708.c) */
extern s32 D_L39_0024CBB4;
extern void func_L39_005F9038(s32, s32, s32, s32, s32);

/* localdecomp:start func_L39_005F9038 */
extern s32  D_L39_0024CBB0;
extern s32  D_L39_0024CBC4;
extern s32  D_L39_0024CBB4;
extern s32  D_L39_0024CBB8;
extern s32  D_L39_0024CBBC;
extern s32 D_L39_0024CBC0 __attribute__((section(".sdata")));
extern u8 D_L39_001FE1A0[];
extern s16 D_L39_00225828[];
extern void func_001264E0(s32 a);
extern void func_00194CB8(s32 a, s32 b, s32 c, s32 d, s32 e);
extern void func_L39_00589460(s32 a);
extern void func_L39_005994D8(void);
extern void func_L39_005BFDC8(void);
extern void func_L39_005F1248(void);

/* from rac2-decomp's func_002F5E20 */
void func_L39_005F9038(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    u8 *p;
    p = D_L39_001FE1A0;
    p[0x43] = p[0x43] | 8;
    func_00194CB8(2, 0, 0, 0, 0);
    func_001264E0(0);
    func_L39_005F1248();
    func_L39_005BFDC8();
    D_L39_0024CBB0 = arg0;
    D_L39_0024CBC4 = (s32) D_L39_00225828[0];
    D_L39_0024CBB4 = arg1;
    D_L39_0024CBB8 = arg2;
    D_L39_0024CBBC = arg3;
    D_L39_0024CBC0 = arg4;
    func_L39_00589460(4);
    func_L39_005994D8();
}
/* localdecomp:end func_L39_005F9038 */
