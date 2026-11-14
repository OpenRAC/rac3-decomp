/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_00496498, the NTSC-U twin of func_L01_00499CD8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_00499C80.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_00499CD8 (src/levels/shared/L01_00499C80.c) */
/* localdecomp:start func_L01_00496498 */
extern u8 D_001439F4[];
extern u8 D_L01_002EBA10[];
extern u8 D_L01_002EBB20[];
extern u8 D_L01_002EBAC8[];
extern u8 D_L01_002EBB98[];
extern u8 *D_001D9318_sda;
__asm__(".extern D_001D9318_sda, 4");
extern s32 D_001D931C_sda;
__asm__(".extern D_001D931C_sda, 4");
extern char D_001D9360_sda;
__asm__(".extern D_001D9360_sda, 1");
extern void func_L01_00496AB0(void);
extern void func_L01_00496B08(void);
extern void func_00389920(s32);
extern void func_L01_00496F08(s32, f32 *, f32 *);
extern char *func_0037DF98(s32);
extern void func_003B3DB8(s32, s32, s32, s32, s32, s32, s32, s32, s32, char *, s32, s32, s32, s32, f32);
extern void func_L01_00512FE8(s32, char *);
extern void func_L01_004967D0(void *);
extern void func_L01_00513548(s32, f32, f32);
extern s32 func_003E2DE0(s32, s32);
extern s32 func_003E29B8(s32, s32);
extern s32 *func_003AED40(s32);
extern void func_003E31A8(s32, s32 *);
extern s32 func_L01_005131A0(s32, s32);
extern void func_L01_00512D70(s32, s32);
extern s32 func_003E3250(s32, s32, s32);
extern void func_L01_00513C08(s32, s32, s32, s32, s32, s32);
extern void func_L01_00513DC8(s32, s32, s32, f32);
extern void func_L01_00513D28(s32);

void func_L01_00496498(void) {
    f32 a;
    f32 b;
    char *msg;

    a = 1.0f;
    b = 0.0f;
    switch (D_001439F4[0]) {
    case 0:
        D_001D931C_sda = 14;
        D_001D9318_sda = D_L01_002EBA10;
        break;
    case 1:
        D_001D931C_sda = 9;
        D_001D9318_sda = D_L01_002EBB20;
        break;
    case 2:
        D_001D931C_sda = 6;
        D_001D9318_sda = D_L01_002EBAC8;
        break;
    }
    func_L01_00496AB0();
    func_L01_00496B08();
    func_00389920(0);
    func_L01_00496F08(0x113, &a, &b);
    msg = func_0037DF98(0x113);
    func_003B3DB8(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008, msg, 0xD0006, 0x124, 0xD0007, 0xCD5, b);
    func_L01_00512FE8(0xD0006, &D_001D9360_sda);
    func_L01_004967D0(D_L01_002EBB98);
    func_L01_00513548(0xD0005, a, a);
    func_003E2DE0(0x11, 0x4B0000);
    func_003E29B8(0x4B0005, 1);
    func_003E29B8(0x4B0006, 1);
    func_003E31A8(0x4B0009, func_003AED40(0));
    func_L01_005131A0(0x4B0009, 0);
    func_L01_00512D70(0x4B0009, 0);
    func_003E3250(0x4B0009, 1, 10);
    func_L01_00513C08(0x4B0006, 1, 1, 1, 0, 0);
    func_L01_00513DC8(0x4B0006, 0x78, 0, 0.0005f);
    func_L01_00513D28(0x4B0006);
}
/* localdecomp:end func_L01_00496498 */
