/* functional: high. Ported from the NTSC-U draft (nonmatching/levels/func_L01_00499CD8.c) re-read against PAL asm: PAL differences are the callee addresses, the three table addresses (D_L01_002EB9C0/EBAD0/EBA78), func_003E87B8(...,1,8) where NTSC had 10, and the gp slots (D_L01_001D92E8 table pointer, D_L01_001D92EC count). Compiles at level_01, 65 diff. */

extern u8 D_001439F4[];
extern u8 D_L01_002EB9C0[];
extern u8 D_L01_002EBAD0[];
extern u8 D_L01_002EBA78[];
extern u8 D_L01_002EBB48[];
extern E_496DC0 *D_L01_001D92E8;
extern s32 D_L01_001D92EC;
extern char D_L01_001D9330[];
extern void func_L01_0049A2F0(void);
extern void func_L01_0049A348(void);
extern void func_0038E150(s32);
extern void func_L01_0049A748(s32, f32 *, f32 *);
extern s32 func_00381FF0(s32);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00516FD8(s32, char *);
extern void func_L01_0049A010(void *);
extern void func_L01_00517538(s32, f32, f32);
extern s32 func_003E8348(s32, s32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_003B42F8(s32);
extern s32 func_003E8710(s32, s32);
extern s32 func_L01_00517190(s32, s32);
extern void func_L01_00516D60(s32, s32);
extern s32 func_003E87B8(s32, s32, s32);
extern void func_L01_00517BF8(s32, s32, s32, s32, s32, s32);
extern void func_L01_00517DB8(s32, s32, s32, f32);
extern void func_L01_00517D18(s32);

void func_L01_00499CD8(void) {
    f32 a;
    f32 b;
    s32 msg;

    a = 1.0f;
    b = 0.0f;
    switch (D_001439F4[0]) {
    case 0:
        D_L01_001D92EC = 14;
        D_L01_001D92E8 = (E_496DC0 *)D_L01_002EB9C0;
        break;
    case 1:
        D_L01_001D92EC = 9;
        D_L01_001D92E8 = (E_496DC0 *)D_L01_002EBAD0;
        break;
    case 2:
        D_L01_001D92EC = 6;
        D_L01_001D92E8 = (E_496DC0 *)D_L01_002EBA78;
        break;
    }
    func_L01_0049A2F0();
    func_L01_0049A348();
    func_0038E150(0);
    func_L01_0049A748(0x113, &a, &b);
    msg = func_00381FF0(0x113);
    func_003B9298(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, b, 0xD0008, msg, 0xD0006, 0x124, 0xD0007, 0xCD5);
    func_L01_00516FD8(0xD0006, D_L01_001D9330);
    func_L01_0049A010(D_L01_002EBB48);
    func_L01_00517538(0xD0005, a, a);
    func_003E8348(0x11, 0x4B0000);
    func_003E7F20(0x4B0005, 1);
    func_003E7F20(0x4B0006, 1);
    func_003E8710(0x4B0009, func_003B42F8(0));
    func_L01_00517190(0x4B0009, 0);
    func_L01_00516D60(0x4B0009, 0);
    func_003E87B8(0x4B0009, 1, 8);
    func_L01_00517BF8(0x4B0006, 1, 1, 1, 0, 0);
    func_L01_00517DB8(0x4B0006, 0x78, 0, 0.0005f);
    func_L01_00517D18(0x4B0006);
}
