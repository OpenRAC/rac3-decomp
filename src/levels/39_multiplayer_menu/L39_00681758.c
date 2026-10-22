#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00681758);

INCLUDE_ASM("asm/levels", func_L39_006818D0);

INCLUDE_ASM("asm/levels", func_L39_006818F8);

/* localdecomp:start func_L39_00681998 */
s32 func_L39_00681998(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x1059C) = arg1;
    return 1;
}
/* localdecomp:end func_L39_00681998 */

INCLUDE_ASM("asm/levels", func_L39_006819B0);

INCLUDE_ASM("asm/levels", func_L39_00681A40);

INCLUDE_ASM("asm/levels", func_L39_00681CA8);

INCLUDE_ASM("asm/levels", func_L39_00681D78);

/* localdecomp:start func_L39_00682018 */
void func_L39_00682018(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x1057C) = arg1;
}
/* localdecomp:end func_L39_00682018 */

INCLUDE_ASM("asm/levels", func_L39_00682028);

INCLUDE_ASM("asm/levels", func_L39_00682098);

INCLUDE_ASM("asm/levels", func_L39_006820D0);

INCLUDE_ASM("asm/levels", func_L39_00682108);

INCLUDE_ASM("asm/levels", func_L39_00682148);

INCLUDE_ASM("asm/levels", func_L39_00682180);

/* localdecomp:start func_L39_006821C0 */
void func_L39_006821C0(void *arg0, f32 fparg0) {
    *(f32 *)((u8 *)arg0 + 0x4C) = fparg0;
    *(s32 *)((u8 *)arg0 + 0x48) = 1;
}
/* localdecomp:end func_L39_006821C0 */

INCLUDE_ASM("asm/levels", func_L39_006821D0);

INCLUDE_ASM("asm/levels", func_L39_006822E8);

INCLUDE_ASM("asm/levels", func_L39_00682308);

INCLUDE_ASM("asm/levels", func_L39_00682640);

INCLUDE_ASM("asm/levels", func_L39_006826C0);

INCLUDE_ASM("asm/levels", func_L39_00682720);

/* localdecomp:start func_L39_00682748 */
s32 func_L39_00682748(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x64));
}
/* localdecomp:end func_L39_00682748 */

/* localdecomp:start func_L39_00682750 */
s32 func_L39_00682750(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x1057C));
}
/* localdecomp:end func_L39_00682750 */

/* localdecomp:start func_L39_00682760 */
s32 func_L39_00682760(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x10168));
}
/* localdecomp:end func_L39_00682760 */

/* localdecomp:start func_L39_00682770 */
s32 func_L39_00682770(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x10580));
}
/* localdecomp:end func_L39_00682770 */

INCLUDE_ASM("asm/levels", func_L39_00682780);

/* localdecomp:start func_L39_006827A8 */
void *func_L39_006827A8(void *arg0) {
    return arg0 + (((*(s32 *)((u8 *)arg0 + 0x10168)) << 8) + 0x68);
}
/* localdecomp:end func_L39_006827A8 */

/* localdecomp:start func_L39_006827C8 */
s32 func_L39_006827C8(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x10168)) != *(s32 *)((u8 *)arg0 + 0x1016C);
}
/* localdecomp:end func_L39_006827C8 */

/* localdecomp:start func_L39_006827E8 */
u8 func_L39_006827E8(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x10584));
}
/* localdecomp:end func_L39_006827E8 */

INCLUDE_ASM("asm/levels", func_L39_006827F8);

INCLUDE_ASM("asm/levels", func_L39_00682818);

LINKER_REMNANT("asm/levels", func_L39_00682838);

INCLUDE_ASM("asm/levels", func_L39_00682840);

INCLUDE_ASM("asm/levels", func_L39_006828D0);

INCLUDE_ASM("asm/levels", func_L39_006828F8);

INCLUDE_ASM("asm/levels", func_L39_00682990);

INCLUDE_ASM("asm/levels", func_L39_00682A20);

INCLUDE_ASM("asm/levels", func_L39_00682AB8);

INCLUDE_ASM("asm/levels", func_L39_00682AE8);

