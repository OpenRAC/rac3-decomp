#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006CCE90);

INCLUDE_ASM("asm/levels", func_L39_006CD038);

INCLUDE_ASM("asm/levels", func_L39_006CD1B8);

INCLUDE_ASM("asm/levels", func_L39_006CD218);

INCLUDE_ASM("asm/levels", func_L39_006CD270);

INCLUDE_ASM("asm/levels", func_L39_006CD2C8);

INCLUDE_ASM("asm/levels", func_L39_006CD488);

INCLUDE_ASM("asm/levels", func_L39_006CD540);

INCLUDE_ASM("asm/levels", func_L39_006CD568);

INCLUDE_ASM("asm/levels", func_L39_006CD588);

INCLUDE_ASM("asm/levels", func_L39_006CD5F0);

/* localdecomp:start func_L39_006CD6E0 */
extern long func_12DCB0(void);
extern long func_130760(long, long);
void func_L39_006CD768(u8 *);

s32 func_L39_006CD6E0(u8 *arg0) {
    s32 result = 1;

    if (arg0[0] != 0) {
        if (arg0[8] != 0) {
            if (((s32) func_130760(func_12DCB0(), 0x24000) - *(s32 *) (arg0 + 0xC)) >= 0x3A99) {
                arg0[8] = 0;
                result = 0;
                func_L39_006CD768(arg0);
            }
        }
    }
    return result;
}
/* localdecomp:end func_L39_006CD6E0 */

INCLUDE_ASM("asm/levels", func_L39_006CD768);

INCLUDE_ASM("asm/levels", func_L39_006CD808);

INCLUDE_ASM("asm/levels", func_L39_006CDC30);

INCLUDE_ASM("asm/levels", func_L39_006CDD90);

INCLUDE_ASM("asm/levels", func_L39_006CDDB0);

INCLUDE_ASM("asm/levels", func_L39_006CDF18);

/* localdecomp:start func_L39_006CDF38 */
void func_L39_006CDF38(void *arg0) {
    *(s8 *)((u8 *)arg0 + 0x34) = 0;
    *(s8 *)((u8 *)arg0 + 0x5C) = 0;
    *(s8 *)((u8 *)arg0 + 0x64) = 0;
    *(s8 *)((u8 *)arg0 + 0x6C) = 0;
    *(s8 *)((u8 *)arg0 + 0x7C) = 0;
    *(s8 *)((u8 *)arg0 + 0x84) = 0;
    *(s8 *)((u8 *)arg0 + 0x8C) = 0;
    *(s8 *)((u8 *)arg0 + 0x94) = 0;
    *(s8 *)((u8 *)arg0 + 0x9C) = 0;
    *(s8 *)((u8 *)arg0 + 0xA4) = 0;
    *(s8 *)((u8 *)arg0 + 0xAC) = 0;
    *(s8 *)((u8 *)arg0 + 0xB4) = 0;
    *(s8 *)((u8 *)arg0 + 0xBC) = 0;
    *(s8 *)((u8 *)arg0 + 0xC4) = 0;
    *(s8 *)((u8 *)arg0 + 0xCC) = 0;
    *(s8 *)((u8 *)arg0 + 0xD4) = 0;
    *(s8 *)((u8 *)arg0 + 0x220) = 0;
    *(s8 *)((u8 *)arg0 + 0x38C) = 0;
    *(s32 *)((u8 *)arg0 + 0x3B8) = -1;
    *(s8 *)((u8 *)arg0 + 0x3BC) = 0;
    *(s32 *)((u8 *)arg0 + 0x3C0) = -1;
    *(s32 *)((u8 *)arg0 + 0x3C4) = -1;
    *(s32 *)((u8 *)arg0 + 0x3F0) = -1;
    *(s8 *)((u8 *)arg0 + 0x3F4) = 0;
    *(s32 *)((u8 *)arg0 + 0x3F8) = -1;
    *(s32 *)((u8 *)arg0 + 0x3FC) = -1;
    *(s32 *)((u8 *)arg0 + 0x428) = -1;
    *(s8 *)((u8 *)arg0 + 0x42C) = 0;
    *(s32 *)((u8 *)arg0 + 0x430) = -1;
    *(s32 *)((u8 *)arg0 + 0x434) = -1;
    *(s32 *)((u8 *)arg0 + 0x460) = -1;
    *(s8 *)((u8 *)arg0 + 0x464) = 0;
    *(s32 *)((u8 *)arg0 + 0x468) = -1;
    *(s32 *)((u8 *)arg0 + 0x46C) = -1;
    *(s32 *)((u8 *)arg0 + 0x4A0) = -1;
    *(s8 *)((u8 *)arg0 + 0x4A4) = 0;
    *(s32 *)((u8 *)arg0 + 0x4A8) = -1;
    *(s32 *)((u8 *)arg0 + 0x4AC) = -1;
    *(s32 *)((u8 *)arg0 + 0x4E0) = -1;
    *(s8 *)((u8 *)arg0 + 0x4E4) = 0;
    *(s32 *)((u8 *)arg0 + 0x4E8) = -1;
    *(s32 *)((u8 *)arg0 + 0x4EC) = -1;
    *(s32 *)((u8 *)arg0 + 0x518) = -1;
    *(s8 *)((u8 *)arg0 + 0x51C) = 0;
    *(s32 *)((u8 *)arg0 + 0x520) = -1;
    *(s32 *)((u8 *)arg0 + 0x524) = -1;
    *(s32 *)((u8 *)arg0 + 0x0) = -1;
}
/* localdecomp:end func_L39_006CDF38 */

