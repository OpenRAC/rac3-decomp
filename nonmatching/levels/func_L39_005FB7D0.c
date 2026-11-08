/* Ported from rac2-decomp's func_002F5E20 (a twin of this function's code), names renamed from retail's
   relocations; 1 instruction(s) still differ under this file's flags. */
extern s32  D_L39_0024CAB0;
extern s32  D_L39_0024CAC4;
extern s32  D_L39_0024CAB4;
extern s32  D_L39_0024CAB8;
extern s32  D_L39_0024CABC;
extern s32 D_001E13B0 __attribute__((section(".sdata")));
extern u8 D_001FE020[];
extern s16 D_002256A8[];
extern void func_001264E0(s32 a);
extern void func_00194BC8(s32 a, s32 b, s32 c, s32 d, s32 e);
extern void func_L39_0058A5D0(s32 a);
extern void func_L01_0041A6E0(void);
extern void func_L39_005C1E10(void);
extern void func_L39_005F3948(void);

void func_L39_005FB7D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    u8 *p;
    p = D_001FE020;
    p[0x43] = p[0x43] | 8;
    func_00194BC8(2, 0, 0, 0, 0);
    func_001264E0(0);
    func_L39_005F3948();
    func_L39_005C1E10();
    D_L39_0024CAB0 = arg0;
    D_L39_0024CAC4 = (s32) D_002256A8[0];
    D_L39_0024CAB4 = arg1;
    D_L39_0024CAB8 = arg2;
    D_L39_0024CABC = arg3;
    D_001E13B0 = arg4;
    func_L39_0058A5D0(4);
    func_L01_0041A6E0();
}