INCLUDE_ASM("asm/levels", func_L39_00682B80);

/* localdecomp:start func_L39_00682C88 */
s32 func_L01_00516C78(s32, s32, s32);

void func_L39_00682C88(void *arg0, s32 arg1) {
    s32 var_a1;

    var_a1 = arg1;
    switch (var_a1) {                               /* irregular */
    case -1:
        var_a1 = 1;
        break;
    case 1:
        var_a1 = 2;
        break;
    case 0:
        var_a1 = 3;
        break;
    }
    if ((*(s32 *)((u8 *)arg0 + 0xA8)) != -1) {
        func_L01_00516C78((*(s32 *)((u8 *)arg0 + 0xA8)), var_a1, 3);
    }
}
/* localdecomp:end func_L39_00682C88 */

INCLUDE_ASM("asm/levels", func_L39_00682CE8);

INCLUDE_ASM("asm/levels", func_L39_00682D00);

/* localdecomp:start func_L39_00682F90 */
void func_L39_00682F90(void *arg0, f32 fparg0) {
    *(f32 *)((u8 *)arg0 + 0x58) = fparg0;
}
/* localdecomp:end func_L39_00682F90 */

/* localdecomp:start func_L39_00682F98 */
s32 func_L39_00682F98(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x64));
}
/* localdecomp:end func_L39_00682F98 */

/* localdecomp:start func_L39_00682FA0 */
s32 func_L39_00682FA0(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x64)) != *(s32 *)((u8 *)arg0 + 0x68);
}
/* localdecomp:end func_L39_00682FA0 */

LINKER_REMNANT("asm/levels", func_L39_00682FB8);

INCLUDE_ASM("asm/levels", func_L39_00682FC0);

INCLUDE_ASM("asm/levels", func_L39_00683038);

INCLUDE_ASM("asm/levels", func_L39_00683060);

INCLUDE_ASM("asm/levels", func_L39_00683180);

INCLUDE_ASM("asm/levels", func_L39_006831A0);

INCLUDE_ASM("asm/levels", func_L39_00683268);

INCLUDE_ASM("asm/levels", func_L39_00683420);

INCLUDE_ASM("asm/levels", func_L39_00683490);

/* localdecomp:start func_L39_00683510 */
void func_L39_00683510(void *arg0, s32 arg1) {
    s32 var_v1;

    var_v1 = *(s32 *)((u8 *)arg0 + 0x7C);
    *(s32 *)((u8 *)arg0 + 0x80) = arg1;
    if ((var_v1 < arg1) || (var_v1 = (*(s32 *)((u8 *)arg0 + 0x78)), ((arg1 < var_v1) != 0))) {
        *(s32 *)((u8 *)arg0 + 0x80) = var_v1;
    }
}
/* localdecomp:end func_L39_00683510 */

/* localdecomp:start func_L39_00683540 */
s32 func_L39_00683540(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x80));
}
/* localdecomp:end func_L39_00683540 */

LINKER_REMNANT("asm/levels", func_L39_00683548);

INCLUDE_ASM("asm/levels", func_L39_00683550);

INCLUDE_ASM("asm/levels", func_L39_006835B0);

INCLUDE_ASM("asm/levels", func_L39_006835D8);

INCLUDE_ASM("asm/levels", func_L39_00683718);

INCLUDE_ASM("asm/levels", func_L39_00683730);

INCLUDE_ASM("asm/levels", func_L39_00683760);

INCLUDE_ASM("asm/levels", func_L39_006837E8);

INCLUDE_ASM("asm/levels", func_L39_00683818);

INCLUDE_ASM("asm/levels", func_L39_00683848);

INCLUDE_ASM("asm/levels", func_L39_00683A30);

INCLUDE_ASM("asm/levels", func_L39_00683A90);

INCLUDE_ASM("asm/levels", func_L39_00683AB8);

/* localdecomp:start func_L39_00683B50 */
s32 func_L39_00683B50(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)arg0 + 0xCC) = arg1;
    return 1;
}
/* localdecomp:end func_L39_00683B50 */

INCLUDE_ASM("asm/levels", func_L39_00683B60);

INCLUDE_ASM("asm/levels", func_L39_00683BA8);