INCLUDE_ASM("asm/levels", func_L39_006CE000);

INCLUDE_ASM("asm/levels", func_L39_006CE068);

INCLUDE_ASM("asm/levels", func_L39_006CE150);

INCLUDE_ASM("asm/levels", func_L39_006CE1B8);

INCLUDE_ASM("asm/levels", func_L39_006CE2A0);

INCLUDE_ASM("asm/levels", func_L39_006CE308);

INCLUDE_ASM("asm/levels", func_L39_006CE3F0);

INCLUDE_ASM("asm/levels", func_L39_006CE458);

INCLUDE_ASM("asm/levels", func_L39_006CE540);

INCLUDE_ASM("asm/levels", func_L39_006CE5A8);

INCLUDE_ASM("asm/levels", func_L39_006CE690);

INCLUDE_ASM("asm/levels", func_L39_006CE6F8);

INCLUDE_ASM("asm/levels", func_L39_006CE7E0);

INCLUDE_ASM("asm/levels", func_L39_006CE848);

INCLUDE_ASM("asm/levels", func_L39_006CE930);

INCLUDE_ASM("asm/levels", func_L39_006CEA18);

/* localdecomp:start func_L39_006CECA0 */
extern s32 func_00120048(u8 *, u8 *, ...);
extern u8 D_L39_00249BC8[];

void func_L39_006CECA0(u8 *arg0, s32 *arg1) {
    u32 i = 0;
    u8 *p = arg0;
    s32 *q = arg1;

    do {
        func_00120048(p, D_L39_00249BC8, *q);
        i++;
        q++;
        p += 8;
    } while (i < 3);
    *(u8 *)((u8 *)arg0 + i * 8) = 0;
}
/* localdecomp:end func_L39_006CECA0 */

/* localdecomp:start func_L39_006CED20 */
extern u8 D_L39_00249BC8[];
extern void func_001200E0(void *, void *, void *);

void func_L39_006CED20(u8 *arg0, s32 *arg1)
{
    u32 i = 0;
    s32 *q = arg1;
    u8 *p = arg0;

    do {
        func_001200E0(p, D_L39_00249BC8, q);
        i++;
        q++;
        p += 8;
    } while (i < 3);
}
/* localdecomp:end func_L39_006CED20 */

INCLUDE_ASM("asm/levels", func_L39_006CED88);

INCLUDE_ASM("asm/levels", func_L39_006CEEE0);

INCLUDE_ASM("asm/levels", func_L39_006CF080);

INCLUDE_ASM("asm/levels", func_L39_006CF0A0);

INCLUDE_ASM("asm/levels", func_L39_006CF218);

INCLUDE_ASM("asm/levels", func_L39_006CF238);

INCLUDE_ASM("asm/levels", func_L39_006CF3C8);

INCLUDE_ASM("asm/levels", func_L39_006CF3E8);

INCLUDE_ASM("asm/levels", func_L39_006CF588);

INCLUDE_ASM("asm/levels", func_L39_006CF5A8);

INCLUDE_ASM("asm/levels", func_L39_006CF750);

INCLUDE_ASM("asm/levels", func_L39_006CF770);

INCLUDE_ASM("asm/levels", func_L39_006CF900);

INCLUDE_ASM("asm/levels", func_L39_006CF920);

INCLUDE_ASM("asm/levels", func_L39_006CFAD0);

INCLUDE_ASM("asm/levels", func_L39_006CFAF0);

INCLUDE_ASM("asm/levels", func_L39_006CFCB0);

INCLUDE_ASM("asm/levels", func_L39_006CFCD0);

INCLUDE_ASM("asm/levels", func_L39_006CFE68);

INCLUDE_ASM("asm/levels", func_L39_006CFE88);

INCLUDE_ASM("asm/levels", func_L39_006CFEA8);

INCLUDE_ASM("asm/levels", func_L39_006D0058);

INCLUDE_ASM("asm/levels", func_L39_006D0078);

INCLUDE_ASM("asm/levels", func_L39_006D0208);

INCLUDE_ASM("asm/levels", func_L39_006D0228);

INCLUDE_ASM("asm/levels", func_L39_006D0398);

INCLUDE_ASM("asm/levels", func_L39_006D03B8);

INCLUDE_ASM("asm/levels", func_L39_006D0550);

