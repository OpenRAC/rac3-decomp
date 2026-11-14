#include "common.h"

/* NTSC-U counterpart of func_L39_0067CF68 (src/levels/39_multiplayer_menu/L39_0067CF68.c) */
/* localdecomp:start func_L39_0067A458 */
/* best: 201 diff with file flags; 25 diff with --mode S --as ps2as. File flags put 0.7f/0.4f etc. in a $gp literal pool where retail builds them inline with lui/ori (li.s), so it looks like a flags question. Under mode S/ps2as the rest differs only in $v0 vs $v1 choice (retail never uses $v0 after the func_0037DF98 call: its result is stored to 0x18($sp) later), the slti/bnez register in loop 2, and sb to D_L39_00247B94 via $at vs $v0 at the end. */
__asm__(".extern D_001DB154_sda_0067A458, 4");
__asm__(".extern D_001DB158_sda, 4");
__asm__(".extern D_001DB134_sda, 4");
extern void func_L39_0067E8D8(void);
extern void func_0038DA28(s32, s32, s32);
extern char *func_0037DF98(s32);
extern s32 func_L39_00679350(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, char *, s32, s32, s32, s32, f32);
extern s32 func_L01_00481220(s32);
extern void func_L39_0067C270(unsigned int);
extern s32 func_003E30C8(s32, s32);
extern s32 func_003DFE10(s32);
extern s32 func_L01_00512C88(s32, s32, s32);
extern s32 func_L01_00512AB0(s32, s32, s32);
extern s32 func_L01_00512FE8(s32 id, s32 v);
extern s32 func_003E3DF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E2DE0(s32, s32);
extern s32 func_003E3BD0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_005131A0(s32, s32);
extern s32 func_003E3D08(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003DFCA8(s32);
extern s32 func_L01_00512480(s32, f32, f32);
extern s32 func_L01_00513548(s32, f32, f32);
extern s32 func_L01_005130C8(s32, s32);
extern s32 func_003E3988(s32, s32, s32, f32, f32, f32, f32, f32);
extern u8 D_001A5A47[];
extern u8 D_L39_0036FE40[];
extern u8 D_L39_00370D40[];
extern u8 D_L39_00247B94;
extern f32 D_001DB154_sda_0067A458 __attribute__((section(".sdata")));
extern f32 D_001DB158_sda __attribute__((section(".sdata")));
extern s32 D_001DB134_sda __attribute__((section(".sdata")));

void func_L39_0067A458(void) {
    s32 i;
    u8 *p;

    func_L39_0067E8D8();
    func_0038DA28(0, 0, 0);
    func_L39_00679350(0, 0x450001, 0x450002, 0x450003, 0x450000, 0x450004, 0x450005, 0x450006,
                      0x450007, 0x450008, 0x450009, func_0037DF98(0x1000), 0x45000A, 0x124,
                      0x45000B, 0x177, 9.0f);
    func_L01_00481220(0x45000D);
    func_L39_0067C270(D_001A5A47[0]);
    func_003E30C8(0x450000, 0x45000D);
    p = D_L39_0036FE40;
    for (i = 0x45000E; i <= 0x45001C; i++) {
        func_003DFE10(i);
        func_003E30C8(0x45000D, i);
        func_L01_00512C88(i, 1, 3);
        func_L01_00512AB0(i, 1, 0);
        *p = 0;
        func_L01_00512FE8(i, (s32)p);
        p += 0x100;
    }
    func_L01_00481220(0x45001D);
    func_003E3DF0(0x45001E, 0, 0x80FFFFFF, 0.5f, 0.5f, 0.7f, 0.4f, 1.0f);
    func_003E30C8(0x45001D, 0x45001E);
    func_003E2DE0(1, 0x45001D);
    func_L01_00512FE8(0x45001E, (s32)D_L39_00370D40);
    func_003E3BD0(0x45000C, 0x80808080, 0, 0.5f, 0.5f, D_001DB154_sda_0067A458, D_001DB158_sda);
    func_L01_005131A0(0x45000C, 0xED5C);
    func_003E30C8(0x450000, 0x45000C);
    func_L01_00481220(0x450026);
    func_003E30C8(0x450000, 0x450026);
    func_L01_00512AB0(0x450026, 1, 0);
    func_003E3D08(0x45001F, 0x332299DE, 0.5f, 0.5f, 0.82f, 0.5f, 0.004f, 0.005f);
    func_L01_00512AB0(0x45001F, 1, 1);
    func_003E30C8(0x450026, 0x45001F);
    for (i = 0; i < 3; i++) {
        func_003DFCA8(i + 0x450020);
        func_L01_00512AB0(i + 0x450020, 1, 1);
        func_L01_00512C88(i + 0x450020, 3, 3);
        func_L01_00512480(i + 0x450020, 0.5f, 0.5f);
        func_L01_00513548(i + 0x450020, 0.8f, 0.004f);
        func_L01_005130C8(i + 0x450020, 0x332299DE);
        func_003E30C8(0x450026, i + 0x450020);
    }
    func_003E3988(0x450024, 0x80, 0x332299DE, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f);
    func_L01_00512AB0(0x450024, 1, 1);
    func_003E30C8(0x450026, 0x450024);
    func_003E3988(0x450025, 0x80, 0x332299DE, 0.5f, 0.5f, 1.0f, -1.0f, 0.5f);
    func_L01_00512AB0(0x450025, 1, 1);
    func_003E30C8(0x450026, 0x450025);
    func_003DFCA8(0x450023);
    func_L01_00512AB0(0x450023, 1, 1);
    func_L01_00512C88(0x450023, 3, 3);
    func_003E30C8(0x450026, 0x450023);
    D_L39_00247B94 = 0;
    D_001DB134_sda = 1;
}
/* localdecomp:end func_L39_0067A458 */
