#include "common.h"

typedef struct { int a, b, c; } T;

/* declared by functions of L39_0067A788.c, which this file was cut from */
extern void func_L39_00595628(u8 *, u8 *);

/* localdecomp:start func_L39_0067CF68 */
/* best: 201 diff with file flags; 25 diff with --mode S --as ps2as. File flags put 0.7f/0.4f etc. in a $gp literal pool where retail builds them inline with lui/ori (li.s), so it looks like a flags question. Under mode S/ps2as the rest differs only in $v0 vs $v1 choice (retail never uses $v0 after the func_00381FF0 call: its result is stored to 0x18($sp) later), the slti/bnez register in loop 2, and sb to D_L39_00247A34 via $at vs $v0 at the end. */
__asm__(".extern D_001DB174_sda, 4");
__asm__(".extern D_001DB178_sda, 4");
__asm__(".extern D_001DB154_sda, 4");
extern void func_L39_006813F8(void);
extern void func_00392260(s32, s32, s32);
extern char *func_00381FF0(s32);
extern s32 func_L39_0067BE08(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, char *, s32, s32, s32, s32, f32);
extern s32 func_L01_00484A80(s32);
extern void func_L39_0067ED90(unsigned int);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E5360(s32);
extern s32 func_L01_00516C78(s32, s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516FD8(s32 id, s32 v);
extern s32 func_003E9358(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E8348(s32, s32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E51F8(s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern u8 D_001A58C7[];
extern u8 D_L39_0036FD40[];
extern u8 D_L39_00370C40[];
extern u8 D_L39_00247A34;
extern f32 D_001DB174_sda __attribute__((section(".sdata")));
extern f32 D_001DB178_sda __attribute__((section(".sdata")));
extern s32 D_001DB154_sda __attribute__((section(".sdata")));

void func_L39_0067CF68(void) {
    s32 i;
    u8 *p;

    func_L39_006813F8();
    func_00392260(0, 0, 0);
    func_L39_0067BE08(0, 0x450001, 0x450002, 0x450003, 0x450000, 0x450004, 0x450005, 0x450006,
                      0x450007, 0x450008, 0x450009, func_00381FF0(0x1000), 0x45000A, 0x124,
                      0x45000B, 0x177, 9.0f);
    func_L01_00484A80(0x45000D);
    func_L39_0067ED90(D_001A58C7[0]);
    func_003E8630(0x450000, 0x45000D);
    p = D_L39_0036FD40;
    for (i = 0x45000E; i <= 0x45001C; i++) {
        func_003E5360(i);
        func_003E8630(0x45000D, i);
        func_L01_00516C78(i, 1, 3);
        func_L01_00516AA0(i, 1, 0);
        *p = 0;
        func_L01_00516FD8(i, (s32)p);
        p += 0x100;
    }
    func_L01_00484A80(0x45001D);
    func_003E9358(0x45001E, 0, 0x80FFFFFF, 0.5f, 0.5f, 0.7f, 0.4f, 1.0f);
    func_003E8630(0x45001D, 0x45001E);
    func_003E8348(1, 0x45001D);
    func_L01_00516FD8(0x45001E, (s32)D_L39_00370C40);
    func_003E9138(0x45000C, 0x80808080, 0, 0.5f, 0.5f, D_001DB174_sda, D_001DB178_sda);
    func_L01_00517190(0x45000C, 0xED5C);
    func_003E8630(0x450000, 0x45000C);
    func_L01_00484A80(0x450026);
    func_003E8630(0x450000, 0x450026);
    func_L01_00516AA0(0x450026, 1, 0);
    func_003E9270(0x45001F, 0x332299DE, 0.5f, 0.5f, 0.82f, 0.5f, 0.004f, 0.005f);
    func_L01_00516AA0(0x45001F, 1, 1);
    func_003E8630(0x450026, 0x45001F);
    for (i = 0; i < 3; i++) {
        func_003E51F8(i + 0x450020);
        func_L01_00516AA0(i + 0x450020, 1, 1);
        func_L01_00516C78(i + 0x450020, 3, 3);
        func_L01_00516470(i + 0x450020, 0.5f, 0.5f);
        func_L01_00517538(i + 0x450020, 0.8f, 0.004f);
        func_L01_005170B8(i + 0x450020, 0x332299DE);
        func_003E8630(0x450026, i + 0x450020);
    }
    func_003E8EF0(0x450024, 0x80, 0x332299DE, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f);
    func_L01_00516AA0(0x450024, 1, 1);
    func_003E8630(0x450026, 0x450024);
    func_003E8EF0(0x450025, 0x80, 0x332299DE, 0.5f, 0.5f, 1.0f, -1.0f, 0.5f);
    func_L01_00516AA0(0x450025, 1, 1);
    func_003E8630(0x450026, 0x450025);
    func_003E51F8(0x450023);
    func_L01_00516AA0(0x450023, 1, 1);
    func_L01_00516C78(0x450023, 3, 3);
    func_003E8630(0x450026, 0x450023);
    D_L39_00247A34 = 0;
    D_001DB154_sda = 1;
}
/* localdecomp:end func_L39_0067CF68 */
