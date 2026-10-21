/* US draft of func_003BE448 (rac3-uya-decomp func_003B8F50, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */

/* localdecomp:start func_003BE448 */
__asm__(".extern D_001D8D28_003BE448, 4");
__asm__(".extern D_001D8D40_003BE448, 4");
extern s32 D_001DA2D0_003BE448;
extern u8 D_001DA2D4_003BE448;
extern s32 D_001DA2D8_003BE448;
extern s32 D_001DA2DC_003BE448;
extern s32 D_001D8D28_003BE448;
extern s32 D_001D8D40_003BE448;
extern u8 D_001D8D2C_003BE448[8];
extern u8 D_001D8D44_003BE448[8];
extern s32 D_002FCDC4[];
extern void func_003BBA08(s32, s32);
extern void func_003BC408();
extern void func_003BDCB0(s32, s32 *, s32);
extern s32 func_003BDD38();
extern void func_003BDE20();
extern void func_003BE308();
extern void func_003BE528();
extern void func_003BE590();
s32 func_003BE448(s32 a) {
    D_001DA2D0_003BE448 = a;
    D_001DA2D4_003BE448 = 0;
    D_001DA2D8_003BE448 = 0;
    D_001DA2DC_003BE448 = 0;
    *(u8 *)0x1DA380 = 0;
    func_003BBA08(0, 0);
    switch (D_001DA2D0_003BE448) {
    case 0:
        func_003BC408(4, &D_001D8D28_003BE448);
        func_003BDCB0(3, (s32 *)D_001D8D2C_003BE448, D_001D8D28_003BE448);
        break;
    case 1:
        func_003BC408(4, &D_001D8D40_003BE448);
        func_003BDCB0(3, (s32 *)D_001D8D44_003BE448, D_001D8D40_003BE448);
        break;
    }
    func_003BDE20(func_003BDD38());
    func_003BE308(func_003BE528);
    D_002FCDC4[0] = (s32)func_003BE590;
    return 1;
}
/* localdecomp:end func_003BE448 */
