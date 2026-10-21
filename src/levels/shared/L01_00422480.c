#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_00422480);

LINKER_REMNANT("asm/levels", func_L01_00422538);

/* localdecomp:start func_L01_00422548 */
extern s32 D_001A1EDC[];
extern s32 D_001D4BB4;
extern s32 D_001D4BB0;
extern s32 D_001D545C;
extern s32 D_L01_001D76D8;
extern u8 D_L01_001DFBC0[];
extern u8 D_L01_001FDBD0[];
extern u8 D_L01_00200DF0[];
extern u8 D_L01_00200670[];
extern u8 D_L01_0023C800[];
extern u8 D_L01_00243C00[];
extern u8 D_L01_00243800[];
extern u8 D_L01_002385F0[];
extern u8 D_L01_0023A3F0[];
extern u8 D_L01_00239DF0[];
extern void func_003A1330(void);
extern void func_003A9050(void);
extern void func_00397EA8(void);
extern void func_0038CB78(void *, s32, s32);
extern void func_00387268(void);
extern void func_003873C0(void);
extern void func_L01_004077D0(void);
extern void func_003A9108(void);
extern void func_L01_00462978(void);
extern void func_003A9A40(void);
extern void func_L01_0043B5C8(void);
extern void func_L01_004227D8(void);
extern void func_L01_0044CCC8(s32);
extern void func_0039EF28(void);

void func_L01_00422548(void) {
    s32 v;
    s32 t;
    func_003A1330();
    func_003A9050();
    func_00397EA8();
    v = D_001A1EDC[0];
    D_001D4BB0 = v;
    D_001D4BB4 = v;
    func_0038CB78(D_L01_001DFBC0, 0x87654321, 16);
    func_0038CB78(D_L01_001FDBD0, -1, 8192);
    func_0038CB78(D_L01_00200DF0, -1, 3840);
    func_0038CB78(D_L01_00200670, 0, 240);
    func_0038CB78(D_L01_0023C800, -1, 8192);
    func_0038CB78(D_L01_00243C00, -1, 2048);
    func_0038CB78(D_L01_00243800, 0, 128);
    func_0038CB78(D_L01_002385F0, -1, 4096);
    func_0038CB78(D_L01_0023A3F0, -1, 1024);
    func_0038CB78(D_L01_00239DF0, 0, 64);
    func_00387268();
    func_003873C0();
    func_L01_004077D0();
    func_003A9108();
    func_L01_00462978();
    func_003A9A40();
    func_L01_0043B5C8();
    func_L01_004227D8();
    t = D_001D545C;
    if (t != 0) {
        func_L01_0044CCC8(t % 60);
        func_0039EF28();
    }
    D_L01_001D76D8 = 0;
}
/* localdecomp:end func_L01_00422548 */

INCLUDE_ASM("asm/levels", func_L01_004226C8);

/* localdecomp:start func_L01_004227D8 */
extern u8 D_00142CA0[];
extern u8 D_00142D40[];
extern s32 D_001D4C48;
extern s32 D_001D545C;
extern void func_L01_00419188(s32 a0);
extern void func_0039EF28(void);
extern void func_L01_004226C8(void);
extern void func_L01_004228B0(s32 a0);

void func_L01_004227D8(void) {
    if (D_00142CA0[23] == 0) {
        func_L01_00419188(23);
        D_001D4C48 = 23;
    }
    if (D_00142CA0[6] == 0) {
        D_00142D40[6] = 1;
        D_00142CA0[6] = 1;
        func_0039EF28();
    }
    if (D_00142CA0[36] == 0) {
        D_00142CA0[36] = 1;
        D_00142D40[36] = 1;
        func_0039EF28();
        D_00142CA0[37] = 1;
        D_00142D40[37] = 1;
        func_0039EF28();
        D_00142D40[38] = 1;
        D_00142CA0[38] = 1;
        func_0039EF28();
    }
    func_L01_004226C8();
    D_00142CA0[3] = 1;
    D_00142D40[3] = 1;
    func_0039EF28();
    func_L01_004228B0(D_001D545C);
}
/* localdecomp:end func_L01_004227D8 */

/* localdecomp:start func_L01_004228B0 */
extern s32 func_L01_00419C18(s32 i, s32 a);
extern void func_L01_00419248(s32 i);

void func_L01_004228B0(s32 a0)
{
    s32 i;

    for (i = 0; i < 156; i++) {
        if (func_L01_00419C18(i, a0) && i != 0) {
            func_L01_00419248(i);
        }
    }
}
/* localdecomp:end func_L01_004228B0 */