INCLUDE_ASM("asm/levels", func_L39_00683C40);

/* localdecomp:start func_L39_00683CD8 */
s32 func_L39_00683CD8(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0xC8) = arg1;
    return 1;
}
/* localdecomp:end func_L39_00683CD8 */

INCLUDE_ASM("asm/levels", func_L39_00683CE8);

INCLUDE_ASM("asm/levels", func_L39_00683EB8);

INCLUDE_ASM("asm/levels", func_L39_00683FF8);

INCLUDE_ASM("asm/levels", func_L39_00684130);

INCLUDE_ASM("asm/levels", func_L39_00684190);

INCLUDE_ASM("asm/levels", func_L39_00684218);

INCLUDE_ASM("asm/levels", func_L39_00684230);

/* localdecomp:start func_L39_00684488 */
void func_0011D534(s32, s32, s32);

void func_L39_00684488(s32 arg0) {
    func_0011D534(arg0 + 0x64, 0, 0x50);
}
/* localdecomp:end func_L39_00684488 */

/* localdecomp:start func_L39_006844B0 */
void func_L39_006844B0(void *arg0, f32 fparg0) {
    *(f32 *)((u8 *)arg0 + 0x58) = fparg0;
    *(s32 *)((u8 *)arg0 + 0xC0) = 1;
}
/* localdecomp:end func_L39_006844B0 */

/* localdecomp:start func_L39_006844C0 */
void func_L39_006844C0(void *arg0, f32 fparg0) {
    *(f32 *)((u8 *)arg0 + 0x4C) = fparg0;
    *(s32 *)((u8 *)arg0 + 0x48) = 1;
}
/* localdecomp:end func_L39_006844C0 */

/* localdecomp:start func_L39_006844D0 */
s32 func_L39_006844D0(s32 arg0) {
    return arg0 + 0x64;
}
/* localdecomp:end func_L39_006844D0 */

LINKER_REMNANT("asm/levels", func_L39_006844D8);

INCLUDE_ASM("asm/levels", func_L39_006844E0);

INCLUDE_ASM("asm/levels", func_L39_00684528);

/* localdecomp:start func_L39_00684550 */
void func_L39_00684550(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x464) = arg1;
}
/* localdecomp:end func_L39_00684550 */

INCLUDE_ASM("asm/levels", func_L39_00684558);

INCLUDE_ASM("asm/levels", func_L39_00684580);

INCLUDE_ASM("asm/levels", func_L39_006845A0);

INCLUDE_ASM("asm/levels", func_L39_006845D0);

INCLUDE_ASM("asm/levels", func_L39_00684600);

/* localdecomp:start func_L39_00684630 */
s32 func_L39_00610CA8(s32);

s32 func_L39_00684630(void *arg0) {
    s32 temp_a0;
    s32 var_v1;

    temp_a0 = *(s32 *)((u8 *)arg0 + 0x468);
    var_v1 = 0;
    if (temp_a0 != -1) {
        var_v1 = func_L39_00610CA8(temp_a0);
    }
    return var_v1;
}
/* localdecomp:end func_L39_00684630 */

INCLUDE_ASM("asm/levels", func_L39_00684668);

INCLUDE_ASM("asm/levels", func_L39_006846B0);

/* localdecomp:start func_L39_00684728 */
void func_L39_00684728(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x468) = -1;
}
/* localdecomp:end func_L39_00684728 */

INCLUDE_ASM("asm/levels", func_L39_00684738);

/* localdecomp:start func_L39_006847F8 */
void func_0011D534(s32, s32, s32);

void func_L39_006847F8(s32 arg0) {
    func_0011D534(arg0 + 0x64, 0, 0x400);
}
/* localdecomp:end func_L39_006847F8 */

/* localdecomp:start func_L39_00684820 */
void func_00120D28(s32, s32, s32);
void func_L39_00684820(void *arg0, s32 arg1) {
    func_00120D28(arg0 + 0x64, arg1, 0x400);
    *(s8 *)((u8 *)arg0 + 0x463) = 0;
}
/* localdecomp:end func_L39_00684820 */

