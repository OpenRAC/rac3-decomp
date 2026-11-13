#include "common.h"

/* declared by functions of L39_005DED10.c, which this file was cut from */
extern void func_L01_00516AA0(int, int, int);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L39_005DEDD8(void);

/* localdecomp:start func_L39_005DF060 */
/* log: callee alias func_L01_004D2110_005DF060 (stub is another copy in levels 40+). */
/* log: id local = 10 diff (s0 for temp); inline i + 0x6xxxx at each use = MATCH with --as ps2as (float constants inline, file needs @ps2as) */
extern u8 D_001D821C_sda;
extern void func_L01_004D2110_005DF060(s32);
extern void func_L01_00484A80(s32);
extern s32 func_003B5060(s32);
extern s32 func_003E5360(s32);
extern s32 func_00381FF0(s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern void func_003E6FF0(s32, s32);
extern void func_L39_005DEDD8(void);
void func_L39_005DF060(s32 a0) {
    s32 i;
    s32 id;
    D_001D821C_sda = 1;
    func_L01_004D2110_005DF060(1);
    func_L01_00484A80(0x60000);
    func_003B5060(0x60001);
    func_003B5060(0x60002);
    func_003B5060(0x60003);
    func_003B5060(0x60004);

    func_003E5360(0x60005);
    func_L01_00516AA0(0x60005, 1, 0);
    func_L01_00516AA0(0x60005, 0x40, 1);
    func_L01_00516AA0(0x60005, 0x2000, 1);
    func_L01_00516FD8(0x60005, func_00381FF0(0x1332));
    func_L01_005170B8(0x60005, 0x8066CCFF);
    func_L01_00516470(0x60005, 0.28f, 0.25f);
    func_003E8630(0x60001, 0x60005);

    func_003E5360(0x60006);
    func_L01_00516AA0(0x60006, 1, 0);
    func_L01_00516AA0(0x60006, 0x40, 1);
    func_L01_00516AA0(0x60006, 0x2000, 1);
    func_L01_00516FD8(0x60006, func_00381FF0(0x1336));
    func_L01_005170B8(0x60006, 0x8066CCFF);
    func_L01_00516470(0x60006, 0.62f, 0.25f);
    func_003E8630(0x60001, 0x60006);

    func_003E5360(0x60007);
    func_L01_00516AA0(0x60007, 1, 0);
    func_L01_00516AA0(0x60007, 0x40, 1);
    func_L01_00516AA0(0x60007, 0x2000, 1);
    func_L01_00516FD8(0x60007, func_00381FF0(0x1337));
    func_L01_005170B8(0x60007, 0x8066CCFF);
    func_L01_00516470(0x60007, 0.83f, 0.25f);
    func_003E8630(0x60001, 0x60007);

    for (i = 0; i < 16; i++) {
        func_003E5360(i + 0x60008);
        func_L01_00516AA0(i + 0x60008, 1, 0);
        func_L01_00516AA0(i + 0x60008, 0x40, 1);
        func_L01_00516AA0(i + 0x60008, 0x2000, 1);
        func_L01_005170B8(i + 0x60008, 0x8066CCFF);
        func_003E8630(0x60002, i + 0x60008);

        func_003E5360(i + 0x60018);
        func_L01_00516AA0(i + 0x60018, 1, 0);
        func_L01_00516AA0(i + 0x60018, 0x40, 1);
        func_L01_00516AA0(i + 0x60018, 0x2000, 1);
        func_L01_005170B8(i + 0x60018, 0x8066CCFF);
        func_003E8630(0x60003, i + 0x60018);

        func_003E5360(i + 0x60028);
        func_L01_00516AA0(i + 0x60028, 1, 0);
        func_L01_00516AA0(i + 0x60028, 0x40, 1);
        func_L01_00516AA0(i + 0x60028, 0x2000, 1);
        func_L01_005170B8(i + 0x60028, 0x8066CCFF);
        func_003E8630(0x60004, i + 0x60028);
    }

    func_003E5360(0x60038);
    func_L01_00516AA0(0x60038, 1, 0);
    func_L01_00516AA0(0x60038, 0x40, 1);
    func_L01_00516FD8(0x60038, func_00381FF0(0x12A5));
    func_L01_005170B8(0x60038, 0x8066CCFF);
    func_L01_00516470(0x60038, 0.5f, 0.8438f);
    func_003E8630(0x60001, 0x60038);

    func_003E8630(0x60000, 0x60001);
    func_003E8630(0x60000, 0x60002);
    func_003E8630(0x60000, 0x60003);
    func_003E8630(0x60000, 0x60004);
    func_003E8348(0x18, 0x60000);
    func_003E6FF0(a0, 1);
    func_L39_005DEDD8();
    func_L01_004D2110_005DF060(0);
}
/* localdecomp:end func_L39_005DF060 */

INCLUDE_ASM("asm/levels", func_L39_005DF510);

INCLUDE_ASM("asm/levels", func_L39_005DF8F8);