INCLUDE_ASM("asm/levels", func_L39_006D05A0);

INCLUDE_ASM("asm/levels", func_L39_006D08E8);

INCLUDE_ASM("asm/levels", func_L39_006D0990);

INCLUDE_ASM("asm/levels", func_L39_006D0DD0);

INCLUDE_ASM("asm/levels", func_L39_006D0F08);

INCLUDE_ASM("asm/levels", func_L39_006D12C8);

INCLUDE_ASM("asm/levels", func_L39_006D1658);

INCLUDE_ASM("asm/levels", func_L39_006D1710);

INCLUDE_ASM("asm/levels", func_L39_006D1B40);

INCLUDE_ASM("asm/levels", func_L39_006D1BF8);

INCLUDE_ASM("asm/levels", func_L39_006D2030);

INCLUDE_ASM("asm/levels", func_L39_006D20E8);

INCLUDE_ASM("asm/levels", func_L39_006D2500);

INCLUDE_ASM("asm/levels", func_L39_006D25E0);

INCLUDE_ASM("asm/levels", func_L39_006D29F0);

INCLUDE_ASM("asm/levels", func_L39_006D2AC0);

INCLUDE_ASM("asm/levels", func_L39_006D2E80);

/* localdecomp:start func_L39_006D2EB8 */
void func_00120D28(s32, s32, s32);
void func_L39_006D2E80(s32, s32);

void func_L39_006D2EB8(s32 arg0, s32 arg1) {
    func_00120D28(arg0 + 0x30, arg1, 4);
    func_L39_006D2E80(arg0, arg0 + 0x28);
}
/* localdecomp:end func_L39_006D2EB8 */

/* localdecomp:start func_L39_006D2EF0 */
void func_L39_006D2E80(s32, s32);
void func_L39_006D2EF0(void *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((u8 *)arg0 + 0x28) = arg1;
    *(s32 *)((u8 *)arg0 + 0x2C) = arg2;
    func_L39_006D2E80((s32) arg0, (s32) (arg0 + 0x28));
}
/* localdecomp:end func_L39_006D2EF0 */

INCLUDE_ASM("asm/levels", func_L39_006D2F18);

INCLUDE_ASM("asm/levels", func_L39_006D2FA0);

INCLUDE_ASM("asm/levels", func_L39_006D30F8);

INCLUDE_ASM("asm/levels", func_L39_006D31B8);

INCLUDE_ASM("asm/levels", func_L39_006D3318);

INCLUDE_ASM("asm/levels", func_L39_006D33D8);

/* localdecomp:start func_L39_006D3440 */
void *func_L39_006D3440(void *arg0) {
    (*(s8 *)arg0) = 0;
    *(s8 *)((u8 *)arg0 + 1) = 0;
    *(s8 *)((u8 *)arg0 + 2) = 0;
    *(s8 *)((u8 *)arg0 + 3) = 0;
    *(s8 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)((u8 *)arg0 + 0xC) = 0;
    *(s8 *)((u8 *)arg0 + 0x10) = 0;
    *(s8 *)((u8 *)arg0 + 0x11) = 0;
    *(s8 *)((u8 *)arg0 + 0x12) = 0;
    *(s8 *)((u8 *)arg0 + 0x13) = 0;
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    *(s32 *)((u8 *)arg0 + 0x18) = 0;
    *(s8 *)((u8 *)arg0 + 0x20) = 0;
    *(s32 *)((u8 *)arg0 + 0x3FC) = 0;
    *(s32 *)((u8 *)arg0 + 0xD20) = 0;
    *(s32 *)((u8 *)arg0 + 0x1644) = 0;
    return arg0;
}
/* localdecomp:end func_L39_006D3440 */

INCLUDE_ASM("asm/levels", func_L39_006D3490);

INCLUDE_ASM("asm/levels", func_L39_006D34D8);

INCLUDE_ASM("asm/levels", func_L39_006D3950);

INCLUDE_ASM("asm/levels", func_L39_006D3A30);

INCLUDE_ASM("asm/levels", func_L39_006D4018);

INCLUDE_ASM("asm/levels", func_L39_006D4030);

INCLUDE_ASM("asm/levels", func_L39_006D40B0);

INCLUDE_ASM("asm/levels", func_L39_006D4188);

INCLUDE_ASM("asm/levels", func_L39_006D4278);

INCLUDE_ASM("asm/levels", func_L39_006D4380);

INCLUDE_ASM("asm/levels", func_L39_006D44F0);

INCLUDE_ASM("asm/levels", func_L39_006D45B8);

INCLUDE_ASM("asm/levels", func_L39_006D4688);

INCLUDE_ASM("asm/levels", func_L39_006D48C8);

INCLUDE_ASM("asm/levels", func_L39_006D4A68);

INCLUDE_ASM("asm/levels", func_L39_006D4B98);

INCLUDE_ASM("asm/levels", func_L39_006D4D48);