/* localdecomp:start func_L39_00684850 */
s32 func_L39_00684850(s32 arg0) {
    return arg0 + 0x64;
}
/* localdecomp:end func_L39_00684850 */

LINKER_REMNANT("asm/levels", func_L39_00684858);

INCLUDE_ASM("asm/levels", func_L39_00684860);

INCLUDE_ASM("asm/levels", func_L39_00684A68);

INCLUDE_ASM("asm/levels", func_L39_00684A90);

/* localdecomp:start func_L39_00684B58 */
s32 func_L39_00684B58(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)arg0 + 0x248) = arg1;
    return 1;
}
/* localdecomp:end func_L39_00684B58 */

INCLUDE_ASM("asm/levels", func_L39_00684B68);

INCLUDE_ASM("asm/levels", func_L39_00684C30);

INCLUDE_ASM("asm/levels", func_L39_00684C60);

INCLUDE_ASM("asm/levels", func_L39_00684D28);

INCLUDE_ASM("asm/levels", func_L39_006850F8);

INCLUDE_ASM("asm/levels", func_L39_006852C8);

INCLUDE_ASM("asm/levels", func_L39_00685378);

INCLUDE_ASM("asm/levels", func_L39_00685398);

/* localdecomp:start func_L39_00685998 */
void func_L39_00685998(void *arg0, f32 fparg0) {
    *(f32 *)((u8 *)arg0 + 0x58) = fparg0;
    *(s32 *)((u8 *)arg0 + 0x23C) = 1;
}
/* localdecomp:end func_L39_00685998 */

/* localdecomp:start func_L39_006859A8 */
void func_0011D534(s32, s32, s32);

void func_L39_006859A8(s32 arg0) {
    func_0011D534(arg0 + 0x64, 0, 0xC8);
    func_0011D534(arg0 + 0x3DC, 0, 0xC8);
}
/* localdecomp:end func_L39_006859A8 */

INCLUDE_ASM("asm/levels", func_L39_006859E8);

/* localdecomp:start func_L39_00685A78 */
s32 func_L39_00685A78(s32 arg0) {
    return arg0 + 0x64;
}
/* localdecomp:end func_L39_00685A78 */

INCLUDE_ASM("asm/levels", func_L39_00685A80);

INCLUDE_ASM("asm/levels", func_L39_00685AB0);

INCLUDE_ASM("asm/levels", func_L39_00685AE0);

INCLUDE_ASM("asm/levels", func_L39_00685B50);

LINKER_REMNANT("asm/levels", func_L39_00685BC0);

INCLUDE_ASM("asm/levels", func_L39_00685BC8);

INCLUDE_ASM("asm/levels", func_L39_00685C48);

INCLUDE_ASM("asm/levels", func_L39_00685C70);

/* localdecomp:start func_L39_00685CE8 */
void func_L39_00685CE8(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x64) = -1;
}
/* localdecomp:end func_L39_00685CE8 */

INCLUDE_ASM("asm/levels", func_L39_00685CF8);

/* localdecomp:start func_L39_00685D28 */
s32 func_L39_00685D28(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x68) = arg1;
    return 1;
}
/* localdecomp:end func_L39_00685D28 */

/* localdecomp:start func_L39_00685D38 */
s32 func_L39_00685D38(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x6C) = arg1;
    return 1;
}
/* localdecomp:end func_L39_00685D38 */

INCLUDE_ASM("asm/levels", func_L39_00685D48);

INCLUDE_ASM("asm/levels", func_L39_00685E08);

INCLUDE_ASM("asm/levels", func_L39_00685E30);

INCLUDE_ASM("asm/levels", func_L39_00685FF0);

INCLUDE_ASM("asm/levels", func_L39_00686048);

INCLUDE_ASM("asm/levels", func_L39_00686138);

INCLUDE_ASM("asm/levels", func_L39_006862D0);

INCLUDE_ASM("asm/levels", func_L39_00686768);

INCLUDE_ASM("asm/levels", func_L39_00686810);

INCLUDE_ASM("asm/levels", func_L39_00686E40);

INCLUDE_ASM("asm/levels", func_L39_00687268);

INCLUDE_ASM("asm/levels", func_L39_006872E8);
